/* 接円 (0x8068) -- against the four the original drew.
 *
 *   tests/sekien_test.exe
 *
 * A radius and two lines leave four circles of that radius touching both, one
 * in each of the angles they make.  The original says so itself: after the
 * second line its status line reads 「マウスを移動し、必要な接円位置で左クリック
 * してください。 【 4 − 1 】」 and the third click takes the one nearest it.
 * Driven four times over the same crossed pair, placing that click left,
 * right, above and below, it left four circles of radius 10 -- 2000 in a
 * 1/200 group -- whose centres sit on the two angle bisectors
 * (decomp/res/sekien_*.jww).
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

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
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

/* the distance from a point to an infinite line */
static double off(const jw_obj *l, double x, double y)
{
    double ux = l->d[2] - l->d[0], uy = l->d[3] - l->d[1];
    double L = sqrt(ux * ux + uy * uy);

    if (L < 1e-12)
        return 0;
    return fabs((-uy * (x - l->d[0]) + ux * (y - l->d[1])) / L);
}

static void run(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *l[2], *circle = 0;
    int i, nl = 0, before;

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
    /* the last two lines are the pair that was drawn, the arc is the answer */
    for (i = 0; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls == JW_SEN) {
            l[0] = l[1];
            l[1] = &ref.obj[i];
            nl++;
        }
        if (ref.obj[i].cls == JW_ENKO)
            circle = &ref.obj[i];
    }
    if (nl < 2 || !circle) {
        printf("BAD  %s has no pair of lines and a circle\n", path);
        fails++;
        jw_free(&ref);
        return;
    }

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < 2; i++) {
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = l[i]->d[0];
        o->d[1] = l[i]->d[1];
        o->d[2] = l[i]->d[2];
        o->d[3] = l[i]->d[3];
    }
    app_fit();
    before = d->ndrawn;

    printf("%s\n", what);
    jw_cmd_set(JW_CMD_SEKIEN);
    /* the box keeps what was typed into it across commands, the way the
       original's does, so empty it again for each run */
    type_box(1411, "");
    jw_cmd_set(JW_CMD_SEKIEN);
    ck(jw_cmd_box(1411) && !*jw_cmd_box(1411),
       "  接円's 半径 is empty to start with, as the original's is");
    jw_cmd_point(d, app_view(), (l[0]->d[0] + l[0]->d[2]) / 2,
                 (l[0]->d[1] + l[0]->d[3]) / 2, 0);
    jw_cmd_point(d, app_view(), (l[1]->d[0] + l[1]->d[2]) / 2,
                 (l[1]->d[1] + l[1]->d[3]) / 2, 0);
    jw_cmd_point(d, app_view(), circle->d[0], circle->d[1], 0);
    ck(d->ndrawn == before, "  and draws nothing while it is empty");

    /* with the box empty the third click is a third element, not a place to
       put the circle, so that run is still waiting for one -- start over */
    jw_cmd_set(JW_CMD_SEKIEN);
    type_box(1411, "2000");
    jw_cmd_point(d, app_view(), (l[0]->d[0] + l[0]->d[2]) / 2,
                 (l[0]->d[1] + l[0]->d[3]) / 2, 0);
    jw_cmd_point(d, app_view(), (l[1]->d[0] + l[1]->d[2]) / 2,
                 (l[1]->d[1] + l[1]->d[3]) / 2, 0);
    ck(d->ndrawn == before, "  two lines on their own draw nothing");
    jw_cmd_point(d, app_view(), circle->d[0], circle->d[1], 0);
    ck(d->ndrawn == before + 1, "  the third click draws one circle");
    if (d->ndrawn != before + 1) {
        jw_free(&ref);
        return;
    }
    {
        const jw_obj *o = &d->obj[before];
        int same = near(o->d[0], circle->d[0]) && near(o->d[1], circle->d[1])
                && near(o->d[2], circle->d[2]);

        if (!same)
            printf("     ours          %.6f,%.6f r=%.6f\n"
                   "     the original's %.6f,%.6f r=%.6f\n",
                   o->d[0], o->d[1], o->d[2],
                   circle->d[0], circle->d[1], circle->d[2]);
        ck(same, "  the centre and the radius the original chose");
        ck(near(o->d[3], circle->d[3]) && near(o->d[4], circle->d[4])
           && near(o->d[5], circle->d[5]) && near(o->d[6], circle->d[6])
           && o->n == circle->n,
           "  and the rest of the record, the whole way round");
        ck(o->color == 2 && o->ltype == 1, "  in the pen new elements get");
        ck(fabs(off(l[0], o->d[0], o->d[1]) - o->d[2]) < 1e-6
           && fabs(off(l[1], o->d[0], o->d[1]) - o->d[2]) < 1e-6,
           "  touching both lines exactly");
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes it back");
    jw_free(&ref);
}

