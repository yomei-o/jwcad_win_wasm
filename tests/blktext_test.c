/* 反転した参照の中の字: 基線の始点・終点の入れ替えと +0xd0（FUN_00465f40）。
 *
 *   tests/blktext_test.exe
 *
 * 倍率が負の参照を掛けると、写した基線が ±90° を越え字の角が (-90,90] の内なら
 * 始点・終点を入れ替え、+0xd0 を新しい基線の角にする。(1,-1) の水平の字は
 * 基線の向きが変わらないので入れ替えない。逆コンパイルの読み、
 * 原典では押していない。
 */
#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b) { return fabs(a - b) < 1e-6; }

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

    /* (-1,1): 水平の字は 始点・終点が入れ替わり、読む向きのまま */
    o = text(10, 5, 20, 5, 0);
    r = ref(-1, 1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], -20) && near(o.d[1], 5) && near(o.d[2], -10) && near(o.d[3], 5),
       "(-1,1) 始点は 元の終点の写し");
    ck(near(o.d[7], 0.0), "  +0xd0 は 0");

    /* (1,-1): 基線は水平のまま。入れ替えない */
    o = text(10, 5, 20, 5, 0);
    r = ref(1, -1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], 10) && near(o.d[1], -5) && near(o.d[2], 20) && near(o.d[3], -5)
       && near(o.d[7], 0.0), "(1,-1) 入れ替えない");

    /* (-1,-1): 180° 回し。字は 逆さにならず 入れ替える */
    o = text(10, 5, 20, 5, 0);
    r = ref(-1, -1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], -20) && near(o.d[1], -5) && near(o.d[2], -10) && near(o.d[3], -5)
       && near(o.d[7], 0.0), "(-1,-1) 入れ替え");

    /* 斜め 45° の字 (-1,1): 基線は 135° → 入れ替えて -45° */
    o = text(0, 0, 10, 10, 45);
    r = ref(-1, 1, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], -10) && near(o.d[1], 10) && near(o.d[2], 0) && near(o.d[3], 0)
       && near(o.d[7], -45.0), "斜め (-1,1): 入れ替えて -45°");

    /* 正の倍率は変えない */
    o = text(10, 5, 20, 5, 0);
    r = ref(2, 2, 0);
    jw_obj_blkput(&o, &r);
    ck(near(o.d[0], 20) && near(o.d[2], 40) && near(o.d[7], 0.0), "正の倍率はそのまま");

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
