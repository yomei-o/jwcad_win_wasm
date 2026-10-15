/* 基本設定 の残りの小さいもの（2026-10-16、kihon3）。stb 流で 中身は src/app.c の
 * 中（#include "kihon3.h"）。app.c の drawing・kh_value_tab・kh_num などを使う。
 * どれも逆コンパイルの読みで、原典では押していない。
 *
 *   一般(1) 2527 初期ｺﾏﾝﾄﾞ：AUTOﾓｰﾄﾞ      起動のとき AUTO から
 *   一般(2) 2525 ［10\］を10,000(10m)に    箱の式の \ を 1000（src/cmd.c box_calc）
 *   一般(2) 2266 ＋ / 2267 －（ﾏｳｽﾎｲｰﾙ）    ホイールで 拡大・縮小率 (1952) の倍率
 *   文字    1886 輪郭を背景色・1900 範囲を背景色・1563 範囲増寸法（src/draw.c text_bg）
 *   文字    1883 既に作図されている文字のサイズも変更する（1884 の九つの 変更基準点）
 */
#ifndef KIHON3_H
#define KIHON3_H

static int kh_on_get(int tab, int id);
static void kh_on_set(int tab, int id, int on);

/* ---- 2266・2267 ﾏｳｽﾎｲｰﾙ ----
 * OK FUN_005d02e0 が +0xa88 (2266)・+0xa8c (2267) から DAT_00a0d8a0 を 1・-1・0
 * （前が ±3 なら ±3）にする。ホイール FUN_0050a660 は DAT_00a0d8a0 が 0 なら
 * 窓の既定へ、でなければ 負なら回した向きを裏返して、手前（WHEEL_DELTA が負）なら
 * CZoom 0x79、奥なら 0x7a を マウスの点で作る。CZoom の後始末 FUN_0060b110 の
 * 0x79 は 倍率 (+0x1728) × 拡大率 (DAT_00a0d870 = 1952)・マウスの点を動かさない、
 * 0x7a は ÷。±3 の扱い（FUN_00508e60 の ホイールボタンの側）は入れていない。
 * 移植は 0 のとき（既定）前からの 1.25 倍・奥で拡大 のまま。 */
static int kh3_wheel;

/* the factor the wheel zooms by for one notch: delta > 0 is turned away
   from the user (WHEEL_DELTA positive).  0 when the setting leaves the
   wheel to the front end's own 1.25 */
double app_wheel_factor(int delta)
{
    double r = kh_zoom_rate;

    if (!kh3_wheel || !delta || !(r > 0.0))
        return 0.0;
    if (kh3_wheel < 0)
        delta = -delta;
    return delta < 0 ? r : 1.0 / r;
}

/* ---- 2527 初期コマンド AUTO ----
 * OK FUN_005cd940 が +0xbb8 (2527) で DAT_00a0cbd4 に 1 を足す（2 の桁は残す）。
 * 起動の OnInitialUpdate FUN_00506900 は 命令がまだ無い（view+0x2164 == 0）とき
 * DAT_00a0cbd4 が 0 なら FUN_0050dc90 = 線 (0x8003)、でなければ FUN_0050da90 =
 * AUTO (0x8093)。移植は 起動のあと 表側が レジストリの代わり（app_prefs_read）を
 * 読んだところで一度だけ（新規・開くでは 前のとおり 線）。 */
static int kh3_started;

static void kh3_startup(void)
{
    if (kh3_started)
        return;
    kh3_started = 1;
    if (kh_value_tab(0, 2527) && jw_cmd() == JW_CMD_SEN)
        jw_cmd_set(JW_CMD_AUTO);
}

/* ---- OK で効かせるもの ---- */
static void kh3_apply(void)
{
    double ex;

    jw_cmd_yen_m(kh_value_tab(1, 2525));
    kh3_wheel = kh_value_tab(1, 2266) ? 1 : kh_value_tab(1, 2267) ? -1 : 0;
    /* doc+0x82c8: 0、1886 なら 1、1900 なら 2（あとが勝つ）。1563 は DDV -1〜10 */
    jw_draw_text_bg = kh_value_tab(4, 1900) ? 2 : kh_value_tab(4, 1886) ? 1 : 0;
    ex = kh_num(4, 1563, 0.0);
    if (ex >= -1.0 && ex <= 10.0)
        jw_draw_text_bg_expand = ex;
}

/* ---- 1883 既に作図されている文字のサイズも変更する ----
 * 文字 の OK FUN_00584920 は 文字種 1〜10 ごとに 横・縦・間隔・色 が前と違えば
 * DAT_00a0bbb8[k] を立てる。基本設定 のあと FUN_0050e230 が FUN_00475d80 を呼び、
 * 図面の字で 文字種 (+0xb4) が k のものを:
 *   1883 (DAT_00a0bbb4、押したとき FUN_00586840 が入れる) が入っていれば
 *     FUN_0046fd90(DAT_00a0bba0, …) で 新しい 横・縦・間隔・色 にし、
 *     長さ L（FUN_004935b0(1)）を 変更基準点 DAT_00a0bba0（1884 の九つ、
 *     左下 0 中下 1 右下 2 左中 3 … 右上 8）で置き直す: 横は 中なら
 *     始点 = 真ん中 - L/2、右なら 終点 - L、縦は 中なら (古い高さ - 新しい高さ)/2、
 *     上ならその二倍だけ字の上向きへ（縦字は高さの代わりに幅）
 *   切なら 文字種を 0（任意サイズ）に（窓の字「変更しない場合は、任意サイズになる」）
 * 移植の 文字種 は n の 10000 未満（斜体・太字は 10000・20000 の桁）。寸法図形の
 * 字（CDataSunpou の +0x184、FUN_00478b80 → FUN_004787e0）は 切 で 0 にするだけ、
 * 入 での置き直しは入れていない。戻る では戻らない（原典の undo は読んでいない）。 */
