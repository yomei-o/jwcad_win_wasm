/* 曲線, スプライン (0x808c) -- against the curves the original drew.
 *
 *   tests/curve_test.exe
 *
 * Points are clicked one after another and 作図実行 draws the curve through
 * them as a run of straight lines.  The original was given the same four
 * points at four different 分割数 (3, 4, 7 and 10) and left 9, 12, 21 and 30
 * segments -- 分割数 to a span (decomp/res/curve_n*.jww).
 *
 * Two things had to be asked of it, and both came out exact.
 *
 * What curve: a natural cubic spline on uniform knots.  The tangent it left
 * at the start of the first span is (y1-y0) - (2m0+m1)/6 for the natural
 * spline's second derivatives, and the tangents across a join agree to 1e-8.
 * Catmull-Rom would have put the tangent at the first interior point at zero;
 * the original's is nothing like it.
 *
 * Where it samples: not evenly.  With n divisions the parameter steps are
 * 0.58, 1, 1, ..., 1, 0.58 -- the two at the ends are 0.58 of the rest.  That
 * ratio is exact and the same at every 分割数 tried.
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

/* The curve is the last run of lines in the file: Test5's own 46 come first
   and the polyline was added after them. */

static void run(int n, const char *path, int first)
{
    unsigned char *b;
    long len;
    jw_drawing ref, *d;
    const jw_obj *seg[64];
    int i, ns = 0, before, want;
    double worst = 0;
    char num[16];

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
    want = 3 * n;
    {   /* the last `want` lines in the file are the curve */
        const jw_obj *all[4096];
        int na = 0;
        for (i = 0; i < ref.ndrawn; i++)
            if (ref.obj[i].cls == JW_SEN && na < 4096)
                all[na++] = &ref.obj[i];
        for (i = na - want; i >= 0 && i < na && ns < 64; i++)
            seg[ns++] = all[i];
    }
    printf("分割数 %d:\n", n);
    ck(ns == want, "  the original left 分割数 segments to a span");
    if (ns != want) {
        jw_free(&ref);
        return;
    }

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
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_KYOKUSEN);
    /* the box keeps what was typed into it, the way the original's does, so
       the starting value can only be looked at once */
    if (first)
        ck(jw_cmd_box(1411) && !strcmp(jw_cmd_box(1411), "7"),
           "  分割数 starts at 7, the way the original's does");
    sprintf(num, "%d", n);
    type_box(1411, num);
    /* the four points it was given: the polyline's ends and every nth joint */
    jw_cmd_point(d, app_view(), seg[0]->d[0], seg[0]->d[1], 0);
    for (i = 1; i <= 3; i++)
        jw_cmd_point(d, app_view(), seg[i * n - 1]->d[2],
                     seg[i * n - 1]->d[3], 0);
    ck(d->ndrawn == before, "  the points on their own draw nothing");
    ck(jw_cmd_bar(d, 1800) == 1, "  作図実行 can be pressed");
    ck(d->ndrawn == before + want, "  and it draws the whole polyline");
    if (d->ndrawn != before + want) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < want; i++) {
        const jw_obj *a = &d->obj[before + i], *r = seg[i];
        int k;

        for (k = 0; k < 4; k++) {
            double e = fabs(a->d[k] - r->d[k]);
            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6)
        printf("     worst disagreement %.6g\n"
               "     ours   %.6f,%.6f -> %.6f,%.6f\n"
               "     theirs %.6f,%.6f -> %.6f,%.6f\n", worst,
               d->obj[before + 1].d[0], d->obj[before + 1].d[1],
               d->obj[before + 1].d[2], d->obj[before + 1].d[3],
               seg[1]->d[0], seg[1]->d[1], seg[1]->d[2], seg[1]->d[3]);
    ck(worst <= 1e-6, "  every vertex where the original put it");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "  in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the whole curve back");
    jw_free(&ref);
}

/* The four points the original was given, taken out of the spline reference:
   that one passes through them, at every 分割数-th vertex. */
