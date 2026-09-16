/* Does pressing things do what the original does?
 *
 *   tests/click_test.exe [drawing.jww]
 *
 * Checked here:
 *   - the command the original starts in is the one the reference screen was
 *     taken in (線), and that button is the pressed one;
 *   - pressing another command button moves the pressed state, which is all
 *     the original's ON_UPDATE_COMMAND_UI handler does (FUN_00511c20);
 *   - a disabled button does nothing;
 *   - two clicks in the drawing area add one line, with the ends where they
 *     were clicked and the attributes CData's constructor gives it;
 *   - 点 puts one down with a single click.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/layout.h"
#include "../src/gen/cmds.h"
#include "png.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* the middle of button k */
static void btn_mid(int k, int *x, int *y)
{
    *x = jw_buttons[k].x + BTN_W / 2;
    *y = jw_buttons[k].y + BTN_H / 2;
}

static int find_btn(int cmd)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++)
        if (jw_btn_cmd[k] == cmd)
            return k;
    return -1;
}

int main(int argc, char **argv)
{
    int x, y, k, before;
    const jw_drawing *d;
    double mx0, my0, mx1, my1;
    const jw_view *v;

    if (!app_resize(1264, 741)) {
        printf("BAD  out of memory\n");
        return 1;
    }
    if (argc > 1) {
        FILE *f = fopen(argv[1], "rb");
        unsigned char *b;
        long n;
        if (!f) {
            printf("BAD  cannot open %s\n", argv[1]);
            return 1;
        }
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        b = (unsigned char *)malloc((size_t)n);
        if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
            printf("BAD  cannot read %s\n", argv[1]);
            return 1;
        }
        fclose(f);
        if (!app_open(b, n)) {
            printf("BAD  %s: %s\n", argv[1], app_error());
            return 1;
        }
        free(b);
    }

    ck(jw_cmd() == 0x8003, "starts in 線, the command the reference screen shows");
    k = find_btn(0x8003);
    ck(k >= 0 && jw_buttons[k].state != 1, "線 has a button and it is enabled");

    /* 矩形 */
    k = find_btn(0x8004);
    ck(k >= 0, "矩形 has a button");
    btn_mid(k, &x, &y);
    ck(app_press(x, y, 0) == 1, "pressing 矩形 is taken");
    ck(jw_cmd() == 0x8004, "the command is now 矩形");

    /* a disabled one: ブロック化 is greyed out on the reference screen */
    k = find_btn(0x8055);
    ck(k >= 0 && jw_buttons[k].state == 1, "ブロック化 is the disabled one");
    btn_mid(k, &x, &y);
    ck(app_press(x, y, 0) == 0, "a disabled button does nothing");
    ck(jw_cmd() == 0x8004, "and the command did not change");

    /* back to 線 and draw one */
    k = find_btn(0x8003);
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x8003, "back in 線");

    d = app_drawing();
    before = d ? d->ndrawn : 0;
    v = app_view();

    app_press(300, 200, 0);
    ck(app_move(500, 400) == 1, "with one end down, moving shows the line to come");
    d = app_drawing();
    ck(!d || d->ndrawn == before, "and nothing is added until the second point");
    app_press(500, 400, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before + 1, "the second point adds one element");
    if (d && d->ndrawn == before + 1) {
        const jw_obj *o = &d->obj[before];
        int wg = 0, i;
        for (i = 0; i < 16; i++)
            if (d->group[i].state == 3)
                wg = i;
        ck(o->cls == JW_SEN, "it is a line");
        ck(o->ltype == 1 && o->color == 2 && o->width == 0,
           "line type 1, colour 2, no width -- CData's constructor");
        ck(o->lgroup == wg
           && o->layer == (d->group[wg].write_layer & 15),
           "on the write layer of the write layer group");
        mx0 = v->ox + (300 - v->bx) / v->scale;
        my0 = v->oy + (v->by - 200) / v->scale;
        mx1 = v->ox + (500 - v->bx) / v->scale;
        my1 = v->oy + (v->by - 400) / v->scale;
        ck(fabs(o->d[0] - mx0) < 1e-9 && fabs(o->d[1] - my0) < 1e-9
           && fabs(o->d[2] - mx1) < 1e-9 && fabs(o->d[3] - my1) < 1e-9,
           "with the ends where they were clicked");
        /* Back within a pixel: both ways round truncate towards zero, which
           is what the original's cast does too (FUN_004b6d60 forward, and
           the inverse beside it), so a point left of the pinned pixel comes
           back one to the right. */
        ck(abs(jw_sx(v, o->d[0]) - 300) <= 1 && abs(jw_sy(v, o->d[1]) - 200) <= 1,
           "and those millimetres map back to within a pixel of the click");
    }
    /* 点: one click and it is there */
    k = find_btn(0x8011);
    ck(k >= 0, "点 has a button");
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x8011, "the command is now 点");
    d = app_drawing();
    before = d ? d->ndrawn : 0;
    app_press(400, 300, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before + 1, "one click adds one element");
    if (d && d->ndrawn == before + 1) {
        const jw_obj *o = &d->obj[before];
        ck(o->cls == JW_TEN, "and it is a point");
        ck(abs(jw_sx(app_view(), o->d[0]) - 400) <= 1
           && abs(jw_sy(app_view(), o->d[1]) - 300) <= 1,
           "within a pixel of where it was clicked");
    }

    /* 円: centre then a point it goes through */
    k = find_btn(0x8005);
    ck(k >= 0, "円 has a button");
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x8005, "the command is now 円");
    d = app_drawing();
    before = d ? d->ndrawn : 0;
    app_press(600, 350, 0);
    ck(app_move(700, 350) == 1, "the circle to come follows the mouse");
    app_press(700, 350, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before + 1, "the second point adds one element");
    if (d && d->ndrawn == before + 1) {
        const jw_obj *o = &d->obj[before];
        v = app_view();
        ck(o->cls == JW_ENKO, "it is an arc");
        ck(fabs(o->d[2] - 100.0 / v->scale) < 1e-6,
           "with the radius the distance to the second point");
        ck(fabs(o->d[4] - 2 * 3.14159265358979323846) < 1e-9,
           "swept the whole way round -- the constructor's 2 pi");
        ck(o->d[6] == 1.0, "and round, not squashed -- its flattening of 1");
        ck(o->n == 1, "with the trailing 1 every whole circle in the samples has");
    }

    /* 元に戻る is an action, not a mode: it runs and the command stays put */
    k = find_btn(0xe12b);
    ck(k >= 0 && !jw_btn_mode[k], "元に戻る is an action, not a mode");
    d = app_drawing();
    before = d->ndrawn;
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    d = app_drawing();
    ck(jw_cmd() == 0x8005, "pressing it leaves the command alone");
    ck(d->ndrawn == before - 1, "and takes the last element back out");
    ck(find_btn(0x8003) >= 0 && jw_btn_mode[find_btn(0x8003)],
       "線 on the other hand is a mode");

    app_paint();
    if (argc > 2)
        png_rgb(argv[2], app_fb()->w, app_fb()->h, app_fb()->px);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
