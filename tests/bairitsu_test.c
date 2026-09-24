/* 画面倍率・文字表示 (32811) -- the dialog, against the original's own.
 *
 *   tests/bairitsu_test.exe tests/out/bairitsu.png
 *
 * docs/ref_bairitsu.png is that dialog painted into a bitmap by Jw_cad
 * itself.  This puts the port's up in the same state and writes it out to
 * be scored against that picture; tools/check.sh does the scoring, with the
 * text left out of it.
 *
 * One button does something: 用紙全体表示 (1091) fits the sheet to the
 * window.  That is checked here by zooming in first and seeing the view come
 * back to what app_open left it at.  Everything else on the dialog moves the
 * view too, and a view cannot be scored against the original on this machine
 * -- its screen cannot be captured -- so those just take the dialog down.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/bairitsu.h"
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

    ui_bairitsu_rect(1264, 741, &r);
    for (i = 0; i < JW_NBAIRITSU; i++)
        if (jw_bairitsu[i].id == id) {
            *x = r.x + JW_BR_BORDER + jw_bairitsu[i].x + jw_bairitsu[i].w / 2;
            *y = r.y + JW_BR_CAPTION + jw_bairitsu[i].y
                 + jw_bairitsu[i].h / 2;
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
    double mmpp;
    int x, y, i, j;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    mmpp = app_view()->mmpp;

    ck(!app_bairitsu_open(), "the dialog is not up to start with");
    ck(app_command(32811), "画面倍率・文字表示 puts it up");
    ck(app_bairitsu_open(), "which says so");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_bairitsu_rect(fb->w, fb->h, &r);
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

    /* a tick goes on and off */
    ctl(2104, &x, &y);                  /* 【文字枠】を表示する */
    app_press(x, y, 0);
    ck(app_bairitsu_open(), "a checkbox leaves it up");

    /* the greyed 表示範囲記憶 is not pressable */
    ctl(1068, &x, &y);
    app_press(x, y, 0);
    ck(app_bairitsu_open(), "and so does the greyed 表示範囲記憶");

    /* 用紙全体表示 fits the sheet again */
    ui_view_rect(fb->w, fb->h, &r);
    app_zoom(4.0, r.x + r.w / 2, r.y + r.h / 2);
    ck(app_view()->mmpp != mmpp, "zooming in moves the view");
    ctl(1091, &x, &y);
    app_press(x, y, 0);
    ck(!app_bairitsu_open(), "用紙全体表示 takes the dialog down");
    ck(app_view()->mmpp == mmpp, "and the sheet fits the window again");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
