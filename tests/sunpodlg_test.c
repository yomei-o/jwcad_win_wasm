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

static int near(double a, double b)
{
    return a - b < 1e-6 && b - a < 1e-6;
}

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

    /* ------------------------------ 残りの箱: 原典の既定と OK の丸め ---
       既定はレジストリ SUNPO・RUISHINSUNPO（tools/refenv.reg）、写し
       docs/ref_sunpodlg.png の 5・5 10・0 5・3・0.75・4。丸めは
       CSunpoSetteiDialg の OK `FUN_005d34b0` */
    {
        static const struct { int id; const char *v; } DEF[] = {
            { 2080, "5" }, { 1482, "5" }, { 1483, "10" }, { 1484, "0" },
            { 1485, "5" }, { 1486, "3" }, { 2082, "0.75" }, { 2084, "4" }
        };
        char t[32], what[80];
        int k;

        for (k = 0; k < (int)(sizeof DEF / sizeof DEF[0]); k++) {
            sprintf(what, "%d は原典の既定 %s", DEF[k].id, DEF[k].v);
            ck(jw_cmd_sunpo_box(DEF[k].id, t, sizeof t)
               && !strcmp(t, DEF[k].v), what);
        }
        app_command(32925);
        ctl(1483, &x, &y);
        app_press(x, y, 0);
        app_key('1');
        app_key('5');
        app_key('0');
        app_key('\r');
        ck(jw_cmd_sunpo_box(1483, t, sizeof t) && !strcmp(t, "200"),
           "1483 は 100 を超えると 200（原典の丸めのまま）");
        ctl(1486, &x, &y);
        app_press(x, y, 0);
        app_key('-');
        app_key('2');
        app_key('\r');
        ck(jw_cmd_sunpo_box(1486, t, sizeof t) && !strcmp(t, "0"),
           "1486 は 0 より小さくならない");
        ctl(2082, &x, &y);
        app_press(x, y, 0);
        app_key('0');
        app_key('\r');
        ck(jw_cmd_sunpo_box(2082, t, sizeof t) && !strcmp(t, "0.1"),
           "2082 は 0.1 より小さくならない");
        ctl(2080, &x, &y);
        app_press(x, y, 0);
        app_key('7');
        app_key('\r');
        ck(jw_cmd_sunpo_box(2080, t, sizeof t) && !strcmp(t, "7"),
           "逆矢印の突出寸法を 7 に");
        ctl(2084, &x, &y);
        app_press(x, y, 0);
        app_key('2');
        app_key('\r');
        ck(jw_cmd_sunpo_box(2084, t, sizeof t) && !strcmp(t, "4"),
           "2084 は押せない箱なので打てない");
        ctl(1, &x, &y);
        app_press(x, y, 0);
        ck(!app_sunpodlg_open(), "OK で閉じる");
        ck(jw_cmd_sunpo_box(1483, t, sizeof t) && !strcmp(t, "200")
           && jw_cmd_sunpo_box(2080, t, sizeof t) && !strcmp(t, "7"),
           "OK のあとも残る");
    }

    /* ------------------------------------------ 端部 の 逆矢印 -------
       端部 (1062) は 0 点 → 1 矢印 → 2 逆矢印 → 0 と回る（FUN_005d9350）。
       逆矢印は 寸法線の前に 両端から外へ 突出寸法 の線を二本、矢印は
       外向き（FUN_00783730 の 0x784977・0x784e85） */
    {
        jw_drawing *dz = (jw_drawing *)app_drawing();
        int b0, k, ok;
        const jw_obj *o;

        jw_cmd_set(JW_CMD_SUNPO);
        ck(jw_cmd_sunpo_arrows() == 0, "端部 は 点 から");
        jw_cmd_bar(dz, 1062);
        ck(jw_cmd_sunpo_arrows() == 1, "  一回で 矢印");
        jw_cmd_bar(dz, 1062);
        ck(jw_cmd_sunpo_arrows() == 2, "  二回で 逆矢印");
        b0 = dz->ndrawn;
        jw_cmd_point(dz, app_view(), 100.0, 120.0, 0);
        jw_cmd_point(dz, app_view(), 100.0, 110.0, 0);
        jw_cmd_point(dz, app_view(), 100.0, 100.0, 0);
        jw_cmd_point(dz, app_view(), 200.0, 100.0, 0);
        ck(dz->ndrawn == b0 + 10,
           "  突出二本・寸法線・矢印四本・引出線二本・値");
        if (dz->ndrawn == b0 + 10) {
            o = &dz->obj[b0];
            ck(o->cls == JW_SEN && o->color == 4 && (o->flags & 0x2000)
               && near(o->d[0], 100.0) && near(o->d[1], 110.0)
               && near(o->d[2], 93.0) && near(o->d[3], 110.0),
               "  一本目は始点から外へ 7");
            o = &dz->obj[b0 + 1];
            ck(near(o->d[0], 200.0) && near(o->d[2], 207.0)
               && near(o->d[3], 110.0), "  二本目は終点から外へ 7");
            o = &dz->obj[b0 + 2];
            ck(near(o->d[0], 100.0) && near(o->d[2], 200.0),
               "  そのあと寸法線");
            ok = 1;
            for (k = 0; k < 4; k++) {
                o = &dz->obj[b0 + 3 + k];
                /* 始点の矢印は左へ、終点の矢印は右へ開く */
                if (k < 2 ? !(o->d[2] < o->d[0]) : !(o->d[2] > o->d[0]))
                    ok = 0;
            }
            ck(ok, "  矢印は外向き");
        }
        /* 逆向き（二点目が一点目より手前）に測ると突出の線は出ない */
        jw_cmd_set(0);                  /* 次の寸法は一から */
        jw_cmd_set(JW_CMD_SUNPO);
        b0 = dz->ndrawn;
        jw_cmd_point(dz, app_view(), 200.0, 120.0, 0);
        jw_cmd_point(dz, app_view(), 200.0, 110.0, 0);
        jw_cmd_point(dz, app_view(), 200.0, 100.0, 0);
        jw_cmd_point(dz, app_view(), 100.0, 100.0, 0);
        ck(dz->ndrawn == b0 + 8, "  逆向きに測ると突出の線は無い（local_71a8）");
        jw_cmd_bar(dz, 1062);
        ck(jw_cmd_sunpo_arrows() == 0, "  三回で 点 に戻る");
        jw_cmd_set(0);
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
