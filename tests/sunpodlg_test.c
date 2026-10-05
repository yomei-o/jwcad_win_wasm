/* 寸法設定 -- the dialog, against the original's own.
 *
 *   tests/sunpodlg_test.exe tests/out/sunpodlg.png
 *
 * docs/ref_sunpodlg.png is that dialog painted into a bitmap by Jw_cad
 * itself.  This puts the port's up in the same state and writes it out to
 * be scored against that picture; tools/check.sh does the scoring, with the
 * text left out of it.
 *
 * **八つの箱は効きます。**原典で一つずつ変えて同じ寸法を引かせ、出て
 * きた要素を見比べて確かめたものです（`tools/probe147.sh`）:
 *
 *   1488 文字種類    値の文字が その文字種になる
 *   1489 寸法線色 / 2083 引出線色 / 1473 矢印・点色
 *   1475 寸法線と文字の間隔 / 1479 引出線の突出寸法
 *   1477 矢印の長さ / 1481 矢印の角度（矢印を出していないと見えない）
 *
 * 2084 小数桁 は原典でも使えない状態（enabled=0）なので触りません。
 * 残りの押し釦は絵だけで、押すと凹むところまでです。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/sunpodlg.h"
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

static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_sunpodlg_rect(1264, 741, &r);
    for (i = 0; i < JW_NSUNPODLG; i++)
        if (jw_sunpodlg[i].id == id) {
            *x = r.x + JW_SD_BORDER + jw_sunpodlg[i].x + jw_sunpodlg[i].w / 2;
            *y = r.y + JW_SD_CAPTION + jw_sunpodlg[i].y
                 + jw_sunpodlg[i].h / 2;
            return;
        }
    *x = *y = -1;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);

    ck(!app_sunpodlg_open(), "the dialog is not up to start with");
    ck(app_command(32925), "寸法設定 puts it up");
    ck(app_sunpodlg_open(), "which says so");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_sunpodlg_rect(fb->w, fb->h, &r);
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

    /* there is no キャンセル on this one: two OKs instead */
    ctl(1, &x, &y);
    app_press(x, y, 0);
    ck(!app_sunpodlg_open(), "OK takes it down");

    /* ------------------------------------------ 箱に打ち込む --------- */
    {
        char t[32];
        jw_drawing *dd = (jw_drawing *)app_drawing();
        int before2;

        app_command(32925);
        ck(jw_cmd_sunpo_box(1489, t, sizeof t) && !strcmp(t, "1"),
           "寸法線色は 1 から");
        ctl(1489, &x, &y);
        app_press(x, y, 0);
        app_key('4');
        app_key('\r');
        ck(jw_cmd_sunpo_box(1489, t, sizeof t) && !strcmp(t, "4"),
           "4 と打てば 4 になる");

        /* 間隔 too, and the caption's × drops what was typed */
        ctl(1475, &x, &y);
        app_press(x, y, 0);
        app_key('3');
        app_key('\r');
        ck(jw_cmd_sunpo_box(1475, t, sizeof t) && !strcmp(t, "3"),
           "間隔も打てる");
        ctl(1475, &x, &y);
        app_press(x, y, 0);
        app_key('9');
        /* the caption's × is not in the table: it is drawn by the
           dialog chrome, at (W-28,10), ten pixels square */
        ui_sunpodlg_rect(1264, 741, &r);
        app_press(r.x + JW_SD_BORDER + JW_SD_W - 26, r.y + 18, 0);
        ck(!app_sunpodlg_open(), "× も窓を下ろす");
        ck(jw_cmd_sunpo_box(1475, t, sizeof t) && !strcmp(t, "3"),
           "× なら打ちかけは捨てられる");

        /* and the dimension that comes out carries it */
        {
            jw_drawing *dz = dd;

            jw_obj *ln = jw_add(dz, JW_SEN);

            ln->d[0] = 100.0;
            ln->d[1] = 100.0;
            ln->d[2] = 200.0;
            ln->d[3] = 100.0;
            app_fit();
            before2 = dz->ndrawn;
            jw_cmd_set(JW_CMD_SUNPO);
            jw_cmd_point(dz, app_view(), 100.0, 120.0, 0);  /* 引出線の端 */
            jw_cmd_point(dz, app_view(), 100.0, 110.0, 0);  /* 寸法線の高さ */
            jw_cmd_point(dz, app_view(), 100.0, 100.0, 0);  /* 始点 */
            jw_cmd_point(dz, app_view(), 200.0, 100.0, 0);  /* 終点 */
            ck(dz->ndrawn > before2, "寸法が引けた");
            if (dz->ndrawn > before2)
                ck(dz->obj[before2].cls == JW_SEN
                   && dz->obj[before2].color == 4,
                   "寸法線は打ち込んだ色 4");
            jw_cmd_set(0);
        }
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
