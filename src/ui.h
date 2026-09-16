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

/* How many millimetres of the screen one pixel is.  The status line's 倍率
 * is the view's scale times this -- the original asks GDI for the display's
 * own size (GetDeviceCaps HORZSIZE over HORZRES), so it is a property of the
 * machine, not of the drawing.  Measured off the reference screens, which
 * read 0.21, 0.3, 0.42 and 0.1 for A-2, A-3, A-4 and A-0 (scales 1.63333,
 * 2.30976, 3.26667 and 0.81570): those four bracket it to between 0.12988
 * and 0.13163, and 1/7.62 sits in the middle. */
#define JW_SCREEN_MM_PER_PX (1.0 / 7.62)

/* What state toolbar button `k` is in: 0 normal, 1 disabled, 2 pressed. */
int ui_button_state(int k, int saveable, int undoable);

/* The drawing area, in client coordinates, for a client of this size. */
void ui_view_rect(int cw, int ch, rect_t *r);

/* Paint everything except the drawing itself.  `d` may be NULL; when it is
   not, the layer bars show which layers the drawing uses and which one it is
   written to.  `saveable` is whether 上書 is drawn enabled: the original
   greys it out until there is a file to write back to, which is why it is
   grey on docs/ref_start.png and black once a drawing has been opened.
   `undoable` is the same for 元に戻る, which the view enables when there is
   something to take back (FUN_00511a50). */
/* The floating box the 文字 command types into.  Drawn over the drawing, so
   it goes on after it. */
void ui_textbox(fb_t *fb, const char *line, const char *composing);

void ui_paint(fb_t *fb, const jw_drawing *d, double zoom, int saveable,
              int undoable);

#endif
