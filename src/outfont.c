/* See outfont.h. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "outfont.h"
#include "cp932.h"

/* stb_truetype.h, public domain (src/stb_truetype.h is Sean Barrett's file,
   unmodified).  It does no range checking, so it is only ever given the
   fonts of ours -- jw_outfont_put checks the header and nothing else. */
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include "stb_truetype.h"

typedef struct {
    const char *name, *alias, *file;
    int state;          /* 0 untouched, 1 wanted, 2 ready, 3 failed, 4 fetching */
    unsigned char *data;
    stbtt_fontinfo info;
    int asc, desc;      /* font units; asc - desc is the em the cell maps to */
} ofont_t;

/* the aliases are CP932: ゴシック = 83 53 83 56 83 62 83 4E, 明朝 = 96 BE 92 A9 */
static ofont_t F[JW_NOUTFONT] = {
    { "IPAexGothic",  "IPAex\x83\x53\x83\x56\x83\x62\x83\x4e", "jwsubgothic.ttf", 0 },
    { "IPAexMincho",  "IPAex\x96\xbe\x92\xa9",                 "jwsubmincho.ttf", 0 },
    { "BIZ UDGothic", "BIZ UD\x83\x53\x83\x56\x83\x62\x83\x4e", "bizudgothic-sub.ttf", 0 },
};
static int fgen;
static char fdir[260];

int jw_outfont_count(void) { return JW_NOUTFONT; }

const char *jw_outfont_name(int i)
{
    return i >= 0 && i < JW_NOUTFONT ? F[i].name : "";
}

const char *jw_outfont_file(int i)
{
    return i >= 0 && i < JW_NOUTFONT ? F[i].file : "";
}

int jw_outfont_gen(void) { return fgen; }

static int same(const char *a, const char *b)
{
    for (; *a && *b; a++, b++) {
        unsigned char x = (unsigned char)*a, y = (unsigned char)*b;

        if (x >= 'A' && x <= 'Z') x += 32;
        if (y >= 'A' && y <= 'Z') y += 32;
        if (x != y)
            return 0;
    }
    return !*a && !*b;
}

int jw_outfont_find(const char *face)
{
    int i;

    if (!face || !*face)
        return -1;
    for (i = 0; i < JW_NOUTFONT; i++)
        if (same(face, F[i].name) || same(face, F[i].alias))
            return i;
    return -1;
}

void jw_outfont_dir(const char *dir)
{
    snprintf(fdir, sizeof fdir, "%s", dir ? dir : "");
}

int jw_outfont_put(int i, const unsigned char *data, long len)
{
    unsigned char *copy;
    int off;

    if (i < 0 || i >= JW_NOUTFONT || F[i].state == 2)
        return 0;
    F[i].state = 3;
    if (!data || len < 64)
        return 0;
    if (!((data[0] == 0 && data[1] == 1 && data[2] == 0 && data[3] == 0)
          || !memcmp(data, "true", 4) || !memcmp(data, "OTTO", 4)))
        return 0;
    copy = (unsigned char *)malloc((size_t)len);
    if (!copy)
        return 0;
    memcpy(copy, data, (size_t)len);
    off = stbtt_GetFontOffsetForIndex(copy, 0);
    if (off < 0 || !stbtt_InitFont(&F[i].info, copy, off)) {
        free(copy);
        return 0;
    }
    stbtt_GetFontVMetrics(&F[i].info, &F[i].asc, &F[i].desc, &off);
    if (F[i].asc - F[i].desc <= 0) {
        free(copy);
        return 0;
    }
    F[i].data = copy;
    F[i].state = 2;
    fgen++;
    return 1;
}

void jw_outfont_fail(int i)
{
    if (i >= 0 && i < JW_NOUTFONT && F[i].state != 2)
        F[i].state = 3;
}

int jw_outfont_pending(void)
{
    int i;

    for (i = 0; i < JW_NOUTFONT; i++)
        if (F[i].state == 1) {
            F[i].state = 4;
            return i;
        }
    return -1;
}

