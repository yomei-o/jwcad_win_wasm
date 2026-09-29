/* What the command bars' numbers and boxes actually draw.
 *
 *   tests/bardraw_test.exe
 *
 * Every command puts up a bar of its own, and Jw_cad is driven through it:
 * a circle of a size is typed into 半径, not dragged out.  Each case here
 * types what the original was given, clicks where it was clicked, and scores
 * the elements that come out against the ones the original wrote.
 *
 * The answers are the original's own (tools/refanswers.sh).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/sunpo.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
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

static jw_drawing *fresh(void)
{
    unsigned char *b;
    long n;

    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        exit(1);
    }
    free(b);
    return (jw_drawing *)app_drawing();
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

/* the answer's elements of one class, in the order it wrote them */
static int of_class(const jw_drawing *d, int cls, const jw_obj **out, int max)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++)
        if (d->obj[i].cls == cls)
            out[n++] = &d->obj[i];
    return n;
}

/* the last `want` elements of a class */
static int tail_of(const jw_drawing *d, int cls, const jw_obj **out, int want)
{
    const jw_obj *all[4096];
    int n = of_class(d, cls, all, 4096), k;

    if (n < want)
        return 0;
    for (k = 0; k < want; k++)
        out[k] = all[n - want + k];
    return 1;
}

/* 円 の 半径: one click, one circle of that radius */
static void circle_radius(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[2];
    int before, i;

    b = slurp("decomp/res/enradius.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/enradius.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  enradius.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_ENKO, r, 2)) {
        printf("BAD  enradius.jww has no two circles in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_ENKO);
    ck(jw_cmd_box(1411) != 0, "円 has a 半径 box the port keeps");
    type_box(1411, "100");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    ck(d->ndrawn == before + 1, "one click draws one circle, without a second");
    jw_cmd_point(d, app_view(), r[1]->d[0], r[1]->d[1], 0);
    ck(d->ndrawn == before + 2, "and the next click draws another");
    if (d->ndrawn != before + 2) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 2; i++) {
        const jw_obj *a = &d->obj[before + i];
        int ok = a->cls == JW_ENKO && near(a->d[0], r[i]->d[0])
                 && near(a->d[1], r[i]->d[1]) && near(a->d[2], r[i]->d[2])
                 && near(a->d[3], r[i]->d[3]) && near(a->d[4], r[i]->d[4])
                 && a->n == r[i]->n;
        if (!ok)
            printf("     ours  c=(%.6f,%.6f) r=%.6f a=%.6f sweep=%.6f n=%d\n"
                   "     the original's c=(%.6f,%.6f) r=%.6f a=%.6f sweep=%.6f n=%d\n",
                   a->d[0], a->d[1], a->d[2], a->d[3], a->d[4], a->n,
                   r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3], r[i]->d[4],
                   r[i]->n);
        ck(ok, i == 0 ? "the first is the original's, to 1e-9"
                      : "and so is the second");
    }
    ck(near(d->obj[before].d[2], 0.5),
       "100 on a 1/200 group is a radius of 0.5 mm");
    jw_free(&ref);
}

/* 円弧 (1318): three clicks -- centre, then radius and start, then the end.
 *
 * The sweep is scored by where the arc *ends*, not by the number written:
 * the original keeps a direction of its own that survives between runs, so
 * the same three clicks came out as +1.107149 one time and -5.176037 the
 * next -- the short way round and the long way round to the same end.  The
 * centre, the radius, the start and the trailing 0 are not ambiguous. */
static void circle_arc(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before;
    double ex, ey, ax, ay;

    b = slurp("decomp/res/enarc.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/enarc.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  enarc.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_ENKO, r, 1)) {
        printf("BAD  enarc.jww has no arc in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_ENKO);
    ck(jw_cmd_bar_check(1318) == 0, "円 comes up with 円弧 off");
    jw_cmd_bar(d, 1318);
    ck(jw_cmd_bar_check(1318) == 1, "and pressing it turns it on");
    before = d->ndrawn;
    /* the same three points the original was given: its centre, a point at
       its radius along its start angle, and one at the angle it ended at */
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    ck(d->ndrawn == before, "the first click draws nothing");
    jw_cmd_point(d, app_view(),
                 r[0]->d[0] + r[0]->d[2] * cos(r[0]->d[3]),
                 r[0]->d[1] + r[0]->d[2] * sin(r[0]->d[3]), 0);
    ck(d->ndrawn == before, "nor does the second");
    ex = r[0]->d[0] + r[0]->d[2] * cos(r[0]->d[3] + r[0]->d[4]);
    ey = r[0]->d[1] + r[0]->d[2] * sin(r[0]->d[3] + r[0]->d[4]);
    jw_cmd_point(d, app_view(), ex, ey, 0);
    ck(d->ndrawn == before + 1, "the third draws the arc");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        ck(a->cls == JW_ENKO && near(a->d[0], r[0]->d[0])
           && near(a->d[1], r[0]->d[1]) && near(a->d[2], r[0]->d[2]),
           "at the original's centre and radius");
        ck(near(a->d[3], r[0]->d[3]), "starting where the original's starts");
        ax = a->d[0] + a->d[2] * cos(a->d[3] + a->d[4]);
        ay = a->d[1] + a->d[2] * sin(a->d[3] + a->d[4]);
        if (!(fabs(ax - ex) < 1e-9 && fabs(ay - ey) < 1e-9))
            printf("     ours ends at %.6f,%.6f, the original's at %.6f,%.6f\n",
                   ax, ay, ex, ey);
        ck(fabs(ax - ex) < 1e-9 && fabs(ay - ey) < 1e-9,
           "and ending where the original's ends");
        ck(a->n == 0, "with the trailing 0 an arc carries, not a circle's 1");
    }
    jw_free(&ref);
}

/* 矩形 の 傾き (1411): the two clicks are opposite corners still, but of a
 * rectangle whose sides run at that angle. */
static void rect_tilt(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[4];
    int before, i, ok = 1;

    b = slurp("decomp/res/kutilt.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/kutilt.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  kutilt.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SEN, r, 4)) {
        printf("BAD  kutilt.jww has no rectangle in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1411, "30");
    type_box(1413, "");
    before = d->ndrawn;
    /* the corner the original started at, and the opposite corner it was
       given -- which is the far end of its second side */
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[1]->d[2], r[1]->d[3], 0);
    ck(d->ndrawn == before + 4, "矩形の傾き: two clicks draw four lines");
    if (d->ndrawn != before + 4) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 4; i++) {
        const jw_obj *a = &d->obj[before + i];
        if (!(near(a->d[0], r[i]->d[0]) && near(a->d[1], r[i]->d[1])
              && near(a->d[2], r[i]->d[2]) && near(a->d[3], r[i]->d[3]))) {
            ok = 0;
            printf("     ours %.6f,%.6f -> %.6f,%.6f\n"
                   "     the original's %.6f,%.6f -> %.6f,%.6f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
        }
    }
    ck(ok, "  all four exactly where the original put them");
    jw_free(&ref);
}

/* 線 の １５度毎 (1336): the angle rounds to the nearest fifteen degrees and
 * the length is kept. */
static void line_15(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before;
    double deg;

    b = slurp("decomp/res/sen15.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/sen15.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  sen15.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SEN, r, 1)) {
        printf("BAD  sen15.jww has no line in it\n");
        fails++;
        return;
    }
    d = fresh();
    /* by way of 点: asking for 線 while 線 is already in force is how the
       original flips 水平・垂直, and that would hold the line flat */
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    type_box(1411, "");
    type_box(1412, "");
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar(d, 1333);
    ck(jw_cmd_bar_check(1333) == 0, "水平・垂直 is off");
    ck(jw_cmd_bar_check(1336) == 0, "線 comes up with １５度毎 off");
    jw_cmd_bar(d, 1336);
    ck(jw_cmd_bar_check(1336) == 1, "  and pressing it turns it on");
    before = d->ndrawn;
    /* the same two points the original was given: its start, and the free
       end it would have had -- 14.036 degrees, which rounds to 15 */
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    {   /* the free end the same two clicks give without the box ticked --
           taken from the original's own drawing of it, because a value read
           off six printed decimals is already 1e-8 out */
        unsigned char *fb;
        long fn;
        jw_drawing free_ref;
        const jw_obj *f[1];
        fb = slurp("decomp/res/sen15free.jww", &fn);
        if (!fb || !jw_parse(&free_ref, fb, fn) || !tail_of(&free_ref, JW_SEN, f, 1)) {
            printf("BAD  no decomp/res/sen15free.jww\n");
            fails++;
            free(fb);
            jw_free(&ref);
            return;
        }
        free(fb);
        jw_cmd_point(d, app_view(), f[0]->d[2], f[0]->d[3], 0);
        jw_free(&free_ref);
    }
    ck(d->ndrawn == before + 1, "  two clicks draw one line");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        if (!(near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3])))
            printf("     ours ends %.6f,%.6f, the original's %.6f,%.6f\n",
                   a->d[2], a->d[3], r[0]->d[2], r[0]->d[3]);
        ck(near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3]),
           "  ending exactly where the original ended");
        deg = atan2(a->d[3] - a->d[1], a->d[2] - a->d[0]) * 180.0 / 3.14159265358979323846;
        ck(fabs(deg + 15.0) < 1e-9, "  which is a whole fifteen degrees");
    }
    jw_free(&ref);
}

