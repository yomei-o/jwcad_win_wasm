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

/* Shift+Enter: 複写・移動's 範囲確定 + 基点変更 together (see
   jw_cmd_shift_enter_key).  A front end calls this instead of
   app_key(13) when Shift is down for the Enter it would otherwise send --
   WM_CHAR and a DOM keydown both carry the key but not that state, so
   each front end has to read it its own way.  Returns 1 when the screen
   has to be repainted. */
int app_shift_enter(void);

/* What an IME is still converting: -1 clears it, otherwise a CP932 byte. */
int app_compose(int c);

/* The view.  Zooming keeps the drawing under the point the user aimed at. */
void app_fit(void);
void app_zoom(double factor, int sx, int sy);
void app_pan(int dx, int dy);
const jw_view *app_view(void);
void app_paint(void);                   /* redraw into the framebuffer */
/* 0: draw the drawing afresh on every paint rather than reuse the picture of
   it from the last paint when nothing it depends on has changed.  For the
   tests that hold the two ways to the same pixels. */
void app_paint_cache(int on);
const fb_t *app_fb(void);

/* Something the front end has to do, because it needs the file system or a
   dialog: app_press leaves one behind and app_take_action hands it over. */
enum { JW_ACT_NONE = 0, JW_ACT_OPEN, JW_ACT_SAVE, JW_ACT_SAVE_AS,
       JW_ACT_SAVE_DXF, JW_ACT_OPEN_DXF, JW_ACT_OPEN_SFC,
       JW_ACT_SAVE_SFC, JW_ACT_OPEN_JWC, JW_ACT_SAVE_JWC,
       JW_ACT_SAVE_FIG, JW_ACT_SAVE_COORD,
       JW_ACT_ENV_READ, JW_ACT_ENV_WRITE, JW_ACT_ENV_EDIT,
       JW_ACT_PLOT,
       /* 文読 (1069) on the 文字 bar: the original puts up an
          ordinary 「開く」 and the port has none, so the front end
          reads the text file and hands it to app_text. */
       JW_ACT_OPEN_TEXT,
       /* 新規 on a drawing that has been changed since it was opened or
          saved: nothing has been thrown away yet.  The front end asks
          whether to, and calls app_new if the answer is yes. */
       JW_ACT_NEW_ASK,
       /* ファイル > タグジャンプ: the file a picked text names (app_tag_name) */
       JW_ACT_TAG,
       /* 画像編集's 画像挿入: the front end picks a bitmap, PNG or JPEG and
          hands it to app_image */
       JW_ACT_OPEN_IMAGE,
       /* 同梱画像分離 made files (app_image_out) for the front end to put in
          the folder named <drawing>～分離画像 */
       JW_ACT_SAVE_IMAGES,
       /* 外部変形 with something picked: app_gaibu_begin, run, app_gaibu_end */
       JW_ACT_GAIBU,
       /* 文字の 範囲選択: 文書 (a .TXT to write), 外部エディタ, 貼付 */
       JW_ACT_MOJI_DOC, JW_ACT_MOJI_EDIT, JW_ACT_MOJI_PASTE,
       /* 外部変形: every step is answered, run the BAT (app_gaibu_run_begin) */
       JW_ACT_GAIBU_RUN,
       /* 図形 (32862): 命令に入ったところで原典はファイルの窓を出す。表側が
          .jws を選ばせて app_figure に渡す（取り消せば命令のまま「データが
          ありません」） */
       JW_ACT_OPEN_FIG,
       /* Jw_cadの終了 (57665): 表側が窓を閉じる（保存の問いは WM_CLOSE の側） */
       JW_ACT_EXIT };

/* Whether a 新規 or a 開く would lose something: the drawing is not as it
   was when it was opened or last written by app_save. */
int  app_modified(void);
int  app_save_backup(unsigned char **out, long *n);   /* a copy for autosave: still "modified" */
void app_mark_modified(void);                      /* e.g. after restoring such a copy */
/* how many times a new, empty drawing has been started -- the front end
   notices a 新規 it was not told about by this changing */
int  app_new_count(void);

/* The mouse.  Coordinates are client pixels; `button` is 0 for the left and
   1 for the right.  app_press returns 1 when something changed and the
   window wants repainting. */
/* One command by id -- what a toolbar button or a menu item asks for.
   Returns 1 when the window wants repainting. */
int  app_command(int cmd);

int  app_press(int x, int y, int button);
/* the button coming up (only 連続線's 手書線 uses it); 1 if the picture changed */
int  app_release(int x, int y, int button);
int  app_move(int x, int y);
int  app_take_action(void);

/* Whether the 線属性 dialog is up; while it is, it takes every press. */
int  app_zoku_open(void);
/* and whether the 書込み文字種変更 one is */
int  app_moji_open(void);
/* what one of its three boxes holds, and which one the typing goes into */
const char *app_moji_box(int id);
int  app_moji_focus(void);
/* 色No. (ComboBox 2358) and whether its list is down. */
int  app_moji_color(void);
int  app_moji_drop(void);       /* 0 none, 1 the 色No. list, 2 the フォント one */
/* フォント (ComboBox 1423): its rows (0 is the original's default face, then
   the outline fonts of src/outfont.h), their names in CP932, and the one set */
