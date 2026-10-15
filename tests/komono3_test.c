/* 小物 3: 複写・移動の 戻る・ﾏｳｽ倍率 (1069)・角 (1071)・/ (1072)・連続の右押し、
 * 図形読込の 軸角 と 縮尺の違うグループの問い (0x157e)、伸縮の一括処理の
 * (LL) free 基準点、距離指定点の 戻る。
 *
 *   tests/komono3_test.exe
 *
 * どれも逆コンパイルの読みで、原典では押していない（答えの .jww は無い）。
 * 根拠は src/cmd.c の fk_mouse_place・fk_unplace・fk_swap・figure_place・
 * jw_cmd_point_ll（SHINSHUKU）・jw_cmd_back（KYORITEN）の注。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/gen/prompts.h"

#define PI 3.14159265358979323846

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

static int near(double a, double b)
{
    return fabs(a - b) < 1e-7;
}

static jw_drawing *fresh(void)
{
    unsigned char *b;
    long n;

    app_new();
    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        free(b);
        return 0;
    }
    free(b);
    jw_cmd_set_axis(0.0);
    return (jw_drawing *)app_drawing();
}

static jw_obj *add_line(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    return o;
}

/* 範囲 (-5,-5)-(15,15) を拾って、基準点 (0,0) で確定 */
static int pick(jw_drawing *d, int cmd)
{
    jw_cmd_set(cmd);
    jw_cmd_box_put(1411, "");
    jw_cmd_box_put(1412, "");
    jw_cmd_box_put(1413, "");
    jw_cmd_point(d, app_view(), -5.0, -5.0, 0);
    jw_cmd_point(d, app_view(), 15.0, 15.0, 0);
    jw_cmd_track(0.0, 0.0);
    return jw_cmd_bar(d, 1120) == 1;
}

static jw_drawing *setup(int cmd)
{
    jw_drawing *d = fresh();

    if (!d)
        return 0;
    add_line(d, 0.0, 0.0, 10.0, 0.0);
    if (!pick(d, cmd)) {
        printf("BAD  選択確定 could not be pressed\n");
        fails++;
        return 0;
    }
    return d;
}

static const jw_obj *last(const jw_drawing *d)
{
    return &d->obj[d->ndrawn - 1];
}

static void pt(jw_drawing *d, double x, double y)
{
    jw_cmd_point(d, app_view(), x, y, 0);
}

static void back(void)
{
    app_command(JW_CMD_UNDO);
}

