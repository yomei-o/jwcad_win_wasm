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
    ck(jw_cmd_box(1412) != 0, "  複線の 留線出 1412 の箱がある");
    jw_cmd_box_put(1412, "0.25");
    ck(!strcmp(bx(1412), "250") && !strcmp(raw(1412), "0.25"),
       "  留線出 0.25 は 命令には 250（FUN_004b2390）");
    jw_cmd_box_put(1412, "");
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

    /* ---- 分類の (2): 命令の中で掛ける・割るもの ---- */
    /* 接円 の 半径 1411 は円のバーの読み手（×1000）、札の r は ÷1000 して ｍ（FUN_007063b0） */
    app_command(JW_CMD_SEKIEN);
    jw_cmd_box_put(1411, "0.3");
    ck(!strcmp(bx(1411), "300"), "  接円の 半径 0.3 は 300");
    ck(strstr(jw_cmd_status(d), "[ r = 0.300\x82\x8d ]") != 0, "  接円の札は [ r = 0.300ｍ ]");
    jw_cmd_box_put(1411, "");

    /* 連続線 の 丸面辺寸法 1411・連続弧半径 1412 は 実寸 (2096) のときだけ（FUN_005b8390・005b8450） */
    app_command(JW_CMD_RENZOKU);
    jw_cmd_box_put(1411, "5");
    jw_cmd_box_put(1412, "2");
    if (jw_cmd_bar_check(2096) > 0)
        jw_cmd_bar(d, 2096);
    ck(!strcmp(bx(1411), "5") && !strcmp(bx(1412), "2"), "  連続線は 図寸 なら 5・2 のまま");
    jw_cmd_bar(d, 2096);
    ck(jw_cmd_bar_check(2096) > 0 && !strcmp(bx(1411), "5000") && !strcmp(bx(1412), "2000"),
       "  実寸 なら 5000・2000");
    jw_cmd_bar(d, 2096);
    jw_cmd_box_put(1411, "");
    jw_cmd_box_put(1412, "");

    /* 面取 の 切断間隔 1413 も 実寸 のときだけ（FUN_0056fd50）、寸法 1411 はいつも */
    app_command(JW_CMD_MENTORI);
    jw_cmd_box_put(1413, "4");
    if (jw_cmd_bar_check(2096) > 0)
        jw_cmd_bar(d, 2096);
    ck(!strcmp(bx(1413), "4"), "  面取の 切断間隔 4 は 図寸 なら 4");
    jw_cmd_bar(d, 2096);
    ck(jw_cmd_bar_check(2096) > 0 && !strcmp(bx(1413), "4000"), "  実寸 なら 4000");
    jw_cmd_bar(d, 2096);
    jw_cmd_box_put(1413, "");

    /* ハッチ の ピッチ 1411・線間隔 1412 は 実寸 (1323) のときだけ、角度 1419 は掛けない
       （CHachiDialog の FUN_004c8700・004c8650・004c8600）。型を替えても箱の字は字のまま */
    app_command(JW_CMD_HATCH);
    jw_cmd_bar(d, 1690);
    jw_cmd_box_put(1419, "30");
    jw_cmd_box_put(1411, "2");
    jw_cmd_box_put(1412, "0.5");
    if (jw_cmd_bar_check(1323) > 0)
        jw_cmd_bar(d, 1323);
    ck(!strcmp(bx(1411), "2") && !strcmp(bx(1412), "0.5") && !strcmp(bx(1419), "30"),
       "  ハッチは 図寸 なら 2・0.5・角度 30 のまま");
    jw_cmd_bar(d, 1323);
    ck(jw_cmd_bar_check(1323) > 0 && !strcmp(bx(1411), "2000") && !strcmp(bx(1412), "500")
       && !strcmp(bx(1419), "30"), "  実寸 なら 2000・500、角度は 30");
    jw_cmd_bar(d, 1692);
    ck(!strcmp(raw(1411), "3") && !strcmp(raw(1412), "6"), "  ┬┴┬ に替えると箱は 3・6（÷しない）");
    ck(!strcmp(bx(1411), "3000"), "  命令には 3000");
    jw_cmd_bar(d, 1690);
    ck(!strcmp(raw(1411), "2") && !strcmp(raw(1412), "0.5"), "  戻すと 2・0.5 のまま");
    jw_cmd_bar(d, 1323);
    jw_cmd_bar(d, 1689);

    /* 複写 の 数値位置 1413（二つ目のバー、FUN_004ae4a0・004ae510） */
    {
        jw_obj *o = jw_add(d, JW_SEN);
        double s = 1.0;
        int g, wg = 0, before;

        o->d[0] = 0.0;
        o->d[1] = 0.0;
        o->d[2] = 10.0;
        o->d[3] = 0.0;
        for (g = 0; g < 16; g++)
            if (d->group[g].state == 3)
                wg = g;
        if (d->group[wg].scale > 0.0)
            s = d->group[wg].scale;
        app_command(JW_CMD_FUKUSHA);
        jw_cmd_point(d, app_view(), -5.0, -5.0, 0);
        jw_cmd_point(d, app_view(), 15.0, 5.0, 0);
        jw_cmd_track(0.0, 0.0);
        ck(jw_cmd_bar(d, 1120) == 1, "  複写の 選択確定");
        jw_cmd_box_put(1413, "1,0.5");
        ck(!strcmp(bx(1413), "1000,500"), "  数値位置 1,0.5 は 1000,500");
        before = d->ndrawn;
        jw_cmd_enter_key(d);
        /* 範囲には前に引いた線も入るので、(10,0) の線の写しを探す */
        for (g = before, o = 0; g < d->ndrawn; g++)
            if (fabs(d->obj[g].d[2] - d->obj[g].d[0] - 10.0) < 1e-9)
                o = &d->obj[g];
        ck(o && fabs(o->d[0] - 1000.0 / s) < 1e-9 && fabs(o->d[1] - 500.0 / s) < 1e-9,
           "  置く先は 基準点 + 1000,500 ÷縮尺");
        jw_cmd_escape();
    }

    /* 距離指定点 の 距離 1412（FUN_006baad0）・分割 の 割付 の 距離 1412（FUN_007668f0） */
    app_command(JW_CMD_KYORITEN);
    jw_cmd_box_put(1412, "0.5");
    ck(!strcmp(bx(1412), "500"), "  距離指定点の 距離 0.5 は 500");
    jw_cmd_box_put(1412, "");
    app_command(JW_CMD_BUNKATSU);
    jw_cmd_box_put(1411, "3");
    if (jw_cmd_bar_check(1324) <= 0)
        jw_cmd_bar(d, 1324);
    jw_cmd_box_put(1412, "0.4");
    ck(!strcmp(bx(1412), "400"), "  分割の 割付 の 距離 0.4 は 400");
    jw_cmd_box_put(1412, "");
    jw_cmd_bar(d, 1324);
    ck(!strcmp(bx(1411), "3"), "  分割数 3 は 3 のまま");
    jw_cmd_box_put(1411, "");

    /* 状態表示の 線の長さ・矩形の W H・円の r は ÷1000 して ｍ（FUN_006edd60・006ee840・
       00647b40） */
    {
        const jw_view *v = app_view();
        const jw_obj *o;
        double s = 1.0;
        char want[96];
        int g, wg = 0;

        for (g = 0; g < 16; g++)
            if (d->group[g].state == 3)
                wg = g;
        if (d->group[wg].scale > 0.0)
            s = d->group[wg].scale;
        app_command(JW_CMD_SEN);
        jw_cmd_box_put(1412, "");
        if (jw_cmd_bar_check(1333) > 0)
            app_key(32);
        app_press(jw_sx(v, 0.0), jw_sy(v, 0.0), 0);
        app_press(jw_sx(v, 3.0), jw_sy(v, 4.0), 0);
        o = &d->obj[d->ndrawn - 1];
        snprintf(want, sizeof want, "   %.3f\x82\x8d",
                 hypot(o->d[2] - o->d[0], o->d[3] - o->d[1]) * s / 1000.0);
        ck(o->cls == JW_SEN && strstr(jw_cmd_status(d), want) != 0
           && !strcmp(jw_cmd_status(d) + strlen(jw_cmd_status(d)) - strlen(want), want),
           "  線の状態表示の長さは ÷1000 で末尾に ｍ");
        app_command(JW_CMD_ENKO);
        jw_cmd_box_put(1411, "");
        app_press(jw_sx(v, 0.0), jw_sy(v, 0.0), 0);
        app_press(jw_sx(v, 0.0), jw_sy(v, 2.0), 0);
        o = &d->obj[d->ndrawn - 1];
        snprintf(want, sizeof want, "r = %.3f\x82\x8d", o->d[2] * s / 1000.0);
        ck(o->cls == JW_ENKO && strstr(jw_cmd_status(d), want) != 0, "  円の r も ÷1000 で ｍ");
        app_command(JW_CMD_KUKEI);
        jw_cmd_box_put(1413, "");
        app_press(jw_sx(v, 0.0), jw_sy(v, 0.0), 0);
        app_press(jw_sx(v, 6.0), jw_sy(v, 2.0), 0);
        {
            char w2[96];
            const char *st = jw_cmd_status(d);
            const char *wp = strstr(st, "W=");

            snprintf(w2, sizeof w2, "%s", wp ? wp : "");
            ck(wp && strstr(w2, "H=") && w2[strlen(w2) - 2] == '\x82' && w2[strlen(w2) - 1] == '\x8d'
               && atof(w2 + 2) > 0.0 && atof(w2 + 2) < 6.0 * s / 1000.0 + 0.01,
               "  矩形の W H も ÷1000、H のあとに ｍ");
        }
        jw_cmd_escape();
    }

    /* ---- 切ればまた元どおり ---- */
    kh_press(1, 2526);
    kh_ok();
    app_command(JW_CMD_SEKIEN);
    jw_cmd_box_put(1411, "0.3");
    ck(!strcmp(bx(1411), "0.3") && strstr(jw_cmd_status(d), "[ r = 0.300 ]") != 0,
       "切れば 接円の 0.3 は 0.3、札も ｍ なし");
    jw_cmd_box_put(1411, "");
    app_command(JW_CMD_SEN);
    jw_cmd_box_put(1412, "1.5");
    ck(!strcmp(bx(1412), "1.5"), "切ればまた 1.5 は 1.5");
    l_off = sen_len(d, "1.5");
    ck(l_off > 0.0 && fabs(l_off - l_mm) > 1.0, "  寸法 1.5 は 1500 の長さではない");
    ck(strstr(jw_cmd_status(d), "]   ") != 0 && strstr(jw_cmd_status(d), "\x82\x8d") == 0,
       "  線の状態表示に ｍ は付かない");
    app_command(JW_CMD_KYORITEN);
    jw_cmd_box_put(1412, "0.5");
    ck(!strcmp(bx(1412), "0.5"), "  距離指定点の 距離 0.5 は 0.5");
    jw_cmd_box_put(1412, "");
    app_command(JW_CMD_NISEN);
    jw_cmd_box_put(1412, "100 , 200");
    jw_cmd_bar(d, 1066);
    ck(!strcmp(raw(1412), "200 , 400"), "  ２倍間隔 は 200 , 400");
    jw_cmd_box_put(1412, "");

    /* 複線の 留線付両側複線 (1069) は 留線出 1412 だけ蓋が外へ（FUN_0065be40 → FUN_0065e9e0） */
    {
        double e0 = -1.0, e1 = -1.0;
        int k, n0;

        for (k = 0; k < 2; k++) {
            const jw_obj *ln, *cap;
            jw_obj *o;


            app_new();
            d = (jw_drawing *)app_drawing();
            o = jw_add(d, JW_SEN);
            o->d[0] = -20.0;
            o->d[1] = 0.0;
            o->d[2] = 20.0;
            o->d[3] = 0.0;
            app_fit();
            jw_cmd_set(JW_CMD_TEN);
            jw_cmd_set(JW_CMD_FUKUSEN);
            jw_cmd_point(d, app_view(), 0.0, 0.0, 0);
            jw_cmd_box_put(1411, "10");
            jw_cmd_box_put(1412, k ? "5" : "");
            n0 = d->ndrawn;
            jw_cmd_bar(d, 1069);
            if (d->ndrawn != n0 + 4)
                break;
            ln = &d->obj[0];
            cap = &d->obj[n0];
            if (k)
                e1 = fabs(cap->d[0] - ln->d[0]) + fabs(cap->d[1] - ln->d[1]);
            else
                e0 = fabs(cap->d[0] - ln->d[0]) + fabs(cap->d[1] - ln->d[1]);
            jw_cmd_box_put(1412, "");
        }
        ck(e0 >= 0.0 && e1 >= 0.0 && fabs(e1 - e0 - 0.05) < 1e-9,
           "  留線出 5（1/100 で 0.05）の蓋は 空のときより その分だけ線の外へ出る");
    }

    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
