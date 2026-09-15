#include "view.h"

void jw_view_fit(jw_view *v, const rect_t *r, double hw, double hh)
{
    double sx = hw > 0 ? r->w / (2 * hw) : 1.0;
    double sy = hh > 0 ? r->h / (2 * hh) : 1.0;

    /* The original's own fit comes out a shade under the naive one -- the
     * reference screen of Test1.jww (A2, 686 pixels of height) is at
     * 1.63125 px/mm where 686/420 would be 1.63333.  Where the difference
     * comes from is still to be read out of CGamenJoken; until then this is
     * the naive fit and the last 0.1% of the drawing's position is wrong. */
    v->scale = sx < sy ? sx : sy;
    v->cx = r->x + r->w / 2.0;
    v->cy = r->y + r->h / 2.0;
    v->clip = *r;
}
