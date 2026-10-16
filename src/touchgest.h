/* 指の判定（ネイティブの WM_POINTER のタッチ）。
 *
 * 原典にタッチの扱いは無い。これは移植の都合で、ブラウザ版（index.html の
 * pointerdown／pointermove／pointerup の pointerType 'touch' の枝）と同じ
 * 作法をネイティブにも持たせるためのもの:
 *
 *   一本指   触れて動かすと app_move（ゴム紐が指について来る）、離した所で
 *            クリック（左）。TG_HOLD より長く・TG_HOLD_MOVE 未満の動きで
 *            離せば右ボタン
 *   二本指   動かすとパン（中点の動き）とピンチ（指の間の比で拡大縮小、
 *            中点が中心）。動かさずに TG_TAP_TIME 未満で全部離すと右ボタン
 *            （中点で）。動かさずに TG_HOLD 押したままなら両ボタンドラッグ
 *            （ryo_*、src/ryoboton.h）、そのまま二本で動かして向きを選び、
 *            全部離すと判定どおり
 *   (LL)     指で叩くと「2 画素以内に二度」は出ないので、指のクリックは
 *            app_ll_slop を TG_TAP_SLOP に広げ、前の指のクリックから
 *            TG_TAP_TIME（Windows の既定のダブルクリック時間）より空いたら
 *            先に app_ll_break。マウスに戻ったら 2 に戻す
 *
 * 座標は app の画素（main_win32.c の MX と同じく uiscale で割ったもの）、
 * 時刻はミリ秒。判定だけをここに置き、Windows にも app にも触らない
 * （tests/touchgest_test.c がそのまま試す）。呼ぶと ev[] に、表側がする
 * ことを順に積む（呼ぶたびに空にしてから）。
 *
 * 作りは stb 流: 中身は TOUCHGEST_IMPL を立てて include した所にある。 */
#ifndef JW_TOUCHGEST_H
#define JW_TOUCHGEST_H

#define TG_TAP_SLOP 16      /* 指の (LL) の幅（index.html の TAP_SLOP） */
#define TG_TAP_TIME 500     /* 二本ちょん・(LL) の間（TAP_TIME） */
#define TG_HOLD 550         /* 長押し（TAP_HOLD） */
#define TG_HOLD_MOVE 12     /* 一本の長押しで許す動き */
#define TG_PAN_SLOP 6       /* 二本の中点がこれより動けば「動いた」 */
#define TG_PINCH_SLOP 10    /* 指の間がこれより変われば「動いた」 */
#define TG_MAXEV 8

enum {
    TG_MOVE = 1,        /* app_move(x, y) */
    TG_CLICK,           /* 指の左クリック: app_ll_slop(TG_TAP_SLOP)、brk なら
                           app_ll_break、app_press(x, y, 0) */
    TG_RIGHT,           /* app_press(x, y, 1) */
    TG_PAN,             /* app_pan(x, y)（x, y は差） */
    TG_ZOOM,            /* app_zoom(f, x, y) */
    TG_RYO_BEGIN,       /* ryo_begin(x, y)（holdable は済んでいる） */
    TG_RYO_MOVE,        /* ryo_move(x, y) */
    TG_RYO_END,         /* ryo_end() */
    TG_RYO_CANCEL,      /* ryo_cancel() */
    TG_TIMER            /* t ミリ秒後に tg_tick を呼んでほしい */
};

typedef struct {
    int kind, x, y, brk, t;
    double f;
} tg_ev_t;

typedef struct {
    int id, x, y, x0, y0;
    long t0;
} tg_finger_t;

typedef struct {
    tg_finger_t f[4];
    int n;
    /* 二本の手: on、動いたか、両ボタンか、始めた時刻、いまの中点と間 */
    int g_on, g_moved, g_ryo, g_seq;
    long g_t;
    double g_cx, g_cy, g_d;
    int g_px, g_py;     /* パンで渡し済みの中点（整数で、端数を貯めないように） */
    int armed;          /* 長押しの時計を待っている g_seq */
    long last_tap;      /* 前の指のクリック（0 はまだ） */
    int touched;        /* 指で叩いた（マウスに戻ったら幅を戻す） */
    int (*holdable)(int x, int y);  /* ryo_holdable（NULL なら両ボタンなし） */
    tg_ev_t ev[TG_MAXEV];
    int nev;
} tg_t;

void tg_down(tg_t *g, int id, int x, int y, long t);
void tg_move(tg_t *g, int id, int x, int y, long t);
void tg_up(tg_t *g, int id, int x, int y, long t);
/* 指が取り上げられた（WM_POINTERCAPTURECHANGED・取り消し）: 全部やめる */
void tg_cancel(tg_t *g);
/* TG_TIMER で頼まれた時計が来た */
void tg_tick(tg_t *g, long t);
/* マウスに戻った: 指で広げた (LL) の幅を戻すなら 1 */
int  tg_mouse(tg_t *g);

#endif

#ifdef TOUCHGEST_IMPL
#undef TOUCHGEST_IMPL

#include <math.h>

static void tg_emit(tg_t *g, int kind, int x, int y)
{
    tg_ev_t *e;

    if (g->nev >= TG_MAXEV)
        return;
    e = &g->ev[g->nev++];
    e->kind = kind;
    e->x = x;
    e->y = y;
    e->brk = 0;
    e->t = 0;
    e->f = 1.0;
}

static int tg_find(tg_t *g, int id)
{
    int i;

    for (i = 0; i < g->n; i++)
        if (g->f[i].id == id)
            return i;
    return -1;
}

