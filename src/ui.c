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
#include "gen/blkname.h"
#include "gen/blkedit.h"
#include "gen/kihon.h"
#include "gen/pens.h"
#include "gen/menu.h"
#include "gen/jwicon.h"
#include "gen/cmds.h"
#include "cmd.h"
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

void ui_view_rect(int cw, int ch, rect_t *r)
{
    r->x = VIEW_L;
    r->y = VIEW_T;
    r->w = cw - VIEW_R - VIEW_L;
    r->h = ch - VIEW_B - VIEW_T;
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
static void checker(fb_t *fb, int x, int y, int w, int h)
{
    int i, j;

    for (j = 0; j < h; j++)
        for (i = 0; i < w; i++)
            fb->px[(size_t)(y + j) * fb->w + x + i] =
                ((x + i + y + j) & 1) ? C_BTNHILIGHT : C_BTNFACE;
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
            if (cellpx(bm, cell, i, j) != 0xc0c0c0u
                && x + i + 1 < fb->w && y + j + 1 < fb->h)
                fb->px[(size_t)(y + j + 1) * fb->w + x + i + 1] = C_BTNHILIGHT;
    for (j = 0; j < CELL_H; j++)
        for (i = 0; i < CELL_W; i++)
            if (cellpx(bm, cell, i, j) != 0xc0c0c0u)
                fb->px[(size_t)(y + j) * fb->w + x + i] = C_BTNSHADOW;
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
    if (pop_top == top)
        return 0;
    pop_top = top;
    pop_sub = -1;
    pop_hot = -1;
    return 1;
}

int ui_popup_top(void)
{
    return pop_top;
}

int ui_popup_hit(int x, int y)
{
    int px, py, pw, ph, from, to, k;

    if (pop_top < 0)
        return -1;
    if (pop_sub >= 0) {
        int sx, sy, sw, sh, sf, st;

        sub_box(&sx, &sy, &sw, &sh, &sf, &st);
        k = pop_at(sf, st, 2, sx, sy, sw, x, y);
        if (k >= 0)
            return k;
    }
    pop_box(&px, &py, &pw, &ph, &from, &to);
    return pop_at(from, to, 1, px, py, pw, x, y);
}

int ui_popup_in(int x, int y)
{
    int px, py, pw, ph, from, to;

    if (pop_top < 0)
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
        else if (m->id && (int)m->id == jw_cmd())
            jw_text_px(fb, x0 + 16, ty, "*", C_BTNTEXT);
        y += JW_POPUP_ITEM_H;
    }
}

