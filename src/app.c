#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

#include "app.h"
#include "ui.h"
#include "outfont.h"
#include "text.h"
#include "draw.h"
#include "view.h"
#include "cmd.h"
#include "pick.h"
#include "plot.h"
#include "umekomi.h"
#include "d25view.h"
#include "tategu.h"
#include "senkigou.h"
#include "image.h"
#include "gen/layout.h"
#include "gen/cmds.h"
#include "gen/tips.h"
#include "gen/newjww.h"
#include "gen/pens.h"
#include "gen/prompts.h"

static fb_t fb;
/* the caption and menu bar, painted above the client for the build that has
   no window of its own (app_chrome) */
static fb_t chrome;
static int chrome_on;
static char title[128] = "\x96\xb3\x91\xe8 - jw_win";   /* 無題 - jw_win */
static jw_view view;
static int view_ready;
static jw_drawing drawing;
static int have_drawing;
static int have_file;      /* 上書 is grey until there is one */
static int new_count;          /* how many times app_new has started afresh */
static unsigned clean_stamp;   /* jw_cmd_edit_stamp() when it was last saved */
static int action;         /* what the front end has been asked to do */
static const char *last_error = "";
static unsigned char *rgba;
static int rgba_n;

void app_fit(void)
{
    rect_t r;

    if (!fb.px)
        return;
    ui_view_rect(fb.w, fb.h, &r);
    jw_view_fit(&view, &r, have_drawing ? drawing.paper_hw : 297.0,
                have_drawing ? drawing.paper_hh : 210.0);
    view_ready = 1;
}

/* Zoom about a point on the screen, so what is under it stays put. */
void app_zoom(double factor, int sx, int sy)
{
    double wx, wy;

    if (!view_ready || factor <= 0.0)
        return;
    wx = view.ox + (sx - view.bx) / view.scale;
    wy = view.oy + (view.by - sy) / view.scale;
    /* Enough steps one way run the millimetres per pixel out of the range
       of a double, and a view whose scale is 0 or infinite turns every
       coordinate after it into a NaN.  Refuse the step instead: nothing a
       person can reach is anywhere near this, but the command fuzzer holds
       the zoom key down thousands of times. */
    if (!(view.mmpp / factor > 1e-300 && view.mmpp / factor < 1e300))
        return;
    view.mmpp /= factor;
    view.scale = 1.0 / view.mmpp;
    view.ox = wx - (sx - view.bx) / view.scale;
    view.oy = wy - (view.by - sy) / view.scale;     /* it is wy that sits at sy */
}

void app_pan(int dx, int dy)
{
    if (!view_ready)
        return;
    view.ox -= dx / view.scale;
    view.oy += dy / view.scale;
}

const jw_view *app_view(void)
{
    return &view;
}

/* Which toolbar button is under the point, or -1.  The buttons are all the
   same size and their corners are in layout.h. */
static int hit_button(int x, int y)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++) {
        const jw_btn_t *b = &jw_buttons[k];
        /* the right-hand column rides the right edge, so the hit test has
           to move with it (ui.h) */
        int bx = ui_ax(b->x, fb.w);
        if (x >= bx && x < bx + BTN_W && y >= b->y && y < b->y + BTN_H)
            return k;
    }
    return -1;
}

static int in_view(int x, int y)
{
    rect_t r;

    if (!fb.px)
        return 0;
    ui_view_rect(fb.w, fb.h, &r);
    return x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h;
}

/* Screen pixels back to paper millimetres -- the other way round from
   FUN_004b6d60. */
static void to_paper(int x, int y, double *px, double *py)
{
    *px = view.ox + (x - view.bx) / view.scale;
    *py = view.oy + (view.by - y) / view.scale;
}

/* A press on one of the two grids at the bottom right.
 *
 * What each button does was read off the original: Test5 was opened, cells
 * were pressed and the file saved, and the states in it say
 *
 *   left  -- steps the cell round 編集可(2) -> 非表示(0) -> 表示のみ(1) ->
 *            編集可, and does nothing at all on the one being written to
 *            (three presses on layer 6 brought it back where it started,
 *            and one on the write layer changed nothing);
 *   right -- makes it the one written to (3), and the one that was drops
 *            to 編集可.
 *
 * The group grid behaves the same way. */
/* Shift and Ctrl as they were when the button went down.  The original
 * keeps them in two globals of its own (0xa0cc6c Shift, 0xa0cc74 Ctrl --
 * the strings "[Shift]" and "[Ctrl]" at 0x40ea40 are printed off them), and
 * the layer cells look at Ctrl.  The front end says what they are
 * (app_keymods) before it hands over the press. */
static int ly_shift, ly_ctrl;

void app_keymods(int shift, int ctrl)
{
    ly_shift = shift != 0;
    ly_ctrl = ctrl != 0;
    jw_cmd_keymods(shift, ctrl);
}

/* 反転表示 (0x805c, the X under the group grid): FUN_00508a50 keeps every
 * state (document +0x246c and +0x1c2c), then turns the picture inside out --
 * every group editable, and in a group that was 非表示 or 表示のみ every
 * layer editable, in one that was 編集可 or 書込 every 非表示 / 表示のみ layer
 * editable and every editable one 非表示; an editable one that is protected
 * (its own or its group's protection) is 表示のみ instead.  The second press
 * (FUN_004fd3b0) puts the kept states back, and so do choosing a command
 * (FUN_004fdc40) and 戻る (FUN_00504100 does that and nothing else).  While
 * it is on, the cells and the two All buttons do nothing (+0x1824).
 * The write group keeps its 3 here, unlike the original's 2: the port finds
 * the write group by that 3.  Read off the decompilation, not pressed. */
static int ly_inv;
static int ly_inv_g[16], ly_inv_l[16][16];

static void ly_invert(void)
{
    int g, l;

    for (g = 0; g < 16; g++) {
        jw_group *gr = &drawing.group[g];
        int gs = gr->state;

        ly_inv_g[g] = gs;
        for (l = 0; l < 16; l++)
            ly_inv_l[g][l] = gr->layer[l].state;
        if (gs != 3)
            gr->state = 2;
        for (l = 0; l < 16; l++) {
            int s0 = ly_inv_l[g][l], ns;

            ns = gs == 0 || gs == 1 ? 2 : s0 == 0 || s0 == 1 ? 2 : 0;
            if (ns == 2 && (gr->layer[l].state2 != 0 || gr->c != 0))
                ns = 1;
            gr->layer[l].state = ns;
        }
    }
    ly_inv = 1;
}

static void ly_restore(void)
{
    int g, l;

    if (!ly_inv)
        return;
    ly_inv = 0;
    if (!have_drawing)
        return;
    for (g = 0; g < 16; g++) {
        drawing.group[g].state = ly_inv_g[g];
        for (l = 0; l < 16; l++)
            drawing.group[g].layer[l].state = ly_inv_l[g][l];
    }
}

static int ly_wg(void)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (drawing.group[i].state == 3)
            wg = i;
    return wg;
}

/* a cell's protection: a layer's is state2, a group's the c after its
   scale (src/jww.c) -- 0 none, 1 protected, 2 protected and its state
   cannot be changed either */
static int *ly_prot(int g, int n)
{
    return g == 0 ? &drawing.group[ly_wg()].layer[n].state2
                  : &drawing.group[n].c;
}

/* bar: 1 for the grids beside the drawing (CLayerControlButton), 0 for
 * the dialog's sixteen (CLayerButton), which do not look at Ctrl.
 *
 * Ctrl + left on a cell that is not the write one (FUN_0055ea10): its
 * protection goes 0 -> 1, or 0 -> 2 with Shift as well, and anything else
 * back to 0; the state is left alone.  A cell protected with 2 does not
 * step round (both classes, +0xb0 != 2), and one protected at all cannot be
 * made the write one (the bar's FUN_005571b0, the dialog's FUN_00561750,
 * which looks at the group's protection too).  Read off the decompilation,
 * not pressed. */
static int press_layer_in(int g, int n, int button, int bar)
{
    jw_group *grp;
    int wg, *st, *pr;

    if (!have_drawing || ly_inv)
        return 0;
    wg = ly_wg();
    grp = &drawing.group[wg];
    st = g == 0 ? &grp->layer[n].state : &drawing.group[n].state;
    pr = ly_prot(g, n);
    if (button != 0) {
        if (*pr != 0)
            return 0;
        if (g == 0) {
            grp->layer[grp->write_layer & 15].state = 2;
            grp->layer[n].state = 3;
            grp->write_layer = n;
        } else {
            drawing.group[wg].state = 2;
            drawing.group[n].state = 3;
        }
        return 1;
    }
    if (*st == 3)
        return 0;
    if (bar && ly_ctrl) {
        *pr = *pr != 0 ? 0 : ly_shift ? 2 : 1;
        return 1;
    }
    if (*pr == 2)
        return 0;
    *st = *st == 2 ? 0 : *st == 0 ? 1 : 2;
    return 1;
}

static int press_layer(int g, int n, int button)
{
    return press_layer_in(g, n, button, 1);
}

/* The four buttons under the grids (FUN_00555b70 makes them).
 *
 *   0  All under the layers, a CMy3Button whose left and right presses
 *      send the bar 0x1403 with 1 and 2 (FUN_0058b8b0) -- FUN_00557600
 *   1  the one under it, 0x805a DispGLayerBar: the group bar comes and goes
 *      (FUN_0056a080)
 *   2  All under the groups, the same as 0 for the sixteen groups
 *   3  the X, 0x805c 反転表示／反転解除 (FUN_00508a50, above)
 *
 * All, left: the bar's own state (+0xfc, 2 when it is made) steps
 * 2 -> 0 -> 1 -> 2 and every cell that is not the write one and not
 * protected with 2 is put at it; right: the state is 2 and so are they.
 * With Ctrl the left one steps the bar's protection instead (+0x100:
 * 0 -> 1, or 2 with Shift, and back to 0) and every cell but the write one
 * is given it.  Read off the decompilation, not pressed. */
static int ly_all[2] = { 2, 2 }, ly_allp[2];

static int press_layer_small(int k, int button)
{
    int g = k >= 2, i, wg;

    if (k == 1) {
        if (button != 0)
            return 0;
        ui_glayer_show(!ui_glayer_shown());
        return 1;
    }
    if (!have_drawing)
        return 0;
    if (k == 3) {
        if (button != 0)
            return 0;
        if (ly_inv)
            ly_restore();
        else
            ly_invert();
        return 1;
    }
    if (ly_inv)
        return 0;
    wg = ly_wg();
    if (button == 0 && ly_ctrl) {
        ly_allp[g] = ly_allp[g] != 0 ? 0 : ly_shift ? 2 : 1;
        for (i = 0; i < 16; i++) {
            int st = g == 0 ? drawing.group[wg].layer[i].state
                            : drawing.group[i].state;
            if (st != 3)
                *ly_prot(g, i) = ly_allp[g];
        }
        return 1;
    }
    ly_all[g] = button != 0 ? 2
              : ly_all[g] == 2 ? 0 : ly_all[g] == 0 ? 1 : 2;
    for (i = 0; i < 16; i++) {
        int *st = g == 0 ? &drawing.group[wg].layer[i].state
                         : &drawing.group[i].state;
        if (*ly_prot(g, i) != 2 && *st != 3)
            *st = ly_all[g];
    }
    return 1;
}

/* 線属性 (0x8027): the dialog is up, and what it has picked so far.  The
 * original applies them when Ok is pressed and drops them on キャンセル. */
static int zoku_open, zoku_color, zoku_ltype;
/* Who put the 線属性 dialog up: 0 the 線属性 command itself, which sets the
 * write pen; 1 属性選択's 指定【線色】指定 / 指定 線種 指定, which is where
 * that "指定" comes from; 2 属性変更's 指定…に変更.  The rest is what those
 * two had settled before the dialog came up.
 */
static int zoku_for;
static int zs_mask, zs_exclude, zs_wantc, zs_wantl;
static int zh_lay, zh_grp, zh_wantc, zh_wantl;

/* Put the 線属性 dialog up on top of one of them. */
static void zoku_ask(int who)
{
    zoku_color = have_drawing && drawing.write_color
                 ? drawing.write_color : 2;
    zoku_ltype = have_drawing && drawing.write_ltype
                 ? drawing.write_ltype : 1;
    zoku_for = who;
    zoku_open = 1;
}

int app_zoku_open(void)
{
    return zoku_open;
}

static int press_zoku(int x, int y)
{
    int id = ui_zoku_hit(fb.w, fb.h, x, y);

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id >= 1401 && id <= 1409)
        zoku_color = id - 1400;
    else if (id >= 2449 && id <= 2457)
        zoku_ltype = id - 2448;
    else if (id == 1) {                 /* Ok */
        if (have_drawing && zoku_for == 1)
            jw_cmd_zokusel(&drawing, zs_mask, zs_exclude,
                           zs_wantc ? zoku_color : 0,
                           zs_wantl ? zoku_ltype : 0);
        else if (have_drawing && zoku_for == 2)
            jw_cmd_zokuhen_range(&drawing, zh_lay, zh_grp,
                                 zh_wantc ? zoku_color : 0,
                                 zh_wantl ? zoku_ltype : 0);
        else if (have_drawing) {
            drawing.write_color = (unsigned short)zoku_color;
            drawing.write_ltype = (unsigned char)zoku_ltype;
        }
        zoku_for = 0;
        zoku_open = 0;
    } else if (id == 2) {               /* キャンセル */
        zoku_for = 0;
        zoku_open = 0;
    }
    return 1;
}

/* 書込み文字種変更: the dialog the 文字 bar's own button puts up.  Which
 * 文字種 is chosen is kept here while it is open and only reaches the
 * drawing on Ok, the way 線属性 does.  0 is 任意サイズ, which leaves the
 * drawing's own size alone.
 */
static int moji_open, moji_style;
/* The three boxes -- width, height and the space between letters -- and
 * which of them the typing goes into.  They are what 任意サイズ writes at,
 * and picking one of the ten fills them with its numbers.  Driving the
 * original bears it out: typing 30, 40 and 2 with 任意サイズ chosen and
 * pressing OK gave the next text w=30 h=40 sp=2 (decomp/res/mojisize.jww).
 */
static char moji_box[3][16];
static int moji_focus;          /* 1491, 1492, 1493, or 0 for none */
/* 色No. (ComboBox 2358).  Driving the original says the row it is set to
 * **is** the colour: row 4 gave a text of colour 4 and row 6 one of colour
 * 6 (decomp/res/mojicol.jww).  The port drops a list of its own down when
 * the box is pressed -- the original's dropdown has not been photographed,
 * so the picture of it is the port's own. */
static int moji_color = 1;
static int moji_drop;           /* whether that list is down */

int app_moji_color(void)
{
    return moji_color;
}

int app_moji_drop(void)
{
    return moji_drop;
}

/* フォント (ComboBox 1423).  The original fills it with the machine's
 * installed faces, so there is nothing to copy; the port's list is the four
 * faces of the MS family a drawing usually names -- which the port draws in
 * IPAex, the gothic or the mincho, see src/outfont.h -- and then the three
 * outline fonts by their own names.  Row 0 is ＭＳ ゴシック, the default.  OK
 * writes the face into what new texts carry (jw_cmd_moji_face_set), and
 * from there into the .jww exactly as spelled here. */
static const char *const FACES[] = {
    "\x82l\x82r \x83S\x83V\x83" "b\x83N",                  /* ＭＳ ゴシック  */
    "\x82l\x82r \x82o\x83S\x83V\x83" "b\x83N",             /* ＭＳ Ｐゴシック */
    "\x82l\x82r \x96\xbe\x92\xa9",                          /* ＭＳ 明朝      */
    "\x82l\x82r \x82o\x96\xbe\x92\xa9",                     /* ＭＳ Ｐ明朝    */
};
#define NFACES ((int)(sizeof FACES / sizeof FACES[0]))

static int moji_font;

int app_moji_font(void)
{
    return moji_font;
}

int app_moji_font_n(void)
{
    return NFACES + jw_outfont_count();
}

const char *app_moji_font_item(int k)
{
    if (k < 0)
        k = 0;
    return k < NFACES ? FACES[k] : jw_outfont_name(k - NFACES);
}

static int moji_font_now(void)
{
    const char *f = jw_cmd_moji_face();
    int k;

    for (k = 0; k < NFACES; k++)
        if (!strcmp(f, FACES[k]))
            return k;
    k = jw_outfont_find(f);
    return k >= 0 ? NFACES + k : 0;
}

static void moji_fill(const jw_drawing *d, int style)
{
    double w, h, sp;

    if (style >= 1 && style <= 10) {
        w = d->style[style - 1].w;
        h = d->style[style - 1].h;
        sp = d->style[style - 1].sp;
    } else {
        w = d->cur_style.w;
        h = d->cur_style.h;
        sp = d->cur_style.sp;
    }
    /* the sizes come from the drawing, and a damaged one can hold 1e300
       -- which "%.2f" spells in three hundred characters, where these hold
       sixteen (the same shape as src/sfcwrite.c's ang(), found with
       -fsanitize=address) */
    snprintf(moji_box[0], sizeof moji_box[0], "%.2f", w);
    snprintf(moji_box[1], sizeof moji_box[1], "%.2f", h);
    snprintf(moji_box[2], sizeof moji_box[2], "%.3f", sp);
}

const char *app_moji_box(int id)
{
    if (id == 1491)
        return moji_box[0];
    if (id == 1492)
        return moji_box[1];
    if (id == 1493)
        return moji_box[2];
    return 0;
}

int app_moji_focus(void)
{
    return moji_focus;
}

int app_moji_open(void)
{
    return moji_open;
}

/* ---------------------------------------------------- 属性選択 (1069) --
 * One byte per control of the dialog, 1 when it is ticked.  The two at the
 * bottom -- 【指定属性選択】 and 《指定属性除外》 -- are one choice between
 * them: the original unticks the one when the other is ticked, which is
 * what driving it showed (a dump taken after pressing 1324 has 1323 off).
 */
static int zsel_open;
static unsigned char zsel_on[64];

int app_zokusel_open(void)
{
    return zsel_open;
}

const unsigned char *app_zokusel_on(void)
{
    return zsel_on;
}

static void zsel_start(void)
{
    int i, n = ui_zokusel_n();

    for (i = 0; i < n && i < (int)sizeof zsel_on; i++)
        zsel_on[i] = (unsigned char)(ui_zokusel_id(i) == 1323);
    jw_cmd_zokusel_name("");
    zsel_open = 1;
}

static void zsel_tick(int id, int on)
{
    int i, n = ui_zokusel_n();

    for (i = 0; i < n && i < (int)sizeof zsel_on; i++)
        if (ui_zokusel_id(i) == id)
            zsel_on[i] = (unsigned char)(on != 0);
}

/* Which kinds the ticks add up to, for jw_cmd_zokusel. */
static int zsel_mask(void)
{
    static const struct { int id, bit; } K[] = {
        { 1812, JW_ZOK_SEN },   { 2434, JW_ZOK_ENKO },
        { 2430, JW_ZOK_TEN },   { 1804, JW_ZOK_MOJI },
        { 2433, JW_ZOK_SOLID }, { 2431, JW_ZOK_HOJO },
        { 1802, JW_ZOK_BLOCK }
    };
    int i, k, n = ui_zokusel_n(), mask = 0;

    for (i = 0; i < n && i < (int)sizeof zsel_on; i++) {
        if (!zsel_on[i])
            continue;
        for (k = 0; k < (int)(sizeof K / sizeof K[0]); k++)
            if (K[k].id == ui_zokusel_id(i))
                mask |= K[k].bit;
    }
    return mask;
}

/* ---------------------------------------------------- ブロック化 -------
 * The command puts a dialog up rather than doing anything at once: a box
 * for the name, and 元データのレイヤを優先する beside it.
 */
static int blk_open, blk_pref, blk_attr;
/* ブロック編集's own dialog, which comes up before the mode starts */
static int be_open, be_all = 1;
/* 基本設定: one byte per control, 1 for ticked */
/* 軸角・目盛・オフセット */
static int jk_open;
static char jk_angle[16];
static unsigned char jk_on[32];
static unsigned char jk_saved[32];       /* what OK left ticked */
static int jk_have_saved;

int app_jikkaku_open(void)
{
    return jk_open;
}

const char *app_jikkaku_angle(void)
{
    return jk_angle;
}

static void jk_start(void)
{
    int i, n = ui_jikkaku_n();
    double a = jw_cmd_axis();

    for (i = 0; i < n && i < (int)sizeof jk_on; i++)
        jk_on[i] = (unsigned char)(jk_have_saved ? jk_saved[i] : ui_jikkaku_on(i));
    if (a == 0.0)
        strcpy(jk_angle, "0");
    else
        sprintf(jk_angle, "%g", a);
    jk_open = 1;
}

static int press_jikkaku(int x, int y)
{
    int id = ui_jikkaku_hit(fb.w, fb.h, x, y), i, n = ui_jikkaku_n();

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* Ok: the angle is applied */
        jw_cmd_set_axis(atof(jk_angle));
        memcpy(jk_saved, jk_on, sizeof jk_saved);
        jk_have_saved = 1;
        jk_open = 0;
        return 1;
    }
    if (id == 1411)
        return 1;                       /* the box the typing goes into */
    for (i = 0; i < n && i < (int)sizeof jk_on; i++)
        if (ui_jikkaku_id(i) == id)
            jk_on[i] = (unsigned char)!jk_on[i];
    return 1;
}

/* One key while it is up: the 軸角 box takes it. */
static int jk_key(int c)
{
    size_t n = strlen(jk_angle);

    if (c == 8) {
        if (n)
            jk_angle[n - 1] = 0;
        return 1;
    }
    if (c == 13) {
        jw_cmd_set_axis(atof(jk_angle));
        memcpy(jk_saved, jk_on, sizeof jk_saved);
        jk_have_saved = 1;
        jk_open = 0;
        return 1;
    }
    if (((c >= '0' && c <= '9') || c == '.' || c == '-')
        && n + 1 < sizeof jk_angle) {
        jk_angle[n] = (char)c;
        jk_angle[n + 1] = 0;
        return 1;
    }
    return 0;
}

/* 寸法設定 -- the picture only */
/* ---------------------------------------------------- 縮尺・読取 -----
 * What the menu's 縮尺・読取 (32944) and the status line's first two boxes
 * (32825 and 32827, sent by FUN_00596e80) put up.  The scale of a layer
 * group is a numerator over a denominator -- 1/200 -- and the list on the
 * left says what each of the sixteen is at.  Clicking one picks it; Ok
 * applies what the two boxes hold, to that group or to every editable one
 * if 全レイヤグループの縮尺変更 is ticked. */
static int sk_open, sk_group, sk_caret;

/* 建具のファイル選択（src/ui.c の ui_tgp）。建具平面に入ると（そして
   建具選択を押すと）出る。原典は窓が自分で絵を描くので、ここも同じ作り */
static int tgp_open, tgp_kind, tgp_file, tgp_page;
static int kj_open, kj_sel;             /* 基準点選択（建具の 基準点変更） */

static int td_open;
static int td_start(int tpl);
static int td_caret_set(int id);
static void td_first_no(void);
static void gz_check(void);
static void mb_close(int ok);
static int mb_open, mb_kind;
static char mb_text[400];
static int mb3_open;                    /* 天空図の「測定点が建物の内側」の問い（はい／いいえ／キャンセル） */
#define MB3_TEXT "\x8c\x9a\x95\xa8\x93\xe0\x95\x94\x82\xc9\x91\xaa\x92\xe8\x93_\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xbd\x89\xc2\x94\\x90\xab\x82\xaa\x82\xa0\x82\xe8\x82\xdc\x82\xb7\x81" "B  \x8ew\x8e\xa6\x82\xb5\x82\xbd\x91\xaa\x92\xe8\x93_\x82\xcc\x8f\xe3\x82\xc9\x94\xdd\x82\xdc\x82\xbd\x82\xcd\x89\xae\x8d\xaa\x82\xaa\x82\xa0\x82\xe8\x82\xdc\x82\xb7\x82\xa9\x81H"

static void tgp_tp_open(void);
static int hk_kind;                     /* 日影の窓の種類（jw_cmd_hikage_ask） */

static void tgp_check(void)
{
    if (!td_open && have_drawing && jw_cmd() == JW_CMD_HIKAGE && (hk_kind = jw_cmd_hikage_ask()) != 0) {
        if (td_start(348)) {
            td_caret_set(1411);
            if (hk_kind == 4)
                td_first_no();
        }
    }
    if (!mb3_open && have_drawing && jw_cmd() == JW_CMD_TENKU && jw_cmd_tenku_ask())
        mb3_open = 1;
    if (!mb_open && have_drawing && jw_cmd() == JW_CMD_TENKU && jw_cmd_tenku_north_ask()) {
        /* 「真北が設定されていません。」（0x15e2）、OK/キャンセル */
        strcpy(mb_text, "^kªÝè³êÄ"
                        "¢Ü¹ñB");
        mb_kind = 3;
        mb_open = 1;
    }
    if (!mb_open && have_drawing && jw_cmd() == JW_CMD_ZUKEI && jw_cmd_figure_ask()) {
        /* 図形読込: 「元レイヤグループに異なる縮尺があります。」（0x157e）、OK/キャンセル */
        strcpy(mb_text, JW_STR_5502);
        mb_kind = 5;
        mb_open = 1;
    }
    if (jw_cmd() == JW_CMD_GAZOU) {
        gz_check();
        if (!td_open && !mb_open)
            tgp_tp_open();
    }
    if (!tgp_open && jw_cmd_tategu_need_pick() && (jw_cmd() == JW_CMD_TATEGU || jw_cmd() == JW_CMD_TATEGU_DAN ||
         jw_cmd() == JW_CMD_TATEGU_RITSU)) {
        tgp_open = 1;
        tgp_kind = jw_cmd() == JW_CMD_TATEGU_RITSU ? 3
                 : jw_cmd() == JW_CMD_TATEGU_DAN ? 2 : 1;
        tgp_file = 0;
        tgp_page = 0;
    }
    if (!tgp_open && jw_cmd() == JW_CMD_KIGOU && jw_cmd_kigou_need_pick()) {
        tgp_open = 1;
        tgp_kind = 4;
        tgp_file = 0;
        tgp_page = 0;
    }
    if (!kj_open && !tgp_open && jw_cmd_tategu_need_ref()) {
        kj_open = 1;
        kj_sel = jw_cmd_tategu_ref();
    }
}

/* 基準点選択: ○ を押すと選んで閉じる（原典の窓は ○ を押すとそのまま閉じた） */
static int press_kj(int x, int y)
{
    int r = ui_kijun_hit(fb.w, fb.h, x, y);

    if (r >= 0) {
        jw_cmd_tategu_set_ref(r);
        kj_open = 0;
    }
    return 1;
}

static int press_tgp(int x, int y)
{
    int val = 0;
    int r = ui_tgp_hit(fb.w, fb.h, tgp_kind, tgp_file, tgp_page, x, y, &val);

    if (r == 1) {
        tgp_open = 0;
    } else if (r == 2) {
        tgp_file = val;
        tgp_page = 0;
    } else if (r == 3) {
        if (tgp_kind == 4)
            jw_cmd_kigou_choose(jw_tgdat_index(tgp_kind, tgp_file), val);
        else
            jw_cmd_tategu_choose(jw_tgdat_index(tgp_kind, tgp_file), val);
        tgp_open = 0;
    } else if (r == 4) {
        if (tgp_page > 0)
            tgp_page--;
    } else if (r == 5) {
        int idx = jw_tgdat_index(tgp_kind, tgp_file);
        const jw_tategu *t = tgp_kind == 4 ? 0 : jw_tategu_load(idx);
        const jw_senkigou *sg = tgp_kind == 4 ? jw_sk_load(idx) : 0;
        int per = ui_tgp_per_page(fb.w, fb.h, tgp_kind);

        if (t && (tgp_page + 1) * per < t->nitem)
            tgp_page++;
        else if (sg && (tgp_page + 1) * per < sg->nitem)
            tgp_page++;
    }
    return 1;                           /* modal: nothing behind hears it */
}


int app_shakudo_open(void)
{
    return sk_open;
}
static char sk_num[16] = "1", sk_den[16] = "100";
static unsigned char sk_on[64];
static unsigned char sk_saved[64];
static int sk_have_saved;
static char sk_list[16][16];
static const char *sk_listp[16];

static int sk_write_group(void)
{
    int g, wg = 0;

    if (!have_drawing)
        return 0;
    for (g = 0; g < 16; g++)
        if (drawing.group[g].state == 3)
            wg = g;
    return wg;
}

static void sk_fill(void)
{
    int g;

    for (g = 0; g < 16; g++) {
        double sc = have_drawing ? drawing.group[g].scale : 100.0;
        if (sc <= 0.0)
            sc = 1.0;
        sprintf(sk_list[g], "1/%g", sc);
        sk_listp[g] = sk_list[g];
    }
}

static void sk_start(void)
{
    int i, n = ui_shakudo_n();
    double sc;

    for (i = 0; i < n && i < (int)sizeof sk_on; i++)
        sk_on[i] = (unsigned char)(sk_have_saved ? sk_saved[i] : ui_shakudo_on(i));
    sk_group = sk_write_group();
    sc = have_drawing ? drawing.group[sk_group].scale : 100.0;
    if (sc <= 0.0)
        sc = 1.0;
    strcpy(sk_num, "1");
    sprintf(sk_den, "%g", sc);
    sk_caret = 1471;
    sk_fill();
    sk_open = 1;
}

/* 実寸固定 (1704) で縮尺が変わったときの要素の倍率（CScaleDialog の OnOK
   FUN_005ba3c0 → FUN_00449b30）: グループの要素を 原点まわりに 旧縮尺/新縮尺
   倍して、実寸を保つ。要素ごとの FUN_00465c40 は 文字サイズ変更 (1955,
   DAT_00a0cb58) が無ければ 文字の大きさを保ち（FUN_00466e30 → FUN_00465f40）、
   点マーカサイズ変更 (1956, DAT_00a0cb5c) があれば 点の +0x78（マーカの
   大きさ）も掛ける（FUN_00469fa0）。ブロックは挿入点と 倍率 x・y を掛ける
   （FUN_00464870）ので jw_obj_xform の原点まわりと同じ。倍率が 1e-5〜1e5 の
   外なら どれも何もしない。逆コンパイルの読み、原典では押していない。
   大きさを保つ文字は 移植は始点を動かして向きと長さを保つ（原典の
   FUN_00465f40 は字の基点まわりで取り直していて、そこは読み切っていない）。
   寸法図形は部品ごとに同じ扱い（FUN_00469060 は読んでいない）。元に戻す
   には積まない（残し）。 */
static void sk_xf(jw_obj *o, double s, int moji, int ten)
{
    if (o->cls == JW_MOJI && !moji) {
        double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];

        o->d[0] *= s;
        o->d[1] *= s;
        o->d[2] = o->d[0] + dx;
        o->d[3] = o->d[1] + dy;
        return;
    }
    jw_obj_xform(o, 0.0, 0.0, s, 0.0, 0.0, 0.0);
    if (o->cls == JW_TEN && ten && o->size != 0.0)
        o->size *= s;
}

/* 0 なら何もしていない。移植の守り: 掛けた先が図面の持てる数
   （jw_numbers_sane の ±1e12）を超える要素が一つでもあれば、縮尺も
   要素も変えない（tests/boxfuzz_test.c の 5e11 の線を 1/100 → 1/1 で） */
static int sk_rescale(int g, double old, double nw, int moji, int ten)
{
    double s;
    int i, k, pass;

    if (!(old > 0.0) || !(nw > 0.0) || old == nw)
        return 1;
    s = old / nw;
    if (!(s >= 1e-5 && s <= 1e5))
        return 1;
    for (pass = 0; pass < 2; pass++)
        for (i = 0; i < drawing.ndrawn && i < drawing.nobj; i++) {
            jw_obj t = drawing.obj[i];

            if (t.lgroup != g)
                continue;
            sk_xf(&t, s, moji, ten);
            if (pass) {
                /* 画像は w・h も掛け、字の大きさは保つ（FUN_00465c40 →
                   FUN_00466e30／FUN_00465f40 → FUN_0048f7f0） */
                jw_pic_xform(&drawing, &t, &drawing.obj[i], s, 0.0);
                drawing.obj[i] = t;
                continue;
            }
            for (k = 0; k < 8; k++)
                if (!(t.d[k] > -1e12 && t.d[k] < 1e12))
                    return 0;
        }
    return 1;
}

/* 縮尺を入れる。実寸固定 なら要素も（上） */
static void sk_set(int g, double sc, int jitsu, int moji, int ten)
{
    double old = drawing.group[g].scale;

    if (jitsu && old != sc && !sk_rescale(g, old, sc, moji, ten))
        return;
    drawing.group[g].scale = sc;
}

/* Ok: the two boxes become the group's scale.  1/200 is kept as the 200 the
   file carries, so a numerator of anything but 1 divides into it. */
static void sk_apply(void)
{
    double num = atof(sk_num), den = atof(sk_den);
    double sc;
    int g, all = 0, jitsu = 0, moji = 0, ten = 0, i, n = ui_shakudo_n();

    memcpy(sk_saved, sk_on, sizeof sk_saved);
    sk_have_saved = 1;
    for (i = 0; i < n && i < (int)sizeof sk_on; i++) {
        if (ui_shakudo_id(i) == 1954)
            all = sk_on[i];
        if (ui_shakudo_id(i) == 1704)   /* 実寸固定（図寸固定 1705 と二択） */
            jitsu = sk_on[i];
        if (ui_shakudo_id(i) == 1955)   /* 文字サイズ変更 */
            moji = sk_on[i];
        if (ui_shakudo_id(i) == 1956)   /* 点マーカサイズ変更 */
            ten = sk_on[i];
    }
    if (!have_drawing || num == 0.0 || den <= 0.0)
        return;
    sc = den / num;
    if (sc <= 0.0)
        return;
    if (!all) {
        sk_set(sk_group, sc, jitsu, moji, ten);
        return;
    }
    for (g = 0; g < 16; g++)
        if (drawing.group[g].state == 1 || drawing.group[g].state == 3)
            sk_set(g, sc, jitsu, moji, ten);
}

static int press_shakudo(int x, int y)
{
    int id = ui_shakudo_hit(fb.w, fb.h, x, y), i, n = ui_shakudo_n();

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* Ok */
        sk_apply();
        sk_open = 0;
        return 1;
    }
    if (id == 2) {                      /* キャンセル */
        sk_open = 0;
        return 1;
    }
    if (id == 1470 || id == 1471) {
        sk_caret = id;
        return 1;
    }
    if (id >= 1959 && id <= 1974) {     /* a group in the list */
        double sc;
        sk_group = id - 1959;
        sc = have_drawing ? drawing.group[sk_group].scale : 100.0;
        if (sc <= 0.0)
            sc = 1.0;
        strcpy(sk_num, "1");
        sprintf(sk_den, "%g", sc);
        return 1;
    }
    for (i = 0; i < n && i < (int)sizeof sk_on; i++) {
        if (ui_shakudo_id(i) != id)
            continue;
        if (id == 1704 || id == 1705) { /* 実寸固定 / 図寸固定: one of two */
            int k;
            for (k = 0; k < n && k < (int)sizeof sk_on; k++)
                if (ui_shakudo_id(k) == 1704 || ui_shakudo_id(k) == 1705)
                    sk_on[k] = (unsigned char)(ui_shakudo_id(k) == id);
        } else {
            sk_on[i] = (unsigned char)!sk_on[i];
        }
        return 1;
    }
    return 1;                           /* on the dialog, on nothing */
}

