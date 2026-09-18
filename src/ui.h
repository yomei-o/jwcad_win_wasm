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
/* The client the frame was measured in (docs/ref_start.png), and the two
 * edges things follow when the window is some other size.
 *
 * The original was driven at 1264x741 and again at 1484x841 and every child
 * window written down both times (tmp/jwdraw.ps1's `all` and `size:` steps).
 * What moved:
 *
 *   the right-hand control bar and everything in it -- the toolbars, the
 *   layer grids, the buttons under them -- moved by the width difference
 *   and kept its own height off the top;
 *   the status line moved by the height difference and grew as wide as the
 *   client;
 *   the top bar and the left bar stayed where they were and only grew, the
 *   top one wider and the left one taller;
 *   nothing else moved at all -- the command bar's controls, the left
 *   toolbars and their buttons all keep the coordinates they were measured
 *   at.
 *
 * So the whole of the frame's layout is those two shifts.
 */
#define JW_REF_W    1264
#define JW_REF_H     741
#define JW_RIGHT_X  1188        /* the right bar starts here */
#define JW_BOTTOM_Y  720        /* and the status line here  */

/* x shifted by the width difference, and y by the height difference. */
int ui_right(int x, int cw);
int ui_bottom(int y, int ch);
/* The same, but only for what sits in the right bar or the status line. */
int ui_ax(int x, int cw);
int ui_ay(int y, int ch);

int ui_button_state(int k, int saveable, int undoable);

/* Which control of the command bar is under the point -- its id, as the
   original numbers them (src/gen/bars.h), or 0.  A disabled one answers 0,
   the same as empty bar. */
int ui_bar_hit(int x, int y);

/* Which cell of the layer grids is under the point: 0 for the layer grid,
   1 for the layer group grid, -1 for neither, and *n is which of the
   sixteen. */
int ui_layer_hit(int cw, int x, int y, int *n);

/* 線属性 (0x8027), the dialog that picks the colour and the line type new
   elements get.  Where it sits, what is on it and how each control looks
   were read out of the running original -- tools/mkzoku.py and the picture
   it points at.  `colour` and `ltype` are what is picked in it right now,
   1..9 each (9 being 補助); the drawing is there for the pen colours. */
void ui_zoku_rect(int cw, int ch, rect_t *r);
void ui_zoku(fb_t *fb, const jw_drawing *d, int colour, int ltype);
/* The id of the control under the point, or 0.  Ok is 1 and キャンセル 2. */
int  ui_zoku_hit(int cw, int ch, int x, int y);

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
