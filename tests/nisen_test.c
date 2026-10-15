/* ２線 -- against the pairs the original drew.
 *
 *   tests/nisen_test.exe
 *
 * Two runs of the original are held up against: decomp/res/nisen.jww, where
 * the line to run along was drawn left to right and the two points were on
 * it, and decomp/res/nisen2.jww, where the same line was drawn right to left
 * and the points were above it.  Between them they say that the two sides
 * follow the line's own direction and not where it was clicked.
 *
 * Both were made with 間隔 2000,1000 on a 1/200 group, so the pair should
 * come out 10 mm one side and 5 mm the other.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

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

static int same_line(const jw_obj *a, const jw_obj *b)
{
    return (near(a->d[0], b->d[0]) && near(a->d[1], b->d[1])
            && near(a->d[2], b->d[2]) && near(a->d[3], b->d[3]))
        || (near(a->d[0], b->d[2]) && near(a->d[1], b->d[3])
            && near(a->d[2], b->d[0]) && near(a->d[3], b->d[1]));
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

/* one of the two runs: the file has the line that was drawn and the pair */
static void run(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[3] = { 0, 0, 0 };
    int i, k = 0, before;

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
        if (ref.obj[i].cls == JW_SEN) {
            r[0] = r[1];
            r[1] = r[2];
            r[2] = &ref.obj[i];
            k++;
        }
    if (k < 3) {
        printf("BAD  %s has no pair in it\n", path);
        fails++;
        return;
    }

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {   /* the line it ran along, drawn the way it was */
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = r[0]->d[0];
        o->d[1] = r[0]->d[1];
        o->d[2] = r[0]->d[2];
        o->d[3] = r[0]->d[3];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "2000,1000");
    {   /* pick it in the middle, then the two ends of the pair -- which are
           where the original's two lines start and stop */
        double mx = (r[0]->d[0] + r[0]->d[2]) / 2;
        double my = (r[0]->d[1] + r[0]->d[3]) / 2;
        jw_cmd_point(d, app_view(), mx, my, 0);
        jw_cmd_point(d, app_view(), r[1]->d[0], r[1]->d[1], 0);
        jw_cmd_point(d, app_view(), r[1]->d[2], r[1]->d[3], 0);
    }
    printf("%s\n", what);
    ck(d->ndrawn == before + 2, "  two lines come out");
    if (d->ndrawn == before + 2) {
        int ok = (same_line(&d->obj[before], r[1])
                  && same_line(&d->obj[before + 1], r[2]))
              || (same_line(&d->obj[before], r[2])
                  && same_line(&d->obj[before + 1], r[1]));
        if (!ok) {
            for (i = 0; i < 2; i++)
                printf("     ours %.4f,%.4f -> %.4f,%.4f\n",
                       d->obj[before + i].d[0], d->obj[before + i].d[1],
                       d->obj[before + i].d[2], d->obj[before + i].d[3]);
            printf("     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   r[1]->d[0], r[1]->d[1], r[1]->d[2], r[1]->d[3]);
            printf("     and            %.4f,%.4f -> %.4f,%.4f\n",
                   r[2]->d[0], r[2]->d[1], r[2]->d[2], r[2]->d[3]);
        }
        ck(ok, "  both where the original put them");
    }
    jw_free(&ref);
}

/* ---- (R)Read・基準線変更 (LL)・留線出 (1413) ---------------------------
 * 原典の答えは無く（原典では押していない）、CZukei2Sen の逆コンパイルの
 * 読み（src/cmd.c の nisen / nisen_ll の注）どおりかを見ます。 */
static jw_drawing *fresh(void)
{
    unsigned char *b;
    long n;
    jw_drawing *d;

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        free(b);
        return 0;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    return d;
}

static void add_line(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
}

static double wscale(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

/* (x,y) を端に持つ線があるか（from 以降の線の中で） */
static int has_end(const jw_drawing *d, int from, double x, double y)
{
    int i, n = 0;

    for (i = from; i < d->ndrawn; i++) {
        const double *q = d->obj[i].d;

        if (d->obj[i].cls != JW_SEN)
            continue;
        if ((near(q[0], x) && near(q[1], y)) || (near(q[2], x) && near(q[3], y)))
            n++;
    }
    return n;
}

static void read_points(void)
{
    jw_drawing *d = fresh();
    int before;
    double g;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);             /* 基準線 */
    add_line(d, -30, 10, -30, 20);          /* 読む点の (−30,10) */
    add_line(d, 30, 10, 30, 20);            /* と (30,10) */
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100");
    g = 100.0 / wscale(d);
    printf("(R)Read の始点・終点:\n");
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -30.3, 10.2, 1);
    ck(jw_cmd_midway() && strcmp(jw_cmd_prompt(), JW_STR_5402) == 0, "  (R) で始点が入って終点待ち");
    jw_cmd_point(d, app_view(), 29.8, 10.1, 1);
    ck(d->ndrawn == before + 2, "  二本出る");
    if (d->ndrawn == before + 2) {
        const double *p = d->obj[before].d, *q = d->obj[before + 1].d;

        ck(near(p[0], -30) && near(p[2], 30) && near(q[0], -30) && near(q[2], 30),
           "  読んだ点の射影 −30〜30 ちょうど");
        ck(near(fabs(p[1]), g) && near(fabs(q[1]), g) && near(p[1], -q[1]),
           "  基準線から ±間隔");
    }
    /* 読めない所の (R) は何もしない */
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 0.0, -12.0, 1);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5401) == 0, "  読めない (R) では始点待ちのまま");
    jw_cmd_set(JW_CMD_NISEN);
}

