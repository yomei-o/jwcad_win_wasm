/* 連続線 の 丸面辺寸法 (1411) と 実寸 (2096) —— 原典の答えと突き合わせる。
 *
 *   tests/renzoku_test.exe
 *
 * `tools/probe159.sh`（直角）と `tools/probe162.sh`（鋭角・短い辺・
 * 一直線・五点）が原典に引かせた `decomp/res/p159_*.jww`・`p162_*.jww`。
 * 下敷きは `decomp/res/new.jww` で、そこへ新しく出たものを、原典と
 * 同じ順に同じ数だけ、座標まで見ます。
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

static void run(const char *name, const char *box, int jitsu,
                const int (*pt)[2], int npt, int last, int arc, int after)
{
    char path[96];
    jw_drawing ref, base;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t r;
    int i, ok = 1;

    b = slurp("decomp/res/new.jww", &n);
    memset(&base, 0, sizeof base);
    if (!b || !jw_parse(&base, b, n)) {
        printf("BAD  new.jww が読めません\n");
        fails++;
        return;
    }
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
    app_command(32883);
    /* 連続弧 も 実寸 と同じく命令をまたいで残ります */
    if ((jw_cmd_bar_check(2492) > 0) != (arc != 0))
        jw_cmd_bar((jw_drawing *)app_drawing(), 2492);
    jw_cmd_box_put(1411, box ? box : "");
    /* 実寸 の点き具合は命令をまたいで残るので、欲しい側へ寄せます */
    if ((jw_cmd_bar_check(2096) > 0) != (jitsu != 0))
        jw_cmd_bar((jw_drawing *)app_drawing(), 2096);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    for (i = 0; i < npt; i++)
        app_press(r.x + pt[i][0], r.y + pt[i][1], 0);
    if (last >= 0)
        app_press(r.x + pt[last][0], r.y + pt[last][1], 1);
    if (after)
        app_command(after);
    d = app_drawing();
    {
        const jw_obj *ra[64], *ma[64];
        int rn = 0, mn = 0;

        for (i = 0; i < ref.ndrawn && rn < 64; i++)
            if (ref.obj[i].cls == JW_SEN || ref.obj[i].cls == JW_ENKO)
                ra[rn++] = &ref.obj[i];
        for (i = 0; i < d->ndrawn && mn < 64; i++)
            if (d->obj[i].cls == JW_SEN || d->obj[i].cls == JW_ENKO)
                ma[mn++] = &d->obj[i];
        if (rn != mn) {
            printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, rn, mn);
            fails++;
            return;
        }
        for (i = 0; i < rn; i++) {
            int k;
            if (ma[i]->cls != ra[i]->cls)
                ok = 0;
            for (k = 0; k < (ra[i]->cls == JW_SEN ? 4 : 5); k++)
                /* 始角の ±π は、符号つきの 0 の違いで入れ替わります */
                if (fabs(ma[i]->d[k] - ra[i]->d[k]) > 1e-6
                    && !(ra[i]->cls == JW_ENKO && k == 3
                         && fabs(fabs(ma[i]->d[k]) - 3.141592653589793) < 1e-6
                         && fabs(fabs(ra[i]->d[k]) - 3.141592653589793) < 1e-6)) {
                    ok = 0;
                    printf("     %d.d[%d] 原典 %.6f・移植 %.6f\n", i, k,
                           ra[i]->d[k], ma[i]->d[k]);
                }
        }
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

/* 下敷き new.jww に 連続線 を入れて、pre 点 → 釦 → post 点 → 命令の送り直し
   (resend) と流す。新しく出た線・弧を out へ。 */
static int drive(int arc, const int (*pt)[2], int pre, int npt, int press,
                 int resend, jw_obj *out, int max)
{
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t r;
    int i, base, k = 0;

    b = slurp("decomp/res/new.jww", &n);
    if (!b)
        return -1;
    app_new();
    app_resize(1264, 741);
    app_open(b, n);
    free(b);
    app_command(32883);
    if ((jw_cmd_bar_check(2492) > 0) != (arc != 0))
        jw_cmd_bar((jw_drawing *)app_drawing(), 2492);
    jw_cmd_box_put(1411, "");
    if (jw_cmd_bar_check(2096) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 2096);
    d = app_drawing();
    base = d->ndrawn;
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    for (i = 0; i < npt; i++) {
        if (i == pre && press) {
            jw_cmd_bar((jw_drawing *)d, press < 0 ? -press : press);
            if (press < 0)
                jw_cmd_bar((jw_drawing *)d, -press);
        }
        app_press(r.x + pt[i][0], r.y + pt[i][1], 0);
    }
    if (npt == pre && press)
        jw_cmd_bar((jw_drawing *)d, press);
    if (resend)
        app_command(32883);
    d = app_drawing();
    for (i = base; i < d->ndrawn && k < max; i++)
        if (d->obj[i].cls == JW_SEN || d->obj[i].cls == JW_ENKO)
            out[k++] = d->obj[i];
    return k;
}

static void check(const char *name, int ok)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

static int same_obj(const jw_obj *a, const jw_obj *b)
{
    int k;

    if (a->cls != b->cls)
        return 0;
    for (k = 0; k < (a->cls == JW_SEN ? 4 : 5); k++)
        if (fabs(a->d[k] - b->d[k]) > 1e-9)
            return 0;
    return 1;
}

/* 終了 (1064)・弧反転 (1067)。逆コンパイルの読みで入れたもので、原典では
   押していない（src/cmd.c の bar_press の注）。 */
