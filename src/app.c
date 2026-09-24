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
    sprintf(moji_box[0], "%.2f", w);
    sprintf(moji_box[1], "%.2f", h);
    sprintf(moji_box[2], "%.3f", sp);
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
static int sd_open;
static unsigned char sd_on[128];

int app_sunpodlg_open(void)
{
    return sd_open;
}

static void sd_start(void)
{
    int i, n = ui_sunpodlg_n();

    for (i = 0; i < n && i < (int)sizeof sd_on; i++)
        sd_on[i] = (unsigned char)ui_sunpodlg_on(i);
    sd_open = 1;
}

static int press_sunpodlg(int x, int y)
{
    int id = ui_sunpodlg_hit(fb.w, fb.h, x, y), i, n = ui_sunpodlg_n();

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
    if (id == 1 || id == 2) {           /* neither does anything yet */
        sd_open = 0;
        return 1;
    }
    for (i = 0; i < n && i < (int)sizeof sd_on; i++)
        if (ui_sunpodlg_id(i) == id)
            sd_on[i] = (unsigned char)!sd_on[i];
    return 1;
}

/* 画面倍率・文字表示 -- 用紙全体表示 fits the sheet, the rest is the picture */
static int br_open;
static unsigned char br_on[64];
static char br_zoom[32];

/* 図形登録's 基準点, kept from the press that gave it. */
static double fig_bx, fig_by;

int app_figure_save(unsigned char **out, long *n)
{
    if (!have_drawing)
        return 0;
    return jw_cmd_figure_save(&drawing, fig_bx, fig_by, out, n);
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

/* One key while the ブロック編集 dialog is up: the name box takes it. */
static int be_key(int c)
{
    size_t n = strlen(be_name);

    if (c == 8) {
        while (n && (unsigned char)be_name[n - 1] >= 0x80
               && !jw_is_lead((unsigned char)be_name[n - 1]))
            n--;
        if (n)
            be_name[n - 1] = 0;
        return 1;
    }
    if (c == 13) {                      /* Enter is the OK button */
        if (have_drawing && !be_all)
            jw_cmd_block_split(&drawing);
        be_open = 0;
        return 1;
    }
    if (c >= 0x20 && n + 1 < sizeof be_name) {
        be_name[n] = (char)c;
        be_name[n + 1] = 0;
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
        while (n && (unsigned char)blk_name[n - 1] >= 0x80
               && !jw_is_lead((unsigned char)blk_name[n - 1]))
            n--;                        /* the trail byte of a pair */
        if (n)
            blk_name[n - 1] = 0;
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
    if (c >= 0x20 && n + 1 < sizeof blk_name) {
        blk_name[n] = (char)c;
        blk_name[n + 1] = 0;
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
    int id = ui_moji_hit(fb.w, fb.h, x, y);

    if (id < 0)
        return 0;                       /* outside it: the dialog is modal */
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
        }
        moji_open = 0;
        moji_focus = 0;
    } else if (id == 2) {               /* キャンセル */
        moji_open = 0;
        moji_focus = 0;
    }
    return 1;
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
        return 1;
    }
    /* an action: it runs, and never becomes "the command" */
    switch (cmd) {
    case 32820: case 32821: case 32822: case 32823: case 32824:
        /* Ａ-０..Ａ-４: the sheet changes and nothing else does */
        if (!have_drawing)
            return 0;
        jw_paper_set(&drawing, cmd - 32820);
        return 1;
    case 32891:                         /* 基本設定 */
        kh_start();
        return 1;
    case 32842:                         /* 軸角・目盛・オフセット */
        jk_start();
        return 1;
    case 32925:                         /* 寸法設定 */
        sd_start();
        return 1;
    case 32811:                         /* 画面倍率・文字表示 */
        br_start();
        return 1;
    case 32946:                         /* 図形登録 */
        /* It takes a range of its own -- the original asks for one even
           when something is already picked -- and the point after 選択確定
           is the 基準点. */
        jw_cmd_set(JW_CMD_ZUKEIREG);
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
        if (!jw_cmd_can_undo())
            return 0;
        jw_cmd_undo(have_drawing ? &drawing : 0);
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

    if (ui_popup_top() < 0)
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
    if (ui_popup_top() >= 0) {
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

    if ((g = ui_layer_hit(fb.w, x, y, &n)) >= 0)
        return press_layer(g, n, button);

    if (button == 0 && (id = ui_bar_hit(x, y)) != 0) {
        if (id == 1070 && jw_cmd_bar_enabled(have_drawing ? &drawing : 0,
                                             1069) > 0) {
            /* 属性変更 -- the same window, its other half */
            zhen_start();
            return 1;
        }
        if (id == 1069 && jw_cmd_bar_enabled(have_drawing ? &drawing : 0,
                                             1069) > 0) {
            /* 範囲選択's own button, which only comes alive once a box is
               in -- the bar has it greyed until then */
            zsel_start();
            return 1;
        }
        if (id == 1843 && jw_cmd() == JW_CMD_MOJI) {
            /* the 文字 bar's own button, which puts the dialog up */
            moji_style = moji_current();
            moji_open = 1;
            moji_focus = 0;
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

int app_key(int c)
{
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
    if (jw_cmd_box_key(c)) {
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

    if (ui_popup_top() >= 0)
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

void app_paint(void)
{
    int i, n;

    if (!fb.px)
        return;
    ui_paint(&fb, have_drawing ? &drawing : 0,
             view_ready ? view.scale * JW_SCREEN_MM_PER_PX : 0.0,
             have_file, jw_cmd_can_undo());
    if (have_drawing) {
        if (!view_ready)
            app_fit();
        ui_view_rect(fb.w, fb.h, &view.clip);
        jw_draw(&fb, &view, &drawing);
    }
    {
        /* The element the command is part way through.  The original draws
           its provisional figure through a raster op (it has a SetROP2
           wrapper at FUN_0079f1b8) which has not been traced yet, so this
           just draws the element that is about to exist. */
        jw_obj o[JW_CMD_MAXFIG];
        int n;
        if (view_ready && have_drawing
            && (n = jw_cmd_pending(&drawing, o, JW_CMD_MAXFIG)) > 0) {
            jw_drawing one = drawing;
            ui_view_rect(fb.w, fb.h, &view.clip);
            one.obj = o;
            one.nobj = one.ndrawn = n;
            jw_draw(&fb, &view, &one);
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
    if (sd_open)
        ui_sunpodlg(&fb, sd_on);
    if (br_open)
        ui_bairitsu(&fb, br_zoom, br_on);
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
