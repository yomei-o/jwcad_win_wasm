#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

#include "draw.h"
#include "gen/circle.h"
#include "gen/pens.h"
#include "text.h"

#define PI 3.14159265358979323846

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

/* One pixel wide, the way GDI draws it -- Jw_cad goes through LineTo.  GDI
 * leaves the last point out; Jw_cad wants it, so the caller passes the
 * endpoint it wants drawn and this includes it (jw_line_open says
 * otherwise). */
/* Is the pattern lit at this pixel?
 *
 * The original walks the pattern, not the pixels: bit i sits at pixel
 * (int)(i * step) and a run of set bits is drawn as one segment from the
 * first of them to where the bit after the run sits (FUN_004bbef0
 * accumulates the step in a double and truncates).  So the bit a pixel
 * belongs to is the LAST one that starts at or before it -- ceiling
 * arithmetic, not floor.  Getting that backwards moves every dash one pixel
 * along, which is most of what was left of Test7.jww.
 *
 * When the step is under a pixel several bits land on the same one.  Taking
 * the first of them, or lighting the pixel if any of them is set, both score
 * worse over the fifteen samples (28,088 and 27,838 against 27,544), so the
 * last one it is.
 */
static int bits_set(int ltype, double step, double ppb)
{
    int i = (int)ceil((step + 1.0) / ppb) - 1;

    if (i < 0)
        i = 0;
    return (LTYPE[ltype].bits & (1u << (i % LTYPE[ltype].unit))) != 0;
}

/* Cut the line down to what is on screen before anything is rounded.  The
 * original does this too, and it matters because the line type is fitted to
 * the piece that is actually drawn -- but it only cuts along the LONG axis
 * (FUN_004280f0 clamps the major coordinate against the view and carries the
 * other one along the slope), so that is all this does.  Whatever is left
 * off the sides is thrown away a pixel at a time.
 *
 * The view reaches two pixels past the drawing area each way: OnDraw takes
 * its extent as the client plus four pixels. */
static int clip_major(double lo, double hi, double *p0, double *q0,
                      double *p1, double *q1)
{
    double d = *p1 - *p0, slope;

    if (*p0 > *p1) {
        double *t;
        t = p0; p0 = p1; p1 = t;
        t = q0; q0 = q1; q1 = t;
        d = -d;
    }
    if (*p1 < lo || *p0 > hi)
        return 0;
    if (d < 1e-9)
        return 1;
    slope = (*q1 - *q0) / d;
    if (*p0 < lo) {
        *q0 += (lo - *p0) * slope;
        *p0 = lo;
    }
    if (*p1 > hi) {
        *q1 += (hi - *p1) * slope;
        *p1 = hi;
    }
    return 1;
}

/* One pixel wide, the way GDI draws it -- Jw_cad goes through LineTo.  GDI
 * leaves the last point out; `open` says whether to do the same. */
static void stroke(fb_t *fb, const rect_t *c, int x0, int y0, int x1, int y1,
                   unsigned int col, int wide, int open)
{
    int dx = x1 > x0 ? x1 - x0 : x0 - x1;
    int dy = y1 > y0 ? y1 - y0 : y0 - y1;
    int sx = x0 < x1 ? 1 : -1;
    int sy = y0 < y1 ? 1 : -1;
    /* GDI's own Bresenham, checked against this machine's LineTo over 1,200
     * random lines (87,809 pixels, no difference): one step per pixel of the
     * long axis, and the short axis moves when the error term is positive --
     * or zero, if the short axis runs backwards.  That last clause is the
     * bias that makes GDI draw the same pixels whichever end it starts
     * from. */
    int xmaj = dx > dy;
    int mj = xmaj ? dx : dy;
    int mn = xmaj ? dy : dx;
    int tie = xmaj ? (sy < 0) : (sx < 0);
    int e = 2 * mn - mj;
    int k;

    if ((outcode(c, x0, y0) & outcode(c, x1, y1)) != 0)
        return;
    for (k = 0; k <= mj; k++) {
        int i, j;
        if (k == mj && open)
            break;
        for (j = 0; j < wide; j++)
            for (i = 0; i < wide; i++)
                put(fb, c, x0 + i, y0 + j, col);
        if (e > 0 || (e == 0 && tie)) {
            if (xmaj) y0 += sy; else x0 += sx;
            e -= 2 * mj;
        }
        e += 2 * mn;
        if (xmaj) x0 += sx; else y0 += sy;
    }
}

