/* バーのつまみを一つずつ押して、原典と移植で同じものが出るか。
 *
 *   tests/barsweep_test.exe             全部
 *   tests/barsweep_test.exe 32773       一つの命令だけ
 *
 * `tools/barsweep.sh` が原典に同じことをさせて
 * `decomp/res/bsw_<cmd>_<id>.jww` を作ります。**一つの命令につき
 * Jw_cad は一度だけ**起動して、
 *
 *     命令を送り直す → つまみを押す → 三クリック → 保存 → 押し戻す
 *
 * を繰り返します。絵は消さずに積み上がるので、一枚ごとの中身は
 * 「そこまでに引いた全部」で、**そのつまみが引いたものは一つ前との
 * 差**です。ここもそう読み、移植にも同じ順でやらせます。
 *
 * `tests/drawsweep_test.c` と同じで、**合っていると言うための試験では
 * ありません。**食い違ったところが次に原典へ訊きに行く場所です。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/bars.h"

static int nsame, ndiff, nmiss;

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

/* その命令のバーに出てくる押せる id を、原典から読んだ表どおりに。 */
static int press_ids(int cmd, int *out, int max)
{
    int i, k, n = 0;

    for (i = 0; i < JW_NBARS && n < max; i++) {
        if (jw_bars[i].cmd != (unsigned)cmd)
            continue;
        for (k = 0; k < jw_bars[i].n && n < max; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            int j, dup = 0;

            /* 原典の控え（decomp/res/bars.txt）は窓の階級で並べていて、
               チェックボックスも階級は Button です。掃き出しの台本も
               そちらを見ているので、ここも両方拾います。 */
            if ((c->kind != JW_CTL_BUTTON && c->kind != JW_CTL_CHECK)
                || !c->enabled)
                continue;
            for (j = 0; j < n; j++)
                if (out[j] == c->id)
                    dup = 1;
            if (!dup)
                out[n++] = c->id;
        }
        break;                          /* tools/barsweep.sh と同じ一枚目 */
    }
    return n;
}

int main(int argc, char **argv)
{
    static const int CMD[] = {
        32771, 32772, 32773, 32785, 32806, 32847, 32870, 32872,
        32873, 32874, 32883, 32892, 32894, 32908
    };
    static const int CLICK[3][2] = { { 400, 350 }, { 600, 450 }, { 500, 420 } };
    jw_drawing ref, base, prev, pmine;
    unsigned char *b;
    long n;
    int k, want = argc > 1 ? atoi(argv[1]) : 0;

    memset(&base, 0, sizeof base);
    memset(&prev, 0, sizeof prev);
    memset(&pmine, 0, sizeof pmine);
    b = slurp("decomp/res/sweep_base.jww", &n);
    if (!b || !jw_parse(&base, b, n)) {
        printf("BAD  decomp/res/sweep_base.jww が読めません\n");
        free(b);
        return 1;
    }
    free(b);

    for (k = 0; k < (int)(sizeof CMD / sizeof CMD[0]); k++) {
        int ids[32], nid, step;

        if (want && CMD[k] != want)
            continue;
        nid = press_ids(CMD[k], ids, 32);
        printf("=== %d  (%d の釦)\n", CMD[k], nid);

        /* 一つの命令ぶんを、台本と同じ順で通します */
        b = slurp("decomp/res/sweep_base.jww", &n);
        app_new();
        app_resize(1264, 741);
        if (!b || !app_open(b, n)) {
            printf("BAD  下敷きが開けません\n");
            free(b);
            return 1;
        }
        free(b);
        /* 台本の下敷きと同じ順にバーの状態を作ります —— 線 に入って
           水平・垂直 を切り、点 へ逃がす。**ここで命令を余分に送ると
           いけません**: 線 をもう一度送ると原典も移植も 水平・垂直 を
           裏返すので（src/cmd.c の jw_cmd_set）、段ごとの送り直しと
           合わなくなります。 */
        app_command(32771);
        if (jw_cmd_bar_check(1333) > 0)
            jw_cmd_bar((jw_drawing *)app_drawing(), 1333);
        app_command(32785);
        /* 一段目は下敷きとの差を見ます（空と比べると下敷きごと
           並んでしまって、何が新しいのか分からなくなります） */
        jw_free(&prev);
        memset(&prev, 0, sizeof prev);
        jw_free(&pmine);
        memset(&pmine, 0, sizeof pmine);
        if (base.ndrawn > 0) {
            prev.obj = (jw_obj *)malloc((size_t)base.ndrawn
                                        * sizeof *prev.obj);
            pmine.obj = (jw_obj *)malloc((size_t)base.ndrawn
                                         * sizeof *pmine.obj);
            if (prev.obj && pmine.obj) {
                memcpy(prev.obj, base.obj,
                       (size_t)base.ndrawn * sizeof *prev.obj);
                memcpy(pmine.obj, base.obj,
                       (size_t)base.ndrawn * sizeof *pmine.obj);
                prev.ndrawn = prev.nobj = base.ndrawn;
                pmine.ndrawn = pmine.nobj = base.ndrawn;
            }
        }

        for (step = 0; step <= nid; step++) {
            char path[64];
            const jw_drawing *d = app_drawing();
            const fb_t *fb = app_fb();
            rect_t r;
            int i, id = step ? ids[step - 1] : 0;
            const jw_obj *ta[96], *ma[96];
            int tn, mn, miss = 0;

            app_command(CMD[k]);        /* 台本も毎回送り直します */
            if (step)
                jw_cmd_bar((jw_drawing *)d, id);
            ui_view_rect(fb->w, fb->h, &r);
            for (i = 0; i < 3; i++)
                app_press(r.x + CLICK[i][0], r.y + CLICK[i][1], 0);

            snprintf(path, sizeof path, "decomp/res/bsw_%d_%d.jww",
                     CMD[k], id);
            memset(&ref, 0, sizeof ref);
            b = slurp(path, &n);
            if (!b || !jw_parse(&ref, b, n)) {
                printf("     %5d  答えなし\n", id);
                nmiss++;
                free(b);
                continue;
            }
            free(b);
            /* 一つ前の段との差が、そのつまみの引いたもの */
            tn = fresh(&ref, &prev, ta, 96);
            mn = fresh(d, &pmine, ma, 96);
            for (i = 0; i < tn; i++)
                if (!found_in(ta[i], ma, mn))
                    miss++;
            for (i = 0; i < mn; i++)
                if (!found_in(ma[i], ta, tn))
                    miss++;
            if (miss) {
                printf("     %5d  差: 原典 %d・移植 %d（合わない %d）\n",
                       id, tn, mn, miss);
                ndiff++;
            } else {
                nsame++;
            }
            /* 次の段のために、いまを控えておきます */
            jw_free(&prev);
            prev = ref;
            memset(&ref, 0, sizeof ref);
            jw_free(&pmine);
            memset(&pmine, 0, sizeof pmine);
            if (d->ndrawn > 0) {
                pmine.obj = (jw_obj *)malloc((size_t)d->ndrawn
                                             * sizeof *pmine.obj);
                if (pmine.obj) {
                    memcpy(pmine.obj, d->obj,
                           (size_t)d->ndrawn * sizeof *pmine.obj);
                    pmine.ndrawn = pmine.nobj = d->ndrawn;
                }
            }
            /* 押し戻しはしません（台本も同じ。上の注） */
        }
        jw_free(&prev);
        memset(&prev, 0, sizeof prev);
        jw_free(&pmine);
        memset(&pmine, 0, sizeof pmine);
    }
    printf("一致 %d、差 %d、答えなし %d\n", nsame, ndiff, nmiss);
    return 0;
}
