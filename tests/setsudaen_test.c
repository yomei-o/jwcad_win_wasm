/* 接円 (32872) の 接楕円 (1065).
 *
 *   tests/setsudaen_test.exe
 *
 * 逆コンパイルの読み（CZukeiSetuEn の slot 26 FUN_00706e50 が作る
 * CZukeiSetuDaEn。３点は FUN_00643340、菱形内接は FUN_006450c0、平行四辺
 * 内接は FUN_00643c30 と楕円の伸ばし FUN_00464fd0）、原典では押していない.
 * 答えは原典の絵ではなく、出来た楕円が 三点を通ること・辺に接すること
 * （中心から辺までの距離が その向きの楕円の張り出しと等しいこと）で見る.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

static int fails;
static jw_drawing *d;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b) { return fabs(a - b) < 1e-6; }

static void line(double x1, double y1, double x2, double y2)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x1;
    o->d[1] = y1;
    o->d[2] = x2;
    o->d[3] = y2;
}

static void fresh(void)
{
    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
}

/* 楕円 o の上の点か: 軸の枠に直して (u/r)^2 + (v/(r f))^2 = 1 */
static int on_ell(const jw_obj *o, double x, double y)
{
    double c = cos(o->d[5]), s = sin(o->d[5]);
    double u = (x - o->d[0]) * c + (y - o->d[1]) * s;
    double v = (y - o->d[1]) * c - (x - o->d[0]) * s;
    double a = o->d[2], b = o->d[2] * o->d[6];

    return fabs(u * u / (a * a) + v * v / (b * b) - 1.0) < 1e-6;
}

/* 楕円 o が 線 (x1,y1)-(x2,y2)（端無し）に接するか */
static int touches(const jw_obj *o, double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1, dy = y2 - y1, L = sqrt(dx * dx + dy * dy);
    double nx = -dy / L, ny = dx / L;
    double dist = fabs((o->d[0] - x1) * nx + (o->d[1] - y1) * ny);
    double c = cos(o->d[5]), s = sin(o->d[5]);
    double a = o->d[2], b = o->d[2] * o->d[6];
    double nu = nx * c + ny * s, nv = ny * c - nx * s;

    return fabs(dist - sqrt(a * a * nu * nu + b * b * nv * nv)) < 1e-6;
}

static int bar_has(int want)
{
    int i, id, k, x, y, w, h;

    for (i = 0; ui_bar_item(i, &id, &k, &x, &y, &w, &h); i++)
        if (id == want)
            return 1;
    return 0;
}

static void enter(int type_button)
{
    app_fit();
    app_command(JW_CMD_SEKIEN);
    jw_cmd_bar(d, 1065);
    if (type_button)
        jw_cmd_bar(d, type_button);
}

static void bar_and_types(void)
{
    printf("接楕円のバーと型\n");
    fresh();
    line(-100, -100, 100, 100);
    enter(0);
    ck(jw_cmd_setsudaen() == -1, "  1065 で接楕円に入り、型はまだ無い");
    ck(jw_cmd_bar_check(9021) > 0, "  バーは 9021（DIALOG 310 の CButton9Dlg）");
    ck(bar_has(1064) && bar_has(1066) && bar_has(1067) && bar_has(1068) && bar_has(1069)
       && !bar_has(1065) && !bar_has(1411) && !bar_has(1417),
       "  << と 四つの型の釦だけ（半径・多重円 は隠れる）");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5403), "  案内は 5403「項目を選択してください」");
    jw_cmd_bar(d, 1067);
    ck(jw_cmd_setsudaen() == 20, "  菱形内接 (1067) は 型 20");
    ck(strstr(jw_cmd_prompt(), JW_STR_5444) && !strncmp(jw_cmd_prompt(), "1 ", 2),
       "  案内は「1 」と 5444「辺をマウスで指示してください。」");
    jw_cmd_bar(d, 1068);
    ck(jw_cmd_setsudaen() == 30, "  平行四辺内接 (1068) は 型 30");
    jw_cmd_bar(d, 1069);
    ck(jw_cmd_setsudaen() == 50, "  ３点半楕円 (1069) は 型 50");
    jw_cmd_bar(d, 1066);
    ck(jw_cmd_setsudaen() == 10 && !strcmp(jw_cmd_prompt(), JW_STR_5441),
       "  ３点指示 (1066) は 型 10、案内 5441");
    jw_cmd_bar(d, 1064);
    ck(jw_cmd_setsudaen() == 0 && jw_cmd() == JW_CMD_SEKIEN && jw_cmd_bar_check(9021) <= 0,
       "  << で接円のバーに戻る");
    ck(bar_has(1411) && bar_has(1065), "  接円の 半径・接楕円 がまた出る");
    enter(1066);
    app_command(JW_CMD_SEN);
    ck(jw_cmd_setsudaen() == 0, "  ほかの命令へ移ると 接楕円 は消える");
}

