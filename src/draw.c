#include <math.h>
#include <stddef.h>

/* GDI's LineTo draws from the current point up to, but not including, the
 * point given.  Jw_cad draws every line that way, so the port does too --
 * it is worth about sixty pixels of Test1.jww. */

#include "draw.h"
#include "text.h"

#include <stdlib.h>

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

/* One bit of a line type pattern is one pixel along the line.
 *
 * 敷地図.jww settles it: its 一点鎖1 lines are 0xf99ff99f over 16 bits, and
 * the original draws 10 on, 2 off, 2 on, 2 off, repeating every 16 pixels at
 * 2.303 px/mm.  An earlier reading of Test1.jww's 道路中心線 put one bit at
 * 0.625 mm of paper, which comes to 1.02 px there -- near enough to 1 that
 * the measurement could not tell them apart, and wrong by half again on an
 * A-3 sheet.  jw_mm_per_bit is kept as a knob for tools/calibrate; 0 means
 * one pixel. */

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
    int err;

    /* The original's lines reach one pixel further than the rounded ends at
     * each end: 敷地図.jww's long horizontals run 358..922 where the ends
     * land on 358.76 and 921.64.  jw_line_ext says to do the same. */
    if (jw_line_ext) {
        if (dx >= dy) {
            x0 -= sx;
            x1 += sx;
            dx += 2;
        } else {
            y0 -= sy;
            y1 += sy;
            dy += 2;
        }
    }
    err = dx - dy;

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
    if (jw_line_algo == 0) {
        for (;;) {
            int i, j;
            if (x0 == x1 && y0 == y1 && jw_line_open)
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
    } else {
        /* The textbook major-axis Bresenham, which is what GDI runs: one
         * step per pixel of the long axis, the short axis moving when the
         * error term crosses.  jw_line_algo 2 moves on a tie as well. */
        int major = dx > dy ? dx : dy;
        int minor = dx > dy ? dy : dx;
        int e = 2 * minor - major;
        int k;
        for (k = 0; k <= major; k++) {
            int i, j;
            if (k == major && jw_line_open)
                break;
            if (bits & (1u << (((int)(step / ppb)) % unit)))
                for (j = 0; j < wide; j++)
                    for (i = 0; i < wide; i++)
                        put(fb, c, x0 + i, y0 + j, col);
            step += adv;
            if (e > 0 || (e == 0 && jw_line_algo == 2)) {
                if (dx > dy) y0 += sy; else x0 += sx;
                e -= 2 * major;
            }
            e += 2 * minor;
            if (dx > dy) x0 += sx; else y0 += sy;
        }
    }
    if (phase)
        *phase = step;
}

/* How many pixels one bit of the pattern covers at this zoom.  Below one the
 * dashes would fall between pixels and the line would vanish. */
static double pix_per_bit(const jw_view *v)
{
    double p = jw_mm_per_bit > 0.0 ? jw_mm_per_bit * v->scale : 1.0;
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

/* One pixel, always.  The file carries a width per pen and the original
 * honours it when printing, but not on the screen: Test1.jww's 道路中心線 is
 * pen 6, whose width is 2, and the original draws it one row high. */
static int pen_wide(const jw_drawing *d, int pen)
{
    (void)d;
    (void)pen;
    return 1;
}

/* How an element is shown, exactly as FUN_0043b460 works it out:
 *
 *      0  not shown
 *      1  shown but not editable -- drawn in one flat grey
 *      3  shown normally
 *
 * The group's state and the layer's state are each folded to 0, 1 or 3 and
 * ANDed, so "display only" anywhere wins; and bit 0 of the element's own
 * flags at +0x44 knocks a visible element down to "display only" on its own.
 *
 * Which layer an element is on is +0x2e and its group +0x2f -- not the long
 * at +0x04, which is a serial number.  The same function indexes the state
 * arrays with exactly those two bytes. */
static int shown(const jw_drawing *d, const jw_obj *o)
{
    int g = o->lgroup & 15, l = o->layer & 15;
    int gs = d->group[g].state, ls = d->group[g].layer[l].state;
    int v;

    {   /* debugging hooks: draw just one layer, or just one flag value */
        const char *e = getenv("JW_ONLY_LAYER");
        const char *f = getenv("JW_ONLY_FLAG");
        if (f)
            return o->flags == (unsigned short)strtoul(f, 0, 0) ? 3 : 0;
        if (e)
            return l == atoi(e) ? 3 : 0;
    }
    gs = gs == 0 ? 0 : gs == 1 ? 1 : 3;
    ls = ls == 0 ? 0 : ls == 1 ? 1 : 3;
    v = gs & ls;
    if (v && (o->flags & 1))
        v = 1;
    return v;
}

/* Shown-but-not-editable is drawn in one flat grey whatever the element's own
 * colour is -- 0xc0c0c0, which is pen 9.  日影図.jww keeps nine of its
 * sixteen layers that way, and drawing them in their own colours makes the
 * screen look nothing like the original's. */
static unsigned int obj_colour(const jw_drawing *d, const jw_obj *o)
{
    if (shown(d, o) == 1)
        return d->pen_rgb[9];
    return pen_colour(d, o->color);
}

static int obj_wide(const jw_drawing *d, const jw_obj *o)
{
    return pen_wide(d, o->color);
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
    unsigned int col = obj_colour(d, o);
    int wide = obj_wide(d, o);
    double sweep, ct, st;
    int lt = line_type(o);
    double phase = 0.0, ppb = pix_per_bit(v);
    int n, i, px = 0, py = 0;

    if (flat <= 0.0)
        flat = 1.0;
    sweep = sw;
    /* A negative sweep runs clockwise -- the door swings of
     * Ａマンション平面例.jww are stored that way.  Only a sweep of nothing
     * means the whole circle. */
    if (sweep == 0.0)
        sweep = 2 * 3.14159265358979323846;
    n = (int)(r * v->scale * (sweep < 0 ? -sweep : sweep)) + 8;
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
        col = obj_colour(d, o);
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

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        if (!shown(d, o))
            continue;
        unsigned int col = obj_colour(d, o);
        int wide = obj_wide(d, o);

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
