/* 色の設定 -- the Windows colour dialog, against the original's own.
 *
 *   tests/colordlg_test.exe tests/out/colordlg.png
 *
 * 基本設定 (32891) の 色・画面 の 色１ が出す窓です。**Jw_cad の窓では
 * なく Windows の共通ダイアログ**（comdlg32 の ChooseColor、CC_FULLOPEN）
 * なので、形は Jw_win.exe ではなく comdlg32.dll.mui の DIALOG 資源が
 * 持っています。移植はその資源から起こしています
 * （`tools/mkcolordlg.py` が MapDialogRect で単位を画素に直し、原典に
 * 出させた窓の控え `decomp/res/colordlg.txt` と全部品が合うことを
 * 毎回確かめます）。
 *
 * この試験はそこから先 ——「描いた絵」が原典の撮った絵
 * （`docs/ref_colordlg.png`）と合うか —— を見ます。採点は
 * `tools/check.sh` が `tools/cmp.py` でやります。ここでは窓の切り出しと、
 * 中の算術・押したときの動きを見ます。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/draw.h"
#include "../src/gen/colordlg.h"
#include "../src/gen/pens.h"
#include "../src/gen/kihon.h"
#include "png.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* Where a control of the dialog sits, in the frame. */
static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_colordlg_rect(1264, 741, &r);
    for (i = 0; i < JW_NCOLORDLG; i++)
        if (jw_colordlg[i].id == id) {
            *x = r.x + JW_CD_BORDER + jw_colordlg[i].x
                 + jw_colordlg[i].w / 2;
            *y = r.y + JW_CD_CAPTION + jw_colordlg[i].y
                 + jw_colordlg[i].h / 2;
            return;
        }
    *x = *y = -1;
}

/* The top-left swatch of one of the two grids. */
static void swatch(int which, int col, int row, int *x, int *y)
{
    rect_t r;
    int i;

    ui_colordlg_rect(1264, 741, &r);
    for (i = 0; i < JW_NCOLORDLG; i++)
        if (jw_colordlg[i].id == which) {
            *x = r.x + JW_CD_BORDER + jw_colordlg[i].x + JW_CD_X0
                 + col * JW_CD_PX + JW_CD_CELLW / 2;
            *y = r.y + JW_CD_CAPTION + jw_colordlg[i].y + JW_CD_Y0
                 + row * JW_CD_PY + JW_CD_CHH / 2;
            return;
        }
    *x = *y = -1;
}

