#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "cmd.h"
#include "pick.h"
#include "text.h"
#include "gen/prompts.h"

/* view+0x8564 in the original, and +0x8568 for the one before.  Entering a
   command copies the outgoing one into +0x8568 before the new command's arm
   of FUN_004fdc40 runs, which is how that arm can tell it is being entered
   from itself. */
static int current = JW_CMD_SEN;
static int prev;

/* 水平・垂直, the first checkbox on 線's command bar after 矩形.
 *
 * Pressing 線 when 線 is already the command flips it -- FUN_004fdc40's
 * 0x8003 arm does that and nothing else when the command before was 0x8003
 * too, and driving Jw_cad bears it out: from a fresh start a diagonal drag
 * draws a diagonal, after one press of 線 it draws horizontal or vertical,
 * and after two it is diagonal again.  矩形's arm (0x8004) has no such test,
 * so only 線 toggles.
 *
 * With it on the line keeps whichever way the drag went further; a drag of
 * exactly 45 degrees comes out vertical. */
static int hv;

/* Each command keeps how far it has got in a word of its own -- CZukeiSen in
 * local_662c[0x2a] of FUN_006ecb90, CZukeiEnko in local_6840[0xc2] -- and
 * both use 0 for "nothing yet" and 2 for "one point down".  The same values
 * are used here so the two can be compared.
 */
static int step;
static double sx, sy;           /* the first point, in paper millimetres */
/* 連続線 keeps one segment back.  Clicking n times in Jw_cad and saving
 * leaves n-2 lines in the file -- two clicks leave none, four leave two,
 * five leave three (driven with tmp/jwdraw.ps1 -Cmd 32883) -- so the segment
 * between the last two points is still only on the screen when the next
 * click arrives, and that click is what puts it in.  These are those two
 * points; sx,sy is the one before them. */
static double rx, ry;

/* 消去's left button, the partial erase.  Three clicks: the first picks the
 * line, the next two say which piece of it to take out.  CZukeiShoukyo keeps
 * the same three states in +0x21c (0, then 1, then 2, and the third click
 * makes it 3 and runs). */
static int cut_step;
static int cut_obj;             /* which element, while it is being cut */
static double cut_x, cut_y;     /* the first of the two range points */

/* コーナー処理: the first line, and where it was clicked.  CZukeiCorner
   keeps the same in +0x204 (0, then 2 once a line is down, then 3). */
static int corner_step;
static int corner_obj;
static double corner_x, corner_y;

/* 線伸縮: the line, while its end is being moved. */
static int stretch_step;
static int stretch_obj;

/* 文字: what has been typed but not placed yet.  The original wants it that
   way round -- type into its floating box first, then click where it goes;
   pressing Enter does not place anything. */
static char line_buf[256];
static int line_n;
/* the typed line put in the drawing's pool, so the preview can be drawn
   without putting it there again on every mouse move */
static int line_off = -1, line_gen, line_shown = -1;
/* what an IME is still converting */
static char comp_buf[256];
static int comp_n;

/* 複線: the line, and how far to one side the copy goes. */
static int para_step;
static int para_obj;
static double para_off;
static double tx, ty;           /* where the mouse is now */
static int tracking;

/* 範囲選択 (CZukeiSentaku) and the two commands built on it, 複写 and 移動
 * (both CZukeiFukusha).
 *
 *   0  the box's first corner   「範囲選択の始点をﾏｳｽ(L)で…」
 *   1  its second               「選択範囲の終点を…(L)文字を除く(R)文字を含む」
 *   2  something is selected, waiting for 選択確定
 *   3  being placed             「基準点…」 then 「複写先の点…」
 *
 * The original's own state words are +0x1f8 and +0x1fc while it is choosing
 * a range and +0xfd14 once it is placing (FUN_006533c0).  Which elements are
 * selected is bit 1 of each element's flags at +0x44 -- saving a drawing
 * with a selection keeps it, which is how the rule below was read off the
 * original: it was given a box and the file it wrote said what was in it. */
static int sel_step;
static double sel_x0, sel_y0, sel_x1, sel_y1;
static double base_x, base_y;   /* 基準点 */
/* What the selected elements looked like when 基準点 was taken, so a move
   can put them at that place plus the offset however often it is done. */
static jw_obj *sel_was;
static int *sel_at;
static int sel_n;

static void sel_free(void);

/* 元に戻る works a command at a time, not an element at a time: drawing a
 * rectangle in Jw_cad and pressing it puts the drawing back to 46 lines, all
 * four at once (tmp/jwdraw.ps1 with -After 57643).  So what is remembered is
 * how many elements each command added, and one press takes back the last
 * command's worth.  Adding at the end is all the commands here do, so the
 * count is all that has to be kept. */
/* One step of 元に戻る.  A command can add elements at the end, take one
   out, and change others in place -- a partial erase does the first two, a
   corner does the third to both of its lines -- and one press has to undo
   all of it. */
typedef struct {
    int at;                     /* where it was */
    int removed;                /* taken out, rather than changed */
    jw_obj was;
} op_item;

typedef struct {
    int n;                      /* how many were added, at the end */
    int nitem, citem;
    op_item *item;              /* 移動 changes a whole selection at once,
                                   so there is no useful upper bound */
} op_t;

/* Remember an element as it is now, so it can be put back. */
static op_item *op_keep(op_t *o, const jw_drawing *d, int at, int removed)
{
    op_item *it;

    if (!o || at < 0 || at >= d->nobj)
        return 0;
    if (o->nitem == o->citem) {
        int n = o->citem ? o->citem * 2 : 4;
        op_item *p = (op_item *)realloc(o->item, (size_t)n * sizeof *p);
        if (!p)
            return 0;
        o->item = p;
        o->citem = n;
    }
    it = &o->item[o->nitem++];
    it->at = at;
    it->removed = removed;
    it->was = d->obj[at];
    return it;
}

