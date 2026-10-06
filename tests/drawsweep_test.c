/* 作図コマンドを一つずつ、原典と同じ三クリックで引いて突き合わせる。
 *
 *   tests/drawsweep_test.exe            全部
 *   tests/drawsweep_test.exe 32771      一つだけ
 *
 * `tools/drawsweep.sh` が原典に同じことをさせて `decomp/res/sweep_*.jww`
 * を作ります。下敷き（交わる二本と円一つ）は `sweep_base.jww`。
 *
 * **これは「合っている」と言うための試験ではありません。**三クリック
 * だけの、つまみも触らない素の状態で、原典と移植が同じものを引くか
 * どうかの**地図**です。食い違ったところが次に調べる場所になります。
 * 一つずつ原典に訊いて直した結果は、それぞれの専用の試験のほうに
 * あります（`tests/bardraw_test.c`・`tests/tenbar_test.c` など）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"

static int fails, nskip;

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

/* その絵に何がいくつあるか。種類ごとの数だけ見ます。
 *
 * **末尾から数えてはいけません。**原典は書き出すとき新しい要素を
 * いちばん後ろに置くとは限らないので、下敷きぶんを引く形にします。 */
static void tally(const jw_drawing *d, int *cnt)
{
    int i;

    for (i = 0; i < 8; i++)
        cnt[i] = 0;
    for (i = 0; i < d->ndrawn; i++) {
        int c = d->obj[i].cls;

        if (c >= 0 && c < 8)
            cnt[c]++;
    }
}

static void minus(int *a, const int *b)
{
    int i;

    for (i = 0; i < 8; i++)
        a[i] -= b[i];
}

/* 下敷きに無い要素。下敷きと同じものは飛ばして拾います。 */
static int fresh(const jw_drawing *d, const jw_drawing *base,
                 const jw_obj **out, int max)
{
    int i, j, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++) {
        int same = 0;

        for (j = 0; j < base->ndrawn; j++)
            if (base->obj[j].cls == d->obj[i].cls
                && fabs(base->obj[j].d[0] - d->obj[i].d[0]) < 1e-9
                && fabs(base->obj[j].d[1] - d->obj[i].d[1]) < 1e-9
                && fabs(base->obj[j].d[2] - d->obj[i].d[2]) < 1e-9
                && fabs(base->obj[j].d[3] - d->obj[i].d[3]) < 1e-9) {
                same = 1;
                break;
            }
        if (!same)
            out[n++] = &d->obj[i];
    }
    return n;
}

/* その要素が相手の並びのどれかと同じか。 */
static int found_in(const jw_obj *o, const jw_obj **set, int n)
{
    int i, k;

    for (i = 0; i < n; i++) {
        int same = set[i]->cls == o->cls;

        for (k = 0; k < 7 && same; k++)
            if (fabs(set[i]->d[k] - o->d[k]) > 1e-6)
                same = 0;
        if (same)
            return 1;
    }
    return 0;
}

/* src/jww.h の enum のとおり */
static const char *CLSNAME[8] = {
    "線", "円弧", "点", "文字", "ソリッド", "ブロック", "定義", "?"
};

static void show(const char *who, const int *c)
{
    int i;

    printf("     %-8s", who);
    for (i = 0; i < 8; i++)
        if (c[i])
            printf(" %s=%d", CLSNAME[i], c[i]);
    printf("\n");
}