/* The ends come in as real offsets from the view's pinned pixel -- u across,
 * w up -- because the original cuts the line against the view in paper
 * millimetres, before anything is rounded.  Rounding first and cutting after
 * moves a line that runs off the screen by a pixel. */
static void line(fb_t *fb, const jw_view *v, double u0, double w0,
                 double u1, double w1,
                 unsigned int col, int wide, int ltype, double ppb,
                 double *phase)
{
    const rect_t *c = &v->clip;
    const unsigned int bits = LTYPE[ltype].bits;
    const int unit = LTYPE[ltype].unit;
    int x0, y0, x1, y1, dx, dy;

    {
        /* FUN_004280f0 has three cases, and which one a line falls into
         * decides both whether its ends get put in order and whether it is
         * cut against the view:
         *
         *   - dead level (the two y in millimetres exactly equal): the ends
         *     are always put in order so x increases, then cut across;
         *   - dead upright (the two x equal): likewise so y increases --
         *     in millimetres, where y runs up, so on screen it decreases;
         *   - anything else: only if the line runs off the view along its
         *     long axis, and then in that axis.
         *
         * A sloping line that fits on the screen is therefore drawn from the
         * end the file happens to store first, and its line type starts
         * there.  日影図.jww has a nearly level dotted line stored right to
         * left -- 0.008 mm out of level over 150 mm -- and the original
         * starts its dashes at the right-hand end.
         */
        double lo_u = c->x - 2 - v->bx, hi_u = c->x + c->w + 2 - v->bx;
        double lo_w = v->by - (c->y + c->h + 2), hi_w = v->by - (c->y - 2);
        int level = w0 == w1, upright = u0 == u1;
        double eu = u1 > u0 ? u1 - u0 : u0 - u1;
        double ew = w1 > w0 ? w1 - w0 : w0 - w1;
        int xmaj = level ? 1 : upright ? 0 : eu > ew;
        int act = level || upright;

        if (!act) {
            double lo = xmaj ? (u0 < u1 ? u0 : u1) : (w0 < w1 ? w0 : w1);
            double hi = xmaj ? (u0 > u1 ? u0 : u1) : (w0 > w1 ? w0 : w1);
            act = xmaj ? (lo < lo_u || hi >= hi_u) : (lo < lo_w || hi >= hi_w);
        }
        if (act) {
            if (xmaj) {
                if (u1 < u0) {
                    double t;
                    t = u0; u0 = u1; u1 = t;
                    t = w0; w0 = w1; w1 = t;
                }
                if (!clip_major(lo_u, hi_u, &u0, &w0, &u1, &w1))
                    return;
            } else {
                if (w1 < w0) {
                    double t;
                    t = u0; u0 = u1; u1 = t;
                    t = w0; w0 = w1; w1 = t;
                }
                if (!clip_major(lo_w, hi_w, &w0, &u0, &w1, &u1))
                    return;
            }
        }
    }
    x0 = v->bx + (int)u0; y0 = v->by - (int)w0;
    x1 = v->bx + (int)u1; y1 = v->by - (int)w1;
    dx = x1 > x0 ? x1 - x0 : x0 - x1;
    dy = y1 > y0 ? y1 - y0 : y0 - y1;

    if (bits == 0xffffffffu || phase) {
        /* a solid line, or a chord of an ellipse, which is walked whole so
         * the pattern can run on from one chord to the next */
        double step = phase ? *phase : 0.0;
        int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
        int xmaj = dx > dy, mj = xmaj ? dx : dy, mn = xmaj ? dy : dx;
        int tie = xmaj ? (sy < 0) : (sx < 0);
        int e = 2 * mn - mj, k;
        if ((outcode(c, x0, y0) & outcode(c, x1, y1)) != 0)
            return;
        for (k = 0; k <= mj; k++) {
            int i, j;
            if (bits_set(ltype, step, ppb))
                for (j = 0; j < wide; j++)
                    for (i = 0; i < wide; i++)
                        put(fb, c, x0 + i, y0 + j, col);
            step += 1.0;
            if (e > 0 || (e == 0 && tie)) {
                if (xmaj) y0 += sy; else x0 += sx;
                e -= 2 * mj;
            }
            e += 2 * mn;
            if (xmaj) x0 += sx; else y0 += sy;
        }
        if (phase)
            *phase = step;
        return;
    }

    /* A line type is not a mask over the line: the original walks the
     * pattern and draws each run of set bits as its own short line
     * (FUN_004bbef0).  Bit i sits at (int)(i * step) along the long axis and
     * the other axis follows the slope, truncated the same way, so a dashed
     * line does not take quite the same staircase as a solid one.
     *
     * The pattern is also stretched so a whole number of repeats fits: count
     * how many do, then divide the long axis by that many.  It therefore
     * always ends flush with the far end. */
    {
        int xmaj = dx > dy;
        int m0 = xmaj ? x0 : y0, m1 = xmaj ? x1 : y1;
        int n0 = xmaj ? y0 : x0, n1 = xmaj ? y1 : x1;
        int major = m1 > m0 ? m1 - m0 : m0 - m1;
        double stepm, stepn;
        int nbits, i;

        if (!major) {
            stroke(fb, c, x0, y0, x1, y1, col, wide, 0);
            return;
        }
        if (unit > 0) {
            double len = sqrt((double)dx * dx + (double)dy * dy);
            int reps = (int)(len / (unit * ppb));
            if (reps < 1)
                reps = 1;
            ppb = (double)major / (double)(unit * reps);
            if (ppb < 0.1)
                ppb = 0.1;
        }
        stepm = m1 > m0 ? ppb : -ppb;
        stepn = (double)(n1 - n0) / major * ppb;
        nbits = (int)(major / ppb) + 2;
        for (i = 0; i <= nbits; ) {
            int b, am, an, bm, bn, open;
            if (!(bits & (1u << (i % unit)))) {
                i++;
                continue;
            }
            b = i;
            while (b < nbits && (bits & (1u << ((b + 1) % unit))))
                b++;
            am = m0 + (int)(i * stepm);
            an = n0 + (int)(i * stepn);
            bm = m0 + (int)((b + 1) * stepm);
            bn = n0 + (int)((b + 1) * stepn);
            /* The last run stops at the end of the line, and that end is
             * drawn -- a solid line gets its far pixel too. */
            open = am != bm || an != bn;
            if (m1 > m0 ? bm >= m1 : bm <= m1) {
                bm = m1;
                bn = n1;
                open = 0;
            }
            if (xmaj)
                stroke(fb, c, am, an, bm, bn, col, wide, open);
            else
                stroke(fb, c, an, am, bn, bm, col, wide, open);
            i = b + 1;
        }
    }
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
    /* An element picked *in this session* is drawn in Pen/Color10 whatever
       its own colour is: the original's own screen has a live selection in
       ff00ff.  Not bit 1 of +0x44 -- that is what it writes to the file for
       whatever was picked at save time, and a drawing that arrives with the
       bit already set is not shown picked.  天空率表.jww ships with 245 of
       them and the original draws every one in its own pen. */
    if (o->sel)
        return JW_SEL_RGB;
    return pen_colour(d, o->color);
}