/* 多重円 (1417): rings inside the one drawn, at k/n of its radius. */
static void circle_rings(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[3];
    int before, i, ok = 1;

    b = slurp("decomp/res/enmulti.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/enmulti.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  enmulti.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_ENKO, r, 3)) {
        printf("BAD  enmulti.jww has no three circles in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_ENKO);
    type_box(1411, "");
    type_box(1417, "3");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[0]->d[0] + r[0]->d[2], r[0]->d[1], 0);
    ck(d->ndrawn == before + 3, "多重円 3: one drag draws three circles");
    if (d->ndrawn != before + 3) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 3; i++) {
        const jw_obj *a = &d->obj[before + i];
        if (!(near(a->d[0], r[i]->d[0]) && near(a->d[1], r[i]->d[1])
              && near(a->d[2], r[i]->d[2]) && a->n == r[i]->n)) {
            ok = 0;
            printf("     ours r=%.9f n=%d, the original's r=%.9f n=%d\n",
                   a->d[2], a->n, r[i]->d[2], r[i]->n);
        }
    }
    ck(ok, "  at the original's radii, outermost first");
    jw_free(&ref);
}

/* 扁平率 (1412) と 傾き (1413): an ellipse through the dragged point. */
static void circle_ellipse(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before;

    b = slurp("decomp/res/enflat.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/enflat.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  enflat.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_ENKO, r, 1)) {
        printf("BAD  enflat.jww has no ellipse in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_ENKO);
    type_box(1411, "");
    type_box(1417, "");
    type_box(1412, "50");
    type_box(1413, "20");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    /* the same drag: straight out along the paper, the length the original
       was given -- its own point on the curve at the parameter it wrote */
    jw_cmd_point(d, app_view(),
                 r[0]->d[0] + r[0]->d[2] * cos(r[0]->d[3]) * cos(r[0]->d[5])
                 - r[0]->d[2] * r[0]->d[6] * sin(r[0]->d[3]) * sin(r[0]->d[5]),
                 r[0]->d[1] + r[0]->d[2] * cos(r[0]->d[3]) * sin(r[0]->d[5])
                 + r[0]->d[2] * r[0]->d[6] * sin(r[0]->d[3]) * cos(r[0]->d[5]), 0);
    ck(d->ndrawn == before + 1, "扁平率と傾き: the drag draws one ellipse");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        int ok = near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3])
                 && near(a->d[5], r[0]->d[5]) && near(a->d[6], r[0]->d[6]);
        if (!ok)
            printf("     ours  a=%.9f t=%.9f tilt=%.9f ratio=%.9f\n"
                   "     the original's a=%.9f t=%.9f tilt=%.9f ratio=%.9f\n",
                   a->d[2], a->d[3], a->d[5], a->d[6],
                   r[0]->d[2], r[0]->d[3], r[0]->d[5], r[0]->d[6]);
        ck(ok, "  the long radius, the angle, the tilt and the ratio");
    }
    jw_free(&ref);
}

/* 矩形 の ソリッド (1334): one filled quadrilateral, not four lines. */
static void rect_solid(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before, i, ok = 1;

    b = slurp("decomp/res/kusolid.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/kusolid.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  kusolid.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SOLID, r, 1)) {
        printf("BAD  kusolid.jww has no solid in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1411, "");
    type_box(1413, "");
    ck(jw_cmd_bar_check(1334) == 0, "矩形 comes up with ソリッド off");
    jw_cmd_bar(d, 1334);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[0]->d[4], r[0]->d[5], 0);
    ck(d->ndrawn == before + 1, "  and with it on, two clicks draw one solid");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        ck(a->cls == JW_SOLID, "  which is a ソリッド, not four lines");
        for (i = 0; i < 8; i++)
            if (!near(a->d[i], r[0]->d[i]))
                ok = 0;
        if (!ok)
            printf("     ours  %.4f,%.4f %.4f,%.4f %.4f,%.4f %.4f,%.4f\n"
                   "     the original's %.4f,%.4f %.4f,%.4f %.4f,%.4f %.4f,%.4f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   a->d[4], a->d[5], a->d[6], a->d[7],
                   r[0]->d[0], r[0]->d[1], r[0]->d[2], r[0]->d[3],
                   r[0]->d[4], r[0]->d[5], r[0]->d[6], r[0]->d[7]);
        ck(ok, "  with its four corners in the original's order");
    }
    jw_cmd_bar(d, 1334);
    jw_free(&ref);
}

/* 寸法 の 小数桁 (1061): the button cycles 2 -> 3 -> 0 -> 1 -> 2.
 *
 * Each case drives the port the way the original was driven -- the same
 * line, the same clicks, that many presses -- and scores the value written
 * and the width word that carries the places (places << 12 | 0x43). */
static void dim_decimals(void)
{
    static const char *FILE_OF[4] = {
        "decomp/res/sunpo.jww", "decomp/res/sunketa.jww",
        "decomp/res/sunketa2.jww", "decomp/res/sunketa3.jww"
    };
    int c;

    for (c = 0; c < 4; c++) {
        unsigned char *b;
        long n;
        jw_drawing ref, *d;
        const jw_obj *r_line = 0, *r_dim = 0, *r_ext = 0, *r_txt = 0;
        const char *want, *got;
        int i, nb, before, k;

        b = slurp(FILE_OF[c], &n);
        if (!b) {
            printf("BAD  no %s -- run tools/refanswers.sh\n", FILE_OF[c]);
            fails++;
            continue;
        }
        if (!jw_parse(&ref, b, n)) {
            printf("BAD  %s: %s\n", FILE_OF[c], ref.error);
            fails++;
            free(b);
            continue;
        }
        free(b);
        d = fresh();
        nb = d->ndrawn;
        for (i = nb; i < ref.ndrawn; i++) {
            const jw_obj *o = &ref.obj[i];
            if (o->cls == JW_SEN && o->flags == 0 && o->color == 2 && !r_line)
                r_line = o;
            else if (o->cls == JW_SEN && (o->flags & 0x2000)) {
                if (!r_dim)
                    r_dim = o;
                else if (!r_ext)
                    r_ext = o;
            } else if (o->cls == JW_MOJI && (o->flags & 0x4000))
                r_txt = o;
        }
        if (!r_line || !r_dim || !r_ext || !r_txt) {
            printf("BAD  %s has no dimension in it\n", FILE_OF[c]);
            fails++;
            jw_free(&ref);
            continue;
        }
        want = jw_str(&ref, r_txt->text);
        {   /* the line the original drew first */
            jw_obj *o = jw_add(d, JW_SEN);
            o->d[0] = r_line->d[0];
            o->d[1] = r_line->d[1];
            o->d[2] = r_line->d[2];
            o->d[3] = r_line->d[3];
        }
        app_fit();
        before = d->ndrawn;
        jw_cmd_set(JW_CMD_SUNPO);
        for (k = 0; k < c; k++)
            jw_cmd_bar(d, 1061);
        type_box(1411, "0");
        jw_cmd_point(d, app_view(), r_ext->d[2], r_ext->d[3], 0);
        jw_cmd_point(d, app_view(), r_dim->d[0], r_dim->d[1], 0);
        jw_cmd_point(d, app_view(), r_line->d[0], r_line->d[1], 0);
        jw_cmd_point(d, app_view(), r_line->d[2], r_line->d[3], 0);
        if (d->ndrawn != before + 6) {
            printf("BAD  %s: the port drew %d elements, not six\n",
                   FILE_OF[c], d->ndrawn - before);
            fails++;
            jw_free(&ref);
            continue;
        }
        got = jw_str(d, d->obj[d->ndrawn - 1].text);
        if (!got || !want || strcmp(got, want)
            || d->obj[d->ndrawn - 1].width != r_txt->width)
            printf("     %d presses: ours [%s] width %#x, the original's [%s] %#x\n",
                   c, got ? got : "(none)",
                   (unsigned)d->obj[d->ndrawn - 1].width,
                   want ? want : "(none)", (unsigned)r_txt->width);
        ck(got && want && !strcmp(got, want)
           && d->obj[d->ndrawn - 1].width == r_txt->width,
           c == 0 ? "小数桁: no press writes the original's two places"
                  : "  and another press writes what the original's does");
        /* back to where it started for the next case */
        for (k = c; k < 4; k++)
            jw_cmd_bar(d, 1061);
        jw_free(&ref);
    }
}

