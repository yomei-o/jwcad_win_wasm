/* 目盛基準点 (32912) —— 目盛を刻む原点を動かす一手。
 *
 *   tests/mesh_test.exe
 *
 * 問いかけは「■■■■    基準点を指示して下さい  (L)free  (R)Read
 * ■■■■」（5314）で、一手で終わります（`tools/probe120.sh`）。
 *
 * 動かすのは**図面の目盛原点**です。`src/draw.c` が目盛をそこから刻み、
 * .jww に書かれているので、**絵でなくファイルで測れました**
 * （`tools/probe132.sh`、`tools/mesh.exe` が読み出します）:
 *
 *   decomp/res/mesh_base.jww  何もしない           ox=0        oy=0
 *   decomp/res/mesh_a.jww     画面 (300,300) を指す ox=-155.510204 oy=26.326531
 *   decomp/res/mesh_b.jww     画面 (700,500) を指す ox=89.387755  oy=-96.122449
 *
 * どちらも**指した所の紙座標そのもの**です。目盛間隔を 10 にして目盛を
 * 出した原典では、この命令のあと格子が 5,706 画素ぶんずれました
 * （`tools/probe131.sh`）—— 目盛間隔を入れないと目盛は出ないので、
 * 一度目はそれで空振りしています。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void cknear(double got, double want, double tol, const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.6f / %.6f)\n", ok ? "ok" : "BAD", what, got, want);
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

static int origin_of(const char *path, double *ox, double *oy)
{
    static jw_drawing d;
    unsigned char *b;
    long n;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        return 0;
    }
    memset(&d, 0, sizeof d);
    if (!jw_parse(&d, b, n)) {
        printf("BAD  cannot parse %s\n", path);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    *ox = d.mesh_ox;
    *oy = d.mesh_oy;
    return 1;
}

int main(void)
{
    double ox, oy;
    const jw_drawing *d;
    rect_t vr;

    /* ----------------------------------------------- the original's own */
    if (origin_of("decomp/res/mesh_base.jww", &ox, &oy)) {
        cknear(ox, 0.0, 1e-9, "原典: 何もしなければ原点は 0");
        cknear(oy, 0.0, 1e-9, "  縦も");
    }
    if (origin_of("decomp/res/mesh_a.jww", &ox, &oy)) {
        cknear(ox, -155.510204, 1e-6, "原典: (300,300) を指すと ox");
        cknear(oy, 26.326531, 1e-6, "  と oy");
    }
    if (origin_of("decomp/res/mesh_b.jww", &ox, &oy)) {
        cknear(ox, 89.387755, 1e-6, "原典: (700,500) を指すと ox");
        cknear(oy, -96.122449, 1e-6, "  と oy");
    }

    /* -------------------------------------------------- and the port's */
    app_resize(1264, 741);
    app_new();
    d = app_drawing();
    /* the probe's clicks are posted to the view, so they are the view's
       own coordinates; app_press takes the frame's */
    ui_view_rect(1264, 741, &vr);
    cknear(d->mesh_ox, 0.0, 1e-9, "移植も新規では原点 0");

    ck(app_command(32912) != 0, "目盛基準点 が出る");
    ck(jw_cmd_get_mode_now() == 32912, "  一手の割り込みが立つ");
    app_press(vr.x + 300, vr.y + 300, 0);
    ck(jw_cmd_get_mode_now() == 0, "  一手で終わる");
    cknear(d->mesh_ox, -155.510204, 1e-6, "  原点が指した所に動く");
    cknear(d->mesh_oy, 26.326531, 1e-6, "  縦も");

    app_command(32912);
    app_press(vr.x + 700, vr.y + 500, 0);
    cknear(d->mesh_ox, 89.387755, 1e-6, "もう一度指すとそちらへ");
    cknear(d->mesh_oy, -96.122449, 1e-6, "  縦も");

    /* it does not draw anything */
    ck(d->ndrawn == 0, "図面には何も足さない");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
