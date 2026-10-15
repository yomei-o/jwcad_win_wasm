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

/* 基準角度 (1065)・基点 (1066) と、前の線の上へ戻るクリックを捨てる決まり。
   原典の答えは bsw_32883_1065_solo・1066_solo（tools/barsweep.sh）だけで、
   ほかは逆コンパイルの読み（FUN_006de7a0・FUN_006dcff0、src/cmd.c の
   rn_next の注）から組んだ期待値。 */
static int kj_drive(const int (*pt)[2], int npt, int kak, int kiten,
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
    jw_cmd_renzoku_reset();
    app_command(32883);
    if (jw_cmd_bar_check(2492) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 2492);
    jw_cmd_box_put(1411, "");
    if (jw_cmd_bar_check(2096) > 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 2096);
    d = app_drawing();
    for (i = 0; i < kak; i++)
        jw_cmd_bar((jw_drawing *)d, 1065);
    if (kiten)
        jw_cmd_bar((jw_drawing *)d, 1066);
    base = d->ndrawn;
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    for (i = 0; i < npt; i++)
        app_press(r.x + pt[i][0], r.y + pt[i][1], 0);
    if (resend)
        app_command(32883);
    d = app_drawing();
    for (i = base; i < d->ndrawn && k < max; i++)
        if (d->obj[i].cls == JW_SEN || d->obj[i].cls == JW_ENKO)
            out[k++] = d->obj[i];
    jw_cmd_renzoku_reset();
    return k;
}

/* 画面の点が図面のどこか: 素の連続線で一本引いて読む */
static void kj_where(int x, int y, double *px, double *py)
{
    int pt[2][2];
    jw_obj o[4];

    pt[0][0] = x;
    pt[0][1] = y;
    pt[1][0] = x + 100;
    pt[1][1] = y + 37;
    *px = *py = 1e30;
    if (kj_drive((const int (*)[2])pt, 2, 0, 0, 1, o, 4) == 1) {
        *px = o[0].d[0];
        *py = o[0].d[1];
    }
}

static int kj_near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

/* 刻み st（度）の倍数の向きか */
static int kj_mult(double dx, double dy, double st)
{
    double v = atan2(dy, dx) * 180.0 / 3.141592653589793 / st;

    return fabs(v - floor(v + 0.5)) < 1e-9;
}

