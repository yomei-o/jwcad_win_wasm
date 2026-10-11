/* 建具平面の流れ（壁を指す → 位置を指す）を、原典の答えと突き合わせる。
 *
 *   tests/tategu3_test.exe
 *
 * `tools/probe180.sh`・`probe184.sh`・`probe183` が原典に引かせた
 * `decomp/res/p180_*.jww`・`p184_*.jww`。壁を線で引き、建具平面に入り、
 * 建具 [5] を選び（原典はファイル選択の窓。ここは jw_cmd_tategu_choose）、
 * 同じクリックを送って、出てきた要素を座標まで見ます。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/tategu.h"

static int fails;
static int cmdid = 32848;
static int cat = 0, itm = 4;           /* 選ぶ建具（jw_tgdat の番号と中の何番） */

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

typedef struct { int x, y, b; } clk;

static void run(const char *name, const int (*wall)[2], const clk *c, int nc)
{
    char path[96];
    jw_drawing ref;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t r;
    int i, ok = 1, ri = 0, mi = 0;
    const jw_obj *ra[256], *ma[256];

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
    app_press(r.x + wall[0][0], r.y + wall[0][1], 0);
    app_press(r.x + wall[1][0], r.y + wall[1][1], 0);
    app_command(cmdid);
    jw_cmd_tategu_choose(cat, itm);
    jw_cmd_box_put(1424, "70");
    jw_cmd_box_put(1425, "35");
    jw_cmd_box_put(1426, "1700");
    jw_cmd_box_put(1427, "0");
    for (i = 0; i < nc; i++)
        app_press(r.x + c[i].x, r.y + c[i].y, c[i].b);
    d = app_drawing();
    for (i = 0; i < ref.ndrawn && ri < 256; i++)
        if (ref.obj[i].cls == JW_SEN)
            ra[ri++] = &ref.obj[i];
    for (i = 0; i < d->ndrawn && mi < 256; i++)
        if (d->obj[i].cls == JW_SEN)
            ma[mi++] = &d->obj[i];
    if (ri != mi) {
        printf("BAD  %s: 線 原典 %d・移植 %d\n", name, ri, mi);
        fails++;
        return;
    }
    for (i = 0; i < ri; i++) {
        int k;

        for (k = 0; k < 4; k++)
            if (fabs(ra[i]->d[k] - ma[i]->d[k]) > 2e-3) {
                ok = 0;
                printf("     %d.d[%d] 原典 %.4f・移植 %.4f\n", i, k,
                       ra[i]->d[k], ma[i]->d[k]);
            }
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

/* 建具立面 (32865): 位置を一回指すだけ。基準点の釦・反転・角度・内法の箱で
   p192_* と同じ設定を作ってクリックする */
typedef struct {
    const char *name;
    int item;
    const char *size;           /* 内法の箱 */
    int bh, bv;                 /* 左内法・下内法の釦を押した回数 */
    int flip_h, flip_v;         /* 横反転・縦反転 */
    const char *angle;
} case3;

static void run3(const case3 *k)
{
    char path[96];
    jw_drawing ref;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t r;
    int i, ok = 1, ri = 0, mi = 0;
    const jw_obj *ra[256], *ma[256];

    b = slurp("decomp/res/new.jww", &n);
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    free(b);
    snprintf(path, sizeof path, "decomp/res/%s.jww", k->name);
    memset(&ref, 0, sizeof ref);
    b = slurp(path, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  %s が読めません\n", path);
        fails++;
        return;
    }
    free(b);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    app_command(32865);
    jw_cmd_tategu_choose(jw_tgdat_index(3, 0), k->item);
    jw_cmd_box_put(1426, k->size);
    jw_cmd_box_put(1430, k->angle);
    for (i = 0; i < k->bh; i++)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1065);
    for (i = 0; i < k->bv; i++)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1066);
    /* 反転の箱は次の試験まで残るので、ほしい状態にそろえる */
    if ((jw_cmd_bar_check(1323) > 0) != (k->flip_h != 0))
        jw_cmd_bar((jw_drawing *)app_drawing(), 1323);
    if ((jw_cmd_bar_check(1324) > 0) != (k->flip_v != 0))
        jw_cmd_bar((jw_drawing *)app_drawing(), 1324);
    app_press(r.x + 450, r.y + 400, 0);
    d = app_drawing();
    for (i = 0; i < ref.ndrawn && ri < 256; i++)
        if (ref.obj[i].cls == JW_SEN)
            ra[ri++] = &ref.obj[i];
    for (i = 0; i < d->ndrawn && mi < 256; i++)
        if (d->obj[i].cls == JW_SEN)
            ma[mi++] = &d->obj[i];
    if (ri != mi) {
        printf("BAD  %s: 線 原典 %d・移植 %d\n", k->name, ri, mi);
        fails++;
        return;
    }
    for (i = 0; i < ri; i++) {
        int j;

        for (j = 0; j < 4; j++)
            if (fabs(ra[i]->d[j] - ma[i]->d[j]) > 2e-3) {
                ok = 0;
                printf("     %d.d[%d] 原典 %.4f・移植 %.4f\n", i, j,
                       ra[i]->d[j], ma[i]->d[j]);
            }
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", k->name);
    if (!ok)
        fails++;
}

int main(void)
{
    static const int H[2][2] = { {300,400}, {800,400} };
    static const int HREV[2][2] = { {800,400}, {300,400} };
    static const int V[2][2] = { {500,200}, {500,600} };
    static const int D[2][2] = { {300,300}, {700,500} };
    static const int D2[2][2] = { {700,500}, {300,300} };
    static const int ST[2][2] = { {300,500}, {400,300} };
    static const clk a[] = { {450,400,0}, {550,400,0} };
    static const clk left[] = { {450,400,0}, {350,400,0} };
    static const clk off[] = { {450,400,0}, {550,420,0} };
    static const clk vd[] = { {500,300,0}, {500,400,0} };
    static const clk vu[] = { {500,300,0}, {500,200,0} };
    static const clk dr[] = { {400,350,0}, {500,400,0} };
    static const clk steep[] = { {350,400,0}, {380,340,0} };
    static const clk rr[] = { {800,400,1}, {300,400,1}, {550,420,0} };

    run("p180_h_r", H, a, 2);
    run("p180_h_l", H, left, 2);
    run("p180_h_off", H, off, 2);
    run("p180_v_d", V, vd, 2);
    run("p180_v_u", V, vu, 2);
    run("p180_d_r", D, dr, 2);
    run("p184_rev", HREV, a, 2);
    run("p184_diag2", D2, dr, 2);
    run("p184_steep", ST, steep, 2);
    run("p184_rr", H, rr, 3);
    /* 平面詳細用（JW_OPT1C）の [3]・[7]: 内出・外出の箱（75）で面が決まる */
    cat = jw_tgdat_index(1, 2);
    itm = 2;
    cmdid = 32866;                      /* 建具断面: 同じ流れ、下枠（左）は動かない */
    cat = jw_tgdat_index(2, 0);
    itm = 0;
    run("p190_32866_A1", H, a, 2);
    itm = 14;
    run("p190_32866_A15", H, a, 2);
    cmdid = 32848;
    cat = jw_tgdat_index(1, 2);
    itm = 2;
    run("p187_C3", H, a, 2);
    itm = 6;
    run("p187_C7", H, a, 2);
    itm = 8;
    run("p187_C9", H, a, 2);
    {
        static const case3 c3[] = {
            { "p192_n4_h2400", 3, "1700 , 2400", 0, 0, 0, 0, "" },
            { "p192_n4_rhr",   3, "1700 , 2400", 2, 0, 0, 0, "" },
            { "p192_n4_rvc",   3, "1700 , 2400", 0, 1, 0, 0, "" },
            { "p192_n4_fh",    3, "1700 , 2400", 0, 0, 1, 0, "" },
            { "p192_n4_fv",    3, "1700 , 2400", 0, 0, 0, 1, "" },
            { "p192_n4_a30",   3, "1700 , 2400", 0, 0, 0, 0, "30" },
            { "p192_n2_w3000", 1, "3000 , 2400", 0, 0, 0, 0, "" },
        };
        unsigned k;

        for (k = 0; k < sizeof c3 / sizeof c3[0]; k++)
            run3(&c3[k]);
    }
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
