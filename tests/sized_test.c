/* 線 and 矩形 with a size typed into the command bar.
 *
 *   tests/sized_test.exe
 *
 * This is how Jw_cad is actually used: a square 1000 mm across is typed into
 * 矩形's 寸法 box and put down with two clicks, not dragged to size by eye.
 * The port had the boxes drawn but dead, so neither could be done.
 *
 * The answers are the original's own, made by tools/refanswers.sh:
 *
 *   decomp/res/kukeisize.jww  寸法 1000,1000 on a 1/200 group, a click and
 *                             then one down and to the right of it
 *   decomp/res/sensize.jww    傾き 30 and 寸法 1000, a click and then one up
 *                             and to the left
 *
 * What they say, and what this checks the port does:
 *
 *   the box is a real-world length, so the paper gets it over the layer
 *   group's scale -- 1000 came out 5 mm;
 *   the first click is the corner (線: the end), and the second only says
 *   which way it runs from there -- the rectangle went down-right of the
 *   first click for a second click down-right, and up-left for up-left;
 *   the line came out at 傾き, or 傾き turned round, whichever is nearer the
 *   second click: -150 degrees for a 30 degree box and a click up-left.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

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

/* the last `want` lines of a drawing -- what the original drew last */
static int tail_lines(jw_drawing *d, const jw_obj **out, int want)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SEN) {
            int k;
            for (k = 0; k + 1 < want; k++)
                out[k] = out[k + 1];
            out[want - 1] = &d->obj[i];
            n++;
        }
    return n >= want;
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

static jw_drawing *fresh(void)
{
    unsigned char *b;
    long n;

    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        exit(1);
    }
    free(b);
    return (jw_drawing *)app_drawing();
}

static void rectangle(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[4];
    int i, before;

    b = slurp("decomp/res/kukeisize.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/kukeisize.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  kukeisize.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_lines(&ref, r, 4)) {
        printf("BAD  kukeisize.jww has no rectangle in it\n");
        fails++;
        return;
    }
    d = fresh();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_KUKEI);
    ck(jw_cmd_box(1413) != 0, "矩形 has a 寸法 box the port keeps");
    type_box(1413, "1000,1000");
    /* the first corner is where the original's first line starts, and the
       far corner is in the quadrant its second click was in */
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[1]->d[2], r[1]->d[3], 0);
    ck(d->ndrawn == before + 4, "typing 1000,1000 and two clicks draw four lines");
    if (d->ndrawn == before + 4) {
        int ok = 1;
        for (i = 0; i < 4; i++) {
            const jw_obj *a = &d->obj[before + i];
            if (!(near(a->d[0], r[i]->d[0]) && near(a->d[1], r[i]->d[1])
                  && near(a->d[2], r[i]->d[2]) && near(a->d[3], r[i]->d[3]))) {
                ok = 0;
                printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
                       "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                       a->d[0], a->d[1], a->d[2], a->d[3],
                       r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
            }
        }
        ck(ok, "all four exactly where the original put them");
        {   /* 1000 on a 1/200 group is 5 mm of paper */
            double w = fabs(d->obj[before].d[2] - d->obj[before].d[0]);
            ck(near(w, 5.0), "and the size is the box over the group's scale");
        }
    }
    /* the other way round: a second click up-left mirrors it */
    {
        double ax = r[0]->d[0], ay = r[0]->d[1];
        int was = d->ndrawn;
        jw_cmd_point(d, app_view(), ax, ay, 0);
        jw_cmd_point(d, app_view(), ax - 100.0, ay + 100.0, 0);
        ck(d->ndrawn == was + 4, "another two clicks draw another one");
        if (d->ndrawn == was + 4)
            ck(near(d->obj[was].d[2], ax - 5.0),
               "and a second click the other way turns it round");
    }
    jw_free(&ref);
}

static void line(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before;

    b = slurp("decomp/res/sensize.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/sensize.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  sensize.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_lines(&ref, r, 1)) {
        printf("BAD  sensize.jww has no line in it\n");
        fails++;
        return;
    }
    d = fresh();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_SEN);
    ck(jw_cmd_box(1411) != 0 && jw_cmd_box(1412) != 0,
       "線 has 傾き and 寸法 boxes the port keeps");
    type_box(1411, "30");
    type_box(1412, "1000");
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[0]->d[2], r[0]->d[3], 0);
    ck(d->ndrawn == before + 1, "typing 30 and 1000 and two clicks draw a line");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        if (!(near(a->d[0], r[0]->d[0]) && near(a->d[1], r[0]->d[1])
              && near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3])))
            printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
                   "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   r[0]->d[0], r[0]->d[1], r[0]->d[2], r[0]->d[3]);
        ck(near(a->d[0], r[0]->d[0]) && near(a->d[1], r[0]->d[1])
           && near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3]),
           "exactly where the original put it");
        ck(near(hypot(a->d[2] - a->d[0], a->d[3] - a->d[1]), 5.0),
           "5 mm long, which is 1000 over the group's scale");
    }
    /* the same length the other way when the second click is the other side */
    {
        int was = d->ndrawn;
        jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
        jw_cmd_point(d, app_view(), r[0]->d[0] + 100.0, r[0]->d[1] + 57.7, 0);
        ck(d->ndrawn == was + 1, "and another pair draws another line");
        if (d->ndrawn == was + 1) {
            const jw_obj *a = &d->obj[was];
            double deg = atan2(a->d[3] - a->d[1], a->d[2] - a->d[0]) * 180.0 / 3.14159265358979323846;
            ck(fabs(deg - 30.0) < 1e-6,
               "at 30 degrees when the second click is that side");
        }
    }
    jw_free(&ref);
}

int main(void)
{
    app_resize(1264, 741);
    rectangle();
    line();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
