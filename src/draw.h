/* Drawing a .jww into the framebuffer. */
#ifndef JW_DRAW_H
#define JW_DRAW_H

#include "fb.h"
#include "jww.h"
#include "view.h"

void jw_draw(fb_t *fb, const jw_view *v, const jw_drawing *d);

#endif
