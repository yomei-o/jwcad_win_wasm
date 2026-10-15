/* 面取 の 丸面 (1691) に円弧が入る組 —— 線と円弧・円弧どうし。
 *
 *   tests/mentoriarc_test.exe
 *
 * 原典は CZukeiCorner（+0xa03c）の FUN_0063aa60 が丸面のときだけ円弧を拾い、
 * FUN_00634b70 → FUN_006377b0 が丸を付ける。どれも逆コンパイルと命令の読み
 * で、原典では押していません（src/cmd.c の mentori_arc の注）。答えはその読み
 * どおりの作図を手で計算したもの。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

static int fails;
static const double PI_ = 3.141592653589793;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near_(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

static double wscale(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

static double ang(double y, double x)
{
    double a = atan2(y, x);

    return a < 0.0 ? a + 2 * PI_ : a;
}

static jw_obj *arc(jw_drawing *d, double cx, double cy, double r, double st, double sw)
{
    jw_obj *o = jw_add(d, JW_ENKO);

    o->d[0] = cx; o->d[1] = cy; o->d[2] = r; o->d[3] = st; o->d[4] = sw;
    o->d[5] = 0; o->d[6] = 1;
    o->n = fabs(sw) >= 2 * PI_ - 1e-9;
    return o;
}

static jw_drawing *setup(int mode, const char *size)
{
    jw_drawing *d;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    jw_cmd_set(JW_CMD_MENTORI);
    jw_cmd_bar(d, mode);
    jw_cmd_box_put(1411, size);
    return d;
}

/* 線 (0,0)-(100,0) と 円弧 中心 (100,20) 半径 30（90〜270 度）。線を (20,0)、
   弧を 150 度で指す。r = 5（縮尺で割る）:
     弧の指示点は線の上 → 線を +r へ、線の指示点は円の外 → 円は 30 + r
     C = (100 − √((30+r)² − (20−r)²), r)、線は C の足まで（交点 x≈77.6 が
     指示点より終点の側なので終点を）、弧は接点から 90 度の端まで時計回り、
     丸は 線の接点 (270 度) から弧の接点へ、交点を通る反時計回り */
static void line_arc(void)
{
    jw_drawing *d = setup(1691, "5");
    jw_obj *o;
    double r, cx, cy, tx, ty, n0;
    const jw_obj *l, *e, *f;

    o = jw_add(d, JW_SEN);
    o->d[0] = 0; o->d[1] = 0; o->d[2] = 100; o->d[3] = 0;
    arc(d, 100, 20, 30, PI_ / 2, PI_);
    app_fit();
    jw_cmd_set(JW_CMD_MENTORI);
    jw_cmd_bar(d, 1691);
    jw_cmd_box_put(1411, "5");
    r = 5.0 / wscale(d);
    n0 = d->ndrawn;
    jw_cmd_point(d, app_view(), 20, 0, 0);
    jw_cmd_point(d, app_view(), 100 + 30 * cos(5 * PI_ / 6), 20 + 30 * sin(5 * PI_ / 6), 0);
    ck(d->ndrawn == n0 + 1, "line+arc: 丸が一つ増える");
    if (d->ndrawn != n0 + 1)
        return;
    l = &d->obj[d->ndrawn - 3];
    e = &d->obj[d->ndrawn - 2];
    f = &d->obj[d->ndrawn - 1];
    cx = 100 - sqrt((30 + r) * (30 + r) - (20 - r) * (20 - r));
    cy = r;
    tx = 100 + (cx - 100) * 30 / (30 + r);
    ty = 20 + (cy - 20) * 30 / (30 + r);
    ck(l->cls == JW_SEN && e->cls == JW_ENKO && f->cls == JW_ENKO, "line+arc: 線・弧・丸の順で末尾に");
    ck(near_(l->d[0], 0) && near_(l->d[1], 0) && near_(l->d[2], cx) && near_(l->d[3], 0),
       "line+arc: 線は丸の中心の足まで（始点の側が残る）");
    ck(near_(e->d[3], ang(cy - 20, cx - 100)) && near_(e->d[3] + e->d[4], PI_ / 2),
       "line+arc: 弧は接点から 90 度の端まで");
    ck(e->d[4] < 0, "line+arc: 弧は時計回り（接点が始まり）");
    ck(near_(f->d[0], cx) && near_(f->d[1], cy) && near_(f->d[2], r), "line+arc: 丸の中心と半径");
    ck(near_(f->d[3], 3 * PI_ / 2)
       && near_(f->d[4], 2 * PI_ - (3 * PI_ / 2 - ang(ty - cy, tx - cx))),
       "line+arc: 丸は線の接点から弧の接点へ");
    app_command(JW_CMD_UNDO);
    ck(d->ndrawn == n0 && d->obj[0].cls == JW_SEN && near_(d->obj[0].d[2], 100)
       && near_(d->obj[1].d[4], PI_), "line+arc: 戻る で元どおり");
}