static op_t *op;
static int nop, cop;

static op_t *op_new(void)
{
    if (nop == cop) {
        int c = cop ? cop * 2 : 64;
        op_t *p = (op_t *)realloc(op, (size_t)c * sizeof *p);
        if (!p)
            return 0;
        op = p;
        cop = c;
    }
    memset(&op[nop], 0, sizeof op[nop]);
    return &op[nop++];
}

static void op_push(int n)
{
    op_t *o;

    if (n <= 0)
        return;
    o = op_new();
    if (o)
        o->n = n;
}

#define PI 3.14159265358979323846

/* The font name Jw_cad writes with a new text.  It is whatever its font box
   has, and every text in the drawings to hand has this one; the port draws
   with a bitmap font of its own and has no font list to choose from. */
#define JW_MOJI_FACE "lr SVbN" 

int jw_cmd(void)
{
    return current;
}

const char *jw_cmd_line(void)
{
    line_buf[line_n] = 0;
    return line_buf;
}

const char *jw_cmd_compose(void)
{
    comp_buf[comp_n] = 0;
    return comp_buf;
}

void jw_cmd_compose_clear(void)
{
    comp_n = 0;
}

void jw_cmd_compose_key(int c)
{
    if (c >= 0 && c < 256 && comp_n < (int)sizeof comp_buf - 2)
        comp_buf[comp_n++] = (char)c;
}

void jw_cmd_key(int c)
{
    line_gen++;
    if (c == 8) {
        /* back over a whole character, lead byte and all */
        if (line_n > 0) {
            int i = 0, last = 0;
            while (i < line_n) {
                last = i;
                i += (jw_is_lead((unsigned char)line_buf[i]) && i + 1 < line_n)
                     ? 2 : 1;
            }
            line_n = last;
        }
        return;
    }
    if (c >= 0 && c < 256 && line_n < (int)sizeof line_buf - 2)
        line_buf[line_n++] = (char)c;
}

static void blank(jw_obj *o);

/* What the line is worth in paper millimetres, and how the text element for
   it is laid out.  Shared by the preview and the one that gets placed. */
static int moji(jw_drawing *d, jw_obj *o, double x, double y)
{
    const char *p = line_buf;
    double len = 0.0, cw, ch, sp;
    int nch = 0, i;

    if (!d || line_n == 0)
        return 0;
    cw = d->cur_style.w;
    ch = d->cur_style.h;
    sp = d->cur_style.sp;
    if (cw <= 0.0 || ch <= 0.0)
        return 0;
    line_buf[line_n] = 0;
    while (*p) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            len += wide ? sp : sp / 2;
        len += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    blank(o);
    o->cls = JW_MOJI;
    o->color = (unsigned short)d->cur_style.color;
    o->ltype = 1;
    o->d[0] = x;
    o->d[1] = y;
    o->d[2] = x + len;
    o->d[3] = y;
    o->d[4] = cw;
    o->d[5] = ch;
    o->d[6] = sp;
    o->d[7] = 0.0;
    o->n = 0;
    for (i = 0; i < 10; i++)
        if (d->style[i].w == cw && d->style[i].h == ch
            && d->style[i].sp == sp)
            o->n = i + 1;
    if (line_shown != line_gen) {
        line_off = jw_add_str(d, line_buf);
        line_shown = line_gen;
    }
    o->text = line_off;
    o->face = -1;
    return 1;
}

int jw_cmd_hv(void)
{
    return hv;
}

void jw_cmd_set(int id)
{
    prev = current;
    if (id == JW_CMD_SEN && prev == JW_CMD_SEN)
        hv = !hv;
    /* FUN_004fdc40: the new command's state starts empty. */
    current = id;
    step = 0;
    comp_n = 0;
    cut_step = 0;
    corner_step = 0;
    stretch_step = 0;
    para_step = 0;
    tracking = 0;
    /* The range starts over, the way FUN_004fdc40 leaves the command's own
       state -- but what is picked belongs to the elements, not to the
       command, so it stays until a new box is begun.  That is how the
       original can be given a range in 範囲選択 and then told what to do
       with it. */
    if (id == JW_CMD_HANI || id == JW_CMD_FUKUSHA || id == JW_CMD_IDOU) {
        sel_step = 0;
        sel_free();
    }
}

void jw_cmd_reset(void)
{
    /* 新規 does not enter a command, so nothing here goes through
       jw_cmd_set: the previous command and 水平・垂直 are left alone, the
       way the original leaves +0x8568 and +0x730 alone. */
    current = JW_CMD_SEN;
    step = 0;
    cut_step = 0;
    tracking = 0;
    while (nop > 0) {
        free(op[--nop].item);
        op[nop].item = 0;
    }
    sel_step = 0;
    sel_free();
}

int jw_cmd_can_undo(void)
{
    return nop > 0;
}

