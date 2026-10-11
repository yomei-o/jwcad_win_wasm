/* 天空図 (32971) の作図 (src/tenku.c) を 原典の答え decomp/res/hk_s1.jww（tools/hkprobe.sh）と
   orig/天空率表.jww の一枚目の天空図と突き合わせる。cmd.c には 依存しない。
   比べ方は tests/hk_test.c の same() と同じ（座標・属性・文字・書体）。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/jww.h"
#include "../src/hikage.h"
#include "../src/tenku.h"
#include "../tmp/spec_hikage/tenku_sample_data.h"

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
        fclose(f);
        return 0;
    }
    fclose(f);
    return b;
}

static int junk(const jw_obj *o)
{
    return o->cls == JW_MOJI && o->d[0] == 0.0 && o->d[1] == -1000.0;
}

#define MAXO 1024
static int collect(const jw_drawing *d, int from, int to, const jw_obj **out)
{
    int i, n = 0;

    for (i = from; i < d->ndrawn && i < to && n < MAXO; i++)
        if (!junk(&d->obj[i]))
            out[n++] = &d->obj[i];
    return n;
}

static double g_tol = 0.02;

static int same(const jw_drawing *ref, int rfrom, int rto, const jw_drawing *d, int mfrom,
                const char *name, int layer_too)
{
    const jw_obj *ra[MAXO], *ma[MAXO];
    int i, j, bad = 0, rn = collect(ref, rfrom, rto, ra), mn = collect(d, mfrom, 1 << 30, ma);

    if (rn != mn) {
        printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, rn, mn);
        bad = 1;
    }
    for (i = 0; i < rn && i < mn; i++) {
        const jw_obj *a = ra[i], *m = ma[i];
        int nd = a->cls == JW_SEN ? 4 : a->cls == JW_ENKO ? 7 : a->cls == JW_TEN ? 2 : 4;
        int ok = 1;

        if (a->cls != m->cls) {
            printf("     %d: 種類 原典 %d・移植 %d\n", i, a->cls, m->cls);
            bad = 1;
            continue;
        }
        for (j = 0; j < nd; j++)
            if (fabs(a->d[j] - m->d[j]) > g_tol) {
                ok = 0;
                printf("     %d.d[%d] 原典 %.4f・移植 %.4f\n", i, j, a->d[j], m->d[j]);
            }
        if (a->color != m->color || a->ltype != m->ltype || a->width != m->width ||
            (layer_too && a->layer != m->layer) || (a->flags & ~(layer_too ? 0 : 2)) != m->flags || a->n != m->n) {
            ok = 0;
            printf("     %d: 属性 原典 col%d lt%d w%d ly%d fl%x n%d・移植 col%d lt%d w%d ly%d fl%x n%d\n",
                   i, a->color, a->ltype, a->width, a->layer, a->flags, a->n,
                   m->color, m->ltype, m->width, m->layer, m->flags, m->n);
        }
        if (a->cls == JW_MOJI && (fabs(a->d[7] - m->d[7]) > 2e-3 || fabs(a->d[4] - m->d[4]) > 2e-3 ||
                                  fabs(a->d[5] - m->d[5]) > 2e-3 || fabs(a->d[6] - m->d[6]) > 2e-3)) {
            ok = 0;
            printf("     %d: 文字の大きさ・角度 原典 %.3f %.3f %.3f %.3f・移植 %.3f %.3f %.3f %.3f\n", i,
                   a->d[4], a->d[5], a->d[6], a->d[7], m->d[4], m->d[5], m->d[6], m->d[7]);
        }
        if (a->cls == JW_MOJI && a->text >= 0 && m->text >= 0 &&
            (strcmp(jw_str(ref, a->text), jw_str(d, m->text)) ||
             (a->face >= 0 && m->face >= 0 && strcmp(jw_str(ref, a->face), jw_str(d, m->face))))) {
            ok = 0;
            printf("     %d: 文字 原典 [%s]・移植 [%s]\n", i, jw_str(ref, a->text), jw_str(d, m->text));
        }
        if (!ok)
            bad = 1;
    }
    if (bad)
        printf("BAD  %s\n", name);
    else
        printf("ok   %s (%d 要素)\n", name, rn);
    return bad;
}

/* 押した画素 → mm （tests/hk_test.c と同じ比） */
static double pxx(int x) { return (x - 300) / 1.633333333 - 155.510204; }
static double pxy(int y) { return -34.897959 - (y - 400) / 1.633333333; }

