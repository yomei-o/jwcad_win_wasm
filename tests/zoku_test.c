/* 線属性 -- the dialog, against the original's own.
 *
 *   tests/zoku_test.exe tests/out/zoku.png
 *
 * docs/ref_zoku.png is that dialog painted into a bitmap by Jw_cad itself
 * (tmp/jwdraw.ps1's dlg: step, which never touches the screen).  This puts
 * the port's up in the same state -- colour 2, line type 1, which is what
 * the original had -- and writes it out to be scored against that picture;
 * tools/check.sh does the scoring, with the text left out of it the same way
 * the frame is.
 *
 * It also checks what the dialog is for: pressing a colour and a line type
 * and then Ok sets the pen new elements are drawn with.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/layout.h"
#include "../src/gen/zoku.h"
#include "../src/gen/cmds.h"
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

    ui_zoku_rect(1264, 741, &r);
    for (i = 0; i < JW_NZOKU; i++)
        if (jw_zoku[i].id == id) {
            *x = r.x + JW_ZOKU_BORDER + jw_zoku[i].x + jw_zoku[i].w / 2;
            *y = r.y + JW_ZOKU_CAPTION + jw_zoku[i].y + jw_zoku[i].h / 2;
            return;
        }
    *x = *y = -1;
}

int main(int argc, char **argv)
{
    const jw_drawing *d;
    FILE *f;
    unsigned char *b;
    long n;
    int k, x, y;

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

    for (k = 0; k < JW_NBUTTONS; k++)
        if (jw_btn_cmd[k] == 0x8027)
            break;
    ck(k < JW_NBUTTONS, "線属性 has a button");
    ck(!app_zoku_open(), "and the dialog is not up to start with");
    app_press(jw_buttons[k].x + BTN_W / 2, jw_buttons[k].y + BTN_H / 2, 0);
    ck(app_zoku_open(), "pressing it puts the dialog up");

    /* the picture, in the state the original's was in */
    app_paint();
    if (argc > 1) {
        const fb_t *fb = app_fb();
        rect_t r;
        unsigned int *px;
        int i, j;
        ui_zoku_rect(fb->w, fb->h, &r);
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

    /* what it is for */
    d = app_drawing();
    /* nothing has touched the pen yet: the drawing keeps 0 for both, and
       jw_add reads that as colour 2 and line type 1 -- what the original
       starts every session with */
    ck(d->write_color == 0 && d->write_ltype == 0,
       "the pen is untouched to start with");
    ctl(1405, &x, &y);                  /* 線色5 */
    app_press(x, y, 0);
    ctl(2451, &x, &y);                  /* 点線2 */
    app_press(x, y, 0);
    ck(d->write_color == 0 && d->write_ltype == 0,
       "picking in it changes nothing on its own");
    ctl(1, &x, &y);                     /* Ok */
    app_press(x, y, 0);
    ck(!app_zoku_open(), "Ok closes it");
    ck(d->write_color == 5 && d->write_ltype == 3,
       "and the pen is what was picked");

    /* and a line drawn afterwards has it */
    jw_cmd_set(JW_CMD_SEN);
    app_press(300, 200, 0);
    app_press(500, 300, 0);
    d = app_drawing();
    ck(d->obj[d->ndrawn - 1].color == 5 && d->obj[d->ndrawn - 1].ltype == 3,
       "a line drawn after it comes out in that pen");

    /* キャンセル drops what was picked */
    app_press(jw_buttons[k].x + BTN_W / 2, jw_buttons[k].y + BTN_H / 2, 0);
    ctl(1402, &x, &y);                  /* 線色2 */
    app_press(x, y, 0);
    ctl(2, &x, &y);                     /* キャンセル */
    app_press(x, y, 0);
    ck(!app_zoku_open(), "キャンセル closes it too");
    ck(d->write_color == 5 && d->write_ltype == 3, "and changes nothing");

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