static void three_points(void)
{
    const jw_obj *o;
    int before;

    printf("３点指示\n");
    fresh();
    line(-100, -100, 100, 100);
    enter(1066);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5442), "  始点のあと 5442");
    jw_cmd_point(d, app_view(), 100.0, 0.0, 0);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5443), "  終点のあと 5443");
    {
        jw_obj pv[8];

        jw_cmd_track(50.0, 30.0);
        ck(jw_cmd_pending(d, pv, 8) == 1 && pv[0].cls == JW_ENKO && near(pv[0].d[6], 0.6),
           "  通過点を待つ間は カーソルを通る楕円を仮に描く");
    }
    jw_cmd_point(d, app_view(), 50.0, 30.0, 0);
    ck(d->ndrawn == before + 1, "  通過点で一つ描く");
    o = &d->obj[d->ndrawn - 1];
    ck(o->cls == JW_ENKO && near(o->d[0], 50) && near(o->d[1], 0) && near(o->d[2], 50)
       && near(o->d[6], 0.6) && near(o->d[5], 0) && near(o->d[3], 0)
       && near(o->d[4], 2 * 3.14159265358979323846) && o->n == 1,
       "  中心は軸の中点、半径は軸の半分、扁平率 30/50、全楕円");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5441), "  描いたら 始点待ち に戻る");

    /* 通過点が軸より外へ張り出す: 短い方を軸にやり直す */
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 20.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 10.0, 30.0, 0);
    o = &d->obj[d->ndrawn - 1];
    ck(d->ndrawn == before + 1 && near(o->d[0], 10) && near(o->d[1], 0) && near(o->d[2], 30)
       && near(o->d[6], 1.0 / 3.0) && near(o->d[5], -3.14159265358979323846 / 2),
       "  扁平率が 1 を超えれば 縦を軸にした楕円（半径 30、扁平率 1/3）");
    ck(on_ell(o, 0, 0) && on_ell(o, 20, 0) && on_ell(o, 10, 30), "  三点とも楕円の上");

    /* 軸の始点と終点が同じ: 計算できません */
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 5.0, 5.0, 0);
    jw_cmd_point(d, app_view(), 5.0, 5.0, 0);
    jw_cmd_point(d, app_view(), 9.0, 9.0, 0);
    ck(d->ndrawn == before && jw_cmd_notice_id() == 5205, "  始点と終点が同じなら 札 5205");

    /* 戻る: 段を戻し、段 1 では描いたものを図面の 戻る で消し、無くなれば接円へ */
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 30.0, 0.0, 0);
    app_command(JW_CMD_UNDO);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5442), "  戻る で 終点待ち へ");
    app_command(JW_CMD_UNDO);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5441), "  もう一度で 始点待ち へ");
    before = d->ndrawn;
    app_command(JW_CMD_UNDO);
    ck(d->ndrawn == before - 1 && jw_cmd_setsudaen() == 10, "  段 1 の 戻る は 描いた楕円を消す");
    app_command(JW_CMD_UNDO);
    ck(d->ndrawn == before - 2 && jw_cmd_setsudaen() == 10, "  二つ目も");
    app_command(JW_CMD_UNDO);
    ck(jw_cmd_setsudaen() == 0 && jw_cmd() == JW_CMD_SEKIEN && d->ndrawn == before - 2,
       "  描いた数が尽きれば 接円 に戻る");

    /* (R) は読取点 */
    enter(1066);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), -99.0, -99.5, 1);
    jw_cmd_point(d, app_view(), 99.5, 99.0, 1);
    jw_cmd_point(d, app_view(), 0.0, 40.0, 0);
    o = &d->obj[d->ndrawn - 1];
    ck(d->ndrawn == before + 1 && near(o->d[0], 0) && near(o->d[1], 0)
       && near(o->d[2], sqrt(2.0) * 100) && near(o->d[5], 3.14159265358979323846 / 4),
       "  (R) は線の端を読む");
}

static void half(void)
{
    const jw_obj *o;

    printf("３点半楕円\n");
    fresh();
    line(-100, -100, 100, 100);
    enter(1069);
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 50.0, 30.0, 0);
    o = &d->obj[d->ndrawn - 1];
    ck(o->n == 0 && near(o->d[3], 0) && near(o->d[4], 3.14159265358979323846)
       && near(o->d[6], 0.6), "  通過点が上: 0 から π の半分");
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 50.0, -30.0, 0);
    o = &d->obj[d->ndrawn - 1];
    ck(o->n == 0 && near(o->d[3], 0) && near(o->d[4], -3.14159265358979323846),
       "  通過点が下: 0 から −π");
}

