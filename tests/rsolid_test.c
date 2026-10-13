/* 円ソリッドの閉じ方と 線種 111 -- 原典が描いた絵との突き合わせ。
 *
 *   tests/rsolid_test.exe
 *
 * decomp/res/rs_kinds.jww は線種 101 の 扇形（末尾 0）・弓形（5）・円外側（-1）・
 * 全円（100）と、線種 111 の同じものを並べた図面（移植で書き出したもの）。
 * decomp/res/rs_kinds.png はそれを原典で開いて tools/jwdraw.ps1 の shot:
 * （PrintWindow）で撮り、窓の枠を外して 1264x741 にしたもの（2026-10-13）。
 *
 * 111 は弧だけなので画素まで一致する。101 の塗りは 形（扇・弓・接線の角）は
 * 合っているが、縁の 1 画素がまだ原典の GDI と揃っていない（2026-10-13 で
 * 全円 282・扇形 240° 192・円外側 90° 138 画素。円外側は原典のほうが弧の側に
 * 一列多く、全円は移植のほうが一回り大きい）。その分は図形ごとに 違う画素
 * 300 以下・黒い画素の数が原典の 15% 以内 で見ている。閉じ方を取り違えれば
 * （扇と弓、角と中心）千画素単位でずれるので、それは捕まえられる。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/view.h"
#include "../src/image.h"

static int fails;

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

int main(void)
{
    static const char *NAME[] = {
        "101 扇形 240°", "101 弓形 240°", "101 円外側 90°", "101 扇形 90°（0.3 から）",
        "111 扇形 240°（弧だけ）", "111 弓形 240°（弧だけ）", "111 円外側 90°（弧だけ）",
        "111 全円（円周だけ）", "101 全円", "101 円外側 90°（π から）",
    };
    long n;
    unsigned char *b;
    jw_img im;
    const fb_t *fb;
    const jw_drawing *d;
    const jw_view *v;
    int i, k = 0;

    app_resize(1264, 741);
    b = slurp("decomp/res/rs_kinds.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  decomp/res/rs_kinds.jww が開けません\n");
        return 1;
    }
    free(b);
    b = slurp("decomp/res/rs_kinds.png", &n);
    if (!b || !jw_img_decode(b, n, &im) || im.w != 1264 || im.h != 741) {
        printf("BAD  decomp/res/rs_kinds.png が読めません\n");
        return 1;
    }
    free(b);
    app_paint();
    fb = app_fb();
    d = app_drawing();
    v = app_view();
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        int x0, x1, y0, y1, x, y, diff = 0, inkr = 0, inkm = 0, ok;

        if (o->cls != JW_SOLID)
            continue;
        x0 = jw_sx(v, o->d[0] - o->d[2]) - 3;
        x1 = jw_sx(v, o->d[0] + o->d[2]) + 3;
        y0 = jw_sy(v, o->d[1] + o->d[2]) - 3;
        y1 = jw_sy(v, o->d[1] - o->d[2]) + 3;
        for (y = y0; y <= y1; y++)
            for (x = x0; x <= x1; x++) {
                const unsigned char *q = im.rgb + ((size_t)y * im.w + x) * 3;
                unsigned p = fb->px[(size_t)y * fb->w + x];
                int r = q[0] < 128, m = ((p >> 16) & 0xff) < 128;

                inkr += r;
                inkm += m;
                diff += r != m;
            }
        if (o->ltype >= 110)
            ok = diff == 0;
        else
            ok = diff <= 300 && abs(inkr - inkm) * 100 <= 15 * inkr;
        printf("%-4s %s: 原典の黒 %d・移植 %d、違う画素 %d\n", ok ? "ok" : "BAD",
               k < 10 ? NAME[k] : "?", inkr, inkm, diff);
        if (!ok)
            fails++;
        k++;
    }
    if (k != 10) {
        printf("BAD  ソリッドが %d 個（10 個のはず）\n", k);
        fails++;
    }
    jw_img_free(&im);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
