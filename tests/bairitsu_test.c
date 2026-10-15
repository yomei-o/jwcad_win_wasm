/* 画面倍率・文字表示 (32811) -- the dialog, against the original's own.
 *
 *   tests/bairitsu_test.exe tests/out/bairitsu.png
 *
 * docs/ref_bairitsu.png is that dialog painted into a bitmap by Jw_cad
 * itself.  This puts the port's up in the same state and writes it out to
 * be scored against that picture; tools/check.sh does the scoring, with the
 * text left out of it.
 *
 * 後半は釦ごとの働き（src/app.c の press_bairitsu、CGamenBairitsuDialog の
 * 逆コンパイルの読み、原典では押していない）と 前倍率 の控え（app_zoom_*、
 * CZoom の 1〜4）、縮尺・読取 の 実寸固定 と 文字サイズ変更・点マーカサイズ
 * 変更（CScaleDialog の OnOK）。原典の画面は写せないので、答えは読みから
 * 出した数（倍率の表示・真ん中の点・要素の座標）で見る。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/bairitsu.h"
#include "../src/gen/shakudo.h"
#include "png.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

static int open_file(const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);
    int ok = b && app_open(b, n);

    free(b);
    return ok;
}

static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_bairitsu_rect(1264, 741, &r);
    for (i = 0; i < JW_NBAIRITSU; i++)
        if (jw_bairitsu[i].id == id) {
            *x = r.x + JW_BR_BORDER + jw_bairitsu[i].x + jw_bairitsu[i].w / 2;
            *y = r.y + JW_BR_CAPTION + jw_bairitsu[i].y
                 + jw_bairitsu[i].h / 2;
            return;
        }
    *x = *y = -1;
}

static void br(int id)
{
    int x, y;

    if (!app_bairitsu_open())
        app_command(32811);
    ctl(id, &x, &y);
    app_press(x, y, 0);
}

static void sk(int id)
{
    rect_t r;
    int i;

    ui_shakudo_rect(1264, 741, &r);
    for (i = 0; i < (int)(sizeof jw_shakudo / sizeof jw_shakudo[0]); i++)
        if (jw_shakudo[i].id == id) {
            app_press(r.x + JW_SK_BORDER + jw_shakudo[i].x + 4,
                      r.y + JW_SK_CAPTION + jw_shakudo[i].y
                      + jw_shakudo[i].h / 2, 0);
            return;
        }
}

/* 状態行の倍率（view.scale × 画面のミリ毎画素） */
static double readout(void)
{
    return app_view()->scale * JW_SCREEN_MM_PER_PX;
}

static int near_(double a, double b, double e)
{
    return fabs(a - b) <= e;
}

static int same_view(const jw_view *a, const jw_view *b)
{
    return near_(a->mmpp, b->mmpp, 1e-12 * a->mmpp)
           && near_(a->ox, b->ox, 1e-9) && near_(a->oy, b->oy, 1e-9);
}

static int write_group(void)
{
    const jw_drawing *d = app_drawing();
    int g, wg = 0;

    for (g = 0; g < 16; g++)
        if (d->group[g].state == 3)
            wg = g;
    return wg;
}

/* 図面の領域の白でない画素 */
static long inked(void)
{
    const fb_t *fb = app_fb();
    rect_t r;
    long k = 0;
    int x, y;

    ui_view_rect(fb->w, fb->h, &r);
    for (y = r.y; y < r.y + r.h; y++)
        for (x = r.x; x < r.x + r.w; x++)
            if ((fb->px[(size_t)y * fb->w + x] & 0xffffffu) != 0xffffffu)
                k++;
    return k;
}

static void type(const char *s)
{
    for (; *s; s++)
        app_key((unsigned char)*s);
}

