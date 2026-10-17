#include <math.h>
#include <stddef.h>

#include "text.h"
#include "fontx.h"
#include "outfont.h"
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
 * that would not just blur it.
 *
 * `lean` slants it (斜体): a dot `h` above the baseline moves h * lean along
 * the run, the baseline being 2 of the font's 16 rows up.  `bold` (mm,
 * 太字) draws it again that far along the run, a pixel a step. */
static void glyph(fb_t *fb, const jw_view *v, unsigned code,
                  double ox, double oy, double ux, double uy,
                  double vx, double vy, double cw, double ch,
                  unsigned int col, double lean, double bold)
{
    const fontx_t *f = code > 0xff ? &kanji : &ank;
    const unsigned char *g = fontx_glyph(f, code);
    int stride, gx, gy, nx, ny, i, j, b, nb = 0;
    double pv = ch * 2.0 / 16.0;

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
    if (bold > 0.0) {                   /* that many more samples across */
        nb = jw_px_round(bold * nx / cw + 0.5);
        if (nb < 1) nb = 1;
        if (nb > nx) nb = nx;
    }
    /* And a cell that lies wholly off the window is not sampled at all.
       Every sample is inside the parallelogram the cell's four corners make,
       so if their screen box -- a pixel wider all round, for the rounding --
       misses the clip, so does every sample.  Without this, zooming in made
       each character of the drawing cost up to (w + h)^2 samples whether it
       was on the window or not: Test7 at 256 times took ten seconds a paint,
       and 0.045 with its texts taken out. */
    {
        double cx[4], cy[4], lo = -fabs(lean) * pv;
        double hi = cw + (nb ? bold : 0.0) + fabs(lean) * ch;
        int c, x0, x1, y0, y1;

        cx[0] = ox + ux * lo;            cy[0] = oy + uy * lo;
        cx[1] = ox + ux * hi;            cy[1] = oy + uy * hi;
        cx[2] = ox + ux * lo + vx * ch;  cy[2] = oy + uy * lo + vy * ch;
        cx[3] = ox + ux * hi + vx * ch;  cy[3] = oy + uy * hi + vy * ch;
        x0 = x1 = jw_sx(v, cx[0]);
        y0 = y1 = jw_sy(v, cy[0]);
        for (c = 1; c < 4; c++) {
            int sx = jw_sx(v, cx[c]), sy = jw_sy(v, cy[c]);

            if (sx < x0) x0 = sx;
            if (sx > x1) x1 = sx;
            if (sy < y0) y0 = sy;
            if (sy > y1) y1 = sy;
        }
        if (x1 + 2 < v->clip.x || x0 - 2 >= v->clip.x + v->clip.w
            || y1 + 2 < v->clip.y || y0 - 2 >= v->clip.y + v->clip.h)
            return;
    }
    for (j = 0; j < ny; j++) {
        gy = f->height - 1 - j * f->height / ny;
        for (i = 0; i < nx + nb; i++) {
            double px, py, u = cw * i / nx;
            int sx, sy, on = 0;

            /* 太字: on if any of the nb samples to its left is */
            for (b = i < nx ? 0 : i - nx + 1; b <= nb && b <= i; b++) {
                gx = (i - b) * f->width / nx;
                if (g[gy * stride + (gx >> 3)] & (0x80 >> (gx & 7))) {
                    on = 1;
                    break;
                }
            }
            if (!on)
                continue;
            if (lean != 0.0)
                u += lean * (ch * j / ny - pv);
            px = ox + ux * u + vx * (ch * j / ny);
            py = oy + uy * u + vy * (ch * j / ny);
            sx = jw_sx(v, px);
            sy = jw_sy(v, py);
            if (sx >= v->clip.x && sx < v->clip.x + v->clip.w
                && sy >= v->clip.y && sy < v->clip.y + v->clip.h)
                fb->px[(size_t)sy * fb->w + sx] =
                    jw_rop(fb->px[(size_t)sy * fb->w + sx], col);
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

/* 丸数字 ①〜⑳ (CP932 0x8740..0x8753)。NEC 特殊文字の 13 区で、東雲
 * （JIS X 0208）には無いので何も描かれていなかった —— 線属性の
 * 「①〜⑤キー:ランダム線　⑥〜⑨キー:倍長線種」が「〜 キー:…」に
 * なっていた。原典（ＭＳ Ｐゴシック 9pt）の ⑤ を写しから読むと、
 * 11×11 の円の中に 5×7 の数字が (3,2) から入っている。二桁は 3×5 を
 * 二つ並べる（写しに二桁は無いので、これは移植の作）。 */
static const unsigned short circ11[11] = {
    0x070, 0x18c, 0x202, 0x202, 0x401, 0x401, 0x401, 0x202, 0x202,
    0x18c, 0x070,
};
static const unsigned char dig57[10][7] = {
    { 0x0e, 0x11, 0x13, 0x15, 0x19, 0x11, 0x0e },     /* 0 */
    { 0x04, 0x0c, 0x04, 0x04, 0x04, 0x04, 0x04 },     /* 1 */
    { 0x0e, 0x11, 0x01, 0x02, 0x04, 0x08, 0x1f },     /* 2 */
    { 0x1f, 0x02, 0x04, 0x02, 0x01, 0x11, 0x0e },     /* 3 */
    { 0x02, 0x06, 0x0a, 0x12, 0x1f, 0x02, 0x02 },     /* 4 */
    { 0x1f, 0x10, 0x10, 0x1e, 0x01, 0x11, 0x0e },     /* 5 */
    { 0x06, 0x08, 0x10, 0x1e, 0x11, 0x11, 0x0e },     /* 6 */
    { 0x1f, 0x01, 0x02, 0x04, 0x04, 0x04, 0x04 },     /* 7 */
    { 0x0e, 0x11, 0x11, 0x0e, 0x11, 0x11, 0x0e },     /* 8 */
    { 0x0e, 0x11, 0x11, 0x0f, 0x01, 0x02, 0x0c },     /* 9 */
};
static const unsigned char dig35[10][5] = {
    { 7, 5, 5, 5, 7 }, { 2, 6, 2, 2, 7 }, { 7, 1, 7, 4, 7 }, { 7, 1, 3, 1, 7 },
    { 5, 5, 7, 1, 1 }, { 7, 4, 7, 1, 7 }, { 7, 4, 7, 5, 7 }, { 7, 1, 1, 2, 2 },
    { 7, 5, 7, 5, 7 }, { 7, 5, 7, 1, 7 },
};

static void dot(fb_t *fb, int x, int y, unsigned int col)
{
    if (fb && x >= 0 && x < fb->w && y >= 0 && y < fb->h)
        fb->px[(size_t)y * fb->w + x] = col;
}

/* 丸数字なら描いて（fb が NULL なら描かずに）1 を返す */
static int circled(fb_t *fb, int x, int y, unsigned code, unsigned int col)
{
    int n, i, j;

    if (code < 0x8740 || code > 0x8753)
        return 0;
    n = (int)(code - 0x8740) + 1;
    for (j = 0; j < 11; j++)
        for (i = 0; i < 11; i++)
            if (circ11[j] & (0x400 >> i))
                dot(fb, x + i, y + j, col);
    if (n < 10) {
        for (j = 0; j < 7; j++)
            for (i = 0; i < 5; i++)
                if (dig57[n][j] & (0x10 >> i))
                    dot(fb, x + 3 + i, y + 2 + j, col);
    } else {
        int k;
        for (k = 0; k < 2; k++) {
            int d = k ? n % 10 : n / 10;
            for (j = 0; j < 5; j++)
                for (i = 0; i < 3; i++)
                    if (dig35[d][j] & (4 >> i))
                        dot(fb, x + 2 + k * 4 + i, y + 3 + j, col);
        }
    }
    return 1;
}

/* One run of the frame font.  `room` < 0: every character a whole cell, as
 * the font has it.  `room` >= 0: the run has to go into that many pixels --
 * the original's dialog font is proportional (ＭＳ Ｐゴシック), the port's
 * is not, and a label the original fits into its control came out of the
 * port a few pixels too wide and lost its last characters (「フォント」
 * 「〔1〕」「(，)をスペース」...).  So when the whole cells will not go in,
 * each character is set as narrow as its ink, a pixel apart, the way a
 * proportional face would; what still does not fit is left off. */
static int text_run(fb_t *fb, int x, int y, const char *s, unsigned int col,
                    int room)
{
    const unsigned char *p = (const unsigned char *)s;
    int x0 = x;

    want_fonts();
    while (*p) {
        unsigned code = p[0];
        const fontx_t *f = &ank12;
        const unsigned char *g;
        int stride, i, j, l = 0, adv;

        if (is_lead(p[0]) && p[1]) {
            code = ((unsigned)p[0] << 8) | p[1];
            f = &kanji12;
            p += 2;
        } else {
            p += 1;
        }
        g = fontx_glyph(f, code);
        stride = (f->width + 7) / 8;
        adv = f->width;
        if (room >= 0) {
            int r = -1;
            l = f->width;
            if (g) {
                for (j = 0; j < f->height; j++)
                    for (i = 0; i < f->width; i++)
                        if (g[j * stride + (i >> 3)] & (0x80 >> (i & 7))) {
                            if (i < l) l = i;
                            if (i > r) r = i;
                        }
            } else if (code >= 0x8740 && code <= 0x8753) {
                l = 0;
                r = 10;
            }
            if (r < 0) {                /* a space */
                l = 0;
                adv = f->width / 2;
            } else {
                adv = r - l + 2;
            }
            if (x + adv - 1 - x0 > room)
                break;
        }
        if (g) {
            if (fb)
                for (j = 0; j < f->height; j++)
                    for (i = l; i < f->width; i++)
                        if (g[j * stride + (i >> 3)] & (0x80 >> (i & 7)))
                            dot(fb, x + i - l, y + j, col);
        } else if (f == &kanji12) {
            circled(fb, x - l, y, code, col);
        }
        x += adv;
    }
    return x;
}

int jw_text_px(fb_t *fb, int x, int y, const char *s, unsigned int col)
{
    return text_run(fb, x, y, s, col, -1);
}

/* How wide `s` is without the blanks at its end -- a label padded with
   spaces still fits as it is if its letters do. */
static int inked_w(const char *s)
{
    const unsigned char *p = (const unsigned char *)s;
    int w = 0, upto = 0;

    want_fonts();
    while (*p) {
        int sp;
        if (is_lead(p[0]) && p[1]) {
            sp = p[0] == 0x81 && p[1] == 0x40;
            w += kanji12.width;
            p += 2;
        } else {
            sp = p[0] == ' ';
            w += ank12.width;
            p += 1;
        }
        if (!sp)
            upto = w;
    }
    return upto;
}

int jw_text_px_fit(fb_t *fb, int x, int y, const char *s, unsigned int col,
                   int w)
{
    if (inked_w(s) <= w)
        return text_run(fb, x, y, s, col, -1);
    return text_run(fb, x, y, s, col, w < 0 ? 0 : w);
}

int jw_text_px_fit_w(const char *s, int w)
{
    if (inked_w(s) <= w)
        return jw_text_px_w(s);     /* as before: centred on the whole cells */
    return text_run(0, 0, 0, s, 0, w < 0 ? 0 : w);
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
void jw_text_run_face(fb_t *fb, const jw_view *v, const char *s,
                      double x0, double y0, double x1, double y1,
                      double cw, double ch, unsigned int col, int tate,
                      const char *face, int style)
{
    /* A face of ours is drawn from its outline once that has arrived; the
       original's own faces, and ours while the file is still on its way,
       are the bitmap font as they always were. */
    int prop, of = jw_outfont_resolve(face, &prop);

    if (of >= 0 && jw_outfont_run(fb, v, of, s, x0, y0, x1, y1, cw, ch, col,
                                  tate, style, prop))
        return;
    jw_text_run_style(fb, v, s, x0, y0, x1, y1, cw, ch, col, tate, style);
}

void jw_text_run(fb_t *fb, const jw_view *v, const char *s,
                 double x0, double y0, double x1, double y1,
                 double cw, double ch, unsigned int col, int tate)
{
    jw_text_run_style(fb, v, s, x0, y0, x1, y1, cw, ch, col, tate, 0);
}

/* 斜体 and 太字 in the bitmap font lean and thicken the way the outline
   ones do (JW_TEXT_ITALIC, JW_TEXT_BOLD in src/outfont.h): the original's
   CreateFontW gets lfItalic and lfWeight 700 whatever the face. */
void jw_text_run_style(fb_t *fb, const jw_view *v, const char *s,
                       double x0, double y0, double x1, double y1,
                       double cw, double ch, unsigned int col, int tate,
                       int style)
{
    double dx = x1 - x0, dy = y1 - y0;
    double len = sqrt(dx * dx + dy * dy);
    double ux, uy, vx, vy, step, sw, sh;
    double lean = (style & 1) ? JW_TEXT_ITALIC : 0.0;
    double bold = (style & 2) ? ch * JW_TEXT_BOLD : 0.0;
    int n = jw_text_count(s), i;
    const unsigned char *p = (const unsigned char *)s;

    want_fonts();
    /* 負の幅・高さは 左右・上下に裏返した字（反転した参照の中の字。原典で測った:
       src/jww.c blk_text_post の注）。幅が負なら 進む向きも字の右も 逆に、高さが負なら
       字の上が逆 */
    sw = cw < 0.0 ? -1.0 : 1.0;
    sh = ch < 0.0 ? -1.0 : 1.0;
    cw = fabs(cw);
    ch = fabs(ch);
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
    vx = -uy * sh;
    vy = ux * sh;
    ux *= sw;
    uy *= sw;
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
              tate ? sw : ux, tate ? 0.0 : uy,
              tate ? 0.0 : vx, tate ? sh : vy, cw, ch, col, lean, bold);
    }
}

void jw_text(fb_t *fb, const jw_view *v, const char *s,
             double x0, double y0, double x1, double y1,
             double cw, double ch, unsigned int col)
{
    jw_text_run(fb, v, s, x0, y0, x1, y1, cw, ch, col, 0);
}
