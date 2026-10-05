#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "app.h"
#include "ui.h"
#include "text.h"
#include "draw.h"
#include "view.h"
#include "cmd.h"
#include "gen/layout.h"
#include "gen/cmds.h"
#include "gen/newjww.h"

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
    view.oy = wy + (view.by - sy) / view.scale;
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
static int press_layer(int g, int n, int button)
{
    jw_group *grp;
    int i, wg = 0;

    if (!have_drawing)
        return 0;
    for (i = 0; i < 16; i++)
        if (drawing.group[i].state == 3)
            wg = i;
    grp = &drawing.group[wg];
    if (button != 0) {
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
    {
        int *st = g == 0 ? &grp->layer[n].state : &drawing.group[n].state;
        if (*st == 3)
            return 0;
        *st = *st == 2 ? 0 : *st == 0 ? 1 : 2;
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
    zsel_open = 1;
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
        jk_on[i] = (unsigned char)ui_jikkaku_on(i);
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

int app_shakudo_open(void)
{
    return sk_open;
}
static char sk_num[16] = "1", sk_den[16] = "100";
static unsigned char sk_on[64];
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
        sk_on[i] = (unsigned char)ui_shakudo_on(i);
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

/* Ok: the two boxes become the group's scale.  1/200 is kept as the 200 the
   file carries, so a numerator of anything but 1 divides into it. */
static void sk_apply(void)
{
    double num = atof(sk_num), den = atof(sk_den);
    double sc;
    int g, all = 0, i, n = ui_shakudo_n();

    for (i = 0; i < n && i < (int)sizeof sk_on; i++)
        if (ui_shakudo_id(i) == 1954)
            all = sk_on[i];
    if (!have_drawing || num == 0.0 || den <= 0.0)
        return;
    sc = den / num;
    if (sc <= 0.0)
        return;
    if (!all) {
        drawing.group[sk_group].scale = sc;
        return;
    }
    for (g = 0; g < 16; g++)
        if (drawing.group[g].state == 1 || drawing.group[g].state == 3)
            drawing.group[g].scale = sc;
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

int app_layerdlg_open(void)
{
    return ld_open;
}

static void ld_start(void)
{
    int i, n = ui_layerdlg_n();

    for (i = 0; i < n && i < (int)sizeof ld_on; i++)
        ld_on[i] = (unsigned char)ui_layerdlg_on(i);
    ld_open = 1;
}

static int press_layerdlg(int x, int y, int button)
{
    int id = ui_layerdlg_hit(fb.w, fb.h, x, y), i, n = ui_layerdlg_n();
    int lay;

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* OK */
        ld_open = 0;
        return 1;
    }
    if (id == 2000 || id == 1073 || id == 1141) {
        /* 全レイヤ編集, 全レイヤ非表示 and 一括, as the original left the
         * file after pressing each of them:
         *
         *   全レイヤ編集    every layer of the group being written to goes
         *                  to 編集可能, and every other layer group with it
         *   全レイヤ非表示  the same the other way: every layer and every
         *                  other group goes out
         *   一括          the layers walk on one step together, the way a
         *                  single one does when it is clicked --
         *                  編集可能 → 非表示 → 表示のみ → 編集可能, which is
         *                  what three presses in a row drew out of it
         *
         * The one being written to stays where it is in all three. */
        int i, wg = 0, out = 0;
        if (!have_drawing)
            return 1;
        /* 「[全レイヤ非表示]を[全レイヤ表示のみ] にする」 (1524): with it
           ticked the original put everything at 表示のみ instead of out
           altogether -- pressed with the box on, the file came back with
           every layer and every group at 1 rather than 0 */
        for (i = 0; i < n && i < (int)sizeof ld_on; i++)
            if (ui_layerdlg_id(i) == 1524 && ld_on[i])
                out = 1;
        for (i = 0; i < 16; i++)
            if (drawing.group[i].state == 3)
                wg = i;
        if (id == 1141) {
            for (i = 0; i < 16; i++) {
                int *st = &drawing.group[wg].layer[i].state;
                if (*st != 3)
                    *st = *st == 2 ? 0 : *st == 0 ? 1 : 2;
            }
        } else {
            /* every group, not only the one being written to: the original
               left every layer of all sixteen at the new state, each
               group's own write layer excepted */
            int g, k;
            for (g = 0; g < 16; g++) {
                for (k = 0; k < 16; k++)
                    if (drawing.group[g].layer[k].state != 3)
                        drawing.group[g].layer[k].state
                            = id == 2000 ? 2 : out;
                if (g != wg)
                    drawing.group[g].state = id == 2000 ? 2 : out;
            }
        }
        return 1;
    }
    lay = ui_layerdlg_layer(id);
    if (lay >= 0)
        /* the same as pressing that layer on the grid beside the drawing:
           the left button walks its state round, the right makes it the one
           being written to */
        return press_layer(0, lay, button);
    for (i = 0; i < n && i < (int)sizeof ld_on; i++)
        if (ui_layerdlg_id(i) == id) {
            ld_on[i] = (unsigned char)!ld_on[i];
            return 1;
        }
    return 1;                           /* on the dialog, on nothing */
}

static int sd_open;
static unsigned char sd_on[128];

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

static void sd_start(void)
{
    int i, n = ui_sunpodlg_n();

    for (i = 0; i < n && i < (int)sizeof sd_on; i++)
        sd_on[i] = (unsigned char)ui_sunpodlg_on(i);
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
    for (i = 0; i < n && i < (int)sizeof sd_on; i++)
        if (ui_sunpodlg_id(i) == id)
            sd_on[i] = (unsigned char)!sd_on[i];
    return 1;
}

/* 画面倍率・文字表示 -- 用紙全体表示 fits the sheet, the rest is the picture */
static int br_open;
static unsigned char br_on[64];
static char br_zoom[32];

int app_coord_save(unsigned char **out, long *n)
{
    double x, y;

    if (!have_drawing || !jw_cmd_block_point(&drawing, &x, &y))
        return 0;
    return jw_write_coord(&drawing, x, y, out, n);
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

static void br_start(void)
{
    int i, n = ui_bairitsu_n();

    for (i = 0; i < n && i < (int)sizeof br_on; i++)
        br_on[i] = (unsigned char)ui_bairitsu_on(i);
    br_zoom[0] = 0;
    br_open = 1;
}

static int press_bairitsu(int x, int y)
{
    int id = ui_bairitsu_hit(fb.w, fb.h, x, y), i, n = ui_bairitsu_n();

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1091) {                   /* 用紙全体表示 */
        app_fit();
        br_open = 0;
        return 1;
    }
    if (id == 1 || id == 2 || id == 1933 || id == 1089) {
        /* 指定倍率表示, 倍率 ＝ １．０ and 設定 OK all take it down.  What
           the first two do to the view is not settled: the original's screen
           cannot be captured here. */
        br_open = 0;
        return 1;
    }
    for (i = 0; i < n && i < (int)sizeof br_on; i++)
        if (ui_bairitsu_id(i) == id)
            br_on[i] = (unsigned char)!br_on[i];
    return 1;
}

/* 文字基点設定 -- the 文字 bar's 基点 (1064).  Only the
   nine radios do anything: what each of them does to a placed text was
   measured off the original (tools/probe62.sh), and nothing has been
   asked of the ずれ boxes or the three 作図 checkboxes. */
static int mk_open;
/* which of the six ずれ boxes is being typed into, or 0 */
static int mk_caret;

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
    return jw_cmd_moji_zure_key(mk_caret, c);
}

static int kh_open, kh_tab;
static unsigned char kh_on[8][256];

int app_kihon_open(void)
{
    return kh_open;
}

static void kh_start(void)
{
    int t, i;

    for (t = 0; t < ui_kihon_ntabs() && t < 8; t++)
        for (i = 0; i < ui_kihon_n(t) && i < 256; i++)
            kh_on[t][i] = (unsigned char)ui_kihon_on(t, i);
    kh_tab = 0;
    kh_open = 1;
}

static int press_kihon(int x, int y)
{
    int id = ui_kihon_hit(fb.w, fb.h, kh_tab, x, y), i, n;

    if (id == -1000)
        return 0;                       /* outside it: the dialog is modal */
    if (id < 0) {                       /* one of the tabs */
        kh_tab = -id - 1;
        return 1;
    }
    if (id == 1 || id == 2 || id == 9) {
        /* OK, キャンセル, ヘルプ -- none of them does anything yet: what
           the boxes mean has not been worked out */
        kh_open = 0;
        return 1;
    }
    n = ui_kihon_n(kh_tab);
    for (i = 0; i < n && i < 256; i++)
        if (ui_kihon_id(kh_tab, i) == id)
            kh_on[kh_tab][i] = (unsigned char)!kh_on[kh_tab][i];
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

static const struct { unsigned short cmd, tpl; } TD_CMD[] = {
    { 59392, 273 },     /* 表示 > ツールバー -- ツールバーの表示 */
    { 32995, 384 },     /* 表示 > ブロックツリー半透明化 -- 透過率 */
    { 57664, 100 },     /* ヘルプ > バージョン情報 */
    { 32977, 368 },     /* ファイル操作 > ファイル一括変換 */
    { 32979, 371 },     /* ファイル操作 > ファイル名変更 -- ファイル選択 */
    { 32980, 371 },     /* ファイル操作 > ファイル削除 -- ファイル選択 */
    { 32984, 371 },     /* ファイル操作 > ファイル属性変更 -- ファイル選択 */
};

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
    return 1;
}

static int press_tdlg(int x, int y)
{
    int id = ui_tdlg_hit(fb.w, fb.h, td_t, x, y), i, k, n, kind, flags;

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1 || id == 2) {           /* OK, キャンセル, the × */
        td_open = 0;
        return 1;
    }
    i = ui_tdlg_index(td_t, id);
    if (i < 0 || i >= TD_MAX || !ui_tdlg_ctl(td_t, i, 0, &kind, &flags))
        return 1;
    if (kind == UI_TC_CHECK)
        td_on[i] = (unsigned char)!td_on[i];
    else if (kind == UI_TC_RADIO) {
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
    kp_set(1770, 0, kp_txt[2]);
}

static void kp_sum(void)
{
    double s = 0.0;
    int g;

    for (g = 0; g < 7; g++)
        s += kp_place[g];
    kp_raw[kp_which] = 0;
    kp_v[kp_which] = kp_sign[kp_which] * s;
}

static int kp_start(int box)
{
    const char *t = jw_cmd_box(box), *p;

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
        memset(kp_place, 0, sizeof kp_place);
        break;
    default:
        return 1;
    }
    kp_show();
    return 1;
}

static int td_key(int c)
{
    int i = ui_tdlg_index(td_t, td_caret);

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

static int press_blkname(int x, int y)
{
    int id = ui_blkname_hit(fb.w, fb.h, x, y);

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1) {                      /* OK */
        if (have_drawing && blk_attr)
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
        if (have_drawing && blk_attr)
            jw_cmd_block_attr(&drawing, blk_pref);
        else if (have_drawing && blk_name[0])
            jw_cmd_block_make(&drawing, blk_name, blk_pref);
        blk_open = 0;
        return 1;
    }
    if (blk_attr)                       /* the box is greyed out there */
        return 0;
    (void)n;
    if (c >= 0x20 && c < 256) {
        text_put(blk_name, sizeof blk_name, &blk_drop, c);
        return 1;
    }
    return 0;
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
        if (id == 2412 && zsel_on[i])
            td_start(340);
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

    if (moji_drop) {                    /* the 色No. list is down */
        int row = ui_moji_drop_hit(fb.w, fb.h, x, y);

        moji_drop = 0;
        if (row >= 0)
            moji_color = row;
        return 1;
    }
    id = ui_moji_hit(fb.w, fb.h, x, y);
    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 2358) {
        moji_drop = 1;
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

/* One command, however it was asked for: a toolbar button, or the menu the
 * native build hands to Windows (both send the same ids -- they are the
 * original's own, out of its resources).  Returns 1 when the window wants
 * repainting, 0 otherwise; the two that need the front end's help leave an
 * action behind for app_take_action. */
int app_command(int cmd)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++)
        if (jw_btn_cmd[k] == cmd)
            break;
    if (k < JW_NBUTTONS && (jw_btn_mode[k] || cmd == JW_CMD_ZOKUSEI)) {
        /* 属性取得 is not a mode in the drawn sense -- the original has no
           ON_UPDATE_COMMAND_UI for it, so its button is never shown pressed
           -- but it does become the command: the click after it is what
           picks the element to take the pen from. */
        jw_cmd_set(cmd);
        /* 消去 with a settled range in hand empties it at once */
        if (cmd == JW_CMD_SHOUKYO && have_drawing)
            jw_cmd_sel_erase(&drawing);
        /* 座標ファイル: the original's bar asks for a file name and then a
           range of its own.  The port has no bar for it, so entering the
           command with something already picked is what writes the file --
           the front end is handed JW_ACT_SAVE_COORD to ask for a name. */
        if (cmd == 32895 && have_drawing && jw_cmd_sel_count(&drawing) > 0)
            action = JW_ACT_SAVE_COORD;
        return 1;
    }
    /* a dialog put up from the original's own template (td_start) */
    for (k = 0; k < (int)(sizeof TD_CMD / sizeof TD_CMD[0]); k++)
        if (TD_CMD[k].cmd == cmd)
            return td_start(TD_CMD[k].tpl);
    /* an action: it runs, and never becomes "the command" */
    switch (cmd) {
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
        return jw_cmd_clip_copy(&drawing, cmd == 57635);
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
    case 32862:                         /* 図形読込 */
        /* The original puts up a file window of its own here.  The port has
           none: the front end reads the .jws and calls app_figure, which is
           what enters the command. */
        return 0;
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
        /* A command part way through takes the press itself and backs
           up (jw_cmd_back); only a command at rest lets a step of the
           drawing come off (jw_cmd_midway).  The port used to undo the drawing whatever the
           command was doing, and the command kept the elements it had
           picked by their index -- which after the undo could be another
           element, or past the end. */
        if (jw_cmd_midway()
            && jw_cmd_back(have_drawing ? &drawing : 0))
            return 1;           /* 0 なら原典と同じく図面の 戻る へ */
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
    case 32810:                         /* JWC形式で保存 */
        action = JW_ACT_SAVE_JWC;
        return 0;
    case 57607:                         /* 印刷 */
        /* The original puts the Windows printer dialog up here and then
           goes into a mode of its own, with a frame to place and 印刷 (L)
           to press.  The port has no printer: what it hands over is a
           file of the sheet, one to one, which is what that print comes
           out as -- a PDF to send to a printer or a PNG to look at, by
           the name it is given (src/plot.h). */
        action = JW_ACT_PLOT;
        return 0;
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

int app_press(int x, int y, int button)
{
    int k = hit_button(x, y);
    int id, g, n;

    /* An open popup takes the press: on an item it runs it, anywhere else it
       just shuts -- the click that closes a menu does nothing else, which is
       what Windows does too. */
    if (ui_popup_up()) {
        int cmd = ui_popup_in(x, y) ? ui_popup_press(x, y) : 0;

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
    if (td_open)
        return td_tpl == 314 ? press_kp(x, y, button) : press_tdlg(x, y);
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
    if (button == 0 && (id = ui_bar_hit(x, y)) != 0) {
        /* 複写・移動 once the range is settled: their second bar has its
           own 1070, 作図属性, and that one puts up 作図属性設定 (template
           342) -- CZukeiFukusha's slot 31 builds it (tools/cmddlg.py's
           sort of reading, from the class side).  The 1070 below is the
           first bar's 属性変更 and must not answer here: this bar's 1069
           is ﾏｳｽ倍率, which is enabled, and the window it opened was the
           range selection's. */
        if (id == 1070 && jw_cmd_sel_stage() == 3
            && (jw_cmd() == JW_CMD_FUKUSHA || jw_cmd() == JW_CMD_IDOU)) {
            td_start(342);
            return 1;
        }
        if (id == 1070 && jw_cmd_bar_enabled(have_drawing ? &drawing : 0,
                                             1069) > 0) {
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
            /* 矩形 の ソリッド の横の無名の釦（任意□）.  The original
               puts the 線属性 dialog up from it -- pressed on the original
               with ソリッド ticked, that is the window that came up -- so
               the colour a solid is filled with is picked there. */
            zoku_ask(0);
            return 1;
        }
        if (id == 1069 && jw_cmd_bar_enabled(have_drawing ? &drawing : 0,
                                             1069) > 0) {
            /* 範囲選択's own button, which only comes alive once a box is
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
        if (id == 1064 && jw_cmd() == JW_CMD_MOJI) {
            /* 基点(左下): the button puts up 文字基点設定 */
            mk_open = 1;
            return 1;
        }
        if (id == 1843 && jw_cmd() == JW_CMD_MOJI) {
            /* the 文字 bar's own button, which puts the dialog up */
            moji_style = moji_current();
            moji_open = 1;
            moji_focus = 0;
            moji_drop = 0;
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
        if (jw_cmd_bar(have_drawing ? &drawing : 0, id))
            return 1;
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
        jw_cmd_box_click(0);            /* the caret leaves the bar */
        to_paper(x, y, &mx, &my);
        {   /* While ブロック編集 is on, whatever a click makes goes into
               the block's definition rather than into the drawing -- see
               jw_cmd_block_take. */
            int was = have_drawing ? drawing.ndrawn : 0;

            jw_cmd_point(have_drawing ? &drawing : 0, &view, mx, my, button);
            if (have_drawing && jw_cmd_block_editing()
                && drawing.ndrawn > was)
                jw_cmd_block_take(&drawing, was);
            if (jw_cmd_figure_base(&fig_bx, &fig_by))
                action = JW_ACT_SAVE_FIG;   /* 図形登録 wants a file name */
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
    return zoku_open || moji_open || zsel_open || blk_open || be_open
           || jk_open || sd_open || br_open || kh_open || zhen_open
           || sk_open || ld_open || td_open;
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
    sd_caret = 0;
    sd_edit[0] = 0;
}

int app_key(int c)
{
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
    if (mk_open && mk_caret && mk_key(c)) {
        app_paint();
        return 1;
    }
    if (sd_open && sd_caret && sd_key(c)) {
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
        return 1;
    }
    if (jw_cmd_box_key(c)) {
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
    if (jw_cmd() != JW_CMD_MOJI) {
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
    if (c == 27) {              /* Esc lets go of the points taken so far */
        jw_cmd_escape();
        app_paint();
        return 1;
    }
    if (c == 32 && jw_cmd() != JW_CMD_MOJI) {
        jw_cmd_space();         /* Space turns 水平・垂直 over */
        app_paint();
        return 1;
    }
    if (jw_cmd() != JW_CMD_MOJI)
        return 0;
    jw_cmd_key(c);
    app_paint();
    return 1;
}

int app_compose(int c)
{
    if (jw_cmd() != JW_CMD_MOJI)
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
    return a;
}

int app_save(unsigned char **out, long *n)
{
    if (!have_drawing)
        return 0;
    return jw_write(&drawing, out, n);
}

/* The same drawing as DXF, which is what 「DXF形式で保存」 writes. */
int app_save_dxf(unsigned char **out, long *n)
{
    if (!have_drawing)
        return 0;
    return jw_dxf_write(&drawing, out, n);
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

int app_move(int x, int y)
{
    double mx, my;
    jw_obj o[JW_CMD_MAXFIG];

    if (ui_popup_up())
        return ui_popup_move(x, y);
    if (!view_ready || !in_view(x, y))
        return 0;
    to_paper(x, y, &mx, &my);
    jw_cmd_track(mx, my);
    {   /* the range box and the selection being dragged both follow the
           mouse, so the window has to be told to paint again */
        double a, b, c, e;
        if (jw_cmd_sel_box(&a, &b, &c, &e) || jw_cmd_sel_ghost(&a, &b))
            return 1;
    }
    return jw_cmd_pending(have_drawing ? &drawing : 0, o,
                          JW_CMD_MAXFIG) > 0;
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

    if (!jw_parse(&d, jw_new_jww, jw_new_jww_len)) {
        last_error = d.error;   /* only reachable if the bake went wrong */
        jw_free(&d);
        return;
    }
    d.nobj = 0;
    d.ndrawn = 0;
    if (have_drawing)
        jw_free(&drawing);
    drawing = d;
    have_drawing = 1;
    have_file = 0;
    last_error = "";
    jw_cmd_reset();
    app_fit();
}

int app_open(const unsigned char *b, long n)
{
    jw_drawing d;

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
    last_error = "";
    jw_cmd_reset();
    app_fit();
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
    app_fit();
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
    app_fit();
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
    app_fit();
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
    h = mix(h, &drawing, sizeof drawing);
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
        draw_drawing();
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
    if (view_ready && have_drawing) {
        double a, b, e, f;
        ui_view_rect(fb.w, fb.h, &view.clip);
        if (jw_cmd_sel_box(&a, &b, &e, &f))
            jw_draw_box(&fb, &view, a, b, e, f);
        if (jw_cmd_sel_ghost(&a, &b))
            jw_draw_sel(&fb, &view, &drawing, a, b);
    }
    /* the 文字 command's box goes over the drawing */
    if (jw_cmd() == JW_CMD_MOJI)
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
        ui_blkname(&fb, blk_name, blk_pref, !blk_attr, blk_attr);
    if (be_open)
        ui_blkedit(&fb, be_name, be_all);
    if (kh_open)
        ui_kihon(&fb, kh_tab, kh_on[kh_tab]);
    if (jk_open)
        ui_jikkaku(&fb, jk_angle, jk_on, 1);
    if (td_open)
        ui_tdlg(&fb, td_t, td_on, td_txtp, td_caret);
    if (sd_open)
        ui_sunpodlg(&fb, sd_on, sd_caret, sd_edit);
    if (br_open)
        ui_bairitsu(&fb, br_zoom, br_on);
    if (mk_open)
        ui_mojikijun(&fb, jw_cmd_moji_base_now(), mk_caret);
    if (sk_open) {
        sk_fill();
        ui_shakudo(&fb, sk_num, sk_den, sk_listp, sk_group, sk_on, sk_caret);
    }
    if (ld_open)
        ui_layerdlg(&fb, have_drawing ? &drawing : 0, ld_on);
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
