/* 建具平面の置き方 —— 原典に置かせた答えと突き合わせる。
 *
 *   tests/tategu2_test.exe
 *
 * `tools/probe185.sh`（JW_OPT1.DAT の 1〜16 番を初期値で水平な壁に）、
 * `probe180.sh`（壁の向き・数値）、`probe182.sh`・`probe186.sh`（反転）が
 * 原典に置かせた `decomp/res/p18*_*.jww`。壁の線は最初の一本で、そのあとに
 * 置かれた要素を、順に、座標まで見ます。
 *
 * 建具 [1] は 寸法図形と文字を伴うので入れていません（まだ置きません）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/tategu.h"
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
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

static int near(double a, double b)
{
    return fabs(a - b) < 2e-3;
}

/* 壁（最初の一本）のあとの要素と比べる */
static void run(const char *name, int dat, int item, jw_tg_pose p)
{
    char path[96];
    long n;
    unsigned char *b;
    jw_drawing ref, mine;
    const jw_tategu *t = jw_tategu_load(dat);
    int i, k, ok = 1, bad = 0, nref = 0;

    snprintf(path, sizeof path, "decomp/res/%s.jww", name);
    memset(&ref, 0, sizeof ref);
    b = slurp(path, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  %s が読めません\n", path);
        fails++;
        return;
    }
    free(b);
    b = slurp("decomp/res/new.jww", &n);
    memset(&mine, 0, sizeof mine);
    jw_parse(&mine, b, n);
    free(b);
    if (!t) {
        printf("BAD  %s: 建具のデータが読めません\n", name);
        fails++;
        return;
    }
    jw_tategu_put(&mine, t, item, &p);
    /* 原典の答えは 壁・（建具）・文字 の順。文字だけ外す */
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls != JW_MOJI)
            nref++;
    {
        int ri = 0, mi = 0;
        const jw_obj *ra[256], *ma[256];

        for (i = 0; i < ref.ndrawn && ri < 256; i++)
            if (ref.obj[i].cls != JW_MOJI)
                ra[ri++] = &ref.obj[i];
        for (i = 0; i < mine.ndrawn && mi < 256; i++)
            if (mine.obj[i].cls != JW_MOJI)
                ma[mi++] = &mine.obj[i];
        /* ra[0] は壁の線 */
        if (ri - 1 != mi) {
            printf("BAD  %s: 要素 原典 %d・移植 %d\n", name, ri - 1, mi);
            fails++;
            return;
        }
        for (i = 0; i < mi; i++) {
            const jw_obj *r = ra[i + 1], *m = ma[i];
            int cnt = r->cls == JW_SEN ? 4 : r->cls == JW_ENKO ? 7 : 2;

            if (r->cls != m->cls) {
                ok = 0;
                if (bad++ < 3)
                    printf("     %d: 種類 原典 %d・移植 %d\n", i, r->cls, m->cls);
                continue;
            }
            for (k = 0; k < cnt; k++)
                if (!near(r->d[k], m->d[k])) {
                    ok = 0;
                    if (bad++ < 3)
                        printf("     %d.d[%d] 原典 %.4f・移植 %.4f\n", i, k,
                               r->d[k], m->d[k]);
                }
            if (r->flags != m->flags) {
                ok = 0;
                if (bad++ < 3)
                    printf("     %d: flags 原典 %x・移植 %x\n", i,
                           (unsigned)r->flags, (unsigned)m->flags);
            }
        }
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

/* 文字と寸法図形（&m）も含めて、すべて突き合わせる。[1] 用 */
static void run_full(const char *name, int dat, int item, jw_tg_pose p)
{
    char path[96];
    long n;
    unsigned char *b;
    jw_drawing ref, mine;
    const jw_tategu *t = jw_tategu_load(dat);
    int i, k, ok = 1, bad = 0, first;

    snprintf(path, sizeof path, "decomp/res/%s.jww", name);
    memset(&ref, 0, sizeof ref);
    b = slurp(path, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  %s が読めません\n", path);
        fails++;
        return;
    }
    free(b);
    b = slurp("decomp/res/new.jww", &n);
    memset(&mine, 0, sizeof mine);
    jw_parse(&mine, b, n);
    free(b);
    first = mine.ndrawn;
    jw_tategu_put(&mine, t, item, &p);
    /* 原典の答えの終わりには、建具とは関係のない文字（Printer_…）が並ぶ */
    for (i = 0; i < mine.ndrawn - first; i++) {
        const jw_obj *r = &ref.obj[i + 1], *m = &mine.obj[first + i];
        int cnt = r->cls == JW_SEN ? 4 : r->cls == JW_MOJI ? 6 : 2;

#define NEQ(what, a, c) do { if ((a) != (c)) { ok = 0; if (bad++ < 6) \
    printf("     %d: %s 原典 %d・移植 %d\n", i, what, (int)(a), (int)(c)); } } while (0)
        NEQ("cls", r->cls, m->cls);
        NEQ("sub", r->sub, m->sub);
        NEQ("ltype", r->ltype, m->ltype);
        NEQ("color", r->color, m->color);
        NEQ("width", r->width, m->width);
        NEQ("flags", r->flags, m->flags);
        NEQ("n", r->n, m->n);
        NEQ("mark", r->mark, m->mark);
        NEQ("list2", r->list[2], m->list[2]);
        for (k = 0; k < cnt; k++)
            if (!near(r->d[k], m->d[k])) {
                ok = 0;
                if (bad++ < 6)
                    printf("     %d.d[%d] 原典 %.4f・移植 %.4f\n", i, k,
                           r->d[k], m->d[k]);
            }
        if (r->cls == JW_MOJI) {
            if (strcmp(jw_str(&ref, r->text), jw_str(&mine, m->text))) {
                ok = 0;
                printf("     %d: 文字が違います\n", i);
            }
            if (strcmp(jw_str(&ref, r->face), jw_str(&mine, m->face))) {
                ok = 0;
                printf("     %d: 書体が違います\n", i);
            }
        }
    }
    printf("%-4s %s\n", ok ? "ok" : "BAD", name);
    if (!ok)
        fails++;
}