static int obj_wide(const jw_drawing *d, const jw_obj *o)
{
    return pen_wide(d, o->color);
}

/* A circle, the way GDI draws it.  Jw_cad hands Arc the box
 * (cx-r, cy-r)-(cx+r, cy+r); those corners are exclusive, so the circle sits
 * half a pixel up and to the left of the centre pixel -- drawing it centred
 * on the pixel puts every pixel of it in the wrong place.  The boundary is
 * the textbook midpoint ellipse, which is the family GDI's own is from.
 *
 * The points come out in order round the circle so a line type can advance
 * along it, and so an arc can start where it is told to.
 *
 * Up to radius 256 the quadrant is GDI's own, written down by asking it
 * (src/gen/circle.h, tools/gdicirc.c).  GDI's circle is not the textbook
 * midpoint one -- for radius 5 the textbook walk goes (0,5) (1,5) (2,5)
 * (3,4) and GDI's goes (0,5) (1,5) (2,4) (3,4) -- and nothing as simple as a
 * fudged radius reproduces it.  Past 256 the midpoint ellipse below is used
 * instead, which is the right family but not the same curve.
 */
#define ARC_MAX 65536

/* Fill the quadrant from GDI's own walk.  Returns how many points, or 0 if
   that radius is not in the table. */
static int circle_table(int rp, int odd, short *qx, short *qy)
{
    const unsigned short *off = odd ? jw_circ_off1 : jw_circ_off0;
    const unsigned short *len = odd ? jw_circ_len1 : jw_circ_len0;
    const unsigned char *bits = odd ? jw_circ_bits1 : jw_circ_bits0;
    int n = 0, x = 0, y = rp, i, base, steps;

    if (rp < 1 || rp > JW_CIRC_RMAX || len[rp] == 0)
        return 0;
    base = off[rp];
    steps = len[rp];
    qx[n] = 0;
    qy[n] = (short)rp;
    n++;
    for (i = 0; i < steps; i++) {
        int k = base + i;
        int c = (bits[k >> 2] >> ((k & 3) * 2)) & 3;
        if (c != 1)
            x++;
        if (c != 0)
            y--;
        qx[n] = (short)x;
        qy[n] = (short)y;
        n++;
    }
    return n;
}

