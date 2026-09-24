/* Which command the user is in, and what it is waiting for.
 *
 * The original keeps the current command as one id in the view, at +0x8564,
 * and every toolbar button's ON_UPDATE_COMMAND_UI handler is the same three
 * lines (FUN_00511c20):
 *
 *     pCmdUI->SetCheck(view->current == id);
 *
 * so a button is drawn pressed exactly when it is the command in force.
 * Entering a command (FUN_004fdba0 -> FUN_004fdc40) remembers the old one at
 * +0x8568, stores the new one at +0x8564 and clears the command's own state.
 */
#ifndef JW_CMD_H
#define JW_CMD_H

#include "jww.h"
#include "view.h"

/* The ids are the resource ids the toolbars send; src/gen/cmds.h has the one
   for each button on the screen. */
enum {
    JW_CMD_SEN = 0x8003,            /* 線 -- the one the original starts in */
    JW_CMD_TEN = 0x8011,            /* 点 */
    JW_CMD_KUKEI = 0x8004,          /* 矩形 -- CZukeiSen's other mode */
    JW_CMD_ENKO = 0x8005,           /* 円 */
    JW_CMD_RENZOKU = 0x8073,        /* 連続線 */
    JW_CMD_SHOUKYO = 0x801a,        /* 消去 */
    JW_CMD_CORNER = 0x8012,         /* コーナー処理 */
    JW_CMD_SHINSHUKU = 0x8017,      /* 線伸縮 */
    JW_CMD_FUKUSEN = 0x8020,        /* 複線 */
    JW_CMD_ZOKUSEI = 0x80a3,        /* 属性取得 */
    JW_CMD_ZOKUHEN = 0x80b8,        /* 属性変更 */
    JW_CMD_MOJI = 0x8026,           /* 文字 */
    JW_CMD_HANI = 0x8013,           /* 範囲選択 -- CZukeiSentaku */
    JW_CMD_FUKUSHA = 0x8024,        /* 複写 -- CZukeiFukusha */
    JW_CMD_IDOU = 0x8096,           /* 移動 -- the same class */
    JW_CMD_SUNPO = 0x804f,          /* 寸法 -- CZukeiSunpo */
    JW_CMD_TAKAKU = 0x807e,         /* 多角形 -- CZukeiTakakukei */
    JW_CMD_MENTORI = 0x805b,        /* 面取 -- CZukeiCorner's other half */
    JW_CMD_BUNKATSU = 0x8063,       /* 分割 -- CZukeiBunkatsu */
    JW_CMD_NISEN = 0x807c,          /* ２線 -- the menu resource and the
                                       toolbar cell both say 0x807c; it
                                       was 0x805c here, which is not a
                                       command at all, so the button and
                                       the menu never reached this and
                                       the bar fell back to 線's.  The
                                       tests set it by name, so they did
                                       not notice. */
    JW_CMD_CHUSHIN = 0x8069,        /* 中心線 -- CZukeiChuushinSen */
    JW_CMD_SESSEN = 0x8066,         /* 接線 -- 円→円 only so far */
    JW_CMD_SEKIEN = 0x8068,         /* 接円 -- two lines and a radius */
    JW_CMD_KYOKUSEN = 0x808c,       /* 曲線 -- スプライン only so far */
    JW_CMD_HOURAKU = 0x804e,        /* 包絡処理 -- CZukeiHouraku */
    JW_CMD_HATCH = 0x806a,          /* ハッチ -- 1線 only so far */
    JW_CMD_SEIRI = 0x808e,          /* データ整理 -- CZukeiSeiri */
    JW_CMD_BLOCK = 0x8055,          /* ブロック化 -- CZukeiBlock */
    JW_CMD_BLOCK_FREE = 0x808d,     /* ブロック解除 */
    JW_CMD_BLOCK_ATTR = 0x80ca,     /* ブロック属性 */
    JW_CMD_BLOCK_EDIT = 0x80da,     /* ブロック編集 */
    JW_CMD_BLOCK_DONE = 0x80d9,     /* ブロック編集終了 */
    JW_CMD_ZUKEI = 0x805e,          /* 図形読込 -- CZukeiZukei */
    JW_CMD_ZUKEIREG = 0x80b2,       /* 図形登録 -- it takes a range of its
                                       own, and the point after 選択確定 is
                                       the 基準点 */
    JW_CMD_UNDO = 0xe12b            /* 元に戻る (ID_EDIT_UNDO) */
};