static int tg_round(double v)
{
    return (int)floor(v + 0.5);
}

/* 初めの二本の中点と間（index.html の touchPair） */
static void tg_pair(tg_t *g, double *cx, double *cy, double *d)
{
    double dx = g->f[0].x - g->f[1].x, dy = g->f[0].y - g->f[1].y;

    *cx = (g->f[0].x + g->f[1].x) / 2.0;
    *cy = (g->f[0].y + g->f[1].y) / 2.0;
    *d = sqrt(dx * dx + dy * dy);
    if (*d == 0.0)
        *d = 1.0;
}

void tg_down(tg_t *g, int id, int x, int y, long t)
{
    tg_finger_t *f;

    g->nev = 0;
    if (tg_find(g, id) >= 0 || g->n >= 4)
        return;
    f = &g->f[g->n++];
    f->id = id;
    f->x = f->x0 = x;
    f->y = f->y0 = y;
    f->t0 = t;
    if (g->n == 2) {
        g->g_on = 1;
        g->g_moved = 0;
        g->g_ryo = 0;
        g->g_t = t;
        g->g_seq++;
        tg_pair(g, &g->g_cx, &g->g_cy, &g->g_d);
        g->g_px = tg_round(g->g_cx);
        g->g_py = tg_round(g->g_cy);
        if (g->holdable) {
            g->armed = g->g_seq;
            tg_emit(g, TG_TIMER, 0, 0);
            g->ev[g->nev - 1].t = TG_HOLD;
        }
    } else if (g->n == 1)
        tg_emit(g, TG_MOVE, x, y);
}

void tg_tick(tg_t *g, long t)
{
    double cx, cy, d;
    int seq = g->armed;

    g->nev = 0;
    g->armed = 0;
    if (!seq || !g->g_on || seq != g->g_seq || g->g_moved || g->n != 2 || !g->holdable)
        return;
    tg_pair(g, &cx, &cy, &d);
    if (!g->holdable(tg_round(cx), tg_round(cy)))
        return;
    g->g_ryo = 1;
    tg_emit(g, TG_RYO_BEGIN, tg_round(cx), tg_round(cy));
}

void tg_move(tg_t *g, int id, int x, int y, long t)
{
    int i = tg_find(g, id);
    double cx, cy, d;

    g->nev = 0;
    if (i < 0)
        return;
    g->f[i].x = x;
    g->f[i].y = y;
    if (g->g_on && g->g_ryo) {
        if (g->n >= 2) {
            tg_pair(g, &cx, &cy, &d);
            tg_emit(g, TG_RYO_MOVE, tg_round(cx), tg_round(cy));
        }
    } else if (g->g_on && g->n >= 2) {
        tg_pair(g, &cx, &cy, &d);
        if (fabs(cx - g->g_cx) > TG_PAN_SLOP || fabs(cy - g->g_cy) > TG_PAN_SLOP
            || fabs(d - g->g_d) > TG_PINCH_SLOP)
            g->g_moved = 1;
        if (g->g_moved) {
            int px = tg_round(cx), py = tg_round(cy);

            if (px != g->g_px || py != g->g_py)
                tg_emit(g, TG_PAN, px - g->g_px, py - g->g_py);
            if (fabs(d / g->g_d - 1.0) > 0.01) {
                tg_emit(g, TG_ZOOM, px, py);
                g->ev[g->nev - 1].f = d / g->g_d;
                g->g_d = d;
            }
            g->g_px = px;
            g->g_py = py;
            g->g_cx = cx;
            g->g_cy = cy;
        }
    } else if (!g->g_on)
        tg_emit(g, TG_MOVE, x, y);
}

void tg_up(tg_t *g, int id, int x, int y, long t)
{
    int i = tg_find(g, id), had = g->n;
    tg_finger_t f;

    g->nev = 0;
    if (i < 0)
        return;
    f = g->f[i];
    f.x = x;
    f.y = y;
    for (; i + 1 < g->n; i++)
        g->f[i] = g->f[i + 1];
    g->n--;
    if (g->g_on) {
        if (g->n == 0) {
            g->g_on = 0;
            g->armed = 0;
            if (g->g_ryo)
                tg_emit(g, TG_RYO_END, 0, 0);
            else if (!g->g_moved && t - g->g_t < TG_TAP_TIME)
                tg_emit(g, TG_RIGHT, tg_round(g->g_cx), tg_round(g->g_cy));
            g->g_ryo = 0;
        }
        return;
    }
    if (had == 1) {
        double dx = f.x - f.x0, dy = f.y - f.y0;

        if (t - f.t0 > TG_HOLD && sqrt(dx * dx + dy * dy) < TG_HOLD_MOVE)
            tg_emit(g, TG_RIGHT, x, y);
        else {
            tg_emit(g, TG_CLICK, x, y);
            g->ev[g->nev - 1].brk = !g->last_tap || t - g->last_tap > TG_TAP_TIME;
            g->last_tap = t;
            g->touched = 1;
        }
    }
}

void tg_cancel(tg_t *g)
{
    g->nev = 0;
    if (g->g_on && g->g_ryo)
        tg_emit(g, TG_RYO_CANCEL, 0, 0);
    g->n = 0;
    g->g_on = g->g_ryo = 0;
    g->armed = 0;
}

int tg_mouse(tg_t *g)
{
    int r = g->touched;

    g->touched = 0;
    g->last_tap = 0;
    return r;
}

#endif
