/* 間隔取得 (32948) -- against three runs of the original.
 *
 *   tests/kankaku_test.exe
 *
 * It sits in 設定 > 長さ取得, next to 線長 and ２点間長, and what it leaves
 * behind is 複線's 間隔.  It takes a line with (L) and a point with
 * (R)Read, and the number is the **perpendicular distance from the point
 * to the line**; the status line shows it as it is taken.
 *
 * Six earlier runs looked for that number in six places and found it in
 * none (tools/probe44.sh, probe46.sh .. probe48.sh).  All six had the same
 * hole: the second click was an (R) where there was nothing to read, so
 * nothing was ever taken, and the command just sat there swallowing the
 * clicks that followed.  With a point to read, it finishes by itself and
 * hands control back to the command it was called from -- so the walk is
 *
 *     複線 → the line → 間隔取得 → the line (L) → the point (R)
 *          → one more click, which only says which side
 *
 * and the copy comes out exactly that far off.  Three runs, three
 * distances (tools/probe92.sh; the same line (300,300)-(700,500) each
 * time, the point moved):
 *
 *     kankaku_a.jww   point (300,600)   164.27
 *     kankaku_b.jww   point (700,650)    82.14
 *     kankaku_c.jww   point (200,200)    27.38
 *
 * and in b the point is on the far side of the line from the copy, which
 * says the sign is the click's and not the measurement's.
 * kankaku_none.jww is the same walk without the grab: there the second
 * click sets the offset and a third is needed, so nothing is copied.
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

/* `grab` runs 間隔取得 between picking the line and saying which side;
   without it the walk needs the extra click and copies nothing. */
static void run(const char *path, int grab, double sx, double sy,
                const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *line = 0, *pt = 0, *copy = 0;
    int i, before, k;
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
    for (i = 0; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls == JW_SEN)
            line ? (copy = &ref.obj[i]) : (line = &ref.obj[i]);
        else if (ref.obj[i].cls == JW_TEN)
            pt = &ref.obj[i];
    }
    ck(line && pt, "  the original's line and point are in the file");
    if (!line || !pt) {
        jw_free(&ref);
        return;
    }

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *o = jw_add(d, JW_SEN);

        for (k = 0; k < 4; k++)
            o->d[k] = line->d[k];
        o = jw_add(d, JW_TEN);
        o->d[0] = pt->d[0];
        o->d[1] = pt->d[1];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_FUKUSEN);
    /* the line, picked in the middle */
    jw_cmd_point(d, app_view(), (line->d[0] + line->d[2]) / 2,
                 (line->d[1] + line->d[3]) / 2, 0);
    ck(d->ndrawn == before, "  picking the line draws nothing");
    if (grab) {
        jw_cmd_get_mode(32948);
        jw_cmd_point(d, app_view(), (line->d[0] + line->d[2]) / 2,
                     (line->d[1] + line->d[3]) / 2, 0);
        jw_cmd_point(d, app_view(), pt->d[0], pt->d[1], 1);
        ck(jw_cmd_get_mode_now() == 0, "  間隔取得 finishes on its own");
        ck(d->ndrawn == before, "  and draws nothing");
    }
    /* and the side */
    jw_cmd_point(d, app_view(), sx, sy, 0);
    if (!grab) {
        ck(d->ndrawn == before, "  with no grab that click only sets 間隔");
        ck(copy == 0, "  and the original copied nothing either");
        jw_free(&ref);
        return;
    }
    ck(copy != 0, "  the original's copy is in the file");
    ck(d->ndrawn == before + 1, "  one copy, as the original made one");
    if (!copy || d->ndrawn != before + 1) {
        jw_free(&ref);
        return;
    }
    for (k = 0; k < 4; k++) {
        double e = fabs(d->obj[before].d[k] - copy->d[k]);

        if (e > worst)
            worst = e;
    }
    if (worst > 1e-6)
        printf("     ours   %.4f,%.4f -> %.4f,%.4f\n"
               "     theirs %.4f,%.4f -> %.4f,%.4f\n",
               d->obj[before].d[0], d->obj[before].d[1],
               d->obj[before].d[2], d->obj[before].d[3],
               copy->d[0], copy->d[1], copy->d[2], copy->d[3]);
    ck(worst <= 1e-6, "  and exactly where the original put it");
    jw_cmd_undo(d);
    jw_free(&ref);
}

int main(void)
{
    /* the side click, in the drawing's own units: (500,200) on the screen
       of the runs is above the line, (500,600) below it */
    run("decomp/res/kankaku_a.jww", 1, -2.449, 87.551, "-- 点 (300,600)");
    run("decomp/res/kankaku_b.jww", 1, -2.449, 87.551, "-- 点 (700,650)");
    run("decomp/res/kankaku_c.jww", 1, -2.449, -157.347, "-- 点 (200,200)");
    run("decomp/res/kankaku_none.jww", 0, -2.449, 87.551, "-- 取らない場合");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