static void zoom_parts(void)
{
    const fb_t *fb = app_fb();
    rect_t r;
    jw_view fit, v1, v2;
    int cx, cy, wg;

    ck(open_file("orig/Test5.jww"), "Test5 を開き直す");
    ui_view_rect(fb->w, fb->h, &r);
    cx = r.x + r.w / 2;
    cy = r.y + r.h / 2;
    fit = *app_view();

    /* 倍率 ＝ １．０ (1089): 表示が 1.0、真ん中はそのまま */
    app_zoom(3.0, cx + 100, cy + 50);
    v1 = *app_view();
    br(1089);
    ck(!app_bairitsu_open(), "倍率＝1.0 で閉じる");
    ck(near_(readout(), 1.0, 1e-9), "  倍率の表示が 1.0");
    ck(near_(app_view()->ox, v1.ox, 1e-9) && near_(app_view()->oy, v1.oy, 1e-9),
       "  真ん中の点は動かない");
    /* 前倍率 は OK の前の画面 */
    app_zoom_prev();
    ck(same_view(app_view(), &v1), "前倍率 で 倍率＝1.0 の前に戻る");
    app_zoom_prev();
    ck(near_(readout(), 1.0, 1e-9), "  もう一度で 1.0 へ（入れ替え）");

    /* 指定倍率: 開いた時は箱の「2」が選ばれていて、打てば替わる */
    app_command(32811);
    type("3");
    app_key(13);                        /* Enter = IDOK = 指定倍率表示 */
    ck(!app_bairitsu_open(), "Enter で 指定倍率表示");
    ck(near_(readout(), 3.0, 1e-9), "  打った 3 で倍率の表示が 3");
    app_command(32811);
    br(1);                              /* 箱はさっきの 3 のまま */
    ck(near_(readout(), 3.0, 1e-9), "  箱は次に開いても 3");
    app_command(32811);
    app_key(8);
    type("0.001");                      /* DDV の 0.01 より下 */
    br(1);
    ck(!app_bairitsu_open() && near_(readout(), 3.0, 1e-9),
       "  0.01 より小さいと閉じるだけ");
    app_command(32811);
    type("2.5");
    br(1);
    ck(near_(readout(), 2.5, 1e-9), "  2.5 なら 2.5");

    /* 用紙全体表示 から 表示範囲記憶 */
    br(1091);
    ck(same_view(app_view(), &fit), "用紙全体表示 は app_fit と同じ");
    br(1068);                           /* 死んでいる（倍率 1・(0,0)） */
    ck(app_bairitsu_open(), "  用紙全体では 表示範囲記憶 は押せない");
    app_key(27);
    app_zoom(2.0, cx - 120, cy + 40);
    v2 = *app_view();
    br(1068);
    ck(!app_bairitsu_open(), "寄っていれば 表示範囲記憶 が効いて閉じる");
    app_fit();
    app_zoom_all(0);
    ck(same_view(app_view(), &v2), "  全体 は記憶した画面へ");
    app_zoom_all(1);
    ck(same_view(app_view(), &fit), "  用紙全体の 全体 は記憶によらない");
    app_zoom_prev();
    ck(same_view(app_view(), &v2), "  前倍率 で戻る");
    br(1069);
    ck(!app_bairitsu_open(), "記憶解除 で閉じる");
    app_zoom_all(0);
    ck(same_view(app_view(), &fit), "  記憶解除 のあとの 全体 は用紙全体");

    /* マークジャンプ: 〔1〕を登録、〔2〕は登録なし */
    app_fit();
    app_zoom(4.0, cx + 30, cy - 70);
    v1 = *app_view();
    wg = write_group();
    br(1327);                           /* レイヤグループ同時登録 */
    br(1323);                           /* 〔1〕 登録（すぐ効く） */
    br(1933);                           /* 設定 OK */
    ck(!app_bairitsu_open(), "設定 OK で閉じる");
    {   /* 書込みグループを替えておく */
        jw_drawing *d = (jw_drawing *)app_drawing();
        int other = wg == 0 ? 1 : 0;

        d->group[wg].state = 2;
        d->group[other].state = 3;
    }
    app_fit();
    br(1064);
    ck(!app_bairitsu_open(), "マークジャンプ〔1〕で閉じる");
    ck(same_view(app_view(), &v1), "  登録した画面へ");
    ck(write_group() == wg, "  グループも登録したものへ");
    br(1065);
    ck(same_view(app_view(), &fit), "登録の無い〔2〕は用紙全体");
    app_zoom_prev();
    ck(same_view(app_view(), &v1), "  前倍率 で〔1〕の画面へ");
    br(1323);                           /* 外すと 1・(0,0) に戻る */
    app_key(27);
    br(1064);
    ck(same_view(app_view(), &fit), "〔1〕を外せば用紙全体");
    br(1327);                           /* 同時登録 を戻す */
    app_key(27);

    /* 目盛 表示最小倍率: Test5 は目盛が無いので押せない */
    if (app_drawing()->mesh_mode == 0) {
        br(1090);
        ck(app_bairitsu_open(), "目盛の無い図面では 目盛 表示最小倍率 は押せない");
        app_key(27);
    }

    /* 両ボタンドラッグの 縮小・範囲拡大 */
    app_fit();
    app_zoom_out(cx, cy);
    ck(near_(app_view()->mmpp, fit.mmpp * 2, 1e-12), "縮小 で倍率が半分");
    app_zoom_out(cx, cy);
    ck(near_(app_view()->mmpp, fit.mmpp * 2, 1e-12), "  0.5 より下へは行かない");
    app_fit();
    app_zoom_rect(cx - r.w / 4, cy - r.h / 4, cx + r.w / 4, cy + r.h / 4);
    ck(near_(app_view()->mmpp, fit.mmpp / 2, fit.mmpp * 0.01), "範囲拡大 で半分の箱が窓いっぱい");
    app_zoom_prev();
    ck(same_view(app_view(), &fit), "  前倍率 で戻る");
}

