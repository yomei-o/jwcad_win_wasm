/* 用紙サイズ のポップアップ —— 状態表示の 用紙 の箱が出すもの。
 *
 *   tests/youshi_test.exe tests/out/youshi.png
 *
 * 移植はこの箱で 縮尺・読取 のダイアログを開いていました。原典に
 * WM_COMMAND 32825 を投げると、上がってくるのは **#32768 のポップアップ**
 * です（`tools/probe119.sh` の `popcmd:` ステップ）—— 用紙サイズ の
 * 十二項目で、いまの用紙に印が付きます。窓は 127x270、つまり
 * 12 * 22 + 3 * 2 で、`JW_POPUP_ITEM_H` と `JW_POPUP_BORDER` のまま。
 *
 * 出る所もポインタに付いてきます。カーソルを二箇所に置いて同じ命令を
 * 投げると、どちらも左上が (カーソル - 63, カーソル) でした。63 は
 * (127-1)/2 なので、**横はカーソルの真ん中、縦はカーソルから下**です。
 *
 * docs/ref_youshi.png が原典の描いたその絵です。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "png.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    rect_t b, r;
    int x, y, i, j;

    app_new();
    app_resize(1264, 741);
    fb = app_fb();

    ck(!ui_popup_up(), "ポップアップはまだ出ていない");
    ui_status_box(0, fb->w, fb->h, &b);
    x = b.x + b.w / 2;
    y = b.y;
    app_press(x, y, 0);
    ck(ui_popup_up(), "用紙 の箱を押すと出る");
    ck(ui_popup_rect(&r), "その所が取れる");
    ck(r.h == 12 * 22 + 6, "高さは十二項目ぶん（原典の窓は 270）");
    printf("     （原典の窓は 127x270。幅が狭いのは字形と、Windows のメニューが右に取る余白のぶん）\n");
    ck(r.x == x - (r.w - 1) / 2, "横はカーソルの真ん中");
    ck(r.y == y - r.h, "用紙の箱は下の端なので、上へ折り返す");

    app_paint();
    if (argc > 1) {
        unsigned int *px = (unsigned int *)malloc((size_t)r.w * r.h
                                                  * sizeof *px);
        if (px) {
            for (j = 0; j < r.h; j++)
                for (i = 0; i < r.w; i++)
                    px[j * r.w + i] = fb->px[(size_t)(r.y + j) * fb->w
                                             + r.x + i];
            png_rgb(argv[1], r.w, r.h, px);
            free(px);
            printf("     wrote %s, %dx%d\n", argv[1], r.w, r.h);
        }
    }

    /* and where there is room below, it runs down from the press */
    app_press(10, 400, 0);              /* shut it */
    ui_popup_open_at(32820, 32820, 600, 200, fb->w, fb->h);
    ck(ui_popup_rect(&r) && r.y == 200, "余裕があれば下へ出る");
    ck(r.x == 600 - (r.w - 1) / 2, "  横はやはり真ん中");
    app_press(10, 400, 0);
    app_press(x, y, 0);
    ui_popup_rect(&r);

    /* Ａ-４ is the fifth row */
    ck(app_drawing()->paper_size == 2, "出たときの用紙は Ａ-２（新規の）");
    app_press(r.x + r.w / 2, r.y + 3 + 4 * 22 + 11, 0);
    ck(!ui_popup_up(), "項目を押すと引っ込む");
    ck(app_drawing()->paper_size == 4, "  そして用紙が Ａ-４ になる");

    /* and pressing outside it just shuts it */
    app_press(x, y, 0);
    ck(ui_popup_up(), "もう一度出す");
    app_press(10, 400, 0);
    ck(!ui_popup_up(), "外を押すと引っ込むだけ");
    ck(app_drawing()->paper_size == 4, "  用紙はそのまま");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