#ifndef __EMSCRIPTEN__
static int read_file(int i)
{
    static const char *const where[] = { "", "fonts/", "font/", "../fonts/",
                                         "../font/", "../../fonts/" };
    char path[600], env[300];
    const char *e = getenv("JW_FONTS");
    unsigned k;

    for (k = 0; k < 8; k++) {
        FILE *f;
        long n;
        unsigned char *buf;
        int ok;

        if (k == 0 && !fdir[0])
            continue;
        if (k == 1 && !(e && *e))
            continue;
        if (k == 0)
            snprintf(path, sizeof path, "%s/%s", fdir, F[i].file);
        else if (k == 1) {
            snprintf(env, sizeof env, "%s", e);
            snprintf(path, sizeof path, "%s/%s", env, F[i].file);
        } else
            snprintf(path, sizeof path, "%s%s", where[k - 2], F[i].file);
        f = fopen(path, "rb");
        if (!f)
            continue;
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        if (n < 64 || n > 64L * 1024 * 1024 || !(buf = (unsigned char *)malloc((size_t)n))) {
            fclose(f);
            continue;
        }
        ok = fread(buf, 1, (size_t)n, f) == (size_t)n;
        fclose(f);
        if (ok && jw_outfont_put(i, buf, n)) {
            free(buf);
            return 1;
        }
        free(buf);
        F[i].state = 0;
    }
    return 0;
}
#endif

int jw_outfont_ready(int i)
{
    if (i < 0 || i >= JW_NOUTFONT)
        return 0;
    if (F[i].state == 2)
        return 1;
    if (F[i].state == 0) {
#ifdef __EMSCRIPTEN__
        F[i].state = 1;                 /* the page fetches it */
#else
        if (!read_file(i))
            F[i].state = 3;
#endif
    }
    return F[i].state == 2;
}

/* ------------------------------------------------------------ glyph cache
 * A glyph is rasterised at the scale it is drawn at, so the same letter in
 * the same size -- which is most of a drawing's text -- is made once.  A
 * direct-mapped table; an entry is replaced by whatever hashes onto it. */
typedef struct {
    int font, glyph, qx, qy;
    float sx, sy;
    int x0, y0, w, h;
    unsigned char *bm;
    int used;
} gc_t;
#define NGC 512
static gc_t gc[NGC];

static const gc_t *bitmap(int fi, int glyph, float sx, float sy, int qx, int qy)
{
    unsigned h = (unsigned)glyph * 2654435761u ^ (unsigned)fi * 40503u
                 ^ (unsigned)qx * 7u ^ (unsigned)qy * 13u
                 ^ (unsigned)(sx * 64.0f) * 31u ^ (unsigned)(sy * 64.0f) * 17u;
    gc_t *e = &gc[h % NGC];
    int x1, y1;
    float fx = qx / 4.0f, fy = qy / 4.0f;

    if (e->used && e->font == fi && e->glyph == glyph && e->qx == qx
        && e->qy == qy && e->sx == sx && e->sy == sy)
        return e;
    free(e->bm);
    memset(e, 0, sizeof *e);
    e->used = 1;
    e->font = fi;
    e->glyph = glyph;
    e->qx = qx;
    e->qy = qy;
    e->sx = sx;
    e->sy = sy;
    stbtt_GetGlyphBitmapBoxSubpixel(&F[fi].info, glyph, sx, sy, fx, fy,
                                    &e->x0, &e->y0, &x1, &y1);
    e->w = x1 - e->x0;
    e->h = y1 - e->y0;
    if (e->w <= 0 || e->h <= 0 || e->w > 2048 || e->h > 2048) {
        e->w = e->h = 0;
        return e;
    }
    e->bm = (unsigned char *)calloc((size_t)e->w * (size_t)e->h, 1);
    if (!e->bm) {
        e->w = e->h = 0;
        return e;
    }
    stbtt_MakeGlyphBitmapSubpixel(&F[fi].info, e->bm, e->w, e->h, e->w,
                                  sx, sy, fx, fy, glyph);
    return e;
}

/* grey level of a coverage: a touch heavier than linear, so a thin stem
   one pixel across still reads on the paper (gamma 0.8); filled in by the
   first run */
static unsigned char boost[256];

