#include <stddef.h>

#include "ui.h"
#include "theme.h"
#include "gen/jwres.h"
#include "gen/layout.h"
#include "gen/bars.h"
#include "gen/cmds.h"
#include "cmd.h"
#include "text.h"

#include <stdio.h>

/* The window is a stack of docked bars round the drawing area.  Each bar
 * paints its face and, where it meets another, a two-pixel border: a shadow
 * line on the outside and a highlight just inside it -- what MFC's
 * CControlBar::DrawBorders does.
 *
 * The rectangles below were measured off docs/ref_start.png (client
 * 1264x741).  They are fixed sizes: resizing the window grows the drawing
 * area, not the bars.  Which bar is which, and why they are split the way
 * they are, is still to be read out of CMainFrame::OnCreate -- see RESUME.md.
 */
#define B_TOP   1
#define B_LEFT  2

typedef struct {
    short x, y, w, h;
    unsigned int face;
    unsigned char borders;
} bar_t;

static const bar_t bars[] = {
    /* the command bar across the top, and the empty white strip beside it */
    {    0,   0,  829,  32, C_BTNFACE, B_TOP },
    {  829,   0,  435,  32, C_WINDOW,  B_TOP | B_LEFT },

    /* left side: two columns of buttons in three bands */
    {    0,  32,   37, 227, C_BTNFACE, B_TOP },
    {   37,  32,   39, 227, C_BTNFACE, B_TOP | B_LEFT },
    {    0, 259,   37, 227, C_BTNFACE, B_TOP },
    {   37, 259,   39, 227, C_BTNFACE, B_TOP | B_LEFT },
    {    0, 486,   37, 129, C_BTNFACE, B_TOP },
    {   37, 486,   39,  32, C_WINDOW,  B_TOP | B_LEFT },  /* line-type sample */
    {   37, 518,   39,  14, C_WINDOW,  B_TOP | B_LEFT },
    {   37, 532,   39,  80, C_BTNFACE, B_TOP | B_LEFT },
    {   37, 612,   39,   4, C_WINDOW,  B_TOP | B_LEFT },
    {    0, 615,   39, 105, C_WINDOW,  B_TOP },
    {   39, 616,   37, 104, C_WINDOW,  0 },

    /* right side: the same idea, plus the layer grid low down */
    { 1188,  32,   37, 227, C_BTNFACE, B_TOP },
    { 1225,  32,   39, 227, C_BTNFACE, B_TOP | B_LEFT },
    { 1188, 259,   37,  80, C_BTNFACE, B_TOP },
    { 1225, 259,   39, 129, C_BTNFACE, B_TOP | B_LEFT },
    { 1188, 339,   37,  32, C_WINDOW,  B_TOP },
    { 1188, 371,   37,  14, C_WINDOW,  B_TOP },
    { 1188, 385,   37, 231, C_WINDOW,  B_TOP },
    { 1225, 388,   39, 228, C_WINDOW,  B_TOP | B_LEFT },
    { 1188, 612,   37, 108, C_WINDOW,  B_TOP },
    { 1225, 615,   39, 105, C_WINDOW,  B_TOP },

    /* the status line */
    {    0, 720, 1264,  21, C_BTNFACE, B_TOP },
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

static void paint_bars(fb_t *fb)
{
    int k;

    for (k = 0; k < NBARS; k++) {
        const bar_t *b = &bars[k];
        int x = b->x, y = b->y, w = b->w, h = b->h;

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
                int x = layer_grids[g].x + col * LAYER_CELL_W;
                int y = layer_grids[g].y + row * LAYER_CELL_H;

                blit_layer_cell(fb, (col == 0 && row == 0) ? 2652 : 2662,
                                x, y, layer_grids[g].clip);
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
        int x = samples[k].x, y = samples[k].y;

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
    int wg = 0, i;

    /* The prompt is the command's own, out of the string table. */
    jw_text_px(fb, 8, 726, jw_cmd_prompt(), C_BTNTEXT);
    if (!d)
        return;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    jw_text_px(fb, panes[0].x0 + 4, 726,
               d->paper_size >= 0 && d->paper_size < 15
               ? PAPER[d->paper_size] : "?", C_BTNTEXT);
    sprintf(buf, "S=1/%g", d->group[wg].scale);
    jw_text_px(fb, panes[1].x0 + 4, 726, buf, C_BTNTEXT);
    sprintf(buf, "[%X-%X]", wg, d->group[wg].write_layer & 15);
    jw_text_px(fb, panes[2].x0 + 4, 726, buf, C_BTNTEXT);
    jw_text_px(fb, panes[3].x0 + 4, 726, "\x81\xda 0", C_BTNTEXT);
    /* two decimals, cut not rounded, and a trailing zero dropped: the
       original shows 0.21, 0.3, 0.42 and 0.1 for the four sheet sizes */
    sprintf(buf, "\x81\x7e %g", (double)(long)(zoom * 100.0 + 1e-9) / 100.0);
    jw_text_px(fb, panes[4].x0 + 4, 726, buf, C_BTNTEXT);
}

static void paint_status(fb_t *fb)
{
    int k, i, j;
    int bottom = fb->h - 1;

    for (k = 0; k < 5; k++)
        fb_edge(fb, panes[k].x0, PANE_T, panes[k].x1 - panes[k].x0 + 1,
                bottom - PANE_T + 1, C_BTNHILIGHT, C_BTNSHADOW);

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
static void paint_tick(fb_t *fb, int x, int y)
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
                fb_fill(fb, x + c, y + 3 + r, 1, 1, C_BTNTEXT);
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
        }
    }
}

