/* 基本設定 一般(2) 2526「ｍ単位入力」（src/cmd.c mu_len の注）。
 *
 * 入れると 長さの箱（線の 寸法 1412 など）を命令が読むとき ×1000、命令が書き戻すとき
 * ÷1000。角度の箱（線の 傾き 1411）は変わらない。表側（バーの表示・打ち込み）は
 * 字のまま。既定（切）なら何も変わらない。逆コンパイルの読み（FUN_005bdb30・FUN_005be9e0
 * ほか）で、原典では押していない。ここで確かめるのは 移植がその読みどおりに動くことだけ。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int hit(int want)
{
    const fb_t *fb = app_fb();
    int x, y;

    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == want) {
                app_press(x, y, 0);
                return 1;
            }
    return 0;
}

static int kh_press(int tab, int id)
{
    if (!app_kihon_open())
        app_command(32891);
    if (!app_kihon_open())
        return 0;
    if (app_kihon_tab() != tab && !hit(-tab - 1))
        return 0;
    return hit(id);
}

static void kh_ok(void)
{
    if (app_kihon_open())
        hit(1);
}

static const char *bx(int id)
{
    const char *t = jw_cmd_box(id);

    return t ? t : "(null)";
}

static const char *raw(int id)
{
    const char *t = jw_cmd_box_raw(id);

    return t ? t : "(null)";
}

static const char *bar_sum(int id, const char *typed)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 40; i++)
        jw_cmd_box_key(8);
    while (*typed)
        jw_cmd_box_key((unsigned char)*typed++);
    jw_cmd_box_key(13);
    return raw(id);
}

/* 線を 寸法 s で (0,0) から右へ一本。引いた線の長さ（引けなければ -1） */
static double sen_len(jw_drawing *d, const char *s)
{
    int n0;
    const jw_obj *o;

    app_command(JW_CMD_SEN);
    jw_cmd_box_put(1411, "");
    jw_cmd_box_put(1412, s);
    n0 = d->ndrawn;
    jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
    jw_cmd_point(d, app_view(), 50.0, 0.0, 0);
    if (d->ndrawn != n0 + 1)
        return -1.0;
    o = &d->obj[d->ndrawn - 1];
    return hypot(o->d[2] - o->d[0], o->d[3] - o->d[1]);
}

int main(void)
{
    jw_drawing *d;
    double l_mm, l_m, l_off;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    app_fit();

    /* ---- 既定（切）: 何も変わらない ---- */
    app_command(JW_CMD_SEN);
    jw_cmd_box_put(1412, "1.5");
    ck(!strcmp(bx(1412), "1.5"), "既定は 線の 寸法 1.5 を命令も 1.5 と読む");
    l_mm = sen_len(d, "1500");
    l_off = sen_len(d, "1.5");
    ck(l_mm > 0.0 && l_off > 0.0 && fabs(l_mm - l_off) > 1.0, "  寸法 1500 と 1.5 は別の長さ");

    /* ---- 入れる ---- */
    ck(kh_press(1, 2526), "一般(2) の ｍ単位入力 を押す");
    kh_ok();
    app_command(JW_CMD_SEN);
    jw_cmd_box_put(1412, "1.5");
    ck(!strcmp(bx(1412), "1500"), "  線の 寸法 1.5 は 命令には 1500");
    ck(!strcmp(raw(1412), "1.5"), "  箱の字（表示）は 1.5 のまま");
    jw_cmd_box_put(1411, "30");
    ck(!strcmp(bx(1411), "30"), "  傾き（角度）30 は 30 のまま");
    jw_cmd_box_put(1411, "");
    l_m = sen_len(d, "1.5");
    ck(l_m > 0.0 && fabs(l_m - l_mm) < 1e-6, "  寸法 1.5 で引いた線は 切のときの 1500 と同じ長さ");
    ck(!strcmp(bar_sum(1412, "1+0.5"), "1.5") && !strcmp(bx(1412), "1500"),
       "  式 1+0.5 は箱に 1.5、命令には 1500");

    app_command(JW_CMD_KUKEI);
    jw_cmd_box_put(1413, "1.5 , 2");
    ck(!strcmp(bx(1413), "1500 , 2000"), "  矩形の 寸法 1.5 , 2 は 1500 , 2000");

    app_command(JW_CMD_TAKAKU);
    jw_cmd_box_put(1411, "0.25");
    jw_cmd_box_put(1413, "6");
    ck(!strcmp(bx(1411), "250") && !strcmp(bx(1413), "6"), "  多角形の 寸法は ×1000、角数 6 は 6 のまま");

    app_command(JW_CMD_FUKUSEN);
    ck(jw_cmd_box(1411) != 0, "  複線に入る");
    app_command(JW_CMD_ENKO);
    jw_cmd_box_put(1411, "0.3");
    ck(!strcmp(bx(1411), "300"), "  円の 半径 0.3 は 300");

    /* 書き戻し: ２線 の ２倍間隔 は 命令が読んだ数（×1000）の倍を ÷1000 して入れる */
    app_command(JW_CMD_NISEN);
    jw_cmd_box_put(1412, "0.1 , 0.2");
    ck(!strcmp(bx(1412), "100 , 200"), "  ２線の間隔 0.1 , 0.2 は 100 , 200");
    jw_cmd_bar(d, 1066);
    ck(!strcmp(raw(1412), "0.2 , 0.4"), "  ２倍間隔 の書き戻しは ÷1000 で 0.2 , 0.4");
    jw_cmd_bar(d, 1065);
    jw_cmd_bar(d, 1065);
    ck(!strcmp(raw(1412), "0.05 , 0.1"), "  1/2 間隔 二度で 0.05 , 0.1");

    /* ---- 切ればまた元どおり ---- */
    kh_press(1, 2526);
    kh_ok();
    app_command(JW_CMD_SEN);
    jw_cmd_box_put(1412, "1.5");
    ck(!strcmp(bx(1412), "1.5"), "切ればまた 1.5 は 1.5");
    l_off = sen_len(d, "1.5");
    ck(l_off > 0.0 && fabs(l_off - l_mm) > 1.0, "  寸法 1.5 は 1500 の長さではない");
    app_command(JW_CMD_NISEN);
    jw_cmd_box_put(1412, "100 , 200");
    jw_cmd_bar(d, 1066);
    ck(!strcmp(raw(1412), "200 , 400"), "  ２倍間隔 は 200 , 400");
    jw_cmd_box_put(1412, "");

    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