int  jw_cmd(void);                  /* the current command */
void jw_cmd_set(int id);            /* enter a command */
void jw_cmd_reset(void);            /* back to how it starts, for a new drawing */

/* The 文字 command's line, as CP932 bytes.  Jw_cad wants the text typed
   first and then the place clicked, so this is what has been typed so far. */
const char *jw_cmd_line(void);
void jw_cmd_key(int c);             /* a character, or 8 for backspace */

/* 斜体 and 太字, the two checkboxes of the 書込み文字種変更 dialog.  A text
 * written with them on carries 10000 and 20000 in its trailing long, on top
 * of whichever 文字種 it is: the original wrote 10000 for 斜体, 20000 for
 * 太字 and 30000 for both, all at 任意サイズ (decomp/res/moji{ital,bold,
 * both}.jww), and 3 for 文字種[ 3] on its own.
 */
void jw_cmd_moji_style(int italic, int bold);
int  jw_cmd_moji_italic(void);
int  jw_cmd_moji_bold(void);

/* What an IME is still converting, shown after the line but not part of it.
   The original's box is a real edit control and shows it as a matter of
   course; this port draws its own box, so it has to be told. */
const char *jw_cmd_compose(void);
void jw_cmd_compose_clear(void);
void jw_cmd_compose_key(int c);

/* 軸角 -- the angle the sheet's own axes are turned to, in degrees.  It is
 * typed into the 軸角・目盛・オフセット dialog (32842) and Ok applies it;
 * from then on 水平・垂直 snaps to it and to it plus ninety rather than to
 * flat and upright.  The original bears it out to the last digit: with 30
 * set, a drag that came out at -2.862 degrees without it made a line at
 * exactly 30 (decomp/res/jikkaku30.jww), as far along the axis as the drag
 * reached.
 */
double jw_cmd_axis(void);
void   jw_cmd_set_axis(double deg);

/* Whether 線's 水平・垂直 is on.  Pressing 線 while already in 線 flips it,
   which is all that arm of FUN_004fdc40 does when the command before was 線
   as well; with it on a line keeps whichever way the drag went further. */
int  jw_cmd_hv(void);

/* The left-hand text of the status line, in CP932.  Each command puts its
   own prompt there as it goes (FUN_004efbb0 with a string id). */
const char *jw_cmd_prompt(void);

/* A click in the drawing area, in paper millimetres.  `button` is 0 for the
   left and 1 for the right. */
/* A click in the drawing area.  `button` is 0 for the left and 1 for the
   right; the view is needed because 消去 has to work out what is under the
   point, and how near "under" is depends on the zoom. */
void jw_cmd_point(jw_drawing *d, const jw_view *v,
                  double x, double y, int button);

/* The mouse moved to here, in paper millimetres. */
void jw_cmd_track(double x, double y);

/* Undoing.  The view enables 元に戻る when there is something to undo --
   its ON_UPDATE_COMMAND_UI (FUN_00511a50) is Enable(list is not empty) --
   and the button is greyed out on docs/ref_start.png because there is not.
   What this can take back is the elements the commands here have added. */
int  jw_cmd_can_undo(void);
void jw_cmd_undo(jw_drawing *d);

/* The elements the command is part way through, if any: how many, filled in
   ready to draw (a rectangle is four lines).  They are worked out the same
   way as the ones that get added, so what is shown is what will be made. */
