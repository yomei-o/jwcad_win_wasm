/* 回った・反転した参照の中の字、縦書きの字（ブロック解除 32909）。原典で測った答え:
 *
 *   tests/blkrot_test.exe
 *
 * decomp/res/blkrot_<名前>_base.jww（tools/mkblktxt2.c: 定義に字 5 本、参照 20 = 角 0・30・90・200・-60 ×
 * 倍率 (-1,1)・(1,-1)・(-1,-1)・(1,1)）を原典で 範囲選択 → ブロック解除 した結果が _free.jww。
 *   h  横書き（角 0・30・90・150・-60）     v  縦書き（+0x44 の 0x20、角 -90・0・90・180・-45）
 *   h3 / v3  幅 4・高さ 3・間隔 0.3・入れた長さ 5、字数 1〜5（字の長さが式でかけ直されるのを見る）
 *   v2  同じで 字数 2
 * 写しの方は 参照を選んで 32909 を押し、出た字の始点・終点・幅・高さ・間隔・角を 1e-6 で比べる
 * （字は始点が一番近いものどうし）。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

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

static int hidden(const jw_obj *o)
{
    return o->d[1] == -1000.0;
}

static void one(const char *name)
{
    char p[200], msg[200];
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    int i, j, nt = 0, bad = 0, nref = 0;

    snprintf(p, sizeof p, "decomp/res/blkrot_%s_free.jww", name);
    b = slurp(p, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  no %s\n", p);
        fails++;
        free(b);
        return;
    }
    free(b);
    snprintf(p, sizeof p, "decomp/res/blkrot_%s_base.jww", name);
    b = slurp(p, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open %s\n", p);
        fails++;
        free(b);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_BLOCK) {
            d->obj[i].sel = 1;
            d->obj[i].flags = (unsigned short)(d->obj[i].flags | 2u);
            nref++;
        }
    jw_cmd_set(JW_CMD_HANI);
    app_command(32909);
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        double bd = 1e300;
        int bj = -1;

        if (o->cls != JW_MOJI || hidden(o))
            continue;
        nt++;
        /* 始点が重なる字が いくつかあるので、始点が一番近いなかで 残りが一番近いもの */
        for (j = 0; j < ref.ndrawn; j++) {
            const jw_obj *g = &ref.obj[j];
            double dd, rest = 0.0;
            int k;

            if (g->cls != JW_MOJI || hidden(g))
                continue;
            for (k = 2; k < 7; k++)
                rest += fabs(g->d[k] - o->d[k]);
            dd = hypot(g->d[0] - o->d[0], g->d[1] - o->d[1]) * 1e3 + rest;
            if (dd < bd) {
                bd = dd;
                bj = j;
            }
        }
        if (bj >= 0) {
            const jw_obj *g = &ref.obj[bj];
            int k, same = hypot(g->d[0] - o->d[0], g->d[1] - o->d[1]) < 1e-6;

            for (k = 2; k < 7 && same; k++)
                if (!(fabs(o->d[k] - g->d[k]) < 1e-6))
                    same = 0;
            /* 角は 360 の違いは同じ */
            if (same) {
                double dv = fmod(fabs(o->d[7] - g->d[7]), 360.0);

                if (!(dv < 1e-6 || dv > 360.0 - 1e-6))
                    same = 0;
            }
            if (!same) {
                if (bad < 6)
                    printf("     ours s=(%.4f,%.4f) e=(%.4f,%.4f) w=%.3f h=%.3f sp=%.3f ang=%.3f\n"
                           "     orig s=(%.4f,%.4f) e=(%.4f,%.4f) w=%.3f h=%.3f sp=%.3f ang=%.3f\n",
                           o->d[0], o->d[1], o->d[2], o->d[3], o->d[4], o->d[5], o->d[6], o->d[7],
                           g->d[0], g->d[1], g->d[2], g->d[3], g->d[4], g->d[5], g->d[6], g->d[7]);
                bad++;
            }
        }
    }
    snprintf(msg, sizeof msg, "%s: 字 %d 本（参照 %d）", name, nt, nref);
    ck(nt == nref * 5 && bad == 0, msg);
    jw_free(&ref);
}

int main(void)
{
    static const char *const names[] = { "h", "v", "h3", "v3", "v2" };
    int i;

    app_resize(1264, 741);
    for (i = 0; i < 5; i++)
        one(names[i]);
    return fails ? 1 : 0;
}