static int control(double *cx, double *cy)
{
    unsigned char *b;
    long len;
    jw_drawing ref;
    const jw_obj *all[4096];
    int i, na = 0, base;

    b = slurp("decomp/res/curve_n7.jww", &len);
    if (!b)
        return 0;
    if (!jw_parse(&ref, b, len)) {
        free(b);
        return 0;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN && na < 4096)
            all[na++] = &ref.obj[i];
    if (na < 21) {
        jw_free(&ref);
        return 0;
    }
    base = na - 21;
    cx[0] = all[base]->d[0];
    cy[0] = all[base]->d[1];
    for (i = 1; i <= 3; i++) {
        cx[i] = all[base + i * 7 - 1]->d[2];
        cy[i] = all[base + i * 7 - 1]->d[3];
    }
    jw_free(&ref);
    return 1;
}

/* ベジェ: the curve does not pass through the middle points, so the run has
   to be driven with the points themselves rather than read off the answer. */
static void run_bezier(int n, const char *path)
{
    unsigned char *b;
    long len;
    jw_drawing ref, *d;
    const jw_obj *seg[256];
    double cx[4], cy[4];
    int i, ns = 0, before, want = 3 * n - 1;
    double worst = 0;
    char num[16];

    printf("ベジェ, 分割数 %d:\n", n);
    if (!control(cx, cy)) {
        printf("BAD  cannot read the control points\n");
        fails++;
        return;
    }
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
    {
        const jw_obj *all[4096];
        int na = 0;
        for (i = 0; i < ref.ndrawn; i++)
            if (ref.obj[i].cls == JW_SEN && na < 4096)
                all[na++] = &ref.obj[i];
        for (i = na - want; i >= 0 && i < na && ns < 256; i++)
            seg[ns++] = all[i];
    }
    ck(ns == want, "  (点数-1)*分割数 - 1 segments, as the original left");
    if (ns != want) {
        jw_free(&ref);
        return;
    }

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
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_KYOKUSEN);
    ck(jw_cmd_bar(d, 1692) == 1, "  ベジェ曲線 can be pressed");
    sprintf(num, "%d", n);
    type_box(1411, num);
    for (i = 0; i < 4; i++)
        jw_cmd_point(d, app_view(), cx[i], cy[i], 0);
    ck(jw_cmd_bar(d, 1800) == 1, "  作図実行 can be pressed");
    ck(d->ndrawn == before + want, "  and it draws the whole polyline");
    if (d->ndrawn != before + want) {
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
        printf("     worst disagreement %.6g\n", worst);
    ck(worst <= 1e-6, "  every vertex where the original put it");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the whole curve back");
    jw_free(&ref);
}

/* サイン曲線 (1689) and ２次曲線 (1690) -- against six the original drew.
 *
 * These are not given a string of points but a line and then four or five
 * places, so the clicks cannot be read back out of the answer the way the
 * other curves' are.  They are written down here as the pixels that were
 * clicked, and turned into the drawing's own units by the line itself: the
 * base line was drawn with two of those same clicks, so the pair it came back
 * as gives the scale and the offset exactly.  (The view is the one Test5
 * opens in, the same as every other answer here.)
 *
 * The line comes first, then 原点, 振幅（頂点）の幅の点, １サイクル点, 始点,
 * 終点 for サイン, and 原点, 中間点, 始点, 終点 for ２次.  The status line
 * asks for them in those words.
 */
