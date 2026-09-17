/* ２線 -- against the pairs the original drew.
 *
 *   tests/nisen_test.exe
 *
 * Two runs of the original are held up against: decomp/res/nisen.jww, where
 * the line to run along was drawn left to right and the two points were on
 * it, and decomp/res/nisen2.jww, where the same line was drawn right to left
 * and the points were above it.  Between them they say that the two sides
 * follow the line's own direction and not where it was clicked.
 *
 * Both were made with 間隔 2000,1000 on a 1/200 group, so the pair should
 * come out 10 mm one side and 5 mm the other.
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

static int same_line(const jw_obj *a, const jw_obj *b)
{
    return (near(a->d[0], b->d[0]) && near(a->d[1], b->d[1])
            && near(a->d[2], b->d[2]) && near(a->d[3], b->d[3]))
        || (near(a->d[0], b->d[2]) && near(a->d[1], b->d[3])
            && near(a->d[2], b->d[0]) && near(a->d[3], b->d[1]));
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

/* one of the two runs: the file has the line that was drawn and the pair */
static void run(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[3];
    int i, k = 0, before;

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
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN) {
            r[0] = r[1];
            r[1] = r[2];
            r[2] = &ref.obj[i];
            k++;
        }
    if (k < 3) {
        printf("BAD  %s has no pair in it\n", path);
        fails++;
        return;
    }

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {   /* the line it ran along, drawn the way it was */
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = r[0]->d[0];
        o->d[1] = r[0]->d[1];
        o->d[2] = r[0]->d[2];
        o->d[3] = r[0]->d[3];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "2000,1000");
    {   /* pick it in the middle, then the two ends of the pair -- which are
           where the original's two lines start and stop */
        double mx = (r[0]->d[0] + r[0]->d[2]) / 2;
        double my = (r[0]->d[1] + r[0]->d[3]) / 2;
        jw_cmd_point(d, app_view(), mx, my, 0);
        jw_cmd_point(d, app_view(), r[1]->d[0], r[1]->d[1], 0);
        jw_cmd_point(d, app_view(), r[1]->d[2], r[1]->d[3], 0);
    }
    printf("%s\n", what);
    ck(d->ndrawn == before + 2, "  two lines come out");
    if (d->ndrawn == before + 2) {
        int ok = (same_line(&d->obj[before], r[1])
                  && same_line(&d->obj[before + 1], r[2]))
              || (same_line(&d->obj[before], r[2])
                  && same_line(&d->obj[before + 1], r[1]));
        if (!ok) {
            for (i = 0; i < 2; i++)
                printf("     ours %.4f,%.4f -> %.4f,%.4f\n",
                       d->obj[before + i].d[0], d->obj[before + i].d[1],
                       d->obj[before + i].d[2], d->obj[before + i].d[3]);
            printf("     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   r[1]->d[0], r[1]->d[1], r[1]->d[2], r[1]->d[3]);
            printf("     and            %.4f,%.4f -> %.4f,%.4f\n",
                   r[2]->d[0], r[2]->d[1], r[2]->d[2], r[2]->d[3]);
        }
        ck(ok, "  both where the original put them");
    }
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/nisen.jww",
        "the line drawn left to right, the points on it:");
    run("decomp/res/nisen2.jww",
        "the same line drawn the other way, the points above it:");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