int main(void)
{
    int fails = 0, i;
    long n, rn;
    unsigned char *b, *rb;
    jw_drawing ref, d;

    /* 1. hk_s1: 正射影・既定値 */
    b = slurp("decomp/res/new.jww", &n);
    rb = slurp("decomp/res/hk_s1.jww", &rn);
    if (!b || !rb) {
        printf("BAD  decomp/res/new.jww か hk_s1.jww が読めません\n");
        return 1;
    }
    memset(&ref, 0, sizeof ref);
    memset(&d, 0, sizeof d);
    jw_parse(&ref, rb, rn);
    jw_parse(&d, b, n);
    for (i = 0; i < 8; i++) {                       /* 箱の四辺と 高さの文字四つ */
        jw_obj *o = jw_add(&d, ref.obj[i].cls);

        *o = ref.obj[i];
        if (ref.obj[i].text >= 0)
            o->text = jw_add_str(&d, jw_str(&ref, ref.obj[i].text));
        if (ref.obj[i].face >= 0)
            o->face = jw_add_str(&d, jw_str(&ref, ref.obj[i].face));
    }
    {
        hk_tenku_opts o;
        double pct = -1;
        int got;

        hk_tenku_opts_default(&o);
        got = jw_tenku_draw(&d, &o, pxx(500), pxy(600), pxx(900), pxy(300), &pct);
        printf("     hk_s1: 足した要素 %d  天空率 %.2f\n", got, pct);
        fails += same(&ref, 0, 1 << 30, &d, 0, "hk_s1", 1);
    }

    /* 2. 天空率表.jww 一枚目 (No.1): 測定点表示・天空率計算あり（層は 3） */
    free(b);
    free(rb);
    rb = slurp("decomp/res/tenkuhyo.jww", &rn);
    b = slurp("decomp/res/new.jww", &n);
    if (rb) {
        jw_drawing r2, d2;
        hk_tenku_opts o;
        hk_edge3 e[9];
        int k;
        double pct = -1;

        memset(&r2, 0, sizeof r2);
        memset(&d2, 0, sizeof d2);
        jw_parse(&r2, rb, rn);
        jw_parse(&d2, b, n);
        for (k = 0; k < 9; k++) {
            e[k].x0 = T_edges[k][0];
            e[k].y0 = T_edges[k][1];
            e[k].x1 = T_edges[k][2];
            e[k].y1 = T_edges[k][3];
            e[k].z0 = T_edges[k][4] * 1000.0 / 200.0;
            e[k].z1 = T_edges[k][5] * 1000.0 / 200.0;
        }
        for (k = 0; k < 10; k++) {            /* No.1..10 (次の円までが 一組） */
            char nm[40];
            int got, c0 = -1, c1 = -1;

            for (i = 0; i < r2.ndrawn; i++)
                if (r2.obj[i].cls == JW_ENKO && r2.obj[i].layer == 3 &&
                    fabs(r2.obj[i].d[0] - (-170.770 + 40.0 * k)) < 0.01) {
                    c0 = i;
                    break;
                }
            for (i = c0 + 1; c0 >= 0 && i < r2.ndrawn; i++)
                if (r2.obj[i].cls == JW_ENKO && r2.obj[i].layer == 3) {
                    c1 = i;
                    break;
                }
            if (c0 < 0 || c1 < 0) {
                printf("BAD  天空率表.jww の No.%d が見つかりません\n", k + 1);
                fails++;
                continue;
            }
            d2.ndrawn = d2.nobj = 0;
            hk_tenku_opts_default(&o);
            o.R = 15.0;
            o.calc = 1;
            o.show_point = 1;
            o.number = k + 1;
            got = jw_tenku_draw_edges(&d2, &o, e, 9, T_pts[k][0], T_pts[k][1],
                                      -170.770 + 40.0 * k, -230.501, &pct);
            printf("     天空率表 No.%d: 足した要素 %d  天空率 %.2f\n", k + 1, got, pct);
            snprintf(nm, sizeof nm, "tenku_table_no%d", k + 1);
            fails += same(&r2, c0, c1, &d2, 0, nm, 0);
        }
        /* 目盛間隔 10°の一枚目: 円・目盛の円・放射線・測定点・文字 （物体なし） */
        d2.ndrawn = d2.nobj = 0;
        hk_tenku_opts_default(&o);
        o.R = 100.0;
        o.interval = 10.0;
        o.show_point = 1;
        o.number = 1;
        jw_tenku_draw_edges(&d2, &o, e, 0, -185.873, -84.949, -395.361, 236.341, &pct);
        fails += same(&r2, 0, 49, &d2, 0, "tenku_table_scale10", 0);
    } else
        printf("skip 天空率表.jww なし\n");

    printf(fails ? "SOME BAD (%d)\n" : "all ok\n", fails);
    return fails != 0;
}
