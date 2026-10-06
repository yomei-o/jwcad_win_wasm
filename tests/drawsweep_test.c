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

/* その絵に何がいくつあるか。種類ごとの数だけ見ます。 */
static void tally(const jw_drawing *d, int from, int *cnt)
{
    int i;

    for (i = 0; i < 8; i++)
        cnt[i] = 0;
    for (i = from; i < d->ndrawn; i++) {
        int c = d->obj[i].cls;

        if (c >= 0 && c < 8)
            cnt[c]++;
    }
}

static const char *CLSNAME[8] = {
    "?", "線", "円弧", "点", "文字", "ソリッド", "連続線", "?"
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
    jw_drawing ref;
    unsigned char *b;
    long n;
    int k, i, want = argc > 1 ? atoi(argv[1]) : 0;
    int base_n = 0;

    /* 下敷き */
    b = slurp("decomp/res/sweep_base.jww", &n);
    if (!b) {
        printf("BAD  decomp/res/sweep_base.jww がありません"
               " -- tools/drawsweep.sh を走らせてください\n");
        return 1;
    }
    free(b);

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
        base_n = d->ndrawn;
        fb = app_fb();
        ui_view_rect(fb->w, fb->h, &r);
        app_command(CMD[k]);
        for (i = 0; i < 3; i++)
            app_press(r.x + CLICK[i][0], r.y + CLICK[i][1], 0);

        tally(d, base_n, mine);
        tally(&ref, base_n, theirs);
        for (i = 0; i < 8; i++)
            if (mine[i] != theirs[i])
                same = 0;
        printf("%-4s %d\n", same ? "ok" : "差", CMD[k]);
        if (!same) {
            show("原典", theirs);
            show("移植", mine);
        }
        jw_free(&ref);
    }
    printf("%d の答えがありませんでした\n", nskip);
    printf("%s\n", fails ? "SOME BAD" : "終わり");
    return 0;
}