/* The bar for the command in force.  Which controls each one has, and where
 * they sit, was read out of the running original -- see tools/mkbars.py. */
static void paint_bar(fb_t *fb)
{
    const jw_ctl_t *c = jw_bar_32771;
    int n = (int)(sizeof jw_bar_32771 / sizeof jw_bar_32771[0]);
    int cmd = jw_cmd(), i;
    /* the labels are centred in their control the way Windows centres them;
       the port's glyphs are taller than the original's, and without this the
       bottom rows of them fall outside the bar's text area */
    int th = jw_text_height();

    for (i = 0; i < JW_NBARS; i++)
        if (jw_bars[i].cmd == cmd) {
            c = jw_bars[i].c;
            n = jw_bars[i].n;
            break;
        }
    for (i = 0; i < n; i++) {
        int on = 0;
        switch (c[i].kind) {
        case JW_CTL_CHECK:
            /* how the original has it on entering the command, read out
               with BM_GETCHECK, and then whatever the port itself changes */
            on = c[i].checked;
            if (cmd == JW_CMD_SEN && c[i].x == 71)
                on = jw_cmd_hv();
            paint_checkbox(fb, c[i].x, c[i].y, on);
            jw_text_px(fb, c[i].x + CHECK_W + 3, c[i].y + (c[i].h - th) / 2,
                       c[i].text, c[i].enabled ? C_BTNTEXT : C_GRAYTEXT);
            break;
        case JW_CTL_BUTTON:
            paint_barbutton(fb, c[i].x, c[i].y, c[i].w, c[i].h);
            jw_text_px(fb, c[i].x + 5, c[i].y + (c[i].h - th) / 2,
                       c[i].text, c[i].enabled ? C_BTNTEXT : C_GRAYTEXT);
            break;
        case JW_CTL_STATIC:
            jw_text_px(fb, c[i].x, c[i].y + (c[i].h - th) / 2, c[i].text,
                       c[i].enabled ? C_BTNTEXT : C_GRAYTEXT);
            break;
        case JW_CTL_COMBO:
            paint_combo(fb, c[i].x, c[i].y, c[i].w, c[i].h);
            break;
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
        int dx, dy;

        dx = CELL_DX + (state == 2);
        dy = CELL_DY + (state == 2);

        button_frame(fb, b->x, b->y, BTN_W, BTN_H, state == 2);
        if (state == 2)
            checker(fb, b->x + 2, b->y + 2, BTN_W - 4, BTN_H - 4);
        else
            fb_fill(fb, b->x + 2, b->y + 2, BTN_W - 4, BTN_H - 4, C_BTNFACE);
        blit_cell_state(fb, bm, b->cell, b->x + dx, b->y + dy, state);
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

    paint_bar(fb);
    paint_layer_grids(fb, d);
    paint_samples(fb);
    paint_status(fb);
    status_text(fb, d, zoom);
    paint_buttons(fb, saveable, undoable);

    {
        int k;
        for (k = 0; k < 4; k++) {
            int x = small_buttons[k].x, y = small_buttons[k].y;
            button_frame(fb, x, y, SMALL_W, SMALL_H, 0);
            fb_fill(fb, x + 2, y + 2, SMALL_W - 4, SMALL_H - 4, C_BTNFACE);
        }
    }
}
