/* 中心点取得 (33016) -- against the original.
 *
 *   tests/snap_test.exe
 *
 * The 設定 menu's one-shot read modes.  The status line spells this one out:
 * 「線・円指示で線・円の中心点　　　読取点指示で２点間中心」.
 *
 * The original was opened on tmp/geom.jww with 水平・垂直 turned off, and
 * two lines were drawn: each started free and ended with 中心点取得 armed,
 * the first pointing at the whole circle (centre 60,-30) and the second at
 * the first line (which runs -90,60 to 90,60, so its middle is 0,60).
 * decomp/res/snapcen.jww is what it saved -- and those are exactly the two
 * ends.
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
    int i, was, bad = 0;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("tmp/geom.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open tmp/geom.jww -- run tools/refanswers.sh\n");
        free(b);
        return 1;
    }
    free(b);
    was = app_drawing()->ndrawn;
    ui_view_rect(fb->w, fb->h, &r);

    /* The port opens in 線 with 水平・垂直 off, which is where the drive
       was after its pb:1333 -- entering 線 again here would flip it back
       on, so the command is left alone. */
    ck(jw_cmd() == JW_CMD_SEN && !jw_cmd_hv(), "線 with 水平・垂直 off");
    app_press(r.x + 200, r.y + 150, 0);
    ck(app_command(33016), "中心点取得 arms");
    ck(jw_cmd_read_mode_now() == 33016, "  and says so");
    app_press(r.x + 636, r.y + 365, 0); /* on the whole circle */
    ck(!jw_cmd_read_mode_now(), "  and goes off once it has been used");

    app_press(r.x + 250, r.y + 150, 0);
    app_command(33016);
    app_press(r.x + 589, r.y + 274, 0); /* on the first line */
    d = app_drawing();
    ck(d->ndrawn == was + 2, "two lines came out of it");

    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/snapcen.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/snapcen.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
        printf("SOME BAD\n");
        return 1;
    }
    free(b);
    for (i = was; i < ref.ndrawn && i < d->ndrawn; i++) {
        const jw_obj *q = &ref.obj[i], *p = &d->obj[i];
        int k;

        if (!jw_text_drawn(q))
            continue;
        for (k = 0; k < 4; k++)
            if (fabs(p->d[k] - q->d[k]) > 1e-6) {
                printf("     the %dth's d[%d] is %.6f, the original's "
                       "%.6f\n", i, k, p->d[k], q->d[k]);
                bad = 1;
            }
    }
    ck(!bad, "and both end where the original's do, to six places");
    jw_free(&ref);

    /* 円周1/4点取得 (33028) twice and 線上点 (33017) once, from the same
       drawing again -- decomp/res/snapmore.jww is the original's. */
    b = slurp("tmp/geom.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open tmp/geom.jww again\n");
        free(b);
        printf("SOME BAD\n");
        return 1;
    }
    free(b);
    app_press(r.x + 200, r.y + 150, 0);
    ck(app_command(33028), "円周1/4点取得 arms");
    app_press(r.x + 638, r.y + 374, 1);  /* near the circle's 0 o'clock */
    app_press(r.x + 250, r.y + 150, 0);
    app_command(33028);
    app_press(r.x + 626, r.y + 361, 1);  /* and near its 90 */
    app_press(r.x + 300, r.y + 150, 0);
    ck(app_command(33017), "線上点・交点取得 arms");
    app_press(r.x + 589, r.y + 274, 1);  /* picks the line */
    ck(jw_cmd_read_mode_now() == 33017, "  and waits on it for the point");
    app_press(r.x + 589, r.y + 240, 0);  /* dropped onto it */
    d = app_drawing();
    ck(d->ndrawn == was + 3, "three more lines came out of them");

    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/snapmore.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/snapmore.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
        printf("SOME BAD\n");
        return 1;
    }
    free(b);
    bad = 0;
    for (i = was; i < ref.ndrawn && i < d->ndrawn; i++) {
        const jw_obj *q = &ref.obj[i], *p = &d->obj[i];
        int k;

        if (!jw_text_drawn(q))
            continue;
        for (k = 0; k < 4; k++)
            if (fabs(p->d[k] - q->d[k]) > 1e-6) {
                printf("     the %dth's d[%d] is %.6f, the original's "
                       "%.6f\n", i, k, p->d[k], q->d[k]);
                bad = 1;
            }
    }
    ck(!bad, "and those three end where the original's do too");
    jw_free(&ref);

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