/* The same command over elements other than two lines.
 *
 * Everything the original drew past Test5's own is read back: the last circle
 * is its answer and what comes before are the elements it was given, in the
 * order they were picked.  Each is pointed at on itself -- a line at its
 * middle, a circle at its rim -- and, when there is a 半径, the circle is
 * asked for where the original's came out, which is the place nearest that
 * one of the several the radius allows.
 *
 * `radius` is what goes in the 半径 box; an empty one means the third element
 * settles it instead, and then there is no placing click.
 */
static void run_el(const char *path, const char *radius, int want, int mult,
                   const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *el[16], *circle;
    int i, nb, nel = 0, before;

    printf("%s\n", what);
    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    nb = d->ndrawn;

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
    /* the original leaves six CDataMoji of its own settings at the end of
       every file it writes, so stop at the first thing that is neither a
       line nor a circle */
    for (i = nb; i < ref.ndrawn && nel < 16; i++) {
        if (ref.obj[i].cls != JW_SEN && ref.obj[i].cls != JW_ENKO)
            break;
        el[nel++] = &ref.obj[i];
    }
    if (nel != want + mult) {
        printf("BAD  %s has %d elements past Test5's own, not %d\n",
               path, nel, want + mult);
        fails++;
        jw_free(&ref);
        return;
    }
    nel -= mult;
    circle = el[nel];           /* and mult - 1 more inside it */
    ck(circle->cls == JW_ENKO, "  the original's answer is a circle");

    for (i = 0; i < nel; i++) {
        jw_obj *o = jw_add(d, el[i]->cls);
        int k;

        for (k = 0; k < 7; k++)
            o->d[k] = el[i]->d[k];
        o->n = el[i]->n;
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_SEKIEN);
    type_box(1411, radius);
    if (mult > 1) {
        char t[4];

        t[0] = (char)('0' + mult);
        t[1] = 0;
        type_box(1417, t);
    } else {
        type_box(1417, "");
    }
    jw_cmd_set(JW_CMD_SEKIEN);
    for (i = 0; i < nel; i++) {
        double px, py;

        if (el[i]->cls == JW_SEN) {
            px = (el[i]->d[0] + el[i]->d[2]) / 2;
            py = (el[i]->d[1] + el[i]->d[3]) / 2;
        } else {
            px = el[i]->d[0] + el[i]->d[2];
            py = el[i]->d[1];
        }
        jw_cmd_point(d, app_view(), px, py, 0);
        if (i < nel - 1 || *radius)
            ck(d->ndrawn == before, "  nothing yet");
    }
    if (*radius) {
        ck(d->ndrawn == before, "  the elements alone draw nothing");
        jw_cmd_point(d, app_view(), circle->d[0], circle->d[1], 0);
    }
    ck(d->ndrawn == before + mult, mult > 1
       ? "  that many circles come out" : "  one circle comes out");
    if (d->ndrawn != before + mult) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < mult; i++) {
        const jw_obj *o = &d->obj[before + i];
        int same = near(o->d[0], circle[i].d[0])
                && near(o->d[1], circle[i].d[1])
                && near(o->d[2], circle[i].d[2]);

        if (!same)
            printf("     ours          %.6f,%.6f r=%.6f\n"
                   "     the original's %.6f,%.6f r=%.6f\n",
                   o->d[0], o->d[1], o->d[2],
                   circle[i].d[0], circle[i].d[1], circle[i].d[2]);
        ck(same, "  where the original put it, to the last digit");
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the lot back");
    jw_free(&ref);
}

/* Three elements with circles among them and an empty 半径.
 *
 * The original walks to the circle from the three pick points (FUN_00709940:
 * put each touch point on its element, take the circle through the three,
 * move each to the middle of the chord it cuts, until nothing moves).  None
 * of these were driven in the original -- they follow the decompilation's
 * reading -- so what is checked is that the circle touches all three the way
 * the picks lead to, not digits read back from it.
 *
 * Each element is given as a line (x1,y1,x2,y2) or a circle (cx,cy,r,-1) and
 * picked at (px,py); `side[i]` says how the answer must touch element i: for
 * a circle +1 outside it (centres R + r apart), -1 around it (R - r); a line
 * just has to be R away.
 */
