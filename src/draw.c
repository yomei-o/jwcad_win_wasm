#include <math.h>
#include <stddef.h>

#include "draw.h"

/* Cohen-Sutherland, so a drawing bigger than the window does not run off the
 * end of the framebuffer. */
enum { L = 1, R = 2, B = 4, T = 8 };

static int outcode(const rect_t *c, int x, int y)
{
    int k = 0;

    if (x < c->x) k |= L;
    else if (x >= c->x + c->w) k |= R;
    if (y < c->y) k |= T;
    else if (y >= c->y + c->h) k |= B;
    return k;
}

static void put(fb_t *fb, const rect_t *c, int x, int y, unsigned int col)
{
    if (x >= c->x && x < c->x + c->w && y >= c->y && y < c->y + c->h)
        fb->px[(size_t)y * fb->w + x] = col;
}

/* The nine line types, as Jw_cad keeps them: a 32-bit pattern and how many
 * of its bits make one repeat.  One bit is one pixel along the line.  These
 * are the defaults out of HKCU\Software\Jw_cad\jw_win\Line (Type_01..09,
 * Unit_01..09); a drawing can carry its own set, which is not read yet. */
static const struct { unsigned int bits; int unit; } LTYPE[10] = {
    { 0xffffffffu, 32 },        /* 0: unused, treated as solid */
    { 0xffffffffu, 32 },        /* 1 実線       */
    { 0x99999999u,  4 },        /* 2 点線1      */
    { 0xc3c3c3c3u,  8 },        /* 3 点線2      */
    { 0xe7e7e7e7u,  8 },        /* 4 点線3      */
    { 0xf99ff99fu, 16 },        /* 5 一点鎖1    */
    { 0xfff99fffu, 32 },        /* 6 一点鎖2    */
    { 0xf24ff24fu, 16 },        /* 7 二点鎖1    */
    { 0xfff24fffu, 32 },        /* 8 二点鎖2    */
    { 0x22222222u,  4 },        /* 9 補助線     */
};

/* Bresenham, one pixel wide.  Jw_cad draws through GDI's LineTo, which is
 * also Bresenham, so the pixels land in the same places -- except that GDI
 * leaves the last point out, which is why the caller passes the endpoint it
 * wants drawn and this includes it. */
static void line(fb_t *fb, const rect_t *c, int x0, int y0, int x1, int y1,
                 unsigned int col, int wide, int ltype, int *phase)
{
    const unsigned int bits = LTYPE[ltype].bits;
    const int unit = LTYPE[ltype].unit;
    int step = phase ? *phase : 0;
    int dx = x1 > x0 ? x1 - x0 : x0 - x1;
    int dy = y1 > y0 ? y1 - y0 : y0 - y1;
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    if ((outcode(c, x0, y0) & outcode(c, x1, y1)) != 0)
        return;
    for (;;) {
        int i, j;
        if (bits & (1u << (step % unit)))
            for (j = 0; j < wide; j++)
                for (i = 0; i < wide; i++)
                    put(fb, c, x0 + i, y0 + j, col);
        step++;
        if (x0 == x1 && y0 == y1)
            break;
        {
            int e2 = 2 * err;
            if (e2 > -dy) { err -= dy; x0 += sx; }
            if (e2 < dx)  { err += dx; y0 += sy; }
        }
    }
    if (phase)
        *phase = step;
}

static int line_type(const jw_obj *o)
{
    int t = o->ltype % 100;
    return t >= 1 && t <= 9 ? t : 1;
}

static unsigned int pen_colour(const jw_drawing *d, int pen)
{
    return d->pen_rgb[pen >= 1 && pen <= 9 ? pen : 2];
}

static int pen_wide(const jw_drawing *d, int pen)
{
    int w = d->pen_width[pen >= 1 && pen <= 9 ? pen : 2];
    return w < 1 ? 1 : w;
}

/* An arc: centre, radius, flattening, start and end angle, tilt.  Stepped
 * finely enough that the chords are under a pixel. */
static void arc(fb_t *fb, const jw_view *v, const jw_drawing *d,
                const jw_obj *o)
{
    /* centre, radius, start angle, sweep, tilt, flattening.  A round arc has
     * flattening 1; an ellipse has it less.  Angles are radians, and the
     * sweep is a length, not an end angle -- the corner fillets of
     * Test1.jww come out as (90 deg, 90 deg) and (0, 90 deg). */
    double cx = o->d[0], cy = o->d[1], r = o->d[2];
    double a0 = o->d[3], sw = o->d[4], tilt = o->d[5], flat = o->d[6];
    unsigned int col = pen_colour(d, o->color);
    int wide = pen_wide(d, o->color);
    double sweep, ct, st;
    int lt = line_type(o), phase = 0;
    int n, i, px = 0, py = 0;

    if (flat <= 0.0)
        flat = 1.0;
    sweep = sw;
    if (sweep <= 0.0)
        sweep = 2 * 3.14159265358979323846;
    n = (int)(r * v->scale * sweep) + 8;
    if (n > 8192)
        n = 8192;
    ct = cos(tilt);
    st = sin(tilt);
    for (i = 0; i <= n; i++) {
        double t = a0 + sweep * i / n;
        double ux = r * cos(t), uy = r * flat * sin(t);
        int sx = jw_sx(v, cx + ux * ct - uy * st);
        int sy = jw_sy(v, cy + ux * st + uy * ct);
        if (i)
            line(fb, &v->clip, px, py, sx, sy, col, wide, lt, &phase);
        px = sx;
        py = sy;
    }
}

void jw_draw(fb_t *fb, const jw_view *v, const jw_drawing *d)
{
    int i;

    for (i = 0; i < d->nobj; i++) {
        const jw_obj *o = &d->obj[i];
        unsigned int col = pen_colour(d, o->color);
        int wide = pen_wide(d, o->color);

        switch (o->cls) {
        case JW_SEN: {
            int phase = 0;
            line(fb, &v->clip, jw_sx(v, o->d[0]), jw_sy(v, o->d[1]),
                 jw_sx(v, o->d[2]), jw_sy(v, o->d[3]), col, wide,
                 line_type(o), &phase);
            break;
        }
        case JW_ENKO:
            arc(fb, v, d, o);
            break;
        case JW_TEN: {
            int x = jw_sx(v, o->d[0]), y = jw_sy(v, o->d[1]);
            put(fb, &v->clip, x, y, col);
            break;
        }
        case JW_SOLID: {
            /* four corners; the fourth repeats the third for a triangle */
            int k;
            for (k = 0; k < 4; k++) {
                int a = k, b = (k + 1) & 3;
                int phase = 0;
                line(fb, &v->clip,
                     jw_sx(v, o->d[2 * a]), jw_sy(v, o->d[2 * a + 1]),
                     jw_sx(v, o->d[2 * b]), jw_sy(v, o->d[2 * b + 1]),
                     col, wide, 1, &phase);
            }
            break;
        }
        default:
            break;      /* text is not drawn yet */
        }
    }
}
