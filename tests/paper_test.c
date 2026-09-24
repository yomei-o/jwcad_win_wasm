/* 用紙サイズ (Ａ-０..Ａ-４, 32820..32824) -- against the original.
 *
 *   tests/paper_test.exe
 *
 * The original was given Test5 -- an A-1 sheet -- and each of the five menu
 * commands in turn, and saved what it had (decomp/res/paperA0.jww and
 * paperA3.jww).  Only the sheet changed: the number the header keeps and
 * the half width and half height that go with it.  Nothing of the drawing
 * moved.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

static void one(int cmd, const char *answer)
{
    jw_drawing ref;
    const jw_drawing *d;
    unsigned char *b;
    long n;
    int i, bad = 0;

    printf("%d -> %s\n", cmd, answer);
    memset(&ref, 0, sizeof ref);
    b = slurp(answer, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", answer);
        fails++;
        free(b);
        return;
    }
    free(b);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot read orig/Test5.jww\n");
        fails++;
        free(b);
        jw_free(&ref);
        return;
    }
    free(b);
    ck(app_command(cmd), "  the command does something");
    d = app_drawing();
    ck(d->paper_size == ref.paper_size && d->paper_hw == ref.paper_hw
       && d->paper_hh == ref.paper_hh, "  and the sheet is the original's");
    if (d->paper_size != ref.paper_size || d->paper_hw != ref.paper_hw)
        printf("     ours %d %gx%g, theirs %d %gx%g\n", d->paper_size,
               d->paper_hw, d->paper_hh, ref.paper_size, ref.paper_hw,
               ref.paper_hh);
    /* and nothing of the drawing moved */
    for (i = 0; i < d->ndrawn && i < ref.ndrawn; i++) {
        int k;

        if (!jw_text_drawn(&ref.obj[i]))
            continue;
        for (k = 0; k < 8; k++)
            if (d->obj[i].d[k] != ref.obj[i].d[k])
                bad = 1;
    }
    ck(!bad, "  and nothing of the drawing moved");
    jw_free(&ref);
}

int main(void)
{
    app_resize(1264, 741);
    one(32820, "decomp/res/paperA0.jww");
    one(32823, "decomp/res/paperA3.jww");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
