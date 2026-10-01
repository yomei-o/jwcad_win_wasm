/* ハッチの 図形 (1693) -- against seven runs of the original.
 *
 *   tests/hatchfig_test.exe
 *
 * This is the last of the five hatch modes, and the one whose name misled
 * the earlier notes: it has **nothing to do with 図形読込**.  Pressing 図形
 * puts no file window up, and a hatch run with a figure read in draws
 * nothing at all (tools/probe84.sh).  What it lays down is the pattern that
 * 範囲選択 (1067) picked and 選択図形登録 (1068) then registered -- the
 * original says so itself when there is none: string 10036,
 * 「範囲選択で選択図形登録を行ってください。」.  The decompilation agrees:
 * FUN_00675b10's mode-4 branch walks that list first and gives up with that
 * message when everything in it is text or a dimension.
 *
 * The walk is
 *
 *     ハッチ → 図形 → 範囲選択 → the two corners → 選択図形登録
 *            → 角度・縦ピッチ・横ピッチ → the boundary (R) → 実行
 *
 * and 選択確定 (1120) must not be pressed on the way: it takes the
 * 選択図形登録 button away (tools/probe85.sh).
 *
 * What it then draws was read off an L of known size laid in a plain
 * rectangle, seven times over (tools/probe85.sh .. probe88.sh):
 *
 *   * the copies sit on a lattice **fixed to the drawing's origin**,
 *     spanned by 横ピッチ (1412) along the 角度 and 縦ピッチ (1411) across
 *     it.  Sliding the region did not move a single copy, and neither did
 *     moving the pattern -- only how many fitted changed
 *   * the point of the pattern that lands on a lattice point is
 *     (box left + width/4, box top - height/4).  Three Ls of different
 *     shapes agree to six places; the first had width exactly twice
 *     height, which is why it took three
 *   * a copy is laid only where the whole box round it is inside the
 *     region
 *   * nothing is turned and nothing is scaled: at 角度 30 the Ls still
 *     stood square, and the same L in Test5 (write group 1/200) came out
 *     the same size and the same 80 apart
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

static void type_box(int id, const char *v)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *v; v++)
        jw_cmd_box_key((unsigned char)*v);
    jw_cmd_box_key(13);
}

/* The hatch the original drew is every element with the hatch bit; the six
   lines just before the first of them are the rectangle and the L. */
#define MAXHATCH 2048

static void run(const char *base, const char *path, const char *ang,
                const char *pitch, const char *gap, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *made[MAXHATCH], *setup[6];
    int i, k, nmade = 0, first = -1, before, worstk = 0;
    double worst = 0.0, lx0, ly0, lx1, ly1;

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
        if (ref.obj[i].flags & 0x20) {
            if (first < 0)
                first = i;
            if (nmade < MAXHATCH)
                made[nmade++] = &ref.obj[i];
        }
    ck(first >= 6 && nmade > 0, "  the original's hatch is in the file");
    if (first < 6 || !nmade) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 6; i++)
        setup[i] = &ref.obj[first - 6 + i];

    app_resize(1264, 741);
    b = slurp(base, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open %s\n", base);
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < 6; i++) {
        jw_obj *o = jw_add(d, JW_SEN);

        for (k = 0; k < 4; k++)
            o->d[k] = setup[i]->d[k];
    }
    app_fit();
    before = d->ndrawn;

    /* the box the range took: round the L, which is the last two */
    lx0 = lx1 = setup[4]->d[0];
    ly0 = ly1 = setup[4]->d[1];
    for (i = 4; i < 6; i++)
        for (k = 0; k < 4; k += 2) {
            if (setup[i]->d[k] < lx0) lx0 = setup[i]->d[k];
            if (setup[i]->d[k] > lx1) lx1 = setup[i]->d[k];
            if (setup[i]->d[k + 1] < ly0) ly0 = setup[i]->d[k + 1];
            if (setup[i]->d[k + 1] > ly1) ly1 = setup[i]->d[k + 1];
        }

    jw_cmd_set(JW_CMD_HATCH);
    ck(jw_cmd_bar(d, 1693) == 1, "  図形 can be pressed");
    ck(jw_cmd_bar(d, 1067) == 1, "  範囲選択 can be pressed");
    jw_cmd_point(d, app_view(), lx0 - 10.0, ly0 - 10.0, 0);
    jw_cmd_point(d, app_view(), lx1 + 10.0, ly1 + 10.0, 0);
    ck(jw_cmd_sel_count(d) == 2, "  the box takes the two lines of the L");
    ck(jw_cmd_bar(d, 1068) == 1, "  選択図形登録 can be pressed");
    ck(jw_cmd_sel_count(d) == 0, "  and lets the selection go");
    type_box(1419, ang);
    type_box(1411, pitch);
    type_box(1412, gap);
    /* the boundary, with the right button on one of the rectangle's sides */
    jw_cmd_point(d, app_view(), (setup[0]->d[0] + setup[0]->d[2]) / 2,
                 (setup[0]->d[1] + setup[0]->d[3]) / 2, 1);
    ck(d->ndrawn == before, "  picking the boundary draws nothing on its own");
    ck(jw_cmd_bar(d, 1148) == 1, "  実行 runs");
    ck(d->ndrawn == before + nmade, "  as many copies as the original");
    if (d->ndrawn != before + nmade) {
        printf("     ours %d, the original's %d\n", d->ndrawn - before, nmade);
        jw_free(&ref);
        return;
    }
    for (i = 0; i < nmade; i++)
        for (k = 0; k < 4; k++) {
            double e = fabs(d->obj[before + i].d[k] - made[i]->d[k]);

            if (e > worst) {
                worst = e;
                worstk = i;
            }
        }
    if (worst > 1e-6)
        printf("     worst %.6g at %d\n"
               "     ours   %.4f,%.4f -> %.4f,%.4f\n"
               "     theirs %.4f,%.4f -> %.4f,%.4f\n", worst, worstk,
               d->obj[before + worstk].d[0], d->obj[before + worstk].d[1],
               d->obj[before + worstk].d[2], d->obj[before + worstk].d[3],
               made[worstk]->d[0], made[worstk]->d[1],
               made[worstk]->d[2], made[worstk]->d[3]);
    ck(worst <= 1e-6, "  every copy where the original put it, in its order");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the whole hatch back");
    jw_free(&ref);
}

int main(void)
{
    const char *N = "decomp/res/new.jww";

    run(N, "decomp/res/hatchfig.jww", "0", "60", "80",
        "-- 角度 0・縦 60・横 80、L は 36.7x18.4");
    run(N, "decomp/res/hatchfig_region.jww", "0", "60", "80",
        "-- 矩形だけずらす（格子は動かない）");
    run(N, "decomp/res/hatchfig_p40.jww", "0", "40", "40",
        "-- ピッチ 40/40");
    run(N, "decomp/res/hatchfig_ang.jww", "30", "60", "80",
        "-- 角度 30（図形は回らない）");
    run(N, "decomp/res/hatchfig_a.jww", "0", "60", "80",
        "-- 横 61.2・縦 18.4 の L");
    run(N, "decomp/res/hatchfig_b.jww", "0", "60", "80",
        "-- 横 24.5・縦 42.9 の L");
    run("orig/Test5.jww", "decomp/res/hatchfig_t5.jww", "0", "60", "80",
        "-- 書込グループが 1/200 の紙（大きさも間隔も変わらない）");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