static int sk_key(int c)
{
    char *t = sk_caret == 1470 ? sk_num : sk_den;
    size_t n = strlen(t);

    if (c == 8) {
        if (n)
            t[n - 1] = 0;
        return 1;
    }
    if (c == 13) {
        sk_apply();
        sk_open = 0;
        return 1;
    }
    if (c == 9) {                       /* Tab moves between the two */
        sk_caret = sk_caret == 1470 ? 1471 : 1470;
        return 1;
    }
    if ((c >= '0' && c <= '9') || c == '.') {
        if (n + 1 < 16) {
            t[n] = (char)c;
            t[n + 1] = 0;
        }
        return 1;
    }
    return 0;
}

/* -------------------------------------------------------- レイヤ設定 -----
 * What the menu's レイヤ (32808) and the status line's third box (32829,
 * sent by FUN_00596e80) put up: the sixteen layers of the group being
 * written to.  Pressing one of the sixteen buttons does what pressing the
 * same layer on the grid beside the drawing does -- the left button walks
 * its state round, the right makes it the one being written to. */
static int ld_open;
static unsigned char ld_on[64];

/* 一括 (1141): the dialog's own state (+0xa8), 2 each time it is made */
static int ld_ikk = 2;
/* 戻す (2001): what 全レイヤ編集 / 全レイヤ非表示 kept (document +0x2424 and
   +0x1fa4) and whether there is anything (+0x17a0, which also enables the
   button the next time the dialog comes up) */
static int ld_back;
static int ld_back_g[16], ld_back_l[16][16];
/* the name box with the caret: 1838 the group's, 1839 the write layer's */
static int ld_caret;
static char ld_edit[256];
static int ld_drop;
/* 1524 and 1323 as OK left them (DAT_00a0c7dc, DAT_00a0ef58): OnInitDialog
   ticks them from there and OnOK (FUN_005610e0) puts them back */
static int ld_c7dc, ld_ef58;

int app_layerdlg_open(void)
{
    return ld_open;
}

/* a new drawing: nothing to take back, and not turned inside out */
static void ly_reset(void)
{
    ly_inv = 0;
    ld_back = 0;
}

static void ld_start(void)
{
    int i, n = ui_layerdlg_n();

    for (i = 0; i < n && i < (int)sizeof ld_on; i++) {
        ld_on[i] = (unsigned char)ui_layerdlg_on(i);
        if (ui_layerdlg_id(i) == 1524)
            ld_on[i] = (unsigned char)ld_c7dc;
        if (ui_layerdlg_id(i) == 1323)
            ld_on[i] = (unsigned char)ld_ef58;
    }
    ld_ikk = 2;
    ld_caret = 0;
    ld_open = 1;
}

/* OK, or Enter: the two checks are kept, and 1323 is the status line's */
static void ld_ok(void)
{
    int i, n = ui_layerdlg_n();

    for (i = 0; i < n && i < (int)sizeof ld_on; i++) {
        if (ui_layerdlg_id(i) == 1524)
            ld_c7dc = ld_on[i] != 0;
        if (ui_layerdlg_id(i) == 1323)
            ld_ef58 = ld_on[i] != 0;
    }
    ui_status_grpname(ld_ef58);
    ld_caret = 0;
    ld_open = 0;
}

static int press_layerdlg(int x, int y, int button)
{
    int id = ui_layerdlg_hit(fb.w, fb.h, x, y), i, n = ui_layerdlg_n();
    int lay;

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1838 || id == 1839) {
        /* the name boxes (CBS_SIMPLE, each with its Edit 1001): the caret
           goes in, with the name as it is */
        const char *t = "";
        if (have_drawing) {
            jw_group *gr = &drawing.group[ly_wg()];
            t = jw_str(&drawing, id == 1838 ? gr->name
                                            : gr->layer_name[gr->write_layer & 15]);
        }
        ld_caret = id;
        ld_drop = 0;
        strncpy(ld_edit, t, sizeof ld_edit - 1);
        ld_edit[sizeof ld_edit - 1] = 0;
        return 1;
    }
    if (id != 0)
        ld_caret = 0;                   /* a press on another control takes the focus */
    if (id == 1) {                      /* OK */
        ld_ok();
        return 1;
    }
    if (id == 2001) {
        /* 戻す (FUN_00560eb0): the states 全レイヤ編集 / 全レイヤ非表示 kept
         * come back, a 3 among them as 2, the write group and each group's
         * write layer as 3; a group or layer protected with 2 is left as it
         * is.  Read off the decompilation, not pressed. */
        int g, k, wg;
        if (!have_drawing || !ld_back)
            return 1;                   /* greyed (WS_DISABLED) */
        wg = ly_wg();
        for (g = 0; g < 16; g++) {
            jw_group *gr = &drawing.group[g];
            if (gr->c == 2)
                continue;
            gr->state = g == wg ? 3 : ld_back_g[g] == 3 ? 2 : ld_back_g[g];
            for (k = 0; k < 16; k++) {
                jw_layer *ly = &gr->layer[k];
                if (ly->state2 == 2)
                    continue;
                ly->state = k == (gr->write_layer & 15) ? 3
                          : ld_back_l[g][k] == 3 ? 2 : ld_back_l[g][k];
            }
        }
        ld_back = 0;
        return 1;
    }
    if (id == 1141) {
        /* 一括 (FUN_005619c0, a CMy3Button sending 0x1403): left steps the
         * dialog's state 2 -> 0 -> 1 -> 2, right makes it 2, and every
         * layer that is not the write one and not protected with 2 is put
         * at it -- all at the same state, not each a step on.  Nothing when
         * the group is protected.  Three presses from all 編集可 are what the
         * original left in decomp/res/lay_ikk*.jww.  Read off the
         * decompilation, not pressed. */
        jw_group *gr;
        int k;
        if (!have_drawing)
            return 1;
        gr = &drawing.group[ly_wg()];
        if (gr->c != 0)
            return 1;
        ld_ikk = button != 0 ? 2 : ld_ikk == 2 ? 0 : ld_ikk == 0 ? 1 : 2;
        for (k = 0; k < 16; k++)
            if (gr->layer[k].state2 != 2 && gr->layer[k].state != 3)
                gr->layer[k].state = ld_ikk;
        return 1;
    }
    if (id == 2000 || id == 1073) {
        /* 全レイヤ編集 (FUN_00561dc0) and 全レイヤ非表示 (FUN_00561b50), as
         * the original left the file after pressing each of them: every
         * group but the write one, and every layer of every group, goes to
         * 編集可能 -- or out altogether.  What was there is kept for 戻す.
         * The write group and each group's write layer are 3.  A group
         * protected with 2 keeps its state, a protected group (1 or 2)
         * keeps all its layers', a layer protected with 2 keeps its own.
         * (The original says 0x14a8 when it left any; the port has no
         * box for it.)
         *
         * 「[全レイヤ非表示]を[全レイヤ表示のみ] にする」 (1524): with it
         * ticked the original put everything at 表示のみ instead of out
         * altogether -- pressed with the box on, the file came back with
         * every layer and every group at 1 rather than 0 */
        int g, k, wg, out = 0;
        if (!have_drawing)
            return 1;
        for (i = 0; i < n && i < (int)sizeof ld_on; i++)
            if (ui_layerdlg_id(i) == 1524 && ld_on[i])
                out = 1;
        wg = ly_wg();
        for (g = 0; g < 16; g++) {
            jw_group *gr = &drawing.group[g];
            ld_back_g[g] = gr->state;
            if (g == wg)
                gr->state = ld_back_g[g] = 3;
            else if (gr->c != 2)
                gr->state = id == 2000 ? 2 : out;
            for (k = 0; k < 16; k++) {
                jw_layer *ly = &gr->layer[k];
                ld_back_l[g][k] = ly->state;
                if (gr->c != 0 || ly->state2 == 2)
                    continue;
                if (k == (gr->write_layer & 15))
                    ly->state = ld_back_l[g][k] = 3;
                else
                    ly->state = id == 2000 ? 2 : out;
            }
        }
        ld_back = id == 2000 ? 1 : 2;
        return 1;
    }
    lay = ui_layerdlg_layer(id);
    if (lay >= 0) {
        /* the same as pressing that layer on the grid beside the drawing:
           the left button walks its state round, the right makes it the one
           being written to -- not when the group is protected
           (FUN_00561750) */
        if (button != 0 && have_drawing && drawing.group[ly_wg()].c != 0)
            return 1;
        return press_layer_in(0, lay, button, 0);
    }
    for (i = 0; i < n && i < (int)sizeof ld_on; i++)
        if (ui_layerdlg_id(i) == id) {
            ld_on[i] = (unsigned char)!ld_on[i];
            return 1;
        }
    return 1;                           /* on the dialog, on nothing */
}

static int sd_open;
static unsigned char sd_on[128];
/* what OK left ticked, kept for the next time it is opened (キャンセル drops the changes) */
static unsigned char sd_saved[128];
static int sd_have_saved;

int app_sunpodlg_open(void)
{
    return sd_open;
}

/* 寸法設定's boxes: which one has the caret, and what has been typed
   into it.  The value itself lives in the command (jw_cmd_sunpo_box);
   this is only the line being edited, and it goes back on Enter or when
   the caret moves away. */
static int sd_caret;
static char sd_edit[32];

/* チェックボックスとラジオの値は命令（jw_cmd_sunpo_chk）が持つ。OK で
   点き具合を渡し、開くときはそこから読む（バーの 小数桁 が 桁 を変える
   ので）。繋いでいない id は窓の中の sd_on だけ */
static void sd_apply(const unsigned char *on)
{
    int i, n = ui_sunpodlg_n();

    for (i = 0; i < n && i < (int)sizeof sd_on; i++)
        if (jw_cmd_sunpo_chk(ui_sunpodlg_id(i)) >= 0)
            jw_cmd_sunpo_chk_set(ui_sunpodlg_id(i), on[i]);
}

static void sd_start(void)
{
    int i, n = ui_sunpodlg_n(), v;

    for (i = 0; i < n && i < (int)sizeof sd_on; i++) {
        sd_on[i] = (unsigned char)(sd_have_saved ? sd_saved[i] : ui_sunpodlg_on(i));
        v = jw_cmd_sunpo_chk(ui_sunpodlg_id(i));
        if (v >= 0)
            sd_on[i] = (unsigned char)v;
    }
    sd_open = 1;
    sd_caret = 0;                       /* nothing is being typed yet */
    sd_edit[0] = 0;
}

static void sd_commit(void)
{
    if (sd_caret) {
        jw_cmd_sunpo_box_set(sd_caret, sd_edit);
        sd_caret = 0;
        sd_edit[0] = 0;
    }
}

/* a digit, a dot, a minus or a backspace into the box with the caret */
static int sd_key(int c)
{
    size_t n;

    if (!sd_caret)
        return 0;
    if (c == 13) {                      /* Enter: take it */
        sd_commit();
        return 1;
    }
    n = strlen(sd_edit);
    if (c == 8) {
        if (n)
            sd_edit[n - 1] = 0;
        return 1;
    }
    if ((c >= '0' && c <= '9') || c == '.' || c == '-') {
        if (n + 1 < sizeof sd_edit) {
            sd_edit[n] = (char)c;
            sd_edit[n + 1] = 0;
        }
        return 1;
    }
    return 0;
}

static int press_sunpodlg(int x, int y)
{
    int id = ui_sunpodlg_hit(fb.w, fb.h, x, y), i, n = ui_sunpodlg_n();
    char t[32];

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* OK: what was typed is taken */
        sd_commit();
        memcpy(sd_saved, sd_on, sizeof sd_saved);
        sd_have_saved = 1;
        sd_apply(sd_on);
        sd_open = 0;
        return 1;
    }
    if (id == 2) {                      /* 見出しの ×: typing is dropped */
        sd_caret = 0;
        sd_edit[0] = 0;
        sd_open = 0;
        return 1;
    }
    /* a box that is wired up takes the caret, and what was in the one
       before it is taken */
    if (jw_cmd_sunpo_box(id, t, (int)sizeof t)) {
        sd_commit();
        sd_caret = id;
        sd_edit[0] = 0;
        return 1;
    }
    sd_commit();
    if (jw_cmd_sunpo_radio_group(id)) {
        /* ラジオ（BS_AUTORADIOBUTTON）: 押したものだけが点き、同じ組の
           ほかは消える */
        int g = jw_cmd_sunpo_radio_group(id);

        for (i = 0; i < n && i < (int)sizeof sd_on; i++)
            if (jw_cmd_sunpo_radio_group(ui_sunpodlg_id(i)) == g)
                sd_on[i] = (unsigned char)(ui_sunpodlg_id(i) == id);
        return 1;
    }
    if (id == 1323)                     /* 押せない（WS_DISABLED） */
        return 1;
    for (i = 0; i < n && i < (int)sizeof sd_on; i++)
        if (ui_sunpodlg_id(i) == id)
            sd_on[i] = (unsigned char)!sd_on[i];
    return 1;
}

/* 画面倍率・文字表示 (32811) と 前倍率 の控え。
 *
 * 原典は画面を doc の 倍率 +0x1728（用紙全体表示 が 1）と 画面の真ん中に
 * 来る用紙の点 +0x7a18 で持つ（CGamenBairitsuDialog の OnInitDialog
 * FUN_004c6530 は 倍率 が 1、点が (0,0) なら 表示範囲記憶・記憶解除 を殺す）。
 * 移植の view は ミリ毎画素 と 留めた点 (ox, oy) なので、行き来は vw_get /
 * vw_set（倍率 = 用紙全体の ミリ毎画素 / いまの ミリ毎画素）。控えは三つ:
 *   前倍率      +0x7a38・+0x7a28  OK と両ボタンドラッグの 範囲拡大・縮小・全体
 *                                 が変える前の画面を置く（CZoom の後始末）
 *   表示範囲記憶 +0x7a68・+0x7a58  全体 の行き先。記憶解除 で 1・(0,0) に
 *   マークジャンプ +0x7a70+n*8・+0x7ac0+n*16・+0x7b60+n*4（グループ、-1 は無し）
 * どれも逆コンパイルの読み、原典では押していない。原典はこれらを .jww の
 * 頭にも書く（版 200 から）が、移植は読まずに開くたび初めに戻す（残し）。 */
typedef struct { double z, x, y; } vw_t;
static const vw_t VW_ONE = { 1.0, 0.0, 0.0 };
static vw_t vw_prev = { 1.0, 0.0, 0.0 };
static vw_t vw_mem = { 1.0, 0.0, 0.0 };
static vw_t vw_mark[4] = { { 1.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0 },
                           { 1.0, 0.0, 0.0 }, { 1.0, 0.0, 0.0 } };
static int vw_mark_g[4] = { -1, -1, -1, -1 };

static int br_open;
static unsigned char br_on[64];
static unsigned char br_en[64];      /* 押せるか（OnInitDialog が決める） */
static char br_zoom[32];
static int br_sel;                   /* 箱の字が選ばれている（打てば替わる） */
/* 指定倍率 (+0x178)。作り手 FUN_004c5c20 が 2、窓は view と一緒に生きる
   ので次に開いても残る */
static double br_val = 2.0;
static int br_lgroup;   /* レイヤグループ同時登録 (1327) DAT_00a0d8d0 */
static int br_textframe; /* 【文字枠】を表示する (2104) DAT_00a0c794 */
static int br_textspace; /* 文字のスペースを表示する (2103) DAT_00a0c790 */

static double vw_fit_mmpp(void)
{
    jw_view t;
    rect_t r;

    ui_view_rect(fb.w, fb.h, &r);
    jw_view_fit(&t, &r, have_drawing ? drawing.paper_hw : 297.0,
                have_drawing ? drawing.paper_hh : 210.0);
    return t.mmpp;
}

static vw_t vw_get(void)
{
    vw_t c;

    c.z = view_ready && view.mmpp > 0.0 ? vw_fit_mmpp() / view.mmpp : 1.0;
    c.x = view_ready ? view.ox - jw_fit_dx : 0.0;
    c.y = view_ready ? view.oy - jw_fit_dy : 0.0;
    return c;
}

/* 倍率 1・点 (0,0) は app_fit とちょうど同じ画面になる */
static void vw_set(vw_t c)
{
    double m;

    if (!fb.px)
        return;
    app_fit();
    if (!(c.z > 0.0))
        return;
    m = view.mmpp / c.z;
    if (!(m > 1e-300 && m < 1e300))
        return;
    if (c.z != 1.0) {
        view.mmpp = m;
        view.scale = 1.0 / m;
    }
    view.ox = c.x + jw_fit_dx;
    view.oy = c.y + jw_fit_dy;
}

static void vw_reset(void)
{
    int k;

    vw_prev = vw_mem = VW_ONE;
    for (k = 0; k < 4; k++) {
        vw_mark[k] = VW_ONE;
        vw_mark_g[k] = -1;
    }
}

/* 前倍率 を置いてから行く（CGamenBairitsuDialog の OnOK、CZoom の 1・2・4） */
static void vw_go(vw_t c)
{
    vw_prev = vw_get();
    vw_set(c);
}

/* 両ボタンドラッグの 範囲拡大 (CZoom の 1): 囲んだ画素の箱が窓いっぱいに
   なるよう倍率を掛け（縦横の小さいほう、幅 0 は 1 に）、箱の真ん中を
   真ん中へ。倍率 100000 を超えれば 100000 に */
void app_zoom_rect(int x0, int y0, int x1, int y1)
{
    vw_t c;
    rect_t r;
    double k, ky;
    int w = x1 - x0, h = y1 - y0;

    if (!view_ready)
        return;
    ui_view_rect(fb.w, fb.h, &r);
    if (w == 0)
        w = 1;
    if (h == 0)
        h = 1;
    k = (double)r.w / w;
    ky = (double)r.h / h;
    if (ky < k)
        k = ky;
    if (k < 0)
        k = -k;
    c = vw_get();
    to_paper((x0 + x1) / 2, (y0 + y1) / 2, &c.x, &c.y);
    c.x -= jw_fit_dx;
    c.y -= jw_fit_dy;
    c.z *= k;
    /* 倍率の表示（view.scale × JW_SCREEN_MM_PER_PX）で 100000 まで */
    if (c.z * JW_SCREEN_MM_PER_PX / vw_fit_mmpp() > 100000.0)
        c.z = 100000.0 * vw_fit_mmpp() / JW_SCREEN_MM_PER_PX;
    vw_go(c);
}

/* 縮小 (CZoom の 2): 押した点を真ん中に、倍率を半分に。0.5 より下へは
   行かない */
void app_zoom_out(int sx, int sy)
{
    vw_t c;

    if (!view_ready)
        return;
    c = vw_get();
    to_paper(sx, sy, &c.x, &c.y);
    c.x -= jw_fit_dx;
    c.y -= jw_fit_dy;
    c.z *= 0.5;
    if (c.z < 0.5)
        c.z = 0.5;
    vw_go(c);
}

/* 前倍率 (CZoom の 3): いまの画面と控えを入れ替える。二度で戻る */
void app_zoom_prev(void)
{
    vw_t c;

    if (!view_ready)
        return;
    c = vw_get();
    vw_set(vw_prev);
    vw_prev = c;
}

/* 全体 (CZoom の 4): 表示範囲記憶 があればそこへ（記憶解除 のあとは
   用紙全体）。paper が 0 でなければ記憶によらず用紙全体（CZoom の +0x24） */
void app_zoom_all(int paper)
{
    if (!view_ready)
        return;
    vw_go(paper ? VW_ONE : vw_mem);
}

/* 両ボタンドラッグの判定と枠（CZoom の作りから後始末まで）。中身は src/ryoboton.h */
#define JW_RYOBOTON_IMPL
#include "ryoboton.h"

int app_coord_save(unsigned char **out, long *n)
{
    double x, y;

    if (!have_drawing || !jw_cmd_block_point(&drawing, &x, &y))
        return 0;
    return jw_write_coord(&drawing, x, y, out, n);
}


/* 外部変形 (32913).  begin() reads a BAT's header and writes what goes in
   JWC_TEMP.TXT from what is picked; end() takes what the program left there.
   Running the program in between is the front end's job.  Returns 1, or 0 if
   the BAT is not one for Jw_cad (「JW外部変形用バッチファイルではありません」),
   or -1 if nothing is picked. */
static double gaibu_ox, gaibu_oy;
static jw_gaibu gaibu_info;

int app_gaibu_begin(const char *bat, long bn, unsigned char **out, long *n)
{
    double x0 = 1e300, y0 = 1e300, x1 = -1e300, y1 = -1e300;
    int i, k;

    if (!have_drawing || jw_cmd_sel_count(&drawing) <= 0)
        return -1;
    if (!jw_gaibu_header(bat, bn, &gaibu_info))
        return 0;
    if (!jw_cmd_gaibu_origin(&gaibu_ox, &gaibu_oy) && !jw_cmd_block_point(&drawing, &gaibu_ox, &gaibu_oy))
        return -1;
    for (i = 0; i < drawing.ndrawn; i++)
        if (drawing.obj[i].sel)
            for (k = 0; k < 4; k += 2) {
                double *q = drawing.obj[i].d;

                if (q[k] < x0) x0 = q[k];
                if (q[k] > x1) x1 = q[k];
                if (q[k + 1] < y0) y0 = q[k + 1];
                if (q[k + 1] > y1) y1 = q[k + 1];
            }
    return jw_gaibu_write(&drawing, &gaibu_info, gaibu_ox, gaibu_oy,
                          x0, y0, x1, y1, out, n) ? 1 : -1;
}

/* 外部変形 with its steps answered: the points (xy[i], for the steps that ask
   for one) go into the header as hp lines, and the typed values and chosen
   items become the argument string the BAT is started with. */
int app_gaibu_begin2(const char *bat, long bn, int item, const double (*xy)[2],
                     char val[][128], unsigned char **out, long *n,
                     char *args, int acap)
{
    jw_gscript *sc;
    unsigned char *t = 0, *o;
    long tn = 0, at, i;
    char pts[4096];
    int r, pl;

    r = app_gaibu_begin(bat, bn, &t, &tn);
    if (r != 1)
        return r;
    sc = (jw_gscript *)calloc(1, sizeof *sc);
    if (!sc) {
        free(t);
        return -1;
    }
    jw_gaibu_script(bat, bn, item, sc);
    pl = jw_gaibu_points(sc, xy, pts, (int)sizeof pts);
    jw_gaibu_args(sc, val, args, acap);
    free(sc);
    /* after the hn line */
    for (at = 0, i = 0; i + 3 < tn; i++)
        if (t[i] == '\n' && t[i + 1] == 'h' && t[i + 2] == 'n') {
            for (at = i + 1; at < tn && t[at] != '\n'; at++)
                ;
            at++;
            break;
        }
    o = (unsigned char *)malloc((size_t)(tn + pl + 1));
    if (!o) {
        free(t);
        return -1;
    }
    memcpy(o, t, (size_t)at);
    memcpy(o + at, pts, (size_t)pl);
    memcpy(o + at + pl, t + at, (size_t)(tn - at));
    free(t);
    *out = o;
    *n = tn + pl;
    return 1;
}

int app_gaibu_end(const unsigned char *b, long n, char *msg, int cap)
{
    jw_gaibu_out o;
    int r;

    if (msg && cap > 0)
        msg[0] = 0;
    if (!have_drawing)
        return -1;
    r = jw_cmd_gaibu_commit(&drawing, b, n, gaibu_ox, gaibu_oy, &o);
    if (msg && cap > 0)
        snprintf(msg, (size_t)cap, "%s", o.msg[0] ? o.msg : o.note);
    return r;
}

/* 文字の 範囲選択: the files 文書 and 外部エディタ trade in (src/cmd.c) */
int app_moji_doc(unsigned char **out, long *n)
{
    return have_drawing && jw_cmd_moji_doc(&drawing, out, n);
}

int app_moji_edit_text(unsigned char **out, long *n)
{
    return have_drawing && jw_cmd_moji_edit_text(&drawing, out, n);
}

int app_moji_apply(const unsigned char *b, long n)
{
    return have_drawing && jw_cmd_moji_apply(&drawing, b, n) > 0;
}

/* 外部変形 with its steps (src/cmd.c): the BAT picked, then every step answered */
int app_gaibu_load(const char *bat, long n)
{
    return have_drawing && jw_cmd_gaibu_load(&drawing, bat, n);
}

int app_gaibu_run_begin(unsigned char **out, long *n, char *args, int acap)
{
    const char *bat;
    long bn;
    int item;
    const double (*xy)[2];
    char (*val)[128];

    int *num, r;
    char *kind;

    if (!have_drawing || !jw_cmd_gaibu_session(&bat, &bn, &item, &xy, &val))
        return -1;
    num = (int *)malloc((size_t)(drawing.ndrawn + 1) * sizeof *num);
    kind = (char *)malloc((size_t)drawing.ndrawn + 1);
    if (num && kind && jw_cmd_gaibu_tags(&drawing, num, kind, drawing.ndrawn))
        jw_coord_tags(num, kind, drawing.ndrawn);
    r = app_gaibu_begin2(bat, bn, item, xy, val, out, n, args, acap);
    jw_coord_tags(0, 0, 0);
    free(num);
    free(kind);
    return r;
}

void app_gaibu_run_end(void)
{
    jw_cmd_gaibu_done();
}

/* what a press or key may have left for the front end */
static void gaibu_after(void)
{
    if (jw_cmd_gaibu_ready())
        action = JW_ACT_GAIBU_RUN;
    else if (jw_cmd_gaibu_want_bat())
        action = JW_ACT_GAIBU;
}

/* The tool tip of the toolbar button under (x, y), in UTF-8: the original's own
   status text for its command (src/gen/tips.h).  Nought when there is none. */
const char *app_tip(int x, int y)
{
    int k = hit_button(x, y), i;

    if (k < 0 || k >= JW_NBUTTONS)
        return 0;
    for (i = 0; i < JW_NTIPS; i++)
        if (jw_tips[i].id == jw_btn_cmd[k])
            return jw_tips[i].text;
    return 0;
}
/* 図形登録's 基準点, kept from the press that gave it. */
static double fig_bx, fig_by;

int app_figure_save(unsigned char **out, long *n)
{
    if (!have_drawing)
        return 0;
    return jw_cmd_figure_save(&drawing, fig_bx, fig_by, out, n);
}

/* 座標ファイル: the text, which the original reads as a 図形. */
int app_coord(const unsigned char *b, long n)
{
    if (!have_drawing)
        return 0;
    return jw_cmd_coord_load(&drawing, b, n);
}

/* 画像挿入: the file the front end picked, under the name that goes into the
   drawing (its path, or what the browser calls it) */
int app_image(const char *path, const unsigned char *b, long n)
{
    if (!have_drawing)
        return 0;
    return jw_cmd_gazou_insert(&drawing, path, b, n);
}

/* 同梱画像分離's files, for the front end to put in the folder */
int app_image_out(int i, const char **name, const unsigned char **b, long *n)
{
    return jw_cmd_gazou_out(i, name, b, n);
}

/* the folder the drawing is in (CP932, "" when it has none): 相対パス and the
   folder 同梱画像分離 makes are measured from it */
static char doc_dir[260];

void app_doc_dir(const char *dir)
{
    strncpy(doc_dir, dir ? dir : "", sizeof doc_dir - 1);
    doc_dir[sizeof doc_dir - 1] = 0;
}

void app_doc(const char *dir, const char *stem)
{
    app_doc_dir(dir);
    jw_cmd_gazou_doc(doc_dir, stem);
}

/* 図形読込 (32862): the bytes of a .jws, in place of the original's own
   file window.  The figure then hangs on the cursor until a point is
   clicked. */
int app_figure(const unsigned char *b, long n)
{
    if (!have_drawing)
        return 0;
    return jw_cmd_figure_load(&drawing, b, n);
}

int app_text(const unsigned char *b, long n)
{
    if (!have_drawing)
        return 0;
    return jw_cmd_text_load(&drawing, b, n);
}

int app_bairitsu_open(void)
{
    return br_open;
}

static int br_idx(int id)
{
    int i, n = ui_bairitsu_n();

    for (i = 0; i < n && i < (int)sizeof br_on; i++)
        if (ui_bairitsu_id(i) == id)
            return i;
    return -1;
}

static void br_set(unsigned char *a, int id, int v)
{
    int i = br_idx(id);

    if (i >= 0)
        a[i] = (unsigned char)(v != 0);
}

static int br_get(const unsigned char *a, int id)
{
    int i = br_idx(id);

    return i >= 0 && a[i];
}

/* 登録されているか: 倍率が 1 でないか、点が (0,0) でないか、グループを
   持つか（OnInitDialog の 1323〜1326 の印） */
static int br_marked(int k)
{
    return vw_mark[k].z != 1.0 || vw_mark[k].x != 0.0 || vw_mark[k].y != 0.0
           || vw_mark_g[k] >= 0;
}

/* OnInitDialog (FUN_004c6530) */
static void br_start(void)
{
    int i, k, n = ui_bairitsu_n();
    vw_t c = vw_get();

    for (i = 0; i < n && i < (int)sizeof br_on; i++) {
        br_on[i] = (unsigned char)ui_bairitsu_on(i);
        br_en[i] = 1;
    }
    /* 目盛 表示最小倍率 は 目盛 が無ければ死ぬ（doc+0x7984 == 0）。
       表示範囲記憶・記憶解除 は 倍率 1・点 (0,0) のとき死ぬ */
    br_set(br_en, 1090, have_drawing && drawing.mesh_mode != 0);
    k = !(fabs(c.z - 1.0) <= 1e-7 && fabs(c.x) <= 1e-7 && fabs(c.y) <= 1e-7);
    br_set(br_en, 1068, k);
    br_set(br_en, 1069, k);
    for (k = 0; k < 4; k++)
        br_set(br_on, 1323 + k, br_marked(k));
    br_set(br_on, 1327, br_lgroup);
    br_set(br_on, 2104, br_textframe);
    br_set(br_on, 2103, br_textspace);
    /* DDX_Text の double は %.15g、開いた時は箱の字が選ばれている
       （docs/ref_bairitsu.png の「2」） */
    snprintf(br_zoom, sizeof br_zoom, "%.15g", br_val);
    br_sel = 1;
    br_open = 1;
}

/* 書込みグループを替える（OnOK の +0xb8 の枝: 前は 2、新しいのは 3） */
static void br_group(int g)
{
    int wg = sk_write_group();

    if (!have_drawing || g < 0 || g > 15)
        return;
    drawing.group[wg].state = 2;
    drawing.group[g].state = 3;
}

/* マークジャンプ・用紙全体表示 が OnOK に渡すグループ (+0xf0)。作り手が
   -1、マークジャンプ が書き、用紙全体表示 は書かない —— 同じ窓で前に
   マークジャンプ した後の 用紙全体表示 もそのグループへ替える（読みのまま） */
static int br_jump_g = -1;

/* OnOK (FUN_004c6a90)。kind: 1 指定倍率表示、1089 倍率＝1.0、
   1090 目盛表示最小倍率、1091 用紙全体表示、1064〜1067 マークジャンプ */
static void br_ok(int kind)
{
    vw_t c = vw_get();
    double fit = vw_fit_mmpp(), v;
    char *end;

    /* UpdateData: 数として読めれば箱の値に（DDV の 0.01〜100000 を外れても
       値は入り、倍率は変わらない） */
    v = strtod(br_zoom, &end);
    if (end != br_zoom && *end == 0)
        br_val = v;
    vw_prev = c;
    if (kind == 1089) {
        /* 倍率の表示 1.0: doc[6000] / (doc[0x1778] / |doc[0x1780]|) */
        c.z = fit / JW_SCREEN_MM_PER_PX;
        vw_set(c);
    } else if (kind == 1090) {
        if (have_drawing && drawing.mesh_mode != 0) {
            double s = drawing.mesh_ix < drawing.mesh_iy ? drawing.mesh_ix
                                                         : drawing.mesh_iy;

            s /= drawing.mesh_mode;
            if (s > 1e-6 && drawing.mesh_min > 0.0) {
                c.z = drawing.mesh_min * fit / s + 0.001;
                vw_set(c);
            }
        }
    } else if (kind == 1091 || (kind >= 1064 && kind <= 1067)) {
        if (kind == 1091) {
            vw_set(VW_ONE);
        } else {
            vw_set(vw_mark[kind - 1064]);
            br_jump_g = vw_mark_g[kind - 1064];
        }
        br_group(br_jump_g);
    } else if (br_val >= 0.01 && br_val <= 100000.0) {
        c.z = br_val * fit / JW_SCREEN_MM_PER_PX;
        vw_set(c);
    }
    br_lgroup = br_get(br_on, 1327);
    br_open = 0;
}

static int press_bairitsu(int x, int y)
{
    int id = ui_bairitsu_hit(fb.w, fb.h, x, y, br_en), i;

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1 || id == 1089 || id == 1090 || id == 1091
        || (id >= 1064 && id <= 1067)) {
        br_ok(id);
        return 1;
    }
    if (id == 1068) {                   /* 表示範囲記憶 (FUN_004c72b0) */
        vw_mem = vw_get();
        br_open = 0;
        return 1;
    }
    if (id == 1069) {                   /* 記憶解除 (FUN_004c7350) */
        vw_mem = VW_ONE;
        br_open = 0;
        return 1;
    }
    if (id == 1933) {                   /* 設定 OK (FUN_004c73f0) */
        br_textframe = br_get(br_on, 2104);
        br_textspace = br_get(br_on, 2103);
        jw_pick_pic_text = br_textspace;    /* 画像の拾い（pick.c の dist_moji） */
        br_open = 0;
        return 1;
    }
    if (id == 2) {                      /* 見出しの ×: OnCancel、何も変えない */
        br_open = 0;
        return 1;
    }
    if (id == 1470) {                   /* 箱を押すと選びが外れる */
        br_sel = 0;
        return 1;
    }
    i = br_idx(id);
    if (i < 0)
        return 1;
    br_on[i] = (unsigned char)!br_on[i];
    if (id >= 1323 && id <= 1326) {     /* 登録 (FUN_004c7480) */
        int k = id - 1323;

        vw_mark_g[k] = -1;
        if (br_on[i]) {
            vw_mark[k] = vw_get();
            if (br_lgroup)
                vw_mark_g[k] = sk_write_group();
        } else {
            vw_mark[k] = VW_ONE;
        }
    } else if (id == 1327) {            /* FUN_004c64f0: すぐ効く */
        br_lgroup = br_on[i];
    }
    return 1;
}