typedef struct {
    double w, h, sp;
    int color;
} kh3_style_t;

static void kh3_style_take(kh3_style_t *s)
{
    int k;

    for (k = 0; k < 10; k++) {
        s[k].w = drawing.style[k].w;
        s[k].h = drawing.style[k].h;
        s[k].sp = drawing.style[k].sp;
        s[k].color = drawing.style[k].color;
    }
}

/* 1884 の九つのどれが入っているか（左下 0 … 右上 8） */
static int kh3_base(void)
{
    static const short ID[9] = { 1884, 1689, 1690, 1691, 1692, 1693, 1694, 1695, 1696 };
    int k;

    for (k = 0; k < 9; k++)
        if (kh_value_tab(4, ID[k]))
            return k;
    return 0;
}

/* FUN_004935b0(1) の長さ（src/cmd.c zoku_moji と同じ式） */
static double kh3_run(const char *t, double cw, double sp)
{
    int nb = 0, wide = 0;

    while (t && *t) {
        wide = jw_is_lead((unsigned char)t[0]) && t[1];
        nb += wide ? 2 : 1;
        t += wide ? 2 : 1;
    }
    return nb < 1 ? 0.0 : nb == 1 ? cw / 2.0
         : (cw + sp) * 0.5 * nb - (wide ? sp : sp * 0.5);
}

static void kh3_resize(jw_obj *o, double w, double h, double sp, int color, int base)
{
    int tate = (o->flags & 0x20) != 0, hb = base % 3, vb = base / 3;
    double oldh = tate ? o->d[4] : o->d[5], newh = tate ? w : h;
    double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
    double olen = sqrt(dx * dx + dy * dy);
    double a = olen > 0.0 ? atan2(dy, dx) : o->d[7] * 3.14159265358979323846 / 180.0;
    double c = cos(a), s = sin(a), run, x0 = 0.0, y0 = 0.0;
    const char *t = o->text >= 0 ? jw_str(&drawing, o->text) : "";

    o->d[4] = w;
    o->d[5] = h;
    o->d[6] = sp;
    if (color >= 1 && color <= 9)
        o->color = (unsigned short)color;
    run = kh3_run(t, tate ? h : w, sp);
    if (hb == 1)
        x0 = olen / 2.0 - run / 2.0;
    else if (hb == 2)
        x0 = olen - run;
    if (vb == 1)
        y0 = (oldh - newh) / 2.0;
    else if (vb == 2)
        y0 = oldh - newh;
    {
        double sx = o->d[0] + x0 * c - y0 * s, sy = o->d[1] + x0 * s + y0 * c;

        o->d[0] = sx;
        o->d[1] = sy;
        o->d[2] = sx + run * c;
        o->d[3] = sy + run * s;
    }
}

static void kh3_restyle(const kh3_style_t *was)
{
    int changed[11], any = 0, k, i, on, base;

    if (!have_drawing)
        return;
    for (k = 0; k < 10; k++) {
        changed[k + 1] = was[k].w != drawing.style[k].w || was[k].h != drawing.style[k].h
                         || was[k].sp != drawing.style[k].sp
                         || was[k].color != drawing.style[k].color;
        any |= changed[k + 1];
    }
    if (!any)
        return;
    on = kh_value_tab(4, 1883);
    base = kh3_base();
    for (i = 0; i < drawing.ndrawn; i++) {
        jw_obj *o = &drawing.obj[i];

        if (o->cls != JW_MOJI || o->n < 0)
            continue;
        k = o->n % 10000;
        if (k < 1 || k > 10 || !changed[k])
            continue;
        if (!on)
            o->n -= k;                  /* 任意サイズ */
        else if (!o->sub)
            kh3_resize(o, drawing.style[k - 1].w, drawing.style[k - 1].h,
                       drawing.style[k - 1].sp, drawing.style[k - 1].color, base);
    }
}

/* ---- 押したときの連れ ----
 * 1884 の九つは一組の丸釦（WS_GROUP 1884 から 1696 まで）。1900 を入れると
 * 1887 が入り 1886 が切れる（FUN_00586980）、1886 を入れると 1887 が入り 1900 が
 * 切れる（FUN_005869e0）。1 を返したら 押した処理は済み */
static int kh3_press(int tab, int id)
{
    static const short ID[9] = { 1884, 1689, 1690, 1691, 1692, 1693, 1694, 1695, 1696 };
    int k;

    if (tab != 4)
        return 0;
    for (k = 0; k < 9; k++)
        if (ID[k] == id) {
            int j;

            for (j = 0; j < 9; j++)
                kh_on_set(4, ID[j], j == k);
            return 1;
        }
    return 0;
}

static void kh3_after_press(int tab, int id)
{
    if (tab == 4 && (id == 1886 || id == 1900) && kh_on_get(4, id)) {
        kh_on_set(4, 1887, 1);
        kh_on_set(4, id == 1886 ? 1900 : 1886, 0);
    }
}

/* 押せる・押せない: 1884 の九つ・変更基準点の枠 1885・1917 は 1883 が入って
   いるとき（FUN_00586840 の EnableWindow）、範囲増寸法 2259・1563 は 1900 が
   入っているとき（窓の型では WS_DISABLED）。-1 はこれの知らない部品 */
static int kh3_enabled(int tab, int id)
{
    if (tab != 4)
        return -1;
    if (id == 1884 || (id >= 1689 && id <= 1696) || id == 1885 || id == 1917)
        return kh_on_get(4, 1883);
    if (id == 2259 || id == 1563)
        return kh_on_get(4, 1900);
    return -1;
}

#endif
