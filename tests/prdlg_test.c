/* 印刷の命令の窓の口（src/plot.h の jw_pr_dialogs・jw_pr_ask・jw_pr_entered・
 * jw_pr_printer_paper）。ネイティブの表側（src/prnative.h）が使う。
 *
 * 原典: プリンタの設定 (1067) は FUN_005aeaf0 が ID_FILE_PRINT_SETUP、
 * 出力方法設定 (1069) は FUN_005aeb40 が プリント出力形式 DIALOG 344、
 * 印刷 は入る前に印刷の窓（FUN_0050be70）、枠の紙は FUN_004fccb0 が取る
 * プリンタの HORZSIZE/VERTSIZE（slot 8 FUN_006d2cb0 が 2 で整数割り）。
 * 逆コンパイルの読み、原典では押していない。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/plot.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static long be32(const unsigned char *p)
{
    return ((long)p[0] << 24) | ((long)p[1] << 16) | ((long)p[2] << 8) | p[3];
}

int main(void)
{
    jw_drawing *d;
    double x0, y0, x1, y1, w, h, dw, dh;
    unsigned char *png;
    long n;
    jw_plot_frame fr;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    jw_pr_reset();

    ck(!jw_pr_enabled(1067) && !jw_pr_enabled(1069), "窓の無い表側（ブラウザ）では 1067・1069 は押せない");
    ck(jw_pr_enabled(1065) && jw_pr_enabled(1068), "  ほかの釦は押せる");
    app_command(57607);
    ck(jw_cmd() == JW_PRINT_CMD, "印刷 で印刷の命令に入る");
    ck(jw_pr_entered() == 1 && jw_pr_entered() == 0, "  入った知らせは一度だけ");
    jw_pr_bar(d, 1067);
    ck(jw_pr_ask() == 0, "窓が無ければ 1067 は何も頼まない");

    jw_pr_dialogs(1);
    ck(jw_pr_enabled(1067) && jw_pr_enabled(1069), "窓のある表側（ネイティブ）では押せる");
    ck(jw_pr_bar(d, 1067) == 1 && jw_pr_ask() == 1067 && jw_pr_ask() == 0, "  1067 は プリンタの設定 を頼む（読むと消える）");
    ck(jw_pr_bar(d, 1069) == 1 && jw_pr_ask() == 1069, "  1069 は 出力方法設定");
    /* 画面のバーから（decomp/res/bars8.txt: 1069 は x 648 幅 86、1070 回転 は x 395 幅 77、y 5 高 24）。
       1069 が押せると app.c の 範囲選択 の 属性選択 (1069)・属性変更 (1070) が先に取らないこと */
    app_press(690, 17, 0);
    app_release(690, 17, 0);
    ck(jw_pr_ask() == 1069 && !app_modal(), "  バーの 1069 を押すと 出力方法設定 を頼む（属性選択 の窓は出ない）");
    jw_pr_settings(&fr);
    n = fr.rot;
    app_press(430, 17, 0);
    app_release(430, 17, 0);
    jw_pr_settings(&fr);
    ck(fr.rot == (n + 1) % 3 && !app_modal(), "  バーの 回転 (1070) は回すだけ（属性変更 の窓は出ない）");
    app_press(430, 17, 0);
    app_release(430, 17, 0);
    app_press(430, 17, 0);
    app_release(430, 17, 0);

    jw_plot_paper(d, &dw, &dh);
    jw_pr_paper(d, &w, &h);
    ck(w == dw && h == dh, "プリンタの紙が無ければ図面の用紙");
    jw_pr_frame(d, &x0, &y0, &x1, &y1);
    ck(fabs((x1 - x0) - 2 * (double)((int)dw / 2)) < 1e-9, "  枠の幅は用紙の幅");

    jw_pr_printer_paper(203.0, 289.0);  /* A4 縦の印刷できる所くらい */
    jw_pr_paper(d, &w, &h);
    ck(w == 203.0 && h == 289.0, "選んだプリンタの紙（HORZSIZE/VERTSIZE の mm）");
    jw_pr_frame(d, &x0, &y0, &x1, &y1);
    printf("     枠 %.1f x %.1f\n", x1 - x0, y1 - y0);
    ck(fabs((x1 - x0) - 202.0) < 1e-9 && fabs((y1 - y0) - 288.0) < 1e-9,
       "  枠は (int)(203/2)*2 x (int)(289/2)*2（slot 8 の整数割り）");
    jw_pr_settings(&fr);
    png = jw_plot_png_at(d, &fr, 2.0, &n);
    ck(png && n > 24, "刷る絵が作れる");
    if (png && n > 24) {
        printf("     絵 %ld x %ld\n", be32(png + 16), be32(png + 20));
        ck(labs(be32(png + 16) - 406) <= 1 && labs(be32(png + 20) - 578) <= 1,
           "  刷る絵はプリンタの紙の大きさ（2 画素/mm で 406 x 578）");
    }
    free(png);
    jw_pr_printer_paper(0.0, 0.0);
    jw_pr_paper(d, &w, &h);
    ck(w == dw && h == dh, "0 で図面の用紙に戻る");

    jw_pr_reset();
    ck(!jw_pr_enabled(1067), "jw_pr_reset で素に戻る");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
