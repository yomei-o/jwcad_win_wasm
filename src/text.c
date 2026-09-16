#include <math.h>
#include <stddef.h>

#include "text.h"
#include "fontx.h"
#include "gen/jwfont.h"

static fontx_t ank, kanji;
static int fonts_ready;

static void want_fonts(void)
{
    if (fonts_ready)
        return;
    fontx_open(&ank, jw_font_ank, jw_font_ank_len);
    fontx_open(&kanji, jw_font_kanji, jw_font_kanji_len);
    fonts_ready = 1;
}

static int is_lead(unsigned char c)
{
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc);
}

/* How many characters, counting a Shift-JIS pair as one. */
int jw_text_count(const char *s)
{
    int n = 0;

    while (*s) {
        if (is_lead((unsigned char)s[0]) && s[1])
            s += 2;
        else
            s += 1;
        n++;
    }
    return n;
}

/* One glyph, scaled to fit the cell, into the parallelogram the baseline
 * direction defines.  Nearest neighbour: the font is 16 pixels tall and the
 * text on screen is anywhere from 4 to 60, so there is nothing to interpolate
 * that would not just blur it. */
static void glyph(fb_t *fb, const jw_view *v, unsigned code,
                  double ox, double oy, double ux, double uy,
                  double vx, double vy, double cw, double ch,
                  unsigned int col)
{
    const fontx_t *f = code > 0xff ? &kanji : &ank;
    const unsigned char *g = fontx_glyph(f, code);
    int stride, gx, gy, nx, ny, i, j;

    if (!g)
        return;
    stride = (f->width + 7) / 8;
    /* one screen pixel per step, so nothing is skipped when scaling up */
    nx = (int)(cw * v->scale + 0.5);
    ny = (int)(ch * v->scale + 0.5);
    if (nx < 1) nx = 1;
    if (ny < 1) ny = 1;
    for (j = 0; j < ny; j++) {
        gy = f->height - 1 - j * f->height / ny;
        for (i = 0; i < nx; i++) {
            double px, py;
            int sx, sy;
            gx = i * f->width / nx;
            if (!(g[gy * stride + (gx >> 3)] & (0x80 >> (gx & 7))))
                continue;
            px = ox + ux * (cw * i / nx) + vx * (ch * j / ny);
            py = oy + uy * (cw * i / nx) + vy * (ch * j / ny);
            sx = jw_sx(v, px);
            sy = jw_sy(v, py);
            if (sx >= v->clip.x && sx < v->clip.x + v->clip.w
                && sy >= v->clip.y && sy < v->clip.y + v->clip.h)
                fb->px[(size_t)sy * fb->w + sx] = col;
        }
    }
}

int jw_text_height(void)
{
    want_fonts();
    return ank.height;
}

int jw_text_px(fb_t *fb, int x, int y, const char *s, unsigned int col)
{
    const unsigned char *p = (const unsigned char *)s;

    want_fonts();
    while (*p) {
        unsigned code = p[0];
        const fontx_t *f = &ank;
        const unsigned char *g;
        int stride, i, j;

        if (is_lead(p[0]) && p[1]) {
            code = ((unsigned)p[0] << 8) | p[1];
            f = &kanji;
            p += 2;
        } else {
            p += 1;
        }
        g = fontx_glyph(f, code);
        if (g) {
            stride = (f->width + 7) / 8;
            for (j = 0; j < f->height; j++)
                for (i = 0; i < f->width; i++)
                    if ((g[j * stride + (i >> 3)] & (0x80 >> (i & 7)))
                        && x + i >= 0 && x + i < fb->w
                        && y + j >= 0 && y + j < fb->h)
                        fb->px[(size_t)(y + j) * fb->w + x + i] = col;
        }
        x += f->width;
    }
    return x;
}

void jw_text(fb_t *fb, const jw_view *v, const char *s,
             double x0, double y0, double x1, double y1,
             double cw, double ch, unsigned int col)
{
    double dx = x1 - x0, dy = y1 - y0;
    double len = sqrt(dx * dx + dy * dy);
    double ux, uy, vx, vy, step;
    int n = jw_text_count(s), i;
    const unsigned char *p = (const unsigned char *)s;

    want_fonts();
    if (!n || ch <= 0.0)
        return;
    if (len < 1e-9) {
        ux = 1.0;
        uy = 0.0;
        len = n * cw;
    } else {
        ux = dx / len;
        uy = dy / len;
    }
    vx = -uy;
    vy = ux;
    /* The file gives the run's two ends, so the advance follows from them:
     * the last character's left edge is len - cw away from the first.  That
     * is also how the character spacing gets in without being stored. */
    step = n > 1 ? (len - cw) / (n - 1) : 0.0;

    for (i = 0; i < n; i++) {
        unsigned code = p[0];
        if (is_lead(p[0]) && p[1]) {
            code = ((unsigned)p[0] << 8) | p[1];
            p += 2;
        } else {
            p += 1;
        }
        glyph(fb, v, code, x0 + ux * step * i, y0 + uy * step * i,
              ux, uy, vx, vy, cw, ch, col);
    }
}
