/* 両ボタンドラッグ・両ボタンクリック（原典の CZoom）。
 *
 * 原典は左右のボタンの片方を押したままもう片方を押すと CZoom を作り
 * （CJw_winView の左押し FUN_00507d00・右押し FUN_0050d070 が、もう片方の
 * 押しの旗 view+0x90cc／+0x90c8 を見て FUN_004fcdb0 へ）、押した点が起点、
 * マウスが動くたびに FUN_0060c6a0 が向きを決めて枠と字を出し、二つとも
 * 離れたところで（左離し FUN_005081c0・右離し FUN_0050d3f0）後始末
 * FUN_0060b110 がその向きの仕事をする:
 *
 *     dx = いま − 起点、dy も（画面の y は下が正）。しきい s は 基本設定
 *     一般(2) の「[移動］の両ボタンドラッグ範囲」(1950、既定 10 → DAT_00a0d8c8)
 *       |dx| < s かつ |dy| < s    5 移動（起点を画面の真ん中へ。倍率はそのまま）
 *       |dx| < s か |dy| < s だけ  0 何もしない（真上・真右・真下・真左は
 *                                  1946〜1949 のマークジャンプ。既定 0 は無指定）
 *       dx > 0, dy > 0  ↘         1 範囲拡大（枠を窓いっぱいに）
 *       dx ≤ 0, dy ≤ 0  ↖         2 縮小（起点を真ん中に半分）
 *       dx ≤ 0, dy > 0  ↙         3 前倍率
 *       dx > 0, dy ≤ 0  ↗         4 全体（表示範囲記憶 があればそこ）
 *
 * 字は文字列 5135〜5139（0x140f〜0x1413）、全体 は 表示範囲記憶 が
 * 1 倍・(0,0) でなければ 5273「(範 囲)」。起点の右 2・上 16 画素に
 * 文字色 doc+0x52b0（既定 0xc8c8c8）で。枠は 範囲拡大 のときだけで、
 * 線 doc+0x52b4（既定 0x808080）の R2_NOTXORPEN・中は塗らない
 * （FUN_0060c570 のペンと NULL_BRUSH、FUN_005887e0 の Rectangle）。
 * 逆コンパイルの読み、原典では押していない。
 *
 * 移植の命令は 押した瞬間に点を受ける（app_press）ので、表側は 図面の
 * 上での左押しを預かり、離すか少し動くまでに右が来れば両ボタンにする
 * （原典の命令も点を受けるのは左の離しのとき）。src/main_win32.c と
 * index.html。
 *
 * 作りは stb 流: 中身は JW_RYOBOTON_IMPL を立てた src/app.c の中にある
 * （ビルドの源の並びを触らずに済むように）。 */
#ifndef JW_RYOBOTON_H
#define JW_RYOBOTON_H

#include "fb.h"

enum { RYO_NONE, RYO_KAKUDAI, RYO_SHUKUSHO, RYO_MAEBAI, RYO_ZENTAI, RYO_IDO };

/* 向きの判定（FUN_0060c6a0 の前半）。dx, dy は起点からの画素、s はしきい */
int  ryo_kind(int dx, int dy, int s);
/* 1950 のしきい（原典は箱の数を (int) にしてそのまま） */
void ryo_set_slop(int px);
int  ryo_slop(void);
/* 左押しを預かってよい所か: 図面の範囲の中で、ポップアップが開いていない */
int  ryo_holdable(int x, int y);
/* 両ボタンになった（起点）・動いた・二つとも離れた。end は判定どおりに
   app_zoom_rect／app_zoom_out／app_zoom_prev／app_zoom_all か 画面移動 を
   して、何かしたら 1。cancel は何もせずにやめる */
void ryo_begin(int x, int y);
void ryo_move(int x, int y);
int  ryo_end(void);
void ryo_cancel(void);
int  ryo_active(void);
/* いまの判定（ryo_active でなければ RYO_NONE） */
int  ryo_now(void);
/* 枠と字（app_paint が描く） */
void ryo_paint(fb_t *fb);

#endif

#ifdef JW_RYOBOTON_IMPL
#undef JW_RYOBOTON_IMPL

static int ryo_s = 10, ryo_on, ryo_x0, ryo_y0, ryo_x1, ryo_y1;

int ryo_kind(int dx, int dy, int s)
{
    int ax = dx < 0 ? -dx : dx, ay = dy < 0 ? -dy : dy;

    if (ax < s && ay < s)
        return RYO_IDO;
    /* 真っすぐの向きは FUN_0060cef0(1, 向き) が 1 を返して 0 になる
       （マークジャンプの設定が 0 でも） */
    if (ax < s || ay < s)
        return RYO_NONE;
    if (dx < 1)
        return dy < 1 ? RYO_SHUKUSHO : RYO_MAEBAI;
    return dy < 1 ? RYO_ZENTAI : RYO_KAKUDAI;
}

void ryo_set_slop(int px)
{
    ryo_s = px;
}

int ryo_slop(void)
{
    return ryo_s;
}

int ryo_holdable(int x, int y)
{
    rect_t r;

    if (!view_ready || ui_popup_up())
        return 0;
    ui_view_rect(fb.w, fb.h, &r);
    return x >= r.x && y >= r.y && x < r.x + r.w && y < r.y + r.h;
}

