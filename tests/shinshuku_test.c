/* 伸縮 (32791, CZukeiShinshuku) の右ボタン —— (R) 線切断・(RR) 基準線指定・
 * 基準線までの伸縮（状態 3・4）・突出寸法。
 *
 *   tests/shinshuku_test.exe
 *
 * どれも原典の逆コンパイルの読み（FUN_00718e60・FUN_00719580・
 * FUN_00715f50・FUN_0071a050・FUN_0046e550）で、原典では押していません。
 * 線を引いて伸縮へ移り、押して、線の端を見ます。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/prompts.h"

static int fails;
static rect_t r;
static int n0;              /* new.jww が初めから持つ要素の数 */

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

static void fresh(void)
{
    unsigned char *b;
    long n;

    b = slurp("decomp/res/new.jww", &n);
    app_new();
    app_resize(1264, 741);
    if (b)
        app_open(b, n);
    free(b);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    n0 = app_drawing()->ndrawn;
}

static void press(int x, int y, int button)
{
    app_press(r.x + x, r.y + y, button);
}

/* 線を一本、画面の点で */
static void line(int x0, int y0, int x1, int y1)
{
    app_command(32771);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
    press(x0, y0, 0);
    press(x1, y1, 0);
}

static const jw_obj *obj(int i)
{
    const jw_drawing *d = app_drawing();

    return n0 + i < d->ndrawn ? &d->obj[n0 + i] : 0;
}

static int near_(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

static double wscale(void)
{
    const jw_drawing *d = app_drawing();
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

/* (RR) で縦の線を基準線にし、横の線を左で指すとそこまで伸び、縮む。
   基準線は残る。 */
static void base_line(void)
{
    const jw_obj *v, *h;
    double vx;

    fresh();
    line(700, 200, 700, 400);           /* 0: 基準線になる縦線 */
    line(300, 300, 500, 300);           /* 1: 届かない横線 */
    line(300, 350, 900, 350);           /* 2: 越えている横線 */
    line(900, 250, 1000, 250);          /* 3: 右側にある横線 */
    app_command(32791);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5336), "base: 初めは 0x14d8");
    press(700, 300, 1);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5339), "base: 右一度で 0x14db");
    press(700, 300, 1);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5337), "base: 右二度で 0x14d9");
    ck(app_drawing()->ndrawn - n0 == 4, "base: 右二度では何も切らない");
    v = obj(0);
    vx = v->d[0];
    press(350, 300, 0);
    h = obj(1);
    ck(near_(h->d[2], vx) && near_(h->d[3], h->d[1]), "base: 届かない線の右端が基準線へ");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5337), "base: 基準線は残る");
    press(350, 350, 0);
    h = obj(2);
    ck(near_(h->d[2], vx), "base: 越えた線は基準線まで縮む（指した側が残る）");
    press(950, 250, 0);
    h = obj(3);
    ck(near_(h->d[0], vx) && h->d[2] > vx, "base: 右側の線は左端が基準線へ");
    ck(app_drawing()->ndrawn - n0 == 4, "base: 線の数は変わらない");
    app_key(27);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5336), "base: Esc で 0x14d8 へ");
}

/* (R) を押してマウスを動かすと、その点で切れる（切断間隔が空なら二つに） */
static void cut_move(void)
{
    const jw_obj *a, *b;

    fresh();
    line(300, 300, 700, 300);
    app_command(32791);
    press(500, 300, 1);
    ck(app_drawing()->ndrawn - n0 == 1, "cut: 右一度ではまだ切れない");
    app_move(r.x + 501, r.y + 300);
    ck(app_drawing()->ndrawn - n0 == 1, "cut: 1 画素では切れない");
    app_move(r.x + 520, r.y + 310);
    ck(app_drawing()->ndrawn - n0 == 2, "cut: 動かすと二つに");
    a = obj(0);
    b = obj(1);
    ck(a && b && near_(a->d[2], b->d[0]) && near_(a->d[3], b->d[1]),
       "cut: 間隔なしなら切れ目は一点");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5336), "cut: 切ったあとは 0x14d8");
    app_move(r.x + 600, r.y + 330);
    ck(app_drawing()->ndrawn - n0 == 2, "cut: 二度は切らない");

    /* 切断間隔 10（図寸）: 切れ目が 10 空く */
    fresh();
    line(300, 300, 700, 300);
    app_command(32791);
    jw_cmd_box_put(1411, "10");
    press(500, 300, 1);
    app_move(r.x + 540, r.y + 340);
    a = obj(0);
    b = obj(1);
    ck(app_drawing()->ndrawn - n0 == 2 && a && b && near_(b->d[0] - a->d[2], 10.0),
       "cut: 切断間隔 10 の切れ目");

    /* 動きを見ずに遠くを押したら、先に切ってからその押しを扱う */
    fresh();
    line(300, 300, 700, 300);
    app_command(32791);
    press(500, 300, 1);
    press(650, 300, 0);
    ck(app_drawing()->ndrawn - n0 == 2, "cut: 遠くの押しの前に切る");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5338), "cut: その左で線を指した");

    /* 右を待つあいだの、同じ所の左は何もしない */
    fresh();
    line(300, 300, 700, 300);
    app_command(32791);
    press(500, 300, 1);
    press(500, 300, 0);
    ck(app_drawing()->ndrawn - n0 == 1 && !strcmp(jw_cmd_prompt(), JW_STR_5339),
       "cut: 待つあいだの左は何もしない");
}