void ui_popup_draw(fb_t *fb)
{
    int px, py, pw, ph, from, to;

    if (pop_top < 0)
        return;
    pop_box(&px, &py, &pw, &ph, &from, &to);
    pop_paint(fb, px, py, pw, ph, from, to, 1);
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
 * bitmap from the resources.  The top-left cell of a grid uses the variant
 * with the black top and left edge (2652); the others carry black on the
 * bottom and right (2662), so the cells tile into one grid with a single
 * outline.  Only the face colour is remapped -- the grey stays 0x808080,
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

/* The mark for "there is something on this one", two rows across the top. */
#define C_HASDATA  0xd700d7u

static void paint_layer_grids(fb_t *fb, const jw_drawing *d)
{
    int used[2][16];
    int write[2];
    int g, col, row, i, j, k;

    for (g = 0; g < 2; g++) {
        write[g] = 0;
        for (i = 0; i < 16; i++)
            used[g][i] = 0;
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
            used[1][o->lgroup & 15] = 1;
            if ((o->lgroup & 15) == wg)
                used[0][o->layer & 15] = 1;
        }
    }

    for (g = 0; g < 2; g++) {
        for (col = 0; col < 2; col++) {
            for (row = 0; row < 8; row++) {
                int n = col * 8 + row;
                int x = ui_right(layer_grids[g].x, fb->w)
                        + col * LAYER_CELL_W;
                int y = layer_grids[g].y + row * LAYER_CELL_H;

                blit_layer_cell(fb, (col == 0 && row == 0) ? 2652 : 2662,
                                x, y,
                                ui_right(layer_grids[g].clip, fb->w));
                if (n == write[g]) {
                    /* a red bar if it holds anything, then the mark: a ring
                     * for the layer, a box for the group */
                    if (used[g][n])
                        fb_fill(fb, x + 2, y + 2, 16, 2, 0xff0000u);
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
                    /* every group cell carries a black box round its digit */
                    if (g == 1)
                        fb_edge(fb, x + 1, y + 3, 16, 16,
                                C_BTNTEXT, C_BTNTEXT);
                    if (used[g][n])
                        fb_fill(fb, x + 1, y + 1, 16, 2, C_HASDATA);
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

static void paint_samples(fb_t *fb)
{
    int k;

    for (k = 0; k < 2; k++) {
        int x = ui_ax(samples[k].x, fb->w), y = samples[k].y;

        fb_fill(fb, x + 1, y + 1, SAMPLE_W - 2, SAMPLE_H - 2, C_WINDOW);
        fb_edge(fb, x, y, SAMPLE_W, SAMPLE_H, 0xc0c0c0u, 0x8c8c8cu);
        /* the black shadow is an L, not a box: right edge and underside */
        fb_vline(fb, x + SAMPLE_W, y - 1, SAMPLE_H + 2, C_BTNTEXT);
        fb_hline(fb, x - 1, y + SAMPLE_H, SAMPLE_W + 2, C_BTNTEXT);
        /* the current line type, drawn across the middle */
        fb_hline(fb, x + 1, y + 9, SAMPLE_W - 2, C_BTNTEXT);
    }
}

/* The status line: a face-coloured bar with a row of panes and a size grip. */
static const struct { short x0, x1; } panes[5] = {
    {  987, 1022 }, { 1025, 1086 }, { 1089, 1153 },
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
    jw_text_px(fb, 8, ty, jw_cmd_prompt(), C_BTNTEXT);
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
    jw_text_px(fb, ui_right(panes[3].x0 + 4, fb->w), ty, "\x81\xda 0", C_BTNTEXT);
    /* two decimals, cut not rounded, and a trailing zero dropped: the
       original shows 0.21, 0.3, 0.42 and 0.1 for the four sheet sizes */
    sprintf(buf, "\x81\x7e %g", (double)(long)(zoom * 100.0 + 1e-9) / 100.0);
    jw_text_px(fb, ui_right(panes[4].x0 + 4, fb->w), ty, buf, C_BTNTEXT);
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
            fb->px[(size_t)y * fb->w + x] = C_BTNHILIGHT;
            for (j = 1; j <= 2; j++)
                if (x + j <= fb->w - 2)
                    fb->px[(size_t)y * fb->w + x + j] = C_BTNSHADOW;
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
#define MJ_CLOSE      0x9b9b9bu

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

/* One row of the table: width, height, spacing, colour and how many texts
   are written in that 文字種.  The columns are the original's own. */
static void mj_row(char *t, double w, double h, double sp, int col, int used)
{
    char n[16], c[16];

    if (used > 0)
        sprintf(n, "%d", used);
    else
        sprintf(n, "--");
    sprintf(c, "(%d)", col);
    sprintf(t, "%7.2f%8.2f%8.3f%7s%11s", w, h, sp, c, n);
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
    int scol = d->cur_style.color;

    if (style >= 1 && style <= 10) {
        sw = d->style[style - 1].w;
        sh = d->style[style - 1].h;
        ss = d->style[style - 1].sp;
        scol = d->style[style - 1].color;
    }
    mj_counts(d, used);
    ui_moji_rect(fb->w, fb->h, &r);
    /* the window: a black border, a light caption across the top and the
       client below it */
    fb_fill(fb, r.x, r.y, r.w, r.h, C_BTNTEXT);
    fb_fill(fb, r.x, r.y, r.w, JW_MOJI_CAPTION, MJ_CAPTION_BG);
    jw_text_px(fb, r.x + 9, r.y + (JW_MOJI_CAPTION - th) / 2,
               /* 書込み文字種変更 */
               "\x8f\x91\x8d\x9e\x82\xdd\x95\xb6\x8e\x9a\x8e\xed\x95\xcf\x8d"
               "X", C_BTNTEXT);
    for (i = 0; i < 9; i++) {   /* the close cross */
        fb_fill(fb, r.x + 381 + i, r.y + 10 + i, 1, 1, MJ_CLOSE);
        fb_fill(fb, r.x + 389 - i, r.y + 10 + i, 1, 1, MJ_CLOSE);
    }
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
                    sprintf(t, "%.3f", ss);
                else
                    sprintf(t, "%.2f", z->id == 1491 ? sw : sh);
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
                sprintf(t, "%d", scol);
                jw_text_px(fb, x + 4, y + (z->h - th) / 2, t, C_BTNTEXT);
            }
            break;
        case JW_MJ_STATIC:
            if (z->n >= 1 && z->n <= 10) {
                mj_row(t, d->style[z->n - 1].w, d->style[z->n - 1].h,
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

int ui_moji_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_moji_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside the dialog altogether */
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
    fb_fill(fb, r.x, r.y, r.w, r.h, C_BTNTEXT);
    fb_fill(fb, r.x, r.y, r.w, JW_ZS_CAPTION, MJ_CAPTION_BG);
    for (i = 0; i < 9; i++) {   /* the close cross, and no title beside it */
        fb_fill(fb, r.x + JW_ZS_W - 25 + i, r.y + 10 + i, 1, 1, MJ_CLOSE);
        fb_fill(fb, r.x + JW_ZS_W - 17 - i, r.y + 10 + i, 1, 1, MJ_CLOSE);
    }
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
    fb_fill(fb, r.x, r.y, r.w, r.h, C_BTNTEXT);
    fb_fill(fb, r.x, r.y, r.w, JW_BN_CAPTION, MJ_CAPTION_BG);
    jw_text_px(fb, r.x + 9, r.y + (JW_BN_CAPTION - th) / 2, JW_BN_TITLE,
               C_BTNTEXT);
    for (i = 0; i < 9; i++) {           /* the close cross */
        fb_fill(fb, r.x + JW_BN_W - 25 + i, r.y + 10 + i, 1, 1, MJ_CLOSE);
        fb_fill(fb, r.x + JW_BN_W - 17 - i, r.y + 10 + i, 1, 1, MJ_CLOSE);
    }
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
    fb_fill(fb, r.x, r.y, r.w, r.h, C_BTNTEXT);
    fb_fill(fb, r.x, r.y, r.w, JW_BE_CAPTION, MJ_CAPTION_BG);
    jw_text_px(fb, r.x + 9, r.y + (JW_BE_CAPTION - th) / 2, JW_BE_TITLE,
               C_BTNTEXT);
    for (i = 0; i < 9; i++) {           /* the close cross */
        fb_fill(fb, r.x + JW_BE_W - 25 + i, r.y + 10 + i, 1, 1, MJ_CLOSE);
        fb_fill(fb, r.x + JW_BE_W - 17 - i, r.y + 10 + i, 1, 1, MJ_CLOSE);
    }
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

int ui_kihon_n(void)
{
    return JW_NKIHON;
}

int ui_kihon_id(int i)
{
    return i >= 0 && i < JW_NKIHON ? jw_kihon[i].id : 0;
}

void ui_kihon(fb_t *fb, const unsigned char *on)
{
    rect_t r;
    int cx, cy, i, th = jw_text_height(), tx;

    ui_kihon_rect(fb->w, fb->h, &r);
    fb_fill(fb, r.x, r.y, r.w, r.h, C_BTNTEXT);
    fb_fill(fb, r.x, r.y, r.w, JW_KH_CAPTION, MJ_CAPTION_BG);
    jw_text_px(fb, r.x + 9, r.y + (JW_KH_CAPTION - th) / 2, JW_KH_TITLE,
               C_BTNTEXT);
    for (i = 0; i < 9; i++) {           /* the close cross */
        fb_fill(fb, r.x + JW_KH_W - 25 + i, r.y + 10 + i, 1, 1, MJ_CLOSE);
        fb_fill(fb, r.x + JW_KH_W - 17 - i, r.y + 10 + i, 1, 1, MJ_CLOSE);
    }
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
    tx = cx + JW_KH_TAB_X + 2;
    for (i = 0; i < JW_NKIHON_TABS; i++) {
        int w = jw_text_px_w(jw_kihon_tabs[i]) + 12;
        int y = cy + JW_KH_TAB_Y + (i ? 2 : 0);
        int h = JW_KH_TAB_ROW - (i ? 2 : 0) + 1;

        fb_fill(fb, tx, y, w, h, C_BTNFACE);
        fb_edge(fb, tx, y, w, h, C_BTNHILIGHT, C_BTNSHADOW);
        zs_text(fb, tx + 6, y + (h - th) / 2, w - 12, jw_kihon_tabs[i],
                C_BTNTEXT);
        tx += w;
    }

    for (i = 0; i < JW_NKIHON; i++) {
        const jw_kh_t *z = &jw_kihon[i];
        int x = cx + z->x, y = cy + z->y;
        unsigned int col = z->enabled ? C_BTNTEXT : C_BTNSHADOW;

        if (!z->shown)
            continue;
        switch (z->kind) {
        case JW_KH_PUSH: {
            int k2 = z->id == 1;        /* OK is the default one */

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
        case JW_KH_CHECK:
        case JW_KH_RADIO: {
            int by = y + (z->h - CHECK_W) / 2;

            paint_checkbox(fb, x, by, on ? on[i] : z->on);
            /* A box that cannot be pressed has the dialog's face inside it
               rather than white, and its tick comes out in the shadow
               colour rather than black. */
            if (!z->enabled) {
                fb_fill(fb, x + 2, by + 2, CHECK_W - 4, CHECK_H - 3,
                        C_BTNFACE);
                if (on ? on[i] : z->on)
                    paint_tick_col(fb, x, by, C_BTNSHADOW);
            }
            if ((z->h - CHECK_W) / 2 + CHECK_H < z->h)
                fb_hline(fb, x, y + (z->h - CHECK_W) / 2 + CHECK_H, CHECK_W,
                         C_BTNHILIGHT);
            zs_text(fb, x + CHECK_W + 3, y + (z->h - th) / 2,
                    z->w - CHECK_W - 3, z->text, col);
            break;
        }
        case JW_KH_EDIT:
            mj_sunken(fb, x, y, z->w, z->h);
            break;
        case JW_KH_STATIC:
            zs_text(fb, x, y + (z->h - th) / 2, z->w, z->text, col);
            break;
        default:
            break;
        }
    }
}

int ui_kihon_hit(int cw, int ch, int x, int y)
{
    rect_t r;
    int i;

    ui_kihon_rect(cw, ch, &r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return -1;                      /* outside it: the dialog is modal */
    x -= r.x + JW_KH_BORDER;
    y -= r.y + JW_KH_CAPTION;
    for (i = 0; i < JW_NKIHON; i++) {
        const jw_kh_t *z = &jw_kihon[i];

        if (z->kind == JW_KH_STATIC || !z->shown || !z->enabled)
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
            if (jw_bars[i].cmd == 100000u + (unsigned)cmd) {
                *c = jw_bars[i].c;
                return jw_bars[i].n;
            }
    for (i = 0; i < JW_NBARS; i++)
        if (jw_bars[i].cmd == (unsigned)cmd) {
            *c = jw_bars[i].c;
            return jw_bars[i].n;
        }
    *c = jw_bar_32771;
    return (int)(sizeof jw_bar_32771 / sizeof jw_bar_32771[0]);
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
        if ((c[i].kind == JW_CTL_BUTTON || c[i].kind == JW_CTL_COMBO)
            && x >= c[i].x && x < c[i].x + c[i].w
            && y >= c[i].y && y < c[i].y + c[i].h)
            return c[i].id;
    return 0;
}

static void paint_bar(fb_t *fb, const jw_drawing *d)
{
    const jw_ctl_t *c = jw_bar_32771;
    int n = (int)(sizeof jw_bar_32771 / sizeof jw_bar_32771[0]);
    int cmd = jw_cmd(), i;
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
            if (cmd == JW_CMD_SEN && c[i].x == 71)
                on = jw_cmd_hv();
            else if (jw_cmd_bar_check(c[i].id) >= 0)
                on = jw_cmd_bar_check(c[i].id);
            paint_checkbox(fb, c[i].x, c[i].y, on);
            jw_text_px(fb, c[i].x + CHECK_W + 3, c[i].y + (c[i].h - th) / 2,
                       c[i].text, en ? C_BTNTEXT : C_GRAYTEXT);
            break;
        case JW_CTL_BUTTON:
            paint_barbutton(fb, c[i].x, c[i].y, c[i].w, c[i].h);
            jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                       c[i].text, en ? C_BTNTEXT : C_GRAYTEXT);
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
    paint_samples(fb);
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
