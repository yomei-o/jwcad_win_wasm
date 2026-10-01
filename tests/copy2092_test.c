/* 複写 (the second stage's 2092) -- against four runs of the original.
 *
 *   tests/copy2092_test.exe
 *
 * Whether a range is **copied or moved** is not the command's business:
 * it is this one tick on the bar that comes up once the range is settled.
 * 図形複写 (32804) comes up with it on and 図形移動 (32918) with it off,
 * and either can be turned into the other.
 *
 * The original says so twice over (tools/probe102.sh, probe103.sh).
 * Taking it off in 図形複写 turns the prompt into
 * 「移動先の点を指示して下さい」 and leaves the drawing with the rectangle
 * **moved**, not doubled; putting it on in 図形移動 leaves a copy.  The
 * four runs are the same clicks each time -- a rectangle, a box round it,
 * the base point, 選択確定, and the destination:
 *
 *     copy2092on.jww    図形複写 as it comes up      8 lines
 *     copy2092off.jww   図形複写 with it taken off   4 lines, moved
 *     move2092off.jww   図形移動 as it comes up      4 lines, moved
 *     move2092on.jww    図形移動 with it put on      8 lines
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

/* how many lines are in it, and which they are: a new drawing also holds
   six settings texts, which these runs never touch */
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

/* the probe's screen points in the drawing's own units: the view puts the
   paper origin at (554,343) and runs 49 pixels to 30 millimetres */
static double px(double sx) { return (sx - 554.0) / (49.0 / 30.0); }
static double py(double sy) { return (343.0 - sy) / (49.0 / 30.0); }

static void run(const char *path, int cmd, int press, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *want[16], *got[16];
    int i, k, nw = 0;
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
    nw = lines(&ref, want, 16);
    ck(nw == 4 || nw == 8, "  the original left four lines or eight");
    if (nw != 4 && nw != 8) {
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
    {   /* the rectangle the probe drew, put in by hand so that the walk
           under test starts from the same four lines every time */
        static const double R[4][4] = {
            { 300, 300, 500, 300 }, { 500, 300, 500, 400 },
            { 500, 400, 300, 400 }, { 300, 400, 300, 300 }
        };

        for (i = 0; i < 4; i++) {
            jw_obj *o = jw_add(d, JW_SEN);

            o->d[0] = px(R[i][0]);
            o->d[1] = py(R[i][1]);
            o->d[2] = px(R[i][2]);
            o->d[3] = py(R[i][3]);
        }
    }
    app_fit();
    ck(lines(d, 0, 0) == 4, "  the rectangle is four lines");

    jw_cmd_set(cmd);
    jw_cmd_point(d, app_view(), px(250.0), py(250.0), 0);
    jw_cmd_point(d, app_view(), px(550.0), py(450.0), 0);
    ck(jw_cmd_sel_count(d) == 4, "  the box takes all four");
    /* the base point first: the original was given m400,350 and then
       選択確定, and the port's 選択確定 wants the cursor to be somewhere */
    jw_cmd_track(px(400.0), py(350.0));
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 can be pressed");
    if (press)
        ck(jw_cmd_bar(d, 2092) == 1, "  複写 can be pressed");
    jw_cmd_point(d, app_view(), px(700.0), py(500.0), 0);
    ck(lines(d, got, 16) == nw, "  as many lines as the original");
    if (lines(d, 0, 0) != nw) {
        printf("     ours %d, the original's %d\n", lines(d, 0, 0), nw);
        if (press)
            jw_cmd_bar(d, 2092);        /* the tick outlives the command */
        jw_free(&ref);
        return;
    }
    for (i = 0; i < nw; i++)
        for (k = 0; k < 4; k++) {
            double e = fabs(got[i]->d[k] - want[i]->d[k]);

            if (e > worst)
                worst = e;
        }
    if (worst > 1e-6)
        for (i = 0; i < nw; i++)
            printf("     %d ours %.3f,%.3f->%.3f,%.3f"
                   "   theirs %.3f,%.3f->%.3f,%.3f\n", i,
                   got[i]->d[0], got[i]->d[1], got[i]->d[2], got[i]->d[3],
                   want[i]->d[0], want[i]->d[1], want[i]->d[2],
                   want[i]->d[3]);
    ck(worst <= 1e-6, "  every line where the original left it");
    if (press)
        jw_cmd_bar(d, 2092);
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/copy2092on.jww", JW_CMD_FUKUSHA, 0,
        "-- 図形複写 そのまま");
    run("decomp/res/copy2092off.jww", JW_CMD_FUKUSHA, 1,
        "-- 図形複写 で 複写 を外す");
    run("decomp/res/move2092off.jww", JW_CMD_IDOU, 0,
        "-- 図形移動 そのまま");
    run("decomp/res/move2092on.jww", JW_CMD_IDOU, 1,
        "-- 図形移動 で 複写 を入れる");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