static void copy_back(void)
{
    jw_drawing *d;
    int n0;

    printf("複写: 戻るは置いた一手を取り消して連続の回数を減らす\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    n0 = d->ndrawn;
    pt(d, 20.0, 0.0);
    jw_cmd_bar(d, 1064);                /* 二歩目 (40,0) */
    jw_cmd_bar(d, 1064);                /* 三歩目 (60,0) */
    ck(d->ndrawn == n0 + 3 && near(last(d)->d[0], 60.0), "  置いて連続を二度");
    back();
    ck(d->ndrawn == n0 + 2 && near(last(d)->d[0], 40.0), "  戻るで三歩目が消える");
    ck(jw_cmd_sel_count(d) == 1 && strcmp(jw_cmd_prompt(), JW_STR_5307) == 0,
       "  選んだまま 置く段に居る");
    jw_cmd_bar(d, 1064);
    ck(d->ndrawn == n0 + 3 && near(last(d)->d[0], 60.0), "  回数が減ったので 次の連続はまた三歩目");
    back();
    back();
    back();
    ck(d->ndrawn == n0, "  三度の戻るで 一回目まで消える");
    ck(jw_cmd_bar_enabled(d, 1064) == 0, "  回数 0 で 連続 は死ぬ");
    ck(jw_cmd_sel_count(d) == 1, "  まだ選んだまま");
    back();
    ck(jw_cmd_sel_count(d) == 0 && d->ndrawn == n0, "  置いたものが無ければ選択を放す（これまでどおり）");

    printf("移動: 戻るで元の所へ\n");
    d = setup(JW_CMD_IDOU);
    if (!d)
        return;
    n0 = d->ndrawn;
    pt(d, 3.0, 4.0);
    ck(near(last(d)->d[0], 3.0), "  動いた");
    back();
    ck(d->ndrawn == n0 && near(last(d)->d[0], 0.0) && near(last(d)->d[1], 0.0)
       && jw_cmd_sel_count(d) == 1, "  戻るで元の所、選んだまま");
}

/* 楕円（円弧）の (cos t, sin t) の点 */
static void arc_at(const jw_obj *o, double t, double *x, double *y)
{
    double f = o->d[6] > 0.0 ? o->d[6] : 1.0;
    double u = o->d[2] * cos(t), w = o->d[2] * f * sin(t);

    *x = o->d[0] + cos(o->d[5]) * u - sin(o->d[5]) * w;
    *y = o->d[1] + sin(o->d[5]) * u + cos(o->d[5]) * w;
}

static int near3(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

static void mouse_scale(void)
{
    jw_drawing *d;
    jw_obj *c;
    int n0;
    double x, y, ex, ey;

    printf("複写: ﾏｳｽ倍率 (1069)\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_box_put(1411, "2");
    n0 = d->ndrawn;
    ck(jw_cmd_bar_enabled(d, 1069) == 1, "  置く段で ﾏｳｽ倍率 が押せる");
    ck(jw_cmd_bar(d, 1069) == 1, "  ﾏｳｽ倍率 を押す");
    ck(strcmp(jw_cmd_box(1411), "0 , 0") == 0, "  倍率の箱は \"0 , 0\"");
    ck(jw_cmd_bar_enabled(d, 1151) == 1 && jw_cmd_bar_enabled(d, 1066) == 0
       && jw_cmd_bar_enabled(d, 1411) == 0 && jw_cmd_bar_enabled(d, 2092) == 0,
       "  バーは型 2（任意方向 と ﾏｳｽ倍率 のほか死ぬ）");
    ck(strcmp(jw_cmd_prompt(), JW_STR_5411) == 0, "  元図形の対角位置の問い 0x1523");
    pt(d, 10.0, 5.0);                   /* 元の対角 */
    ck(strcmp(jw_cmd_prompt(), JW_STR_5307) == 0, "  次は ふつうの置く点");
    pt(d, 100.0, 0.0);                  /* 置く点 */
    ck(strcmp(jw_cmd_prompt(), JW_STR_5412) == 0 && d->ndrawn == n0,
       "  三つ目の問い 0x1524、まだ置かない");
    pt(d, 120.0, 15.0);                 /* 写しの対角: X 2 倍、Y 3 倍 */
    ck(d->ndrawn == n0 + 1 && near(last(d)->d[0], 100.0) && near(last(d)->d[1], 0.0)
       && near(last(d)->d[2], 120.0) && near(last(d)->d[3], 0.0),
       "  X は (20/10) 倍で 置く点に");
    ck(strcmp(jw_cmd_prompt(), JW_STR_5307) == 0 && jw_cmd_bar_enabled(d, 1064) == 0,
       "  一回きり、連続 は死ぬ");

    /* 縦の線で Y の倍率 */
    d = fresh();
    if (!d)
        return;
    add_line(d, 0.0, 0.0, 0.0, 10.0);
    pick(d, JW_CMD_FUKUSHA);
    jw_cmd_bar(d, 1069);
    pt(d, 10.0, 5.0);
    pt(d, 0.0, 0.0);
    pt(d, 20.0, 15.0);
    ck(near(last(d)->d[3], 30.0) && near(last(d)->d[2], 0.0), "  Y は (15/5) 倍");

    /* 円弧は楕円に、裏返しは向きを逆に */
    d = fresh();
    if (!d)
        return;
    c = jw_add(d, JW_ENKO);
    c->d[0] = 5.0;
    c->d[1] = 5.0;
    c->d[2] = 4.0;
    c->d[3] = 0.3;
    c->d[4] = 1.0;
    c->d[5] = 0.0;
    c->d[6] = 1.0;
    pick(d, JW_CMD_FUKUSHA);
    jw_cmd_bar(d, 1069);
    pt(d, 10.0, 10.0);
    pt(d, 50.0, 0.0);
    pt(d, 50.0 + 20.0, -10.0);          /* X 2 倍、Y -1 倍 */
    {
        const jw_obj *o = last(d);
        double ox, oy;

        ck(o->cls == JW_ENKO && near(o->d[0], 60.0) && near(o->d[1], -5.0),
           "  楕円の中心");
        ck(near3(o->d[2], 8.0) && near3(o->d[6], 0.5), "  長い半径 8・扁平 0.5");
        /* 元の終わりの点の写しが 新しい始まり（裏返し） */
        ox = 5.0 + 4.0 * cos(1.3);
        oy = 5.0 + 4.0 * sin(1.3);
        ex = 50.0 + 2.0 * ox;
        ey = -oy;
        arc_at(o, o->d[3], &x, &y);
        ck(near3(x, ex) && near3(y, ey), "  元の終わり → 新しい始まり");
        ox = 5.0 + 4.0 * cos(0.3);
        oy = 5.0 + 4.0 * sin(0.3);
        arc_at(o, o->d[3] + o->d[4], &x, &y);
        ck(near3(x, 50.0 + 2.0 * ox) && near3(y, -oy), "  元の始まり → 新しい終わり");
    }

    printf("複写: マウス倍率のときXY等倍 (2556)\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_fk_xy1_set(1);
    jw_cmd_bar(d, 1069);
    pt(d, 10.0, 5.0);
    pt(d, 0.0, 30.0);
    pt(d, 20.0, 30.0 + 15.0);           /* X 2 倍・Y 3 倍 → |a.x| > |a.y| で X の 2 倍 */
    ck(near(last(d)->d[2], 20.0) && near(last(d)->d[1], 30.0) && near(last(d)->d[3], 30.0),
       "  X の倍率を両方に");
    jw_cmd_fk_xy1_set(0);

    printf("複写: ﾏｳｽ倍率 の中の 戻る と 押し直し\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_bar(d, 1069);
    pt(d, 10.0, 5.0);
    pt(d, 100.0, 0.0);
    back();
    ck(strcmp(jw_cmd_prompt(), JW_STR_5307) == 0, "  三つ目待ちから戻ると 置く点待ち");
    back();
    ck(strcmp(jw_cmd_prompt(), JW_STR_5411) == 0, "  もう一度で 一つ目待ち");
    back();
    ck(strcmp(jw_cmd_prompt(), JW_STR_5307) == 0 && jw_cmd_sel_count(d) == 1,
       "  もう一度で ﾏｳｽ倍率 を切る（選んだまま）");
    jw_cmd_bar(d, 1069);
    jw_cmd_bar(d, 1069);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5307) == 0, "  二度押せば切れる");
}

static void kaku(void)
{
    jw_drawing *d;
    int n0;

    printf("複写: 角 (1071)\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_box_put(1412, "45");
    n0 = d->ndrawn;
    jw_cmd_bar(d, 1071);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5631) == 0, "  一つ目は 角度基準点 0x15ff");
    ck(jw_cmd_bar_enabled(d, 1411) == 1 && jw_cmd_bar_enabled(d, 1412) == 0
       && jw_cmd_bar_enabled(d, 1066) == 0, "  バーは型 3（任意方向・倍率・角）");
    pt(d, 0.0, 10.0);                   /* 基準の向き 90° */
    pt(d, 50.0, 0.0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_10118) == 0, "  三つ目は 角度点");
    pt(d, 60.0, 0.0);                   /* 0° → -90° 回す */
    ck(d->ndrawn == n0 + 1 && near(last(d)->d[0], 50.0) && near(last(d)->d[1], 0.0)
       && near(last(d)->d[2], 50.0) && near(last(d)->d[3], -10.0),
       "  -90° 回して 置く点に（回転角の箱 45 は使わない）");
    ck(strcmp(jw_cmd_box(1412), "-90") == 0, "  回転角の箱に -90");

    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    jw_cmd_bar(d, 1071);
    jw_cmd_bar(d, 1071);                /* 基準角 水平 */
    ck(strcmp(jw_cmd_prompt(), JW_STR_5307) == 0, "  二度押すと 基準角は水平で 置く点から");
    pt(d, 50.0, 0.0);
    pt(d, 50.0, 10.0);
    ck(near(last(d)->d[2], 50.0) && near(last(d)->d[3], 10.0)
       && strcmp(jw_cmd_box(1412), "90") == 0, "  真上で 90°");
    jw_cmd_bar(d, 1071);
    jw_cmd_bar(d, 1071);
    jw_cmd_bar(d, 1071);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5307) == 0, "  三度で切れる");
}

