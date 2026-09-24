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
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/text.h"
#include "../src/gen/layout.h"
#include "../src/gen/moji.h"
#include "../src/gen/cmds.h"
#include "../src/gen/bars.h"
#include "png.h"

static int fails;

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

    /* the three boxes: with 任意サイズ chosen, what is typed into them is
       what the next text is written at.  The original was given 30, 40 and
       2 the same way and its text came out w=30 h=40 sp=2
       (decomp/res/mojisize.jww). */
    {
        jw_drawing ref;
        unsigned char *b2;
        long n2;
        const jw_drawing *d3;
        const jw_obj *o;
        int k, at = -1;

        memset(&ref, 0, sizeof ref);
        b2 = slurp("decomp/res/mojisize.jww", &n2);
        if (!b2 || !jw_parse(&ref, b2, n2)) {
            printf("BAD  cannot read decomp/res/mojisize.jww -- drive the "
                   "original first\n");
            fails++;
            free(b2);
        } else {
            free(b2);
            /* the original's own text is the one with no 文字種 and a size
               nothing else has */
            for (k = 0; k < ref.ndrawn; k++)
                if (ref.obj[k].cls == JW_MOJI && ref.obj[k].n == 0
                    && ref.obj[k].d[4] == 30.0)
                    at = k;
            ck(at >= 0, "the original's text is in the answer");
            if (at >= 0) {
                jw_cmd_set(JW_CMD_MOJI);
                if (bar_button(1843, &x, &y))
                    app_press(x, y, 0);
                ck(app_moji_open(), "the dialog is up again");
                ctl(1884, &x, &y);              /* 任意サイズ */
                app_press(x, y, 0);
                ctl(1491, &x, &y);              /* 幅 */
                app_press(x, y, 0);
                ck(app_moji_focus() == 1491, "a box takes the typing");
                for (k = 0; k < 8; k++)
                    app_key(8);                 /* clear what was there */
                app_key('3');
                app_key('0');
                ctl(1492, &x, &y);              /* 高さ */
                app_press(x, y, 0);
                for (k = 0; k < 8; k++)
                    app_key(8);
                app_key('4');
                app_key('0');
                ctl(1493, &x, &y);              /* 間隔 */
                app_press(x, y, 0);
                for (k = 0; k < 8; k++)
                    app_key(8);
                app_key('2');
                ck(!strcmp(app_moji_box(1491), "30")
                   && !strcmp(app_moji_box(1492), "40")
                   && !strcmp(app_moji_box(1493), "2"),
                   "and holds what was typed");
                ctl(1, &x, &y);                 /* OK */
                app_press(x, y, 0);
                d3 = app_drawing();
                ck(d3->cur_style.w == 30.0 && d3->cur_style.h == 40.0
                   && d3->cur_style.sp == 2.0,
                   "OK writes them into the drawing");
                app_key('B');
                app_press(400, 300, 0);
                d3 = app_drawing();
                o = &d3->obj[d3->ndrawn - 1];
                ck(o->cls == JW_MOJI && o->d[4] == ref.obj[at].d[4]
                   && o->d[5] == ref.obj[at].d[5]
                   && o->d[6] == ref.obj[at].d[6] && o->n == ref.obj[at].n,
                   "and a text comes out the size the original's did");
            }
            jw_free(&ref);
        }
    }

    /* 斜体 and 太字.  They are not part of a 文字種: a text written with
       them on carries 10000 and 20000 in its trailing long on top of
       whichever 文字種 it is.  The original wrote one with each and one
       with both (decomp/res/moji{ital,bold,both}.jww), all at 任意サイズ,
       and a 文字種[ 3] on its own for the other half of the sum. */
    {
        static const struct { const char *f; int ital, bold; } W[3] = {
            { "decomp/res/mojiital.jww", 1, 0 },
            { "decomp/res/mojibold.jww", 0, 1 },
            { "decomp/res/mojiboth.jww", 1, 1 },
        };
        int w;

        for (w = 0; w < 3; w++) {
            jw_drawing ref;
            unsigned char *b2;
            long n2;
            const jw_drawing *d3;
            const jw_obj *o;
            int k, at = -1;

            memset(&ref, 0, sizeof ref);
            b2 = slurp(W[w].f, &n2);
            if (!b2 || !jw_parse(&ref, b2, n2)) {
                printf("BAD  cannot read %s -- drive the original first\n",
                       W[w].f);
                fails++;
                free(b2);
                continue;
            }
            free(b2);
            /* the one the original wrote is the only text saying A */
            for (k = 0; k < ref.ndrawn; k++)
                if (ref.obj[k].cls == JW_MOJI
                    && !strcmp(jw_str(&ref, ref.obj[k].text), "A"))
                    at = k;
            ck(at >= 0, "the original's text is in the answer");
            if (at >= 0) {
                b2 = slurp("orig/Test5.jww", &n2);
                if (b2 && app_open(b2, n2)) {
                    free(b2);
                    jw_cmd_set(JW_CMD_MOJI);
                    if (bar_button(1843, &x, &y))
                        app_press(x, y, 0);
                    if (W[w].ital) {
                        ctl(2420, &x, &y);
                        app_press(x, y, 0);
                    }
                    if (W[w].bold) {
                        ctl(2413, &x, &y);
                        app_press(x, y, 0);
                    }
                    ck(jw_cmd_moji_italic() == W[w].ital
                       && jw_cmd_moji_bold() == W[w].bold,
                       "  the boxes go down");
                    ctl(1, &x, &y);
                    app_press(x, y, 0);
                    app_key('A');
                    app_press(400, 300, 0);
                    d3 = app_drawing();
                    o = &d3->obj[d3->ndrawn - 1];
                    if (o->cls != JW_MOJI || o->n != ref.obj[at].n)
                        printf("     ours %d, the original's %d\n",
                               o->cls == JW_MOJI ? o->n : -1, ref.obj[at].n);
                    ck(o->cls == JW_MOJI && o->n == ref.obj[at].n,
                       "  and the text carries what the original's did");
                }
            }
            jw_free(&ref);
            jw_cmd_moji_style(0, 0);    /* back to plain for the next one */
        }
    }

    /* 色No. (ComboBox 2358).  The original was given row 6 of it and then
       an "A", and the text came out colour 6 -- the row **is** the colour
       (decomp/res/mojicol.jww).  The port drops a list of its own down when
       the box is pressed; the original's has not been photographed. */
    {
        jw_drawing ref;
        unsigned char *b2;
        long n2;
        int at = -1, i;

        memset(&ref, 0, sizeof ref);
        b2 = slurp("decomp/res/mojicol.jww", &n2);
        if (!b2 || !jw_parse(&ref, b2, n2)) {
            printf("BAD  cannot read decomp/res/mojicol.jww -- drive the "
                   "original first\n");
            fails++;
            free(b2);
        } else {
            free(b2);
            for (i = ref.ndrawn - 1; i >= 0; i--)
                if (ref.obj[i].cls == JW_MOJI && jw_text_drawn(&ref.obj[i])
                    && !strcmp(jw_str(&ref, ref.obj[i].text), "A")) {
                    at = i;
                    break;
                }
            ck(at >= 0, "the original's coloured text is in the answer");
            b2 = slurp("orig/Test5.jww", &n2);
            if (at >= 0 && b2 && app_open(b2, n2)) {
                const jw_drawing *d4;
                const jw_obj *o;
                rect_t vr;

                free(b2);
                jw_cmd_set(JW_CMD_MOJI);
                if (bar_button(1843, &x, &y))
                    app_press(x, y, 0);
                ck(app_moji_open(), "the 文字種 dialog is up");
                ctl(2358, &x, &y);              /* the 色No. box */
                app_press(x, y, 0);
                ck(app_moji_drop(), "  and pressing 色No. drops its list");
                {   /* row 6 of it */
                    rect_t dr;
                    int th = jw_text_height(), k, cy = 0;

                    ui_moji_rect(1264, 741, &dr);
                    for (k = 0; k < JW_NMOJI; k++)
                        if (jw_moji[k].id == 2358)
                            cy = dr.y + JW_MOJI_CAPTION + jw_moji[k].y
                                 + jw_moji[k].h;
                    app_press(x, cy + 1 + 6 * th + th / 2, 0);
                }
                ck(app_moji_color() == 6, "  and row 6 is colour 6");
                ctl(1, &x, &y);                 /* Ok */
                app_press(x, y, 0);
                app_key('A');
                ui_view_rect(1264, 741, &vr);
                app_press(vr.x + 500, vr.y + 400, 0);
                d4 = app_drawing();
                o = &d4->obj[d4->ndrawn - 1];
                if (o->cls != JW_MOJI || o->color != ref.obj[at].color)
                    printf("     ours %d, the original's %d\n",
                           o->cls == JW_MOJI ? o->color : -1,
                           ref.obj[at].color);
                ck(o->cls == JW_MOJI && o->color == ref.obj[at].color,
                   "and the text comes out the original's colour");
            }
            jw_free(&ref);
        }
    }

    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