/* 指定倍率 の箱 (1470)。選ばれていれば打った字で置き換わる */
static int br_key(int c)
{
    size_t n;

    if (c == 8) {
        if (br_sel)
            br_zoom[0] = 0;
        n = strlen(br_zoom);
        if (n)
            br_zoom[n - 1] = 0;
        br_sel = 0;
        return 1;
    }
    if ((c >= '0' && c <= '9') || c == '.' || c == '-') {
        if (br_sel)
            br_zoom[0] = 0;
        br_sel = 0;
        n = strlen(br_zoom);
        if (n + 1 < sizeof br_zoom) {
            br_zoom[n] = (char)c;
            br_zoom[n + 1] = 0;
        }
        return 1;
    }
    return 0;
}

/* 文字基点設定 -- the 文字 bar's 基点 (1064).  Only the
   nine radios do anything: what each of them does to a placed text was
   measured off the original (tools/probe62.sh), and nothing has been
   asked of the ずれ boxes or the three 作図 checkboxes. */
static int mk_open;
/* which of the six ずれ boxes is being typed into, or 0 */
static int mk_caret;
/* the box was just clicked: the first character typed replaces what is in it
   (the boxes now come up holding the original's -1 0 1, and typing after
   them would make -15) -- the bar's boxes do the same, see box_fresh */
static int mk_fresh;

int app_mojikijun_open(void)
{
    return mk_open;
}

static int press_mojikijun(int x, int y)
{
    int id = ui_mojikijun_hit(fb.w, fb.h, x, y);

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id >= 1689 && id <= 1697) {
        if (mk_open == 2)               /* 範囲選択の 文字位置･集計 の 基点 (1072) */
            jw_cmd_mp_base(id - 1689);
        else
            jw_cmd_moji_base(id - 1689);
        return 1;
    }
    if (id == 1323) {                   /* ずれ使用 */
        jw_cmd_moji_zure(!jw_cmd_moji_zure_now());
        return 1;
    }
    if (id == 1327 || id == 1328 || id == 1329) {
        jw_cmd_moji_rule(id, !jw_cmd_moji_rule_now(id));
        return 1;
    }
    if (id == 1 || id == 2) {           /* OK */
        mk_open = 0;
        mk_caret = 0;
        return 1;
    }
    /* the six ずれ boxes take the typing.  They are dead until
       ずれ使用 is on, which is how the original has them: driving its
       own dialog with the boxes before the tick was refused outright
       (tools/probe70.sh). */
    if (jw_cmd_moji_zure_box(id) && jw_cmd_moji_zure_now()) {
        mk_caret = id;
        mk_fresh = 1;
        return 1;
    }
    mk_caret = 0;
    return 1;
}

static int mk_key(int c)
{
    if (c == 13) {
        mk_caret = 0;
        return 1;
    }
    if (mk_fresh && c != 8 && mk_caret) {
        const char *t;
        int guard = 32;

        if (!((c >= '0' && c <= '9') || c == '.' || c == '-'))
            return 0;
        while ((t = jw_cmd_moji_zure_box(mk_caret)) && *t && guard-- > 0)
            jw_cmd_moji_zure_key(mk_caret, 8);
    }
    mk_fresh = 0;
    return jw_cmd_moji_zure_key(mk_caret, c);
}

/* ------------------------------------------------ 色の設定 ----------
 *
 * 基本設定 (32891) の 色・画面 の 色１ などが出す窓です。原典では
 * Windows の共通ダイアログ（ChooseColor、CC_FULLOPEN）で、移植は
 * `src/gen/colordlg.h` に写した原典の窓をそのまま描きます。
 *
 * どの釦がどのペンかは、原典のその窓を一つずつ開かせて、出てきた
 * 「いまの色」で確かめたものです（tools/probe148.sh）。
 */
static int cd_open;
/* 書き戻す先。1..9 は画面ペン、13・15・16 は 色・画面 の行（src/draw.c の
   jw_row_rgb）、CD_ROW_ANY は 矩形 の 任意色。-1 なら書きません。 */
#define CD_ROW_ANY (-2)
static int cd_row;
static jw_cd_state cd;
static char cd_edit[8];

int app_colordlg_open(void)
{
    return cd_open;
}

static void cd_sync_from_rgb(void)
{
    jw_rgb_to_hls(cd.rgb, &cd.h, &cd.l, &cd.s);
}

static void cd_sync_from_hls(void)
{
    cd.rgb = jw_hls_to_rgb(cd.h, cd.l, cd.s);
}

static void cd_start(int row, unsigned int rgb)
{
    int i;

    cd_row = row;
    cd.rgb = rgb;
    cd_sync_from_rgb();
    for (i = 0; i < 16; i++)
        cd.custom[i] = ui_colordlg_startup_custom(i);
    /* 原典の窓は、開いた途端に **基本色 の一つ目に点線の輪**（鍵盤の
       焦点）が付き、**いまの色と同じ升に黒い輪**が付きます
       （docs/ref_colordlg.png では 作成した色 の一つ目）。 */
    cd.focus = 720;
    cd.focus_cell = 0;
    cd.basic_sel = -1;
    cd.custom_sel = -1;
    for (i = 0; i < 48; i++)
        if (ui_colordlg_basic(i) == rgb) {
            cd.basic_sel = i;
            cd.focus_cell = i;          /* 焦点もそこへ移ります */
            break;
        }
    for (i = 0; i < 16; i++)
        if (cd.custom[i] == rgb) {
            cd.custom_sel = i;
            break;
        }
    cd.caret = 0;
    cd.edit = cd_edit;
    cd_edit[0] = 0;
    cd_open = 1;
}

static void cd_commit(void)
{
    if (!cd.caret)
        return;
    if (cd_edit[0]) {
        int v = atoi(cd_edit);

        if (v < 0)
            v = 0;
        switch (cd.caret) {
        case 703: cd.h = v > 239 ? 239 : v; cd_sync_from_hls(); break;
        case 704: cd.s = v > 240 ? 240 : v; cd_sync_from_hls(); break;
        case 705: cd.l = v > 240 ? 240 : v; cd_sync_from_hls(); break;
        case 706:
            cd.rgb = (cd.rgb & 0x00ffffu) | ((unsigned)(v > 255 ? 255 : v) << 16);
            cd_sync_from_rgb();
            break;
        case 707:
            cd.rgb = (cd.rgb & 0xff00ffu) | ((unsigned)(v > 255 ? 255 : v) << 8);
            cd_sync_from_rgb();
            break;
        case 708:
            cd.rgb = (cd.rgb & 0xffff00u) | (unsigned)(v > 255 ? 255 : v);
            cd_sync_from_rgb();
            break;
        }
        cd.basic_sel = cd.custom_sel = -1;
    }
    cd.caret = 0;
    cd_edit[0] = 0;
}

static int cd_key(int c)
{
    size_t n;

    if (!cd.caret)
        return 0;
    if (c == 13) {
        cd_commit();
        return 1;
    }
    n = strlen(cd_edit);
    if (c == 8) {
        if (n > 0)
            cd_edit[n - 1] = 0;
        return 1;
    }
    if (c >= '0' && c <= '9' && n + 1 < sizeof cd_edit) {
        cd_edit[n] = (char)c;
        cd_edit[n + 1] = 0;
        return 1;
    }
    return 0;
}

static int press_colordlg(int x, int y)
{
    int id = ui_colordlg_hit(fb.w, fb.h, x, y), k, h, sat, lum;

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* OK */
        cd_commit();
        /* 原典と同じく、OK のときだけ書き戻します */
        if (cd_row == CD_ROW_ANY) {
            jw_cmd_any_color_set(cd.rgb);
        } else if (cd_row >= 1 && cd_row <= 9) {
            if (have_drawing)
                drawing.pen_rgb[cd_row] = cd.rgb;
        } else if (cd_row == 13) {
            if (have_drawing)
                drawing.gray_rgb = cd.rgb;
            jw_row_rgb_set(13, cd.rgb);
        } else {
            jw_row_rgb_set(cd_row, cd.rgb);
        }
        cd_open = 0;
        return 1;
    }
    if (id == 2) {                      /* キャンセル と 見出しの × */
        cd.caret = 0;
        cd_edit[0] = 0;
        cd_open = 0;
        return 1;
    }
    cd_commit();
    switch (id) {
    case 720:                           /* 基本色 */
        k = ui_colordlg_cell(fb.w, fb.h, 720, x, y);
        if (k >= 0) {
            cd.basic_sel = k;
            cd.custom_sel = -1;
            cd.focus = 720;
            cd.focus_cell = k;
            cd.rgb = ui_colordlg_basic(k);
            cd_sync_from_rgb();
        }
        return 1;
    case 721:                           /* 作成した色 */
        k = ui_colordlg_cell(fb.w, fb.h, 721, x, y);
        if (k >= 0) {
            cd.custom_sel = k;
            cd.basic_sel = -1;
            cd.focus = 721;
            cd.focus_cell = k;
            cd.rgb = cd.custom[k];
            cd_sync_from_rgb();
        }
        return 1;
    case 710:                           /* 虹の升: 色相と彩度 */
        if (ui_colordlg_hs(fb.w, fb.h, x, y, &h, &sat)) {
            cd.h = h;
            cd.s = sat;
            cd_sync_from_hls();
            cd.basic_sel = cd.custom_sel = -1;
        }
        return 1;
    case 702:                           /* 明るさの帯 */
        if (ui_colordlg_lum(fb.w, fb.h, x, y, &lum)) {
            cd.l = lum;
            cd_sync_from_hls();
            cd.basic_sel = cd.custom_sel = -1;
        }
        return 1;
    case 712:                           /* 色の追加: 作成した色の次の枠へ */
        for (k = 0; k < 16; k++)
            if (cd.custom[k] == cd.rgb)
                break;
        if (k == 16) {
            for (k = 15; k > 0; k--)
                cd.custom[k] = cd.custom[k - 1];
            cd.custom[0] = cd.rgb;
            k = 0;
        }
        cd.custom_sel = k;
        cd.basic_sel = -1;
        return 1;
    case 703: case 704: case 705:
    case 706: case 707: case 708:
        cd.caret = id;
        cd_edit[0] = 0;
        return 1;
    default:
        return 1;                       /* 絵だけの部品。窓は modal */
    }
}

static int kh_open, kh_tab;
static int kh_colinit;                  /* 色彩の初期化 (1910) が 背景色の釦を押せるようにした */
static unsigned char kh_on[8][256];

int app_kihon_open(void)
{
    return kh_open;
}

/* What OK left in the boxes: the dialog comes up again as it was left, not as the
   original has it on entering.  Only the boxes whose meaning is known go any further
   (kh_apply). */
static unsigned char kh_saved[8][256];
static int kh_have_saved;

/* the state of the box with this id, as OK left it (or the original's default) */
static int kh_value(int id)
{
    int t, i;

    for (t = 0; t < ui_kihon_ntabs() && t < 8; t++)
        for (i = 0; i < ui_kihon_n(t) && i < 256; i++)
            if (ui_kihon_id(t, i) == id)
                return kh_have_saved ? kh_saved[t][i] : ui_kihon_on(t, i);
    return 0;
}

/* the same, but only on that tab (1325 and 2094 are on more than one) */
static int kh_value_tab(int tab, int id)
{
    int i;

    if (tab < 0 || tab >= ui_kihon_ntabs() || tab >= 8)
        return 0;
    for (i = 0; i < ui_kihon_n(tab) && i < 256; i++)
        if (ui_kihon_id(tab, i) == id && !ui_kihon_isbox(tab, i))
            return kh_have_saved ? kh_saved[tab][i] : ui_kihon_on(tab, i);
    return 0;
}

static int kh_arrows;                   /* 2362: 0 切、1 入、2 入で軸角方向移動 (1325) */
static int kh_cross;                    /* 2437: 0 切、1 いつも、2 範囲指定のみ、3 範囲始点のみ */
static int cross_have;                  /* マウスが図面の上にある（cross_x, cross_y に） */
static double cross_x, cross_y;
static double kh_move_rate = 0.5, kh_zoom_rate = 1.5;   /* 移動率 1951・拡大率 1952 */
static double kh_num(int tab, int id, double dflt);
#include "kihon3.h"                     /* 2527・2525・ホイール・1886・1900・1883 */

/* OK: the boxes whose meaning is read from the decompile or the dialog's words:
   画像･ソリッドを最初に描画 (2405) and 透過属性 (2860), see src/draw.c */
static void kh_apply_text(void);

static void kh_apply(void)
{
    kh_apply_text();
    jw_draw_images_first = kh_value(2405);
    jw_draw_transparent = kh_value(2860);
    jw_draw_reverse = kh_value(2444);
    jw_draw_texts_last = kh_value(1887);
    jw_cmd_layhide_shown(kh_value(2446));
    jw_cmd_get_shown_too(kh_value(1522));
    jw_pick_reverse = kh_value(2445);
    jw_cmd_get_arc_length(kh_value(2100));
    jw_moji_sjis_set(!kh_value(2112));
    jw_cmd_moji_point_first(kh_value(2466));
    /* 2532 用紙枠を表示する → DAT_00a0c78c（CSonotaPage の OK FUN_005cd940 が
       +0xbc0 から）。src/draw.c の jw_draw_frame と pick.c の jw_read */
    jw_draw_paper_frame = kh_value(2532);
    /* 一般(2) 2531 埋め込み文字を画面にも → DAT_00a0bc40（CSonotaPage1 の DDX
       0x5d0f72 が +0x59c、OK FUN_005d02e0 が in_ECX[0x167] から）。読み手は
       字の描き手 FUN_00481d50 の 0x485797。src/umekomi.c */
    jw_umekomi_screen = kh_value_tab(1, 2531);
    jw_draw_text_subst = jw_umekomi_screen ? jw_umekomi_screen_hook : 0;
    /* 2094 複線の Enter で連続複線 → DAT_00a0cb20（+0x718）。src/cmd.c */
    jw_cmd_fukusen_enter_on(kh_value_tab(0, 2094));
    /* 一般(2) 2362 矢印キーで画面移動… → DAT_00a0d864（CSonotaPage1 の OK
       FUN_005d02e0 が +0x6b4 から 1、隣の 1325 軸角方向移動 +0x740 も立てば 2）、
       移動率 1951 → DAT_00a0d868、拡大率 1952 → DAT_00a0d870（どちらも箱の数を
       そのまま）。app_arrow_key */
    kh_arrows = kh_value_tab(1, 2362) ? (kh_value_tab(1, 1325) ? 2 : 1) : 0;
    kh_move_rate = kh_num(1, 1951, 0.5);
    kh_zoom_rate = kh_num(1, 1952, 1.5);
    /* 1950「[移動］の両ボタンドラッグ範囲」→ DAT_00a0d8c8（FUN_005d02e0 が (int) に）。
       src/ryoboton.h */
    ryo_set_slop((int)kh_num(1, 1950, 10.0));
    /* 2437 クロスラインカーソルを使う・2438 範囲指定のみ・2439 範囲始点のみ →
       doc+6000（FUN_005cd940: 2437 が切なら 0、2438 なら 2、2439 なら 3、どちらも
       切なら 1）。app_paint の cross_paint */
    kh_cross = !kh_value_tab(0, 2437) ? 0 : kh_value_tab(0, 2438) ? 2
               : kh_value_tab(0, 2439) ? 3 : 1;
    kh3_apply();                        /* src/kihon3.h */
}

/* 基本設定 の箱の字。原典の既定は src/gen/kihonval.h（tools/mkkihonval.py が
 * レジストリの控え tools/refenv.reg から、無いものは写し docs/ref_kihon*.png
 * から作る）。OK で残り、次に開くとその字で出る（キャンセル は捨てる）。
 *
 * **図面の持ち物は図面から読んで OK で図面へ書く**（kh_live）: 色・画面 の
 * 画面の線色 1〜8・補助線色（ペン 9）の 赤 緑 青 と線幅、グレー（gray_rgb）、
 * 選択色・仮表示色（jw_row_rgb の 15・16）、背景色（ペン 0）、プリンタ出力の
 * 線色 1〜8 と線幅・グレー（print_rgb 9）。文字 の 文字種 1〜10 の 横 縦
 * 間隔 色No.（style[]）。どれも描く・置く ときにそのまま使われる値。
 *
 * **箱の字を移植の働きが読むもの**（kh_apply_text、OK と prefs の読み込みの
 * あと）: 線種 の 線種 2〜9 のパターン・単位・画面のピッチ（src/draw.c の
 * LTYPE へ）、一般(1) の Undo の回数（src/cmd.c の 戻る の段数の上限）、
 * オートセーブ時間・バックアップ数（表側が app_autosave_minutes・
 * app_backup_gens で読む）。
 *
 * それ以外（外部エディタ、画面横寸法、ランダム線・倍長線種、プリンタの
 * 線種ピッチ、AUTO のクロックメニュー、KEY の割り当て、SXF の
 * 許容差 など）は**表示と保存だけ**: 移植のその働き（ランダム線・倍長線種は
 * 実線で描く、キーは app の固定の割り当て、外部エディタは無い）がまだ設定を
 * 読まないため。 */
#include "gen/kihonval.h"
#define KH_TXT 48
static char kh_txt[8][256][KH_TXT];
static char kh_txt_saved[8][256][KH_TXT];
/* what the drawing's boxes held when the dialog came up (or last followed the
   drawing): a box not typed into since follows the drawing -- 色の設定 opened
   from 色・画面 changes a pen under it -- and OK writes only the typed ones */
static char kh_txt_init[8][256][KH_TXT];
static int kh_txt_have;
/* the box being typed into (tab and index), or -1; and whether nothing has
   been typed since it was clicked, so the first key replaces what is there */
static int kh_ctab = -1, kh_ci = -1, kh_cfresh;
static unsigned int kihon_row_rgb(int row);

static const jw_khv_t *kh_val(int tab, int i)
{
    int id = ui_kihon_id(tab, i), nth = 0, k;

    for (k = 0; k < i; k++)
        if (ui_kihon_id(tab, k) == id && ui_kihon_isbox(tab, k))
            nth++;
    for (k = 0; k < JW_NKIHONVAL; k++)
        if (jw_kihonval[k].tab == tab && jw_kihonval[k].id == id
            && jw_kihonval[k].nth == nth)
            return &jw_kihonval[k];
    return 0;
}

/* 色・画面 の箱が図面のどの色のどの成分か。row は 1..9 画面ペン、0 背景色、
   13 グレー、15 選択色、16 仮表示色、101..108 プリンタのペン、109 その
   グレー。comp は 0 赤 1 緑 2 青 3 線幅。行と釦の対応は kihon_row の注 */
static int kh_pen_box(int id, int *row, int *comp)
{
    static const short scr_r[8] = { 1571, 1575, 1576, 1577, 1578, 1579, 1580, 1581 };
    int k;

    for (k = 0; k < 8; k++) {
        if (id == scr_r[k]) {
            *row = k + 1;
            *comp = 0;
            return 1;
        }
    }
    if (id >= 1572 && id <= 1574) {
        *row = 1;
        *comp = id - 1571;
        return 1;
    }
    if (id >= 1583 && id <= 1603) {             /* 線色 2..8 の 緑 青 線幅 */
        *row = 2 + (id - 1583) / 3;
        *comp = 1 + (id - 1583) % 3;
        return 1;
    }
    switch (id) {
    case 1645: *row = 13; *comp = 0; return 1;  /* グレー */
    case 1646: *row = 13; *comp = 1; return 1;
    case 1647: *row = 13; *comp = 2; return 1;
    case 1582: *row = 9; *comp = 0; return 1;   /* 補助線色 */
    case 1604: *row = 9; *comp = 1; return 1;
    case 1605: *row = 9; *comp = 2; return 1;
    case 1606: *row = 9; *comp = 3; return 1;
    case 1623: *row = 15; *comp = 0; return 1;  /* 選択色 */
    case 1641: *row = 15; *comp = 1; return 1;
    case 1642: *row = 15; *comp = 2; return 1;
    case 1640: *row = 16; *comp = 0; return 1;  /* 仮表示色 */
    case 1643: *row = 16; *comp = 1; return 1;
    case 1644: *row = 16; *comp = 2; return 1;
    case 2480: *row = 0; *comp = 0; return 1;   /* 背景色 */
    case 2481: *row = 0; *comp = 1; return 1;
    case 2482: *row = 0; *comp = 2; return 1;
    case 1648: *row = 109; *comp = 0; return 1; /* プリンタのグレー */
    case 1649: *row = 109; *comp = 1; return 1;
    case 1650: *row = 109; *comp = 2; return 1;
    }
    /* プリンタ出力 線色 1..8: 赤 緑 青 線幅 が四つずつ（1623 は 選択色 が使う） */
    if (id >= 1607 && id <= 1622) {
        *row = 101 + (id - 1607) / 4;
        *comp = (id - 1607) % 4;
        return 1;
    }
    if (id >= 1624 && id <= 1639) {
        *row = 105 + (id - 1624) / 4;
        *comp = (id - 1624) % 4;
        return 1;
    }
    return 0;
}

/* where a colour's red, green or blue sits in the row's word: the printer
   pens are kept as the file has them, a COLORREF (0x00bbggrr), but the
   screen ones and the 選択色・仮表示色 rows as 0x00rrggbb (docs/ref_kihon3.png:
   線色 1 is 0 192 192 and 仮表示色 255 0 0) */
static int kh_shift(int row, int comp)
{
    return row >= 101 ? 8 * comp : 8 * (2 - comp);
}

/* the colour and width a row has now */
static unsigned int kh_row_get(int row, int *w)
{
    *w = -1;
    if (row >= 101 && row <= 109) {
        if (row <= 108)
            *w = drawing.print_width[row - 100];
        return drawing.print_rgb[row - 100];
    }
    if (row >= 1 && row <= 9) {
        *w = drawing.pen_width[row];
        return drawing.pen_rgb[row];
    }
    if (row == 0)
        return drawing.pen_rgb[0];
    return kihon_row_rgb(row);
}

static void kh_row_put(int row, unsigned int rgb, int w)
{
    if (row >= 101 && row <= 109) {
        drawing.print_rgb[row - 100] = rgb;
        if (row <= 108 && w >= 1 && w <= 500)   /* プリンタ出力線幅(1～500) */
            drawing.print_width[row - 100] = w;
    } else if (row >= 1 && row <= 9) {
        drawing.pen_rgb[row] = rgb;
        if (w >= 1 && w <= 16)                  /* 画面線幅(1～16) */
            drawing.pen_width[row] = w;
    } else if (row == 0) {
        drawing.pen_rgb[0] = rgb;
    } else if (row == 13) {
        drawing.gray_rgb = rgb;
    } else {
        jw_row_rgb_set(row, rgb);
    }
}

/* the boxes whose value is the drawing's: their text now */
static int kh_live(int tab, int id, char *out)
{
    int row, comp, w;

    if (!have_drawing)
        return 0;
    if (tab == 2 && kh_pen_box(id, &row, &comp)) {
        unsigned int v = kh_row_get(row, &w);

        if (comp == 3)
            sprintf(out, "%d", w);
        else
            sprintf(out, "%u", (v >> kh_shift(row, comp)) & 255u);
        return 1;
    }
    if (tab == 4 && id >= 2470 && id <= 2479) {     /* 横 */
        sprintf(out, "%g", drawing.style[id - 2470].w);
        return 1;
    }
    if (tab == 4 && id >= 1532 && id <= 1541) {     /* 縦 */
        sprintf(out, "%g", drawing.style[id - 1532].h);
        return 1;
    }
    if (tab == 4 && id >= 1542 && id <= 1551) {     /* 間隔 */
        sprintf(out, "%g", drawing.style[id - 1542].sp);
        return 1;
    }
    if (tab == 4 && id >= 1552 && id <= 1561) {     /* 色No. */
        sprintf(out, "%d", drawing.style[id - 1552].color);
        return 1;
    }
    return 0;
}

/* OK: what was typed into those boxes goes back into the drawing.  A box
   that does not hold a number in range leaves the value as it was */
static void kh_live_apply(void)
{
    int i, n, row, comp;

    if (!have_drawing)
        return;
    n = ui_kihon_n(2);
    for (i = 0; i < n && i < 256; i++) {
        int id = ui_kihon_id(2, i), w;
        const char *t = kh_txt[2][i];
        char *e;
        long v;
        unsigned int rgb;

        if (!ui_kihon_isbox(2, i) || !kh_pen_box(id, &row, &comp) || !*t
            || !strcmp(t, kh_txt_init[2][i]))
            continue;
        v = strtol(t, &e, 10);
        if (*e)
            continue;
        rgb = kh_row_get(row, &w);
        if (comp == 3) {
            kh_row_put(row, rgb, (int)v);
        } else if (v >= 0 && v <= 255) {        /* 色要素(0～255) */
            int sh = kh_shift(row, comp);

            rgb = (rgb & ~(255u << sh)) | ((unsigned int)v << sh);
            kh_row_put(row, rgb, -1);
        }
    }
    n = ui_kihon_n(4);
    for (i = 0; i < n && i < 256; i++) {
        int id = ui_kihon_id(4, i), k;
        const char *t = kh_txt[4][i];
        char *e;
        double v;

        if (!ui_kihon_isbox(4, i) || !*t || !strcmp(t, kh_txt_init[4][i]))
            continue;
        v = strtod(t, &e);
        if (*e)
            continue;
        if (id >= 2470 && id <= 2479 && v >= 0.01 && v <= 500.0)
            drawing.style[id - 2470].w = v;     /* 文字サイズ(0.01～500) */
        else if (id >= 1532 && id <= 1541 && v >= 0.01 && v <= 500.0)
            drawing.style[id - 1532].h = v;
        else if (id >= 1542 && id <= 1551 && v >= 0.0 && v <= 500.0)
            drawing.style[id - 1542].sp = v;
        else if (id >= 1552 && id <= 1561) {
            k = (int)v;
            if (k == v && k >= 1 && k <= 9)     /* 文字ペンNo(1～9) */
                drawing.style[id - 1552].color = k;
        }
    }
}

/* what box i of the tab shows, for ui_kihon: 0 when it has nothing */
const char *app_kihon_text(int tab, int i, int *center, int *caret)
{
    const jw_khv_t *v;

    if (tab < 0 || tab >= 8 || i < 0 || i >= 256)
        return 0;
    v = kh_val(tab, i);
    if (center)
        *center = v ? v->center : 0;
    if (caret)
        *caret = kh_ctab == tab && kh_ci == i;
    if (!strcmp(kh_txt[tab][i], kh_txt_init[tab][i])
        && kh_live(tab, ui_kihon_id(tab, i), kh_txt_init[tab][i]))
        strcpy(kh_txt[tab][i], kh_txt_init[tab][i]);
    return kh_txt[tab][i];
}

static void kh_txt_start(void)
{
    int t, i;

    for (t = 0; t < ui_kihon_ntabs() && t < 8; t++)
        for (i = 0; i < ui_kihon_n(t) && i < 256; i++) {
            const jw_khv_t *v;
            char *o = kh_txt[t][i];

            o[0] = 0;
            if (!ui_kihon_isbox(t, i))
                continue;
            if (kh_live(t, ui_kihon_id(t, i), o))
                continue;
            if (kh_txt_have) {
                memcpy(o, kh_txt_saved[t][i], KH_TXT);
                continue;
            }
            v = kh_val(t, i);
            if (v && v->text) {
                strncpy(o, v->text, KH_TXT - 1);
                o[KH_TXT - 1] = 0;
            }
        }
    memcpy(kh_txt_init, kh_txt, sizeof kh_txt_init);
    kh_ctab = kh_ci = -1;
    kh_cfresh = 0;
}

/* OK (the button or Enter): the ticks and the text stay, and what is known
   is applied */
static void kh_ok(void)
{
    kh3_style_t was[10];

    memcpy(kh_saved, kh_on, sizeof kh_saved);
    kh_have_saved = 1;
    memcpy(kh_txt_saved, kh_txt, sizeof kh_txt_saved);
    kh_txt_have = 1;
    kh3_style_take(was);
    kh_live_apply();
    kh3_restyle(was);                   /* 1883（src/kihon3.h） */
    kh_apply();
    kh_ctab = kh_ci = -1;
    kh_open = 0;
}

/* a key into the box being typed into.  Enter is not taken: it is the
   dialog's OK, as in Windows */
static int kh_key(int c)
{
    char *t;
    size_t n;

    if (kh_ctab < 0 || kh_ci < 0)
        return 0;
    t = kh_txt[kh_ctab][kh_ci];
    n = strlen(t);
    if (c == 8) {
        if (n)
            t[n - 1] = 0;
        kh_cfresh = 0;
        return 1;
    }
    if (c < 0x20 || c > 0x7e)
        return 0;
    if (kh_cfresh) {
        t[0] = 0;
        n = 0;
        kh_cfresh = 0;
    }
    if (n + 1 < KH_TXT) {
        t[n] = (char)c;
        t[n + 1] = 0;
    }
    return 1;
}

static void kh_start(void)
{
    int t, i;

    for (t = 0; t < ui_kihon_ntabs() && t < 8; t++)
        for (i = 0; i < ui_kihon_n(t) && i < 256; i++)
            kh_on[t][i] = (unsigned char)(kh_have_saved ? kh_saved[t][i] : ui_kihon_on(t, i));
    /* 2112「TextFileをUTF-8出力」 is the same flag as the 文字 range bar's
       SJIS/UTF8 button (DAT_00a0b458, MOJI\OutSJIS): the page ticks it when
       the flag says UTF-8 (FUN_005cc7e0), and OK puts it back (DAT_00a0b458 = !ticked) */
    for (t = 0; t < ui_kihon_ntabs() && t < 8; t++)
        for (i = 0; i < ui_kihon_n(t) && i < 256; i++)
            if (ui_kihon_id(t, i) == 2112)
                kh_on[t][i] = (unsigned char)!jw_moji_sjis();
    kh_txt_start();
    kh_colinit = 0;
    kh_tab = 0;
    kh_open = 1;
}

/* ------------------------------------------- 設定を起動をまたいで残す ---
 *
 * 原典は 基本設定 の箱の多くをレジストリ HKCU\Software\Jw_cad\jw_win に置き
 * （書き手 `FUN_004ea620`、呼び手は CJw_winView の後始末 `FUN_004f9bb0` ＝
 * 閉じるとき、と 寸法設定 の OK `FUN_0050f6f0`）、次の起動で読む。移植の
 * 代わりがこの字の並び（app_prefs_write / app_prefs_read）で、ネイティブは
 * %APPDATA%\jw_port\jw_win_reg.txt、ブラウザは localStorage に置く。
 *
 * 残すのは OK が残したもの: 基本設定 の 箱の字（kh_txt_saved）と 押し釦の
 * 点き具合（kh_saved）、寸法設定 の 押し釦（sd_saved）。どれも既定
 * （src/gen/kihonval.h・kihon.h・sunpodlg.h）と違うものだけを書く。
 *
 * **書かないもの**: 図面の持ち物（色・画面 のペン、文字 の文字種 ——
 * kh_live）は図面が勝つので書かない（.jwf の LCOLLOR などは別に残る）。
 * 2112「TextFileをUTF-8出力」は 文字 のバーの SJIS/UTF8 と同じ旗で、表側が
 * 別に残している（jw_port.ini の OutSJIS、localStorage の jw.sjis）。
 * 寸法設定 の数の箱と 文字基点設定 のずれは .jwf の S_SET・MOFST の行に
 * 入る（src/cmd.c env_sunpo_line）。
 *
 * 鍵は原典のレジストリ名ではなく窓の部品の id（どの箱がどの名前かは
 * tools/mkkihonval.py が知っているが、押し釦の側はまだ読んでいない）:
 *
 *   [KIHON]   T<タブ>.<id>.<同じ id の何番目の箱>=字
 *             C<タブ>.<id>.<同じ id の何番目の部品>=0|1
 *   [SUNPODLG] C<id>.<何番目>=0|1
 *
 * 字は ASCII の外（CP932 の二バイトなど）と \ を \xHH・\\ にして、行が
 * ASCII だけで済むようにする（localStorage にそのまま入る）。 */
static int kh_is_live(int tab, int id)
{
    int row, comp;

    return (tab == 2 && kh_pen_box(id, &row, &comp))
           || (tab == 4 && ((id >= 2470 && id <= 2479)
                            || (id >= 1532 && id <= 1561)));
}

/* which one of that id it is: among the boxes (box = 1) or all controls */
static int kh_nth(int tab, int i, int box)
{
    int id = ui_kihon_id(tab, i), k, nth = 0;

    for (k = 0; k < i; k++)
        if (ui_kihon_id(tab, k) == id && (!box || ui_kihon_isbox(tab, k)))
            nth++;
    return nth;
}

static int kh_find(int tab, int id, int nth, int box)
{
    int i;

    if (tab < 0 || tab >= ui_kihon_ntabs() || tab >= 8)
        return -1;
    for (i = 0; i < ui_kihon_n(tab) && i < 256; i++)
        if (ui_kihon_id(tab, i) == id && (!box || ui_kihon_isbox(tab, i))
            && kh_nth(tab, i, box) == nth)
            return i;
    return -1;
}

static void kh_txt_default(int tab, int i, char *o)
{
    const jw_khv_t *v = kh_val(tab, i);

    o[0] = 0;
    if (ui_kihon_isbox(tab, i) && v && v->text) {
        strncpy(o, v->text, KH_TXT - 1);
        o[KH_TXT - 1] = 0;
    }
}

/* ---------------------------- 箱の字を移植の働きへ（kh_apply_text） ---
 *
 * OK が残した字（無ければ既定の字）を読む。数の箱は原典の DDX と同じく
 * double で読んで int に切り、DDV の範囲の外や数でない字なら**前の値の
 * まま**（原典は OK を通さないが、移植の窓は止めないので効かせないだけ）。 */
static int kh_autosave_min = 30;    /* AutoSave\Time（分）、DAT_00a0cb04 */
static int kh_backup = 1;           /* AutoSave\Back（-9〜9）、DAT_00a0cb18 */

static const char *kh_ok_text(int tab, int id, int nth, char *buf)
{
    int i = kh_find(tab, id, nth, 1);

    if (i < 0)
        return 0;
    if (kh_txt_have)
        return kh_txt_saved[tab][i];
    kh_txt_default(tab, i, buf);
    return buf;
}

static int kh_ok_int(int tab, int id, int nth, int lo, int hi, int *out)
{
    char buf[KH_TXT], *e;
    const char *t = kh_ok_text(tab, id, nth, buf);
    double v;

    if (!t)
        return 0;
    while (*t == ' ')
        t++;
    if (!*t)
        return 0;
    v = strtod(t, &e);
    while (*e == ' ')
        e++;
    if (*e || !(v >= lo && v <= hi))
        return 0;
    *out = (int)v;
    return 1;
}

/* 線種の箱の字からパターン: 原典の FUN_005c2670 と同じく、頭の字から
   上の桁へ 32 字、空白・カンマ・字の終わりでなければ 1。原典の字は
   UTF-16 なので、二バイトの字は一字に数える */
static unsigned int kh_pattern(const char *t)
{
    unsigned int r = 0;
    int k;

    for (k = 0; k < 32; k++) {
        unsigned char c = (unsigned char)*t;

        r <<= 1;
        if (c && c != ' ' && c != ',')
            r |= 1;
        if (c) {
            t += jw_is_lead(c) && t[1] ? 2 : 1;
        }
    }
    return r;
}

