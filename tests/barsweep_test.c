/* バーのつまみを一つずつ押して、原典と移植で同じものが出るか。
 *
 *   tests/barsweep_test.exe             全部
 *   tests/barsweep_test.exe 32773       一つの命令だけ
 *
 * `tools/barsweep.sh` が原典に同じことをさせて
 * `decomp/res/bsw_<cmd>_<id>.jww` を作ります。押したものは**次へ
 * 持ち越されます** —— 一つの命令につき Jw_cad を一度だけ起動して、
 * 押しては三クリック、押しては三クリック、と進むからです。だから
 * ここで見るのは「そこまで順に押していったときの絵」です。
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

            if (c->kind != JW_CTL_BUTTON || !c->enabled)
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
    jw_drawing ref, base;
    unsigned char *b;
    long n;
    int k, want = argc > 1 ? atoi(argv[1]) : 0;

    memset(&base, 0, sizeof base);
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

        /* 移植も一度きりの流れで、押しては三クリック、を繰り返します */
        b = slurp("decomp/res/sweep_base.jww", &n);
        app_new();
        app_resize(1264, 741);
        if (!b || !app_open(b, n)) {
            printf("BAD  下敷きが開けません\n");
            free(b);
            return 1;
        }
        free(b);
        app_command(CMD[k]);
        if (jw_cmd_bar_check(1333) > 0)
            jw_cmd_bar((jw_drawing *)app_drawing(), 1333);

        for (step = 0; step <= nid; step++) {
            char path[64];
            const jw_drawing *d = app_drawing();
            const fb_t *fb = app_fb();
            rect_t r;
            int i, id = step ? ids[step - 1] : 0;
            const jw_obj *ta[96], *ma[96];
            int tn, mn, miss = 0;

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
            tn = fresh(&ref, &base, ta, 96);
            mn = fresh(d, &base, ma, 96);
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
            jw_free(&ref);
        }
    }
    printf("一致 %d、差 %d、答えなし %d\n", nsame, ndiff, nmiss);
    return 0;
}
