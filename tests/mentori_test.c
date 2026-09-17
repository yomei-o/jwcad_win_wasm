/* 面取 -- against the chamfer the original cut.
 *
 *   tests/mentori_test.exe [decomp/res/mentori.jww]
 *
 * That file is Test5 with two lines drawn on it in an L and the corner cut
 * with 寸法 2000 typed into the command bar.  The test draws the same L
 * here, types the same number, picks the same two lines, and holds all three
 * lines up against the original's.
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
    const char *path = argc > 1 ? argv[1] : "decomp/res/mentori.jww";
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[3];
    int i, k = 0, before;
    double ax, ay, bx, by, cx, cy;

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
    /* the original's three lines are the last three in the file */
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN) {
            r[0] = r[1];
            r[1] = r[2];
            r[2] = &ref.obj[i];
            k++;
        }
    ck(k >= 3, "the original's chamfer is in the file");
    if (k < 3)
        return 1;
    /* the L as it was drawn: the level line's far end, the corner, and the
       upright line's far end.  The cut ends are r[0]->d[0] and r[1]->d[0]. */
    ax = r[0]->d[2];
    ay = r[0]->d[3];
    cx = r[1]->d[0];
    cy = r[0]->d[1];            /* the corner they met at */
    bx = r[1]->d[2];
    by = r[1]->d[3];

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {   /* the same two lines, drawn the way they were */
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = ax; o->d[1] = ay; o->d[2] = cx; o->d[3] = cy;
        o = jw_add(d, JW_SEN);
        o->d[0] = cx; o->d[1] = cy; o->d[2] = bx; o->d[3] = by;
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_MENTORI);
    ck(jw_cmd_box(1411) && !*jw_cmd_box(1411),
       "面取 starts with an empty 寸法, as the original does");
    /* with nothing typed in it, nothing is cut */
    jw_cmd_point(d, app_view(), (ax + cx) / 2, (ay + cy) / 2, 0);
    jw_cmd_point(d, app_view(), (bx + cx) / 2, (by + cy) / 2, 0);
    ck(d->ndrawn == before && near(d->obj[before - 2].d[2], cx),
       "and cuts nothing while it is empty");

    type_box(1411, "2000");
    jw_cmd_point(d, app_view(), (ax + cx) / 2, (ay + cy) / 2, 0);
    jw_cmd_point(d, app_view(), (bx + cx) / 2, (by + cy) / 2, 0);
    ck(d->ndrawn == before + 1, "with a size in it, one line is added");
    if (d->ndrawn != before + 1)
        return 1;
    ck(near(d->obj[before - 2].d[0], r[0]->d[0])
       && near(d->obj[before - 2].d[1], r[0]->d[1])
       && near(d->obj[before - 2].d[2], r[0]->d[2])
       && near(d->obj[before - 2].d[3], r[0]->d[3]),
       "the first line is cut back exactly as the original's is");
    ck(near(d->obj[before - 1].d[0], r[1]->d[0])
       && near(d->obj[before - 1].d[1], r[1]->d[1])
       && near(d->obj[before - 1].d[2], r[1]->d[2])
       && near(d->obj[before - 1].d[3], r[1]->d[3]),
       "and so is the second");
    ck(near(d->obj[before].d[0], r[2]->d[0])
       && near(d->obj[before].d[1], r[2]->d[1])
       && near(d->obj[before].d[2], r[2]->d[2])
       && near(d->obj[before].d[3], r[2]->d[3]),
       "and the new line joins them where the original's does");
    jw_cmd_undo(d);
    ck(d->ndrawn == before && near(d->obj[before - 2].d[2], cx)
       && near(d->obj[before - 1].d[0], cx),
       "元に戻る puts the corner back");

    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
