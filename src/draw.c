#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "draw.h"
#include "gen/circle.h"
#include "gen/pens.h"
#include "gen/wide.h"
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
    { 0x44444444u,  4 },        /* 9 補助線     */
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

/* The table in gen/wide.h is indexed by the width and by the offset across
 * the line; this hands back one row of it. */
static const signed char *wide_row(int wide, int xmaj, int d)
{
    int w = wide >= 1 && wide <= JW_WIDE_MAX ? wide : 1;

    return xmaj ? JW_WIDE_H[w - 1][d] : JW_WIDE_V[w - 1][d];
}

/* One pass along the line, offset across it by (ox, oy) and running from `a`
 * steps before its first pixel to `b` steps after its last.  A negative `b`
 * stops short: that is how GDI's LineTo leaves its last point out. */
static void stroke_at(fb_t *fb, const rect_t *c, int x0, int y0, int x1,
                      int y1, unsigned int col, int ox, int oy, int a, int b)
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
    int sxm = xmaj ? sx : 0, sym = xmaj ? 0 : sy;
    int e = 2 * mn - mj;
    int k, last = mj + (b < 0 ? b : 0);
    /* a positive `a` is the other way round: the outermost row of a level
       line starts a pixel late, so the walk skips that many */
    int first = a > 0 ? a : 0;

    /* the ends the round cap adds, straight on along the long axis */
    for (k = a; k < 0; k++)
        put(fb, c, x0 + sxm * k + ox, y0 + sym * k + oy, col);
    for (k = 0; k <= last; k++) {
        if (k >= first)
            put(fb, c, x0 + ox, y0 + oy, col);
        if (e > 0 || (e == 0 && tie)) {
            if (xmaj) y0 += sy; else x0 += sx;
            e -= 2 * mj;
        }
        e += 2 * mn;
        if (xmaj) x0 += sx; else y0 += sy;
    }
    for (k = 1; k <= b; k++)
        put(fb, c, x1 + sxm * k + ox, y1 + sym * k + oy, col);
}

/* A line as wide as its pen, the way GDI draws it -- Jw_cad goes through
 * LineTo with CreatePen(PS_SOLID, width, colour) (FUN_004db560).
 *
 * A wide line is not a square stamp walked along the line.  GDI rounds the
 * ends off, and for an even width it is not symmetric: the extra pixels go
 * above a level line and to the left of an upright one, and the outermost
 * row of a level one starts a pixel late.  tools/gdiwide.c asks GDI for all
 * of that, as a start and an end delta for each offset across the line, and
 * width 1 is in the same table (0, -1: LineTo leaves its last point out), so
 * this one loop covers every pen.
 *
 * `open` says whether to leave the last point out, as before: the caller
 * closes the last run of a dashed line so its far pixel is drawn. */
static void stroke(fb_t *fb, const rect_t *c, int x0, int y0, int x1, int y1,
                   unsigned int col, int wide, int open)
{
    int dx = x1 > x0 ? x1 - x0 : x0 - x1;
    int dy = y1 > y0 ? y1 - y0 : y0 - y1;
    int xmaj = dx > dy;
    int w = wide >= 1 && wide <= JW_WIDE_MAX ? wide : 1;
    int d;

    if ((outcode(c, x0, y0) & outcode(c, x1, y1)) != 0)
        return;
    for (d = 0; d < w; d++) {
        const signed char *t = wide_row(w, xmaj, d);
        int off = d - w / 2;

        stroke_at(fb, c, x0, y0, x1, y1, col, xmaj ? 0 : off,
                  xmaj ? off : 0, t[0], t[1] + (open ? 0 : 1));
    }
}

/* One pixel of a line, as wide as the pen.  A walk that goes pixel by pixel
 * -- a dotted line, a chord of an ellipse -- has no run to hand to stroke(),
 * so it stamps this instead: the shape the table gives in the middle of a
 * run, which is all such a walk can know. */
