#include <stddef.h>

#include "ui.h"
#include "app.h"
#include "theme.h"
#include "gen/jwres.h"
#include "gen/layout.h"
#include "gen/bars.h"
#include "gen/zoku.h"
#include "gen/moji.h"
#include "gen/zokusel.h"
#include "gen/zokuhen.h"
#include "gen/blkname.h"
#include "gen/blkedit.h"
#include "gen/kihon.h"
#include "gen/jikkaku.h"
#include "gen/shakudo.h"
#include "gen/layerdlg.h"
#include "gen/grpicon.h"
#include "gen/skradio.h"
#include "gen/mojikijun.h"
#include "gen/layicon.h"
#include "gen/laytab.h"
#include "gen/sunpodlg.h"
#include "gen/bairitsu.h"
#include "gen/pens.h"
#include "gen/menu.h"
#include "gen/jwicon.h"
#include "gen/cmds.h"
#include "cmd.h"
#include "draw.h"
#include "text.h"

#include <stdio.h>
#include <string.h>

/* The window is a stack of docked bars round the drawing area.  Each bar
 * paints its face and, where it meets another, a two-pixel border: a shadow
 * line on the outside and a highlight just inside it -- what MFC's
 * CControlBar::DrawBorders does.
 *
 * The rectangles below were measured off docs/ref_start.png (client
 * 1264x741).  Most of them are fixed, and the four `A_` flags say which ones
 * ride an edge when the window is another size -- see ui.h for how that was
 * read out of the original.  Which bar is which, and why they are split the
 * way they are, is still to be read out of CMainFrame::OnCreate.
 */
#define B_TOP   1
#define B_LEFT  2

#define A_RIGHT  1      /* x follows the right edge                       */
#define A_WIDE   2      /* the right edge of the panel does                */
#define A_TALL   4      /* the bottom edge does (down to the status line)  */
#define A_BOTTOM 8      /* y follows the bottom edge                       */

typedef struct {
    short x, y, w, h;
    unsigned int face;
    unsigned char borders;
    unsigned char anchor;
} bar_t;

static const bar_t bars[] = {
    /* the command bar across the top, and the empty white strip beside it,
       which is the bar's own background and so takes up the slack */
    {    0,   0,  829,  32, C_BTNFACE, B_TOP,          0 },
    {  829,   0,  435,  32, C_WINDOW,  B_TOP | B_LEFT, A_WIDE },

    /* left side: two columns of buttons in three bands.  The bar grows
       downwards, so the last band of each column reaches the status line. */
    {    0,  32,   37, 227, C_BTNFACE, B_TOP,          0 },
    {   37,  32,   39, 227, C_BTNFACE, B_TOP | B_LEFT, 0 },
    {    0, 259,   37, 227, C_BTNFACE, B_TOP,          0 },
    {   37, 259,   39, 227, C_BTNFACE, B_TOP | B_LEFT, 0 },
    {    0, 486,   37, 129, C_BTNFACE, B_TOP,          0 },
    {   37, 486,   39,  32, C_WINDOW,  B_TOP | B_LEFT, 0 },  /* line sample */
    {   37, 518,   39,  14, C_WINDOW,  B_TOP | B_LEFT, 0 },
    {   37, 532,   39,  80, C_BTNFACE, B_TOP | B_LEFT, 0 },
    {   37, 612,   39,   4, C_WINDOW,  B_TOP | B_LEFT, 0 },
    {    0, 615,   39, 105, C_WINDOW,  B_TOP,          A_TALL },
    {   39, 616,   37, 104, C_WINDOW,  0,              A_TALL },

    /* right side: the same idea, plus the layer grid low down.  All of it
       rides the right edge. */
    { 1188,  32,   37, 227, C_BTNFACE, B_TOP,          A_RIGHT },
    { 1225,  32,   39, 227, C_BTNFACE, B_TOP | B_LEFT, A_RIGHT },
    { 1188, 259,   37,  80, C_BTNFACE, B_TOP,          A_RIGHT },
    { 1225, 259,   39, 129, C_BTNFACE, B_TOP | B_LEFT, A_RIGHT },
    { 1188, 339,   37,  32, C_WINDOW,  B_TOP,          A_RIGHT },
    { 1188, 371,   37,  14, C_WINDOW,  B_TOP,          A_RIGHT },
    { 1188, 385,   37, 231, C_WINDOW,  B_TOP,          A_RIGHT },
    { 1225, 388,   39, 228, C_WINDOW,  B_TOP | B_LEFT, A_RIGHT },
    { 1188, 612,   37, 108, C_WINDOW,  B_TOP,          A_RIGHT | A_TALL },
    { 1225, 615,   39, 105, C_WINDOW,  B_TOP,          A_RIGHT | A_TALL },

    /* the status line, which rides the bottom and is as wide as the client */
    {    0, 720, 1264,  21, C_BTNFACE, B_TOP,          A_BOTTOM | A_WIDE },
};
#define NBARS ((int)(sizeof bars / sizeof bars[0]))

/* Measured off the reference screen: the drawing area's white rectangle. */
#define VIEW_L   78     /* first white column                       */
#define VIEW_T   34     /* first white row                          */
#define VIEW_R   78     /* client width  - 1 - last white column    */
#define VIEW_B   21     /* client height - 1 - last white row       */

/* 表示 > ステータスバー (59393) は状態表示を仕舞い、**ビューがその分
 * 広がります**。原典に訊くと 1264x741 のフレームで 1108x686 だったビューが
 * 1108x705 になりました（`tools/probe134.sh` の `viewrect`）—— 19 画素です。
 * 移植の VIEW_B は白くなる所までの 21 画素なので、仕舞うと 2 だけ残って
 * 705 になり、原典とぴったり合います。
 *
 * 同じ並びの ツールバー (59392) は**ただの小見出し**で（その下に個々の
 * バーが並ぶ `MENU 400`）、投げても割り付けは動きません。
 * ダイアログボックス (32953) も動きませんでした —— 絵は 2,439 画素
 * 変わるのに見出しと菜単の帯だけで、何が起きているのかは分かっていません
 * （`tools/probe127.sh`・`probe134.sh`）。 */
static int status_hidden;

void ui_status_show(int on)
{
    status_hidden = !on;
}

int ui_status_shown(void)
{
    return !status_hidden;
}

static int view_b(void)
{
    return status_hidden ? 2 : VIEW_B;
}

void ui_view_rect(int cw, int ch, rect_t *r)
{
    r->x = VIEW_L;
    r->y = VIEW_T;
    r->w = cw - VIEW_R - VIEW_L;
    r->h = ch - view_b() - VIEW_T;
}

/* A toolbar button: two nested one-pixel rings round a face.  Not DrawEdge --
 * the original mixes the rings (highlight outside, 3DLIGHT inside) in a way
 * no single EDGE_ constant produces, so it is spelled out. */
static void button_frame(fb_t *fb, int x, int y, int w, int h, int pressed)
{
    if (pressed) {
        fb_edge(fb, x, y, w, h, C_3DDKSHADOW, C_BTNHILIGHT);
        fb_edge(fb, x + 1, y + 1, w - 2, h - 2, C_BTNSHADOW, C_3DLIGHT);
    } else {
        fb_edge(fb, x, y, w, h, C_BTNHILIGHT, C_3DDKSHADOW);
        fb_edge(fb, x + 1, y + 1, w - 2, h - 2, C_3DLIGHT, C_BTNSHADOW);
    }
}

/* The pressed-in button's face is a checkerboard of highlight and face,
 * phased on the window, not on the button. */
/* One pixel, if it is on the framebuffer at all.  The bars and the buttons
   are laid out for a 1264-wide window, and ui_ax/ui_right put the ones that
   hang off the right edge outside a narrower one; fb_fill and
   fb_blit_cell_ex cut those away themselves, and what is below has to do the
   same.  Without it a window small enough to push a pressed button off the
   edge writes past the end of the framebuffer -- found by rendering at
   200x150 under AddressSanitizer (tools/asan.sh). */
static void px_put(fb_t *fb, int x, int y, unsigned int c)
{
    if (x >= 0 && x < fb->w && y >= 0 && y < fb->h)
        fb->px[(size_t)y * fb->w + x] = c;
}

static void checker(fb_t *fb, int x, int y, int w, int h)
{
    int i, j;

    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
            px_put(fb, x + i, y + j,
                   ((x + i + y + j) & 1) ? C_BTNHILIGHT : C_BTNFACE);
}

static unsigned int cellpx(const jw_bitmap_t *bm, int cell, int i, int j)
{
    int n = bm->idx[(size_t)j * bm->w + cell * CELL_W + i];
    const unsigned char *p = bm->pal + 3 * n;

    return ((unsigned)p[0] << 16) | ((unsigned)p[1] << 8) | p[2];
}

static void blit_cell_state(fb_t *fb, const jw_bitmap_t *bm, int cell,
                            int x, int y, int state)
{
    int i, j;

    if (!bm)
        return;
    if (state != 1) {
        fb_blit_cell_ex(fb, (const struct jw_bitmap *)bm, cell, CELL_W, x, y,
                        state == 2);
        return;
    }
    /* Disabled: the ink once in highlight offset by one, then in shadow on
     * top.  0xc0c0c0 is the face the art is drawn against, not ink. */
    for (j = 0; j < CELL_H; j++)
        for (i = 0; i < CELL_W; i++)
            if (cellpx(bm, cell, i, j) != 0xc0c0c0u)
                px_put(fb, x + i + 1, y + j + 1, C_BTNHILIGHT);
    for (j = 0; j < CELL_H; j++)
        for (i = 0; i < CELL_W; i++)
            if (cellpx(bm, cell, i, j) != 0xc0c0c0u)
                px_put(fb, x + i, y + j, C_BTNSHADOW);
}


/* ------------------------------------------------------------- the chrome
 *
 * All of this was measured off docs/ref_window.png -- Jw_cad's own window,
 * painted into a bitmap with PrintWindow so nothing had to be grabbed off
 * the screen:
 *
 *   rows  0..30   the caption, 0xf3f3f3 all over; the program's icon at
 *                 8,7 (src/gen/jwicon.h, which is RT_ICON 2 and matches the
 *                 caption pixel for pixel); the name at 30,10; and the
 *                 three window buttons' glyphs 119, 74 and 28 pixels in
 *                 from the right edge, black, 10 wide;
 *   rows 31..50   the menu bar, white but for its last two rows (0xf2f2f2
 *                 then 0xf0f0f0); the seven names at the columns in
 *                 src/gen/menu.h with their tops four rows down.
 *
 * The glyphs are the port's own font, so the names will not match the
 * original's pixel for pixel -- the same trade as everywhere else.
 */
#define CAP_FACE   0xf3f3f3u
#define CAP_ICON_X  8
#define CAP_ICON_Y  7
#define CAP_TEXT_X 30
#define CAP_TEXT_Y 10
#define MENU_TEXT_Y 4

/* how far in from the right edge each window button's glyph starts */
static const short cap_btn[3] = { -119, -74, -28 };

void ui_caption(fb_t *fb, int y, int cw, const char *title)
{
    int i, j, k;

    fb_fill(fb, 0, y, cw, JW_CAPTION_H, CAP_FACE);
    for (j = 0; j < JW_ICON_H; j++)
        for (i = 0; i < JW_ICON_W; i++)
            if (jw_icon_mask[j * JW_ICON_W + i])
                fb_fill(fb, CAP_ICON_X + i, y + CAP_ICON_Y + j, 1, 1,
                        jw_icon[j * JW_ICON_W + i]);
    if (title && *title)
        jw_text_px(fb, CAP_TEXT_X, y + CAP_TEXT_Y, title, C_BTNTEXT);
    for (k = 0; k < 3; k++) {
        int x = cw + cap_btn[k];
        if (k == 0) {                   /* minimise: one row */
            fb_hline(fb, x, y + 15, 10, C_BTNTEXT);
        } else if (k == 1) {            /* maximise: a box */
            fb_edge(fb, x, y + 10, 10, 10, C_BTNTEXT, C_BTNTEXT);
        } else {                        /* close: two diagonals */
            for (i = 0; i < 10; i++) {
                fb_fill(fb, x + i, y + 10 + i, 1, 1, C_BTNTEXT);
                fb_fill(fb, x + 9 - i, y + 10 + i, 1, 1, C_BTNTEXT);
            }
        }
    }
}

void ui_menu(fb_t *fb, int y, int cw)
{
    int th = jw_text_height(), i;

    fb_fill(fb, 0, y, cw, JW_MENU_H - 2, C_WINDOW);
    fb_hline(fb, 0, y + JW_MENU_H - 2, cw, 0xf2f2f2u);
    fb_hline(fb, 0, y + JW_MENU_H - 1, cw, C_BTNFACE);
    for (i = 0; i < JW_NMENU; i++) {
        /* the name whose popup is open sits on a patch, the way Windows marks
           it; with nothing open this is exactly what it always was */
        if (i == ui_popup_top()) {
            int x0 = jw_menu[i].x - 8;
            int x1 = jw_menu[i].x + jw_text_px_w(jw_menu[i].text) + 8;

            fb_fill(fb, x0, y, x1 - x0, JW_MENU_H - 2, JW_POPUP_HOT);
        }
        jw_text_px(fb, jw_menu[i].x, y + MENU_TEXT_Y + (12 - th) / 2,
                   jw_menu[i].text, C_BTNTEXT);
    }
}

/* ------------------------------------------------------------------ popup
 *
 * The tree in src/gen/menu.h is flat: depth 0 is a name on the bar, depth 1
 * what its popup holds, depth 2 what a submenu of that holds.  So a popup is
 * a range of the array, and walking it means taking the entries at one depth
 * and stepping over the deeper ones that belong to them.
 */
static int pop_top = -1;        /* which name of the bar is open */
static int pop_sub = -1;        /* the submenu entry that is open, or -1 */
static int pop_hot = -1;        /* the entry under the mouse */

/* A popup that hangs off a point instead of off the bar.
 *
 * 状態表示の 用紙 の箱 (32825) はダイアログでなく**ポップアップ**を出し
 * ます —— 原典に WM_COMMAND を投げると #32768 が一つ上がってきて、中身は
 * 用紙サイズ の十二項目、いまの用紙に印が付いています（`popcmd:` を足し
 * ました）。窓は 127x270、`JW_POPUP_ITEM_H` 22 と `JW_POPUP_BORDER` 3 で
 * 12 * 22 + 6 = 270 ちょうどです。
 *
 * **出る所はポインタに付いてきます。**カーソルを (400,300) と (900,650)
 * に置いて同じ命令を投げると、窓はどちらも左上が (カーソル - 63, カーソル)
 * に出ました。63 は (127-1)/2 で、つまり**横はカーソルの真ん中、縦は
 * カーソルから下**です。 */
static int pop_free = -1;       /* the submenu entry it shows, or -1 */
static int pop_fx, pop_fy;      /* its top left, worked out when it opens */
static int pop_mark = -1;       /* the entry id to tick, or -1 */

/* Which depth of the tree the open popup is showing. */
static int pop_depth(void)
{
    return pop_free >= 0 ? jw_menu_tree[pop_free].depth + 1 : 1;
}

/* [from,to) of the tree that belongs to top-level `t`, deeper entries and
   all. */
static void top_range(int t, int *from, int *to)
{
    int i, n = -1;

    *from = *to = 0;
    for (i = 0; i < JW_NMENU_TREE; i++) {
        if (jw_menu_tree[i].depth != 0)
            continue;
        n++;
        if (n == t)
            *from = i + 1;
        else if (n == t + 1) {
            *to = i;
            return;
        }
    }
    if (n >= t)
        *to = JW_NMENU_TREE;
}

/* The children of the submenu at `s`: the entries after it that are one
   deeper, up to the first that is not. */
static void sub_range(int s, int *from, int *to)
{
    int d = jw_menu_tree[s].depth + 1, i;

    *from = s + 1;
    for (i = s + 1; i < JW_NMENU_TREE; i++)
        if (jw_menu_tree[i].depth < d) {
            *to = i;
            return;
        }
    *to = JW_NMENU_TREE;
}

/* The label without its ampersand, and where the accelerator starts. */
static const char *pop_label(const char *s, char *out, int cap)
{
    const char *tab = 0;
    int k = 0;

    while (*s && k < cap - 1) {
        /* 用紙サイズ のポップアップだけは札の末尾の「(&0)」が付きません。
           メニューバーのほうは出ます（原典の 設定 の popup には (S) まで
           写っています）。Jw_cad がこのポップアップをメニュー資源の札で
           なく自前の札で組んでいるからでしょう。 */
        if (pop_free >= 0 && s[0] == '(' && s[1] == '&')
            break;
        if (*s == '&') {                /* Windows' underline marker */
            s++;
            continue;
        }
        if (*s == '\t') {
            tab = s + 1;
            break;
        }
        out[k++] = *s++;
    }
    out[k] = 0;
    return tab;
}

static int pop_h(int from, int to, int depth)
{
    int h = 0, i;

    for (i = from; i < to; i++) {
        if (jw_menu_tree[i].depth != depth)
            continue;
        h += jw_menu_tree[i].kind == 2 ? JW_POPUP_SEP_H : JW_POPUP_ITEM_H;
    }
    return h + 2 * JW_POPUP_BORDER;
}

static int pop_w(int from, int to, int depth)
{
    char lab[256];
    int w = 0, i;

    for (i = from; i < to; i++) {
        const jw_menu_item_t *m = &jw_menu_tree[i];
        const char *acc;
        int n;

        if (m->depth != depth || m->kind == 2)
            continue;
        acc = pop_label(m->text, lab, sizeof lab);
        n = jw_text_px_w(lab);
        if (acc)
            n += 24 + jw_text_px_w(acc);
        else if (m->kind == 1)
            n += 24;                    /* room for the arrow */
        if (n > w)
            w = n;
    }
    return JW_POPUP_TEXT_X + w + 20;
}

/* The y a given entry's row starts at, inside its popup. */
static int pop_row_y(int from, int to, int depth, int want)
{
    int y = JW_POPUP_BORDER, i;

    for (i = from; i < to; i++) {
        if (jw_menu_tree[i].depth != depth)
            continue;
        if (i == want)
            return y;
        y += jw_menu_tree[i].kind == 2 ? JW_POPUP_SEP_H : JW_POPUP_ITEM_H;
    }
    return -1;
}

/* Where a top-level popup sits, in client coordinates: hanging off its name
   and starting at the top of the client, which is where the original puts
   it -- its popups came back at y = -1 of the frame's client. */
static void pop_box(int *x, int *y, int *w, int *h,
                    int *from, int *to)
{
    if (pop_free >= 0) {
        int d = pop_depth();

        sub_range(pop_free, from, to);
        *w = pop_w(*from, *to, d);
        *h = pop_h(*from, *to, d);
        *x = pop_fx;
        *y = pop_fy;
        return;
    }
    top_range(pop_top, from, to);
    *x = jw_menu[pop_top].x - 8;
    *y = 0;
    *w = pop_w(*from, *to, 1);
    *h = pop_h(*from, *to, 1);
}

/* And where the open submenu sits: off its parent item's right edge. */
static void sub_box(int *x, int *y, int *w, int *h, int *from, int *to)
{
    int pf, pt, px, py, pw, ph;

    pop_box(&px, &py, &pw, &ph, &pf, &pt);
    sub_range(pop_sub, from, to);
    *x = px + pw - 4;
    *y = py + pop_row_y(pf, pt, 1, pop_sub) - JW_POPUP_BORDER;
    *w = pop_w(*from, *to, 2);
    *h = pop_h(*from, *to, 2);
}

