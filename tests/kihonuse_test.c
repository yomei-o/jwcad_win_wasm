/* 基本設定 の箱の字が移植の働きに届くこと。
 *
 *   tests/kihonuse_test.exe
 *
 *   線種 タブ    線種 2〜9 のパターン・単位・画面のピッチ → src/draw.c の
 *                LTYPE（jw_ltype_set）。原典は FUN_004bbef0 がパターンを
 *                上の桁から 32 ビット回し、一ビットを Pitch 画素で歩く
 *   一般(1)      Undo の回数 → 戻る の段数の上限（jw_cmd_undo_limit）、
 *                オートセーブ時間・バックアップ数（app_autosave_minutes・
 *                app_backup_gens・app_backup_ext）
 *
 * 箱の字は app_prefs_read で入れる（OK が残したのと同じ所へ入り、
 * kh_apply が効く）。既定の値なら絵が今までと一画素も違わないことも見る。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/draw.h"
#include "../src/fb.h"
#include "../src/jww.h"
#include "../src/view.h"

#define FBW 400
#define FBH 200

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
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

/* one element of type cls (a level line, or a whole circle) drawn black on
   white; returns a hash of the picture and puts the lit pixels of row y
   into row[] */
static unsigned long draw_one(fb_t *fb, int cls, int ltype, int y,
                              unsigned char *row)
{
    jw_drawing d;
    jw_obj o;
    jw_view v;
    unsigned long h = 5381;
    long i;
    int x;

    memset(&d, 0, sizeof d);
    memset(&o, 0, sizeof o);
    d.paper_hw = 297.0;
    d.paper_hh = 210.0;
    d.paper_size = 3;
    d.group[0].state = 3;
    d.group[0].scale = 1.0;
    d.group[0].layer[0].state = 3;
    d.pen_rgb[1] = 0x00000000u;
    d.pen_width[1] = 1;
    o.cls = cls;
    o.ltype = (unsigned char)ltype;
    o.color = 1;
    o.text = o.face = -1;
    if (cls == JW_SEN) {
        o.d[0] = -180.0; o.d[1] = 0.0; o.d[2] = 180.0; o.d[3] = 0.0;
    } else {
        o.d[0] = 0.0; o.d[1] = 0.0; o.d[2] = 80.0;      /* r */
        o.d[3] = 0.0; o.d[4] = 0.0; o.d[5] = 0.0; o.d[6] = 1.0;
    }
    d.obj = &o;
    d.nobj = d.cobj = d.ndrawn = 1;
    memset(&v, 0, sizeof v);
    v.mmpp = 1.0;
    v.scale = 1.0;
    v.bx = FBW / 2;
    v.by = FBH / 2;
    v.clip.x = 0;
    v.clip.y = 0;
    v.clip.w = FBW;
    v.clip.h = FBH;
    for (i = 0; i < (long)FBW * FBH; i++)
        fb->px[i] = 0xffffffu;
    jw_draw(fb, &v, &d);
    for (i = 0; i < (long)FBW * FBH; i++)
        h = h * 33u + (fb->px[i] & 0xffffffu);
    if (row)
        for (x = 0; x < FBW; x++)
            row[x] = fb->px[(size_t)(FBH / 2 + y) * FBW + x] != 0xffffffu;
    return h;
}

/* how many times the row goes from unlit to lit */
static int runs(const unsigned char *row)
{
    int x, n = 0;

    for (x = 1; x < FBW; x++)
        if (row[x] && !row[x - 1])
            n++;
    return n;
}

/* the lengths of the lit runs, the first and the last left out */
static void run_lens(const unsigned char *row, int *lo, int *hi)
{
    int x = 0, k = 0;

    *lo = 1 << 30;
    *hi = 0;
    while (x < FBW && !row[x])
        x++;
    while (x < FBW && row[x])
        x++;                            /* the first one */
    for (;;) {
        int s;

        while (x < FBW && !row[x])
            x++;
        s = x;
        while (x < FBW && row[x])
            x++;
        if (x >= FBW || s >= FBW)
            break;
        /* a run that ends at the far end is the last: leave it out */
        {
            int t = x;

            while (t < FBW && !row[t])
                t++;
            if (t >= FBW)
                break;
        }
        if (x - s < *lo)
            *lo = x - s;
        if (x - s > *hi)
            *hi = x - s;
        k++;
    }
    if (!k)
        *lo = *hi = 0;
}

static int prefs(const char *text)
{
    return app_prefs_read((const unsigned char *)text, (long)strlen(text));
}

static int draw_line(jw_drawing *d, double x0, double y0, double x1, double y1)
{
    int n0 = d->ndrawn;

    jw_cmd_point(d, app_view(), x0, y0, 0);
    jw_cmd_point(d, app_view(), x1, y1, 0);
    return d->ndrawn > n0;
}