static void kh_apply_text(void)
{
    int k, n;

    /* 線種 タブ: 線種 2〜9（1001 の何番目 1〜8）、単位 1777..、画面
       ピッチ 1652..。三つのどれかが読めなければその線種はそのまま */
    for (k = 2; k <= 9; k++) {
        char buf[KH_TXT];
        const char *t = kh_ok_text(3, 1001, k - 1, buf);
        int unit, pitch;

        if (t && kh_ok_int(3, 1775 + k, 0, 1, 32, &unit)
            && kh_ok_int(3, 1650 + k, 0, 1, 16, &pitch))
            jw_ltype_set(k, kh_pattern(t), unit, pitch);
    }
    /* 一般(1): Undo 1934（1〜100、FUN_005ce2a0 の DDV）、オートセーブ 1049
       （1〜1000 分）、バックアップ 1055（-9〜9） */
    if (kh_ok_int(0, 1934, 0, 1, 100, &n))
        jw_cmd_undo_limit(n);
    if (kh_ok_int(0, 1049, 0, 1, 1000, &n))
        kh_autosave_min = n;
    if (kh_ok_int(0, 1055, 0, -9, 9, &n))
        kh_backup = n;
}

int app_autosave_minutes(void)
{
    return kh_autosave_min;
}

/* 上書き保存の前に残す控えの世代の数。原典の保存の手前 FUN_004be3a0 の
 * 読み（DAT_00a0cb18 の枝。A: などの字は 0x95eb1c.. の "A:" "a:" "B:" "b:"
 * を Left(2) と比べる FUN_00447310・FUN_004b4f10）:
 *   0                 控えを作らない
 *   負                A: B: のドライブ（フロッピー）なら作らない
 *   |n| が 2 以上     A: B: でなければ n 世代（.BAK・.BK2 … .BK<n>）、
 *                     A: B: なら .BAK の一つだけ
 * floppy は保存先が A:・a:・B:・b: で始まるか */
int app_backup_gens(int floppy)
{
    int n = kh_backup < 0 ? -kh_backup : kh_backup;

    if (n == 0 || (kh_backup < 0 && floppy))
        return 0;
    return floppy ? 1 : n;
}

/* k 世代目の控えの拡張子（拡張子の三字をこれに替える）: 1 は BAK、
   2 から BK2 … BK9 */
const char *app_backup_ext(int k)
{
    static char e[4];

    if (k <= 1)
        return "BAK";
    if (k > 9)
        k = 9;
    e[0] = 'B';
    e[1] = 'K';
    e[2] = (char)('0' + k);
    e[3] = 0;
    return e;
}

/* the number in the first box with this id on that tab, as OK left it (or the
   original's default); dflt when it holds no number */
static double kh_num(int tab, int id, double dflt)
{
    char t[KH_TXT], *e;
    int i = kh_find(tab, id, 0, 1);
    double v;

    if (i < 0)
        return dflt;
    if (kh_txt_have)
        memcpy(t, kh_txt_saved[tab][i], KH_TXT);
    else
        kh_txt_default(tab, i, t);
    t[KH_TXT - 1] = 0;
    v = strtod(t, &e);
    return e != t && !*e ? v : dflt;
}

/* 基本設定 一般(2) 2362「矢印キーで画面移動、PageUp・PageDownで画面拡大・縮小、
 * Homeで全体表示にする」。原典はキーを CZoom の命令に替え（FUN_00512920: ← 0x65、
 * → 0x66、↑ 0x67、↓ 0x68、PageUp 0x6f、PageDown 0x70、Home 4）、CZoom の後始末
 * FUN_0060b110 が 画面の中心（+0x7a18・+0x7a20）を 画面の幅（↑↓は高さ）×移動率
 * (DAT_00a0d868) だけ動かし、倍率（+0x1728）を 拡大率 (DAT_00a0d870) で掛け・割る
 * （1000 と 0.01 で止める）。2362 と 1325 が両方なら（DAT_00a0d864 == 2）動かす向きを
 * 軸角（doc+0x1738）だけ回す。旗が立っていなければ 窓の部品（バーの箱）がそのキーを
 * 受ける（FUN_0054cae0・0058abc0 などの PreTranslateMessage が DAT_00a0d864 を見る）。
 * 移植は旗が立っているときだけ ←↑→↓ PageUp PageDown を受ける（Home は前から
 * いつも全体表示）。vk は Windows の仮想キー（0x21 PageUp 0x22 PageDown
 * 0x25〜0x28 ←↑→↓）。受けたら 1。逆コンパイルの読み、原典では押していない。
 * ２．５D の立体の画面では 旗に関わらず 2.5D が受ける（view の PreTranslateMessage
 * 0x4e9a76.. が ← → ↑ ↓ PageUp PageDown を 0x1501..0x1504・0x1506・0x1507 にして
 * 図形の slot 37〜42 へ。src/d25view.c の jw_d25_key） */
int app_arrow_key(int vk)
{
    double w, h, c = 1.0, s = 0.0, mx = 0.0, my = 0.0;

    if (view_ready && have_drawing && !app_modal() && jw_cmd() == JW_CMD_25D
        && jw_d25_mode())
        return jw_d25_key(&drawing, vk);
    if (!kh_arrows || !view_ready || !have_drawing || app_modal())
        return 0;
    if (vk == 0x21 || vk == 0x22) {
        double f = kh_zoom_rate;

        if (!(f > 0.0))
            return 1;
        if (vk == 0x22)
            f = 1.0 / f;
        /* 原典の 1000 倍・0.01 倍の止めは 移植の app_zoom が持たない（行き過ぎだけ断る） */
        app_zoom(f, view.clip.x + view.clip.w / 2, view.clip.y + view.clip.h / 2);
        return 1;
    }
    if (vk < 0x25 || vk > 0x28)
        return 0;
    w = view.clip.w * view.mmpp * kh_move_rate;
    h = view.clip.h * view.mmpp * kh_move_rate;
    if (kh_arrows == 2) {
        double a = jw_cmd_axis() * 3.14159265358979323846 / 180.0;

        c = cos(a);
        s = sin(a);
    }
    switch (vk) {
    case 0x25: mx = -w * c; my = -w * s; break;     /* ← 0x65 */
    case 0x27: mx = w * c;  my = w * s;  break;     /* → 0x66 */
    case 0x26: mx = -h * s; my = h * c;  break;     /* ↑ 0x67 */
    case 0x28: mx = h * s;  my = -h * c; break;     /* ↓ 0x68 */
    }
    view.ox += mx;
    view.oy += my;
    return 1;
}

/* 基本設定 一般(1) 2437 クロスラインカーソル。原典は doc+0x176c に CCrossLine
 * のようなもの（FUN_0041c850）を持ち、FUN_00517430(1/0) で作り・消す。いつ作るか:
 * 命令が替わるとき（FUN_004faf00・004fdc40）は doc+6000 == 1 なら作り、ほかは消す。
 * 範囲の始点待ち（FUN_0040ac80 の local_6800[1] == 0）は 1 以上なら作り、終点待ちは
 * 2 なら作り 3 なら消す。描くのは FUN_0041d3f0: 仮表示（FUN_004bbad0 =
 * R2_NOTXORPEN）で、マウスの点を通る 縦横の二本を 窓の大きさ（+0x1808）の 1.45 倍
 * の長さで、軸角（+0x17c0 を -45〜45 に畳んだもの）だけ傾けて。線種は
 * DAT_00a0c7f4 が 2 以上ならその線種（移植は実線だけ）。
 * 逆コンパイルの読み、原典では押していない。 */
static int cross_on(void)
{
    int ph;

    if (!kh_cross || !cross_have || !view_ready || !have_drawing || app_modal())
        return 0;
    if (kh_cross == 1)
        return 1;
    ph = jw_cmd_range_phase();
    return kh_cross == 2 ? ph != 0 : ph == 1;
}

static void cross_paint(void)
{
    jw_drawing one;
    jw_obj o[2];
    double a, c, s, len;
    int k;

    if (!cross_on())
        return;
    a = jw_cmd_axis();
    while (a > 45.0)
        a -= 90.0;
    while (a <= -45.0)
        a += 90.0;
    a *= 3.14159265358979323846 / 180.0;
    c = cos(a);
    s = sin(a);
    len = (view.clip.w + view.clip.h) * view.mmpp * 1.45;
    one = drawing;
    one.group[0].state = 3;
    one.group[0].layer[0].state = 3;
    one.mesh_ix = one.mesh_iy = 0.0;
    for (k = 0; k < 2; k++) {
        double dx = k ? -s : c, dy = k ? c : s;

        memset(&o[k], 0, sizeof o[k]);
        o[k].cls = JW_SEN;
        o[k].ltype = 1;
        o[k].color = 2;
        o[k].text = o[k].face = -1;
        o[k].d[0] = cross_x - dx * len;
        o[k].d[1] = cross_y - dy * len;
        o[k].d[2] = cross_x + dx * len;
        o[k].d[3] = cross_y + dy * len;
    }
    one.obj = o;
    one.nobj = one.ndrawn = 2;
    ui_view_rect(fb.w, fb.h, &view.clip);
    jw_draw_kari = 1;
    jw_draw(&fb, &view, &one);
    jw_draw_kari = 0;
}

typedef struct { char *b; size_t n, cap; int bad; } pf_out;

static void pf_put(pf_out *o, const char *t)
{
    size_t l = strlen(t);

    if (o->bad)
        return;
    if (o->n + l + 1 > o->cap) {
        size_t c = o->cap ? o->cap * 2 : 4096;
        char *nb;

        while (c < o->n + l + 1)
            c *= 2;
        nb = (char *)realloc(o->b, c);
        if (!nb) {
            o->bad = 1;
            return;
        }
        o->b = nb;
        o->cap = c;
    }
    memcpy(o->b + o->n, t, l + 1);
    o->n += l;
}

static void pf_esc(pf_out *o, const char *t)
{
    char c[8];

    for (; *t; t++) {
        unsigned char u = (unsigned char)*t;

        if (u == '\\')
            strcpy(c, "\\\\");
        else if (u < 0x20 || u > 0x7e)
            sprintf(c, "\\x%02x", u);
        else {
            c[0] = (char)u;
            c[1] = 0;
        }
        pf_put(o, c);
    }
}

int app_prefs_write(unsigned char **out, long *n)
{
    pf_out o = { 0, 0, 0, 0 };
    char line[96], def[KH_TXT];
    int t, i;

    if (!out || !n)
        return 0;
    pf_put(&o, "# jw_win port: the original's registry settings (HKCU\\Software\\Jw_cad\\jw_win)\n");
    pf_put(&o, "[KIHON]\n");
    for (t = 0; t < ui_kihon_ntabs() && t < 8; t++)
        for (i = 0; i < ui_kihon_n(t) && i < 256; i++) {
            int id = ui_kihon_id(t, i);

            if (ui_kihon_isbox(t, i)) {
                if (!kh_txt_have || kh_is_live(t, id))
                    continue;
                kh_txt_default(t, i, def);
                if (!strcmp(kh_txt_saved[t][i], def))
                    continue;
                sprintf(line, "T%d.%d.%d=", t, id, kh_nth(t, i, 1));
                pf_put(&o, line);
                pf_esc(&o, kh_txt_saved[t][i]);
                pf_put(&o, "\n");
            } else if (kh_have_saved && id != 2112
                       && kh_saved[t][i] != (unsigned char)ui_kihon_on(t, i)) {
                sprintf(line, "C%d.%d.%d=%d\n", t, id, kh_nth(t, i, 0),
                        kh_saved[t][i] ? 1 : 0);
                pf_put(&o, line);
            }
        }
    pf_put(&o, "[SUNPODLG]\n");
    if (sd_have_saved) {
        int nn = ui_sunpodlg_n();

        for (i = 0; i < nn && i < (int)sizeof sd_saved; i++) {
            int id = ui_sunpodlg_id(i), k, nth = 0;

            if (sd_saved[i] == (unsigned char)ui_sunpodlg_on(i))
                continue;
            for (k = 0; k < i; k++)
                if (ui_sunpodlg_id(k) == id)
                    nth++;
            sprintf(line, "C%d.%d=%d\n", id, nth, sd_saved[i] ? 1 : 0);
            pf_put(&o, line);
        }
    }
    if (o.bad) {
        free(o.b);
        return 0;
    }
    *out = (unsigned char *)o.b;
    *n = (long)o.n;
    return 1;
}

static void pf_unesc(const char *v, char *o, size_t cap)
{
    size_t k = 0;

    while (*v && k + 1 < cap) {
        if (v[0] == '\\' && v[1] == '\\') {
            o[k++] = '\\';
            v += 2;
        } else if (v[0] == '\\' && v[1] == 'x' && v[2] && v[3]
                   && strchr("0123456789abcdefABCDEF", v[2])
                   && strchr("0123456789abcdefABCDEF", v[3])) {
            char h[3] = { v[2], v[3], 0 };

            o[k++] = (char)strtol(h, 0, 16);
            v += 4;
        } else {
            o[k++] = *v++;
        }
    }
    o[k] = 0;
}

/* what app_prefs_write wrote, back into the dialogs as if OK had left it
   there.  Anything not understood is skipped.  Returns how many lines it
   took. */
int app_prefs_read(const unsigned char *b, long n)
{
    const char *p = (const char *)b, *end = p + (b ? n : 0);
    char sec[16] = "";
    int t, i, taken = 0, kh_any = 0, sd_any = 0;
    static unsigned char kon[8][256], son[128];
    static char ktx[8][256][KH_TXT];

    if (!b || n <= 0)
        return 0;
    /* start from the defaults, or what OK has left this run */
    for (t = 0; t < ui_kihon_ntabs() && t < 8; t++)
        for (i = 0; i < ui_kihon_n(t) && i < 256; i++) {
            kon[t][i] = kh_have_saved ? kh_saved[t][i]
                                      : (unsigned char)ui_kihon_on(t, i);
            if (kh_txt_have)
                memcpy(ktx[t][i], kh_txt_saved[t][i], KH_TXT);
            else
                kh_txt_default(t, i, ktx[t][i]);
        }
    for (i = 0; i < ui_sunpodlg_n() && i < (int)sizeof son; i++)
        son[i] = sd_have_saved ? sd_saved[i] : (unsigned char)ui_sunpodlg_on(i);
    while (p < end) {
        const char *nl = memchr(p, '\n', (size_t)(end - p));
        size_t ll = nl ? (size_t)(nl - p) : (size_t)(end - p);
        char line[512];
        const char *v;
        int a, id, nth, k;

        if (ll >= sizeof line)
            ll = sizeof line - 1;
        memcpy(line, p, ll);
        line[ll] = 0;
        p = nl ? nl + 1 : end;
        while (ll > 0 && (line[ll - 1] == '\r' || line[ll - 1] == ' '))
            line[--ll] = 0;
        if (line[0] == '[') {
            for (k = 0; k + 1 < (int)sizeof sec && line[k + 1]
                        && line[k + 1] != ']'; k++)
                sec[k] = line[k + 1];
            sec[k] = 0;
            continue;
        }
        v = strchr(line, '=');
        if (line[0] == '#' || !v)
            continue;
        v++;
        if (!strcmp(sec, "KIHON") && line[0] == 'T'
            && sscanf(line + 1, "%d.%d.%d=", &a, &id, &nth) == 3) {
            k = kh_find(a, id, nth, 1);
            if (k >= 0 && !kh_is_live(a, id)) {
                pf_unesc(v, ktx[a][k], KH_TXT);
                kh_any = 1;
                taken++;
            }
        } else if (!strcmp(sec, "KIHON") && line[0] == 'C'
                   && sscanf(line + 1, "%d.%d.%d=", &a, &id, &nth) == 3) {
            k = kh_find(a, id, nth, 0);
            if (k >= 0 && !ui_kihon_isbox(a, k) && id != 2112) {
                kon[a][k] = (unsigned char)(atoi(v) != 0);
                kh_any = 1;
                taken++;
            }
        } else if (!strcmp(sec, "SUNPODLG") && line[0] == 'C'
                   && sscanf(line + 1, "%d.%d=", &id, &nth) == 2) {
            for (k = 0; k < ui_sunpodlg_n() && k < (int)sizeof son; k++)
                if (ui_sunpodlg_id(k) == id && nth-- == 0) {
                    son[k] = (unsigned char)(atoi(v) != 0);
                    sd_any = 1;
                    taken++;
                    break;
                }
        }
    }
    if (kh_any) {
        int sjis = jw_moji_sjis();

        memcpy(kh_saved, kon, sizeof kh_saved);
        kh_have_saved = 1;
        memcpy(kh_txt_saved, ktx, sizeof kh_txt_saved);
        kh_txt_have = 1;
        kh_apply();                     /* as OK does, but not into the drawing */
        jw_moji_sjis_set(sjis);         /* 2112 is the front end's (see above) */
        kh3_startup();                  /* 2527 初期コマンド AUTO（src/kihon3.h） */
    }
    if (sd_any) {
        memcpy(sd_saved, son, sizeof sd_saved);
        sd_have_saved = 1;
        sd_apply(sd_saved);             /* OK と同じく作図に効かせる */
    }
    return taken;
}

/* 色・画面 の左の列（画面の色）の釦と、原典の行番号。
 *
 * **デコンパイルから引いたものです。**CGamenPage の振り分け表
 * （`python tools/msgmap.py 1059` で出ます。表は 0095edc0、38 項目）
 * はこの十二個をどれも同じ受け手に入れていて、渡すのは行番号だけ
 * でした:
 *
 *   FUN_004c3530 → FUN_004c4af0(1)    釦 1059 色１
 *   …                                 1060→2 1061→3 1062→4
 *                                      1901→5 1902→6 1903→7 1904→8
 *   FUN_004c3630 → FUN_004c4af0(0xd)  釦 1905 グレー
 *   FUN_004c3650 → FUN_004c4af0(9)    釦 1120
 *   FUN_004c3670 → FUN_004c4af0(0xf)  釦 1121
 *   FUN_004c3690 → FUN_004c4af0(0x10) 釦 1122
 *
 * 受け手 FUN_004c4af0 は CColorDialog をその行の色で開き、**戻りが
 * 1（OK）のときだけ** R・G・B を書き戻します。
 *
 * どの行がどの色かは原典にその窓を出させて確かめました
 * （tools/probe149.sh、見本枠の画素）: 1059 が 00c0c0、1120 が
 * ff80ff —— それぞれ画面ペン 1 と 9 です。1905 は c0c0c0 で
 * どのペンでもなく「グレー」、1121 は ff00ff の選択色、1122 は
 * ff0000 の仮表示色でした。
 *
 * 右の列（釦 1074..1082 など）はプリンタ出力の色です。原典は同じ
 * 受け手に 100 を足した行番号を渡し（釦 1074 は FUN_004c4af0(0x65)）、
 * `param_1 % 100` の行の**別の欄**を書きます。移植はプリンタ側の色を
 * 持っていないので、そこは触りません。
 */
static int kihon_row(int id)
{
    switch (id) {
    case 1059: return 1;
    case 1060: return 2;
    case 1061: return 3;
    case 1062: return 4;
    case 1901: return 5;
    case 1902: return 6;
    case 1903: return 7;
    case 1904: return 8;
    case 1120: return 9;
    case 1905: return 13;               /* グレー */
    case 1121: return 15;               /* 選択色 */
    case 1122: return 16;               /* 仮表示色 */
    }
    return -1;
}

/* その行がいま持っている色。行 13（グレー）は図面が持っています ——
   ファイルの十本目の画面ペンがそこに入るからで、原典もそう読みます
   （src/jww.h の gray_rgb）。 */
static unsigned int kihon_row_rgb(int row)
{
    if (row >= 1 && row <= 9)
        return have_drawing ? drawing.pen_rgb[row]
                            : jw_default_pen_rgb[row];
    if (row == 13)
        return have_drawing ? drawing.gray_rgb : jw_row_rgb(13);
    return jw_row_rgb(row);
}

/* 色・画面 の 色彩の初期化 (1910)・背景色：白 (1907)・黒 (1908)・深緑 (1909)・
 * プリンタ出力色 (1911)。CGamenPage の振り分け表（mm.py 4bf000 4c4100）で
 * 1910 → FUN_004c3e30: +0x178 を裏返して 押し釦五つの EnableWindow をそれに
 * （窓の型では 1907〜1909・1911 が WS_DISABLED）。1907 → FUN_004c4000、
 * 1908 → FUN_004c3ca0(0)、1909 → FUN_004c3ca0(1)、1911 → FUN_004c3f00 は
 * 頁の色の欄（+0x184 + 行×4、COLORREF）を決まった色で埋め、FUN_004c4cf0 で
 * 箱の数（赤 緑 青）に移して、FUN_004c3e30 でまた押せなくし、UpdateData(FALSE)。
 * 線幅は触らない。行 0 背景色 1..8 画面の線色 9 補助線色 13 グレー 15 選択色
 * 16 仮表示色、19（+0x1d0）は 2483〜2485 の箱、101..109 はプリンタ出力の線色と
 * グレー（+0x1dc + 行×4、+0x210）。数は機械語の即値（0x4c3ca0〜・0x4c4000〜）。
 * OK で図面へ（kh_live_apply、打った箱と同じ）。逆コンパイルの読み、原典では
 * 押していない。 */
static int kh_on_get(int tab, int id)
{
    int i;

    for (i = 0; i < ui_kihon_n(tab) && i < 256; i++)
        if (ui_kihon_id(tab, i) == id && !ui_kihon_isbox(tab, i))
            return kh_on[tab][i];
    return 0;
}

static void kh_on_set(int tab, int id, int on)
{
    int i;

    for (i = 0; i < ui_kihon_n(tab) && i < 256; i++)
        if (ui_kihon_id(tab, i) == id && !ui_kihon_isbox(tab, i))
            kh_on[tab][i] = (unsigned char)(on != 0);
}

int app_kihon_enabled(int tab, int i, int deflt)
{
    int id;

    if (i >= 0 && tab >= 0 && (id = kh3_enabled(tab, ui_kihon_id(tab, i))) >= 0)
        return id;                      /* 文字 の 1884・1563 ほか（src/kihon3.h） */

    if (tab == 1 && i >= 0 && ui_kihon_id(tab, i) == 1325)
        return kh_on_get(1, 2362);      /* 軸角方向移動 は 矢印キーで画面移動 の下の段 */
    /* 一般(1) の DDX（FUN_005ce2a0）は UpdateData のたびに、2437 が入っていれば
       範囲指定のみ・範囲始点のみ を、2405 が入っていれば ソリッドを先に描画 と
       ソリッド描画順 を押せるようにする（EnableWindow） */
    if (tab == 0 && i >= 0) {
        id = ui_kihon_id(tab, i);
        if (id == 2438 || id == 2439)
            return kh_on_get(0, 2437);
        if (id == 2406 || (id >= 1525 && id <= 1529))
            return kh_on_get(0, 2405);
    }
    if (tab != 2 || i < 0)
        return deflt;
    id = ui_kihon_id(tab, i);
    if (id == 1907 || id == 1908 || id == 1909 || id == 1911)
        return kh_colinit;
    return deflt;
}

/* put row's colour (a COLORREF, 0x00bbggrr) into the 色・画面 boxes of that row */
static void kh_put_row(int row, unsigned int cref)
{
    int i, r, comp, n = ui_kihon_n(2);

    for (i = 0; i < n && i < 256; i++) {
        int id = ui_kihon_id(2, i);

        if (!ui_kihon_isbox(2, i))
            continue;
        if (row == 19 && id >= 2483 && id <= 2485)
            comp = id - 2483;
        else if (!kh_pen_box(id, &r, &comp) || r != row || comp > 2)
            continue;
        sprintf(kh_txt[2][i], "%u", (cref >> (8 * comp)) & 255u);
    }
}

static void kh_colour_preset(int id)
{
    /* 行 0..9（背景色・線色 1〜8・補助線色）、13 グレー、15 選択色、16 仮表示色、19 */
    static const unsigned int WHITE[10] = {
        0xffffff, 0xc0c000, 0x000000, 0x00c000, 0x00c0c0,
        0xc000c0, 0xff0000, 0x808000, 0x8000ff, 0xff80ff
    };
    static const unsigned int DARK[10] = {
        0x000000, 0xffff00, 0xffffff, 0x00ff00, 0x00ffff,
        0xc000c0, 0xff2020, 0x808000, 0x0000a0, 0x8080c0
    };
    static const unsigned int PRN[9] = {        /* プリンタ 線色 1〜8 と グレー */
        0xffff00, 0x000000, 0x00ff00, 0x00ffff, 0xff00ff,
        0xff0000, 0x808000, 0x0000ff, 0xc0c0c0
    };
    int k;

    if (id == 1911) {
        for (k = 0; k < 8; k++)
            kh_put_row(101 + k, PRN[k]);
        kh_put_row(109, PRN[8]);
        return;
    }
    for (k = 0; k < 10; k++)
        kh_put_row(k, id == 1907 ? WHITE[k] : DARK[k]);
    if (id == 1909)
        kh_put_row(0, 0x002000);                /* 深緑 */
    kh_put_row(13, id == 1907 ? 0xc0c0c0 : 0x808080);
    kh_put_row(15, id == 1907 ? 0xff00ff : 0xc800e6);
    kh_put_row(16, id == 1907 ? 0x0000ff : 0xffff00);
    kh_put_row(19, 0x808080);
}

static int press_kihon(int x, int y)
{
    int id = ui_kihon_hit(fb.w, fb.h, kh_tab, x, y), i, n;
    int at = ui_kihon_hit_index(fb.w, fb.h, kh_tab, x, y);

    if (id == -1000)
        return 0;                       /* outside it: the dialog is modal */
    if (id < 0) {                       /* one of the tabs */
        kh_tab = -id - 1;
        kh_ctab = kh_ci = -1;
        return 1;
    }
    if (id == 1) {                      /* OK: what is ticked and typed stays, and what is known is applied */
        kh_ok();
        return 1;
    }
    /* an edit box takes the typing; the first key replaces what is in it */
    if (at >= 0 && ui_kihon_isbox(kh_tab, at) == 1) {
        kh_ctab = kh_tab;
        kh_ci = at;
        kh_cfresh = 1;
        return 1;
    }
    kh_ctab = kh_ci = -1;
    if (id == 1 || id == 2 || id == 9) {
        /* キャンセル and ヘルプ do nothing; what most of the boxes mean
           has not been worked out */
        kh_open = 0;
        return 1;
    }
    if (kh_tab == 2) {                  /* 色・画面 */
        int row = kihon_row(id);

        if (id == 1910) {
            kh_colinit = !kh_colinit;
            return 1;
        }
        if (id == 1907 || id == 1908 || id == 1909 || id == 1911) {
            kh_colour_preset(id);
            kh_colinit = !kh_colinit;   /* FUN_004c3e30 をもう一度: また押せなく */
            return 1;
        }

        if (row >= 0) {
            cd_start(row, kihon_row_rgb(row));
            return 1;
        }
    }
    if (kh3_press(kh_tab, id))          /* 1884 の丸釦（src/kihon3.h） */
        return 1;
    n = ui_kihon_n(kh_tab);
    for (i = 0; i < n && i < 256; i++)
        if (ui_kihon_id(kh_tab, i) == id)
            kh_on[kh_tab][i] = (unsigned char)!kh_on[kh_tab][i];
    kh3_after_press(kh_tab, id);        /* 1886・1900 の連れ */
    /* 押したときの連れ（窓の受け手）。一般(2): 2362 を切ると 1325 も切れ、入れると
       2093 が切れる（FUN_005d1a50）、2093 を入れると 2362・1325 が切れる
       （FUN_005d1930）。一般(1): 2438 範囲指定のみ と 2439 範囲始点のみ は
       入れると もう片方が切れる（FUN_005cf4c0・005cf500 の BM_SETCHECK 0） */
    if (kh_tab == 1 && id == 2362) {
        if (!kh_on_get(1, 2362))
            kh_on_set(1, 1325, 0);
        else
            kh_on_set(1, 2093, 0);
    }
    if (kh_tab == 1 && id == 2093 && kh_on_get(1, 2093)) {
        kh_on_set(1, 1325, 0);
        kh_on_set(1, 2362, 0);
    }
    if (kh_tab == 0 && (id == 2438 || id == 2439) && kh_on_get(0, id))
        kh_on_set(0, id == 2438 ? 2439 : 2438, 0);
    if (kh_tab == 0 && id == 2405 && !kh_on_get(0, 2405))
        kh_on_set(0, 2406, 0);          /* FUN_005cf390 */
    return 1;
}

int app_kihon_tab(void)
{
    return kh_tab;
}
static char be_name[64];

int app_blkedit_open(void)
{
    return be_open;
}

const char *app_blkedit_name(void)
{
    return be_name;
}

static int press_blkedit(int x, int y)
{
    int id = ui_blkedit_hit(fb.w, fb.h, x, y);

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* OK: the mode is already on */
        if (have_drawing && !be_all)    /* 選択したブロックのみに */
            jw_cmd_block_split(&drawing);
        be_open = 0;
    } else if (id == 2) {               /* キャンセル */
        jw_cmd_block_done();
        be_open = 0;
    } else if (id == 3) {               /* ブロック名変更 */
        if (have_drawing)
            jw_cmd_block_rename(&drawing, be_name);
    } else if (id == 2410 || id == 2411) {
        be_all = id == 2410;            /* the two are one choice */
    }
    return 1;
}

/* CP932 typed into a fixed buffer a byte at a time -- the two block-name
 * boxes.  The same two faults the 文字 line had (src/cmd.c, jw_cmd_key):
 * a lead byte taken into the last place with no room for its trail, and a
 * backspace that took off bytes of 0x80 and over that were not lead bytes,
 * which is not how a pair is told -- the trail of ア is 0x41, so backing
 * over ア left its lead byte behind.  Both are settled by walking the
 * string from its start, which is the only way CP932 can be read. */
static int ends_in_lead(const char *s, size_t n)
{
    size_t i = 0;

    while (i < n) {
        if (jw_is_lead((unsigned char)s[i])) {
            if (i + 1 >= n)
                return 1;
            i += 2;
        } else {
            i++;
        }
    }
    return 0;
}

static void text_back(char *s)
{
    size_t n = strlen(s), i = 0, last = 0;

    while (i < n) {
        last = i;
        i += jw_is_lead((unsigned char)s[i]) && i + 1 < n ? 2 : 1;
    }
    s[last] = 0;
}

/* one byte in; `drop` is the buffer's own flag for a refused lead byte,
   whose trail must be refused after it */
static void text_put(char *s, size_t cap, int *drop, int c)
{
    size_t n = strlen(s);

    if (*drop) {
        *drop = 0;
        return;
    }
    if (!ends_in_lead(s, n)) {          /* c starts a character */
        size_t w = jw_is_lead((unsigned char)c) ? 2 : 1;

        if (n + w >= cap) {
            *drop = w == 2;
            return;
        }
    }
    s[n] = (char)c;                     /* (a trail always has its room) */
    s[n + 1] = 0;
}

static int blk_drop, be_drop;

/* A name typed into the layer dialog's box.  The original's CBN_EDITCHANGE
 * (FUN_005615f0 for 1838, FUN_00561690 for 1839) gives the group, or the
 * group's write layer, the box's text at every change, so キャンセル does not
 * take it back.  A lead byte waits for its trail before the name is set.
 * DDV_MaxChars is 250 (FUN_0055f5f0); the port counts bytes. */
static void ld_name_set(void)
{
    jw_group *gr;
    int off;

    if (!have_drawing || ends_in_lead(ld_edit, strlen(ld_edit)))
        return;
    off = jw_add_str_w(&drawing, ld_edit, drawing.version > 0x275);
    if (off < 0)
        return;
    gr = &drawing.group[ly_wg()];
    if (ld_caret == 1838)
        gr->name = off;
    else
        gr->layer_name[gr->write_layer & 15] = off;
}

static int ld_key(int c)
{
    if (!ld_caret)
        return 0;
    if (c == 8)
        text_back(ld_edit);
    else if (c >= 0x20 && c < 256)
        text_put(ld_edit, 251, &ld_drop, c);
    else
        return 0;
    ld_name_set();
    return 1;
}

/* ---------------------------------------- dialogs from the templates -----
 * A dialog nobody has read off the running original yet, put up from the
 * original's own template instead (src/gen/dlgtpl.h, src/ui.c's ui_tdlg).
 * What it holds is only what a dialog holds by itself: which checks and
 * radios are on, what has been typed into each edit box, and which one has
 * the caret.  OK, キャンセル and the × take it down; nothing it holds is
 * applied to the drawing yet -- what each of these dialogs does is still
 * to be read, one by one.
 *
 * The commands that put one up are the ones whose menu item did nothing at
 * all (tests/menusweep_test.exe --list).  Which template each one builds is
 * the original's own answer where it could be read: tools/cmddlg.py takes
 * the WM_COMMAND entries of its message maps out of orig/Jw_win.exe and
 * follows each handler in the decompilation to the CDialog constructor it
 * calls (FUN_00797f57 with the template's number) -- that is where
 * ツールバー (273), ファイル一括変換 (368) and the three file operations
 * (371, ファイル選択) come from.  バージョン情報 and ブロックツリー半透明化
 * are not found that way (MFC's own handler, and one too deep) and are
 * matched by the template's caption.
 */
#define TD_MAX 160
static int td_open, td_t = -1;
static unsigned char td_on[TD_MAX];
static char td_txt[TD_MAX][64];
static const char *td_txtp[TD_MAX];
static int td_drop[TD_MAX];
static int td_caret;                    /* the edit box being typed into */
static int td_tpl;                      /* the template it came from */
/* a combo's list, dropped: which control (-1 for none) and its rows */
#define TD_LIST 64
static char td_items[TD_LIST][64];
static const char *td_itemp[TD_LIST];
static int td_nitems, td_dl = -1;

static const struct { unsigned short cmd, tpl; } TD_CMD[] = {
    { 59392, 273 },     /* 表示 > ツールバー -- ツールバーの表示 */
    { 57664, 100 },     /* ヘルプ > バージョン情報 */
    /* ファイル操作 の 32977・32979・32980・32984 は表側の仕事（fo_command） */
};

/* src/fileops.h（この頁の終わりで読む）の窓 */
static int lyl_open;
static int lyl_ren;
static int lyl_start(int kind);
static int lyl_press(int x, int y, int button);
static void lyl_paint(void);
static void lyl_ren_close(int ok);
static int fo_info_clip(void);
static int fo_command(int cmd);

int app_tdlg_open(void)
{
    return td_open ? td_t : -1;
}

/* the template the dialog that is up came from, or 0 */
int app_tdlg_tpl(void)
{
    return td_open ? td_tpl : 0;
}

int app_tdlg_on(int i)
{
    return td_open && i >= 0 && i < TD_MAX ? td_on[i] : 0;
}

const char *app_tdlg_text(int i)
{
    if (!td_open || i < 0 || i >= TD_MAX)
        return "";
    return td_txtp[i] ? td_txtp[i] : td_txt[i];
}

