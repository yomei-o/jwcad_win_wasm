/* 指で叩く (LL)（app_ll_slop・app_ll_break）。
 *
 * 原典は (LL) を Windows の WM_LBUTTONDBLCLK で受け、２線 は (L) のあと
 * 2 画素動くまで待つ（src/app.c の ll_* の注、FUN_00629330・FUN_00624fa0）。
 * 指は二度叩いても同じ画素には落ちないので、ブラウザ（index.html）は
 * タッチのときだけ幅を広げ、間が空けば預かりを先に渡す。ここでは
 * ２線 で角を (LL) で回り、
 *   幅 2 で同じ画素に二度 ＝ 幅 16 で 6,5 ずれて二度（間に動きがあっても）
 *   幅 2 で 6,5 ずれて二度 ＝ 幅 16 でも間に app_ll_break を挟んだもの
 * で、前の二つと後の二つが違うことを見る。移植の都合（原典に指は無い）。
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void at(int x, int y)
{
    app_move(x, y);
    app_press(x, y, 0);
    app_release(x, y, 0);
}

typedef struct {
    int n;
    double sum;
} snap_t;

/* mv: 二度目の前に指が少し動く。brk: 二度目の前に app_ll_break */
static snap_t run(int slop, int dx, int dy, int mv, int brk)
{
    const jw_drawing *d;
    snap_t s;
    int i, k;

    app_ll_slop(slop);
    app_new();
    app_fit();
    d = app_drawing();
    app_command(JW_CMD_SEN);
    at(200, 300);
    at(700, 300);                       /* 横の線 */
    at(600, 100);
    at(600, 550);                       /* 縦の線 */
    app_command(JW_CMD_NISEN);
    at(300, 300);                       /* 基準線: 横 */
    at(250, 300);                       /* 始点 */
    app_move(600, 200);
    app_press(600, 200, 0);             /* 縦の線の上で一度目 */
    app_release(600, 200, 0);
    if (mv)
        app_move(600 + dx / 2, 200 + dy / 2);
    if (brk)
        app_ll_break();
    app_press(600 + dx, 200 + dy, 0);   /* 二度目 */
    app_release(600 + dx, 200 + dy, 0);
    app_move(600, 420);
    at(600, 450);                       /* 終点 */
    app_move(400, 200);
    app_move(380, 180);
    s.n = d->ndrawn;
    s.sum = 0;
    for (i = 0; i < d->ndrawn; i++)
        for (k = 0; k < 4; k++)
            s.sum += d->obj[i].d[k] * (i + 1) * (k + 1);
    app_ll_slop(0);
    return s;
}

static int same(snap_t a, snap_t b)
{
    return a.n == b.n && fabs(a.sum - b.sum) < 1e-6;
}

int main(void)
{
    snap_t ll, ll16, ll16m, two, brk;

    app_resize(1264, 741);
    ll = run(2, 0, 0, 0, 0);
    ll16 = run(16, 6, 5, 0, 0);
    ll16m = run(16, 6, 5, 1, 0);
    two = run(2, 6, 5, 0, 0);
    brk = run(16, 6, 5, 0, 1);
    printf("     (LL) %d 本 %.3f / 幅16 %d %.3f / 動き %d %.3f / 二つの(L) %d %.3f / break %d %.3f\n",
           ll.n, ll.sum, ll16.n, ll16.sum, ll16m.n, ll16m.sum, two.n, two.sum, brk.n, brk.sum);
    ck(ll.n >= 4, "線二本と２線が描けた");
    ck(same(ll, ll16), "幅 16 なら 6,5 ずれた二度も (LL)");
    ck(same(ll, ll16m), "  間に 4 画素ほど動いても (LL)");
    ck(!same(ll, two), "幅 2 では 6,5 ずれた二度は (L) 二つ（ちがう図になる）");
    ck(same(two, brk), "幅 16 でも app_ll_break を挟めば (L) 二つ");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