void jw_cmd_undo(jw_drawing *d)
{
    op_t *o;
    int i;

    if (!d || nop <= 0)
        return;
    o = &op[nop - 1];
    {   /* Everything is added at the end of the drawn elements, so the last
           command's elements are the last ones there. */
        int n;
        for (n = o->n; n > 0 && d->ndrawn > 0; n--)
            jw_remove(d, d->ndrawn - 1);
    }
    for (i = o->nitem - 1; i >= 0; i--) {
        op_item *it = &o->item[i];
        if (!it->removed) {
            if (it->at < d->nobj)
                d->obj[it->at] = it->was;
        } else {
            /* an erased one goes back where it was, so the drawing order --
               and so what is on top of what -- comes back with it */
            jw_obj *p = jw_add(d, it->was.cls);
            if (p) {
                int at = it->at < d->ndrawn ? it->at : d->ndrawn - 1;
                *p = it->was;
                while (p > &d->obj[at]) {
                    jw_obj t = p[-1];
                    p[-1] = p[0];
                    p[0] = t;
                    p--;
                }
            }
        }
    }
    free(o->item);
    o->item = 0;
    o->nitem = o->citem = 0;
    nop--;
    step = 0;
    tracking = 0;
}

const char *jw_cmd_prompt(void)
{
    switch (current) {
    case JW_CMD_SEN:
    case JW_CMD_RENZOKU:
        /* CZukeiRenzokuSen shows the same two: 0x14c8 while its own step is
           0 or 1, 0x14c9 once it is 3.  (Its step 2 asks for an arc's middle
           point, which belongs to the 連続円弧 half of the command.) */
        return step == 0 ? JW_STR_5320 : JW_STR_5321;
    case JW_CMD_TEN:
        return JW_STR_5376;
    case JW_CMD_MOJI:
        /* 「文字を入力するか…」 until something is typed, then
           「文字の位置を指示して下さい」 */
        return line_n ? JW_STR_5318 : JW_STR_5316;
    case JW_CMD_ZOKUSEI:
        return JW_STR_5263;
    case JW_CMD_FUKUSEN:
        /* 「複線にする図形を選択してください ﾏｳｽ(L)　前回値 ﾏｳｽ(R)」 then
           「複線方向を指示 ﾏｳｽ(L)…」 */
        return para_step == 0 ? JW_STR_5305 : JW_STR_5366;
    case JW_CMD_SHINSHUKU:
        /* FUN_00717df0: 0x14d8 while its state is 0, 0x14da once a line is
           picked.  (Its states 3 and 4 are the 基準線 variant, where the end
           goes to another line instead of to a point; not done here.) */
        return stretch_step == 0 ? JW_STR_5336 : JW_STR_5338;
    case JW_CMD_CORNER:
        /* 「線（Ａ）指示(L)　線切断(R)」 then 「◆　線【Ｂ】指示(L)…」
           -- FUN_00635ae0 puts up 0x14dc while its state is 0 and 0x14dd
           while it is 1 or 2. */
        return corner_step == 0 ? JW_STR_5340 : JW_STR_5341;
    case JW_CMD_SHOUKYO:
        /* 10111 is CZukeiShoukyo's own line, and where the two buttons' jobs
           are written down: (L) takes a piece out of a line or circle, (R)
           deletes the whole element.  Once a line has been picked it asks
           for the two ends of the piece instead (FUN_0070dc20: 0x2780 and
           0x2781 for a line, 0x2782 and 0x2783 for a circle). */
        if (cut_step == 1)
            return JW_STR_10112;
        if (cut_step == 2)
            return JW_STR_10113;
        return JW_STR_10111;
    case JW_CMD_HANI:
    case JW_CMD_FUKUSHA:
    case JW_CMD_IDOU:
        /* 5383 while the box has no first corner, 5326 while it is being
           dragged, then 5314 基準点 and 5307/5311 for where it goes. */
        if (sel_step == 1)
            return JW_STR_5326;
        if (sel_step == 3)
            return current == JW_CMD_IDOU ? JW_STR_5311 : JW_STR_5307;
        if (sel_step == 2)
            return JW_STR_5314;
        return JW_STR_5383;
    case JW_CMD_ENKO:
        /* CZukeiEnko asks for the centre first and then a point the circle
           goes through.  It leads with 円位置 instead only when a radius has
           been typed into its command bar, which there is nowhere to do
           yet. */
        return step == 0 ? JW_STR_5309 : JW_STR_5301;
    }
    /* Every other command puts its own string there; which one is in that
       command's class and has not been read out of the binary yet, so rather
       than make one up the line keeps the one it starts with. */
    return JW_STR_5320;
}

void jw_cmd_track(double x, double y)
{
    tx = x;
    ty = y;
    tracking = 1;
}

static void blank(jw_obj *o)
{
    memset(o, 0, sizeof *o);
    o->text = o->face = -1;
    o->ltype = 1;
    o->color = 2;
}

/* What the point down and the point here make -- one element, or the four of
   a rectangle.  Working it out in one place keeps the provisional figure and
   what gets added identical. */
