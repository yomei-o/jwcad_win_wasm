/* 仮表示色 -- the colour a figure gets while the command is part way
 * through it.
 *
 *   tests/pending_test.exe
 *
 * The original does **not** draw it in the element's own pen, and it does
 * not simply paint it red either.  It brackets the draw with
 * SetROP2(R2_NOTXORPEN) and SetROP2(R2_COPYPEN) -- FUN_004bbad0 and
 * FUN_004bbaa0 of the decompilation, which also raise and drop the flag
 * at +0x8444 that its drawing routine FUN_00481d50 reads -- and the pen
 * is 仮表示色 (1122 on the basic-settings colour page, Pen/Color11,
 * ff0000 here).  So a pixel becomes **~(ff0000 ^ what was there)**.
 *
 * Its own window bears that out.  The same drawing was painted into an
 * off-screen bitmap with and without a rubber rectangle over it, and
 * every pixel that changed was one of these two (tools/probe78.sh,
 * probe79.sh):
 *
 *     ffffff -> ff0000     over bare paper
 *     000000 -> 00ffff     over one of its own black lines
 *
 * and a line with one end down and a circle with its centre down came
 * back in ff0000 over paper as well (tools/probe75.sh).
 *
 * The port drew the figure in the element's own pen, which is the bug
 * this test is here to keep shut.  Both halves are checked: red over the
 * paper, and cyan where it crosses a black line.
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

    /* and over what is now drawn, the band is ~(pen ^ dest): black turns
       cyan.  The committed figure is black (線色2), so a second
       provisional one laid over it has to show 00ffff. */
    {
        int cyan, nothing;

        for (i = 0; i < n1; i++)
            app_press(pt[i][0], pt[i][1], 0);
        app_move(pt[n1][0], pt[n1][1]);
        app_paint();
        count(~(JW_KARI_RGB ^ pen_now()) & 0xffffffu, 0xdeadbeefu,
              &cyan, &nothing);
        printf("     重なったところ %d 画素\n", cyan);
        ck(cyan > 10, "  描いてあるものに重なると ~(ペン^下地)");
    }
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
