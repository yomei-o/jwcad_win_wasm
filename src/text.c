#include <math.h>
#include <stddef.h>

#include "text.h"
#include "fontx.h"
#include "gen/jwfont.h"

static fontx_t ank, kanji;
/* The frame's own font.  The original draws it with the dialog font, MS P
   Gothic at 9 point, whose cell is 12 pixels tall; drawing the toolbars with
   the 16 pixel one made the labels wider than their buttons. */
static fontx_t ank12, kanji12;
static int fonts_ready;

static void want_fonts(void)
{
    if (fonts_ready)
        return;
    fontx_open(&ank, jw_font_ank, jw_font_ank_len);
    fontx_open(&kanji, jw_font_kanji, jw_font_kanji_len);
    fontx_open(&ank12, jw_font_ank12, jw_font_ank12_len);
    fontx_open(&kanji12, jw_font_kanji12, jw_font_kanji12_len);
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
    /* jw_px_round, not a bare cast: a damaged file may give a text style a
       character 1e12 millimetres across, and the cast is undefined when the
       value will not fit.  See src/view.h. */
    nx = jw_px_round(cw / v->mmpp + 0.5);
    ny = jw_px_round(ch / v->mmpp + 0.5);
    if (nx < 1) nx = 1;
    if (ny < 1) ny = 1;
    /* One sample a screen pixel is all it takes to leave no gaps, so a cell
       wider than the whole framebuffer needs no more steps than that.  A
       damaged file can ask for a character 1e12 millimetres across, and
       without this the two loops below run for the rest of the day. */
    if (nx > fb->w + fb->h) nx = fb->w + fb->h;
    if (ny > fb->w + fb->h) ny = fb->w + fb->h;
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

int jw_is_lead(unsigned char c)
{
    return is_lead(c);
}

int jw_text_height(void)
{
    want_fonts();
    return ank12.height;
}

/* The same walk as jw_text_px, with nothing drawn: the menu has to know how
   wide a popup must be before it has anywhere to draw it. */
int jw_text_px_w(const char *s)
{
    const unsigned char *p = (const unsigned char *)s;
    int w = 0;

    want_fonts();
    while (*p) {
        if (is_lead(p[0]) && p[1]) {
            w += kanji12.width;
            p += 2;
        } else {
            w += ank12.width;
            p += 1;
        }
    }
    return w;
}

int jw_text_px(fb_t *fb, int x, int y, const char *s, unsigned int col)
{
    const unsigned char *p = (const unsigned char *)s;

    want_fonts();
    while (*p) {
        unsigned code = p[0];
        const fontx_t *f = &ank12;
        const unsigned char *g;
        int stride, i, j;

        if (is_lead(p[0]) && p[1]) {
            code = ((unsigned)p[0] << 8) | p[1];
            f = &kanji12;
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

/* 縦書き -- bit 0x20 of the flags at +0x44.  The two ends the file gives
 * still say where the run goes (the two in `天空率表` have x0 == x1 and run
 * straight down), so the advance is unchanged; what changes is that the
 * letters stay **upright** instead of turning with the run.  That is what
 * 縦書き means, and it is why the original writes those texts under `cv`
 * rather than `ch` in a coordinate file (docs/notes-formats.md).
 *
 * Nothing in the score can see this: the mask tests/shot.c lays over a text
 * is the box round its two ends widened by a letter's height, which covers
 * the column either way.  So this is read rather than measured, and the two
 * texts it touches are the only ones in the sixteen drawings. */
void jw_text_run(fb_t *fb, const jw_view *v, const char *s,
                 double x0, double y0, double x1, double y1,
                 double cw, double ch, unsigned int col, int tate)
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
              tate ? 1.0 : ux, tate ? 0.0 : uy,
              tate ? 0.0 : vx, tate ? 1.0 : vy, cw, ch, col);
    }
}

void jw_text(fb_t *fb, const jw_view *v, const char *s,
             double x0, double y0, double x1, double y1,
             double cw, double ch, unsigned int col)
{
    jw_text_run(fb, v, s, x0, y0, x1, y1, cw, ch, col, 0);
}