static int pop_at(int from, int to, int depth, int x0, int y0, int w,
                  int x, int y)
{
    int yy = y0 + JW_POPUP_BORDER, i;

    if (x < x0 || x >= x0 + w)
        return -1;
    for (i = from; i < to; i++) {
        int ih;

        if (jw_menu_tree[i].depth != depth)
            continue;
        ih = jw_menu_tree[i].kind == 2 ? JW_POPUP_SEP_H : JW_POPUP_ITEM_H;
        if (y >= yy && y < yy + ih)
            return i;
        yy += ih;
    }
    return -1;
}

int ui_popup_open(int top)
{
    if (pop_top == top && pop_free < 0)
        return 0;
    pop_top = top;
    pop_free = -1;
    pop_mark = -1;
    pop_sub = -1;
    pop_hot = -1;
    return 1;
}

int ui_popup_open_at(int first, int mark, int x, int y, int cw, int ch)
{
    int i, s = -1, f, t, k, w, h;

    for (i = 0; i < JW_NMENU_TREE; i++) {
        if (jw_menu_tree[i].kind != 1)
            continue;
        sub_range(i, &f, &t);
        for (k = f; k < t; k++)
            if (jw_menu_tree[k].depth == jw_menu_tree[i].depth + 1
                && jw_menu_tree[k].id == first) {
                s = i;
                break;
            }
        if (s >= 0)
            break;
    }
    if (s < 0)
        return 0;
    pop_top = -1;
    pop_sub = -1;
    pop_hot = -1;
    pop_free = s;
    pop_mark = mark;
    sub_range(s, &f, &t);
    w = pop_w(f, t, jw_menu_tree[s].depth + 1);
    h = pop_h(f, t, jw_menu_tree[s].depth + 1);
    /* centred on the press and running down from it, and -- as any menu
       does -- flipped above it when there is no room below */
    pop_fx = x - (w - 1) / 2;
    pop_fy = y + h <= ch ? y : y - h;
    if (pop_fx + w > cw)
        pop_fx = cw - w;
    if (pop_fx < 0)
        pop_fx = 0;
    if (pop_fy < 0)
        pop_fy = 0;
    return 1;
}

int ui_popup_up(void)
{
    return pop_top >= 0 || pop_free >= 0;
}

int ui_popup_rect(rect_t *r)
{
    int from, to;

    if (!ui_popup_up())
        return 0;
    pop_box(&r->x, &r->y, &r->w, &r->h, &from, &to);
    return 1;
}

int ui_popup_top(void)
{
    return pop_top;
}

int ui_popup_hit(int x, int y)
{
    int px, py, pw, ph, from, to, k;

    if (!ui_popup_up())
        return -1;
    if (pop_sub >= 0) {
        int sx, sy, sw, sh, sf, st;

        sub_box(&sx, &sy, &sw, &sh, &sf, &st);
        k = pop_at(sf, st, 2, sx, sy, sw, x, y);
        if (k >= 0)
            return k;
    }
    pop_box(&px, &py, &pw, &ph, &from, &to);
    return pop_at(from, to, pop_depth(), px, py, pw, x, y);
}

int ui_popup_in(int x, int y)
{
    int px, py, pw, ph, from, to;

    if (!ui_popup_up())
        return 0;
    if (pop_sub >= 0) {
        int sx, sy, sw, sh, sf, st;

        sub_box(&sx, &sy, &sw, &sh, &sf, &st);
        if (x >= sx && x < sx + sw && y >= sy && y < sy + sh)
            return 1;
    }
    pop_box(&px, &py, &pw, &ph, &from, &to);
    return x >= px && x < px + pw && y >= py && y < py + ph;
}

int ui_popup_move(int x, int y)
{
    int k = ui_popup_hit(x, y), redraw = 0;

    if (k != pop_hot) {
        pop_hot = k;
        redraw = 1;
    }
    /* Hovering an item of the top-level popup opens its submenu, or shuts
       the one that is open -- which is what Windows does. */
    if (k >= 0 && jw_menu_tree[k].depth == 1) {
        int want = jw_menu_tree[k].kind == 1 ? k : -1;

        if (want != pop_sub) {
            pop_sub = want;
            redraw = 1;
        }
    }
    return redraw;
}

int ui_popup_press(int x, int y)
{
    int k = ui_popup_hit(x, y);

    if (k < 0 || jw_menu_tree[k].kind == 2)
        return 0;
    if (jw_menu_tree[k].kind == 1) {    /* a submenu: open it, run nothing */
        pop_sub = k;
        return 0;
    }
    return jw_menu_tree[k].id;
}

static void pop_paint(fb_t *fb, int x0, int y0, int w, int h,
                      int from, int to, int depth)
{
    int th = jw_text_height();
    int y = y0 + JW_POPUP_BORDER, i;

    fb_fill(fb, x0, y0, w, h, JW_POPUP_FACE);
    fb_edge(fb, x0, y0, w, h, JW_POPUP_EDGE, JW_POPUP_EDGE);
    for (i = from; i < to; i++) {
        const jw_menu_item_t *m = &jw_menu_tree[i];
        char lab[256];
        const char *acc;
        int ty;

        if (m->depth != depth)
            continue;
        if (m->kind == 2) {
            fb_hline(fb, x0 + 12, y + JW_POPUP_SEP_H / 2, w - 24,
                     JW_POPUP_EDGE);
            y += JW_POPUP_SEP_H;
            continue;
        }
        if (i == pop_hot || (m->kind == 1 && i == pop_sub))
            fb_fill(fb, x0 + 3, y, w - 6, JW_POPUP_ITEM_H, JW_POPUP_HOT);
        acc = pop_label(m->text, lab, sizeof lab);
        ty = y + (JW_POPUP_ITEM_H - th) / 2;
        jw_text_px(fb, x0 + JW_POPUP_TEXT_X, ty, lab, C_BTNTEXT);
        if (acc)
            jw_text_px(fb, x0 + w - 16 - jw_text_px_w(acc), ty, acc,
                       C_GRAYTEXT);
        if (m->kind == 1)               /* the arrow that says it opens */
            jw_text_px(fb, x0 + w - 16, ty, ">", C_BTNTEXT);
        else if (m->id && ((int)m->id == jw_cmd()
                           || (int)m->id == pop_mark))
            jw_text_px(fb, x0 + 16, ty, "*", C_BTNTEXT);
        y += JW_POPUP_ITEM_H;
    }
}

void ui_popup_draw(fb_t *fb)
{
    int px, py, pw, ph, from, to;

    if (!ui_popup_up())
        return;
    pop_box(&px, &py, &pw, &ph, &from, &to);
    pop_paint(fb, px, py, pw, ph, from, to, pop_depth());
    if (pop_sub >= 0) {
        int sx, sy, sw, sh, sf, st;

        sub_box(&sx, &sy, &sw, &sh, &sf, &st);
        pop_paint(fb, sx, sy, sw, sh, sf, st, 2);
    }
}

int ui_menu_hit(int x, int y)
{
    int i;

    if (y < JW_CAPTION_H || y >= JW_CHROME_H)
        return -1;
    for (i = 0; i < JW_NMENU; i++) {
        int x0 = jw_menu[i].x - 8;
        int x1 = jw_menu[i].x + jw_text_count(jw_menu[i].text) * 6 + 8;
        if (x >= x0 && x < x1)
            return i;
    }
    return -1;
}

int ui_right(int x, int cw)
{
    return x + cw - JW_REF_W;
}

int ui_bottom(int y, int ch)
{
    return y + ch - JW_REF_H;
}

int ui_ax(int x, int cw)
{
    return x >= JW_RIGHT_X ? ui_right(x, cw) : x;
}

int ui_ay(int y, int ch)
{
    return y >= JW_BOTTOM_Y ? ui_bottom(y, ch) : y;
}

static void paint_bars(fb_t *fb)
{
    int k;

    for (k = 0; k < NBARS; k++) {
        const bar_t *b = &bars[k];
        int x = b->x, y = b->y, w = b->w, h = b->h;

        if (b->anchor & A_RIGHT)
            x = ui_right(x, fb->w);
        if (b->anchor & A_BOTTOM)
            y = ui_bottom(y, fb->h);
        if (b->anchor & A_WIDE)
            w = ui_right(x + w, fb->w) - x;
        if (b->anchor & A_TALL)
            h = ui_bottom(y + h, fb->h) - y;

        if (b->borders & B_TOP) {
            fb_hline(fb, x, y, w, C_BTNSHADOW);
            fb_hline(fb, x, y + 1, w, C_BTNHILIGHT);
            y += 2;
            h -= 2;
        }
        if (b->borders & B_LEFT) {
            fb_vline(fb, x, y, h, C_BTNSHADOW);
            fb_vline(fb, x + 1, y, h, C_BTNHILIGHT);
            x += 2;
            w -= 2;
        }
        fb_fill(fb, x, y, w, h, b->face);
    }
}

/* The layer-group and layer grids: two 2x8 grids of 19x21 cells, each cell a
 * bitmap from the resources.  **The one being written to** uses the variant
 * with the black top and left edge (2652); the others carry black on the
 * bottom and right (2662).  It looked like "the top-left cell" for a long
 * while, because a new drawing writes to group 0 and layer 0 and those are
 * the top-left cells -- but Test6.jww writes to group 4, and there the
 * original puts the 2652 cell on row 4 of the group grid and leaves row 0
 * alone.  Only the face colour is remapped -- the grey stays 0x808080,
 * unlike a toolbar bitmap. */
#define LAYER_CELL_W 19
#define LAYER_CELL_H 21

static void blit_layer_cell(fb_t *fb, int id, int x, int y, int clipright)
{
    const jw_bitmap_t *bm = jw_bitmap(id);
    int i, j;

    if (!bm)
        return;
    for (j = 0; j < bm->h; j++) {
        if (y + j < 0 || y + j >= fb->h)
            continue;
        for (i = 0; i < bm->w; i++) {
            const unsigned char *p;
            unsigned int c;
            if (x + i < 0 || x + i >= fb->w || x + i > clipright)
                continue;
            p = bm->pal + 3 * bm->idx[(size_t)j * bm->w + i];
            c = ((unsigned)p[0] << 16) | ((unsigned)p[1] << 8) | p[2];
            if (c == 0xc0c0c0u)
                c = C_BTNFACE;
            fb->px[(size_t)(y + j) * fb->w + x + i] = c;
        }
    }
}

/* GDI's Ellipse() inscribed in a 16x16 box -- the ring that marks the layer
 * group being written to. */
static const unsigned short circle16[16] = {
    0x07e0, 0x0810, 0x300c, 0x2004, 0x4002, 0x8001, 0x8001, 0x8001,
    0x8001, 0x8001, 0x8001, 0x4002, 0x2004, 0x300c, 0x0810, 0x07e0,
};

/* Where the two grids sit and how far they may draw, measured off the
 * reference screen.  The bar clips them: the right-hand column's cell would
 * otherwise put its black edge over the groove beside it.
 *
 * The left grid is the sixteen layers, the right the sixteen layer groups;
 * a cell's column is the index over eight and its row the index under it,
 * so layer 10 is the third cell of the second column. */
static const struct { short x, y, clip; } layer_grids[2] = {
    { 1188, 394, 1224 },        /* layers, circled digits   */
    { 1227, 397, 1263 },        /* layer groups, plain ones */
};

/* The mark for "there is something on this one", two rows across the top.
 * It comes in two halves: nine pixels on the left when the layer holds
 * anything that is not text, eight on the right when it holds text.  The
 * original sets them from two calls of its own (FUN_00555800 asks the
 * document twice per layer and lights bit 1 or bit 2 of the cell), and the
 * shipped drawings show every combination -- layer 4 of サンプル.jww holds
 * eight texts and nothing else, and its mark is the right-hand half alone;
 * layer 7 of Ａマンション平面例.jww holds lines, points and texts, and its
 * mark runs the whole way across. */
#define C_HASDATA  0xd700d7u
#define BAR_L      9            /* the left half, from x+1  */
#define BAR_R      8            /* the right half, from x+9 */

static void paint_layer_grids(fb_t *fb, const jw_drawing *d)
{
    int used[2][16], text[2][16];
    int write[2];
    int g, col, row, i, j, k;

    for (g = 0; g < 2; g++) {
        write[g] = 0;
        for (i = 0; i < 16; i++)
            used[g][i] = text[g][i] = 0;
    }
    if (d) {
        int wg = 0;
        for (i = 0; i < 16; i++)
            if (d->group[i].state == 3)
                wg = i;
        write[1] = wg;
        write[0] = d->group[wg].write_layer & 15;
        for (k = 0; k < d->nobj; k++) {
            const jw_obj *o = &d->obj[k];
            int *u = o->cls == JW_MOJI ? text[1] : used[1];
            u[o->lgroup & 15] = 1;
            if ((o->lgroup & 15) == wg) {
                u = o->cls == JW_MOJI ? text[0] : used[0];
                u[o->layer & 15] = 1;
            }
        }
    }

    for (g = 0; g < 2; g++) {
        for (col = 0; col < 2; col++) {
            for (row = 0; row < 8; row++) {
                int n = col * 8 + row;
                int x = ui_right(layer_grids[g].x, fb->w)
                        + col * LAYER_CELL_W;
                int y = layer_grids[g].y + row * LAYER_CELL_H;

                blit_layer_cell(fb, n == write[g] ? 2652 : 2662,
                                x, y,
                                ui_right(layer_grids[g].clip, fb->w));
                if (n == write[g]) {
                    /* a red bar if it holds anything, then the mark: a ring
                     * for the layer, a box for the group */
                    if (used[g][n])
                        fb_fill(fb, x + 2, y + 2, BAR_L, 2, 0xff0000u);
                    if (text[g][n])
                        fb_fill(fb, x + 10, y + 2, BAR_R, 2, 0xff0000u);
                    if (g == 0) {
                        for (j = 0; j < 16; j++)
                            for (i = 0; i < 16; i++)
                                if (circle16[j] & (1 << i))
                                    fb_fill(fb, x + 2 + i, y + 4 + j, 1, 1,
                                            0xff0000u);
                    } else {
                        fb_edge(fb, x + 2, y + 4, 16, 16, 0xff0000u, 0xff0000u);
                    }
                } else {
                    /* a group cell carries a black box round its digit only
                     * while the group can be drawn on: 表示のみ and 非表示
                     * ones show the bar that says they hold something and
                     * nothing else (Test6.jww has three of them) */
                    if (g == 1 && d && d->group[n].state >= 2)
                        fb_edge(fb, x + 1, y + 3, 16, 16,
                                C_BTNTEXT, C_BTNTEXT);
                    if (used[g][n])
                        fb_fill(fb, x + 1, y + 1, BAR_L, 2, C_HASDATA);
                    if (text[g][n])
                        fb_fill(fb, x + 9, y + 1, BAR_R, 2, C_HASDATA);
                }
            }
        }
    }
}

int ui_layer_hit(int cw, int x, int y, int *n)
{
    int g, col, row;

    for (g = 0; g < 2; g++)
        for (col = 0; col < 2; col++)
            for (row = 0; row < 8; row++) {
                int cx = ui_right(layer_grids[g].x, cw) + col * LAYER_CELL_W;
                int cy = layer_grids[g].y + row * LAYER_CELL_H;
                if (x >= cx && x < cx + LAYER_CELL_W
                    && y >= cy && y < cy + LAYER_CELL_H) {
                    *n = col * 8 + row;
                    return g;
                }
            }
    return -1;
}


/* The four square buttons under the layer grids (All / 0 / All / X).  Same
 * chrome as a toolbar button, but 25x21 and their captions are text. */
static const struct { short x, y; } small_buttons[4] = {
    { 1194, 564 }, { 1194, 587 },       /* under the layer-group grid */
    { 1234, 567 }, { 1234, 590 },       /* under the layer grid       */
};
#define SMALL_W 25
#define SMALL_H 21

/* The line-type sample: a white box with a hand-drawn frame in raw greys
 * (0xc0c0c0 and 0x8c8c8c), not system colours, and the current line drawn
 * across the middle. */
static const struct { short x, y; } samples[2] = {
    {   41, 493 },      /* left bar  */
    { 1190, 346 },      /* right bar */
};
#define SAMPLE_W 33
#define SAMPLE_H 19

static void paint_samples(fb_t *fb, const jw_drawing *d)
{
    /* the pen being written with, which is what the 矩形 bar's colour
       button shows as well -- the two are the same setting */
    int pen = d && d->write_ltype ? d->write_color : 2;
    int lt = d && d->write_ltype ? d->write_ltype : 1;
    unsigned rgb;
    int k;

    if (pen < 1 || pen > 9)
        pen = 2;
    if (lt < 1 || lt > 9)
        lt = 1;
    rgb = d ? d->pen_rgb[pen] : jw_default_pen_rgb[pen];
    for (k = 0; k < 2; k++) {
        int x = ui_ax(samples[k].x, fb->w), y = samples[k].y;

        fb_fill(fb, x + 1, y + 1, SAMPLE_W - 2, SAMPLE_H - 2, C_WINDOW);
        fb_edge(fb, x, y, SAMPLE_W, SAMPLE_H, 0xc0c0c0u, 0x8c8c8cu);
        /* the black shadow is an L, not a box: right edge and underside */
        fb_vline(fb, x + SAMPLE_W, y - 1, SAMPLE_H + 2, C_BTNTEXT);
        fb_hline(fb, x - 1, y + SAMPLE_H, SAMPLE_W + 2, C_BTNTEXT);
        /* the current line type, drawn across the middle, in the pen being
         * written with -- black until the pen is changed, which is why it
         * looked fixed.  The dashes are the same bits the drawing itself is
         * drawn with (src/draw.c's LTYPE), one bit to a pixel, started at
         * the left edge of the box. */
        {
            int i;
            for (i = 0; i < SAMPLE_W - 2; i++)
                if (jw_ltype_bit(lt, i))
                    px_put(fb, x + 1 + i, y + 9, rgb);
        }
    }
}

/* The status line: a face-coloured bar with a row of panes and a size grip. */
static const struct { short x0, x1; } panes[5] = {
    /* Read off the original's own window: the highlight down each box's left
       edge and the shadow down its right, in the capture at 1264x741.  The
       first three were five pixels right of these. */
    {  982, 1017 }, { 1020, 1081 }, { 1084, 1153 },
    { 1156, 1185 }, { 1188, 1244 },
};
#define PANE_T 724

/* What the original puts in the status line: a prompt on the left, then the
 * sheet size, the scale of the group being written to, which layer that is,
 * the current angle and the zoom.  The glyphs come out of the port's own
 * font, so they do not match the original's -- only where they sit does. */
static void status_text(fb_t *fb, const jw_drawing *d, double zoom)
{
    static const char *PAPER[] = { "A-0", "A-1", "A-2", "A-3", "A-4",
                                   "B-4", "B-5", "B-6", "2A", "3A",
                                   "4A", "5A", "10m", "50m", "100m" };
    char buf[64];
    int wg = 0, i, ty = ui_bottom(726, fb->h);

    /* The prompt is the command's own, out of the string table. */
    jw_text_px(fb, 8, ty, jw_cmd_status(d), C_BTNTEXT);
    if (!d)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    jw_text_px(fb, ui_right(panes[0].x0 + 4, fb->w), ty,
               d->paper_size >= 0 && d->paper_size < 15
               ? PAPER[d->paper_size] : "?", C_BTNTEXT);
    sprintf(buf, "S=1/%g", d->group[wg].scale);
    jw_text_px(fb, ui_right(panes[1].x0 + 4, fb->w), ty, buf, C_BTNTEXT);
    sprintf(buf, "[%X-%X]", wg, d->group[wg].write_layer & 15);
    jw_text_px(fb, ui_right(panes[2].x0 + 4, fb->w), ty, buf, C_BTNTEXT);
    {   /* 軸角: the angle the drawing is being worked at, which the
           status line's own box and the menu both set.  It was a fixed
           zero here, so setting it changed nothing on the screen. */
        double ax = jw_cmd_axis();
        sprintf(buf, "\x81\xda %g", ax);
        jw_text_px(fb, ui_right(panes[3].x0 + 4, fb->w), ty, buf,
                   C_BTNTEXT);
    }
    /* two decimals, cut not rounded, and a trailing zero dropped: the
       original shows 0.21, 0.3, 0.42 and 0.1 for the four sheet sizes */
    {
        /* Cut, do not round, and drop a trailing zero.  The cast to long is
           undefined when the value does not fit, and the zoom is a quotient
           the command bar can drive as far as it likes, so clamp first --
           the same hole as the pen width in src/coord.c. */
        double z = zoom * 100.0 + 1e-9;

        /* written as !(a > b) so that a NaN falls into the first clamp */
        if (!(z > -2147483000.0)) z = -2147483000.0;
        if (!(z <  2147483000.0)) z =  2147483000.0;
        sprintf(buf, "\x81\x7e %g", (double)(long)z / 100.0);
    }
    jw_text_px(fb, ui_right(panes[4].x0 + 4, fb->w), ty, buf, C_BTNTEXT);
}