static int figure(jw_obj *o, int max, double x, double y)
{
    blank(o);
    switch (current) {
    case JW_CMD_SEN:
        if (hv) {
            if (fabs(x - sx) > fabs(y - sy))
                y = sy;
            else
                x = sx;
        }
        o->cls = JW_SEN;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = x;
        o->d[3] = y;
        return 1;
    case JW_CMD_RENZOKU:
        o->cls = JW_SEN;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = x;
        o->d[3] = y;
        return 1;
    case JW_CMD_KUKEI: {
        /* Four lines round the corners, in the order the original writes
         * them.  Drawn one in Jw_cad itself and read the file back: starting
         * at the corner clicked first it goes along x, then y, then back,
         * each line carrying on from where the last one ended.  There is no
         * rectangle in the file format -- only 線・円弧・点・文字・ソリッド --
         * so four lines is what it has to be. */
        static const int ix[4][4] = {
            {0, 1, 2, 1}, {2, 1, 2, 3}, {2, 3, 0, 3}, {0, 3, 0, 1}
        };
        double c[4];
        int k, j;
        if (max < 4)
            return 0;
        c[0] = sx; c[1] = sy; c[2] = x; c[3] = y;
        for (k = 0; k < 4; k++) {
            blank(&o[k]);
            o[k].cls = JW_SEN;
            for (j = 0; j < 4; j++)
                o[k].d[j] = c[ix[k][j]];
        }
        return (sx != x && sy != y) ? 4 : 0;
    }
    case JW_CMD_ENKO: {
        /* CZukeiEnko's constructor leaves it a whole circle: the sweep it
         * starts with is 2 pi (0x401921fb54442d18 at +0x34), the flattening
         * is 1 (+0x3c) and the 円弧 flag is off (+0xe8 = 1).  Every whole
         * circle in the sample drawings carries the trailing 1 as well. */
        double dx = x - sx, dy = y - sy;
        o->cls = JW_ENKO;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = sqrt(dx * dx + dy * dy);
        o->d[3] = atan2(dy, dx);
        o->d[4] = 2 * PI;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        o->n = 1;
        return o->d[2] > 0.0;
    }
    }
    return 0;
}

int jw_cmd_pending(jw_drawing *d, jw_obj *o, int max)
{
    if (current == JW_CMD_MOJI)
        return tracking ? moji(d, o, tx, ty) : 0;
    if (current == JW_CMD_RENZOKU) {
        int n = 0;
        /* the segment that is drawn but not yet in the drawing */
        if (step == 3 && max > 0) {
            blank(o);
            o->cls = JW_SEN;
            o->d[0] = sx;
            o->d[1] = sy;
            o->d[2] = rx;
            o->d[3] = ry;
            n = 1;
        }
        /* and the one following the mouse, from the last point */
        if (step != 0 && tracking && n < max) {
            blank(&o[n]);
            o[n].cls = JW_SEN;
            o[n].d[0] = step == 3 ? rx : sx;
            o[n].d[1] = step == 3 ? ry : sy;
            o[n].d[2] = tx;
            o[n].d[3] = ty;
            n++;
        }
        return n;
    }
    if (step != 2 || !tracking)
        return 0;
    return figure(o, max, tx, ty);
}

/* Take an element out and remember it, so 元に戻る can put it back.  `o` is
   the step it belongs to, so a cut can record the removal and the two pieces
   that replace it as one press-worth. */
static void erase(jw_drawing *d, int i, op_t *o)
{
    op_keep(o, d, i, 1);
    jw_remove(d, i);
}

/* Cut the piece between two points out of a line -- FUN_00471e40, the arm of
 * FUN_00470200 that handles CDataSen.
 *
 * Both points are put on the line first (the original drops a perpendicular
 * on to it: drawing a line in Jw_cad at screen y 300 and then cutting it with
 * clicks at y 330 and y 270 leaves two pieces that both end on the line, at
 * exactly the x of the clicks).  What is left is the piece before the nearer
 * cut and the piece after the further one, and either can be nothing.
 *
 * The element itself is kept and made into the first surviving piece; only a
 * second piece is added.  That is what the original does -- cutting the
 * middle out of an arc in Jw_cad left the first half where the whole one had
 * been and put the other half at the end.
 */
static void cut_line(jw_drawing *d, int i, double px, double py,
                     double qx, double qy)
{
    jw_obj was;
    op_t *rec;
    double ax, ay, ux, uy, len, t0, t1, t;
    int keep0, keep1;

    if (i < 0 || i >= d->ndrawn || d->obj[i].cls != JW_SEN)
        return;
    was = d->obj[i];
    ax = was.d[0];
    ay = was.d[1];
    ux = was.d[2] - ax;
    uy = was.d[3] - ay;
    len = sqrt(ux * ux + uy * uy);
    if (len < 1e-07)
        return;
    ux /= len;
    uy /= len;
    t0 = (px - ax) * ux + (py - ay) * uy;
    t1 = (qx - ax) * ux + (qy - ay) * uy;
    if (t1 < t0) {
        t = t0;
        t0 = t1;
        t1 = t;
    }
    if (t1 <= 1e-07 || len - 1e-07 <= t0)
        return;                 /* the piece misses the line altogether */

    keep0 = t0 > 1e-07;
    keep1 = t1 < len - 1e-07;
    rec = op_new();
    if (!keep0 && !keep1) {
        erase(d, i, rec);
        return;
    }
    op_keep(rec, d, i, 0);
    if (keep0) {
        d->obj[i].d[2] = ax + t0 * ux;
        d->obj[i].d[3] = ay + t0 * uy;
    } else {
        d->obj[i].d[0] = ax + t1 * ux;
        d->obj[i].d[1] = ay + t1 * uy;
    }
    if (keep0 && keep1) {
        jw_obj *o = jw_add(d, JW_SEN);
        if (o) {
            *o = was;
            o->d[0] = ax + t1 * ux;
            o->d[1] = ay + t1 * uy;
            if (rec)
                rec->n++;
        }
    }
}

/* The angle of a point round an arc, in the arc's own frame -- turned back
   by its tilt and unsquashed by its flattening, the way FUN_0042b7d0 does
   it.  Only the angle matters: clicking well inside the circle cuts it in
   exactly the same place as clicking on it. */
static double arc_angle(const jw_obj *o, double x, double y)
{
    double ex = x - o->d[0], ey = y - o->d[1];
    double c = cos(o->d[5]), s = sin(o->d[5]);
    double flat = o->d[6] > 0.0 ? o->d[6] : 1.0;

    return atan2((c * ey - s * ex) / flat, c * ex + s * ey);
}

