/* Drawing a .jww into the framebuffer. */
#ifndef JW_DRAW_H
#define JW_DRAW_H

#include "fb.h"
#include "jww.h"
#include "view.h"

/* While this is set, jw_draw paints everything in 仮表示色 instead of
   each element's own pen -- which is what the original does with the
   figure a command is part way through (see obj_colour in src/draw.c). */
extern int jw_draw_kari;

void jw_draw(fb_t *fb, const jw_view *v, const jw_drawing *d);

/* The selection being dragged: every picked element drawn again dx,dy away,
   in the colour a picked element has.  What it shows is what a click will
   make. */
void jw_draw_sel(fb_t *fb, const jw_view *v, const jw_drawing *d,
                 double dx, double dy);
/* The range box, in the colour the original draws it (src/gen/pens.h). */
void jw_draw_box(fb_t *fb, const jw_view *v,
                 double x0, double y0, double x1, double y1);

/* one bit of a line type's pattern, for drawing a sample of it */
int jw_ltype_bit(int ltype, int i);

#endif
