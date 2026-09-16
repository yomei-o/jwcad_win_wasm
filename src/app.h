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
int  app_press(int x, int y, int button);
int  app_move(int x, int y);
int  app_take_action(void);

/* The drawing as bytes, ready to write to a file.  The caller frees *out.
   0 when there is nothing that can be written. */
int  app_save(unsigned char **out, long *n);

/* RGBA bytes for a canvas, in the buffer app_rgba() returns. */
unsigned char *app_rgba(void);

#endif
