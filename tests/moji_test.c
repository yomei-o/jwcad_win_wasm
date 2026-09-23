/* 書込み文字種変更 -- the dialog, against the original's own.
 *
 *   tests/moji_test.exe tests/out/moji.png
 *
 * docs/ref_moji.png is that dialog painted into a bitmap by Jw_cad itself
 * (tools/jwdraw.ps1's dlg:b step, which never touches the screen).  This
 * puts the port's up in the same state -- Test5.jww open, the 文字 command
 * in force and 任意サイズ chosen, which is what the original had -- and
 * writes it out to be scored against that picture; tools/check.sh does the
 * scoring, with the text left out of it the same way the frame is.
 *
 * It also checks what the dialog is for: picking a 文字種 and pressing Ok
 * sets the size new texts are written in.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/layout.h"
#include "../src/gen/moji.h"
#include "../src/gen/cmds.h"
#include "../src/gen/bars.h"
#include "png.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* the middle of the control with this id, in client pixels */
static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_moji_rect(1264, 741, &r);
    for (i = 0; i < JW_NMOJI; i++)
        if (jw_moji[i].id == id) {
            *x = r.x + JW_MOJI_BORDER + jw_moji[i].x + jw_moji[i].w / 2;
            *y = r.y + JW_MOJI_CAPTION + jw_moji[i].y + jw_moji[i].h / 2;
            return;
        }
    *x = *y = -1;
}

/* the middle of a control on the 文字 command's bar, whose controls sit at
   client coordinates of their own (src/gen/bars.h) */
static int bar_button(int id, int *x, int *y)
{
    int i;

    for (i = 0; i < (int)(sizeof jw_bar_32806 / sizeof jw_bar_32806[0]); i++)
        if (jw_bar_32806[i].id == id) {
            *x = jw_bar_32806[i].x + jw_bar_32806[i].w / 2;
            *y = jw_bar_32806[i].y + jw_bar_32806[i].h / 2;
            return 1;
        }
    return 0;
}

int main(int argc, char **argv)
{
    const jw_drawing *d;
    FILE *f;
    unsigned char *b;
    long n;
    int x, y;

    app_resize(1264, 741);
    f = fopen("orig/Test5.jww", "rb");
    if (!f) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    app_open(b, n);
    free(b);

    jw_cmd_set(JW_CMD_MOJI);
    ck(!app_moji_open(), "the dialog is not up to start with");
    ck(bar_button(1843, &x, &y), "the 文字 bar has the 文字種 button");
    app_press(x, y, 0);
    ck(app_moji_open(), "pressing it puts the dialog up");

    /* the picture, in the state the original's was in */
    app_paint();
    if (argc > 1) {
        const fb_t *fb = app_fb();
        rect_t r;
        unsigned int *px;
        int i, j;

        ui_moji_rect(fb->w, fb->h, &r);
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

    /* what it is for.  Test5 writes at a free 20 by 20; 文字種 4 is 4 by 4
       with 0.5 between the letters. */
    d = app_drawing();
    ck(d->cur_style.w == 20.0 && d->cur_style.h == 20.0,
       "the drawing is writing at a free size to start with");
    ctl(1692, &x, &y);                  /* 文字種[ 4] */
    app_press(x, y, 0);
    ck(d->cur_style.w == 20.0, "picking one changes nothing on its own");
    ctl(1, &x, &y);                     /* OK */
    app_press(x, y, 0);
    ck(!app_moji_open(), "OK closes it");
    ck(d->cur_style.w == 4.0 && d->cur_style.h == 4.0
       && d->cur_style.sp == 0.5 && d->cur_style.color == 2,
       "and the drawing writes in what was picked");

    /* a text written afterwards has it, and says which 文字種 it is */
    {
        int before = d->ndrawn;

        app_key('A');
        app_press(400, 300, 0);
        d = app_drawing();
        ck(d->ndrawn == before + 1, "a text goes in");
        if (d->ndrawn == before + 1) {
            const jw_obj *o = &d->obj[d->ndrawn - 1];

            ck(o->d[4] == 4.0 && o->d[5] == 4.0 && o->d[6] == 0.5,
               "in the size the dialog set");
            ck(o->n == 4, "and it knows it is 文字種 4");
        }
    }

    /* キャンセル drops what was picked */
    app_press(x, y, 0);                 /* the bar button is where it was */
    jw_cmd_set(JW_CMD_MOJI);
    if (bar_button(1843, &x, &y))
        app_press(x, y, 0);
    ck(app_moji_open(), "it opens again");
    ctl(1698, &x, &y);                  /* 文字種[10] */
    app_press(x, y, 0);
    ctl(2, &x, &y);                     /* キャンセル */
    app_press(x, y, 0);
    ck(!app_moji_open(), "キャンセル closes it");
    d = app_drawing();
    ck(d->cur_style.w == 4.0, "and leaves the size as it was");

    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
