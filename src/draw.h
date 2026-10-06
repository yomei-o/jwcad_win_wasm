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

/* one bit of a line type's pattern, for drawing a sample of it */
int jw_ltype_bit(int ltype, int i);

/* 基本設定 の 色・画面 の、図面に属さない色の行（13 グレー・
   15 選択色・16 仮表示色）。行番号は原典の CGamenPage の受け手
   FUN_004c4af0 に渡るものと同じです。 */
unsigned int jw_row_rgb(int row);
int jw_row_rgb_set(int row, unsigned int rgb);

#endif