/* Which of the five boxes at the right of the status line a point is in.
 *
 * The original hit-tests them itself -- they are status bar parts, not
 * windows -- and on the release sends the frame a command: FUN_00596e80
 * walks parts 1 to 5, and for the one the press went down in sends WM_COMMAND
 * 0x8039, 0x803b, 0x803d, 0x804b, 0x804c.  Those are the ids the resource
 * calls 用紙サイズ, scale, Layer, 軸角 and 画面表示倍率, so a box is a
 * menu command with a number painted on it. */
/* One of the five boxes of the status line, in client coordinates --
   so that whatever hangs off a box knows where it is. */
void ui_status_box(int k, int cw, int ch, rect_t *r)
{
    r->x = ui_right(panes[k].x0, cw);
    r->w = ui_right(panes[k].x1, cw) - r->x + 1;
    r->y = ui_bottom(PANE_T, ch);
    r->h = ch - r->y;
}

int ui_status_hit(int x, int y, int cw, int ch)
{
    int k;

    if (status_hidden)
        return -1;
    if (y < ui_bottom(PANE_T, ch) || y > ch - 1)
        return -1;
    for (k = 0; k < 5; k++)
        if (x >= ui_right(panes[k].x0, cw) && x <= ui_right(panes[k].x1, cw))
            return k;
    return -1;
}

static void paint_status(fb_t *fb)
{
    int k, i, j;
    int bottom = fb->h - 1;

    for (k = 0; k < 5; k++) {
        int x0 = ui_right(panes[k].x0, fb->w);
        int x1 = ui_right(panes[k].x1, fb->w);
        int t = ui_bottom(PANE_T, fb->h);
        fb_edge(fb, x0, t, x1 - x0 + 1, bottom - t + 1,
                C_BTNHILIGHT, C_BTNSHADOW);
    }

    /* The size grip in the corner: three diagonals of highlight-shadow-shadow
     * running up and to the right from one pixel inside the bottom right. */
    for (i = 0; i < 12; i++) {
        int y = bottom - 1 - i;
        int x0 = fb->w - 2 - 11 + i;
        for (k = 0; k < 3; k++) {
            int x = x0 + 4 * k;
            if (x > fb->w - 2)
                break;
            px_put(fb, x, y, C_BTNHILIGHT);
            for (j = 1; j <= 2; j++)
                if (x + j <= fb->w - 2)
                    px_put(fb, x + j, y, C_BTNSHADOW);
        }
    }
}

/* The command bar across the top is a CDialogBar, so its contents are
 * ordinary Windows controls.  Positions are measured off the reference; the
 * dialog template (DIALOG 280 for the line command) gives them in dialog
 * units, which only convert to pixels once the dialog font is known. */
#define CHECK_Y 11
#define CHECK_W 13
#define CHECK_H 12

/* The tick Windows itself puts in a checked box.  Taken from a real
 * BS_AUTOCHECKBOX printed into a memory bitmap with WM_PRINTCLIENT
 * (tmp/dfc2.c -- no window is ever shown), so it is the button control's own
 * glyph, not a drawing of one.  Rows and columns are from the box's corner. */
static void paint_tick_col(fb_t *fb, int x, int y, unsigned int col)
{
    /* col ranges per row, from the control's own bitmap */
    static const signed char run[7][4] = {
        { 9, 9, -1, -1 },
        { 8, 9, -1, -1 },
        { 3, 3,  7,  9 },
        { 3, 4,  6,  8 },
        { 3, 7, -1, -1 },
        { 4, 6, -1, -1 },
        { 5, 5, -1, -1 }
    };
    int r, i, c;

    for (r = 0; r < 7; r++)
        for (i = 0; i < 4; i += 2)
            for (c = run[r][i]; run[r][i] >= 0 && c <= run[r][i + 1]; c++)
                fb_fill(fb, x + c, y + 3 + r, 1, 1, col);
}

static void paint_tick(fb_t *fb, int x, int y)
{
    paint_tick_col(fb, x, y, C_BTNTEXT);
}

static void paint_checkbox(fb_t *fb, int x, int y, int checked)
{
    fb_hline(fb, x, y, CHECK_W - 1, C_BTNSHADOW);
    fb_vline(fb, x, y, CHECK_H, C_BTNSHADOW);
    fb_vline(fb, x + CHECK_W - 1, y, CHECK_H, C_BTNHILIGHT);
    fb_hline(fb, x + 1, y + 1, CHECK_W - 3, C_3DDKSHADOW);
    fb_vline(fb, x + 1, y + 1, CHECK_H - 2, C_3DDKSHADOW);
    fb_vline(fb, x + CHECK_W - 2, y + 1, CHECK_H - 1, C_3DLIGHT);
    fb_hline(fb, x + 1, y + CHECK_H - 1, CHECK_W - 2, C_3DLIGHT);
    fb_fill(fb, x + 2, y + 2, CHECK_W - 4, CHECK_H - 3, C_WINDOW);
    if (checked)
        paint_tick(fb, x, y);
}

#define COMBO_Y 8
#define COMBO_H 20
#define DROP_W 17
#define DROP_H 16

static void paint_combo(fb_t *fb, int x, int y, int w, int h)
{
    int dx = x + w - 19, dy = y + 2;
    int i;

    fb_edge(fb, x, y, w, h, C_BTNSHADOW, C_BTNHILIGHT);
    fb_edge(fb, x + 1, y + 1, w - 2, h - 2, C_3DDKSHADOW, C_3DLIGHT);
    fb_fill(fb, x + 2, y + 2, w - 4, h - 4, C_WINDOW);

    /* the drop-down button, with the arrow drawn as four shrinking rows */
    fb_edge(fb, dx, dy, DROP_W, DROP_H, C_3DLIGHT, C_3DDKSHADOW);
    fb_edge(fb, dx + 1, dy + 1, DROP_W - 2, DROP_H - 2,
            C_BTNHILIGHT, C_BTNSHADOW);
    fb_fill(fb, dx + 2, dy + 2, DROP_W - 4, DROP_H - 4, C_BTNFACE);
    for (i = 0; i < 4; i++)
        fb_hline(fb, dx + 4 + i, dy + 6 + i, 7 - 2 * i, C_BTNTEXT);
}

/* A raised button sitting in a one-pixel sunken groove, the way the command
   bar's wide buttons look. */
static void paint_barbutton(fb_t *fb, int x, int y, int w, int h)
{
    fb_edge(fb, x, y, w, h, C_BTNSHADOW, C_BTNHILIGHT);
    button_frame(fb, x + 1, y + 1, w - 2, h - 2, 0);
    fb_fill(fb, x + 3, y + 3, w - 6, h - 6, C_BTNFACE);
}

/* The 文字 command's floating box.
 *
 * Where it sits and what is on it were read out of the running original the
 * same way the command bars were (tmp/jwdraw.ps1, the `box` step): it is a
 * #32770 popup 700x65 with a 684x26 client, at 81,39 in the frame's client
 * area, carrying a combo box for the text at 3,1 461x26, one for the font at
 * 471,3 120x20, and a フォント読取 button at 596,3 90x20.
 *
 * The frame and the caption are the only part of this port that is not
 * pixel for pixel: they are a themed window frame -- rounded corners and a
 * gradient -- rather than something MFC draws flat, and baking those pixels
 * would cost more than a decoration is worth.  Everything inside is where
 * the original puts it.
 */
#define BOX_X 81
#define BOX_Y 39
#define BOX_W 700
#define BOX_H 65
#define BOX_CX 8                /* the client's corner inside the box */
#define BOX_CY 31
#define BOX_CW 684
#define BOX_CH 26
#define C_CAPTION 0x99b4d1u     /* what DrawCaption fills an active one with */

void ui_textbox(fb_t *fb, const char *line, const char *composing)
{
    int x = BOX_X, y = BOX_Y, th = jw_text_height();

    fb_fill(fb, x, y, BOX_W, BOX_H, C_BTNFACE);
    fb_edge(fb, x, y, BOX_W, BOX_H, C_3DLIGHT, C_3DDKSHADOW);
    fb_fill(fb, x + 2, y + 2, BOX_W - 4, BOX_CY - 4, C_CAPTION);
    fb_fill(fb, x + BOX_CX, y + BOX_CY, BOX_CW, BOX_CH, C_BTNFACE);

    x += BOX_CX;
    y += BOX_CY;
    paint_combo(fb, x + 3, y + 1, 461, 26);
    paint_combo(fb, x + 471, y + 3, 120, 20);
    paint_barbutton(fb, x + 596, y + 3, 90, 20);
    jw_text_px(fb, x + 601, y + 3 + (20 - th) / 2,
               /* フォント読取, in CP932 */
               "\x83" "\x74" "\x83" "\x48" "\x83" "\x93" "\x83" "\x67" "\x93" "\xc7" "\x8e" "\xe6", C_BTNTEXT);
    /* what has been typed, in the first combo's edit, and after it whatever
       an IME is still converting -- underlined, the way one is shown in an
       edit control */
    {
        int tx = x + 6, ty = y + 4 + (20 - th) / 2;
        if (line && *line)
            tx = jw_text_px(fb, tx, ty, line, C_BTNTEXT);
        if (composing && *composing) {
            int end = jw_text_px(fb, tx, ty, composing, C_BTNTEXT);
            fb_hline(fb, tx, ty + th - 1, end - tx, C_BTNTEXT);
            tx = end;
        }
        /* The caret.  The original's box is a real edit control, so Windows
           gives it a blinking one; this is the same bar, standing still.
           Without it there is nothing to say the box takes typing. */
        fb_fill(fb, tx, ty, 1, th, C_BTNTEXT);
    }
}

/* ------------------------------------------------------------------ 線属性
 *
 * The dialog the 線属性 button puts up.  Its controls come from
 * src/gen/zoku.h, read out of the running original; how they are drawn was
 * read off the same dialog painted into a bitmap, and is spelled out here
 * because the two owner-draw buttons are Jw_cad's own, not Windows':
 *
 *   not the chosen one -- a black rectangle round the whole button, with a
 *   shadow down the inside of its right and bottom edges;
 *   the chosen one    -- black along the top and the left only, a shadow
 *   inset on all four sides, a tick at the left, and everything inside
 *   moved one pixel right and down.
 *
 * Inside sits the sample: for a colour, a bar 32 by 4 at 16,6 in the pen's
 * own colour; for a line type, one row of 33 pixels at 16,8 drawn with that
 * type's pattern.
 */
#define ZK_SWATCH_X  16
#define ZK_SWATCH_Y   6
#define ZK_SWATCH_W  32
#define ZK_SWATCH_H   4
#define ZK_SAMPLE_Y   8
#define ZK_SAMPLE_W  33

