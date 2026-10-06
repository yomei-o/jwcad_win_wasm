/* 点 (32785) のバー -- 仮点・仮点消去・全仮点消去・交点。
 *
 *   tests/tenbar_test.exe
 *
 * 原典の名は 仮実点（string 5251）。四つとも原典に訊いて決めました
 * （`tools/probe151.sh`。出てきた .jww は `decomp/res/ten_*.jww`）:
 *
 *   素のクリック      要素の kind が **0**。画面では 5 画素の十字
 *   1323 仮点         kind が **1**。画面では 11 画素の環
 *   1065 全仮点消去   消えるのは **kind=1 のほう** —— 混ぜて置いてから
 *                     押すと kind=0 だけ残りました
 *   1064 仮点消去     「【消去】する仮点を指示してください。」になり、
 *                     **その状態が続きます**（三つ置いて二回クリック
 *                     したら一つ残った）
 *   1066 交点         「線・円（Ａ）…」→「線・円【Ｂ】…」の二段。
 *                     二本の交点に kind=0 の点が落ちます。拾えなかった
 *                     クリックは**段を進めません**（CZukeiTen の slot 9
 *                     が 0 を返す枝）
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

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

/* バーの印を狙った状態にする。jw_cmd_bar は裏返すので、いまを見てから */
static void tick(jw_drawing *d, int id, int on)
{
    if ((jw_cmd_bar_check(id) > 0) != !!on)
        jw_cmd_bar(d, id);
}

static int nten(const jw_drawing *d, int kind)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_TEN && d->obj[i].n == kind)
            n++;
    return n;
}

