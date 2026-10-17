/* 三斜 の作図 (src/tenku_sansha.c) を 原典の答え orig/天空率表.jww の 二つの三斜図と 突き合わせる。
 *   - 計画建物用 (層 5, 12 m と 14 m の 寄棟 9 本・6 頂点) : 原典の書いた順そのまま
 *   - 基準建物用 (層 13, 高さ 7 m の 壁 1 本)               : 原典の 書いた順の 逆 (移動・複写で 逆に なった物)
 * 比べ方は tests/tenku_test.c の same() と 同じ（座標・属性・文字・書体）。 cmd.c には 依存しない。
 * 二つの図は 書式の古い版で作られている (hk_sansha_opts.style = HK_SANSHA_SAMPLE)。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/jww.h"
#include "../src/hikage.h"
#include "../src/tenku.h"
#include "../src/tenku_sansha.h"

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

#define MAXO 1024
static double g_tol = 0.002;
static double g_maxdev = 0.0;

/* ref[rfrom..rto) の 要素と d[mfrom..) を 順に 比べる。 rev=1 なら ref を 逆順に 見る。 */
static int same(const jw_drawing *ref, int rfrom, int rto, int rev, const jw_drawing *d, int mfrom,
                const char *name)
{
    const jw_obj *ra[MAXO], *ma[MAXO];
    int i, j, bad = 0, rn = 0, mn = 0;

    for (i = rfrom; i < rto && rn < MAXO; i++)
        ra[rn++] = &ref->obj[rev ? rto - 1 - (i - rfrom) : i];
    for (i = mfrom; i < d->ndrawn && mn < MAXO; i++)
        ma[mn++] = &d->obj[i];
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
        for (j = 0; j < nd; j++) {
            double dv = fabs(a->d[j] - m->d[j]);

            if (dv > g_maxdev)
                g_maxdev = dv;
            if (dv > g_tol) {
                ok = 0;
                printf("     %d.d[%d] 原典 %.4f・移植 %.4f\n", i, j, a->d[j], m->d[j]);
            }
        }
        if (a->color != m->color || a->ltype != m->ltype || a->width != m->width ||
            (a->flags & ~2) != m->flags || a->n != m->n) {
            ok = 0;
            printf("     %d: 属性 原典 col%d lt%d w%d fl%x n%d・移植 col%d lt%d w%d fl%x n%d\n", i, a->color,
                   a->ltype, a->width, a->flags, a->n, m->color, m->ltype, m->width, m->flags, m->n);
        }
        if (a->cls == JW_MOJI &&
            (fabs(a->d[7] - m->d[7]) > 2e-3 || fabs(a->d[4] - m->d[4]) > 2e-3 ||
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

/* ref の layer l (group 0) の 線 (ltype lt) と 高さの文字 (0x80) だけを 写した 白紙を 作る */
static int make_doc(jw_drawing *d, const jw_drawing *ref, const unsigned char *blank, long bn, int layer,
                    int lt, int ofrom, int oto)
{
    int i, g, l;

    memset(d, 0, sizeof *d);
    jw_parse(d, (unsigned char *)blank, bn);
    for (i = ofrom; i < oto; i++) {
        const jw_obj *s = &ref->obj[i];
        jw_obj *o;

        if (s->layer != layer || s->lgroup != 0)
            continue;
        if (!((s->cls == JW_SEN && s->ltype == lt) || (s->cls == JW_MOJI && (s->flags & 0x80))))
            continue;
        o = jw_add(d, s->cls);
        *o = *s;
        if (s->text >= 0)
            o->text = jw_add_str(d, jw_str(ref, s->text));
        if (s->face >= 0)
            o->face = jw_add_str(d, jw_str(ref, s->face));
    }
    for (g = 0; g < 16; g++)
        for (l = 0; l < 16; l++)
            if (d->group[g].layer[l].state == 0)
                d->group[g].layer[l].state = 3;
    d->group[0].scale = ref->group[0].scale;
    return d->ndrawn;
}

int main(void)
{
    int fails = 0, i, got, c0, c1, first;
    long rn, bn;
    unsigned char *rb, *bb;
    jw_drawing ref, d;
    hk_sansha_opts o;
    double pct = -1;
    const jw_obj *pt = 0, *ci = 0;

    rb = slurp("decomp/res/tenkuhyo.jww", &rn);
    bb = slurp("decomp/res/new.jww", &bn);
    if (!rb || !bb) {
        printf("BAD  decomp/res/tenkuhyo.jww か new.jww が読めません\n");
        return 1;
    }
    memset(&ref, 0, sizeof ref);
    jw_parse(&ref, rb, rn);
    printf("     group 0 の縮尺 %g\n", ref.group[0].scale);

    /* ---------- 計画建物用 (層 5): 測定点 (6035)・円 (6034) ---------- */
    first = -1;
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_ENKO && ref.obj[i].layer == 5 && fabs(ref.obj[i].d[2] - 100.0) < 1e-6) {
            first = i;
            break;
        }
    if (first < 0) {
        printf("BAD  計画建物用の円が見つかりません\n");
        return 1;
    }
    ci = &ref.obj[first];
    pt = &ref.obj[first + 1];
    c0 = first;
    c1 = first;
    while (c1 < ref.ndrawn && ref.obj[c1].layer == 5)
        c1++;
    make_doc(&d, &ref, bb, bn, 1, 1, 397, 425);
    printf("     計画建物用: 線と高さの文字 %d 要素 (層 1)\n", d.ndrawn);
    hk_sansha_opts_default(&o);
    hk_sansha_opts_set_mode(&o, 1);                 /* 計画建物用: 弦のまま・<n>・切り捨て */
    o.style = HK_SANSHA_SAMPLE;
    got = jw_tenku_sansha_draw_ex(&d, &o, pt->d[0], pt->d[1], ci->d[0], ci->d[1], &pct);
    printf("     計画建物用: 足した要素 %d (原典 %d)  天空率 %.2f (原典 91.27)\n", got, c1 - c0, pct);
    fails += same(&ref, c0, c1, 0, &d, d.ndrawn - (got > 0 ? got : 0), "sansha_keikaku");
    if (fabs(pct - 91.27) > 1e-9)
        fails++;

    /* ---------- 基準建物用 (層 13): 原典の逆順 ---------- */
    first = -1;
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_ENKO && ref.obj[i].layer == 13 && fabs(ref.obj[i].d[2] - 100.0) < 1e-6) {
            first = i;
            break;
        }
    if (first < 0) {
        printf("BAD  基準建物用の円が見つかりません\n");
        return 1;
    }
    ci = &ref.obj[first];
    pt = &ref.obj[first - 1 - 1];            /* 396 円・395 点・394 No.1 の 文字 (逆順) */
    pt = &ref.obj[first - 1];
    c1 = first + 1;
    c0 = first;
    while (c0 > 0 && ref.obj[c0 - 1].layer == 13)
        c0--;
    make_doc(&d, &ref, bb, bn, 9, 1, 4000, 4070);
    printf("     基準建物用: 線と高さの文字 %d 要素 (層 9)\n", d.ndrawn);
    hk_sansha_opts_default(&o);
    o.style = HK_SANSHA_SAMPLE;
    pct = -1;
    got = jw_tenku_sansha_draw_ex(&d, &o, pt->d[0], pt->d[1], ci->d[0], ci->d[1], &pct);
    printf("     基準建物用: 足した要素 %d (原典 %d)  天空率 %.2f (原典 90.73)\n", got, c1 - c0, pct);
    fails += same(&ref, c0, c1, 1, &d, d.ndrawn - (got > 0 ? got : 0), "sansha_kijun (原典を逆順に見る)");
    if (fabs(pct - 90.73) > 1e-9)
        fails++;

    /* ---------- 原典の exe (10.03.6) の 書式: 内部の 無矛盾だけ ---------- */
    make_doc(&d, &ref, bb, bn, 9, 1, 4000, 4070);
    hk_sansha_opts_default(&o);
    pct = -1;
    got = jw_tenku_sansha_draw_ex(&d, &o, pt->d[0], pt->d[1], ci->d[0], ci->d[1], &pct);
    printf("     exe 書式 (基準・壁): 足した要素 %d  天空率 %.3f\n", got, pct);
    for (i = d.ndrawn - got; i < d.ndrawn; i++)
        if (d.obj[i].cls == JW_MOJI && strstr(jw_str(&d, d.obj[i].text), "= ") &&
            strstr(jw_str(&d, d.obj[i].text), "%"))
            printf("       [%s]\n", jw_str(&d, d.obj[i].text));

    /* ---------- 視点と同じ面に ある 線の 併合 (0x741553..): 壁を二本に割っても 同じ表になる [G] ---------- */
    {
        jw_drawing d2, d3;
        double p2 = -1, p3 = -1;
        int n2, n3, k2, k3, bad = 0, nt = 0, a2, a3;
        jw_obj *ln, *t2;
        jw_obj *l2, *tm;

        make_doc(&d2, &ref, bb, bn, 9, 1, 4000, 4070);
        make_doc(&d3, &ref, bb, bn, 9, 1, 4000, 4070);
        ln = 0;
        for (i = 0; i < d3.ndrawn; i++)
            if (d3.obj[i].cls == JW_SEN)
                ln = &d3.obj[i];
        t2 = 0;
        for (i = 0; i < d3.ndrawn; i++)
            if (d3.obj[i].cls == JW_MOJI)
                t2 = &d3.obj[i];
        if (ln && t2) {
            double mx = (ln->d[0] + ln->d[2]) / 2.0, bx = ln->d[2];
            jw_obj lcopy = *ln, tcopy = *t2;

            ln->d[2] = mx;
            l2 = jw_add(&d3, JW_SEN);
            *l2 = lcopy;
            l2->d[0] = mx;
            l2->d[2] = bx;
            tm = jw_add(&d3, JW_MOJI);
            *tm = tcopy;
            tm->d[0] = mx;
            tm->d[2] = mx + (tcopy.d[2] - tcopy.d[0]);
            tm->text = jw_add_str(&d3, jw_str(&d3, tcopy.text));
            tm->face = jw_add_str(&d3, jw_str(&d3, tcopy.face));
        }
        hk_sansha_opts_default(&o);
        o.style = HK_SANSHA_SAMPLE;
        a2 = d2.ndrawn;
        a3 = d3.ndrawn;
        n2 = jw_tenku_sansha_draw_ex(&d2, &o, pt->d[0], pt->d[1], ci->d[0], ci->d[1], &p2);
        n3 = jw_tenku_sansha_draw_ex(&d3, &o, pt->d[0], pt->d[1], ci->d[0], ci->d[1], &p3);
        for (k2 = a2, k3 = a3; k2 < d2.ndrawn && k3 < d3.ndrawn;) {
            while (k2 < d2.ndrawn && d2.obj[k2].cls != JW_MOJI)
                k2++;
            while (k3 < d3.ndrawn && d3.obj[k3].cls != JW_MOJI)
                k3++;
            if (k2 >= d2.ndrawn || k3 >= d3.ndrawn)
                break;
            nt++;
            if (strcmp(jw_str(&d2, d2.obj[k2].text), jw_str(&d3, d3.obj[k3].text)))
                bad++;
            k2++;
            k3++;
        }
        printf("     壁を二本に割る: %d 個 / %d 個 (割らない/割る) 天空率 %.2f / %.2f  文字 %d 個 の 違い %d\n", n2, n3, p2, p3, nt, bad);
        if (bad || fabs(p2 - p3) > 1e-9 || n3 != n2 + 1) {
            printf("BAD  sansha_merge\n");
            fails++;
        } else
            printf("ok   sansha_merge (割った壁は 併合されて 同じ表・縦線が 一本 増えるだけ)\n");
    }

    /* ---------- 暴走しないか: 分割角 1 度 (50 行を 超える → 二頁)、目盛、名前なし、測定面高さ、等距離 ---------- */
    {
        static const struct { double maxdiv, interval, plane; int equidist, noname; } v[] = {
            {1.0, 0, 0, 0, 0}, {10.0, 10.0, 0, 0, 0}, {10.0, 0, 0, 0, 1}, {10.0, 0, 3.0, 0, 0},
            {10.0, 0, 0, 1, 0}, {0.5, 0, 0, 0, 0}, {45.0, 0, 0, 0, 0}
        };
        int vi;

        for (vi = 0; vi < (int)(sizeof v / sizeof v[0]); vi++) {
            int r;

            make_doc(&d, &ref, bb, bn, 1, 1, 397, 425);
            hk_sansha_opts_default(&o);
            hk_sansha_opts_set_mode(&o, vi & 1);
            o.maxdiv = v[vi].maxdiv;
            o.t.interval = v[vi].interval;
            o.t.plane_m = v[vi].plane;
            o.t.equidist = v[vi].equidist;
            if (v[vi].noname)
                o.name[0] = 0;
            pct = -1;
            r = jw_tenku_sansha_draw_ex(&d, &o, -185.873, -84.949, 412.867, 236.341, &pct);
            printf("     変種 %d (分割角 %g 目盛 %g 測定面 %g 等距離 %d 名前%s): 要素 %d 天空率 %.3f\n", vi,
                   v[vi].maxdiv, v[vi].interval, v[vi].plane, v[vi].equidist, v[vi].noname ? "なし" : "あり",
                   r, pct);
            if (r <= 0 || !(pct >= -1e-9 && pct <= 100.0 + 1e-9)) {
                printf("BAD  変種 %d\n", vi);
                fails++;
            }
        }
    }

    /* 名前なしでも 目盛 >= 1 度なら「目盛間隔 n°」の行が一行 増える（逆コンパイルの読み、原典では押していない）。
       名前なしで 目盛 0 の図との 文字の数の差が 一つ、その文字が 目盛間隔 10 */
    {
        int cnt[2], found = 0, ii, kk;

        for (ii = 0; ii < 2; ii++) {
            make_doc(&d, &ref, bb, bn, 1, 1, 397, 425);
            hk_sansha_opts_default(&o);
            hk_sansha_opts_set_mode(&o, 0);
            o.name[0] = 0;
            o.t.interval = ii ? 10.0 : 0.0;
            jw_tenku_sansha_draw_ex(&d, &o, -185.873, -84.949, 412.867, 236.341, &pct);
            cnt[ii] = 0;
            for (kk = 0; kk < d.ndrawn; kk++)
                if (d.obj[kk].cls == JW_MOJI) {
                    cnt[ii]++;
                    if (ii && strstr(jw_str(&d, d.obj[kk].text), "\226\332\220\267\212\324\212u 10\201\213"))
                        found = 1;
                }
        }
        if (cnt[1] != cnt[0] + 1 || !found) {
            printf("BAD  名前なしの 目盛間隔の行 (%d, %d, found %d)\n", cnt[0], cnt[1], found);
            fails++;
        } else
            printf("ok   名前なしの 目盛間隔の行\n");
    }

    printf("     最大の座標のずれ %.3e mm (許容 %.3f)\n", g_maxdev, g_tol);
    printf(fails ? "SOME BAD (%d)\n" : "all ok\n", fails);
    return fails != 0;
}
