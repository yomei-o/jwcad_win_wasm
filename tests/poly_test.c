/* 多角形 -- against the one the original drew.
 *
 *   tests/poly_test.exe [decomp/res/poly.jww]
 *
 * That file is Test5 with an octagon on it, made by driving Jw_cad with
 * 角数 8, 寸法 3000 and 底辺角度 30 typed into the command bar and one click
 * for the centre.  The test types the same three numbers into the port's own
 * boxes, clicks the same centre, and holds the eight lines up against the
 * original's.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/bars.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
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

/* type into one of the bar's boxes, the way a press and the keys would */
static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);              /* clear it */
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "decomp/res/poly.jww";
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj **ref8 = 0;
    double cx = 0, cy = 0;
    int i, j, nref = 0, before, ok;

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
    /* the original's octagon is the last eight lines in the file -- the six
       records Jw_cad adds when it saves come after them, so they have to be
       stepped over */
    {
        static const jw_obj *sen[8];
        for (i = 0; i < ref.ndrawn; i++)
            if (ref.obj[i].cls == JW_SEN) {
                for (j = 0; j < 7; j++)
                    sen[j] = sen[j + 1];
                sen[7] = &ref.obj[i];
                nref++;
            }
        if (nref >= 8) {
            for (i = 0; i < 8; i++) {
                cx += sen[i]->d[0];
                cy += sen[i]->d[1];
            }
            cx /= 8;
            cy /= 8;
        }
        ref8 = sen;
    }
    ck(nref >= 8, "the original's octagon is in the file");

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    before = d->ndrawn;

    /* the boxes are what the bar shows, and they can be typed into */
    jw_cmd_set(JW_CMD_TAKAKU);
    ck(jw_cmd_box(1411) && !strcmp(jw_cmd_box(1411), "1000"),
       "寸法 starts at 1000, the way the original's does");
    ck(jw_cmd_box(1413) && !strcmp(jw_cmd_box(1413), "5"), "角数 at 5");
    ck(jw_cmd_box(1414) && !strcmp(jw_cmd_box(1414), "0"), "底辺角度 at 0");
    ck(jw_cmd_box(9999) == 0, "and a box the port does not keep says so");
    type_box(1413, "8");
    type_box(1411, "3000");
    type_box(1414, "30");
    ck(!strcmp(jw_cmd_box(1413), "8") && !strcmp(jw_cmd_box(1411), "3000")
       && !strcmp(jw_cmd_box(1414), "30"), "typing into them takes");
    ck(jw_cmd_box_focus() == 0, "and Enter puts the caret away");

    jw_cmd_point(d, app_view(), cx, cy, 0);
    ck(d->ndrawn == before + 8, "one click leaves the eight lines");
    if (d->ndrawn != before + 8)
        return 1;
    ok = 1;
    for (i = 0; i < 8; i++) {
        /* the original's lines and ours are the same set; they need not be
           written down in the same order for the shape to be the same */
        int found = 0;
        for (j = 0; j < 8; j++)
            if (fabs(d->obj[before + i].d[0] - ref8[j]->d[0]) < 1e-9
                && fabs(d->obj[before + i].d[1] - ref8[j]->d[1]) < 1e-9
                && fabs(d->obj[before + i].d[2] - ref8[j]->d[2]) < 1e-9
                && fabs(d->obj[before + i].d[3] - ref8[j]->d[3]) < 1e-9)
                found = 1;
        if (!found) {
            ok = 0;
            printf("     ours %.4f,%.4f -> %.4f,%.4f is not one of the "
                   "original's\n", d->obj[before + i].d[0],
                   d->obj[before + i].d[1], d->obj[before + i].d[2],
                   d->obj[before + i].d[3]);
        }
    }
    ck(ok, "every one of them where the original put it");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "元に戻る takes the whole polygon back");

    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
