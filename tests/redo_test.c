/* 進む (0xe12c) -- against six runs of the original.
 *
 *   tests/redo_test.exe
 *
 * One press puts one undone step back.  The original was given three
 * lines and then, each time from scratch (tools/probe107.sh, probe108.sh):
 *
 *     戻る x0   3 lines      戻る x2 then 進む x1   2 lines
 *     戻る x1   2 lines      戻る x2 then 進む x2   3 lines
 *     戻る x2   1 line       戻る x2, a new line, 進む   2 lines
 *     戻る x3   0 lines      進む with nothing undone    3 lines
 *
 * so a new step throws the undone ones away, and 進む with nothing to put
 * back does nothing.
 *
 * **Measuring it took fixing the apparatus first.**  Six earlier runs
 * could not make the counts add up at all (RESUME, 「進む は測り方から
 * 作り直し」).  The decompilation says why: 戻る (`FUN_00504100`) asks
 * **the command in force** to undo its own step first, through vtable
 * +0x40, and only touches the drawing when that says it did not -- and
 * 進む (`FUN_00503e90`) does the same through +0x3c.  A command that is
 * part way through swallows the press.  Leaving the command and coming
 * back (円 then 線) empties its step, and after that every press lands
 * exactly once.
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

static int lines(const jw_drawing *d, const jw_obj **out, int max)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SEN) {
            if (out && n < max)
                out[n] = &d->obj[i];
            n++;
        }
    return n;
}

static double px(double sx) { return (sx - 554.0) / (49.0 / 30.0); }
static double py(double sy) { return (343.0 - sy) / (49.0 / 30.0); }

/* the three lines the probe drew, in the order it drew them */
static const double L[3][4] = {
    { 300, 300, 700, 500 }, { 300, 550, 700, 650 }, { 300, 200, 700, 250 }
};

/* `undo` presses 戻る that many times, `redo` 進む, and `fresh` draws one
   more line in between */
static void run(const char *path, int undo, int fresh, int redo,
                const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *want[8], *got[8];
    int i, k, nw;
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
    nw = lines(&ref, want, 8);

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
    app_fit();
    jw_cmd_set(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar(d, 1333);            /* 水平・垂直 off, as the probe had it */
    for (i = 0; i < 3; i++) {
        jw_cmd_point(d, app_view(), px(L[i][0]), py(L[i][1]), 0);
        jw_cmd_point(d, app_view(), px(L[i][2]), py(L[i][3]), 0);
    }
    ck(lines(d, 0, 0) == 3, "  three lines to start with");
    for (i = 0; i < undo; i++)
        app_command(JW_CMD_UNDO);
    if (fresh) {
        jw_cmd_point(d, app_view(), px(300.0), py(700.0), 0);
        jw_cmd_point(d, app_view(), px(700.0), py(720.0), 0);
    }
    for (i = 0; i < redo; i++)
        app_command(JW_CMD_REDO);
    ck(lines(d, got, 8) == nw, "  as many lines as the original");
    if (lines(d, 0, 0) != nw) {
        printf("     ours %d, the original's %d\n", lines(d, 0, 0), nw);
        jw_free(&ref);
        return;
    }
    for (i = 0; i < nw; i++)
        for (k = 0; k < 4; k++) {
            double e = fabs(got[i]->d[k] - want[i]->d[k]);

            if (e > worst)
                worst = e;
        }
    ck(worst <= 1e-6, "  and the same lines, in the same order");
    if (worst > 1e-6)
        for (i = 0; i < nw; i++)
            printf("     %d ours %.3f,%.3f->%.3f,%.3f"
                   "   theirs %.3f,%.3f->%.3f,%.3f\n", i,
                   got[i]->d[0], got[i]->d[1], got[i]->d[2], got[i]->d[3],
                   want[i]->d[0], want[i]->d[1], want[i]->d[2],
                   want[i]->d[3]);
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/redo_n0.jww", 0, 0, 0, "-- 戻らない");
    run("decomp/res/redo_n1.jww", 1, 0, 0, "-- 戻る 1 回");
    run("decomp/res/redo_n2.jww", 2, 0, 0, "-- 戻る 2 回");
    run("decomp/res/redo_n3.jww", 3, 0, 0, "-- 戻る 3 回");
    run("decomp/res/redo_u2r1.jww", 2, 0, 1, "-- 戻る 2 回、進む 1 回");
    run("decomp/res/redo_u2r2.jww", 2, 0, 2, "-- 戻る 2 回、進む 2 回");
    run("decomp/res/redo_fresh.jww", 2, 1, 1,
        "-- 戻る 2 回、新しく引いてから 進む");
    run("decomp/res/redo_u1r1.jww", 1, 0, 1, "-- 戻る 1 回、進む 1 回");
    run("decomp/res/redo_u3r1.jww", 3, 0, 1, "-- 戻る 3 回、進む 1 回");
    run("decomp/res/redo_none.jww", 0, 0, 1, "-- 戻らずに 進む");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