void ryo_begin(int x, int y)
{
    ryo_on = 1;
    ryo_x0 = ryo_x1 = x;
    ryo_y0 = ryo_y1 = y;
}

void ryo_move(int x, int y)
{
    if (!ryo_on)
        return;
    ryo_x1 = x;
    ryo_y1 = y;
}

int ryo_active(void)
{
    return ryo_on;
}

int ryo_now(void)
{
    return ryo_on ? ryo_kind(ryo_x1 - ryo_x0, ryo_y1 - ryo_y0, ryo_s) : RYO_NONE;
}

void ryo_cancel(void)
{
    ryo_on = 0;
}

int ryo_end(void)
{
    int k = ryo_now();

    ryo_on = 0;
    switch (k) {
    case RYO_KAKUDAI:
        app_zoom_rect(ryo_x0, ryo_y0, ryo_x1, ryo_y1);
        return 1;
    case RYO_SHUKUSHO:
        app_zoom_out(ryo_x0, ryo_y0);
        return 1;
    case RYO_MAEBAI:
        app_zoom_prev();
        return 1;
    case RYO_ZENTAI:
        app_zoom_all(0);
        return 1;
    case RYO_IDO:
        /* 起点を真ん中へ（FUN_0060b110 の 5: FUN_004b8a00 で起点の用紙の点を
           +0x7a18 へ。前倍率 の控えは触らない） */
        if (!view_ready)
            return 0;
        app_pan(view.bx - ryo_x0, view.by - ryo_y0);
        return 1;
    }
    return 0;
}

static void ryo_px(fb_t *f, const rect_t *c, int x, int y)
{
    unsigned int *p;

    if (x < c->x || y < c->y || x >= c->x + c->w || y >= c->y + c->h)
        return;
    p = &f->px[y * f->w + x];
    *p = ~(0x808080u ^ *p) & 0xffffffu;           /* R2_NOTXORPEN */
}

void ryo_paint(fb_t *f)
{
    static const char *const word[6] = {
        0,
        "  \x8a" "g  \x91\xe5  ",                       /* 5135 拡  大 */
        "  \x8f" "k  \x8f\xac  ",                       /* 5136 縮  小 */
        "  \x91" "O\x94{\x97\xa6  ",                    /* 5137 前倍率 */
        "  \x91" "S  \x91\xcc  ",                       /* 5138 全  体 */
        "  \x88\xda  \x93\xae  " };                     /* 5139 移  動 */
    const char *w;
    rect_t c;
    int k = ryo_now(), x, y, xa, xb, ya, yb;

    if (!ryo_on || !view_ready)
        return;
    ui_view_rect(f->w, f->h, &c);
    if (k == RYO_KAKUDAI) {
        xa = ryo_x0 < ryo_x1 ? ryo_x0 : ryo_x1;
        xb = ryo_x0 < ryo_x1 ? ryo_x1 : ryo_x0;
        ya = ryo_y0 < ryo_y1 ? ryo_y0 : ryo_y1;
        yb = ryo_y0 < ryo_y1 ? ryo_y1 : ryo_y0;
        /* Rectangle は右と下の辺を一つ内側に描く */
        for (x = xa; x < xb; x++) {
            ryo_px(f, &c, x, ya);
            if (yb - 1 > ya)
                ryo_px(f, &c, x, yb - 1);
        }
        for (y = ya + 1; y < yb - 1; y++) {
            ryo_px(f, &c, xa, y);
            if (xb - 1 > xa)
                ryo_px(f, &c, xb - 1, y);
        }
    }
    if (k == RYO_NONE)
        return;
    w = word[k];
    if (k == RYO_ZENTAI && (vw_mem.z != 1.0 || vw_mem.x != 0.0 || vw_mem.y != 0.0))
        w = " (\x94\xcd \x88\xcd)  ";                    /* 5273 (範 囲) */
    jw_text_px(f, ryo_x0 + 2, ryo_y0 - 16, w, 0xc8c8c8u);
}

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
/* ブラウザから（index.html）。y は画布の座標（上の飾りの分を引く） */
EMSCRIPTEN_KEEPALIVE int jw_ryo_holdable(int x, int y)
{
    return ryo_holdable(x, y - app_chrome_h());
}

EMSCRIPTEN_KEEPALIVE void jw_ryo_begin(int x, int y)
{
    ryo_begin(x, y - app_chrome_h());
    app_paint();
}

EMSCRIPTEN_KEEPALIVE void jw_ryo_move(int x, int y)
{
    ryo_move(x, y - app_chrome_h());
    app_paint();
}

EMSCRIPTEN_KEEPALIVE int jw_ryo_end(void)
{
    int r = ryo_end();

    app_paint();
    return r;
}

EMSCRIPTEN_KEEPALIVE void jw_ryo_cancel(void)
{
    ryo_cancel();
    app_paint();
}

/* cdp の確かめ用: いまの判定（0〜5、両ボタンでなければ -1） */
EMSCRIPTEN_KEEPALIVE int jw_ryo_now(void)
{
    return ryo_on ? ryo_now() : -1;
}
#endif

#endif
