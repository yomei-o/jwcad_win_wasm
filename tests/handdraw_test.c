/* The two drawings, built with nothing but a mouse and a keyboard.
 *
 *   tests/handdraw_test.exe [out.jww]
 *
 * tests/tenkai_test.c builds the same two -- 直方体の展開図 and 円錐の展開図,
 * each with a dimension on it -- by calling into the command layer.  This one
 * has only what a person has: app_press on the toolbar, on the boxes and
 * checkboxes of the command bar, and in the drawing; app_key for what is
 * typed.  Nothing here reaches past the front end.
 *
 * That is the whole point of it.  Everything the command layer can do is of
 * no use until the buttons and the boxes reach it, and this says whether
 * they do.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/bars.h"
#include "../src/gen/cmds.h"
#include "../src/gen/layout.h"

#define PI 3.14159265358979323846

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* --------------------------------------------------------------- a hand --
 * The three things a person can do, and nothing else.
 */

/* the toolbar button for a command, pressed where it is drawn */
static int press_button(int cmd)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++)
        if (jw_btn_cmd[k] == cmd) {
            app_press(jw_buttons[k].x + BTN_W / 2,
                      jw_buttons[k].y + BTN_H / 2, 0);
            return jw_cmd() == cmd;
        }
    return 0;
}

/* a control on whatever command bar is up now */
static int bar_press(int id)
{
    int i, k;

    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != (unsigned)jw_cmd())
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            int x, y;
            if (c->id != id)
                continue;
            x = c->x + c->w / 2;
            y = c->y + c->h / 2;
            if (ui_bar_hit(x, y) != id)
                continue;               /* a variant bar's, not up now */
            app_press(x, y, 0);
            return 1;
        }
    }
    return 0;
}

/* press a box on the bar and type into it */
static int bar_type(int id, const char *s)
{
    int i;

    if (!bar_press(id))
        return 0;
    for (i = 0; i < 24; i++)
        app_key(8);
    for (; *s; s++)
        app_key((unsigned char)*s);
    app_key(13);
    return 1;
}

/* a click in the drawing, given where it should land on the paper */
static void click(double x, double y)
{
    const jw_view *v = app_view();
    int sx = jw_sx(v, x), sy = jw_sy(v, y);

    app_move(sx, sy);
    app_press(sx, sy, 0);
}

/* the same with the right button, which is how a point is read */
static void click_r(double x, double y)
{
    const jw_view *v = app_view();
    int sx = jw_sx(v, x), sy = jw_sy(v, y);

    app_move(sx, sy);
    app_press(sx, sy, 1);
}

static int count_of(const jw_drawing *d, int cls, int from)
{
    int i, n = 0;

    for (i = from; i < d->ndrawn; i++)
        if (d->obj[i].cls == cls)
            n++;
    return n;
}

/* ------------------------------------------------------------ 直方体 -----
 * 1000 x 600 x 400, laid out as a cross: the six faces typed into 矩形の寸法
 * one at a time, each one placed with two clicks.
 *
 * The paper is 1/100, so 1000 mm of the box is 10 mm across.
 */
static void box_development(jw_drawing *d, double ox, double oy)
{
    static const struct { double w, h, x, y; } F[6] = {
        { 1000.0,  600.0,   0.0,   0.0 },      /* front  */
        { 1000.0,  600.0,   0.0, -14.0 },      /* back   */
        {  400.0,  600.0, -14.0,   0.0 },      /* left   */
        {  400.0,  600.0,  10.0,   0.0 },      /* right  */
        { 1000.0,  400.0,   0.0,   6.0 },      /* top    */
        { 1000.0,  400.0,   0.0,  -4.0 }       /* bottom */
    };
    int i, before = d->ndrawn;

    ck(press_button(0x8004), "矩形 のボタンを押す");
    for (i = 0; i < 6; i++) {
        char box[32];
        sprintf(box, "%g,%g", F[i].w, F[i].h);
        if (!bar_type(1413, box)) {
            ck(0, "  寸法の箱に打てない");
            return;
        }
        click(ox + F[i].x, oy + F[i].y);
        click(ox + F[i].x + 1.0, oy + F[i].y + 1.0);
    }
    ck(count_of(d, JW_SEN, before) == 24,
       "  六面分の四角が 24 本引ける");
    bar_type(1413, "");
}

/* -------------------------------------------------------------- 円錐 -----
 * A base circle of 300 and the sector that wraps it: slant 800, so the
 * sweep is 2 pi 300 / 800.  The circle comes out of 円の半径, the sector
 * out of 円弧 with three clicks, and the two radii out of 線.
 */