static void mesh_zoom(void)
{
    jw_drawing *d;
    double s;

    /* 目盛を持つ図面の代わりに Test5 に 目盛 を入れる（割り 2、5mm、最小 15 画素） */
    ck(open_file("orig/Test5.jww"), "Test5 を開き直す（目盛）");
    d = (jw_drawing *)app_drawing();
    d->mesh_mode = 2;
    d->mesh_ix = 5.0;
    d->mesh_iy = 6.0;
    d->mesh_min = 15.0;
    br(1090);
    ck(!app_bairitsu_open(), "目盛 表示最小倍率 で閉じる");
    s = (d->mesh_ix < d->mesh_iy ? d->mesh_ix : d->mesh_iy) / d->mesh_mode;
    /* いちばん細かい目盛がちょうど 表示最小間隔 の画素に（倍率に +0.001） */
    ck(s / app_view()->mmpp >= d->mesh_min
       && s / app_view()->mmpp < d->mesh_min * 1.01,
       "  細かい目盛の間が 表示最小間隔 の画素");
    d->mesh_mode = 0;
}

static void text_frame(void)
{
    long a, b, c;

    ck(open_file("orig/Test5.jww"), "Test5 を開き直す（文字枠）");
    app_paint();
    a = inked();
    br(2104);                           /* 【文字枠】を表示する */
    app_key(27);                        /* Esc（× と同じ OnCancel）では効かない */
    app_paint();
    ck(inked() == a, "【文字枠】は Esc では効かない");
    br(2104);
    br(1933);
    app_paint();
    b = inked();
    ck(b > a, "設定 OK で文字に枠が付く");
    br(2104);
    br(1933);
    app_paint();
    c = inked();
    ck(c == a, "外せば元の絵");
    printf("     白でない画素 %ld → %ld → %ld\n", a, b, c);
}