static void wide_dot(fb_t *fb, const rect_t *c, int x, int y,
                     unsigned int col, int wide, int xmaj)
{
    int w = wide >= 1 && wide <= JW_WIDE_MAX ? wide : 1;
    int d, t;

    if (w == 1) {
        put(fb, c, x, y, col);
        return;
    }
    for (d = 0; d < w; d++) {
        int off = d - w / 2, e = wide_row(w, xmaj, d)[1];

        for (t = -e; t <= e; t++)
            put(fb, c, xmaj ? x + t : x + off, xmaj ? y + off : y + t, col);
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

    if (bits == 0xffffffffu) {
        /* a solid line: every pixel of it */
        double step = 0.0;
        int sx = x0 < x1 ? 1 : -1, sy = y0 < y1 ? 1 : -1;
        int xmaj = dx > dy, mj = xmaj ? dx : dy, mn = xmaj ? dy : dx;
        int tie = xmaj ? (sy < 0) : (sx < 0);
        int e = 2 * mn - mj, k;
        if ((outcode(c, x0, y0) & outcode(c, x1, y1)) != 0)
            return;
        for (k = 0; k <= mj; k++) {
            if (bits_set(ltype, step, ppb))
                wide_dot(fb, c, x0, y0, col, wide, xmaj);
            step += 1.0;
            if (e > 0 || (e == 0 && tie)) {
                if (xmaj) y0 += sy; else x0 += sx;
                e -= 2 * mj;
            }
            e += 2 * mn;
            if (xmaj) x0 += sx; else y0 += sy;
        }
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
     * always ends flush with the far end.
     *
     * A chord of an arc (phase given) is the other case FUN_004bbef0 has.
     * The original passes it a 1 where a line gets a 0, and that turns the
     * stretching off: the pattern runs at its own size and its place in the
     * ring -- the 32-bit register the original rotates one bit at a time --
     * is carried from one chord to the next.  So a dashed arc is a run of
     * short straight lines whose dashes do not restart at every corner. */
    {
        int xmaj = dx > dy;
        int m0 = xmaj ? x0 : y0, m1 = xmaj ? x1 : y1;
        int n0 = xmaj ? y0 : x0, n1 = xmaj ? y1 : x1;
        int major = m1 > m0 ? m1 - m0 : m0 - m1;
        double stepm, stepn;
        int nbits, i, base = phase ? (int)*phase : 0;

        if (!major) {
            stroke(fb, c, x0, y0, x1, y1, col, wide, 0);
            return;
        }
        if (phase) {
            /* how far the ring has turned by the end of this chord: the
             * original steps while the truncated position is still short of
             * the far end, so it is one bit per step of ppb, rounded up */
            *phase = base + ceil((double)major / ppb);
        } else if (unit > 0) {
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
            if (phase && (m1 > m0 ? m0 + (int)(i * stepm) >= m1
                                  : m0 + (int)(i * stepm) <= m1))
                break;
            if (!(bits & (1u << ((base + i) % unit)))) {
                i++;
                continue;
            }
            b = i;
            while (b < nbits && (bits & (1u << ((base + b + 1) % unit))))
                b++;
            am = m0 + (int)(i * stepm);
            an = n0 + (int)(i * stepn);
            bm = m0 + (int)((b + 1) * stepm);
            bn = n0 + (int)((b + 1) * stepn);
            /* The last run stops at the end of the line, and that end is
             * drawn -- a solid line gets its far pixel too.  A chord does
             * not: its far end belongs to the chord after it, and the arc
             * puts the very last point down itself. */
            open = am != bm || an != bn;
            if (m1 > m0 ? bm >= m1 : bm <= m1) {
                bm = m1;
                bn = n1;
                open = phase != 0;
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

/* The width of a pen, from the drawing's own table.  Test3.jww has pen 6 at
 * 2, 7 at 3 and 8 at 5, and the original draws them that wide: its blue
 * dashed border comes out on rows 559 and 560 where the port had only 560,
 * and on columns 427 and 428 where it had only 428.  That is 533 pixels of
 * Test3.jww on its own. */
static int pen_wide(const jw_drawing *d, int pen)
{
    int w = pen >= 1 && pen <= 9 ? d->pen_width[pen] : 1;

    return w >= 1 && w <= JW_WIDE_MAX ? w : 1;
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

/* Which way the arc's end really points.  FUN_00421490 does not hand GDI an
 * angle: it hands it the *pixel* the ray lands on, and it gets there by
 * truncating -- `(int)(rp * cos a)` across and `-(int)(rp * sin a)` down.
 * GDI then takes the ray through that whole pixel, so an end at 30 degrees
 * on a radius of 24 is really an end at atan2(12, 20) = 30.96 degrees.  The
 * difference is under a degree but it moves the last pixel of the walk, and
 * over half of what is left of the residue sits within three pixels of an
 * arc's end. */
static double ray_angle(int rp, double a)
{
    int x = (int)(rp * cos(a)), y = (int)(rp * sin(a));

    if (!x && !y)
        return a;
    return atan2((double)y, (double)x);
}

/* FUN_00421490 asks GDI for the boundary only while the *centre* of the
 * circle is inside the drawing area -- the four tests against the window in
 * millimetres (doc+0x79f8, +0x7a00, +0x7a08, +0x7a10) that sit next to the
 * line-type test and jump to the polyline with it.  The printing side
 * (around line 31175 of all_00401000.c) spells the same four out the other
 * way round, as the condition for taking the GDI arm.  So a circle whose
 * middle has been scrolled off the edge is drawn as a chord walk, on the
 * other ring. */
static int centre_inside(const jw_view *v, double cx, double cy)
{
    static int anywhere = -1;
    int x, y;

    if (anywhere < 0)
        anywhere = getenv("JW_ARC_ANYWHERE") != 0;
    if (anywhere)
        return 1;
    x = jw_sx(v, cx);
    y = jw_sy(v, cy);
    return x > v->clip.x && x < v->clip.x + v->clip.w &&
           y > v->clip.y && y < v->clip.y + v->clip.h;
}

/* An arc: centre, radius, flattening, start and end angle, tilt.  A solid
 * circle goes through GDI's own boundary; anything else is a polyline, and
 * the two do not land on the same ring. */
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
    int idx;
    double px = 0, py = 0;

    if (flat <= 0.0)
        flat = 1.0;
    sweep = sw;
    /* A negative sweep runs clockwise -- the door swings of
     * Ａマンション平面例.jww are stored that way.  Only a sweep of nothing
     * means the whole circle. */
    if (sweep == 0.0)
        sweep = 2 * PI;

    /* A true solid circle goes through GDI's Arc; anything squashed does
     * not, and neither does anything dashed, so both keep the chord walk
     * below.  FUN_00421490 asks for the GDI arc only when the line type's
     * entry in the table at +0x2fc4 is -1, which is what 実線 has: with any
     * other type it jumps straight to the polyline. */
    if (flat == 1.0 && LTYPE[lt].bits == 0xffffffffu
        && centre_inside(v, cx, cy)) {
        static short pts[2 * ARC_MAX];
        int rp = (int)(r / v->mmpp + 0.5);     /* FUN_004b8250 */
        int cxp = jw_sx(v, cx), cyp = jw_sy(v, cy);
        /* A whole circle goes into a box 2r across, a part of one into a box
         * 2r+1 across -- FUN_00421490 passes cx+r+1 in the second case and
         * cx+r in the first.  So a whole circle is half a pixel off centre
         * and an arc is not.
         *
         * Only a solid one comes through here at all, so the line type does
         * not enter into it: a dashed circle is a polyline, and its ring is
         * the one the chord walk lands on -- which is why the original's
         * dashed 40 mm circle measures 65.11 about 436.54,279.30 where its
         * solid one measures 64.32 about 435.50,278.49. */
        /* Whole or not: the original's test is `6.283185207179586 < |sweep|`
           -- a tenth of a microradian short of a turn, not a turn.  A file
           that stores its circles a hair under 2 pi (and some do) would
           otherwise land on the arc's ring, half a pixel off the circle's. */
        int odd = !(sweep > 2 * PI - 1e-7 || sweep < -(2 * PI - 1e-7));
        /* A whole circle under two pixels across is not drawn as a circle
         * at all: FUN_00421490 moves to the centre and draws the one pixel
         * (the `if (local_e8 < 2)` arm, MoveTo then LineTo one to the
         * right).  Only the whole-circle arm has it; a part of one goes
         * through the boundary walk however small it is. */
        if (!odd && rp < 2) {
            put(fb, &v->clip, cxp, cyp, col);
            return;
        }
        /* debugging hook: write the boundary walk out, so a render can be
           sampled along it and held against the original's */
        int dumpwalk = getenv("JW_ARC_WALK") != 0;
        int n = circle_points(rp, odd, pts);
        if (n > 0) {
            int full = !odd;
            double a = a0 + tilt;
            int step = sweep < 0 ? -1 : 1;
            double span = sweep < 0 ? -sweep : sweep;
            int start = 0;
            double bestd = 1e9;
            static int rays = -1;

            if (rays < 0)
                rays = getenv("JW_ARC_NORAY") == 0;
            if (rays && !full) {
                double e = ray_angle(rp, a + sweep);
                a = ray_angle(rp, a);
                span = step > 0 ? e - a : a - e;
                while (span < 0) span += 2 * PI;
                while (span >= 2 * PI) span -= 2 * PI;
            }

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
                    wide_dot(fb, &v->clip, sx, sy, col, wide, 1);
                phase += 1.0;
                if (dumpwalk)
                    fprintf(stderr, "walk %d %d %d %.3f\n", idx, sx, sy, phase);
            }
            return;
        }
    }

    /* The polyline (FUN_0042e140).  The step in angle is not a fraction of
     * the sweep, and it is not a fraction of the arc on screen either: the
     * original takes the bigger half axis **in the drawing's own
     * millimetres** and looks it up in a fixed ladder.  So the same circle
     * is chopped the same way however far it is zoomed in, and a 100 mm one
     * gets 0.1 rad (63 chords round) where the screen measure would have
     * said 0.07.
     *
     * The value it looks up is `bigger half axis * doc[0x1728]`, and
     * doc[0x1728] is the numerator of the millimetres per pixel
     * (FUN_004b6d60 divides by doc[6000]/doc[0x1728]), so on screen it is 1.
     * That is also why printing needs the correction the original applies
     * just before this -- a ladder in millimetres knows nothing about how
     * fine the paper is. */
    {
        double big = flat > 1.0 ? r * flat : r;
        double da = big < 50.0    ? 0.2
                  : big < 125.0   ? 0.1
                  : big < 312.0   ? 0.07
                  : big < 781.0   ? 0.04
                  : big < 1953.0  ? 0.02
                  : big < 4882.0  ? 0.01
                  : big < 12200.0 ? 0.005
                  : big < 24400.0 ? 0.002
                                  : 0.001;
        double acc, span = sweep < 0 ? -sweep : sweep;

        if (sweep < 0)
            da = -da;
        ct = cos(tilt);
        st = sin(tilt);
        px = jw_ux(v, cx + r * cos(a0) * ct - r * flat * sin(a0) * st);
        py = jw_uy(v, cy + r * cos(a0) * st + r * flat * sin(a0) * ct);
        for (acc = da; span > (acc < 0 ? -acc : acc); acc += da) {
            double t = a0 + acc;
            double ux = r * cos(t), uy = r * flat * sin(t);
            double sx = jw_ux(v, cx + ux * ct - uy * st);
            double sy = jw_uy(v, cy + ux * st + uy * ct);

            line(fb, v, px, py, sx, sy, col, wide, lt, ppb, &phase);
            px = sx;
            py = sy;
        }
        {   /* and the last chord, which ends on the far end exactly */
            double t = a0 + sweep;
            double ux = r * cos(t), uy = r * flat * sin(t);
            double sx = jw_ux(v, cx + ux * ct - uy * st);
            double sy = jw_uy(v, cy + ux * st + uy * ct);

            line(fb, v, px, py, sx, sy, col, wide, lt, ppb, &phase);
            /* The far end itself is always put down, whatever the pattern
             * says: FUN_00436a20 moves to it and draws one pixel when the
             * chord is the last one and the pen is a thin one. */
            if (wide < 2)
                wide_dot(fb, &v->clip, v->bx + (int)sx, v->by - (int)sy,
                         col, wide, 1);
        }
    }
}

/* A solid is four corners, filled.  The fourth repeats the third when it is
 * a triangle.  Colour 10 means "any colour", and then the RGB sits in the
 * trailing long as a COLORREF. */
/* Fill a ring of points.  The same scanline rule the four-cornered solid
   below uses, so a round one and a straight one meet the same way. */
static void fill_ring(fb_t *fb, const jw_view *v, const short *pts, int n,
                      unsigned int col)
{
    int i, j, y, ymin, ymax;

    if (n < 3)
        return;
    ymin = ymax = pts[1];
    for (i = 1; i < n; i++) {
        if (pts[2 * i + 1] < ymin) ymin = pts[2 * i + 1];
        if (pts[2 * i + 1] > ymax) ymax = pts[2 * i + 1];
    }
    if (ymin < v->clip.y) ymin = v->clip.y;
    if (ymax > v->clip.y + v->clip.h) ymax = v->clip.y + v->clip.h;
    for (y = ymin; y < ymax; y++) {
        int xs[512], m = 0;

        for (i = 0, j = n - 1; i < n; j = i++) {
            int y0 = pts[2 * j + 1], y1 = pts[2 * i + 1];

            if ((y0 <= y) == (y1 <= y) || m >= 512)
                continue;
            xs[m++] = pts[2 * j]
                    + (int)((double)(y - y0) * (pts[2 * i] - pts[2 * j])
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

/* 円ソリッド -- a solid whose line type is 101.  Its eight numbers are an
 * arc's: centre, radius, how flat, the turn, where it starts and how far it
 * goes, and a 5 on the end.  The original fills it with GDI; this walks the
 * same circle table src/draw.c's arcs use and fills the ring, which is the
 * right shape but not promised to the pixel -- none of the drawings to hand
 * has one to score against.
 */
static void round_solid(fb_t *fb, const jw_view *v, const jw_drawing *d,
                        const jw_obj *o)
{
    static short pts[2 * (ARC_MAX + 2)];
    double r = o->d[2], flat = o->d[6] > 0.0 ? 1.0 : 1.0;
    double a0 = o->d[5], sw = o->d[6], tilt = o->d[4], ratio = o->d[3];
    int rp = (int)(r / v->mmpp + 0.5), n = 0, k, steps;
    unsigned int col;

    (void)flat;
    if (rp < 1)
        return;
    if (ratio <= 0.0)
        ratio = 1.0;
    if (sw <= 0.0)
        sw = 2.0 * PI;
    if (sw > 2.0 * PI)
        sw = 2.0 * PI;
    col = o->color == 10
        ? (unsigned)(((o->n & 0xff) << 16) | (o->n & 0xff00)
                     | ((o->n >> 16) & 0xff))
        : obj_colour(d, o);
    /* A point every pixel or so along the rim, and nothing else: part of a
       circle is closed by the chord between its two ends rather than by the
       centre, which is a 弓形 and not a 扇形.  The original says so itself
       when it writes one out -- decomp/res/rsolid.sfc closes the boundary of
       its 45..270 solid with a two-point polyline between the ends. */
    steps = (int)(sw * rp) + 8;
    if (steps > ARC_MAX)
        steps = ARC_MAX;
    for (k = 0; k <= steps && n < ARC_MAX + 2; k++) {
        double t = a0 + sw * k / steps;
        double x = r * cos(t), y = r * ratio * sin(t);
        double ct = cos(tilt), st = sin(tilt);

        pts[2 * n] = (short)jw_sx(v, o->d[0] + x * ct - y * st);
        pts[2 * n + 1] = (short)jw_sy(v, o->d[1] + x * st + y * ct);
        n++;
    }
    fill_ring(fb, v, pts, n, col);
}

static void solid(fb_t *fb, const jw_view *v, const jw_drawing *d,
                  const jw_obj *o)
{
    int px[4], py[4], n = 4, i, j, y, ymin, ymax;
    unsigned int col;

    /* debugging hooks, like shown()'s: leave the solids out, or say where
       each one lands on the screen */
    if (getenv("JW_NO_SOLID"))
        return;
    if (o->ltype == 101) {      /* a round one, not four corners */
        round_solid(fb, v, d, o);
        return;
    }
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

/* A 図形: one of the definitions that follow the drawing, put where the
   reference says.  A definition's elements are kept straight after it in the
   same array (src/jww.c), so drawing one is drawing that stretch through the
   reference's own place, size and turn.  A definition that holds a further
   reference is followed too, but only so deep: one that somehow held itself
   would never finish. */
static void block(fb_t *fb, const jw_view *v, const jw_drawing *d,
                  const jw_obj *ref, int depth)
{
    jw_drawing one;
    jw_obj o;
    int i, at = -1;

    if (depth > 8)
        return;
    for (i = d->ndrawn; i < d->nobj; i++)
        if (d->obj[i].cls == JW_LIST && d->obj[i].list[0] == ref->block) {
            at = i;
            break;
        }
    if (at < 0)
        return;
    one = *d;
    one.obj = &o;
    one.nobj = one.ndrawn = 1;
    one.mesh_ix = one.mesh_iy = 0.0;    /* the grid is already down */
    for (i = at + 1; i < d->nobj && i <= at + d->obj[at].n; i++) {
        o = d->obj[i];
        if (o.cls == JW_LIST)
            break;              /* a definition of its own, not a member */
        if (o.cls == JW_BLOCK) {
            /* the inner reference, carried by the outer one */
            o.d[0] = o.d[0] * ref->d[2] + ref->d[0];
            o.d[1] = o.d[1] * ref->d[3] + ref->d[1];
            o.d[2] *= ref->d[2];
            o.d[3] *= ref->d[3];
            o.d[4] += ref->d[4];
            block(fb, v, d, &o, depth + 1);
            continue;
        }
        /* One scale, not two: an element can be turned and made bigger,
           but nothing in a drawing is stretched more one way than the
           other, so a reference with two different scales is drawn with
           the first of them. */
        jw_obj_xform(&o, 0.0, 0.0, ref->d[2], ref->d[4],
                     ref->d[0], ref->d[1]);
        jw_draw(fb, v, &one);
    }
}

void jw_draw(fb_t *fb, const jw_view *v, const jw_drawing *d)
{
    int i;

    /* 目盛 first of all: a grid of single pixels under the drawing.
     *
     * The drawing carries its own spacing and the least number of pixels it
     * is worth drawing at (jw_drawing's mesh_*).  Of the fifteen samples only
     * 木造平面例.jww has 9 mm rather than 5, and it is the only one the
     * original draws a grid for -- 9 mm at its A4 scale is 29.4 pixels and
     * the minimum is 15, while 5 mm never reaches 11.6.  That one rule covers
     * all fifteen.
     */
    if (d->mesh_ix > 0.0 && d->mesh_iy > 0.0
        && d->mesh_ix / v->mmpp >= d->mesh_min
        && d->mesh_iy / v->mmpp >= d->mesh_min) {
        /* over the whole drawing area, not just the sheet: the original's
           grid carries two more columns past each edge of the paper */
        double lx = v->ox + (v->clip.x - v->bx) * v->mmpp;
        double hx = v->ox + (v->clip.x + v->clip.w - v->bx) * v->mmpp;
        double ly = v->oy - (v->clip.y + v->clip.h - v->by) * v->mmpp;
        double hy = v->oy - (v->clip.y - v->by) * v->mmpp;
        double x0 = d->mesh_ox, y0 = d->mesh_oy, x, y;
        long k = (long)floor((lx - x0) / d->mesh_ix);
        long j0 = (long)floor((ly - y0) / d->mesh_iy);

        for (x = x0 + k * d->mesh_ix; x <= hx; x += d->mesh_ix)
            for (y = y0 + j0 * d->mesh_iy; y <= hy; y += d->mesh_iy)
                put(fb, &v->clip, jw_sx(v, x), jw_sy(v, y), d->pen_rgb[2]);
    }

    /* The solids go down first, and everything else on top of them.
     *
     * Not in element order: Ａマンション平面例.jww has 79 of them making its
     * walls, and taken in order they bury the lines that were drawn before
     * them -- 1,126 pixels the original has black and 1,086 it has cyan came
     * out grey.  Putting them all down first leaves those lines showing and
     * takes that drawing from 2,775 mismatched pixels to 568.
     */
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SOLID && shown(d, &d->obj[i]))
            solid(fb, v, d, &d->obj[i]);
    /* And the flat grey of the 表示のみ layers goes down before the rest of
     * the lines, not in element order.  日影図.jww is the one that says so:
     * its 表示のみ layers cross the editable ones all over, and taken in
     * order the grey buries 125 pixels the original has in black.  Drawing
     * the grey first takes that drawing from 400 mismatched pixels to 275.
     * (The solids above come first of all, for the same kind of reason.)
     *
     * The loop runs twice over the elements: once for the grey ones, once
     * for the rest. */
    for (i = 0; i < 2 * d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i % d->ndrawn];
        int grey_pass = i < d->ndrawn;
        int state = shown(d, o);

        if (!state || o->cls == JW_SOLID)
            continue;
        if ((state == 1) != grey_pass)
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
            int x = jw_sx(v, o->d[0]), y = jw_sy(v, o->d[1]), k;
            /* 実点 -- the trailing long is 1 -- wears a little ring; 仮点,
             * where it is 0, is the one pixel on its own.  The ring is the
             * same eleven pixels wherever it appears, and it is not
             * symmetric: read off two isolated points of Test3.jww, which
             * agreed exactly.  Whatever the original hands GDI, this is what
             * comes back.
             *
             *   dy\dx  -2  -1   0   1   2
             *    -2     .   #   #   .   .
             *    -1     #   .   .   #   .
             *     0     #   .   .   .   #
             *     1     #   .   .   .   #
             *     2     .   #   #   #   .
             *
             * **A 仮点 is not always one pixel.**  FUN_00424200 draws one
             * of four shapes -- a pixel, a cross, three rows (a filled 3 by
             * 3), five rows -- and picks between them on a setting at
             * doc+0x8238.  The shapes are plain enough in the fifteen
             * samples: Test1 to Test4 draw a cross, サンプル and
             * Ａマンション平面例 and 日影図 a filled 3 by 3, Test6 a single
             * pixel.
             *
             * **Which one, though, is not in the file.**  Every value
             * src/jww.c reads out of a header -- all 3,535 of them, bytes,
             * words, longs and doubles, the skipped ones as well -- was
             * held up drawing against drawing, and nothing separates the
             * three groups (RESUME.md, "仮点の形"); doc+0x8238 looks like a
             * registry setting, written with WriteProfileInt under "Point".
             * So this goes by what the element carries instead: bit 0x400
             * of +0x44 for the cross, nothing at all (or only the "came
             * from a 図形" bit) for the block.  It agrees with all fifteen
             * -- Test1 comes out to the pixel and the fifteen together drop
             * from 1,384 to 1,169 -- but it is a rule read off the samples,
             * not one read out of the original. */
            static const signed char RING[11][2] = {
                { -1, -2 }, { 0, -2 },
                { -2, -1 }, { 1, -1 },
                { -2, 0 }, { 2, 0 },
                { -2, 1 }, { 2, 1 },
                { -1, 2 }, { 0, 2 }, { 1, 2 },
            };
            put(fb, &v->clip, x, y, col);
            if (o->n == 1) {
                for (k = 0; k < 11; k++)
                    put(fb, &v->clip, x + RING[k][0], y + RING[k][1], col);
            } else if (o->flags & 0x400) {
                /* the cross: FUN_00424200's doc+0x8238 == 1 */
                put(fb, &v->clip, x - 1, y, col);
                put(fb, &v->clip, x + 1, y, col);
                put(fb, &v->clip, x, y - 1, col);
                put(fb, &v->clip, x, y + 1, col);
            } else if ((o->flags & ~0x40u) == 0) {
                /* three rows of three: doc+0x8238 == 2 */
                int i2, j2;
                for (j2 = -1; j2 <= 1; j2++)
                    for (i2 = -1; i2 <= 1; i2++)
                        put(fb, &v->clip, x + i2, y + j2, col);
            }
            break;
        }
        case JW_MOJI:
            jw_text(fb, v, jw_str(d, o->text), o->d[0], o->d[1],
                    o->d[2], o->d[3], o->d[4], o->d[5], col);
            break;
        case JW_BLOCK:
            block(fb, v, d, o, 0);
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
