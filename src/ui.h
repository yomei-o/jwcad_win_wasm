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
/* What Windows puts above the client: a caption with the program's icon and
 * its name, and the menu bar.  The native window gets both from Windows; the
 * browser has no window of its own, so the port draws them.  Measured off
 * docs/ref_window.png, the original's own window painted into a bitmap.
 */
#define JW_CAPTION_H 31
#define JW_MENU_H    20
#define JW_CHROME_H  (JW_CAPTION_H + JW_MENU_H)

void ui_caption(fb_t *fb, int y, int cw, const char *title);
void ui_menu(fb_t *fb, int y, int cw);
/* Which name of the menu bar is under the point, or -1.  x and y are in the
   chrome's own coordinates, the caption included. */
int  ui_menu_hit(int x, int y);

/* The popup one of those names opens.  Windows draws this one for the native
 * build, so it is the browser's alone -- and like the caption it is a themed
 * window on the original, which the port has no way to match pixel for pixel
 * (rounded corners, a shadow, a different font).  What is copied is the
 * measurements, taken off the original's own popups with tools/jwdraw.ps1's
 * `menu:` step: an item is 22 rows, a separator 9, the border 3, and the
 * label starts 44 in.  Nothing here is scored against a reference image.
 */
#define JW_POPUP_ITEM_H  22
#define JW_POPUP_SEP_H    9
#define JW_POPUP_BORDER   3
#define JW_POPUP_TEXT_X  44
#define JW_POPUP_FACE   0xf9f9f9u
#define JW_POPUP_EDGE   0xe5e5e5u
#define JW_POPUP_HOT    0xe8e8e8u

/* Open the popup under a name of the bar, or -1 to close.  Returns 1 when
   the screen has to be redrawn. */
int  ui_popup_open(int top);
int  ui_popup_top(void);                /* -1 when nothing is open */
/* The mouse moved to a client point while a popup is open. */
int  ui_popup_move(int x, int y);
/* Which entry of jw_menu_tree is under a client point, or -1. */
int  ui_popup_hit(int x, int y);
/* Whether a client point is on the open popup at all. */
int  ui_popup_in(int x, int y);
/* A press on the open popup: the command id to run, 0 for nothing (a
   separator, a submenu that just opened, or a miss). */
int  ui_popup_press(int x, int y);
void ui_popup_draw(fb_t *fb);

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

/* 書込み文字種変更 -- the dialog the 文字 bar's 1843 button puts up.
   `style` is which 文字種 is chosen, 0 being 任意サイズ. */
void ui_moji_rect(int cw, int ch, rect_t *r);
void ui_moji(fb_t *fb, const jw_drawing *d, int style);
int  ui_moji_hit(int cw, int ch, int x, int y);

/* 属性選択 -- the dialog the 範囲選択 bar's 1069 puts up once a box is in.
   `on` is one byte per control of src/gen/zokusel.h, 1 for ticked. */
void ui_zokusel_rect(int cw, int ch, rect_t *r);
void ui_zokusel(fb_t *fb, const unsigned char *on);
int  ui_zokusel_hit(int cw, int ch, int x, int y);
int  ui_zokusel_n(void);
int  ui_zokusel_id(int i);

/* ブロック化 -- the dialog 32853 puts up once a range is in.  `name` is what
   has been typed into its box, `on` whether its checkbox is ticked, `caret`
   whether the box has the caret in it. */
void ui_blkname_rect(int cw, int ch, rect_t *r);
/* `attr` draws it the way ブロック属性 has it: the name box greyed out and
   its label cut down to just ブロック名. */
void ui_blkname(fb_t *fb, const char *name, int on, int caret, int attr);
int  ui_blkname_hit(int cw, int ch, int x, int y);

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
