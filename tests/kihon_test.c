/* 基本設定 -- the dialog, against the original's own.
 *
 *   tests/kihon_test.exe tests/out/kihon.png
 *
 * docs/ref_kihon1.png .. 8.png are that dialog painted into bitmaps by
 * Jw_cad itself, one per tab (tools/jwdraw.ps1's dlgat: step, which clicks
 * the strip before it reads the dialog -- the original does not build a
 * tab's controls until it is shown).  This walks the port's through the
 * same eight and writes each one out to be scored against its picture;
 * tools/check.sh does the scoring, with the text and the tab strip left out
 * of it.
 *
 * What the boxes mean has not been worked out, so pressing one only makes
 * it go down or up, and OK and キャンセル both just close the dialog.
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

/* the middle of one of the showing tab's controls, in client pixels */
static void ctl(int tab, int id, int *x, int *y)
{
    rect_t r;
    const jw_kh_t *c = jw_kihon_tabs[tab].c;
    int i;

    ui_kihon_rect(1264, 741, &r);
    for (i = 0; i < jw_kihon_tabs[tab].n; i++)
        if (c[i].id == id) {
            *x = r.x + JW_KH_BORDER + c[i].x + c[i].w / 2;
            *y = r.y + JW_KH_CAPTION + c[i].y + c[i].h / 2;
            return;
        }
    *x = *y = -1;
}

/* the middle of one of the tabs */
static void tab_at(int t, int *x, int *y)
{
    rect_t r;

    ui_kihon_rect(1264, 741, &r);
    *x = r.x + JW_KH_BORDER + JW_KH_TAB_X
         + (jw_kihon_tab_at[t] + jw_kihon_tab_at[t + 1]) / 2;
    *y = r.y + JW_KH_CAPTION + JW_KH_TAB_Y + JW_KH_TAB_ROW / 2;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j, t;

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
    ck(ui_kihon_ntabs() == 8, "it has eight tabs");

    /* one picture per tab */
    for (t = 0; t < ui_kihon_ntabs(); t++) {
        if (t) {
            tab_at(t, &x, &y);
            app_press(x, y, 0);
        }
        ck(app_kihon_tab() == t, "  the tab that was pressed is showing");
        app_paint();
        if (argc > 1) {
            unsigned int *px;
            char path[256];
            const char *dot = strrchr(argv[1], '.');
            int len = dot ? (int)(dot - argv[1]) : (int)strlen(argv[1]);

            sprintf(path, "%.*s%d%s", len, argv[1], t + 1, dot ? dot : "");
            ui_kihon_rect(fb->w, fb->h, &r);
            px = (unsigned int *)malloc((size_t)r.w * r.h * sizeof *px);
            if (px) {
                for (j = 0; j < r.h; j++)
                    for (i = 0; i < r.w; i++)
                        px[j * r.w + i] =
                            fb->px[(size_t)(r.y + j) * fb->w + r.x + i];
                png_rgb(path, r.w, r.h, px);
                free(px);
                printf("     wrote %s\n", path);
            }
        }
    }

    /* a box goes down and comes up again */
    tab_at(0, &x, &y);
    app_press(x, y, 0);
    for (i = 0; i < jw_kihon_tabs[0].n; i++)
        if (jw_kihon_tabs[0].c[i].id == 2860)   /* 透過属性, starts ticked */
            break;
    ck(i < jw_kihon_tabs[0].n, "透過属性 is one of the boxes");
    ctl(0, 2860, &x, &y);
    app_press(x, y, 0);
    app_paint();
    ck(1, "and pressing it does not fall over");
    app_press(x, y, 0);

    ctl(0, 2, &x, &y);                  /* キャンセル */
    app_press(x, y, 0);
    ck(!app_kihon_open(), "キャンセル takes it down");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