static double turn(double a)
{
    while (a < 0.0)
        a += 2 * PI;
    while (a >= 2 * PI)
        a -= 2 * PI;
    return a;
}

/* The same for an arc.  A whole circle keeps one arc, starting where the
 * second point was and going the long way round; a part of one splits the
 * way a line does.  Both were driven through Jw_cad: cutting a whole circle
 * between 90 and 180 degrees left one arc at 180 sweeping 270, and cutting
 * that one again between 270 and 0 left 180+90 and 0+90.
 */
static void cut_arc(jw_drawing *d, int i, double px, double py,
                    double qx, double qy)
{
    jw_obj was;
    op_t *rec;
    double a0, sw, span, dir, u1, u2, t;
    int whole, keep0, keep1;

    if (i < 0 || i >= d->ndrawn || d->obj[i].cls != JW_ENKO)
        return;
    was = d->obj[i];
    a0 = was.d[3];
    sw = was.d[4];
    dir = sw < 0.0 ? -1.0 : 1.0;
    span = sw == 0.0 ? 2 * PI : fabs(sw);
    whole = span >= 6.283185207179586;
    u1 = turn((arc_angle(&was, px, py) - a0) * dir);
    u2 = turn((arc_angle(&was, qx, qy) - a0) * dir);

    rec = op_new();
    if (whole) {
        double gap = turn(u2 - u1);
        if (gap <= 0.0)
            return;
        op_keep(rec, d, i, 0);
        d->obj[i].d[3] = turn(a0 + dir * u2);
        d->obj[i].d[4] = dir * (2 * PI - gap);
        return;
    }
    if (u2 < u1) {
        t = u1;
        u1 = u2;
        u2 = t;
    }
    if (u2 <= 1e-07 || span - 1e-07 <= u1)
        return;
    keep0 = u1 > 1e-07;
    keep1 = u2 < span - 1e-07;
    if (!keep0 && !keep1) {
        erase(d, i, rec);
        return;
    }
    op_keep(rec, d, i, 0);
    if (keep0) {
        d->obj[i].d[4] = dir * u1;
    } else {
        d->obj[i].d[3] = turn(a0 + dir * u2);
        d->obj[i].d[4] = dir * (span - u2);
    }
    if (keep0 && keep1) {
        jw_obj *o = jw_add(d, JW_ENKO);
        if (o) {
            *o = was;
            o->d[3] = turn(a0 + dir * u2);
            o->d[4] = dir * (span - u2);
            if (rec)
                rec->n++;
        }
    }
}

/* コーナー処理 -- two lines, cut or carried on to where they meet.
 *
 * What survives is the piece on the side the line was clicked: drawing an L
 * with a gap in Jw_cad and clicking each near the gap carries both on to the
 * corner, and clicking two lines that already cross, each on one side, cuts
 * both back to the crossing.  Either way both lines stay where they were in
 * the drawing -- the original changes them in place, it does not remake them.
 */
static void corner(jw_drawing *d, int a, double ax, double ay,
                   int b, double bx, double by)
{
    jw_obj *p = &d->obj[a], *q = &d->obj[b];
    double pdx, pdy, qdx, qdy, den, tp, tq, ix, iy, cp, cq;
    op_t *rec;

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    pdx = p->d[2] - p->d[0];
    pdy = p->d[3] - p->d[1];
    qdx = q->d[2] - q->d[0];
    qdy = q->d[3] - q->d[1];
    den = pdx * qdy - pdy * qdx;
    if (den == 0.0)
        return;                 /* parallel: there is no corner */
    tp = ((q->d[0] - p->d[0]) * qdy - (q->d[1] - p->d[1]) * qdx) / den;
    tq = ((q->d[0] - p->d[0]) * pdy - (q->d[1] - p->d[1]) * pdx) / den;
    ix = p->d[0] + tp * pdx;
    iy = p->d[1] + tp * pdy;
    /* where each click falls along its own line */
    cp = ((ax - p->d[0]) * pdx + (ay - p->d[1]) * pdy) / (pdx * pdx + pdy * pdy);
    cq = ((bx - q->d[0]) * qdx + (by - q->d[1]) * qdy) / (qdx * qdx + qdy * qdy);

    rec = op_new();
    op_keep(rec, d, a, 0);
    op_keep(rec, d, b, 0);
    if (cp < tp) {
        p->d[2] = ix;
        p->d[3] = iy;
    } else {
        p->d[0] = ix;
        p->d[1] = iy;
    }
    if (cq < tq) {
        q->d[2] = ix;
        q->d[3] = iy;
    } else {
        q->d[0] = ix;
        q->d[1] = iy;
    }
}

static void sel_free(void)
{
    free(sel_was);
    free(sel_at);
    sel_was = 0;
    sel_at = 0;
    sel_n = 0;
}

int jw_cmd_sel_count(const jw_drawing *d)
{
    int i, n = 0;

    if (!d)
        return 0;
    for (i = 0; i < d->nobj; i++)
        if (d->obj[i].flags & 2)
            n++;
    return n;
}

static void sel_clear(jw_drawing *d)
{
    int i;

    if (d)
        for (i = 0; i < d->nobj; i++)
            d->obj[i].flags = (unsigned short)(d->obj[i].flags & ~2u);
    sel_free();
}

/* Everything the box holds whole.  An element that only crosses it is left
 * alone: the original was given a box over Test5 and saved it, and of the
 * lines that crossed the box not one came back with the flag on, while
 * every line inside it did.  Texts are in only when the second corner was
 * the right button -- 「(L)文字を除く (R)文字を含む」, string 5326, and the
 * same run bears it out: 28 texts sat inside the box and a left click took
 * none of them. */