/* 突出寸法 (1413): 点までの伸縮も基準線までの伸縮も、その実寸だけ先へ */
static void protrude(void)
{
    const jw_obj *h;
    double vx, s, x0;

    fresh();
    line(700, 200, 700, 400);
    line(300, 300, 500, 300);
    line(300, 350, 500, 350);
    app_command(32791);
    jw_cmd_box_put(1413, "100");
    s = wscale();
    vx = obj(0)->d[0];
    press(700, 300, 1);
    press(700, 300, 1);
    press(350, 300, 0);
    h = obj(1);
    ck(near_(h->d[2], vx + 100.0 / s), "out: 基準線を突出寸法だけ越える");
    app_key(27);
    /* 点まで: 指示点を線に落として、その先へ */
    x0 = obj(2)->d[0];
    press(350, 350, 0);
    press(600, 360, 0);
    h = obj(2);
    ck(h->d[2] > obj(1)->d[0] && near_(h->d[0], x0), "out: 点までは右端が動く");
    {
        double want = h->d[2];
        /* 突出寸法を消して同じことをすると 100 / s だけ手前 */
        jw_cmd_box_put(1413, "");
        press(350, 350, 0);
        press(600, 360, 0);
        ck(near_(obj(2)->d[2], want - 100.0 / s), "out: 点までの伸縮も突出寸法だけ先");
    }
}

/* 円弧の伸縮（FUN_0044cfb0 → FUN_0044d190、逆コンパイルの読み、原典では
   押していない）。図面の座標で直に押す */
static jw_drawing *arcs(void)
{
    jw_drawing *d;
    jw_obj *o;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    o = jw_add(d, JW_ENKO);                 /* 0: 中心 (0,0) 半径 50、0〜90 度 */
    o->d[0] = 0; o->d[1] = 0; o->d[2] = 50; o->d[3] = 0; o->d[4] = 3.141592653589793 / 2;
    o->d[5] = 0; o->d[6] = 1;
    o = jw_add(d, JW_ENKO);                 /* 1: 全円 (200,0) 半径 30 */
    o->d[0] = 200; o->d[1] = 0; o->d[2] = 30; o->d[3] = 0; o->d[4] = 2 * 3.141592653589793;
    o->d[5] = 0; o->d[6] = 1; o->n = 1;
    o = jw_add(d, JW_SEN);                  /* 2: 縦線 x = 30 */
    o->d[0] = 30; o->d[1] = -400; o->d[2] = 30; o->d[3] = -200;
    o = jw_add(d, JW_ENKO);                 /* 3: 中心 (0,-300) 半径 50、-60〜60 度 */
    o->d[0] = 0; o->d[1] = -300; o->d[2] = 50; o->d[3] = -3.141592653589793 / 3;
    o->d[4] = 2 * 3.141592653589793 / 3; o->d[5] = 0; o->d[6] = 1;
    app_fit();
    jw_cmd_set(JW_CMD_SHINSHUKU);
    return d;
}

static double deg(double a)
{
    return a * 180.0 / 3.141592653589793;
}

