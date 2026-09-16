#include "cmd.h"
#include "gen/prompts.h"

/* view+0x8564 in the original.  It also remembers the one before at +0x8568;
   nothing here needs that yet. */
static int current = JW_CMD_SEN;

/* CZukeiSen keeps how far it has got in one word of its own (local_662c[0x2a]
 * in FUN_006ecb90): 0 before the first point, 2 once it has one.  The same
 * two values are used here so the two can be compared. */
static int step;
static double sx, sy;           /* the first point, in paper millimetres */
static double tx, ty;           /* where the mouse is now */
static int tracking;

int jw_cmd(void)
{
    return current;
}

void jw_cmd_set(int id)
{
    /* FUN_004fdc40: the new command's state starts empty. */
    current = id;
    step = 0;
    tracking = 0;
}

const char *jw_cmd_prompt(void)
{
    if (current == JW_CMD_SEN)
        return step == 0 ? JW_STR_5320 : JW_STR_5321;
    /* Every other command puts its own string there; which one is in that
       command's class and has not been read out of the binary yet, so rather
       than make one up the line keeps what it had. */
    return JW_STR_5320;
}

void jw_cmd_track(double x, double y)
{
    tx = x;
    ty = y;
    tracking = 1;
}

int jw_cmd_pending(double *x0, double *y0, double *x1, double *y1)
{
    if (current != JW_CMD_SEN || step != 2 || !tracking)
        return 0;
    *x0 = sx;
    *y0 = sy;
    *x1 = tx;
    *y1 = ty;
    return 1;
}

void jw_cmd_point(jw_drawing *d, double x, double y, int button)
{
    if (button != 0)
        return;                 /* (R) is Read -- snapping, not done yet */
    if (current != JW_CMD_SEN)
        return;
    if (step == 0) {
        sx = x;
        sy = y;
        step = 2;
        tx = x;
        ty = y;
        return;
    }
    if (d) {
        jw_obj *o = jw_add(d, JW_SEN);
        if (o) {
            o->d[0] = sx;
            o->d[1] = sy;
            o->d[2] = x;
            o->d[3] = y;
        }
    }
    step = 0;
    tracking = 0;
}
