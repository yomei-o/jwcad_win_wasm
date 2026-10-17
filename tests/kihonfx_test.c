/* 基本設定 の、印が切り替わるだけだった箱を効かせたもの（2026-10-16）。
 *
 *   2532 用紙枠を表示する         用紙の四辺を線色 2 で描き、読取り点が四隅を拾う
 *   2362 矢印キーで画面移動…      ←↑→↓ で 移動率 (1951)、PageUp/Down で 拡大率 (1952)
 *   2094 複線の Enter で連続複線   間隔を打って Enter のたびに 前の写しから同じ側へ
 *   2437 クロスラインカーソル      マウスを通る縦横の二本（仮表示）
 *   1910・1907〜1909              色彩の初期化 で 背景色 白・黒・深緑 が押せ、箱に色が入る
 *
 * どれも逆コンパイルの読み（src/app.c・src/draw.c・src/cmd.c の注）で、原典では
 * 押していない。ここで確かめるのは 移植がその読みどおりに動くことだけ。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/draw.h"
#include "../src/jww.h"
#include "../src/pick.h"
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

static unsigned int pixel_at(double mx, double my)
{
    const fb_t *fb = app_fb();
    int x, y;

    px(mx, my, &x, &y);
    return fb->px[(size_t)y * fb->w + x] & 0xffffffu;
}

/* anything but bg within a pixel of there (the line may round to the next row) */
static int marked(double mx, double my, unsigned int bg)
{
    const fb_t *fb = app_fb();
    int x, y, i, j;

    px(mx, my, &x, &y);
    for (j = -1; j <= 1; j++)
        for (i = -1; i <= 1; i++)
            if ((fb->px[(size_t)(y + j) * fb->w + x + i] & 0xffffffu) != bg)
                return 1;
    return 0;
}

static void at(double mx, double my, int button)
{
    int x, y;

    px(mx, my, &x, &y);
    app_move(x, y);
    app_press(x, y, button);
    app_release(x, y, button);
}

/* press whatever on the showing dialog answers to this id (tab < 0: the tab -tab-1) */
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

/* open 基本設定, go to the tab and press the box there */
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

/* the text of the first box with that id on the tab */
static const char *kbox(int tab, int id)
{
    int i;

    for (i = 0; i < jw_kihon_tabs[tab].n; i++)
        if (jw_kihon_tabs[tab].c[i].id == id && jw_kihon_tabs[tab].c[i].kind == JW_KH_EDIT)
            return app_kihon_text(tab, i, 0, 0);
    return 0;
}

static jw_obj *line(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = x0; o->d[1] = y0; o->d[2] = x1; o->d[3] = y1;
    o->color = 2;
    o->ltype = 1;
    d->ndrawn = d->nobj;
    return o;
}

