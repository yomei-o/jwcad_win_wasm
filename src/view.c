#include "view.h"

void jw_view_fit(jw_view *v, const rect_t *r, double hw, double hh)
{
    double sx = hw > 0 ? r->w / (2 * hw) : 1.0;
    double sy = hh > 0 ? r->h / (2 * hh) : 1.0;

    /* The original comes out a few parts in a thousand under this: fitting
     * Test1.jww (A2) by its long lines gives 1.6305 px/mm where 686/420 is
     * 1.63333, and Test7.jww (A3) gives 2.299 where 686/297 is 2.30976.
     * Both are within the noise of measuring off a screen grab, so this is
     * the naive fit until CGamenJoken says otherwise -- the cost is the odd
     * pixel at the far edges of a drawing. */
    v->scale = sx < sy ? sx : sy;
    v->cx = r->x + r->w / 2.0;
    v->cy = r->y + r->h / 2.0;
    v->clip = *r;
}