static void swap_and_r(void)
{
    jw_drawing *d;
    int n0;

    printf("複写: / (1072) で 移動 に置き直す\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    n0 = d->ndrawn;
    ck(jw_cmd_bar_enabled(d, 1072) == 0, "  置くまで / は死んでいる");
    pt(d, 20.0, 0.0);
    ck(d->ndrawn == n0 + 1 && jw_cmd_bar_enabled(d, 1072) == 1, "  一つ写すと生きる");
    ck(jw_cmd_bar(d, 1072) == 1, "  / を押す");
    ck(d->ndrawn == n0 && near(last(d)->d[0], 20.0) && near(last(d)->d[2], 30.0)
       && jw_cmd_bar_check(2092) == 0, "  写しは消え、元が動いて 複写 は外れる");
    ck(jw_cmd_bar(d, 1072) == 1 && d->ndrawn == n0 + 1 && near(last(d)->d[0], 20.0)
       && near(d->obj[n0 - 1].d[0], 0.0) && jw_cmd_bar_check(2092) == 1,
       "  もう一度で 元へ戻して 写しに");

    printf("複写: 連続の右押し\n");
    d = setup(JW_CMD_FUKUSHA);
    if (!d)
        return;
    n0 = d->ndrawn;
    ck(jw_cmd_bar_r(d, 1064) == 0, "  置くまでは受けない");
    pt(d, 20.0, 0.0);
    ck(jw_cmd_bar_r(d, 1064) == 1 && d->ndrawn == n0 + 2 && near(last(d)->d[0], 40.0),
       "  右押しで連続を一つ");
}

static void figure(void)
{
    jw_drawing *d, fg;
    unsigned char *b;
    long n;
    double bx, by, u0x, u0y, u1x, u1y, a = 30.0 * PI / 180.0;
    int n0, g, wg = 0, i;

    printf("図形読込: 回転は箱 + 軸角\n");
    d = fresh();
    if (!d)
        return;
    b = slurp("decomp/res/fig.jws", &n);
    ck(b != 0, "  decomp/res/fig.jws を読む");
    if (!b)
        return;
    memset(&fg, 0, sizeof fg);
    if (!jw_parse_jws(&fg, b, n, &bx, &by) || fg.ndrawn <= 0) {
        ck(0, "  図形が読めた");
        free(b);
        return;
    }
    ck(app_figure(b, n) && jw_cmd() == JW_CMD_ZUKEI, "  図形読込");
    jw_cmd_box_put(1412, "0");
    jw_cmd_box_put(1431, "1");
    n0 = d->ndrawn;
    pt(d, 50.0, 50.0);
    ck(d->ndrawn > n0, "  軸角 0 で置く");
    u0x = d->obj[n0].d[0] - 50.0;
    u0y = d->obj[n0].d[1] - 50.0;
    jw_cmd_set_axis(30.0);
    n0 = d->ndrawn;
    pt(d, 50.0, 50.0);
    u1x = d->obj[n0].d[0] - 50.0;
    u1y = d->obj[n0].d[1] - 50.0;
    ck(near3(u1x, cos(a) * u0x - sin(a) * u0y) && near3(u1y, sin(a) * u0x + cos(a) * u0y),
       "  軸角 30 なら 30° 回る");
    jw_cmd_set_axis(0.0);

    printf("図形読込: 元グループで縮尺が違えば 0x157e を訊く\n");
    g = fg.obj[0].lgroup & 15;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    {
        int w = (g + 1) & 15;           /* 図形のグループでない書込グループ */

        d->group[wg].state = 2;
        d->group[w].state = 3;
        d->group[w].scale = d->group[g].scale * 2.0;
        jw_cmd_fzoku_set(2, 0);
        jw_cmd_fzoku_set(3, 0);
        n0 = d->ndrawn;
        pt(d, 80.0, 80.0);
        app_paint();
        ck(d->ndrawn == n0 && app_modal(), "  置かずに問いの窓");
        app_key(27);
        ck(d->ndrawn == n0 && !app_modal(), "  キャンセルなら置かない");
        pt(d, 80.0, 80.0);
        app_paint();
        app_key(13);
        ck(d->ndrawn > n0 && !app_modal(), "  OK なら置く");
        jw_cmd_fzoku_set(3, 1);
        n0 = d->ndrawn;
        pt(d, 90.0, 90.0);
        app_paint();
        ck(d->ndrawn > n0 && !app_modal(), "  書込グループなら訊かない");
        jw_cmd_fzoku_set(2, 1);
        d->group[w].scale = d->group[g].scale;
        d->group[w].state = 2;
        d->group[wg].state = 3;
    }
    jw_free(&fg);
    free(b);
}

static void stretch_ll(void)
{
    jw_drawing *d;
    rect_t r;
    const jw_view *v;
    int n0;
    double fx;

    printf("伸縮: 一括処理の (LL) free 基準点\n");
    d = fresh();
    if (!d)
        return;
    v = app_view();
    n0 = d->ndrawn;
    add_line(d, 0.0, 0.0, 10.0, 0.0);
    add_line(d, 0.0, 5.0, 10.0, 5.0);
    add_line(d, 0.0, 30.0, 10.0, 30.0);         /* 範囲の外 */
    app_command(32791);
    jw_cmd_bar(d, 1064);
    ck(jw_cmd_ikk_base_wait() == 1, "  基準線待ち");
    /* 何もない所でダブルクリック（app の二度押し） */
    fx = 40.0;
    app_press(jw_sx(v, fx), jw_sy(v, 50.0), 0);
    app_press(jw_sx(v, fx), jw_sy(v, 50.0), 0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5391) == 0, "  (LL) で基準点、始線の問いへ");
    jw_cmd_point(d, v, 5.0, 0.0, 0);
    jw_cmd_point(d, v, 5.0, 5.0, 0);
    jw_cmd_point(d, v, 100.0, 100.0, 1);        /* 段 5 の (R) は実行 */
    {
        double want = d->obj[n0].d[2];
        int px = jw_sx(v, fx);

        /* 押した画素の紙の x（free なので読まない） */
        ck(fabs(want - fx) < 2.0 * v->mmpp + 1e-9 && fabs(d->obj[n0 + 1].d[2] - want) < 1e-9
           && near(d->obj[n0 + 2].d[2], 10.0), "  二本が free 基準点の x まで、外の線はそのまま");
        (void)px;
    }
    (void)r;

    /* 直に: 基準線を拾ったあとの (LL) は基準点に替える */
    app_command(32791);
    jw_cmd_bar(d, 1064);
    jw_cmd_point_ll(d, v, 25.0, 0.0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5391) == 0, "  jw_cmd_point_ll で基準点");
    jw_cmd_point_ll(d, v, 30.0, 0.0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5391) == 0, "  始線待ちの (LL) は基準点を替える");
    jw_cmd_point(d, v, 5.0, 0.0, 0);
    jw_cmd_point_ll(d, v, 35.0, 0.0);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5392) == 0, "  始線を拾ったあとの (LL) は何もしない");
    jw_cmd_point(d, v, 5.0, 5.0, 0);
    jw_cmd_bar(d, 1065);
    ck(near(d->obj[n0].d[2], 30.0) && near(d->obj[n0 + 1].d[2], 30.0), "  替えた基準点 x=30 まで");
}