static int circle_points(int rp, int odd, short *out)
{
    /* the first quadrant, from (0, r) to (r, 0) */
    static short qx[ARC_MAX / 8], qy[ARC_MAX / 8];
    long rx2 = (long)rp * rp, ry2 = (long)rp * rp;
    long px = 0, py = 2 * rx2 * rp;
    double p;
    int x = 0, y = rp, nq = 0, n = 0, i;

    if (rp <= 0 || rp >= ARC_MAX / 8 - 2)
        return 0;
    nq = circle_table(rp, odd, qx, qy);
    if (nq > 0)
        goto mirror;
    qx[nq] = (short)x; qy[nq] = (short)y; nq++;
    p = (double)ry2 - (double)rx2 * rp + 0.25 * rx2;
    while (px < py) {
        x++;
        px += 2 * ry2;
        if (p < 0) {
            p += ry2 + px;
        } else {
            y--;
            py -= 2 * rx2;
            p += (double)ry2 + px - py;
        }
        qx[nq] = (short)x; qy[nq] = (short)y; nq++;
    }
    p = (double)ry2 * (x + 0.5) * (x + 0.5)
      + (double)rx2 * (y - 1) * (y - 1) - (double)rx2 * ry2;
    while (y > 0) {
        y--;
        py -= 2 * rx2;
        if (p > 0) {
            p += (double)rx2 - py;
        } else {
            x++;
            px += 2 * ry2;
            p += (double)rx2 - py + px;
        }
        qx[nq] = (short)x; qy[nq] = (short)y; nq++;
    }

    /* Round the circle, starting at three o'clock and going anticlockwise on
     * screen (which is the direction the file's angles run).  An odd box is
     * centred on the pixel, an even one half a pixel up and to the left, so
     * the two sides of each axis come from different offsets. */
mirror:
    {
        int lo = odd ? 0 : -1;               /* the right and bottom sides  */
        for (i = nq - 1; i >= 0; i--) {      /* 0 to 90 degrees   */
            out[2 * n] = (short)(qx[i] + lo); out[2 * n + 1] = (short)(-qy[i]); n++;
        }
        for (i = 0; i < nq; i++) {           /* 90 to 180         */
            out[2 * n] = (short)(-qx[i]); out[2 * n + 1] = (short)(-qy[i]); n++;
        }
        for (i = nq - 1; i >= 0; i--) {      /* 180 to 270        */
            out[2 * n] = (short)(-qx[i]); out[2 * n + 1] = (short)(qy[i] + lo); n++;
        }
        for (i = 0; i < nq; i++) {           /* 270 to 360        */
            out[2 * n] = (short)(qx[i] + lo); out[2 * n + 1] = (short)(qy[i] + lo); n++;
        }
    }
    return n;
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
    int n, i, idx;
    double px = 0, py = 0;

    if (flat <= 0.0)
        flat = 1.0;
    sweep = sw;
    /* A negative sweep runs clockwise -- the door swings of
     * Ａマンション平面例.jww are stored that way.  Only a sweep of nothing
     * means the whole circle. */
    if (sweep == 0.0)
        sweep = 2 * PI;

    /* A true circle goes through GDI's Arc; anything squashed does not, so
     * that keeps the chord walk below. */
    if (flat == 1.0) {
        static short pts[2 * ARC_MAX];
        int rp = (int)(r / v->mmpp + 0.5);     /* FUN_004b8250 */
        int cxp = jw_sx(v, cx), cyp = jw_sy(v, cy);
        /* A whole circle goes into a box 2r across, a part of one into a box
         * 2r+1 across -- FUN_00421490 passes cx+r+1 in the second case and
         * cx+r in the first.  So a whole circle is half a pixel off centre
         * and an arc is not. */
        /* A whole circle goes into a box 2r across, a part of one into a box
         * 2r+1 -- but only while it is solid.  Drawn dashed, the original's
         * whole circle comes out on the bigger ring: a 40 mm circle at this
         * scale has its solid outline centred on 435.50,278.49 with a mean
         * radius of 64.32 and its dashed one on 436.54,279.30 at 65.11,
         * while the port drew both the same.  Reading it as "a dashed circle
         * is drawn as arcs, and an arc gets the 2r+1 box" takes
         * 天空率表.jww from 2,451 mismatched pixels to 2,016. */
        int odd = !(sweep >= 2 * PI || sweep <= -2 * PI) || lt != 1;
        /* debugging hook: write the boundary walk out, so a render can be
           sampled along it and held against the original's */
        int dumpwalk = getenv("JW_ARC_WALK") != 0;
        int n = circle_points(rp, odd, pts);
        if (n > 0) {
            int full = !odd;
            double a = a0 + tilt;
            int step = sweep < 0 ? -1 : 1;
            double span = sweep < 0 ? -sweep : sweep;
            int start = 0, i, j;
            double bestd = 1e9;

            /* Which boundary pixel the arc starts on.  The pixels are not
             * spaced evenly in angle, so ask each one rather than working
             * the index out from the fraction of a turn.  A pixel at offset
             * (a, b) has its centre at (a + 1, b + 1) from the middle of the
             * circle, which sits half a pixel up and left. */
            for (idx = 0; idx < n; idx++) {
                double t = atan2(-(double)pts[2 * idx + 1] - (odd ? 0.0 : 1.0),
                                 (double)pts[2 * idx] + (odd ? 0.0 : 1.0));
                double dd = t - a;
                while (dd <= -PI) dd += 2 * PI;
                while (dd > PI) dd -= 2 * PI;
                if (dd < 0) dd = -dd;
                if (dd < bestd) { bestd = dd; start = idx; }
            }
            if (full)
                span = 2 * PI;
            for (idx = 0; idx < n; idx++) {
                int m = (start + step * idx) % n;
                int sx, sy;
                if (m < 0) m += n;
                if (!full && idx) {
                    /* stop once the walk has covered the sweep */
                    double t = atan2(-(double)pts[2 * m + 1] - (odd ? 0.0 : 1.0),
                                     (double)pts[2 * m] + (odd ? 0.0 : 1.0));
                    double dd = step > 0 ? t - a : a - t;
                    while (dd < 0) dd += 2 * PI;
                    while (dd >= 2 * PI) dd -= 2 * PI;
                    if (dd > span)
                        break;
                }
                sx = cxp + pts[2 * m];
                sy = cyp + pts[2 * m + 1];
                if (bits_set(lt, phase, ppb))
                    for (j = 0; j < wide; j++)
                        for (i = 0; i < wide; i++)
                            put(fb, &v->clip, sx + i, sy + j, col);
                phase += 1.0;
                if (dumpwalk)
                    fprintf(stderr, "walk %d %d %d %.3f\n", idx, sx, sy, phase);
            }
            return;
        }
    }

    n = (int)(r * v->scale * (sweep < 0 ? -sweep : sweep)) + 8;
    if (n > 8192)
        n = 8192;
    ct = cos(tilt);
    st = sin(tilt);
    for (i = 0; i <= n; i++) {
        double t = a0 + sweep * i / n;
        double ux = r * cos(t), uy = r * flat * sin(t);
        double sx = jw_ux(v, cx + ux * ct - uy * st);
        double sy = jw_uy(v, cy + ux * st + uy * ct);
        if (i)
            line(fb, v, px, py, sx, sy, col, wide, lt, ppb, &phase);
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

    /* debugging hooks, like shown()'s: leave the solids out, or say where
       each one lands on the screen */
    if (getenv("JW_NO_SOLID"))
        return;
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
    if (getenv("JW_DUMP_SOLID"))
        fprintf(stderr, "solid %d (%d,%d) (%d,%d) (%d,%d) (%d,%d) colour %d layer %d/%d\n",
                n, px[0], py[0], px[1], py[1], px[2], py[2], px[3], py[3],
                (int)o->color, (int)o->lgroup, (int)o->layer);
    ymin = ymax = py[0];
    for (i = 1; i < n; i++) {
        if (py[i] < ymin) ymin = py[i];
        if (py[i] > ymax) ymax = py[i];
    }
    if (ymin < v->clip.y) ymin = v->clip.y;
    if (ymax > v->clip.y + v->clip.h) ymax = v->clip.y + v->clip.h;
    /* GDI's fill leaves the right and bottom edges out, and the original
     * selects a null pen so nothing draws them back in: asked directly, a
     * Polygon over (17,4)-(20,50) covers x 17..19 and y 4..49, not 17..20 and
     * 4..50 (tools/gdipoly.c).  Taking both edges in made every solid a pixel
     * wider and a pixel taller, which on the thin walls of
     * Ａマンション平面例.jww is most of the element -- 79 of them covered
     * 7,809 pixels against the original's 3,818. */
    for (y = ymin; y < ymax; y++) {
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
            if (b > v->clip.x + v->clip.w) b = v->clip.x + v->clip.w;
            for (; a < b; a++)
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
        case JW_SEN:
            line(fb, v, jw_ux(v, o->d[0]), jw_uy(v, o->d[1]),
                 jw_ux(v, o->d[2]), jw_uy(v, o->d[3]), col, wide,
                 line_type(o), pix_per_bit(v), 0);
            break;
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

void jw_draw_sel(fb_t *fb, const jw_view *v, const jw_drawing *d,
                 double dx, double dy)
{
    jw_drawing one = *d;
    jw_obj o;
    int i;

    one.obj = &o;
    one.nobj = one.ndrawn = 1;
    for (i = 0; i < d->ndrawn; i++) {
        if (!(d->obj[i].flags & 2))
            continue;
        o = d->obj[i];
        jw_obj_move(&o, dx, dy);
        jw_draw(fb, v, &one);
    }
}

void jw_draw_box(fb_t *fb, const jw_view *v,
                 double x0, double y0, double x1, double y1)
{
    double a = jw_ux(v, x0), b = jw_uy(v, y0);
    double c = jw_ux(v, x1), e = jw_uy(v, y1);
    double ppb = pix_per_bit(v);

    line(fb, v, a, b, c, b, JW_RANGE_RGB, 1, 1, ppb, 0);
    line(fb, v, c, b, c, e, JW_RANGE_RGB, 1, 1, ppb, 0);
    line(fb, v, c, e, a, e, JW_RANGE_RGB, 1, 1, ppb, 0);
    line(fb, v, a, e, a, b, JW_RANGE_RGB, 1, 1, ppb, 0);
}
