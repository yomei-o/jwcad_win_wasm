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
    JW_CMD_MOJI = 0x8026,           /* 文字 */
    JW_CMD_HANI = 0x8013,           /* 範囲選択 -- CZukeiSentaku */
    JW_CMD_FUKUSHA = 0x8024,        /* 複写 -- CZukeiFukusha */
    JW_CMD_IDOU = 0x8096,           /* 移動 -- the same class */
    JW_CMD_UNDO = 0xe12b            /* 元に戻る (ID_EDIT_UNDO) */
};

int  jw_cmd(void);                  /* the current command */
void jw_cmd_set(int id);            /* enter a command */
void jw_cmd_reset(void);            /* back to how it starts, for a new drawing */

/* The 文字 command's line, as CP932 bytes.  Jw_cad wants the text typed
   first and then the place clicked, so this is what has been typed so far. */
const char *jw_cmd_line(void);
void jw_cmd_key(int c);             /* a character, or 8 for backspace */

/* What an IME is still converting, shown after the line but not part of it.
   The original's box is a real edit control and shows it as a matter of
   course; this port draws its own box, so it has to be told. */
const char *jw_cmd_compose(void);
void jw_cmd_compose_clear(void);
void jw_cmd_compose_key(int c);

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

#endif