static double wscale(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

static void kyori_back(void)
{
    jw_drawing *d;
    double step;
    int n0;

    printf("距離指定点: 戻るで連続の回数を減らす\n");
    d = fresh();
    if (!d)
        return;
    jw_cmd_set(JW_CMD_KYORITEN);
    jw_cmd_box_put(1412, "1000");
    step = 1000.0 / wscale(d);
    n0 = d->ndrawn;
    pt(d, 0.0, 0.0);
    pt(d, 10.0, 0.0);
    jw_cmd_bar(d, 1066);
    jw_cmd_bar(d, 1066);
    ck(d->ndrawn == n0 + 3 && near(last(d)->d[0], 3.0 * step), "  一つ置いて 連続 を二度");
    back();
    ck(d->ndrawn == n0 + 2 && near(last(d)->d[0], 2.0 * step), "  戻るで三つ目が消える");
    jw_cmd_bar(d, 1066);
    ck(d->ndrawn == n0 + 3 && near(last(d)->d[0], 3.0 * step), "  次の連続はまた三つ目の所");
    back();
    back();
    back();
    ck(d->ndrawn == n0 && jw_cmd_bar_enabled(d, 1066) == 0, "  回数 0 で 連続 は死ぬ");
    pt(d, 0.0, 0.0);
    back();
    ck(strcmp(jw_cmd_prompt(), JW_STR_5320) == 0 && d->ndrawn == n0,
       "  始点のあとの戻るは始点待ちに（図面はそのまま）");
}

int main(void)
{
    copy_back();
    mouse_scale();
    kaku();
    swap_and_r();
    figure();
    stretch_ll();
    kyori_back();
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
