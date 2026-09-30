/* 縮尺・読取　設定 -- the dialog, against the original's own.
 *
 *   tests/shakudo_test.exe tests/out/shakudo.png
 *
 * docs/ref_shakudo.png is that dialog painted into a bitmap by Jw_cad
 * itself over orig/Test5.jww, which is why the sixteen groups are at the
 * scales they are.  This puts the port's up over the same drawing and
 * writes it out to be scored against that picture; tools/check.sh does the
 * scoring, with the text left out of it.
 *
 * The menu's 縮尺・読取 (32944) opens it, and so does the second box of the
 * status line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/gen/shakudo.h"
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

    ui_shakudo_rect(1264, 741, &r);
    for (i = 0; i < JW_NSHAKUDO; i++)
        if (jw_shakudo[i].id == id) {
            *x = r.x + JW_SK_BORDER + jw_shakudo[i].x + jw_shakudo[i].w / 2;
            *y = r.y + JW_SK_CAPTION + jw_shakudo[i].y + jw_shakudo[i].h / 2;
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

    ck(!app_shakudo_open(), "the dialog is not up to start with");
    ck(app_command(32944), "縮尺・読取 が出す");
    ck(app_shakudo_open(), "which says so");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_shakudo_rect(fb->w, fb->h, &r);
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

    ctl(2, &x, &y);                     /* キャンセル */
    if (x < 0)
        ctl(1, &x, &y);
    app_press(x, y, 0);
    ck(!app_shakudo_open(), "閉じる");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
