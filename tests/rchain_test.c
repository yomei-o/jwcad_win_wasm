/* 範囲選択とハッチの範囲選択で、始点の前の (R) が連続線を拾う.
 *
 *   tests/rchain_test.exe
 *
 * 逆コンパイルの読み（CZukeiSentaku の 11 番 FUN_006fda70 → FUN_0040deb0 →
 * FUN_0040f830）、原典では押していない.  端点が 1e-6 未満で合う線・円弧を
 * たどり、分岐はデータ順で先のもの、閉じた輪で止まり、行き止まりなら逆向き
 * にもう一度.  全円は始まらない.  曲線属性の付いたものは組ごと.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

#define PI_2_TEST 1.5707963267948966

static int fails;
static jw_drawing *d;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void at(double x, double y, int b) { jw_cmd_point(d, app_view(), x, y, b); }

static int line(double a, double b, double c, double e)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = a;
    o->d[1] = b;
    o->d[2] = c;
    o->d[3] = e;
    return (int)(o - d->obj);
}

static int arc(double cx, double cy, double r, double a0, double sweep)
{
    jw_obj *o = jw_add(d, JW_ENKO);

    o->d[0] = cx;
    o->d[1] = cy;
    o->d[2] = r;
    o->d[3] = a0;
    o->d[4] = sweep;
    o->d[5] = 0.0;
    o->d[6] = 1.0;
    return (int)(o - d->obj);
}

static int picked(int i) { return d->obj[i].sel && (d->obj[i].flags & 2u); }

static void fresh(void)
{
    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
}

/* an open run of lines and an arc, ends either way round */
static void open_run(void)
{
    int l1, l2, a, l3, l4, l5, l6;

    printf("an open run:\n");
    fresh();
    l1 = line(0, 0, 10, 0);
    l2 = line(20, 0, 10, 0);                    /* the other way round */
    a = arc(20, 10, 10, -PI_2_TEST, PI_2_TEST); /* (20,0) to (30,10) */
    l3 = line(30, 10, 30, 30);
    l4 = line(50, 50, 60, 60);                  /* on its own */
    l5 = line(-10, 0, 0, 0.00001);              /* 1e-5 off: not joined */
    l6 = line(30, 30, 40, 30);
    d->obj[l6].flags |= 0x20;                   /* a hatch's line: not followed */
    app_fit();
    jw_cmd_set(JW_CMD_HANI);
    at(15, 0, 1);
    ck(picked(l1) && picked(l2) && picked(a) && picked(l3),
       "  (R) on one line takes the lines and the arc joined to it");
    ck(!picked(l4) && !picked(l5) && !picked(l6),
       "  and nothing else (1e-5 off, apart, ハッチ属性)");
    ck(jw_cmd_sel_stage() == 2, "  and goes on to the stage after the box");
    ck(jw_cmd_sel_count(d) == 4, "  four picked");

    jw_cmd_set(JW_CMD_HANI);
    at(55, 55, 1);
    ck(picked(l4) && jw_cmd_sel_count(d) == 1,
       "  (R) again at the start drops the last pick and takes the lone line");
}

/* a closed ring stops where it began; a T goes the first way in the data */
static void ring_and_branch(void)
{
    int r[4], a, b, c, k, circ, n0;

    printf("a ring, a branch, a circle:\n");
    fresh();
    r[0] = line(0, 0, 100, 0);
    r[1] = line(100, 0, 100, 50);
    r[2] = line(0, 50, 100, 50);
    r[3] = line(0, 0, 0, 50);
    a = line(200, 0, 210, 0);
    b = line(210, 0, 220, 0);
    c = line(210, 0, 210, 10);
    circ = arc(300, 0, 10, 0.0, 0.0);
    app_fit();
    jw_cmd_set(JW_CMD_HANI);
    at(50, 0, 1);
    for (k = 0; k < 4 && picked(r[k]); k++)
        ;
    ck(k == 4 && jw_cmd_sel_count(d) == 4, "  a rectangle comes whole");

    jw_cmd_set(JW_CMD_HANI);
    at(205, 0, 1);
    ck(picked(a) && picked(b) && !picked(c),
       "  at a T the one first in the drawing goes on");

    n0 = jw_cmd_sel_count(d);
    jw_cmd_set(JW_CMD_HANI);
    at(310, 0, 1);
    ck(jw_cmd_sel_stage() == 0 && !picked(circ) && jw_cmd_sel_count(d) == n0,
       "  a whole circle has no ends: nothing starts, nothing is dropped");
}

/* ハッチ's 範囲選択: (R) on a side takes the ring, and the hatch draws */
static void hatch_ring(void)
{
    int before;

    printf("ハッチ:\n");
    fresh();
    line(0, 0, 60, 0);
    line(60, 60, 60, 0);
    line(60, 60, 0, 60);
    line(0, 0, 0, 60);
    app_fit();
    before = d->ndrawn;
    jw_cmd_set(JW_CMD_HATCH);
    ck(jw_cmd_bar(d, 1067) == 1, "  範囲選択 can be pressed");
    at(30, 60, 1);
    ck(jw_cmd_sel_count(d) == 4, "  (R) on a side takes the four");
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 can be pressed");
    ck(jw_cmd_bar(d, 1148) == 1 && d->ndrawn > before, "  実行 lays lines");
}

int main(void)
{
    open_run();
    ring_and_branch();
    hatch_ring();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