static void cone_development(jw_drawing *d, double cx, double cy)
{
    double R = 3.0, L = 8.0;            /* 300 and 800 on a 1/100 sheet */
    double sweep = 2.0 * PI * R / L;
    int before = d->ndrawn;

    ck(press_button(0x8005), "円 のボタンを押す");
    ck(bar_type(1411, "300"), "  半径に 300 を打つ");
    click(cx, cy - 20.0);
    ck(count_of(d, JW_ENKO, before) == 1, "  一回のクリックで底面の円");
    bar_type(1411, "");

    /* the sector: 円弧 wants three points -- centre, start, end */
    ck(bar_press(1318), "  円弧 を押す");
    click(cx, cy);
    click(cx + L, cy);
    click(cx + L * cos(sweep), cy + L * sin(sweep));
    ck(count_of(d, JW_ENKO, before) == 2, "  三回のクリックで扇形の弧");
    bar_press(1318);                    /* put it back */

    /* and the two radii */
    ck(press_button(0x8003), "線 のボタンを押す");
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* Space: 水平・垂直 off */
    click(cx, cy);
    click(cx + L, cy);
    click(cx, cy);
    click(cx + L * cos(sweep), cy + L * sin(sweep));
    ck(count_of(d, JW_SEN, before) == 2, "  母線が二本");
}

/* ------------------------------------------------------------- 寸法 ------
 * On the box, not on thin air: the first face is 1000 wide and 600 high, so
 * the width goes under its bottom edge and the height beside its left one.
 * Both are measured by reading the corners with the right button, which is
 * how the original takes them -- a left click on an empty spot gives it
 * nothing to measure.
 */
static void dimension(jw_drawing *d, double x0, double y0, double w, double h)
{
    int before = d->ndrawn;

    ck(press_button(0x804f), "寸法 のボタンを押す");
    ck(bar_press(1062), "  端部 を矢印にする");
    ck(bar_press(1061) && bar_press(1061), "  小数桁を 0 にする");
    ck(bar_type(1411, "0"), "  傾きに 0 を打つ");

    /* the width, under the bottom edge */
    click(x0, y0 - 12.0);               /* where the extension lines end */
    click(x0, y0 - 10.0);               /* the dimension line itself */
    click_r(x0, y0);                    /* the two corners, read */
    click_r(x0 + w, y0);
    ck(count_of(d, JW_MOJI, before) == 1, "  幅の寸法値が一つ");
    ck(count_of(d, JW_SEN, before) >= 3, "  寸法線と引出線も引ける");

    /* and the height, standing up beside the left edge */
    before = d->ndrawn;
    ck(bar_press(1059), "  ０º/９０º を押す");
    click(x0 - 12.0, y0);
    click(x0 - 10.0, y0);
    click_r(x0, y0);
    click_r(x0, y0 + h);
    ck(count_of(d, JW_MOJI, before) == 1, "  高さの寸法値が一つ");
    if (count_of(d, JW_SEN, before) >= 1) {
        const jw_obj *line = 0;
        int i;
        for (i = before; i < d->ndrawn; i++)
            if (d->obj[i].cls == JW_SEN) {
                line = &d->obj[i];
                break;
            }
        ck(line && fabs(line->d[0] - line->d[2]) < 1e-9
           && fabs(fabs(line->d[3] - line->d[1]) - h) < 1e-6,
           "  その寸法線は立っていて高さを測っている");
    } else {
        ck(0, "  高さの寸法線が引ける");
    }
    bar_press(1059);                    /* put it back */
}

int main(int argc, char **argv)
{
    jw_drawing *d;
    int n0;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    ck(d && d->ndrawn == 0, "紙を一枚");
    if (!d)
        return 1;

    box_development(d, -60.0, 40.0);
    n0 = d->ndrawn;
    cone_development(d, 40.0, -30.0);
    ck(d->ndrawn > n0, "円錐側も伸びた");
    dimension(d, -60.0, 40.0, 10.0, 6.0);

    ck(d->ndrawn >= 24 + 4 + 6, "図面全体が手だけで組み上がる");

    if (argc > 1) {                     /* keep it, to open in the original */
        unsigned char *b;
        long n;
        if (app_save(&b, &n)) {
            FILE *f = fopen(argv[1], "wb");
            if (f) {
                fwrite(b, 1, (size_t)n, f);
                fclose(f);
                printf("ok   wrote %s (%ld bytes)\n", argv[1], n);
            }
            free(b);
        }
    }
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