int main(void)
{
    jw_drawing *d;
    int before;

    app_new();
    app_resize(1264, 741);
    d = (jw_drawing *)app_drawing();

    /* ------------------------------------------- 素の点は kind=0 ---- */
    jw_cmd_set(JW_CMD_TEN);
    tick(d, 1323, 0);
    jw_cmd_point(d, app_view(), -90.0, 0.0, 0);
    ck(d->ndrawn == 1 && d->obj[0].cls == JW_TEN && d->obj[0].n == 0,
       "素のクリックは kind=0 の点");

    /* --------------------------------------------- 1323 で kind=1 --- */
    tick(d, 1323, 1);
    jw_cmd_point(d, app_view(), -60.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -30.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    ck(nten(d, 1) == 3, "仮点を押すと kind=1 の点が三つ");
    ck(nten(d, 0) == 1, "さっきの実点はそのまま");

    /* ------------------------------------------- 1064 仮点消去 ------ */
    jw_cmd_bar(d, 1064);
    ck(jw_cmd_status(d) != 0, "仮点消去 の行が出る");
    jw_cmd_point(d, app_view(), -60.0, 0.0, 0);
    ck(nten(d, 1) == 2, "一つ消える");
    jw_cmd_point(d, app_view(), -30.0, 0.0, 0);
    ck(nten(d, 1) == 1, "押しっぱなしなので次も消える");
    jw_cmd_point(d, app_view(), -90.0, 0.0, 0);
    ck(nten(d, 0) == 1, "実点は仮点消去では消えない");

    /* ------------------------------------------- 1065 全仮点消去 ---- */
    /* 仮点消去 を抜けるには別の釦を押すか、命令を出入りする。
       ここは 1323 を押して置く側へ戻します。 */
    jw_cmd_bar(d, 1323);                /* 仮点消去 を抜けて 印は裏返る */
    tick(d, 1323, 1);
    ck(nten(d, 1) == 1, "消したあとは仮点が一つ");
    jw_cmd_point(d, app_view(), -60.0, 0.0, 0);
    jw_cmd_point(d, app_view(), -30.0, 0.0, 0);
    ck(nten(d, 1) == 3, "また置けるようになっている");
    jw_cmd_bar(d, 1065);
    ck(nten(d, 1) == 0 && nten(d, 0) == 1,
       "全仮点消去 で kind=1 だけ消える");

    /* ------------------------------------------------ 1066 交点 ----- */
    app_new();
    app_resize(1264, 741);
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *o = jw_add(d, JW_SEN);

        o->d[0] = -100.0;
        o->d[1] = -50.0;
        o->d[2] = 100.0;
        o->d[3] = 50.0;
        o = jw_add(d, JW_SEN);
        o->d[0] = -100.0;
        o->d[1] = 50.0;
        o->d[2] = 100.0;
        o->d[3] = -50.0;
    }
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_bar(d, 1066);
    jw_cmd_point(d, app_view(), 1000.0, 1000.0, 0);
    ck(d->ndrawn == before, "何も無いところを押しても段は進まない");
    jw_cmd_point(d, app_view(), -50.0, -25.0, 0);   /* 一本目の上 */
    ck(d->ndrawn == before, "（Ａ）を拾っただけでは何も落ちない");
    jw_cmd_point(d, app_view(), -50.0, 25.0, 0);    /* 二本目の上 */
    ck(d->ndrawn == before + 1, "【Ｂ】で点が落ちる");
    if (d->ndrawn == before + 1) {
        const jw_obj *o = &d->obj[before];

        ck(o->cls == JW_TEN && near(o->d[0], 0.0) && near(o->d[1], 0.0),
           "  二本の交わるところ");
        ck(o->n == 0, "  交点に落ちるのは実点 (kind=0)");
    }

    /* ------------------------------------------- 交点: 線×円 ------ */
    /* 原典の数そのもの（tools/probe155.sh、decomp/res/ten_lc_*.jww）:
       中心 (-33.061224, -34.897959) 半径 61.224490 の円と
       y = -53.265306 の線。交点は x が -91.465665 と 25.343216 で、
       **【Ｂ】を押した側に近いほう**が落ちます。 */
    {
        jw_obj *o;
        int n0;

        app_new();
        app_resize(1264, 741);
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_ENKO);
        o->d[0] = -33.061224;
        o->d[1] = -34.897959;
        o->d[2] = 61.224490;
        o->d[3] = 0.0;
        o->d[4] = 6.283185;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        o = jw_add(d, JW_SEN);
        o->d[0] = -155.510204;
        o->d[1] = -53.265306;
        o->d[2] = 89.387755;
        o->d[3] = -53.265306;
        app_fit();
        n0 = d->ndrawn;

        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_bar(d, 1066);
        jw_cmd_point(d, app_view(), -33.061224, 26.326531, 0);  /* 円の天辺 */
        jw_cmd_point(d, app_view(), -140.0, -53.265306, 0);     /* 線の左 */
        ck(d->ndrawn == n0 + 1, "線×円で点が落ちる");
        if (d->ndrawn == n0 + 1)
            ck(near(d->obj[n0].d[0], -91.465665)
               && near(d->obj[n0].d[1], -53.265306),
               "  左を押せば左の交点（原典の数そのもの）");

        n0 = d->ndrawn;
        jw_cmd_point(d, app_view(), -33.061224, 26.326531, 0);
        jw_cmd_point(d, app_view(), 80.0, -53.265306, 0);       /* 線の右 */
        /* 原典の .jww に出てくる数は丸めてあるので、ここだけ 1e-5 */
        ck(d->ndrawn == n0 + 1
           && fabs(d->obj[n0].d[0] - 25.343216) < 1e-5,
           "  右を押せば右の交点");
    }

    /* ------------------------------------------- 交点: 円×円 ------ */
    /* 原典の数（tools/probe155.sh、decomp/res/ten_cc_*.jww）:
       中心 (-63.673469, -34.897959) と (9.795918, -34.897959)、
       どちらも半径 42.857143。交点は y が -12.823155 と -56.972763 で、
       x はどちらも -26.938776。ここでも**押した側に近いほう**でした。 */
    {
        jw_obj *o;
        int n0;
        int k;

        app_new();
        app_resize(1264, 741);
        d = (jw_drawing *)app_drawing();
        for (k = 0; k < 2; k++) {
            o = jw_add(d, JW_ENKO);
            o->d[0] = k ? 9.795918 : -63.673469;
            o->d[1] = -34.897959;
            o->d[2] = 42.857143;
            o->d[3] = 0.0;
            o->d[4] = 6.283185;
            o->d[5] = 0.0;
            o->d[6] = 1.0;
        }
        app_fit();
        n0 = d->ndrawn;
        jw_cmd_set(JW_CMD_TEN);
        jw_cmd_bar(d, 1066);
        jw_cmd_point(d, app_view(), -63.673469, 7.959184, 0);   /* 上の弧 */
        jw_cmd_point(d, app_view(), 9.795918, 7.959184, 0);
        ck(d->ndrawn == n0 + 1, "円×円で点が落ちる");
        if (d->ndrawn == n0 + 1)
            ck(fabs(d->obj[n0].d[0] + 26.938776) < 1e-5
               && fabs(d->obj[n0].d[1] + 12.823155) < 1e-5,
               "  上を押せば上の交点（原典の数そのもの）");

        n0 = d->ndrawn;
        jw_cmd_point(d, app_view(), -63.673469, -77.755102, 0); /* 下の弧 */
        jw_cmd_point(d, app_view(), 9.795918, -77.755102, 0);
        ck(d->ndrawn == n0 + 1
           && fabs(d->obj[n0].d[1] + 56.972763) < 1e-5,
           "  下を押せば下の交点");
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
