/* Painting the frame: the bars around the drawing area.
 *
 * The whole window is drawn into one framebuffer, so the native build and the
 * browser build cannot diverge.  Nothing here asks the operating system for
 * anything -- the bitmaps come from the resources and the colours are fixed
 * in theme.h -- which is what makes the result comparable with the original
 * pixel for pixel.
 */
#ifndef JW_UI_H
#define JW_UI_H

#include "fb.h"
#include "jww.h"

/* The drawing area, in client coordinates, for a client of this size. */
void ui_view_rect(int cw, int ch, rect_t *r);

/* Paint everything except the drawing itself.  `d` may be NULL; when it is
   not, the layer bars show which layers the drawing uses and which one it is
   written to. */
void ui_paint(fb_t *fb, const jw_drawing *d, double zoom);

#endif