static void run_line(const char *path, int mode, const int *px,
                     const int *py, int npt, const char *what)
{
    unsigned char *b;
    long len;
    jw_drawing ref, *d;
    const jw_obj *base = 0, *seg[4096];
    int i, ns = 0, nb, before;
    double k, ox, oy, worst = 0;

    printf("%s\n", what);
    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &len);
    if (!b || !app_open(b, len)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    nb = d->ndrawn;

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
    /* what the original drew: the base line first, then the curve */
    for (i = nb; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls != JW_SEN)
            break;
        if (!base)
            base = &ref.obj[i];
        else if (ns < 4096)
            seg[ns++] = &ref.obj[i];
    }
    ck(base && ns > 0, "  the original's line and curve are in the file");
    if (!base || !ns) {
        jw_free(&ref);
        return;
    }
    /* the two clicks that drew the line give the view: paper = o + k * pixel,
       with y the other way up */
    k = (base->d[2] - base->d[0]) / (px[1] - px[0]);
    ox = base->d[0] - k * px[0];
    oy = base->d[1] + k * py[0];
    ck(fabs(base->d[3] - (oy - k * py[1])) < 1e-9,
       "  and the line pins the view down both ways");

    {
        jw_obj *o = jw_add(d, JW_SEN);

        for (i = 0; i < 4; i++)
            o->d[i] = base->d[i];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_KYOKUSEN);
    /* the box keeps what an earlier run typed into it, the way the
       original's does, and these were drawn with its own 7 */
    type_box(1411, "7");
    ck(jw_cmd_bar(d, mode) == 1, "  the mode button goes down");
    /* the line, then the points */
    jw_cmd_point(d, app_view(), (base->d[0] + base->d[2]) / 2,
                 (base->d[1] + base->d[3]) / 2, 0);
    ck(d->ndrawn == before, "  the base line on its own draws nothing");
    for (i = 0; i < npt; i++) {
        jw_cmd_point(d, app_view(), ox + k * px[i + 2], oy - k * py[i + 2], 0);
        if (i < npt - 1)
            ck(d->ndrawn == before, "  nor the points before the last");
    }
    ck(d->ndrawn == before + ns, "  as many pieces as the original drew");
    if (d->ndrawn != before + ns) {
        printf("     ours %d, the original's %d\n", d->ndrawn - before, ns);
        jw_free(&ref);
        return;
    }
    for (i = 0; i < ns; i++) {
        int c;

        for (c = 0; c < 4; c++) {
            double e = fabs(d->obj[before + i].d[c] - seg[i]->d[c]);

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
    ck(worst <= 1e-6, "  every piece where the original put it, in its order");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "  in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the whole curve back");
    jw_free(&ref);
}

int main(void)
{
    run(3, "decomp/res/curve_n3.jww", 1);
    run(4, "decomp/res/curve_n4.jww", 0);
    run(7, "decomp/res/curve_n7.jww", 0);
    run(10, "decomp/res/curve_n10.jww", 0);
    run_bezier(3, "decomp/res/bezier_n3.jww");
    run_bezier(7, "decomp/res/bezier_n7.jww");
    run_bezier(10, "decomp/res/bezier_n10.jww");
    {
        /* base line, then the clicks, as pixels */
        static const int ax[] = { 300, 900, 400, 500, 600, 400, 800 };
        static const int ay[] = { 400, 400, 400, 300, 400, 400, 400 };
        static const int bx[] = { 300, 900, 400, 500, 600, 450, 850 };
        static const int by[] = { 400, 400, 380, 300, 400, 420, 400 };
        static const int cx[] = { 300, 900, 450, 550, 700, 500, 850 };
        static const int cy[] = { 250, 550, 300, 300, 450, 350, 500 };
        static const int dx[] = { 300, 900, 400, 600, 450, 700 };
        static const int dy[] = { 400, 400, 370, 320, 400, 400 };
        static const int ex[] = { 300, 900, 400, 600, 470, 700 };
        static const int ey[] = { 400, 400, 370, 320, 400, 400 };
        static const int fx[] = { 300, 900, 450, 650, 500, 850 };
        static const int fy[] = { 250, 550, 300, 320, 350, 500 };

        run_line("decomp/res/curve_sin_a.jww", 1689, ax, ay, 5,
                 "サイン曲線, the origin on the line:");
        run_line("decomp/res/curve_sin_b.jww", 1689, bx, by, 5,
                 "サイン曲線, the origin off it and the ends between vertices:");
        run_line("decomp/res/curve_sin_c.jww", 1689, cx, cy, 5,
                 "サイン曲線 along a sloping line:");
        run_line("decomp/res/curve_q_a.jww", 1690, dx, dy, 4,
                 "２次曲線, the origin off the line:");
        run_line("decomp/res/curve_q_b.jww", 1690, ex, ey, 4,
                 "２次曲線 starting 2.13 spacings out:");
        run_line("decomp/res/curve_q_c.jww", 1690, fx, fy, 4,
                 "２次曲線 along a sloping line:");
    }
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
