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

static int near6(double a, double b)
{
    return fabs(a - b) < 1e-6;
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
    /* 終点のあとは同じ基準線で始点待ち（原典は state 2 へ）。そこで読めない
       所の (R) は何もしない */
    ck(jw_cmd_midway() && strcmp(jw_cmd_prompt(), JW_STR_5401) == 0,
       "  終点のあとは同じ基準線で始点待ち");
    before = d->ndrawn;
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
    ck(jw_cmd_midway() && strcmp(jw_cmd_prompt(), JW_STR_5401) == 0,
       "  終点のあとは今の基準線で始点待ち");
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

/* 留線出 (1413) が空のときの伸び: 原典で測った（decomp/res/nisen_tome50.jww・
   nisen_tome100.jww。縮尺 1/50 と 1/100 の同じ 2 線）。50 ÷ 縮尺 図寸mm */
static void tome_empty(const char *base, const char *ans, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *cap = 0;
    int i, k = 0, before;
    const double r = 400.0 / 244.897959184;     /* 画素 / mm（原典のとき） */

    printf("留線出が空のときの伸び（%s）:\n", what);
    b = slurp(ans, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s\n", ans);
        fails++;
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN && ++k == 3)
            cap = &ref.obj[i];
    if (!cap) {
        printf("BAD  %s has no cap\n", ans);
        fails++;
        return;
    }
    app_resize(1264, 741);
    b = slurp(base, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open %s\n", base);
        fails++;
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    add_line(d, -155.510204082, 26.326530612, 89.387755102, -96.122448980);
    add_line(d, -155.510204082, -96.122448980, 89.387755102, 26.326530612);
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100,300");
    jw_cmd_bar(d, 1323);
    /* 原典の三つの押し (400,350)・(600,450)・(500,420) の紙の位置 */
    jw_cmd_point(d, app_view(), -155.510204082 + 100.0 / r, -96.122448980 + 150.0 / r, 0);
    jw_cmd_point(d, app_view(), -155.510204082 + 300.0 / r, -96.122448980 + 50.0 / r, 0);
    jw_cmd_point(d, app_view(), -155.510204082 + 200.0 / r, -96.122448980 + 80.0 / r, 0);
    ck(d->ndrawn == before + 3, "  蓋と二本");
    if (d->ndrawn == before + 3) {
        const jw_obj *o = &d->obj[before];

        ck((near6(o->d[0], cap->d[0]) && near6(o->d[1], cap->d[1]) && near6(o->d[2], cap->d[2])
            && near6(o->d[3], cap->d[3]))
           || (near6(o->d[0], cap->d[2]) && near6(o->d[1], cap->d[3])
               && near6(o->d[2], cap->d[0]) && near6(o->d[3], cap->d[1])),
           "  蓋が 原典と同じ所");
    }
    jw_cmd_set(JW_CMD_NISEN);
}

/* ---- 終点のあとの続き・角の組・指示線包絡 (RR) --------------------------
 * CZukei2Sen の逆コンパイルの読み（src/cmd.c の nisen・nisen_rr・nisen_env の
 * 注）。原典では押していない。 */
static jw_drawing *empty(void)
{
    app_resize(1264, 741);
    app_new();
    return (jw_drawing *)app_drawing();
}

/* from 以降に (a,b)-(c,e) の線（向きは問わない）がいくつあるか */
static int has_line(const jw_drawing *d, int from, double a, double b,
                    double c, double e)
{
    int i, n = 0;

    for (i = from; i < d->ndrawn; i++) {
        const double *q = d->obj[i].d;

        if (d->obj[i].cls != JW_SEN)
            continue;
        if ((near(q[0], a) && near(q[1], b) && near(q[2], c) && near(q[3], e))
            || (near(q[0], c) && near(q[1], e) && near(q[2], a) && near(q[3], b)))
            n++;
    }
    return n;
}

static void undo_press(jw_drawing *d)
{
    /* app.c の 戻る と同じ: 途中なら命令に、0 なら図面の 戻る */
    if (jw_cmd_midway() && jw_cmd_back(d))
        return;
    jw_cmd_undo(d);
}

static void cont_and_back(void)
{
    jw_drawing *d = empty();
    int before;
    double g;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);
    app_fit();
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100");
    g = 100.0 / wscale(d);
    printf("終点のあとの続き（state 2 へ）と 戻る:\n");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -40.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -20.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 10.0, 0.0, 0);   /* 同じ基準線の始点 */
    jw_cmd_point(d, app_view(), 30.0, 0.0, 0);
    ck(d->ndrawn == before + 4, "  基準線を拾い直さずに二組目");
    ck(has_line(d, before, 10, -g, 30, -g) == 1 && has_line(d, before, 10, g, 30, g) == 1,
       "  二組目は 10〜30");
    undo_press(d);
    ck(d->ndrawn == before + 2 && strcmp(jw_cmd_prompt(), JW_STR_5402) == 0,
       "  戻る で二組目が消えて その終点待ち");
    jw_cmd_point(d, app_view(), 40.0, 0.0, 0);
    ck(d->ndrawn == before + 4 && has_line(d, before, 10, g, 40, g) == 1,
       "  始点 10 のまま引き直せる");
    jw_cmd_set(JW_CMD_NISEN);
}

/* 角の続きの座標系: 前の区間の始まりが今の基準線の左なら逆向きに見る。
   隔たりの違う「100,300」で、縦の線が上向き（逆向きに見る）と下向き */
