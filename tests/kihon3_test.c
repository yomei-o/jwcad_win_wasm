/* 基本設定 の残りの小さいもの（2026-10-16、src/kihon3.h）。
 *
 *   2525 ［10\］を10,000(10m)に   箱の式の 一つの \ が 1000
 *   2527 初期ｺﾏﾝﾄﾞ：AUTOﾓｰﾄﾞ       レジストリの代わりを読んだ起動のとき AUTO
 *   2266・2267 ﾏｳｽﾎｲｰﾙ ＋ －       一刻みの倍率が 拡大・縮小率 (1952)
 *   1886・1900（・1563）           文字の輪郭・文字列範囲を背景色で
 *   1883（・1884 の九つ）          文字種を変えると 既にある字も（切なら任意サイズに）
 *
 * どれも逆コンパイルの読み（src/kihon3.h・src/draw.c text_bg・src/cmd.c box_calc の注）で、
 * 原典では押していない。ここで確かめるのは 移植がその読みどおりに動くことだけ。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/draw.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/kihon.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void px(double mx, double my, int *x, int *y)
{
    const jw_view *v = app_view();

    *x = (int)floor(v->bx + (mx - v->ox) * v->scale + 0.5);
    *y = (int)floor(v->by - (my - v->oy) * v->scale + 0.5);
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

/* 箱を押して字を打ち直す（最初の字が前の字に替わる） */
static int kh_type(int tab, int id, const char *s)
{
    if (!kh_press(tab, id))
        return 0;
    while (*s)
        app_key((unsigned char)*s++);
    return 1;
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
    return jw_cmd_box(id) ? jw_cmd_box(id) : "";
}

/* 横の一行（画面の y）で 地でない画素の数 */
static int row_marks(double mx0, double mx1, double my, unsigned int bg)
{
    const fb_t *fb = app_fb();
    int x0, x1, y, yy, x, n = 0;

    px(mx0, my, &x0, &y);
    px(mx1, my, &x1, &yy);
    for (x = x0; x <= x1; x++)
        if ((fb->px[(size_t)y * fb->w + x] & 0xffffffu) != bg)
            n++;
    return n;
}

static jw_obj *add_line(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x0; o->d[1] = y0; o->d[2] = x1; o->d[3] = y1;
    o->color = 2;
    o->ltype = 1;
    d->ndrawn = d->nobj;
    return o;
}

static jw_obj *add_text(jw_drawing *d, const char *s, double x, double y, double len,
                        double w, double h, int n)
{
    jw_obj *o = jw_add(d, JW_MOJI);

    o->d[0] = x; o->d[1] = y; o->d[2] = x + len; o->d[3] = y;
    o->d[4] = w; o->d[5] = h; o->d[6] = 0.0; o->d[7] = 0.0;
    o->color = 2;
    o->n = n;
    o->face = -1;
    o->text = jw_add_str(d, s);
    d->ndrawn = d->nobj;
    return o;
}