static int td_start(int tpl)
{
    int t = ui_tdlg_find(tpl), i, n, group_has = 0;

    if (t < 0)
        return 0;
    n = ui_tdlg_n(t);
    if (n > TD_MAX)
        n = TD_MAX;
    memset(td_on, 0, sizeof td_on);
    memset(td_drop, 0, sizeof td_drop);
    td_caret = 0;
    for (i = 0; i < n; i++) {
        int id, kind, flags;

        td_txt[i][0] = 0;
        td_txtp[i] = 0;
        ui_tdlg_ctl(t, i, &id, &kind, &flags);
        if (flags & 4)
            group_has = 0;              /* WS_GROUP: a new run of radios */
        if (kind == UI_TC_RADIO && !group_has) {
            td_on[i] = 1;               /* the first of each run is on */
            group_has = 1;
        }
        if (kind == UI_TC_EDIT || kind == UI_TC_COMBO)
            td_txtp[i] = td_txt[i];
        if (kind == UI_TC_EDIT && !td_caret && !(flags & 2))
            td_caret = id;
    }
    td_t = t;
    td_tpl = tpl;
    td_open = 1;
    td_dl = -1;
    return 1;
}

static int td_caret_set(int id)
{
    td_caret = id;
    return 1;
}

/* 日影図 指定点の 初期Ｎｏ 設定（窓 348）: CHikageJikanDialog の DDX FUN_0054ff80 が 2523 に +0xa8（0x15b7
   「初期Ｎｏ 設定」）、2524 に +0xac（空）、箱 1411 に +0xb0（いまの番号）を入れる */
static void td_first_no(void)
{
    int i2523 = ui_tdlg_index(td_t, 2523), i2524 = ui_tdlg_index(td_t, 2524);
    int i1411 = ui_tdlg_index(td_t, 1411);

    if (i2523 >= 0 && i2523 < TD_MAX)
        td_txtp[i2523] = "\x8f\x89\x8a\xfa\x82m\x82\x8f \x90\xdd\x92\xe8";
    if (i2524 >= 0 && i2524 < TD_MAX)
        td_txtp[i2524] = "";
    if (i1411 >= 0 && i1411 < TD_MAX)
        snprintf(td_txt[i1411], sizeof td_txt[i1411], "%d", jw_cmd_hikage_first_no());
}

/* 文字集計設定 (351, CMojiSeiriDialog): 範囲選択の 文字位置･集計 の
   集計書込 (1121) が出す（FUN_005ca030）。値は jw_cmd_mp_sum_cfg、OK
   （FUN_0057d7b0）で書き戻して集計書込を入れる。逆コンパイルの読み、
   原典では押していない。OnInitDialog（FUN_0057d670）の 押せる・押せない の
   切り替えは入れていない */
static const int MS_RADIO[3] = { 1689, 1690, 1691 };

static void ms_text_set(int id, const char *t)
{
    int i = ui_tdlg_index(td_t, id);

    if (i >= 0 && i < TD_MAX)
        snprintf(td_txt[i], sizeof td_txt[i], "%s", t);
}

static void ms_tick(int id, int on)
{
    int i = ui_tdlg_index(td_t, id);

    if (i >= 0 && i < TD_MAX)
        td_on[i] = (unsigned char)(on != 0);
}

static int ms_ticked(int id)
{
    int i = ui_tdlg_index(td_t, id);

    return i >= 0 && i < TD_MAX && td_on[i];
}

static const char *ms_text(int id)
{
    int i = ui_tdlg_index(td_t, id);

    return i >= 0 && i < TD_MAX ? td_txt[i] : "";
}

static void ms_open(void)
{
    int shu, tab, sort, block, back, non, k;
    const char *pre, *post;
    char t[16];

    if (!td_start(351))
        return;
    jw_cmd_mp_sum_cfg(&shu, &tab, &sort, &block, &back, &non, &pre, &post);
    snprintf(t, sizeof t, "%d", shu);
    ms_text_set(1491, t);
    ms_text_set(1492, pre);
    ms_text_set(1493, post);
    ms_tick(2469, sort);
    ms_tick(2467, block);
    ms_tick(2468, back);
    ms_tick(1531, non);
    for (k = 0; k < 3; k++)
        ms_tick(MS_RADIO[k], k == tab);
    td_caret = 1491;
}

static void ms_close(int ok)
{
    int k, tab = -1;

    td_open = 0;
    if (!ok)
        return;
    for (k = 0; k < 3; k++)
        if (ms_ticked(MS_RADIO[k]))
            tab = k;
    jw_cmd_mp_sum_cfg_set((int)atof(ms_text(1491)), tab, ms_ticked(2469),
                          ms_ticked(2467), ms_ticked(2468), ms_ticked(1531),
                          ms_text(1492), ms_text(1493));
    jw_cmd_mp_sum_set(1);
}

/* 作図時間の窓 (348) を閉じる。OK なら 入れた時間で影を描く */
static int bt_alpha;
static void tr_close(int ok)
{
    int i = ui_tdlg_index(td_t, 1411);

    td_open = 0;
    if (ok && i >= 0 && i < TD_MAX) {
        int v = atoi(td_txt[i]);

        bt_alpha = v < 0 ? 0 : v > 255 ? 255 : v;
    }
}

/* 透過色 (391): three boxes for 赤 緑 青, 0 to 255.  OK puts the colour on
   the picture that was clicked; anything else leaves it. */
static void gp_close(int ok)
{
    int r = 0, g = 0, b = 0, i;

    if (ok) {
        i = ui_tdlg_index(td_t, 2579);
        if (i >= 0 && i < TD_MAX)
            r = atoi(td_txt[i]);
        i = ui_tdlg_index(td_t, 2580);
        if (i >= 0 && i < TD_MAX)
            g = atoi(td_txt[i]);
        i = ui_tdlg_index(td_t, 2581);
        if (i >= 0 && i < TD_MAX)
            b = atoi(td_txt[i]);
    }
    td_open = 0;
    if (ok && have_drawing)
        jw_cmd_gazou_tp_set(&drawing, r, g, b);
    else if (have_drawing)
        jw_cmd_gazou_tp_set(&drawing, -1, 0, 0);       /* cancelled */
}

static void tgp_tp_open(void)
{
    int r, g, b, i;

    if (!jw_cmd_gazou_tp_ask(&r, &g, &b) || !td_start(391))
        return;
    i = ui_tdlg_index(td_t, 2579);
    if (i >= 0 && i < TD_MAX)
        sprintf(td_txt[i], "%d", r);
    i = ui_tdlg_index(td_t, 2580);
    if (i >= 0 && i < TD_MAX)
        sprintf(td_txt[i], "%d", g);
    i = ui_tdlg_index(td_t, 2581);
    if (i >= 0 && i < TD_MAX)
        sprintf(td_txt[i], "%d", b);
    td_caret = 2579;
}

static void hk_time_close(int ok)
{
    int i = ui_tdlg_index(td_t, 1411);

    td_open = 0;
    if (ok && i >= 0 && i < TD_MAX)
        jw_cmd_hikage_answer(&drawing, hk_kind, td_txt[i]);
}

static int td_item_cmp(const void *a, const void *b)
{
    return strcmp(*(const char *const *)a, *(const char *const *)b);
}

/* What a combo lists, for the ones the port fills: ブロック名を指定して選択's
   name box has the drawing's blocks, sorted as its CBS_SORT keeps them and
   without the @@SfigorgFlag@@n on the end.  0 when it lists nothing. */
static int td_fill_list(int id)
{
    int i, k;

    td_nitems = 0;
    if (td_tpl != 340 || id != 2435 || !have_drawing)
        return 0;
    for (i = drawing.ndrawn; i < drawing.nobj && td_nitems < TD_LIST; i++) {
        const char *p, *q;
        size_t n;
        char *t = td_items[td_nitems];

        if (drawing.obj[i].cls != JW_LIST)
            continue;
        p = jw_str(&drawing, drawing.obj[i].text);
        q = strstr(p, "@@");
        n = q ? (size_t)(q - p) : strlen(p);
        if (n > sizeof td_items[0] - 1)
            n = sizeof td_items[0] - 1;
        memcpy(t, p, n);
        t[n] = 0;
        for (k = 0; k < td_nitems && strcmp(td_items[k], t); k++)
            ;
        if (k == td_nitems && n)
            td_itemp[td_nitems++] = t;
    }
    qsort(td_itemp, (size_t)td_nitems, sizeof td_itemp[0], td_item_cmp);
    return td_nitems;
}

/* ブロック名を指定して選択 (340) closing over 属性選択, as FUN_00609a10
   has it: OK keeps the name and ticks ブロック指定 (1802) as well, and
   anything else takes ブロック名指定 back off */
static void bn_close(int ok)
{
    int i = ui_tdlg_index(td_t, 2435);

    td_open = 0;
    if (!ok) {
        zsel_tick(2412, 0);
        jw_cmd_zokusel_name("");
        return;
    }
    jw_cmd_zokusel_name(i >= 0 && i < TD_MAX ? td_txt[i] : "");
    zsel_tick(1802, 1);
}

/* 作図属性設定 (342): its four 書込み ticks are 複写・移動's (src/cmd.c's
   za_on), the others are kept here from one opening to the next and do
   nothing yet -- except 2556 マウス倍率のときXY等倍, which 複写の ﾏｳｽ倍率
   reads (jw_cmd_fk_xy1_set) */
static const short ZA_ID[4] = { 1324, 1323, 1325, 1326 };
static const short ZA_KEEP_ID[5] = { 1322, 2114, 1328, 2250, 2556 };
static unsigned char za_keep[5];
/* 1 なら 図形読込の 作図属性 (1067) として開いている（jw_cmd_fzoku）。原典は
   1325・1326 の字を「◆元レイヤに作図」「◆元ｸﾞﾙｰﾌﾟに作図」に替えて印を
   逆向きに持つ（FUN_004ae8d0）が、移植の窓は字を替えられないので 複写 の字の
   まま同じ三通り（書込レイヤ／書込グループで元レイヤ／元グループ）を持つ */
static int za_fig;

static void za_tick(int id, int on)
{
    int i = ui_tdlg_index(td_t, id);

    if (i >= 0 && i < TD_MAX)
        td_on[i] = (unsigned char)(on != 0);
}

static int za_ticked(int id)
{
    int i = ui_tdlg_index(td_t, id);

    return i >= 0 && i < TD_MAX && td_on[i];
}

static void za_open(void)
{
    int k;

    if (!td_start(342))
        return;
    za_fig = 0;
    for (k = 0; k < 4; k++)
        za_tick(ZA_ID[k], jw_cmd_zuzoku(k));
    for (k = 0; k < 5; k++)
        za_tick(ZA_KEEP_ID[k], za_keep[k]);
}

static void fz_open(void)
{
    int k;

    if (!td_start(342))
        return;
    za_fig = 1;
    za_tick(1324, jw_cmd_fzoku(0));
    za_tick(1323, jw_cmd_fzoku(1));
    za_tick(1325, jw_cmd_fzoku(2));
    za_tick(1326, jw_cmd_fzoku(3) && !jw_cmd_fzoku(2));
    for (k = 0; k < 5; k++)
        za_tick(ZA_KEEP_ID[k], za_keep[k]);
}

static void za_save(void)
{
    int k;

    if (za_fig) {
        jw_cmd_fzoku_set(0, za_ticked(1324));
        jw_cmd_fzoku_set(1, za_ticked(1323));
        jw_cmd_fzoku_set(3, za_ticked(1325) || za_ticked(1326));
        jw_cmd_fzoku_set(2, za_ticked(1325));
        for (k = 0; k < 5; k++)
            za_keep[k] = (unsigned char)za_ticked(ZA_KEEP_ID[k]);
        jw_cmd_fk_xy1_set(za_keep[4]);  /* 2556 は 複写の ﾏｳｽ倍率 も見る */
        return;
    }
    for (k = 0; k < 4; k++)
        jw_cmd_zuzoku_set(k, za_ticked(ZA_ID[k]));
    for (k = 0; k < 5; k++)
        za_keep[k] = (unsigned char)za_ticked(ZA_KEEP_ID[k]);
    jw_cmd_fk_xy1_set(za_keep[4]);      /* 2556 マウス倍率のときXY等倍（DAT_00a0cb2c） */
}

/* the dialog's own answers (FUN_004aec10, 004aec70, 004aecb0):
   ◇元レイヤ・元線色・元線種 takes the four off and closes as OK does, and
   書込み【レイヤ】 and 書込みレイヤグループ each take the other off */
static int za_press(int id)
{
    int k;

    if (id == 1)
        za_save();
    if (id == 1064) {
        for (k = 0; k < 4; k++)
            za_tick(ZA_ID[k], 0);
        if (za_fig)             /* 図形では「◆書込レイヤ、元線色、元線種」(0x182c) */
            za_tick(1325, 1);
        za_save();
        td_open = 0;
        return 1;
    }
    return 0;
}

static void za_after(int id)
{
    if (id == 1325 && za_ticked(1325))
        za_tick(1326, 0);
    if (id == 1326 && za_ticked(1326))
        za_tick(1325, 0);
}

static int press_tdlg(int x, int y)
{
    int id, i, k, n, kind, flags;

    if (td_dl >= 0) {                   /* a list is down: it takes the press */
        int row = ui_tdlg_drop_hit(fb.w, fb.h, td_t, td_dl, td_nitems, x, y);

        if (row >= 0) {
            strncpy(td_txt[td_dl], td_itemp[row], sizeof td_txt[0] - 1);
            td_txt[td_dl][sizeof td_txt[0] - 1] = 0;
            td_drop[td_dl] = 0;
        }
        td_dl = -1;
        return 1;
    }
    id = ui_tdlg_hit(fb.w, fb.h, td_t, x, y);
    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (td_tpl == 342 && za_press(id))
        return 1;
    if (td_tpl == 373 && lyl_ren >= 0 && (id == 1 || id == 2)) {
        lyl_ren_close(id == 1);         /* レイヤ一覧 の名前 */
        return 1;
    }
    if (td_tpl == 340 && (id == 1 || id == 2)) {
        bn_close(id == 1);
        return 1;
    }
    if (td_tpl == 348 && (id == 1 || id == 2)) {
        hk_time_close(id == 1);
        return 1;
    }
    if (td_tpl == 391 && (id == 1 || id == 2)) {
        gp_close(id == 1);
        return 1;
    }
    if (td_tpl == 384 && (id == 1 || id == 2)) {
        tr_close(id == 1);
        return 1;
    }
    if (td_tpl == 351 && (id == 1 || id == 2)) {
        ms_close(id == 1);
        return 1;
    }
    if (id == 1 || id == 2) {           /* OK, キャンセル, the × */
        td_open = 0;
        return 1;
    }
    i = ui_tdlg_index(td_t, id);
    if (i < 0 || i >= TD_MAX || !ui_tdlg_ctl(td_t, i, 0, &kind, &flags))
        return 1;
    if (kind == UI_TC_CHECK) {
        td_on[i] = (unsigned char)!td_on[i];
        if (td_tpl == 342)
            za_after(id);
    } else if (kind == UI_TC_RADIO) {
        /* the run it is in: back to the control that starts the group,
           on to the next one that starts another */
        int a = i, b = i, f;

        n = ui_tdlg_n(td_t);
        while (a > 0 && ui_tdlg_ctl(td_t, a, 0, 0, &f) && !(f & 4))
            a--;
        while (b + 1 < n && ui_tdlg_ctl(td_t, b + 1, 0, 0, &f) && !(f & 4))
            b++;
        for (k = a; k <= b && k < TD_MAX; k++) {
            int kk;

            if (ui_tdlg_ctl(td_t, k, 0, &kk, 0) && kk == UI_TC_RADIO)
                td_on[k] = 0;
        }
        td_on[i] = 1;
    } else if (kind == UI_TC_EDIT)
        td_caret = id;
    else if (kind == UI_TC_COMBO && td_fill_list(id))
        td_dl = i;
    return 1;
}

/* ---------------------------------------------------- 数値入力 (314) -----
 * A right press on one of a command bar's boxes puts up the original's table
 * of numbers: CMy02ComboBox and its kin answer WM_RBUTTONUP by building
 * template 314 (FUN_00589e20 and three others like it), handing it what the
 * box holds, and writing back what it says when it closes with OK.  None of
 * this has been asked of the original -- it is the decompilation's reading
 * (FUN_005d7cb0, FUN_005d87c0, FUN_005d5300, FUN_005d8140), so it is the
 * table's sums, not its looks under use, that the port has from it.
 *
 * Each column holds one digit of its own place (00,000 is the ten
 * thousands, 0.00 the hundredths) and the number is their sum: pressing 3
 * in the 000 column and then 5 in it again makes 500, not 800.  A right
 * press on a digit puts it in and closes the table with OK, as the
 * original's CMy3Button does (it reports a right release as 2, and 2 is
 * OnOK).  「，」 moves on to a second number, for the boxes that take two
 * ("横,縦"), and back.  The calculator underneath, the °′″ row and the
 * arrows are drawn but do nothing yet -- coming from a box, the original
 * hides the °′″ row and the arrows anyway.
 */
static int kp_box;              /* the bar's box it writes back to */
static double kp_v[2];          /* the two numbers (+0xc8, +0xd0) */
static double kp_sign[2];       /* their signs (+0xe0, +0xe8) */
static double kp_place[7];      /* one digit's worth per column */
static double kp_keep;          /* the second number, put by (+0xd8) */
static int kp_which;            /* 0 the first number, 1 the second */
static int kp_raw[2];           /* untouched since it came in (+0xbc/+0xc0) */
static int kp_two;              /* the box had two numbers in it */
static int kp_shown2;           /* the second number has been shown */
static char kp_txt[3][32];
/* 電卓 (the lower half, FUN_005d5fe0 / 005d57e0 / 005d5bb0 and the buttons'
   handlers 0x005d6d90 .. 0x005d7890).  kp_acc is the dialog's +0x158: the
   number the table above last made and the calculator's running result, shown
   in 1770; the entry being typed is +0x16c (1772); the operator waiting is
   +0x7c4 (1771: ＋ － × ÷ ＾ √ atan cos sin, "E" when a sum cannot be done). */
static double kp_acc;
static char kc_s[20];                   /* the entry as typed, 15 at most */
static int kc_len, kc_dot, kc_minus, kc_op;
static double kc_v;                     /* and its value (+0x160) */
static char kc_acc_txt[32];
static const char *kc_op_txt = " ";

/* The column and the digit a button stands for: columns from 0 (0.0x) to 6
   (x0,000), as FUN_005d7cb0 has them; -1 if it is not one of them. */
static int kp_digit(int id, int *d)
{
    static const short first[7] = { 1176, 1175, 1152, 1162, 1177, 1178,
                                    1179 };
    static const short rest[7] = { 1189, 1180, 0, 0, 1198, 1207, 1216 };
    int g;

    for (g = 0; g < 7; g++) {
        if (id == first[g]) {
            *d = 0;
            return g;
        }
        if (!rest[g] && id > first[g] && id <= first[g] + 9) {
            *d = id - first[g];
            return g;
        }
        if (rest[g] && id >= rest[g] && id < rest[g] + 9) {
            *d = id - rest[g] + 1;
            return g;
        }
    }
    return -1;
}

/* FUN_005d8730: ten figures, and %lg below a thousandth */
static void kp_fmt(char *out, size_t n, double v)
{
    snprintf(out, n, (v < 0 ? -v : v) >= 0.001 ? "%.10g" : "%g", v);
}

static void kp_set(int id, int bits, const char *txt)
{
    int i = ui_tdlg_index(td_t, id);

    if (i < 0 || i >= TD_MAX)
        return;
    td_on[i] = (unsigned char)bits;
    if (txt)
        td_txtp[i] = txt;
}

/* what is shown and what is greyed, FUN_005d5300 the way a box opens it */
static void kp_show(void)
{
    static const short hide[] = { 2076, 2077, 2078, 2079, 1767, 1225, 1768,
                                  1226, 1769, 1227, 2075 };
    int k;

    for (k = 0; k < (int)(sizeof hide / sizeof hide[0]); k++)
        kp_set(hide[k], UI_TD_HIDE, 0);
    kp_fmt(kp_txt[0], sizeof kp_txt[0], kp_v[0]);
    kp_fmt(kp_txt[1], sizeof kp_txt[1], kp_v[1]);
    kp_fmt(kp_txt[2], sizeof kp_txt[2], kp_v[kp_which]);
    kp_set(1764, kp_which ? UI_TD_GREY : 0, kp_txt[0]);
    kp_set(1172, kp_which ? UI_TD_GREY : 0, 0);
    kp_set(1173, kp_which ? 0 : UI_TD_GREY, 0);
    kp_set(1765, kp_which ? 0 : UI_TD_GREY, kp_shown2 ? kp_txt[1] : 0);
    kp_fmt(kc_acc_txt, sizeof kc_acc_txt, kp_acc);
    kp_set(1770, 0, kc_acc_txt);
    kp_set(1771, 0, kc_op_txt);
    kp_set(1772, 0, kc_len ? kc_s : "0");
}

/* FUN_005d7160 (Ｃ): the entry goes back to nothing */
static void kc_clear(void)
{
    kc_len = kc_dot = kc_minus = 0;
    kc_s[0] = 0;
    kc_v = 0.0;
}

/* FUN_005d5bb0: the operator's mark */
static void kc_mark(void)
{
    static const char *const mark[10] = {
        " ", "\x81\x7b", "\x81\x7c", "\x81\x7e", "\x81\x80",      /* ＋ － × ÷ */
        "atan", "cos", "sin", "\x81\xe3", "\x81\x4f"                 /* √ ＾ */
    };

    kc_op_txt = kc_op >= 0 && kc_op < 10 ? mark[kc_op] : " ";
}

/* FUN_005d5fe0: one key of the entry -- a digit, '.' or '-' */
static void kc_key(int c)
{
    if (kc_len > 14)
        return;
    if (c == '0' && fabs(kc_v) < 1e-7 && !kc_dot
        && !(kc_len == 1 && kc_s[0] == '-'))
        return;                         /* no run of leading zeros */
    if (c == '.') {
        if (kc_dot)
            return;
        kc_dot = 1;
        if (kc_len == 0) {
            strcpy(kc_s, "0.");
            kc_len = 2;
            goto parse;
        }
        if (kc_len == 1 && kc_s[0] == '-') {
            strcpy(kc_s, "-0.");
            kc_len = 3;
            goto parse;
        }
    }
    if (c == '-') {
        if (kc_minus)
            return;
        kc_minus = 1;
        if (kc_len != 0)
            return;
        strcpy(kc_s, "-");
        kc_len = 1;
    } else {
        kc_s[kc_len++] = (char)c;
        kc_s[kc_len] = 0;
    }
parse:
    kc_v = atof(kc_s);
}

/* FUN_005d57e0: do the operator waiting with the entry.  0 when it cannot be
   done (÷ 0, a power out of reach), which leaves "E" showing */
static int kc_do(void)
{
    int bad = 0;

    if (kc_op == 0) {
        if (fabs(kc_v) < 1e-7)
            goto done;
        kp_acc = kc_v;
    }
    if (kc_op == 1)
        kp_acc += kc_v;
    if (kc_op == 2)
        kp_acc -= kc_v;
    if (kc_op == 3)
        kp_acc *= kc_v;
    if (kc_op == 4) {
        if (fabs(kc_v) < 1e-7) {
            bad = 1;
            goto done;
        }
        kp_acc /= kc_v;
    }
    if (kc_op == 9) {
        if ((kp_acc >= 0.0 || kc_v == (double)(int)kc_v) && (kc_v != 0.0 || kp_acc > 0.0)) {
            double r = pow(kp_acc, kc_v);

            if (r <= 1e20)
                kp_acc = r;
            else
                bad = 1;
        } else
            bad = 1;
    }
done:
    kc_clear();
    kc_op = 0;
    kc_op_txt = bad ? "E" : " ";
    return !bad;
}

/* FUN_005d5e40 (＝): the sum is done and becomes the number above */
static void kc_equals(void)
{
    if (!kc_do())
        return;
    kp_v[kp_which] = kp_acc;
    memset(kp_place, 0, sizeof kp_place);
    kp_raw[0] = kp_raw[1] = 1;
    if (kp_which)
        kp_shown2 = 1;
}

/* atan, cos, sin and √ (FUN_005d6f80, 005d7200, 005d76a0, 005d74c0): the
   operator waiting first, then the function of the result, then ＝ */
static void kc_func(int f)
{
    int bad = 0;

    if (kc_op == 0) {
        if (fabs(kc_v) > 1e-7)
            kp_acc = kc_v;
    } else if (!kc_do())
        return;
    kc_clear();
    kc_op = 0;
    kc_mark();
    if (f == 5)
        kp_acc = atan2(kp_acc, 1.0) * 180.0 / 3.141592653589793;
    else if (f == 6)
        kp_acc = cos(kp_acc * 3.141592653589793 / 180.0);
    else if (f == 7)
        kp_acc = sin(kp_acc * 3.141592653589793 / 180.0);
    else if (kp_acc >= 0.0)
        kp_acc = sqrt(kp_acc);
    else {
        kp_acc = 0.0;
        bad = 1;
    }
    kc_equals();
    if (bad)
        kc_op_txt = "E";
}

/* the calculator's buttons; 1 if it was one of them */
static int kc_press(int id)
{
    if (id >= 1440 && id <= 1449) {
        kc_key('0' + id - 1440);
        return 1;
    }
    switch (id) {
    case 1450: kc_key('.'); return 1;
    case 1464: kc_key('-'); return 1;
    case 1455: case 1454: case 1453: case 1452: case 1458: {   /* ＋ － × ÷ ＾ */
        int op = id == 1455 ? 1 : id == 1454 ? 2 : id == 1453 ? 3 : id == 1452 ? 4 : 9;

        if (fabs(kc_v) <= 1e-7 || kc_do()) {
            kc_op = op;
            kc_mark();
        }
        return 1;
    }
    case 1451: kc_equals(); return 1;                          /* ＝ */
    case 1459: kc_func(5); return 1;                           /* atan */
    case 1461: kc_func(6); return 1;                           /* cos */
    case 1462: kc_func(7); return 1;                           /* sin */
    case 1456: kc_func(8); return 1;                           /* √ */
    case 1463: kp_acc = -kp_acc; return 1;                     /* ± */
    case 1457: kc_clear(); return 1;                           /* Ｃ */
    case 1460:                                                 /* ＡＣ */
        kp_acc = 0.0;
        kc_op = 0;
        kc_mark();
        kc_clear();
        return 1;
    }
    return 0;
}

static void kp_sum(void)
{
    double s = 0.0;
    int g;

    for (g = 0; g < 7; g++)
        s += kp_place[g];
    kp_raw[kp_which] = 0;
    kp_v[kp_which] = kp_sign[kp_which] * s;
    kp_acc = kp_v[kp_which];            /* FUN_005d87c0 leaves it in +0x158 */
}

static int kp_start(int box)
{
    const char *t = jw_cmd_box_raw(box), *p;

    if (!t || !td_start(314))
        return 0;
    kp_box = box;
    kp_v[0] = atof(t);
    p = strchr(t, ',');
    kp_two = p != 0;
    /* FUN_005899b0: the second number is the first again when the box
       holds only one */
    kp_v[1] = kp_keep = p ? atof(p + 1) : kp_v[0];
    kp_sign[0] = kp_sign[1] = 1.0;
    memset(kp_place, 0, sizeof kp_place);
    kp_which = 0;
    kp_raw[0] = kp_raw[1] = 1;
    kp_shown2 = 0;
    kp_acc = 0.0;
    kc_clear();
    kc_op = 0;
    kc_mark();
    kp_show();
    return 1;
}

/* OK: back into the box, two numbers the way FUN_0058ae50 writes them */
static void kp_ok(void)
{
    char a[32], b[32], out[72];

    kp_fmt(a, sizeof a, kp_v[0]);
    if (kp_two || kp_shown2) {
        kp_fmt(b, sizeof b, kp_v[1]);
        snprintf(out, sizeof out, "%s , %s", a, b);
    } else
        snprintf(out, sizeof out, "%s", a);
    jw_cmd_box_put(kp_box, out);
    td_open = 0;
}

static int press_kp(int x, int y, int button)
{
    int id = ui_tdlg_hit(fb.w, fb.h, td_t, x, y), i, g, d;

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 2) {                      /* the × */
        td_open = 0;
        return 1;
    }
    i = ui_tdlg_index(td_t, id);
    if (i >= 0 && i < TD_MAX && (td_on[i] & (UI_TD_HIDE | UI_TD_GREY)))
        return 1;
    if (id == 1) {
        kp_ok();
        return 1;
    }
    if ((g = kp_digit(id, &d)) >= 0) {
        static const double place[7] = { 0.01, 0.1, 1, 10, 100, 1000,
                                         10000 };

        kp_place[g] = d * place[g];
        kp_sum();
        kp_show();
        if (button == 1)
            kp_ok();
        return 1;
    }
    switch (id) {
    case 1172:                          /* the first number's ± */
        if (kp_which || kp_raw[0])
            kp_v[0] = -kp_v[0];
        else {
            kp_sign[0] = -kp_sign[0];
            kp_sum();
        }
        break;
    case 1173:                          /* the second's */
        if (kp_raw[1])
            kp_v[1] = -kp_v[1];
        else {
            kp_sign[1] = -kp_sign[1];
            kp_sum();
        }
        break;
    case 1174:                          /* 「，」: over to the other number */
        if (!kp_which) {
            kp_which = 1;
            kp_v[1] = kp_keep;
            kp_shown2 = 1;
        } else {
            kp_which = 0;
            kp_keep = kp_v[1];
        }
        kp_acc = kp_v[kp_which];        /* FUN_005d8140 puts it in +0x158 */
        memset(kp_place, 0, sizeof kp_place);
        break;
    default:
        if (!kc_press(id))
            return 1;
        if (id == 1451 && button == 1)  /* ＝ is a CMy3Button too: a right press is OK */
            kp_ok();
        break;
    }
    kp_show();
    return 1;
}

static int td_key(int c)
{
    int i = ui_tdlg_index(td_t, td_caret);

    td_dl = -1;                         /* a key puts the list away */
    if (c == 13 && td_tpl == 342)       /* Enter is OK */
        za_save();
    if ((c == 13 || c == 27) && td_tpl == 340) {
        bn_close(c == 13);
        return 1;
    }
    if ((c == 13 || c == 27) && td_tpl == 348) {
        hk_time_close(c == 13);
        return 1;
    }
    if ((c == 13 || c == 27) && td_tpl == 391) {
        gp_close(c == 13);
        return 1;
    }
    if ((c == 13 || c == 27) && td_tpl == 384) {
        tr_close(c == 13);
        return 1;
    }
    if ((c == 13 || c == 27) && td_tpl == 351) {
        ms_close(c == 13);
        return 1;
    }
    if ((c == 13 || c == 27) && td_tpl == 373 && lyl_ren >= 0) {
        lyl_ren_close(c == 13);
        return 1;
    }
    if (c == 13 && td_tpl == 314) {     /* 数値入力's OK writes back */
        kp_ok();
        return 1;
    }
    if (c == 27 || c == 13) {           /* Esc, and Enter for OK */
        td_open = 0;
        return 1;
    }
    if (i < 0 || i >= TD_MAX)
        return 1;
    if (c == 8) {
        text_back(td_txt[i]);
        td_drop[i] = 0;
        return 1;
    }
    if (c >= 0x20 && c < 256)
        text_put(td_txt[i], sizeof td_txt[i], &td_drop[i], c);
    return 1;
}

/* One key while the ブロック編集 dialog is up: the name box takes it. */
static int be_key(int c)
{
    if (c == 8) {
        text_back(be_name);
        be_drop = 0;
        return 1;
    }
    if (c == 13) {                      /* Enter is the OK button */
        if (have_drawing && !be_all)
            jw_cmd_block_split(&drawing);
        be_open = 0;
        return 1;
    }
    if (c >= 0x20 && c < 256) {
        text_put(be_name, sizeof be_name, &be_drop, c);
        return 1;
    }
    return 0;
}
static char blk_name[64];

int app_blkname_open(void)
{
    return blk_open;
}

const char *app_blkname(void)
{
    return blk_name;
}

static void bt_rename_ok(void);

static int press_blkname(int x, int y)
{
    int id = ui_blkname_hit(fb.w, fb.h, x, y);

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* OK */
        if (blk_attr == 2)
            bt_rename_ok();             /* ブロックツリー's ブロック名変更 */
        else if (have_drawing && blk_attr)
            jw_cmd_block_attr(&drawing, blk_pref);
        else if (have_drawing && blk_name[0])
            jw_cmd_block_make(&drawing, blk_name, blk_pref);
        blk_open = 0;
    } else if (id == 2) {               /* キャンセル */
        blk_open = 0;
    } else if (id == 1323) {
        blk_pref = !blk_pref;
    }
    return 1;
}

/* One key while the dialog is up: the name takes anything printable. */

static int blk_key(int c)
{
    size_t n = strlen(blk_name);

    if (c == 8) {
        text_back(blk_name);
        blk_drop = 0;
        return 1;
    }
    if (c == 13) {                      /* Enter is the OK button */
        if (blk_attr == 2)
            bt_rename_ok();
        else if (have_drawing && blk_attr)
            jw_cmd_block_attr(&drawing, blk_pref);
        else if (have_drawing && blk_name[0])
            jw_cmd_block_make(&drawing, blk_name, blk_pref);
        blk_open = 0;
        return 1;
    }
    if (blk_attr == 1)                  /* the box is greyed out there */
        return 0;
    (void)n;
    if (c >= 0x20 && c < 256) {
        text_put(blk_name, sizeof blk_name, &blk_drop, c);
        return 1;
    }
    return 0;
}

/* ------------------------------------------------------ ブロックツリー ---
 * 表示 > ブロックツリー (32988).  The original enters 範囲選択 (the command
 * set puts the tree away, so it goes first) and then raises DIALOG 355, which
 * stays up beside the drawing -- it is not modal, so the drawing and the
 * menus work with it up.  What puts it away again is anything that sets a
 * command and any press in the drawing area (probed with tools/jwdraw.ps1:
 * `cmd:32787`, a click in the view, and `cmd:32771` all took it down; a
 * command that only acts, like ブロック解除, left it alone).
 *
 * What it shows is in src/cmd.c (jw_bt_kids).  Picking a row picks the block
 * in the drawing the way a range does -- it is drawn in the picked colour --
 * but it is not a selection in the drawing's sense: the toolbar does not
 * change and ブロック解除 with only the tree's pick does nothing.  So the
 * pick is drawn by src/draw.c's jw_draw_hl and is kept here.
 *
 *   同名BLK全検索   every block (at any depth) with the name of the picked one
 *                   goes bold, its ancestors open, the last one found is
 *                   picked, and the line at the foot says 同名ブロック数 = n
 *   選択BLK編集     ブロック編集 on the picked block, with 選択したブロックのみ
 *                   as the check box says; the tree goes away
 *   BLK名変更       asks for a name (編集後のブロック名を入力してください), gives
 *                   it to the block's definition and ends the edit; the
 *                   tree is made again with the new name found
 *
 * Both of the last two are greyed until a block (not the root) is picked.
 */