/* 文字 の 垂直 (1324): the baseline turns a quarter turn. */
static void text_vertical(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before;

    b = slurp("decomp/res/mojivert.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/mojivert.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  mojivert.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    {   /* not the last text: the original keeps its own settings
           records as texts at (0,-1000).  The one wanted says ABC. */
        int i;
        r[0] = 0;
        for (i = 0; i < ref.ndrawn; i++) {
            const char *t = ref.obj[i].cls == JW_MOJI
                            ? jw_str(&ref, ref.obj[i].text) : 0;
            if (t && !strcmp(t, "ABC"))
                r[0] = &ref.obj[i];
        }
        if (!r[0]) {
            printf("BAD  mojivert.jww has no ABC in it\n");
            fails++;
            return;
        }
    }
    d = fresh();
    app_command(0x8026);                        /* 文字 */
    {   /* 縦字 (1325) first, which is only bit 0x20 on the text */
        unsigned char *tb;
        long tn;
        jw_drawing tref;
        const jw_obj *tv = 0;
        int k, was;
        tb = slurp("decomp/res/mojitate.jww", &tn);
        if (tb && jw_parse(&tref, tb, tn)) {
            free(tb);
            for (k = 0; k < tref.ndrawn; k++) {
                const char *t = tref.obj[k].cls == JW_MOJI
                                ? jw_str(&tref, tref.obj[k].text) : 0;
                if (t && !strcmp(t, "ABC"))
                    tv = &tref.obj[k];
            }
            jw_cmd_bar(d, 1325);
            was = d->ndrawn;
            app_key('A');
            app_key('B');
            app_key('C');
            jw_cmd_point(d, app_view(), tv ? tv->d[0] : 0.0,
                         tv ? tv->d[1] : 0.0, 0);
            ck(tv && d->ndrawn == was + 1, "文字: 縦字 puts a text down");
            if (tv && d->ndrawn == was + 1) {
                const jw_obj *a = &d->obj[was];
                ck(a->flags == tv->flags && near(a->d[2], tv->d[2])
                   && near(a->d[3], tv->d[3]),
                   "  with the original's own flags (0x20) and ends");
            }
            jw_cmd_bar(d, 1325);
            jw_free(&tref);
        } else {
            free(tb);
        }
    }
    jw_cmd_bar(d, 1324);
    ck(jw_cmd_bar_check(1324) == 1, "文字: 垂直 turns on");
    before = d->ndrawn;
    app_key('A');
    app_key('B');
    app_key('C');
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    ck(d->ndrawn == before + 1, "  and a click puts the text down");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        int ok = near(a->d[0], r[0]->d[0]) && near(a->d[1], r[0]->d[1])
                 && near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3]);
        if (!ok)
            printf("     ours %.4f,%.4f -> %.4f,%.4f, the original's %.4f,%.4f -> %.4f,%.4f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   r[0]->d[0], r[0]->d[1], r[0]->d[2], r[0]->d[3]);
        ck(ok, "  running the way the original ran it -- upward");
    }
    jw_cmd_bar(d, 1324);
    jw_free(&ref);
}

/* 寸法 の 端部 (1062): a point at each end, or an arrowhead.  Scored on
 * every element the original wrote, in its order. */
static void dim_arrows(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r_line = 0, *r_dim = 0, *r_ext = 0;
    int i, nb, before, ok = 1, nref = 0;

    b = slurp("decomp/res/suntan.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/suntan.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  suntan.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    d = fresh();
    nb = d->ndrawn;
    for (i = nb; i < ref.ndrawn; i++) {
        const jw_obj *o = &ref.obj[i];
        if (o->cls == JW_SEN && o->flags == 0 && o->color == 2 && !r_line)
            r_line = o;
        else if (o->cls == JW_SEN && (o->flags & 0x2000)) {
            nref++;
            if (!r_dim)
                r_dim = o;     /* the 寸法線 comes first */
            r_ext = o;         /* and the 引出線 last, after the arrows */
        }
    }
    if (!r_line || !r_dim || !r_ext) {
        printf("BAD  suntan.jww has no dimension in it\n");
        fails++;
        jw_free(&ref);
        return;
    }
    ck(nref == 7, "端部: the original's arrowed dimension has seven lines");
    {
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = r_line->d[0];
        o->d[1] = r_line->d[1];
        o->d[2] = r_line->d[2];
        o->d[3] = r_line->d[3];
    }
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_bar(d, 1062);
    type_box(1411, "0");
    jw_cmd_point(d, app_view(), r_ext->d[2], r_ext->d[3], 0);
    jw_cmd_point(d, app_view(), r_dim->d[0], r_dim->d[1], 0);
    jw_cmd_point(d, app_view(), r_line->d[0], r_line->d[1], 0);
    jw_cmd_point(d, app_view(), r_line->d[2], r_line->d[3], 0);
    {   /* every dimension line the port made, against the original's */
        int mine = 0, k = 0;
        for (i = before; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_SEN && (d->obj[i].flags & 0x2000))
                mine++;
        ck(mine == nref, "  and so does the port's");
        for (i = nb; i < ref.ndrawn && k < d->ndrawn - before; i++) {
            const jw_obj *o = &ref.obj[i];
            const jw_obj *a;
            if (!(o->cls == JW_SEN && (o->flags & 0x2000)))
                continue;
            while (before + k < d->ndrawn
                   && !(d->obj[before + k].cls == JW_SEN
                        && (d->obj[before + k].flags & 0x2000)))
                k++;
            if (before + k >= d->ndrawn)
                break;
            a = &d->obj[before + k];
            if (!(near(a->d[0], o->d[0]) && near(a->d[1], o->d[1])
                  && near(a->d[2], o->d[2]) && near(a->d[3], o->d[3]))) {
                ok = 0;
                printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
                       "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                       a->d[0], a->d[1], a->d[2], a->d[3],
                       o->d[0], o->d[1], o->d[2], o->d[3]);
            }
            k++;
        }
        ck(ok, "  every one of them where the original put it");
    }
    jw_cmd_bar(d, 1062);
    jw_free(&ref);
}

