/* 連続線の 連続弧 (2492) -- against two runs of the original.
 *
 *   tests/renarc_test.exe
 *
 * With it ticked the command strings **arcs** together instead of
 * segments.  Its own prompts spell the walk out (tools/probe99.sh):
 *
 *     始点を指示してください
 *     　　◎　円弧の中間点を指示してください
 *     ◆　　終点を指示してください
 *     ◆　　終点を指示してください  << 同一点再指示で終了 ﾏｳｽ（L) >>
 *
 * so three points make the first arc and every click after that adds one
 * more; clicking the same point again ends the chain (with the **left**
 * button -- the right one does not, which is how probe99 came back with
 * an empty drawing).
 *
 * Given (300,300) (400,250) (500,300) and then (600,350), the original
 * wrote two arcs, both of radius 76.5306 (decomp/res/renarc_two.jww):
 *
 *     centre (-94.2857,-19.5918) from 2.49809, sweep -1.85459
 *     centre ( 28.1633, 72.2449) from -2.49809, sweep  0.927295
 *
 * The first is the circle through the three points, swept the way that
 * passes through the middle one.  The second leaves the first's end
 * **along the same tangent** -- its centre is further along the same
 * radius, on the far side, so it curves the other way -- and ends where
 * the fourth click is.  That fixes everything about it: the centre has
 * to be at J + t*u with |C - P| = |t|, which gives
 * t = -|J-P|^2 / (2 u.(J-P)), and the way round is the one that sets off
 * the way the last arc arrived.
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

/* the probe's screen points, in the drawing's own units: the view puts the
   paper origin at (554,343) and runs 49 pixels to 30 millimetres */
static double px(double sx) { return (sx - 554.0) / (49.0 / 30.0); }
static double py(double sy) { return (343.0 - sy) / (49.0 / 30.0); }

static void run(const char *path, int npt, const double (*pt)[2],
                const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *want[8];
    int i, k, nw = 0, before;
    double worst = 0.0;

    printf("%s\n", what);
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
        if (ref.obj[i].cls == JW_ENKO && nw < 8)
            want[nw++] = &ref.obj[i];
    ck(nw > 0, "  the original's arcs are in the file");
    if (!nw) {
        jw_free(&ref);
        return;
    }

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_RENZOKU);
    if (jw_cmd_bar_check(2492) <= 0)
        jw_cmd_bar(d, 2492);
    ck(jw_cmd_bar_check(2492) > 0, "  連続弧 can be ticked");
    for (i = 0; i < npt; i++)
        jw_cmd_point(d, app_view(), pt[i][0], pt[i][1], 0);
    ck(d->ndrawn == before + nw, "  as many arcs as the original");
    if (d->ndrawn != before + nw) {
        printf("     ours %d, the original's %d\n", d->ndrawn - before, nw);
        jw_cmd_bar(d, 2492);
        jw_free(&ref);
        return;
    }
    for (i = 0; i < nw; i++)
        for (k = 0; k < 7; k++) {
            double e = fabs(d->obj[before + i].d[k] - want[i]->d[k]);

            if (e > worst)
                worst = e;
        }
    if (worst > 1e-6)
        for (i = 0; i < nw; i++)
            printf("     %d ours   %.4f,%.4f r %.4f from %.6f sweep %.6f\n"
                   "       theirs %.4f,%.4f r %.4f from %.6f sweep %.6f\n", i,
                   d->obj[before + i].d[0], d->obj[before + i].d[1],
                   d->obj[before + i].d[2], d->obj[before + i].d[3],
                   d->obj[before + i].d[4],
                   want[i]->d[0], want[i]->d[1], want[i]->d[2],
                   want[i]->d[3], want[i]->d[4]);
    ck(worst <= 1e-6, "  every arc where the original put it");
    jw_cmd_bar(d, 2492);        /* the tick outlives the command */
    jw_free(&ref);
}

int main(void)
{
    static double a[4][2], b2[5][2];
    static const double S1[4][2] = {
        { 300, 300 }, { 400, 250 }, { 500, 300 }, { 500, 300 }
    };
    static const double S2[5][2] = {
        { 300, 300 }, { 400, 250 }, { 500, 300 }, { 600, 350 }, { 600, 350 }
    };
    int i;

    for (i = 0; i < 4; i++) {
        a[i][0] = px(S1[i][0]);
        a[i][1] = py(S1[i][1]);
    }
    for (i = 0; i < 5; i++) {
        b2[i][0] = px(S2[i][0]);
        b2[i][1] = py(S2[i][1]);
    }
    run("decomp/res/renarc_one.jww", 4, (const double (*)[2])a, "-- 弧一つ");
    run("decomp/res/renarc_two.jww", 5, (const double (*)[2])b2, "-- 弧二つ");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