/* 円弧どうし: A 中心 (0,0) 半径 50（-90〜90 度）、B 中心 (80,0) 半径 50
   （90〜270 度）。交点は (40,±30)。A を 20 度、B を 160 度で指す。どちらの
   指示点も相手の円の内なので 50 − r どうしの交点が丸の中心 */
static void arc_arc(void)
{
    jw_drawing *d = setup(1691, "5");
    double r, cy, ta, tb, n0;
    const jw_obj *a, *b, *f;

    arc(d, 0, 0, 50, -PI_ / 2, PI_);
    arc(d, 80, 0, 50, PI_ / 2, PI_);
    app_fit();
    jw_cmd_set(JW_CMD_MENTORI);
    jw_cmd_bar(d, 1691);
    jw_cmd_box_put(1411, "5");
    r = 5.0 / wscale(d);
    n0 = d->ndrawn;
    jw_cmd_point(d, app_view(), 50 * cos(PI_ / 9), 50 * sin(PI_ / 9), 0);
    jw_cmd_point(d, app_view(), 80 + 50 * cos(8 * PI_ / 9), 50 * sin(8 * PI_ / 9), 0);
    ck(d->ndrawn == n0 + 1, "arc+arc: 丸が一つ増える");
    if (d->ndrawn != n0 + 1)
        return;
    a = &d->obj[d->ndrawn - 3];
    b = &d->obj[d->ndrawn - 2];
    f = &d->obj[d->ndrawn - 1];
    cy = sqrt((50 - r) * (50 - r) - 40 * 40);
    ta = ang(cy, 40);
    tb = ang(cy, -40);
    ck(near_(a->d[0], 0) && near_(b->d[0], 80), "arc+arc: 一つ目・二つ目の順");
    ck(near_(a->d[3], ta) && near_(a->d[3] + a->d[4], -PI_ / 2) && a->d[4] < 0,
       "arc+arc: 一つ目は接点から時計回りに -90 度の端まで");
    ck(near_(b->d[3], tb) && near_(b->d[3] + b->d[4], 3 * PI_ / 2) && b->d[4] > 0,
       "arc+arc: 二つ目は接点から反時計回りに 270 度の端まで");
    ck(near_(f->d[0], 40) && near_(f->d[1], cy) && near_(f->d[2], r)
       && near_(f->d[3], ta) && near_(f->d[4], tb - ta),
       "arc+arc: 丸は一つ目の接点から交点の側を通って二つ目の接点へ");
}

/* 断るもの: 丸面でないときの円弧（札 0x14de）、全円（0x1458）、楕円（0x145e） */
static void refuse(void)
{
    jw_drawing *d = setup(1689, "5");
    jw_obj *o;
    int n0;

    o = jw_add(d, JW_SEN);
    o->d[0] = 0; o->d[1] = 0; o->d[2] = 100; o->d[3] = 0;
    arc(d, 100, 20, 30, PI_ / 2, PI_);
    arc(d, -100, 20, 30, 0, 2 * PI_);
    o = arc(d, 0, 200, 30, 0, PI_);
    o->d[6] = 0.5;
    app_fit();
    jw_cmd_set(JW_CMD_MENTORI);
    jw_cmd_bar(d, 1689);
    jw_cmd_box_put(1411, "5");
    n0 = d->ndrawn;
    jw_cmd_notice_clear();
    jw_cmd_point(d, app_view(), 70, 20, 0);
    ck(jw_cmd_notice_id() == 5342 && !jw_cmd_midway(), "refuse: 辺寸法では円弧は「直線ではありません。」");
    jw_cmd_bar(d, 1691);
    jw_cmd_notice_clear();
    jw_cmd_point(d, app_view(), -70, 20, 0);
    ck(jw_cmd_notice_id() == 5208 && !jw_cmd_midway(), "refuse: 全円は「円です」");
    jw_cmd_notice_clear();
    jw_cmd_point(d, app_view(), 30, 200, 0);
    ck(jw_cmd_notice_id() == 5214 && !jw_cmd_midway(), "refuse: 楕円は「楕円は計算できません。」");
    /* 線を拾ってから全円: 断って、線は拾ったまま */
    jw_cmd_point(d, app_view(), 20, 0, 0);
    jw_cmd_notice_clear();
    jw_cmd_point(d, app_view(), -70, 20, 0);
    ck(jw_cmd_notice_id() == 5208 && jw_cmd_midway() && d->ndrawn == n0,
       "refuse: 二つ目の全円は断って、一つ目は拾ったまま");
}

int main(void)
{
    line_arc();
    arc_arc();
    refuse();
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
