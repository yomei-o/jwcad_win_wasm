/* 指の判定（src/touchgest.h、ネイティブの WM_POINTER のタッチ）。
 *
 * 原典にタッチは無い。答えは index.html の指の作法（一本で動かして離すと
 * クリック・長押しで右、二本でパン・ピンチ・ちょんで右・長押しで両ボタン、
 * 指の (LL) の幅と間）から出したもの。
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define TOUCHGEST_IMPL
#include "../src/touchgest.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int hold_ok = 1;
static int holdable(int x, int y)
{
    return hold_ok;
}

static void fresh(tg_t *g)
{
    memset(g, 0, sizeof *g);
    g->holdable = holdable;
}

static int has(tg_t *g, int kind)
{
    int i;

    for (i = 0; i < g->nev; i++)
        if (g->ev[i].kind == kind)
            return i + 1;
    return 0;
}

int main(void)
{
    tg_t g;
    int i;

    /* 一本: 触れて動かすと app_move、離した所でクリック */
    fresh(&g);
    tg_down(&g, 7, 100, 100, 1000);
    ck(g.nev == 1 && g.ev[0].kind == TG_MOVE && g.ev[0].x == 100, "一本 触れると app_move");
    tg_move(&g, 7, 140, 120, 1100);
    ck(g.nev == 1 && g.ev[0].kind == TG_MOVE && g.ev[0].x == 140 && g.ev[0].y == 120, "一本 動かすと app_move");
    tg_up(&g, 7, 150, 125, 1200);
    ck(g.nev == 1 && g.ev[0].kind == TG_CLICK && g.ev[0].x == 150 && g.ev[0].y == 125,
       "一本 離した所でクリック");
    ck(g.ev[0].brk == 1, "初めての指のクリックは (L) を先に渡す");
    /* 続けて 500ms 以内: (LL) にできるよう break しない。空けば break */
    tg_down(&g, 8, 152, 126, 1400);
    tg_up(&g, 8, 152, 126, 1450);
    ck(g.nev == 1 && g.ev[0].kind == TG_CLICK && g.ev[0].brk == 0, "500ms 以内の二度目は break しない");
    tg_down(&g, 9, 152, 126, 2000);
    tg_up(&g, 9, 152, 126, 2100);
    ck(g.ev[0].kind == TG_CLICK && g.ev[0].brk == 1, "間が空けば break");
    ck(tg_mouse(&g) == 1 && tg_mouse(&g) == 0, "マウスに戻ると一度だけ幅を戻す");

    /* 一本の長押し: 右。動きすぎればクリック */
    fresh(&g);
    tg_down(&g, 1, 50, 60, 0);
    tg_move(&g, 1, 55, 64, 300);
    tg_up(&g, 1, 55, 64, 600);
    ck(g.nev == 1 && g.ev[0].kind == TG_RIGHT && g.ev[0].x == 55, "一本 長押し（動き 12 未満）は右");
    tg_down(&g, 1, 50, 60, 1000);
    tg_up(&g, 1, 50, 60, 1500);
    ck(g.ev[0].kind == TG_CLICK, "一本 550ms 以内はクリック");
    tg_down(&g, 1, 50, 60, 2000);
    tg_move(&g, 1, 70, 60, 2300);
    tg_up(&g, 1, 70, 60, 2700);
    ck(g.ev[0].kind == TG_CLICK, "一本 長くても動けばクリック");

    /* 二本ちょん: 中点で右 */
    fresh(&g);
    tg_down(&g, 1, 100, 100, 0);
    tg_down(&g, 2, 200, 100, 20);
    ck(has(&g, TG_TIMER) && g.ev[has(&g, TG_TIMER) - 1].t == TG_HOLD, "二本目で長押しの時計を頼む");
    tg_up(&g, 1, 100, 100, 200);
    ck(g.nev == 0, "一本離してもまだ何もしない");
    tg_up(&g, 2, 200, 100, 250);
    ck(g.nev == 1 && g.ev[0].kind == TG_RIGHT && g.ev[0].x == 150 && g.ev[0].y == 100, "二本ちょんは中点で右");
    tg_tick(&g, 570);
    ck(g.nev == 0, "離したあとの時計は何もしない");
    /* 二本 動かさず 500ms より長く置いて離す（両ボタンなし）: 何もしない */
    g.holdable = NULL;
    tg_down(&g, 1, 100, 100, 1000);
    tg_down(&g, 2, 200, 100, 1000);
    tg_up(&g, 1, 100, 100, 1600);
    tg_up(&g, 2, 200, 100, 1600);
    ck(g.nev == 0, "二本 ゆっくり離すと右にしない");

    /* 二本でパン */
    fresh(&g);
    tg_down(&g, 1, 100, 100, 0);
    tg_down(&g, 2, 200, 100, 0);
    tg_move(&g, 1, 103, 100, 10);
    ck(g.nev == 0, "二本 少しの動きは何もしない");
    tg_move(&g, 2, 213, 100, 20);      /* 中点 150 → 158 */
    ck(g.nev >= 1 && g.ev[0].kind == TG_PAN && g.ev[0].x == 8 && g.ev[0].y == 0, "二本 中点が動くとパン");
    {
        int sx = 8;
        for (i = 0; i < 10; i++) {
            tg_move(&g, 1, 104 + i, 100 + i, 30 + i);
            if (has(&g, TG_PAN))
                sx += g.ev[has(&g, TG_PAN) - 1].x;
        }
        /* 最後の中点 (113+213)/2 = 163 */
        ck(sx == 13, "パンの差を足すと中点の動きに等しい（端数を貯めない）");
    }
    tg_tick(&g, 600);
    ck(g.nev == 0, "動いたあとは長押しにならない");
    tg_up(&g, 1, 113, 109, 700);
    tg_up(&g, 2, 213, 100, 700);
    ck(g.nev == 0, "動いた二本を離しても右にしない");

    /* ピンチ: 間の比で拡大、中心は中点 */
    fresh(&g);
    tg_down(&g, 1, 100, 100, 0);
    tg_down(&g, 2, 200, 100, 0);
    tg_move(&g, 1, 50, 100, 10);       /* 間 100 → 150、中点 150 → 125 */
    i = has(&g, TG_ZOOM);
    ck(i && fabs(g.ev[i - 1].f - 1.5) < 1e-9 && g.ev[i - 1].x == 125 && g.ev[i - 1].y == 100,
       "ピンチで 1.5 倍、中心は中点");
    tg_move(&g, 2, 250, 100, 20);      /* 間 150 → 200 */
    i = has(&g, TG_ZOOM);
    ck(i && fabs(g.ev[i - 1].f - 200.0 / 150.0) < 1e-9, "続けてのピンチは前からの比");
    tg_move(&g, 2, 251, 100, 30);      /* 間 200 → 201: 1% 未満 */
    ck(!has(&g, TG_ZOOM), "1% 未満の比は拡大しない");

    /* 二本の長押し: 両ボタンドラッグ */
    fresh(&g);
    tg_down(&g, 1, 100, 100, 0);
    tg_down(&g, 2, 200, 100, 0);
    tg_tick(&g, 550);
    ck(g.nev == 1 && g.ev[0].kind == TG_RYO_BEGIN && g.ev[0].x == 150 && g.ev[0].y == 100,
       "二本 長押しで両ボタン（中点が起点）");
    tg_move(&g, 1, 140, 150, 600);
    tg_move(&g, 2, 240, 150, 610);
    ck(g.nev == 1 && g.ev[0].kind == TG_RYO_MOVE && g.ev[0].x == 190 && g.ev[0].y == 150,
       "両ボタンの間はパンせず ryo_move（中点）");
    tg_up(&g, 1, 140, 150, 700);
    ck(g.nev == 0, "一本離してもまだ");
    tg_up(&g, 2, 240, 150, 720);
    ck(g.nev == 1 && g.ev[0].kind == TG_RYO_END, "全部離すと ryo_end");
    /* 図面の外（holdable が 0）では両ボタンにしない */
    hold_ok = 0;
    tg_down(&g, 1, 100, 100, 1000);
    tg_down(&g, 2, 200, 100, 1000);
    tg_tick(&g, 1550);
    ck(g.nev == 0, "holdable でなければ両ボタンにしない");
    tg_up(&g, 1, 100, 100, 1600);
    tg_up(&g, 2, 200, 100, 1600);
    ck(g.nev == 0, "そのまま離しても右にしない（500ms 過ぎ）");
    hold_ok = 1;
    /* 取り消し */
    tg_down(&g, 1, 100, 100, 2000);
    tg_down(&g, 2, 200, 100, 2000);
    tg_tick(&g, 2550);
    tg_cancel(&g);
    ck(g.nev == 1 && g.ev[0].kind == TG_RYO_CANCEL && g.n == 0, "取り消しで ryo_cancel");
    /* 古い時計（一度離して付け直した二本）は効かない */
    tg_down(&g, 1, 100, 100, 3000);
    tg_down(&g, 2, 200, 100, 3000);
    tg_up(&g, 1, 100, 100, 3100);
    tg_down(&g, 3, 100, 100, 3200);    /* また二本: 新しい手（index.html も同じ） */
    ck(g.n == 2 && has(&g, TG_TIMER), "また二本になれば手をやり直す");
    tg_up(&g, 2, 200, 100, 3300);
    tg_up(&g, 3, 100, 100, 3300);
    ck(g.nev == 1 && g.ev[0].kind == TG_RIGHT, "やり直した手のちょんは右");
    tg_down(&g, 4, 100, 100, 3400);
    tg_tick(&g, 3550);
    ck(g.nev == 0, "一本だけのときの時計は何もしない");
    tg_up(&g, 4, 100, 100, 3450);
    ck(g.nev == 1 && g.ev[0].kind == TG_CLICK, "そのあとの一本はクリック");

    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
