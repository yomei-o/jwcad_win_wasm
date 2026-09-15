#include "view.h"

/* Knobs for tools/calibrate: how much smaller than the drawing area the
 * original measures its client, and where paper (0,0) lands.  The defaults
 * are what the samples say; nothing but the calibration tool moves them. */
double jw_fit_inset = 2.0;
double jw_fit_dx = 0.0;
double jw_fit_dy = 0.0;
double jw_round_x = 0.3;
double jw_round_y = 0.5;
/* GDI's LineTo leaves the last point out; 1 says do the same. */
int jw_line_open = 0;

void jw_view_fit(jw_view *v, const rect_t *r, double hw, double hh)
{
    /* Two pixels smaller than the white area, each way.  The original's
     * CJw_winView::OnDraw (0x00503020) takes the millimetres per pixel as
     *     max(sheet width / client width, sheet height / client height)
     * -- FUN_004b7630, mode 2 -- and divides by the zoom, which starts at 1.
     * The client it measures is two pixels short of the white rectangle on
     * the screen; fitting the samples says so plainly (the total mismatch of
     * five drawings goes 34,019 -> 23,584 -> 22,303 for 0, -1 and -2, and
     * back up to 28,467 at -3). */
    double sx = hw > 0 ? (r->w - jw_fit_inset) / (2 * hw) : 1.0;
    double sy = hh > 0 ? (r->h - jw_fit_inset) / (2 * hh) : 1.0;

    /* The original comes out a few parts in a thousand under this: fitting
     * Test1.jww (A2) by its long lines gives 1.6305 px/mm where 686/420 is
     * 1.63333, and Test7.jww (A3) gives 2.299 where 686/297 is 2.30976.
     * Both are within the noise of measuring off a screen grab, so this is
     * the naive fit until CGamenJoken says otherwise -- the cost is the odd
     * pixel at the far edges of a drawing. */
    v->scale = sx < sy ? sx : sy;
    v->cx = r->x + r->w / 2.0 + jw_fit_dx;
    v->cy = r->y + r->h / 2.0 + jw_fit_dy;
    v->clip = *r;
}
