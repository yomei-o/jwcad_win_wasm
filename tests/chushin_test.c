/* 中心線 -- against the two the original drew.
 *
 *   tests/chushin_test.exe
 *
 * decomp/res/chushin.jww has two level lines with the middle one between
 * them; decomp/res/chushin2.jww has two that meet at an angle, where the
 * middle is the bisector.  Each file holds the two lines that were picked
 * and then the line that came out, so the test draws the first two, picks
 * them, gives the same two points, and compares.
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
        printf("BAD  %s has no middle line in it\n", path);
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
    for (i = 0; i < 2; i++) {
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = r[i]->d[0];
        o->d[1] = r[i]->d[1];
        o->d[2] = r[i]->d[2];
        o->d[3] = r[i]->d[3];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_CHUSHIN);
    jw_cmd_point(d, app_view(), (r[0]->d[0] + r[0]->d[2]) / 2,
                 (r[0]->d[1] + r[0]->d[3]) / 2, 0);
    jw_cmd_point(d, app_view(), (r[1]->d[0] + r[1]->d[2]) / 2,
                 (r[1]->d[1] + r[1]->d[3]) / 2, 0);
    ck(d->ndrawn == before, "two picks on their own draw nothing");
    /* the two points: the ends of the original's own middle line, which are
       already on it, so dropping them onto it changes nothing */
    jw_cmd_point(d, app_view(), r[2]->d[0], r[2]->d[1], 0);
    jw_cmd_point(d, app_view(), r[2]->d[2], r[2]->d[3], 0);
    printf("%s\n", what);
    ck(d->ndrawn == before + 1, "  the two points draw one line");
    if (d->ndrawn != before + 1) {
        jw_free(&ref);
        return;
    }
    if (!(near(d->obj[before].d[0], r[2]->d[0])
          && near(d->obj[before].d[1], r[2]->d[1])
          && near(d->obj[before].d[2], r[2]->d[2])
          && near(d->obj[before].d[3], r[2]->d[3])))
        printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
               "     the original's %.4f,%.4f -> %.4f,%.4f\n",
               d->obj[before].d[0], d->obj[before].d[1],
               d->obj[before].d[2], d->obj[before].d[3],
               r[2]->d[0], r[2]->d[1], r[2]->d[2], r[2]->d[3]);
    ck(near(d->obj[before].d[0], r[2]->d[0])
       && near(d->obj[before].d[1], r[2]->d[1])
       && near(d->obj[before].d[2], r[2]->d[2])
       && near(d->obj[before].d[3], r[2]->d[3]),
       "  exactly where the original's is");
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/chushin.jww", "two lines that run together:");
    run("decomp/res/chushin2.jww", "two that meet at an angle:");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
