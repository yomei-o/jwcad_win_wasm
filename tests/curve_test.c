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
#include "../src/jww.h"

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

/* ---- スプラインの弦長・始・終点連続処理 (1323)・連結線指定 (1068) ----------
 *
 * 逆コンパイルの読み（FUN_006b5bc0・FUN_006b76e0・FUN_006b4690・
 * FUN_006b6860）、原典では押していない。答えは原典の絵ではなく、同じ式を
 * 別の形で書いたもの: 弦の長さ L を媒介変数にした三次エルミートの一階微分 m
 * を密な連立一次方程式で解き、エルミート基底で値を出す。端は自然
 * （2m1 + m2 = 3d/L）か、連結した要素の単位の向きに固定。 */
static jw_drawing *dz;

static void zfresh(void)
{
    app_resize(1264, 741);
    app_new();
    dz = (jw_drawing *)app_drawing();
}

static void zat(double x, double y) { jw_cmd_point(dz, app_view(), x, y, 0); }

static void zline(double a, double b, double c, double e)
{
    jw_obj *o = jw_add(dz, JW_SEN);

    o->d[0] = a;
    o->d[1] = b;
    o->d[2] = c;
    o->d[3] = e;
}

static void zarc(double cx, double cy, double r, double a0, double sw)
{
    jw_obj *o = jw_add(dz, JW_ENKO);

    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = a0;
    o->d[4] = sw;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
}

/* 点 P[0..M-1] の弦長スプラインを解き、spans [s0, s1) を n 分割した頂点を
   ox, oy に（各区間の始点は書かない）。ta/tb が非 0 ならその端を固定 */
static int ref_spline(const double *px, const double *py, int M, int n,
                      const double *ta, const double *tb, int s0, int s1,
                      double *ox, double *oy)
{
    double A[80][81], m[2][80], L[80];
    int c, i, j, k, no = 0;

    for (i = 0; i < M - 1; i++)
        L[i] = hypot(px[i + 1] - px[i], py[i + 1] - py[i]);
    for (c = 0; c < 2; c++) {
        const double *p = c ? py : px;

        memset(A, 0, sizeof A);
        if (ta) {
            A[0][0] = 1;
            A[0][M] = ta[c];
        } else {
            A[0][0] = 2;
            A[0][1] = 1;
            A[0][M] = 3 * (p[1] - p[0]) / L[0];
        }
        for (i = 1; i < M - 1; i++) {
            A[i][i - 1] = L[i];
            A[i][i] = 2 * (L[i - 1] + L[i]);
            A[i][i + 1] = L[i - 1];
            A[i][M] = 3 * (L[i - 1] * (p[i + 1] - p[i]) / L[i]
                           + L[i] * (p[i] - p[i - 1]) / L[i - 1]);
        }
        if (tb) {
            A[M - 1][M - 1] = 1;
            A[M - 1][M] = tb[c];
        } else {
            A[M - 1][M - 2] = 1;
            A[M - 1][M - 1] = 2;
            A[M - 1][M] = 3 * (p[M - 1] - p[M - 2]) / L[M - 2];
        }
        for (i = 0; i < M; i++) {           /* ガウスの消去（ピボット選択） */
            int b = i;
            for (j = i + 1; j < M; j++)
                if (fabs(A[j][i]) > fabs(A[b][i]))
                    b = j;
            for (k = 0; k <= M; k++) {
                double t = A[i][k];
                A[i][k] = A[b][k];
                A[b][k] = t;
            }
            for (j = 0; j < M; j++)
                if (j != i) {
                    double f = A[j][i] / A[i][i];
                    for (k = i; k <= M; k++)
                        A[j][k] -= f * A[i][k];
                }
        }
        for (i = 0; i < M; i++)
            m[c][i] = A[i][M] / A[i][i];
    }
    for (i = s0; i < s1; i++)
        for (k = 1; k <= n; k++) {
            double s = k == n ? 1.0 : (0.58 + (k - 1)) / (n - 0.84);
            double h00 = 2 * s * s * s - 3 * s * s + 1, h10 = s * s * s - 2 * s * s + s;
            double h01 = -2 * s * s * s + 3 * s * s, h11 = s * s * s - s * s;

            ox[no] = h00 * px[i] + h10 * L[i] * m[0][i] + h01 * px[i + 1]
                   + h11 * L[i] * m[0][i + 1];
            oy[no] = h00 * py[i] + h10 * L[i] * m[1][i] + h01 * py[i + 1]
                   + h11 * L[i] * m[1][i + 1];
            no++;
        }
    return no;
}

