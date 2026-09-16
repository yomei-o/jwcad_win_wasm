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

/* The ids are the resource ids the toolbars send; src/gen/cmds.h has the one
   for each button on the screen. */
enum {
    JW_CMD_SEN = 0x8003,            /* 線 -- the one the original starts in */
    JW_CMD_TEN = 0x8011             /* 点 */
};

int  jw_cmd(void);                  /* the current command */
void jw_cmd_set(int id);            /* enter a command */

/* The left-hand text of the status line, in CP932.  Each command puts its
   own prompt there as it goes (FUN_004efbb0 with a string id). */
const char *jw_cmd_prompt(void);

/* A click in the drawing area, in paper millimetres.  `button` is 0 for the
   left and 1 for the right. */
void jw_cmd_point(jw_drawing *d, double x, double y, int button);

/* The mouse moved to here, in paper millimetres. */
void jw_cmd_track(double x, double y);

/* The element being drawn, if the command is part way through one: 1, and
   the two ends in paper millimetres. */
int  jw_cmd_pending(double *x0, double *y0, double *x1, double *y1);

#endif