static void put(fb_t *fb, const jw_view *v, int sx, int sy, unsigned int col,
                int cov)
{
    unsigned int *p;
    unsigned int d, t, r;
    int c;

    if (cov <= 0 || sx < v->clip.x || sx >= v->clip.x + v->clip.w
        || sy < v->clip.y || sy >= v->clip.y + v->clip.h)
        return;
    p = &fb->px[(size_t)sy * fb->w + sx];
    d = *p;
    t = jw_rop(d, col);
    if (cov >= 255) {
        *p = t;
        return;
    }
    r = 0;
    for (c = 0; c < 24; c += 8) {
        int a = (int)((d >> c) & 255), b = (int)((t >> c) & 255);

        r |= (unsigned)(a + (b - a) * cov / 255) << c;
    }
    *p = r;
}

/* One glyph.  (px,py) is where its origin -- the left end of the baseline --
 * lies on the paper; (ux,uy) and (vx,vy) are the unit vectors along and up
 * the text; hx and hy are paper millimetres per font unit across and up;
 * `shear` slants it (italic). */
static void glyph(fb_t *fb, const jw_view *v, int fi, int g, double px,
                  double py, double ux, double uy, double vx, double vy,
                  double hx, double hy, double shear, unsigned int col)
{
    const ofont_t *f = &F[fi];
    double em = f->asc - f->desc;
    double hs = hx / v->mmpp, vs = hy / v->mmpp;   /* pixels per font unit */
    double ox = v->bx + jw_ux(v, px) + 0.5, oy = v->by - jw_uy(v, py) + 0.5;
    double bsx = hs, bsy = vs, lim = 256.0 / em;
    int fast, qx = 0, qy = 0, ix = 0, iy = 0;
    const gc_t *b;
    double c[4][2];
    int k, x0, x1, y0, y1;

    if (!(hs > 0.0) || !(vs > 0.0) || hs * em > 1e5 || vs * em > 1e5
        || !(fabs(ox) < 1e8) || !(fabs(oy) < 1e8))
        return;
    /* rough reject: the em box, a little wide, against the clip */
    {
        static const double ex[4] = { -0.3, 1.3, -0.3, 1.3 };
        static const double ey[4] = { -0.3, -0.3, 1.3, 1.3 };

        for (k = 0; k < 4; k++) {
            double e1 = ex[k] * em, e2 = (ey[k] * em) + f->desc;
            double ru = (e1 + shear * e2) * hs, rv = e2 * vs;

            c[k][0] = ox + ux * ru + vx * rv;
            c[k][1] = oy - (uy * ru + vy * rv);
        }
        x0 = x1 = (int)floor(c[0][0]);
        y0 = y1 = (int)floor(c[0][1]);
        for (k = 1; k < 4; k++) {
            int a = (int)floor(c[k][0]), bb = (int)floor(c[k][1]);

            if (a < x0) x0 = a;
            if (a > x1) x1 = a;
            if (bb < y0) y0 = bb;
            if (bb > y1) y1 = bb;
        }
        if (x1 + 2 < v->clip.x || x0 - 2 >= v->clip.x + v->clip.w
            || y1 + 2 < v->clip.y || y0 - 2 >= v->clip.y + v->clip.h)
            return;
    }
    fast = uy == 0.0 && vx == 0.0 && ux > 0.0 && vy > 0.0 && shear == 0.0
           && hs <= lim && vs <= lim;
    if (!fast) {
        if (bsx > lim) bsx = lim;
        if (bsy > lim) bsy = lim;
    } else {
        double fx, fy;

        if (ox < -1e8 || ox > 1e8 || oy < -1e8 || oy > 1e8)
            return;
        ix = (int)floor(ox);
        iy = (int)floor(oy);
        fx = ox - ix;
        fy = oy - iy;
        qx = (int)(fx * 4.0);
        qy = (int)(fy * 4.0);
        if (qx > 3) qx = 3;
        if (qy > 3) qy = 3;
    }
    b = bitmap(fi, g, (float)bsx, (float)bsy, qx, qy);
    if (!b || !b->bm)
        return;
    if (fast) {
        int i, j;

        for (j = 0; j < b->h; j++) {
            int sy = iy + b->y0 + j;

            if (sy < v->clip.y || sy >= v->clip.y + v->clip.h)
                continue;
            for (i = 0; i < b->w; i++)
                put(fb, v, ix + b->x0 + i, sy, col, b->bm[j * b->w + i]);
        }
        return;
    }
    /* turned, slanted or scaled: every screen pixel in the box the bitmap
       covers asks the bitmap what is under it, and takes a bilinear mix */
    {
        double gx[4], gy[4];
        int sx, sy;
        double iu = 1.0 / hs, iv = 1.0 / vs;

        gx[0] = gx[2] = b->x0 / bsx;
        gx[1] = gx[3] = (b->x0 + b->w) / bsx;
        gy[0] = gy[1] = -(b->y0) / bsy;
        gy[2] = gy[3] = -(b->y0 + b->h) / bsy;
        for (k = 0; k < 4; k++) {
            double ru = (gx[k] + shear * gy[k]) * hs, rv = gy[k] * vs;

            c[k][0] = ox + ux * ru + vx * rv;
            c[k][1] = oy - (uy * ru + vy * rv);
        }
        x0 = x1 = (int)floor(c[0][0]);
        y0 = y1 = (int)floor(c[0][1]);
        for (k = 1; k < 4; k++) {
            int a = (int)floor(c[k][0]), bb = (int)floor(c[k][1]);

            if (a < x0) x0 = a;
            if (a > x1) x1 = a;
            if (bb < y0) y0 = bb;
            if (bb > y1) y1 = bb;
        }
        x0 -= 1; y0 -= 1; x1 += 1; y1 += 1;
        if (x0 < v->clip.x) x0 = v->clip.x;
        if (y0 < v->clip.y) y0 = v->clip.y;
        if (x1 >= v->clip.x + v->clip.w) x1 = v->clip.x + v->clip.w - 1;
        if (y1 >= v->clip.y + v->clip.h) y1 = v->clip.y + v->clip.h - 1;
        for (sy = y0; sy <= y1; sy++)
            for (sx = x0; sx <= x1; sx++) {
                double dx = sx + 0.5 - ox, dy = -(sy + 0.5 - oy);
                double u = dx * ux + dy * uy, w = dx * vx + dy * vy;
                double ey = w * iv, ex = u * iu - shear * ey;
                double fx = ex * bsx - b->x0 - 0.5, fy = -ey * bsy - b->y0 - 0.5;
                int ax = (int)floor(fx), ay = (int)floor(fy), cov;
                double tx = fx - ax, ty = fy - ay, s = 0.0;
                int a, bq;

                if (ax < -1 || ay < -1 || ax >= b->w || ay >= b->h)
                    continue;
                for (bq = 0; bq < 2; bq++)
                    for (a = 0; a < 2; a++) {
                        int qx2 = ax + a, qy2 = ay + bq;
                        double wgt = (a ? tx : 1.0 - tx) * (bq ? ty : 1.0 - ty);

                        if (qx2 >= 0 && qx2 < b->w && qy2 >= 0 && qy2 < b->h)
                            s += wgt * b->bm[qy2 * b->w + qx2];
                    }
                cov = (int)(s + 0.5);
                put(fb, v, sx, sy, col, cov);
            }
    }
}

