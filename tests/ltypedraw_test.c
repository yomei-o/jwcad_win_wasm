/* ランダム線・倍長線種の描き方と、図面が持つ線種の表。
 *
 *   tests/ltypedraw_test.exe        （repo の根で）
 *
 *   ランダム線 11〜15   FUN_004bbef0 の else の枝: パターンを上の桁から回し、
 *                       立てば -振れ幅、落ちれば +振れ幅だけ短い軸へずらした
 *                       点を LineTo でつなぐ。長い軸の一歩は
 *                       (int)(画面ピッチ * (1.41 - 傾き * 0.4))
 *   倍長線種 16〜19     破線の枝のまま、ピッチが 2（19 は 4）
 *   図面の表            .jww の線色の後ろの 4 long x 8・5 long x 5・
 *                       4 long x 4。原典は Pen\File（既定 1）なら開くと
 *                       doc の表を図面の値に替える。あとの 基本設定 OK が勝つ
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
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

/* one element drawn black on white at 1 mm a pixel, the origin in the
   middle: a line (x0,y0)-(x1,y1) in millimetres (y up), or a circle of
   radius r about the origin when r > 0.  Returns a hash of the picture. */
static unsigned long draw_one(fb_t *fb, int ltype, double x0, double y0,
                              double x1, double y1, double r)
{
    jw_drawing d;
    jw_obj o;
    jw_view v;
    unsigned long h = 5381;
    long i;

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
    o.ltype = (unsigned char)ltype;
    o.color = 1;
    o.text = o.face = -1;
    if (r > 0.0) {
        o.cls = JW_ENKO;
        o.d[2] = r;
        o.d[6] = 1.0;
    } else {
        o.cls = JW_SEN;
        o.d[0] = x0; o.d[1] = y0; o.d[2] = x1; o.d[3] = y1;
    }
    d.obj = &o;
    d.nobj = d.cobj = d.ndrawn = 1;
    memset(&v, 0, sizeof v);
    v.mmpp = 1.0;
    v.scale = 1.0;
    v.bx = FBW / 2;
    v.by = FBH / 2;
    v.clip.w = FBW;
    v.clip.h = FBH;
    for (i = 0; i < (long)FBW * FBH; i++)
        fb->px[i] = 0xffffffu;
    jw_draw(fb, &v, &d);
    for (i = 0; i < (long)FBW * FBH; i++)
        h = h * 33u + (fb->px[i] & 0xffffffu);
    return h;
}

static int prefs(const char *text)
{
    return app_prefs_read((const unsigned char *)text, (long)strlen(text));
}

static int lit(const fb_t *fb, int x, int y)
{
    return fb->px[(size_t)y * FBW + x] != 0xffffffu;
}

/* the lit pixels' spread across a level (rows) or upright (columns) line,
   and whether anything is lit at all */
static int spread(const fb_t *fb, int level, int *lo, int *hi)
{
    int x, y, n = 0;

    *lo = 1 << 30;
    *hi = -(1 << 30);
    for (y = 0; y < FBH; y++)
        for (x = 0; x < FBW; x++)
            if (lit(fb, x, y)) {
                int a = level ? y : x;
                if (a < *lo) *lo = a;
                if (a > *hi) *hi = a;
                n++;
            }
    return n;
}