void ui_zoku_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_ZOKU_W;
    r->h = JW_ZOKU_H;
    /* Across the client, and up by the status bar: the original put it at
       478,162 in a 1264 by 741 one, which is exactly this. */
    r->x = (cw - JW_ZOKU_W) / 2;
    r->y = (ch - 42 - JW_ZOKU_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

/* Jw_cad draws these itself, in the greys Windows used to have rather than
   the ones the theme gives the rest of the dialog. */
#define ZK_FACE   0xc0c0c0u
#define ZK_SHADOW 0x808080u

static void zk_button(fb_t *fb, int x, int y, int w, int h, int chosen)
{
    fb_fill(fb, x, y, w, h, ZK_FACE);
    if (!chosen) {
        fb_edge(fb, x, y, w, h, C_BTNTEXT, C_BTNTEXT);
        fb_vline(fb, x + w - 2, y + 1, h - 2, ZK_SHADOW);
        fb_hline(fb, x + 1, y + h - 2, w - 2, ZK_SHADOW);
        return;
    }
    fb_hline(fb, x, y, w, C_BTNTEXT);
    fb_vline(fb, x, y, h, C_BTNTEXT);
    fb_hline(fb, x + 1, y + 1, w - 1, ZK_SHADOW);
    fb_vline(fb, x + 1, y + 1, h - 1, ZK_SHADOW);
    fb_vline(fb, x + w - 1, y + 1, h - 1, ZK_SHADOW);
    fb_hline(fb, x + 1, y + h - 1, w - 1, ZK_SHADOW);
    paint_tick(fb, x, y + 2);
}

/* one row of a line type, the way src/draw.c walks the pattern */
static void zk_sample(fb_t *fb, int x, int y, int w, int lt, unsigned int col)
{
    static const struct { unsigned int bits; int unit; } LT[10] = {
        { 0xffffffffu, 32 }, { 0xffffffffu, 32 }, { 0x99999999u,  4 },
        { 0xc3c3c3c3u,  8 }, { 0xe7e7e7e7u,  8 }, { 0xf99ff99fu, 16 },
        { 0xfff99fffu, 32 }, { 0xf24ff24fu, 16 }, { 0xfff24fffu, 32 },
        { 0x22222222u,  4 },
    };
    int i;

    if (lt < 0 || lt > 9)
        lt = 1;
    for (i = 0; i < w; i++)
        if (LT[lt].bits & (1u << (i % LT[lt].unit)))
            fb_fill(fb, x + i, y, 1, 1, col);
}

void ui_zoku(fb_t *fb, const jw_drawing *d, int colour, int ltype)
{
    (void)d;    /* the swatches are the settings' colours, not the file's */
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_zoku_rect(fb->w, fb->h, &r);
    /* the frame.  Windows draws a themed one round a real dialog; this is
       the same shape, flat -- the same trade the 文字 box makes. */
    fb_fill(fb, r.x, r.y, r.w, r.h, C_BTNFACE);
    fb_edge(fb, r.x, r.y, r.w, r.h, C_3DLIGHT, C_3DDKSHADOW);
    fb_fill(fb, r.x + 2, r.y + 2, r.w - 4, JW_ZOKU_CAPTION - 4, C_CAPTION);
    jw_text_px(fb, r.x + 6, r.y + 2 + (JW_ZOKU_CAPTION - 4 - th) / 2,
               /* 線属性 */
               "\x90\xfc\x91\xae\x90\xab", 0xffffffu);
    cx = r.x + JW_ZOKU_BORDER;
    cy = r.y + JW_ZOKU_CAPTION;
    fb_fill(fb, cx, cy, JW_ZOKU_CW, JW_ZOKU_CH, C_BTNFACE);

    {   /* The two panels the dialog paints itself.  On the left a white box
           with the line as it will be drawn, on the right the width sample.
           Both measured off the original's own dialog. */
        fb_edge(fb, cx + 34, cy + 218, 136, 24, C_BTNTEXT, C_BTNTEXT);
        fb_fill(fb, cx + 35, cy + 219, 134, 22, C_WINDOW);
        zk_sample(fb, cx + 46, cy + 230, 113, ltype,
                  jw_default_pen_rgb[colour % 10]);
        fb_fill(fb, cx + 176, cy + 220, 89, 19, ZK_FACE);
        fb_fill(fb, cx + 186, cy + 229, 72, 2, C_BTNTEXT);
    }
    for (i = 0; i < JW_NZOKU; i++) {
        const jw_zk_t *z = &jw_zoku[i];
        int x = cx + z->x, y = cy + z->y, on;

        switch (z->kind) {
        case JW_ZK_COLOR:
            on = z->n == colour;
            zk_button(fb, x, y, z->w, z->h, on);
            fb_fill(fb, x + ZK_SWATCH_X + on, y + ZK_SWATCH_Y + on,
                    ZK_SWATCH_W, ZK_SWATCH_H,
                    jw_default_pen_rgb[z->n % 10]);
            break;
        case JW_ZK_TYPE:
            on = z->n == ltype;
            zk_button(fb, x, y, z->w, z->h, on);
            zk_sample(fb, x + ZK_SWATCH_X + on, y + ZK_SAMPLE_Y + on,
                      ZK_SAMPLE_W, z->n, C_BTNTEXT);
            break;
        case JW_ZK_OK:
        case JW_ZK_CANCEL: {
            /* A themed push button: white and the light grey outside, the
               dark shadow and the shadow inside -- and Ok, being the one
               Enter presses, carries one more ring of 0x646464 round the
               lot.  Both read off the original's own dialog. */
            int k2 = z->kind == JW_ZK_OK;
            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            jw_text_px(fb, x + (z->w - jw_text_count(z->text) * 6) / 2,
                       y + (z->h - th) / 2, z->text, C_BTNTEXT);
            break;
        }
        case JW_ZK_CHECK:
            paint_checkbox(fb, x, y + (z->h - CHECK_W) / 2, 0);
            /* one row taller here than on the command bars: the dialog's
               box has a white edge under it as well */
            fb_hline(fb, x, y + (z->h - CHECK_W) / 2 + CHECK_H, CHECK_W,
                     C_BTNHILIGHT);
            jw_text_px(fb, x + CHECK_W + 3, y + (z->h - th) / 2, z->text,
                       C_BTNTEXT);
            break;
        case JW_ZK_STATIC:
            jw_text_px(fb, x, y + (z->h - th) / 2, z->text, C_BTNTEXT);
            break;
        }
    }
}

int ui_zoku_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_zoku_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside the dialog altogether */
    x -= r.x + JW_ZOKU_BORDER;
    y -= r.y + JW_ZOKU_CAPTION;
    for (i = 0; i < JW_NZOKU; i++) {
        const jw_zk_t *z = &jw_zoku[i];
        if (z->kind == JW_ZK_STATIC)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* ------------------------------------------------------- 書込み文字種変更
 *
 * The dialog the 文字 bar's 1843 button puts up.  Its controls come from
 * src/gen/moji.h, read out of the running original the same way 線属性's
 * were; the radio button is Windows' own and is baked from the picture of
 * the dialog rather than drawn, because nothing here would draw a circle.
 *
 * The ten rows of numbers are the drawing's own 文字種 table, and the last
 * column is how many texts are written in each -- which is why the dialog
 * takes the drawing.
 */
#define MJ_CAPTION_BG 0xf3f3f3u /* this one's caption came out light */

/* -------------------------------------------- ダイアログの外枠と × ----
 *
 * **GetWindowRect の矩形は、画面に出ているものより左右と下が 7 画素ずつ
 * 大きい。**Windows 10 以降が掴みしろとして持っている見えない縁で、
 * `DwmGetWindowAttribute(DWMWA_EXTENDED_FRAME_BOUNDS)` がそう答えます
 * （`tools/probe116.sh`: 504x227 の窓のうち見えているのは 490x220、
 * 左 7・上 0・右 7・下 7）。`docs/ref_*.png` でそこが真っ黒なのは
 * PrintWindow の絵だからで、**プログラムはそこに何も描いていません**。
 * 移植はその黒をそのまま塗っていたので、外枠が真っ黒に見えていました。
 *
 * 見えている 490x220 の縁一画素は DWM が半透明の灰で描きます。画面から
 * 測ると（`dlgshot:`）**後ろの色の九分の五に 7c7c7c の九分の四**を足して
 * 切り捨てた色です。画面から取った四通りが一つ残らずこの式に合います
 * （f3f3f3 の上で bebebe、d8d8d8 で afafaf、b1b1b1 で 999999、
 * d0d0d0 で aaaaaa）。
 * 中身はその内側で、見出しとクライアントが窓座標の x = 8 から CW 画素
 * ぶん並びます（どのダイアログも BORDER 8・CAPTION 31）。上の縁一画素は
 * **見出しの上に重なります** —— 原典のその行が bebebe、つまり f3f3f3 に
 * 掛けた色だったので。左右と下の縁は後ろの絵に直に掛かります。
 */
#define DLG_BORDER   8
#define DLG_CAPTION  31
#define DLG_EDGE_RGB 0x7c7c7cu
#define DLG_EDGE_NUM 4                  /* 7c7c7c の分、九分の四 */
#define DLG_EDGE_DEN 9

static unsigned int dlg_mix(unsigned int under)
{
    unsigned int o = 0, i;

    for (i = 0; i < 3; i++) {
        unsigned int sh = i * 8;
        unsigned int a = (under >> sh) & 0xff, b = (DLG_EDGE_RGB >> sh) & 0xff;

        o |= ((a * (DLG_EDGE_DEN - DLG_EDGE_NUM) + b * DLG_EDGE_NUM)
              / DLG_EDGE_DEN) << sh;
    }
    return o;
}

static void dlg_edge_px(fb_t *fb, int x, int y)
{
    if (x >= 0 && y >= 0 && x < fb->w && y < fb->h)
        fb->px[y * fb->w + x] = dlg_mix(fb->px[y * fb->w + x]);
}

/* The one pixel of frame Windows draws round the visible window. */
static void dlg_edge(fb_t *fb, int x, int y, int w, int h)
{
    int i;

    for (i = 0; i < w; i++) {
        dlg_edge_px(fb, x + i, y);
        dlg_edge_px(fb, x + i, y + h - 1);
    }
    for (i = 1; i < h - 1; i++) {
        dlg_edge_px(fb, x, y + i);
        dlg_edge_px(fb, x + w - 1, y + i);
    }
}

/* 見出しと外枠。`r` は窓そのもの（GetWindowRect のほう）の矩形で、
   `cw`/`ch` はクライアント。見えない縁には何も置きません。 */
static void dlg_chrome(fb_t *fb, const rect_t *r, int cw, int ch)
{
    fb_fill(fb, r->x + DLG_BORDER, r->y, cw, DLG_CAPTION, MJ_CAPTION_BG);
    dlg_edge(fb, r->x + DLG_BORDER - 1, r->y, cw + 2, DLG_CAPTION + ch + 1);
}

/* 見出しの × —— 原典の絵から一画素ずつ写したもの（`docs/ref_shakudo.png`
   の窓座標 (W-28, 10) から 10x10）。斜め二本の芯が 171818、両端だけ
   212121 で、その左右に b5b6b6 の縁取りが付きます。どのダイアログでも
   同じ形・同じ位置でした（右端から 28 画素）。レイヤ設定 と
   軸角・目盛・オフセット にだけ × がありません（`tools/probe116.sh`・
   `probe117.sh` の WM_NCHITTEST に HTCLOSE が出ない）。 */
#define DLG_X_SIZE 10
#define DLG_X_CORE 0x171818u
#define DLG_X_TIP  0x212121u
#define DLG_X_HALO 0xb5b6b6u

static void dlg_cross(fb_t *fb, const rect_t *r, int w)
{
    int x0 = r->x + w - 28, y0 = r->y + 10, i, j, k;

    for (i = 0; i < DLG_X_SIZE; i++) {
        int on[2];

        on[0] = i;
        on[1] = DLG_X_SIZE - 1 - i;
        for (j = 0; j < 2; j++)
            for (k = on[j] - 1; k <= on[j] + 1; k += 2)
                if (k >= 0 && k < DLG_X_SIZE && k != on[1 - j])
                    fb_fill(fb, x0 + k, y0 + i, 1, 1, DLG_X_HALO);
        for (j = 0; j < 2; j++)
            fb_fill(fb, x0 + on[j], y0 + i, 1, 1,
                    (i == 0 || i == DLG_X_SIZE - 1) ? DLG_X_TIP : DLG_X_CORE);
    }
}

/* 押せる所は絵よりずっと広く、WM_NCHITTEST が HTCLOSE と答えるのは
   窓座標の x = W-43..W-9・y = 8..29 です（`tools/probe116.sh`、三つの
   ダイアログで同じ）。**押すと キャンセル と同じ**で、打ち込んだものは
   捨てられます（`tools/probe118.sh`: 縮尺の分母に 2 を打って × で
   閉じると縮尺は変わらず、OK なら変わる）。だから当たり判定は
   キャンセル釦の id である 2 を返します。 */
static int dlg_close_hit(const rect_t *r, int w, int x, int y)
{
    return x >= r->x + w - 43 && x <= r->x + w - 9
           && y >= r->y + 8 && y <= r->y + 29;
}

void ui_moji_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_MOJI_W;
    r->h = JW_MOJI_H;
    r->x = (cw - JW_MOJI_W) / 2;
    r->y = (ch - 42 - JW_MOJI_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

/* A box sunk into the dialog: the edits and the combos both sit in one.
   Read off the original's own: shadow and dark shadow going in, light and
   white coming out, and the white row is outside the control's rectangle
   on the right and the bottom. */
static void mj_sunken(fb_t *fb, int x, int y, int w, int h)
{
    fb_edge(fb, x, y, w - 1, h - 1, C_BTNSHADOW, C_3DLIGHT);
    /* both corners on the shadow side belong to the shadow */
    fb_hline(fb, x, y, w - 1, C_BTNSHADOW);
    fb_vline(fb, x, y, h - 1, C_BTNSHADOW);
    /* the dark ring goes along the top and down the left and no further */
    fb_hline(fb, x + 1, y + 1, w - 3, C_3DDKSHADOW);
    fb_vline(fb, x + 1, y + 1, h - 3, C_3DDKSHADOW);
    fb_fill(fb, x + 2, y + 2, w - 4, h - 4, C_WINDOW);
    fb_vline(fb, x + w - 1, y, h, C_BTNHILIGHT);
    fb_hline(fb, x, y + h - 1, w, C_BTNHILIGHT);
}

/* The button at the right end of a combo box, sixteen wide and fifteen
   tall, with its triangle: light and shadow going out, white inside, and
   the face in the middle. */
static void mj_combo_button(fb_t *fb, int x, int y, int w, int h)
{
    int bx = x + w - 19, by = y + 2, i;

    fb_edge(fb, bx, by, 16, 15, C_3DLIGHT, C_BTNSHADOW);
    fb_hline(fb, bx, by, 16, C_3DLIGHT);        /* and here on the light one */
    fb_vline(fb, bx, by, 15, C_3DLIGHT);
    fb_hline(fb, bx + 1, by + 1, 14, C_BTNHILIGHT);
    fb_vline(fb, bx + 1, by + 1, 13, C_BTNHILIGHT);
    fb_fill(fb, bx + 2, by + 2, 13, 12, C_BTNFACE);
    for (i = 0; i < 4; i++)
        fb_hline(fb, bx + 4 + i, by + 6 + i, 7 - i * 2, C_BTNTEXT);
    /* a combo's dark ring carries on down the right and along under the
       button, which an edit's does not */
    fb_vline(fb, x + w - 3, y + 1, h - 3, C_3DDKSHADOW);
    fb_hline(fb, x + w - 19, y + h - 3, 17, C_3DDKSHADOW);
}

static void mj_radio(fb_t *fb, int x, int y, int on)
{
    const unsigned int *sp = on ? jw_moji_radio_on : jw_moji_radio_off;
    int i, j;

    for (j = 0; j < JW_MJ_RADIO_H; j++)
        for (i = 0; i < JW_MJ_RADIO_W; i++) {
            unsigned int c = sp[j * JW_MJ_RADIO_W + i];

            if (c != 0xffffffffu)
                fb_fill(fb, x + i, y + j, 1, 1, c);
        }
}

/* The same, greyed: a radio that cannot be pressed has the dialog's face
   where the white inside the ring would be.  Only the white that is walled
   in on both sides is changed, so the shadow down its right stays white. */
static void mj_radio_off(fb_t *fb, int x, int y, int on)
{
    const unsigned int *sp = jw_moji_radio_off;
    int i, j;

    mj_radio(fb, x, y, 0);
    for (j = 0; j < JW_MJ_RADIO_H; j++) {
        int a = -1, b = -1;

        for (i = 0; i < JW_MJ_RADIO_W; i++) {
            unsigned int c = sp[j * JW_MJ_RADIO_W + i];

            if (c != 0xffffffffu && c != C_WINDOW) {
                if (a < 0)
                    a = i;
                b = i;
            }
        }
        for (i = a + 1; i >= 0 && i < b; i++)
            if (sp[j * JW_MJ_RADIO_W + i] == C_WINDOW)
                fb_fill(fb, x + i, y + j, 1, 1, C_BTNFACE);
    }
    /* the dot, which is whatever the two sprites differ by, in the shadow
       colour rather than black */
    if (on)
        for (j = 0; j < JW_MJ_RADIO_H; j++)
            for (i = 0; i < JW_MJ_RADIO_W; i++) {
                int k = j * JW_MJ_RADIO_W + i;

                if (jw_moji_radio_on[k] != jw_moji_radio_off[k])
                    fb_fill(fb, x + i, y + j, 1, 1, C_BTNSHADOW);
            }
}

/* One row of the table: width, height, spacing, colour and how many texts
   are written in that 文字種.  The columns are the original's own. */
static void mj_row(char *t, size_t cap, double w, double h, double sp,
                   int col, int used)
{
    char n[16], c[16];

    if (used > 0)
        sprintf(n, "%d", used);
    else
        sprintf(n, "--");
    sprintf(c, "(%d)", col);
    /* the three numbers come from the drawing: a damaged one can hold
       1e300, which "%.2f" spells in three hundred characters */
    snprintf(t, cap, "%7.2f%8.2f%8.3f%7s%11s", w, h, sp, c, n);
}

/* How many texts of the drawing are written in each 文字種, 0 being 任意. */
static void mj_counts(const jw_drawing *d, int *used)
{
    int i;

    for (i = 0; i <= 10; i++)
        used[i] = 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI) {
            int n = d->obj[i].n;

            if (n >= 0 && n <= 10)
                used[n]++;
        }
}

void ui_moji(fb_t *fb, const jw_drawing *d, int style)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height(), used[11];
    double sw = d->cur_style.w, sh = d->cur_style.h, ss = d->cur_style.sp;


    if (style >= 1 && style <= 10) {
        sw = d->style[style - 1].w;
        sh = d->style[style - 1].h;
        ss = d->style[style - 1].sp;

    }
    mj_counts(d, used);
    ui_moji_rect(fb->w, fb->h, &r);
    /* the window: its one pixel of frame, the caption across the top and
       the client below it */
    dlg_chrome(fb, &r, JW_MOJI_CW, JW_MOJI_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_MOJI_CAPTION - th) / 2,
               /* 書込み文字種変更 */
               "\x8f\x91\x8d\x9e\x82\xdd\x95\xb6\x8e\x9a\x8e\xed\x95\xcf\x8d"
               "X", C_BTNTEXT);
    dlg_cross(fb, &r, JW_MOJI_W);
    cx = r.x + JW_MOJI_BORDER;
    cy = r.y + JW_MOJI_CAPTION;
    fb_fill(fb, cx, cy, JW_MOJI_CW, JW_MOJI_CH, C_BTNFACE);

    for (i = 0; i < JW_NMOJI; i++) {
        const jw_mj_t *z = &jw_moji[i];
        int x = cx + z->x, y = cy + z->y;
        char t[80];

        switch (z->kind) {
        case JW_MJ_OK:
        case JW_MJ_CANCEL: {
            int k2 = z->kind == JW_MJ_OK;

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            jw_text_px(fb, x + (z->w - jw_text_count(z->text) * 6) / 2,
                       y + (z->h - th) / 2, z->text, C_BTNTEXT);
            break;
        }
        case JW_MJ_RADIO:
            mj_radio(fb, x, y, z->n == style);
            jw_text_px(fb, x + 17, y + (z->h - th) / 2, z->text, C_BTNTEXT);
            break;
        case JW_MJ_CHECK:
            /* the same box the 線属性 dialog has, one row taller than the
               command bars' because of the white edge under it.  斜体 and
               太字 show what the command has, not what the original had
               when its dialog was read. */
            paint_checkbox(fb, x, y + (z->h - CHECK_W) / 2,
                           z->id == 2420 ? jw_cmd_moji_italic()
                           : z->id == 2413 ? jw_cmd_moji_bold() : z->n);
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, y + (z->h - CHECK_W) / 2 + CHECK_H, CHECK_W,
                         C_BTNHILIGHT);
            jw_text_px(fb, x + CHECK_W + 3, y + (z->h - th) / 2, z->text,
                       C_BTNTEXT);
            break;
        case JW_MJ_PUSH:
            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            fb_edge(fb, x, y, z->w, z->h, C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + 1, y + 1, z->w - 2, z->h - 2,
                    C_3DLIGHT, C_BTNSHADOW);
            jw_text_px(fb, x + (z->w - jw_text_count(z->text) * 6) / 2,
                       y + (z->h - th) / 2, z->text, C_BTNTEXT);
            break;
        case JW_MJ_EDIT:
            mj_sunken(fb, x, y, z->w, z->h);
            if (z->id == 1491 || z->id == 1492 || z->id == 1493) {
                /* what the box holds, which is what has been typed into it
                   rather than what the drawing says */
                const char *box = app_moji_box(z->id);
                int tx;

                if (box && *box)
                    strcpy(t, box);
                else if (z->id == 1493)
                    snprintf(t, sizeof t, "%.3f", ss);
                else
                    snprintf(t, sizeof t, "%.2f", z->id == 1491 ? sw : sh);
                tx = x + z->w - 4 - jw_text_count(t) * 6;
                jw_text_px(fb, tx, y + (z->h - th) / 2, t, C_BTNTEXT);
                if (app_moji_focus() == z->id)   /* the caret */
                    fb_vline(fb, x + z->w - 3, y + 3, z->h - 8, C_BTNTEXT);
            }
            break;
        case JW_MJ_COMBO:
            mj_sunken(fb, x, y, z->w, z->h);
            mj_combo_button(fb, x, y, z->w, z->h);
            if (z->id == 2358) {
                sprintf(t, "%d", app_moji_color());
                jw_text_px(fb, x + 4, y + (z->h - th) / 2, t, C_BTNTEXT);
            }
            break;
        case JW_MJ_STATIC:
            if (z->n >= 1 && z->n <= 10) {
                mj_row(t, sizeof t, d->style[z->n - 1].w,
                       d->style[z->n - 1].h,
                       d->style[z->n - 1].sp, d->style[z->n - 1].color,
                       used[z->n]);
                jw_text_px(fb, x, y + (z->h - th) / 2, t, C_BTNTEXT);
            } else if (z->id == 1932) {
                sprintf(t, "%d", used[0]);
                jw_text_px(fb, x + z->w - jw_text_count(t) * 6,
                           y + (z->h - th) / 2, t, C_BTNTEXT);
            } else {
                jw_text_px(fb, x, y + (z->h - th) / 2, z->text, C_BTNTEXT);
            }
            break;
        }
    }
}

/* The 色No. list the port drops down when the box is pressed.  It holds ten
 * rows, 0 to 9 -- driving the original shows the row **is** the colour --
 * and it hangs under the box.  The original's own dropdown has not been
 * photographed, so this is the port's own drawing of one. */
static void moji_drop_rect(int cw, int ch, rect_t *r)
{
    rect_t d;
    int i;

    ui_moji_rect(cw, ch, &d);
    r->x = r->y = r->w = r->h = 0;
    for (i = 0; i < JW_NMOJI; i++)
        if (jw_moji[i].id == 2358) {
            r->x = d.x + JW_MOJI_BORDER + jw_moji[i].x;
            r->y = d.y + JW_MOJI_CAPTION + jw_moji[i].y + jw_moji[i].h;
            r->w = jw_moji[i].w;
            r->h = 10 * jw_text_height() + 2;
            return;
        }
}

void ui_moji_drop(fb_t *fb)
{
    rect_t r;
    int i, th = jw_text_height();
    char t[8];

    moji_drop_rect(fb->w, fb->h, &r);
    if (r.w <= 0)
        return;
    fb_fill(fb, r.x, r.y, r.w, r.h, C_BTNHILIGHT);
    fb_edge(fb, r.x, r.y, r.w, r.h, C_3DDKSHADOW, C_3DDKSHADOW);
    for (i = 0; i < 10; i++) {
        int yy = r.y + 1 + i * th;

        if (i == app_moji_color())
            fb_fill(fb, r.x + 1, yy, r.w - 2, th, C_BTNSHADOW);
        sprintf(t, "%d", i);
        jw_text_px(fb, r.x + 4, yy, t,
                   i == app_moji_color() ? C_BTNHILIGHT : C_BTNTEXT);
    }
}

int ui_moji_drop_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int th = jw_text_height(), row;

    moji_drop_rect(cw, ch, &r);
    if (r.w <= 0 || x < r.x || x >= r.x + r.w || y < r.y + 1
        || y >= r.y + r.h - 1)
        return -1;
    row = (y - r.y - 1) / th;
    return row >= 0 && row < 10 ? row : -1;
}

