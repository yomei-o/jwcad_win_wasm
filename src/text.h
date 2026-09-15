/* Drawing a Jw_cad text run.
 *
 * A .jww text carries the two ends of its baseline and the size of one
 * character in millimetres of paper, so where each character goes is fixed by
 * the file.  The glyphs are not: the original asks Windows for ＭＳ ゴシック
 * and the port has a public-domain bitmap font instead (src/fontx.h).
 */
#ifndef JW_TEXT_H
#define JW_TEXT_H

#include "fb.h"
#include "view.h"

/* `s` is CP932.  (x0,y0) is the left end of the baseline, (x1,y1) the right;
 * cw and ch are one character's size in paper millimetres. */
/* Straight onto the screen at one pixel per font pixel, for the bars.  `s` is
   CP932; returns where the next character would start. */
int jw_text_px(fb_t *fb, int x, int y, const char *s, unsigned int col);

void jw_text(fb_t *fb, const jw_view *v, const char *s,
             double x0, double y0, double x1, double y1,
             double cw, double ch, unsigned int col);

#endif