static void shakudo(void)
{
    jw_drawing *d;
    jw_obj *ln, *tx, *pt;
    int g, i;

    app_new();
    d = (jw_drawing *)app_drawing();
    g = write_group();
    d->group[g].scale = 100.0;
    ln = jw_add(d, JW_SEN);
    ln->d[0] = 10; ln->d[1] = 10; ln->d[2] = 20; ln->d[3] = 10;
    tx = jw_add(d, JW_MOJI);
    tx->d[0] = 5; tx->d[1] = 5; tx->d[2] = 15; tx->d[3] = 5;
    tx->d[4] = 2.5; tx->d[5] = 2.5; tx->d[6] = 0;
    pt = jw_add(d, JW_TEN);
    pt->d[0] = 4; pt->d[1] = -6; pt->size = 1.5;
    ln = &d->obj[0];
    tx = &d->obj[1];
    pt = &d->obj[2];

    /* 1/100 → 1/50: 実寸固定（既定）なら 用紙の上で 2 倍 */
    app_command(32944);
    for (i = 0; i < 8; i++)
        app_key(8);
    type("50");
    app_key(13);
    ck(d->group[g].scale == 50.0, "縮尺 1/50");
    ck(ln->d[0] == 20 && ln->d[2] == 40 && ln->d[1] == 20,
       "  実寸固定 で線が 2 倍（原点まわり）");
    ck(tx->d[0] == 10 && tx->d[1] == 10 && tx->d[2] == 20 && tx->d[4] == 2.5,
       "  文字サイズ変更 が無ければ文字の大きさはそのまま");
    ck(pt->d[0] == 8 && pt->d[1] == -12 && pt->size == 1.5,
       "  点マーカサイズ変更 が無ければ点の大きさはそのまま");

    /* 文字サイズ変更・点マーカサイズ変更 を入れて 1/50 → 1/25 */
    app_command(32944);
    sk(1955);
    sk(1956);
    for (i = 0; i < 8; i++)
        app_key(8);
    type("25");
    app_key(13);
    ck(d->group[g].scale == 25.0, "縮尺 1/25");
    ck(tx->d[0] == 20 && tx->d[2] == 40 && tx->d[4] == 5.0 && tx->d[5] == 5.0,
       "  文字サイズ変更 で文字も 2 倍");
    ck(pt->size == 3.0, "  点マーカサイズ変更 で点の大きさも 2 倍");

    /* 図寸固定 なら縮尺だけ */
    app_command(32944);
    sk(1705);
    for (i = 0; i < 8; i++)
        app_key(8);
    type("100");
    app_key(13);
    ck(d->group[g].scale == 100.0 && ln->d[0] == 40, "図寸固定 では要素は動かない");
    app_command(32944);
    sk(1704);                           /* 次の試験のために戻す */
    sk(1955);
    sk(1956);
    app_key(27);
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b;
    long n;
    rect_t r;
    double mmpp;
    int x, y, i, j;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    mmpp = app_view()->mmpp;

    ck(!app_bairitsu_open(), "the dialog is not up to start with");
    ck(app_command(32811), "画面倍率・文字表示 puts it up");
    ck(app_bairitsu_open(), "which says so");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_bairitsu_rect(fb->w, fb->h, &r);
        px = (unsigned int *)malloc((size_t)r.w * r.h * sizeof *px);
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

    /* a tick goes on and off */
    ctl(2104, &x, &y);                  /* 【文字枠】を表示する */
    app_press(x, y, 0);
    ck(app_bairitsu_open(), "a checkbox leaves it up");

    /* the greyed 表示範囲記憶 is not pressable */
    ctl(1068, &x, &y);
    app_press(x, y, 0);
    ck(app_bairitsu_open(), "and so does the greyed 表示範囲記憶");

    /* 用紙全体表示 fits the sheet again */
    ui_view_rect(fb->w, fb->h, &r);
    app_zoom(4.0, r.x + r.w / 2, r.y + r.h / 2);
    ck(app_view()->mmpp != mmpp, "zooming in moves the view");
    ctl(1091, &x, &y);
    app_press(x, y, 0);
    ck(!app_bairitsu_open(), "用紙全体表示 takes the dialog down");
    ck(app_view()->mmpp == mmpp, "and the sheet fits the window again");
    app_zoom_prev();
    ck(near_(app_view()->mmpp, mmpp / 4, 1e-12), "前倍率 goes back to the zoom");

    zoom_parts();
    mesh_zoom();
    text_frame();
    shakudo();

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
