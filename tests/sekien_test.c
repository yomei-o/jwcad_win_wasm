/* 接円 (0x8068) -- against the four the original drew.
 *
 *   tests/sekien_test.exe
 *
 * A radius and two lines leave four circles of that radius touching both, one
 * in each of the angles they make.  The original says so itself: after the
 * second line its status line reads 「マウスを移動し、必要な接円位置で左クリック
 * してください。 【 4 − 1 】」 and the third click takes the one nearest it.
 * Driven four times over the same crossed pair, placing that click left,
 * right, above and below, it left four circles of radius 10 -- 2000 in a
 * 1/200 group -- whose centres sit on the two angle bisectors
 * (decomp/res/sekien_*.jww).
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
    return fabs(a - b) < 1e-6;
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

/* the distance from a point to an infinite line */
static double off(const jw_obj *l, double x, double y)
{
    double ux = l->d[2] - l->d[0], uy = l->d[3] - l->d[1];
    double L = sqrt(ux * ux + uy * uy);

    if (L < 1e-12)
        return 0;
    return fabs((-uy * (x - l->d[0]) + ux * (y - l->d[1])) / L);
}

static void run(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *l[2], *circle = 0;
    int i, nl = 0, before;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        fails++;
        return;
    }
    free(b);
    /* the last two lines are the pair that was drawn, the arc is the answer */
    for (i = 0; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls == JW_SEN) {
            l[0] = l[1];
            l[1] = &ref.obj[i];
            nl++;
        }
        if (ref.obj[i].cls == JW_ENKO)
            circle = &ref.obj[i];
    }
    if (nl < 2 || !circle) {
        printf("BAD  %s has no pair of lines and a circle\n", path);
        fails++;
        jw_free(&ref);
        return;
    }

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < 2; i++) {
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = l[i]->d[0];
        o->d[1] = l[i]->d[1];
        o->d[2] = l[i]->d[2];
        o->d[3] = l[i]->d[3];
    }
    app_fit();
    before = d->ndrawn;

    printf("%s\n", what);
    jw_cmd_set(JW_CMD_SEKIEN);
    /* the box keeps what was typed into it across commands, the way the
       original's does, so empty it again for each run */
    type_box(1411, "");
    jw_cmd_set(JW_CMD_SEKIEN);
    ck(jw_cmd_box(1411) && !*jw_cmd_box(1411),
       "  接円's 半径 is empty to start with, as the original's is");
    jw_cmd_point(d, app_view(), (l[0]->d[0] + l[0]->d[2]) / 2,
                 (l[0]->d[1] + l[0]->d[3]) / 2, 0);
    jw_cmd_point(d, app_view(), (l[1]->d[0] + l[1]->d[2]) / 2,
                 (l[1]->d[1] + l[1]->d[3]) / 2, 0);
    jw_cmd_point(d, app_view(), circle->d[0], circle->d[1], 0);
    ck(d->ndrawn == before, "  and draws nothing while it is empty");

    /* with the box empty the third click is a third element, not a place to
       put the circle, so that run is still waiting for one -- start over */
    jw_cmd_set(JW_CMD_SEKIEN);
    type_box(1411, "2000");
    jw_cmd_point(d, app_view(), (l[0]->d[0] + l[0]->d[2]) / 2,
                 (l[0]->d[1] + l[0]->d[3]) / 2, 0);
    jw_cmd_point(d, app_view(), (l[1]->d[0] + l[1]->d[2]) / 2,
                 (l[1]->d[1] + l[1]->d[3]) / 2, 0);
    ck(d->ndrawn == before, "  two lines on their own draw nothing");
    jw_cmd_point(d, app_view(), circle->d[0], circle->d[1], 0);
    ck(d->ndrawn == before + 1, "  the third click draws one circle");
    if (d->ndrawn != before + 1) {
        jw_free(&ref);
        return;
    }
    {
        const jw_obj *o = &d->obj[before];
        int same = near(o->d[0], circle->d[0]) && near(o->d[1], circle->d[1])
                && near(o->d[2], circle->d[2]);

        if (!same)
            printf("     ours          %.6f,%.6f r=%.6f\n"
                   "     the original's %.6f,%.6f r=%.6f\n",
                   o->d[0], o->d[1], o->d[2],
                   circle->d[0], circle->d[1], circle->d[2]);
        ck(same, "  the centre and the radius the original chose");
        ck(near(o->d[3], circle->d[3]) && near(o->d[4], circle->d[4])
           && near(o->d[5], circle->d[5]) && near(o->d[6], circle->d[6])
           && o->n == circle->n,
           "  and the rest of the record, the whole way round");
        ck(o->color == 2 && o->ltype == 1, "  in the pen new elements get");
        ck(fabs(off(l[0], o->d[0], o->d[1]) - o->d[2]) < 1e-6
           && fabs(off(l[1], o->d[0], o->d[1]) - o->d[2]) < 1e-6,
           "  touching both lines exactly");
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes it back");
    jw_free(&ref);
}

