/* 多角形 (32894) の 三つの指定と 中央 (1068) —— 原典の答えと突き合わせる。
 *
 *   tests/takaku_test.exe
 *
 * `tools/probe165.sh`（指定 × 寸法あり／なし × 中央）と `tools/probe166.sh`
 * （中央を k 回押す）が原典に引かせた `decomp/res/p165_*.jww`・`p166_*.jww`。
 * 下敷きは `decomp/res/new.jww`。出てきた線を順に、座標まで見ます。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

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

static void run2(const char *name, int mode, int boxid, const char *box,
                 int pos, const int (*pt)[2], int npt, int rlast)
{
    char path[96];
    jw_drawing ref;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t r;
    const jw_obj *ra[96], *ma[96];
    int i, rn = 0, mn = 0, ok = 1;

    b = slurp("decomp/res/new.jww", &n);
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    free(b);
    snprintf(path, sizeof path, "decomp/res/%s.jww", name);
    memset(&ref, 0, sizeof ref);
    b = slurp(path, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  %s が読めません\n", path);
        fails++;
        return;
    }
    free(b);
    app_command(32894);
    jw_cmd_bar((jw_drawing *)app_drawing(), mode);
    jw_cmd_box_put(boxid, box);
    while (jw_cmd_takaku_pos() != pos)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1068);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    for (i = 0; i < npt; i++)
        app_press(r.x + pt[i][0], r.y + pt[i][1], 0);
    if (rlast)
        app_press(r.x + pt[npt - 1][0], r.y + pt[npt - 1][1], 1);
    d = app_drawing();
    for (i = 0; i < ref.ndrawn && rn < 96; i++)
        if (ref.obj[i].cls == JW_SEN)
            ra[rn++] = &ref.obj[i];
    for (i = 0; i < d->ndrawn && mn < 96; i++)
        if (d->obj[i].cls == JW_SEN)
            ma[mn++] = &d->obj[i];
    if (rn != mn) {
        printf("BAD  %s: 線 原典 %d・移植 %d\n", name, rn, mn);
        fails++;
        return;
    }
    for (i = 0; i < rn; i++) {
        int k;
        for (k = 0; k < 4; k++)
            if (fabs(ma[i]->d[k] - ra[i]->d[k]) > 1e-6) {
                ok = 0;
                printf("     %d.d[%d] 原典 %.6f・移植 %.6f\n", i, k,
                       ra[i]->d[k], ma[i]->d[k]);
            }
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

static void run(const char *name, int mode, const char *box, int pos,
                const int (*pt)[2], int npt)
{
    run2(name, mode, mode == 1689 ? 1412 : 1411, box, pos, pt, npt, 0);
}

int main(void)
{
    static const int ABC[3][2] = { {400,350}, {600,450}, {500,420} };
    static const int ONE[1][2] = { {500,400} };
    static const int M[3] = { 1690, 1691, 1692 };
    char nm[64];
    int m, k;

    for (m = 0; m < 3; m++) {
        snprintf(nm, sizeof nm, "p165_%d_full", M[m]);
        run(nm, M[m], "1000", 0, ABC, 3);
        snprintf(nm, sizeof nm, "p165_%d_empty", M[m]);
        run(nm, M[m], "", 0, ABC, 3);
        snprintf(nm, sizeof nm, "p165_%d_c", M[m]);
        run(nm, M[m], "1000", 1, ABC, 3);
        snprintf(nm, sizeof nm, "p165_%d_c_empty", M[m]);
        run(nm, M[m], "", 1, ABC, 3);
    }
    /* 中央 を k 回: 0 中央・1 頂点・2 辺 の三つを回る */
    for (k = 0; k <= 10; k++) {
        snprintf(nm, sizeof nm, "p166_k%d", k);
        run(nm, 1692, "1000", k % 3, ONE, 1);
    }
    {
        /* ２辺: 二点が底辺・箱が両端から頂点までの長さ・三点目が側 */
        static const int A4[4][2] = { {400,350}, {600,450}, {500,420}, {300,300} };
        static const int OTHER[3][2] = { {400,350}, {600,450}, {700,200} };
        static const int AB4[4][2] = { {400,350}, {600,450}, {300,500}, {300,300} };

        run("p167_abc", 1689, "1000 , 1000", 0, A4, 3);
        run("p167_abcd", 1689, "1000 , 1000", 0, A4, 4);
        run("p167_abcd2", 1689, "1000 , 1000", 0, AB4, 4);
        run("p167_b700", 1689, "700,500", 0, A4, 3);
        run("p167_b700d", 1689, "700,500", 0, A4, 4);
        run("p167_b0", 1689, "0", 0, A4, 4);
        run("p167_ab", 1689, "1000 , 1000", 0, A4, 2);
        run("p168_big", 1689, "10000,10000", 0, A4, 3);
        run("p168_bigd", 1689, "10000,10000", 0, A4, 4);
        run("p168_uneq", 1689, "8000,12000", 0, A4, 3);
        run("p168_uneqo", 1689, "8000,12000", 0, OTHER, 3);
        run("p168_one", 1689, "10000", 0, A4, 3);
        run("p168_xonly", 1689, "0,10000", 0, A4, 3);
        run("p168_zero", 1689, "0", 0, A4, 3);
        run("p168_zero4", 1689, "0", 0, A4, 4);
        run2("p168_zeroR", 1689, 1412, "0", 0, A4, 3, 1);
    }
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
