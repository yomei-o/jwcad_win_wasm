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

static __inline int jw_sx(const jw_view *v, double x)
{
    return v->bx + (int)((x - v->ox) * v->scale + jw_round_x);
}

static __inline int jw_sy(const jw_view *v, double y)
{
    return v->by - (int)((y - v->oy) * v->scale + jw_round_y);
}

#endif
