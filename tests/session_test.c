/* A whole session, the way someone would use it.
 *
 *   tests/session_test.exe [out.jww]
 *
 * New drawing, pick a pen, draw a line, a rectangle, a circle and a point,
 * write some text, put a dimension on the line, copy the lot, erase one of
 * the copies, save.  Nothing here is new ground -- every command has its own
 * test -- but the commands have never been run one after another before, and
 * the file that comes out is one Jw_cad can be asked to open (tools/jwopen.ps1
 * does that; RESUME.md says how the round trip is checked).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/layout.h"
#include "../src/gen/cmds.h"
#include "../src/gen/zoku.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void btn(int cmd)
{
    int k;

    for (k = 0; k < JW_NBUTTONS; k++)
        if (jw_btn_cmd[k] == cmd) {
            app_press(jw_buttons[k].x + BTN_W / 2,
                      jw_buttons[k].y + BTN_H / 2, 0);
            return;
        }
    printf("BAD  no button for %d\n", cmd);
    fails++;
}

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

static int count(int cls)
{
    const jw_drawing *d = app_drawing();
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == cls)
            n++;
    return n;
}

int main(int argc, char **argv)
{
    const jw_drawing *d;
    unsigned char *out;
    long n;
    int x, y, before;

    app_resize(1264, 741);
    app_new();
    d = app_drawing();
    ck(d && d->ndrawn == 0, "a new drawing, with nothing in it");

    /* a pen out of the 線属性 dialog: 線色 4, 点線 1 */
    btn(0x8027);
    ck(app_zoku_open(), "線属性 puts its dialog up");
    ctl(1404, &x, &y);
    app_press(x, y, 0);
    ctl(2450, &x, &y);
    app_press(x, y, 0);
    ctl(1, &x, &y);
    app_press(x, y, 0);
    ck(!app_zoku_open() && d->write_color == 4 && d->write_ltype == 2,
       "and picking in it sets the pen");

    /* 線 */
    btn(0x8003);
    app_press(300, 200, 0);
    app_press(700, 200, 0);
    ck(count(JW_SEN) == 1, "a line");
    ck(d->obj[0].color == 4 && d->obj[0].ltype == 2, "in that pen");

    /* 矩形 */
    btn(0x8004);
    app_press(300, 300, 0);
    app_press(700, 500, 0);
    ck(count(JW_SEN) == 5, "a rectangle, which is four more lines");

    /* 円 */
    btn(0x8005);
    app_press(900, 300, 0);
    app_press(960, 300, 0);
    ck(count(JW_ENKO) == 1, "a circle");

    /* 点 */
    btn(0x8011);
    app_press(900, 500, 0);
    ck(count(JW_TEN) == 1, "a point");

    /* 文字 */
    btn(0x8026);
    app_key('J');
    app_key('w');
    app_key('_');
    app_key('c');
    app_key('a');
    app_key('d');
    app_press(400, 600, 0);
    ck(count(JW_MOJI) == 1, "some text");

    /* 寸法 on the first line's two ends */
    btn(0x804f);
    app_move(300, 150);
    app_press(300, 150, 0);             /* 引出し線の始点 */
    app_press(300, 120, 0);             /* 寸法線の位置   */
    before = d->ndrawn;
    app_press(300, 200, 0);             /* reads the line's left end  */
    app_press(700, 200, 0);             /* and its right end          */
    ck(d->ndrawn == before + 6, "a dimension, which is six elements");

    /* 範囲選択 over everything, then 複写 */
    btn(0x8024);
    app_move(200, 100);
    app_press(200, 100, 0);
    app_move(1000, 700);
    app_press(1000, 700, 1);            /* (R): the text comes too */
    ck(jw_cmd_sel_count(d) > 0, "a range with something in it");
    {
        int picked = jw_cmd_sel_count(d);
        before = d->ndrawn;
        app_move(400, 300);
        app_press(491 + 44, 5 + 12, 0); /* 選択確定 on the bar */
        app_move(400, 400);
        app_press(400, 400, 0);
        printf("     picked %d, before %d, after %d\n",
               picked, before, d->ndrawn);
        ck(d->ndrawn == before + picked && picked > 1,
           "and a copy of all of it");
    }

    /* 消去: the right button takes one element out */
    btn(0x801a);
    before = d->ndrawn;
    app_press(960, 400, 1);             /* the edge of the copied circle */
    ck(d->ndrawn == before - 1, "消去 takes one back out");

    /* and it all saves */
    ck(app_save(&out, &n) && n > 0, "the drawing saves");
    if (out) {
        jw_drawing back;
        ck(jw_parse(&back, out, n), "and reads back");
        ck(back.ndrawn == d->ndrawn, "with the same elements in it");
        jw_free(&back);
        if (argc > 1) {
            FILE *f = fopen(argv[1], "wb");
            if (f) {
                fwrite(out, 1, (size_t)n, f);
                fclose(f);
                printf("     wrote %s, %ld bytes, %d elements\n",
                       argv[1], n, d->ndrawn);
            }
        }
        free(out);
    }

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