static int is_lead(unsigned char c)
{
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc);
}


/* ------------------------------------------------------ the original's faces
 * With outline fonts switched on, a text in one of the original's own faces
 * is set in IPAex as well: ゴシック (and anything unknown, the default
 * included) in the gothic, 明朝 in the mincho.  A face with a full-width Ｐ
 * (ＭＳ Ｐゴシック, ＭＳ Ｐ明朝) is the proportional one: each letter takes
 * its own advance.  The tests that score against the original leave this off
 * (they link no main), so their pixels are the bitmap font's. */
static int enabled;

void jw_outfont_enable(int on) { enabled = on != 0; }
int jw_outfont_enabled(void) { return enabled; }

static int has(const char *s, const char *t)
{
    size_t n = strlen(t);

    for (; *s; s++)
        if (!strncmp(s, t, n))
            return 1;
    return 0;
}

int jw_outfont_resolve(const char *face, int *prop)
{
    int i;

    if (prop)
        *prop = 0;
    i = jw_outfont_find(face);
    if (i >= 0 || !enabled)
        return i;
    if (face && prop && (has(face, "\x82\x6f") || has(face, "MS P")
                         || has(face, "PGothic") || has(face, "PMincho")))
        *prop = 1;
    if (face && (has(face, "\x96\xbe\x92\xa9") || has(face, "Mincho")
                 || has(face, "MINCHO") || has(face, "mincho")
                 || has(face, "Serif")))
        return 1;
    return 0;
}