int ui_moji_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_moji_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside the dialog altogether */
    if (dlg_close_hit(&r, JW_MOJI_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_MOJI_BORDER;
    y -= r.y + JW_MOJI_CAPTION;
    for (i = 0; i < JW_NMOJI; i++) {
        const jw_mj_t *z = &jw_moji[i];

        if (z->kind == JW_MJ_STATIC)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* ---------------------------------------------------- 属性選択 (1069) --
 * The same dialog as 属性変更 with the 《...に変更》 half hidden, which is
 * why its controls are so far apart: the ones between them are not on the
 * screen.  Everything it draws is a box, a line or a piece of text, so
 * nothing had to be lifted out of the original's picture -- see
 * tools/mkzokusel.py.  Its caption carries no title, only the cross.
 */
/* A label cut to fit its control.  The original clips whatever does not fit
   half way through a glyph; the port's font is a little wider, so rather
   than spill onto the dialog's face it drops the characters that do not
   fit -- the text itself is not scored against the original's anyway. */
static void zs_text(fb_t *fb, int x, int y, int w, const char *s,
                    unsigned int col)
{
    char t[128];
    int n = 0;

    while (s[n] && n + 3 < (int)sizeof t) {
        int k = jw_is_lead((unsigned char)s[n]) && s[n + 1] ? 2 : 1;

        memcpy(t, s, (size_t)(n + k));
        t[n + k] = 0;
        if (jw_text_px_w(t) > w)
            break;
        n += k;
    }
    memcpy(t, s, (size_t)n);
    t[n] = 0;
    jw_text_px(fb, x, y, t, col);
}

void ui_zokusel_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_ZS_W;
    r->h = JW_ZS_H;
    r->x = (cw - JW_ZS_W) / 2;
    r->y = (ch - 42 - JW_ZS_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

int ui_zokusel_n(void)
{
    return JW_NZOKUSEL;
}

int ui_zokusel_id(int i)
{
    return i >= 0 && i < JW_NZOKUSEL ? jw_zokusel[i].id : 0;
}

void ui_zokusel(fb_t *fb, const unsigned char *on)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_zokusel_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_ZS_CW, JW_ZS_CH);
    dlg_cross(fb, &r, JW_ZS_W);
    cx = r.x + JW_ZS_BORDER;
    cy = r.y + JW_ZS_CAPTION;
    fb_fill(fb, cx, cy, JW_ZS_CW, JW_ZS_CH, C_BTNFACE);

    for (i = 0; i < JW_NZOKUSEL; i++) {
        const jw_zs_t *z = &jw_zokusel[i];
        int x = cx + z->x, y = cy + z->y;

        switch (z->kind) {
        case JW_ZS_OK:
        case JW_ZS_PUSH: {
            int k2 = z->kind == JW_ZS_OK && z->id == 2;

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            {
                int tw = jw_text_px_w(z->text), tx = x + (z->w - tw) / 2;

                if (tx < x + 3)
                    tx = x + 3;
                zs_text(fb, tx, y + (z->h - th) / 2, x + z->w - 3 - tx,
                        z->text, C_BTNTEXT);
            }
            break;
        }
        case JW_ZS_CHECK:
            paint_checkbox(fb, x, y + (z->h - CHECK_W) / 2, on ? on[i] : 0);
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, y + (z->h - CHECK_W) / 2 + CHECK_H, CHECK_W,
                         C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, C_BTNTEXT);
            break;
        case JW_ZS_STATIC:
            jw_text_px(fb, x, y + (z->h - th) / 2, z->text, C_BTNTEXT);
            break;
        default:
            break;
        }
    }
}

int ui_zokusel_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_zokusel_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_ZS_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_ZS_BORDER;
    y -= r.y + JW_ZS_CAPTION;
    for (i = 0; i < JW_NZOKUSEL; i++) {
        const jw_zs_t *z = &jw_zokusel[i];

        if (z->kind == JW_ZS_STATIC)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* ---------------------------------------------------- 属性変更 (1070) --
 * The same window as 属性選択 with the other half of its controls showing.
 */
void ui_zokuhen_rect(int cw, int ch, rect_t *r)
{
    ui_zokusel_rect(cw, ch, r);         /* the same window */
}

int ui_zokuhen_n(void)
{
    return JW_NZOKUHEN;
}

int ui_zokuhen_id(int i)
{
    return i >= 0 && i < JW_NZOKUHEN ? jw_zokuhen[i].id : 0;
}

int ui_zokuhen_on(int i)
{
    return i >= 0 && i < JW_NZOKUHEN ? jw_zokuhen[i].on : 0;
}

void ui_zokuhen(fb_t *fb, const unsigned char *on)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_zokuhen_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_ZH_CW, JW_ZH_CH);
    dlg_cross(fb, &r, JW_ZH_W);
    cx = r.x + JW_ZH_BORDER;
    cy = r.y + JW_ZH_CAPTION;
    fb_fill(fb, cx, cy, JW_ZH_CW, JW_ZH_CH, C_BTNFACE);

    for (i = 0; i < JW_NZOKUHEN; i++) {
        const jw_zh_t *z = &jw_zokuhen[i];
        int x = cx + z->x, y = cy + z->y;
        unsigned int col = z->enabled ? C_BTNTEXT : C_BTNSHADOW;

        switch (z->kind) {
        case JW_ZH_OK:
        case JW_ZH_PUSH: {
            int k2 = z->kind == JW_ZH_OK && z->id == 2;

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            {
                int tw = jw_text_px_w(z->text), tx = x + (z->w - tw) / 2;

                if (tx < x + 3)
                    tx = x + 3;
                zs_text(fb, tx, y + (z->h - th) / 2, x + z->w - 3 - tx,
                        z->text, col);
            }
            break;
        }
        case JW_ZH_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;
            int lit = on ? on[i] : z->on;

            paint_checkbox(fb, x, by, lit);
            if (!z->enabled) {
                fb_fill(fb, x + 2, by + 2, CHECK_W - 4, CHECK_H - 3,
                        C_BTNFACE);
                if (lit)
                    paint_tick_col(fb, x, by, C_BTNSHADOW);
            }
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, col);
            break;
        }
        case JW_ZH_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, col);
            break;
        default:
            break;
        }
    }
}

int ui_zokuhen_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_zokuhen_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_ZH_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_ZH_BORDER;
    y -= r.y + JW_ZH_CAPTION;
    for (i = 0; i < JW_NZOKUHEN; i++) {
        const jw_zh_t *z = &jw_zokuhen[i];

        if (z->kind == JW_ZH_STATIC || !z->enabled)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* ---------------------------------------------------- ブロック化 -------
 * A small dialog: a line of text, the box the name goes in, a checkbox and
 * the two buttons.  This one's caption carries a title.
 */
void ui_blkname_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_BN_W;
    r->h = JW_BN_H;
    r->x = (cw - JW_BN_W) / 2;
    r->y = (ch - 42 - JW_BN_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

void ui_blkname(fb_t *fb, const char *name, int on, int caret, int attr)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_blkname_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_BN_CW, JW_BN_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_BN_CAPTION - th) / 2, JW_BN_TITLE,
               C_BTNTEXT);
    dlg_cross(fb, &r, JW_BN_W);
    cx = r.x + JW_BN_BORDER;
    cy = r.y + JW_BN_CAPTION;
    fb_fill(fb, cx, cy, JW_BN_CW, JW_BN_CH, C_BTNFACE);

    for (i = 0; i < JW_NBLKNAME; i++) {
        const jw_bn_t *z = &jw_blkname[i];
        int x = cx + z->x, y = cy + z->y;

        switch (z->kind) {
        case JW_BN_OK:
        case JW_BN_PUSH: {
            int k2 = z->id == 1;        /* OK is the default one */

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            zs_text(fb, x + (z->w - jw_text_px_w(z->text)) / 2,
                    y + (z->h - th) / 2, z->w - 6, z->text, C_BTNTEXT);
            break;
        }
        case JW_BN_CHECK:
            paint_checkbox(fb, x, y + (z->h - CHECK_W) / 2, on);
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, y + (z->h - CHECK_W) / 2 + CHECK_H, CHECK_W,
                         C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, C_BTNTEXT);
            break;
        case JW_BN_EDIT: {
            int tw;

            mj_sunken(fb, x, y, z->w, z->h);
            if (attr) {         /* greyed out: ブロック属性 cannot rename */
                fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
                break;
            }
            tw = jw_text_px_w(name ? name : "");
            zs_text(fb, x + 3, y + (z->h - th) / 2, z->w - 6,
                    name ? name : "", C_BTNTEXT);
            if (caret)
                fb_fill(fb, x + 3 + tw, y + (z->h - th) / 2, 1, th,
                        C_BTNTEXT);
            break;
        }
        case JW_BN_STATIC:
            /* ブロック属性 says just ブロック名 */
            zs_text(fb, x, y + (z->h - th) / 2, z->w,
                    attr ? "\x83u\x83\x8d\x83" "b\x83N\x96\xbc" : z->text,
                    C_BTNTEXT);
            break;
        default:
            break;
        }
    }
}

int ui_blkname_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_blkname_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_BN_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_BN_BORDER;
    y -= r.y + JW_BN_CAPTION;
    for (i = 0; i < JW_NBLKNAME; i++) {
        const jw_bn_t *z = &jw_blkname[i];

        if (z->kind == JW_BN_STATIC)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* ---------------------------------------------------- ブロック編集 -----
 * The block's name, a button to change it, the two 編集結果を choices and
 * the usual pair.  The name box holds the block's own name and is not typed
 * into here -- ブロック名変更 is what changes it, and that is not done.
 */
void ui_blkedit_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_BE_W;
    r->h = JW_BE_H;
    r->x = (cw - JW_BE_W) / 2;
    r->y = (ch - 42 - JW_BE_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

void ui_blkedit(fb_t *fb, const char *name, int all)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_blkedit_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_BE_CW, JW_BE_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_BE_CAPTION - th) / 2, JW_BE_TITLE,
               C_BTNTEXT);
    dlg_cross(fb, &r, JW_BE_W);
    cx = r.x + JW_BE_BORDER;
    cy = r.y + JW_BE_CAPTION;
    fb_fill(fb, cx, cy, JW_BE_CW, JW_BE_CH, C_BTNFACE);

    for (i = 0; i < JW_NBLKEDIT; i++) {
        const jw_be_t *z = &jw_blkedit[i];
        int x = cx + z->x, y = cy + z->y;

        switch (z->kind) {
        case JW_BE_OK:
        case JW_BE_PUSH: {
            int k2 = z->id == 1;        /* OK is the default one */

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            zs_text(fb, x + (z->w - jw_text_px_w(z->text)) / 2,
                    y + (z->h - th) / 2, z->w - 6, z->text, C_BTNTEXT);
            break;
        }
        case JW_BE_CHECK:
            paint_checkbox(fb, x, y + (z->h - CHECK_W) / 2,
                           z->id == 2410 ? all
                           : z->id == 2411 ? !all : z->on);
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, y + (z->h - CHECK_W) / 2 + CHECK_H, CHECK_W,
                         C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, C_BTNTEXT);
            break;
        case JW_BE_EDIT:
            mj_sunken(fb, x, y, z->w, z->h);
            zs_text(fb, x + 3, y + (z->h - th) / 2, z->w - 6,
                    name ? name : "", C_BTNTEXT);
            break;
        case JW_BE_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, C_BTNTEXT);
            break;
        default:
            break;
        }
    }
}

int ui_blkedit_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_blkedit_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_BE_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_BE_BORDER;
    y -= r.y + JW_BE_CAPTION;
    for (i = 0; i < JW_NBLKEDIT; i++) {
        const jw_be_t *z = &jw_blkedit[i];

        if (z->kind == JW_BE_STATIC)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* ------------------------------------------------------- 基本設定 -----
 * The big one: eight tabs of which only 一般(1) can be read out of the
 * original, because it does not build the others until they are shown.  The
 * strip of tabs across the top is a themed Windows control and the port
 * draws a plain one, so it is scored with the caption rather than against
 * the original (see tools/mkkihon.py).
 */
void ui_kihon_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_KH_W;
    r->h = JW_KH_H;
    r->x = (cw - JW_KH_W) / 2;
    r->y = (ch - 42 - JW_KH_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

int ui_kihon_ntabs(void)
{
    return JW_NKIHON_TABS;
}

int ui_kihon_n(int tab)
{
    return tab >= 0 && tab < JW_NKIHON_TABS ? jw_kihon_tabs[tab].n : 0;
}

int ui_kihon_id(int tab, int i)
{
    if (tab < 0 || tab >= JW_NKIHON_TABS || i < 0
        || i >= jw_kihon_tabs[tab].n)
        return 0;
    return jw_kihon_tabs[tab].c[i].id;
}

int ui_kihon_on(int tab, int i)
{
    if (tab < 0 || tab >= JW_NKIHON_TABS || i < 0
        || i >= jw_kihon_tabs[tab].n)
        return 0;
    return jw_kihon_tabs[tab].c[i].on;
}

void ui_kihon(fb_t *fb, int tab, const unsigned char *on)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height(), n;
    const jw_kh_t *c;

    if (tab < 0 || tab >= JW_NKIHON_TABS)
        tab = 0;
    c = jw_kihon_tabs[tab].c;
    n = jw_kihon_tabs[tab].n;
    ui_kihon_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_KH_CW, JW_KH_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_KH_CAPTION - th) / 2, JW_KH_TITLE,
               C_BTNTEXT);
    dlg_cross(fb, &r, JW_KH_W);
    cx = r.x + JW_KH_BORDER;
    cy = r.y + JW_KH_CAPTION;
    fb_fill(fb, cx, cy, JW_KH_CW, JW_KH_CH, C_BTNFACE);

    /* The tab control: its whole rectangle is raised the way a button is
       -- white and dark shadow outside, light and shadow inside -- and the
       tabs are drawn over the top of it. */
    fb_edge(fb, cx + JW_KH_TAB_X, cy + JW_KH_TAB_Y, JW_KH_TAB_W,
            JW_KH_TAB_H, C_BTNHILIGHT, C_3DDKSHADOW);
    fb_edge(fb, cx + JW_KH_TAB_X + 1, cy + JW_KH_TAB_Y + 1,
            JW_KH_TAB_W - 2, JW_KH_TAB_H - 2, C_3DLIGHT, C_BTNSHADOW);
    for (i = 0; i < JW_NKIHON_TABS; i++) {
        int x = cx + JW_KH_TAB_X + jw_kihon_tab_at[i];
        int w = jw_kihon_tab_at[i + 1] - jw_kihon_tab_at[i];
        int y = cy + JW_KH_TAB_Y + (i == tab ? 0 : 2);
        int h = JW_KH_TAB_ROW - (i == tab ? 0 : 2) + 1;

        fb_fill(fb, x, y, w, h, C_BTNFACE);
        fb_edge(fb, x, y, w, h, C_BTNHILIGHT, C_BTNSHADOW);
        zs_text(fb, x + (w - jw_text_px_w(jw_kihon_tabs[i].name)) / 2,
                y + (h - th) / 2, w - 6, jw_kihon_tabs[i].name, C_BTNTEXT);
    }

    for (i = 0; i < n; i++) {
        const jw_kh_t *z = &c[i];
        int x = cx + z->x, y = cy + z->y;
        unsigned int col = z->enabled ? C_BTNTEXT : C_BTNSHADOW;

        if (!z->shown)
            continue;
        switch (z->kind) {
        case JW_KH_PUSH: {
            int k2 = z->deflt;          /* BS_DEFPUSHBUTTON */

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            zs_text(fb, x + (z->w - jw_text_px_w(z->text)) / 2,
                    y + (z->h - th) / 2, z->w - 6, z->text, col);
            break;
        }
        case JW_KH_RADIO: {
            /* a round one, the same sprite the 文字種 dialog uses */
            int by = y + (z->h - JW_MJ_RADIO_H) / 2;
            int bx = z->lefttext ? x + z->w - JW_MJ_RADIO_W : x;

            if (z->enabled)
                mj_radio(fb, bx, by, on ? on[i] : z->on);
            else
                mj_radio_off(fb, bx, by, on ? on[i] : z->on);
            if (z->lefttext)
                zs_text(fb, x, y + (z->h - th) / 2, z->w - 17, z->text, col);
            else
                zs_text(fb, x + 17, y + (z->h - th) / 2, z->w - 17, z->text,
                        col);
            break;
        }
        case JW_KH_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;
            int lit = on ? on[i] : z->on;
            /* BS_LEFTTEXT puts the box at the right and the words left */
            int bx = z->lefttext ? x + z->w - CHECK_W : x;

            paint_checkbox(fb, bx, by, lit);
            /* A box that cannot be pressed has the dialog's face inside it
               rather than white, and its tick comes out in the shadow
               colour rather than black. */
            if (!z->enabled) {
                fb_fill(fb, bx + 2, by + 2, CHECK_W - 4, CHECK_H - 3,
                        C_BTNFACE);
                if (lit)
                    paint_tick_col(fb, bx, by, C_BTNSHADOW);
            }
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, bx, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            if (z->lefttext)
                zs_text(fb, x, y + (z->h - th) / 2, z->w - CHECK_W - 3,
                        z->text, col);
            else
                zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                        z->w - CHECK_W - 3, z->text, col);
            break;
        }
        case JW_KH_EDIT:
            mj_sunken(fb, x, y, z->w, z->h);
            break;
        case JW_KH_COMBO:
            mj_sunken(fb, x, y, z->w, z->h);
            mj_combo_button(fb, x, y, z->w, z->h);
            break;
        case JW_KH_GROUP: {
            /* an etched frame -- shadow and then white going in -- that
               starts half a line down, with the label over its top */
            int gy = y + th / 2, gh = z->h - th / 2;

            fb_edge(fb, x, gy, z->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, z->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            fb_fill(fb, x + 8, y, jw_text_px_w(z->text) + 4, th, C_BTNFACE);
            zs_text(fb, x + 10, y, z->w - 10, z->text, col);
            break;
        }
        case JW_KH_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, col);
            break;
        default:
            break;
        }
    }
}

int ui_kihon_hit(int cw, int ch, int tab, int x, int y)
{
    rect_t r;
    int i, n;
    const jw_kh_t *c;

    if (tab < 0 || tab >= JW_NKIHON_TABS)
        tab = 0;
    c = jw_kihon_tabs[tab].c;
    n = jw_kihon_tabs[tab].n;
    ui_kihon_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1000;                   /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_KH_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_KH_BORDER;
    y -= r.y + JW_KH_CAPTION;
    if (y >= JW_KH_TAB_Y && y < JW_KH_TAB_Y + JW_KH_TAB_ROW + 1)
        for (i = 0; i < JW_NKIHON_TABS; i++)
            if (x >= JW_KH_TAB_X + jw_kihon_tab_at[i]
                && x < JW_KH_TAB_X + jw_kihon_tab_at[i + 1])
                return -(i + 1);
    for (i = 0; i < n; i++) {
        const jw_kh_t *z = &c[i];

        if (z->kind == JW_KH_STATIC || z->kind == JW_KH_GROUP
            || !z->shown || !z->enabled)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* ---------------------------------------------- 軸角・目盛・オフセット --
 * Three group boxes with a combo in the first two.  The angle is typed into
 * the 軸角 one and Ok applies it -- see jw_cmd_set_axis.
 */
void ui_jikkaku_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_JK_W;
    r->h = JW_JK_H;
    r->x = (cw - JW_JK_W) / 2;
    r->y = (ch - 42 - JW_JK_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

int ui_jikkaku_n(void)
{
    return JW_NJIKKAKU;
}

int ui_jikkaku_id(int i)
{
    return i >= 0 && i < JW_NJIKKAKU ? jw_jikkaku[i].id : 0;
}

int ui_jikkaku_on(int i)
{
    return i >= 0 && i < JW_NJIKKAKU ? jw_jikkaku[i].on : 0;
}

void ui_jikkaku(fb_t *fb, const char *angle, const unsigned char *on,
                int caret)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_jikkaku_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_JK_CW, JW_JK_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_JK_CAPTION - th) / 2, JW_JK_TITLE,
               C_BTNTEXT);
    cx = r.x + JW_JK_BORDER;
    cy = r.y + JW_JK_CAPTION;
    fb_fill(fb, cx, cy, JW_JK_CW, JW_JK_CH, C_BTNFACE);

    for (i = 0; i < JW_NJIKKAKU; i++) {
        const jw_jk_t *z = &jw_jikkaku[i];
        int x = cx + z->x, y = cy + z->y;

        switch (z->kind) {
        case JW_JK_OK:
        case JW_JK_PUSH:
            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (z->kind == JW_JK_OK)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + (z->kind == JW_JK_OK),
                    y + (z->kind == JW_JK_OK),
                    z->w - 2 * (z->kind == JW_JK_OK),
                    z->h - 2 * (z->kind == JW_JK_OK),
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + (z->kind == JW_JK_OK) + 1,
                    y + (z->kind == JW_JK_OK) + 1,
                    z->w - 2 * (z->kind == JW_JK_OK) - 2,
                    z->h - 2 * (z->kind == JW_JK_OK) - 2,
                    C_3DLIGHT, C_BTNSHADOW);
            zs_text(fb, x + (z->w - jw_text_px_w(z->text)) / 2,
                    y + (z->h - th) / 2, z->w - 6, z->text, C_BTNTEXT);
            break;
        case JW_JK_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;

            paint_checkbox(fb, x, by, on ? on[i] : z->on);
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, C_BTNTEXT);
            break;
        }
        case JW_JK_COMBO: {
            const char *t = z->id == 1411 ? angle : "";
            int tw = jw_text_px_w(t ? t : "");

            mj_sunken(fb, x, y, z->w, z->h);
            mj_combo_button(fb, x, y, z->w, z->h);
            zs_text(fb, x + 3, y + (z->h - th) / 2, z->w - 22, t ? t : "",
                    C_BTNTEXT);
            if (caret && z->id == 1411)
                fb_fill(fb, x + 3 + tw, y + (z->h - th) / 2, 1, th,
                        C_BTNTEXT);
            break;
        }
        case JW_JK_GROUP: {
            int gy = y + th / 2, gh = z->h - th / 2;

            fb_edge(fb, x, gy, z->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, z->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            fb_fill(fb, x + 8, y, jw_text_px_w(z->text) + 4, th, C_BTNFACE);
            zs_text(fb, x + 10, y, z->w - 10, z->text, C_BTNTEXT);
            break;
        }
        case JW_JK_EDIT:
            mj_sunken(fb, x, y, z->w, z->h);
            break;
        case JW_JK_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, C_BTNTEXT);
            break;
        default:
            break;
        }
    }
}

