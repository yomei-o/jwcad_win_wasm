/* 設定 > 角度取得 と 長さ取得 -- against the original's own drawings.
 *
 *   tests/getang_test.exe
 *
 * These put no number anywhere the port can see: the two combo boxes on
 * the command bar stay empty and the status line goes back to what it
 * was.  So the original was asked the only way left -- draw the same
 * second line twice, once with the value taken and once without
 * (tools/probe20.sh .. probe22.sh).  With a reference line at -26.565
 * degrees and 273.804 long on a 1/100 sheet:
 *
 *   decomp/res/getplain.jww   no grab: the second line is as clicked
 *   decomp/res/getang.jww     線角度 (32932): it comes out along the
 *                             reference line, its length the click
 *                             projected on to that way
 *   decomp/res/getsuich.jww   線鉛直角度 (32935): the same, square to it
 *   decomp/res/getlen.jww     線長 (32939): the way it was clicked, the
 *                             reference line's length
 *   decomp/res/getlen2.jww    ２点間長 (32940): the same, the distance
 *                             between the two points read
 *   decomp/res/getangtwice.jww  the line after that keeps it
 *   decomp/res/getangleave.jww  leaving the command drops it
 *   decomp/res/getangbox.jww    a number typed into 傾き beats it
 *
 * Every one of those files is read here and the rule read off it, and
 * then the port is driven the same way and held to the same rule.  Going
 * through the mouse the port cannot land on the original's own points to
 * the last decimal -- a pixel is six tenths of a millimetre there -- so
 * what is compared is the rule and not the coordinates.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/view.h"

#define PI 3.14159265358979323846

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void cknear(double got, double want, double tol, const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.6f / %.6f)\n", ok ? "ok" : "BAD", what, got, want);
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

/* the lines of a drawing, in the order they were drawn */
static int lines_of(jw_drawing *d, const jw_obj *out[], int max)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++)
        if (d->obj[i].cls == JW_SEN)
            out[n++] = &d->obj[i];
    return n;
}

static double deg_of(const jw_obj *o)
{
    return atan2(o->d[3] - o->d[1], o->d[2] - o->d[0]) * 180.0 / PI;
}

static double len_of(const jw_obj *o)
{
    return sqrt((o->d[2] - o->d[0]) * (o->d[2] - o->d[0])
                + (o->d[3] - o->d[1]) * (o->d[3] - o->d[1]));
}

/* what the original made of one of those files: the reference line and
   the line drawn after the grab */
static int read_pair(const char *path, double *refdeg, double *reflen,
                     double *gotdeg, double *gotlen, int which)
{
    static jw_drawing d;
    const jw_obj *l[4];
    unsigned char *b;
    long n;
    int k;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        return 0;
    }
    memset(&d, 0, sizeof d);
    if (!jw_parse(&d, b, n)) {
        printf("BAD  cannot parse %s\n", path);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    k = lines_of(&d, l, 4);
    if (k < which + 1) {
        printf("BAD  %s has only %d lines\n", path, k);
        fails++;
        return 0;
    }
    *refdeg = deg_of(l[0]);
    *reflen = len_of(l[0]);
    *gotdeg = deg_of(l[which]);
    *gotlen = len_of(l[which]);
    return 1;
}

static void click(double x, double y, int button)
{
    const jw_view *v = app_view();

    app_press(jw_sx(v, x), jw_sy(v, y), button);
}

/* draw the reference line, take the value, draw a second line, and give
   back what came out */
static void port_run(int grab, double rx0, double ry0, double rx1, double ry1,
                     double sx, double sy, double ex, double ey,
                     const jw_obj **ref, const jw_obj **got, int extra)
{
    jw_drawing *d;
    const jw_obj *l[4];
    int n;

    app_new();
    d = (jw_drawing *)app_drawing();
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* Space: 水平・垂直 off */
    click(rx0, ry0, 0);
    click(rx1, ry1, 0);
    if (grab) {
        app_command(grab);
        if (grab == 32940 || grab == 32933) {   /* two read points */
            click(rx0, ry0, 1);
            click(rx1, ry1, 1);
        } else {                        /* one pick, on the line */
            click((rx0 + rx1) / 2.0, (ry0 + ry1) / 2.0, 0);
        }
    }
    if (extra) {                        /* leave the command and come back */
        app_command(JW_CMD_ENKO);
        app_command(JW_CMD_SEN);
        if (jw_cmd_bar_check(1333) > 0)
            app_key(32);
    }
    click(sx, sy, 0);
    click(ex, ey, 0);
    n = lines_of(d, l, 4);
    *ref = n > 0 ? l[0] : 0;
    *got = n > 1 ? l[n - 1] : 0;
}