#define BT_MAXD 8
#define BT_MAXROW 600
#define BT_MARKS 128

typedef struct { int n; int p[BT_MAXD]; } bt_path_t;

/* ダイアログボックスの表示位置を初期状態にします。 / よろしいですか？ */
#define MB_TEXT "\x83_\x83" "C\x83" "A\x83\x8d\x83O\x83{\x83" "b\x83N\x83X\x82\xcc\x95\x5c\x8e\xa6\x88\xca\x92u\x82\xf0\x8f\x89\x8a\xfa\x8f\xf3\x91\xd4\x82\xc9\x82\xb5\x82\xdc\x82\xb7\x81" "B\n\x82\xe6\x82\xeb\x82\xb5\x82\xa2\x82\xc5\x82\xb7\x82\xa9\x81H"
/* 表示 > ブロックツリー半透明化: the window shows through (see bt_paint) */
static int bt_trans;
/* 表示 > Direct2D and ANTIALIAS: only their state is kept.  The port draws
   the one way, the GDI way the original's reference pictures were taken
   in; Direct2D is the original's other renderer, a Windows facility. */
static int d2d_on, aa_on;
/* 表示 > ダイアログボックス: the original asks first (AfxMessageBox) */
static int mb_open;
/* 0: the dialog-position question above; 3: 天空図の 真北が無いときの問い;
   1 and 2: 画像編集's (OK and キャンセル,
   OK alone), whose words are mb_text */
static int mb_kind;
static char mb_text[400];
static char tag_name[260];

static int bt_open;
static rect_t bt_win;
static bt_path_t bt_sel;                /* n 0: the root */
static int bt_all;                      /* 選択したブロックのみに… */
static int bt_scroll;
static int bt_found = -1;               /* the count under 同名ブロック数 */
static bt_path_t bt_exp[BT_MARKS];
static int bt_nexp;
static bt_path_t bt_bold[BT_MARKS];
static int bt_nbold;
static int bt_menu_x = -1, bt_menu_y;   /* the right press's pop-up */
static unsigned bt_sig;
static ui_btrow_t bt_row[BT_MAXROW];
static bt_path_t bt_rpath[BT_MAXROW];
static int bt_nrow;
static bt_path_t bt_ren;                /* the block BLK名変更 is asking about */

static int bt_same(const bt_path_t *a, const bt_path_t *b)
{
    int i;

    if (a->n != b->n)
        return 0;
    for (i = 0; i < a->n; i++)
        if (a->p[i] != b->p[i])
            return 0;
    return 1;
}

static int bt_find(const bt_path_t *list, int n, const bt_path_t *p)
{
    int i;

    for (i = 0; i < n; i++)
        if (bt_same(&list[i], p))
            return i;
    return -1;
}

/* What the tree depends on in the drawing: if any of it changes the paths
   mean something else, and the tree is made again from the root. */
static unsigned bt_signature(void)
{
    unsigned h = 2166136261u;
    int i;

    if (!have_drawing)
        return 0;
    h = (h ^ (unsigned)drawing.ndrawn) * 16777619u;
    h = (h ^ (unsigned)drawing.nobj) * 16777619u;
    for (i = 0; i < drawing.nobj; i++) {
        const jw_obj *o = &drawing.obj[i];

        if (o->cls != JW_BLOCK && o->cls != JW_LIST)
            continue;
        h = (h ^ (unsigned)i) * 16777619u;
        h = (h ^ (unsigned)o->cls) * 16777619u;
        h = (h ^ (unsigned)(o->cls == JW_BLOCK ? o->block : o->list[0]))
            * 16777619u;
        h = (h ^ (unsigned)(o->cls == JW_LIST ? o->text + o->n * 7 : 0))
            * 16777619u;
        h = (h ^ (unsigned)(o->flags & 1)) * 16777619u;
    }
    return h;
}

static void bt_reset(void)
{
    bt_sel.n = 0;
    bt_nexp = 0;
    bt_nbold = 0;
    bt_found = -1;
    bt_scroll = 0;
    bt_menu_x = -1;
}

/* Rows from the node `p` down.  `line` has a bit set for each ancestor
   that has siblings still to come. */
static void bt_walk(const bt_path_t *p, int depth, unsigned line)
{
    int kids[BT_MAXROW > 400 ? 400 : BT_MAXROW], nk, k;

    nk = jw_bt_kids(&drawing, p->n ? p->p[p->n - 1] : -1, kids,
                    (int)(sizeof kids / sizeof kids[0]));
    for (k = 0; k < nk && bt_nrow < BT_MAXROW; k++) {
        bt_path_t c = *p;
        ui_btrow_t *r = &bt_row[bt_nrow];
        int kk, open;

        if (c.n >= BT_MAXD)
            break;
        c.p[c.n++] = kids[k];
        kk = jw_bt_has_kids(&drawing, kids[k]);
        open = kk && bt_find(bt_exp, bt_nexp, &c) >= 0;
        memset(r, 0, sizeof *r);
        strncpy(r->text, jw_bt_name(&drawing, kids[k]), sizeof r->text - 1);
        r->depth = (short)depth;
        r->kids = (unsigned char)kk;
        r->open = (unsigned char)open;
        r->sel = (unsigned char)bt_same(&c, &bt_sel);
        r->bold = bt_find(bt_bold, bt_nbold, &c) >= 0;
        r->last = k == nk - 1;
        r->line = line;
        bt_rpath[bt_nrow++] = c;
        if (open)
            bt_walk(&c, depth + 1, line | (k < nk - 1 ? 1u << depth : 0u));
    }
}

static void bt_build(void)
{
    bt_path_t root;
    ui_btrow_t *r = &bt_row[0];
    int one[1];

    root.n = 0;
    bt_nrow = 0;
    memset(r, 0, sizeof *r);
    r->text[0] = 0;                     /* the root has no name */
    r->kids = jw_bt_kids(&drawing, -1, one, 1) > 0;
    r->open = 1;
    r->sel = bt_sel.n == 0;
    r->last = 1;
    bt_rpath[0] = root;
    bt_nrow = 1;
    bt_walk(&root, 1, 0);
}

/* what the window draws must be what the drawing holds */
static void bt_refresh(void)
{
    unsigned sig;

    if (!bt_open)
        return;
    sig = bt_signature();
    if (sig != bt_sig) {
        bt_reset();
        bt_sig = sig;
    }
    bt_build();
    if (bt_scroll > bt_nrow - 1)
        bt_scroll = bt_nrow - 1;
    if (bt_scroll < 0)
        bt_scroll = 0;
}

/* the pick, drawn in the picked colour */
static void bt_hl(void)
{
    if (bt_open && have_drawing && bt_sel.n > 0)
        jw_draw_hl(&drawing, bt_sel.p, bt_sel.n);
    else
        jw_draw_hl(&drawing, 0, 0);
}

static void bt_close(void)
{
    if (!bt_open)
        return;
    bt_open = 0;
    bt_menu_x = -1;
    jw_draw_hl(&drawing, 0, 0);
}

int app_blktree_open(void)
{
    return bt_open;
}

/* the rows as the window shows them (tests/btree_test.c reads them), and
   where the window is */
int app_blktree_n(void)
{
    bt_refresh();
    return bt_open ? bt_nrow : 0;
}

const ui_btrow_t *app_blktree_row(int i)
{
    bt_refresh();
    return bt_open && i >= 0 && i < bt_nrow ? &bt_row[i] : 0;
}

void app_blktree_win(rect_t *r)
{
    *r = bt_win;
}

int app_blktree_found(void)
{
    return bt_found;
}

int app_blktree_all(void)
{
    return bt_all;
}

static unsigned int *bt_tmp;
static size_t bt_tmpcap;

/* The window and what it carries.  With 半透明化 on it is made in a picture
   of its own first and laid over the drawing: at 透過率 0 the white of it is
   the colour that is not painted (SetLayeredWindowAttributes with a colour
   key, FUN_00416f00), and at 1..255 the whole of it is blended in. */
static void bt_paint(void)
{
    char msg[64];
    fb_t t;
    rect_t w0;
    int x, y;

    msg[0] = 0;
    if (bt_found > 0)
        sprintf(msg, "%s%d", "\x93\xaf\x96\xbc\x83u\x83\x8d\x83" "b\x83N\x90\x94 = ", bt_found);
    if (!bt_trans) {
        ui_blktree(&fb, &bt_win, bt_row, bt_nrow, bt_scroll, bt_all,
                   bt_sel.n > 0, msg, bt_menu_x, bt_menu_y);
        return;
    }
    t.w = bt_win.w;
    t.h = bt_win.h;
    if ((size_t)t.w * t.h > bt_tmpcap) {
        unsigned int *p = (unsigned int *)realloc(bt_tmp,
                                (size_t)t.w * t.h * sizeof *p);

        if (!p)
            return;
        bt_tmp = p;
        bt_tmpcap = (size_t)t.w * t.h;
    }
    t.px = bt_tmp;
    memset(bt_tmp, 0xff, (size_t)t.w * t.h * sizeof *bt_tmp);
    w0.x = w0.y = 0;
    w0.w = t.w;
    w0.h = t.h;
    ui_blktree(&t, &w0, bt_row, bt_nrow, bt_scroll, bt_all, bt_sel.n > 0, msg,
               -1, -1);
    for (y = 0; y < t.h; y++)
        for (x = 0; x < t.w; x++) {
            int fx = bt_win.x + x, fy = bt_win.y + y;
            unsigned int c = bt_tmp[(size_t)y * t.w + x], *d;

            if (fx < 0 || fy < 0 || fx >= fb.w || fy >= fb.h)
                continue;
            d = &fb.px[(size_t)fy * fb.w + fx];
            if (bt_alpha == 0) {
                if (c != 0xffffffu)
                    *d = c;
            } else {
                unsigned int a = (unsigned int)bt_alpha, r, g, b;

                r = (((c >> 16) & 255) * a + ((*d >> 16) & 255) * (255 - a)) / 255;
                g = (((c >> 8) & 255) * a + ((*d >> 8) & 255) * (255 - a)) / 255;
                b = ((c & 255) * a + (*d & 255) * (255 - a)) / 255;
                *d = (r << 16) | (g << 8) | b;
            }
        }
    if (bt_menu_x >= 0)
        ui_blktree_menu(&fb, bt_menu_x, bt_menu_y);
}

static void bt_start(void)
{
    if (!have_drawing)
        return;
    /* the command first, which puts away a tree that is already up */
    jw_cmd_flush(&drawing);
    jw_cmd_set(JW_CMD_HANI);
    bt_close();
    bt_open = 1;
    bt_reset();
    bt_sig = bt_signature();
    ui_blktree_default(fb.w, fb.h, &bt_win);
    bt_all = 0;
}

/* Every block under `p`, depth first and in the order the data lies: the
   order the original lists them in, which is what decides the one it ends
   up on after 同名BLK全検索. */
static void bt_all_walk(const bt_path_t *p, const char *name, bt_path_t *last,
                        int *count, int depth)
{
    int from, to, i, at = -1;

    if (depth > BT_MAXD)
        return;
    if (p->n == 0) {
        from = 0;
        to = drawing.ndrawn;
    } else {
        int ref = p->p[p->n - 1];

        for (i = drawing.ndrawn; i < drawing.nobj; i++)
            if (drawing.obj[i].cls == JW_LIST
                && drawing.obj[i].list[0] == drawing.obj[ref].block) {
                at = i;
                break;
            }
        if (at < 0)
            return;
        from = at + 1;
        to = at + 1 + drawing.obj[at].n;
        if (to > drawing.nobj)
            to = drawing.nobj;
    }
    for (i = from; i < to; i++) {
        bt_path_t c = *p;

        if (drawing.obj[i].cls == JW_LIST)
            break;
        if (drawing.obj[i].cls != JW_BLOCK || (drawing.obj[i].flags & 1))
            continue;
        if (c.n >= BT_MAXD)
            continue;
        c.p[c.n++] = i;
        if (!strcmp(jw_bt_name(&drawing, i), name)) {
            int a;

            if (bt_nbold < BT_MARKS)
                bt_bold[bt_nbold++] = c;
            /* its ancestors open to show it */
            for (a = 1; a < c.n; a++) {
                bt_path_t anc = c;

                anc.n = a;
                if (bt_find(bt_exp, bt_nexp, &anc) < 0 && bt_nexp < BT_MARKS)
                    bt_exp[bt_nexp++] = anc;
            }
            *last = c;
            (*count)++;
        }
        bt_all_walk(&c, name, last, count, depth + 1);
    }
}

/* 同名BLK全検索 for the name `name`; with nothing found nothing changes */
static void bt_search(const char *name)
{
    bt_path_t last, root;
    int count = 0;

    root.n = 0;
    last.n = 0;
    bt_nbold = 0;
    bt_all_walk(&root, name, &last, &count, 0);
    bt_found = count;
    if (count > 0)
        bt_sel = last;
}

static void bt_scroll_to_sel(void)
{
    int i, page = ui_blktree_page(&bt_win);

    for (i = 0; i < bt_nrow; i++)
        if (bt_row[i].sel) {
            if (i < bt_scroll)
                bt_scroll = i;
            else if (i >= bt_scroll + page)
                bt_scroll = i - page + 1;
            break;
        }
}

static void bt_do(int what)
{
    if (!bt_open || !have_drawing || bt_sel.n == 0)
        return;
    switch (what) {
    case 2545:                          /* 同名BLK全検索 */
        bt_search(jw_bt_name(&drawing, bt_sel.p[bt_sel.n - 1]));
        bt_refresh();
        bt_scroll_to_sel();
        break;
    case 2546:                          /* 選択BLK編集 */
        if (jw_cmd_block_edit_path(&drawing, bt_sel.p, bt_sel.n)) {
            if (bt_all)
                jw_cmd_block_split(&drawing);
            bt_close();
        }
        break;
    case 2548:                          /* BLK名変更 */
        bt_ren = bt_sel;
        blk_name[0] = 0;
        blk_pref = 0;
        blk_attr = 2;
        blk_open = 1;
        break;
    }
}

/* ブロック名変更's OK: the name goes to the definition, and the tree comes
   back made afresh with every block of the new name in bold */
static void bt_rename_ok(void)
{
    char nm[64];

    if (!have_drawing || !blk_name[0] || bt_ren.n == 0)
        return;
    strncpy(nm, blk_name, sizeof nm - 1);
    nm[sizeof nm - 1] = 0;
    if (jw_cmd_block_rename_path(&drawing, bt_ren.p, bt_ren.n, nm)) {
        bt_reset();
        bt_sig = bt_signature();
        bt_build();
        bt_search(nm);
        bt_refresh();
        bt_scroll_to_sel();
    }
}

/* A press while the tree is up.  -1: not on it, the press goes on to
   whatever is behind. */
static int bt_press(int x, int y, int button)
{
    int row, box, hit;

    if (bt_menu_x >= 0) {               /* its pop-up takes the press */
        int k = ui_blktree_menu_hit(bt_menu_x, bt_menu_y, fb.w, fb.h, x, y);

        bt_menu_x = -1;
        if (k == 0)
            bt_do(2545);
        else if (k == 1)
            bt_do(2546);
        else if (k == 2)
            bt_do(2548);
        return 1;
    }
    bt_refresh();
    hit = ui_blktree_hit(&bt_win, bt_row, bt_nrow, bt_scroll, x, y, &row, &box);
    if (hit < 0)
        return -1;
    if (hit == 2) {
        bt_close();
        return 1;
    }
    if (hit == 2545 || hit == 2546 || hit == 2548) {
        if (button == 0)
            bt_do(hit);
        return 1;
    }
    if (hit == 2547) {
        if (button == 0)
            bt_all = !bt_all;
        return 1;
    }
    if (hit == 1775 && row >= 0) {
        const bt_path_t *p = &bt_rpath[row];

        if (box && button == 0) {       /* the little box opens or shuts */
            int at = bt_find(bt_exp, bt_nexp, p);

            if (at >= 0) {
                bt_exp[at] = bt_exp[--bt_nexp];
            } else if (bt_nexp < BT_MARKS) {
                bt_exp[bt_nexp++] = *p;
            }
            return 1;
        }
        bt_sel = *p;
        if (button == 1) {              /* a right press picks, then asks */
            bt_menu_x = x;
            bt_menu_y = y;
        }
        return 1;
    }
    if (hit >= 1776 && hit <= 1779) {   /* the bar down its right */
        int page = ui_blktree_page(&bt_win);

        if (button == 0) {
            bt_scroll += hit == 1776 ? -1 : hit == 1777 ? 1
                         : hit == 1778 ? -page : page;
            if (bt_scroll > bt_nrow - page)
                bt_scroll = bt_nrow - page;
            if (bt_scroll < 0)
                bt_scroll = 0;
        }
        return 1;
    }
    return 1;
}

/* 属性変更 (1070): the same window as 属性選択 with the other half up */
static int zhen_open;
static unsigned char zhen_on[64];

int app_zokuhen_open(void)
{
    return zhen_open;
}

static void zhen_start(void)
{
    int i, n = ui_zokuhen_n();

    for (i = 0; i < n && i < (int)sizeof zhen_on; i++)
        zhen_on[i] = (unsigned char)ui_zokuhen_on(i);
    zhen_open = 1;
}

static int press_zokuhen(int x, int y)
{
    int id = ui_zokuhen_hit(fb.w, fb.h, x, y), i, n = ui_zokuhen_n();

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1 || id == 2) {           /* either OK does the same thing */
        int lay = 0, grp = 0, wantc = 0, wantl = 0;

        for (i = 0; i < n && i < (int)sizeof zhen_on; i++) {
            if (!zhen_on[i])
                continue;
            if (ui_zokuhen_id(i) == 1825)
                lay = 1;                /* 書込【レイヤ】に変更 */
            if (ui_zokuhen_id(i) == 1826)
                grp = 1;                /* 書込レイヤグループに変更 */
            if (ui_zokuhen_id(i) == 1822)
                wantc = 1;              /* 指定【線色】に変更 */
            if (ui_zokuhen_id(i) == 1823)
                wantl = 1;              /* 指定   線種   に変更 */
        }
        zhen_open = 0;
        if (wantc || wantl) {
            /* the colour and the line type are asked for next */
            zh_lay = lay;
            zh_grp = grp;
            zh_wantc = wantc;
            zh_wantl = wantl;
            zoku_ask(2);
            return 1;
        }
        if (have_drawing)
            jw_cmd_zokuhen_range(&drawing, lay, grp, 0, 0);
        return 1;
    }
    for (i = 0; i < n && i < (int)sizeof zhen_on; i++)
        if (ui_zokuhen_id(i) == id)
            zhen_on[i] = (unsigned char)!zhen_on[i];
    return 1;
}

static int press_zokusel(int x, int y)
{
    int id = ui_zokusel_hit(fb.w, fb.h, x, y), i, n = ui_zokusel_n();

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1 || id == 2) {           /* either OK does the same thing */
        int exclude = 0, wantc = 0, wantl = 0;

        for (i = 0; i < n && i < (int)sizeof zsel_on; i++) {
            if (!zsel_on[i])
                continue;
            if (ui_zokusel_id(i) == 1324)
                exclude = 1;
            if (ui_zokusel_id(i) == 1810)
                wantc = 1;              /* 指定【線色】指定 */
            if (ui_zokusel_id(i) == 1811)
                wantl = 1;              /* 指定   線種   指定 */
        }
        zsel_open = 0;
        if (wantc || wantl) {
            zs_mask = zsel_mask();
            zs_exclude = exclude;
            zs_wantc = wantc;
            zs_wantl = wantl;
            zoku_ask(1);
            return 1;
        }
        if (have_drawing)
            jw_cmd_zokusel(&drawing, zsel_mask(), exclude, 0, 0);
        return 1;
    }
    for (i = 0; i < n && i < (int)sizeof zsel_on; i++) {
        if (ui_zokusel_id(i) != id)
            continue;
        zsel_on[i] = (unsigned char)!zsel_on[i];
        /* ブロック名指定: ticking it asks which block, in the original's
           ブロック名を指定して選択 (template 340) on top of this one --
           CZokuseiSelHenkouDialog's handler for 2412 builds it (its
           message map, read by tools/cmddlg.py's method) */
        if (id == 2412 && zsel_on[i] && td_start(340))
            td_caret = 2435;            /* the name box takes the typing */
        if (id == 2412 && !zsel_on[i])
            jw_cmd_zokusel_name("");
        /* the two at the bottom are one choice */
        if (zsel_on[i] && (id == 1323 || id == 1324)) {
            int k, other = id == 1323 ? 1324 : 1323;

            for (k = 0; k < n && k < (int)sizeof zsel_on; k++)
                if (ui_zokusel_id(k) == other)
                    zsel_on[k] = 0;
        }
    }
    return 1;
}

/* Which of the ten the drawing is writing in, 0 if it is a free size. */
static int moji_current(void)
{
    int i;

    if (!have_drawing)
        return 0;
    for (i = 0; i < 10; i++)
        if (drawing.style[i].w == drawing.cur_style.w
            && drawing.style[i].h == drawing.cur_style.h
            && drawing.style[i].sp == drawing.cur_style.sp)
            return i + 1;
    return 0;
}

static int press_moji(int x, int y)
{
    int id;

    if (moji_drop) {                    /* the 色No. or フォント list is down */
        int row = ui_moji_drop_hit(fb.w, fb.h, x, y);

        if (row >= 0 && moji_drop == 2) {
            moji_font = row;
            {   /* start fetching what it will be drawn with */
                int pr, of = jw_outfont_resolve(app_moji_font_item(row), &pr);

                if (of >= 0)
                    jw_outfont_ready(of);
            }
        } else if (row >= 0) {
            moji_color = row;
        }
        moji_drop = 0;
        return 1;
    }
    id = ui_moji_hit(fb.w, fb.h, x, y);
    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 2358 || id == 1423) {
        moji_drop = id == 1423 ? 2 : 1;
        return 1;
    }
    if (id == 1884) {
        moji_style = 0;                 /* 任意サイズ */
        moji_focus = 0;
    } else if (id >= 1689 && id <= 1698) {
        moji_style = id - 1688;
        moji_focus = 0;
        if (have_drawing)               /* the boxes follow the pick */
            moji_fill(&drawing, moji_style);
    } else if (id == 1491 || id == 1492 || id == 1493) {
        moji_focus = id;                /* the typing goes in here */
    } else if (id == 2420) {            /* 斜体 */
        jw_cmd_moji_style(!jw_cmd_moji_italic(), jw_cmd_moji_bold());
    } else if (id == 2413) {            /* 太字 */
        jw_cmd_moji_style(jw_cmd_moji_italic(), !jw_cmd_moji_bold());
    } else if (id == 1) {               /* Ok */
        if (have_drawing && moji_style >= 1 && moji_style <= 10) {
            drawing.cur_style = drawing.style[moji_style - 1];
        } else if (have_drawing) {
            /* 任意サイズ: whatever the three boxes say */
            double w = atof(moji_box[0]), h = atof(moji_box[1]);
            double sp = atof(moji_box[2]);

            if (w > 0.0)
                drawing.cur_style.w = w;
            if (h > 0.0)
                drawing.cur_style.h = h;
            if (sp >= 0.0)
                drawing.cur_style.sp = sp;
            drawing.cur_style.color = moji_color;
        }
        jw_cmd_moji_face_set(app_moji_font_item(moji_font));
        moji_open = 0;
        moji_focus = 0;
        moji_drop = 0;
    } else if (id == 2) {               /* キャンセル */
        moji_open = 0;
        moji_focus = 0;
        moji_drop = 0;
    }
    return 1;
}

/* 用紙サイズ のポップアップを (x, y) に出す。印は**いまの用紙**で、
   図面の `paper_size` がメニューのどの番号に当たるかは `jw_paper_set` の
   裏返しです（0..4 が Ａ-０..Ａ-４、8..11 が ２Ａ..５Ａ、12..14 が
   10ｍ・50ｍ・100m）。 */
static void paper_popup(int x, int y)
{
    int n = have_drawing ? drawing.paper_size : 2, mark = 0;

    if (n >= 0 && n <= 4)
        mark = 32820 + n;
    else if (n >= 8 && n <= 11)
        mark = 32899 + n - 8;
    else if (n >= 12 && n <= 14)
        mark = 32903 + n - 12;
    ui_popup_open_at(32820, mark, x, y, fb.w, fb.h);
}

/* ２線 の 基準線変更 (LL) を、画面の (L) 二つから作る。
 *
 * 原典の CZukei2Sen は始点・終点の (L) を受けるとすぐには書かず、マウスが
 * x か y で 2 画素以上動くまで待ちます（state 4・5、FUN_00629330）。その
 * あいだにダブルクリック（slot 12、FUN_00624fa0）が来れば 基準線変更 です。
 * 二つ目の (L) は左 (slot 9, FUN_00625680) の state 4・5 の枝が受けて
 * 基準線変更 にします。移植の jw_cmd_point は (L) をその場で済ませ、(LL) は
 * jw_cmd_point_ll と別の入口なのに、どの表（ネイティブ・ブラウザ）も
 * 呼んでいなかったので、画面からは角を回れませんでした。そこでここで:
 *
 *   始点の (L)  その場で渡す（原典も始点は覚えて state 4 に居る。案内は
 *               終点のもの）。2 画素未満でもう一度 (L) が来たら、始点を
 *               jw_cmd_back で取り消して (LL)
 *   終点の (L)  原典は動くまで書かないので預かる。2 画素以上動くか、
 *               ほかの押し・キー・命令が来たらその (L) として渡し、
 *               2 画素未満でもう一度 (L) が来たら (LL)
 *
 * 逆コンパイルの読み、原典では押していない。tests/workflow_test.c */
static int ll_pend, ll_start, ll_x, ll_y;
static double ll_mx, ll_my;
/* 「動かずに」の幅。マウスは原典の 2 画素（state 4・5 の待ち）。指は
 * 二度叩いても同じ画素には落ちないので、ブラウザがタッチのときだけ広げる
 * （app_ll_slop。移植の都合で、原典には指の扱いは無い） */
static int ll_slop = 2;

void app_ll_slop(int px)
{
    ll_slop = px < 1 ? 2 : px;
}

static int ll_wanted(int button)
{
    return button == 0 && have_drawing && jw_cmd() == JW_CMD_NISEN && jw_cmd_midway();
}

/* ほかに (LL) を受けるのは 文字 の 連（文字を指示…移動（LL)、5473）と
 * 曲線 の スプライン（連結する線・弧指示（LL)、1691）。どちらも原典は
 * 一つ目を普通の左で受けてから WM_LBUTTONDBLCLK が来るので、一つ目は
 * その場で渡し、2 画素未満でもう一度 (L) が来たら、一つ目が進めた分を
 * jw_cmd_back で戻して jw_cmd_point_ll（ダブルクリック一つ分）にする。
 * 連 は一つ目で字を拾ったときだけ（5474）、曲線は点を持っているときだけ戻す */
static int ll_cmd;

static int ll_other(int button)
{
    if (button != 0 || !have_drawing)
        return 0;
    if (jw_cmd() == JW_CMD_MOJI)
        return strcmp(jw_cmd_prompt(), JW_STR_5473) == 0;
    if (jw_cmd() == JW_CMD_SHINSHUKU)
        return jw_cmd_ikk_base_wait();  /* 一括処理の (LL) free 基準点 */
    return jw_cmd() == JW_CMD_KYOKUSEN && jw_cmd_bar_radio(1691) == 1;
}

static void ll_flush(void)
{
    int was;

    ll_start = 0;
    if (!ll_pend)
        return;
    ll_pend = 0;
    if (!have_drawing || jw_cmd() != JW_CMD_NISEN)
        return;
    was = drawing.ndrawn;
    jw_cmd_point(&drawing, &view, ll_mx, ll_my, 0);
    if (jw_cmd_block_editing() && drawing.ndrawn > was)
        jw_cmd_block_take(&drawing, was);
}

/* 二度目の (L) が遅すぎた（指で叩く表が時間を見る）: 預かりをいま渡す */
int app_ll_break(void)
{
    int had = ll_pend;

    ll_flush();
    return had;
}

/* One command, however it was asked for: a toolbar button, or the menu the
 * native build hands to Windows (both send the same ids -- they are the
 * original's own, out of its resources).  Returns 1 when the window wants
 * repainting, 0 otherwise; the two that need the front end's help leave an
 * action behind for app_take_action. */