int ui_jikkaku_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_jikkaku_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    x -= r.x + JW_JK_BORDER;
    y -= r.y + JW_JK_CAPTION;
    for (i = 0; i < JW_NJIKKAKU; i++) {
        const jw_jk_t *z = &jw_jikkaku[i];

        if (z->kind == JW_JK_STATIC || z->kind == JW_JK_GROUP)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* -------------------------------------------------------- レイヤ設定 -----
 * The sixteen layers of the group being written to.  Read out of the running
 * original with `dlg:32808` -- the id the menu's レイヤ sends, and the one
 * the status line's third box sends as well (FUN_00596e80).
 *
 * A button per layer with its number on it (1063..1072, 1115..1119, 1142) and
 * a static beside it for its name (1975..1990); above them the group's own
 * number and scale; below, 全レイヤ編集 and its neighbours.  The whole top
 * of it is a tab control in the original, which nothing else here has, so
 * what the port draws is its frame and the one page that is up.
 */
/* Every label in this dialog is an SS_SUNKEN static and the two combos are
 * CBS_SIMPLE, so all of them are ringed with the same thin etched frame:
 * a0a0a0 along the top and down the left, white along the bottom and the
 * right.  Measured off docs/ref_layerdlg.png. */
#define JW_LD_ETCH_TL 0xa0a0a0u
#define JW_LD_ETCH_BR 0xffffffu
/* the combos have a second ring inside that one */
#define JW_LD_SUNK_TL 0x696969u
#define JW_LD_SUNK_BR 0xe3e3e3u

void ui_layerdlg_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_LD_W;
    r->h = JW_LD_H;
    r->x = (cw - JW_LD_W) / 2;
    r->y = (ch - 42 - JW_LD_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

int ui_layerdlg_n(void)
{
    return JW_NLAYERDLG;
}

int ui_layerdlg_id(int i)
{
    return i >= 0 && i < JW_NLAYERDLG ? jw_layerdlg[i].id : 0;
}

int ui_layerdlg_on(int i)
{
    return i >= 0 && i < JW_NLAYERDLG ? jw_layerdlg[i].on : 0;
}

/* which layer a button stands for, or -1 */
int ui_layerdlg_layer(int id)
{
    static const short B[16] = { 1063, 1064, 1065, 1066, 1067, 1068, 1069,
                                 1070, 1071, 1072, 1115, 1116, 1117, 1118,
                                 1119, 1142 };
    int i;

    for (i = 0; i < 16; i++)
        if (B[i] == id)
            return i;
    return -1;
}

void ui_layerdlg(fb_t *fb, const jw_drawing *d, const unsigned char *on)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height(), wg = 0, wl = 0;
    unsigned lay_has = 0;        /* a bit per layer with something on it */
    const jw_group *g;

    ui_layerdlg_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_LD_CW, JW_LD_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_LD_CAPTION - th) / 2, JW_LD_TITLE,
               C_BTNTEXT);
    cx = r.x + JW_LD_BORDER;
    cy = r.y + JW_LD_CAPTION;
    fb_fill(fb, cx, cy, JW_LD_CW, JW_LD_CH, C_BTNFACE);
    if (d)
        for (i = 0; i < 16; i++)
            if (d->group[i].state == 3)
                wg = i;
    g = d ? &d->group[wg] : 0;
    if (g)
        for (i = 0; i < 16; i++)
            if (g->layer[i].state == 3)
                wl = i;
    /* which of the write group's layers have anything drawn on them: the
     * original puts a different picture on an empty layer's button */
    if (d)
        for (i = 0; i < d->ndrawn; i++)
            if (((d->obj[i].layer >> 4) & 15) == wg)
                lay_has |= 1u << (d->obj[i].layer & 15);

    /* the tab control's page, under the two rows of cells: the same
     * two-ring frame the original draws, white then e3e3e3 going in on the
     * top and the left, 696969 then a0a0a0 on the bottom and the right.
     * The tab control is (0, 0, 278, 278) and the cells take 34 of it. */
    fb_edge(fb, cx, cy + 34, 278, 244, 0xffffffu, 0x696969u);
    fb_edge(fb, cx + 1, cy + 35, 276, 242, 0xe3e3e3u, 0xa0a0a0u);

    /* the sixteen layer groups on the tab control, eight to a row: 8..F
     * along the top and 0..7 below, which is the order the original shows
     * them in.  The two cells are lifted from a picture of its own dialog
     * (tools/mklaytab.py); the one being written to is bigger and is drawn
     * last so it sits over its neighbours' edges. */
    for (i = 0; i < 17; i++) {
        int k = i == 16 ? wg : i;
        int row = k < 8 ? 1 : 0;        /* 0..7 are the lower row */
        int col = k & 7;
        int tx = cx + JW_LAYTAB_X + JW_LAYTAB_DX * col;
        int ty = cy + JW_LAYTAB_Y + JW_LAYTAB_DY * row;
        const unsigned int *cell;
        int cw, ch, px_, py_;
        char lab[4];

        if (i < 16 && i == wg)
            continue;                   /* drawn last, at i == 16 */
        if (i == 16) {
            /* a cell in the first column meets the page's own left edge,
             * which runs up to it, so it is not the same cell */
            cell = col ? jw_laytab_sel : jw_laytab_sel0;
            cw = JW_LAYTAB_SEL_W;
            ch = JW_LAYTAB_SEL_H;
            tx -= 2;
            ty -= 2;
        } else {
            cell = jw_laytab_unsel;
            cw = JW_LAYTAB_UNSEL_W;
            ch = JW_LAYTAB_UNSEL_H;
        }
        for (py_ = 0; py_ < ch; py_++)
            for (px_ = 0; px_ < cw; px_++)
                px_put(fb, tx + px_, ty + py_, cell[py_ * cw + px_]);
        sprintf(lab, "%X", k);
        jw_text_px(fb, tx + (cw - jw_text_px_w(lab)) / 2,
                   ty + (ch - th) / 2, lab, C_BTNTEXT);
    }

    for (i = 0; i < JW_NLAYERDLG; i++) {
        const jw_ld_t *z = &jw_layerdlg[i];
        int x = cx + z->x, y = cy + z->y;
        int lay = ui_layerdlg_layer(z->id);

        switch (z->kind) {
        case JW_LD_OK:
        case JW_LD_PUSH: {
            const char *t = z->text;
            unsigned col = z->en ? C_BTNTEXT : C_GRAYTEXT;
            /* the write layer's button is drawn held down */
            int down = lay >= 0 && g && g->layer[lay].state == 3;
            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (z->dflt) {
                /* BS_DEFPUSHBUTTON is flat: two rings and no 3D edges */
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
                fb_edge(fb, x + 1, y + 1, z->w - 2, z->h - 2,
                        0xa0a0a0u, 0xa0a0a0u);
            } else if (down) {
                fb_edge(fb, x, y, z->w, z->h, C_3DDKSHADOW, C_BTNHILIGHT);
                fb_edge(fb, x + 1, y + 1, z->w - 2, z->h - 2,
                        C_BTNSHADOW, C_3DLIGHT);
            } else {
                fb_edge(fb, x, y, z->w, z->h, C_BTNHILIGHT, C_3DDKSHADOW);
                fb_edge(fb, x + 1, y + 1, z->w - 2, z->h - 2,
                        C_3DLIGHT, C_BTNSHADOW);
            }
            if (z->id == 1087 && g) {
                /* the group's own state, as a picture, on a BS_BITMAP
                 * button exactly like the sixteen layers' */
                int px_, py_, has = lay_has != 0;
                for (py_ = 0; py_ < JW_GRPICON_H; py_++)
                    for (px_ = 0; px_ < JW_GRPICON_W; px_++)
                        px_put(fb, x + 2 + px_, y + 2 + py_,
                               jw_grpicon[has][py_ * JW_GRPICON_W + px_]);
                break;
            }
            if (lay >= 0 && g) {
                /* the original paints a little picture of the layer's
                 * state on the button rather than its number (the number is
                 * the static above it), and a different one again when the
                 * layer is empty.  The eight faces are lifted whole from
                 * pictures of its own dialog -- tools/mklayicon.py. */
                int st = g->layer[lay].state;
                int px_, py_, has = (lay_has >> lay) & 1;
                if (st < 0 || st > 3)
                    st = 0;
                for (py_ = 0; py_ < JW_LAYICON_H; py_++)
                    for (px_ = 0; px_ < JW_LAYICON_W; px_++)
                        px_put(fb, x + 2 + px_, y + 2 + py_,
                               jw_layicon[st][has]
                                         [py_ * JW_LAYICON_W + px_]);
                break;
            }
            zs_text(fb, x + (z->w - jw_text_px_w(t)) / 2,
                    y + (z->h - th) / 2, z->w - 4, t, col);
            break;
        }
        case JW_LD_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;
            paint_checkbox(fb, x, by, on ? on[i] : z->on);
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, C_BTNTEXT);
            break;
        }
        case JW_LD_GROUP: {
            int gy = y + th / 2, gh = z->h - th / 2;
            fb_edge(fb, x, gy, z->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, z->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            fb_fill(fb, x + 8, y, jw_text_px_w(z->text) + 4, th, C_BTNFACE);
            zs_text(fb, x + 10, y, z->w - 10, z->text, C_BTNTEXT);
            break;
        }
        case JW_LD_COMBO: {
            /* CBS_SIMPLE (style 0x241): an edit with the list under it, so
             * there is no drop-down button on it -- just the thin etched
             * frame the rest of the dialog uses, and the name inside.
             * 1838 is the group's name, 1839 the write layer's. */
            const char *t = 0;
            if (d) {
                if (z->id == 1838)
                    t = jw_str((jw_drawing *)d, d->group[wg].name);
                else if (z->id == 1839)
                    t = jw_str((jw_drawing *)d,
                               d->group[wg].layer_name[wl]);
            }
            fb_fill(fb, x, y, z->w, z->h, 0xffffffu);
            fb_edge(fb, x, y, z->w, z->h, JW_LD_ETCH_TL, JW_LD_ETCH_BR);
            fb_edge(fb, x + 1, y + 1, z->w - 2, z->h - 2,
                    JW_LD_SUNK_TL, JW_LD_SUNK_BR);
            if (t && *t)
                zs_text(fb, x + 4, y + (z->h - th) / 2, z->w - 6, t,
                        C_BTNTEXT);
            break;
        }
        case JW_LD_EDIT:
            mj_sunken(fb, x, y, z->w, z->h);
            break;
        case JW_LD_STATIC: {
            /* the name each layer is given, out of the drawing */
            /* 1975..1990 are the sixteen layer numbers.  The original
             * leaves them as numbers even when the layers have names --
             * the name only shows in the レイヤ名 box (1839). */
            const char *t = z->text;
            if (z->sunk)
                fb_edge(fb, x, y, z->w, z->h, JW_LD_ETCH_TL, JW_LD_ETCH_BR);
            zs_text(fb, x + (z->w - jw_text_px_w(t)) / 2,
                    y + (z->h - th) / 2, z->w - 2, t, C_BTNTEXT);
            break;
        }
        default:
            break;
        }
    }
}

int ui_layerdlg_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_layerdlg_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;
    x -= r.x + JW_LD_BORDER;
    y -= r.y + JW_LD_CAPTION;
    for (i = 0; i < JW_NLAYERDLG; i++) {
        const jw_ld_t *z = &jw_layerdlg[i];

        if (z->kind == JW_LD_GROUP || z->kind == JW_LD_STATIC)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;
}

/* ---------------------------------------------------- 縮尺・読取 -----
 * The scale each layer group is drawn at.  Read out of the running original
 * with `dlg:32944` -- the id the menu's 縮尺・読取 sends, and the one the
 * status line's second box sends as well (FUN_00596e80).
 *
 * The left half lists the sixteen groups and what each is at; the right half
 * has the scale in two boxes, 1470 over 1471, and the switches that say what
 * else moves with it.  The statics 1959..1974 carry the list, so what is
 * painted in them is the drawing's own scales rather than the text that was
 * captured. */
void ui_shakudo_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_SK_W;
    r->h = JW_SK_H;
    r->x = (cw - JW_SK_W) / 2;
    r->y = (ch - 42 - JW_SK_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

int ui_shakudo_n(void)
{
    return JW_NSHAKUDO;
}

int ui_shakudo_id(int i)
{
    return i >= 0 && i < JW_NSHAKUDO ? jw_shakudo[i].id : 0;
}

int ui_shakudo_on(int i)
{
    return i >= 0 && i < JW_NSHAKUDO ? jw_shakudo[i].on : 0;
}

void ui_shakudo(fb_t *fb, const char *num, const char *den,
                const char *const *scales, int write_group,
                const unsigned char *on, int caret)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_shakudo_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_SK_CW, JW_SK_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_SK_CAPTION - th) / 2, JW_SK_TITLE,
               C_BTNTEXT);
    dlg_cross(fb, &r, JW_SK_W);
    cx = r.x + JW_SK_BORDER;
    cy = r.y + JW_SK_CAPTION;
    fb_fill(fb, cx, cy, JW_SK_CW, JW_SK_CH, C_BTNFACE);

    for (i = 0; i < JW_NSHAKUDO; i++) {
        const jw_sk_t *z = &jw_shakudo[i];
        int x = cx + z->x, y = cy + z->y;

        switch (z->kind) {
        case JW_SK_OK:
        case JW_SK_PUSH:
            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (z->id == 1)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + (z->id == 1), y + (z->id == 1),
                    z->w - 2 * (z->id == 1), z->h - 2 * (z->id == 1),
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + (z->id == 1) + 1, y + (z->id == 1) + 1,
                    z->w - 2 * (z->id == 1) - 2, z->h - 2 * (z->id == 1) - 2,
                    C_3DLIGHT, C_BTNSHADOW);
            zs_text(fb, x + (z->w - jw_text_px_w(z->text)) / 2,
                    y + (z->h - th) / 2, z->w - 6, z->text, C_BTNTEXT);
            break;
        case JW_SK_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;

            paint_checkbox(fb, x, by, on ? on[i] : z->on);
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, C_BTNTEXT);
            break;
        }
        case JW_SK_RADIO: {
            /* not the 文字 dialog's pair: this one's are themed, and are
             * lifted from a picture of its own (tools/mkskradio.py) */
            const unsigned int *sp = (on ? on[i] : z->on)
                                     ? jw_skradio_on : jw_skradio_off;
            int px_, py_;
            for (py_ = 0; py_ < JW_SKRADIO_H; py_++)
                for (px_ = 0; px_ < JW_SKRADIO_W; px_++)
                    px_put(fb, x + px_, y + py_,
                           sp[py_ * JW_SKRADIO_W + px_]);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, C_BTNTEXT);
            break;
        }
        case JW_SK_GROUP: {
            int gy = y + th / 2, gh = z->h - th / 2;

            fb_edge(fb, x, gy, z->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, z->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            fb_fill(fb, x + 8, y, jw_text_px_w(z->text) + 4, th, C_BTNFACE);
            zs_text(fb, x + 10, y, z->w - 10, z->text, C_BTNTEXT);
            break;
        }
        case JW_SK_EDIT: {
            const char *t = z->id == 1470 ? num : den;
            int tw;

            if (!t)
                t = "";
            tw = jw_text_px_w(t);
            mj_sunken(fb, x, y, z->w, z->h);
            zs_text(fb, x + 3, y + (z->h - th) / 2, z->w - 6, t, C_BTNTEXT);
            if (caret == z->id)
                fb_fill(fb, x + 3 + tw, y + (z->h - th) / 2, 1, th,
                        C_BTNTEXT);
            break;
        }
        case JW_SK_STATIC: {
            const char *t = z->text;
            unsigned c = C_BTNTEXT;

            if (z->id >= 1959 && z->id <= 1974) {
                int g = z->id - 1959;
                if (scales && scales[g])
                    t = scales[g];
                if (g == write_group)
                    c = 0x0000ffu;      /* the one being written to */
            }
            zs_text(fb, x, y + (z->h - th) / 2, z->w, t, c);
            break;
        }
        default:
            break;
        }
    }
}

int ui_shakudo_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_shakudo_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_SK_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_SK_BORDER;
    y -= r.y + JW_SK_CAPTION;
    for (i = 0; i < JW_NSHAKUDO; i++) {
        const jw_sk_t *z = &jw_shakudo[i];

        if (z->kind == JW_SK_GROUP)
            continue;
        /* the sixteen scales are statics, and clicking one is how a group
           is chosen -- so they answer, unlike the labels beside them */
        if (z->kind == JW_SK_STATIC && !(z->id >= 1959 && z->id <= 1974))
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* -------------------------------------------------------- 寸法設定 -----
 * The numbers a dimension is drawn with.  The picture only: what each one
 * does has not been followed up.
 */
void ui_sunpodlg_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_SD_W;
    r->h = JW_SD_H;
    r->x = (cw - JW_SD_W) / 2;
    r->y = (ch - 42 - JW_SD_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

int ui_sunpodlg_n(void)
{
    return JW_NSUNPODLG;
}

int ui_sunpodlg_id(int i)
{
    return i >= 0 && i < JW_NSUNPODLG ? jw_sunpodlg[i].id : 0;
}

int ui_sunpodlg_on(int i)
{
    return i >= 0 && i < JW_NSUNPODLG ? jw_sunpodlg[i].on : 0;
}

/* 寸法設定: the boxes that are wired up show their value, and the one
   with the caret shows it.  `caret` is that box's id, or 0.  Which boxes
   answer is the command's business (jw_cmd_sunpo_box). */
void ui_sunpodlg(fb_t *fb, const unsigned char *on, int caret,
                 const char *edit)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_sunpodlg_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_SD_CW, JW_SD_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_SD_CAPTION - th) / 2, JW_SD_TITLE,
               C_BTNTEXT);
    dlg_cross(fb, &r, JW_SD_W);
    cx = r.x + JW_SD_BORDER;
    cy = r.y + JW_SD_CAPTION;
    fb_fill(fb, cx, cy, JW_SD_CW, JW_SD_CH, C_BTNFACE);

    for (i = 0; i < JW_NSUNPODLG; i++) {
        const jw_sd_t *z = &jw_sunpodlg[i];
        int x = cx + z->x, y = cy + z->y;

        switch (z->kind) {
        case JW_SD_OK:
        case JW_SD_PUSH: {
            int k2 = z->deflt;          /* BS_DEFPUSHBUTTON */

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            zs_text(fb, x + (z->w - jw_text_px_w(z->text)) / 2,
                    y + (z->h - th) / 2, z->w - 6, z->text, C_BTNTEXT);
            break;
        }
        case JW_SD_RADIO: {
            int by = y + (z->h - JW_MJ_RADIO_H) / 2;

            if (z->enabled)
                mj_radio(fb, x, by, on ? on[i] : z->on);
            else
                mj_radio_off(fb, x, by, on ? on[i] : z->on);
            zs_text(fb, x + 17, y + (z->h - th) / 2, z->w - 17, z->text,
                    z->enabled ? C_BTNTEXT : C_BTNSHADOW);
            break;
        }
        case JW_SD_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;
            int lit = on ? on[i] : z->on;

            paint_checkbox(fb, x, by, lit);
            if (!z->enabled) {          /* greyed, like 基本設定's */
                fb_fill(fb, x + 2, by + 2, CHECK_W - 4, CHECK_H - 3,
                        C_BTNFACE);
                if (lit)
                    paint_tick_col(fb, x, by, C_BTNSHADOW);
            }
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text,
                    z->enabled ? C_BTNTEXT : C_BTNSHADOW);
            break;
        }
        case JW_SD_COMBO:
            mj_sunken(fb, x, y, z->w, z->h);
            mj_combo_button(fb, x, y, z->w, z->h);
            break;
        case JW_SD_EDIT: {
            char t[32];
            int got = jw_cmd_sunpo_box(z->id, t, (int)sizeof t);
            const char *v = t;

            mj_sunken(fb, x, y, z->w, z->h);
            if (caret == z->id && edit)
                v = edit;               /* what is being typed, as typed */
            if (got)
                jw_text_px(fb, x + 3, y + (z->h - th) / 2, v,
                           z->enabled ? C_BTNTEXT : C_GRAYTEXT);
            if (caret == z->id)
                fb_fill(fb, x + 3 + (got ? jw_text_px_w(v) : 0),
                        y + (z->h - th) / 2, 1, th, C_BTNTEXT);
            break;
        }
        case JW_SD_GROUP: {
            int gy = y + th / 2, gh = z->h - th / 2;

            fb_edge(fb, x, gy, z->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, z->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            fb_fill(fb, x + 8, y, jw_text_px_w(z->text) + 4, th, C_BTNFACE);
            zs_text(fb, x + 10, y, z->w - 10, z->text, C_BTNTEXT);
            break;
        }
        case JW_SD_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, C_BTNTEXT);
            break;
        default:
            break;
        }
    }
}

