/* 分割 -- against the dividers the original drew.
 *
 *   tests/bunkatsu_test.exe [decomp/res/bunkatsu.jww]
 *
 * That file is Test5 with two lines on it -- neither parallel nor the same
 * length -- divided three ways, 分割数 3 typed into the command bar.  The
 * test draws the same two lines, types the same number, picks them, and
 * holds its two dividers up against the original's.  The original wrote the
 * ends of its pair the other way round, so the comparison takes a line
 * either way about.
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

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "decomp/res/bunkatsu.jww";
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[4];
    int i, k = 0, before, ok;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        return 1;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        return 1;
    }
    free(b);
    /* the two lines that were drawn and the two dividers are the last four */
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN) {
            r[0] = r[1];
            r[1] = r[2];
            r[2] = r[3];
            r[3] = &ref.obj[i];
            k++;
        }
    ck(k >= 4, "the original's dividers are in the file");
    if (k < 4)
        return 1;

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {   /* the same two lines */
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = r[0]->d[0]; o->d[1] = r[0]->d[1];
        o->d[2] = r[0]->d[2]; o->d[3] = r[0]->d[3];
        o = jw_add(d, JW_SEN);
        o->d[0] = r[1]->d[0]; o->d[1] = r[1]->d[1];
        o->d[2] = r[1]->d[2]; o->d[3] = r[1]->d[3];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_BUNKATSU);
    ck(jw_cmd_box(1411) && !*jw_cmd_box(1411),
       "分割 starts with an empty 分割数");
    {   /* pick the two lines by their middles */
        double a1x = (r[0]->d[0] + r[0]->d[2]) / 2;
        double a1y = (r[0]->d[1] + r[0]->d[3]) / 2;
        double b1x = (r[1]->d[0] + r[1]->d[2]) / 2;
        double b1y = (r[1]->d[1] + r[1]->d[3]) / 2;
        jw_cmd_point(d, app_view(), a1x, a1y, 0);
        jw_cmd_point(d, app_view(), b1x, b1y, 0);
        ck(d->ndrawn == before, "and divides nothing while it is empty");
        type_box(1411, "3");
        jw_cmd_point(d, app_view(), a1x, a1y, 0);
        jw_cmd_point(d, app_view(), b1x, b1y, 0);
    }
    ck(d->ndrawn == before + 2, "3 leaves two lines between them");
    if (d->ndrawn != before + 2)
        return 1;
    ok = same_line(&d->obj[before], r[2]) && same_line(&d->obj[before + 1], r[3]);
    if (!ok) {
        for (i = 0; i < 2; i++)
            printf("     ours %.4f,%.4f -> %.4f,%.4f\n",
                   d->obj[before + i].d[0], d->obj[before + i].d[1],
                   d->obj[before + i].d[2], d->obj[before + i].d[3]);
        for (i = 2; i < 4; i++)
            printf("     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
    }
    ck(ok, "both exactly where the original put them");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "元に戻る takes both back");

    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
