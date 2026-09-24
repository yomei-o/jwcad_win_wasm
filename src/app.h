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
enum { JW_ACT_NONE = 0, JW_ACT_OPEN, JW_ACT_SAVE, JW_ACT_SAVE_AS,
       JW_ACT_SAVE_DXF, JW_ACT_OPEN_DXF, JW_ACT_OPEN_SFC,
       JW_ACT_SAVE_SFC, JW_ACT_OPEN_JWC, JW_ACT_SAVE_JWC,
       JW_ACT_SAVE_FIG, JW_ACT_SAVE_COORD };

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
/* and whether the 書込み文字種変更 one is */
int  app_moji_open(void);
/* what one of its three boxes holds, and which one the typing goes into */
const char *app_moji_box(int id);
int  app_moji_focus(void);

/* 属性選択: whether its dialog is up, and which of its boxes are ticked
   (one byte per control of src/gen/zokusel.h). */
int  app_zokusel_open(void);
const unsigned char *app_zokusel_on(void);
/* 属性変更: whether its dialog is up */
int  app_zokuhen_open(void);

/* ブロック化: whether its dialog is up, and what has been typed into it. */
int  app_blkname_open(void);
int  app_blkedit_open(void);
/* what its name box holds */
const char *app_blkedit_name(void);
/* 基本設定: whether its dialog is up */
int  app_kihon_open(void);
int  app_kihon_tab(void);
/* 軸角・目盛・オフセット: whether it is up, and what its 軸角 box holds */
int  app_jikkaku_open(void);
const char *app_jikkaku_angle(void);
/* 寸法設定: whether its dialog is up */
int  app_sunpodlg_open(void);
int  app_bairitsu_open(void);

/* 図形読込 (32862) -- the .jws the original would have put a file window up
   for.  Returns 0 if it is not a figure.  The command is entered, and the
   next press puts the figure down. */
int  app_figure(const unsigned char *b, long n);

/* 図形登録 (32946) -- the other way.  The command takes a range and then a
   基準点; the press that gives the point leaves JW_ACT_SAVE_FIG behind, and
   this writes the .jws for the front end to put somewhere.  The caller
   frees *out. */
int  app_figure_save(unsigned char **out, long *n);

/* 座標ファイル (32895) の ファイル書込 -- what is picked goes out as the
   original's text file.  The command leaves JW_ACT_SAVE_COORD behind for
   the front end to ask for a name with.  The caller frees *out. */
int  app_coord_save(unsigned char **out, long *n);

/* And the other way: 座標ファイル's ファイル読込, which the original makes a
   図形 of.  The next press puts it down. */
int  app_coord(const unsigned char *b, long n);
const char *app_blkname(void);

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
/* the same drawing written as DXF (src/dxf.c) */
int  app_save_dxf(unsigned char **out, long *n);
/* 「SFC形式で保存」.  The name goes in the file's own header, so the front end
   has to have asked for it first, and the moment comes off the clock. */
int  app_save_sfc(const char *name, unsigned char **out, long *n);
/* 「JWC形式で保存」, which needs nothing from outside the drawing. */
int  app_save_jwc(unsigned char **out, long *n);
/* a DXF read into what is open (src/dxfread.c) */
int  app_open_dxf(const unsigned char *b, long n);
/* and an SFC (src/sfcread.c) */
int  app_open_sfc(const unsigned char *b, long n);
/* and a JWC (src/jwcread.c) */
int  app_open_jwc(const unsigned char *b, long n);

/* RGBA bytes for a canvas, in the buffer app_rgba() returns. */
unsigned char *app_rgba(void);

#endif