/* 円 の ３点指示 (1321): the circle through three clicked points. */
static void circle_3pt(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before;
    double a0 = 0.0, a1 = 2.0943951023931953, a2 = 4.1887902047863905;

    b = slurp("decomp/res/en3pt.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/en3pt.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  en3pt.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_ENKO, r, 1)) {
        printf("BAD  en3pt.jww has no circle in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_ENKO);
    type_box(1411, "");
    type_box(1412, "");
    type_box(1413, "");
    type_box(1417, "");
    jw_cmd_bar(d, 1321);
    ck(jw_cmd_bar_check(1321) == 1, "円: ３点指示 turns on");
    before = d->ndrawn;
    /* three points on the circle the original drew -- any three do */
    jw_cmd_point(d, app_view(), r[0]->d[0] + r[0]->d[2] * cos(a0),
                                r[0]->d[1] + r[0]->d[2] * sin(a0), 0);
    jw_cmd_point(d, app_view(), r[0]->d[0] + r[0]->d[2] * cos(a1),
                                r[0]->d[1] + r[0]->d[2] * sin(a1), 0);
    ck(d->ndrawn == before, "  the first two clicks draw nothing");
    jw_cmd_point(d, app_view(), r[0]->d[0] + r[0]->d[2] * cos(a2),
                                r[0]->d[1] + r[0]->d[2] * sin(a2), 0);
    ck(d->ndrawn == before + 1, "  the third draws the circle");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        int ok = fabs(a->d[0] - r[0]->d[0]) < 1e-6
                 && fabs(a->d[1] - r[0]->d[1]) < 1e-6
                 && fabs(a->d[2] - r[0]->d[2]) < 1e-6
                 && near(a->d[3], r[0]->d[3]) && a->n == r[0]->n;
        if (!ok)
            printf("     ours c=(%.6f,%.6f) r=%.6f, the original's c=(%.6f,%.6f) r=%.6f\n",
                   a->d[0], a->d[1], a->d[2],
                   r[0]->d[0], r[0]->d[1], r[0]->d[2]);
        ck(ok, "  round the original's centre, at its radius");
    }
    jw_cmd_bar(d, 1321);
    jw_free(&ref);
}

/* 円 の 半円 (1320): the diameter's two ends, then the side it bulges. */
static void circle_half(void)
{
    static const char *FILE_OF[2] = {
        "decomp/res/enhalf.jww", "decomp/res/enhalf2.jww"
    };
    int c;

    for (c = 0; c < 2; c++) {
        unsigned char *b;
        long n;
        jw_drawing ref, *d;
        const jw_obj *r[1];
        int before;
        double p1x, p1y, p2x, p2y, midx, midy;

        b = slurp(FILE_OF[c], &n);
        if (!b) {
            printf("BAD  no %s -- run tools/refanswers.sh\n", FILE_OF[c]);
            fails++;
            continue;
        }
        if (!jw_parse(&ref, b, n)) {
            printf("BAD  %s: %s\n", FILE_OF[c], ref.error);
            fails++;
            free(b);
            continue;
        }
        free(b);
        if (!tail_of(&ref, JW_ENKO, r, 1)) {
            printf("BAD  %s has no half circle in it\n", FILE_OF[c]);
            fails++;
            continue;
        }
        d = fresh();
        jw_cmd_set(JW_CMD_ENKO);
        type_box(1411, "");
        type_box(1417, "");
        jw_cmd_bar(d, 1320);
        before = d->ndrawn;
        /* the two ends of its diameter, and a point on the side it bulges */
        p1x = r[0]->d[0] + r[0]->d[2] * cos(r[0]->d[5]);
        p1y = r[0]->d[1] + r[0]->d[2] * sin(r[0]->d[5]);
        p2x = r[0]->d[0] - r[0]->d[2] * cos(r[0]->d[5]);
        p2y = r[0]->d[1] - r[0]->d[2] * sin(r[0]->d[5]);
        midx = r[0]->d[0] + r[0]->d[2] * cos(r[0]->d[5] + r[0]->d[4] / 2.0);
        midy = r[0]->d[1] + r[0]->d[2] * sin(r[0]->d[5] + r[0]->d[4] / 2.0);
        jw_cmd_point(d, app_view(), p1x, p1y, 0);
        jw_cmd_point(d, app_view(), p2x, p2y, 0);
        jw_cmd_point(d, app_view(), midx, midy, 0);
        ck(d->ndrawn == before + 1,
           c == 0 ? "半円: three clicks draw one" : "  and the other side too");
        if (d->ndrawn == before + 1) {
            const jw_obj *a = &d->obj[before];
            int ok = near(a->d[0], r[0]->d[0]) && near(a->d[1], r[0]->d[1])
                     && near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3])
                     && near(a->d[4], r[0]->d[4]) && near(a->d[5], r[0]->d[5])
                     && a->n == r[0]->n;
            if (!ok)
                printf("     ours c=(%.4f,%.4f) r=%.4f a=%.4f sweep=%.6f tilt=%.6f\n"
                       "     the original's c=(%.4f,%.4f) r=%.4f a=%.4f sweep=%.6f tilt=%.6f\n",
                       a->d[0], a->d[1], a->d[2], a->d[3], a->d[4], a->d[5],
                       r[0]->d[0], r[0]->d[1], r[0]->d[2], r[0]->d[3],
                       r[0]->d[4], r[0]->d[5]);
            ck(ok, "  the original's centre, radius, tilt and sweep");
        }
        jw_cmd_bar(d, 1320);
        jw_free(&ref);
    }
}

/* 線 の 寸法値 (1350): the line becomes a dimension and its length goes
 * beside it. */
static void line_value(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r_sen = 0, *r_txt = 0;
    int i, before;

    b = slurp("decomp/res/sensun.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/sensun.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  sensun.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++) {
        const jw_obj *o = &ref.obj[i];
        if (o->cls == JW_SEN && (o->flags & 0x2000))
            r_sen = o;
        else if (o->cls == JW_MOJI && (o->flags & 0x4000))
            r_txt = o;
    }
    if (!r_sen || !r_txt) {
        printf("BAD  sensun.jww has no measured line in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    type_box(1411, "");
    type_box(1412, "");
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar(d, 1333);
    if (jw_cmd_bar_check(1336) > 0)
        jw_cmd_bar(d, 1336);
    jw_cmd_bar(d, 1350);
    ck(jw_cmd_bar_check(1350) == 1, "線: 寸法値 turns on");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r_sen->d[0], r_sen->d[1], 0);
    jw_cmd_point(d, app_view(), r_sen->d[2], r_sen->d[3], 0);
    ck(d->ndrawn == before + 2, "  and the line comes with its length");
    if (d->ndrawn == before + 2) {
        const jw_obj *a = &d->obj[before], *t = &d->obj[before + 1];
        const char *got = jw_str(d, t->text), *want = jw_str(&ref, r_txt->text);
        ck((a->flags & 0x2000) != 0, "  the line carries the dimension flag");
        if (!got || !want || strcmp(got, want))
            printf("     ours [%s], the original's [%s]\n",
                   got ? got : "(none)", want ? want : "(none)");
        ck(got && want && !strcmp(got, want), "  the length the original wrote");
        {
            int ok = near(t->d[0], r_txt->d[0]) && near(t->d[1], r_txt->d[1])
                     && near(t->d[2], r_txt->d[2]) && near(t->d[3], r_txt->d[3])
                     && t->width == r_txt->width && t->n == r_txt->n;
            if (!ok)
                printf("     ours %.4f,%.4f -> %.4f,%.4f w=%#x n=%d\n"
                       "     the original's %.4f,%.4f -> %.4f,%.4f w=%#x n=%d\n",
                       t->d[0], t->d[1], t->d[2], t->d[3],
                       (unsigned)t->width, t->n,
                       r_txt->d[0], r_txt->d[1], r_txt->d[2], r_txt->d[3],
                       (unsigned)r_txt->width, r_txt->n);
            ck(ok, "  laid along the line where the original laid it");
        }
    }
    jw_cmd_bar(d, 1350);
    jw_free(&ref);
}

/* 複線 の 複線間隔 (1411): a typed offset, and the click only says which
 * side.  The original takes it in its second stage -- 「間隔を入力するか、
 * 複写する位置」 -- and goes straight on to the third. */
static void offset_typed(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[2];
    int before;
    double mx, my;

    b = slurp("decomp/res/fukukan.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/fukukan.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  fukukan.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SEN, r, 2)) {
        printf("BAD  fukukan.jww has no pair of lines in it\n");
        fails++;
        return;
    }
    d = fresh();
    {   /* the line the original drew, put in the same way */
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = r[0]->d[0];
        o->d[1] = r[0]->d[1];
        o->d[2] = r[0]->d[2];
        o->d[3] = r[0]->d[3];
    }
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_FUKUSEN);
    type_box(1411, "1000");
    mx = (r[0]->d[0] + r[0]->d[2]) / 2.0;
    my = (r[0]->d[1] + r[0]->d[3]) / 2.0;
    jw_cmd_point(d, app_view(), mx, my, 0);              /* the line */
    ck(d->ndrawn == before, "複線: picking the line draws nothing");
    /* one click on the side the original's copy went, and that is all */
    jw_cmd_point(d, app_view(), mx, my + (r[1]->d[1] - r[0]->d[1]) * 0.3, 0);
    ck(d->ndrawn == before + 1, "  and with an interval typed, one more draws it");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        int ok = near(a->d[0], r[1]->d[0]) && near(a->d[1], r[1]->d[1])
                 && near(a->d[2], r[1]->d[2]) && near(a->d[3], r[1]->d[3]);
        if (!ok)
            printf("     ours %.6f,%.6f -> %.6f,%.6f\n"
                   "     the original's %.6f,%.6f -> %.6f,%.6f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   r[1]->d[0], r[1]->d[1], r[1]->d[2], r[1]->d[3]);
        ck(ok, "  exactly where the original's copy went (5 mm, 1000/200)");
    }
    type_box(1411, "");
    jw_free(&ref);
}

/* 寸法 の 半径 (1065): one click on a circle -- a line from its centre, the
 * value with an R in front, and a point at each end. */
