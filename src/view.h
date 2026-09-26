/* Paper millimetres to screen pixels.
 *
 * A .jww stores every coordinate in millimetres on the sheet, with the origin
 * at the middle of it: an A2 sheet runs -297..297 by -210..210, and the file
 * keeps that corner (-297,-210) in its header.  The view puts the origin at
 * the middle of the drawing area and scales so the sheet fits.
 */
#ifndef JW_VIEW_H
#define JW_VIEW_H

#include <math.h>
#include <stdlib.h>

#include "fb.h"

/* The original's own shape, from FUN_004b6d60: a paper point (ox, oy) is
 * pinned to a whole pixel (bx, by), and everything else is that pixel plus
 * the offset in pixels, truncated.  Truncation towards zero, so the rounding
 * is symmetric about the pinned point -- and on the y axis the truncation
 * happens inside the subtraction, which rounds the other way.  Writing it as
 * "round(cy - y * scale)" is not the same thing and costs a pixel here and
 * there all over the picture. */
typedef struct {
    /* Millimetres per pixel, and the same thing the other way up.  Both are
     * kept because the original keeps both: it divides by the millimetres per
     * pixel (FUN_004b6d60, FUN_004b8250) and that is not the same arithmetic
     * as multiplying by its reciprocal.  The two disagree in the last bit,
     * and the truncation below turns that into a whole pixel wherever a
     * coordinate lands near a boundary. */
    double mmpp;        /* millimetres of paper per pixel -- divide by this */
    double scale;       /* pixels per millimetre of paper */
    double ox, oy;      /* the paper point that is pinned, in millimetres */
    int bx, by;         /* the pixel it is pinned to                      */
    rect_t clip;        /* the drawing area                               */
} jw_view;

extern double jw_fit_inset, jw_fit_dx, jw_fit_dy;
extern double jw_round_x, jw_round_y;
extern int jw_line_open;
extern double jw_mm_per_bit;
extern int jw_stretch;

/* Fit a sheet of half-width hw and half-height hh into r. */
void jw_view_fit(jw_view *v, const rect_t *r, double hw, double hh);

/* Millimetres of paper to a whole number of pixels.
 *
 * The cast is undefined when the value will not fit in an int, and it does
 * not take a damaged file to get there: jw_numbers_sane() lets a coordinate
 * reach 1e12, and a fitted sheet is about half a millimetre to the pixel, so
 * an honest read of a damaged drawing hands this 2e12.  A hundred million
 * pixels is already a hundred thousand screens away, so pinning there
 * changes nothing that can be seen -- it only keeps the conversion defined,
 * and it leaves room to subtract two of them without overflowing an int.
 * Written as !(p > lo) so that a NaN, which loses every comparison, falls
 * into the first clamp. */
static __inline int jw_px_round(double p)
{
    if (!(p > -1e8)) return -100000000;
    if (!(p <  1e8)) return  100000000;
    return (int)p;
}

/* JW_PX_FLOOR picks the rounding, for measuring rather than for use:
 *
 *   unset   0 towards zero, which is what FUN_004b6d60's (int) does
 *   "x"     x rounds down instead
 *   "y"     y rounds down *on the screen*, which is ceil here because the
 *           port takes by - this
 *   "xy"    both
 *
 * The question is real: the port's truncation is not symmetric about the
 * pinned pixel, so a point left of bx rounds one way and a point right of
 * it the other.  `Test6`'s blue wall starts at 158.138 and the original
 * paints 158 where the port paints 159 (docs\notes-pixels.md,「`Test6` の線は」).
 * An earlier note says flooring "both axes" costs 149,336 pixels -- but
 * flooring the y of `by - (int)(w)` rounds the screen y *up*, so that
 * measurement asked a different question from the one it meant to. */
static __inline int jw_px_mode(void)
{
    static int m = -1;
    if (m < 0) {
        const char *t = getenv("JW_PX_FLOOR");
        m = 0;
        if (t) {
            if (*t == 'x') m = 1;
            if (*t == 'y') m = 2;
            if (t[0] == 'x' && t[1] == 'y') m = 3;
        }
        t = getenv("JW_PX_MODE");
        if (t && *t)
            m = atoi(t);
    }
    return m;
}

/* The rounding a mode asks for.  Bit 0/1 are the floors above; 2/3 round the
 * other way and 4/5 round to the nearest.
 *
 * Why the last two are worth measuring: the port's truncation is toward
 * zero and the zero is the pinned pixel, so the drawing is cut in two --
 * 109 of `Ａマンション平面例`'s arc middles land left of it and round up,
 * 106 land right of it and round down.  If the original's own pinned pixel
 * is not in the same place, every middle between the two rounds differently.
 * Rounding the same way everywhere, or to the nearest, are the two shapes
 * that have no such seam, and neither has ever been put on the scoreboard.
 * FUN_004b6d60 reads as a plain (int), so this is a measurement, not a
 * reading. */
static __inline double jw_px_bend(double p, int lo)
{
    int m = jw_px_mode();
    if (m & (1 << lo))  return floor(p);
    if (m & (4 << lo))  return ceil(p);
    if (m & (16 << lo)) return floor(p + 0.5);
    return p;
}

static __inline int jw_sx(const jw_view *v, double x)
{
    double p = jw_px_bend((x - v->ox) / v->mmpp + jw_round_x, 0);
    return v->bx + jw_px_round(p);
}

static __inline int jw_sy(const jw_view *v, double y)
{
    /* by - this, so a floor here is the screen y rounded *up* */
    double p = jw_px_bend((y - v->oy) / v->mmpp + jw_round_y, 1);
    return v->by - jw_px_round(p);
}

/* The same, but before the rounding: how far across and up the point is from
 * the pinned pixel.  Cutting a line against the view has to happen here, not
 * after the rounding. */
static __inline double jw_ux(const jw_view *v, double x)
{
    return (x - v->ox) / v->mmpp;
}

static __inline double jw_uy(const jw_view *v, double y)
{
    return (y - v->oy) / v->mmpp;
}

#endif
