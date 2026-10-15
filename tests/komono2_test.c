/* 札の残り・バーの釦の右押し・半径／直径寸法の矢印（逆コンパイルの読み、原典では押していない）。
 *   - 一括処理（消去）: 基準線をもう一度 5394、始線をもう一度 5351、同一線種で色違い 5212、
 *     円を指すと 5342
 *   - 消去の 選択順切替 (1068): 5626 → 5625、入ると 5625（FUN_0070ea90・FUN_0070c300）
 *   - AUTO: プロテクトレイヤの線を左で → 5290 に " [0]-(0)" をつないだ札（FUN_00516e40）
 *   - 測定: 同じ点を二度 → 5343（FUN_0071e8d0）
 *   - 多角形 ２辺: 一点目と同じ二点目 → 5343（FUN_00723ab0）
 *   - ハッチ: ピッチ 0 で実行 → 5205（FUN_00675b10）
 *   - 印刷の 基準点 (1066) の右押しで 左・下 に戻る（FUN_00550310）、図形読込の 90ﾟ毎 (1064)
 *     の右押しで一つ前（FUN_005f4fd0）
 *   - 寸法の 半径・直径 の 端部 矢印・逆矢印（FUN_007891b0） */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/plot.h"
#include "../src/gen/prompts.h"

static unsigned char *buf;
static long nbuf;
static rect_t r;
static int fails;

static void bad(const char *what)
{
    printf("BAD  %s\n", what);
    fails++;
}

static void ck(int ok, const char *what)
{
    if (!ok)
        bad(what);
    else
        printf("ok   %s\n", what);
}

static void press(int x, int y, int b)
{
    app_press(r.x + x, r.y + y, b);
}

static jw_drawing *dr(void)
{
    return (jw_drawing *)app_drawing();
}

/* 画面の (sx, sy)（ビューの中の画素）の図面の点 */
static void paper(int sx, int sy, double *x, double *y)
{
    const jw_view *v = app_view();

    *x = v->ox + (r.x + sx - v->bx) / v->scale;
    *y = v->oy + (v->by - (r.y + sy)) / v->scale;
}

static void open_new(void)
{
    app_new();
    app_resize(1264, 741);
    app_open(buf, nbuf);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
}

static void add_line(int x0, int y0, int x1, int y1)
{
    jw_obj *o = jw_add(dr(), JW_SEN);

    paper(x0, y0, &o->d[0], &o->d[1]);
    paper(x1, y1, &o->d[2], &o->d[3]);
}

/* 中心 (sx, sy)・半径 rp 画素の円 */
static int add_circle(int sx, int sy, int rp)
{
    jw_obj *o = jw_add(dr(), JW_ENKO);

    paper(sx, sy, &o->d[0], &o->d[1]);
    o->d[2] = rp / app_view()->scale;
    o->d[3] = 0.0;
    o->d[4] = 2.0 * 3.14159265358979;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
    o->n = 1;
    return dr()->ndrawn - 1;
}