int main(void)
{
    fb_t fb;
    unsigned char row[FBW], row2[FBW];
    unsigned long h_line[10], h_arc[10], h;
    unsigned int pat;
    int unit, pitch, lt, lo, hi, i, k, ok;

    if (!fb_init(&fb, FBW, FBH)) {
        printf("BAD  no framebuffer\n");
        return 1;
    }

    /* ------------------------------------------------------- 線種 --- */
    printf("線種\n");
    jw_ltype_get(9, &pat, &unit, &pitch);
    ck(pat == 0x22222222u && unit == 4 && pitch == 1,
       "  補助線の既定はレジストリの Type_09 22222222・Unit 4・Pitch 1");
    jw_ltype_get(5, &pat, &unit, &pitch);
    ck(pat == 0xf99ff99fu && unit == 16 && pitch == 1, "  一点鎖1 は f99ff99f・16・1");
    for (lt = 1; lt <= 9; lt++) {
        h_line[lt] = draw_one(&fb, JW_SEN, lt, 0, 0);
        h_arc[lt] = draw_one(&fb, JW_ENKO, lt, 0, 0);
    }
    /* the same values put back through the setter: not a pixel moves */
    for (lt = 2; lt <= 9; lt++) {
        jw_ltype_get(lt, &pat, &unit, &pitch);
        jw_ltype_set(lt, pat, unit, pitch);
    }
    ok = 1;
    for (lt = 1; lt <= 9; lt++)
        ok &= draw_one(&fb, JW_SEN, lt, 0, 0) == h_line[lt]
              && draw_one(&fb, JW_ENKO, lt, 0, 0) == h_arc[lt];
    ck(ok, "  既定の値を入れ直しても線・円の絵は同じ");

    /* through the dialog's boxes, the same text as the defaults */
    ck(prefs("[KIHON]\nT3.1001.1=-  --  --  --  --  --  --  --  -\n"
             "T3.1777.0=4\nT3.1652.0=1\n") >= 3, "  既定と同じ字を箱へ");
    ok = 1;
    for (lt = 1; lt <= 9; lt++)
        ok &= draw_one(&fb, JW_SEN, lt, 0, 0) == h_line[lt]
              && draw_one(&fb, JW_ENKO, lt, 0, 0) == h_arc[lt];
    ck(ok, "  （箱から）既定の字なら絵は同じ");

    /* 点線1 を 4 on 4 off に: 字は上の桁から、空白で 0 */
    ck(prefs("[KIHON]\nT3.1001.1=----    ----    ----    ----\n"
             "T3.1777.0=8\nT3.1652.0=1\n") >= 3, "  点線1 を ----____ ・単位 8 に");
    jw_ltype_get(2, &pat, &unit, &pitch);
    ck(pat == 0xf0f0f0f0u && unit == 8 && pitch == 1, "  パターンは f0f0f0f0（字の後ろの空きも 0）");
    draw_one(&fb, JW_SEN, 2, 0, row);
    run_lens(row, &lo, &hi);
    ck(lo >= 4 && hi <= 5, "  画面の線は 4 画素前後の点が並ぶ");
    printf("     runs %d, lit run %d..%d\n", runs(row), lo, hi);

    /* ピッチ 2: 一ビットが 2 画素、点の数はおよそ半分 */
    k = runs(row);
    ck(prefs("[KIHON]\nT3.1652.0=2\n") >= 1, "  画面ピッチ 2");
    jw_ltype_get(2, 0, 0, &pitch);
    ck(pitch == 2, "  ピッチが入る");
    draw_one(&fb, JW_SEN, 2, 0, row2);
    run_lens(row2, &lo, &hi);
    ck(lo >= 8 && hi <= 10, "  点の長さは倍（8 画素前後）");
    ck(runs(row2) * 2 >= k - 2 && runs(row2) * 2 <= k + 2, "  点の数はおよそ半分");
    printf("     runs %d (pitch 1: %d), lit run %d..%d\n", runs(row2), k, lo, hi);
    ck(draw_one(&fb, JW_ENKO, 2, 0, 0) != h_arc[2], "  破線の円もピッチで変わる");

    /* 範囲の外（単位 40・ピッチ 0）は効かない */
    ck(prefs("[KIHON]\nT3.1777.0=40\n") >= 1, "  単位 40（1〜32 の外）");
    jw_ltype_get(2, &pat, &unit, &pitch);
    ck(pat == 0xf0f0f0f0u && unit == 8 && pitch == 2, "  線種 2 はそのまま");
    ck(!jw_ltype_set(2, 0, 8, 0) && !jw_ltype_set(1, 0, 8, 1)
       && !jw_ltype_set(10, 0, 8, 1), "  ピッチ 0・線種 1・線種 10 は断る");

    /* 全部の字が線（パターン ffffffff）なら実線と同じ絵 */
    ck(prefs("[KIHON]\nT3.1001.1=--------------------------------\n"
             "T3.1777.0=32\nT3.1652.0=1\n") >= 3, "  点線1 を全部 -");
    ck(draw_one(&fb, JW_SEN, 2, 0, 0) == h_line[1]
       && draw_one(&fb, JW_ENKO, 2, 0, 0) == h_arc[1], "  実線と同じ（円も GDI の円の道）");

    /* カンマも 0、ほかの字は 1（ランダム線の字 ' と ,） */
    ck(prefs("[KIHON]\nT3.1001.7='',,'',,'',,'',,'',,'',,'',,'',,\n") >= 1,
       "  二点鎖2 を '' ,, の繰り返しに");
    jw_ltype_get(8, &pat, 0, 0);
    ck(pat == 0xccccccccu, "  ' は 1、, は 0");

    /* もとへ戻す */
    ck(prefs("[KIHON]\nT3.1001.1=-  --  --  --  --  --  --  --  -\n"
             "T3.1001.7=------------  -  -  ------------\n"
             "T3.1777.0=4\nT3.1652.0=1\n") >= 4, "  既定の字へ戻す");
    ok = 1;
    for (lt = 1; lt <= 9; lt++)
        ok &= draw_one(&fb, JW_SEN, lt, 0, 0) == h_line[lt]
              && draw_one(&fb, JW_ENKO, lt, 0, 0) == h_arc[lt];
    ck(ok, "  戻すと絵も元どおり");

    /* ------------------------------------------------ 一般(1) ------- */
    printf("Undo の回数\n");
    {
        unsigned char *b;
        long n;
        jw_drawing *d;

        app_resize(1264, 741);
        b = slurp("decomp/res/new.jww", &n);
        if (!b || !app_open(b, n)) {
            printf("BAD  cannot open decomp/res/new.jww\n");
            return 1;
        }
        free(b);
        d = (jw_drawing *)app_drawing();
        app_fit();
        ck(jw_cmd_undo_limit_get() == 100, "  既定は 100");
        ck(prefs("[KIHON]\nT0.1934.0=3\n") >= 1, "  Undo 3");
        ck(jw_cmd_undo_limit_get() == 3, "  上限が 3 に");
        jw_cmd_set(JW_CMD_SEN);
        if (jw_cmd_bar_check(1333) > 0)
            jw_cmd_bar(d, 1333);
        ok = 1;
        for (i = 0; i < 6; i++)
            ok &= draw_line(d, 10.0 * i, 0.0, 10.0 * i + 5.0, 30.0);
        ck(ok && d->ndrawn >= 6, "  線を六本");
        ck(jw_cmd_undo_depth() == 3, "  戻れるのは三段");
        k = d->ndrawn;
        for (i = 0; i < 10; i++)
            app_command(JW_CMD_UNDO);
        ck(d->ndrawn == k - 3, "  戻る を十回押しても消えるのは三本");
        ck(!jw_cmd_can_undo(), "  そのあとは戻れない");
        app_command(JW_CMD_REDO);
        ck(d->ndrawn == k - 2, "  進む は効く");
        ck(prefs("[KIHON]\nT0.1934.0=0\n") >= 1 && jw_cmd_undo_limit_get() == 3,
           "  0（1〜100 の外）は効かない");
        ck(prefs("[KIHON]\nT0.1934.0=100\n") >= 1 && jw_cmd_undo_limit_get() == 100,
           "  100 に戻す");
        ok = 1;
        for (i = 0; i < 5; i++)
            ok &= draw_line(d, 10.0 * i, 50.0, 10.0 * i + 5.0, 80.0);
        /* 進む で戻した一段と合わせて六段 */
        ck(ok && jw_cmd_undo_depth() == 6, "  上限 100 なら五本とも戻れる");
    }

    printf("オートセーブ・バックアップ\n");
    ck(app_autosave_minutes() == 30, "  オートセーブの既定は 30 分");
    ck(app_backup_gens(0) == 1 && app_backup_gens(1) == 1, "  バックアップの既定は一世代");
    ck(prefs("[KIHON]\nT0.1049.0=5\nT0.1055.0=3\n") >= 2, "  5 分・3 世代");
    ck(app_autosave_minutes() == 5, "  オートセーブ 5 分");
    ck(app_backup_gens(0) == 3, "  3 世代");
    ck(app_backup_gens(1) == 1, "  A: B: は一世代だけ");
    ck(!strcmp(app_backup_ext(1), "BAK") && !strcmp(app_backup_ext(2), "BK2")
       && !strcmp(app_backup_ext(3), "BK3"), "  BAK・BK2・BK3");
    ck(prefs("[KIHON]\nT0.1055.0=-2\n") >= 1 && app_backup_gens(0) == 2
       && app_backup_gens(1) == 0, "  -2: A: B: には作らない、ほかは二世代");
    ck(prefs("[KIHON]\nT0.1055.0=0\n") >= 1 && app_backup_gens(0) == 0
       && app_backup_gens(1) == 0, "  0: 作らない");
    ck(prefs("[KIHON]\nT0.1049.0=0\nT0.1055.0=12\n") >= 2
       && app_autosave_minutes() == 5 && app_backup_gens(0) == 0,
       "  0 分・12 世代（範囲の外）は効かない");
    ck(prefs("[KIHON]\nT0.1049.0=30\nT0.1055.0=1\n") >= 2
       && app_autosave_minutes() == 30 && app_backup_gens(0) == 1, "  既定へ戻す");

    fb_free(&fb);
    printf("%s kihonuse\n", fails ? "BAD " : "ok  ");
    return fails ? 1 : 0;
}
