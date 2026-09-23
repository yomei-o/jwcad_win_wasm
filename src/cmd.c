#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cmd.h"
#include "pick.h"
#include "text.h"
#include "gen/prompts.h"
#include "gen/sunpo.h"

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
/* 面取 works the same way and keeps its pick in the same three */

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

/* 寸法 (CZukeiSunpo).  Four clicks, and the prompts say what each is for:
 *
 *   0  5329  [寸法] 引出し線の始点を指示して下さい。(L)free (R)Read
 *   1  5330  ■ 寸法線の位置を指示して下さい。(L)free (R)Read
 *   2  5331  ○ 寸法の始点を指示して下さい
 *   3  5332  ● 寸法の終点を指示して下さい。
 *
 * The last two have no "(L)free" on them and that is not an oversight: in
 * the original a click there does nothing at all unless it reads a point.
 * Driving it, a left or a right button on a line's end both moved it on,
 * and a click in open space never did.
 *
 * What comes out is six ordinary elements -- the settings that decide them
 * are in src/gen/sunpo.h, and every one of them showed up in the dimension
 * the original drew for us. */
static int sun_step;
static double sun_hx, sun_hy;   /* 引出し線の始点                          */
static double sun_lx, sun_ly;   /* 寸法線の位置                            */
static double sun_sx, sun_sy;   /* 寸法の始点, once it has been read       */
static int sun_deg = 0;         /* 0 or 90 -- the bar's 0ﾟ/90ﾟ button      */

/* 中心線: the two lines it runs between, and the first of its two points */
static int chu_a = -1, chu_b = -1, chu_step;
/* 接線: the circle picked first, and where it was picked -- which of the
   four common tangents comes out is settled by the side each circle was
   pointed at. */
static int ses_a = -1, ses_step;
static double ses_x, ses_y;
/* 角度指定 and 円上点指定 settle on a line first and then take two points
   along it: where it passes through, which way it runs, and the first of the
   two. */
static double ses_lx, ses_ly, ses_ux, ses_uy, ses_t0;
/* which of the bar's four buttons is in force: 0 円→円 (1689), 1 点→円
   (1690).  角度指定 (1691) and 円上点指定 (1692) are not done. */
static int ses_mode = 1689;     /* the bar button: 1689..1692 */
/* 接円: the two elements picked, then a click that says which of the four
   circles of that radius is wanted -- the status line counts them 【 4 − n 】. */
static int sek_a = -1, sek_b = -1, sek_step;
/* 曲線: the points clicked so far, kept until 作図実行 is pressed. */
#define CV_MAX 64
static double cv_x[CV_MAX], cv_y[CV_MAX];
static int cv_n;
/* which of the bar's four is in force: 1691 スプライン is the one the
   original enters in; サイン (1689), ２次 (1690) and ベジェ (1692) are not
   done, and pressing 作図実行 in those draws nothing. */
static int cv_mode = 1691;
/* ハッチ: the closed boundary that was picked, as a ring of corners, or a
   circle.  Right-clicking one line of a closed chain takes the whole chain;
   right-clicking a circle takes the circle. */
#define HT_MAX 256
static double ht_x[HT_MAX], ht_y[HT_MAX];
static int ht_n;                /* corners in the ring, 0 when none */
static double ht_cx, ht_cy, ht_r;
static int ht_round;            /* the boundary is a circle */
static void ht_mode_set(int id);
static int ht_mode = 1689;      /* 1線, the one the original enters in */
/* The bar keeps one set of numbers for 1線・2線・3線 and another for
   ┬┴┬・図形, and pressing a mode button puts that set up: 1線 shows 角度 45・
   ピッチ 10・線間隔 1, ┬┴┬ shows 角度 0・縦ピッチ 3・横ピッチ 6, and going
   back shows 45・10・1 again, whatever was typed in between (read out of the
   original with tools/jwdraw.ps1's `read:`). */
static char ht_keep[2][3][16] = {
    { "45", "10", "1" }, { "0", "3", "6" }
};
static double chu_x, chu_y;

/* ２線: the line the pair runs along, and the first of the two points */
static double nisen_a, nisen_b;
static int nisen_obj = -1, nisen_step;
static double nisen_x, nisen_y;

/* The boxes on the command bar that hold a number.  Jw_cad keeps these in
 * the command itself, not in the registry, and the values below are the ones
 * the original comes up with: a 多角形 drawn straight after starting came out
 * a pentagon of 1000 (real) radius with its base level.
 *
 * They are what makes the rest of the commands usable, so the port lets them
 * be typed into: a press puts the caret in one (jw_cmd_box_click) and the
 * keys go there instead of to the drawing.
 */
/* The ids are not unique: 1411 is the first combo of nearly every bar, so
   a box belongs to a command as well as to an id. */
static struct { unsigned short cmd, id; char t[16]; } box[] = {
    { JW_CMD_TAKAKU, 1411, "1000" },    /* 寸法      */
    { JW_CMD_TAKAKU, 1413, "5" },       /* 角数      */
    { JW_CMD_TAKAKU, 1414, "0" },       /* 底辺角度  */
    { JW_CMD_MENTORI, 1411, "" },       /* 面取の寸法 -- empty to start with,
                                           the way the original's is */
    { JW_CMD_BUNKATSU, 1411, "" },      /* 分割数, likewise */
    { JW_CMD_NISEN, 1412, "" },         /* ２線の間隔, "a,b"         */
    { JW_CMD_SEKIEN, 1411, "" },        /* 接円の半径, likewise */
    { JW_CMD_KYOKUSEN, 1411, "7" },     /* 曲線の分割数; the original
                                           comes up with 7 */
    { JW_CMD_SESSEN, 1412, "" },        /* 接線 角度指定 の角度 */
    { JW_CMD_HATCH, 1419, "45" },       /* ハッチの角度   */
    { JW_CMD_HATCH, 1411, "10" },       /* ハッチのピッチ */
    { JW_CMD_HATCH, 1412, "1" },        /* ハッチの線間隔（２線・３線） */
};
static int box_focus;