static void dim_radius_one(const char *file, int button)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r_c = 0, *r_sen = 0, *r_txt = 0;
    int i, before;

    b = slurp(file, &n);
    if (!b) {
        printf("BAD  no %s -- run tools/refanswers.sh\n", file);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", file, ref.error);
        fails++;
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++) {
        const jw_obj *o = &ref.obj[i];
        if (o->cls == JW_ENKO && !r_c)
            r_c = o;
        else if (o->cls == JW_SEN && (o->flags & 0x2000) && !r_sen)
            r_sen = o;
        else if (o->cls == JW_MOJI && (o->flags & 0x4000) && !r_txt)
            r_txt = o;
    }
    if (!r_c || !r_sen || !r_txt) {
        printf("BAD  %s has no radius dimension in it\n", file);
        fails++;
        return;
    }
    d = fresh();
    {   /* the circle the original measured */
        jw_obj *o = jw_add(d, JW_ENKO);
        int k;
        for (k = 0; k < 8; k++)
            o->d[k] = r_c->d[k];
        o->n = r_c->n;
    }
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_SUNPO);
    ck(jw_cmd_bar(d, button) == 1,
       button == 1065 ? "寸法: 半径 can be pressed" : "寸法: 直径 can be pressed");
    jw_cmd_point(d, app_view(), r_sen->d[2], r_sen->d[3], 0);
    ck(d->ndrawn == before + 4, "  and one click on the circle makes four elements");
    if (d->ndrawn == before + 4) {
        const jw_obj *a = &d->obj[before], *t = &d->obj[before + 1];
        const char *got = jw_str(d, t->text), *want = jw_str(&ref, r_txt->text);
        int ok = near(a->d[0], r_sen->d[0]) && near(a->d[1], r_sen->d[1])
                 && near(a->d[2], r_sen->d[2]) && near(a->d[3], r_sen->d[3]);
        ck(ok, "  the line from the centre out, where the original put it");
        if (!got || !want || strcmp(got, want))
            printf("     ours [%s], the original's [%s]\n",
                   got ? got : "(none)", want ? want : "(none)");
        ck(got && want && !strcmp(got, want), "  the R value it wrote");
        ok = near(t->d[0], r_txt->d[0]) && near(t->d[1], r_txt->d[1])
             && near(t->d[2], r_txt->d[2]) && near(t->d[3], r_txt->d[3])
             && t->width == r_txt->width && t->flags == r_txt->flags;
        if (!ok)
            printf("     ours %.4f,%.4f -> %.4f,%.4f w=%#x f=%#x\n"
                   "     the original's %.4f,%.4f -> %.4f,%.4f w=%#x f=%#x\n",
                   t->d[0], t->d[1], t->d[2], t->d[3],
                   (unsigned)t->width, (unsigned)t->flags,
                   r_txt->d[0], r_txt->d[1], r_txt->d[2], r_txt->d[3],
                   (unsigned)r_txt->width, (unsigned)r_txt->flags);
        ck(ok, "  laid where the original laid it, with its own flags");
    }
    jw_cmd_bar(d, 1064);
    jw_free(&ref);
}

static void dim_radius(void)
{
    dim_radius_one("decomp/res/sunhankei.jww", 1065);
    dim_radius_one("decomp/res/sunchokkei.jww", 1066);
}

/* Esc lets go of the points taken so far.
 *
 * The original, given a click, an Esc and then two more clicks, drew the
 * rectangle across the *last two* -- the first was thrown away. */
static void escape_drops_the_point(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[4];
    int before, i, ok = 1;

    b = slurp("decomp/res/kuesc.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/kuesc.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  kuesc.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SEN, r, 4)) {
        printf("BAD  kuesc.jww has no rectangle in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1411, "");
    type_box(1413, "");
    if (jw_cmd_bar_check(1334) > 0)
        jw_cmd_bar(d, 1334);
    before = d->ndrawn;
    /* a point the original threw away: anywhere but its corners */
    jw_cmd_point(d, app_view(), r[0]->d[0] - 90.0, r[0]->d[1] + 90.0, 0);
    app_key(27);
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[1]->d[2], r[1]->d[3], 0);
    ck(d->ndrawn == before + 4, "Esc: the rectangle is drawn from the last two");
    if (d->ndrawn == before + 4) {
        for (i = 0; i < 4; i++) {
            const jw_obj *a = &d->obj[before + i];
            if (!(near(a->d[0], r[i]->d[0]) && near(a->d[1], r[i]->d[1])
                  && near(a->d[2], r[i]->d[2]) && near(a->d[3], r[i]->d[3]))) {
                ok = 0;
                printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
                       "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                       a->d[0], a->d[1], a->d[2], a->d[3],
                       r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
            }
        }
        ck(ok, "  exactly where the original drew it, the first point gone");
    }
    jw_free(&ref);
}

/* Space turns 水平・垂直 over, which is what the original does with it. */
static void space_turns_hv(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[1];
    int before, was;

    b = slurp("decomp/res/senspace.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/senspace.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  senspace.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SEN, r, 1)) {
        printf("BAD  senspace.jww has no line in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    type_box(1411, "");
    type_box(1412, "");
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar(d, 1333);
    if (jw_cmd_bar_check(1336) > 0)
        jw_cmd_bar(d, 1336);
    was = jw_cmd_bar_check(1333);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    app_key(32);
    ck(jw_cmd_bar_check(1333) != was, "Space: 水平・垂直 turns over");
    app_key(32);
    ck(jw_cmd_bar_check(1333) == was, "  and back again on the next press");
    app_key(32);
    /* the same second click the original was given: up and to the right */
    {   /* the same drag: up and to the right by the height it ended at.
           Taken from the answer rather than typed, because a value read off
           six printed decimals is already 1e-8 out. */
        double up = r[0]->d[3] - r[0]->d[1];
        jw_cmd_point(d, app_view(), r[0]->d[0] + up, r[0]->d[1] + up, 0);
    }
    ck(d->ndrawn == before + 1, "  and the line is drawn");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        int ok = near(a->d[0], r[0]->d[0]) && near(a->d[1], r[0]->d[1])
                 && near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3]);
        if (!ok)
            printf("     ours %.6f,%.6f -> %.6f,%.6f\n"
                   "     the original's %.6f,%.6f -> %.6f,%.6f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   r[0]->d[0], r[0]->d[1], r[0]->d[2], r[0]->d[3]);
        ck(ok, "  straight up, where the original drew it");
    }
    if (jw_cmd_bar_check(1333) != was)
        app_key(32);
    jw_free(&ref);
}

/* 矩形 の 多重 (1417): rectangles inside the one drawn, k/n of its size. */
static void rect_rings(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[12];
    int before, i, ok = 1;

    b = slurp("decomp/res/ku_multi.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/ku_multi.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  ku_multi.jww: %s\n", ref.error);
        fails++;
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SEN, r, 12)) {
        printf("BAD  ku_multi.jww has no three rectangles in it\n");
        fails++;
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1411, "");
    type_box(1413, "");
    type_box(1417, "3");
    if (jw_cmd_bar_check(1334) > 0)
        jw_cmd_bar(d, 1334);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[1]->d[2], r[1]->d[3], 0);
    ck(d->ndrawn == before + 12, "多重 3: two clicks draw three rectangles");
    if (d->ndrawn == before + 12) {
        for (i = 0; i < 12; i++) {
            const jw_obj *a = &d->obj[before + i];
            if (!(near(a->d[0], r[i]->d[0]) && near(a->d[1], r[i]->d[1])
                  && near(a->d[2], r[i]->d[2]) && near(a->d[3], r[i]->d[3]))) {
                ok = 0;
                printf("     %d ours %.4f,%.4f -> %.4f,%.4f, the original's %.4f,%.4f -> %.4f,%.4f\n",
                       i, a->d[0], a->d[1], a->d[2], a->d[3],
                       r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
            }
        }
        ck(ok, "  all twelve lines where the original put them");
    }
    type_box(1417, "");
    jw_free(&ref);
}

/* 矩形 の (対角線) 1335 と 任意色 2553, both on top of ソリッド. */
static void rect_solid_more(void)
{
    static const struct { const char *file; int id; const char *what; } C[2] = {
        { "decomp/res/ku_diag.jww", 1335, "(対角線)" },
        { "decomp/res/ku_anycol.jww", 2553, "任意色" }
    };
    int c;

    for (c = 0; c < 2; c++) {
        unsigned char *b;
        long n;
        jw_drawing ref, *d;
        const jw_obj *r[1];
        int before, i, ok = 1;

        b = slurp(C[c].file, &n);
        if (!b) {
            printf("BAD  no %s -- run tools/refanswers.sh\n", C[c].file);
            fails++;
            continue;
        }
        if (!jw_parse(&ref, b, n)) {
            printf("BAD  %s: %s\n", C[c].file, ref.error);
            fails++;
            free(b);
            continue;
        }
        free(b);
        if (!tail_of(&ref, JW_SOLID, r, 1)) {
            printf("BAD  %s has no solid in it\n", C[c].file);
            fails++;
            continue;
        }
        d = fresh();
        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_KUKEI);
        type_box(1411, "");
        type_box(1413, "");
        type_box(1417, "");
        if (jw_cmd_bar_check(1334) <= 0)
            jw_cmd_bar(d, 1334);
        jw_cmd_bar(d, C[c].id);
        before = d->ndrawn;
        jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
        jw_cmd_point(d, app_view(), c == 0 ? r[0]->d[2] : r[0]->d[4],
                     c == 0 ? r[0]->d[3] : r[0]->d[5], 0);
        ck(d->ndrawn == before + 1, C[c].what);
        if (d->ndrawn == before + 1) {
            const jw_obj *a = &d->obj[before];
            for (i = 0; i < 8; i++)
                if (!near(a->d[i], r[0]->d[i]))
                    ok = 0;
            if (a->color != r[0]->color || a->n != r[0]->n)
                ok = 0;
            if (!ok)
                printf("     ours pen=%d n=%#x %.1f,%.1f %.1f,%.1f %.1f,%.1f %.1f,%.1f\n"
                       "     the original's pen=%d n=%#x %.1f,%.1f %.1f,%.1f %.1f,%.1f %.1f,%.1f\n",
                       a->color, (unsigned)a->n, a->d[0], a->d[1], a->d[2],
                       a->d[3], a->d[4], a->d[5], a->d[6], a->d[7],
                       r[0]->color, (unsigned)r[0]->n, r[0]->d[0], r[0]->d[1],
                       r[0]->d[2], r[0]->d[3], r[0]->d[4], r[0]->d[5],
                       r[0]->d[6], r[0]->d[7]);
            ck(ok, "  the original's corners, pen and colour");
        }
        jw_cmd_bar(d, C[c].id);
        jw_cmd_bar(d, 1334);
        jw_free(&ref);
    }
}

