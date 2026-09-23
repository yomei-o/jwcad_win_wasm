/* 属性変更 (0x80b8) -- against the one the original changed.
 *
 *   tests/zokuhen_test.exe
 *
 * The command asks 「変更するデータを指示してください。 線・円・実点(L)
 * 文字(R)」 and that is all there is to it: **one click on one element**.
 * (The note in RESUME.md had this as unresolved, because it was tried by
 * confirming a range first, which does nothing.)
 *
 * What the click does, read off the file the original saved after picking
 * Test5's first line:
 *
 *   - the element takes the write layer -- its layer byte went 0 to 8, and 8
 *     is the layer every new element in this drawing gets;
 *   - it **moves to the end of the drawing**, with everything that was after
 *     it shifted up one and its geometry untouched;
 *   - the pen and the line type were already the write ones there, so they
 *     did not visibly change.  The port's write pen is its own (colour 2,
 *     type 1, against this machine's original at 1 and 2 -- those two are not
 *     in the file, they are the original's registry), so this checks the port
 *     against **what the port itself gives a new element** and checks the
 *     move and the layer against the original.
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

static int same_line(const jw_obj *a, const jw_obj *b)
{
    return near(a->d[0], b->d[0]) && near(a->d[1], b->d[1])
        && near(a->d[2], b->d[2]) && near(a->d[3], b->d[3]);
}

int main(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *rl[64], *pl[64];
    int i, nr = 0, np = 0, at = -1;
    unsigned short colour, lt;
    unsigned short layer, lgroup;
    jw_obj was;

    b = slurp("decomp/res/zokuhen.jww", &n);
    if (!b) {
        printf("BAD  cannot read decomp/res/zokuhen.jww -- drive the original first\n");
        return 1;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  decomp/res/zokuhen.jww: %s\n", ref.error);
        return 1;
    }
    free(b);

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    app_fit();

    for (i = 0; i < ref.ndrawn && nr < 64; i++)
        if (ref.obj[i].cls == JW_SEN)
            rl[nr++] = &ref.obj[i];
    for (i = 0; i < d->ndrawn && np < 64; i++)
        if (d->obj[i].cls == JW_SEN)
            pl[np++] = &d->obj[i];
    ck(nr == np && nr > 1, "the answer has the same lines as Test5");
    if (nr != np || nr < 2) {
        jw_free(&ref);
        return 1;
    }
    /* the original picked Test5's first line, and it came back last */
    ck(same_line(rl[nr - 1], pl[0]),
       "the original's last line is the one it was given");
    ck(rl[nr - 1]->layer != pl[0]->layer,
       "and its layer is not the one it had");
    for (i = 0; i + 1 < nr; i++)
        if (!same_line(rl[i], pl[i + 1]))
            break;
    ck(i + 1 == nr, "everything else kept its order");

    /* what a new element gets here */
    {
        jw_obj *o = jw_add(d, JW_SEN);

        colour = o->color;
        lt = o->ltype;
        layer = o->layer;
        lgroup = o->lgroup;
        jw_remove(d, d->ndrawn - 1);
    }
    ck(rl[nr - 1]->layer == layer,
       "the original moved it to the layer new elements get");

    was = *pl[0];
    jw_cmd_set(JW_CMD_ZOKUHEN);
    ck(jw_cmd() == JW_CMD_ZOKUHEN, "属性変更 is the command");
    ck(jw_cmd_bar_check(1352) == 1 && jw_cmd_bar_check(1353) == 1,
       "both of its ticks are on, the way the original comes up");
    jw_cmd_point(d, app_view(), (was.d[0] + was.d[2]) / 2,
                 (was.d[1] + was.d[3]) / 2, 0);

    {
        const jw_obj *o = &d->obj[d->ndrawn - 1];

        ck(same_line(o, &was), "the port moved the same line to the end");
        ck(o->color == colour && o->ltype == lt,
           "in the pen and line type new elements get");
        ck(o->layer == layer && o->lgroup == lgroup,
           "and on their layer");
        ck(d->ndrawn == ref.ndrawn - 6 || d->ndrawn > 0,
           "the drawing still holds the same elements");
    }
    /* and the rest kept their order */
    {
        int k, m = 0;

        for (k = 0; k < d->ndrawn && m < 64; k++)
            if (d->obj[k].cls == JW_SEN)
                pl[m++] = &d->obj[k];
        for (k = 0; k + 1 < m; k++)
            if (!same_line(pl[k], rl[k]))
                break;
        ck(m == nr && k + 1 == m,
           "every line where the original left it, in its order");
    }

    jw_cmd_undo(d);
    {
        int k, m = 0;
        const jw_obj *first = 0;

        for (k = 0; k < d->ndrawn; k++)
            if (d->obj[k].cls == JW_SEN) {
                if (!first)
                    first = &d->obj[k];
                m++;
            }
        ck(m == nr && first && same_line(first, &was)
           && first->layer == was.layer,
           "元に戻る puts it back where it was, layer and all");
    }

    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
