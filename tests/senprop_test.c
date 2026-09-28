/* Drawing a line with all four of its properties set: 長さ, 角度, 線色, 線種.
 *
 *   tests/senprop_test.exe
 *
 * A line is never just two clicks.  The command bar carries its 傾き and its
 * 寸法, the 線属性 dialog carries the colour and the line type, and the line
 * that comes out has to have all four.  Each of those had a test of its own
 * at most -- the pen was checked where it is picked, not on what was drawn
 * with it -- so this draws one line with every one of them set and scores it
 * against the original's own.
 *
 * The answer is decomp/res/senprop.jww, made by tools/refanswers.sh:
 *
 *      線属性: 線色 3 (1403), 線種 点線３ (2452)
 *      傾き 15, 寸法 2000 on a 1/200 group
 *      a click at 500,400 and a second one down and to the right
 *
 * so the line is 10 mm of paper at 15 degrees, in colour 3 and type 4, and
 * everything this checks is read back out of what the original wrote.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/layout.h"
#include "../src/gen/cmds.h"
#include "../src/gen/zoku.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

/* a control of the 線属性 dialog, in window coordinates */
static void zoku_ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_zoku_rect(1264, 741, &r);
    for (i = 0; i < JW_NZOKU; i++)
        if (jw_zoku[i].id == id) {
            *x = r.x + JW_ZOKU_BORDER + jw_zoku[i].x + jw_zoku[i].w / 2;
            *y = r.y + JW_ZOKU_CAPTION + jw_zoku[i].y + jw_zoku[i].h / 2;
            return;
        }
    *x = *y = -1;
}

static void press_ctl(int id)
{
    int x, y;

    zoku_ctl(id, &x, &y);
    if (x < 0) {
        printf("BAD  the 線属性 dialog has no control %d\n", id);
        fails++;
        return;
    }
    app_press(x, y, 0);
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

/* the last line of a drawing */
static const jw_obj *last_line(const jw_drawing *d)
{
    const jw_obj *o = 0;
    int i;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SEN)
            o = &d->obj[i];
    return o;
}

int main(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r;
    int before;

    b = slurp("decomp/res/senprop.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/senprop.jww -- run tools/refanswers.sh\n");
        return 1;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  senprop.jww: %s\n", ref.error);
        return 1;
    }
    free(b);
    r = last_line(&ref);
    if (!r) {
        printf("BAD  senprop.jww has no line in it\n");
        return 1;
    }

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();

    /* the pen, out of the 線属性 dialog the way it is picked */
    app_command(0x8027);
    ck(app_zoku_open(), "線属性 puts its dialog up");
    press_ctl(1403);                    /* 線色 ３ */
    press_ctl(2452);                    /* 線種 点線 ３ */
    press_ctl(1);                       /* Ok */
    ck(!app_zoku_open(), "and Ok takes it down again");
    ck(d->write_color == 3 && d->write_ltype == 4,
       "the colour and the line type picked are the ones being written with");

    /* the length and the angle, off the command bar */
    jw_cmd_set(JW_CMD_SEN);
    type_box(1411, "15");
    type_box(1412, "2000");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r->d[0], r->d[1], 0);
    jw_cmd_point(d, app_view(), r->d[0] + 100.0, r->d[1] - 100.0, 0);
    ck(d->ndrawn == before + 1, "two clicks draw one line");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        double deg;
        if (!(near(a->d[0], r->d[0]) && near(a->d[1], r->d[1])
              && near(a->d[2], r->d[2]) && near(a->d[3], r->d[3])))
            printf("     ours %.6f,%.6f -> %.6f,%.6f\n"
                   "     the original's %.6f,%.6f -> %.6f,%.6f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   r->d[0], r->d[1], r->d[2], r->d[3]);
        ck(near(a->d[0], r->d[0]) && near(a->d[1], r->d[1])
           && near(a->d[2], r->d[2]) && near(a->d[3], r->d[3]),
           "exactly where the original put it");
        ck(near(hypot(a->d[2] - a->d[0], a->d[3] - a->d[1]), 10.0),
           "2000 on a 1/200 group is 10 mm of paper");
        deg = atan2(a->d[3] - a->d[1], a->d[2] - a->d[0]) * 180.0 / 3.14159265358979323846;
        ck(fabs(deg - 15.0) < 1e-6, "at the 15 degrees the 傾き box asked for");
        if (a->color != r->color || a->ltype != r->ltype)
            printf("     ours colour %d type %d, the original's %d %d\n",
                   a->color, a->ltype, r->color, r->ltype);
        ck(a->color == r->color, "in the colour the original drew it in");
        ck(a->ltype == r->ltype, "and the line type the original drew it in");
    }
    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
