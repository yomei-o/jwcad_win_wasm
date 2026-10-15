/* 属性変更 (32952) の文字: (R) で文字を指すと書込みの文字種になる.
 *
 *   tests/zokumoji_test.exe
 *
 * 逆コンパイルの読み（CZukeiHenkou の 3 番 FUN_0067b890 の CDataMoji の枝と
 * FUN_0067adf0）、原典では押していない.  大きさ・間隔・色・縦字が変わり、
 * 文字は基点を据えたまま新しい長さに置き直される.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

static int fails;
static jw_drawing *d;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b) { return fabs(a - b) < 1e-9; }

/* "ABC" 2 wide and 2 tall, no spacing: its run is 3 */
static void text(double x, double y)
{
    jw_obj *o = jw_add(d, JW_MOJI);

    o->d[0] = x;
    o->d[1] = y;
    o->d[2] = x + 3.0;
    o->d[3] = y;
    o->d[4] = 2.0;
    o->d[5] = 2.0;
    o->d[6] = 0.0;
    o->n = 0;
    o->text = jw_add_str(d, "ABC");
}

static const jw_obj *last(void) { return &d->obj[d->ndrawn - 1]; }

static void setup(void)
{
    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    text(0.0, 0.0);
    app_fit();
    d->cur_style.w = 4.0;
    d->cur_style.h = 6.0;
    d->cur_style.sp = 1.0;
    d->cur_style.color = 5;
    jw_cmd_set(JW_CMD_ZOKUHEN);
}

int main(void)
{
    const jw_obj *o;
    int before;

    printf("基点 左下:\n");
    setup();
    jw_cmd_moji_base(2);                /* 左下 */
    before = d->ndrawn;
    jw_cmd_point(d, app_view(), 1.5, 1.0, 1);
    o = last();
    ck(d->ndrawn == before && o->cls == JW_MOJI, "  (R) takes the text, which goes to the end");
    ck(near(o->d[4], 4.0) && near(o->d[5], 6.0) && near(o->d[6], 1.0),
       "  and it takes the write size and spacing");
    ck(o->color == 5, "  and the write text colour");
    /* (4 + 1) / 2 * 3 - 1 / 2 */
    ck(near(o->d[0], 0.0) && near(o->d[1], 0.0) && near(o->d[2], 7.0)
       && near(o->d[3], 0.0), "  laid out again from the same bottom left");
    ck(!(o->flags & 0x20), "  縦字 off: not stacked");

    printf("基点 中中:\n");
    setup();
    jw_cmd_moji_base(4);                /* 中中 */
    jw_cmd_point(d, app_view(), 1.5, 1.0, 1);
    o = last();
    /* along (3 - 7) / 2, across (2 - 6) / 2 */
    ck(near(o->d[0], -2.0) && near(o->d[1], -2.0) && near(o->d[2], 5.0)
       && near(o->d[3], -2.0), "  the middle stays where it was");
    jw_cmd_moji_base(2);

    printf("縦字・線種文字種変更 off:\n");
    setup();
    jw_cmd_bar(d, 1325);
    ck(jw_cmd_bar_check(1325) > 0, "  縦字 ticks");
    jw_cmd_point(d, app_view(), 1.5, 1.0, 1);
    ck((last()->flags & 0x20) != 0, "  and the text comes back stacked");
    setup();
    jw_cmd_bar(d, 1352);
    jw_cmd_point(d, app_view(), 1.5, 1.0, 1);
    o = last();
    ck(near(o->d[4], 2.0) && near(o->d[2], 3.0), "  with 1352 off the size stays");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
