#include <stddef.h>

#include "ui.h"
#include "theme.h"
#include "gen/jwres.h"
#include "gen/layout.h"

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
    { 1188, 616,   76, 104, C_WINDOW,  0 },

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
        fb_blit_cell(fb, (const struct jw_bitmap *)bm, cell, CELL_W, x, y);
        return;
    }
    /* Disabled: the ink once in highlight offset by one, then in shadow on
     * top.  0xc0c0c0 is the face the art is drawn against, not ink. */
    for (j = 0; j < CELL_H; j++)
        for (i = 0; i < CELL_W; i++)
            if (cellpx(bm, cell, i, j) != 0xc0c0c0u
                && i + 1 < CELL_W && j + 1 < CELL_H)
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

static void blit_layer_cell(fb_t *fb, int id, int x, int y)
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
            if (x + i < 0 || x + i >= fb->w)
                continue;
            p = bm->pal + 3 * bm->idx[(size_t)j * bm->w + i];
            c = ((unsigned)p[0] << 16) | ((unsigned)p[1] << 8) | p[2];
            if (c == 0xc0c0c0u)
                c = C_BTNFACE;
            fb->px[(size_t)(y + j) * fb->w + x + i] = c;
        }
    }
}

/* Where the two grids sit, measured off the reference screen. */
static const struct { short x, y; } layer_grids[2] = {
    { 1188, 394 },      /* layer groups, circled digits   */
    { 1227, 397 },      /* layers, plain digits           */
};

static void paint_layer_grids(fb_t *fb)
{
    int g, col, row;

    for (g = 0; g < 2; g++) {
        for (col = 0; col < 2; col++) {
            for (row = 0; row < 8; row++) {
                int x = layer_grids[g].x + col * LAYER_CELL_W;
                int y = layer_grids[g].y + row * LAYER_CELL_H;
                int first = (col == 0 && row == 0);
                blit_layer_cell(fb, first ? 2652 : 2662, x, y);
            }
        }
    }
}

static void paint_buttons(fb_t *fb)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++) {
        const jw_btn_t *b = &jw_buttons[k];
        const jw_bitmap_t *bm = jw_bitmap(b->strip);
        int dx = CELL_DX + (b->state == 2);
        int dy = CELL_DY + (b->state == 2);

        button_frame(fb, b->x, b->y, BTN_W, BTN_H, b->state == 2);
        if (b->state == 2)
            checker(fb, b->x + 2, b->y + 2, BTN_W - 4, BTN_H - 4);
        else
            fb_fill(fb, b->x + 2, b->y + 2, BTN_W - 4, BTN_H - 4, C_BTNFACE);
        blit_cell_state(fb, bm, b->cell, b->x + dx, b->y + dy, b->state);
    }
}

void ui_paint(fb_t *fb)
{
    rect_t v;

    fb_fill(fb, 0, 0, fb->w, fb->h, C_BTNFACE);
    paint_bars(fb);

    ui_view_rect(fb->w, fb->h, &v);
    /* EDGE_SUNKEN round the drawing area */
    fb_edge(fb, v.x - 2, v.y - 2, v.w + 4, v.h + 4, C_BTNSHADOW, C_BTNHILIGHT);
    fb_edge(fb, v.x - 1, v.y - 1, v.w + 2, v.h + 2, C_3DDKSHADOW, C_3DLIGHT);
    fb_fill(fb, v.x, v.y, v.w, v.h, C_WINDOW);

    paint_layer_grids(fb);
    paint_buttons(fb);
}