#define JW_CMD_MAXFIG 4         /* a rectangle, the biggest so far */
int  jw_cmd_pending(jw_drawing *d, jw_obj *o, int max);

/* 範囲選択, and the two commands built on it.
 *
 * Which elements are selected is kept where the original keeps it: bit 1 of
 * the element's own flags at +0x44, which is why a drawing saved with a
 * selection still has it when it is opened again.
 *
 * A press on one of the command bar's buttons comes here by its control id
 * -- 1120 選択確定, 1067 選択解除, 1066 全選択 -- which is how the original
 * dispatches them too.  Returns 1 when the screen has to be redrawn. */
int  jw_cmd_bar(jw_drawing *d, int id);
/* Whether that button is there to be pressed, for the drawing of the bar. */
int  jw_cmd_bar_check(int id);
/* The label 任意方向 is carrying (CP932): it cycles X, Y, XY and back. */
const char *jw_cmd_dir_text(void);
int  jw_cmd_bar_enabled(const jw_drawing *d, int id);

/* The range box while its second corner is being chosen: the original draws
   it in red (Pen/Color11) over the drawing. */
int  jw_cmd_sel_box(double *x0, double *y0, double *x1, double *y1);
/* How far the selection has been dragged from 基準点, once it is being
   placed.  The selected elements are drawn a second time that far away, so
   what will be made is what is shown. */
int  jw_cmd_sel_ghost(double *dx, double *dy);
/* How many elements are selected. */
int  jw_cmd_sel_count(const jw_drawing *d);
/* Take the settled selection out of the drawing, which is what entering 消去
   with one in hand does.  Returns 1 if anything went. */
int  jw_cmd_sel_erase(jw_drawing *d);

/* 属性選択 -- narrow what is picked to the kinds ticked in the 1069 dialog,
 * or with 除外 to everything but those.  The mask is JW_ZOK_*; a mask of
 * nothing leaves the selection as it was.  Returns how many are left.
 */
enum {
    JW_ZOK_SEN   = 1,           /* 直線指定   1812 */
    JW_ZOK_ENKO  = 2,           /* 円指定     2434 */
    JW_ZOK_TEN   = 4,           /* 実点指定   2430 */
    JW_ZOK_MOJI  = 8,           /* 文字指定   1804 */
    JW_ZOK_SOLID = 16,          /* ソリッド図形指定 2433 */
    JW_ZOK_HOJO  = 32,          /* 補助線指定 2431 */
    JW_ZOK_BLOCK = 64           /* ブロック図形指定 1802 */
};
int  jw_cmd_zokusel(jw_drawing *d, int mask, int exclude);

/* 属性変更 (範囲選択's 1070) -- the same dialog with its other half showing.
 * Only the two that could be driven are done: 書込【レイヤ】に変更 moves
 * everything picked to the write layer (twelve elements on layer 0 came back
 * on layer 8, decomp/res/zhlayer.jww) and 書込レイヤグループに変更 does the
 * same for the group.  指定【線色】に変更 and 指定 線種 に変更 changed
 * nothing at all when they were driven, the same way the 指定【線色】指定
 * filter matches everything -- where the "指定" one comes from is still not
 * known.  Returns how many elements were changed.
 */
int  jw_cmd_zokuhen_range(jw_drawing *d, int to_layer, int to_group);

/* 図形読込 (32862).  The original puts up a file window of its own -- not a
 * common dialog -- and once a .jws is picked the figure hangs on the cursor
 * until a point is clicked.  The port has no file window, so the front end
 * hands the bytes over here; that enters the command, and the next point
 * places the figure.  Returns 0 if the file is not a figure.
 *
 * What the original does with it, read out of decomp/res/figin.jww (Test5,
 * whose write group is at 1/200, given the 1/100 figure decomp/res/fig.jws):
 *
 *   * the figure is scaled by **its own layer-group scale over the write
 *     group's** -- 100/200, so the 6mm box came in 3mm wide.  The figure
 *     keeps the size it stands for on the ground, not on the paper.
 *   * the base point in the .jws header lands on the clicked point.
 *   * colour and line type come with the figure; the layer and the layer
 *     group are the drawing's write ones (the figure's own layer 4 became
 *     layer 8).
 */