int app_command(int cmd)
{
    int k;

    ll_flush();

    for (k = 0; k < JW_NBUTTONS; k++)
        if (jw_btn_cmd[k] == cmd)
            break;
    if (k < JW_NBUTTONS && (jw_btn_mode[k] || cmd == JW_CMD_ZOKUSEI)) {
        /* 属性取得 is not a mode in the drawn sense -- the original has no
           ON_UPDATE_COMMAND_UI for it, so its button is never shown pressed
           -- but it does become the command: the click after it is what
           picks the element to take the pen from. */
        if (have_drawing)
            jw_cmd_flush(&drawing);
        ly_restore();                   /* 反転表示を解く（FUN_004fdc40） */
        if (have_drawing)
            jw_cmd_moji_leave(&drawing, cmd);   /* 文字の選択は種別の違う命令へ持ち越さない */
        jw_cmd_set(cmd);
        bt_close();                     /* setting a command puts it away */
        /* 消去 with a settled range in hand empties it at once */
        if (cmd == JW_CMD_SHOUKYO && have_drawing)
            jw_cmd_sel_erase(&drawing);
        /* 座標ファイル: the original's bar asks for a file name and then a
           range of its own.  The port has no bar for it, so entering the
           command with something already picked is what writes the file --
           the front end is handed JW_ACT_SAVE_COORD to ask for a name. */
        if (cmd == 32895 && have_drawing && jw_cmd_sel_count(&drawing) > 0)
            action = JW_ACT_SAVE_COORD;
        if (cmd == 32913 && have_drawing)
            action = JW_ACT_GAIBU;          /* the front end picks the BAT */
        /* 図形 (32862): 原典は命令に入ってファイルの窓を出す。移植は表側に
           選ばせて app_figure で受ける */
        if (cmd == JW_CMD_ZUKEI && have_drawing)
            action = JW_ACT_OPEN_FIG;
        return 1;
    }
    /* a dialog put up from the original's own template (td_start) */
    for (k = 0; k < (int)(sizeof TD_CMD / sizeof TD_CMD[0]); k++)
        if (TD_CMD[k].cmd == cmd)
            return td_start(TD_CMD[k].tpl);
    /* an action: it runs, and never becomes "the command" */
    switch (cmd) {
    case 32835:                         /* 全体再表示: the whole sheet in view */
        app_fit();
        return 1;
    case 32820: case 32821: case 32822: case 32823: case 32824:
        /* Ａ-０..Ａ-４: the sheet changes and nothing else does */
        if (!have_drawing)
            return 0;
        jw_paper_set(&drawing, cmd - 32820);
        return 1;
    case 32899: case 32900: case 32901: case 32902:
        /* ２Ａ..５Ａ, which the menu carries after Ａ-４ */
        if (!have_drawing)
            return 0;
        jw_paper_set(&drawing, cmd - 32899 + 8);
        return 1;
    case 32903: case 32904: case 32905:
        /* 10ｍ, 50ｍ, 100m -- the sizes the file format numbers 12 to 14 */
        if (!have_drawing)
            return 0;
        jw_paper_set(&drawing, cmd - 32903 + 12);
        return 1;
    case 32891:                         /* 基本設定 */
        kh_start();
        return 1;
    case 32808:                         /* レイヤ */
    case 32829:                         /* the status line's レイヤ box */
        ld_start();
        return 1;
    case 32944:                         /* 縮尺・読取 */
    case 32827:                         /* the status line's 縮尺 box */
        sk_start();
        return 1;
    case 32825:                         /* その 用紙 の箱 */
        /* without a point to hang it off, over the box itself */
        {
            rect_t b;

            ui_status_box(0, fb.w, fb.h, &b);
            paper_popup(b.x + b.w / 2, b.y);
        }
        return 1;
    case 32842:                         /* 軸角・目盛・オフセット */
    case 32843:                         /* the same, from the status line */
        jk_start();
        return 1;
    case 32925:                         /* 寸法設定 */
        sd_start();
        return 1;
    case 32988:                         /* 表示 > ブロックツリー */
        bt_start();
        return 1;
    case 32987:                         /* 図面情報コピー（src/fileops.h） */
        return fo_info_clip();
    case 32977:                         /* ファイル一括変換 */
    case 32979:                         /* ファイル名変更 */
    case 32980:                         /* ファイル削除 */
    case 32984:                         /* ファイル属性変更 */
        return fo_command(cmd);
    case 32917:                         /* レイヤ一覧 */
        return lyl_start(1);
    case 32916:                         /* レイヤグループ一覧 */
        return lyl_start(2);
    case 32995:                         /* 表示 > ブロックツリー半透明化 */
        /* A switch.  Turning it on puts 透過率 (DIALOG 384) up; the flag is
           already on when it does, so キャンセル leaves it on at the old
           rate (FUN_005146a0 sets it and then calls DoModal). */
        bt_trans = !bt_trans;
        if (bt_trans && td_start(384)) {
            int i = ui_tdlg_index(td_t, 1411);

            if (i >= 0 && i < TD_MAX)
                sprintf(td_txt[i], "%d", bt_alpha);
            td_caret = 1411;
        }
        return 1;
    case 33037:                         /* 表示 > Direct2D */
        d2d_on = !d2d_on;
        return 1;
    case 33041:                         /* 表示 > ANTIALIAS */
        if (!d2d_on)
            return 0;                   /* greyed unless Direct2D is on */
        aa_on = !aa_on;
        return 1;
    case 32953:                         /* 表示 > ダイアログボックス */
        mb_open = 1;
        return 1;
    case 32967:                         /* ファイル > タグジャンプ */
        /* the file a picked text names: the front end finds it, asks
           about changes and opens it */
        if (!have_drawing
            || !jw_cmd_sel_text(&drawing, tag_name, (int)sizeof tag_name))
            return 0;
        action = JW_ACT_TAG;
        return 1;
    case 33032:                         /* 編集 > SPEED Data 入力 */
        /* Enabled only when the original has the SPEED program's path
           (DAT_00a08b70) and then it asks for a .spd file with a Windows
           file dialog and hands the line to that program: nothing the
           browser has.  The item is greyed (app_menu_state). */
        return 0;
    case 59393:                         /* 表示 > ステータスバー */
        /* a tick: the status line goes away and the drawing area takes
           the room (tools/probe134.sh).  The view's clip is read from
           ui_view_rect on every paint, so there is nothing else to do. */
        ui_status_show(!ui_status_shown());
        return 1;
    case 32811:                         /* 画面倍率・文字表示 */
    case 32844:                         /* the same, from the status line */
        br_start();
        return 1;
    case 32946:                         /* 図形登録 */
        /* It takes a range of its own -- the original asks for one even
           when something is already picked -- and the point after 選択確定
           is the 基準点. */
        jw_cmd_set(JW_CMD_ZUKEIREG);
        return 1;
    case 57634:                         /* 編集 > コピー   Ctrl+C */
    case 57635:                         /* 同        切り取り Ctrl+X */
        /* Both want a range picked first; the original's bar and status
           line do not change when they are pressed, so there is nothing
           to show for it either way (tools/probe56.sh). */
        if (!jw_cmd_clip_copy(&drawing, cmd == 57635))
            return 0;
        action = JW_ACT_CLIP_PUT;       /* 表側がシステムのクリップボードへ */
        return 1;
    case 57637:                         /* 同        貼り付け Ctrl+V */
        /* which puts up 図形読込's own command, figure and all */
        return jw_cmd_clip_paste(&drawing);
    case 33016:                         /* 中心点取得 */
    case 33017:                         /* 線上点・交点取得 */
    case 33028:                         /* 円周1/4点取得 */
        jw_cmd_read_mode(cmd);
        return 1;
    case 32932:                         /* 設定 > 角度取得 > 線角度 */
    case 32933:                         /* 同           X軸角度 */
    case 32934:                         /* 同           ２点間角度 */
    case 32935:                         /* 同           線鉛直角度 */
    case 32938:                         /* 同           数値角度 */
    case 32962:                         /* 同           軸角 */
    case 32939:                         /* 設定 > 長さ取得 > 線長 */
    case 32940:                         /* 同           ２点間長 */
    case 32941:                         /* 同           数値長 */
    case 32948:                         /* 同           間隔取得 */
    case 32912:                         /* 設定 > 環境設定ファイル >
                                           目盛基準点 */
    case 32936:                         /* 同           レイヤ非表示化 */
        jw_cmd_get_mode(cmd);
        return 1;
    case 33013:                         /* 編集 > 画像編集 */
        if (have_drawing)
            jw_cmd_flush(&drawing);
        jw_cmd_set(JW_CMD_GAZOU);
        bt_close();
        return 1;
    case 32862:                         /* 図形読込 */
        /* 釦にあれば上で命令に入り JW_ACT_OPEN_FIG を置く。ここへ来るのは
           釦の表に無いときだけ: 同じように命令に入って表側に選ばせる */
        if (!have_drawing)
            return 0;
        jw_cmd_flush(&drawing);
        jw_cmd_set(JW_CMD_ZUKEI);
        bt_close();
        action = JW_ACT_OPEN_FIG;
        return 1;
    case 57665:                         /* Jw_cadの終了 */
        /* 原典は CWinApp の ID_APP_EXIT（主窓に WM_CLOSE）。窓は表側のもの */
        action = JW_ACT_EXIT;
        return 1;
    case JW_CMD_BLOCK_EDIT:             /* ブロック編集 */
        if (!have_drawing || jw_cmd_sel_count(&drawing) <= 0)
            return 0;
        if (!jw_cmd_block_edit(&drawing))
            return 0;                   /* nothing but a reference will do */
        strncpy(be_name, jw_cmd_block_name(&drawing), sizeof be_name - 1);
        be_name[sizeof be_name - 1] = 0;
        be_all = 1;
        be_open = 1;
        return 1;
    case JW_CMD_BLOCK_DONE:             /* ブロック編集終了 */
        if (!jw_cmd_block_editing())
            return 0;
        jw_cmd_block_done();
        return 1;
    case JW_CMD_BLOCK_FREE:             /* ブロック解除 */
        if (!have_drawing || jw_cmd_sel_count(&drawing) <= 0)
            return 0;
        return jw_cmd_block_free(&drawing) > 0;
    case JW_CMD_BLOCK:                  /* ブロック化 */
    case JW_CMD_BLOCK_ATTR:             /* ブロック属性 -- the same dialog */
        if (!have_drawing || jw_cmd_sel_count(&drawing) <= 0)
            return 0;                   /* nothing picked: nothing to do */
        blk_name[0] = 0;
        blk_pref = 0;
        blk_attr = cmd == JW_CMD_BLOCK_ATTR;
        blk_open = 1;
        return 1;
    case JW_CMD_UNDO:
        if (ly_inv) {                   /* 反転表示の間の 戻る は解くだけ（FUN_00504100） */
            ly_restore();
            return 1;
        }
        /* A command part way through takes the press itself and backs
           up (jw_cmd_back); only a command at rest lets a step of the
           drawing come off (jw_cmd_midway).  The port used to undo the drawing whatever the
           command was doing, and the command kept the elements it had
           picked by their index -- which after the undo could be another
           element, or past the end. */
        if (jw_cmd_midway()
            && jw_cmd_back(have_drawing ? &drawing : 0))
            return 1;           /* 0 なら原典と同じく図面の 戻る へ */
        jw_cmd_undo_trim();     /* Undo の回数より古い段はもう戻れない */
        if (!jw_cmd_can_undo())
            return 0;
        jw_cmd_undo(have_drawing ? &drawing : 0);
        return 1;
    case JW_CMD_REDO:
        if (!jw_cmd_can_redo())
            return 0;
        jw_cmd_redo(have_drawing ? &drawing : 0);
        return 1;
    case 0x8027:                        /* 線属性 */
        zoku_color = have_drawing && drawing.write_color
                     ? drawing.write_color : 2;
        zoku_ltype = have_drawing && drawing.write_ltype
                     ? drawing.write_ltype : 1;
        zoku_open = 1;
        return 1;
    case 57600:                         /* 新規 (ID_FILE_NEW) */
        if (app_modified()) {           /* the original asks first */
            action = JW_ACT_NEW_ASK;
            return 0;
        }
        app_new();
        return 1;
    case 57601:                         /* 開く (ID_FILE_OPEN) */
        action = JW_ACT_OPEN;
        return 0;
    case 57603:                         /* 上書 (ID_FILE_SAVE) */
        action = JW_ACT_SAVE;
        return 0;
    case 57604:                         /* 名前を付けて保存 */
        action = JW_ACT_SAVE_AS;
        return 0;
    case 32961:                         /* DXF形式で保存 */
        action = JW_ACT_SAVE_DXF;
        return 0;
    case 32960:                         /* DXFファイルを開く */
        action = JW_ACT_OPEN_DXF;
        return 0;
    case 32975:                         /* SFCファイルを開く */
        action = JW_ACT_OPEN_SFC;
        return 0;
    case 32976:                         /* SFC形式で保存 */
        action = JW_ACT_SAVE_SFC;
        return 0;
    case 32809:                         /* JWCファイルを開く */
        action = JW_ACT_OPEN_JWC;
        return 0;
    case 32923:                         /* 環境設定ファイル 読込み */
        action = JW_ACT_ENV_READ;
        return 0;
    case 32924:                         /* 環境設定ファイル 書出し */
        action = JW_ACT_ENV_WRITE;
        return 0;
    case 32954:                         /* 環境設定ファイル 編集・作成 */
        action = JW_ACT_ENV_EDIT;       /* greyed in the browser */
        return 0;
    case 32810:                         /* JWC形式で保存 */
        action = JW_ACT_SAVE_JWC;
        return 0;
    case 57607:                         /* 印刷 */
        /* The original puts the Windows printer dialog up here and then
           goes into a mode of its own, 印刷範囲を設定 (0x8053), with a
           frame to place and 印刷 (L) to press (src/plot.h).  The port has
           no printer dialog to put up first -- the native build asks for
           the printer when 印刷 (L) is pressed -- so it goes straight into
           the mode; 印刷 (L) then hands over JW_ACT_PLOT through
           app_take_action, and what comes out is the frame's range: a PDF
           or a PNG, or a print on the printer. */
        if (have_drawing)
            jw_cmd_flush(&drawing);
        jw_cmd_set(JW_PRINT_CMD);
        bt_close();
        return 1;
    }
    /* a command the port does not do yet: it still becomes the one in force
       if it has a button, so the bar and the prompt follow */
    if (k < JW_NBUTTONS)
        return 0;
    return 0;
}

/* A name on the menu bar was pressed: its popup opens, and pressing the same
   one again shuts it.  The native build never gets here -- Windows runs its
   menu itself. */
int app_chrome_press(int x, int y)
{
    int i = ui_menu_hit(x, y);

    if (i < 0)
        return ui_popup_open(-1);
    return ui_popup_open(i == ui_popup_top() ? -1 : i);
}

int app_chrome_move(int x, int y)
{
    int i;

    if (!ui_popup_up())
        return 0;
    /* sliding along the bar with one open moves to the next, as Windows does */
    i = ui_menu_hit(x, y);
    if (i >= 0 && i != ui_popup_top())
        return ui_popup_open(i);
    return 0;
}

/* 画像編集: what the command wants of the front end.  A file (画像挿入) is
   an action; a question or a report is the message box; the 透過色 dialog is
   template 391 (see tgp_check, which looks at it on every paint). */
static void mb_close(int ok)
{
    int kind = mb_kind;

    mb_open = 0;
    mb_kind = 0;
    if (kind == 0) {
        if (ok)
            ui_blktree_default(fb.w, fb.h, &bt_win);   /* every dialog back to where it first appears */
        return;
    }
    if (kind == 3) {                    /* 天空図の 真北が無いときの問い */
        if (have_drawing)
            jw_cmd_tenku_north_answer(&drawing, ok);
        return;
    }
    if (kind == 5) {                    /* 図形読込の 縮尺の違うグループの問い */
        if (have_drawing)
            jw_cmd_figure_answer(&drawing, ok);
        return;
    }
    if (have_drawing)
        jw_cmd_gazou_answer(&drawing, kind == 1 && ok);
    if (jw_cmd_gazou_out_ready())
        action = JW_ACT_SAVE_IMAGES;
    gz_check();
}

static void gz_check(void)
{
    const char *t;
    int k;

    if (jw_cmd() != JW_CMD_GAZOU)
        return;
    if (jw_cmd_gazou_file())
        action = JW_ACT_OPEN_IMAGE;
    if (!mb_open && (k = jw_cmd_gazou_ask(&t)) != 0) {
        strncpy(mb_text, t, sizeof mb_text - 1);
        mb_text[sizeof mb_text - 1] = 0;
        mb_kind = k;
        mb_open = 1;
    }
}

/* 札（jw_cmd_notice）の置き場。原典は札を出す命令が view の +0x8f24/+0x8f28（押した
   画素）を渡すので、最後に押した所を持っておき、新しい札が出た（seq が進んだ）とき
   その所に据える。押すと下ろす（view の WM_LBUTTONDOWN・WM_RBUTTONDOWN が
   FUN_004fb9f0 を呼ぶ）。マウスが札に乗っても下ろす（CMsgDialog の WM_SETCURSOR、
   FUN_005889c0 が隠す）。逆コンパイルの読み、原典では押していない。 */
static int nt_px, nt_py, nt_x, nt_y;
static unsigned nt_seen;

static const char *notice_at(rect_t *r)
{
    const char *s = jw_cmd_notice_text();

    if (!s)
        return 0;
    if (jw_cmd_notice_seq() != nt_seen) {
        nt_seen = jw_cmd_notice_seq();
        nt_x = nt_px;
        nt_y = nt_py;
    }
    ui_notice_rect(fb.w, fb.h, nt_x, nt_y, s, r);
    return s;
}

int app_press(int x, int y, int button)
{
    int k, id, g, n;

    jw_cmd_notice_clear();
    nt_px = x;
    nt_py = y;
    if (ll_pend || ll_start) {
        if (button == 0 && abs(x - ll_x) < ll_slop && abs(y - ll_y) < ll_slop
            && have_drawing && jw_cmd() == ll_cmd) {
            int was = drawing.ndrawn;

            if (ll_cmd == JW_CMD_MOJI) {
                if (strcmp(jw_cmd_prompt(), JW_STR_5474) == 0)
                    jw_cmd_back(&drawing);      /* 一つ目で拾った字を放す */
            } else if (ll_cmd == JW_CMD_KYOKUSEN) {
                if (jw_cmd_midway())
                    jw_cmd_back(&drawing);      /* 一つ目の点を捨てる */
            } else if (ll_cmd == JW_CMD_SHINSHUKU) {
                /* 伸縮の一括処理: 一つ目の左はそのまま（原典も slot 9 のあと
                   slot 12 が 基準線を放して点に替える。jw_cmd_point_ll） */
            } else if (ll_start)
                jw_cmd_back(&drawing);  /* 始点を取り消して 始点待ち に */
            ll_pend = ll_start = 0;
            jw_cmd_point_ll(&drawing, &view, ll_mx, ll_my);
            if (jw_cmd_block_editing() && drawing.ndrawn > was)
                jw_cmd_block_take(&drawing, was);
            return 1;
        }
        ll_flush();
    }
    k = hit_button(x, y);

    if (mb3_open) {                     /* はい 1・いいえ 3・キャンセル 2 */
        int h = ui_msgbox3_hit(fb.w, fb.h, x, y);

        if (h == 1 || h == 2 || h == 3) {
            mb3_open = 0;
            if (have_drawing)
                jw_cmd_tenku_answer(&drawing, h == 1 ? 1 : h == 3 ? 0 : -1);
        }
        return 1;
    }
    if (mb_open) {                      /* modal over everything */
        int h = ui_msgbox_hit(fb.w, fb.h, mb_kind != 2, x, y);

        if (h == 1 || h == 2)
            mb_close(h == 1);
        return 1;
    }

    /* An open popup takes the press: on an item it runs it, anywhere else it
       just shuts -- the click that closes a menu does nothing else, which is
       what Windows does too. */
    if (ui_popup_up()) {
        int cmd = ui_popup_in(x, y) ? ui_popup_press(x, y) : 0;

        if (cmd && (app_menu_state(cmd) & 2)) {     /* a greyed item */
            ui_popup_open(-1);
            return 1;
        }
        if (cmd) {
            ui_popup_open(-1);
            return app_command(cmd) | 1;
        }
        if (!ui_popup_in(x, y)) {
            ui_popup_open(-1);
            return 1;
        }
        return 1;                       /* a separator, or a submenu opening */
    }

    /* a dialog from a template may sit on top of one of the others
       (ブロック名を指定して選択 over 属性選択), so it hears first */
    if (tgp_open)
        return press_tgp(x, y);
    if (kj_open)
        return press_kj(x, y);
    if (td_open)
        return td_tpl == 314 ? press_kp(x, y, button) : press_tdlg(x, y);
    if (lyl_open)
        return lyl_press(x, y, button);
    if (zoku_open)
        return press_zoku(x, y);
    if (moji_open)
        return press_moji(x, y);
    if (zsel_open)
        return press_zokusel(x, y);
    if (zhen_open)
        return press_zokuhen(x, y);
    if (blk_open)
        return press_blkname(x, y);
    if (be_open)
        return press_blkedit(x, y);
    if (cd_open)
        return press_colordlg(x, y);    /* 基本設定 の上に重なる */
    if (kh_open)
        return press_kihon(x, y);
    if (jk_open)
        return press_jikkaku(x, y);
    if (sd_open)
        return press_sunpodlg(x, y);
    if (br_open)
        return press_bairitsu(x, y);
    if (mk_open)
        return press_mojikijun(x, y);
    if (sk_open)
        return press_shakudo(x, y);
    if (ld_open)
        return press_layerdlg(x, y, button);

    if (bt_open) {                      /* modeless: it hears, or passes on */
        int r = bt_press(x, y, button);

        if (r >= 0)
            return r;
    }

    if ((g = ui_layer_small_hit(fb.w, x, y)) >= 0)
        return press_layer_small(g, button);
    if ((g = ui_layer_hit(fb.w, x, y, &n)) >= 0)
        return press_layer(g, n, button);

    /* the five boxes at the right of the status line.  The original sends
       the frame a command from each (FUN_00596e80), so the port runs the
       same one. */
    if (button == 0) {
        static const int STATUS_CMD[5] = { 32825, 32827, 32829, 32843, 32844 };
        int k = ui_status_hit(x, y, fb.w, fb.h);
        if (k == 0) {
            /* 用紙サイズ: the original answers this one with a popup of the
               twelve sizes rather than a window, and the popup hangs off
               the press -- centred on it, running down from it
               (tools/probe119.sh).  So it needs the point, which is why it
               is here and not in app_command. */
            paper_popup(x, y);
            return 1;
        }
        if (k >= 0)
            return app_command(STATUS_CMD[k]) | 1;
    }

    if (button == 1 && (id = ui_bar_hit(x, y)) != 0 && jw_cmd_box(id)) {
        /* a right press on one of the bar's boxes: 数値入力 */
        jw_cmd_box_click(0);
        kp_start(id);
        return 1;
    }
    if (button == 1 && (id = ui_bar_hit(x, y)) != 0
        && jw_cmd_bar_r(have_drawing ? &drawing : 0, id)) {
        /* 釦の右押し: 右押しに意味のある釦だけ命令が受ける（jw_cmd_bar_r） */
        gz_check();
        return 1;
    }
    if (button == 0 && (id = ui_bar_hit(x, y)) != 0) {
        /* 範囲選択の 文字位置･集計 のバー: 基点 (1072) は FUN_005ca230 が
           文字基点設定 の窓をバーの基点で、集計書込 (1121) は FUN_005ca030 が
           切れていれば 文字集計設定 を出す（入っていれば命令の側が切る） */
        if (id == 1072 && jw_cmd_mp_on()) {
            mk_open = 2;
            mk_caret = 0;
            return 1;
        }
        if (id == 1121 && jw_cmd_mp_on() && !jw_cmd_mp_sum()) {
            ms_open();
            return 1;
        }
        /* 文字 with texts picked: 文書, 外部エディタ and 貼付 are the front end's */
        if (jw_cmd_moji_ready() && id == 1069) {
            jw_moji_sjis_toggle();          /* 1092, drawn where 文読 is */
            return 1;
        }
        if (jw_cmd_moji_ready() && id == 1065 && have_drawing
            && jw_cmd_moji_paste(&drawing) >= 0)
            return 1;                       /* 貼付: コピーの字の控えから */
        if (jw_cmd_moji_ready() && (id == 1070 || id == 1067 || id == 1065)) {
            action = id == 1070 ? JW_ACT_MOJI_DOC
                   : id == 1067 ? JW_ACT_MOJI_EDIT : JW_ACT_MOJI_PASTE;
            return 1;
        }
        /* 複写・移動 once the range is settled: their second bar has its
           own 1070, 作図属性, and that one puts up 作図属性設定 (template
           342) -- CZukeiFukusha's slot 31 builds it (tools/cmddlg.py's
           sort of reading, from the class side).  The 1070 below is the
           first bar's 属性変更 and must not answer here: this bar's 1069
           is ﾏｳｽ倍率, which is enabled, and the window it opened was the
           range selection's. */
        if (id == 1070 && jw_cmd_sel_stage() == 3
            && (jw_cmd() == JW_CMD_FUKUSHA || jw_cmd() == JW_CMD_IDOU)) {
            za_open();
            return 1;
        }
        /* 図形読込の 作図属性 (1067): 同じ窓を図形の組で（jw_cmd_fzoku） */
        if (id == 1067 && jw_cmd() == JW_CMD_ZUKEI) {
            fz_open();
            return 1;
        }
        /* 図形選択 (1065): slot 26 FUN_00758820 → FUN_0075a9a0（+0x1f8 = 1）。
           クロックの「【図形】再選沢」と同じ関数で、ファイルの窓を出し直す
           見込み（窓の側は読み切っていない） */
        if (id == 1065 && jw_cmd() == JW_CMD_ZUKEI && have_drawing) {
            action = JW_ACT_OPEN_FIG;
            return 1;
        }
        if (id == 1070 && jw_cmd() != JW_PRINT_CMD     /* 印刷の 1070 は 回転、1069 は */
            && jw_cmd_bar_enabled(have_drawing ? &drawing : 0,   /* 出力方法設定（ネイティブ */
                                  1069) > 0) {                   /* で押せる、src/prnative.h） */
            /* 属性変更 -- the same window, its other half */
            zhen_start();
            return 1;
        }
        if (id == 1071 && jw_cmd() == JW_CMD_SUNPO) {
            /* 寸法 の 設定: the original put its 寸法設定 dialog up from it,
               which is the same window the menu's 寸法設定 opens */
            sd_start();
            return 1;
        }
        if (id == 2552) {
            /* 矩形 の 任意色 の横の無名の釦。**原典は二通りに分かれます**
               （`FUN_005bde40`）:

                 任意色 (2553) が切  線属性 の窓（`FUN_004eed20`）
                 入                  色の設定（`CColorDialog`）を開いて、
                                     OK なら任意色に書き戻す

               はじめは切のほうしか見ていなくて、いつも線属性を出して
               いました。 */
            if (jw_cmd_bar_check(2553) > 0) {
                cd_start(CD_ROW_ANY, jw_cmd_any_color());
                return 1;
            }
            zoku_ask(0);
            return 1;
        }
        if (id == 1069 && jw_cmd() != JW_PRINT_CMD
            && jw_cmd_bar_enabled(have_drawing ? &drawing : 0,
                                  1069) > 0
            && !(jw_cmd() == JW_CMD_PARAM && jw_cmd_sel_stage() == 3)) {
            /* (パラメトリック変形 の二枚目では 1069 は 再選択 で、命令の側が受ける)
               範囲選択's own button, which only comes alive once a box is
               in -- the bar has it greyed until then */
            zsel_start();
            return 1;
        }
        if (id == 1069 && jw_cmd() == JW_CMD_MOJI) {
            /* 文読: the original puts up an ordinary 「開く」 here
               (tools/probe66.sh); the port asks the front end for it */
            action = JW_ACT_OPEN_TEXT;
            return 1;
        }
        if (id == 1064 && (jw_cmd() == JW_CMD_MOJI || jw_cmd() == JW_CMD_ZOKUHEN)) {
            /* 基点(左下): the button puts up 文字基点設定 */
            mk_open = 1;
            return 1;
        }
        if (id == 1843 && (jw_cmd() == JW_CMD_MOJI || jw_cmd() == JW_CMD_ZOKUHEN)) {
            /* the 文字 bar's own button, which puts the dialog up */
            moji_style = moji_current();
            moji_open = 1;
            moji_focus = 0;
            moji_drop = 0;
            moji_font = moji_font_now();
            if (have_drawing)
                moji_color = moji_style >= 1 && moji_style <= 10
                             ? drawing.style[moji_style - 1].color
                             : drawing.cur_style.color;
            if (have_drawing)
                moji_fill(&drawing, moji_style);
            return 1;
        }
        if (jw_cmd_box(id)) {           /* a box: it takes the typing */
            jw_cmd_box_click(id);
            return 1;
        }
        if (jw_cmd_bar(have_drawing ? &drawing : 0, id)) {
            gz_check();
            return 1;
        }
    }
    if (k >= 0) {
        int cmd = jw_btn_cmd[k];
        if (button != 0
            || ui_button_state(k, have_file, jw_cmd_can_undo()) == 1)
            return 0;           /* a disabled button does nothing */
        return app_command(cmd);
    }
    if (view_ready && in_view(x, y)) {
        double mx, my;
        bt_close();                     /* a press in the drawing */
        jw_cmd_box_click(0);            /* the caret leaves the bar */
        to_paper(x, y, &mx, &my);
        if (ll_wanted(button)) {        /* ２線: (LL) かどうか */
            ll_cmd = JW_CMD_NISEN;
            ll_x = x;
            ll_y = y;
            ll_mx = mx;
            ll_my = my;
            if (strcmp(jw_cmd_prompt(), JW_STR_5401) == 0) {
                jw_cmd_point(&drawing, &view, mx, my, 0);
                ll_start = 1;           /* 始点は渡して、取り消せるように */
            } else
                ll_pend = 1;            /* 終点は動くまで預かる */
            return 1;
        }
        {   /* While ブロック編集 is on, whatever a click makes goes into
               the block's definition rather than into the drawing -- see
               jw_cmd_block_take. */
            int was = have_drawing ? drawing.ndrawn : 0;
            int other = ll_other(button);   /* 連・曲線: (LL) の一つ目かもしれない */

            jw_cmd_point(have_drawing ? &drawing : 0, &view, mx, my, button);
            if (have_drawing && jw_cmd_block_editing()
                && drawing.ndrawn > was)
                jw_cmd_block_take(&drawing, was);
            gaibu_after();
            if (jw_cmd_figure_base(&fig_bx, &fig_by))
                action = JW_ACT_SAVE_FIG;   /* 図形登録 wants a file name */
            if (other) {
                ll_cmd = jw_cmd();
                ll_x = x;
                ll_y = y;
                ll_mx = mx;
                ll_my = my;
                ll_start = 1;
            }
        }
        return 1;
    }
    return 0;
}

/* Typing changes what is on the screen, so the picture is made again here.
   A front end that forgets to would show nothing until something else --
   a mouse move, say -- happened to redraw. */
/* One key while the 書込み文字種変更 dialog has one of its boxes chosen. */
static int moji_key(int c)
{
    char *t = (char *)app_moji_box(moji_focus);
    size_t n;

    if (!t)
        return 0;
    n = strlen(t);
    if (c == 8) {                       /* backspace */
        if (n)
            t[n - 1] = 0;
        return 1;
    }
    if ((c >= '0' && c <= '9') || c == '.' || c == '-') {
        if (n + 1 < sizeof moji_box[0]) {
            t[n] = (char)c;
            t[n + 1] = 0;
        }
        return 1;
    }
    return 0;
}

/* Whether one of the port's windows is up in front of the drawing.
 *
 * Every one of them is a modal dialog in the original: while it is on the
 * screen nothing behind it hears a click or a key.  The presses were already
 * confined -- each press_* returns 0 for a point outside it -- but the keys
 * were not, and Esc or a digit went through to the command bar behind.  Esc
 * shuts one, the way it shuts any dialog with a cancel button. */
static int dialog_open(void)
{
    return mb_open || mb3_open || zoku_open || moji_open || zsel_open || blk_open || be_open
           || jk_open || sd_open || br_open || kh_open || zhen_open
           || sk_open || ld_open || td_open || tgp_open || kj_open
           || lyl_open;
}

/* What the menu says about an item: bit 0 ticked, bit 1 greyed.  It is the
 * original's ON_UPDATE_COMMAND_UI, one handler to an id:
 *
 *   59393 ステータスバー           ticked while the status line shows
 *   32995 ブロックツリー半透明化   ticked while it is on        (FUN_00511e00)
 *   33037 Direct2D                 ticked while it is on        (FUN_00511e50)
 *   33041 ANTIALIAS                greyed unless Direct2D is on, ticked
 *                                  while it is on               (FUN_00511db0)
 *   32967 タグジャンプ             greyed unless a single text is picked
 *                                                               (FUN_00511ca0)
 *   33013 画像編集                 ticked while that is the command
 *   33032 SPEED Data 入力          greyed: the SPEED program is not there
 */
int app_menu_state(int id)
{
    char t[8];

    switch (id) {
    case 59393:
        return ui_status_shown() ? 1 : 0;
    case 57616:                         /* 最新のﾌｧｲﾙ, when there are none */
        return 2;
    case 57643:                         /* 戻る: nothing to take back */
        return jw_cmd_can_undo() ? 0 : 2;
    case 57644:                         /* 進む */
        return jw_cmd_can_redo() ? 0 : 2;
    case 57637:                         /* 貼り付け: the clipboard is empty */
        return jw_cmd_clip_has() ? 0 : 2;
    case 32995:
        return bt_trans ? 1 : 0;
    case 33037:
        return d2d_on ? 1 : 0;
    case 33041:
        return (aa_on && d2d_on ? 1 : 0) | (d2d_on ? 0 : 2);
    case 32967:
        return have_drawing && jw_cmd_sel_text(&drawing, t, (int)sizeof t)
               ? 0 : 2;
    case 33013:
        return jw_cmd() == 0x80f5 ? 1 : 0;
    case 33032:
        return 2;
#ifdef __EMSCRIPTEN__
    case 32954:                         /* no Notepad in a browser */
        return 2;
    case 32977: case 32979: case 32980: case 32984:
        return 2;                       /* ファイル操作: ブラウザにファイルは無い */
#endif
    }
    return 0;
}

const char *app_tag_name(void)
{
    return tag_name;
}

/* whether any of them is up, for whoever is outside */
int app_modal(void)
{
    return dialog_open();
}

static void dialog_close(void)
{
    zoku_open = moji_open = zsel_open = jk_open = 0;
    sd_open = br_open = kh_open = zhen_open = sk_open = ld_open = 0;
    td_open = 0;
    tgp_open = 0;
    kj_open = 0;
    lyl_open = 0;
    lyl_ren = -1;
    sd_caret = 0;
    sd_edit[0] = 0;
}

int app_key(int c)
{
    ll_flush();
    if (mb3_open) {
        if (c == 13 || c == 27 || c == 'y' || c == 'Y' || c == 'n' || c == 'N') {
            mb3_open = 0;
            if (have_drawing)
                jw_cmd_tenku_answer(&drawing, c == 13 || c == 'y' || c == 'Y' ? 1 : c == 27 ? -1 : 0);
        }
        app_paint();
        return 1;
    }
    if (mb_open) {
        if (c == 13 || c == 27)
            mb_close(c == 13);
        app_paint();
        return 1;
    }
    if (tgp_open) {
        if (c == 27) {
            tgp_open = 0;
        } else if (c == 9) {
            /* Tab: the next catalogue file, which is what a click on its name does */
            int nf = jw_tgdat_count(tgp_kind);

            if (nf > 0) {
                tgp_file = (tgp_file + 1) % nf;
                tgp_page = 0;
            }
        } else if (c == 13 || (c >= '1' && c <= '9')) {
            /* Enter takes the first one on the page, a digit the one that
               is that far down it -- the keyboard's way to a click on it */
            int n = c == 13 ? 1 : c - '0';
            int idx = jw_tgdat_index(tgp_kind, tgp_file);
            int per = ui_tgp_per_page(fb.w, fb.h, tgp_kind);
            int total = 0;

            if (tgp_kind == 4) {
                const jw_senkigou *sg = jw_sk_load(idx);

                total = sg ? sg->nitem : 0;
            } else {
                const jw_tategu *t = jw_tategu_load(idx);

                total = t ? t->nitem : 0;
            }
            if (tgp_page * per + n <= total) {
                if (tgp_kind == 4)
                    jw_cmd_kigou_choose(idx, tgp_page * per + n);
                else
                    jw_cmd_tategu_choose(idx, tgp_page * per + n);
                tgp_open = 0;
            }
        }
        app_paint();
        return 1;
    }
    if (kj_open) {
        if (c == 27)
            kj_open = 0;
        app_paint();
        return 1;
    }
    if (td_open && td_key(c)) {         /* the one on top hears first */
        app_paint();
        return 1;
    }
    if (sk_open && sk_key(c)) {
        app_paint();
        return 1;
    }
    if (jk_open && jk_key(c)) {
        app_paint();
        return 1;
    }
    if (be_open && be_key(c)) {
        app_paint();
        return 1;
    }
    if (blk_open && blk_key(c)) {
        app_paint();
        return 1;
    }
    if (moji_open && moji_focus && moji_key(c)) {
        app_paint();
        return 1;
    }
    if (cd_open && cd.caret && cd_key(c)) {
        app_paint();
        return 1;
    }
    if (mk_open && mk_caret && mk_key(c)) {
        app_paint();
        return 1;
    }
    if (kh_open && !cd_open && kh_key(c)) {
        app_paint();
        return 1;
    }
    if (sd_open && sd_caret && sd_key(c)) {
        app_paint();
        return 1;
    }
    if (ld_open && ld_key(c)) {
        app_paint();
        return 1;
    }
    if (br_open && br_key(c)) {
        app_paint();
        return 1;
    }
    if (dialog_open()) {
        /* modal: the drawing and its command bar hear nothing.  Esc shuts
           it without applying what was typed, as a cancel button would;
           the two that name a block keep their own key handlers above. */
        if (c == 27 && !be_open && !blk_open) {
            dialog_close();
            app_paint();
        }
        /* Enter is the default button, as in any Windows dialog: 基本設定,
           寸法設定 and 画面倍率・文字表示 take what is set and close */
        if (c == 13 && !cd_open) {
            if (kh_open) {
                kh_ok();
            } else if (sd_open) {
                sd_commit();
                memcpy(sd_saved, sd_on, sizeof sd_saved);
                sd_have_saved = 1;
                sd_apply(sd_on);
                sd_open = 0;
            } else if (br_open) {
                br_ok(1);               /* IDOK = 指定倍率表示 */
            } else if (ld_open) {
                ld_ok();
            }
            app_paint();
        }
        return 1;
    }
    if (have_drawing && jw_cmd_gaibu_key(&drawing, c)) {
        gaibu_after();
        app_paint();
        return 1;
    }
    if (jw_cmd_box_key(c)) {
        if (c == 13 && have_drawing)    /* 複写・移動のバーは箱の Enter でも置く */
            jw_cmd_numpos_enter(&drawing);
        if (c == 13 && have_drawing && view_ready)  /* 間隔を打っての Enter: 2094 連続複線 */
            jw_cmd_fukusen_enter(&drawing, &view);
        app_paint();
        return 1;
    }
    /* 一文字コマンド.
     *
     * The original keeps the assignment in its own settings
     * (HKCU\Software\Jw_cad\jw_win\KeyCom) as a number per key, and the
     * number is looked up in a table that has not been found in the binary.
     * So the letters were asked of the original instead: each one was sent
     * to its frame with the command put back to 線 first, and the command
     * bar that came up says which command it entered (tools/keysweep.sh).
     * Eighteen of them answered with a bar that matches one of the
     * commands the port already has.
     *
     * Not while 文字 is in force -- there a letter is what is being
     * written -- and not while a box on the bar has the caret, which the
     * line above has already taken care of. */
    if (!jw_cmd_text_mode()) {
        static const struct { char key; unsigned short cmd; } KEY[18] = {
            { 'a', 0x8026 },        /* 文字     */
            { 'b', 0x8004 },        /* 矩形     */
            { 'c', 0x8024 },        /* 図形複写 */
            { 'd', 0x801a },        /* 消去     */
            { 'e', 0x8005 },        /* 円弧     */
            { 'f', 0x8020 },        /* 複線     */
            { 'h', 0x8003 },        /* 線       */
            { 'k', 0x808c },        /* 曲線     */
            { 'l', 0x8073 },        /* 連続線   */
            { 'm', 0x8096 },        /* 図形移動 */
            { 'o', 0x8066 },        /* 接線     */
            { 'q', 0x804e },        /* 包絡処理 */
            { 'r', 0x805b },        /* 面取     */
            { 's', 0x804f },        /* 寸法     */
            { 't', 0x8017 },        /* 伸縮     */
            { 'v', 0x8012 },        /* コーナー処理 */
            { 'w', 0x807c },        /* ２線     */
            { 'x', 0x806a }         /* ハッチ   */
        };
        int i;
        for (i = 0; i < 18; i++)
            if (KEY[i].key == c) {
                app_command(KEY[i].cmd);
                app_paint();
                return 1;
            }
        if (c == 'y') {                 /* 範囲選択 */
            app_command(0x8013);
            app_paint();
            return 1;
        }
        /* Shift つきは別の割り付け (the settings keep it as S_A..S_Z).
           Asked of the original the same way, with the command put back to
           矩形 first so an unchanged bar means the key does nothing. */
        {
            static const struct { char key; unsigned short cmd; } SKEY[13] = {
                { 'B', 0x8003 },    /* 線       */
                { 'D', 0x8005 },    /* 円弧     */
                { 'F', 0x8011 },    /* 点       */
                { 'G', 0x804f },    /* 寸法     */
                { 'M', 0x8017 },    /* 伸縮     */
                { 'N', 0x805b },    /* 面取     */
                { 'O', 0x801a },    /* 消去     */
                { 'Q', 0x8096 },    /* 図形移動 */
                { 'R', 0x8066 },    /* 接線     */
                { 'S', 0x8068 },    /* 接円     */
                { 'W', 0x807e },    /* 多角形   */
                { 'X', 0x808c },    /* 曲線     */
                { 'Y', 0x804e }     /* 包絡処理 */
            };
            for (i = 0; i < 13; i++)
                if (SKEY[i].key == c) {
                    app_command(SKEY[i].cmd);
                    app_paint();
                    return 1;
                }
        }
    }
    if (c == 27) {              /* Esc steps the command back (see jw_cmd_esc_key) */
        jw_cmd_esc_key(have_drawing ? &drawing : 0);
        app_paint();
        return 1;
    }
    if (c == 13 && have_drawing && view_ready
        && jw_cmd_fukusen_enter(&drawing, &view)) {   /* 2094 連続複線 */
        app_paint();
        return 1;
    }
    if (c == 13 && have_drawing && jw_cmd_enter_key(&drawing)) {
        if (jw_cmd_moji_go())
            action = JW_ACT_MOJI_EDIT;      /* 外部エディタ, once the range is in */
        gaibu_after();
        app_paint();
        return 1;
    }
    if (c == 32 && !jw_cmd_text_mode()) {
        jw_cmd_space();         /* Space turns 水平・垂直 over */
        app_paint();
        return 1;
    }
    if (!jw_cmd_text_mode())
        return 0;
    if (c == 9 || c == 13)      /* the box is one line: Tab and Enter are not text */
        return 0;
    jw_cmd_key(c);
    app_paint();
    return 1;
}

