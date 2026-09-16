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

#endif