/* 線 の ●─── (1348) と ＜─── (1349): a mark on the point clicked first. */
static void line_marks(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[3];
    const jw_obj *t[1];
    int before, i, ok = 1;

    /* ＜───: the line, then two legs off its start */
    b = slurp("decomp/res/sen_a_fwd.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/sen_a_fwd.jww -- run tools/refanswers.sh\n");
        fails++;
    } else if (!jw_parse(&ref, b, n)) {
        printf("BAD  sen_a_fwd.jww: %s\n", ref.error);
        fails++;
        free(b);
    } else {
        free(b);
        if (!tail_of(&ref, JW_SEN, r, 3)) {
            printf("BAD  sen_a_fwd.jww has no line and two legs in it\n");
            fails++;
        } else {
            d = fresh();
            jw_cmd_set(JW_CMD_TEN);
            jw_cmd_set(JW_CMD_SEN);
            type_box(1411, "");
            type_box(1412, "");
            if (jw_cmd_bar_check(1333) > 0)
                app_key(32);            /* 水平・垂直 off */
            if (jw_cmd_bar_check(1349) <= 0)
                jw_cmd_bar(d, 1349);
            before = d->ndrawn;
            jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
            jw_cmd_point(d, app_view(), r[0]->d[2], r[0]->d[3], 0);
            ck(d->ndrawn == before + 3, "＜───: the line and two legs");
            if (d->ndrawn == before + 3) {
                for (i = 0; i < 3; i++) {
                    const jw_obj *a = &d->obj[before + i];
                    if (!(near(a->d[0], r[i]->d[0]) && near(a->d[1], r[i]->d[1])
                          && near(a->d[2], r[i]->d[2])
                          && near(a->d[3], r[i]->d[3]))) {
                        ok = 0;
                        printf("     %d ours %.4f,%.4f -> %.4f,%.4f, the original's %.4f,%.4f -> %.4f,%.4f\n",
                               i, a->d[0], a->d[1], a->d[2], a->d[3],
                               r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
                    }
                }
                ck(ok, "  3 long at plus then minus 15 degrees, as the original drew");
            }
            jw_cmd_bar(d, 1349);
        }
        jw_free(&ref);
    }

    /* ●───: the line and a 点 on its start */
    b = slurp("decomp/res/sen_p_fwd.jww", &n);
    if (!b) {
        printf("BAD  no decomp/res/sen_p_fwd.jww -- run tools/refanswers.sh\n");
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  sen_p_fwd.jww: %s\n", ref.error);
        fails++;
        free(b);
        return;
    }
    free(b);
    /* the drawn line is not the last one in the file -- find the one that
       starts where the mark is */
    if (tail_of(&ref, JW_TEN, t, 1)) {
        const jw_obj *all[4096];
        int m = of_class(&ref, JW_SEN, all, 4096), j;
        r[0] = 0;
        for (j = m - 1; j >= 0; j--)
            if (near(all[j]->d[0], t[0]->d[0]) && near(all[j]->d[1], t[0]->d[1])) {
                r[0] = all[j];
                break;
            }
    } else {
        r[0] = 0;
    }
    if (!r[0]) {
        printf("BAD  sen_p_fwd.jww has no line with a point on it\n");
        fails++;
        jw_free(&ref);
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    type_box(1411, "");
    type_box(1412, "");
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);
    if (jw_cmd_bar_check(1348) <= 0)
        jw_cmd_bar(d, 1348);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[0]->d[2], r[0]->d[3], 0);
    ck(d->ndrawn == before + 2, "●───: the line and a point");
    if (d->ndrawn == before + 2) {
        const jw_obj *a = &d->obj[before + 1];
        /* the original wrote the point with pen 1 and line type 1 while the
           line came out pen 2 -- the mark does not take the writing pen, and
           the test says so both ways round. */
        ok = a->cls == JW_TEN && near(a->d[0], t[0]->d[0])
             && near(a->d[1], t[0]->d[1]) && a->ltype == t[0]->ltype
             && a->color == t[0]->color && t[0]->color != r[0]->color;
        if (!ok)
            printf("     ours cls=%d pen=%d type=%d %.4f,%.4f\n"
                   "     the original's pen=%d type=%d %.4f,%.4f\n",
                   a->cls, a->color, a->ltype, a->d[0], a->d[1],
                   t[0]->color, t[0]->ltype, t[0]->d[0], t[0]->d[1]),
            printf("     our line pen=%d, the original's line pen=%d\n",
                   d->obj[before].color, r[0]->color);
        ck(ok, "  on the point clicked first, pen and type as the original wrote them");
    }
    jw_cmd_bar(d, 1348);
    jw_free(&ref);
}

/* 線 の 傾き (1411) on its own: the angle is fixed and the drag only
   says how far along it to go. */
static void line_slope(void)
{
    static const struct { const char *file; } C[2] = {
        { "decomp/res/sen_kata30.jww" },
        { "decomp/res/sen_kata_m.jww" }
    };
    int c;

    for (c = 0; c < 2; c++) {
        unsigned char *b;
        long n;
        jw_drawing ref, *d;
        const jw_obj *r[1];
        int before, ok;

        b = slurp(C[c].file, &n);
        if (!b) {
            printf("BAD  no %s -- run tools/refanswers.sh\n", C[c].file);
            fails++;
            continue;
        }
        if (!jw_parse(&ref, b, n)) {
            printf("BAD  %s: %s\n", C[c].file, ref.error);
            fails++;
            free(b);
            continue;
        }
        free(b);
        if (!tail_of(&ref, JW_SEN, r, 1)) {
            printf("BAD  %s has no line in it\n", C[c].file);
            fails++;
            continue;
        }
        d = fresh();
        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_SEN);
        type_box(1412, "");
        type_box(1411, "30");
        if (jw_cmd_bar_check(1333) > 0)
            app_key(32);
        before = d->ndrawn;
        jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
        /* the second click: the end of the original's own line pushed 50
           sideways.  A drag read off six printed decimals is already 1e-4
           out, and the projection has to throw the sideways part away, so
           this says the same thing exactly. */
        jw_cmd_point(d, app_view(),
                     r[0]->d[2] + 50.0 * -sin(30.0 * 3.14159265358979323846 / 180.0),
                     r[0]->d[3] + 50.0 * cos(30.0 * 3.14159265358979323846 / 180.0), 0);
        ck(d->ndrawn == before + 1, c ? "傾き 30, the drag the other way"
                                      : "傾き 30 on its own: one line");
        if (d->ndrawn == before + 1) {
            const jw_obj *a = &d->obj[before];
            ok = near(a->d[0], r[0]->d[0]) && near(a->d[1], r[0]->d[1])
                 && near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3]);
            if (!ok)
                printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
                       "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                       a->d[0], a->d[1], a->d[2], a->d[3],
                       r[0]->d[0], r[0]->d[1], r[0]->d[2], r[0]->d[3]);
            ck(ok, "  the drag projected onto 30 degrees, as the original drew");
        }
        type_box(1411, "");
        jw_free(&ref);
    }
}

