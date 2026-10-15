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
 * チェックボックスとラジオは命令が持ち（jw_cmd_sunpo_chk）、OK で効きます
 * （末尾の節。逆コンパイルの読み、原典では押していない）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/sunpodlg.h"
#include "../src/gen/sunpo.h"
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

    /* ------------------------- チェックボックスとラジオ（2026-10-16）---
       DDX FUN_005d2b30・OK FUN_005d34b0 の繋ぎ、値の書き方 FUN_0045a220、
       単位 FUN_00786cf0、全角 FUN_00473110、+0x2c FUN_004782d0、斜体太字
       FUN_00479550、R・φ FUN_007891b0。逆コンパイルの読み、原典では押して
       いない（照らす原典の答えは無い） */
    {
        jw_drawing *dz = (jw_drawing *)app_drawing();
        double sc = 1.0;
        int k, wg = 0;
        char want[64];

        for (k = 0; k < 16; k++)
            if (dz->group[k].state == 3)
                wg = k;
        sc = dz->group[wg].scale;

        /* 既定は 原典の窓のまま */
        ck(jw_cmd_sunpo_chk(2332) == 1 && jw_cmd_sunpo_chk(2333) == 0
           && jw_cmd_sunpo_chk(1708) == 1 && jw_cmd_sunpo_chk(2487) == 1
           && jw_cmd_sunpo_chk(1710) == 1 && jw_cmd_sunpo_chk(2489) == 1
           && jw_cmd_sunpo_chk(1718) == 1 && jw_cmd_sunpo_chk(1716) == 1
           && jw_cmd_sunpo_chk(2420) == 0 && jw_cmd_sunpo_chk(1801) == 0,
           "ラジオとチェックの既定は窓の初め（2桁・(，)有・0表示無・前付・四捨五入・mm・単位無）");
        ck(jw_cmd_sunpo_chk(1488) == -1, "箱は チェックではない");
        ck(jw_cmd_sunpo_radio_group(2331) == 2330
           && jw_cmd_sunpo_radio_group(2420) == 0, "組の頭");

        /* 窓で 3桁・0表示 有・(，)表示 無・切上・斜体 を押して OK */
        app_command(32925);
        ctl(2333, &x, &y); app_press(x, y, 0);
        ctl(2488, &x, &y); app_press(x, y, 0);
        ctl(1707, &x, &y); app_press(x, y, 0);
        ctl(2491, &x, &y); app_press(x, y, 0);
        ctl(2420, &x, &y); app_press(x, y, 0);
        ck(jw_cmd_sunpo_chk(2333) == 0, "  押しただけでは効かない（OK まで）");
        ctl(1, &x, &y); app_press(x, y, 0);
        ck(jw_cmd_sunpo_chk(2333) == 1 && jw_cmd_sunpo_chk(2332) == 0
           && jw_cmd_sunpo_decimals() == 3, "  OK で 3桁（同じ組の 2桁 は消える、バーの 小数桁 と同じ）");
        ck(jw_cmd_sunpo_chk(2488) == 1 && jw_cmd_sunpo_chk(1707) == 1
           && jw_cmd_sunpo_chk(2491) == 1 && jw_cmd_sunpo_chk(2420) == 1,
           "  0表示 有・(，) 無・切上・斜体");
        {
            /* 100/3 の線: 切上 3桁、0 を残し、, は無い */
            int b0 = dz->ndrawn, t = -1;
            double v = 100.0 / 3.0 * sc;
            jw_obj *ln = jw_add(dz, JW_SEN);    /* 測る点は読んだ点でないといけない */

            ln->d[0] = 100.0;
            ln->d[1] = 50.0;
            ln->d[2] = 100.0 + 100.0 / 3.0;
            ln->d[3] = 100.0;
            b0 = dz->ndrawn;
            jw_cmd_set(JW_CMD_SUNPO);
            jw_cmd_point(dz, app_view(), 100.0, 120.0, 0);
            jw_cmd_point(dz, app_view(), 100.0, 110.0, 0);
            jw_cmd_point(dz, app_view(), 100.0, 100.0, 0);
            jw_cmd_point(dz, app_view(), 100.0 + 100.0 / 3.0, 100.0, 0);
            for (k = b0; k < dz->ndrawn; k++)
                if (dz->obj[k].cls == JW_MOJI)
                    t = k;
            /* "%lf" の六桁を三桁で切って、先に 0 より大きい字があれば一つ上げる */
            {
                char f[64];
                int dot;
                sprintf(f, "%f", v);
                dot = (int)(strchr(f, '.') - f);
                f[dot + 4] = 0;
                {
                    double q = atof(f) + (v - atof(f) > 1e-9 ? 0.001 : 0.0);
                    sprintf(want, "%.3f", q);
                }
            }
            ck(t >= 0 && !strcmp(jw_str(dz, dz->obj[t].text), want),
               "  値は 切上 3桁 で 0 を残し , 無し");
            printf("     port [%s]  want [%s]  (%d 個)\n",
                   t >= 0 ? jw_str(dz, dz->obj[t].text) : "", want,
                   dz->ndrawn - b0);
            ck(t >= 0 && dz->obj[t].width == (3u | 0x80u | 0x200u | (3u << 12)),
               "  +0x2c は 0表示 0x80・切上 0x200・桁 3、(，) の 0x40 は無い");
            ck(t >= 0 && dz->obj[t].n == JW_SUN_MOJINO + 10000, "  斜体は n に 10000");
            jw_cmd_set(0);
        }

        /* 全角・(，)全角・ｍ・単位表示 有 に、0表示 無・(，)表示 有・四捨五入・2桁 に戻して */
        app_command(32925);
        ctl(2332, &x, &y); app_press(x, y, 0);
        ctl(2487, &x, &y); app_press(x, y, 0);
        ctl(1708, &x, &y); app_press(x, y, 0);
        ctl(2489, &x, &y); app_press(x, y, 0);
        ctl(2420, &x, &y); app_press(x, y, 0);
        ctl(1801, &x, &y); app_press(x, y, 0);
        ctl(1346, &x, &y); app_press(x, y, 0);
        ctl(1719, &x, &y); app_press(x, y, 0);
        ctl(1717, &x, &y); app_press(x, y, 0);
        app_key('\r');                  /* Enter も OK */
        ck(!app_sunpodlg_open() && jw_cmd_sunpo_chk(1719) == 1
           && jw_cmd_sunpo_chk(1717) == 1 && jw_cmd_sunpo_chk(1801) == 1
           && jw_cmd_sunpo_chk(2420) == 0, "Enter で 全角・ｍ・単位表示 有");
        {
            int b0 = dz->ndrawn, t = -1;
            const char *s;
            jw_cmd_set(JW_CMD_SUNPO);
            jw_cmd_point(dz, app_view(), 100.0, 120.0, 0);
            jw_cmd_point(dz, app_view(), 100.0, 110.0, 0);
            jw_cmd_point(dz, app_view(), 100.0, 100.0, 0);
            jw_cmd_point(dz, app_view(), 200.0, 100.0, 0);
            for (k = b0; k < dz->ndrawn; k++)
                if (dz->obj[k].cls == JW_MOJI)
                    t = k;
            s = t >= 0 ? jw_str(dz, dz->obj[t].text) : "";
            printf("     port [%s]\n", s);
            /* 値は 100*sc/1000 ｍ。数字は全角（82 4f〜）、終わりは ｍ（82 8d） */
            ck(t >= 0 && (unsigned char)s[0] == 0x82
               && (unsigned char)s[1] >= 0x4f && (unsigned char)s[1] <= 0x58,
               "  数字は全角");
            k = (int)strlen(s);
            ck(k >= 2 && (unsigned char)s[k - 2] == 0x82
               && (unsigned char)s[k - 1] == 0x8d, "  単位は ｍ（R_STR0_00 の既定）");
            ck(t >= 0 && dz->obj[t].width
                   == (3u | 0x08u | 0x10u | 0x20u | 0x40u | (2u << 12)),
               "  +0x2c は 全角 8・ｍ 0x10・単位 0x20・(，) 0x40・桁 2");
            ck(t >= 0 && dz->obj[t].n == JW_SUN_MOJINO, "  斜体を消せば n は文字種だけ");
            jw_cmd_set(0);
        }

        /* 半径の R・φ 後付、全角を消し mm に戻して */
        app_command(32925);
        ctl(1801, &x, &y); app_press(x, y, 0);
        ctl(1346, &x, &y); app_press(x, y, 0);
        ctl(1718, &x, &y); app_press(x, y, 0);
        ctl(1716, &x, &y); app_press(x, y, 0);
        ctl(1711, &x, &y); app_press(x, y, 0);
        ctl(1, &x, &y); app_press(x, y, 0);
        ck(jw_cmd_sunpo_chk(1711) == 1 && jw_cmd_sunpo_chk(1710) == 0, "後付 を選ぶ");
        {
            jw_obj *c = jw_add(dz, JW_ENKO);
            int b0, t = -1;
            const char *s;
            c->d[0] = 300.0; c->d[1] = 300.0; c->d[2] = 20.0;
            c->d[4] = 6.283185307179586; c->d[6] = 1;
            app_fit();
            b0 = dz->ndrawn;
            jw_cmd_set(JW_CMD_SUNPO);
            jw_cmd_bar(dz, 1065);
            jw_cmd_point(dz, app_view(), 320.0, 300.0, 0);
            for (k = b0; k < dz->ndrawn; k++)
                if (dz->obj[k].cls == JW_MOJI)
                    t = k;
            s = t >= 0 ? jw_str(dz, dz->obj[t].text) : "";
            printf("     port [%s]\n", s);
            k = (int)strlen(s);
            ck(t >= 0 && k > 1 && s[k - 1] == 'R' && s[0] != 'R', "  半径の R は後ろ");
            ck(t >= 0 && (dz->obj[t].width & 0x0c00u) == 0x0800u, "  +0x2c は 後付 0x800");
            jw_cmd_set(0);
        }
        /* 元に戻す（ほかの試験に響かないように） */
        jw_cmd_sunpo_chk_set(1710, 1);
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
