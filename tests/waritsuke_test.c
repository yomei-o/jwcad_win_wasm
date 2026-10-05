/* 分割の 割付 (1324)・振分 (1325)・割付距離以下 (1326)。
 *
 *   tests/waritsuke_test.exe
 *
 * 割付 を押すと 分割 のバーが入れ替わり、分割数 (1411) の代わりに
 * 距離 (1412) が出て 振分 と 割付距離以下 が付きます。歩きは 等距離分割
 * と同じ二手で、線を二本指すだけ（`tools/probe115.sh`）。
 *
 * 原典の答え（どれも 1/100 の紙、距離 6000 ＝ 紙で 60 mm）:
 *
 *   平行な二本（間 183.673 mm）
 *     decomp/res/wari_base.jww  線二本だけ
 *     decomp/res/wari_off.jww   割付 —— 60, 60, 60 と置き、Ｂ側に 3.673 の余り
 *     decomp/res/wari_furi.jww  振分 —— 同じ三本を真ん中へ。両端 31.837
 *     decomp/res/wari_on.jww    割付距離以下 —— 183.673/4 = 45.918 の等分
 *     decomp/res/wari_both.jww  振分＋割付距離以下 —— 余りが無いので同じ
 *
 *   平行でない二本（始点どうし 183.673、終点どうし 244.898）
 *     decomp/res/wari_xbase.jww
 *     decomp/res/wari_xoff.jww  **終点側が 60 ずつ**の四本。つまり間は
 *                               「端どうしの距離の大きいほう」で測ります
 *     decomp/res/wari_xon.jww   244.898/5 = 48.980 の等分で四本
 *
 * 間がちょうど距離で割り切れるとき、距離が間より大きいとき、円を指した
 * ときは訊いていません。
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

/* every line of one of the original's answers, in the order written */
static int lines_of(const char *path, double *out, int max)
{
    static jw_drawing d;
    unsigned char *b;
    long n;
    int i, k = 0;

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
    for (i = 0; i < d.ndrawn && k < max; i++)
        if (d.obj[i].cls == JW_SEN) {
            out[k * 4 + 0] = d.obj[i].d[0];
            out[k * 4 + 1] = d.obj[i].d[1];
            out[k * 4 + 2] = d.obj[i].d[2];
            out[k * 4 + 3] = d.obj[i].d[3];
            k++;
        }
    return k;
}

/* The point in paper millimetres, straight at the command: one of the
   原典's clicks here lands below the drawing area, and app_press would
   give it to the status line. */
static void click(double x, double y, int button)
{
    jw_cmd_point((jw_drawing *)app_drawing(), app_view(), x, y, button);
}

/* the bar's ticks are the port's own state and outlive app_new(), so set
   them rather than toggle them */
static void tick(jw_drawing *d, int id, int on)
{
    if ((jw_cmd_bar_check(id) > 0) != (on != 0))
        jw_cmd_bar(d, id);
}

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (i = 0; s[i]; i++)
        jw_cmd_box_key((unsigned char)s[i]);
    jw_cmd_box_key(13);
}

/* draw the two lines, press what is asked for, and divide */
static int port_run(double b1y, double b2y, int furi, int ika,
                    double *out, int max)
{
    jw_drawing *d;
    int i, k = 0;

    app_new();
    app_resize(1264, 741);
    d = (jw_drawing *)app_drawing();
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* 水平・垂直 off */
    click(-155.510204, 26.326531, 0);
    click(89.387755, 26.326531, 0);
    click(-155.510204, -157.346939, 0);
    click(89.387755, b2y, 0);
    (void)b1y;
    app_command(JW_CMD_BUNKATSU);
    tick(d, 1324, 1);                   /* 割付 */
    tick(d, 1325, furi);
    tick(d, 1326, ika);
    type_box(1412, "6000");
    click((-155.510204 + 89.387755) / 2.0, 26.326531, 0);       /* line A */
    click((-155.510204 + 89.387755) / 2.0,
          (-157.346939 + b2y) / 2.0, 0);                        /* line B */
    for (i = 2; i < d->ndrawn && k < max; i++)  /* the two picked first */
        if (d->obj[i].cls == JW_SEN) {
            out[k * 4 + 0] = d->obj[i].d[0];
            out[k * 4 + 1] = d->obj[i].d[1];
            out[k * 4 + 2] = d->obj[i].d[2];
            out[k * 4 + 3] = d->obj[i].d[3];
            k++;
        }
    return k;
}

