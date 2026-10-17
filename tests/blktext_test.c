/* 反転した参照の中の字。原典で測った（ブロック解除 32909 で 倍率 (-1,1)・(1,-1)・
 * (-1,-1)・(1,1) の参照を戻した答え decomp/res/blktxt_free.jww。入れたのは
 * decomp/res/blktxt_base.jww = tools/mkblktxt.c）:
 *
 *   tests/blktext_test.exe
 *
 * 字の始点は 基点の写しのまま（入れ替えない）。幅・間隔に sgn(x)、高さに sgn(y) を
 * 掛け（負 = 裏返した字）、+0xd0 は 写った基線の向きに x が負なら 180° を足した角、
 * 終点は始点からその角へ 元の長さ。参照が回っているとき・縦書きは 測っていない。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/text.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b) { return fabs(a - b) < 1e-6; }

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

static jw_obj text(double x0, double y0, double x1, double y1, double deg)
{
    jw_obj o;

    memset(&o, 0, sizeof o);
    o.cls = JW_MOJI;
    o.d[0] = x0; o.d[1] = y0; o.d[2] = x1; o.d[3] = y1;
    o.d[4] = 2.0; o.d[5] = 2.0; o.d[6] = 0.5; o.d[7] = deg;
    return o;
}

static jw_obj ref(double sx, double sy, double ang)
{
    jw_obj r;

    memset(&r, 0, sizeof r);
    r.cls = JW_BLOCK;
    r.d[2] = sx; r.d[3] = sy; r.d[4] = ang;
    return r;
}

int main(void)
{
    jw_obj o, r;

    /* (-1,1): 水平の字。始点は基点の写し、幅・間隔が負、角は 0 のまま、終点は右へ */
    o = text(10, 5, 20, 5, 0);
    r = ref(-1, 1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], -10) && near(o.d[1], 5) && near(o.d[2], 0) && near(o.d[3], 5),
       "(-1,1) 始点は 元の始点の写し、終点は 始点から 元の長さだけ右");
    ck(near(o.d[7], 0.0) && near(o.d[4], -2) && near(o.d[5], 2) && near(o.d[6], -0.5),
       "  +0xd0 は 0、幅・間隔が負");

    /* (1,-1): 基線は水平のまま。高さが負 */
    o = text(10, 5, 20, 5, 0);
    r = ref(1, -1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], 10) && near(o.d[1], -5) && near(o.d[2], 20) && near(o.d[3], -5)
       && near(o.d[7], 0.0), "(1,-1) 始点・終点は そのまま写る");
    ck(near(o.d[4], 2) && near(o.d[5], -2) && near(o.d[6], 0.5), "  高さが負");

    /* (-1,-1): 180° 回し。幅・高さ・間隔が負、角は元のまま */
    o = text(10, 5, 20, 5, 0);
    r = ref(-1, -1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], -10) && near(o.d[1], -5) && near(o.d[2], 0) && near(o.d[3], -5)
       && near(o.d[7], 0.0), "(-1,-1) 始点は写し、終点は右、角は 0");
    ck(near(o.d[4], -2) && near(o.d[5], -2) && near(o.d[6], -0.5), "  幅・高さ・間隔が負");

    /* 斜め 45° の字 (-1,1): 写った基線は 135°、180° を足して -45° */
    o = text(0, 0, 10, 10, 45);
    r = ref(-1, 1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], 0) && near(o.d[1], 0) && near(o.d[7], -45.0)
       && near(o.d[2], 10) && near(o.d[3], -10), "斜め (-1,1): 始点はそのまま、+0xd0 は -45°");

    /* 正の倍率は変えない */
    o = text(10, 5, 20, 5, 0);
    r = ref(2, 2, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], 20) && near(o.d[2], 40) && near(o.d[7], 0.0), "正の倍率はそのまま");

    /* 描く: 負の幅は 左右に、負の高さは 上下に 裏返った字（src/text.c）。始点を軸にした鏡 */
    {
        enum { W = 160, H = 100 };
        static unsigned int img[3][W * H];
        fb_t fb;
        jw_view v;
        int k, i, n[3], x0[3], x1[3], y0[3], y1[3];
        double cw[3] = { 8.0, -8.0, 8.0 }, chh[3] = { 8.0, 8.0, -8.0 };

        memset(&v, 0, sizeof v);
        v.mmpp = 0.25;
        v.scale = 4.0;
        v.bx = 0;
        v.by = H - 20;
        v.clip.x = 0;
        v.clip.y = 0;
        v.clip.w = W;
        v.clip.h = H;
        fb.w = W;
        fb.h = H;
        for (k = 0; k < 3; k++) {
            fb.px = img[k];
            for (i = 0; i < W * H; i++)
                img[k][i] = 0xffffff;
            jw_text_run_face(&fb, &v, "F", 20.0, 5.0, 28.0, 5.0, cw[k], chh[k], 0x000000, 0,
                             "\x82l\x82r \x83S\x83V\x83" "b\x83N", 0);
            n[k] = 0;
            x0[k] = y0[k] = 1 << 20;
            x1[k] = y1[k] = -1;
            for (i = 0; i < W * H; i++)
                if (img[k][i] != 0xffffff) {
                    n[k]++;
                    if (i % W < x0[k]) x0[k] = i % W;
                    if (i % W > x1[k]) x1[k] = i % W;
                    if (i / W < y0[k]) y0[k] = i / W;
                    if (i / W > y1[k]) y1[k] = i / W;
                }
        }
        ck(n[0] > 10 && n[1] == n[0] && n[2] == n[0], "裏返した字も 同じ数の画素");
        ck(x1[1] <= x0[0] + 1 && x0[1] < x0[0] && y0[1] == y0[0] && y1[1] == y1[0],
           "負の幅: 始点の左へ（左右に裏返し）、高さはそのまま");
        ck(y0[2] > y0[0] && x0[2] == x0[0] && x1[2] == x1[0],
           "負の高さ: 始点の線の下へ（上下に裏返し）、幅はそのまま");
        {
            int same = 1, xs = jw_sx(&v, 20.0), j;

            for (i = 0; i < H && same; i++)
                for (j = 0; j < W; j++) {
                    int mj = 2 * xs - j;

                    if (mj < 0 || mj >= W)
                        continue;
                    if ((img[0][i * W + j] != 0xffffff) != (img[1][i * W + mj] != 0xffffff)
                        && j != xs && mj != xs && (j - 1 != xs) && (mj - 1 != xs)) {
                        same = 0;
                        break;
                    }
                }
            ck(same, "  左右の裏返しは 始点の画素の列を軸にした鏡像（1 列の丸めを除く）");
        }
    }

    /* 原典の答えと 一つずつ */
    {
        unsigned char *bb, *aa;
        long nb = 0, na = 0;
        jw_drawing ans, *d;
        int i, k, n1 = 0, n2 = 0, same = 1;
        const jw_obj *t1[64], *t2[64];

        bb = slurp("decomp/res/blktxt_base.jww", &nb);
        aa = slurp("decomp/res/blktxt_free.jww", &na);
        ck(bb && aa && jw_parse(&ans, aa, na) && app_open(bb, nb), "原典の答え blktxt_free を読む");
        d = (jw_drawing *)app_drawing();
        for (i = 0; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_BLOCK)
                d->obj[i].sel = 1;
        jw_cmd_block_free(d);
        for (i = 0; i < d->ndrawn && n1 < 64; i++)
            if (d->obj[i].cls == JW_MOJI && d->obj[i].d[1] != -1000.0)
                t1[n1++] = &d->obj[i];
        for (i = 0; i < ans.ndrawn && n2 < 64; i++)
            if (ans.obj[i].cls == JW_MOJI && ans.obj[i].d[1] != -1000.0)
                t2[n2++] = &ans.obj[i];
        ck(n1 == 20 && n2 == 20, "字は 4 参照 x 5 本");
        for (k = 0; k < n1 && k < n2; k++) {
            int q;

            for (q = 0; q < 8; q++)
                if (!near(t1[k]->d[q], t2[k]->d[q]))
                    same = 0;
            if (!same) {
                printf("     %d: %g %g %g %g | %g %g %g %g  vs %g %g %g %g | %g %g %g %g\n", k,
                       t1[k]->d[0], t1[k]->d[1], t1[k]->d[2], t1[k]->d[3], t1[k]->d[4],
                       t1[k]->d[5], t1[k]->d[6], t1[k]->d[7], t2[k]->d[0], t2[k]->d[1],
                       t2[k]->d[2], t2[k]->d[3], t2[k]->d[4], t2[k]->d[5], t2[k]->d[6],
                       t2[k]->d[7]);
                break;
            }
        }
        ck(same, "戻した字 20 本の 始点・終点・幅・高さ・間隔・角が 原典と同じ");
        free(bb);
        free(aa);
    }

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