/* 線: the marks on the far end, and 寸法 with 水平・垂直 or １５度毎. */
static void line_more(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[4];
    int before, i, ok;

    /* ＜─── with the button pressed twice: legs on both ends, the ones
       at the start first */
    b = slurp("decomp/res/sen_1837x2.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  no decomp/res/sen_1837x2.jww\n");
        fails++;
        free(b);
    } else {
        free(b);
        if (!tail_of(&ref, JW_SEN, r, 4)) {
            printf("BAD  sen_1837x2.jww has no four legs in it\n");
            fails++;
        } else {
            /* the line itself comes before the four: find it by its start */
            const jw_obj *all[4096];
            int m = of_class(&ref, JW_SEN, all, 4096), j, at = -1;
            for (j = m - 5; j >= 0; j--)
                if (near(all[j]->d[0], r[0]->d[0])
                    && near(all[j]->d[1], r[0]->d[1])) {
                    at = j;
                    break;
                }
            if (at < 0) {
                printf("BAD  sen_1837x2.jww has no line under its legs\n");
                fails++;
            } else {
                const jw_obj *line = all[at];
                d = fresh();
                jw_cmd_set(JW_CMD_TEN);
                jw_cmd_set(JW_CMD_SEN);
                type_box(1411, "");
                type_box(1412, "");
                if (jw_cmd_bar_check(1349) <= 0)
                    jw_cmd_bar(d, 1349);
                jw_cmd_bar(d, 1837);
                jw_cmd_bar(d, 1837);
                before = d->ndrawn;
                jw_cmd_point(d, app_view(), line->d[0], line->d[1], 0);
                jw_cmd_point(d, app_view(), line->d[2], line->d[3], 0);
                ck(d->ndrawn == before + 5,
                   "＜─── with the button twice: the line and four legs");
                ok = 1;
                if (d->ndrawn == before + 5)
                    for (i = 0; i < 4; i++) {
                        const jw_obj *a = &d->obj[before + 1 + i];
                        if (!(near(a->d[0], r[i]->d[0])
                              && near(a->d[1], r[i]->d[1])
                              && near(a->d[2], r[i]->d[2])
                              && near(a->d[3], r[i]->d[3]))) {
                            ok = 0;
                            printf("     %d ours %.4f,%.4f -> %.4f,%.4f, the original's %.4f,%.4f -> %.4f,%.4f\n",
                                   i, a->d[0], a->d[1], a->d[2], a->d[3],
                                   r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
                        }
                    }
                ck(ok, "  both ends, the start's pair written first");
                jw_cmd_bar(d, 1837);    /* back to the start */
                jw_cmd_bar(d, 1349);
            }
        }
        jw_free(&ref);
    }

    /* 寸法 with 水平・垂直: straight up the axis the drag leans to */
    b = slurp("decomp/res/sen_sunhv_v.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  no decomp/res/sen_sunhv_v.jww\n");
        fails++;
        free(b);
        return;
    }
    free(b);
    if (!tail_of(&ref, JW_SEN, r, 1)) {
        printf("BAD  sen_sunhv_v.jww has no line in it\n");
        fails++;
        jw_free(&ref);
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    type_box(1411, "");
    type_box(1412, "50000");
    if (jw_cmd_bar_check(1333) <= 0)
        app_key(32);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    /* the drag: a little to the right and a long way up, so the upright
       axis is the one it leans to */
    jw_cmd_point(d, app_view(), r[0]->d[0] + 17.0, r[0]->d[1] + 216.0, 0);
    ck(d->ndrawn == before + 1, "寸法 with 水平・垂直: one line");
    if (d->ndrawn == before + 1) {
        const jw_obj *a = &d->obj[before];
        ok = near(a->d[0], r[0]->d[0]) && near(a->d[1], r[0]->d[1])
             && near(a->d[2], r[0]->d[2]) && near(a->d[3], r[0]->d[3]);
        if (!ok)
            printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
                   "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   a->d[0], a->d[1], a->d[2], a->d[3],
                   r[0]->d[0], r[0]->d[1], r[0]->d[2], r[0]->d[3]);
        ck(ok, "  250 straight up, where the original drew it");
    }
    type_box(1412, "");
    jw_free(&ref);
}

/* 矩形 の仮線: the frame, and the diagonal across it with (対角線).
   Caught on the original's own screen with the second corner under the
   cursor -- ソリッド hangs four sides off the mouse and nothing inside. */
static void rect_band(void)
{
    jw_drawing *d = fresh();
    jw_obj t[16];
    int n, i, solid;

    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1411, "");
    type_box(1413, "");
    type_box(1417, "");
    if (jw_cmd_bar_check(1334) > 0)
        jw_cmd_bar(d, 1334);
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_track(80.0, 50.0);
    n = jw_cmd_pending(d, t, 16);
    solid = 0;
    for (i = 0; i < n; i++)
        if (t[i].cls == JW_SOLID)
            solid = 1;
    ck(n == 4 && !solid, "矩形の仮線は四辺");
    jw_cmd_bar(d, 1334);                /* ソリッド */
    n = jw_cmd_pending(d, t, 16);
    solid = 0;
    for (i = 0; i < n; i++)
        if (t[i].cls == JW_SOLID)
            solid = 1;
    ck(n == 4 && !solid, "ソリッドでも仮線は四辺だけで塗らない");
    jw_cmd_bar(d, 1335);                /* (対角線) */
    n = jw_cmd_pending(d, t, 16);
    ck(n == 5, "(対角線) で対角線が一本加わる");
    if (n == 5)
        ck(near(t[4].d[0], 0.0) && near(t[4].d[1], 0.0)
           && near(t[4].d[2], 80.0) && near(t[4].d[3], 50.0),
           "  一点目からカーソルまで");
    jw_cmd_bar(d, 1335);
    jw_cmd_bar(d, 1334);
    jw_cmd_escape();
}

/* 複線 の 両側複線 (1068)・留線付両側複線 (1069)・連続 (1064).
   Each of the three was asked of the original with one line picked and 1000
   in the spacing on a 1/100 sheet. */
static void para_buttons(void)
{
    static const struct { const char *file; int id; int n; const char *what; }
    C[3] = {
        { "decomp/res/fuku_both.jww", 1068, 3, "両側複線" },
        { "decomp/res/fuku_cap.jww",  1069, 5, "留線付両側複線" },
        { "decomp/res/fuku_cont.jww", 1064, 3, "連続" }
    };
    int c;

    for (c = 0; c < 3; c++) {
        unsigned char *b;
        long n;
        jw_drawing ref, *d;
        const jw_obj *r[5];
        int i, ok = 1, before;

        b = slurp(C[c].file, &n);
        if (!b || !jw_parse(&ref, b, n)) {
            printf("BAD  no %s\n", C[c].file);
            fails++;
            free(b);
            continue;
        }
        free(b);
        if (!tail_of(&ref, JW_SEN, r, C[c].n)) {
            printf("BAD  %s has no %d lines in it\n", C[c].file, C[c].n);
            fails++;
            continue;
        }
        /* the answers were drawn on a new sheet, which is 1/100 -- Test5's
           write group is 1/200 and 1000 would come out five */
        app_new();
        d = (jw_drawing *)app_drawing();
        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_set(JW_CMD_SEN);
        if (jw_cmd_bar_check(1333) > 0)
            app_key(32);
        before = d->ndrawn;
        jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
        jw_cmd_point(d, app_view(), r[0]->d[2], r[0]->d[3], 0);
        jw_cmd_set(JW_CMD_FUKUSEN);
        jw_cmd_point(d, app_view(), (r[0]->d[0] + r[0]->d[2]) / 2.0,
                     (r[0]->d[1] + r[0]->d[3]) / 2.0, 0);
        type_box(1411, "1000");
        if (C[c].id == 1064)            /* 連続 carries on from a copy */
            jw_cmd_point(d, app_view(), (r[0]->d[0] + r[0]->d[2]) / 2.0,
                         r[0]->d[1] + 5.0, 0);
        jw_cmd_bar(d, C[c].id);
        ck(d->ndrawn - before == C[c].n, C[c].what);
        if (d->ndrawn - before == C[c].n) {
            for (i = 0; i < C[c].n; i++) {
                const jw_obj *a = &d->obj[before + i];
                if (!(near(a->d[0], r[i]->d[0]) && near(a->d[1], r[i]->d[1])
                      && near(a->d[2], r[i]->d[2])
                      && near(a->d[3], r[i]->d[3]))) {
                    ok = 0;
                    printf("     %d ours %.3f,%.3f -> %.3f,%.3f, the original's %.3f,%.3f -> %.3f,%.3f\n",
                           i, a->d[0], a->d[1], a->d[2], a->d[3],
                           r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
                }
            }
            ck(ok, "  the original's own lines, in its own order");
        }
        type_box(1411, "");
        jw_free(&ref);
    }
}

/* 寸法 の ０º/９０º (1059): the dimension stands upright and measures
   the height between the two points instead of the distance along them. */
static void dim_upright(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[2];
    const jw_obj *t[2];
    const jw_obj *all[4096];
    int m, i, before, ok = 1, at = -1;

    b = slurp("decomp/res/sun2_0_90.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  no decomp/res/sun2_0_90.jww\n");
        fails++;
        free(b);
        return;
    }
    free(b);
    /* the slanted line the original measured, and the dimension it drew */
    m = of_class(&ref, JW_SEN, all, 4096);
    for (i = 0; i < m; i++)
        /* the plain line is the one without the dimension flag on it */
        if (!(all[i]->flags & JW_SUN_LINE_FLAGS)) {
            at = i;
            break;
        }
    if (at < 0 || !tail_of(&ref, JW_SEN, r, 2) || !tail_of(&ref, JW_TEN, t, 2)) {
        printf("BAD  sun2_0_90.jww is not the drawing it was\n");
        fails++;
        jw_free(&ref);
        return;
    }
    d = fresh();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);
    jw_cmd_point(d, app_view(), all[at]->d[0], all[at]->d[1], 0);
    jw_cmd_point(d, app_view(), all[at]->d[2], all[at]->d[3], 0);
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_SUNPO);
    type_box(1411, "0");
    jw_cmd_bar(d, 1059);                /* ０º/９０º */
    /* both clicks on the line the dimension stands on, then the two ends
       read off the slanted line */
    jw_cmd_point(d, app_view(), t[0]->d[0], all[at]->d[1] - 30.0, 0);
    jw_cmd_point(d, app_view(), t[0]->d[0], all[at]->d[1] - 20.0, 0);
    jw_cmd_point(d, app_view(), all[at]->d[0], all[at]->d[1], 1);
    jw_cmd_point(d, app_view(), all[at]->d[2], all[at]->d[3], 1);
    ck(d->ndrawn > before, "０º/９０º: 寸法が出る");
    if (d->ndrawn > before) {
        const jw_obj *line = &d->obj[before];
        ok = near(line->d[0], line->d[2])       /* upright */
             && near(line->d[1], r[1]->d[1])
             && near(line->d[3], r[1]->d[3]);
        if (!ok)
            printf("     ours %.4f,%.4f -> %.4f,%.4f\n"
                   "     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   line->d[0], line->d[1], line->d[2], line->d[3],
                   r[1]->d[0], r[1]->d[1], r[1]->d[2], r[1]->d[3]);
        ck(ok, "  立っていて、二点の高さを測る");
    }
    jw_cmd_bar(d, 1059);                /* twice puts it back */
    jw_free(&ref);
}

