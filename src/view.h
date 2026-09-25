/* Paper millimetres to screen pixels.
 *
 * A .jww stores every coordinate in millimetres on the sheet, with the origin
 * at the middle of it: an A2 sheet runs -297..297 by -210..210, and the file
 * keeps that corner (-297,-210) in its header.  The view puts the origin at
 * the middle of the drawing area and scales so the sheet fits.
 */
#ifndef JW_VIEW_H
#define JW_VIEW_H

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

static __inline int jw_sx(const jw_view *v, double x)
{
    return v->bx + jw_px_round((x - v->ox) / v->mmpp + jw_round_x);
}

static __inline int jw_sy(const jw_view *v, double y)
{
    return v->by - jw_px_round((y - v->oy) / v->mmpp + jw_round_y);
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