/* 描いた線 [from, ndrawn) が始点 (x0,y0) から ox,oy をつないだものか */
static double zworst(int from, double x0, double y0, const double *ox,
                     const double *oy, int no)
{
    double w = 0, e;
    int i;

    if (dz->ndrawn - from != no)
        return 1e9;
    for (i = 0; i < no; i++) {
        const jw_obj *o = &dz->obj[from + i];
        double sx = i ? ox[i - 1] : x0, sy = i ? oy[i - 1] : y0;

        e = fabs(o->d[0] - sx) + fabs(o->d[1] - sy)
          + fabs(o->d[2] - ox[i]) + fabs(o->d[3] - oy[i]);
        if (e > w)
            w = e;
    }
    return w;
}

static double seg_ang(const jw_obj *a, const jw_obj *b)
{
    double ux = a->d[2] - a->d[0], uy = a->d[3] - a->d[1];
    double vx = b->d[2] - b->d[0], vy = b->d[3] - b->d[1];

    return acos((ux * vx + uy * vy) / (hypot(ux, uy) * hypot(vx, vy)))
           * 180.0 / 3.14159265358979;
}

static void spline_more(void)
{
    double ox[400], oy[400];
    int before, no, i;

    printf("スプラインの弦長（不等間隔）:\n");
    {
        static const double X[] = { 0, 30, 100, 120 }, Y[] = { 0, 10, 0, 60 };

        zfresh();
        zline(-50, -50, 200, 100);      /* 画面の広さのため */
        app_fit();
        before = dz->ndrawn;
        jw_cmd_set(JW_CMD_KYOKUSEN);
        type_box(1411, "5");
        for (i = 0; i < 4; i++)
            zat(X[i], Y[i]);
        jw_cmd_bar(dz, 1800);
        no = ref_spline(X, Y, 4, 5, 0, 0, 0, 3, ox, oy);
        ck(zworst(before, 0, 0, ox, oy, no) < 1e-9,
           "  弦の長さを媒介変数にした自然スプライン（FUN_006b76e0）");
    }

    printf("始・終点連続処理 (1323):\n");
    {
        static const double X[] = { 0, 100, 100, 0, 0 }, Y[] = { 0, 0, 100, 100, 0 };
        /* P(N-2) P(N-1) P1..PN P2 P3 */
        static const double CX[] = { 100, 0, 0, 100, 100, 0, 0, 100, 100 };
        static const double CY[] = { 100, 100, 0, 0, 100, 100, 0, 0, 100 };
        int n0;

        zfresh();
        zline(-50, -50, 150, 150);
        app_fit();
        jw_cmd_set(JW_CMD_KYOKUSEN);
        ck(jw_cmd_bar_check(1323) == 1, "  既定で印あり");
        type_box(1411, "6");
        before = dz->ndrawn;
        for (i = 0; i < 5; i++)
            zat(X[i], Y[i]);
        jw_cmd_bar(dz, 1800);
        no = ref_spline(CX, CY, 9, 6, 0, 0, 2, 6, ox, oy);
        ck(no == 24 && zworst(before, 0, 0, ox, oy, no) < 1e-9,
           "  終点が始点なら前後に二点ずつ足して解き、もとの四区間だけ描く");
        ck(seg_ang(&dz->obj[before], &dz->obj[dz->ndrawn - 1]) < 20.0,
           "  始点でなめらかにつながる");

        jw_cmd_bar(dz, 1323);
        ck(jw_cmd_bar_check(1323) == 0, "  1323 を外す");
        n0 = dz->ndrawn;
        for (i = 0; i < 5; i++)
            zat(X[i], Y[i]);
        jw_cmd_bar(dz, 1800);
        no = ref_spline(X, Y, 5, 6, 0, 0, 0, 4, ox, oy);
        ck(zworst(n0, 0, 0, ox, oy, no) < 1e-9, "  外せば開いた自然スプライン");
        ck(seg_ang(&dz->obj[n0], &dz->obj[dz->ndrawn - 1]) > 45.0,
           "  始点で角が立つ");
        jw_cmd_bar(dz, 1323);
    }

    printf("連結線指定 (1068):\n");
    {
        static const double X[] = { 0, 50, 120 }, Y[] = { 0, 40, 0 };
        static const double ta[2] = { 1, 0 };

        zfresh();
        zline(-100, 0, 0, 0);
        zline(-50, -50, 200, 100);
        app_fit();
        jw_cmd_set(JW_CMD_KYOKUSEN);
        type_box(1411, "5");
        before = dz->ndrawn;
        ck(jw_cmd_bar(dz, 1068) == 1, "  押せる");
        zat(-2, 0);                     /* 線の上: 近い端 (0,0) に */
        zat(50, 40);
        zat(120, 0);
        jw_cmd_bar(dz, 1800);
        no = ref_spline(X, Y, 3, 5, ta, 0, 0, 2, ox, oy);
        ck(zworst(before, 0, 0, ox, oy, no) < 1e-9,
           "  始点を線の端に置き、線の向き (1,0) で出る");
    }
    {
        static const double X[] = { 0, 50, 100 }, Y[] = { 0, 50, 50 };
        static const double tb[2] = { 0, -1 };
        double a = 3.14159265358979 + 0.05;

        zfresh();
        zarc(200, 50, 100, 3.14159265358979, 3.14159265358979 / 2);
        zline(-50, -50, 300, 100);
        app_fit();
        jw_cmd_set(JW_CMD_KYOKUSEN);
        type_box(1411, "4");
        before = dz->ndrawn;
        zat(0, 0);
        zat(50, 50);
        /* (LL): 一つ目は普通の点、二つ目でそれを戻して円弧を拾う */
        jw_cmd_point_ll(dz, app_view(), 200 + 100 * cos(a), 50 + 100 * sin(a));
        jw_cmd_bar(dz, 1800);
        no = ref_spline(X, Y, 3, 4, 0, tb, 0, 2, ox, oy);
        ck(zworst(before, 0, 0, ox, oy, no) < 1e-9,
           "  (LL) で円弧の始点へ、反時計回りに入る向き (0,-1) で着く");
    }
    {
        int n0;

        zfresh();
        zarc(0, 0, 50, 0.0, 0.0);       /* 全円 */
        zline(-100, -100, 100, 100);
        app_fit();
        jw_cmd_set(JW_CMD_KYOKUSEN);
        type_box(1411, "4");
        jw_cmd_bar(dz, 1068);
        zat(0, 50);                     /* 全円は断る（0x1458） */
        zat(0, 50);                     /* 印は下りたので普通の点 */
        zat(60, 80);
        zat(90, 20);
        n0 = dz->ndrawn;
        jw_cmd_bar(dz, 1800);
        ck(dz->ndrawn - n0 == 8 && dz->obj[n0].d[0] == 0 && dz->obj[n0].d[1] == 50,
           "  全円は連結しない、印は下りる");
        jw_cmd_bar(dz, 1068);
        jw_cmd_bar(dz, 1692);
        jw_cmd_bar(dz, 1691);
        n0 = dz->ndrawn;
        zat(0, 49);
        zat(60, 80);
        zat(90, 20);
        jw_cmd_bar(dz, 1800);
        ck(dz->ndrawn - n0 == 8 && dz->obj[n0].d[1] == 49,
           "  曲線の種類を替えると 連結線指定 は下りる（FUN_006b4090）");
    }
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
    spline_more();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
