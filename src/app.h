/* The application surface: one framebuffer the size of the client area.
 *
 * Both front ends -- the native window and the browser -- do the same two
 * things: tell this how big the client is, and hand the pixels to the screen.
 * Everything that decides what a pixel is lives below here, so the two builds
 * cannot drift apart.
 */
#ifndef JW_APP_H
#define JW_APP_H

#include "fb.h"
#include "jww.h"
#include "view.h"

int  app_resize(int w, int h);          /* 0 if the allocation failed */
int  app_open(const unsigned char *b, long n);   /* 0 and sets app_error() */

/* Start an empty drawing, the way the original does when it opens with no
   file: A-2 at 1/100, written to group 0 layer 0. */
void app_new(void);
const char *app_error(void);
const jw_drawing *app_drawing(void);

/* A character typed for the 文字 command, in CP932 (8 is backspace).
   Returns 1 when the screen has to be repainted. */
int app_key(int c);

/* What an IME is still converting: -1 clears it, otherwise a CP932 byte. */
int app_compose(int c);

/* The view.  Zooming keeps the drawing under the point the user aimed at. */
void app_fit(void);
void app_zoom(double factor, int sx, int sy);
void app_pan(int dx, int dy);
const jw_view *app_view(void);
void app_paint(void);                   /* redraw into the framebuffer */
const fb_t *app_fb(void);

/* Something the front end has to do, because it needs the file system or a
   dialog: app_press leaves one behind and app_take_action hands it over. */
enum { JW_ACT_NONE = 0, JW_ACT_OPEN, JW_ACT_SAVE, JW_ACT_SAVE_AS };

/* The mouse.  Coordinates are client pixels; `button` is 0 for the left and
   1 for the right.  app_press returns 1 when something changed and the
   window wants repainting. */
/* One command by id -- what a toolbar button or a menu item asks for.
   Returns 1 when the window wants repainting. */
int  app_command(int cmd);

int  app_press(int x, int y, int button);
int  app_move(int x, int y);
int  app_take_action(void);

/* Whether the 線属性 dialog is up; while it is, it takes every press. */
int  app_zoku_open(void);

/* The caption and the menu bar.  A front end with a window of its own --
   the native one -- gets them from Windows and leaves this off; the browser
   turns it on and the port draws them above the client.  app_rgba() then
   hands back the whole window rather than just the client, and
   app_chrome_h() is how many rows of it are chrome. */
void app_chrome(int on);
int  app_chrome_h(void);

/* A press or a move on the chrome, in its own coordinates (the caption is
   row 0).  Only the browser build has chrome; the native window's menu is
   Windows' own.  Both return 1 when the screen wants repainting. */
int  app_chrome_press(int x, int y);
int  app_chrome_move(int x, int y);
/* What the caption says.  CP932, and the port puts " - jw_win" after it the
   way the original does. */
void app_title(const char *name);

/* The drawing as bytes, ready to write to a file.  The caller frees *out.
   0 when there is nothing that can be written. */
int  app_save(unsigned char **out, long *n);

/* RGBA bytes for a canvas, in the buffer app_rgba() returns. */
unsigned char *app_rgba(void);

#endif