static void rhombus(void)
{
    const jw_obj *o;
    int before;

    printf("菱形内接\n");
    fresh();
    line(0, 0, 10, 0);          /* AB */
    line(10, 0, 16, 8);         /* BC */
    line(16, 8, 6, 8);          /* CD */
    line(6, 8, 0, 0);           /* DA（拾わない） */
    enter(1067);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 5.0, 0.0, 0);
    ck(!strncmp(jw_cmd_prompt(), "  2 ", 4), "  一本目のあと「  2 」");
    jw_cmd_point(d, app_view(), 13.0, 4.0, 0);
    ck(!strncmp(jw_cmd_prompt(), "    3 ", 6), "  二本目のあと「    3 」");
    jw_cmd_point(d, app_view(), 11.0, 8.0, 0);
    ck(d->ndrawn == before + 1, "  三本目で描く");
    o = &d->obj[d->ndrawn - 1];
    ck(near(o->d[0], 8) && near(o->d[1], 4) && near(o->d[2], sqrt(80.0) / sqrt(2.0))
       && near(o->d[6], 0.5) && near(o->d[5], atan2(4.0, 8.0)) && o->n == 1,
       "  中心は対角 AC の中点、半径は 半対角/√2、扁平率は 半対角の比");
    ck(touches(o, 0, 0, 10, 0) && touches(o, 10, 0, 16, 8) && touches(o, 16, 8, 6, 8)
       && touches(o, 6, 8, 0, 0), "  四つの辺に接する");

    /* 平行な組が無い三本 */
    fresh();
    line(0, 0, 10, 0);
    line(10, 0, 16, 8);
    line(0, 0, 3, 9);
    enter(1067);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 5.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 13.0, 4.0, 0);
    jw_cmd_point(d, app_view(), 1.0, 3.0, 0);
    ck(d->ndrawn == before && jw_cmd_notice_id() == 5205, "  平行な辺が無ければ 札 5205");

    /* 直線でないもの */
    {
        jw_obj *c = jw_add(d, JW_ENKO);

        c->d[0] = 50;
        c->d[1] = 50;
        c->d[2] = 10;
        c->d[4] = 2 * 3.14159265358979323846;
        c->d[6] = 1;
        c->n = 1;
    }
    app_fit();
    jw_cmd_notice_clear();
    jw_cmd_point(d, app_view(), 60.0, 50.0, 0);
    ck(jw_cmd_notice_id() == 5342 && !strncmp(jw_cmd_prompt(), "1 ", 2),
       "  円を指せば 札 5342「直線ではありません。」で 段はそのまま");
}

static void parallelogram(void)
{
    const jw_obj *o;
    int before;

    printf("平行四辺内接\n");
    fresh();
    /* A(0,0) B(20,0) C(26,8) D(6,8): 横 20、斜め 10 */
    line(0, 0, 20, 0);
    line(20, 0, 26, 8);
    line(26, 8, 6, 8);
    line(6, 8, 0, 0);
    enter(1068);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 10.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 23.0, 4.0, 0);
    jw_cmd_point(d, app_view(), 16.0, 8.0, 0);
    ck(!strncmp(jw_cmd_prompt(), "      4 ", 8) && d->ndrawn == before,
       "  三本目のあと「      4 」で まだ描かない");
    jw_cmd_point(d, app_view(), 3.0, 4.0, 0);
    ck(d->ndrawn == before + 1, "  四本目で描く");
    o = &d->obj[d->ndrawn - 1];
    ck(near(o->d[0], 13) && near(o->d[1], 4), "  中心は平行四辺形の中心");
    ck(touches(o, 0, 0, 20, 0) && touches(o, 20, 0, 26, 8) && touches(o, 26, 8, 6, 8)
       && touches(o, 6, 8, 0, 0), "  四つの辺に接する");
    ck(on_ell(o, 10, 0) && on_ell(o, 23, 4) && on_ell(o, 16, 8) && on_ell(o, 3, 4),
       "  接するのは辺の中点");

    /* 多重円 2: 半径を半分にしたものも */
    fresh();
    line(0, 0, 20, 0);
    line(20, 0, 26, 8);
    line(26, 8, 6, 8);
    line(6, 8, 0, 0);
    app_fit();
    app_command(JW_CMD_SEKIEN);
    jw_cmd_box_click(1417);
    {
        int i;

        for (i = 0; i < 24; i++)
            jw_cmd_box_key(8);
        jw_cmd_box_key('2');
        jw_cmd_box_key(13);
    }
    jw_cmd_bar(d, 1065);
    jw_cmd_bar(d, 1068);
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 10.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 23.0, 4.0, 0);
    jw_cmd_point(d, app_view(), 16.0, 8.0, 0);
    jw_cmd_point(d, app_view(), 3.0, 4.0, 0);
    ck(d->ndrawn == before + 2 && near(d->obj[before + 1].d[2], d->obj[before].d[2] / 2),
       "  多重円 2 なら 半径の半分の楕円も（FUN_0047f220）");
    app_command(JW_CMD_UNDO);
    ck(d->ndrawn == before, "  戻る で二つとも消える（一手）");
    jw_cmd_box_click(1417);
}

int main(void)
{
    bar_and_types();
    three_points();
    half();
    rhombus();
    parallelogram();
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