int main(void)
{
    fb_t fb;
    unsigned long h_solid, h6;
    unsigned int pat;
    int unit, pitch, lo, hi, n, k, ok;

    if (!fb_init(&fb, FBW, FBH)) {
        printf("BAD  no framebuffer\n");
        return 1;
    }

    printf("既定の表（原典の .data 0x9fe188.. の 21 個）\n");
    jw_ltype_get(12, &pat, &unit, &pitch);
    ck(pat == 0xccb2b32au && pitch == 4, "  ランダム線2 は ccb2b32a・ピッチ 4");
    jw_ltype_get(16, &pat, &unit, &pitch);
    ck(pat == 0xfff99fffu && unit == 32 && pitch == 2, "  倍長線種1 は fff99fff・32・2");
    jw_ltype_get(19, &pat, &unit, &pitch);
    ck(pat == 0xfffe7fffu && unit == 32 && pitch == 4, "  倍長線種4 は fffe7fff・32・4");

    printf("ランダム線\n");
    h_solid = draw_one(&fb, 1, -180.0, 0.0, 180.0, 0.0, 0.0);
    /* 水平の 12: 振れ幅 1、一歩 (int)(4 * 1.41) = 5。線は (20,100) から
       (380,100)。ccb2b32a の上から 1,1,0,0, 1,1,0,0, 1,0,1,1 ... なので
       頂点は (25,99) (30,99) (35,101) (40,101) (45,99) (50,99) (55,101)
       (60,101) (65,99) (70,101) (75,99) (80,99) */
    ck(draw_one(&fb, 12, -180.0, 0.0, 180.0, 0.0, 0.0) != h_solid,
       "  水平のランダム線2 は実線ではない");
    n = spread(&fb, 1, &lo, &hi);
    ck(n > 0 && lo == 99 && hi == 101, "  上下 1 画素の中に収まる（99〜101 行）");
    printf("     %d px, rows %d..%d\n", n, lo, hi);
    ck(lit(&fb, 20, 100) && lit(&fb, 25, 99) && lit(&fb, 30, 99)
       && lit(&fb, 35, 101) && lit(&fb, 40, 101) && lit(&fb, 45, 99)
       && lit(&fb, 65, 99) && lit(&fb, 70, 101) && lit(&fb, 75, 99),
       "  頂点は 5 画素おき、ビットが 1 なら上・0 なら下");
    ck(!lit(&fb, 25, 101) && !lit(&fb, 35, 99) && !lit(&fb, 40, 99)
       && !lit(&fb, 70, 99), "  反対側は描かない");
    ck(lit(&fb, 380, 100) && !lit(&fb, 381, 100),
       "  終点の一画素（MoveTo・LineTo(+1) は +1 を塗らない）");

    /* 垂直の 13: 振れ幅 2、一歩 (int)(5 * 1.41) = 7 */
    draw_one(&fb, 13, 0.0, -90.0, 0.0, 90.0, 0.0);
    n = spread(&fb, 0, &lo, &hi);
    ck(n > 0 && lo >= 198 && hi <= 202, "  垂直のランダム線3 は左右 2 画素の中");
    printf("     %d px, columns %d..%d\n", n, lo, hi);
    ok = 0;
    for (k = 0; k < FBH; k++)
        ok |= lit(&fb, 198, k) * 1 | lit(&fb, 202, k) * 2;
    ck(ok == 3, "  両側へ 2 画素振れる");

    /* 4 画素までの短い線は原典も実線（FUN_004280f0 の 4 < 長さ） */
    ck(draw_one(&fb, 12, 0.0, 0.0, 4.0, 0.0, 0.0)
       == draw_one(&fb, 1, 0.0, 0.0, 4.0, 0.0, 0.0), "  4 画素の線は実線");

    /* 斜め・逆向き・円も落ちずに振れ幅の中 */
    ck(draw_one(&fb, 15, 150.0, 80.0, -150.0, -80.0, 0.0)
       != draw_one(&fb, 1, 150.0, 80.0, -150.0, -80.0, 0.0), "  斜めの逆向き");
    ck(draw_one(&fb, 11, 0.0, 0.0, 0.0, 0.0, 80.0)
       != draw_one(&fb, 1, 0.0, 0.0, 0.0, 0.0, 80.0), "  ランダム線の円は実線の円ではない");
    {
        int x, y, out = 0;
        for (y = 0; y < FBH; y++)
            for (x = 0; x < FBW; x++)
                if (lit(&fb, x, y)) {
                    double dx = x - 200, dy = y - 100, rr = dx * dx + dy * dy;
                    if (rr < 77.0 * 77.0 || rr > 83.0 * 83.0)
                        out++;
                }
        ck(out == 0, "  円の弦のジグザグも半径の近く（77〜83）");
    }

    printf("倍長線種\n");
    h6 = draw_one(&fb, 6, -180.0, 0.0, 180.0, 0.0, 0.0);
    ck(draw_one(&fb, 16, -180.0, 0.0, 180.0, 0.0, 0.0) != h6,
       "  倍長線種1 は一点鎖2 と違う（ピッチ 2）");
    jw_ltype_get(6, &pat, &unit, &pitch);
    jw_ltype_set(6, pat, unit, 2);
    ck(draw_one(&fb, 6, -180.0, 0.0, 180.0, 0.0, 0.0)
       == draw_one(&fb, 16, -180.0, 0.0, 180.0, 0.0, 0.0),
       "  一点鎖2 をピッチ 2 にすると倍長線種1 と同じ絵");
    jw_ltype_set(6, pat, unit, 1);
    ck(draw_one(&fb, 6, -180.0, 0.0, 180.0, 0.0, 0.0) == h6, "  戻す");

    printf("図面が持つ線種\n");
    {
        unsigned char *b;
        long nb;
        jw_drawing d;
        static const char *const names[] = {
            "orig/Test1.jww", "orig/Test5.jww", "orig/Test6.jww",
            "orig/Test7.jww", "decomp/res/new.jww",
        };
        unsigned int dpat[20];
        int dunit[20], dpitch[20], i;

        for (k = 2; k < 20; k++)
            jw_ltype_get(k, &dpat[k], &dunit[k], &dpitch[k]);
        b = slurp("orig/Test6.jww", &nb);
        if (!b || !jw_parse(&d, b, nb)) {
            printf("BAD  cannot read orig/Test6.jww\n");
            return 1;
        }
        ck(d.lt_have, "  Test6.jww は表を持つ");
        ck(d.lt[2].pat == 0x99999999u && d.lt[2].unit == 4 && d.lt[2].pitch == 1
           && d.lt[9].pat == 0x22222222u, "  線種 2・9 は既定と同じ値");
        ck(d.lt[12].pat == 0xccb2b32au && d.lt[12].ran == 1 && d.lt[12].pitch == 4
           && d.lt[12].prran == 1 && d.lt[12].prpit == 10,
           "  ランダム線2: ccb2b32a・振れ幅 1・ピッチ 4・印刷 1・10");
        ck(d.lt[19].pat == 0xfffe7fffu && d.lt[19].unit == 32
           && d.lt[19].pitch == 4 && d.lt[19].prpit == 40, "  倍長線種4: 32・4・40");

        /* 図面の値を変えて入れると、その値になる */
        d.lt[2].pitch = 3;
        d.lt[13].ran = 4;
        jw_ltype_from(&d);
        jw_ltype_get(2, 0, 0, &pitch);
        ck(pitch == 3, "  図面のピッチ 3 が入る");
        draw_one(&fb, 13, 0.0, -90.0, 0.0, 90.0, 0.0);
        spread(&fb, 0, &lo, &hi);
        ck(lo == 196 && hi == 204, "  図面の振れ幅 4 が入る");
        /* 単位 0 は入れない（割り算が回らない） */
        d.lt[3].unit = 0;
        d.lt[3].pitch = 5;
        jw_ltype_from(&d);
        jw_ltype_get(3, 0, &unit, &pitch);
        ck(unit == 8 && pitch == 1, "  単位 0 の線種はそのまま");
        d.lt_have = 0;
        d.lt[2].pitch = 7;
        jw_ltype_from(&d);
        jw_ltype_get(2, 0, 0, &pitch);
        ck(pitch == 3, "  表の無い図面（版 200 まで）は何も変えない");
        jw_free(&d);

        /* 開くと図面の値に戻る。基本設定 の OK（prefs）がそのあと勝つ */
        app_resize(1264, 741);
        if (!app_open(b, nb)) {
            printf("BAD  cannot open orig/Test6.jww\n");
            return 1;
        }
        free(b);
        jw_ltype_get(2, 0, 0, &pitch);
        ck(pitch == 1, "  開くと図面のピッチ 1");
        ck(prefs("[KIHON]\nT3.1652.0=2\n") >= 1, "  基本設定 で画面ピッチ 2");
        jw_ltype_get(2, 0, 0, &pitch);
        ck(pitch == 2, "  基本設定 の値が勝つ");
        ck(prefs("[KIHON]\nT3.1652.0=1\n") >= 1, "  ピッチ 1 へ戻す");

        /* 同梱の図面の値は画面の側は既定と同じ: 開いても絵は変わらない */
        ok = 1;
        for (i = 0; i < (int)(sizeof names / sizeof names[0]); i++) {
            b = slurp(names[i], &nb);
            if (!b || !app_open(b, nb)) {
                printf("BAD  cannot open %s\n", names[i]);
                ok = 0;
                free(b);
                continue;
            }
            free(b);
            for (k = 2; k < 20; k++) {
                unsigned int p2;
                int u2, q2;

                if (k == 10)
                    continue;
                jw_ltype_get(k, &p2, &u2, &q2);
                if (p2 != dpat[k] || q2 != dpitch[k]
                    || (u2 != dunit[k] && !(k >= 11 && k <= 15))) {
                    printf("     %s: 線種 %d %08x/%d/%d\n", names[i], k, p2, u2, q2);
                    ok = 0;
                }
            }
        }
        ck(ok, "  同梱の図面を開いても表は既定のまま（絵は同じ）");
    }

    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails != 0;
}
