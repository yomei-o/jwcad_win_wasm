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


/* 任意 (1070): 頂点を積んで 作図 (1069)。線かソリッドか */
/* 円・連続線指示 (1083): 下絵（円か連続線）を描き、多角形の任意で 指す。
   probe173.sh・probe174.sh の答え p173_c*.jww・p174_*.jww */
/* pick_after: 0 ならつまみを 1083 の前に（原典の probe173/174 の並び。弓形・
   円外側 はそのときまだ enabled でなく効かない）、1 なら 1083 のあとに
   （tkprobe2.sh の並び） */
static int pick_after;
/* 円弧の三点目（probe174 の ARC は (600,200)、tkprobe2.sh の ARC2・ARC3 は別） */
static int arc_end[2] = { 600, 200 };
/* run_any で 曲線属性化 (1325) を立てるか */
static int any_curve;
/* run_pick で 1325 を opt と関係なく立てたままにする */
static int keep_1325;

static void run_pick(const char *name, int kind, int opt, int btn, int px, int py)
{
    char path[96];
    jw_drawing ref;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    rect_t r;
    int i, j, ok = 1, rn = 0, mn = 0;
    static const int POL[3][2] = { {300, 300}, {400, 250}, {500, 300} };

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
    if (kind == 0 || kind == 2) {
        app_command(32773);
        if ((jw_cmd_bar_check(1318) > 0) != (kind == 2))
            jw_cmd_bar((jw_drawing *)app_drawing(), 1318);
        app_press(r.x + 600, r.y + 400, 0);
        app_press(r.x + 800, r.y + 400, 0);
        if (kind == 2)
            app_press(r.x + arc_end[0], r.y + arc_end[1], 0);
    } else if (kind == 5) {
        /* 原典の答えにある円弧をそのまま写す。円弧 (1318) の三点目をどちら
           回りにするかは原典が途中のマウスの道筋で決めていて、送ったクリック
           だけの移植の歩き（短いほう）と合わないことがある（240° の弧） */
        for (i = 0; i < ref.ndrawn; i++)
            if (ref.obj[i].cls == JW_ENKO) {
                jw_obj *o = jw_add((jw_drawing *)app_drawing(), JW_ENKO);
                int keep_cls = o->cls;

                *o = ref.obj[i];
                o->cls = (unsigned char)keep_cls;
                break;
            }
    } else if (kind == 4) {
        static const int PC[6][2] = { {300, 300}, {500, 300}, {500, 450}, {400, 350}, {300, 450}, {300, 300} };

        app_command(32883);
        for (i = 0; i < 6; i++)
            app_press(r.x + PC[i][0], r.y + PC[i][1], 0);
    } else if (kind == 3) {
        static const int P5[5][2] = { {300, 300}, {400, 250}, {500, 300}, {550, 400}, {450, 450} };

        app_command(32883);
        for (i = 0; i < 5; i++)
            app_press(r.x + P5[i][0], r.y + P5[i][1], 0);
        app_press(r.x + P5[4][0], r.y + P5[4][1], 1);
    } else {
        app_command(32883);
        for (i = 0; i < 3; i++)
            app_press(r.x + POL[i][0], r.y + POL[i][1], 0);
    }
    app_command(32894);
    jw_cmd_bar((jw_drawing *)app_drawing(), 1070);
    if (jw_cmd_bar_check(1323) <= 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1323);
    /* opt: 0 なら素のまま、さもなくば 線形・円周 (1326)・曲線属性化 (1325)・
       弓形 (1327)・円外側 (1328) のうち一つだけを立てる。トグルはバーの状態が
       次の呼び出しへ持ち越るので、四つとも望む状態に揃え直す */
    {
        static const int TG[4] = { 1325, 1326, 1327, 1328 };
        int t;

        for (t = 0; t < 4; t++)
            if ((jw_cmd_bar_check(TG[t]) > 0) && opt != TG[t]
                && !(keep_1325 && TG[t] == 1325))
                jw_cmd_bar((jw_drawing *)app_drawing(), TG[t]);
        if (pick_after)
            jw_cmd_bar((jw_drawing *)app_drawing(), 1083);
        /* 原典と同じく、enabled でないつまみは押しても効かない */
        for (t = 0; t < 4; t++)
            if ((opt == TG[t] || (keep_1325 && TG[t] == 1325))
                && jw_cmd_bar_check(TG[t]) <= 0
                && jw_cmd_bar_enabled(app_drawing(), TG[t]))
                jw_cmd_bar((jw_drawing *)app_drawing(), TG[t]);
    }
    if (!pick_after)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1083);
    app_press(r.x + px, r.y + py, btn);
    d = app_drawing();
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls != JW_MOJI)
            rn++;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls != JW_MOJI)
            mn++;
    if (getenv("TKDUMP"))
        for (i = 0; i < d->ndrawn; i++)
            printf("  m%d cls%d lt%d %.3f %.3f %.3f %.3f %.3f %.3f %.3f %.3f\n", i, d->obj[i].cls, d->obj[i].ltype, d->obj[i].d[0], d->obj[i].d[1], d->obj[i].d[2], d->obj[i].d[3], d->obj[i].d[4], d->obj[i].d[5], d->obj[i].d[6], d->obj[i].d[7]);
    if (rn != mn) {
        printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, rn, mn);
        fails++;
        return;
    }
    for (i = 0, j = 0; i < ref.ndrawn && ok; i++) {
        const jw_obj *a = &ref.obj[i], *m;
        int k;

        if (a->cls == JW_MOJI)
            continue;
        while (j < d->ndrawn && d->obj[j].cls == JW_MOJI)
            j++;
        m = &d->obj[j++];
        if (m->cls != a->cls || m->ltype != a->ltype || m->id != a->id)
            ok = 0;
        for (k = 0; k < 8 && ok; k++)
            if (fabs(m->d[k] - a->d[k]) > 2e-3)
                ok = 0;
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

static void run_any(const char *name, int solid, const int (*pt)[2], int npt,
                    int press, int rlast, int anyorder)
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
    jw_cmd_bar((jw_drawing *)app_drawing(), 1070);
    if ((jw_cmd_bar_check(1323) > 0) != (solid != 0))
        jw_cmd_bar((jw_drawing *)app_drawing(), 1323);
    if ((jw_cmd_bar_check(1325) > 0) != (any_curve != 0))
        jw_cmd_bar((jw_drawing *)app_drawing(), 1325);
    ui_view_rect(app_fb()->w, app_fb()->h, &r);
    for (i = 0; i < npt; i++)
        app_press(r.x + pt[i][0], r.y + pt[i][1], 0);
    if (rlast)
        app_press(r.x + pt[npt - 1][0], r.y + pt[npt - 1][1], 1);
    if (press)
        jw_cmd_bar((jw_drawing *)app_drawing(), 1069);
    d = app_drawing();
    for (i = 0; i < ref.ndrawn && rn < 96; i++)
        if (ref.obj[i].cls == JW_SEN || ref.obj[i].cls == JW_SOLID)
            ra[rn++] = &ref.obj[i];
    for (i = 0; i < d->ndrawn && mn < 96; i++)
        if (d->obj[i].cls == JW_SEN || d->obj[i].cls == JW_SOLID)
            ma[mn++] = &d->obj[i];
    if (rn != mn) {
        printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, rn, mn);
        fails++;
        return;
    }
    if (anyorder) {
        /* 凹んだ多角形のソリッドは、出す順が原典と合っているか分かって
           いません（二例だけ）。形が同じなら良しとして数えます */
        for (i = 0; i < rn; i++) {
            int j, found = 0, k;
            for (j = 0; j < mn && !found; j++) {
                int same = ma[j]->cls == ra[i]->cls, p;
                /* 三角は始める頂点の違いも許す（巡回の入れ替え） */
                for (p = 0; p < 3 && !found; p++) {
                    same = ma[j]->cls == ra[i]->cls;
                    for (k = 0; k < 3 && same; k++) {
                        int q = (k + p) % 3;
                        if (fabs(ma[j]->d[q * 2] - ra[i]->d[k * 2]) > 1e-6
                            || fabs(ma[j]->d[q * 2 + 1]
                                    - ra[i]->d[k * 2 + 1]) > 1e-6)
                            same = 0;
                    }
                    found = same;
                }
            }
            if (!found)
                ok = 0;
        }
        printf("%-4s %s%s\n", ok ? "ok" : "BAD", name, "（順は未確認）");
        if (!ok)
            fails++;
        return;
    }
    for (i = 0; i < rn; i++) {
        int k, m = ra[i]->cls == JW_SEN ? 4 : 8;
        if (ma[i]->cls != ra[i]->cls)
            ok = 0;
        for (k = 0; k < m; k++)
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
    {
        /* 任意 */
        static const int T3[3][2] = { {400,350}, {600,450}, {500,420} };
        static const int T4[4][2] = { {400,350}, {600,450}, {500,420}, {300,300} };
        static const int T5[5][2] = { {400,350}, {600,450}, {500,420}, {300,300}, {350,200} };
        static const int T6[6][2] = { {400,350}, {600,450}, {500,420}, {300,300}, {350,200}, {450,250} };
        static const int C5[5][2] = { {600,200}, {410,338}, {482,562}, {718,562}, {790,338} };
        static const int C5W[5][2] = { {600,200}, {790,338}, {718,562}, {482,562}, {410,338} };
        static const int C6[6][2] = { {600,200}, {427,300}, {427,500}, {600,600}, {773,500}, {773,300} };

        run_pick("p173_c1", 0, 0, 0, 800, 400);
        run_pick("p173_c4", 0, 1325, 0, 800, 400);
        run_pick("p173_c5", 0, 1326, 0, 800, 400);
        run_pick("p173_c6", 0, 1327, 0, 800, 400);
        run_pick("p173_c7", 0, 1328, 0, 800, 400);
        run_pick("p174_k5", 0, 0, 1, 800, 400);
        run_pick("p174_p1", 1, 0, 0, 450, 275);
        run_pick("p174_p2", 1, 1325, 0, 450, 275);
        run_pick("p174_p3", 1, 1326, 0, 450, 275);
        run_pick("p174_p4", 1, 1327, 0, 450, 275);
        run_pick("p174_p5", 1, 1328, 0, 450, 275);
        run_pick("p174_p6", 1, 0, 1, 450, 275);
        run_pick("p174_a1", 2, 0, 0, 800, 400);
        run_pick("p174_a2", 2, 1327, 0, 800, 400);
        run_pick("p174_a3", 2, 1328, 0, 800, 400);
        run_pick("p174_a4", 2, 1326, 0, 800, 400);
        run_pick("p174_a5", 2, 0, 1, 800, 400);
        run_pick("p174_q1", 3, 0, 0, 450, 275);
        run_pick("p174_q3", 3, 1326, 0, 450, 275);
        run_pick("p174_q4", 3, 1325, 0, 450, 275);
        run_pick("p174_q2", 4, 0, 0, 450, 275);
        run_any("p170_p3", 0, T3, 3, 1, 0, 0);
        run_any("p170_p4", 0, T4, 4, 1, 0, 0);
        run_any("p170_p3solid", 1, T3, 3, 1, 0, 0);
        run_any("p170_p3r", 0, T3, 3, 0, 1, 0);
        run_any("p170_p2", 0, T3, 2, 1, 0, 0);
        run_any("p171_s4", 1, T4, 4, 1, 0, 0);
        run_any("p171_s5", 1, T5, 5, 1, 0, 0);
        run_any("p171_s6", 1, T6, 6, 1, 0, 0);
        run_any("p172_c5", 1, C5, 5, 1, 0, 0);
        run_any("p172_c5cw", 1, C5W, 5, 1, 0, 0);
        run_any("p172_c6", 1, C6, 6, 1, 0, 0);

        /* tools/tkprobe.sh・tkprobe2.sh（2026-10-13）。凹み・自己交差の
           出す順（並びまで突き合わせ）、曲線属性化 (1325) で付く曲線属性、
           1083 のあとに押した 弓形 (1327)・円外側 (1328)。 */
        {
            static const int T5C[5][2] = { {400,350}, {600,450}, {500,300}, {300,300}, {350,200} };
            static const int X5[5][2] = { {300,300}, {600,300}, {350,450}, {450,200}, {550,450} };
            static const int C7[7][2] = { {300,300}, {500,250}, {600,400}, {450,350}, {400,500}, {250,450}, {350,380} };

            run_any("tk_s5c", 1, T5C, 5, 1, 0, 0);
            run_any("tk_x5", 1, X5, 5, 1, 0, 0);
            run_any("tk_c7", 1, C7, 7, 1, 0, 0);
            any_curve = 1;
            run_any("tk_s6c", 1, T6, 6, 1, 0, 0);
            any_curve = 0;
            pick_after = 1;
            run_pick("tk_b2", 2, 1327, 0, 800, 400);
            run_pick("tk_b3", 2, 1328, 0, 800, 400);
            run_pick("tk_j2", 0, 1327, 0, 800, 400);
            run_pick("tk_j3", 0, 1328, 0, 800, 400);
            run_pick("tk_j5", 3, 1325, 0, 450, 275);
            run_pick("tk_j6", 0, 1325, 0, 800, 400);
            /* 曲線属性化 と 円外側 の両方: 円の四枚に曲線属性が付くのは (R) だけ。
               線形 (1326) の連続線には (L) でも付く。run_pick は opt を一つしか
               立てないので、ここでは 1325 を先に立てておく */
            jw_cmd_bar((jw_drawing *)app_drawing(), 1325);
            keep_1325 = 1;
            run_pick("tk_j7", 0, 1328, 1, 800, 400);
            run_pick("tk_j8", 0, 1328, 0, 800, 400);
            run_pick("tk_j9", 3, 1326, 0, 450, 275);
            keep_1325 = 0;
            arc_end[0] = 400; arc_end[1] = 400;
            run_pick("tk_b4", 2, 1327, 0, 800, 400);
            run_pick("tk_b5", 2, 1328, 0, 800, 400);
            arc_end[0] = 600; arc_end[1] = 200;
            run_pick("tk_b6", 5, 1328, 0, 800, 400);     /* 240° を 80° 三枚 */
            run_pick("tk_b7", 5, 1327, 0, 800, 400);
            pick_after = 0;
        }
    }
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