static jw_tg_pose base(void)
{
    jw_tg_pose p;

    memset(&p, 0, sizeof p);
    p.mikomi = 70;
    p.wakuhaba = 35;
    p.uchinori = 1700;
    p.scale = 100.0;
    p.ox = -2.4490;
    p.oy = -34.8980;
    p.ux = 1.0;
    p.uy = 0.0;
    return p;
}

int main(void)
{
    char nm[48];
    int i;
    jw_tg_pose p;

    run_full("p185_i1", 0, 0, base());
    for (i = 2; i <= 16; i++) {
        snprintf(nm, sizeof nm, "p185_i%d", i);
        run(nm, 0, i - 1, base());
    }
    for (i = 1; i <= 11; i++) {
        snprintf(nm, sizeof nm, "p187_C%d", i);
        run(nm, jw_tgdat_index(1, 2), i - 1, base());
    }
    for (i = 1; i <= 11; i++) {
        snprintf(nm, sizeof nm, "p187_B%d", i);
        run(nm, jw_tgdat_index(1, 1), i - 1, base());
        if (i > 6)
            continue;                   /* 【建具平面D】は六つ */
        snprintf(nm, sizeof nm, "p187_D%d", i);
        run(nm, jw_tgdat_index(1, 3), i - 1, base());
    }
    for (i = 1; i <= 16; i++) {
        snprintf(nm, sizeof nm, "p190_32866_A%d", i);
        run(nm, jw_tgdat_index(2, 0), i - 1, base());
    }
    for (i = 1; i <= 16; i++) {
        snprintf(nm, sizeof nm, "p190_32866_B%d", i);
        run(nm, jw_tgdat_index(2, 1), i - 1, base());
    }
    for (i = 1; i <= 10; i++) {            /* 11・12 番はますが窓の外 */
        snprintf(nm, sizeof nm, "p190_32866_C%d", i);
        run(nm, jw_tgdat_index(2, 2), i - 1, base());
    }
    p = base();
    p.wakuhaba = 50;
    run("p191_w50", jw_tgdat_index(2, 0), 0, p);
    p = base();
    p.mikomi = 100;
    run("p191_m100", jw_tgdat_index(2, 0), 0, p);
    p = base();
    p.uchinori = 1000;
    run("p191_n1000", jw_tgdat_index(2, 0), 0, p);
    p = base();
    p.shinzure = 10;
    run("p191_z10", jw_tgdat_index(2, 0), 0, p);
    p = base();
    p.flip_lr = 1;
    run("p182_s4", 0, 3, p);
    run("p186_s7", 0, 6, p);
    run("p186_s13", 0, 12, p);
    p = base();
    p.flip_io = 1;
    run("p182_n4", 0, 3, p);
    run("p186_n7", 0, 6, p);
    p.flip_lr = 1;
    run("p182_sn4", 0, 3, p);
    run("p186_sn7", 0, 6, p);
    p = base();
    p.uchinori = 1000;
    run("p180_n1000", 0, 4, p);
    p = base();
    p.mikomi = 100;
    run("p180_m100", 0, 4, p);
    p = base();
    p.wakuhaba = 50;
    run("p180_w50", 0, 4, p);
    p = base();
    p.shinzure = 10;
    run("p180_z10", 0, 4, p);
    printf(fails ? "SOME BAD\n" : "all ok\n");
    return fails != 0;
}
