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
    ck(!jw_cmd_hv(), "coming from 矩形 leaves 水平・垂直 alone");

    /* 線 pressed again, with 線 already the command, flips 水平・垂直 --
     * that is the whole of FUN_004fdc40's 0x8003 arm when the command before
     * was 0x8003 too.  Driving Jw_cad: from a fresh start a 30-degree drag
     * draws a 30-degree line, after one press of 線 it draws horizontal,
     * and after two it is back to 30 degrees. */
    app_press(x, y, 0);
    ck(jw_cmd_hv(), "pressing 線 again turns 水平・垂直 on");
    d = app_drawing();
    before = d ? d->ndrawn : 0;
    app_press(300, 200, 0);
    app_press(500, 315, 0);
    d = app_drawing();
    if (d && d->ndrawn == before + 1) {
        const jw_obj *o = &d->obj[before];
        v = app_view();
        ck(o->d[1] == o->d[3] && abs(jw_sx(v, o->d[2]) - 500) <= 1,
           "and the longer way wins: a shallow drag comes out level");
    }
    app_press(300, 200, 0);
    app_press(500, 700, 0);
    d = app_drawing();
    if (d && d->ndrawn == before + 2) {
        const jw_obj *o = &d->obj[before + 1];
        v = app_view();
        ck(o->d[0] == o->d[2] && abs(jw_sy(v, o->d[3]) - 700) <= 1,
           "a steep one comes out upright");
    }
    app_press(x, y, 0);
    ck(!jw_cmd_hv(), "and pressing it once more turns it off again");
    {   /* take those two back out */
        int u = find_btn(0xe12b), ux, uy;
        btn_mid(u, &ux, &uy);
        app_press(ux, uy, 0);
        app_press(ux, uy, 0);
    }

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

    /* 矩形: two opposite corners, and four lines round them.  What they are
     * and the order they come in was taken from Jw_cad itself -- tmp/jwdraw.ps1
     * posts the two clicks and 上書, and the file that comes back has four
     * CDataSen laid end to end from the first corner: along x, then y, then
     * back.  Clicking the corners the other way round gives the same pattern
     * turned round, so it goes by the first click, not by which corner is
     * which. */
    k = find_btn(0x8004);
    ck(k >= 0 && jw_btn_mode[k], "矩形 has a button and is a mode");
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x8004, "the command is now 矩形");
    d = app_drawing();
    before = d ? d->ndrawn : 0;
    app_press(500, 300, 0);
    ck(app_move(650, 400) == 1, "the box to come follows the mouse");
    app_press(650, 400, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before + 4, "the second corner adds four lines");
    if (d && d->ndrawn == before + 4) {
        const jw_obj *o = &d->obj[before];
        double x0, y0, x1, y1;
        int i, ok = 1;
        v = app_view();
        x0 = o[0].d[0];
        y0 = o[0].d[1];
        x1 = o[1].d[0];
        y1 = o[1].d[3];
        for (i = 0; i < 4; i++)
            if (o[i].cls != JW_SEN)
                ok = 0;
        ck(ok, "all four are lines");
        ck(abs(jw_sx(v, x0) - 500) <= 1 && abs(jw_sy(v, y0) - 300) <= 1
           && abs(jw_sx(v, x1) - 650) <= 1 && abs(jw_sy(v, y1) - 400) <= 1,
           "the corners are where they were clicked");
        ck(o[0].d[2] == x1 && o[0].d[3] == y0, "the first runs along x");
        ck(o[1].d[0] == x1 && o[1].d[1] == y0, "the second carries on");
        ck(o[1].d[2] == x1 && o[1].d[3] == y1, "and runs along y");
        ck(o[2].d[0] == x1 && o[2].d[1] == y1, "the third carries on");
        ck(o[2].d[2] == x0 && o[2].d[3] == y1, "and comes back along x");
        ck(o[3].d[0] == x0 && o[3].d[1] == y1, "the fourth carries on");
        ck(o[3].d[2] == x0 && o[3].d[3] == y0, "and closes the box");
        ck(o[0].ltype == 1 && o[0].color == 2,
           "with CData's own line type and colour");
    }

    /* 連続線: it keeps one segment back.  Clicking n times in Jw_cad and
     * saving leaves n-2 lines behind -- two clicks none, four two, five three
     * (tmp/jwdraw.ps1 -Cmd 32883), and the coordinates come out as the points
     * in order, each line starting where the last one ended. */
    k = find_btn(0x8073);
    ck(k >= 0 && jw_btn_mode[k], "連続線 has a button and is a mode");
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x8073, "the command is now 連続線");
    d = app_drawing();
    before = d ? d->ndrawn : 0;
    app_press(300, 200, 0);
    app_press(500, 200, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before, "two clicks put nothing in yet");
    app_press(500, 330, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before + 1, "the third click puts the first in");
    app_press(360, 400, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before + 2, "and the fourth the second");
    if (d && d->ndrawn == before + 2) {
        const jw_obj *o = &d->obj[before];
        ck(o[0].cls == JW_SEN && o[1].cls == JW_SEN, "both are lines");
        ck(o[0].d[2] == o[1].d[0] && o[0].d[3] == o[1].d[1],
           "and the second carries on from the first");
        v = app_view();
        ck(abs(jw_sx(v, o[0].d[0]) - 300) <= 1
           && abs(jw_sy(v, o[0].d[1]) - 200) <= 1
           && abs(jw_sx(v, o[1].d[2]) - 500) <= 1
           && abs(jw_sy(v, o[1].d[3]) - 330) <= 1,
           "through the points that were clicked");
    }
    ck(app_move(300, 420) == 1, "and the next one follows the mouse");

    /* 消去: the right button takes the whole element out.  That is the
     * original's own line 10111 -- 「線・円マウス(L)部分消し　図形マウス(R)
     * 消去」 -- and driving Jw_cad bears it out: a right click on one side of
     * a rectangle leaves 49 lines of 50, and it is that side that goes.  The
     * left button starts a partial erase, which is not done here. */
    k = find_btn(0x801a);
    ck(k >= 0 && jw_btn_mode[k], "消去 has a button and is a mode");
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x801a, "the command is now 消去");
    d = app_drawing();
    before = d ? d->ndrawn : 0;
    {
        /* aim at the middle of the line the 連続線 above left behind */
        const jw_obj *o = &d->obj[before - 2];
        v = app_view();
        x = (jw_sx(v, o->d[0]) + jw_sx(v, o->d[2])) / 2;
        y = (jw_sy(v, o->d[1]) + jw_sy(v, o->d[3])) / 2;
    }
    app_press(x, y, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before, "the left button does not delete");
    app_press(x, y, 1);
    d = app_drawing();
    ck(d && d->ndrawn == before - 1, "the right button takes it out");
    ck(jw_cmd_can_undo(), "and that can be undone");
    {
        int u = find_btn(0xe12b), ux, uy;
        btn_mid(u, &ux, &uy);
        app_press(ux, uy, 0);
    }
    d = app_drawing();
    ck(d && d->ndrawn == before, "元に戻る puts it back");
    ck(d && d->obj[before - 2].cls == JW_SEN,
       "in the place it came from, so the drawing order is unchanged");

    /* and the left button takes a piece out of a line instead: three clicks,
     * one to pick it and two for the ends.  Driving Jw_cad with a line drawn
     * across the screen at y 300 and clicks at (400,300), (350,330),
     * (450,270) leaves two pieces, both ending on the line at the x of the
     * clicks -- so the two range points are dropped on to the line. */
    k = find_btn(0x8003);                       /* a line to cut */
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    d = app_drawing();
    before = d ? d->ndrawn : 0;
    app_press(250 + 78, 300 + 34, 0);
    app_press(600 + 78, 300 + 34, 0);
    d = app_drawing();
    ck(d && d->ndrawn == before + 1, "a line to cut");
    k = find_btn(0x801a);
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    app_press(400 + 78, 300 + 34, 0);           /* pick it */
    app_press(350 + 78, 330 + 34, 0);           /* one end, off the line */
    d = app_drawing();
    ck(d && d->ndrawn == before + 1, "two clicks do not cut anything yet");
    app_press(450 + 78, 270 + 34, 0);           /* the other end */
    d = app_drawing();
    ck(d && d->ndrawn == before + 2, "the third leaves two pieces");
    if (d && d->ndrawn == before + 2) {
        /* what Jw_cad itself left behind for the very same clicks, read out
           of the file it saved.  The port's view sits 78 across and 34 down
           from the original's drawing window, which is why the clicks above
           carry that offset; the paper millimetres then have to agree. */
        static const double want[2][4] = {
            { -263.230, 37.233, -176.641, 37.233 },
            {  -90.052, 37.233,   39.831, 37.233 }
        };
        const jw_obj *o = &d->obj[before];
        int a, e, same = 1;
        v = app_view();
        for (a = 0; a < 2; a++) {
            if (o[a].cls != JW_SEN)
                same = 0;
            for (e = 0; e < 4; e++)
                if (fabs(o[a].d[e] - want[a][e]) > 0.0005)
                    same = 0;
        }
        /* Those numbers are Test5's -- they depend on where the sheet sits
           on the screen.  With another drawing open, only the shape of the
           answer can be checked. */
        if (fabs(v->scale - 1.154882) < 1e-6)
            ck(same, "the two pieces are Jw_cad's own, to a thousandth of a mm");
        else
            ck(o[0].cls == JW_SEN && o[1].cls == JW_SEN
               && fabs(o[0].d[1] - o[0].d[3]) < 1e-9
               && fabs(o[1].d[1] - o[1].d[3]) < 1e-9,
               "two level pieces, both left on the line");
    }
    {
        int u = find_btn(0xe12b), ux, uy;
        btn_mid(u, &ux, &uy);
        app_press(ux, uy, 0);
    }
    d = app_drawing();
    ck(d && d->ndrawn == before + 1,
       "and one 元に戻る puts the whole line back");

    /* コーナー処理: two lines, cut or carried on to where they meet.  Both
     * cases below were driven through Jw_cad and the numbers are its own. */
    k = find_btn(0x8012);
    ck(k >= 0 && jw_btn_mode[k], "コーナー処理 has a button and is a mode");
    {
        static const double want[2][2][4] = {
            {   /* an L with a gap: both carry on to the corner */
                { -219.936, 123.822,  39.831, 123.822 },
                {   39.831, 123.822,  39.831, -135.945 }
            },
            {   /* two that cross: both cut back to the crossing */
                { -219.936, 123.822, -46.758, 123.822 },
                {  -46.758, 123.822, -46.758, -49.356 }
            }
        };
        static const int line[2][8] = {
            { 300, 200, 500, 200, 600, 300, 600, 500 },
            { 300, 200, 700, 200, 500, 100, 500, 400 }
        };
        static const int at[2][4] = {
            { 480, 200, 600, 320 },
            { 350, 200, 500, 350 }
        };
        int c;
        for (c = 0; c < 2; c++) {
            int a, e, same = 1;
            const jw_obj *o;
            jw_cmd_set(0x8003);
            d = app_drawing();
            before = d->ndrawn;
            app_press(line[c][0] + 78, line[c][1] + 34, 0);
            app_press(line[c][2] + 78, line[c][3] + 34, 0);
            app_press(line[c][4] + 78, line[c][5] + 34, 0);
            app_press(line[c][6] + 78, line[c][7] + 34, 0);
            btn_mid(k, &x, &y);
            app_press(x, y, 0);
            ck(jw_cmd() == 0x8012, "the command is now コーナー処理");
            app_press(at[c][0] + 78, at[c][1] + 34, 0);
            app_press(at[c][2] + 78, at[c][3] + 34, 0);
            d = app_drawing();
            ck(d->ndrawn == before + 2, "the two lines are changed, not remade");
            o = &d->obj[before];
            v = app_view();
            for (a = 0; a < 2; a++)
                for (e = 0; e < 4; e++)
                    if (fabs(o[a].d[e] - want[c][a][e]) > 0.0005)
                        same = 0;
            if (fabs(v->scale - 1.154882) < 1e-6)
                ck(same, c == 0 ? "carried on to the corner, as Jw_cad does"
                                : "cut back to the crossing, as Jw_cad does");
            else
                ck(o[0].d[2] == o[1].d[0] && o[0].d[3] == o[1].d[1],
                   "the two lines meet");
            {   /* and one press puts both back */
                int u = find_btn(0xe12b), ux, uy;
                btn_mid(u, &ux, &uy);
                app_press(ux, uy, 0);
                d = app_drawing();
                ck(d->obj[before].d[2] != d->obj[before + 1].d[0]
                   || d->obj[before].d[3] != d->obj[before + 1].d[1],
                   "元に戻る undoes the whole corner");
                app_press(ux, uy, 0);
                app_press(ux, uy, 0);
            }
        }
    }

    /* 線伸縮: pick a line, then say where its end should go.  Which end
     * moves is settled by that second point, not the first -- clicking the
     * left half and then a point near the right end moves the right end.
     * The three cases and their numbers are Jw_cad's own. */
    k = find_btn(0x8017);
    ck(k >= 0 && jw_btn_mode[k], "線伸縮 has a button and is a mode");
    {
        static const int go[3][4] = {
            { 550, 200, 700, 250 },     /* out past the right end   */
            { 350, 200, 250, 250 },     /* out past the left end    */
            { 350, 200, 550, 250 }      /* clicked left, aimed right */
        };
        static const double want[3][4] = {
            { -219.936, 123.822, 126.420, 123.822 },
            { -263.230, 123.822,  39.831, 123.822 },
            { -219.936, 123.822,  -3.464, 123.822 }
        };
        int c;
        for (c = 0; c < 3; c++) {
            int e, same = 1;
            const jw_obj *o;
            jw_cmd_set(0x8003);
            d = app_drawing();
            before = d->ndrawn;
            app_press(300 + 78, 200 + 34, 0);
            app_press(600 + 78, 200 + 34, 0);
            btn_mid(k, &x, &y);
            app_press(x, y, 0);
            app_press(go[c][0] + 78, go[c][1] + 34, 0);
            app_press(go[c][2] + 78, go[c][3] + 34, 0);
            d = app_drawing();
            ck(d->ndrawn == before + 1, "the line is changed, not remade");
            o = &d->obj[before];
            v = app_view();
            for (e = 0; e < 4; e++)
                if (fabs(o->d[e] - want[c][e]) > 0.0005)
                    same = 0;
            if (fabs(v->scale - 1.154882) < 1e-6)
                ck(same, "the end lands where Jw_cad puts it");
            else
                ck(o->d[1] == o->d[3], "the line stays level");
            {
                int u = find_btn(0xe12b), ux, uy;
                btn_mid(u, &ux, &uy);
                app_press(ux, uy, 0);   /* the stretch */
                app_press(ux, uy, 0);   /* and the line */
            }
        }
    }

    /* 複線: pick a line, say which side, then one more click to draw it.
     * The third click only confirms -- in Jw_cad moving it further out does
     * not move the copy.  The copy is a new element with the write pen on
     * the write layer, not a clone of the one it came from: offsetting a
     * dashed line on layer 0 of Test1 gave a plain one on layer 10, at
     * (-83.265,-9.324)-(-83.265,-174.452) -- which is what this port gives
     * for the same clicks. */
    k = find_btn(0x8020);
    ck(k >= 0 && jw_btn_mode[k], "複線 has a button and is a mode");
    jw_cmd_set(0x8003);
    d = app_drawing();
    before = d->ndrawn;
    app_press(300 + 78, 200 + 34, 0);
    app_press(600 + 78, 200 + 34, 0);
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    app_press(450 + 78, 200 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before + 1, "picking the line adds nothing");
    app_press(450 + 78, 260 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before + 1, "nor does saying which side");
    app_press(450 + 78, 400 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before + 2, "the third click draws it");
    if (d->ndrawn == before + 2) {
        const jw_obj *o = &d->obj[before + 1];
        v = app_view();
        ck(abs(jw_sy(v, o->d[1]) - (260 + 34)) <= 1
           && abs(jw_sy(v, o->d[3]) - (260 + 34)) <= 1,
           "and it lands where the second click said, not the third");
        ck(abs(jw_sx(v, o->d[0]) - (300 + 78)) <= 1
           && abs(jw_sx(v, o->d[2]) - (600 + 78)) <= 1,
           "as long as the line it came from");
        ck(o->ltype == 1 && o->color == 2,
           "with the write pen, not the one it was copied from");
    }
    {
        int u = find_btn(0xe12b), ux, uy;
        btn_mid(u, &ux, &uy);
        app_press(ux, uy, 0);
        app_press(ux, uy, 0);
    }

    /* 属性取得: take the pen and the layer off an element and give them to
     * whatever is drawn next.  The write pen is not in the file -- saving a
     * drawing with it set to line type 6 and opening that again gives 1
     * back, while the write layer, which is in the file, comes back as it
     * was -- so this is the only way to change it. */
    k = find_btn(0x80a3);
    ck(k >= 0 && !jw_btn_mode[k],
       "属性取得 has a button, and it is never drawn pressed");
    jw_cmd_set(0x8003);
    d = app_drawing();
    before = d->ndrawn;
    app_press(300 + 78, 200 + 34, 0);
    app_press(600 + 78, 200 + 34, 0);
    {   /* give that line a pen of its own to pick up */
        jw_obj *o = (jw_obj *)&d->obj[before];
        o->ltype = 6;
        o->color = 5;
    }
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x80a3, "the command is now 属性取得");
    app_press(450 + 78, 200 + 34, 0);
    jw_cmd_set(0x8003);
    app_press(300 + 78, 300 + 34, 0);
    app_press(600 + 78, 300 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before + 2, "a second line");
    if (d->ndrawn == before + 2) {
        const jw_obj *o = &d->obj[before + 1];
        ck(o->ltype == 6 && o->color == 5,
           "drawn with the pen taken off the first one");
        ck(o->layer == d->obj[before].layer
           && o->lgroup == d->obj[before].lgroup,
           "and on its layer");
    }
    {
        int u = find_btn(0xe12b), ux, uy;
        btn_mid(u, &ux, &uy);
        app_press(ux, uy, 0);
        app_press(ux, uy, 0);
    }

    /* 文字: type first, then click where it goes -- that is the order Jw_cad
     * wants (pressing Enter in its box places nothing).  Everything about
     * the text comes from the drawing's current style, which sits just after
     * the ten in the header.  Placing "ABCDEF" in Test5 gives Jw_cad
     * (-219.936,123.822)-(-159.936,123.822), colour 1, size 20, spacing 0,
     * style 0; in Test1 it gives (-155.510,87.551)-(-123.010,87.551),
     * colour 5, size 10, spacing 1, style 10.  The run is as long as the
     * characters make it: half width ones advance cw/2 with gaps of sp/2,
     * and the last gap is not counted. */
    k = find_btn(0x8026);
    ck(k >= 0 && jw_btn_mode[k], "文字 has a button and is a mode");
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(jw_cmd() == 0x8026, "the command is now 文字");
    d = app_drawing();
    before = d->ndrawn;
    app_press(300 + 78, 200 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before, "clicking with nothing typed places nothing");
    {
        const char *t = "ABCDEF";
        while (*t)
            app_key((unsigned char)*t++);
    }
    ck(app_move(500, 400) == 1, "and what is typed follows the mouse");
    app_press(300 + 78, 200 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before + 1, "the click places it");
    if (d->ndrawn == before + 1) {
        const jw_obj *o = &d->obj[before];
        v = app_view();
        ck(o->cls == JW_MOJI && o->d[6] == d->cur_style.sp
           && o->d[4] == d->cur_style.w && o->d[5] == d->cur_style.h
           && o->color == d->cur_style.color,
           "with the drawing's own text style");
        ck(fabs((o->d[2] - o->d[0])
                - (6 * d->cur_style.w / 2 + 5 * d->cur_style.sp / 2)) < 1e-9,
           "and a run as long as six half width characters make it");
        ck(abs(jw_sx(v, o->d[0]) - (300 + 78)) <= 1
           && abs(jw_sy(v, o->d[1]) - (200 + 34)) <= 1,
           "starting where it was clicked");
    }
    {
        int u = find_btn(0xe12b), ux, uy;
        btn_mid(u, &ux, &uy);
        app_press(ux, uy, 0);
    }

    /* 元に戻る is an action, not a mode: it runs and the command stays put */
    k = find_btn(0xe12b);
    ck(k >= 0 && !jw_btn_mode[k], "元に戻る is an action, not a mode");
    d = app_drawing();
    before = d->ndrawn;
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    d = app_drawing();
    ck(jw_cmd() == 0x8026, "pressing it leaves the command alone");
    ck(d->ndrawn == before - 1, "and takes the last command's line back out");
    ck(find_btn(0x8003) >= 0 && jw_btn_mode[find_btn(0x8003)],
       "線 on the other hand is a mode");

    /* 新規 starts an empty drawing, 開く asks the front end for a file */
    k = find_btn(57600);
    ck(k >= 0 && !jw_btn_mode[k], "新規 is an action");
    btn_mid(k, &x, &y);
    ck(app_press(x, y, 0) == 1, "pressing it is taken");
    d = app_drawing();
    ck(d && d->ndrawn == 0, "and the drawing is empty again");
    ck(d && d->paper_size == 2, "an A-2 one, as the reference screen shows");
    ck(!jw_cmd_can_undo(), "with nothing to undo");
    ck(d && d->cur_style.w == 3.5 && d->cur_style.h == 3.5
       && d->cur_style.sp == 0.0 && d->cur_style.color == 2,
       "and a text style to write with, the one 書式 reads on a new drawing");

    /* 消去's left button on a circle takes a piece out of it too, and by
     * angle alone -- the two range clicks can be well inside the circle and
     * cut it in exactly the same place.  A whole circle keeps one arc going
     * the long way round; a part of one splits.  Jw_cad's own answers:
     * cutting a circle between 90 and 180 degrees leaves 180 sweeping 270,
     * and cutting that again between 270 and 0 leaves 180+90 and 0+90. */
    jw_cmd_set(0x8005);
    d = app_drawing();
    before = d->ndrawn;
    app_press(400 + 78, 300 + 34, 0);
    app_press(500 + 78, 300 + 34, 0);
    jw_cmd_set(0x801a);
    app_press(500 + 78, 300 + 34, 0);
    app_press(400 + 78, 250 + 34, 0);       /* well inside the circle */
    app_press(350 + 78, 300 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before + 1, "a whole circle keeps one arc");
    if (d->ndrawn == before + 1) {
        const jw_obj *o = &d->obj[before];
        ck(fabs(o->d[3] - 3.14159265358979) < 1e-6
           && fabs(o->d[4] - 4.71238898038469) < 1e-6,
           "starting where the second click was, the long way round");
    }
    app_press(330 + 78, 371 + 34, 0);
    app_press(400 + 78, 400 + 34, 0);
    app_press(500 + 78, 300 + 34, 0);
    d = app_drawing();
    ck(d->ndrawn == before + 2, "cutting the middle out of an arc splits it");
    if (d->ndrawn == before + 2) {
        const jw_obj *o = &d->obj[before];
        ck(fabs(o[0].d[3] - 3.14159265358979) < 1e-6
           && fabs(o[0].d[4] - 1.57079632679490) < 1e-6
           && fabs(o[1].d[3]) < 1e-6
           && fabs(o[1].d[4] - 1.57079632679490) < 1e-6,
           "into the two halves Jw_cad leaves");
    }
    {
        int u = find_btn(0xe12b), ux, uy;
        btn_mid(u, &ux, &uy);
        app_press(ux, uy, 0);
        app_press(ux, uy, 0);
        app_press(ux, uy, 0);
    }

    k = find_btn(57601);
    ck(k >= 0 && !jw_btn_mode[k], "開く is an action too");
    btn_mid(k, &x, &y);
    app_press(x, y, 0);
    ck(app_take_action() == JW_ACT_OPEN, "and it asks for a file");
    ck(app_take_action() == JW_ACT_NONE, "once");

    app_paint();
    if (argc > 2)
        png_rgb(argv[2], app_fb()->w, app_fb()->h, app_fb()->px);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