static void want(const char *what, int id)
{
    char m[160];

    snprintf(m, sizeof m, "%s（札 %d、期待 %d）", what, jw_cmd_notice_id(), id);
    ck(jw_cmd_notice_id() == id, m);
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

int main(void)
{
    FILE *f = fopen("decomp/res/new.jww", "rb");

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    nbuf = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (unsigned char *)malloc((size_t)nbuf);
    if (fread(buf, 1, (size_t)nbuf, f) != (size_t)nbuf)
        return 1;
    fclose(f);

    /* 1. 一括処理（消去） */
    open_new();
    add_line(300, 300, 800, 300);       /* 基準線 1 */
    add_line(300, 350, 800, 350);       /* 基準線 2 */
    add_line(300, 400, 800, 400);       /* 始線 */
    add_line(300, 450, 800, 450);       /* 色違い */
    dr()->obj[dr()->ndrawn - 1].color = 5;
    add_circle(550, 550, 30);
    app_command(JW_CMD_SHOUKYO);
    ck(jw_cmd_bar(dr(), 1064) != 0, "消去の 一括処理 に入る");
    press(550, 580, 0);
    want("一括 円を指す", 5342);
    press(500, 300, 0);
    press(500, 350, 0);
    press(500, 300, 0);
    want("一括 基準線をもう一度", 5394);
    press(500, 400, 0);
    press(500, 400, 0);
    want("一括 始線をもう一度", 5351);
    press(500, 450, 1);
    want("一括 同一線種で色違い", 5212);

    /* 2. 選択順切替 */
    open_new();
    app_command(JW_CMD_SHOUKYO);
    jw_cmd_bar(dr(), 1068);
    want("選択順切替 入", 5625);
    jw_cmd_bar(dr(), 1068);
    want("選択順切替 切", 5626);
    jw_cmd_bar(dr(), 1068);
    app_command(JW_CMD_SEN);
    app_command(JW_CMD_SHOUKYO);
    want("選択順切替 が入ったまま消去に入る", 5625);
    jw_cmd_bar(dr(), 1068);             /* 切に戻す */
    app_command(JW_CMD_SEN);
    app_command(JW_CMD_SHOUKYO);
    want("切なら入っても札なし", 0);

    /* 3. AUTO のプロテクトレイヤ */
    open_new();
    add_line(300, 400, 800, 400);
    {
        jw_obj *o = &dr()->obj[dr()->ndrawn - 1];

        dr()->group[o->lgroup].layer[o->layer].state2 = 1;
    }
    app_command(JW_CMD_AUTO);
    press(500, 400, 0);
    want("AUTO プロテクトレイヤ", 5290);
    {
        char t[96];

        snprintf(t, sizeof t, "%s [%X]-(%X)", JW_STR_5290,
                 dr()->obj[dr()->ndrawn - 1].lgroup,
                 dr()->obj[dr()->ndrawn - 1].layer);
        ck(jw_cmd_notice_text() && strcmp(jw_cmd_notice_text(), t) == 0,
           "  文は 5290 に [グループ]-(レイヤ)");
    }

    /* 4. 測定 */
    open_new();
    app_command(JW_CMD_SOKUTEI);
    press(300, 300, 0);
    press(300, 300, 0);
    want("測定 同じ点を二度", 5343);

    /* 5. 多角形 ２辺 */
    open_new();
    app_command(JW_CMD_TAKAKU);
    jw_cmd_bar(dr(), 1689);
    jw_cmd_box_put(1412, "");           /* 長さは三点目から */
    {
        int n0 = dr()->ndrawn;

        press(300, 300, 0);
        press(300, 300, 0);
        want("多角形 ２辺 同じ二点目", 5343);
        press(400, 300, 0);
        press(350, 250, 0);
        {
            char m[120];

            snprintf(m, sizeof m, "  二点目を待ったままで、次の二点で引ける（%d 本、札 %d）",
                     dr()->ndrawn - n0, jw_cmd_notice_id());
            ck(dr()->ndrawn == n0 + 2, m);
        }
    }

    /* 6. ハッチ ピッチ 0 */
    open_new();
    app_command(JW_CMD_HATCH);
    jw_cmd_box_put(1411, "0");
    jw_cmd_bar(dr(), 1148);
    want("ハッチ ピッチ 0", 5205);

    /* 7. バーの釦の右押し */
    open_new();
    app_command(57607);                 /* 印刷 → 0x8053 */
    ck(jw_cmd() == JW_PRINT_CMD, "印刷の命令に入る");
    jw_cmd_bar(dr(), 1066);
    jw_cmd_bar(dr(), 1066);
    ck(strcmp(jw_pr_label(1066), "\x89" "E\x81" "E\x89\xba") == 0, "印刷 基準点 二回で 右・下");
    ck(jw_cmd_bar_r(dr(), 1066) == 1, "  右押しを命令が受ける");
    ck(strcmp(jw_pr_label(1066), "\x8d\xb6\x81" "E\x89\xba") == 0, "  右押しで 左・下");
    ck(jw_cmd_bar_r(dr(), 1070) == 0, "  回転 の右押しは受けない");
    {
        /* app の側: バーの 1066 を右で押す */
        int x, y, hit = 0;

        jw_cmd_bar(dr(), 1066);
        for (y = 0; y < app_fb()->h && !hit; y++)
            for (x = 0; x < app_fb()->w; x++)
                if (ui_bar_hit(x, y) == 1066) {
                    app_press(x, y, 1);
                    hit = 1;
                    break;
                }
        ck(hit && strcmp(jw_pr_label(1066), "\x8d\xb6\x81" "E\x89\xba") == 0,
           "  バーの釦を右で押して 左・下");
    }
    app_command(JW_CMD_ZUKEI);
    jw_cmd_box_put(1412, "0");
    jw_cmd_bar_r(dr(), 1064);
    ck(jw_cmd_box(1412) && strcmp(jw_cmd_box(1412), "270") == 0, "図形読込 90ﾟ毎 の右で 0 → 270");
    jw_cmd_bar_r(dr(), 1064);
    ck(jw_cmd_box(1412) && strcmp(jw_cmd_box(1412), "180") == 0, "  もう一度で 180");
    jw_cmd_box_put(1412, "100");
    jw_cmd_bar_r(dr(), 1064);
    ck(jw_cmd_box(1412) && strcmp(jw_cmd_box(1412), "0") == 0, "  100 → 0");
    jw_cmd_bar(dr(), 1064);
    ck(jw_cmd_box(1412) && strcmp(jw_cmd_box(1412), "90") == 0, "  左は 0 → 90 のまま");

    /* 8. 寸法の 半径・直径 の矢印 */
    {
        int ci, b0, k, ok;
        double cx, cy, rr, px, py;
        const jw_obj *o;

        open_new();
        ci = add_circle(500, 400, 100);
        cx = dr()->obj[ci].d[0];
        cy = dr()->obj[ci].d[1];
        rr = dr()->obj[ci].d[2];
        paper(600, 400, &px, &py);      /* 円の右 */
        app_command(JW_CMD_SUNPO);
        while (jw_cmd_sunpo_arrows() != 1)
            jw_cmd_bar(dr(), 1062);
        jw_cmd_bar(dr(), 1065);         /* 半径 */
        b0 = dr()->ndrawn;
        jw_cmd_point(dr(), app_view(), px, py, 0);
        ck(dr()->ndrawn == b0 + 4, "半径 矢印: 線・値・矢印二本（中心には付けない）");
        if (dr()->ndrawn == b0 + 4) {
            o = &dr()->obj[b0];
            ck(o->cls == JW_SEN && near(o->d[0], cx) && near(o->d[2], cx + rr), "  線は中心から円へ");
            ok = 1;
            for (k = 2; k < 4; k++) {
                o = &dr()->obj[b0 + k];
                if (o->cls != JW_SEN || !near(o->d[0], cx + rr) || !(o->d[2] < o->d[0]))
                    ok = 0;
            }
            ck(ok, "  矢印は円の上から内へ開く");
        }
        jw_cmd_bar(dr(), 1062);         /* 逆矢印 */
        ck(jw_cmd_sunpo_arrows() == 2, "  逆矢印 に");
        b0 = dr()->ndrawn;
        jw_cmd_point(dr(), app_view(), px, py, 0);
        ck(dr()->ndrawn == b0 + 5, "半径 逆矢印: 線・値・突出一本・矢印二本");
        if (dr()->ndrawn == b0 + 5) {
            o = &dr()->obj[b0 + 2];
            ck(o->cls == JW_SEN && near(o->d[0], cx + rr) && o->d[2] > o->d[0] + 0.1,
               "  突出は円の上から外へ");
            ok = 1;
            for (k = 3; k < 5; k++) {
                o = &dr()->obj[b0 + k];
                if (!near(o->d[0], cx + rr) || !(o->d[2] > o->d[0]))
                    ok = 0;
            }
            ck(ok, "  矢印は外へ開く");
        }
        jw_cmd_bar(dr(), 1066);         /* 直径 */
        b0 = dr()->ndrawn;
        jw_cmd_point(dr(), app_view(), px, py, 0);
        ck(dr()->ndrawn == b0 + 8, "直径 逆矢印: 線・値・突出二本・矢印四本");
        if (dr()->ndrawn == b0 + 8) {
            o = &dr()->obj[b0 + 3];
            ck(near(o->d[0], cx - rr) && o->d[2] < o->d[0], "  二本目の突出は向こう側から外へ");
            o = &dr()->obj[b0 + 4];
            ck(near(o->d[0], cx - rr) && o->d[2] < o->d[0], "  矢印は向こう側が先、外へ");
        }
        while (jw_cmd_sunpo_arrows() != 0)
            jw_cmd_bar(dr(), 1062);
        jw_cmd_bar(dr(), 1065);
        b0 = dr()->ndrawn;
        jw_cmd_point(dr(), app_view(), px, py, 0);
        ck(dr()->ndrawn == b0 + 4 && dr()->obj[b0 + 2].cls == JW_TEN
           && dr()->obj[b0 + 3].cls == JW_TEN, "半径 点: いままでどおり 点二つ");
    }

    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
