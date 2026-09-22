/* 接線 (0x8066, 円→円) -- against the four the original drew.
 *
 *   tests/sessen_test.exe
 *
 * Two circles have four common tangents.  The original was given the same
 * pair four times and pointed at top/top, bottom/bottom, top/bottom and
 * bottom/top; it came back with four different lines, and each one touches
 * each circle on the side it was pointed at (decomp/res/sessen_*.jww).  Every
 * one of them is an exact tangent -- the distance from a centre to its end of
 * the line is the radius to four decimals -- and the ends are the tangency
 * points themselves.
 *
 * So the check is: rebuild the two circles in the port, point at the touch
 * points the original left (they are on the circle, on the right side), and
 * the line that comes out has to be the original's.
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

/* one of the four runs */
static void run(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *c[2], *line = 0;
    int i, nc = 0, before;

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
    /* the two circles it drew, and the last line, which is the tangent */
    for (i = 0; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls == JW_ENKO && nc < 2)
            c[nc++] = &ref.obj[i];
        if (ref.obj[i].cls == JW_SEN)
            line = &ref.obj[i];
    }
    if (nc < 2 || !line) {
        printf("BAD  %s has no pair of circles and a tangent\n", path);
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
        jw_obj *o = jw_add(d, JW_ENKO);
        int k;
        for (k = 0; k < 7; k++)
            o->d[k] = c[i]->d[k];
    }
    app_fit();
    before = d->ndrawn;

    printf("%s\n", what);
    jw_cmd_set(JW_CMD_SESSEN);
    jw_cmd_point(d, app_view(), line->d[0], line->d[1], 0);
    ck(d->ndrawn == before, "  one circle on its own draws nothing");
    jw_cmd_point(d, app_view(), line->d[2], line->d[3], 0);
    ck(d->ndrawn == before + 1, "  the second circle draws one line");
    if (d->ndrawn != before + 1) {
        jw_free(&ref);
        return;
    }
    {
        const jw_obj *o = &d->obj[before];
        int same = (near(o->d[0], line->d[0]) && near(o->d[1], line->d[1])
                    && near(o->d[2], line->d[2]) && near(o->d[3], line->d[3]))
                || (near(o->d[0], line->d[2]) && near(o->d[1], line->d[3])
                    && near(o->d[2], line->d[0]) && near(o->d[3], line->d[1]));
        if (!same)
            printf("     ours          %.4f,%.4f -> %.4f,%.4f\n"
                   "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   o->d[0], o->d[1], o->d[2], o->d[3],
                   line->d[0], line->d[1], line->d[2], line->d[3]);
        ck(same, "  exactly the one the original drew");
        ck(o->color == 2 && o->ltype == 1,
           "  in the pen new elements get");
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes it back");
    jw_free(&ref);
}

/* 点→円: the reference holds the circle and the line, whose first end is the
   point that was given and whose second is where it touches. */
static void run_point(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *circle = 0, *line = 0;
    int i, before, k;

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
    for (i = 0; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls == JW_ENKO && !circle)
            circle = &ref.obj[i];
        if (ref.obj[i].cls == JW_SEN)
            line = &ref.obj[i];
    }
    if (!circle || !line) {
        printf("BAD  %s has no circle and tangent\n", path);
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
    {
        jw_obj *o = jw_add(d, JW_ENKO);
        for (k = 0; k < 7; k++)
            o->d[k] = circle->d[k];
    }
    app_fit();
    before = d->ndrawn;

    printf("%s\n", what);
    jw_cmd_set(JW_CMD_SESSEN);
    ck(jw_cmd_bar(d, 1690) == 1, "  点→円 can be pressed");
    /* the point first, then the circle -- the other way round draws nothing,
       which is what the original does too */
    jw_cmd_point(d, app_view(), line->d[0], line->d[1], 0);
    ck(d->ndrawn == before, "  the point on its own draws nothing");
    jw_cmd_point(d, app_view(), line->d[2], line->d[3], 0);
    ck(d->ndrawn == before + 1, "  pointing at the circle draws one line");
    if (d->ndrawn != before + 1) {
        jw_free(&ref);
        return;
    }
    {
        const jw_obj *o = &d->obj[before];
        int same = near(o->d[0], line->d[0]) && near(o->d[1], line->d[1])
                && near(o->d[2], line->d[2]) && near(o->d[3], line->d[3]);
        if (!same)
            printf("     ours          %.4f,%.4f -> %.4f,%.4f\n"
                   "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   o->d[0], o->d[1], o->d[2], o->d[3],
                   line->d[0], line->d[1], line->d[2], line->d[3]);
        ck(same, "  exactly the one the original drew");
        {   /* and it really is a tangent */
            double dx = o->d[2] - circle->d[0], dy = o->d[3] - circle->d[1];
            ck(fabs(sqrt(dx * dx + dy * dy) - circle->d[2]) < 1e-6,
               "  touching the circle exactly");
        }
    }
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/sessen_tt.jww", "pointed at the top of both:");
    run("decomp/res/sessen_bb.jww", "the bottom of both:");
    run("decomp/res/sessen_tb.jww", "the top of one and the bottom of the other:");
    run("decomp/res/sessen_bt.jww", "and the other way round:");
    run_point("decomp/res/tensen_ur.jww",
              "点→円, the circle pointed at up and to the right:");
    run_point("decomp/res/tensen_lr.jww", "down and to the right:");
    run_point("decomp/res/tensen_ul.jww", "up and to the left:");
    run_point("decomp/res/tensen_ll.jww", "down and to the left:");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