int ui_sunpodlg_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_sunpodlg_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_SD_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_SD_BORDER;
    y -= r.y + JW_SD_CAPTION;
    for (i = 0; i < JW_NSUNPODLG; i++) {
        const jw_sd_t *z = &jw_sunpodlg[i];

        if (z->kind == JW_SD_STATIC || z->kind == JW_SD_GROUP)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* -------------------------------------------- 画面倍率・文字表示 -------
 * 32811's dialog: the zoom, four mark-jump registers and two toggles for
 * what a text draws with it.  Only 用紙全体表示 is wired up (it fits the
 * sheet, which is what the port does when it opens a drawing) -- everything
 * else here moves the view, and this machine cannot capture the original's
 * screen, so there would be nothing to score it against.
 */
void ui_bairitsu_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_BR_W;
    r->h = JW_BR_H;
    r->x = (cw - JW_BR_W) / 2;
    r->y = (ch - 42 - JW_BR_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

int ui_bairitsu_n(void)
{
    return JW_NBAIRITSU;
}

int ui_bairitsu_id(int i)
{
    return i >= 0 && i < JW_NBAIRITSU ? jw_bairitsu[i].id : 0;
}

int ui_bairitsu_on(int i)
{
    return i >= 0 && i < JW_NBAIRITSU ? jw_bairitsu[i].on : 0;
}

/* 設定 OK is a BS_MULTILINE button two lines tall: its words break at the
   space.  Nothing else in the dialog wraps. */
static void br_label(fb_t *fb, int x, int y, int w, int h, const char *t,
                     unsigned int col)
{
    int th = jw_text_height();
    const char *sp = 0;

    /* never past the button's edge rows: the port's letters are wider than
       the original's, and a centred one would else poke out of them */
#define BR_TX(s) (x + (w - jw_text_px_w(s)) / 2 < x + 3                   ? x + 3 : x + (w - jw_text_px_w(s)) / 2)

    if (h >= 2 * th + 8)
        for (sp = t; *sp && *sp != ' '; sp++)
            ;
    if (sp && *sp == ' ') {
        char head[64];
        int n = (int)(sp - t);

        if (n > (int)sizeof head - 1)
            n = (int)sizeof head - 1;
        memcpy(head, t, (size_t)n);
        head[n] = 0;
        zs_text(fb, BR_TX(head), y + h / 2 - th, w - 6, head, col);
        zs_text(fb, BR_TX(sp + 1), y + h / 2 + 1, w - 6, sp + 1, col);
        return;
    }
    zs_text(fb, BR_TX(t), y + (h - th) / 2, w - 6, t, col);
#undef BR_TX
}

void ui_bairitsu(fb_t *fb, const char *zoom, const unsigned char *on)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_bairitsu_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_BR_CW, JW_BR_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_BR_CAPTION - th) / 2, JW_BR_TITLE,
               C_BTNTEXT);
    dlg_cross(fb, &r, JW_BR_W);
    cx = r.x + JW_BR_BORDER;
    cy = r.y + JW_BR_CAPTION;
    fb_fill(fb, cx, cy, JW_BR_CW, JW_BR_CH, C_BTNFACE);

    for (i = 0; i < JW_NBAIRITSU; i++) {
        const jw_br_t *z = &jw_bairitsu[i];
        int x = cx + z->x, y = cy + z->y;
        unsigned int col = z->enabled ? C_BTNTEXT : C_BTNSHADOW;

        switch (z->kind) {
        case JW_BR_OK:
        case JW_BR_PUSH: {
            int k2 = z->deflt;          /* BS_DEFPUSHBUTTON */

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            br_label(fb, x, y, z->w, z->h, z->text, col);
            break;
        }
        case JW_BR_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;
            int lit = on ? on[i] : z->on;

            paint_checkbox(fb, x, by, lit);
            if (!z->enabled) {
                fb_fill(fb, x + 2, by + 2, CHECK_W - 4, CHECK_H - 3,
                        C_BTNFACE);
                if (lit)
                    paint_tick_col(fb, x, by, C_BTNSHADOW);
            }
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, col);
            break;
        }
        case JW_BR_EDIT:
            mj_sunken(fb, x, y, z->w, z->h);
            if (zoom && *zoom)
                zs_text(fb, x + 3, y + (z->h - th) / 2, z->w - 6, zoom,
                        C_BTNTEXT);
            break;
        case JW_BR_COMBO:
            mj_sunken(fb, x, y, z->w, z->h);
            mj_combo_button(fb, x, y, z->w, z->h);
            break;
        case JW_BR_GROUP: {
            int gy = y + th / 2, gh = z->h - th / 2;

            fb_edge(fb, x, gy, z->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, z->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            fb_fill(fb, x + 8, y, jw_text_px_w(z->text) + 4, th, C_BTNFACE);
            zs_text(fb, x + 10, y, z->w - 10, z->text, C_BTNTEXT);
            break;
        }
        case JW_BR_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, col);
            break;
        default:
            break;
        }
    }
}

int ui_bairitsu_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_bairitsu_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_BR_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_BR_BORDER;
    y -= r.y + JW_BR_CAPTION;
    for (i = 0; i < JW_NBAIRITSU; i++) {
        const jw_br_t *z = &jw_bairitsu[i];

        if (z->kind == JW_BR_STATIC || z->kind == JW_BR_GROUP || !z->enabled)
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}


/* 文字基点設定 -- the dialog the 文字 bar's 基点 (1064) puts up.
 *
 * Its controls are read out of the running original (tools/mkmojikijun.py
 * from decomp/res/mojikijun.txt) and drawn here the same way the 画面倍率
 * dialog above is.  What the nine radios do to a placed text was measured
 * separately -- see moji_kijun in src/cmd.c.
 *
 * The six edit boxes and the three 作図 checkboxes are drawn because the
 * dialog is the original's picture, but nothing has been asked of them, so
 * the port does not act on them.
 */
void ui_mojikijun_rect(int cw, int ch, rect_t *r)
{
    r->w = JW_MK_W;
    r->h = JW_MK_H;
    r->x = (cw - JW_MK_W) / 2;
    r->y = (ch - 42 - JW_MK_H) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

/* Whether a control of the dialog is live.  The table is a snapshot of
   the original's dialog as it comes up, with ずれ使用 off and the six
   ずれ boxes dead with it; ticking it brings them to life, which is why
   the original refused to be driven into them before the tick
   (tools/probe70.sh). */
static int mk_live(const jw_mk_t *z)
{
    return z->enabled
           || (z->kind == JW_MK_EDIT && jw_cmd_moji_zure_now());
}

int ui_mojikijun_n(void)
{
    return JW_NMOJIKIJUN;
}

int ui_mojikijun_id(int i)
{
    return i >= 0 && i < JW_NMOJIKIJUN ? jw_mojikijun[i].id : 0;
}

void ui_mojikijun(fb_t *fb, int base, int caret)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    ui_mojikijun_rect(fb->w, fb->h, &r);
    dlg_chrome(fb, &r, JW_MK_CW, JW_MK_CH);
    jw_text_px(fb, r.x + 9, r.y + (JW_MK_CAPTION - th) / 2, JW_MK_TITLE,
               C_BTNTEXT);
    dlg_cross(fb, &r, JW_MK_W);
    cx = r.x + JW_MK_BORDER;
    cy = r.y + JW_MK_CAPTION;
    fb_fill(fb, cx, cy, JW_MK_CW, JW_MK_CH, C_BTNFACE);

    for (i = 0; i < JW_NMOJIKIJUN; i++) {
        const jw_mk_t *z = &jw_mojikijun[i];
        int x = cx + z->x, y = cy + z->y;
        unsigned int col = mk_live(z) ? C_BTNTEXT : C_BTNSHADOW;

        switch (z->kind) {
        case JW_MK_OK:
        case JW_MK_PUSH: {
            int k2 = z->deflt;          /* BS_DEFPUSHBUTTON */

            fb_fill(fb, x, y, z->w, z->h, C_BTNFACE);
            if (k2)
                fb_edge(fb, x, y, z->w, z->h, 0x646464u, 0x646464u);
            fb_edge(fb, x + k2, y + k2, z->w - 2 * k2, z->h - 2 * k2,
                    C_BTNHILIGHT, C_3DDKSHADOW);
            fb_edge(fb, x + k2 + 1, y + k2 + 1, z->w - 2 * k2 - 2,
                    z->h - 2 * k2 - 2, C_3DLIGHT, C_BTNSHADOW);
            zs_text(fb, x + (z->w - jw_text_px_w(z->text)) / 2,
                    y + (z->h - th) / 2, z->w - 6, z->text, col);
            break;
        }
        case JW_MK_RADIO:
            /* mj_radio draws its ring one row down from the y it is
               given (see tools/mkskradio.py), so the ring lands in the
               middle of a 15 tall control at the control's own top */
            mj_radio(fb, x, y + (z->h - 15) / 2, z->id - 1689 == base);
            zs_text(fb, x + 16, y + (z->h - th) / 2, z->w - 16, z->text,
                    col);
            break;
        case JW_MK_CHECK: {
            int by = y + (z->h - CHECK_W) / 2;
            int lit = z->id == 1323 ? jw_cmd_moji_zure_now()
                    : z->id >= 1327 && z->id <= 1329
                      ? jw_cmd_moji_rule_now(z->id) : z->on;

            paint_checkbox(fb, x, by, lit);
            if (!z->enabled) {
                fb_fill(fb, x + 2, by + 2, CHECK_W - 4, CHECK_H - 3,
                        C_BTNFACE);
                if (lit)
                    paint_tick_col(fb, x, by, C_BTNSHADOW);
            }
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, by + CHECK_H, CHECK_W, C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, col);
            break;
        }
        case JW_MK_EDIT: {
            const char *t = jw_cmd_moji_zure_box(z->id);
            int ty = y + (z->h - th) / 2;

            mj_sunken(fb, x, y, z->w, z->h);
            if (t && *t && mk_live(z)) {
                zs_text(fb, x + 3, ty, z->w - 6, t, C_BTNTEXT);
                if (caret == z->id)
                    fb_fill(fb, x + 3 + jw_text_px_w(t), ty, 1, th,
                            C_BTNTEXT);
            } else if (caret == z->id) {
                fb_fill(fb, x + 3, ty, 1, th, C_BTNTEXT);
            }
            break;
        }
        case JW_MK_GROUP: {
            int gy = y + th / 2, gh = z->h - th / 2;

            fb_edge(fb, x, gy, z->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, z->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            fb_fill(fb, x + 8, y, jw_text_px_w(z->text) + 4, th, C_BTNFACE);
            zs_text(fb, x + 10, y, z->w - 10, z->text, C_BTNTEXT);
            break;
        }
        case JW_MK_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, col);
            break;
        default:
            break;
        }
    }
}

int ui_mojikijun_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_mojikijun_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    if (dlg_close_hit(&r, JW_MK_W, x, y))
        return 2;               /* 見出しの × は キャンセル */
    x -= r.x + JW_MK_BORDER;
    y -= r.y + JW_MK_CAPTION;
    for (i = 0; i < JW_NMOJIKIJUN; i++) {
        const jw_mk_t *z = &jw_mojikijun[i];

        if (z->kind == JW_MK_STATIC || z->kind == JW_MK_GROUP || !mk_live(z))
            continue;
        if (x >= z->x && x < z->x + z->w && y >= z->y && y < z->y + z->h)
            return z->id;
    }
    return 0;                           /* on the dialog, on nothing */
}

/* The bar for the command in force.  Which controls each one has, and where
 * they sit, was read out of the running original -- see tools/mkbars.py. */
/* The controls of the bar in force. */
static int bar_now(const jw_ctl_t **c)
{
    int cmd = jw_cmd(), i;

    /* Once a range is settled the command puts up a bar of its own -- the
       one tools/bars2.ps1 reads, filed under 100000 + the command.  範囲選択
       has none, so it keeps the one it started with. */
    if (jw_cmd_sel_stage() == 3)
        for (i = 0; i < JW_NBARS; i++)
            if (jw_bars[i].cmd == 100000u + (unsigned)cmd && !jw_bars[i].on) {
                *c = jw_bars[i].c;
                return jw_bars[i].n;
            }
    /* A command bar is not one fixed row of controls: ticking a box can take
       some away and bring others.  矩形's ソリッド is the plain case -- with
       it on, 多重 goes and (対角線)・任意色・the colour button arrive.  Those
       are captured as variants (tools/bars3.ps1), each carrying the checkbox
       that has to be ticked for it to be the bar. */
    for (i = 0; i < JW_NBARS; i++)
        if (jw_bars[i].cmd == (unsigned)cmd && jw_bars[i].on
            && jw_cmd_bar_check(jw_bars[i].on) > 0) {
            *c = jw_bars[i].c;
            return jw_bars[i].n;
        }
    for (i = 0; i < JW_NBARS; i++)
        if (jw_bars[i].cmd == (unsigned)cmd && !jw_bars[i].on) {
            *c = jw_bars[i].c;
            return jw_bars[i].n;
        }
    *c = jw_bar_32771;
    return (int)(sizeof jw_bar_32771 / sizeof jw_bar_32771[0]);
}

/* What the original has with this id on that command's bar.
 *
 * The bars are CDialogBars in the original and every control on them is a
 * real control: a checkbox toggles when it is clicked and a combo takes
 * typing, whatever the command then makes of it.  src/cmd.c keeps that state
 * for all of them, and asks here what a control is and how it comes up --
 * both read out of the running original by tools/mkbars.py.
 *
 * Answers 'c' for a checkbox, 'b' for a button, 'o' for a combo, 's' for a
 * label and 0 when that bar has no such control; *checked, if it is given,
 * is how the original has a checkbox on entering the command.
 */
int ui_bar_ctl(unsigned cmd, int id, int *checked)
{
    int i, k;

    /* every variant of that command's bar, so a control that only appears
       on one of them still has a kind and a starting state */
    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != cmd)
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            if (c->id != (unsigned short)id)
                continue;
            if (checked)
                *checked = c->checked;
            return c->kind == JW_CTL_CHECK ? 'c'
                 : c->kind == JW_CTL_BUTTON ? 'b'
                 : c->kind == JW_CTL_COMBO ? 'o' : 's';
        }
    }
    return 0;
}

/* Whether a control can be pressed.  The captured state is how the original
   has it on entering the command; the few the port drives itself say so. */
static int ctl_enabled(const jw_drawing *d, const jw_ctl_t *c)
{
    int e = jw_cmd_bar_enabled(d, c->id);

    return e < 0 ? c->enabled : e;
}

int ui_bar_hit(int x, int y)
{
    const jw_ctl_t *c;
    int n = bar_now(&c), i;

    for (i = 0; i < n; i++)
        /* the checkboxes count as well: they are what turns 水平・垂直,
           ソリッド, 実寸 and the rest on and off, and leaving them out of
           the hit test left them drawn but dead */
        if ((c[i].kind == JW_CTL_BUTTON || c[i].kind == JW_CTL_COMBO
             || c[i].kind == JW_CTL_CHECK)
            && x >= c[i].x && x < c[i].x + c[i].w
            && y >= c[i].y && y < c[i].y + c[i].h)
            return c[i].id;
    return 0;
}