/* The same command over elements other than two lines.
 *
 * Everything the original drew past Test5's own is read back: the last circle
 * is its answer and what comes before are the elements it was given, in the
 * order they were picked.  Each is pointed at on itself -- a line at its
 * middle, a circle at its rim -- and, when there is a 半径, the circle is
 * asked for where the original's came out, which is the place nearest that
 * one of the several the radius allows.
 *
 * `radius` is what goes in the 半径 box; an empty one means the third element
 * settles it instead, and then there is no placing click.
 */
static void run_el(const char *path, const char *radius, int want,
                   const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *el[8], *circle;
    int i, nb, nel = 0, before;

    printf("%s\n", what);
    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    nb = d->ndrawn;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        fails++;
        return;
    }
    free(b);
    /* the original leaves six CDataMoji of its own settings at the end of
       every file it writes, so stop at the first thing that is neither a
       line nor a circle */
    for (i = nb; i < ref.ndrawn && nel < 8; i++) {
        if (ref.obj[i].cls != JW_SEN && ref.obj[i].cls != JW_ENKO)
            break;
        el[nel++] = &ref.obj[i];
    }
    if (nel != want + 1) {
        printf("BAD  %s has %d elements past Test5's own, not %d\n",
               path, nel, want + 1);
        fails++;
        jw_free(&ref);
        return;
    }
    circle = el[--nel];
    ck(circle->cls == JW_ENKO, "  the original's answer is a circle");

    for (i = 0; i < nel; i++) {
        jw_obj *o = jw_add(d, el[i]->cls);
        int k;

        for (k = 0; k < 7; k++)
            o->d[k] = el[i]->d[k];
        o->n = el[i]->n;
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_SEKIEN);
    type_box(1411, radius);
    jw_cmd_set(JW_CMD_SEKIEN);
    for (i = 0; i < nel; i++) {
        double px, py;

        if (el[i]->cls == JW_SEN) {
            px = (el[i]->d[0] + el[i]->d[2]) / 2;
            py = (el[i]->d[1] + el[i]->d[3]) / 2;
        } else {
            px = el[i]->d[0] + el[i]->d[2];
            py = el[i]->d[1];
        }
        jw_cmd_point(d, app_view(), px, py, 0);
        if (i < nel - 1 || *radius)
            ck(d->ndrawn == before, "  nothing yet");
    }
    if (*radius) {
        ck(d->ndrawn == before, "  the elements alone draw nothing");
        jw_cmd_point(d, app_view(), circle->d[0], circle->d[1], 0);
    }
    ck(d->ndrawn == before + 1, "  one circle comes out");
    if (d->ndrawn != before + 1) {
        jw_free(&ref);
        return;
    }
    {
        const jw_obj *o = &d->obj[before];
        int same = near(o->d[0], circle->d[0]) && near(o->d[1], circle->d[1])
                && near(o->d[2], circle->d[2]);

        if (!same)
            printf("     ours          %.6f,%.6f r=%.6f\n"
                   "     the original's %.6f,%.6f r=%.6f\n",
                   o->d[0], o->d[1], o->d[2],
                   circle->d[0], circle->d[1], circle->d[2]);
        ck(same, "  where the original put it, to the last digit");
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes it back");
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/sekien_l.jww", "the circle placed to the left:");
    run("decomp/res/sekien_r.jww", "to the right:");
    run("decomp/res/sekien_t.jww", "above:");
    run("decomp/res/sekien_b.jww", "below:");
    run_el("decomp/res/seklc_a.jww", "20000", 2,
           "a line and a circle, r 100, the circle placed left:");
    run_el("decomp/res/seklc_b.jww", "20000", 2, "and right:");
    run_el("decomp/res/sekcc_n.jww", "40000", 2,
           "two circles, r 200, placed above:");
    run_el("decomp/res/sekcc_s.jww", "40000", 2, "below:");
    run_el("decomp/res/sekcc_e.jww", "40000", 2, "to the right:");
    run_el("decomp/res/sekcc_w.jww", "40000", 2, "to the left:");
    run_el("decomp/res/sek3.jww", "", 3,
           "three lines and an empty 半径 -- the circle inside them:");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