int main(void)
{
    jw_drawing *d;
    unsigned char *pb = 0;
    long pn = 0;
    unsigned int bg;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    app_fit();

    /* ---- 2525 ---- */
    app_command(JW_CMD_SEN);
    {
        int g;

        d->mesh_ix = 7.0;               /* x・y は 目盛間隔 × 縮尺（FUN_004f3b80、+0x7a28・+0x7a30） */
        d->mesh_iy = 3.0;
        for (g = 0; g < 16; g++)
            d->group[g].scale = 1.0;
    }
    ck(!strcmp(bar_sum(1412, "10\\"), "70"), "既定は \\ が x（10\\ は 10×x = 70）");
    ck(kh_press(1, 2525), "一般(2) の ［10\\］を10,000(10m)にする を押す");
    kh_ok();
    app_command(JW_CMD_SEN);
    ck(!strcmp(bar_sum(1412, "10\\"), "10000"), "  OK のあと 10\\ は 10000");
    ck(!strcmp(bar_sum(1412, "2.5\\+50"), "2550"), "  2.5\\+50 は 2550");
    ck(!strcmp(bar_sum(1412, "10\\\\"), "70"), "  \\\\ は x（二つ続けて x。10×7）");
    kh_press(1, 2525);
    kh_ok();
    app_command(JW_CMD_SEN);
    ck(!strcmp(bar_sum(1412, "10\\"), "70"), "  切ればまた x");
    bar_sum(1412, "");

    /* ---- 2266・2267 ﾏｳｽﾎｲｰﾙ ---- */
    ck(app_wheel_factor(120) == 0.0 && app_wheel_factor(-120) == 0.0,
       "既定は ホイールの倍率を表側の 1.25 に任せる");
    ck(kh_press(1, 2266), "ﾏｳｽﾎｲｰﾙ ＋ を押す");
    kh_ok();
    ck(fabs(app_wheel_factor(-120) - 1.5) < 1e-12 && fabs(app_wheel_factor(120) - 1.0 / 1.5) < 1e-12,
       "  ＋: 手前で 拡大・縮小率 1.5 倍、奥で 1/1.5");
    kh_press(1, 2266);
    kh_press(1, 2267);
    kh_ok();
    ck(fabs(app_wheel_factor(120) - 1.5) < 1e-12 && fabs(app_wheel_factor(-120) - 1.0 / 1.5) < 1e-12,
       "  －: 向きが逆");
    kh_press(1, 2267);
    kh_ok();
    ck(app_wheel_factor(120) == 0.0, "  両方切れば また 1.25 に任せる");

    /* ---- 2527 初期コマンド AUTO ---- */
    ck(kh_press(0, 2527), "一般(1) の 初期ｺﾏﾝﾄﾞ：AUTOﾓｰﾄﾞ を押す");
    kh_ok();
    app_command(JW_CMD_SEN);
    ck(jw_cmd() == JW_CMD_SEN, "  OK だけでは命令は替わらない");
    ck(app_prefs_write(&pb, &pn) && pb && pn > 0, "  設定を書き出す");
    kh_press(0, 2527);
    kh_ok();
    ck(pb && app_prefs_read(pb, pn) > 0, "  起動のときのように読み直す");
    ck(jw_cmd() == JW_CMD_AUTO, "  起動のあとは AUTO から");
    app_command(JW_CMD_SEN);
    if (pb)
        app_prefs_read(pb, pn);
    ck(jw_cmd() == JW_CMD_SEN, "  読み直しは一度だけ効く（起動のときだけ）");
    app_new();
    ck(jw_cmd() == JW_CMD_SEN, "  新規はこれまでどおり 線");
    kh_press(0, 2527);
    kh_ok();
    free(pb);

    /* ---- 1886・1900 ---- */
    app_new();
    d = (jw_drawing *)app_drawing();
    app_fit();
    add_line(d, -100.0, 5.0, 100.0, 5.0);           /* 字の高さの真ん中を通る */
    add_text(d, "WWWW", -20.0, 0.0, 40.0, 10.0, 10.0, 0);
    add_text(d, "    ", 40.0, 0.0, 40.0, 10.0, 10.0, 0);   /* 空白だけ: 下地だけが見える */
    app_paint();
    bg = d->pen_rgb[0] & 0xffffffu;
    {
        int plain = row_marks(-19.0, 19.0, 5.0, bg), sp = row_marks(42.0, 78.0, 5.0, bg);
        int outl, range_sp, range_w;

        ck(plain > 0 && sp > 0, "既定は 字の上を線が通っている（空白の字の所も）");
        ck(kh_press(4, 1563) == 0, "  範囲増寸法 は 文字列範囲 を入れるまで押せない");
        ck(kh_press(4, 1886), "文字 の 文字の輪郭を背景色で描画 を押す");
        kh_ok();
        ck(jw_draw_text_bg == 1, "  OK で輪郭");
        app_paint();
        outl = row_marks(-19.0, 19.0, 5.0, bg);
        ck(outl < plain, "  字のまわりで線が背景色に消される");
        ck(row_marks(42.0, 78.0, 5.0, bg) == sp, "  空白の字の所は線のまま");
        ck(row_marks(-90.0, -30.0, 5.0, bg) == row_marks(-90.0, -30.0, 5.0, bg) && row_marks(-90.0, -30.0, 5.0, bg) > 0,
           "  字の外の線はそのまま");
        ck(kh_press(4, 1900), "文字列範囲を背景色で描画 を押す");
        ck(kh_press(4, 1563), "  範囲増寸法 が押せるようになる");
        kh_ok();
        ck(jw_draw_text_bg == 2, "  OK で範囲（1886 は切れる）");
        app_paint();
        range_sp = row_marks(42.0, 78.0, 5.0, bg);
        range_w = row_marks(-19.0, 19.0, 5.0, bg);
        ck(range_sp == 0, "  空白の字の範囲は線が消える");
        ck(range_w < plain, "  WWWW の範囲も（字だけが残る）");
        ck(row_marks(-90.0, -30.0, 5.0, bg) > 0, "  範囲の外の線はそのまま");
        kh_type(4, 1563, "5");
        kh_ok();
        app_paint();
        ck(jw_draw_text_bg_expand == 5.0, "  範囲増寸法 に 5 を打って OK");
        ck(row_marks(81.0, 84.0, 5.0, bg) == 0, "  範囲の外 5 mm まで消える");
        kh_type(4, 1563, "0");
        kh_press(4, 1900);
        kh_ok();
        app_paint();
        ck(jw_draw_text_bg == 0 && row_marks(-19.0, 19.0, 5.0, bg) == plain,
           "  切ればもとの絵");
    }

    /* ---- 1883 ---- */
    app_new();
    d = (jw_drawing *)app_drawing();
    app_fit();
    {
        double w0 = d->style[0].w, h0 = d->style[0].h, sp0 = d->style[0].sp;
        jw_obj *a, *b, *c;
        char buf[32];

        a = add_text(d, "AB", 0.0, 0.0, w0 * 2.0 + d->style[0].sp, w0, h0, 1);
        b = add_text(d, "AB", 0.0, 50.0, 7.0, 3.5, 3.5, 0);
        c = add_text(d, "AB", 0.0, 100.0, w0 * 2.0 + d->style[0].sp, w0, h0, 1 + 10000);
        (void)b;
        ck(kh_press(4, 1689) == 0, "変更基準点 は 1883 を入れるまで押せない");
        snprintf(buf, sizeof buf, "%g", w0 * 2.0);
        kh_type(4, 2470, buf);      /* 文字種 1 の 横 */
        kh_ok();
        a = &d->obj[0];
        c = &d->obj[2];
        ck(d->style[0].w == w0 * 2.0, "文字種 1 の 横 を二倍に");
        ck(a->n == 0 && a->d[4] == w0, "  1883 が切なら 既にある字は 任意サイズ（大きさはそのまま）");
        ck(c->n == 10000, "  斜体の桁は残る");
        ck(d->obj[1].n == 0 && d->obj[1].d[4] == 3.5, "  任意サイズの字は触らない");
        a->n = 1;
        a->d[4] = d->style[0].w;
        ck(kh_press(4, 1883), "既に作図されている文字のサイズも変更する を押す");
        ck(kh_press(4, 1689), "  変更基準点 中下 が押せる");
        kh_type(4, 2470, "3");
        kh_ok();
        ck(a->n == 1 && a->d[4] == 3.0, "  文字種 1 の字は 横 3 に");
        {
            double was_mid = (w0 * 2.0 + sp0) / 2.0;   /* 前の長さの真ん中 */
            double run = (3.0 + sp0) * 0.5 * 2 - sp0 * 0.5;
            double mid = (a->d[0] + a->d[2]) / 2.0;

            ck(fabs(a->d[2] - a->d[0] - run) < 1e-9, "  長さは 二字の 横と間隔 から");
            ck(fabs(mid - was_mid) < 1e-9 && a->d[1] == 0.0, "  中下: 真ん中を動かさない");
        }
        kh_press(4, 1884);
        kh_type(4, 1532, "8");      /* 文字種 1 の 縦 */
        kh_ok();
        ck(a->d[5] == 8.0, "  縦 も");
        kh_press(4, 1694);          /* 左上 */
        kh_type(4, 1532, "4");
        kh_ok();
        ck(fabs(a->d[1] - 4.0) < 1e-9, "  左上: 上の辺を動かさない（縦 8→4 で 4 上へ）");
        kh_press(4, 1884);
        kh_press(4, 1883);
        kh_ok();
    }

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