int jw_outfont_run(fb_t *fb, const jw_view *v, int fi, const char *s,
                   double x0, double y0, double x1, double y1,
                   double cw, double ch, unsigned int col, int tate,
                   int style, int prop)
{
    enum { MAXC = 1024 };
    static double cell[MAXC];
    static int gl[MAXC], wide[MAXC];
    double dx = x1 - x0, dy = y1 - y0, len = sqrt(dx * dx + dy * dy);
    double ux, uy, vx, vy, W = 0.0, units = 0.0, sp = 0.0, pen = 0.0;
    double em, hx, hy, base, shear = (style & 1) ? 0.2 : 0.0;
    const unsigned char *p;
    int n = 0, i;

    if (!jw_outfont_ready(fi))
        return 0;
    if (!(ch > 0.0) || !(cw > 0.0) || !s)
        return 1;
    if (!boost[255]) {
        for (i = 0; i < 256; i++)
            boost[i] = (unsigned char)(255.0 * pow(i / 255.0, 0.8) + 0.5);
    }
    em = F[fi].asc - F[fi].desc;
    hx = cw / em;
    hy = ch / em;
    base = -F[fi].desc * hy;
    if (len < 1e-9) {
        ux = 1.0;
        uy = 0.0;
        len = 0.0;
    } else {
        ux = dx / len;
        uy = dy / len;
    }
    vx = -uy;
    vy = ux;
    for (p = (const unsigned char *)s; *p && n < MAXC; n++) {
        int w = is_lead(p[0]) && p[1], adv, lsb;
        unsigned short u[2];
        long m = jw_to_utf16((const char *)p, w ? 2 : 1, u, 2);

        gl[n] = m > 0 && u[0] != 0xfffd
                ? stbtt_FindGlyphIndex(&F[fi].info, u[0]) : 0;
        wide[n] = w;
        cell[n] = w ? cw : cw / 2;
        if (prop && gl[n]) {
            stbtt_GetGlyphHMetrics(&F[fi].info, gl[n], &adv, &lsb);
            cell[n] = adv * hx;
            if (cell[n] < cw / 8)
                cell[n] = cw / 8;
        }
        W += cell[n];
        if (n)
            units += w ? 1.0 : 0.5;
        p += w ? 2 : 1;
    }
    if (len > 0.0 && units > 0.0)
        sp = (len - W) / units;         /* the gap the file's ends leave */
    for (i = 0; i < n; i++) {
        int g = gl[i], adv, lsb, pass;
        double sq = 1.0, xo = 0.0, gap, gx, gy;

        gap = i ? (wide[i] ? sp : sp / 2) : 0.0;
        pen += gap;
        if (g) {
            double a;

            stbtt_GetGlyphHMetrics(&F[fi].info, g, &adv, &lsb);
            a = adv * hx;
            if (prop)
                xo = 0.0;
            else if (a > cell[i] * 1.0001 && a > 0.0)
                sq = cell[i] / a;       /* too wide for its cell: squeeze */
            else
                xo = (cell[i] - a) / 2; /* otherwise centre it */
            /* the run goes its way even when the letters stay upright */
            gx = x0 + ux * (pen + xo);
            gy = y0 + uy * (pen + xo);
            for (pass = 0; pass < ((style & 2) ? 2 : 1); pass++) {
                double bx = pass ? 0.025 * cw : 0.0;
                double ex = tate ? 1.0 : ux, ey2 = tate ? 0.0 : uy;
                double fvx = tate ? 0.0 : vx, fvy = tate ? 1.0 : vy;

                glyph(fb, v, fi, g,
                      gx + ex * bx + fvx * base, gy + ey2 * bx + fvy * base,
                      ex, ey2, fvx, fvy, hx * sq, hy, shear, col);
            }
        }
        pen += cell[i];
    }
    return 1;
}
