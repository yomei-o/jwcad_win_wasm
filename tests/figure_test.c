/* 図形読込 (32862) -- against the original.
 *
 *   tests/figure_test.exe
 *
 * The original was opened on Test5 and given decomp/res/fig.jws -- one of
 * the figures Jw_cad ships, six lines making a 6mm box with a cross in it,
 * drawn at 1/100 -- and the figure was put down at (400, 300) in the view.
 * decomp/res/figin.jww is what it saved.
 *
 * Test5's write group is at 1/200, so the box came in **3mm** wide: the
 * figure keeps the size it stands for on the ground.  Its base point (the
 * one in the .jws header) landed on the clicked point, its colour and line
 * type came with it, and its layer became the drawing's write layer.
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

int main(void)
{
    const fb_t *fb;
    const jw_drawing *d;
    jw_drawing ref;
    unsigned char *b;
    long n;
    rect_t r;
    int i, j, was, bad = 0;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    was = app_drawing()->ndrawn;

    b = slurp("decomp/res/fig.jws", &n);
    if (!b) {
        printf("BAD  cannot read decomp/res/fig.jws -- run "
               "tools/refanswers.sh\n");
        return 1;
    }
    ck(app_figure(b, n), "the figure is read");
    free(b);
    ck(jw_cmd() == JW_CMD_ZUKEI, "and reading it enters 図形読込");
    ck(jw_cmd_figure_ready(), "which says it has one");

    ui_view_rect(fb->w, fb->h, &r);
    app_press(r.x + 400, r.y + 300, 0);
    d = app_drawing();
    ck(d->ndrawn == was + 6, "a point puts its six lines down");

    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/figin.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/figin.jww -- drive the original "
               "first\n");
        fails++;
        free(b);
        printf("%s\n", fails ? "SOME BAD" : "all ok");
        return 1;
    }
    free(b);
    for (i = was, j = was; i < ref.ndrawn && j < d->ndrawn; i++) {
        const jw_obj *q = &ref.obj[i], *p;
        int k;

        if (!jw_text_drawn(q))
            continue;                   /* the memo texts a save leaves */
        while (j < d->ndrawn && !jw_text_drawn(&d->obj[j]))
            j++;
        if (j >= d->ndrawn)
            break;
        p = &d->obj[j++];
        if (p->cls != q->cls || p->color != q->color || p->ltype != q->ltype
            || (p->layer & 15) != (q->layer & 15)
            || (p->lgroup & 15) != (q->lgroup & 15)) {
            printf("     the %dth is cls=%d col=%d lt=%d lay=%d where the "
                   "original's is cls=%d col=%d lt=%d lay=%d\n", i, p->cls,
                   p->color, p->ltype, p->layer & 15, q->cls, q->color,
                   q->ltype, q->layer & 15);
            bad = 1;
            continue;
        }
        for (k = 0; k < 8; k++)
            if (fabs(p->d[k] - q->d[k]) > 1e-6) {
                printf("     the %dth's d[%d] is %.6f, the original's "
                       "%.6f\n", i, k, p->d[k], q->d[k]);
                bad = 1;
            }
    }
    ck(!bad, "and every one of them is the original's, to six places");
    jw_free(&ref);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
