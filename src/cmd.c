#include <math.h>
#include <string.h>

#include "cmd.h"
#include "gen/prompts.h"

/* view+0x8564 in the original.  It also remembers the one before at +0x8568;
   nothing here needs that yet. */
static int current = JW_CMD_SEN;

/* Each command keeps how far it has got in a word of its own -- CZukeiSen in
 * local_662c[0x2a] of FUN_006ecb90, CZukeiEnko in local_6840[0xc2] -- and
 * both use 0 for "nothing yet" and 2 for "one point down".  The same values
 * are used here so the two can be compared.
 */
static int step;
static double sx, sy;           /* the first point, in paper millimetres */
static double tx, ty;           /* where the mouse is now */
static int tracking;

#define PI 3.14159265358979323846

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
    switch (current) {
    case JW_CMD_SEN:
        return step == 0 ? JW_STR_5320 : JW_STR_5321;
    case JW_CMD_TEN:
        return JW_STR_5376;
    case JW_CMD_ENKO:
        /* CZukeiEnko asks for the centre first and then a point the circle
           goes through.  It leads with 円位置 instead only when a radius has
           been typed into its command bar, which there is nowhere to do
           yet. */
        return step == 0 ? JW_STR_5309 : JW_STR_5301;
    }
    /* Every other command puts its own string there; which one is in that
       command's class and has not been read out of the binary yet, so rather
       than make one up the line keeps the one it starts with. */
    return JW_STR_5320;
}

void jw_cmd_track(double x, double y)
{
    tx = x;
    ty = y;
    tracking = 1;
}

/* What the point down and the point here make.  Working it out in one place
   keeps the provisional figure and the element that gets added identical. */
static int figure(jw_obj *o, double x, double y)
{
    memset(o, 0, sizeof *o);
    o->text = o->face = -1;
    o->ltype = 1;
    o->color = 2;
    switch (current) {
    case JW_CMD_SEN:
        o->cls = JW_SEN;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = x;
        o->d[3] = y;
        return 1;
    case JW_CMD_ENKO: {
        /* CZukeiEnko's constructor leaves it a whole circle: the sweep it
         * starts with is 2 pi (0x401921fb54442d18 at +0x34), the flattening
         * is 1 (+0x3c) and the 円弧 flag is off (+0xe8 = 1).  Every whole
         * circle in the sample drawings carries the trailing 1 as well. */
        double dx = x - sx, dy = y - sy;
        o->cls = JW_ENKO;
        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = sqrt(dx * dx + dy * dy);
        o->d[3] = atan2(dy, dx);
        o->d[4] = 2 * PI;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        o->n = 1;
        return o->d[2] > 0.0;
    }
    }
    return 0;
}

int jw_cmd_pending(jw_obj *o)
{
    if (step != 2 || !tracking)
        return 0;
    return figure(o, tx, ty);
}

void jw_cmd_point(jw_drawing *d, double x, double y, int button)
{
    if (button != 0)
        return;                 /* (R) is Read -- snapping, not done yet */
    if (current == JW_CMD_TEN) {
        /* CZukeiTen: one point and it is placed.  Its own prompt never
           changes while it waits (FUN_004efbb0(0x1500)). */
        if (d) {
            jw_obj *o = jw_add(d, JW_TEN);
            if (o) {
                o->d[0] = x;
                o->d[1] = y;
            }
        }
        return;
    }
    if (current != JW_CMD_SEN && current != JW_CMD_ENKO)
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
        jw_obj tmp;
        if (figure(&tmp, x, y)) {
            jw_obj *o = jw_add(d, tmp.cls);
            if (o) {
                int i;
                for (i = 0; i < 8; i++)
                    o->d[i] = tmp.d[i];
                o->n = tmp.n;
            }
        }
    }
    step = 0;
    tracking = 0;
}
