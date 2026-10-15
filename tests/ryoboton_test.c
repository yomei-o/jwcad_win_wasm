/* 両ボタンドラッグ・両ボタンクリック（src/ryoboton.h、原典の CZoom）。
 *
 * 向きの判定（FUN_0060c6a0）と、二つとも離したときの仕事（FUN_0060b110 の
 * 1〜5）、枠と字（範囲拡大 だけ枠、R2_NOTXORPEN の 0x808080、字は 0xc8c8c8）。
 * 逆コンパイルの読み、原典では押していない。答えは読みから出した数で見る。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/ryoboton.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near_(double a, double b, double e)
{
    return fabs(a - b) <= e;
}

static unsigned int px(int x, int y)
{
    const fb_t *f = app_fb();
    return f->px[y * f->w + x];
}

static void drag(int x0, int y0, int x1, int y1)
{
    ryo_begin(x0, y0);
    ryo_move((x0 + x1) / 2, (y0 + y1) / 2);
    ryo_move(x1, y1);
}

int main(void)
{
    rect_t r;
    jw_view fit, v;
    int cx, cy, x, y, n, k;
    double px0, py0;

    /* 判定の表 */
    ck(ryo_kind(0, 0, 10) == RYO_IDO, "動かさなければ 移動");
    ck(ryo_kind(9, -9, 10) == RYO_IDO, "しきい 10 の内は 移動");
    ck(ryo_kind(10, 10, 10) == RYO_KAKUDAI, "10 ちょうどは外（↘ 範囲拡大）");
    ck(ryo_kind(3, 40, 10) == RYO_NONE, "真下は何もしない（マークジャンプ 0）");
    ck(ryo_kind(-40, 2, 10) == RYO_NONE, "真左も");
    ck(ryo_kind(30, 30, 10) == RYO_KAKUDAI, "↘ 範囲拡大");
    ck(ryo_kind(-30, -30, 10) == RYO_SHUKUSHO, "↖ 縮小");
    ck(ryo_kind(-30, 30, 10) == RYO_MAEBAI, "↙ 前倍率");
    ck(ryo_kind(30, -30, 10) == RYO_ZENTAI, "↗ 全体");
    ck(ryo_kind(0, 0, 0) == RYO_SHUKUSHO, "しきい 0 なら 動かさなくても 縮小（dx ≤ 0, dy ≤ 0）");
    ck(ryo_slop() == 10, "しきいの既定は 10（1950）");

    ck(app_resize(1000, 700), "窓");
    app_new();
    app_fit();
    app_paint();
    ui_view_rect(1000, 700, &r);
    cx = r.x + r.w / 2;
    cy = r.y + r.h / 2;
    fit = *app_view();
    ck(ryo_holdable(cx, cy), "図面の上は左を預かる");
    ck(!ryo_holdable(r.x - 1, cy) && !ryo_holdable(cx, r.y + r.h), "図面の外は預からない");
    ck(!ryo_active() && ryo_now() == RYO_NONE, "初めは両ボタンでない");

    /* ↘ 範囲拡大: 枠と字、離せば半分の箱が窓いっぱい */
    {
        unsigned int before = px(cx - r.w / 8, cy - r.h / 4);
        unsigned int inside = px(cx, cy);

        drag(cx - r.w / 4, cy - r.h / 4, cx + r.w / 4, cy + r.h / 4);
        ck(ryo_active() && ryo_now() == RYO_KAKUDAI, "↘ は 範囲拡大");
        app_paint();
        ck(px(cx - r.w / 8, cy - r.h / 4) == (~(0x808080u ^ before) & 0xffffffu),
           "  枠の上の辺は ~(0x808080 ^ 下地)");
        ck(px(cx, cy) == inside, "  枠の中は塗らない");
        for (n = 0, y = cy - r.h / 4 - 16; y < cy - r.h / 4; y++)
            for (x = cx - r.w / 4 + 2; x < cx - r.w / 4 + 80; x++)
                n += px(x, y) == 0xc8c8c8u;
        ck(n > 10, "  起点の右上に「拡  大」を 0xc8c8c8 で");
        ck(ryo_end(), "  離すと仕事をする");
        ck(!ryo_active(), "  両ボタンが終わる");
        ck(near_(app_view()->mmpp, fit.mmpp / 2, fit.mmpp * 0.01), "  半分の箱が窓いっぱい（倍率 2）");
    }
    app_paint();

    /* ↙ 前倍率: 用紙全体に戻る。もう一度で 2 倍へ */
    drag(cx, cy, cx - 40, cy + 40);
    ck(ryo_now() == RYO_MAEBAI, "↙ は 前倍率");
    ryo_end();
    ck(near_(app_view()->mmpp, fit.mmpp, 1e-12), "  前倍率 で用紙全体へ");
    drag(cx, cy, cx - 40, cy + 40);
    ryo_end();
    ck(near_(app_view()->mmpp, fit.mmpp / 2, fit.mmpp * 0.01), "  もう一度で 2 倍へ戻る");

    /* ↗ 全体: 表示範囲記憶 が無ければ用紙全体。字は「全  体」 */
    drag(cx, cy, cx + 40, cy - 40);
    ck(ryo_now() == RYO_ZENTAI, "↗ は 全体");
    ryo_end();
    ck(near_(app_view()->mmpp, fit.mmpp, 1e-12) && near_(app_view()->ox, fit.ox, 1e-9)
       && near_(app_view()->oy, fit.oy, 1e-9), "  用紙全体へ");

    /* ↖ 縮小: 起点を真ん中に倍率半分（0.5 より下へは行かない） */
    drag(cx + 100, cy + 50, cx + 60, cy + 10);
    ck(ryo_now() == RYO_SHUKUSHO, "↖ は 縮小");
    ryo_end();
    ck(near_(app_view()->mmpp, fit.mmpp * 2, 1e-12), "  倍率が半分");

    /* 両ボタンクリック: その点を真ん中へ、倍率はそのまま */
    v = *app_view();
    px0 = v.ox + (cx + 120 - v.bx) / v.scale;
    py0 = v.oy + (v.by - (cy - 70)) / v.scale;
    ryo_begin(cx + 120, cy - 70);
    ryo_move(cx + 124, cy - 66);
    ck(ryo_now() == RYO_IDO, "しきいの内は 移動");
    app_paint();
    for (n = 0, y = cy - 70 - 16; y < cy - 70; y++)
        for (x = cx + 122; x < cx + 200; x++)
            n += px(x, y) == 0xc8c8c8u;
    ck(n > 10, "  「移  動」を出す");
    ryo_end();
    ck(near_(app_view()->mmpp, v.mmpp, 1e-15), "  倍率はそのまま");
    ck(near_(app_view()->ox, px0, 1e-6) && near_(app_view()->oy, py0, 1e-6), "  押した点が真ん中に");

    /* 真っすぐは何もしない。やめれば何もしない */
    v = *app_view();
    drag(cx, cy, cx + 2, cy + 60);
    ck(ryo_now() == RYO_NONE, "真下は判定なし");
    ck(!ryo_end(), "  離しても何もしない");
    ck(near_(app_view()->mmpp, v.mmpp, 1e-15) && near_(app_view()->ox, v.ox, 1e-12), "  画面はそのまま");
    drag(cx, cy, cx + 90, cy + 90);
    ryo_cancel();
    ck(!ryo_active() && near_(app_view()->mmpp, v.mmpp, 1e-15), "やめれば何もしない");

    /* でたらめに 300 回（落ちない・倍率が有限） */
    srand(7);
    for (k = 0; k < 300; k++) {
        ryo_begin(rand() % 1000, rand() % 700);
        ryo_move(rand() % 1000, rand() % 700);
        if (k % 3 == 0)
            app_paint();
        ryo_end();
    }
    ck(app_view()->mmpp > 0 && app_view()->mmpp < 1e9, "でたらめ 300 回で倍率が有限");

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