int main(void)
{
    jw_drawing *d;
    const jw_view *v;
    double hw, hh, rx, ry;
    unsigned int bg;
    int k, changed;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    app_fit();
    v = app_view();
    hw = d->paper_hw;
    hh = d->paper_hh;
    ck(hw > 0.0 && hh > 0.0, "新規の図面に用紙の大きさがある");

    /* ---- 2532 用紙枠 ---- */
    app_zoom(0.8, v->clip.x + v->clip.w / 2, v->clip.y + v->clip.h / 2);
    app_paint();
    bg = pixel_at(0.0, 0.0);
    ck(jw_draw_paper_frame == 0 && !marked(hw * 0.3, hh, bg), "既定は 用紙枠 なし（上の辺は地の色）");
    ck(!jw_read(d, v, hw - 0.3, hh - 0.3, &rx, &ry), "  読取り点も 用紙の隅を拾わない");
    ck(kh_press(0, 2532), "一般(1) の 用紙枠を表示する を押す");
    ck(jw_draw_paper_frame == 0, "  OK までは変わらない");
    kh_ok();
    ck(!app_kihon_open() && jw_draw_paper_frame == 1, "  OK で 用紙枠 が入る");
    app_paint();
    changed = 0;
    for (k = 1; k < 10; k++) {
        if (marked(-hw + 2.0 * hw * k / 10.0, hh, bg))
            changed++;
        if (marked(hw, -hh + 2.0 * hh * k / 10.0, bg))
            changed++;
    }
    ck(changed == 18, "  上の辺と右の辺に線が描かれる");
    ck(!marked(0.0, 0.0, bg) && !marked(hw * 0.5, hh * 0.5, bg), "  用紙の中は地のまま");
    ck(jw_read(d, v, hw - 0.3, hh - 0.3, &rx, &ry) && rx == hw && ry == hh,
       "  読取り点が 用紙の右上の隅を拾う");
    ck(jw_read(d, v, -hw + 0.3, -hh + 0.3, &rx, &ry) && rx == -hw && ry == -hh,
       "  左下の隅も");
    kh_press(0, 2532);
    kh_ok();
    app_paint();
    ck(jw_draw_paper_frame == 0 && !marked(hw * 0.3, hh, bg), "もう一度押して OK で消える（描いた絵の控えも替わる）");

    /* ---- 2362 矢印キー ---- */
    app_fit();
    {
        double ox = v->ox, oy = v->oy, mm = v->mmpp;
        double w = v->clip.w * v->mmpp, h = v->clip.h * v->mmpp;

        ck(!app_arrow_key(0x25) && v->ox == ox, "既定は 矢印キーで画面は動かない");
        ck(kh_press(1, 2362), "一般(2) の 矢印キーで画面移動 を押す");
        kh_ok();
        ck(app_arrow_key(0x25), "  OK のあと ← を受ける");
        ck(fabs(v->ox - (ox - 0.5 * w)) < 1e-9 && v->oy == oy, "  ← は 画面の幅の 0.5（移動率）だけ左へ");
        app_arrow_key(0x27);
        ck(fabs(v->ox - ox) < 1e-9, "  → で戻る");
        app_arrow_key(0x26);
        ck(fabs(v->oy - (oy + 0.5 * h)) < 1e-9, "  ↑ は 高さの 0.5 だけ上へ");
        app_arrow_key(0x28);
        ck(fabs(v->oy - oy) < 1e-9, "  ↓ で戻る");
        app_arrow_key(0x21);
        ck(fabs(v->mmpp - mm / 1.5) < 1e-12 * mm, "  PageUp は 1.5 倍（拡大率）");
        app_arrow_key(0x22);
        ck(fabs(v->mmpp - mm) < 1e-12 * mm, "  PageDown で戻る");
        /* 倍率の止め。原典で測った（PageDown は 12 回目で 0.01 に止まる、PageUp は
           18 回目で 1000 に止まる。1200 mm と 0.2 mm の線の画素の長さ） */
        {
            int k;

            for (k = 0; k < 11; k++)
                app_arrow_key(0x22);
            ck(fabs(v->mmpp - mm * pow(1.5, 11)) < 1e-9 * mm * pow(1.5, 11),
               "  PageDown 11 回は まだ止まらない（倍率 1.5^-11 = 0.0116）");
            app_arrow_key(0x22);
            ck(fabs(v->mmpp - mm * 100.0) < 1e-9 * mm,
               "  12 回目は 倍率 0.01 で止まる（0.0077 まで行かない）");
            app_arrow_key(0x22);
            ck(fabs(v->mmpp - mm * 100.0) < 1e-9 * mm, "  それ以上は動かない");
            app_arrow_key(0x21);
            ck(fabs(v->mmpp - mm * 100.0 / 1.5) < 1e-9 * mm, "  PageUp は止めから 1.5 倍に戻る");
            app_fit();
            for (k = 0; k < 17; k++)
                app_arrow_key(0x21);
            ck(fabs(v->mmpp - mm / pow(1.5, 17)) < 1e-9 * mm / pow(1.5, 17),
               "  PageUp 17 回は まだ止まらない（倍率 985）");
            app_arrow_key(0x21);
            ck(fabs(v->mmpp - mm / 1000.0) < 1e-12 * mm, "  18 回目は 倍率 1000 で止まる");
            app_arrow_key(0x21);
            ck(fabs(v->mmpp - mm / 1000.0) < 1e-12 * mm, "  それ以上は動かない");
            app_fit();
            ox = v->ox;
            oy = v->oy;
        }
        jw_cmd_set_axis(90.0);
        kh_press(1, 1325);
        kh_ok();
        ox = v->ox;
        oy = v->oy;
        app_arrow_key(0x27);
        ck(fabs(v->ox - ox) < 1e-9 && fabs(v->oy - (oy + 0.5 * w)) < 1e-9,
           "  軸角方向移動 (1325) と軸角 90° なら → は上へ");
        app_arrow_key(0x25);
        jw_cmd_set_axis(0.0);
        kh_press(1, 1325);
        kh_press(1, 2362);
        kh_ok();
        ck(!app_arrow_key(0x25), "  切ればまた受けない");
    }

    /* ---- 2094 連続複線 ---- */
    app_new();
    d = (jw_drawing *)app_drawing();
    app_fit();
    v = app_view();
    line(d, -50.0, 0.0, 50.0, 0.0);
    {
        double off;

        app_command(JW_CMD_FUKUSEN);
        at(0.0, 0.0, 0);
        jw_cmd_box_put(1411, "1000");
        {
            int x, y;

            px(0.0, 20.0, &x, &y);
            app_move(x, y);
        }
        app_key(13);
        ck(d->ndrawn == 1, "既定は 間隔を打っての Enter では写さない");
        ck(kh_press(0, 2094), "一般(1) の 複線…Enterキーで連続複線 を押す");
        kh_ok();
        app_command(JW_CMD_FUKUSEN);
        at(0.0, 0.0, 0);
        jw_cmd_box_put(1411, "1000");
        {
            int x, y;

            px(0.0, 20.0, &x, &y);
            app_move(x, y);
        }
        app_key(13);
        ck(d->ndrawn == 2, "  Enter で一本写る");
        off = d->ndrawn == 2 ? d->obj[1].d[1] : 0.0;
        ck(off > 0.0 && fabs(d->obj[1].d[3] - off) < 1e-9, "  マウスの側（上）へ 平行に");
        app_key(13);
        ck(d->ndrawn == 3 && fabs(d->obj[2].d[1] - 2.0 * off) < 1e-9,
           "  もう一度 Enter で 前の写しから同じ間隔でもう一本");
        app_key(13);
        ck(d->ndrawn == 4 && fabs(d->obj[3].d[1] - 3.0 * off) < 1e-9, "  三本目も");
        jw_cmd_undo(d);
        ck(d->ndrawn == 3, "  戻る で一本ずつ戻る");
        kh_press(0, 2094);
        kh_ok();
    }

    /* ---- 2437 クロスラインカーソル ---- */
    app_new();
    d = (jw_drawing *)app_drawing();
    app_fit();
    v = app_view();
    {
        int x, y, cx, cy;

        px(0.0, 0.0, &cx, &cy);
        app_move(cx, cy);
        app_paint();
        bg = pixel_at(30.0, 20.0);
        ck(!marked(30.0, 0.0, bg) && !marked(0.0, -40.0, bg), "既定は クロスラインカーソル なし");
        ck(kh_press(0, 2437), "一般(1) の クロスラインカーソルを使う を押す");
        kh_ok();
        px(0.0, 0.0, &x, &y);
        ck(app_move(x, y), "  OK のあと マウスが動けば描き直しを求める");
        app_paint();
        ck(marked(30.0, 0.0, bg) && marked(0.0, -40.0, bg), "  マウスを通る横と縦の線が出る");
        ck(!marked(30.0, 30.0, bg), "  斜めの所には出ない");
        kh_press(0, 2438);              /* 範囲指定のみ */
        kh_ok();
        app_command(JW_CMD_SEN);
        app_move(x, y);
        app_paint();
        ck(!marked(30.0, 0.0, bg), "  範囲指定のみ: 線の命令では出ない");
        app_command(0x8013);            /* 範囲選択 */
        app_move(x, y);
        app_paint();
        ck(marked(30.0, 0.0, bg), "  範囲選択の始点待ちでは出る");
        kh_press(0, 2438);
        kh_press(0, 2437);
        kh_ok();
        app_command(JW_CMD_SEN);
    }

    /* ---- 色・画面 の 色彩の初期化・背景色 ---- */
    app_new();
    d = (jw_drawing *)app_drawing();
    {
        unsigned int pen0 = d->pen_rgb[0];

        ck(kh_press(2, 1908) == 0, "背景色：黒 は はじめ押せない");
        ck(kh_press(2, 1910), "色彩の初期化 を押す");
        ck(kh_press(2, 1908), "  背景色：黒 が押せる");
        ck(kh_press(2, 1907) == 0, "  押したらまた押せない");
        ck(kbox(2, 2480) && !strcmp(kbox(2, 2480), "0") && !strcmp(kbox(2, 2481), "0")
           && !strcmp(kbox(2, 2482), "0"), "  背景色の箱が 0 0 0");
        ck(kbox(2, 1571) && !strcmp(kbox(2, 1571), "0") && !strcmp(kbox(2, 1572), "255")
           && !strcmp(kbox(2, 1573), "255"), "  線色 1 が 0 255 255");
        ck(d->pen_rgb[0] == pen0, "  OK までは図面は変わらない");
        kh_ok();
        ck((d->pen_rgb[0] & 0xffffffu) == 0 && (d->pen_rgb[1] & 0xffffffu) == 0x00ffffu
           && (d->pen_rgb[2] & 0xffffffu) == 0xffffffu, "  OK で図面の 背景・線色 1・2 が黒の組に");
        kh_press(2, 1910);
        ck(kh_press(2, 1909), "深緑");
        kh_ok();
        ck((d->pen_rgb[0] & 0xffffffu) == 0x002000u, "  背景色は 0 32 0");
        kh_press(2, 1910);
        ck(kh_press(2, 1907), "白");
        kh_ok();
        ck((d->pen_rgb[0] & 0xffffffu) == 0xffffffu && (d->pen_rgb[1] & 0xffffffu) == 0x00c0c0u
           && (d->pen_rgb[2] & 0xffffffu) == 0, "  背景 白、線色 1 は 0 192 192、線色 2 は黒");
    }

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