/* 多角形 (CZukeiTakakukei).  The bar's 中心→頂点指定 is the mode it starts
 * in, and with a 寸法 in the box one click on the centre draws the whole
 * thing -- which is what the original does: a click left a regular pentagon
 * behind, and another click left a second one.
 */

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
    if (id == JW_CMD_SUNPO)
        sun_step = 0;
    if (id == JW_CMD_NISEN) {
        nisen_step = 0;
        nisen_obj = -1;
    }
    if (id == JW_CMD_SESSEN) {
        ses_step = 0;
        ses_a = -1;
        ses_mode = 1689;        /* 円→円, the one the original enters in */
    }
    if (id == JW_CMD_SEKIEN) {
        sek_step = 0;
        sek_a = sek_b = -1;
    }
    if (id == JW_CMD_KYOKUSEN) {
        cv_n = 0;
        cv_mode = 1691;
    }
    if (id == JW_CMD_HATCH) {
        ht_n = 0;
        ht_round = 0;
        ht_mode_set(1689);      /* and the bar's numbers with it */
    }
    if (id == JW_CMD_CHUSHIN) {
        chu_step = 0;
        chu_a = chu_b = -1;
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
    case JW_CMD_BUNKATSU:
    case JW_CMD_MENTORI:
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
    case JW_CMD_TAKAKU:
        /* 「中心点を指示してください (L)free (R)Read」 */
        return JW_STR_5309;
    case JW_CMD_SUNPO:
        if (sun_step == 0)
            return JW_STR_5329;
        if (sun_step == 1)
            return JW_STR_5330;
        return sun_step == 2 ? JW_STR_5331 : JW_STR_5332;
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

/* 面取（角面・辺寸法）.
 *
 * The same two lines as a corner, but each stops short of the crossing by
 * the 寸法 box's distance and a third line joins the two ends.  Driven in
 * the original with 寸法 2000 on a 1/200 group: an L of two lines meeting at
 * (126.4198,-222.5335) came out with the level one ending 10 mm short at
 * 116.4198, the upright one starting 10 mm up at -212.5335, and a new line
 * between exactly those two points.  The distance is therefore 寸法 over the
 * layer group's scale, along each line from the crossing.
 *
 * Both of the old lines are written down cut end first -- the level one's
 * ends came back swapped -- so that is how they are rewritten here. */
static void mentori(jw_drawing *d, int a, double ax, double ay,
                    int b, double bx, double by)
{
    jw_obj *p = &d->obj[a], *q = &d->obj[b];
    double pdx, pdy, qdx, qdy, den, tp, tq, ix, iy, cp, cq;
    double plen, qlen, dist, pux, puy, qux, quy, px, py, qx, qy;
    const char *sz = jw_cmd_box(1411);
    int wg = 0, i;
    op_t *rec;
    jw_obj *n;

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    dist = sz ? atof(sz) : 0.0;
    if (dist <= 0.0)
        return;                 /* no size typed in: nothing to cut */
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        dist /= d->group[wg].scale;
    pdx = p->d[2] - p->d[0];
    pdy = p->d[3] - p->d[1];
    qdx = q->d[2] - q->d[0];
    qdy = q->d[3] - q->d[1];
    den = pdx * qdy - pdy * qdx;
    if (den == 0.0)
        return;
    tp = ((q->d[0] - p->d[0]) * qdy - (q->d[1] - p->d[1]) * qdx) / den;
    tq = ((q->d[0] - p->d[0]) * pdy - (q->d[1] - p->d[1]) * pdx) / den;
    ix = p->d[0] + tp * pdx;
    iy = p->d[1] + tp * pdy;
    cp = ((ax - p->d[0]) * pdx + (ay - p->d[1]) * pdy) / (pdx * pdx + pdy * pdy);
    cq = ((bx - q->d[0]) * qdx + (by - q->d[1]) * qdy) / (qdx * qdx + qdy * qdy);
    plen = sqrt(pdx * pdx + pdy * pdy);
    qlen = sqrt(qdx * qdx + qdy * qdy);
    if (plen == 0.0 || qlen == 0.0)
        return;
    /* the way each line runs from the crossing towards the end that stays */
    pux = (cp < tp ? -pdx : pdx) / plen;
    puy = (cp < tp ? -pdy : pdy) / plen;
    qux = (cq < tq ? -qdx : qdx) / qlen;
    quy = (cq < tq ? -qdy : qdy) / qlen;
    px = ix + pux * dist;
    py = iy + puy * dist;
    qx = ix + qux * dist;
    qy = iy + quy * dist;

    rec = op_new();
    op_keep(rec, d, a, 0);
    op_keep(rec, d, b, 0);
    {   /* cut end first, then the end that stays */
        double kpx = cp < tp ? p->d[0] : p->d[2];
        double kpy = cp < tp ? p->d[1] : p->d[3];
        double kqx = cq < tq ? q->d[0] : q->d[2];
        double kqy = cq < tq ? q->d[1] : q->d[3];
        p->d[0] = px; p->d[1] = py; p->d[2] = kpx; p->d[3] = kpy;
        q->d[0] = qx; q->d[1] = qy; q->d[2] = kqx; q->d[3] = kqy;
    }
    n = jw_add(d, JW_SEN);
    if (n) {
        n->d[0] = px;
        n->d[1] = py;
        n->d[2] = qx;
        n->d[3] = qy;
        /* the new line belongs to the same step as the two that were cut,
           so one press of 元に戻る takes the whole chamfer back */
        if (rec)
            rec->n = 1;
    }
}

/* 分割（等距離分割）between two lines.
 *
 * The original was given two lines and 分割数 4: it left three lines between
 * them, evenly spaced.  A second run with two lines that were neither
 * parallel nor the same length settles what "evenly" means -- each new line
 * is the two ends of the picked ones walked towards each other: start to
 * start and end to end, k/n of the way along.  Both of its dividers came out
 * exactly there.
 *
 * (The original wrote that pair the other way round, end first; which way it
 * picks is not worked out, and it makes no difference to the line.) */
static void bunkatsu(jw_drawing *d, int a, int b)
{
    const jw_obj *p = &d->obj[a], *q = &d->obj[b];
    const char *ns = jw_cmd_box(1411);
    int n = ns ? atoi(ns) : 0, k, made = 0;
    double ax0, ay0, ax1, ay1, bx0, by0, bx1, by1;

    if (a == b || p->cls != JW_SEN || q->cls != JW_SEN)
        return;
    if (n < 2 || n > 1000)
        return;
    ax0 = p->d[0]; ay0 = p->d[1]; ax1 = p->d[2]; ay1 = p->d[3];
    bx0 = q->d[0]; by0 = q->d[1]; bx1 = q->d[2]; by1 = q->d[3];
    for (k = 1; k < n; k++) {
        double t = (double)k / n;
        jw_obj *o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->d[0] = ax0 + (bx0 - ax0) * t;
        o->d[1] = ay0 + (by0 - ay0) * t;
        o->d[2] = ax1 + (bx1 - ax1) * t;
        o->d[3] = ay1 + (by1 - ay1) * t;
        made++;
    }
    op_push(made);
}

/* ２線.
 *
 * A line is picked to run along, then two points say where the pair starts
 * and stops.  What comes out is two lines parallel to the picked one, as far
 * from it as the two numbers in the 間隔 box say -- one to each side -- and
 * as long as the two points, taken along the line.
 *
 * Which side is which follows the picked line's own direction, not where it
 * was clicked: with 間隔 2000,1000 on a 1/200 group the original put the
 * first 10 mm to the right of the way the line runs and the second 5 mm to
 * the left, and drawing the same line the other way round swapped them over
 * while clicking above or below it changed nothing. */
static int nisen_gap(const jw_drawing *d)
{
    const char *t = jw_cmd_box(1412);
    const char *p;
    int wg = 0, i;
    double s;

    if (!t || !*t)
        return 0;
    nisen_a = atof(t);
    p = strchr(t, ',');
    nisen_b = p ? atof(p + 1) : nisen_a;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    s = d->group[wg].scale;
    if (s > 0.0) {
        nisen_a /= s;
        nisen_b /= s;
    }
    return 1;
}

static void nisen(jw_drawing *d, double x, double y)
{
    const jw_obj *o = &d->obj[nisen_obj];
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double len = sqrt(dx * dx + dy * dy), ux, uy, vx, vy;
    double s0, s1, t0, made = 0;
    int k;

    if (len == 0.0)
        return;
    ux = dx / len;
    uy = dy / len;
    vx = -uy;
    vy = ux;
    /* the two points, along the line the pair runs on */
    s0 = (nisen_x - o->d[0]) * ux + (nisen_y - o->d[1]) * uy;
    s1 = (x - o->d[0]) * ux + (y - o->d[1]) * uy;
    t0 = (o->d[0]) * 0.0;       /* the line itself is the zero of the offset */
    (void)t0;
    for (k = 0; k < 2; k++) {
        double off = k ? nisen_b : -nisen_a;
        jw_obj *n = jw_add(d, JW_SEN);
        if (!n)
            break;
        n->d[0] = o->d[0] + ux * s0 + vx * off;
        n->d[1] = o->d[1] + uy * s0 + vy * off;
        n->d[2] = o->d[0] + ux * s1 + vx * off;
        n->d[3] = o->d[1] + uy * s1 + vy * off;
        made++;
    }
    op_push((int)made);
}

/* 中心線.
 *
 * Two lines are picked and then two points, and what comes out is one line
 * along the middle of them, as long as the two points make it.  Driven in
 * the original:
 *
 *   two level lines 259.7667 apart gave a line exactly half way between,
 *   and the two points kept their own place along it;
 *   two lines that meet at 0 and 14.036 degrees gave one at 7.018 -- the
 *   bisector -- and the two points came out at their feet on it.
 *
 * So the middle of two lines that run together is the line half way, of two
 * that cross it is the bisector through the crossing, and the two points are
 * dropped onto it square. */
static int chushin_line(const jw_drawing *d, double *px, double *py,
                        double *ux, double *uy)
{
    const jw_obj *p = &d->obj[chu_a], *q = &d->obj[chu_b];
    double adx = p->d[2] - p->d[0], ady = p->d[3] - p->d[1];
    double bdx = q->d[2] - q->d[0], bdy = q->d[3] - q->d[1];
    double alen = sqrt(adx * adx + ady * ady);
    double blen = sqrt(bdx * bdx + bdy * bdy);
    double den, t;

    if (alen == 0.0 || blen == 0.0)
        return 0;
    adx /= alen;
    ady /= alen;
    bdx /= blen;
    bdy /= blen;
    if (adx * bdx + ady * bdy < 0.0) {      /* point them the same way */
        bdx = -bdx;
        bdy = -bdy;
    }
    den = adx * bdy - ady * bdx;
    if (fabs(den) < 1e-12) {
        /* they run together: half way between, along the first one */
        double wx = q->d[0] - p->d[0], wy = q->d[1] - p->d[1];
        double along = wx * adx + wy * ady;
        *px = p->d[0] + (wx - along * adx) / 2.0;
        *py = p->d[1] + (wy - along * ady) / 2.0;
        *ux = adx;
        *uy = ady;
        return 1;
    }
    /* they cross: the bisector through the crossing */
    t = ((q->d[0] - p->d[0]) * bdy - (q->d[1] - p->d[1]) * bdx) / den;
    *px = p->d[0] + t * adx;
    *py = p->d[1] + t * ady;
    *ux = adx + bdx;
    *uy = ady + bdy;
    t = sqrt(*ux * *ux + *uy * *uy);
    if (t == 0.0)
        return 0;
    *ux /= t;
    *uy /= t;
    return 1;
}

static void chushin(jw_drawing *d, double x, double y)
{
    double px, py, ux, uy, t0, t1;
    jw_obj *o;

    if (chu_a < 0 || chu_b < 0 || chu_a >= d->nobj || chu_b >= d->nobj)
        return;
    if (d->obj[chu_a].cls != JW_SEN || d->obj[chu_b].cls != JW_SEN)
        return;
    if (!chushin_line(d, &px, &py, &ux, &uy))
        return;
    t0 = (chu_x - px) * ux + (chu_y - py) * uy;
    t1 = (x - px) * ux + (y - py) * uy;
    if (t0 == t1)
        return;
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->d[0] = px + ux * t0;
    o->d[1] = py + uy * t0;
    o->d[2] = px + ux * t1;
    o->d[3] = py + uy * t1;
    op_push(1);
}

/* 接線, 円→円 (0x8066).
 *
 * Two circles have four common tangents, and the original draws the one that
 * touches each circle on the side it was pointed at: four runs over the same
 * pair, picking top/top, bottom/bottom, top/bottom and bottom/top, came back
 * with four different lines and each one touches where it was pointed
 * (decomp/res/sessen_*.jww).  The line runs from one touch point to the
 * other -- its ends are the tangency points, to four decimals in every run.
 *
 * A tangent is the line whose unit normal n has
 *     n.cA - k = sa*rA        n.cB - k = sb*rB
 * for a choice of signs; subtracting gives n.(cB-cA) = sb*rB - sa*rA, which
 * fixes n up to the reflection in cB-cA, and the touch points follow as
 * c - s*r*n.  The four sign pairs are the four tangents; the inner two do not
 * exist when the circles overlap, and the term under the root says so.
 */
static int tangent(double ax, double ay, double ra,
                   double bx, double by, double rb,
                   int sa, int sb, double *px, double *py,
                   double *qx, double *qy)
{
    double dx = bx - ax, dy = by - ay;
    double dd = sqrt(dx * dx + dy * dy);
    double r, c, h, ux, uy, nx, ny;

    if (dd < 1e-12)
        return 0;
    r = sb * rb - sa * ra;
    c = r / dd;
    h = 1.0 - c * c;
    if (h < 0.0)
        return 0;               /* no tangent with those two sides */
    h = sqrt(h);
    ux = dx / dd;
    uy = dy / dd;
    /* n = u*c + perp(u)*h -- the other root is the mirror pair of signs */
    nx = ux * c - uy * h;
    ny = uy * c + ux * h;
    *px = ax - sa * ra * nx;
    *py = ay - sa * ra * ny;
    *qx = bx - sb * rb * nx;
    *qy = by - sb * rb * ny;
    return 1;
}

/* 接線, 点→円 (the bar's 点→円 button).
 *
 * A point outside a circle has two tangents, and the original draws the one
 * whose touch point is nearer where the circle was pointed at -- pointing at
 * the upper half of the same circle from the same point gave one, the lower
 * half the other, and the left and right halves agreed with whichever of
 * those they were on (decomp/res/tensen_*.jww).
 *
 * The point comes first and the circle second, whatever the status line says:
 * driving it the other way round leaves nothing drawn.
 *
 * With d = P - c and L = |d|, the touch points are r*cos a along d and
 * r*sin a across it, where cos a = r/L -- (T-P).(T-c) works out to r^2 - r*L*
 * (r/L) = 0, so they are tangents, and the line runs from P to T.
 */
/* 接円 (0x8068): a circle of the radius in the bar's box, touching two lines.
 *
 * Three clicks -- the first line, the second, then a click that says which
 * circle is wanted; the original's status line puts up 「マウスを移動し、必要な
 * 接円位置で左クリックしてください。 【 4 − 1 】」, so there are four of them and
 * it takes the one nearest the click.  Driving it four times over the same
 * crossed pair, placing the click left, right, above and below, gave four
 * circles of radius 10 whose centres are the intersection offset along the
 * two angle bisectors (decomp/res/sekien_*.jww).
 *
 * The radius in the box is a real length, so it is divided by the write layer
 * group's scale the same way 面取's size is -- 2000 in a 1/200 group came out
 * 10 mm on the paper.
 *
 * A centre at distance r from both lines satisfies n1.C = k1 + s1*r and
 * n2.C = k2 + s2*r for the lines' unit normals; the four sign pairs are the
 * four circles, and two parallel lines have none unless they happen to be 2r
 * apart, which the determinant says.
 */
/* 曲線, スプライン (0x808c).
 *
 * Points are clicked one after another and 作図実行 draws the curve through
 * them as a run of straight lines.  Two things had to be settled by asking
 * the original, and both came out exactly.
 *
 * What curve.  A natural cubic spline on uniform knots: driven over four
 * points, the second derivative at the two ends is zero and the tangents
 * across a join agree.  Four points at (0,0) (1,1) (2,0) (3,1) in span units
 * gave f'(0) = 288.6297 where the natural spline's (y1-y0) - (2m0+m1)/6 is
 * 173.178 + 115.452 = 288.630, and the joins matched to 1e-8
 * (decomp/res/curve_*.jww).  Catmull-Rom is not it -- it would have put the
 * tangent at the first interior point at zero, and the original's is -57.73.
 *
 * Where it samples.  Not evenly.  With n divisions to a span the parameter
 * steps are 0.58, 1, 1, ..., 1, 0.58 -- the two at the ends are 0.58 of the
 * rest -- so the middle step is 1/(n - 0.84) and the end ones 0.58 of that.
 * That 0.58 is exact, and the same at n = 3, 4, 7 and 10.
 */
#define CV_END 0.58

/* The second derivatives of the natural cubic spline through v[0..n-1], for
   unit knot spacing.  Thomas' algorithm on the usual tridiagonal system. */
/* two ends of a chain meeting: the original's own rectangles share their
   corners exactly, so this only has to allow for the last bit of a double */
static int near_pt(double ax, double ay, double bx, double by)
{
    double dx = ax - bx, dy = ay - by;

    return dx * dx + dy * dy < 1e-12;
}

static void spline_m(const double *v, int n, double *m)
{
    double c[CV_MAX], r[CV_MAX];
    int i;

    for (i = 0; i < n; i++)
        m[i] = 0.0;
    if (n < 3)
        return;
    /* m[0] = m[n-1] = 0; for i = 1..n-2:
         m[i-1] + 4 m[i] + m[i+1] = 6 (v[i-1] - 2 v[i] + v[i+1]) */
    c[1] = 1.0 / 4.0;
    r[1] = 6.0 * (v[0] - 2 * v[1] + v[2]) / 4.0;
    for (i = 2; i <= n - 2; i++) {
        double den = 4.0 - c[i - 1];
        c[i] = 1.0 / den;
        r[i] = (6.0 * (v[i - 1] - 2 * v[i] + v[i + 1]) - r[i - 1]) / den;
    }
    for (i = n - 2; i >= 1; i--)
        m[i] = r[i] - c[i] * m[i + 1];
}

static double spline_at(const double *v, const double *m, int i, double s)
{
    double a = 1.0 - s;

    return v[i] * a + v[i + 1] * s
         + ((a * a * a - a) * m[i] + (s * s * s - s) * m[i + 1]) / 6.0;
}

/* ベジェ曲線: a Bezier of degree (points - 1) over everything that was
 * clicked, sampled evenly.  Four points came out a cubic Bezier and five a
 * quartic, both to 1e-8, and the sampling is (points - 1) * 分割数 vertices
 * -- one fewer segment than the spline's, since that counts segments rather
 * than points (decomp/res/bezier_*.jww).
 *
 * de Casteljau rather than the Bernstein sum: with up to 64 points the
 * binomial coefficients get large, and this needs no coefficients at all.
 */
static void bezier_at(const double *vx, const double *vy, int n, double t,
                      double *ox, double *oy)
{
    double ax[CV_MAX], ay[CV_MAX];
    int i, k;

    for (i = 0; i < n; i++) {
        ax[i] = vx[i];
        ay[i] = vy[i];
    }
    for (k = n - 1; k > 0; k--)
        for (i = 0; i < k; i++) {
            ax[i] += (ax[i + 1] - ax[i]) * t;
            ay[i] += (ay[i + 1] - ay[i]) * t;
        }
    *ox = ax[0];
    *oy = ay[0];
}

static void kyokusen(jw_drawing *d)
{
    const char *sz = jw_cmd_box(1411);
    double mx[CV_MAX], my[CV_MAX], v, px, py;
    int n = sz ? atoi(sz) : 0, i, k, made = 0;

    if (cv_mode != 1691 && cv_mode != 1692)
        return;                 /* サイン and ２次 are not done */
    if (cv_n < 2 || n < 1)
        return;
    if (cv_mode == 1692) {      /* ベジェ */
        int pts = (cv_n - 1) * n;

        if (pts < 2)
            return;
        px = cv_x[0];
        py = cv_y[0];
        for (k = 1; k < pts; k++) {
            double qx, qy;
            jw_obj *o;

            bezier_at(cv_x, cv_y, cv_n, (double)k / (pts - 1), &qx, &qy);
            o = jw_add(d, JW_SEN);
            if (!o)
                return;
            o->d[0] = px;
            o->d[1] = py;
            o->d[2] = qx;
            o->d[3] = qy;
            px = qx;
            py = qy;
            made++;
        }
        if (made)
            op_push(made);
        return;
    }
    spline_m(cv_x, cv_n, mx);
    spline_m(cv_y, cv_n, my);
    /* the step that makes the two at the ends 0.58 of the rest add up to 1 */
    v = 1.0 / (n - 2 + 2 * CV_END);
    px = cv_x[0];
    py = cv_y[0];
    for (i = 0; i < cv_n - 1; i++)
        for (k = 1; k <= n; k++) {
            double s, qx, qy;
            jw_obj *o;

            if (k == n)
                s = 1.0;
            else
                s = CV_END * v + (k - 1) * v;
            qx = spline_at(cv_x, mx, i, s);
            qy = spline_at(cv_y, my, i, s);
            o = jw_add(d, JW_SEN);
            if (!o)
                return;
            o->d[0] = px;
            o->d[1] = py;
            o->d[2] = qx;
            o->d[3] = qy;
            px = qx;
            py = qy;
            made++;
        }
    if (made)
        op_push(made);
}

/* ハッチ (0x806a), 1線.
 *
 * The boundary is settled with the right button -- 「閉鎖連続線・円をマウス(R)で
 * 指示してください」 -- and 実行 stays greyed until one is.  Right-clicking one
 * side of a rectangle takes the whole ring; right-clicking a circle takes the
 * circle.
 *
 * What it then draws is simple and came out exact both times.  Take the
 * normal of the 角度 direction; the lines sit where n.p is a whole multiple of
 * the ピッチ -- anchored at zero, not at the region, so the same hatch over
 * two regions lines up -- and each line is exactly the chord of the region at
 * that offset.  A circle of radius 129.88 at 45 degrees and pitch 10 came back
 * as 26 chords at offsets -60 to 190, every one matching sqrt(r^2 - d^2) to
 * 1e-6, and a rectangle as 49 (decomp/res/hatch_*.jww).
 *
 * ピッチ is paper millimetres while 実寸 is off, which is how the original
 * starts.
 */
static int hatch_ring(const jw_drawing *d, int a)
{
    char used[HT_MAX];
    double ex, ey, sx, sy;
    int i, k, n = d->ndrawn > HT_MAX ? HT_MAX : d->ndrawn;

    for (i = 0; i < n; i++)
        used[i] = 0;
    if (a < 0 || a >= n || d->obj[a].cls != JW_SEN)
        return 0;
    used[a] = 1;
    sx = d->obj[a].d[0];
    sy = d->obj[a].d[1];
    ex = d->obj[a].d[2];
    ey = d->obj[a].d[3];
    ht_x[0] = sx;
    ht_y[0] = sy;
    ht_n = 1;
    for (k = 0; k < HT_MAX; k++) {
        int found = -1, flip = 0;

        ht_x[ht_n] = ex;
        ht_y[ht_n] = ey;
        ht_n++;
        if (near_pt(ex, ey, sx, sy))
            return ht_n > 3;    /* closed */
        if (ht_n >= HT_MAX - 1)
            return 0;
        for (i = 0; i < n; i++) {
            if (used[i] || d->obj[i].cls != JW_SEN)
                continue;
            if (near_pt(d->obj[i].d[0], d->obj[i].d[1], ex, ey)) {
                found = i;
                flip = 0;
                break;
            }
            if (near_pt(d->obj[i].d[2], d->obj[i].d[3], ex, ey)) {
                found = i;
                flip = 1;
                break;
            }
        }
        if (found < 0)
            return 0;
        used[found] = 1;
        ex = flip ? d->obj[found].d[0] : d->obj[found].d[2];
        ey = flip ? d->obj[found].d[1] : d->obj[found].d[3];
    }
    return 0;
}

static int hatch_at(jw_drawing *d, double o, double ux, double uy,
                    double nx, double ny);
static int hatch_grid(jw_drawing *d, double ux, double uy, double nx,
                      double ny, double vp, double hp);

static void hatch(jw_drawing *d)
{
    const char *sa = jw_cmd_box(1419), *sp = jw_cmd_box(1411);
    const char *sg = jw_cmd_box(1412);
    double ang = sa ? atof(sa) : 0.0, pitch = sp ? atof(sp) : 0.0;
    double gap = sg ? atof(sg) : 0.0;
    double ux, uy, nx, ny, lo, hi, o;
    int i, k, k0, k1, made = 0, extra = 0;

    if (ht_mode < 1689 || ht_mode > 1692)
        return;                 /* 図形 is not done */
    if (pitch <= 0.0)
        return;
    if (ht_mode != 1689) {
        if (gap <= 0.0)
            return;
        /* a group whose middle falls outside the region can still have a
           line of its own inside it */
        extra = 1;
    }
    if (!ht_round && ht_n < 4)
        return;
    ux = cos(ang * PI / 180.0);
    uy = sin(ang * PI / 180.0);
    nx = uy;                    /* turn the direction a quarter turn */
    ny = -ux;
    if (ht_mode == 1692) {      /* ┬┴┬ -- ピッチ is 縦ピッチ, 線間隔 is 横ピッチ */
        made = hatch_grid(d, ux, uy, nx, ny, pitch, gap);
        if (made)
            op_push(made);
        return;
    }
    if (ht_round) {
        lo = nx * ht_cx + ny * ht_cy - ht_r;
        hi = lo + 2 * ht_r;
    } else {
        lo = hi = nx * ht_x[0] + ny * ht_y[0];
        for (i = 1; i < ht_n; i++) {
            o = nx * ht_x[i] + ny * ht_y[i];
            if (o < lo) lo = o;
            if (o > hi) hi = o;
        }
    }
    k0 = (int)ceil(lo / pitch);
    k1 = (int)floor(hi / pitch);
    if (k1 - k0 > 100000)
        return;
    /* the original goes from the far side back: its first line is the one at
       the highest offset, and inside a ２線 or ３線 group the same way round
       -- 301, 300, 299, then 291, 290, 289 */
    for (k = k1 + extra; k >= k0 - extra; k--) {
        o = k * pitch;
        switch (ht_mode) {
        case 1690:
            made += hatch_at(d, o + gap / 2, ux, uy, nx, ny);
            made += hatch_at(d, o - gap / 2, ux, uy, nx, ny);
            break;
        case 1691:
            made += hatch_at(d, o + gap, ux, uy, nx, ny);
            made += hatch_at(d, o, ux, uy, nx, ny);
            made += hatch_at(d, o - gap, ux, uy, nx, ny);
            break;
        default:
            made += hatch_at(d, o, ux, uy, nx, ny);
            break;
        }
    }
    if (made)
        op_push(made);
}

/* Where the region cuts the line that runs along (bx, by) at offset `o`
 * across it, as pairs of positions along that line.  ┬┴┬ needs this with the
 * two directions the other way round -- its cross pieces run across the hatch
 * rather than along it -- so the two vectors are arguments. */
static int hatch_cut(double o, double ax, double ay, double bx, double by,
                     double *t)
{
    int i, nt = 0;

    if (ht_round) {
        double dd = o - (ax * ht_cx + ay * ht_cy);
        double h = ht_r * ht_r - dd * dd;
        double mid;

        if (h <= 0.0)
            return 0;           /* this one misses the circle */
        h = sqrt(h);
        mid = bx * ht_cx + by * ht_cy;
        t[nt++] = mid - h;
        t[nt++] = mid + h;
        return nt;
    }
    for (i = 0; i + 1 < ht_n; i++) {
        double a0 = ax * ht_x[i] + ay * ht_y[i];
        double a1 = ax * ht_x[i + 1] + ay * ht_y[i + 1];
        double f;

        if ((a0 <= o) == (a1 <= o))
            continue;           /* the edge does not cross this line */
        f = (o - a0) / (a1 - a0);
        if (nt < HT_MAX)
            t[nt++] = bx * (ht_x[i] + f * (ht_x[i + 1] - ht_x[i]))
                    + by * (ht_y[i] + f * (ht_y[i + 1] - ht_y[i]));
    }
    for (i = 1; i < nt; i++) {
        double v = t[i];
        int j = i - 1;
        while (j >= 0 && t[j] > v) { t[j + 1] = t[j]; j--; }
        t[j + 1] = v;
    }
    return nt;
}

/* How far the region reaches along (ax, ay). */
static void hatch_span(double ax, double ay, double *lo, double *hi)
{
    int i;

    if (ht_round) {
        *lo = ax * ht_cx + ay * ht_cy - ht_r;
        *hi = *lo + 2 * ht_r;
        return;
    }
    *lo = *hi = ax * ht_x[0] + ay * ht_y[0];
    for (i = 1; i < ht_n; i++) {
        double o = ax * ht_x[i] + ay * ht_y[i];

        if (o < *lo) *lo = o;
        if (o > *hi) *hi = o;
    }
}

static int hatch_at(jw_drawing *d, double o, double ux, double uy,
                    double nx, double ny)
{
    double t[HT_MAX];
    int i, nt = hatch_cut(o, nx, ny, ux, uy, t), made = 0;
    jw_obj *ob;

    for (i = 0; i + 1 < nt; i += 2) {
        if (t[i + 1] - t[i] <= 0.0)
            continue;
        ob = jw_add(d, JW_SEN);
        if (!ob)
            return made;
        ob->d[0] = ux * t[i] + nx * o;
        ob->d[1] = uy * t[i] + ny * o;
        ob->d[2] = ux * t[i + 1] + nx * o;
        ob->d[3] = uy * t[i + 1] + ny * o;
        made++;
    }
    return made;
}

/* ┬┴┬ (1692): a running bond, the way a brick wall is drawn.
 *
 * Lines all the way across the region every 縦ピッチ, and between them short
 * cross pieces every 横ピッチ, half a 横ピッチ out of step from one course to
 * the next.  Read off two runs of the original (decomp/res/hatch_r1692.jww,
 * 角度 0・縦 3・横 6, and hatch_r1692b.jww, 角度 30・縦 20・横 50):
 *
 *   - the long lines sit where q, the distance across the hatch, is a whole
 *     multiple of 縦ピッチ -- anchored at zero like every other hatch -- and
 *     each is the chord of the region there;
 *   - the cross pieces sit where p, the distance along the hatch, is a whole
 *     multiple of **half** the 横ピッチ.  Call that multiple m and number the
 *     courses by k (the one from k*縦 to (k+1)*縦): a piece is drawn when
 *     **m + k is even**, which is what staggers them;
 *   - each piece is one course long and is cut to the region like the lines
 *     are -- the original left a 0.53 long stub where a course ran off the
 *     bottom edge;
 *   - the order is: the long lines with q rising, then every column with m
 *     even, p falling, then every column with m odd.  Inside a column the
 *     pieces come with q rising.
 */
static int hatch_grid(jw_drawing *d, double ux, double uy, double nx, double ny,
                      double vp, double hp)
{
    /* the other way across: q = n2.point rises where the offset o falls */
    double n2x = -nx, n2y = -ny;
    double qlo, qhi, plo, phi, half = hp / 2;
    int k, klo, khi, m, mlo, mhi, par, made = 0;

    hatch_span(n2x, n2y, &qlo, &qhi);
    hatch_span(ux, uy, &plo, &phi);
    klo = (int)ceil(qlo / vp);
    khi = (int)floor(qhi / vp);
    mlo = (int)ceil(plo / half);
    mhi = (int)floor(phi / half);
    if (khi - klo > 100000 || mhi - mlo > 100000)
        return 0;
    for (k = klo; k <= khi; k++)
        made += hatch_at(d, -(k * vp), ux, uy, nx, ny);
    for (par = 0; par < 2; par++)
        for (m = mhi; m >= mlo; m--) {
            double t[HT_MAX], p = m * half;
            int nt, i;

            if (((m % 2) + 2) % 2 != par)
                continue;
            nt = hatch_cut(p, ux, uy, n2x, n2y, t);
            /* one course below the lowest line to one above the highest: a
               course can be cut off by the region and still show */
            for (k = klo - 1; k <= khi; k++) {
                double qa = k * vp, qb = qa + vp;

                if (((m + k) % 2 + 2) % 2 != 0)
                    continue;
                for (i = 0; i + 1 < nt; i += 2) {
                    double a = t[i] > qa ? t[i] : qa;
                    double b = t[i + 1] < qb ? t[i + 1] : qb;
                    jw_obj *ob;

                    if (b - a <= 0.0)
                        continue;
                    ob = jw_add(d, JW_SEN);
                    if (!ob)
                        return made;
                    ob->d[0] = ux * p + n2x * a;
                    ob->d[1] = uy * p + n2y * a;
                    ob->d[2] = ux * p + n2x * b;
                    ob->d[3] = uy * p + n2y * b;
                    made++;
                }
            }
        }
    return made;
}

/* 接線 角度指定 (1691) and 円上点指定 (1692).
 *
 * Both settle on a line that touches the circle and then take two points
 * along it, and the original asks for them in the same words as the 線
 * command -- 「始点を指示してください」「終点を指示してください」.  Read out of
 * the status line, which WM_GETTEXT hands over (tools/jwdraw.ps1's
 * `read:59393`).
 *
 *   角度指定    circle, 始点, 終点.  The 角度 box gives the direction, and of
 *               the two tangents that way round the one on the side the
 *               circle was pointed at is taken.
 *   円上点指定  circle, a point on it, 始点, 終点.  The point is pulled onto
 *               the circle -- centre plus the radius that way -- and the
 *               tangent there is the line.
 *
 * The ends are the two points **dropped onto the line**, not the points
 * themselves: the original was clicked well off the line both times and the
 * segment came back exactly between the two feet (decomp/res/sesang_*.jww,
 * sescpt_*.jww -- 396.5883 long from clicks 500 pixels apart).
 */
static void sesline(jw_drawing *d, const jw_view *v, double x, double y)
{
    const jw_obj *c;
    int i;

    if (ses_step == 0) {                /* the circle */
        i = jw_pick(d, v, x, y, 3);
        if (i < 0 || d->obj[i].cls != JW_ENKO || d->obj[i].d[2] <= 0.0)
            return;
        ses_a = i;
        ses_x = x;
        ses_y = y;
        ses_step = 1;
        if (ses_mode == 1691) {
            const char *sa = jw_cmd_box(1412);
            double ang = sa ? atof(sa) : 0.0;
            double nx, ny, side;

            c = &d->obj[i];
            ses_ux = cos(ang * PI / 180.0);
            ses_uy = sin(ang * PI / 180.0);
            nx = -ses_uy;
            ny = ses_ux;
            side = nx * (x - c->d[0]) + ny * (y - c->d[1]) < 0.0 ? -1.0 : 1.0;
            ses_lx = c->d[0] + side * c->d[2] * nx;
            ses_ly = c->d[1] + side * c->d[2] * ny;
            ses_step = 2;       /* the line is settled; the points are next */
        }
        return;
    }
    if (ses_a < 0 || ses_a >= d->nobj || d->obj[ses_a].cls != JW_ENKO) {
        ses_step = 0;
        return;
    }
    c = &d->obj[ses_a];
    if (ses_step == 1) {                /* 円上点: pull it onto the circle */
        double dx = x - c->d[0], dy = y - c->d[1];
        double L = sqrt(dx * dx + dy * dy);

        if (L <= 0.0)
            return;
        ses_lx = c->d[0] + c->d[2] * dx / L;
        ses_ly = c->d[1] + c->d[2] * dy / L;
        ses_ux = -dy / L;               /* a quarter turn from the radius */
        ses_uy = dx / L;
        ses_step = 2;
        return;
    }
    if (ses_step == 2) {                /* 始点 */
        ses_t0 = ses_ux * (x - ses_lx) + ses_uy * (y - ses_ly);
        ses_step = 3;
        return;
    }
    {                                   /* 終点 */
        double t1 = ses_ux * (x - ses_lx) + ses_uy * (y - ses_ly);
        jw_obj *o = jw_add(d, JW_SEN);

        ses_step = 0;
        ses_a = -1;
        if (!o)
            return;
        o->d[0] = ses_lx + ses_ux * ses_t0;
        o->d[1] = ses_ly + ses_uy * ses_t0;
        o->d[2] = ses_lx + ses_ux * t1;
        o->d[3] = ses_ly + ses_uy * t1;
        op_push(1);
    }
}

/* 接円 (0x8068) -- a circle that touches what was picked.
 *
 * The bar asks for 「１番目の線・円」「２番目の線・円」, so an element is
 * either a line or a circle, and this holds whichever it is: a line as the
 * unit normal and its offset, a circle as its centre and radius.
 */
typedef struct {
    int circle;
    double nx, ny, k;           /* a line: n.point == k */
    double cx, cy, r;           /* a circle */
} sek_el;

static int sek_elem(const jw_obj *o, sek_el *e)
{
    if (o->cls == JW_SEN) {
        double ux = o->d[2] - o->d[0], uy = o->d[3] - o->d[1];
        double L = sqrt(ux * ux + uy * uy);

        if (L < 1e-12)
            return 0;
        e->circle = 0;
        e->nx = -uy / L;
        e->ny = ux / L;
        e->k = e->nx * o->d[0] + e->ny * o->d[1];
        return 1;
    }
    if (o->cls == JW_ENKO && o->d[2] > 0.0) {
        e->circle = 1;
        e->cx = o->d[0];
        e->cy = o->d[1];
        e->r = o->d[2];
        return 1;
    }
    return 0;
}

/* Where can the centre of a circle of radius `r` be, if it touches both of
 * these?  A line puts it on one of the two lines `r` away, a circle on one of
 * the two circles `r` out or `r` in -- four pairings in all, and each pairing
 * leaves nought, one or two places.  The original counts them out loud:
 * two crossed lines said 【 4 − 1 】, a line and a circle 【 2 − 2 】 and two
 * circles 【 6 − 1 】, which is what these four pairings give.
 */
#define SEK_MAX 8
static int sek_places(const sek_el *p, const sek_el *q, double r,
                      double *px, double *py)
{
    int s1, s2, n = 0;

    for (s1 = -1; s1 <= 1; s1 += 2)
        for (s2 = -1; s2 <= 1; s2 += 2) {
            if (!p->circle && !q->circle) {
                double a1 = p->k + s1 * r, a2 = q->k + s2 * r;
                double den = p->nx * q->ny - p->ny * q->nx;

                if (fabs(den) < 1e-12)
                    continue;   /* parallel: nothing, unless 2r apart */
                px[n] = (a1 * q->ny - a2 * p->ny) / den;
                py[n] = (p->nx * a2 - q->nx * a1) / den;
                n++;
            } else if (p->circle && q->circle) {
                /* two circles, centres apart by L: the usual intersection */
                double d1 = fabs(p->r + s1 * r), d2 = fabs(q->r + s2 * r);
                double ex = q->cx - p->cx, ey = q->cy - p->cy;
                double L = sqrt(ex * ex + ey * ey), a, h2;

                if (L < 1e-12)
                    continue;
                a = (L * L + d1 * d1 - d2 * d2) / (2 * L);
                h2 = d1 * d1 - a * a;
                if (h2 < 0.0)
                    continue;
                h2 = sqrt(h2);
                ex /= L;
                ey /= L;
                px[n] = p->cx + a * ex - h2 * ey;
                py[n] = p->cy + a * ey + h2 * ex;
                n++;
                if (h2 > 1e-9) {
                    px[n] = p->cx + a * ex + h2 * ey;
                    py[n] = p->cy + a * ey - h2 * ex;
                    n++;
                }
            } else {
                /* a line and a circle: drop the circle's centre on the line
                   `r` away and come back along it */
                const sek_el *l = p->circle ? q : p;
                const sek_el *c = p->circle ? p : q;
                double sl = p->circle ? s2 : s1, sc = p->circle ? s1 : s2;
                double off = l->k + sl * r;
                double d = fabs(c->r + sc * r);
                double t = off - (l->nx * c->cx + l->ny * c->cy);
                double fx = c->cx + t * l->nx, fy = c->cy + t * l->ny;
                double h2 = d * d - t * t;

                if (h2 < 0.0)
                    continue;
                h2 = sqrt(h2);
                px[n] = fx - h2 * l->ny;    /* along the line */
                py[n] = fy + h2 * l->nx;
                n++;
                if (h2 > 1e-9) {
                    px[n] = fx + h2 * l->ny;
                    py[n] = fy - h2 * l->nx;
                    n++;
                }
            }
            if (n > SEK_MAX - 2)
                return n;
        }
    return n;
}

static jw_obj *sek_add(jw_drawing *d, double cx, double cy, double r)
{
    jw_obj *o = jw_add(d, JW_ENKO);

    if (!o)
        return 0;
    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = 0.0;
    o->d[4] = 6.283185307179586;        /* the whole way round */
    o->d[5] = 0.0;
    o->d[6] = 1.0;                      /* round, not squashed */
    o->n = 1;                           /* the trailing 1 a whole circle has */
    return o;
}

/* The 半径 box, in the drawing's own units. */
static double sek_radius(const jw_drawing *d)
{
    const char *sz = jw_cmd_box(1411);
    double r = sz ? atof(sz) : 0.0;
    int wg = 0, i;

    if (r <= 0.0)
        return 0.0;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        r /= d->group[wg].scale;
    return r;
}

static void sekien(jw_drawing *d, int a, int b, double x, double y)
{
    sek_el p, q;
    double px[SEK_MAX], py[SEK_MAX], r, bestd = 0;
    int i, n, best = -1;

    if (a < 0 || b < 0 || a >= d->nobj || b >= d->nobj || a == b)
        return;
    if (!sek_elem(&d->obj[a], &p) || !sek_elem(&d->obj[b], &q))
        return;
    r = sek_radius(d);
    if (r <= 0.0)
        return;                 /* no radius typed in: nothing to draw */
    n = sek_places(&p, &q, r, px, py);
    for (i = 0; i < n; i++) {
        double e = (px[i] - x) * (px[i] - x) + (py[i] - y) * (py[i] - y);

        if (best < 0 || e < bestd) {
            best = i;
            bestd = e;
        }
    }
    if (best < 0)
        return;
    if (sek_add(d, px[best], py[best], r))
        op_push(1);
}

/* 接円, three elements and an empty 半径 box: the circle that touches all
 * three.  With three lines that is the one inside the triangle they make, and
 * the original draws it the moment the third is picked -- no placing click,
 * and where each line was picked makes no difference (three runs pointed at
 * quite different parts of the same three lines all came back with the same
 * circle, decomp/res/sek3.jww).  Of the four circles that touch three lines
 * the inside one is the smallest, which is what this takes.
 */
static void sekien3(jw_drawing *d, int a, int b, int c, double x, double y)
{
    sek_el e[3];
    double best = 0, bx = 0, by = 0;
    int i, s1, s2, s3, have = 0;

    (void)x;
    (void)y;
    if (a < 0 || b < 0 || c < 0 || a >= d->nobj || b >= d->nobj
        || c >= d->nobj || a == b || b == c || a == c)
        return;
    if (!sek_elem(&d->obj[a], &e[0]) || !sek_elem(&d->obj[b], &e[1])
        || !sek_elem(&d->obj[c], &e[2]))
        return;
    for (i = 0; i < 3; i++)
        if (e[i].circle)
            return;             /* circles are not done here */
    /* n_i.C - s_i r = k_i, three equations in Cx, Cy and r */
    for (s1 = -1; s1 <= 1; s1 += 2)
        for (s2 = -1; s2 <= 1; s2 += 2)
            for (s3 = -1; s3 <= 1; s3 += 2) {
                double m[3][4], t;
                int row, col, piv;

                m[0][0] = e[0].nx; m[0][1] = e[0].ny; m[0][2] = -(double)s1;
                m[1][0] = e[1].nx; m[1][1] = e[1].ny; m[1][2] = -(double)s2;
                m[2][0] = e[2].nx; m[2][1] = e[2].ny; m[2][2] = -(double)s3;
                m[0][3] = e[0].k; m[1][3] = e[1].k; m[2][3] = e[2].k;
                for (col = 0; col < 3; col++) {
                    piv = col;
                    for (row = col + 1; row < 3; row++)
                        if (fabs(m[row][col]) > fabs(m[piv][col]))
                            piv = row;
                    if (fabs(m[piv][col]) < 1e-12)
                        break;
                    if (piv != col)
                        for (i = 0; i < 4; i++) {
                            t = m[col][i];
                            m[col][i] = m[piv][i];
                            m[piv][i] = t;
                        }
                    for (row = 0; row < 3; row++) {
                        if (row == col)
                            continue;
                        t = m[row][col] / m[col][col];
                        for (i = col; i < 4; i++)
                            m[row][i] -= t * m[col][i];
                    }
                }
                if (col < 3)
                    continue;   /* two of them are parallel */
                t = m[2][3] / m[2][2];          /* the radius */
                if (t <= 1e-9 || (have && t >= best))
                    continue;
                have = 1;
                best = t;
                bx = m[0][3] / m[0][0];
                by = m[1][3] / m[1][1];
            }
    if (!have)
        return;
    if (sek_add(d, bx, by, best))
        op_push(1);
}

static void tensen(jw_drawing *d, int b, double px, double py,
                   double x, double y)
{
    const jw_obj *q;
    double cx, cy, r, dx, dy, L, ux, uy, ca, sa, tx, ty, t2x, t2y;
    jw_obj *o;

    if (b < 0 || b >= d->nobj)
        return;
    q = &d->obj[b];
    if (q->cls != JW_ENKO || q->d[2] <= 0.0)
        return;
    cx = q->d[0];
    cy = q->d[1];
    r = q->d[2];
    dx = px - cx;
    dy = py - cy;
    L = sqrt(dx * dx + dy * dy);
    if (L <= r)
        return;                 /* inside it: no tangent from there */
    ux = dx / L;
    uy = dy / L;
    ca = r / L;
    sa = sqrt(1.0 - ca * ca);
    tx = cx + r * (ca * ux - sa * uy);
    ty = cy + r * (ca * uy + sa * ux);
    t2x = cx + r * (ca * ux + sa * uy);
    t2y = cy + r * (ca * uy - sa * ux);
    if ((t2x - x) * (t2x - x) + (t2y - y) * (t2y - y)
        < (tx - x) * (tx - x) + (ty - y) * (ty - y)) {
        tx = t2x;
        ty = t2y;
    }
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->d[0] = px;
    o->d[1] = py;
    o->d[2] = tx;
    o->d[3] = ty;
    op_push(1);
}

static void sessen(jw_drawing *d, int a, int b, double x, double y)
{
    const jw_obj *p, *q;
    double bestd = 0, bp[4] = { 0, 0, 0, 0 };
    int sa, sb, have = 0;
    jw_obj *o;

    if (a < 0 || b < 0 || a >= d->nobj || b >= d->nobj)
        return;
    p = &d->obj[a];
    q = &d->obj[b];
    if (p->cls != JW_ENKO || q->cls != JW_ENKO)
        return;
    if (p->d[2] <= 0.0 || q->d[2] <= 0.0)
        return;
    for (sa = -1; sa <= 1; sa += 2)
        for (sb = -1; sb <= 1; sb += 2) {
            double tx, ty, ux, uy, e;

            if (!tangent(p->d[0], p->d[1], p->d[2],
                         q->d[0], q->d[1], q->d[2], sa, sb,
                         &tx, &ty, &ux, &uy))
                continue;
            e = (tx - ses_x) * (tx - ses_x) + (ty - ses_y) * (ty - ses_y)
              + (ux - x) * (ux - x) + (uy - y) * (uy - y);
            if (!have || e < bestd) {
                have = 1;
                bestd = e;
                bp[0] = tx; bp[1] = ty; bp[2] = ux; bp[3] = uy;
            }
        }
    if (!have)
        return;
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->d[0] = bp[0];
    o->d[1] = bp[1];
    o->d[2] = bp[2];
    o->d[3] = bp[3];
    op_push(1);
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
        if (d->obj[i].sel)
            n++;
    return n;
}

static void sel_clear(jw_drawing *d)
{
    int i;

    if (d)
        for (i = 0; i < d->nobj; i++) {
            d->obj[i].flags = (unsigned short)(d->obj[i].flags & ~2u);
            d->obj[i].sel = 0;
        }
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
        if (a >= x0 && c2 <= x1 && b >= y0 && e <= y1) {
            o->flags = (unsigned short)(o->flags | 2u);
            o->sel = 1;
        }
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
        if (d->obj[i].sel) {
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
 * it saved had 25 of its 46 lines gone and nothing left picked.
 *
 * Only from 範囲選択 though.  The same three keys after a 複写 -- where the
 * selection is settled too, and still drawn pink -- leave the drawing alone:
 * the original made its copy, 消去 took nothing out, and the 25 elements
 * were still picked in the file it saved.  So this is the 範囲選択 arm (step
 * 4) and not the one 複写 and 移動 place from (step 3). */
int jw_cmd_sel_erase(jw_drawing *d)
{
    op_t *o;
    int i, n = 0;

    if (!d || sel_n <= 0 || sel_step != 4)
        return 0;
    o = op_new();
    for (i = d->nobj - 1; i >= 0; i--)
        if (d->obj[i].sel) {
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
            d->obj[at].sel = 1;
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
            p->sel = 0;
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
    if (current == JW_CMD_HATCH) {
        if (id >= 1689 && id <= 1693) {
            ht_mode_set(id);
            return 1;
        }
        if (id == 1149) {       /* クリアー */
            ht_n = 0;
            ht_round = 0;
            return 1;
        }
        if (id == 1148) {       /* 実行 */
            hatch(d);
            ht_n = 0;
            ht_round = 0;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_KYOKUSEN) {
        if (id >= 1689 && id <= 1692) {
            cv_mode = id;
            return 1;
        }
        if (id == 1800) {       /* 作図実行 */
            kyokusen(d);
            cv_n = 0;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_SESSEN) {
        /* the four ways of drawing a tangent */
        if (id >= 1689 && id <= 1692) {
            ses_mode = id;
            ses_step = 0;
            ses_a = -1;
            return 1;
        }
        return 0;
    }
    if (current == JW_CMD_SUNPO)
        return id == 1059 ? (sun_deg = sun_deg == 0 ? 90 : 0, 1) : 0;
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
    case 1059:                  /* 0ﾟ/90ﾟ on 寸法's bar */
        sun_deg = sun_deg == 0 ? 90 : 0;
        return 1;
    case 1066: {                /* 全選択: everything that is drawn */
        int i;
        if (!d)
            return 0;
        for (i = 0; i < d->ndrawn; i++) {
            d->obj[i].flags = (unsigned short)(d->obj[i].flags | 2u);
            d->obj[i].sel = 1;
        }
        sel_step = 2;
        return 1;
    }
    }
    return 0;
}

int jw_cmd_sunpo_angle(void)
{
    return sun_deg;
}

static void box_put(int id, const char *v)
{
    int i;

    for (i = 0; i < (int)(sizeof box / sizeof box[0]); i++)
        if (box[i].id == id && box[i].cmd == current) {
            strncpy(box[i].t, v, sizeof box[i].t - 1);
            box[i].t[sizeof box[i].t - 1] = 0;
            return;
        }
}

/* Switch the hatch to one of the five modes, swapping the bar's numbers over
   when that crosses between the line modes and the grid ones. */
static void ht_mode_set(int id)
{
    static const int ID[3] = { 1419, 1411, 1412 };
    int was = ht_mode >= 1692, now = id >= 1692, i;

    if (was != now)
        for (i = 0; i < 3; i++) {
            const char *t = jw_cmd_box(ID[i]);

            if (t) {
                strncpy(ht_keep[was][i], t, sizeof ht_keep[0][0] - 1);
                ht_keep[was][i][sizeof ht_keep[0][0] - 1] = 0;
            }
            box_put(ID[i], ht_keep[now][i]);
        }
    ht_mode = id;
}

const char *jw_cmd_box(int id)
{
    int i;

    for (i = 0; i < (int)(sizeof box / sizeof box[0]); i++)
        if (box[i].id == id && box[i].cmd == current)
            return box[i].t;
    return 0;
}

int jw_cmd_box_focus(void)
{
    return box_focus;
}

void jw_cmd_box_click(int id)
{
    box_focus = jw_cmd_box(id) ? id : 0;
}

int jw_cmd_box_key(int ch)
{
    int i;

    if (!box_focus)
        return 0;
    for (i = 0; i < (int)(sizeof box / sizeof box[0]); i++) {
        char *t;
        int n;
        if (box[i].id != box_focus || box[i].cmd != current)
            continue;
        t = box[i].t;
        n = (int)strlen(t);
        if (ch == 13 || ch == 27) {         /* Enter, Esc: done */
            box_focus = 0;
            return 1;
        }
        if (ch == 8) {                      /* backspace */
            if (n)
                t[n - 1] = 0;
            return 1;
        }
        /* ２線's box holds two numbers with a comma between them */
        if ((ch >= '0' && ch <= '9') || ch == '.' || ch == '-' || ch == ',') {
            if (n < (int)sizeof box[i].t - 1) {
                t[n] = (char)ch;
                t[n + 1] = 0;
            }
            return 1;
        }
        return 1;                           /* anything else: swallowed */
    }
    return 0;
}

/* One 多角形, round the point that was clicked.
 *
 * Read off the original: the 寸法 box is the radius out to a corner in real
 * units, so paper millimetres are that over the layer group's scale (2000 on
 * a 1/200 group came out 10 mm across the paper); 角数 is how many corners;
 * and the shape sits with its base level, turned by 底辺角度.  The corners
 * are therefore at -90 - 180/n + 底辺角度 and every 360/n after that, going
 * round the way the original's lines do.  A pentagon of 3000 at 30 degrees
 * and an octagon of 3000 at 30 both came out exactly there. */
static void takaku(jw_drawing *d, double cx, double cy)
{
    const char *sz = jw_cmd_box(1411), *ns = jw_cmd_box(1413);
    const char *ang = jw_cmd_box(1414);
    double r = sz ? atof(sz) : 0.0, a0 = ang ? atof(ang) : 0.0;
    int n = ns ? atoi(ns) : 0, i, wg = 0, made = 0;

    if (n < 3 || n > 1000 || r <= 0.0)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    if (d->group[wg].scale > 0.0)
        r /= d->group[wg].scale;
    a0 = (a0 - 90.0 - 180.0 / n) * PI / 180.0;
    for (i = 0; i < n; i++) {
        double t0 = a0 + 2.0 * PI * i / n, t1 = a0 + 2.0 * PI * (i + 1) / n;
        jw_obj *o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->d[0] = cx + r * cos(t0);
        o->d[1] = cy + r * sin(t0);
        o->d[2] = cx + r * cos(t1);
        o->d[3] = cy + r * sin(t1);
        made++;
    }
    op_push(made);
}

/* The number a dimension is written with.
 *
 * The length is in paper millimetres; what goes on the drawing is the real
 * length, which is that times the scale of the layer group it is on -- the
 * original measured 346.3557 mm on a 1/200 group and wrote 69,271.14.
 * Then SHOUSUUKETA decimals, a comma every three digits if ShowComma, and
 * with ShowZero off the trailing zeros of the fraction go. */
static void sunpo_text(char *out, int n, double mm, double scale)
{
    char buf[64], *p = buf;
    double v = mm * scale;
    int i, len, k, neg = v < 0.0, whole;

    if (neg)
        v = -v;
    sprintf(buf, "%.*f", JW_SUN_DECIMALS, v);
    if (JW_SUN_DECIMALS > 0 && !JW_SUN_ZERO) {
        char *dot = strchr(buf, '.');
        if (dot) {
            char *e = buf + strlen(buf);
            while (e > dot && e[-1] == '0')
                *--e = 0;
            if (e == dot + 1)
                *dot = 0;
        }
    }
    len = (int)strlen(p);
    whole = (int)(strchr(p, '.') ? strchr(p, '.') - p : len);
    k = 0;
    if (neg && k < n - 1)
        out[k++] = '-';
    for (i = 0; i < len && k < n - 1; i++) {
        if (JW_SUN_COMMA && i && i < whole && (whole - i) % 3 == 0)
            out[k++] = ',';
        if (k < n - 1)
            out[k++] = p[i];
    }
    out[k] = 0;
}

/* Put the six elements of one dimension in the drawing. */
static void sunpo_make(jw_drawing *d, double bx, double by)
{
    double a = sun_deg == 90 ? PI / 2.0 : 0.0;
    double ux = cos(a), uy = sin(a), vx = -uy, vy = ux;
    /* along the dimension's own direction, and across it */
    double s0 = sun_sx * ux + sun_sy * uy, s1 = bx * ux + by * uy;
    double tl = sun_lx * vx + sun_ly * vy;      /* the dimension line       */
    double th = sun_hx * vx + sun_hy * vy;      /* where the extensions end */
    double x0 = s0 * ux + tl * vx, y0 = s0 * uy + tl * vy;
    double x1 = s1 * ux + tl * vx, y1 = s1 * uy + tl * vy;
    double len = s1 > s0 ? s1 - s0 : s0 - s1;
    double cw, ch, sp, tw = 0.0;
    char txt[64];
    const char *p;
    int nch = 0, i, wg = 0, made = 0;
    jw_obj *o;

    if (len <= 0.0)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;

    /* 寸法線 */
    o = jw_add(d, JW_SEN);
    if (!o)
        return;
    o->color = JW_SUN_SEN_COLOR;
    o->ltype = 1;
    o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
    o->d[0] = x0; o->d[1] = y0; o->d[2] = x1; o->d[3] = y1;
    made++;

    /* 端部 -- a point at each end while Arrow is 0 */
    if (!JW_SUN_ARROW)
        for (i = 0; i < 2; i++) {
            o = jw_add(d, JW_TEN);
            if (!o)
                break;
            o->color = JW_SUN_TEN_COLOR;
            o->ltype = 1;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEN_FLAGS);
            o->d[0] = i ? x1 : x0;
            o->d[1] = i ? y1 : y0;
            o->n = 0;
            made++;
        }

    /* 引出線 -- from the dimension line out to where the first click was */
    for (i = 0; i < 2; i++) {
        double s = i ? s1 : s0;
        o = jw_add(d, JW_SEN);
        if (!o)
            break;
        o->color = JW_SUN_HIKI_COLOR;
        o->ltype = 1;
        o->flags = (unsigned short)(o->flags | JW_SUN_LINE_FLAGS);
        o->d[0] = s * ux + (tl + JW_SUN_TSUKIDASHI) * vx;
        o->d[1] = s * uy + (tl + JW_SUN_TSUKIDASHI) * vy;
        o->d[2] = s * ux + th * vx;
        o->d[3] = s * uy + th * vy;
        made++;
    }

    /* 寸法値 -- 文字種 MOJINO, centred on the line and HANARE above it */
    i = JW_SUN_MOJINO - 1;
    if (i < 0 || i > 9)
        i = 0;
    cw = d->style[i].w;
    ch = d->style[i].h;
    sp = d->style[i].sp;
    sunpo_text(txt, (int)sizeof txt, len, d->group[wg].scale);
    for (p = txt; *p; ) {
        int wide = jw_is_lead((unsigned char)p[0]) && p[1];
        if (nch)
            tw += wide ? sp : sp / 2;
        tw += wide ? cw : cw / 2;
        p += wide ? 2 : 1;
        nch++;
    }
    if (cw > 0.0 && ch > 0.0 && nch) {
        double mid = (s0 + s1) / 2.0, t = tl + JW_SUN_HANARE;
        o = jw_add(d, JW_MOJI);
        if (o) {
            o->color = (unsigned short)d->style[i].color;
            /* an ordinary text has 1 here; the dimension value the original
               wrote has 2, and 0x2043 in the word at +0x2c */
            o->ltype = 2;
            o->width = JW_SUN_TEXT_WIDTH;
            o->flags = (unsigned short)(o->flags | JW_SUN_TEXT_FLAGS);
            o->d[0] = (mid - tw / 2.0) * ux + t * vx;
            o->d[1] = (mid - tw / 2.0) * uy + t * vy;
            o->d[2] = (mid + tw / 2.0) * ux + t * vx;
            o->d[3] = (mid + tw / 2.0) * uy + t * vy;
            o->d[4] = cw;
            o->d[5] = ch;
            o->d[6] = sp;
            o->d[7] = 0.0;
            o->n = JW_SUN_MOJINO;
            o->text = jw_add_str(d, txt);
            o->face = -1;
            made++;
        }
    }
    op_push(made);
}

void jw_cmd_point(jw_drawing *d, const jw_view *v,
                  double x, double y, int button)
{
    if (current == JW_CMD_TAKAKU) {
        if (button == 0 && d)
            takaku(d, x, y);
        return;
    }
    if (current == JW_CMD_SUNPO) {
        double rx, ry;
        if (!d)
            return;
        if (sun_step < 2) {
            /* (L) is where it was clicked, (R) reads a point */
            if (button != 0 && !jw_read(d, v, x, y, &x, &y))
                return;
            if (sun_step == 0) {
                sun_hx = x;
                sun_hy = y;
            } else {
                sun_lx = x;
                sun_ly = y;
            }
            sun_step++;
            return;
        }
        /* the two measured points have to be read ones */
        if (!jw_read(d, v, x, y, &rx, &ry))
            return;
        if (sun_step == 2) {
            sun_sx = rx;
            sun_sy = ry;
            sun_step = 3;
            return;
        }
        sunpo_make(d, rx, ry);
        sun_step = 2;           /* ready for the next one */
        return;
    }
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
    if (current == JW_CMD_CHUSHIN) {
        int i;
        if (button != 0 || !d)
            return;             /* (R) reads a point, which is not done */
        if (chu_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            chu_a = i;
            chu_step = 1;
            return;
        }
        if (chu_step == 1) {
            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == chu_a || d->obj[i].cls != JW_SEN)
                return;
            chu_b = i;
            chu_step = 2;
            return;
        }
        if (chu_step == 2) {
            chu_x = x;
            chu_y = y;
            chu_step = 3;
            return;
        }
        chushin(d, x, y);
        chu_step = 2;           /* the same middle, another line */
        return;
    }
    if (current == JW_CMD_HATCH) {
        int i;
        if (!d)
            return;
        if (button != 1)
            return;             /* the left button picks one line at a time,
                                   which this port does not do yet */
        i = jw_pick(d, v, x, y, 3);
        if (i < 0)
            return;
        if (d->obj[i].cls == JW_ENKO) {
            ht_round = 1;
            ht_cx = d->obj[i].d[0];
            ht_cy = d->obj[i].d[1];
            ht_r = d->obj[i].d[2];
            ht_n = 0;
        } else if (d->obj[i].cls == JW_SEN) {
            ht_round = 0;
            if (!hatch_ring(d, i))
                ht_n = 0;
        }
        return;
    }
    if (current == JW_CMD_KYOKUSEN) {
        if (button != 0 || !d)
            return;
        if (cv_n < CV_MAX) {
            cv_x[cv_n] = x;
            cv_y[cv_n] = y;
            cv_n++;
        }
        return;
    }
    if (current == JW_CMD_SEKIEN) {
        int i;
        if (button != 0 || !d)
            return;
        if (sek_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO))
                return;
            sek_a = i;
            sek_step = 1;
            return;
        }
        if (sek_step == 1) {
            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == sek_a
                || (d->obj[i].cls != JW_SEN && d->obj[i].cls != JW_ENKO))
                return;
            sek_b = i;
            sek_step = 2;
            return;
        }
        if (sek_radius(d) <= 0.0) {
            /* an empty 半径: the third element settles it, and it is drawn
               the moment that is picked */
            i = jw_pick_tie(d, v, x, y, 3, 1);
            if (i < 0 || i == sek_a || i == sek_b)
                return;
            sekien3(d, sek_a, sek_b, i, x, y);
        } else {
            sekien(d, sek_a, sek_b, x, y);
        }
        sek_step = 0;                   /* ready for the next pair */
        sek_a = sek_b = -1;
        return;
    }
    if (current == JW_CMD_SESSEN) {
        int i;
        if (button != 0 || !d)
            return;
        if (ses_mode == 1691 || ses_mode == 1692) {
            sesline(d, v, x, y);
            return;
        }
        if (ses_mode == 1690) {         /* 点→円: the point, then the circle */
            if (ses_step == 0) {
                ses_x = x;
                ses_y = y;
                ses_step = 1;
                return;
            }
            i = jw_pick(d, v, x, y, 3);
            if (i >= 0 && d->obj[i].cls == JW_ENKO)
                tensen(d, i, ses_x, ses_y, x, y);
            ses_step = 0;
            return;
        }
        if (ses_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_ENKO)
                return;
            ses_a = i;
            ses_x = x;          /* the side of this circle that was pointed at */
            ses_y = y;
            ses_step = 1;
            return;
        }
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && i != ses_a && d->obj[i].cls == JW_ENKO)
            sessen(d, ses_a, i, x, y);
        ses_step = 0;           /* ready for the next pair */
        ses_a = -1;
        return;
    }
    if (current == JW_CMD_NISEN) {
        int i;
        if (button != 0 || !d)
            return;
        if (nisen_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN || !nisen_gap(d))
                return;
            nisen_obj = i;
            nisen_step = 1;
            return;
        }
        if (nisen_step == 1) {
            nisen_x = x;
            nisen_y = y;
            nisen_step = 2;
            return;
        }
        if (nisen_obj >= 0 && nisen_obj < d->nobj)
            nisen(d, x, y);
        nisen_step = 0;         /* ready for the next line to run along */
        nisen_obj = -1;
        return;
    }
    if (current == JW_CMD_BUNKATSU) {
        int i;
        if (button != 0 || !d)
            return;
        if (corner_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            corner_obj = i;
            corner_step = 2;
            return;
        }
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && i != corner_obj)
            bunkatsu(d, corner_obj, i);
        corner_step = 0;
        return;
    }
    if (current == JW_CMD_MENTORI) {
        int i;
        if (button != 0 || !d)
            return;
        if (corner_step == 0) {
            i = jw_pick(d, v, x, y, 3);
            if (i < 0 || d->obj[i].cls != JW_SEN)
                return;
            corner_obj = i;
            corner_x = x;
            corner_y = y;
            corner_step = 2;
            return;
        }
        i = jw_pick_tie(d, v, x, y, 3, 1);
        if (i >= 0 && i != corner_obj)
            mentori(d, corner_obj, corner_x, corner_y, i, x, y);
        corner_step = 0;
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
