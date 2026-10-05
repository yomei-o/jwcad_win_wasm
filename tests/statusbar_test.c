/* 表示 > ステータスバー (59393) —— 状態表示を仕舞うと作図面が広がる。
 *
 *   tests/statusbar_test.exe
 *
 * 原典に訊くと、1264x741 のフレームで 1108x686 だったビューが、この命令の
 * あと 1108x705 になりました（`tools/probe134.sh` の `viewrect`）—— 19 画素
 * ぶんです。移植の白い所は 741-34-21 = 686 で、仕舞うと下の余白が 2 だけ
 * 残って 705 になります。
 *
 * 同じ並びの ツールバー (59392) は**ただの小見出し**（その下に個々のバーが
 * 並ぶ `MENU 400`）で、投げても割り付けは動きません。ダイアログボックス
 * (32953) も動きませんでした。
 */
#include <stdio.h>

#include "../src/app.h"
#include "../src/ui.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void ckn(int got, int want, const char *what)
{
    int ok = got == want;

    printf("%-4s %s (%d / %d)\n", ok ? "ok" : "BAD", what, got, want);
    if (!ok)
        fails++;
}

int main(void)
{
    rect_t r;

    app_resize(1264, 741);
    app_new();

    ck(ui_status_shown(), "はじめは出ている");
    ui_view_rect(1264, 741, &r);
    ckn(r.h, 686, "  そのときのビューの高さ");
    ckn(r.y, 34, "  上は 34 のまま");

    ck(app_command(59393) != 0, "ステータスバー を押すと応える");
    ck(!ui_status_shown(), "  仕舞われる");
    ui_view_rect(1264, 741, &r);
    ckn(r.h, 705, "  ビューは 19 画素広がる（原典も 686 -> 705）");
    ckn(r.y, 34, "  上は動かない");
    ckn(ui_status_hit(600, 735, 1264, 741), -1, "  箱はもう押せない");

    app_command(59393);
    ck(ui_status_shown(), "もう一度押すと戻る");
    ui_view_rect(1264, 741, &r);
    ckn(r.h, 686, "  高さも戻る");
    ck(ui_status_hit(1264 - 180, 730, 1264, 741) >= 0, "  箱も押せる");

    /* and it paints without falling over either way */
    app_command(59393);
    app_paint();
    app_command(59393);
    app_paint();
    ck(1, "どちらでも描ける");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