/* the original writes the pair the other way round sometimes, so compare
   the two y values of each line as a set */
static int same_line(const double *a, const double *b)
{
    return (fabs(a[1] - b[1]) < 1e-4 && fabs(a[3] - b[3]) < 1e-4)
        || (fabs(a[1] - b[3]) < 1e-4 && fabs(a[3] - b[1]) < 1e-4);
}

static void compare(const char *path, int skip, const double *got, int ngot,
                    const char *what)
{
    double want[64];
    int n = lines_of(path, want, 16), i, ok = 1;

    if (!n)
        return;
    n -= skip;
    if (n != ngot)
        ok = 0;
    for (i = 0; ok && i < n; i++)
        if (!same_line(want + (skip + i) * 4, got + i * 4))
            ok = 0;
    printf("%-4s %s (%d / %d 本)\n", ok ? "ok" : "BAD", what, ngot, n);
    if (!ok) {
        for (i = 0; i < n || i < ngot; i++)
            printf("     %2d want %s%.6f %.6f%s  got %s%.6f %.6f%s\n", i,
                   i < n ? "" : "(", i < n ? want[(skip + i) * 4 + 1] : 0.0,
                   i < n ? want[(skip + i) * 4 + 3] : 0.0, i < n ? "" : ")",
                   i < ngot ? "" : "(", i < ngot ? got[i * 4 + 1] : 0.0,
                   i < ngot ? got[i * 4 + 3] : 0.0, i < ngot ? "" : ")");
        fails++;
    }
}

int main(void)
{
    double got[64];
    int n;

    /* ------------------------------------------------ parallel pair --- */
    n = port_run(-157.346939, -157.346939, 0, 0, got, 16);
    compare("decomp/res/wari_off.jww", 2, got, n, "割付 だけ");

    n = port_run(-157.346939, -157.346939, 1, 0, got, 16);
    compare("decomp/res/wari_furi.jww", 2, got, n, "振分");

    n = port_run(-157.346939, -157.346939, 0, 1, got, 16);
    compare("decomp/res/wari_on.jww", 2, got, n, "割付距離以下");

    n = port_run(-157.346939, -157.346939, 1, 1, got, 16);
    compare("decomp/res/wari_both.jww", 2, got, n, "振分 ＋ 割付距離以下");

    /* -------------------------------------------- and a skewed pair --- */
    n = port_run(-157.346939, -218.571429, 0, 0, got, 16);
    compare("decomp/res/wari_xoff.jww", 2, got, n,
            "平行でない二本（大きいほうの端で測る）");

    n = port_run(-157.346939, -218.571429, 0, 1, got, 16);
    compare("decomp/res/wari_xon.jww", 2, got, n, "  その 割付距離以下");

    /* and without 割付 it is still the old 等距離分割 */
    {
        jw_drawing *d;

        app_new();
        app_resize(1264, 741);
        d = (jw_drawing *)app_drawing();
        app_command(JW_CMD_SEN);
        if (jw_cmd_bar_check(1333) > 0)
            app_key(32);
        click(-155.510204, 26.326531, 0);
        click(89.387755, 26.326531, 0);
        click(-155.510204, -157.346939, 0);
        click(89.387755, -157.346939, 0);
        app_command(JW_CMD_BUNKATSU);
        tick(d, 1324, 0);
        type_box(1411, "4");
        click((-155.510204 + 89.387755) / 2.0, 26.326531, 0);
        click((-155.510204 + 89.387755) / 2.0, -157.346939, 0);
        ck(d->ndrawn == 5, "割付 を押さなければ 等距離分割 のまま");
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