static void kijun(void)
{
    static const int ABC[3][2] = { { 400, 350 }, { 600, 450 }, { 500, 420 } };
    static const int Q[3][2] = { { 300, 300 }, { 600, 280 }, { 620, 500 } };
    static const int COL[4][2] = { { 300, 300 }, { 600, 300 }, { 900, 300 }, { 600, 500 } };
    static const int K[3][2] = { { 300, 300 }, { 600, 300 }, { 700, 500 } };
    const double PI = 3.141592653589793;
    double ax, ay, bx, by, cx, cy, l, a, ex, ey;
    jw_obj o[8];
    int n, ok;

    /* 原典の答え: 素から 1065 だけ押して三クリックすると何も入らない */
    {
        unsigned char *b;
        long nb;
        jw_drawing ref, *d;
        rect_t r;
        int i, have = 0;
        const char *ans[2] = { "decomp/res/bsw_32883_1065_solo.jww",
                               "decomp/res/bsw_32883_1066_solo.jww" };
        int id[2] = { 1065, 1066 };

        for (i = 0; i < 2; i++) {
            int j, m;

            b = slurp("decomp/res/sweep_base.jww", &nb);
            app_new();
            app_resize(1264, 741);
            if (!b || !app_open(b, nb)) {
                free(b);
                check("sweep_base.jww が開ける", 0);
                return;
            }
            free(b);
            jw_cmd_renzoku_reset();
            d = (jw_drawing *)app_drawing();
            app_command(32771);
            if (jw_cmd_bar_check(1333) > 0)
                jw_cmd_bar(d, 1333);
            app_command(32785);
            app_command(32883);
            if (jw_cmd_bar_check(2492) > 0)
                jw_cmd_bar(d, 2492);
            jw_cmd_bar(d, id[i]);
            ui_view_rect(app_fb()->w, app_fb()->h, &r);
            for (j = 0; j < 3; j++)
                app_press(r.x + ABC[j][0], r.y + ABC[j][1], 0);
            d = (jw_drawing *)app_drawing();
            memset(&ref, 0, sizeof ref);
            b = slurp(ans[i], &nb);
            have = b && jw_parse(&ref, b, nb);
            free(b);
            /* 文字は並びが違うので数えず、線・円は一つずつ相手を探す */
            ok = have && ref.ndrawn == d->ndrawn;
            for (m = 0; ok && m < ref.ndrawn; m++) {
                int k, q, hit = 0;

                if (ref.obj[m].cls == JW_MOJI)
                    continue;
                for (q = 0; !hit && q < d->ndrawn; q++) {
                    hit = ref.obj[m].cls == d->obj[q].cls;
                    for (k = 0; hit && k < 4; k++)
                        hit = fabs(ref.obj[m].d[k] - d->obj[q].d[k]) < 1e-6;
                }
                ok = hit;
            }
            check(i == 0 ? "1065 だけ押して三クリック = 原典（何も入らない）"
                         : "1066 だけ押して三クリック = 原典（素と同じ一本）", ok);
            jw_free(&ref);
        }
        jw_cmd_renzoku_reset();
    }

    /* 同じ三点を送り直しで締めると、一本目だけが -30° に丸まって入る */
    kj_where(ABC[0][0], ABC[0][1], &ax, &ay);
    kj_where(ABC[1][0], ABC[1][1], &bx, &by);
    n = kj_drive(ABC, 3, 1, 0, 1, o, 8);
    l = hypot(bx - ax, by - ay);
    ok = n == 1 && kj_near(o[0].d[0], ax) && kj_near(o[0].d[1], ay)
         && kj_near(o[0].d[2], ax + l * cos(-PI / 6.0))
         && kj_near(o[0].d[3], ay + l * sin(-PI / 6.0));
    check("基準角度 15°: 一本目は -30°・長さそのまま、三点目は捨てる", ok);

    /* 二度押すと 45°: 一本目は 0°、二本目は前の終わりから -90° */
    kj_where(Q[0][0], Q[0][1], &ax, &ay);
    kj_where(Q[1][0], Q[1][1], &bx, &by);
    kj_where(Q[2][0], Q[2][1], &cx, &cy);
    n = kj_drive(Q, 3, 2, 0, 1, o, 8);
    l = hypot(bx - ax, by - ay);
    ex = ax + l;                        /* 0° に丸まった一本目の終わり */
    ey = ay;
    a = hypot(cx - ex, cy - ey);
    ok = n == 2 && kj_near(o[0].d[2], ex) && kj_near(o[0].d[3], ey)
         && kj_near(o[1].d[0], ex) && kj_near(o[1].d[1], ey)
         && kj_near(o[1].d[2], ex) && kj_near(o[1].d[3], ey - a);
    check("基準角度 45°（二度押し）: 0° と -90°", ok);

    /* 三度押すと元へ（丸めない） */
    n = kj_drive(Q, 3, 3, 0, 1, o, 8);
    ok = n == 2 && kj_near(o[0].d[2], bx) && kj_near(o[0].d[3], by)
         && kj_near(o[1].d[2], cx) && kj_near(o[1].d[3], cy);
    check("基準角度 三度押しで 0 に戻る", ok);

    /* 丸めなしでも、前の線（延長）の上のクリックは捨てる */
    kj_where(COL[0][0], COL[0][1], &ax, &ay);
    kj_where(COL[1][0], COL[1][1], &bx, &by);
    kj_where(COL[3][0], COL[3][1], &cx, &cy);
    n = kj_drive(COL, 4, 0, 0, 1, o, 8);
    ok = n == 2 && kj_near(o[0].d[0], ax) && kj_near(o[0].d[2], bx)
         && kj_near(o[1].d[0], bx) && kj_near(o[1].d[1], by)
         && kj_near(o[1].d[2], cx) && kj_near(o[1].d[3], cy);
    check("一直線のクリックは捨てる（FUN_006dcff0 の 1e-7）", ok);

    /* 基点: クリックは動かさず、クリックから前の終わりへの向きを丸め、
       前の線との交点が角になる */
    kj_where(K[0][0], K[0][1], &ax, &ay);
    kj_where(K[1][0], K[1][1], &bx, &by);
    kj_where(K[2][0], K[2][1], &cx, &cy);
    n = kj_drive(K, 3, 1, 1, 1, o, 8);
    {
        double v = atan2(by - cy, bx - cx) / (PI / 12.0);
        double t = (v < 0.0 ? (int)(v - 0.5) : (int)(v + 0.5)) * (PI / 12.0);

        /* 一本目は水平（ay == by）。角は y = ay の上で、(cx,cy) から t の向き */
        ex = cx + (ay - cy) / sin(t) * cos(t);
        ey = ay;
    }
    ok = n == 2 && kj_near(ay, by) && kj_near(o[0].d[0], ax)
         && kj_near(o[0].d[2], ex) && kj_near(o[0].d[3], ey)
         && kj_near(o[1].d[0], ex) && kj_near(o[1].d[1], ey)
         && kj_near(o[1].d[2], cx) && kj_near(o[1].d[3], cy)
         && kj_mult(cx - ex, cy - ey, 15.0) && !kj_near(ex, bx);
    check("基点: クリックが終点、角は前の線の上へ動く", ok);

    /* 基点だけ（基準角度 0）なら素と同じ */
    n = kj_drive(K, 3, 0, 1, 1, o, 8);
    ok = n == 2 && kj_near(o[0].d[2], bx) && kj_near(o[1].d[2], cx)
         && kj_near(o[1].d[3], cy);
    check("基点だけでは何も変わらない", ok);
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
    kijun();
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
