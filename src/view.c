#include "view.h"

/* Knobs for tools/calibrate: how much smaller than the drawing area the
 * original measures its client, and where paper (0,0) lands.  The defaults
 * are what the samples say; nothing but the calibration tool moves them. */
double jw_fit_inset = 0.0;
double jw_fit_dx = 0.0;
double jw_fit_dy = 0.0;
double jw_round_x = 0.0;
double jw_round_y = 0.0;
/* GDI's LineTo leaves the last point out; 1 says do the same. */
int jw_line_open = 0;
/* How much paper one bit of a line type covers; 0 means one pixel. */
double jw_mm_per_bit = 0.0;
/* Fit a whole number of line-type repeats to each line (FUN_004bbef0). */
int jw_stretch = 1;
int jw_bitpick = 2;

void jw_view_fit(jw_view *v, const rect_t *r, double hw, double hh)
{
    /* The original's CJw_winView::OnDraw (0x00503020) takes the millimetres
     * per pixel as
     *     max(sheet width / client width, sheet height / client height)
     * -- FUN_004b7630, mode 2 -- and divides by the zoom, which starts at 1.
     * The client is the white rectangle itself: an earlier reading took it
     * two pixels smaller, which only looked better because the rounding was
     * wrong as well. */
    double sx = hw > 0 ? (r->w - jw_fit_inset) / (2 * hw) : 1.0;
    double sy = hh > 0 ? (r->h - jw_fit_inset) / (2 * hh) : 1.0;

    v->scale = sx < sy ? sx : sy;
    v->ox = jw_fit_dx;
    v->oy = jw_fit_dy;
    v->bx = (int)(r->x + r->w / 2);
    v->by = (int)(r->y + r->h / 2);
    v->clip = *r;
}