typedef struct {
    double v[4], px, py;
    int side;
} el3;

static double ans_r;            /* the radius the last run3 came out with */

static void run3(const el3 *el, const char *what)
{
    jw_drawing *d;
    int i, before;

    printf("%s\n", what);
    ans_r = 0;
    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < 3; i++) {
        jw_obj *o = jw_add(d, el[i].v[3] < 0 ? JW_ENKO : JW_SEN);

        if (el[i].v[3] < 0) {
            o->d[0] = el[i].v[0];
            o->d[1] = el[i].v[1];
            o->d[2] = el[i].v[2];
            o->d[3] = 0.0;
            o->d[4] = 6.283185307179586;
            o->d[5] = 0.0;
            o->d[6] = 1.0;
            o->n = 1;
        } else {
            o->d[0] = el[i].v[0];
            o->d[1] = el[i].v[1];
            o->d[2] = el[i].v[2];
            o->d[3] = el[i].v[3];
        }
    }
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_SEKIEN);
    type_box(1411, "");
    type_box(1417, "");
    jw_cmd_set(JW_CMD_SEKIEN);
    for (i = 0; i < 3; i++)
        jw_cmd_point(d, app_view(), el[i].px, el[i].py, 0);
    ck(d->ndrawn == before + 1, "  the third pick draws one circle");
    if (d->ndrawn != before + 1)
        return;
    {
        const jw_obj *o = &d->obj[before];
        double R = o->d[2];
        int good = R > 0;

        for (i = 0; i < 3; i++) {
            const jw_obj *e = &d->obj[before - 3 + i];

            if (e->cls == JW_SEN)
                good = good && fabs(off(e, o->d[0], o->d[1]) - R) < 1e-6;
            else {
                double dx = o->d[0] - e->d[0], dy = o->d[1] - e->d[1];
                double L = sqrt(dx * dx + dy * dy);

                good = good && fabs(L - fabs(R + el[i].side * e->d[2])) < 1e-6;
            }
        }
        if (!good)
            printf("     ours %.6f,%.6f r=%.6f\n", o->d[0], o->d[1], R);
        ck(good, "  touching all three, the way the picks lead");
        ans_r = R;
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes it back");
}