int main(void)
{
    /* the two points the original's second line was clicked between, read
       off its own plain drawing */
    static jw_drawing plain;
    const jw_obj *pl[4];
    unsigned char *b;
    long n;
    double rx0, ry0, rx1, ry1, sx, sy, ex, ey;
    double refdeg, reflen, gotdeg, gotlen;
    const jw_obj *ref, *got;

    app_resize(1264, 741);
    b = slurp("decomp/res/getplain.jww", &n);
    if (!b || !jw_parse(&plain, b, n)) {
        printf("BAD  cannot read decomp/res/getplain.jww\n");
        return 1;
    }
    free(b);
    if (lines_of(&plain, pl, 4) < 2) {
        printf("BAD  getplain.jww should hold two lines\n");
        return 1;
    }
    rx0 = pl[0]->d[0];  ry0 = pl[0]->d[1];
    rx1 = pl[0]->d[2];  ry1 = pl[0]->d[3];
    sx  = pl[1]->d[0];  sy  = pl[1]->d[1];
    ex  = pl[1]->d[2];  ey  = pl[1]->d[3];
    printf("     基準線 %.3f度 %.3f、二本目は %.3f,%.3f から %.3f,%.3f へ\n",
           deg_of(pl[0]), len_of(pl[0]), sx, sy, ex, ey);

    /* --- what the original did, read off its own files --------------- */
    if (read_pair("decomp/res/getang.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 1)) {
        cknear(gotdeg, refdeg, 1e-6, "原典: 線角度 で二本目は基準線と同じ角");
    }
    if (read_pair("decomp/res/getsuich.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 1)) {
        double want = refdeg + 90.0;
        while (want > 180.0)
            want -= 360.0;
        cknear(gotdeg, want, 1e-6, "原典: 線鉛直角度 で直角に");
    }
    if (read_pair("decomp/res/getlen.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 1))
        cknear(gotlen, reflen, 1e-6, "原典: 線長 で二本目は基準線と同じ長さ");
    if (read_pair("decomp/res/getlen2.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 1))
        cknear(gotlen, reflen, 1e-6, "原典: ２点間長 も同じ長さ");
    if (read_pair("decomp/res/getxjiku.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 1))
        cknear(gotdeg, refdeg, 1e-6,
               "原典: X軸角度 は読んだ二点の間の角");
    if (read_pair("decomp/res/getangtwice.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 2))
        cknear(gotdeg, refdeg, 1e-6, "原典: 三本目まで角が残る");
    if (read_pair("decomp/res/getangleave.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 1)) {
        double asclicked = atan2(ey - sy, ex - sx) * 180.0 / PI;
        cknear(gotdeg, asclicked, 1e-6,
               "原典: コマンドを出ると角は消える");
    }
    if (read_pair("decomp/res/getangbox.jww", &refdeg, &reflen,
                  &gotdeg, &gotlen, 1))
        cknear(gotdeg, 60.0, 1e-6, "原典: 傾き に打った 60 が勝つ");

    /* --- and the port, driven the same way --------------------------- */
    port_run(32932, rx0, ry0, rx1, ry1, sx, sy, ex, ey, &ref, &got, 0);
    ck(ref && got && ref != got, "移植: 線角度 のあとも二本引ける");
    if (ref && got && ref != got) {
        double ux = cos(deg_of(ref) * PI / 180.0);
        double uy = sin(deg_of(ref) * PI / 180.0);
        double run = (got->d[2] - got->d[0]) * ux
                   + (got->d[3] - got->d[1]) * uy;
        cknear(deg_of(got), deg_of(ref), 1e-6, "  二本目は基準線と同じ角");
        cknear(len_of(got), fabs(run), 1e-6,
               "  長さはクリックをその向きに落とした分");
    }

    port_run(32935, rx0, ry0, rx1, ry1, sx, sy, ex, ey, &ref, &got, 0);
    if (ref && got && ref != got) {
        double want = deg_of(ref) + 90.0;
        while (want > 180.0)
            want -= 360.0;
        while (want <= -180.0)
            want += 360.0;
        cknear(deg_of(got), want, 1e-6, "移植: 線鉛直角度 で直角に");
    }

    port_run(32939, rx0, ry0, rx1, ry1, sx, sy, ex, ey, &ref, &got, 0);
    if (ref && got && ref != got) {
        cknear(len_of(got), len_of(ref), 1e-6,
               "移植: 線長 で二本目は基準線と同じ長さ");
        cknear(deg_of(got), atan2(ey - sy, ex - sx) * 180.0 / PI, 0.4,
               "  向きはクリックどおり");
    }

    port_run(32940, rx0, ry0, rx1, ry1, sx, sy, ex, ey, &ref, &got, 0);
    if (ref && got && ref != got)
        cknear(len_of(got), len_of(ref), 1e-6,
               "移植: ２点間長 も基準線と同じ長さ");

    port_run(32933, rx0, ry0, rx1, ry1, sx, sy, ex, ey, &ref, &got, 0);
    if (ref && got && ref != got)
        cknear(deg_of(got), deg_of(ref), 1e-6,
               "移植: X軸角度 も読んだ二点の間の角");

    port_run(32932, rx0, ry0, rx1, ry1, sx, sy, ex, ey, &ref, &got, 1);
    if (ref && got && ref != got)
        cknear(deg_of(got), atan2(ey - sy, ex - sx) * 180.0 / PI, 0.4,
               "移植: コマンドを出ると角は消える");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