int  app_moji_font(void);
int  app_moji_font_n(void);
const char *app_moji_font_item(int k);

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
int  app_colordlg_open(void);  /* 色の設定。基本設定の上に重なります */
int  app_kihon_tab(void);
/* 軸角・目盛・オフセット: whether it is up, and what its 軸角 box holds */
int  app_jikkaku_open(void);
const char *app_jikkaku_angle(void);
/* 寸法設定: whether its dialog is up */
int  app_sunpodlg_open(void);
int  app_layerdlg_open(void);
int  app_mojikijun_open(void);
int  app_shakudo_open(void);
int  app_modal(void);          /* any dialog at all */
/* A dialog put up from the original's own template (src/gen/dlgtpl.h):
   its index for ui_tdlg_*, or -1; the template's number; and what each of
   its controls holds, by the control's place in the template */
int  app_tdlg_open(void);
int  app_tdlg_tpl(void);
int  app_tdlg_on(int i);
const char *app_tdlg_text(int i);
int  app_bairitsu_open(void);

/* 図形読込 (32862) -- the .jws the original would have put a file window up
   for.  Returns 0 if it is not a figure.  The command is entered, and the
   next press puts the figure down. */
int  app_figure(const unsigned char *b, long n);

/* 画像挿入 (画像編集): the file picked, under the name the drawing keeps it
   by -- its path, or what the browser calls it.  0 if there is no command to
   take it. */
int  app_image(const char *path, const unsigned char *b, long n);
/* 同梱画像分離 leaves files to put in the folder: the i-th, 0 past the last */
int  app_image_out(int i, const char **name, const unsigned char **b, long *n);
/* the folder the drawing is in (CP932; "" if it has none).  Set it before
   app_title, which is what tells the command the drawing's name. */
void app_doc_dir(const char *dir);
/* the same, with the drawing's name (without .jww) as well: what the native
   build calls when a drawing is opened or saved */
void app_doc(const char *dir, const char *stem);

/* 文読: the bytes of a text file.  Its lines then go down from
   the next click, 行間 apart. */
int  app_text(const unsigned char *b, long n);

/* 図形登録 (32946) -- the other way.  The command takes a range and then a
   基準点; the press that gives the point leaves JW_ACT_SAVE_FIG behind, and
   this writes the .jws for the front end to put somewhere.  The caller
   frees *out. */
int  app_figure_save(unsigned char **out, long *n);

/* 座標ファイル (32895) の ファイル書込 -- what is picked goes out as the
   original's text file.  The command leaves JW_ACT_SAVE_COORD behind for
   the front end to ask for a name with.  The caller frees *out. */
int  app_coord_save(unsigned char **out, long *n);
int  app_gaibu_begin(const char *bat, long bn, unsigned char **out, long *n);
int  app_gaibu_end(const unsigned char *b, long n, char *msg, int cap);
const char *app_tip(int x, int y);        /* tool tip (UTF-8) of the button there */
int  app_gaibu_load(const char *bat, long n);
int  app_gaibu_run_begin(unsigned char **out, long *n, char *args, int acap);
void app_gaibu_run_end(void);
int  app_gaibu_begin2(const char *bat, long bn, int item, const double (*xy)[2],
                      char val[][128], unsigned char **out, long *n,
                      char *args, int acap);
int  app_moji_doc(unsigned char **out, long *n);
int  app_moji_edit_text(unsigned char **out, long *n);
int  app_moji_apply(const unsigned char *b, long n);

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
/* 環境設定ファイル 書出し (32924): the .jwf text, CP932; name is the first line */
int  app_save_env(const char *name, unsigned char **out, long *n);
/* 環境設定ファイル 読込み (32923) */
int  app_open_env(const unsigned char *b, long n);
/* a DXF read into what is open (src/dxfread.c) */
int  app_open_dxf(const unsigned char *b, long n);
/* and an SFC (src/sfcread.c) */
int  app_open_sfc(const unsigned char *b, long n);
/* and a JWC (src/jwcread.c) */
int  app_open_jwc(const unsigned char *b, long n);

/* RGBA bytes for a canvas, in the buffer app_rgba() returns. */
unsigned char *app_rgba(void);

/* ブロックツリー (表示 > ブロックツリー) の窓が出ているか */
int  app_blktree_open(void);
int  app_blktree_n(void);
void app_blktree_win(rect_t *r);
int  app_blktree_found(void);
int  app_blktree_all(void);

/* What the menu says about an item: bit 0 ticked, bit 1 greyed */
int  app_menu_state(int id);
/* タグジャンプ: the text of the one that was picked, in CP932 */
const char *app_tag_name(void);

#endif