static void paint_bar(fb_t *fb, const jw_drawing *d)
{
    const jw_ctl_t *c = jw_bar_32771;
    int n = (int)(sizeof jw_bar_32771 / sizeof jw_bar_32771[0]);
    int i;
    /* the labels are centred in their control the way Windows centres them;
       the port's glyphs are taller than the original's, and without this the
       bottom rows of them fall outside the bar's text area */
    int th = jw_text_height();

    n = bar_now(&c);
    for (i = 0; i < n; i++) {
        int on = 0, en = ctl_enabled(d, &c[i]);
        switch (c[i].kind) {
        case JW_CTL_CHECK:
            /* how the original has it on entering the command, read out
               with BM_GETCHECK, and then whatever the port itself changes */
            on = c[i].checked;
            if (jw_cmd_bar_check(c[i].id) >= 0)
                on = jw_cmd_bar_check(c[i].id);
            paint_checkbox(fb, c[i].x, c[i].y, on);
            jw_text_px(fb, c[i].x + CHECK_W + 3, c[i].y + (c[i].h - th) / 2,
                       c[i].text, en ? C_BTNTEXT : C_GRAYTEXT);
            break;
        case JW_CTL_BUTTON:
            paint_barbutton(fb, c[i].x, c[i].y, c[i].w, c[i].h);
            if (c[i].id == 2552) {
                /* 矩形 の 任意□: the original owner-draws this one
                 * (its style carries BS_OWNERDRAW) and the capture has no
                 * text for it at all.  What it paints is the writing pen:
                 * the number, and a block of that pen's colour beside it.
                 * Measured off the original's own window -- the block is
                 * ten across and twelve down, 27 in from the button's left
                 * edge and 6 down from its top, and the number sits 9 in. */
                char num[8];
                unsigned rgb;
                int pen = d && d->write_ltype ? d->write_color : 2;
                if (pen < 1 || pen > 9)
                    pen = 2;
                rgb = d ? d->pen_rgb[pen] : jw_default_pen_rgb[pen];
                sprintf(num, "%d", pen);
                jw_text_px(fb, c[i].x + 9, c[i].y + (c[i].h - th) / 2,
                           num, en ? C_BTNTEXT : C_GRAYTEXT);
                fb_fill(fb, c[i].x + 27, c[i].y + 6, 10, 12, rgb);
            } else if (c[i].id == 1061 && jw_cmd() == 0x804f) {
                /* 寸法 の 小数桁: the label carries the number, and the
                   capture baked in the 2 the original happened to be at.
                   Pressing it cycles 2 -> 3 -> 0 -> 1, so the label has
                   to follow or the button looks dead. */
                char t[32];
                sprintf(t, "\x8f\xac\x90\x94\x8c\x85 %d",
                        jw_cmd_sunpo_decimals());
                jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                           t, en ? C_BTNTEXT : C_GRAYTEXT);
            } else if (c[i].id == 1070 && jw_cmd() == 0x8081) {
                /* 測定 の 小数桁: the label carries the number and the
                   capture baked in the 3 the original was at.  Pressing it
                   walks 0 1 2 3 4 F round (tools/probe130.sh). */
                char t[32];
                int k = jw_cmd_sokutei_dp();
                sprintf(t, "\x8f\xac\x90\x94\x8c\x85 %c",
                        k == 5 ? 'F' : (char)('0' + k));
                jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                           t, en ? C_BTNTEXT : C_GRAYTEXT);
            } else if (c[i].id == 1069 && jw_cmd() == 0x8081) {
                /* 測定 の 単位: the braces mark the one in force, and
                   while 角度測定 is chosen the button is the degree
                   format instead (tools/probe130.sh).  度分秒 is not
                   done, so that one is drawn and left alone. */
                const char *t = jw_cmd_sokutei_mode() == 1067
                    ? "\x81y \x81\x8b\x81z\x81^ \x81\x8b\x81\x8c\x81\x8d"
                    : jw_cmd_sokutei_mm() ? "\x81ymm\x81z / \x82\x8d"
                                          : "mm / \x81y\x82\x8d\x81z";
                jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                           t, en ? C_BTNTEXT : C_GRAYTEXT);
            } else if (c[i].id == 1062 && jw_cmd() == 0x804f) {
                /* 寸法 の 端部: the label says which it is, and the
                   original writes the arrow as the two characters ->
                   rather than a glyph (read off its own bar after a
                   press: 「端部 ->」). */
                char t[32];
                sprintf(t, "\x92[\x95\x94 %s",
                        jw_cmd_sunpo_arrows() ? "->" : "\x81\x9c");
                jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                           t, en ? C_BTNTEXT : C_GRAYTEXT);
            } else if (c[i].id == 1843 && d) {
                /* 文字 の書込文字種: the capture baked in whatever the
                 * original happened to be writing with -- 「[10]  W=10 H=10
                 * D=1 (5)」 -- and the port drew that for ever.  It is the
                 * drawing's own: the number of the 文字種 whose width,
                 * height and spacing match, then those three and its pen. */
                char t[64];
                int k, no = 0;
                for (k = 0; k < 10; k++)
                    if (d->style[k].w == d->cur_style.w
                        && d->style[k].h == d->cur_style.h
                        && d->style[k].sp == d->cur_style.sp) {
                        no = k + 1;
                        break;
                    }
                /* and 「Free」 when it is none of the ten -- read off the
                   original's own bar after typing a size into the dialog:
                   「Free  W=30 H=40 D=2 (2)」 */
                if (no)
                    sprintf(t, "[%d]  W=%g H=%g D=%g (%d)", no, d->cur_style.w,
                            d->cur_style.h, d->cur_style.sp,
                            d->cur_style.color);
                else
                    sprintf(t, "Free  W=%g H=%g D=%g (%d)", d->cur_style.w,
                            d->cur_style.h, d->cur_style.sp,
                            d->cur_style.color);
                jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                           t, en ? C_BTNTEXT : C_GRAYTEXT);
            } else {
                jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                           c[i].text, en ? C_BTNTEXT : C_GRAYTEXT);
            }
            break;
        case JW_CTL_STATIC:
            jw_text_px(fb, c[i].x, c[i].y + (c[i].h - th) / 2, c[i].text,
                       en ? C_BTNTEXT : C_GRAYTEXT);
            break;
        case JW_CTL_COMBO: {
            /* the boxes the port keeps a number in are drawn with it, and
               with a caret while they are the one being typed into */
            const char *t = jw_cmd_box(c[i].id);
            paint_combo(fb, c[i].x, c[i].y, c[i].w, c[i].h);
            if (t) {
                int tx = c[i].x + 4, ty = c[i].y + (c[i].h - th) / 2;
                tx = jw_text_px(fb, tx, ty, t, C_BTNTEXT);
                if (jw_cmd_box_focus() == c[i].id)
                    fb_fill(fb, tx, ty, 1, th, C_BTNTEXT);
            }
            break;
        }
        }
    }
}

/* What state a toolbar button is in right now.  Both the painting and the
 * hit test go through this so they cannot disagree.
 *
 * A button is pressed when it is the command in force -- that is all the
 * original's ON_UPDATE_COMMAND_UI handler does for a mode
 * (pCmdUI->SetCheck(view->current == id), FUN_00511c20 and friends).  The
 * reference screen was taken in 線, which is why that one came out pressed.
 * The two buttons that come alive are 上書, once there is a file to write
 * back to, and 元に戻る, once there is something to take back; both are grey
 * on the reference screen because neither was true there.
 */
int ui_button_state(int k, int saveable, int undoable)
{
    const jw_btn_t *b = &jw_buttons[k];
    int state = b->state;

    if (state != 1)
        return jw_btn_mode[k] && jw_btn_cmd[k] == jw_cmd() ? 2 : 0;
    if (b->strip == 464 && b->cell == 2 && saveable)
        return 0;
    if (jw_btn_cmd[k] == 0xe12b && undoable)
        return 0;
    return 1;
}

static void paint_buttons(fb_t *fb, int saveable, int undoable)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++) {
        const jw_btn_t *b = &jw_buttons[k];
        const jw_bitmap_t *bm = jw_bitmap(b->strip);
        int state = ui_button_state(k, saveable, undoable);
        int bx = ui_ax(b->x, fb->w);
        int dx, dy;

        dx = CELL_DX + (state == 2);
        dy = CELL_DY + (state == 2);

        button_frame(fb, bx, b->y, BTN_W, BTN_H, state == 2);
        if (state == 2)
            checker(fb, bx + 2, b->y + 2, BTN_W - 4, BTN_H - 4);
        else
            fb_fill(fb, bx + 2, b->y + 2, BTN_W - 4, BTN_H - 4, C_BTNFACE);
        blit_cell_state(fb, bm, b->cell, bx + dx, b->y + dy, state);
    }
}

void ui_paint(fb_t *fb, const jw_drawing *d, double zoom, int saveable,
              int undoable)
{
    rect_t v;

    fb_fill(fb, 0, 0, fb->w, fb->h, C_BTNFACE);
    paint_bars(fb);

    ui_view_rect(fb->w, fb->h, &v);
    /* EDGE_SUNKEN round the drawing area */
    fb_edge(fb, v.x - 2, v.y - 2, v.w + 4, v.h + 4, C_BTNSHADOW, C_BTNHILIGHT);
    fb_edge(fb, v.x - 1, v.y - 1, v.w + 2, v.h + 2, C_3DDKSHADOW, C_3DLIGHT);
    fb_fill(fb, v.x, v.y, v.w, v.h, C_WINDOW);

    paint_bar(fb, d);
    paint_layer_grids(fb, d);
    paint_samples(fb, d);
    if (!status_hidden)
        paint_status(fb);
    status_text(fb, d, zoom);
    paint_buttons(fb, saveable, undoable);

    {
        int k;
        for (k = 0; k < 4; k++) {
            int x = ui_right(small_buttons[k].x, fb->w);
            int y = small_buttons[k].y;
            button_frame(fb, x, y, SMALL_W, SMALL_H, 0);
            fb_fill(fb, x + 2, y + 2, SMALL_W - 4, SMALL_H - 4, C_BTNFACE);
        }
    }
}

/* ------------------------------------------ dialogs from the templates ---
 * Any of the original's own dialog templates (src/gen/dlgtpl.h, laid out
 * from decomp/res/dialog.txt by tools/mkdlgtpl.py with the same MapDialogRect
 * sum Windows uses).  The dialogs above were each read off the running
 * original one by one; these are every other popup dialog it has, drawn
 * the same way -- the same chrome, the same x, the same buttons, checks,
 * group boxes and edit boxes -- so a command whose dialog nobody has
 * captured yet can still put the right window up.
 *
 * `t` is an index into jw_tdlg; `on` and `txt` are per control, in the order
 * jw_tctl has them from jw_tdlg[t].first, and may be null.
 */
#include "gen/dlgtpl.h"

/* src/ui.h hands the kinds out under its own names; they have to be the
   generated ones, in the same order */
typedef char td_kinds_agree[((int)JW_TC_PUSH == (int)UI_TC_PUSH
                             && (int)JW_TC_RADIO == (int)UI_TC_RADIO
                             && (int)JW_TC_EDIT == (int)UI_TC_EDIT
                             && (int)JW_TC_ICON == (int)UI_TC_ICON) ? 1 : -1];

int ui_tdlg_find(int tpl)
{
    int i;

    for (i = 0; i < JW_NTDLG; i++)
        if (jw_tdlg[i].tpl == tpl)
            return i;
    return -1;
}

int ui_tdlg_n(int t)
{
    return t >= 0 && t < JW_NTDLG ? jw_tdlg[t].n : 0;
}

int ui_tdlg_ctl(int t, int i, int *id, int *kind, int *flags)
{
    const jw_tctl_t *c;

    if (t < 0 || t >= JW_NTDLG || i < 0 || i >= jw_tdlg[t].n)
        return 0;
    c = &jw_tctl[jw_tdlg[t].first + i];
    if (id)
        *id = c->id;
    if (kind)
        *kind = c->kind;
    if (flags)
        *flags = c->flags;
    return 1;
}

/* which control (its index in the dialog) has this id, or -1 */
int ui_tdlg_index(int t, int id)
{
    int i;

    if (t < 0 || t >= JW_NTDLG)
        return -1;
    for (i = 0; i < jw_tdlg[t].n; i++)
        if (jw_tctl[jw_tdlg[t].first + i].id == id)
            return i;
    return -1;
}

void ui_tdlg_rect(int cw, int ch, int t, rect_t *r)
{
    int w = (t >= 0 && t < JW_NTDLG ? jw_tdlg[t].cw : 0) + 2 * JW_TDLG_BORDER;
    int h = (t >= 0 && t < JW_NTDLG ? jw_tdlg[t].ch : 0) + JW_TDLG_CAPTION
            + JW_TDLG_BORDER;

    r->w = w;
    r->h = h;
    r->x = (cw - w) / 2;
    r->y = (ch - 42 - h) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

static void td_radio(fb_t *fb, int x, int y, int on)
{
    const unsigned int *sp = on ? jw_skradio_on : jw_skradio_off;
    int i, j;

    for (j = 0; j < JW_SKRADIO_H; j++)
        for (i = 0; i < JW_SKRADIO_W; i++)
            px_put(fb, x + i, y + j, sp[j * JW_SKRADIO_W + i]);
}

static void td_button(fb_t *fb, int x, int y, int w, int h, int def)
{
    fb_fill(fb, x, y, w, h, C_BTNFACE);
    if (def)
        fb_edge(fb, x, y, w, h, 0x646464u, 0x646464u);
    fb_edge(fb, x + def, y + def, w - 2 * def, h - 2 * def,
            C_BTNHILIGHT, C_3DDKSHADOW);
    fb_edge(fb, x + def + 1, y + def + 1, w - 2 * def - 2, h - 2 * def - 2,
            C_3DLIGHT, C_BTNSHADOW);
}

void ui_tdlg(fb_t *fb, int t, const unsigned char *on,
             const char *const *txt, int caret)
{
    const jw_tdlg_t *g;
    rect_t r;
    int cx, cy, i, th = jw_text_height();

    if (t < 0 || t >= JW_NTDLG)
        return;
    g = &jw_tdlg[t];
    ui_tdlg_rect(fb->w, fb->h, t, &r);
    dlg_chrome(fb, &r, g->cw, g->ch);
    jw_text_px(fb, r.x + 9, r.y + (JW_TDLG_CAPTION - th) / 2, g->title,
               C_BTNTEXT);
    dlg_cross(fb, &r, r.w);
    cx = r.x + JW_TDLG_BORDER;
    cy = r.y + JW_TDLG_CAPTION;
    fb_fill(fb, cx, cy, g->cw, g->ch, C_BTNFACE);

    for (i = 0; i < g->n; i++) {
        const jw_tctl_t *c = &jw_tctl[g->first + i];
        int x = cx + c->x, y = cy + c->y;
        int st = on ? on[i] : 0, lit = st & 1;
        unsigned col = (c->flags & 2) || (st & UI_TD_GREY) ? C_GRAYTEXT
                                                          : C_BTNTEXT;
        const char *s = txt && txt[i] ? txt[i] : c->text;

        if (!(c->flags & 1) || (st & UI_TD_HIDE))
            continue;                   /* not WS_VISIBLE, or hidden since */
        switch (c->kind) {
        case JW_TC_PUSH:
        case JW_TC_DEFPUSH:
            td_button(fb, x, y, c->w, c->h, c->kind == JW_TC_DEFPUSH);
            zs_text(fb, x + (c->w - jw_text_px_w(s)) / 2,
                    y + (c->h - th) / 2, c->w - 6, s, col);
            break;
        case JW_TC_CHECK:
            paint_checkbox(fb, x, y + (c->h - CHECK_W) / 2, lit);
            zs_text(fb, x + CHECK_W + 3, y + (c->h - th) / 2,
                    c->w - CHECK_W - 3, s, col);
            break;
        case JW_TC_RADIO:
            td_radio(fb, x, y + (c->h - JW_SKRADIO_H) / 2, lit);
            zs_text(fb, x + CHECK_W + 3, y + (c->h - th) / 2,
                    c->w - CHECK_W - 3, s, col);
            break;
        case JW_TC_GROUP: {
            int gy = y + th / 2, gh = c->h - th / 2;

            fb_edge(fb, x, gy, c->w, gh, C_BTNSHADOW, C_BTNHILIGHT);
            fb_edge(fb, x + 1, gy + 1, c->w - 2, gh - 2,
                    C_BTNHILIGHT, C_BTNSHADOW);
            if (*s) {
                fb_fill(fb, x + 8, y, jw_text_px_w(s) + 4, th, C_BTNFACE);
                zs_text(fb, x + 10, y, c->w - 10, s, col);
            }
            break;
        }
        case JW_TC_STATIC: {
            int a = (int)(c->style & 3), tw = jw_text_px_w(s);
            int tx = a == 1 ? x + (c->w - tw) / 2 : a == 2 ? x + c->w - tw : x;
            /* SS_CENTERIMAGE (0x200) centres it up and down too */
            int ty = (c->style & 0x200) ? y + (c->h - th) / 2 : y;

            zs_text(fb, tx, ty, c->w - (tx - x), s, col);
            break;
        }
        case JW_TC_EDIT:
            mj_sunken(fb, x, y, c->w, c->h);
            if (!(c->flags & 2))
                fb_fill(fb, x + 2, y + 2, c->w - 4, c->h - 4, 0xffffffu);
            zs_text(fb, x + 3, y + (c->h - th) / 2, c->w - 6,
                    txt && txt[i] ? txt[i] : "", col);
            if (caret == c->id)
                fb_fill(fb, x + 3 + jw_text_px_w(txt && txt[i] ? txt[i] : ""),
                        y + (c->h - th) / 2, 1, th, C_BTNTEXT);
            break;
        case JW_TC_COMBO: {
            int bw = c->h - 4, ax = x + c->w - 2 - bw / 2, ay = y + c->h / 2;
            int k;

            mj_sunken(fb, x, y, c->w, c->h);
            fb_fill(fb, x + 2, y + 2, c->w - 4, c->h - 4, 0xffffffu);
            zs_text(fb, x + 3, y + (c->h - th) / 2, c->w - bw - 8,
                    txt && txt[i] ? txt[i] : "", col);
            td_button(fb, x + c->w - 2 - bw, y + 2, bw, c->h - 4, 0);
            for (k = 0; k < 4; k++)     /* the little arrow */
                fb_fill(fb, ax - 3 + k, ay - 1 + k, 7 - 2 * k, 1, C_BTNTEXT);
            break;
        }
        case JW_TC_LIST:
            mj_sunken(fb, x, y, c->w, c->h);
            fb_fill(fb, x + 2, y + 2, c->w - 4, c->h - 4, 0xffffffu);
            break;
        case JW_TC_FRAME:
            fb_edge(fb, x, y, c->w, c->h, C_BTNSHADOW, C_BTNHILIGHT);
            break;
        case JW_TC_ICON: {
            /* SS_ICON.  The only one in these templates is バージョン情報's
               "#320", the program's own icon group, drawn at its 32x32
               (tools/mkicon.py) from the control's top left as Windows
               draws it */
            int ix, iy;

            for (iy = 0; iy < JW_ICON32; iy++)
                for (ix = 0; ix < JW_ICON32; ix++)
                    if (jw_icon32_mask[iy * JW_ICON32 + ix])
                        px_put(fb, x + ix, y + iy,
                               jw_icon32[iy * JW_ICON32 + ix]);
            break;
        }
        default:
            break;
        }
    }
}

/* -1 outside the window (it is modal), 2 for the x, the id of the control
   under the point, or 0 on the dialog but on nothing that answers */
int ui_tdlg_hit(int cw, int ch, int t, int x, int y)
{
    const jw_tdlg_t *g;
    rect_t r;
    int i;

    if (t < 0 || t >= JW_NTDLG)
        return -1;
    g = &jw_tdlg[t];
    ui_tdlg_rect(cw, ch, t, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;
    if (dlg_close_hit(&r, r.w, x, y))
        return 2;
    x -= r.x + JW_TDLG_BORDER;
    y -= r.y + JW_TDLG_CAPTION;
    for (i = 0; i < g->n; i++) {
        const jw_tctl_t *c = &jw_tctl[g->first + i];

        if (!(c->flags & 1) || (c->flags & 2))
            continue;
        if (c->kind == JW_TC_GROUP || c->kind == JW_TC_STATIC
            || c->kind == JW_TC_FRAME || c->kind == JW_TC_ICON)
            continue;
        if (x >= c->x && x < c->x + c->w && y >= c->y && y < c->y + c->h)
            return c->id;
    }
    return 0;
}

/* where control i of dialog t sits on the screen, for tests and taps */
int ui_tdlg_ctl_rect(int cw, int ch, int t, int i, rect_t *out)
{
    rect_t r;
    const jw_tctl_t *c;

    if (t < 0 || t >= JW_NTDLG || i < 0 || i >= jw_tdlg[t].n)
        return 0;
    ui_tdlg_rect(cw, ch, t, &r);
    c = &jw_tctl[jw_tdlg[t].first + i];
    out->x = r.x + JW_TDLG_BORDER + c->x;
    out->y = r.y + JW_TDLG_CAPTION + c->y;
    out->w = c->w;
    out->h = c->h;
    return 1;
}

/* how many templates there are, and the t-th one's number and kind */
int ui_tdlg_count(void)
{
    return JW_NTDLG;
}

int ui_tdlg_tpl(int t)
{
    return t >= 0 && t < JW_NTDLG ? jw_tdlg[t].tpl : 0;
}

int ui_tdlg_is_bar(int t)
{
    return t >= 0 && t < JW_NTDLG ? jw_tdlg[t].bar : 0;
}

/* control i of dialog t in the dialog's own client coordinates */
int ui_tdlg_ctl_xy(int t, int i, rect_t *out)
{
    const jw_tctl_t *c;

    if (t < 0 || t >= JW_NTDLG || i < 0 || i >= jw_tdlg[t].n)
        return 0;
    c = &jw_tctl[jw_tdlg[t].first + i];
    out->x = c->x;
    out->y = c->y;
    out->w = c->w;
    out->h = c->h;
    return 1;
}