/* 基本設定 の 色・画面 の 色N を押す。 */
static int open_from_kihon(int ctlid)
{
    rect_t r;
    int i, n, x = -1, y = -1;

    app_command(32891);
    if (!app_kihon_open())
        return 0;
    ui_kihon_rect(1264, 741, &r);
    /* 色・画面 is the third tab; the strip's stops are in the header */
    app_press(r.x + JW_KH_BORDER + JW_KH_TAB_X
              + (jw_kihon_tab_at[2] + jw_kihon_tab_at[3]) / 2,
              r.y + JW_KH_CAPTION + JW_KH_TAB_Y + 10, 0);
    if (app_kihon_tab() != 2)
        return 0;
    n = ui_kihon_n(2);
    for (i = 0; i < n; i++)
        if (ui_kihon_id(2, i) == ctlid) {
            x = r.x + JW_KH_BORDER + jw_kihon2[i].x + jw_kihon2[i].w / 2;
            y = r.y + JW_KH_CAPTION + jw_kihon2[i].y + jw_kihon2[i].h / 2;
            break;
        }
    if (x < 0)
        return 0;
    app_press(x, y, 0);
    return app_colordlg_open();
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    rect_t r;
    int x, y, i, j;

    app_new();
    app_resize(1264, 741);
    fb = app_fb();

    /* ---------------------------------------------- the arithmetic --- */
    {
        /* Windows' own HLS, as MFC has it.  The two the original showed:
           色１ is 0x00c0c0 and its window read 色合い120 鮮やかさ240
           明るさ90 (docs/ref_colordlg.png). */
        int h = -1, l = -1, s = -1;

        jw_rgb_to_hls(0x00c0c0u, &h, &l, &s);
        ck(h == 120 && l == 90 && s == 240,
           "0x00c0c0 は 色合い120・明るさ90・鮮やかさ240");
        jw_rgb_to_hls(0xffffffu, &h, &l, &s);
        ck(l == 240 && s == 0, "白は 明るさ240・鮮やかさ0");
        jw_rgb_to_hls(0x000000u, &h, &l, &s);
        ck(l == 0 && s == 0, "黒は 明るさ0・鮮やかさ0");
        ck(jw_hls_to_rgb(0, 120, 240) == 0xff0000u,
           "色相0・明るさ120・鮮やかさ240 は赤");
        ck(jw_hls_to_rgb(0, 240, 0) == 0xffffffu, "明るさ240 は白");
        ck(jw_hls_to_rgb(0, 0, 0) == 0x000000u, "明るさ0 は黒");
    }

    /* ------------------------------------------------- the window ---- */
    ck(!app_colordlg_open(), "はじめは出ていない");
    ck(open_from_kihon(1059), "基本設定 の 色・画面 の 色１ で出る");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_colordlg_rect(fb->w, fb->h, &r);
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

    /* ------------------------------------------------- 押したとき ---- */
    {
        const jw_drawing *d = app_drawing();

        /* 基本色 の一つ目は ff8080（撮った絵から読んだ表） */
        ck(ui_colordlg_basic(0) == 0xff8080u, "基本色の一つ目は ff8080");
        swatch(720, 0, 0, &x, &y);
        app_press(x, y, 0);
        ctl(1, &x, &y);
        app_press(x, y, 0);             /* OK */
        ck(!app_colordlg_open(), "OK で窓が下りる");
        ck(d->pen_rgb[1] == 0xff8080u, "画面ペン1 がその色になった");

        /* キャンセルなら戻さない */
        ck(open_from_kihon(1060), "色２ でも出る");
        swatch(720, 1, 0, &x, &y);
        app_press(x, y, 0);
        ctl(2, &x, &y);
        app_press(x, y, 0);             /* キャンセル */
        ck(!app_colordlg_open(), "キャンセルで下りる");
        ck(d->pen_rgb[2] == jw_default_pen_rgb[2],
           "キャンセルならペンは元のまま");

        /* 見出しの × も キャンセル */
        ck(open_from_kihon(1061), "色３ でも出る");
        ui_colordlg_rect(1264, 741, &r);
        app_press(r.x + JW_CD_W - 26, r.y + 18, 0);
        ck(!app_colordlg_open(), "× でも下りる");
        ck(d->pen_rgb[3] == jw_default_pen_rgb[3], "× でもペンは元のまま");

        /* 虹の升を押すと 色相と彩度 が動く */
        ck(open_from_kihon(1904), "色８ でも出る");
        ctl(710, &x, &y);
        app_press(x, y, 0);
        ctl(1, &x, &y);
        app_press(x, y, 0);
        ck(d->pen_rgb[8] != jw_default_pen_rgb[8],
           "虹の升を押して OK すると色が変わる");

        /* 箱に打ち込む */
        ck(open_from_kihon(1902), "色６ でも出る");
        ctl(706, &x, &y);
        app_press(x, y, 0);             /* 赤 */
        app_key('1');
        app_key('2');
        app_key('8');
        app_key('\r');
        ctl(1, &x, &y);
        app_press(x, y, 0);
        ck(((d->pen_rgb[6] >> 16) & 0xff) == 128,
           "赤に 128 と打つと、その赤になる");
    }

    /* 図面のペンでない行。原典の受け手は同じで、行番号だけが違います
       —— 13 グレー、15 選択色、16 仮表示色（tools/msgmap.py）。 */
    {
        int x2, y2;

        ck(open_from_kihon(1122), "仮表示色 (1122) でも出る");
        swatch(720, 0, 0, &x2, &y2);
        app_press(x2, y2, 0);
        ctl(1, &x2, &y2);
        app_press(x2, y2, 0);
        ck(jw_row_rgb(16) == 0xff8080u,
           "行16（仮表示色）が打った色になった");

        ck(open_from_kihon(1121), "選択色 (1121) でも出る");
        ctl(2, &x2, &y2);
        app_press(x2, y2, 0);
        ck(jw_row_rgb(15) == 0xff00ffu,
           "行15（選択色）はキャンセルなら ff00ff のまま");

        /* 行13（グレー）は図面が持っています —— ファイルの十本目の
           画面ペンがそこに入るので（src/jww.h の gray_rgb）。原典の
           その窓も c0c0c0 を見せました */
        ck(app_drawing()->gray_rgb == 0xc0c0c0u,
           "図面のグレーは c0c0c0（ファイルの十本目）");
        ck(app_drawing()->pen_rgb[9] == 0xff80ffu,
           "画面ペン9 は控えの ff80ff で、ファイルからは来ない");
        ck(open_from_kihon(1905), "グレー (1905) でも出る");
        ctl(2, &x2, &y2);
        app_press(x2, y2, 0);
        ck(jw_row_rgb(13) == 0xc0c0c0u,
           "行13（グレー）は原典が見せた c0c0c0 から");

        /* 1120 は画面ペン9。原典の見本枠が ff80ff で、それが
           jw_default_pen_rgb[9] です */
        {
            unsigned int was = app_drawing()->pen_rgb[9];

            ck(open_from_kihon(1120), "1120 でも出る");
            swatch(720, 1, 0, &x2, &y2);
            app_press(x2, y2, 0);
            ctl(1, &x2, &y2);
            app_press(x2, y2, 0);
            ck(app_drawing()->pen_rgb[9] == ui_colordlg_basic(1)
               && was != ui_colordlg_basic(1),
               "1120 で OK すると画面ペン9 が変わる");
        }
    }

    /* ------------------------------------- 端から端まで ---------- */
    /* 使う人の頼み:「線とか四角形を作図するとき、任意の色を選べる」。
       Jw_cad ではその道筋が二段になっています —— **線属性 で 線色N を
       選び、その 線色N が実際にどの RGB かを 色の設定 で決める**。
       ここはその二段目が作図まで届いているかを見ます。 */
    {
        jw_drawing *d = (jw_drawing *)app_drawing();
        const fb_t *f;
        rect_t v;
        int x2, y2, hit = 0, i, j;

        app_new();
        app_resize(1264, 741);
        /* 画面ペン1 を 基本色 の二つ目（ffff80）にする */
        ck(open_from_kihon(1059), "もう一度 色１ を開く");
        swatch(720, 1, 0, &x2, &y2);
        app_press(x2, y2, 0);
        ctl(1, &x2, &y2);
        app_press(x2, y2, 0);
        ck(d->pen_rgb[1] == ui_colordlg_basic(1),
           "画面ペン1 が 基本色の二つ目になった");

        /* その色で線を引く */
        /* 基本設定 はまだ上に出たままなので、下ろしてから描かせます */
        {
            rect_t kr;
            int t;

            ui_kihon_rect(1264, 741, &kr);
            for (t = 0; t < ui_kihon_n(2); t++)
                if (ui_kihon_id(2, t) == 1) {
                    app_press(kr.x + JW_KH_BORDER + jw_kihon2[t].x + 4,
                              kr.y + JW_KH_CAPTION + jw_kihon2[t].y + 4, 0);
                    break;
                }
            ck(!app_kihon_open(), "基本設定 の OK で下りる");
        }
        {
            int before = d->ndrawn;

            /* jw_add は write_ltype が立っているときだけ
               write_color を使います（src/jww.c） */
            d->write_color = 1;
            d->write_ltype = 1;
            jw_cmd_set(JW_CMD_SEN);
            jw_cmd_point(d, app_view(), -40.0, 0.0, 0);
            jw_cmd_point(d, app_view(), 40.0, 0.0, 0);
            ck(d->ndrawn == before + 1
               && d->obj[before].color == 1, "線色1 の線が引けた");
            if (d->ndrawn != before + 1)
                printf("     ndrawn %d -> %d\n", before, d->ndrawn);
        }
        app_fit();
        app_paint();
        f = app_fb();
        ui_view_rect(f->w, f->h, &v);
        for (j = v.y; j < v.y + v.h && !hit; j++)
            for (i = v.x; i < v.x + v.w; i++)
                if (f->px[(size_t)j * f->w + i] == ui_colordlg_basic(1)) {
                    hit = 1;
                    break;
                }
        ck(hit, "作図領域にその色の画素が出ている");
        jw_cmd_set(JW_CMD_TEN);
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