int main(int argc, char **argv)
{
    static const int CMD[] = {
        32771, 32772, 32773, 32785, 32806, 32847, 32870, 32872,
        32873, 32874, 32883, 32892, 32894, 32908
    };
    /* tools/drawsweep.sh と同じ三クリック（作図領域の座標） */
    static const int CLICK[3][2] = { { 400, 350 }, { 600, 450 }, { 500, 420 } };
    jw_drawing ref, base;
    unsigned char *b;
    long n;
    int k, i, want = argc > 1 ? atoi(argv[1]) : 0;
    int base_n = 0, basec[8];

    /* 下敷き */
    memset(&base, 0, sizeof base);
    b = slurp("decomp/res/sweep_base.jww", &n);
    if (!b || !jw_parse(&base, b, n)) {
        printf("BAD  decomp/res/sweep_base.jww が読めません"
               " -- tools/drawsweep.sh を走らせてください\n");
        free(b);
        return 1;
    }
    free(b);
    tally(&base, basec);
    base_n = base.ndrawn;

    for (k = 0; k < (int)(sizeof CMD / sizeof CMD[0]); k++) {
        char path[64];
        const jw_drawing *d;
        const fb_t *fb;
        rect_t r;
        int mine[8], theirs[8], same = 1;

        if (want && CMD[k] != want)
            continue;
        snprintf(path, sizeof path, "decomp/res/sweep_%d.jww", CMD[k]);
        memset(&ref, 0, sizeof ref);
        b = slurp(path, &n);
        if (!b || !jw_parse(&ref, b, n)) {
            printf("     %d  答えがありません（%s）\n", CMD[k], path);
            nskip++;
            free(b);
            continue;
        }
        free(b);

        /* 移植に同じことをさせる */
        b = slurp("decomp/res/sweep_base.jww", &n);
        app_new();
        app_resize(1264, 741);
        if (!b || !app_open(b, n)) {
            printf("BAD  下敷きが開けません\n");
            free(b);
            fails++;
            break;
        }
        free(b);
        d = app_drawing();
        fb = app_fb();
        ui_view_rect(fb->w, fb->h, &r);
        app_command(CMD[k]);
        /* 下敷きを引くとき `tools/drawsweep.sh` が 水平・垂直 (1333) を
           切っていて、原典ではそれが次の命令にも残ります。移植も同じ
           状態から始めます。 */
        if (jw_cmd_bar_check(1333) > 0)
            jw_cmd_bar((jw_drawing *)d, 1333);
        for (i = 0; i < 3; i++)
            app_press(r.x + CLICK[i][0], r.y + CLICK[i][1], 0);

        tally(d, mine);
        tally(&ref, theirs);
        minus(mine, basec);
        minus(theirs, basec);
        for (i = 0; i < 8; i++)
            if (mine[i] != theirs[i])
                same = 0;
        /* 数が合っていたら座標まで見ます */
        {
            const jw_obj *ta[64], *ma[64];
            int tn = fresh(&ref, &base, ta, 64);
            int mn = fresh(d, &base, ma, 64);
            int miss = 0;

            if (same) {
                for (i = 0; i < tn; i++)
                    if (!found_in(ta[i], ma, mn))
                        miss++;
                for (i = 0; i < mn; i++)
                    if (!found_in(ma[i], ta, tn))
                        miss++;
            }
            printf("%-4s %d   （下敷き %d、原典 %d、移植 %d、"
                   "新しいもの 原典 %d・移植 %d）\n",
                   !same ? "差" : miss ? "座標差" : "ok",
                   CMD[k], base_n, ref.ndrawn, d->ndrawn, tn, mn);
            if (!same) {
                show("原典", theirs);
                show("移植", mine);
            } else if (miss) {
                for (i = 0; i < tn; i++)
                    if (!found_in(ta[i], ma, mn))
                        printf("     原典にだけ %s (%.4f %.4f)-(%.4f %.4f)\n",
                               CLSNAME[ta[i]->cls & 7], ta[i]->d[0],
                               ta[i]->d[1], ta[i]->d[2], ta[i]->d[3]);
                for (i = 0; i < mn; i++)
                    if (!found_in(ma[i], ta, tn))
                        printf("     移植にだけ %s (%.4f %.4f)-(%.4f %.4f)\n",
                               CLSNAME[ma[i]->cls & 7], ma[i]->d[0],
                               ma[i]->d[1], ma[i]->d[2], ma[i]->d[3]);
            }
        }
        jw_free(&ref);
    }
    printf("%d の答えがありませんでした\n", nskip);
    printf("%s\n", fails ? "SOME BAD" : "終わり");
    return 0;
}
