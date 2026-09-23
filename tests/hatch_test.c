/* ハッチ (0x806a), 1線 -- against the two the original drew.
 *
 *   tests/hatch_test.exe
 *
 * The boundary is settled with the right button -- 「閉鎖連続線・円をマウス(R)で
 * 指示してください」 -- and 実行 stays greyed until one is: picking a rectangle's
 * four sides one at a time with the left button left it greyed and drew
 * nothing, while one right click on any of them took the whole ring.
 *
 * What it draws then is simple, and came out exact both times.  The lines sit
 * where the normal of the 角度 direction times the point is a whole multiple
 * of the ピッチ -- anchored at zero rather than at the region, so a hatch over
 * two regions lines up -- and each line is exactly the chord of the region at
 * that offset.  A circle of radius 129.88 at 45 degrees and pitch 10 gave 26
 * chords at offsets 190 down to -60, and a rectangle 49 at 300 down to -180
 * (decomp/res/hatch_*.jww).  They come out far side first.
 *
 * ２線 (1690) and ３線 (1691) draw two and three lines per ピッチ, 線間隔
 * apart and centred on where the one line would have been: the same rectangle
 * came back with 98 lines at 300.5, 299.5, 290.5, 289.5 ... and with 147 at
 * 301, 300, 299, 291, 290, 289 ... (decomp/res/hatch_r169*.jww).  So the
 * group still goes far side first, and so does the group's own inside.
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

/* Test5's own 46 lines come first; `skip` more are the boundary the run drew
   before the hatch itself. */
static void run(const char *path, int skip, int want, int mode,
                const char *what)
{
    unsigned char *b;
    long len;
    jw_drawing ref, *d;
    const jw_obj *all[4096], *circle = 0, *seg[256];
    int i, na = 0, before, ns = 0;
    double worst = 0;

    printf("%s\n", what);
    b = slurp(path, &len);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, len)) {
        printf("BAD  %s: %s\n", path, ref.error);
        fails++;
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls == JW_SEN && na < 4096)
            all[na++] = &ref.obj[i];
        if (ref.obj[i].cls == JW_ENKO)
            circle = &ref.obj[i];
    }
    ck(na >= want + skip, "  the original's hatch is in the file");
    if (na < want + skip) {
        jw_free(&ref);
        return;
    }
    for (i = na - want; i < na && ns < 256; i++)
        seg[ns++] = all[i];

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &len);
    if (!b || !app_open(b, len)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    if (skip) {
        /* the boundary ring the original drew, before its hatch */
        for (i = 0; i < skip; i++) {
            jw_obj *o = jw_add(d, JW_SEN);
            const jw_obj *r = all[na - want - skip + i];
            o->d[0] = r->d[0];
            o->d[1] = r->d[1];
            o->d[2] = r->d[2];
            o->d[3] = r->d[3];
        }
    } else {
        jw_obj *o = jw_add(d, JW_ENKO);
        int k;
        ck(circle != 0, "  and so is the circle it hatched");
        if (!circle) {
            jw_free(&ref);
            return;
        }
        for (k = 0; k < 7; k++)
            o->d[k] = circle->d[k];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_HATCH);
    ck(jw_cmd_box(1419) && !strcmp(jw_cmd_box(1419), "45")
       && jw_cmd_box(1411) && !strcmp(jw_cmd_box(1411), "10")
       && jw_cmd_box(1412) && !strcmp(jw_cmd_box(1412), "1"),
       "  角度 45・ピッチ 10・線間隔 1 to start with, as the original has them");
    if (mode != 1689)
        ck(jw_cmd_bar(d, mode) == 1, "  the mode button can be pressed");
    /* the left button picks one line at a time, which is not done and which
       the original leaves 実行 greyed for anyway */
    jw_cmd_point(d, app_view(), seg[0]->d[0], seg[0]->d[1], 0);
    ck(jw_cmd_bar(d, 1148) == 1, "  実行 can be pressed");
    ck(d->ndrawn == before, "  but with no boundary it draws nothing");

    /* the right button on the boundary */
    if (skip)
        jw_cmd_point(d, app_view(),
                     (d->obj[before - skip].d[0] + d->obj[before - skip].d[2]) / 2,
                     (d->obj[before - skip].d[1] + d->obj[before - skip].d[3]) / 2, 1);
    else
        jw_cmd_point(d, app_view(), circle->d[0] + circle->d[2], circle->d[1], 1);
    ck(d->ndrawn == before, "  picking the boundary draws nothing on its own");
    ck(jw_cmd_bar(d, 1148) == 1, "  実行 runs");
    ck(d->ndrawn == before + want, "  and leaves as many lines as the original");
    if (d->ndrawn != before + want) {
        printf("     ours %d, the original's %d\n", d->ndrawn - before, want);
        jw_free(&ref);
        return;
    }
    for (i = 0; i < want; i++) {
        int k;
        for (k = 0; k < 4; k++) {
            double e = fabs(d->obj[before + i].d[k] - seg[i]->d[k]);
            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6)
        printf("     worst disagreement %.6g\n"
               "     ours   %.6f,%.6f -> %.6f,%.6f\n"
               "     theirs %.6f,%.6f -> %.6f,%.6f\n", worst,
               d->obj[before].d[0], d->obj[before].d[1],
               d->obj[before].d[2], d->obj[before].d[3],
               seg[0]->d[0], seg[0]->d[1], seg[0]->d[2], seg[0]->d[3]);
    ck(worst <= 1e-6, "  every line where the original put it, in its order");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "  in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the whole hatch back");
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/hatch_circle.jww", 0, 26, 1689,
        "a circle, 45 degrees, pitch 10:");
    run("decomp/res/hatch_rect.jww", 4, 49, 1689, "a rectangle, the same:");
    run("decomp/res/hatch_r1690.jww", 4, 98, 1690,
        "the same rectangle, ２線, 線間隔 1:");
    run("decomp/res/hatch_r1691.jww", 4, 147, 1691,
        "the same rectangle, ３線, 線間隔 1:");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
