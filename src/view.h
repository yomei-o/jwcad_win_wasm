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

typedef struct {
    double scale;       /* pixels per millimetre of paper */
    double cx, cy;      /* where paper (0,0) lands, in client pixels */
    rect_t clip;        /* the drawing area */
} jw_view;

extern double jw_fit_inset, jw_fit_dx, jw_fit_dy;
extern double jw_round_x, jw_round_y;
extern int jw_line_open;
extern double jw_mm_per_bit;

/* Fit a sheet of half-width hw and half-height hh into r. */
void jw_view_fit(jw_view *v, const rect_t *r, double hw, double hh);

/* Rounding, not truncation: measured against the reference screens, rounding
   puts about 500 more pixels of Test1.jww in the right place. */
static __inline int jw_sx(const jw_view *v, double x)
{
    return (int)(v->cx + x * v->scale + jw_round_x);
}

static __inline int jw_sy(const jw_view *v, double y)
{
    return (int)(v->cy - y * v->scale + jw_round_y);
}

#endif
