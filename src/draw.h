/* Drawing a .jww into the framebuffer. */
#ifndef JW_DRAW_H
#define JW_DRAW_H

#include "fb.h"
#include "jww.h"
#include "view.h"

void jw_draw(fb_t *fb, const jw_view *v, const jw_drawing *d);

/* The selection being dragged: every picked element drawn again dx,dy away,
   in the colour a picked element has.  What it shows is what a click will
   make. */
void jw_draw_sel(fb_t *fb, const jw_view *v, const jw_drawing *d,
                 double dx, double dy);
/* The range box, in the colour the original draws it (src/gen/pens.h). */
void jw_draw_box(fb_t *fb, const jw_view *v,
                 double x0, double y0, double x1, double y1);

#endif