static void ll_start(void)
{
    jw_drawing *d = fresh();
    int before;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);
    add_line(d, -50, -20, 50, -20);
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100");
    printf("始点での 基準線変更 (LL):\n");
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);           /* 基準線 y=0 */
    jw_cmd_point_ll(d, app_view(), 10.0, -20.0);        /* y=−20 に差し替え */
    ck(strcmp(jw_cmd_prompt(), JW_STR_5401) == 0, "  始点待ちに戻る");
    jw_cmd_point(d, app_view(), -10.0, -18.0, 0);
    jw_cmd_point(d, app_view(), 10.0, -18.0, 0);
    ck(d->ndrawn == before + 2, "  二本出る");
    if (d->ndrawn == before + 2)
        ck(near((d->obj[before].d[1] + d->obj[before + 1].d[1]) / 2, -20.0),
           "  二本の真ん中が新しい基準線 y=−20");
    jw_cmd_set(JW_CMD_NISEN);
}

/* 終点での 基準線変更 (LL): 角を回って続く。縦の線は向きを両方試す */
static void ll_corner(int rev)
{
    jw_drawing *d = fresh();
    int before;
    double g;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);
    if (rev)
        add_line(d, 40, 50, 40, -50);
    else
        add_line(d, 40, -50, 40, 50);
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100");
    g = 100.0 / wscale(d);
    printf("終点での 基準線変更 (LL) で角を回る（縦の線%s）:\n", rev ? "は下向き" : "は上向き");
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -40.0, 0.0, 0);
    jw_cmd_point_ll(d, app_view(), 40.0, 30.0);
    ck(d->ndrawn == before, "  まだ何も書かない（前の二本は書き出し待ち）");
    ck(jw_cmd_midway() && strcmp(jw_cmd_prompt(), JW_STR_5402) == 0, "  終点待ちのまま");
    jw_cmd_point(d, app_view(), 40.0, 45.0, 0);
    ck(d->ndrawn == before + 4, "  前の二本と今の二本で四本");
    if (d->ndrawn == before + 4) {
        ck(has_end(d, before, 40 + g, -g) == 2 && has_end(d, before, 40 - g, g) == 2,
           "  外角 (40+g,−g) と内角 (40−g,g) で二本ずつ出会う");
        ck(has_end(d, before, -40, g) == 1 && has_end(d, before, -40, -g) == 1,
           "  始まりは x=−40");
        ck(has_end(d, before, 40 + g, 45) == 1 && has_end(d, before, 40 - g, 45) == 1,
           "  終わりは y=45");
    }
    ck(!jw_cmd_midway(), "  終点で区切り");
    jw_cmd_set(JW_CMD_NISEN);
}

static void tome_box(void)
{
    jw_drawing *d = fresh();
    int before;
    double s, e;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100");
    type_box(1413, "300");
    e = 300.0 / wscale(d);
    printf("留線出 (1413) と 留線 (1323) の一度きり:\n");
    jw_cmd_bar(d, 1323);
    ck(jw_cmd_bar_check(1323) > 0, "  留線が入る");
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -20.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 20.0, 0.0, 0);
    ck(d->ndrawn == before + 3, "  蓋と二本");
    if (d->ndrawn == before + 3) {
        s = d->obj[before + 1].d[0];
        ck(near(s, -20.0 - e), "  手前の端が 留線出 の分だけ外へ");
        ck(near(d->obj[before].d[0], s) && near(d->obj[before].d[2], s), "  蓋はそこに");
    }
    ck(jw_cmd_bar_check(1323) == 0, "  留線は一度で切れる");
    type_box(1413, "");
    jw_cmd_set(JW_CMD_NISEN);
}

int main(void)
{
    run("decomp/res/nisen.jww",
        "the line drawn left to right, the points on it:");
    run("decomp/res/nisen2.jww",
        "the same line drawn the other way, the points above it:");
    read_points();
    ll_start();
    ll_corner(0);
    ll_corner(1);
    tome_box();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
