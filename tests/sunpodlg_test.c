/* 寸法設定 -- the dialog, against the original's own.
 *
 *   tests/sunpodlg_test.exe tests/out/sunpodlg.png
 *
 * docs/ref_sunpodlg.png is that dialog painted into a bitmap by Jw_cad
 * itself.  This puts the port's up in the same state and writes it out to
 * be scored against that picture; tools/check.sh does the scoring, with the
 * text left out of it.
 *
 * The picture only: what the numbers and the boxes on it do has not been
 * followed up, so pressing one just makes it go down or up.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/sunpodlg.h"
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

static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_sunpodlg_rect(1264, 741, &r);
    for (i = 0; i < JW_NSUNPODLG; i++)
        if (jw_sunpodlg[i].id == id) {
            *x = r.x + JW_SD_BORDER + jw_sunpodlg[i].x + jw_sunpodlg[i].w / 2;
            *y = r.y + JW_SD_CAPTION + jw_sunpodlg[i].y
                 + jw_sunpodlg[i].h / 2;
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

    ck(!app_sunpodlg_open(), "the dialog is not up to start with");
    ck(app_command(32925), "寸法設定 puts it up");
    ck(app_sunpodlg_open(), "which says so");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_sunpodlg_rect(fb->w, fb->h, &r);
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

    /* there is no キャンセル on this one: two OKs instead */
    ctl(1, &x, &y);
    app_press(x, y, 0);
    ck(!app_sunpodlg_open(), "OK takes it down");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
