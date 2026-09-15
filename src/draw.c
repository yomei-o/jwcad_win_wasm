#include <math.h>
#include <stddef.h>

/* GDI's LineTo draws from the current point up to, but not including, the
 * point given.  Jw_cad draws every line that way, so the port does too --
 * it is worth about sixty pixels of Test1.jww. */
#define JW_LINE_OPEN 1

#include "draw.h"
#include "text.h"

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

/* One bit of a line type pattern is this much paper, not one pixel.
 *
 * Measured off the reference: Test1.jww's 道路中心線 is 一点鎖2, whose
 * pattern is 32 bits, and its dashes repeat every 32.71 pixels -- not 32.
 * The line is 503.409 mm long and holds 25.16 repeats, so one repeat is
 * 20.0 mm of paper and one bit is 20/32.  Stepping the pattern per pixel
 * instead makes the dashes drift by about 1% along a long line. */
#ifndef MM_PER_BIT
#define MM_PER_BIT 0.625
#endif

/* Bresenham, one pixel wide.  Jw_cad draws through GDI's LineTo, which is
 * also Bresenham, so the pixels land in the same places -- except that GDI
 * leaves the last point out, which is why the caller passes the endpoint it
 * wants drawn and this includes it. */
static void line(fb_t *fb, const rect_t *c, int x0, int y0, int x1, int y1,
                 unsigned int col, int wide, int ltype, double ppb,
                 double *phase)
{
    const unsigned int bits = LTYPE[ltype].bits;
    const int unit = LTYPE[ltype].unit;
    double step = phase ? *phase : 0.0;
    double adv;
    int dx = x1 > x0 ? x1 - x0 : x0 - x1;
    int dy = y1 > y0 ? y1 - y0 : y0 - y1;
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    int err = dx - dy;

    /* The pattern advances along the line, not along the axis Bresenham
     * steps on: a diagonal covers sqrt(2) as much line per step as a
     * horizontal one, and a drawing full of diagonals goes visibly out of
     * phase if that is ignored. */
    {
        int major = dx > dy ? dx : dy;
        adv = major ? sqrt((double)dx * dx + (double)dy * dy) / major : 1.0;
    }
    if ((outcode(c, x0, y0) & outcode(c, x1, y1)) != 0)
        return;
    for (;;) {
        int i, j;
        if (x0 == x1 && y0 == y1 && JW_LINE_OPEN)
            break;
        if (bits & (1u << (((int)(step / ppb)) % unit)))
            for (j = 0; j < wide; j++)
                for (i = 0; i < wide; i++)
                    put(fb, c, x0 + i, y0 + j, col);
        step += adv;
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

/* How many pixels one bit of the pattern covers at this zoom.  Below one the
 * dashes would fall between pixels and the line would vanish. */
static double pix_per_bit(const jw_view *v)
{
    double p = MM_PER_BIT * v->scale;
    return p < 1.0 ? 1.0 : p;
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
    int lt = line_type(o);
    double phase = 0.0, ppb = pix_per_bit(v);
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
            line(fb, &v->clip, px, py, sx, sy, col, wide, lt, ppb, &phase);
        px = sx;
        py = sy;
    }
}

/* Which layer an object is on is +0x2e, and its group +0x2f -- not the long
 * at +0x04, which is a serial number.  The layer bar of the original settles
 * it: Test1.jww marks layers 0, 1, 2 and 4, which is exactly the set of
 * +0x2e values in it, and nothing like the +0x04 values (0, 8, 16).
 * State 0 is "not shown"; 1 is shown, 2 editable, 3 the one written to. */
static int visible(const jw_drawing *d, const jw_obj *o)
{
    int g = o->lgroup & 15, l = o->layer & 15;

    return d->group[g].state != 0 && d->group[g].layer[l].state != 0;
}

/* A solid is four corners, filled.  The fourth repeats the third when it is
 * a triangle.  Colour 10 means "any colour", and then the RGB sits in the
 * trailing long as a COLORREF. */
static void solid(fb_t *fb, const jw_view *v, const jw_drawing *d,
                  const jw_obj *o)
{
    int px[4], py[4], n = 4, i, j, y, ymin, ymax;
    unsigned int col;

    if (o->color == 10) {
        unsigned c = (unsigned)o->n;
        col = ((c & 0xff) << 16) | (c & 0xff00) | ((c >> 16) & 0xff);
    } else {
        col = pen_colour(d, o->color);
    }
    for (i = 0; i < 4; i++) {
        px[i] = jw_sx(v, o->d[2 * i]);
        py[i] = jw_sy(v, o->d[2 * i + 1]);
    }
    if (px[3] == px[2] && py[3] == py[2])
        n = 3;
    ymin = ymax = py[0];
    for (i = 1; i < n; i++) {
        if (py[i] < ymin) ymin = py[i];
        if (py[i] > ymax) ymax = py[i];
    }
    if (ymin < v->clip.y) ymin = v->clip.y;
    if (ymax >= v->clip.y + v->clip.h) ymax = v->clip.y + v->clip.h - 1;
    for (y = ymin; y <= ymax; y++) {
        int xs[8], m = 0;
        for (i = 0, j = n - 1; i < n; j = i++) {
            int y0 = py[j], y1 = py[i];
            if ((y0 <= y) == (y1 <= y))
                continue;
            xs[m++] = px[j] + (int)((double)(y - y0) * (px[i] - px[j])
                                    / (y1 - y0) + 0.5);
        }
        for (i = 1; i < m; i++) {
            int k = xs[i], q = i - 1;
            while (q >= 0 && xs[q] > k) { xs[q + 1] = xs[q]; q--; }
            xs[q + 1] = k;
        }
        for (i = 0; i + 1 < m; i += 2) {
            int a = xs[i], b = xs[i + 1];
            if (a < v->clip.x) a = v->clip.x;
            if (b > v->clip.x + v->clip.w - 1) b = v->clip.x + v->clip.w - 1;
            for (; a <= b; a++)
                fb->px[(size_t)y * fb->w + a] = col;
        }
    }
}

void jw_draw(fb_t *fb, const jw_view *v, const jw_drawing *d)
{
    int i;

    for (i = 0; i < d->nobj; i++) {
        const jw_obj *o = &d->obj[i];
        if (!visible(d, o))
            continue;
        unsigned int col = pen_colour(d, o->color);
        int wide = pen_wide(d, o->color);

        switch (o->cls) {
        case JW_SEN: {
            double phase = 0.0;
            line(fb, &v->clip, jw_sx(v, o->d[0]), jw_sy(v, o->d[1]),
                 jw_sx(v, o->d[2]), jw_sy(v, o->d[3]), col, wide,
                 line_type(o), pix_per_bit(v), &phase);
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
        case JW_SOLID:
            solid(fb, v, d, o);
            break;
        case JW_MOJI:
            jw_text(fb, v, jw_str(d, o->text), o->d[0], o->d[1],
                    o->d[2], o->d[3], o->d[4], o->d[5], col);
            break;
        default:
            break;
        }
    }
}
