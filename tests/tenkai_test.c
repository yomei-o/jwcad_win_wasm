/* Can a person actually draw something with this yet?
 *
 *   tests/tenkai_test.exe [out.jww]
 *
 * Two drawings anyone learning a CAD makes in the first week, built the way
 * the program is meant to be driven -- the sizes typed into the command bar,
 * not dragged by eye:
 *
 *   直方体の展開図   six rectangles, 1000 x 600 x 400, typed into 矩形の寸法
 *   円錐の展開図     a base circle of 300 (円の半径) and the sector that
 *                    wraps it: slant 800, so the sweep is 2 pi 300 / 800
 *
 * and a dimension across one edge of each.  Nothing here is scored against
 * the original -- every piece of it is, in its own test.  What this asks is
 * whether the pieces reach far enough to make a drawing at all, which is
 * the question the person using it keeps asking.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

#define PI 3.14159265358979323846

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s%s", ok ? "ok" : "BAD", what, "\n");
    if (!ok)
        fails++;
}

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

static int count_of(const jw_drawing *d, int cls, int from)
{
    int i, k = 0;

    for (i = from; i < d->ndrawn; i++)
        if (d->obj[i].cls == cls)
            k++;
    return k;
}

/* the scale of the group being written to: a bar number is a real-world
   length and the paper gets it over this */
static double wscale(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

/* One rectangle of w x h real units, its near corner at (x, y) on the
   paper, drawn the way a person draws it: the size into 寸法, a click at
   the corner and a second one saying which way it runs. */
static void box(jw_drawing *d, double x, double y, const char *size)
{
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1413, size);
    jw_cmd_point(d, app_view(), x, y, 0);
    jw_cmd_point(d, app_view(), x + 1.0, y - 1.0, 0);
}

static void cuboid(jw_drawing *d)
{
    const double s = wscale(d);
    const double W = 1000.0 / s, D = 600.0 / s, H = 400.0 / s;
    const double x0 = -80.0, y0 = 0.0;
    int before = d->ndrawn;

    /* the cross: bottom in the middle, the four sides round it, the top
       above -- 1000 x 600 for the two faces, 1000 x 400 and 600 x 400 for
       the sides */
    box(d, x0,         y0,         "1000,600");
    box(d, x0,         y0 + H,     "1000,400");
    box(d, x0,         y0 - D,     "1000,400");
    box(d, x0 - H,     y0,         "400,600");
    box(d, x0 + W,     y0,         "400,600");
    box(d, x0,         y0 + H + H, "1000,400");
    ck(count_of(d, JW_SEN, before) == 24,
       "直方体の展開図: six faces, twenty-four lines");
    {
        const jw_obj *o = &d->obj[before];
        ck(fabs(fabs(o->d[2] - o->d[0]) - W) < 1e-9,
           "  and the first face is 1000 wide on the paper");
    }
}

static void cone(jw_drawing *d)
{
    const double s = wscale(d);
    const double R = 300.0 / s, L = 800.0 / s;
    const double cx = 60.0, cy = 0.0;
    const double sweep = 2.0 * PI * R / L;
    int before = d->ndrawn;

    /* the base: one click, because the radius is already typed */
    jw_cmd_set(JW_CMD_ENKO);
    type_box(1411, "300");
    jw_cmd_point(d, app_view(), cx, cy - 40.0, 0);
    ck(count_of(d, JW_ENKO, before) == 1, "円錐の展開図: the base circle");

    /* the sector: an arc of the slant radius, opened by 2 pi R / L */
    type_box(1411, "");
    jw_cmd_bar(d, 1318);                        /* 円弧 */
    jw_cmd_point(d, app_view(), cx, cy, 0);                       /* centre */
    jw_cmd_point(d, app_view(), cx + L, cy, 0);                   /* start  */
    jw_cmd_point(d, app_view(), cx + L * cos(sweep),
                                cy + L * sin(sweep), 0);          /* end    */
    ck(count_of(d, JW_ENKO, before) == 2, "  and the arc that wraps it");
    {
        const jw_obj *a = &d->obj[d->ndrawn - 1];
        ck(fabs(a->d[2] - L) < 1e-9, "  at the slant length");
        ck(fabs(fabs(a->d[4]) - sweep) < 1e-6
           || fabs(fabs(a->d[4]) - (2.0 * PI - sweep)) < 1e-6,
           "  opened by 2 pi R / L");
    }
    jw_cmd_bar(d, 1318);                        /* 円弧 off again */

    /* the two radii */
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, app_view(), cx, cy, 0);
    jw_cmd_point(d, app_view(), cx + L, cy, 0);
    jw_cmd_point(d, app_view(), cx, cy, 0);
    jw_cmd_point(d, app_view(), cx + L * cos(sweep), cy + L * sin(sweep), 0);
    ck(count_of(d, JW_SEN, before) == 2, "  and the two radii");
}

/* A dimension across the bottom edge of the first face.  The command wants
   two clicks to place the line and then the two ends, and the ends have to
   be points it can read -- which is what the corners of the rectangle are. */
static void dimension(jw_drawing *d, double ax, double ay, double bx, double by)
{
    int before = d->ndrawn;

    jw_cmd_set(JW_CMD_SUNPO);
    /* the way a drawing is usually dimensioned: arrowheads rather than dots,
       and no decimals on a whole-millimetre size */
    jw_cmd_bar(d, 1062);                        /* 端部 -> arrows */
    jw_cmd_bar(d, 1061);
    jw_cmd_bar(d, 1061);                        /* 小数桁 2 -> 3 -> 0 */
    type_box(1411, "0");
    /* the first click is the far end of an extension line and the second a
       point on the dimension line itself -- the same point for both makes
       the extensions zero long, and the original drops those on the next
       save */
    jw_cmd_point(d, app_view(), ax, ay - 12.0, 0);
    jw_cmd_point(d, app_view(), ax, ay - 10.0, 0);
    jw_cmd_point(d, app_view(), ax, ay, 0);
    jw_cmd_point(d, app_view(), bx, by, 0);
    ck(d->ndrawn == before + 8,
       "寸法: the dimension line, four arrow lines, two extensions and the value");
    {   /* the value, with the places the button was left at */
        const char *t = jw_str(d, d->obj[d->ndrawn - 1].text);
        ck(t && !strchr(t, '.'), "  the value written to no decimal places");
    }
    jw_cmd_bar(d, 1062);
    jw_cmd_bar(d, 1061);
    jw_cmd_bar(d, 1061);
}

int main(int argc, char **argv)
{
    jw_drawing *d;
    unsigned char *out;
    long n;
    double ax, ay, bx, by;
    int lines0;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    ck(d && d->ndrawn == 0, "a new drawing to build in");

    cuboid(d);
    lines0 = d->ndrawn;
    ax = d->obj[0].d[0];
    ay = d->obj[0].d[1];
    bx = d->obj[0].d[2];
    by = d->obj[0].d[3];
    cone(d);
    dimension(d, ax, ay, bx, by);

    ck(d->ndrawn > lines0, "and the drawing has grown");
    ck(app_save(&out, &n) && n > 0, "the whole thing saves");
    if (argc > 1 && n > 0) {
        FILE *f = fopen(argv[1], "wb");
        if (f) {
            fwrite(out, 1, (size_t)n, f);
            fclose(f);
            printf("     wrote %s (%ld bytes, %d elements)%s",
                   argv[1], n, d->ndrawn, "\n");
        }
    }
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
