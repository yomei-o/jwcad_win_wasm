/* 面取 (32859) の五つの指定 —— 原典の答えと突き合わせる。
 *
 *   tests/mentori2_test.exe
 *
 * `tools/probe173.sh`（左右対称）・`probe174.sh`（非対称）・`probe176.sh`
 * （鈍角）が原典に引かせた `decomp/res/p173〜p176_*.jww`。二本の線を引いて、
 * 指定を選び、寸法を打ち、二本を指す。出てきた線と弧を順に、座標まで見ます。
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

static void run3(int cmd, const char *name, const int (*ln)[2], int mode,
                 const char *box, const int (*pk)[2])
{
    char path[96];
    jw_drawing ref;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t r;
    const jw_obj *ra[32], *ma[32];
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
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    app_command(32771);
    if (jw_cmd_bar_check(1333) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
    for (i = 0; i < 4; i++)
        app_press(r.x + ln[i][0], r.y + ln[i][1], 0);
    app_command(cmd);
    jw_cmd_bar((jw_drawing *)app_drawing(), mode);
    if (box)
        jw_cmd_box_put(1411, box);
    app_press(r.x + pk[0][0], r.y + pk[0][1], 0);
    app_press(r.x + pk[1][0], r.y + pk[1][1], 0);
    d = app_drawing();
    for (i = 0; i < ref.ndrawn && rn < 32; i++)
        if (ref.obj[i].cls == JW_SEN || ref.obj[i].cls == JW_ENKO)
            ra[rn++] = &ref.obj[i];
    for (i = 0; i < d->ndrawn && mn < 32; i++)
        if (d->obj[i].cls == JW_SEN || d->obj[i].cls == JW_ENKO)
            ma[mn++] = &d->obj[i];
    if (rn != mn) {
        printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, rn, mn);
        fails++;
        return;
    }
    for (i = 0; i < rn; i++) {
        int k, m = ra[i]->cls == JW_SEN ? 4 : 7;
        if (ma[i]->cls != ra[i]->cls)
            ok = 0;
        for (k = 0; k < m; k++)
            if (fabs(ma[i]->d[k] - ra[i]->d[k]) > 1e-4) {
                ok = 0;
                printf("     %d.d[%d] 原典 %.6f・移植 %.6f\n", i, k,
                       ra[i]->d[k], ma[i]->d[k]);
            }
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

static void run(const char *name, const int (*ln)[2], int mode,
                const char *box, const int (*pk)[2])
{
    run3(32859, name, ln, mode, box, pk);
}

int main(void)
{
    static const int S[4][2] = { {300,300}, {700,500}, {300,500}, {700,300} };
    static const int SP[2][2] = { {400,350}, {400,450} };
    static const int A[4][2] = { {300,300}, {700,500}, {350,600}, {600,300} };
    static const int AP[2][2] = { {400,350}, {400,540} };
    static const int O[4][2] = { {300,300}, {800,300}, {400,200}, {700,400} };
    static const int OP[2][2] = { {450,300}, {650,367} };

    run("p173_m1689", S, 1689, "1000", SP);
    run("p173_m1690", S, 1690, "1000", SP);
    run("p173_m1691", S, 1691, "1000", SP);
    run("p173_m1693", S, 1693, "1000", SP);
    run("p174_a1689", A, 1689, "1000", AP);
    run("p174_a1690", A, 1690, "1000", AP);
    run("p174_a1691", A, 1691, "1000", AP);
    run("p174_a1692", A, 1692, "", AP);
    run("p174_a1693", A, 1693, "1000", AP);
    run("p174_r50", A, 1691, "5000", AP);
    run("p175_l2000", A, 1692, "", AP);
    run("p176_o1689", O, 1689, "1000", OP);
    run("p176_o1690", O, 1690, "1000", OP);
    run("p176_o1691", O, 1691, "1000", OP);
    run("p176_o1693", O, 1693, "1000", OP);
    /* 分割 (32867) の 等角度分割 (1690) */
    {
        static const int PL[4][2] = { {300,300}, {700,300}, {300,500}, {700,500} };
        static const int PP[2][2] = { {400,300}, {400,500} };

        run3(32867, "p178_x4", A, 1690, "4", AP);
        run3(32867, "p178_x3", A, 1690, "3", AP);
        run3(32867, "p178_par", PL, 1690, "4", PP);
    }
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