int  jw_cmd_figure_load(jw_drawing *d, const unsigned char *b, long n);
int  jw_cmd_figure_ready(void);

/* 図形登録 (32946): the elements picked by a range go out as a .jws, with
 * (bx, by) -- the 基準点 the command asks for after 選択確定 -- in its
 * header.  The caller frees *out.  Returns 0 if it could not.
 */
int  jw_cmd_figure_save(const jw_drawing *d, double bx, double by,
                        unsigned char **out, long *n);

/* Whether the last point was 図形登録's 基準点, which is the moment the
   front end has to ask for a file name.  Says so once and forgets. */
int  jw_cmd_figure_base(double *x, double *y);

/* How far a range command has got: 0 nothing, 1 the first corner is in, 2 a
   range is picked, 3 it is settled (4 for 範囲選択, which stops there).  The
   bar for a command changes at 3, so the drawing of it has to know. */
int  jw_cmd_sel_stage(void);

/* ブロック化 -- turn what is picked into a definition of that name and put
 * one reference to it in their place.  Returns how many went in, 0 if it
 * could not.  `prefer_layer` is the dialog's 元データのレイヤを優先する.
 */
int  jw_cmd_block_make(jw_drawing *d, const char *name, int prefer_layer);
/* Where a block made of what is picked would go: the average of one point
   per element.  Returns 0 if nothing is picked. */
int  jw_cmd_block_point(const jw_drawing *d, double *x, double *y);
/* ブロック解除 -- put back the elements of every reference that is picked,
   and drop a definition nothing refers to any more.  Returns how many
   references were undone. */
int  jw_cmd_block_free(jw_drawing *d);
/* ブロック属性 -- the only thing its dialog can change is 元データのレイヤを
   優先する, which is bit 64 of a reference's own line type.  Returns how
   many references it was put on or taken off. */
int  jw_cmd_block_attr(jw_drawing *d, int prefer_layer);

/* ブロック編集 -- while it is on, whatever is drawn goes into the picked
 * block's definition instead of into the drawing, so it shows up through
 * every reference to it at once.  jw_cmd_block_edit starts it on the first
 * reference that is picked (0 if none is), jw_cmd_block_done ends it, and
 * jw_cmd_block_take moves anything added since `from` into the definition.
 */
int  jw_cmd_block_edit(jw_drawing *d);
void jw_cmd_block_done(void);
int  jw_cmd_block_editing(void);
/* The name of the block being edited, for the dialog. */
const char *jw_cmd_block_name(const jw_drawing *d);
void jw_cmd_block_take(jw_drawing *d, int from);
/* ブロック名変更: the name the dialog's box holds becomes the block's, with
   the @@SfigorgFlag@@4 the original puts on the end. */
int  jw_cmd_block_rename(jw_drawing *d, const char *name);
/* 選択したブロックのみに反映させる: the definition is copied for the one
   reference being edited, so that editing it leaves the others alone.  The
   copy is numbered after the last one and named <name>(<number>). */
int  jw_cmd_block_split(jw_drawing *d);

/* 寸法's direction: 0 degrees or 90, which the command bar's 0ﾟ/90ﾟ button
   (id 1059) swaps.  Anything else needs the 傾き box, which is not done. */
int  jw_cmd_sunpo_angle(void);

/* The boxes on the command bar that can be typed into -- 多角形's 寸法,
   角数 and 底辺角度 so far.  The text of one, or NULL if the port does not
   keep that box; `focus` is the one being typed into, 0 for none. */
const char *jw_cmd_box(int id);
int  jw_cmd_box_focus(void);
void jw_cmd_box_click(int id);      /* a press on one: it takes the typing */
int  jw_cmd_box_key(int c);         /* a character; 1 if it was taken */

#endif
