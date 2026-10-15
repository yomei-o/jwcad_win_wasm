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

/* 一括処理 (1064)。伸縮・消去とも CIkktuDialog の 1064 → 25 番目、処理実行
   1065 → 26 番目、段は助け手 FUN_005637b0（左）・FUN_00564350（右）、
   範囲は FUN_00562d40、実行は 消去 FUN_0070ce00・伸縮 FUN_00716b20。
   逆コンパイルの読み、原典では押していない。 */
static int bar_has(int want)
{
    int i, id, k, x, y, w, h;

    for (i = 0; ui_bar_item(i, &id, &k, &x, &y, &w, &h); i++)
        if (id == want)
            return 1;
    return 0;
}

static void ikk_stretch(void)
{
    jw_drawing *d;
    double vx, x4;
    int i;

    fresh();
    d = (jw_drawing *)app_drawing();
    line(700, 200, 700, 400);           /* 0: 基準線 */
    line(300, 250, 500, 250);           /* 1〜3: 始線から終線までの線 */
    line(300, 300, 500, 300);
    line(300, 350, 500, 350);
    line(300, 450, 500, 450);           /* 4: 範囲の外 */
    vx = obj(0)->d[0];
    x4 = obj(4)->d[2];
    app_command(32791);
    ck(jw_cmd_bar_enabled(d, 1064) > 0 && !bar_has(1065), "ikk: 伸縮の 一括処理 は生き、処理実行 は無い");
    ck(jw_cmd_bar(d, 1064), "ikk: 一括処理 を押す");
    ck(!strncmp(jw_cmd_prompt(), JW_STR_5388, strlen(JW_STR_5388)), "ikk: 基準線の問い 5388");
    ck(bar_has(1065) && jw_cmd_bar_enabled(d, 1065) == 0, "ikk: 処理実行 が出て、まだ死んでいる");
    press(700, 380, 0);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5391), "ikk: 始線の問い 5391");
    press(400, 250, 0);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5392), "ikk: 終線の問い 5392");
    press(400, 350, 0);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5393), "ikk: 追加・除外の問い 5393");
    ck(jw_cmd_sel_count(d) == 3, "ikk: 始線から終線まで三本選ぶ");
    ck(jw_cmd_bar_enabled(d, 1065) > 0, "ikk: 処理実行 が生きる");
    ck(jw_cmd_bar(d, 1065), "ikk: 処理実行");
    for (i = 1; i <= 3; i++)
        ck(near_(obj(i)->d[2], vx), "ikk: 選んだ線の右端が基準線まで");
    ck(near_(obj(4)->d[2], x4), "ikk: 範囲の外の線はそのまま");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5336) && jw_cmd_sel_count(d) == 0,
       "ikk: 一回きりで素の伸縮へ戻る");
    jw_cmd_undo(d);
    ck(near_(obj(1)->d[2], x4) && near_(obj(3)->d[2], x4), "ikk: 戻る一度で三本とも戻る");

    /* (R) 読取点を基準点に: 線の端点 (700,200) の x へ */
    app_command(32791);
    jw_cmd_bar(d, 1064);
    press(700, 200, 1);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5391), "ikk: (R) で基準点、始線の問いへ");
    press(400, 250, 0);
    press(400, 300, 0);
    press(1100, 600, 1);                /* 段 5 の (R) は確定 */
    ck(near_(obj(1)->d[2], vx) && near_(obj(2)->d[2], vx) && near_(obj(3)->d[2], x4),
       "ikk: 基準点まで伸びる");
}

static int horiz_over(double y, double x)
{
    const jw_drawing *d = app_drawing();
    int i;

    for (i = n0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        if (o->cls == JW_SEN && near_(o->d[1], y) && near_(o->d[3], y)
            && ((o->d[0] < x && x < o->d[2]) || (o->d[2] < x && x < o->d[0])))
            return 1;
    }
    return 0;
}

static void ikk_erase(void)
{
    jw_drawing *d;
    double xm, y1, y2, y4;

    fresh();
    d = (jw_drawing *)app_drawing();
    line(500, 200, 500, 450);           /* 0・1: 基準線 */
    line(700, 200, 700, 450);
    line(300, 250, 900, 250);           /* 2〜4 */
    line(300, 300, 900, 300);
    line(300, 350, 900, 350);
    line(300, 500, 900, 500);           /* 5: 範囲の外 */
    xm = (obj(0)->d[0] + obj(1)->d[0]) / 2.0;
    y1 = obj(2)->d[1];
    y2 = obj(3)->d[1];
    y4 = obj(5)->d[1];
    app_command(32794);
    ck(jw_cmd_bar_enabled(d, 1064) > 0, "ikk: 消去の 一括処理 は生きる");
    jw_cmd_bar(d, 1064);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5389), "ikk: 消し始めの基準線 5389");
    press(500, 430, 0);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5390), "ikk: 消し終りの基準線 5390");
    press(700, 430, 0);
    press(400, 250, 0);
    press(400, 350, 0);
    ck(jw_cmd_sel_count(d) == 3, "ikk: 三本選ぶ");
    press(1100, 600, 1);
    ck(!horiz_over(y1, xm) && !horiz_over(y2, xm) && horiz_over(y4, xm),
       "ikk: 基準線の間が消え、範囲の外は残る");
    ck(d->ndrawn - n0 == 6 + 3, "ikk: 三本とも二つに分かれる");
    jw_cmd_undo(d);
    ck(d->ndrawn - n0 == 6 && horiz_over(y1, xm), "ikk: 戻る一度で元どおり");

    /* 基準線なし（(R) で始線）: 選んだ線を消す */
    jw_cmd_bar(d, 1064);
    press(400, 250, 1);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5392), "ikk: (R) の始線で終線の問いへ");
    press(400, 300, 0);
    jw_cmd_bar(d, 1065);
    ck(d->ndrawn - n0 == 4 && !horiz_over(y1, xm) && !horiz_over(y2, xm),
       "ikk: 一括消去 は二本を消す");

    /* 戻る で段を戻る */
    jw_cmd_bar(d, 1064);
    press(500, 430, 0);
    app_command(JW_CMD_UNDO);
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5389), "ikk: 戻る で基準線の段へ");
    app_command(JW_CMD_UNDO);
    ck(strcmp(jw_cmd_prompt(), JW_STR_5389) != 0, "ikk: もう一度で 一括をやめる");
}

int main(void)
{
    base_line();
    cut_move();
    protrude();
    ikk_stretch();
    ikk_erase();
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