int app_shift_enter(void)
{
    ll_flush();
    if (!have_drawing || !jw_cmd_shift_enter_key(&drawing))
        return 0;
    app_paint();
    return 1;
}

int app_compose(int c)
{
    if (!jw_cmd_text_mode())
        return 0;
    if (c < 0)
        jw_cmd_compose_clear();
    else
        jw_cmd_compose_key(c);
    app_paint();
    return 1;
}

int app_take_action(void)
{
    int a = action;

    action = JW_ACT_NONE;
    if (a == JW_ACT_NONE && jw_pr_want())
        a = JW_ACT_PLOT;                /* 印刷の命令の 印刷 (L) */
    return a;
}

static jw_obj new_hidden[8];     /* the six, kept for app_save */
static int nnew_hidden;

int app_save(unsigned char **out, long *n)
{
    int added = 0, i, ok;

    ll_flush();                         /* ２線の預かった終点を先に */
    if (!have_drawing)
        return 0;
    /* A drawing begun with 新規 does not hold the six hidden settings records
       (see app_new), but every file Jw_cad writes ends its drawn elements with
       them -- so put them on for the write, as the original makes them when
       it writes, and take them off again.  A drawing from a version 700 file has
       them already.  One from a version 600 sample (orig/Test*.jww) does not, and
       the original writes them into its save of one too (decomp/res/mentori.jww is
       Test5 saved by the original: 89 drawn + 3 + the six), so a first save then a
       reopen shows six more elements, once -- tests/saverepeat_test.c pins that. */
    if (nnew_hidden > 0) {
        int have = 0;

        for (i = 0; i < drawing.ndrawn; i++)
            if (drawing.obj[i].cls == JW_MOJI && drawing.obj[i].d[1] == -1000.0)
                have = 1;
        if (!have)
            for (i = 0; i < nnew_hidden; i++) {
                jw_obj *p = jw_add(&drawing, new_hidden[i].cls);

                if (!p)
                    break;
                *p = new_hidden[i];
                added++;
            }
    }
    ok = jw_write(&drawing, out, n);
    while (added-- > 0)
        jw_remove(&drawing, drawing.ndrawn - 1);
    if (!ok)
        return 0;
    clean_stamp = jw_cmd_edit_stamp();
    jw_umekomi_saved(time(0));          /* 埋め込み文字の =F ほか: 保存日時 */
    return 1;
}

/* Whether there is anything on screen that a 新規 or a 開く would throw
   away: the drawing is not as it was when it was opened or last saved. */
int app_modified(void)
{
    return have_drawing && jw_cmd_edit_stamp() != clean_stamp;
}


/* The drawing as a .jww without calling it saved: for the copy a front end
   keeps in case the program dies (autosave).  The drawing stays "modified". */
int app_save_backup(unsigned char **out, long *n)
{
    unsigned keep = clean_stamp;
    time_t keep_t = jw_umekomi_saved_at();
    int ok = app_save(out, n);

    clean_stamp = keep;
    jw_umekomi_saved(keep_t);
    return ok;
}

/* A drawing brought back from such a copy is not on disk as it is now. */
void app_mark_modified(void)
{
    clean_stamp = ~jw_cmd_edit_stamp();
}
/* The same drawing as DXF, which is what 「DXF形式で保存」 writes. */
int app_save_dxf(unsigned char **out, long *n)
{
    jw_dxf_opt opt;

    if (!have_drawing)
        return 0;
    /* 基本設定 DXF・SXF・JWC の DXF書出し（CDxfPage の OK FUN_004a9a90:
       2202 → DAT_00a0eed4、2203 → eed0、2214 → eee0）。src/dxf.c の注 */
    opt.point_circle = kh_value_tab(7, 2202);
    opt.layer_number = kh_value_tab(7, 2203);
    opt.utf8 = kh_value_tab(7, 2214);
    return jw_dxf_write_opt(&drawing, &opt, out, n);
}

/* 「SFC形式で保存」 (src/sfcwrite.c).  The header carries the name it is
   being saved under and the moment, spelled the way the original spells it:
   the year, month and day unpadded and the time padded. */
int app_save_sfc(const char *name, unsigned char **out, long *n)
{
    char stamp[64];
    time_t now = time(0);
    struct tm *t = localtime(&now);

    if (!have_drawing)
        return 0;
    sprintf(stamp, "%d-%d-%dT%02d:%02d:%02d", t->tm_year + 1900,
            t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return jw_sfc_write(&drawing, name, stamp, out, n);
}

/* 「JWC形式で保存」 (src/jwcwrite.c). */
int app_save_jwc(unsigned char **out, long *n)
{
    if (!have_drawing)
        return 0;
    return jw_jwc_write(&drawing, out, n);
}

/* 環境設定ファイル 書出し (src/cmd.c jw_env_write) */
int app_save_env(const char *name, unsigned char **out, long *n)
{
    if (!have_drawing)
        return 0;
    return jw_env_write(&drawing, name, out, n);
}

/* 環境設定ファイル 読込み */
int app_open_env(const unsigned char *b, long n)
{
    if (!have_drawing)
        app_new();
    if (!have_drawing)
        return 0;
    if (!jw_env_read(&drawing, b, n)) {
        last_error = "not a JWF";
        return 0;
    }
    last_error = "";
    return 1;
}

/* The left button came up.  Only 連続線's 手書線 cares: the stroke ends there.
   Returns 1 when the picture changed. */
int app_release(int x, int y, int button)
{
    double mx, my;

    if (button != 0 || !have_drawing || !view_ready || !jw_cmd_freehand())
        return 0;
    to_paper(x, y, &mx, &my);
    return jw_cmd_release(&drawing, &view, mx, my);
}

int app_move(int x, int y)
{
    double mx, my;
    jw_obj o[JW_CMD_MAXFIG];

    if ((ll_pend || ll_start) && (abs(x - ll_x) >= ll_slop || abs(y - ll_y) >= ll_slop))
        ll_flush();

    {   /* マウスが札に乗れば札は隠れる */
        rect_t r;

        if (notice_at(&r) && x >= r.x && x < r.x + r.w && y >= r.y && y < r.y + r.h) {
            jw_cmd_notice_clear();
            return 1;
        }
    }
    if (ui_popup_up())
        return ui_popup_move(x, y);
    if (!view_ready || !in_view(x, y)) {
        int was = cross_have && cross_on();

        cross_have = 0;
        return was;                     /* クロスラインカーソルを消すので描き直す */
    }
    to_paper(x, y, &mx, &my);
    jw_cmd_track(mx, my);
    cross_x = mx;
    cross_y = my;
    cross_have = 1;
    if (have_drawing && jw_cmd_freehand() && jw_cmd_drag(&drawing, &view, mx, my))
        return 1;                   /* 手書線: a stroke being drawn */
    if (have_drawing && jw_cmd_stretch_move(&drawing, &view, mx, my))
        return 1;                   /* 伸縮の (R) 線切断 */
    if (jw_cmd_sunpo_move(&view, mx, my))
        return 1;                   /* 寸法 ＝ の「ﾏｳｽ移動で確定」 */
    {   /* the range box and the selection being dragged both follow the
           mouse, so the window has to be told to paint again */
        double a, b, c, e;
        if (jw_cmd_sel_box(&a, &b, &c, &e) || jw_cmd_sel_ghost(&a, &b))
            return 1;
    }
    if (have_drawing) {             /* パラメトリック変形 の仮表示 */
        jw_drawing one;

        if (jw_cmd_param_preview(&drawing, &one))
            return 1;
    }
    if (have_drawing) {             /* ぶら下がる建具も 動くたびに描き直す */
        jw_drawing one;

        if (jw_cmd_tategu_preview(&drawing, &one))
            return 1;
    }
    return jw_cmd_pending(have_drawing ? &drawing : 0, o,
                          JW_CMD_MAXFIG) > 0
           || cross_on();               /* クロスラインカーソルはマウスについて動く */
}

void app_chrome(int on)
{
    chrome_on = on;
}

int app_chrome_h(void)
{
    return chrome_on ? JW_CHROME_H : 0;
}

void app_title(const char *name)
{
    const char *tail = " - jw_win";
    size_t n = name ? strlen(name) : 0;

    {   /* the name without its .jww, for what 画像編集 puts a folder's name to */
        char nm[160];
        size_t m = n < sizeof nm - 1 ? n : sizeof nm - 1;

        memcpy(nm, name ? name : "", m);
        nm[m] = 0;
        if (m > 4 && !strcmp(nm + m - 4, ".jww"))
            nm[m - 4] = 0;
        jw_cmd_gazou_doc(doc_dir, nm);
    }
    /* 埋め込み文字のファイル名（doc+0x16d8） */
    jw_umekomi_doc(doc_dir, name ? name : "");
    if (!name || !*name) {
        /* 無題, the way the original starts */
        strcpy(title, "\x96\xb3\x91\xe8 - jw_win");
        return;
    }
    if (n > sizeof title - strlen(tail) - 1)
        n = sizeof title - strlen(tail) - 1;
    memcpy(title, name, n);
    strcpy(title + n, tail);
}

int app_resize(int w, int h)
{
    if (w < 1)
        w = 1;
    if (h < 1)
        h = 1;
    if (fb.w == w && fb.h == h)
        return 1;
    fb_free(&fb);
    if (!fb_init(&fb, w, h))
        return 0;
    fb_free(&chrome);
    if (chrome_on && !fb_init(&chrome, w, JW_CHROME_H))
        return 0;
    free(rgba);
    rgba_n = w * (h + app_chrome_h()) * 4;
    rgba = (unsigned char *)malloc((size_t)rgba_n);
    if (!rgba)
        return 0;
    /* the bars keep their size, so the drawing area grows: refit */
    app_fit();
    return 1;
}

/* The drawing the original has open before anything is loaded.  It is not
 * built here: it is Jw_cad's own.  Started with no file and told to save at
 * once, in the reference environment (tools/refenv.sh), it writes
 * decomp/res/new.jww, and tools/mknew.py bakes that into src/gen/newjww.c.
 * Reading it back gives the sixteen layer groups, the pen table, the line
 * types, the hatch and dimension settings and the ten text styles exactly as
 * the original has them -- and the file header with them, so a drawing begun
 * from nothing can be saved and read again in Jw_cad.  Its status line reads
 * "A-2  S=1/100  [0-0]", which is what docs/ref_start.png shows.
 *
 * The file is not quite empty: it carries six hidden text records Jw_cad
 * keeps its printer and view settings in ("Printer_Orientation = 0" and so
 * on).  Those are made when a drawing is written, not held in the document
 * -- FUN_005707f0 writes them and FUN_00572880 reads them back into the
 * settings -- so the six are dropped here and the new drawing is empty, the
 * way the original's is: its layer bar shows every layer with nothing on it.
 * The port does not write them back, which loses nothing but the settings
 * the original would have put in the file. */
void app_new(void)
{
    jw_drawing d;

    ll_pend = ll_start = 0;
    jw_umekomi_saved(0);                /* 埋め込み文字: 保存日時は無い */
    jw_pr_new_doc();                    /* 連続出力の箱を 0 に（FUN_004d20c0） */

    bt_close();
    ly_reset();

    if (!jw_parse(&d, jw_new_jww, jw_new_jww_len)) {
        last_error = d.error;   /* only reachable if the bake went wrong */
        jw_free(&d);
        return;
    }
    nnew_hidden = d.nobj > 8 ? 8 : d.nobj;
    memcpy(new_hidden, d.obj, (size_t)nnew_hidden * sizeof new_hidden[0]);
    d.nobj = 0;
    d.ndrawn = 0;
    if (have_drawing)
        jw_free(&drawing);
    drawing = d;
    have_drawing = 1;
    have_file = 0;
    last_error = "";
    jw_cmd_reset();
    clean_stamp = 0;
    new_count++;
    app_title("");              /* 無題 */
    app_fit();
    vw_reset();             /* 前倍率・記憶・マークジャンプ も初めに */
}

int app_new_count(void)
{
    return new_count;
}

int app_open(const unsigned char *b, long n)
{
    jw_drawing d;

    ll_pend = ll_start = 0;
    jw_umekomi_saved(0);                /* 開いたファイルの日時は表側が知る */

    bt_close();
    ly_reset();

    if (!jw_parse(&d, b, n)) {
        last_error = d.error;
        jw_free(&d);
        return 0;
    }
    if (have_drawing)
        jw_free(&drawing);
    drawing = d;
    have_drawing = 1;
    have_file = 1;
    /* 図面が持つ線種（2〜9・11〜19）が描き手の表に入る。原典の Pen\File
       （既定 1）の働きで、あとから 基本設定 の OK をすればそちらが勝つ */
    jw_ltype_from(&drawing);
    last_error = "";
    jw_cmd_reset();
    clean_stamp = 0;
    app_fit();
    vw_reset();             /* 前倍率・記憶・マークジャンプ も初めに */
    return 1;
}

/* 「DXFファイルを開く」.  A DXF is read into whatever is open rather than in
   place of it: the sheet, the pens and the layer names all come from the
   document, and only the scale is taken from the DXF (src/dxfread.c).  With
   nothing open it goes into a new drawing. */
int app_open_dxf(const unsigned char *b, long n)
{
    if (!have_drawing)
        app_new();
    if (!have_drawing)
        return 0;
    if (!jw_dxf_read(&drawing, b, n)) {
        last_error = "not a DXF";
        return 0;
    }
    have_file = 0;              /* the .dxf is not a file 上書 can write */
    last_error = "";
    jw_cmd_reset();
    clean_stamp = ~0u;          /* read into the drawing: not what any file holds */
    app_fit();
    vw_reset();             /* 前倍率・記憶・マークジャンプ も初めに */
    return 1;
}

/* 「SFCファイルを開く」.  Like a DXF, an SFC is read into whatever is
   open rather than in place of it (src/sfcread.c). */
int app_open_sfc(const unsigned char *b, long n)
{
    if (!have_drawing)
        app_new();
    if (!have_drawing)
        return 0;
    if (!jw_sfc_read(&drawing, b, n)) {
        last_error = "not an SFC";
        return 0;
    }
    have_file = 0;
    last_error = "";
    jw_cmd_reset();
    clean_stamp = ~0u;          /* read into the drawing: not what any file holds */
    app_fit();
    vw_reset();             /* 前倍率・記憶・マークジャンプ も初めに */
    return 1;
}

/* 「JWCファイルを開く」 (src/jwcread.c), like the other two. */
int app_open_jwc(const unsigned char *b, long n)
{
    if (!have_drawing)
        app_new();
    if (!have_drawing)
        return 0;
    if (!jw_jwc_read(&drawing, b, n)) {
        last_error = "not a JWC";
        return 0;
    }
    have_file = 0;
    last_error = "";
    jw_cmd_reset();
    clean_stamp = ~0u;          /* read into the drawing: not what any file holds */
    app_fit();
    vw_reset();             /* 前倍率・記憶・マークジャンプ も初めに */
    return 1;
}

const char *app_error(void)
{
    return last_error;
}

const jw_drawing *app_drawing(void)
{
    return have_drawing ? &drawing : 0;
}

/* The drawing, kept as it was last drawn.
 *
 * While a command is part way through, every mouse move asks for a paint so
 * the provisional figure can follow the cursor -- and a paint drew the whole
 * drawing again underneath it.  On Test7 (4,207 elements) that is 70 ms a
 * move, about fourteen a second.  But between two moves the drawing, the
 * view and the window round it have not changed; only the provisional figure
 * on top has.  So the drawing area is kept after jw_draw, under a key made of
 * everything jw_draw reads -- the drawing (its header struct, its elements,
 * its string pool), the view, the renderer's own knobs -- and of the pixels
 * ui_paint left in the area before jw_draw went over them.  When the key
 * comes round again the area is copied back instead of drawn.
 *
 * The key is a 64-bit hash, so a stale picture would take a collision.
 * tests/cmdfuzz_test.c paints both ways after every action of its walks and
 * holds the two pictures to be the same pixel for pixel. */
static unsigned int *base_px;
static size_t base_cap;
static unsigned long long base_key;
static int base_ok;
static int base_off;            /* app_paint_cache(0): always draw */

/* Off leaves the kept picture alone, so that a test can paint once each way
   and still find the next cached paint a hit when nothing has changed. */
void app_paint_cache(int on)
{
    base_off = !on;
}

static unsigned long long mix(unsigned long long h, const void *p, size_t n)
{
    const unsigned char *b = (const unsigned char *)p;
    size_t i = 0;

    for (; i + 8 <= n; i += 8) {
        unsigned long long w;

        memcpy(&w, b + i, 8);
        h = (h ^ w) * 0x100000001b3ULL;
        h ^= h >> 29;
    }
    for (; i < n; i++)
        h = (h ^ b[i]) * 0x100000001b3ULL;
    return h;
}

/* 日影図の 確認 の窓（原典 hk_pv1〜pv6）: 作図の領域を白くして 針金（黒の辺・紫の点線の測定面）を描き、
 * 左上に 方位のしるし（赤い縁の黒い円に 赤い矢）を置く。矢は方位角の向き */
static void pv_px(int x, int y, unsigned int c)
{
    if (x >= 0 && y >= 0 && x < fb.w && y < fb.h)
        fb.px[(size_t)y * fb.w + x] = c;
}

static void pv_line(int x0, int y0, int x1, int y1, unsigned int c)
{
    int dx = x1 > x0 ? x1 - x0 : x0 - x1, dy = y1 > y0 ? y1 - y0 : y0 - y1;
    int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1, err = dx - dy;

    for (;;) {
        int e2;

        pv_px(x0, y0, c);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

static void pv_compass(double az)
{
    /* 原典の画面 (115.5, 114.5) から窓の枠 (8, 51) を引いた位置。円は 縁の幅 1 の赤・中は黒、矢は 先・右・凹み・左 の
       四つの点（hk_pv3 に合わせた。az = 0 で先が真上、az だけ回す） */
    const double cx = 107.5, cy = 63.5, R = 19.25;
    static const double P[4][2] = { { 115.5 - 115.5, 97.0 - 114.5 }, { 125.0 - 115.5, 131.0 - 114.5 },
                                    { 115.5 - 115.5, 125.0 - 114.5 }, { 106.0 - 115.5, 132.0 - 114.5 } };
    double a = az * 3.14159265358979323846 / 180.0, ca = cos(a), sa = sin(a);
    int x, y, i, qx[4], qy[4];

    for (y = (int)(cy - R - 1); y <= (int)(cy + R + 1); y++)
        for (x = (int)(cx - R - 1); x <= (int)(cx + R + 1); x++) {
            double dx = x - cx, dy = y - cy, r = sqrt(dx * dx + dy * dy);

            if (r < R - 0.5)
                pv_px(x, y, 0x000000u);
            else if (r <= R + 0.5)
                pv_px(x, y, 0xff0000u);
        }
    for (i = 0; i < 4; i++) {
        qx[i] = (int)floor(cx + P[i][0] * ca - P[i][1] * sa + 0.5);
        qy[i] = (int)floor(cy + P[i][0] * sa + P[i][1] * ca + 0.5);
    }
    for (i = 0; i < 4; i++)
        pv_line(qx[i], qy[i], qx[(i + 1) % 4], qy[(i + 1) % 4], 0xff0000u);
}

static void draw_pv(void)
{
    const rect_t *r = &view.clip;
    jw_drawing one = drawing;       /* 層・ペンの表は図面のもの、線だけ別に */

    fb_fill(&fb, r->x, r->y, r->w, r->h, 0xffffffu);
    one.obj = 0;
    one.nobj = one.ndrawn = one.cobj = 0;
    if (jw_cmd_hikage_preview(&drawing, &view, &one) > 0)
        jw_draw(&fb, &view, &one);
    free(one.obj);
    pv_compass(jw_cmd_hikage_pv_az());
}

/* ２．５D の 透視図・鳥瞰図・アイソメ: 原典は view+0x859c が立つあいだ 図面の代わりに
   CZukei25D の slot 5 (FUN_00617640) を描く。層・ペンは図面のもの */
static void draw_d25(void)
{
    jw_drawing one = drawing;

    one.obj = 0;
    one.nobj = one.ndrawn = one.cobj = 0;
    if (jw_d25_view(&drawing, &one) > 0)
        jw_draw(&fb, &view, &one);
    free(one.obj);
}

static void draw_drawing(void)
{
    const rect_t *r = &view.clip;
    unsigned long long h = 0xcbf29ce484222325ULL;
    int x0 = r->x < 0 ? 0 : r->x, y0 = r->y < 0 ? 0 : r->y;
    int x1 = r->x + r->w > fb.w ? fb.w : r->x + r->w;
    int y1 = r->y + r->h > fb.h ? fb.h : r->y + r->h;
    int w = x1 - x0, y;
    size_t need;

    if (base_off || w <= 0 || y1 <= y0) {
        jw_draw_frame(&fb, &view, &drawing);     /* 用紙枠 (2532): 要素より先 */
        jw_draw(&fb, &view, &drawing);
        return;
    }
    need = (size_t)w * (size_t)(y1 - y0);
    h = mix(h, &view, sizeof view);
    h = mix(h, &fb.w, sizeof fb.w);
    h = mix(h, &fb.h, sizeof fb.h);
    h = mix(h, &jw_round_x, sizeof jw_round_x);
    h = mix(h, &jw_round_y, sizeof jw_round_y);
    h = mix(h, &jw_line_open, sizeof jw_line_open);
    h = mix(h, &jw_mm_per_bit, sizeof jw_mm_per_bit);
    h = mix(h, &jw_stretch, sizeof jw_stretch);
    /* 基本設定 の 描く順・透過（OK で変わっても 図面は同じなので、鍵に入れないと
       古い絵が当たる） */
    h = mix(h, &jw_draw_images_first, sizeof jw_draw_images_first);
    h = mix(h, &jw_draw_transparent, sizeof jw_draw_transparent);
    h = mix(h, &jw_draw_reverse, sizeof jw_draw_reverse);
    h = mix(h, &jw_draw_texts_last, sizeof jw_draw_texts_last);
    h = mix(h, &jw_draw_textframe, sizeof jw_draw_textframe);   /* 【文字枠】 */
    h = mix(h, &jw_draw_paper_frame, sizeof jw_draw_paper_frame);   /* 用紙枠 */
    h = mix(h, &jw_draw_text_bg, sizeof jw_draw_text_bg);           /* 1886・1900 */
    h = mix(h, &jw_draw_text_bg_expand, sizeof jw_draw_text_bg_expand);
    {   /* an outline font arriving changes how its texts come out */
        int fg = jw_outfont_gen();

        h = mix(h, &fg, sizeof fg);
    }
    h = mix(h, &drawing, sizeof drawing);
    {
        int hn = jw_draw_hl_n();

        h = mix(h, &hn, sizeof hn);
        if (hn > 0)
            h = mix(h, jw_draw_hl_path(), (size_t)hn * sizeof(int));
    }
    if (drawing.obj && drawing.nobj > 0)
        h = mix(h, drawing.obj, (size_t)drawing.nobj * sizeof *drawing.obj);
    if (drawing.pool && drawing.npool > 0)
        h = mix(h, drawing.pool, (size_t)drawing.npool);
    for (y = y0; y < y1; y++)
        h = mix(h, fb.px + (size_t)y * fb.w + x0, (size_t)w * sizeof *fb.px);

    if (base_ok && h == base_key && need <= base_cap) {
        for (y = y0; y < y1; y++)
            memcpy(fb.px + (size_t)y * fb.w + x0,
                   base_px + (size_t)(y - y0) * w, (size_t)w * sizeof *fb.px);
        return;
    }
    jw_draw_frame(&fb, &view, &drawing);
    jw_draw(&fb, &view, &drawing);
    base_ok = 0;
    if (need > base_cap) {
        unsigned int *p = (unsigned int *)realloc(base_px, need * sizeof *p);

        if (!p)
            return;
        base_px = p;
        base_cap = need;
    }
    for (y = y0; y < y1; y++)
        memcpy(base_px + (size_t)(y - y0) * w,
               fb.px + (size_t)y * fb.w + x0, (size_t)w * sizeof *fb.px);
    base_key = h;
    base_ok = 1;
}

void app_paint(void)
{
    int i, n;

    tgp_check();

    if (!fb.px)
        return;
    /* The status line's readout -- the angle and length of the line being
       drawn, a rectangle's W and H -- is worked out by jw_cmd_pending, and
       that used to run only further down, after ui_paint had already
       written the status line.  So a paint showed the readout of the paint
       before it: after a click it stayed stale until the mouse moved, and
       painting twice gave two different pictures (tests/cmdfuzz_test.c
       found it by painting twice).  Work it out first. */
    if (view_ready && have_drawing) {
        jw_obj o[JW_CMD_MAXFIG];

        jw_cmd_pending(&drawing, o, JW_CMD_MAXFIG);
    }
    ui_paint(&fb, have_drawing ? &drawing : 0,
             view_ready ? view.scale * JW_SCREEN_MM_PER_PX : 0.0,
             have_file, jw_cmd_can_undo());
    if (have_drawing) {
        if (!view_ready)
            app_fit();
        ui_view_rect(fb.w, fb.h, &view.clip);
        bt_refresh();
        bt_hl();
        if (jw_cmd_hikage_pv_on())
            draw_pv();
        else if (jw_cmd() == JW_CMD_25D && jw_d25_mode())
            draw_d25();                 /* ２．５D の立体（src/d25view.c） */
        else {
            jw_draw_textframe = br_textframe;   /* 画面だけ（印刷は描かない） */
            draw_drawing();
            jw_draw_textframe = 0;
        }
    }
    {
        /* The element the command is part way through.  The original
           draws it in 仮表示色 and not in the element's own pen --
           ff0000 here, the same colour the range box gets.  Its own
           window says so: a rectangle with one corner down, a line
           with one end down and a circle with its centre down all came
           back drawn in ff0000 (tools/probe75.sh), and the basic
           settings have a 仮表示色 (1122) to name it.  jw_draw_kari is
           how src/draw.c is told.

           It goes through a raster op as well: the original brackets
           the draw with SetROP2(R2_NOTXORPEN) and SetROP2(R2_COPYPEN)
           -- FUN_004bbad0 and FUN_004bbaa0, which raise and drop the
           same flag -- so a pixel becomes ~(pen ^ what was there).
           Over the paper that is ff0000 and over one of the drawing's
           own black lines 00ffff, both of which its window gave back
           (tools/probe78.sh, probe79.sh).  jw_rop in src/fb.h is it. */
        jw_obj o[JW_CMD_MAXFIG];
        int n;
        if (view_ready && have_drawing
            && (n = jw_cmd_pending(&drawing, o, JW_CMD_MAXFIG)) > 0) {
            jw_drawing one = drawing;
            ui_view_rect(fb.w, fb.h, &view.clip);
            one.obj = o;
            one.nobj = one.ndrawn = n;
            jw_draw_kari = 1;
            jw_draw(&fb, &view, &one);
            jw_draw_kari = 0;
        }
        cross_paint();                  /* 2437 クロスラインカーソル */
        ryo_paint(&fb);                 /* 両ボタンドラッグの枠と字（src/ryoboton.h） */
    }
    {
        /* and the 図形 waiting to be put down, which is the same
           thing writ large: the whole figure, where the click would put
           it, in 仮表示. */
        jw_drawing one;

        if (view_ready && have_drawing
            && jw_cmd_figure_preview(&drawing, &one)) {
            ui_view_rect(fb.w, fb.h, &view.clip);
            jw_draw_kari = 1;
            jw_draw(&fb, &view, &one);
            jw_draw_kari = 0;
        }
    }
    {
        jw_drawing one;

        if (view_ready && have_drawing && jw_cmd_tategu_preview(&drawing, &one)) {
            ui_view_rect(fb.w, fb.h, &view.clip);
            jw_draw_kari = 1;
            jw_draw(&fb, &view, &one);
            jw_draw_kari = 0;
        }
    }
    {
        jw_drawing one;

        if (view_ready && have_drawing && jw_cmd_param_preview(&drawing, &one)) {
            ui_view_rect(fb.w, fb.h, &view.clip);
            jw_draw_kari = 1;
            jw_draw(&fb, &view, &one);
            jw_draw_kari = 0;
        }
    }
    {
        jw_drawing one;

        if (view_ready && have_drawing && jw_cmd_gaibu_preview(&drawing, &one)) {
            ui_view_rect(fb.w, fb.h, &view.clip);
            jw_draw_kari = 1;
            jw_draw(&fb, &view, &one);
            jw_draw_kari = 0;
        }
    }
    if (view_ready && have_drawing) {
        double a, b, e, f;
        ui_view_rect(fb.w, fb.h, &view.clip);
        if (jw_cmd_sel_box(&a, &b, &e, &f))
            jw_draw_box(&fb, &view, a, b, e, f);
        {   /* 複写・移動 の仮表示（倍率・回転も置くときと同じ） */
            jw_drawing gh;

            if (jw_cmd_sel_preview(&drawing, &gh))
                jw_draw(&fb, &view, &gh);
        }
    }
    /* the 文字 command's box goes over the drawing */
    if (jw_cmd_text_mode())
        ui_textbox(&fb, jw_cmd_line(), jw_cmd_compose());
    if (zoku_open)
        ui_zoku(&fb, have_drawing ? &drawing : 0, zoku_color, zoku_ltype);
    if (moji_open && have_drawing)
        ui_moji(&fb, &drawing, moji_style);
    if (moji_open && moji_drop)
        ui_moji_drop(&fb);
    if (zsel_open)
        ui_zokusel(&fb, zsel_on);
    if (zhen_open)
        ui_zokuhen(&fb, zhen_on);
    if (blk_open)
        ui_blkname(&fb, blk_name, blk_pref, blk_attr != 1, blk_attr);
    if (be_open)
        ui_blkedit(&fb, be_name, be_all);
    if (kh_open)
        ui_kihon(&fb, kh_tab, kh_on[kh_tab]);
    if (cd_open)
        ui_colordlg(&fb, &cd);
    if (jk_open)
        ui_jikkaku(&fb, jk_angle, jk_on, 1);
    lyl_paint();                        /* レイヤ一覧（名前の窓 373 はその上） */
    if (td_open) {
        ui_tdlg(&fb, td_t, td_on, td_txtp, td_caret);
        if (td_dl >= 0)
            ui_tdlg_drop(&fb, td_t, td_dl, td_itemp, td_nitems, -1);
    }
    if (sd_open)
        ui_sunpodlg(&fb, sd_on, sd_caret, sd_edit);
    if (br_open)
        ui_bairitsu(&fb, br_zoom, br_on, br_en, br_sel);
    if (mk_open)
        ui_mojikijun(&fb, mk_open == 2 ? jw_cmd_mp_base_now()
                                       : jw_cmd_moji_base_now(), mk_caret);
    if (sk_open) {
        sk_fill();
        ui_shakudo(&fb, sk_num, sk_den, sk_listp, sk_group, sk_on, sk_caret);
    }
    if (ld_open) {
        ui_layerdlg_state(ld_caret, ld_back != 0);
        ui_layerdlg(&fb, have_drawing ? &drawing : 0, ld_on);
    }
    if (tgp_open)
        ui_tgp(&fb, tgp_kind, tgp_file, tgp_page, -1);
    if (kj_open)
        ui_kijun(&fb, kj_sel);
    if (bt_open)
        bt_paint();
    if (mb_open)
        ui_msgbox(&fb, "jw_win", mb_kind ? mb_text : MB_TEXT, mb_kind != 2);
    if (mb3_open)
        ui_msgbox3(&fb, "jw_win", MB3_TEXT);
    {   /* 札（知らせ）: 原典はポップアップの窓なので 図面の窓たちの上に */
        rect_t r;
        const char *s = notice_at(&r);

        if (s)
            ui_notice(&fb, nt_x, nt_y, s);
    }
    /* last of all, so it covers everything: the menu that is open */
    ui_popup_draw(&fb);
    if (chrome_on && chrome.px) {
        ui_caption(&chrome, 0, chrome.w, title);
        ui_menu(&chrome, JW_CAPTION_H, chrome.w);
    }
    if (!rgba)
        return;
    {   /* the chrome first, then the client under it */
        int k = 0;
        if (chrome_on && chrome.px) {
            n = chrome.w * chrome.h;
            for (i = 0; i < n; i++, k++) {
                unsigned int c = chrome.px[i];
                rgba[4 * k + 0] = (unsigned char)(c >> 16);
                rgba[4 * k + 1] = (unsigned char)(c >> 8);
                rgba[4 * k + 2] = (unsigned char)c;
                rgba[4 * k + 3] = 255;
            }
        }
        n = fb.w * fb.h;
        for (i = 0; i < n; i++, k++) {
            unsigned int c = fb.px[i];
            rgba[4 * k + 0] = (unsigned char)(c >> 16);
            rgba[4 * k + 1] = (unsigned char)(c >> 8);
            rgba[4 * k + 2] = (unsigned char)c;
            rgba[4 * k + 3] = 255;
        }
    }
}

const fb_t *app_fb(void)
{
    return &fb;
}

unsigned char *app_rgba(void)
{
    return rgba;
}

/* ファイル操作・図面情報コピー・レイヤ一覧（app.c の static を使う） */
#include "fileops.h"
