#include <stdlib.h>
#include <string.h>

#include "fb.h"
#include "theme.h"
#include "gen/jwres.h"

int fb_init(fb_t *fb, int w, int h)
{
    fb->w = w;
    fb->h = h;
    fb->px = (unsigned int *)calloc((size_t)w * h, sizeof(unsigned int));
    return fb->px != 0;
}

void fb_free(fb_t *fb)
{
    free(fb->px);
    fb->px = 0;
    fb->w = fb->h = 0;
}

void fb_fill(fb_t *fb, int x, int y, int w, int h, unsigned int c)
{
    int i, j;

    if (x < 0) { w += x; x = 0; }
    if (y < 0) { h += y; y = 0; }
    if (x + w > fb->w) w = fb->w - x;
    if (y + h > fb->h) h = fb->h - y;
    for (j = 0; j < h; j++) {
        unsigned int *p = fb->px + (size_t)(y + j) * fb->w + x;
        for (i = 0; i < w; i++)
            p[i] = c;
    }
}

void fb_hline(fb_t *fb, int x, int y, int n, unsigned int c)
{
    fb_fill(fb, x, y, n, 1, c);
}

void fb_vline(fb_t *fb, int x, int y, int n, unsigned int c)
{
    fb_fill(fb, x, y, 1, n, c);
}

void fb_edge(fb_t *fb, int x, int y, int w, int h,
             unsigned int tl, unsigned int br)
{
    if (w <= 0 || h <= 0)
        return;
    fb_hline(fb, x, y, w - 1, tl);
    fb_vline(fb, x, y, h - 1, tl);
    fb_hline(fb, x, y + h - 1, w, br);
    fb_vline(fb, x + w - 1, y, h, br);
}

/* MFC's AfxLoadSysColorBitmap swaps the four "system" colours of a toolbar
 * bitmap for the current scheme as it loads it.  The art is authored against
 * the old 16-colour palette, so 192,192,192 is the button face and not a real
 * grey.  Anything else is left alone -- the blue labels depend on that. */
static unsigned int remap(unsigned int rgb)
{
    switch (rgb) {
    case 0x000000u: return C_BTNTEXT;
    case 0x808080u: return C_BTNSHADOW;
    case 0xc0c0c0u: return C_BTNFACE;
    case 0xffffffu: return C_BTNHILIGHT;
    default:        return rgb;
    }
}

void fb_blit_cell(fb_t *fb, const struct jw_bitmap *bmp, int cell, int cw,
                  int x, int y)
{
    fb_blit_cell_ex(fb, bmp, cell, cw, x, y, 0);
}

/* transparent: leave the face colour alone, so whatever is underneath shows
 * through.  A pressed toolbar button needs that -- its checkerboard is drawn
 * first and the image sits on top of it. */
void fb_blit_cell_ex(fb_t *fb, const struct jw_bitmap *bmp, int cell, int cw,
                     int x, int y, int transparent)
{
    const jw_bitmap_t *bm = (const jw_bitmap_t *)bmp;
    int i, j, sx;

    if (!bm)
        return;
    sx = cell * cw;
    for (j = 0; j < bm->h; j++) {
        int dy = y + j;
        if (dy < 0 || dy >= fb->h)
            continue;
        for (i = 0; i < cw; i++) {
            int dx = x + i;
            int n;
            const unsigned char *p;
            if (dx < 0 || dx >= fb->w || sx + i >= bm->w)
                continue;
            n = bm->idx[(size_t)j * bm->w + sx + i];
            p = bm->pal + 3 * n;
            {
                unsigned int c =
                    ((unsigned)p[0] << 16) | ((unsigned)p[1] << 8) | p[2];
                if (transparent && c == 0xc0c0c0u)
                    continue;
                fb->px[(size_t)dy * fb->w + dx] = remap(c);
            }
        }
    }
}