static void end_flip(void)
{
    static const int ABC[5][2] = {
        { 400, 350 }, { 600, 450 }, { 500, 420 }, { 300, 300 }, { 350, 500 }
    };
    jw_obj a[16], b[16];
    int na, nb, i, ok;

    /* 終了 は命令の送り直しと同じく、ひとつ手前の線を図面へ入れる */
    na = drive(0, ABC, 3, 3, 1064, 0, a, 16);
    nb = drive(0, ABC, 0, 3, 0, 1, b, 16);
    ok = na == 2 && nb == 2;
    for (i = 0; ok && i < na; i++)
        ok = same_obj(&a[i], &b[i]);
    check("終了 1064 = 送り直し（二本入る）", ok);

    /* 終了 のあとは新しい連続線: 四点目・五点目は前とつながらない */
    na = drive(0, ABC, 3, 5, 1064, 1, a, 16);
    ok = na == 3 && a[2].cls == JW_SEN
         && !(fabs(a[2].d[0] - a[1].d[2]) < 1e-9
              && fabs(a[2].d[1] - a[1].d[3]) < 1e-9);
    check("終了 のあとは新しい鎖", ok);

    /* 終了 が点くのは一本引けてから */
    {
        unsigned char *bb;
        long n;
        rect_t r;
        jw_drawing *d;
        int e0, e1, e2, e3;

        bb = slurp("decomp/res/new.jww", &n);
        app_new();
        app_resize(1264, 741);
        app_open(bb, n);
        free(bb);
        app_command(32883);
        if (jw_cmd_bar_check(2492) > 0)
            jw_cmd_bar((jw_drawing *)app_drawing(), 2492);
        d = (jw_drawing *)app_drawing();
        ui_view_rect(app_fb()->w, app_fb()->h, &r);
        e0 = jw_cmd_bar_enabled(d, 1064);
        app_press(r.x + ABC[0][0], r.y + ABC[0][1], 0);
        e1 = jw_cmd_bar_enabled(d, 1064);
        app_press(r.x + ABC[1][0], r.y + ABC[1][1], 0);
        e2 = jw_cmd_bar_enabled(d, 1064);
        jw_cmd_bar(d, 1064);
        e3 = jw_cmd_bar_enabled(d, 1064);
        check("終了 の点き具合（0 0 1 0）", !e0 && !e1 && e2 && !e3);
    }

    /* 弧反転: 二つ目の弧が同じ円の反対回りになる（中心・半径・始角は同じ、
       掃きは 2π ずれて符号が逆） */
    na = drive(1, ABC, 0, 4, 0, 1, a, 16);
    nb = drive(1, ABC, 3, 4, 1067, 1, b, 16);
    ok = na == 2 && nb == 2 && same_obj(&a[0], &b[0])
         && a[1].cls == JW_ENKO && b[1].cls == JW_ENKO;
    for (i = 0; ok && i < 4; i++)
        ok = fabs(a[1].d[i] - b[1].d[i]) < 1e-9;
    ok = ok && a[1].d[4] * b[1].d[4] < 0.0
         && fabs(fabs(a[1].d[4] - b[1].d[4]) - 2.0 * 3.141592653589793) < 1e-9;
    check("弧反転 1067: 続きの弧が反対回り", ok);

    /* 二度押せば元どおり */
    nb = drive(1, ABC, 3, 4, -1067, 1, b, 16);
    ok = na == 2 && nb == 2 && same_obj(&a[0], &b[0]) && same_obj(&a[1], &b[1]);
    check("弧反転 を二度押すと元の回り", ok);
}

int main(void)
{
    static const int RECT[4][2] = { {300,300}, {600,300}, {600,500}, {900,500} };
    static const int ACUTE[4][2] = { {300,300}, {600,300}, {350,450}, {700,500} };
    static const int SHORT[4][2] = { {300,300}, {600,300}, {600,310}, {900,500} };
    static const int LINE[4][2] = { {300,300}, {600,300}, {900,300}, {1000,300} };
    static const int FIVE[5][2] = { {300,300}, {600,300}, {600,500}, {900,500}, {900,300} };

    run("p159_plain", 0, 0, RECT, 4, 3, 0, 0);
    run("p159_r10", "10", 0, RECT, 4, 3, 0, 0);
    run("p159_r10j", "10", 1, RECT, 4, 3, 0, 0);
    run("p159_r1000j", "1000", 1, RECT, 4, 3, 0, 0);
    run("p162_acute", "10", 0, ACUTE, 4, 3, 0, 0);
    run("p162_short", "10", 0, SHORT, 4, 3, 0, 0);
    run("p162_line", "10", 0, LINE, 4, 3, 0, 0);
    run("p162_five", "10", 0, FIVE, 5, 4, 0, 0);
    {
        static const int ABC[4][2] = { {400,350}, {600,450}, {500,420}, {300,300} };
        /* 連続線: ひとつ手前の線は、命令を送り直すと図面に入る */
        run("p164_base", 0, 0, ABC, 3, -1, 0, 0);
        run("p164_jitsu", 0, 0, ABC, 3, -1, 0, 0);
        run("p164_resend", 0, 0, ABC, 3, -1, 0, 32883);
        run("p164_other", 0, 0, ABC, 3, -1, 0, 32771);
        /* 連続弧: 三点では入らず、四点目で一つ目の弧が入る */
        run("p163_c3", 0, 0, ABC, 3, -1, 1, 0);
        run("p163_c4", 0, 0, ABC, 4, -1, 1, 0);
        run("p163_c3r", 0, 0, ABC, 3, 2, 1, 0);
        run("p163_c2", 0, 0, ABC, 2, -1, 1, 0);
    }
    end_flip();
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
