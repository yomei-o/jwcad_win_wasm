/* 仮表示色 -- the colour a figure gets while the command is part way
 * through it.
 *
 *   tests/pending_test.exe
 *
 * The original does **not** draw it in the element's own pen.  Its basic
 * settings have a 仮表示色 (1122, Pen/Color11) and its own window bears
 * it out: with one corner of a 矩形 down, one end of a 線 down, or the
 * centre of a 円 down, and the cursor somewhere else, the window painted
 * into an off-screen bitmap has the provisional figure in **ff0000**
 * (tools/probe75.sh -- the pictures are tmp/pend_*.png).  That is the
 * same colour the range box already had.
 *
 * The port drew it in the element's own pen, which is the bug this test
 * is here to keep shut.  What is checked is that the figure hanging off
 * the cursor paints in ff0000 and that none of it paints in the writing
 * pen's own colour, and that a committed element goes back to that pen.
 *
 * What the original's raster op does where the provisional figure
 * crosses something already drawn is still not traced, so this only
 * looks at it over bare paper.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/gen/pens.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* how many pixels of each colour are in the drawing area */
static void count(unsigned int want, unsigned int other, int *a, int *b)
{
    const fb_t *fb = app_fb();
    rect_t r;
    int x, y;

    *a = *b = 0;
    ui_view_rect(fb->w, fb->h, &r);
    for (y = r.y; y < r.y + r.h; y++)
        for (x = r.x; x < r.x + r.w; x++) {
            unsigned int p = fb->px[(size_t)y * fb->w + x] & 0xffffffu;
            if (p == want)
                (*a)++;
            else if (p == other)
                (*b)++;
        }
}

/* the writing pen's own colour, which is what the port used to use.
   src/draw.c indexes the table by the pen itself, not by pen-1. */
static unsigned int pen_now(void)
{
    const jw_drawing *d = (const jw_drawing *)app_drawing();

    return d->pen_rgb[2];               /* 線色2, what a new drawing writes */
}

static void one(int cmd, const char *what, int n1, const int (*pt)[2])
{
    int red, own, i;

    printf("-- %s\n", what);
    app_new();
    app_command(cmd);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* Space: 水平・垂直 off */
    for (i = 0; i < n1; i++)
        app_press(pt[i][0], pt[i][1], 0);
    app_move(pt[n1][0], pt[n1][1]);
    app_paint();
    count(JW_KARI_RGB, pen_now(), &red, &own);
    printf("     仮 %d 画素、書込みペン %d 画素\n", red, own);
    ck(red > 20, "  仮の図形が 仮表示色 で出る");
    ck(own == 0, "  書込みペンでは一画素も出ない");

    /* and once it is committed it is the writing pen's again */
    app_press(pt[n1][0], pt[n1][1], 0);
    app_move(pt[n1][0] + 60, pt[n1][1] + 60);
    app_paint();
    count(JW_KARI_RGB, pen_now(), &red, &own);
    printf("     置いたあと 仮 %d 画素、書込みペン %d 画素\n", red, own);
    ck(own > 20, "  置いたものは書込みペンで出る");
}

int main(void)
{
    static const int SEN[2][2] = { { 379, 335 }, { 778, 500 } };
    static const int KUKEI[2][2] = { { 379, 335 }, { 778, 500 } };
    static const int ENKO[2][2] = { { 500, 400 }, { 700, 500 } };

    app_resize(1264, 741);
    ck(JW_KARI_RGB == 0xff0000u, "仮表示色 は ff0000（原典の Pen/Color11）");
    one(JW_CMD_SEN, "線", 1, SEN);
    one(JW_CMD_KUKEI, "矩形", 1, KUKEI);
    one(JW_CMD_ENKO, "円", 1, ENKO);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