static void circles3(void)
{
    /* the two axes and a circle r 30 at (100,100), all picked on the sides
       facing the corner: the small circle in it that the circle stands
       outside, R = (100 sqrt2 - 30) / (sqrt2 + 1) */
    static const el3 llc[3] = {
        { { 0, 0, 300, 0 }, 40, 0, 0 },
        { { 0, 0, 0, 300 }, 0, 40, 0 },
        { { 100, 100, 30, -1 }, 100 - 21.2132, 100 - 21.2132, 1 },
    };
    /* three circles r 10, picked on the sides facing each other: the one in
       the gap between them, outside all three */
    static const el3 ccc_in[3] = {
        { { 0, 0, 10, -1 }, 8, 6, 1 },
        { { 100, 0, 10, -1 }, 92, 6, 1 },
        { { 50, 80, 10, -1 }, 50, 70, 1 },
    };
    /* the same three picked on their far sides: the one round all three */
    static const el3 ccc_out[3] = {
        { { 0, 0, 10, -1 }, -8, -6, -1 },
        { { 100, 0, 10, -1 }, 108, -6, -1 },
        { { 50, 80, 10, -1 }, 50, 90, -1 },
    };
    /* a line and two circles r 20 standing on it, picked between them */
    static const el3 lcc[3] = {
        { { -100, 0, 200, 0 }, 50, 0, 0 },
        { { 0, 20, 20, -1 }, 20, 20, 1 },
        { { 100, 20, 20, -1 }, 80, 20, 1 },
    };
    jw_drawing *d;
    int before;

    run3(llc, "two lines and a circle, an empty 半径, picked toward the corner:");
    ck(fabs(ans_r - (100 * sqrt(2.0) - 30) / (sqrt(2.0) + 1)) < 1e-6,
       "  the small one in the corner");
    run3(ccc_in, "three circles, picked on the sides facing each other:");
    ck(ans_r > 0 && ans_r < 50, "  the small one in the gap");
    run3(ccc_out, "the same three, picked on their far sides:");
    ck(ans_r > 50, "  the big one round them");
    run3(lcc, "a line and two circles standing on it, picked between them:");
    /* centre (50, R) and 50^2 + (R - 20)^2 = (R + 20)^2: R = 2500 / 80 */
    ck(fabs(ans_r - 2500.0 / 80) < 1e-6, "  the one sitting on the line between");

    /* an ellipse is turned away when it is picked, 「楕円は計算できません。」 */
    printf("an ellipse among them:\n");
    app_new();
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *o = jw_add(d, JW_SEN);

        o->d[0] = 0; o->d[1] = 0; o->d[2] = 300; o->d[3] = 0;
        o = jw_add(d, JW_SEN);
        o->d[0] = 0; o->d[1] = 0; o->d[2] = 0; o->d[3] = 300;
        o = jw_add(d, JW_ENKO);
        o->d[0] = 100; o->d[1] = 100; o->d[2] = 30; o->d[3] = 0;
        o->d[4] = 6.283185307179586; o->d[5] = 0; o->d[6] = 0.5; o->n = 1;
    }
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_SEKIEN);
    type_box(1411, "");
    jw_cmd_set(JW_CMD_SEKIEN);
    jw_cmd_point(d, app_view(), 40, 0, 0);
    jw_cmd_point(d, app_view(), 0, 40, 0);
    jw_cmd_point(d, app_view(), 70, 100, 0);
    ck(d->ndrawn == before, "  nothing is drawn");
    d->obj[before - 1].d[6] = 1.0;      /* made round, the same picks do */
    jw_cmd_set(JW_CMD_SEKIEN);
    jw_cmd_point(d, app_view(), 40, 0, 0);
    jw_cmd_point(d, app_view(), 0, 40, 0);
    jw_cmd_point(d, app_view(), 70, 100, 0);
    ck(d->ndrawn == before + 1, "  where the same picks over a circle draw one");
}

/* (R) reads a point in place of an element, 「読取点をﾏｳｽ(R)で指示」.
 *
 * The original keeps the element null and the read point (FUN_007078e0 ->
 * FUN_00707a50); with an empty 半径 the walk leaves that point where it is,
 * so the circle passes through it (FUN_00709940), and with a radius a point
 * is a circle of r 0 (FUN_00707d60's cases 2, 3 and 6).  Not driven in the
 * original: this checks the reading, not digits read back.  The points are
 * read off the ends of short lines kept out of the way.
 */
static jw_drawing *rp_setup(const double (*ln)[4], int n)
{
    jw_drawing *d;
    int i;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < n; i++) {
        jw_obj *o = jw_add(d, JW_SEN);

        o->d[0] = ln[i][0];
        o->d[1] = ln[i][1];
        o->d[2] = ln[i][2];
        o->d[3] = ln[i][3];
    }
    app_fit();
    return d;
}

