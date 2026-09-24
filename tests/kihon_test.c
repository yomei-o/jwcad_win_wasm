/* 基本設定 -- the dialog, against the original's own.
 *
 *   tests/kihon_test.exe tests/out/kihon.png
 *
 * docs/ref_kihon.png is that dialog painted into a bitmap by Jw_cad itself
 * (tools/jwdraw.ps1's dlg: step).  This puts the port's up in the same state
 * and writes it out to be scored against that picture; tools/check.sh does
 * the scoring, with the text and the tab strip left out of it.
 *
 * Only 一般(1) is there to be scored: the original does not build the other
 * seven tabs until they are shown, so there is nothing to copy them from.
 * What the boxes on it mean has not been worked out either, so pressing one
 * only makes it go down or up.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/kihon.h"
#include "png.h"

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

/* the middle of one of the dialog's controls, in client pixels */
static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_kihon_rect(1264, 741, &r);
    for (i = 0; i < JW_NKIHON; i++)
        if (jw_kihon[i].id == id) {
            *x = r.x + JW_KH_BORDER + jw_kihon[i].x + jw_kihon[i].w / 2;
            *y = r.y + JW_KH_CAPTION + jw_kihon[i].y + jw_kihon[i].h / 2;
            return;
        }
    *x = *y = -1;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);

    ck(!app_kihon_open(), "the dialog is not up to start with");
    ck(app_command(32891), "基本設定 puts it up");
    ck(app_kihon_open(), "which says so");

    /* the picture, in the state the original's was in */
    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_kihon_rect(fb->w, fb->h, &r);
        px = (unsigned int *)malloc((size_t)r.w * r.h * sizeof *px);
        if (px) {
            for (j = 0; j < r.h; j++)
                for (i = 0; i < r.w; i++)
                    px[j * r.w + i] = fb->px[(size_t)(r.y + j) * fb->w
                                             + r.x + i];
            png_rgb(argv[1], r.w, r.h, px);
            free(px);
            printf("     wrote %s, %dx%d\n", argv[1], r.w, r.h);
        }
    }

    /* a box goes down and comes up again */
    for (i = 0; i < JW_NKIHON; i++)
        if (jw_kihon[i].id == 2860)     /* 透過属性, which starts ticked */
            break;
    ck(i < JW_NKIHON, "透過属性 is one of the boxes");
    ctl(2860, &x, &y);
    app_press(x, y, 0);
    app_paint();
    ck(1, "and pressing it does not fall over");
    app_press(x, y, 0);

    ctl(2, &x, &y);                     /* キャンセル */
    app_press(x, y, 0);
    ck(!app_kihon_open(), "キャンセル takes it down");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