static void arc_point(void)
{
    jw_drawing *d = arcs();
    const jw_obj *a;
    double pi = 3.141592653589793;

    /* 60 度で指して 120 度（半径の倍の所でも中心から寄せる）: 終わりが伸びる */
    jw_cmd_point(d, app_view(), 50 * cos(pi / 3), 50 * sin(pi / 3), 0);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5338), "arc: 円弧を指すと 0x14da");
    jw_cmd_point(d, app_view(), 100 * cos(2 * pi / 3), 100 * sin(2 * pi / 3), 0);
    a = &d->obj[0];
    ck(near_(a->d[3], 0.0) && near_(deg(a->d[4]), 120.0), "arc: 終わりが 120 度まで伸びる");
    /* 20 度で指して 60 度: 始まりの側を残して縮む */
    jw_cmd_point(d, app_view(), 50 * cos(pi / 9), 50 * sin(pi / 9), 0);
    jw_cmd_point(d, app_view(), 50 * cos(pi / 3), 50 * sin(pi / 3), 0);
    ck(near_(a->d[3], 0.0) && near_(deg(a->d[4]), 60.0), "arc: 終わりが 60 度へ縮む");
    /* 戻る で一つずつ */
    app_command(JW_CMD_UNDO);
    ck(near_(deg(d->obj[0].d[4]), 120.0), "arc: 戻る で 120 度に");
    app_command(JW_CMD_UNDO);
    ck(near_(deg(d->obj[0].d[4]), 90.0), "arc: もう一度で元の 90 度");
    /* 全円は断る（札 0x1458「円です」） */
    jw_cmd_notice_clear();
    jw_cmd_point(d, app_view(), 230, 0, 0);
    ck(jw_cmd_notice_id() == 5208 && !strcmp(jw_cmd_prompt(), JW_STR_5336),
       "arc: 全円は 札「円です」で拾わない");
}

static void arc_base(void)
{
    jw_drawing *d = arcs();
    const jw_obj *a;
    double pi = 3.141592653589793;

    /* 縦線 x = 30 を (RR) で基準線に、-60〜60 度の弧を 20 度で指す:
       終わりが中心から (30,40) の 53.13 度へ */
    jw_cmd_point(d, app_view(), 30, -390, 1);
    jw_cmd_point(d, app_view(), 30, -390, 1);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5337), "arcbase: 基準線を持つ");
    jw_cmd_point(d, app_view(), 50 * cos(pi / 9), -300 + 50 * sin(pi / 9), 0);
    a = &d->obj[3];
    ck(near_(a->d[3], -pi / 3) && near_(a->d[3] + a->d[4], atan2(40.0, 30.0)),
       "arcbase: 円弧の終わりが基準線との交点へ");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5337), "arcbase: 基準線は残る");
}

/* 伸縮の中の 戻る（FUN_007164d0 と FUN_00719c30 の履歴）: 基準線までの伸縮を
   一つずつ戻すあいだ基準線は持ったまま、その次で基準線を放し、その次から
   図面の 戻る */
static void back_hist(void)
{
    const jw_obj *h;
    double x1, x2;
    int nd;

    fresh();
    line(700, 200, 700, 400);           /* 0: 基準線 */
    line(300, 300, 500, 300);           /* 1 */
    line(300, 350, 500, 350);           /* 2 */
    x1 = obj(1)->d[2];
    x2 = obj(2)->d[2];
    nd = app_drawing()->ndrawn;
    app_command(32791);
    press(700, 300, 1);
    press(700, 300, 1);
    press(350, 300, 0);
    press(350, 350, 0);
    ck(!near_(obj(1)->d[2], x1) && !near_(obj(2)->d[2], x2), "back: 二本とも伸びた");
    app_command(JW_CMD_UNDO);
    h = obj(2);
    ck(near_(h->d[2], x2) && !near_(obj(1)->d[2], x1)
       && !strcmp(jw_cmd_prompt(), JW_STR_5337), "back: 一つ目の 戻る で二本目だけ、基準線は持ったまま");
    app_command(JW_CMD_UNDO);
    ck(near_(obj(1)->d[2], x1) && !strcmp(jw_cmd_prompt(), JW_STR_5337),
       "back: 二つ目で一本目も");
    app_command(JW_CMD_UNDO);
    ck(app_drawing()->ndrawn == nd && !strcmp(jw_cmd_prompt(), JW_STR_5336),
       "back: 三つ目で基準線を放す（図面はそのまま）");
    app_command(JW_CMD_UNDO);
    ck(app_drawing()->ndrawn == nd - 1, "back: 四つ目から図面の 戻る（最後に引いた線が消える）");
}

int main(void)
{
    base_line();
    cut_move();
    protrude();
    arc_point();
    arc_base();
    back_hist();
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