static void sel_box(jw_drawing *d, int with_text)
{
    double x0 = sel_x0 < sel_x1 ? sel_x0 : sel_x1;
    double x1 = sel_x0 < sel_x1 ? sel_x1 : sel_x0;
    double y0 = sel_y0 < sel_y1 ? sel_y0 : sel_y1;
    double y1 = sel_y0 < sel_y1 ? sel_y1 : sel_y0;
    int i;

    if (!d)
        return;
    for (i = 0; i < d->ndrawn; i++) {
        jw_obj *o = &d->obj[i];
        double a, b, c2, e;
        if (o->cls == JW_MOJI && !with_text)
            continue;
        jw_obj_box(o, &a, &b, &c2, &e);
        if (a >= x0 && c2 <= x1 && b >= y0 && e <= y1)
            o->flags = (unsigned short)(o->flags | 2u);
    }
}

/* 選択確定.  The selection is taken as it stands and 基準点 becomes where
 * the mouse is -- the bar's own label for it is ≪基準点：マウス位置≫
 * (string 6144).  Driving the original bears it out: after a confirm its
 * copies came out offset from a point that was neither of the box corners
 * nor any click, but the place the cursor happened to be sitting. */
static int sel_confirm(jw_drawing *d)
{
    int i, n = jw_cmd_sel_count(d);

    if (!d || n <= 0 || !tracking)
        return 0;
    sel_free();
    sel_was = (jw_obj *)malloc((size_t)n * sizeof *sel_was);
    sel_at = (int *)malloc((size_t)n * sizeof *sel_at);
    if (!sel_was || !sel_at) {
        sel_free();
        return 0;
    }
    for (i = 0; i < d->nobj; i++)
        if (d->obj[i].flags & 2) {
            sel_at[sel_n] = i;
            sel_was[sel_n] = d->obj[i];
            sel_n++;
        }
    base_x = tx;
    base_y = ty;
    /* 範囲選択 has nothing to place: confirming there only settles what is
       picked, and it is the next command that does something with it. */
    sel_step = current == JW_CMD_HANI ? 4 : 3;
    return 1;
}

/* 消去 entered with a settled selection takes it out at once.  The original
 * does exactly that: 範囲選択 over Test5, 選択確定, then 消去, and the file
 * it saved had 25 of its 46 lines gone and nothing left picked. */
int jw_cmd_sel_erase(jw_drawing *d)
{
    op_t *o;
    int i, n = 0;

    if (!d || sel_n <= 0)
        return 0;
    o = op_new();
    for (i = d->nobj - 1; i >= 0; i--)
        if (d->obj[i].flags & 2) {
            op_keep(o, d, i, 1);
            jw_remove(d, i);
            n++;
        }
    sel_free();
    sel_step = 0;
    return n > 0;
}

/* One click while the selection is being placed. */
static void sel_place(jw_drawing *d, double x, double y)
{
    double dx = x - base_x, dy = y - base_y;
    int i;

    if (!d || sel_n <= 0)
        return;
    if (current == JW_CMD_IDOU) {
        op_t *o = op_new();
        for (i = 0; i < sel_n; i++) {
            int at = sel_at[i];
            if (at >= d->nobj)
                continue;
            op_keep(o, d, at, 0);
            d->obj[at] = sel_was[i];
            jw_obj_move(&d->obj[at], dx, dy);
            d->obj[at].flags = (unsigned short)(d->obj[at].flags | 2u);
        }
        return;
    }
    {   /* 複写: every click leaves another copy, all of them measured from
           the one 基準点 -- three clicks in the original left three copies,
           at one, two and three times the step. */
        int made = 0;
        for (i = 0; i < sel_n; i++) {
            jw_obj *p = jw_add(d, sel_was[i].cls);
            int at;
            if (!p)
                break;
            at = (int)(p - d->obj);
            *p = sel_was[i];
            jw_obj_move(p, dx, dy);
            /* a copy is not itself selected: in the original the new
               elements come out in their own colours while the ones that
               were picked stay pink */
            p->flags = (unsigned short)(p->flags & ~2u);
            p->id = 0;
            (void)at;
            made++;
        }
        op_push(made);
    }
}

int jw_cmd_sel_box(double *x0, double *y0, double *x1, double *y1)
{
    if (sel_step != 1 || !tracking)
        return 0;
    *x0 = sel_x0;
    *y0 = sel_y0;
    *x1 = tx;
    *y1 = ty;
    return 1;
}

int jw_cmd_sel_ghost(double *dx, double *dy)
{
    if (sel_step != 3 || sel_n <= 0 || !tracking)
        return 0;
    *dx = tx - base_x;
    *dy = ty - base_y;
    return 1;
}

int jw_cmd_bar_enabled(const jw_drawing *d, int id)
{
    switch (id) {
    case 1120:                  /* 選択確定 */
        return sel_step == 2 && jw_cmd_sel_count(d) > 0;
    case 1064:                  /* 基準点変更 -- not done */
        return 0;
    case 1067:                  /* 選択解除 */
        return jw_cmd_sel_count(d) > 0;
    case 1066:                  /* 全選択 */
        return sel_step != 3;
    }
    return -1;                  /* not one this port knows about */
}

