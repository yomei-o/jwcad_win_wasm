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

int main(void)
{
    app_resize(1264, 741);
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
