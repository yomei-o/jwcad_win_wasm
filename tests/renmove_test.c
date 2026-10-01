/* 連 の 移動 (LL) -- against three runs of the original.
 *
 *   tests/renmove_test.exe
 *
 * The 文字 bar's 連 (1068) says
 *
 *   文字を指示してください。  連結（L)　移動（LL)　　文字切断位置指示(R)
 *
 * and the (LL) is a **double** click.  The port's own driver could not
 * send one until `LL<x>,<y>` went into tools/jwdraw.ps1 -- Windows
 * delivers a double click as down, up, WM_LBUTTONDBLCLK, up, and all four
 * can be posted, so no real mouse is needed.  That is what had this
 * blocked (RESUME, 「ダブルクリックで、測り手が投げられません」).
 *
 * With it, the original answers plainly.  A double click on a text turns
 * the prompt into 「移動先の点を指示して下さい  (L)free  (R)Read」 (5311)
 * and the click after it puts the text's **start** exactly there:
 *
 *     AB at (-94.2857, 26.3265), clicked at the view's (700,500)
 *                                  -> (89.3878, -96.1224)
 *     the same, clicked at (600,250) -> (28.1633, 56.9388)
 *
 * both the clicked point itself to six places.  **基点 makes no
 * difference**: the first run again with 中中 picked came out at the very
 * same place.  And the text that moved goes to the **end** of the
 * drawing -- the two came back CD first and AB second, the other way
 * round from how they were typed.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

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

/* the texts of a drawing, in its own order, leaving out the six settings
   ones a new sheet carries */
static int texts(const jw_drawing *d, const jw_obj **out, int max)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].color != 9) {
            if (out && n < max)
                out[n] = &d->obj[i];
            n++;
        }
    return n;
}

static double px(double sx) { return (sx - 554.0) / (49.0 / 30.0); }
static double py(double sy) { return (343.0 - sy) / (49.0 / 30.0); }

static void run(const char *path, int base, double tox, double toy,
                const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *want[8], *got[8];
    int i, k, nw;
    double worst = 0.0;

    printf("%s\n", what);
    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        fails++;
        return;
    }
    free(b);
    nw = texts(&ref, want, 8);
    ck(nw == 2, "  the original's two texts are in the file");
    if (nw != 2) {
        jw_free(&ref);
        return;
    }

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    app_fit();
    app_command(JW_CMD_MOJI);
    jw_cmd_moji_base(2);                /* 左下, the way it comes up */
    app_key('A');
    app_key('B');
    jw_cmd_point(d, app_view(), px(400.0), py(300.0), 0);
    app_key('C');
    app_key('D');
    jw_cmd_point(d, app_view(), px(400.0), py(400.0), 0);
    ck(texts(d, 0, 0) == 2, "  two texts to start with");
    jw_cmd_moji_base(base);
    ck(jw_cmd_bar(d, 1068) == 1, "  連 can be pressed");
    jw_cmd_point_ll(d, app_view(), px(405.0), py(300.0));
    jw_cmd_point(d, app_view(), px(tox), py(toy), 0);
    ck(texts(d, got, 8) == 2, "  still two texts");
    if (texts(d, 0, 0) != 2) {
        jw_cmd_bar(d, 1068);
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 2; i++) {
        const char *a = jw_str(d, got[i]->text);
        const char *c = jw_str(&ref, want[i]->text);

        if (!a || !c || strcmp(a, c)) {
            printf("     %d 本目 '%s'、原典は '%s'\n", i, a ? a : "", c ? c : "");
            worst = 1e9;
        }
        for (k = 0; k < 4; k++) {
            double e = fabs(got[i]->d[k] - want[i]->d[k]);

            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6 && worst < 1e8)
        for (i = 0; i < 2; i++)
            printf("     %d ours %.4f,%.4f  theirs %.4f,%.4f\n", i,
                   got[i]->d[0], got[i]->d[1], want[i]->d[0], want[i]->d[1]);
    ck(worst <= 1e-6, "  同じ順で同じところ");
    jw_cmd_bar(d, 1068);                /* 連 stays on until pressed again */
    jw_free(&ref);
}

int main(void)
{
    run("decomp/res/renmove.jww", 2, 700.0, 500.0, "-- 移動先 (700,500)");
    run("decomp/res/renmove2.jww", 2, 600.0, 250.0, "-- 移動先 (600,250)");
    run("decomp/res/renmove_naka.jww", 4, 700.0, 500.0,
        "-- 基点 中中 でも同じ");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