int jw_cmd_bar(jw_drawing *d, int id)
{
    if (current != JW_CMD_HANI && current != JW_CMD_FUKUSHA
        && current != JW_CMD_IDOU)
        return 0;
    if (!jw_cmd_bar_enabled(d, id))
        return 0;
    switch (id) {
    case 1120:
        return sel_confirm(d);
    case 1067:
        sel_clear(d);
        sel_step = 0;
        return 1;
    case 1066: {                /* 全選択: everything that is drawn */
        int i;
        if (!d)
            return 0;
        for (i = 0; i < d->ndrawn; i++)
            d->obj[i].flags = (unsigned short)(d->obj[i].flags | 2u);
        sel_step = 2;
        return 1;
    }
    }
    return 0;
}

void jw_cmd_point(jw_drawing *d, const jw_view *v,
                  double x, double y, int button)
{
    if (current == JW_CMD_HANI || current == JW_CMD_FUKUSHA
        || current == JW_CMD_IDOU) {
        switch (sel_step) {
        case 0:
            if (button != 0)    /* (R) picks a 連続線, which is not done */
                return;
            sel_clear(d);
            sel_x0 = sel_x1 = x;
            sel_y0 = sel_y1 = y;
            sel_step = 1;
            return;
        case 1:
            sel_x1 = x;
            sel_y1 = y;
            sel_box(d, button != 0);
            sel_step = jw_cmd_sel_count(d) > 0 ? 2 : 0;
            return;
        case 2:
            /* another box, on top of what is already picked */
            if (button != 0)
                return;
            sel_x0 = sel_x1 = x;
            sel_y0 = sel_y1 = y;
            sel_step = 1;
            return;
        default:
            if (button != 0)
                return;
            sel_place(d, x, y);
            return;
        }
    }
    if (current == JW_CMD_MOJI) {
        /* Place what has been typed.  Everything about the text comes from
         * the drawing's current style, which sits just after the ten in the
         * header: the size, the spacing and the colour.  A text placed in
         * Jw_cad has exactly those, and the run is as long as the characters
         * make it -- half width ones advance cw/2 and the gaps are sp/2, and
         * the last gap is not counted (six of them at cw 10 sp 1 came to
         * 32.5, not 30). */
        jw_obj tmp, *o;

        if (button != 0 || !d || line_n == 0)
            return;
        if (!moji(d, &tmp, x, y))
            return;
        o = jw_add(d, JW_MOJI);
        if (!o)
            return;
        tmp.layer = o->layer;
        tmp.lgroup = o->lgroup;
        *o = tmp;
        o->face = jw_add_str(d, JW_MOJI_FACE);
        op_push(1);
        line_n = 0;
        line_gen++;
        return;
    }
    if (current == JW_CMD_ZOKUSEI) {
        /* Take the pen and the layer off an element and make them the ones
         * new elements get.  Driving Jw_cad bears both out: after 属性取得 on
         * a line of type 6 on layer 0, a 複線 came out type 6 on layer 0
         * where before it was type 1 on layer 10. */
        int i;
        if (button != 0 || !d)
            return;             /* (R) turns the layer display round */
        i = jw_pick(d, v, x, y, 0);
        if (i < 0)
            return;
        d->write_ltype = d->obj[i].ltype ? d->obj[i].ltype : 1;
        d->write_color = d->obj[i].color;
        d->write_width = d->obj[i].width;
        {   /* and the write layer, which is the group's own */
            int g = d->obj[i].lgroup & 15, k;
            for (k = 0; k < 16; k++)
                if (d->group[k].state == 3 && k != g)
                    d->group[k].state = 2;
            d->group[g].state = 3;
            d->group[g].write_layer = d->obj[i].layer & 15;
            for (k = 0; k < 16; k++)
                if (d->group[g].layer[k].state == 3)
                    d->group[g].layer[k].state = 2;
            d->group[g].layer[d->group[g].write_layer].state = 3;
        }
        return;
    }
    if (current == JW_CMD_FUKUSEN) {
        /* Three clicks: the line, then which side and how far, then one more
         * to draw it.  That third click only confirms -- moving it further
         * out in Jw_cad does not move the copy, which stays where the second
         * click put it.  The copy is a new element with the write pen on the
         * write layer, not a clone: offsetting a dashed line on layer 0 in
         * Test1 gave a plain one on the write layer. */
        int i;
        if (button != 0 || !d)
            return;
        if (para_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            para_obj = i;
            para_step = 1;
            return;
        }
        if (para_step == 1) {
            const jw_obj *o = &d->obj[para_obj];
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len = sqrt(dx * dx + dy * dy);
            if (len < 1e-09) {
                para_step = 0;
                return;
            }
            para_off = ((x - o->d[0]) * -dy + (y - o->d[1]) * dx) / len;
            para_step = 2;
            return;
        }
        para_step = 0;
        if (para_obj >= 0 && para_obj < d->ndrawn
            && d->obj[para_obj].cls == JW_SEN) {
            jw_obj src = d->obj[para_obj];
            double dx = src.d[2] - src.d[0], dy = src.d[3] - src.d[1];
            double len = sqrt(dx * dx + dy * dy);
            jw_obj *o;
            if (len < 1e-09)
                return;
            o = jw_add(d, JW_SEN);
            if (!o)
                return;
            o->d[0] = src.d[0] + -dy / len * para_off;
            o->d[1] = src.d[1] + dx / len * para_off;
            o->d[2] = src.d[2] + -dy / len * para_off;
            o->d[3] = src.d[3] + dx / len * para_off;
            op_push(1);
        }
        return;
    }
    if (current == JW_CMD_SHINSHUKU) {
        /* Pick a line, then say where its end should go.  Which end moves is
         * settled by the second point, not the first: clicking the left half
         * of a line in Jw_cad and then a point past its right end moves the
         * right end.  The point is dropped on to the line first, the same
         * way a partial erase drops its two.  A tie goes to the first end. */
        int i;
        if (button != 0 || !d)
            return;             /* (R) is 線切断, (RR) 基準線指定 */
        if (stretch_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            stretch_obj = i;
            stretch_step = 1;
            return;
        }
        stretch_step = 0;
        i = stretch_obj;
        if (i >= 0 && i < d->ndrawn && d->obj[i].cls == JW_SEN) {
            jw_obj *o = &d->obj[i];
            double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
            double len2 = dx * dx + dy * dy, t, nx, ny;
            if (len2 < 1e-14)
                return;
            t = ((x - o->d[0]) * dx + (y - o->d[1]) * dy) / len2;
            nx = o->d[0] + t * dx;
            ny = o->d[1] + t * dy;
            op_keep(op_new(), d, i, 0);
            if (fabs(t) <= fabs(t - 1.0)) {
                o->d[0] = nx;
                o->d[1] = ny;
            } else {
                o->d[2] = nx;
                o->d[3] = ny;
            }
        }
        return;
    }
    if (current == JW_CMD_CORNER) {
        int i;
        if (button != 0 || !d)
            return;             /* (R) is 線切断, which is not done here */
        if (corner_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            corner_obj = i;
            corner_x = x;
            corner_y = y;
            corner_step = 2;    /* CZukeiCorner's own numbering */
            return;
        }
        /* the second pick flips view+0x82bc, so a tie goes the other way and
           the same line is not found twice */
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && i != corner_obj)
            corner(d, corner_obj, corner_x, corner_y, i, x, y);
        corner_step = 0;
        return;
    }
    if (current == JW_CMD_SHOUKYO) {
        /* 「線・円マウス(L)部分消し　図形マウス(R)消去」 -- string 10111,
         * the original's own words, and driving it bears them out: a right
         * click on one side of a rectangle in Jw_cad leaves 49 lines of 50,
         * and that side is the one that goes.  The left button takes a piece
         * out of a line instead, through a three-step selection
         * (CZukeiShoukyo's vtable slot 9, its +0x21c going 0 to 3), which is
         * not done here.
         *
         * Which element: the one the highlight would be on, and that is
         * found with FUN_0044a270's mode 0 (CZukeiShoukyo's slot 11, the one
         * that runs as the mouse moves). */
        int i;
        if (!d)
            return;
        if (button == 1) {
            i = jw_pick(d, v, x, y, 0);
            if (i >= 0)
                erase(d, i, op_new());
            cut_step = 0;
            return;
        }
        /* the left button: pick, then the two ends of the piece */
        if (cut_step == 0) {
            /* FUN_0070dc20 picks with mode 3, which is the one that leaves
               points alone -- there is no piece of a point to take out. */
            cut_obj = jw_pick(d, v, x, y, 3);
            if (cut_obj >= 0)
                cut_step = 1;
            return;
        }
        if (cut_step == 1) {
            cut_x = x;
            cut_y = y;
            cut_step = 2;
            return;
        }
        if (cut_obj >= 0 && cut_obj < d->ndrawn) {
            if (d->obj[cut_obj].cls == JW_ENKO)
                cut_arc(d, cut_obj, cut_x, cut_y, x, y);
            else
                cut_line(d, cut_obj, cut_x, cut_y, x, y);
        }
        cut_step = 0;
        return;
    }
    if (button == 1) {
        /* Every prompt ends "(L)free  (R)Read": the right button takes the
         * nearest read point instead of where the mouse is, and when there
         * is nothing to read the click does nothing at all -- Jw_cad places
         * no point either (右クリックを端点から 11 画素離すと何も起きない). */
        double sxr, syr;
        if (!d || !jw_read(d, v, x, y, &sxr, &syr))
            return;
        x = sxr;
        y = syr;
    }
    if (current == JW_CMD_TEN) {
        /* CZukeiTen: one point and it is placed.  Its own prompt never
           changes while it waits (FUN_004efbb0(0x1500)). */
        if (d) {
            jw_obj *o = jw_add(d, JW_TEN);
            if (o) {
                o->d[0] = x;
                o->d[1] = y;
                op_push(1);
            }
        }
        return;
    }
    if (current == JW_CMD_RENZOKU) {
        if (step == 0) {
            sx = x;
            sy = y;
            step = 2;
        } else if (step == 2) {
            rx = x;
            ry = y;
            step = 3;
        } else {
            if (d) {
                jw_obj *o = jw_add(d, JW_SEN);
                if (o) {
                    o->d[0] = sx;
                    o->d[1] = sy;
                    o->d[2] = rx;
                    o->d[3] = ry;
                    op_push(1);
                }
            }
            sx = rx;
            sy = ry;
            rx = x;
            ry = y;
        }
        tx = x;
        ty = y;
        return;
    }
    if (current != JW_CMD_SEN && current != JW_CMD_ENKO
        && current != JW_CMD_KUKEI)
        return;
    if (step == 0) {
        sx = x;
        sy = y;
        step = 2;
        tx = x;
        ty = y;
        return;
    }
    if (d) {
        jw_obj tmp[JW_CMD_MAXFIG];
        int n = figure(tmp, JW_CMD_MAXFIG, x, y), k, put = 0;
        for (k = 0; k < n; k++) {
            jw_obj *o = jw_add(d, tmp[k].cls);
            int i;
            if (!o)
                break;
            for (i = 0; i < 8; i++)
                o->d[i] = tmp[k].d[i];
            o->n = tmp[k].n;
            put++;
        }
        op_push(put);
    }
    step = 0;
    tracking = 0;
}