/* 寸法 の 累進 (1070): a 点 on the base end, an arrowhead on the far one,
   and the value stood on end beside it. */
static void dim_progressive(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *all[4096];
    const jw_obj *plain = 0, *r[7];
    int m, i, k = 0, before, ok = 1;

    b = slurp("decomp/res/sun2_rui.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  no decomp/res/sun2_rui.jww\n");
        fails++;
        free(b);
        return;
    }
    free(b);
    /* the plain line, then the seven the dimension is made of, in the
       order the original wrote them */
    m = ref.ndrawn;
    for (i = 0; i < m; i++) {
        const jw_obj *o = &ref.obj[i];
        if (o->cls == JW_MOJI && !(o->flags & JW_SUN_TEXT_FLAGS))
            continue;                   /* the settings texts at the end */
        if (!plain && o->cls == JW_SEN && !(o->flags & JW_SUN_LINE_FLAGS)) {
            plain = o;
            continue;
        }
        if (plain && k < 7)
            r[k++] = o;
    }
    if (!plain || k != 7) {
        printf("BAD  sun2_rui.jww is not the drawing it was (%d)\n", k);
        fails++;
        jw_free(&ref);
        return;
    }
    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);
    jw_cmd_point(d, app_view(), plain->d[0], plain->d[1], 0);
    jw_cmd_point(d, app_view(), plain->d[2], plain->d[3], 0);
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_SUNPO);
    type_box(1411, "0");
    jw_cmd_bar(d, 1070);                /* 累進 */
    /* the two clicks: where the extensions end, then the dimension line */
    jw_cmd_point(d, app_view(), 0.0, r[4]->d[3], 0);
    jw_cmd_point(d, app_view(), 0.0, r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), plain->d[0], plain->d[1], 1);
    jw_cmd_point(d, app_view(), plain->d[2], plain->d[3], 1);
    ck(d->ndrawn - before == 7, "累進: 寸法線・点・矢羽根二本・引出線二本・値");
    if (d->ndrawn - before == 7) {
        for (i = 0; i < 7; i++) {
            const jw_obj *a = &d->obj[before + i];
            int j, same = a->cls == r[i]->cls && a->ltype == r[i]->ltype
                          && a->flags == r[i]->flags;
            for (j = 0; j < 4; j++)
                if (!near(a->d[j], r[i]->d[j]))
                    same = 0;
            if (!same) {
                ok = 0;
                printf("     %d ours cls=%d t=%d f=%#x %.4f,%.4f -> %.4f,%.4f\n"
                       "       the original's cls=%d t=%d f=%#x %.4f,%.4f -> %.4f,%.4f\n",
                       i, a->cls, a->ltype, a->flags,
                       a->d[0], a->d[1], a->d[2], a->d[3],
                       r[i]->cls, r[i]->ltype, r[i]->flags,
                       r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
            }
        }
        ck(ok, "  原典と同じ順で同じ場所に");
    }
    jw_cmd_bar(d, 1070);
    jw_free(&ref);
}

/* A rectangle with its width and its height on it -- what a dimension is
   actually for.  The original was given a 10000 x 6000 rectangle, then the
   width under its bottom edge (傾き 0) and the height beside its left one
   (０º/９０º), the corners read with the right button both times. */
static void dim_rectangle(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[16];
    int m = 0, i, before, ok = 1;

    b = slurp("decomp/res/sun6_rect.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  no decomp/res/sun6_rect.jww\n");
        fails++;
        free(b);
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn && m < 16; i++) {
        const jw_obj *o = &ref.obj[i];
        if (o->cls == JW_MOJI && !(o->flags & JW_SUN_TEXT_FLAGS))
            continue;                   /* the settings texts */
        r[m++] = o;
    }
    if (m != 14) {
        printf("BAD  sun6_rect.jww holds %d elements, not 14\n", m);
        fails++;
        jw_free(&ref);
        return;
    }
    app_new();
    d = (jw_drawing *)app_drawing();
    before = d->ndrawn;
    /* the rectangle, from its own corner and 10000 x 6000 */
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(JW_CMD_KUKEI);
    type_box(1411, "");
    type_box(1417, "");
    type_box(1413, "10000,6000");
    jw_cmd_point(d, app_view(), r[0]->d[0], r[0]->d[1], 0);
    jw_cmd_point(d, app_view(), r[0]->d[0] + 1.0, r[0]->d[1] - 1.0, 0);
    type_box(1413, "");
    /* the width: the two clicks that place the line, then the bottom corners */
    jw_cmd_set(JW_CMD_SUNPO);
    type_box(1411, "0");
    /* both clicks were at the same place across the drawing -- the x the
       upright dimension later stands at, which is r[10]'s */
    jw_cmd_point(d, app_view(), r[10]->d[0], r[7]->d[3], 0);  /* extensions end */
    jw_cmd_point(d, app_view(), r[10]->d[0], r[4]->d[1], 0);  /* the line */
    jw_cmd_point(d, app_view(), r[2]->d[2], r[2]->d[3], 1);
    jw_cmd_point(d, app_view(), r[2]->d[0], r[2]->d[1], 1);
    /* and the height, upright, off the same pair of clicks */
    jw_cmd_bar(d, 1059);
    jw_cmd_point(d, app_view(), r[3]->d[0], r[3]->d[1], 1);
    jw_cmd_point(d, app_view(), r[3]->d[2], r[3]->d[3], 1);
    ck(d->ndrawn - before == 14,
       "四角に幅と高さの寸法が付く");
    if (d->ndrawn - before == 14) {
        for (i = 0; i < 14; i++) {
            const jw_obj *a = &d->obj[before + i];
            int j, same = a->cls == r[i]->cls && a->flags == r[i]->flags;
            for (j = 0; j < 4; j++)
                if (!near(a->d[j], r[i]->d[j]))
                    same = 0;
            if (!same) {
                ok = 0;
                printf("     %2d ours cls=%d f=%#x %.4f,%.4f -> %.4f,%.4f\n"
                       "        the original's cls=%d f=%#x %.4f,%.4f -> %.4f,%.4f\n",
                       i, a->cls, a->flags, a->d[0], a->d[1], a->d[2], a->d[3],
                       r[i]->cls, r[i]->flags,
                       r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
            }
        }
        ck(ok, "  十四要素すべて原典と同じ");
    }
    jw_cmd_bar(d, 1059);
    jw_free(&ref);
}

int main(void)
{
    app_resize(1264, 741);
    rect_solid_more();
    line_marks();
    line_slope();
    line_more();
    rect_band();
    para_buttons();
    dim_upright();
    dim_progressive();
    dim_rectangle();
    rect_rings();
    space_turns_hv();
    escape_drops_the_point();
    dim_radius();
    offset_typed();
    line_value();
    circle_half();
    circle_3pt();
    dim_arrows();
    text_vertical();
    dim_decimals();
    line_15();
    rect_solid();
    circle_rings();
    circle_ellipse();
    circle_radius();
    circle_arc();
    rect_tilt();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