static void rpoints(void)
{
    jw_drawing *d;
    int before;

    printf("(R) three points read, an empty 半径: the circle through them:\n");
    {
        static const double ln[3][4] = {
            { 0, 0, -10, -10 }, { 100, 0, 110, -10 }, { 0, 100, -10, 110 },
        };
        d = rp_setup(ln, 3);
        before = d->ndrawn;
        jw_cmd_set(JW_CMD_SEKIEN);
        type_box(1411, "");
        type_box(1417, "");
        jw_cmd_set(JW_CMD_SEKIEN);
        jw_cmd_point(d, app_view(), 0, 0, 1);
        jw_cmd_point(d, app_view(), 100, 0, 1);
        ck(d->ndrawn == before, "  two points draw nothing yet");
        jw_cmd_point(d, app_view(), 0, 100, 1);
        ck(d->ndrawn == before + 1, "  the third draws one circle");
        if (d->ndrawn == before + 1) {
            const jw_obj *o = &d->obj[before];

            ck(near(o->d[0], 50) && near(o->d[1], 50)
               && near(o->d[2], 50 * sqrt(2.0)), "  centre (50,50), r 50√2");
        }
    }

    printf("two lines and a point read, an empty 半径:\n");
    {
        /* the axes, and a point at (60,30) on the end of a short line: the
           circles touching both axes through it are r 30 and r 150 */
        static const double ln[3][4] = {
            { -200, 0, 300, 0 }, { 0, -200, 0, 300 }, { 60, 30, 70, 45 },
        };
        d = rp_setup(ln, 3);
        before = d->ndrawn;
        jw_cmd_set(JW_CMD_SEKIEN);
        jw_cmd_point(d, app_view(), 40, 0, 0);
        jw_cmd_point(d, app_view(), 0, 40, 0);
        jw_cmd_point(d, app_view(), 60, 30, 1);
        ck(d->ndrawn == before + 1, "  one circle");
        if (d->ndrawn == before + 1) {
            const jw_obj *o = &d->obj[before];
            double R = o->d[2];

            printf("     r=%.6f at %.6f,%.6f\n", R, o->d[0], o->d[1]);
            ck(near(fabs(o->d[0]), R) && near(fabs(o->d[1]), R)
               && near(hypot(o->d[0] - 60, o->d[1] - 30), R)
               && (near(R, 30) || near(R, 150)),
               "  touching both axes and through the point");
        }
        jw_cmd_undo(d);
        ck(d->ndrawn == before, "  元に戻る takes it back");

        /* the point read off the second picked line itself: the original
           makes it touch there, by a frame not read through -- nothing */
        jw_cmd_set(JW_CMD_SEKIEN);
        jw_cmd_point(d, app_view(), 40, 0, 0);
        jw_cmd_point(d, app_view(), 0, 300, 0);
        jw_cmd_point(d, app_view(), 0, 300, 1);
        ck(d->ndrawn == before, "  a point on a picked line: not drawn");
    }

    printf("a line and a point read, with a 半径:\n");
    {
        static const double ln[2][4] = {
            { -200, 0, 200, 0 }, { 0, 50, -10, 60 },
        };
        char t[32];
        int g, wg = 0;

        d = rp_setup(ln, 2);
        before = d->ndrawn;
        /* r 40 on the paper: the box is in real size, the write group's */
        for (g = 0; g < 16; g++)
            if (d->group[g].state == 3)
                wg = g;
        snprintf(t, sizeof t, "%.6f",
                 40 * (d->group[wg].scale > 0 ? d->group[wg].scale : 1));
        jw_cmd_set(JW_CMD_SEKIEN);
        type_box(1411, t);
        jw_cmd_set(JW_CMD_SEKIEN);
        jw_cmd_point(d, app_view(), 100, 0, 0);
        jw_cmd_point(d, app_view(), 0, 50, 1);
        ck(d->ndrawn == before, "  nothing until it is placed");
        jw_cmd_point(d, app_view(), 40, 20, 0);
        ck(d->ndrawn == before + 1, "  the placing click draws one");
        if (d->ndrawn == before + 1) {
            const jw_obj *o = &d->obj[before];
            double R = o->d[2];

            ck(R > 25 && near(o->d[1], R) && o->d[0] > 0
               && near(hypot(o->d[0], o->d[1] - 50), R),
               "  on the line, through the point, on the side clicked");
        }
        type_box(1411, "");
    }
}

int main(void)
{
    run("decomp/res/sekien_l.jww", "the circle placed to the left:");
    run("decomp/res/sekien_r.jww", "to the right:");
    run("decomp/res/sekien_t.jww", "above:");
    run("decomp/res/sekien_b.jww", "below:");
    run_el("decomp/res/seklc_a.jww", "20000", 2, 1,
           "a line and a circle, r 100, the circle placed left:");
    run_el("decomp/res/seklc_b.jww", "20000", 2, 1, "and right:");
    run_el("decomp/res/sekcc_n.jww", "40000", 2, 1,
           "two circles, r 200, placed above:");
    run_el("decomp/res/sekcc_s.jww", "40000", 2, 1, "below:");
    run_el("decomp/res/sekcc_e.jww", "40000", 2, 1, "to the right:");
    run_el("decomp/res/sekcc_w.jww", "40000", 2, 1, "to the left:");
    run_el("decomp/res/sek3.jww", "", 3, 1,
           "three lines and an empty 半径 -- the circle inside them:");
    run_el("decomp/res/sekmul_a.jww", "2000", 2, 3,
           "two lines and 多重円 3 -- r, 2r/3 and r/3:");
    run_el("decomp/res/sekmul_b.jww", "", 3, 3,
           "three lines and 多重円 3, the same way:");
    circles3();
    rpoints();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