static void corner_frame(int rev)
{
    jw_drawing *d = empty();
    int before;
    double g, h;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);
    if (rev)
        add_line(d, 40, 50, 40, -50);
    else
        add_line(d, 40, -50, 40, 50);
    app_fit();
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100,300");
    g = 100.0 / wscale(d);
    h = 300.0 / wscale(d);
    printf("角の座標系と組（100,300、縦の線%s）:\n", rev ? "は下向き" : "は上向き");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -40.0, 0.0, 0);
    jw_cmd_point_ll(d, app_view(), 40.0, 30.0);
    jw_cmd_point(d, app_view(), 40.0, 45.0, 0);
    ck(d->ndrawn == before + 4, "  四本");
    /* 一本目は右（−a）が y=−g、左が y=+h。縦の区間は基準線の向きに関わらず
       前の始まり (−40,0) が右に来る向き（下向き）に見るので、−a は x=40−g */
    ck(has_line(d, before, -40, -g, 40 + h, -g) == 1
       && has_line(d, before, -40, h, 40 - g, h) == 1,
       "  前の二本は 40+h と 40−g まで");
    ck(has_line(d, before, 40 + h, -g, 40 + h, 45) == 1
       && has_line(d, before, 40 - g, h, 40 - g, 45) == 1,
       "  今の二本は x=40+h と x=40−g、交点から");
    jw_cmd_set(JW_CMD_NISEN);
}

static void rr_start(int inside)
{
    jw_drawing *d = empty();
    int before;
    double g, hy;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);
    g = 100.0 / wscale(d);
    add_line(d, -30, -5 * g, -30, 5 * g);       /* 指示線 */
    add_line(d, 50, -6 * g, 50, 6 * g);         /* 画面の広さのため */
    app_fit();
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100");
    hy = inside ? 0.5 * g : 3 * g;
    printf("始点の 指示線包絡 (RR)、押した所が二本の%s:\n", inside ? "あいだ" : "外");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -30.0, hy, 1);
    jw_cmd_point(d, app_view(), -30.0, hy, 1);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5402) == 0 && d->ndrawn == before,
       "  (RR) で終点待ち、まだ何も書かない");
    jw_cmd_point(d, app_view(), 30.0, 0.0, 0);
    ck(has_line(d, 0, -30, -g, 30, -g) == 1 && has_line(d, 0, -30, g, 30, g) == 1,
       "  二本は指示線から");
    ck(!has_line(d, 0, -30, -5 * g, -30, 5 * g), "  指示線は消える");
    if (inside)
        ck(d->ndrawn == before + 2 && has_line(d, 0, -30, -g, -30, g) == 1
           && near(d->obj[before - 1].d[0], -30) && near(d->obj[before - 1].d[2], -30),
           "  あいだを押せば二本のあいだだけ残る（蓋になる）、残りが先");
    else
        ck(d->ndrawn == before + 3 && has_line(d, 0, -30, -5 * g, -30, -g) == 1
           && has_line(d, 0, -30, g, -30, 5 * g) == 1,
           "  外を押せば二本のあいだが抜ける");
    undo_press(d);
    ck(has_line(d, 0, -30, -5 * g, -30, 5 * g) == 1 && d->ndrawn == before,
       "  戻る で指示線も戻る");
    ck(strcmp(jw_cmd_prompt(), JW_STR_5402) == 0, "  終点待ちに戻る");
    jw_cmd_point(d, app_view(), 20.0, 0.0, 0);
    ck(has_line(d, 0, -30, -g, 20, -g) == 1 && !has_line(d, 0, -30, -5 * g, -30, 5 * g),
       "  指示線包絡は残っていて、引き直すとまた効く");
    jw_cmd_set(JW_CMD_NISEN);
}

static void rr_end(void)
{
    jw_drawing *d = empty();
    int before;
    double g;

    if (!d)
        return;
    add_line(d, -50, 0, 50, 0);
    g = 100.0 / wscale(d);
    add_line(d, 30, -5 * g, 30, 5 * g);         /* 終点の指示線 */
    add_line(d, -50, -6 * g, -50, 6 * g);
    app_fit();
    jw_cmd_set(JW_CMD_NISEN);
    type_box(1412, "100");
    printf("終点の 指示線包絡 (RR):\n");
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -20.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 30.0, 3 * g, 1);
    jw_cmd_point(d, app_view(), 30.0, 3 * g, 1);
    ck(d->ndrawn == before + 3, "  二本と指示線の残り二本（指示線は消える）");
    if (d->ndrawn == before + 3) {
        ck(has_line(d, before - 1, -20, -g, 30, -g) == 1
           && has_line(d, before - 1, -20, g, 30, g) == 1, "  二本は指示線まで");
        ck(has_line(d, before - 1, 30, -5 * g, 30, -g) == 1
           && has_line(d, before - 1, 30, g, 30, 5 * g) == 1,
           "  指示線は二本のあいだが抜ける");
        ck(near(d->obj[d->ndrawn - 1].d[0], 30) && near(d->obj[d->ndrawn - 3].d[0], 30) == 0,
           "  書く順は 二本・指示線の残り");
    }
    ck(strcmp(jw_cmd_prompt(), JW_STR_5401) == 0, "  同じ基準線で始点待ちへ");
    undo_press(d);
    ck(d->ndrawn == before && has_line(d, 0, 30, -5 * g, 30, 5 * g) == 1
       && strcmp(jw_cmd_prompt(), JW_STR_5402) == 0,
       "  戻る で二本が消え、指示線が戻って終点待ち");
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
    tome_empty("decomp/res/nisen_tome_base50.jww", "decomp/res/nisen_tome50.jww", "縮尺 1/50");
    tome_empty("decomp/res/new.jww", "decomp/res/nisen_tome100.jww", "縮尺 1/100");
    cont_and_back();
    corner_frame(0);
    corner_frame(1);
    rr_start(0);
    rr_start(1);
    rr_end();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
