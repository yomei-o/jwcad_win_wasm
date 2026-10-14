/* 連続線's 手書線 (1774): a drag made up here.  The original puts a line in wherever the
   mouse has gone 5 pixels (in x or in y) from where the last one ended
   (FUN_006df0f0); the stroke is a chain of such lines, ends with the button, and one
   元に戻す takes it all back. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

int main(void)
{
    const fb_t *fb;
    rect_t r;
    const jw_drawing *d;
    const jw_view *v;
    int n0, i, cx, cy, ok = 1, joined = 1, far_enough = 1, made;

    app_resize(1264, 741);
    app_new();
    fb = app_fb();
    ui_view_rect(fb->w, fb->h, &r);
    app_command(32883);                         /* 連続線 */
    ck(jw_cmd() == JW_CMD_RENZOKU, "連続線 is the command");
    ck(jw_cmd_bar((jw_drawing *)app_drawing(), 1774), "the 手書線 box can be ticked");
    ck(jw_cmd_bar_check(1774) > 0, "and is ticked");
    d = app_drawing();
    v = app_view();
    n0 = d->ndrawn;
    cx = r.x + r.w / 2;
    cy = r.y + r.h / 2;

    /* a tiny move after the press makes no line */
    app_press(cx, cy, 0);
    ck(jw_cmd_freehand(), "the button going down starts a stroke");
    app_move(cx + 2, cy + 2);
    app_move(cx + 3, cy - 3);
    ck(d->ndrawn == n0, "a move of under 5 pixels makes nothing");
    app_move(cx + 4, cy);
    ck(d->ndrawn == n0, "(4 pixels either way is still nothing)");
    app_move(cx + 5, cy);
    ck(d->ndrawn == n0 + 1, "5 pixels in x makes the first line");

    /* a circle of radius 100 pixels, a pixel at a time */
    for (i = 0; i <= 628; i++) {
        double a = i / 100.0;

        app_move(cx + 5 + (int)(100.0 * cos(a)) - 100, cy + (int)(100.0 * sin(a)));
    }
    ck(jw_cmd_release(0, 0, 0, 0) == 0, "release without a drawing does nothing");
    app_release(cx + 5, cy, 0);
    made = d->ndrawn - n0;
    printf("     the circle of 628 pixels of path made %d lines\n", made);
    ck(made > 100 && made < 200, "a stroke of about 630 pixels makes 100 to 200 lines (one per 5 or so)");
    ck(!jw_cmd_freehand(), "the button coming up ends the stroke");
    for (i = n0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        int dx = abs(jw_sx(v, o->d[2]) - jw_sx(v, o->d[0])), dy = abs(jw_sy(v, o->d[3]) - jw_sy(v, o->d[1]));

        if (o->cls != JW_SEN)
            ok = 0;
        if (dx < 5 && dy < 5)
            far_enough = 0;
        if (i > n0 && (fabs(o->d[0] - d->obj[i - 1].d[2]) > 1e-9 || fabs(o->d[1] - d->obj[i - 1].d[3]) > 1e-9))
            joined = 0;
    }
    ck(ok, "every piece is a line");
    ck(far_enough, "and every one is at least 5 pixels in x or y");
    ck(joined, "each starts where the last one ended");
    ck(fabs(d->obj[n0].d[0] - (app_view()->ox + (cx - app_view()->bx) / app_view()->scale)) < 1e-6, "the first starts at the point of the press");

    /* one 元に戻す */
    jw_cmd_undo((jw_drawing *)d);
    ck(d->ndrawn == n0, "one 戻る takes the whole stroke");

    /* a second stroke, and Esc/another command in the middle lets go of it */
    app_press(cx, cy, 0);
    app_move(cx + 20, cy);
    app_command(JW_CMD_SEN);
    ck(!jw_cmd_freehand(), "changing the command ends a stroke");
    app_move(cx + 40, cy);
    ck(d->ndrawn == n0 + 1, "(and what was drawn stays: nothing more is added)");
    jw_cmd_undo((jw_drawing *)d);
    ck(d->ndrawn == n0, "as one step of 戻る");

    /* the box off: 連続線 as it was */
    app_command(32883);
    jw_cmd_bar((jw_drawing *)d, 1774);
    ck(jw_cmd_bar_check(1774) <= 0, "the box can be put out again");
    {
        int before = d->ndrawn;

        app_press(cx - 100, cy + 100, 0);
        app_press(cx - 50, cy + 100, 0);
        app_move(cx, cy + 100);
        ck(!jw_cmd_freehand(), "with the box out a press starts no stroke");
        (void)before;
    }
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
