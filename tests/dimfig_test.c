/* 寸法設定 の 寸法図形（2424）: ふつうの寸法を 寸法図形（CDataSunpou）一つに。
 *
 *   tests/dimfig_test.exe
 *
 * 根拠は逆コンパイルの読み（src/cmd.c の sun_fig_close の注）と原典の答え
 * decomp/res/p169_dimfig.jww（寸法図形化 したもの、tools/probe169.sh）:
 *
 *   FUN_00783730  bda0 なら 寸法線を足さず CDataSunpou の +0x68 に写し、
 *                 値の段で 字を +0xd0 に書いて 図形一つとして足す。
 *                 点・引出線 は ふつうに その前。部品 3〜8 は ctor のまま
 *   p169          部品 3〜8 は 線種 1・線色 2・座標 0、頭は 1・2・0x2000
 *
 * 2424 で作った図形を原典に描かせた答えは無い（寸法図形化 の答えと形を照らす）。
 *
 * 半径・直径（FUN_007891b0 0x789cf4・0x78a129）も同じ形で、点は図形の後ろ。
 * 角度（FUN_00786fb0）は bda0 を見ない（命令で 0xa0bda0 を探して無い）ので
 * 入でも ふつうの要素のまま。拾い・読取点 は 空の部品（座標 0）を見ない。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/pick.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

/* (100,100)-(200,100) の線の両端を測る ふつうの寸法 */
static void line_dim(jw_drawing *d)
{
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_point(d, app_view(), 100.0, 120.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 110.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 200.0, 100.0, 0);
    jw_cmd_set(0);
}

/* 図面の中の 寸法図形 の頭（部品 1）。無ければ -1 */
static int find_fig(const jw_drawing *d, int from)
{
    int k;

    for (k = from; k + 7 < d->ndrawn; k++)
        if (d->obj[k].sub == 1 && d->obj[k + 7].sub == 8)
            return k;
    return -1;
}

static const unsigned char CLS[8] = {
    JW_SEN, JW_MOJI, JW_SEN, JW_SEN, JW_TEN, JW_TEN, JW_TEN, JW_TEN
};

/* 半径（1065）・直径（1066）: (400,100) 半径 30 の円を (430,100) で指示。
   切 なら 線・値・点二つ、入 なら 部品 1〜8 のあとに 点二つ
   （FUN_007891b0: 寸法線は 0x789cf4 で図形へ、値の段 0x78a129 で足す、
   点は 0x78a6xx〜 で後ろ） */
static void radius_dim(jw_drawing *d, int button)
{
    const char *what = button == 1065 ? "半径" : "直径";
    jw_obj *c = jw_add(d, JW_ENKO), off[4];
    int b0, b1, k, i, f, depth;
    char txt[64] = "";

    c->d[0] = 400.0;
    c->d[1] = 100.0;
    c->d[2] = 30.0;
    c->d[3] = 0.0;
    c->d[4] = 6.283185307179586;
    c->d[5] = 0.0;
    c->d[6] = 1.0;
    c->n = 1;
    printf("-- %s\n", what);
    for (k = 0; k < 2; k++) {
        jw_cmd_sunpo_chk_set(2424, k);
        b0 = d->ndrawn;
        depth = jw_cmd_undo_depth();
        jw_cmd_set(JW_CMD_SUNPO);
        jw_cmd_bar(d, button);
        jw_cmd_point(d, app_view(), 430.0, 100.0, 0);
        jw_cmd_set(0);
        b1 = d->ndrawn - b0;
        ck(jw_cmd_undo_depth() == depth + 1, "  一つの 戻る");
        if (!k) {
            ck(b1 == 4 && d->obj[b0].cls == JW_SEN
               && d->obj[b0 + 1].cls == JW_MOJI
               && d->obj[b0 + 2].cls == JW_TEN && d->obj[b0 + 3].cls == JW_TEN
               && !d->obj[b0].sub && !d->obj[b0 + 1].sub,
               "  切: 線・値・点二つ（これまでどおり）");
            for (i = 0; i < 4 && i < b1; i++)
                off[i] = d->obj[b0 + i];
            if (b1 >= 2 && d->obj[b0 + 1].cls == JW_MOJI)
                snprintf(txt, sizeof txt, "%s", jw_str(d, d->obj[b0 + 1].text));
        } else {
            ck(b1 == 8 + 2, "  入: 部品八つと 点二つ");
            f = find_fig(d, b0);
            ck(f == b0, "  部品 1〜8 が先、点が後ろ");
            if (f == b0 && b1 == 10) {
                const jw_obj *p = &d->obj[f], *t = &d->obj[f + 1];
                for (i = 0, k = 1; i < 8; i++)
                    k &= d->obj[f + i].cls == CLS[i] && d->obj[f + i].sub == i + 1;
                ck(k, "  部品の型は 線・字・線・線・点・点・点・点");
                ck(near(p->d[0], off[0].d[0]) && near(p->d[1], off[0].d[1])
                   && near(p->d[2], off[0].d[2]) && near(p->d[3], off[0].d[3])
                   && p->flags == off[0].flags && p->color == off[0].color,
                   "  部品 1 は 切 のときの線と同じ");
                ck(!strcmp(jw_str(d, t->text), txt) && t->flags == off[1].flags
                   && (t->flags & (button == 1065 ? 0x100 : 0x200))
                   && near(t->d[0], off[1].d[0]) && near(t->d[1], off[1].d[1]),
                   "  部品 2 は 切 のときの値と同じ（R・φ の旗も）");
                ck(p->list[0] == 0 && (p->list[2] & 0xffff) == 0x2000,
                   "  頭は +0x1c0 0・旗 0x2000");
                ck(d->obj[f + 8].cls == JW_TEN && !d->obj[f + 8].sub
                   && near(d->obj[f + 8].d[0], off[2].d[0])
                   && d->obj[f + 9].cls == JW_TEN
                   && near(d->obj[f + 9].d[0], off[3].d[0]),
                   "  点二つは ふつうの要素で 図形の後ろ");
            }
            k = 1;
        }
        jw_cmd_undo(d);
        ck(d->ndrawn == b0, "  戻る で消える");
    }
    jw_cmd_sunpo_chk_set(2424, 0);
}

/* 角度（1068）: FUN_00786fb0 は bda0 を見ないので 入でも sub は付かない */
static void angle_dim(jw_drawing *d)
{
    int k, b0, n[2] = { 0, 0 }, any = 0, i;

    jw_obj *v = jw_add(d, JW_SEN);       /* 終りの読取点に (100,200) */

    v->d[0] = 100.0;
    v->d[1] = 100.0;
    v->d[2] = 100.0;
    v->d[3] = 200.0;
    printf("-- 角度\n");
    for (k = 0; k < 2; k++) {
        jw_cmd_sunpo_chk_set(2424, k);
        b0 = d->ndrawn;
        jw_cmd_set(JW_CMD_SUNPO);
        jw_cmd_bar(d, 1068);
        jw_cmd_point(d, app_view(), 100.0, 100.0, 0);   /* 原点 */
        jw_cmd_point(d, app_view(), 140.0, 140.0, 0);   /* 引出線の始め */
        jw_cmd_point(d, app_view(), 150.0, 150.0, 0);   /* 寸法線の位置 */
        jw_cmd_point(d, app_view(), 200.0, 100.0, 1);   /* 始め（読む） */
        jw_cmd_point(d, app_view(), 100.0, 200.0, 1);   /* 終り（読む） */
        jw_cmd_set(0);
        n[k] = d->ndrawn - b0;
        for (i = b0; i < d->ndrawn; i++)
            any |= d->obj[i].sub;
        if (n[k] > 0)
            jw_cmd_undo(d);
    }
    printf("     切 %d 要素、入 %d 要素\n", n[0], n[1]);
    ck(n[0] > 0 && n[0] == n[1] && !any, "  入でも 切 と同じ数、sub は 0");
    jw_cmd_sunpo_chk_set(2424, 0);
}

/* 線 の 寸法値（1350）: FUN_006f46a0 の 0x6f4ec2〜 で bda0 なら 線と値で
   寸法図形一つ（線 +0xac に 0x2000、字 +0x114 に 0x10）、●（1348）は
   0x6f5802〜 で その後ろ。文字種が負なら 字は線の向こう側（0x6f5290〜） */
static void sen_dim(jw_drawing *d)
{
    jw_obj off[2];
    int k, b0, b1, f, depth;

    printf("-- 線の寸法値\n");
    jw_cmd_set(JW_CMD_SEN);
    if (jw_cmd_bar_check(1350) <= 0)
        jw_cmd_bar(d, 1350);
    ck(jw_cmd_bar_check(1350) == 1, "  寸法値 を 入");
    for (k = 0; k < 2; k++) {
        jw_cmd_sunpo_chk_set(2424, k);
        b0 = d->ndrawn;
        depth = jw_cmd_undo_depth();
        jw_cmd_point(d, app_view(), 100.0, 300.0, 0);
        jw_cmd_point(d, app_view(), 200.0, 300.0, 0);
        b1 = d->ndrawn - b0;
        ck(jw_cmd_undo_depth() == depth + 1, "  一つの 戻る");
        if (!k) {
            ck(b1 == 2 && d->obj[b0].cls == JW_SEN && d->obj[b0 + 1].cls == JW_MOJI
               && !d->obj[b0].sub && !d->obj[b0 + 1].sub,
               "  切: 線と値（これまでどおり）");
            off[0] = d->obj[b0];
            off[1] = d->obj[b0 + 1];
        } else {
            ck(b1 == 8, "  入: 部品八つ");
            f = find_fig(d, b0);
            ck(f == b0, "  線と値が 部品 1・2");
            if (f == b0 && b1 == 8) {
                const jw_obj *p = &d->obj[f], *t = &d->obj[f + 1];
                int i, s = 1;
                for (i = 0; i < 8; i++)
                    s &= d->obj[f + i].cls == CLS[i] && d->obj[f + i].sub == i + 1;
                ck(s, "  部品の型は 線・字・線・線・点・点・点・点");
                ck(near(p->d[0], off[0].d[0]) && near(p->d[2], off[0].d[2])
                   && p->flags == off[0].flags && (p->flags & 0x2000),
                   "  部品 1 は 切 のときの線と同じ（0x2000）");
                ck(t->flags == off[1].flags && (t->flags & 0x10)
                   && near(t->d[0], off[1].d[0]) && near(t->d[1], off[1].d[1])
                   && !strcmp(jw_str(d, t->text), jw_str(d, off[1].text)),
                   "  部品 2 は 切 のときの値と同じ（0x10）");
                ck(p->list[0] == 0 && (p->list[2] & 0xffff) == 0x2000,
                   "  頭は +0x1c0 0・旗 0x2000");
            }
        }
        jw_cmd_undo(d);
        ck(d->ndrawn == b0, "  戻る で消える");
    }
    /* ● (1348) は 図形の後ろに ふつうの点 */
    jw_cmd_sunpo_chk_set(2424, 1);
    jw_cmd_bar(d, 1348);
    b0 = d->ndrawn;
    jw_cmd_point(d, app_view(), 100.0, 300.0, 0);
    jw_cmd_point(d, app_view(), 200.0, 300.0, 0);
    b1 = d->ndrawn - b0;
    ck(b1 == 9 && find_fig(d, b0) == b0 && d->obj[b0 + 8].cls == JW_TEN
       && !d->obj[b0 + 8].sub, "  ● は 部品八つの後ろに ふつうの点");
    jw_cmd_undo(d);
    jw_cmd_bar(d, 1348);
    jw_cmd_sunpo_chk_set(2424, 0);

    /* 文字種 -2（既定は 2）: 字は 線の下、上端が 間隔 の所 */
    jw_cmd_sunpo_box_set(1488, "-2");
    b0 = d->ndrawn;
    jw_cmd_point(d, app_view(), 100.0, 300.0, 0);
    jw_cmd_point(d, app_view(), 200.0, 300.0, 0);
    if (d->ndrawn == b0 + 2) {
        const jw_obj *t = &d->obj[b0 + 1];
        double h = d->style[1].h, hn = off[1].d[1] - 300.0;
        printf("     上 y=%.4f、下 y=%.4f（高さ %.3f、間隔 %.3f）\n",
               off[1].d[1], t->d[1], h, hn);
        ck(near(t->d[1], 300.0 - hn - h) && near(t->d[0], off[1].d[0])
           && near(t->d[2], off[1].d[2]) && near(t->d[5], h),
           "  文字種 -2 なら 字は線の向こう側、読む向きは同じ");
    } else
        ck(0, "  文字種 -2 でも 線と値");
    if (d->ndrawn > b0)
        jw_cmd_undo(d);
    jw_cmd_sunpo_box_set(1488, "2");
    jw_cmd_bar(d, 1350);
    jw_cmd_set(0);
}

/* +0x1c0 が 0 でない（引出線・点を描く）図形でも 部品 3〜6 は拾わない:
   原典 CDataSunpou slot 17 FUN_0042d7f0 は 部品 1・2 しか見ない */
static void fig_pick(jw_drawing *d)
{
    int b0 = d->ndrawn, f, pk, k;
    double rx, ry;

    printf("-- +0x1c0 の立つ図形の拾い\n");
    jw_cmd_sunpo_chk_set(2424, 1);
    line_dim(d);
    jw_cmd_sunpo_chk_set(2424, 0);
    f = find_fig(d, b0);
    if (f < 0)
        printf("     %d 要素増えた\n", d->ndrawn - b0);
    ck(f >= 0, "  寸法図形を作る");
    if (f < 0)
        return;
    d->obj[f].list[0] = 1;              /* +0x1c0: 部品 3〜6 も描く */
    for (k = 2; k < 4; k++) {           /* 部品 3・4 を 離れた所の線に */
        d->obj[f + k].d[0] = 500.0 + 50.0 * k;
        d->obj[f + k].d[1] = 500.0;
        d->obj[f + k].d[2] = 500.0 + 50.0 * k;
        d->obj[f + k].d[3] = 540.0;
    }
    d->obj[f + 4].d[0] = 700.0;         /* 部品 5 の点 */
    d->obj[f + 4].d[1] = 500.0;
    pk = jw_pick(d, app_view(), 600.0, 520.0, 0);
    ck(pk != f + 2 && pk != f + 3, "  部品 3・4 の線の上で拾っても当たらない");
    pk = jw_pick(d, app_view(), 700.0, 500.0, 0);
    ck(pk != f + 4, "  部品 5 の点の上で拾っても当たらない");
    d->obj[f].d[1] = d->obj[f].d[3] = 600.0;    /* 部品 1 を ほかと重ならない所へ */
    pk = jw_pick(d, app_view(), 150.0, 600.0, 0);
    ck(pk == f, "  部品 1（寸法線）は当たる");
    /* 読取点は これまでどおり（描く部品は読む） */
    ck(jw_read(d, app_view(), 700.0, 500.0, &rx, &ry) && near(rx, 700.0)
       && near(ry, 500.0), "  読取点は 部品 5 の点を読む（これまでどおり）");
    while (d->ndrawn > b0)
        jw_cmd_undo(d);
}

/* 文字方向補正（2419 文字方向無補正 = bd20）: FUN_00783730 は 字の枠を
   始点→終点 にして FUN_00479550 に 補正 (bd20 == 0) を渡し、補正なら
   左向きの二点を入れ替える（0x4796f0〜）。逆に測った寸法の値は 補正なら
   前に測ったのと同じ所・同じ向き、無補正なら 逆さで寸法線の下 */
static void hosei_dim(jw_drawing *d)
{
    jw_obj fw;
    int b0, k, ok = 1;
    double tl;

    printf("-- 文字方向補正\n");
    b0 = d->ndrawn;
    line_dim(d);                        /* 左から右へ */
    ck(d->ndrawn == b0 + 6 && d->obj[b0 + 5].cls == JW_MOJI, "  左→右 の寸法");
    if (d->ndrawn != b0 + 6)
        return;
    fw = d->obj[b0 + 5];
    tl = d->obj[b0].d[1];               /* 寸法線の y */
    jw_cmd_undo(d);
    for (k = 0; k < 2; k++) {
        jw_cmd_sunpo_chk_set(2419, k);
        b0 = d->ndrawn;
        jw_cmd_set(JW_CMD_SUNPO);       /* 右から左へ */
        jw_cmd_point(d, app_view(), 100.0, 120.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 110.0, 0);
        jw_cmd_point(d, app_view(), 200.0, 100.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
        jw_cmd_set(0);
        ok = d->ndrawn == b0 + 6 && d->obj[b0 + 5].cls == JW_MOJI;
        ck(ok, k ? "  無補正: 右→左 の寸法" : "  補正: 右→左 の寸法");
        if (ok) {
            const jw_obj *t = &d->obj[b0 + 5];
            printf("     字 %.4f,%.4f -> %.4f,%.4f（左→右は %.4f,%.4f -> %.4f,%.4f）\n",
                   t->d[0], t->d[1], t->d[2], t->d[3],
                   fw.d[0], fw.d[1], fw.d[2], fw.d[3]);
            if (!k)
                ck(near(t->d[0], fw.d[0]) && near(t->d[1], fw.d[1])
                   && near(t->d[2], fw.d[2]) && near(t->d[3], fw.d[3]),
                   "  補正（既定）: 左→右 と同じ所・同じ向き");
            else
                ck(near(t->d[0], fw.d[2]) && near(t->d[2], fw.d[0])
                   && near(t->d[1], tl - (fw.d[1] - tl))
                   && near(t->d[3], t->d[1]),
                   "  無補正: 右向きに逆さ、寸法線の下に 間隔");
        }
        if (d->ndrawn > b0)
            jw_cmd_undo(d);
    }
    jw_cmd_sunpo_chk_set(2419, 0);
}

/* 文字方向補正（2419）を 累進 の字にも。FUN_00783730 の累進（0x785f68〜）は
   bd20 == 0 を FUN_00479550 に渡す。傾き 90° の累進は 字の向き +v が左向きなので
   補正なら 二点を入れ替え（字の場所は同じで 読む向きだけ逆、間隔 は反対側）。
   FUN_00786fb0（角度）は 補正に 0 を渡す（FUN_00479c40 の第 4 引数）ので そのまま */
static void hosei2_dim(jw_drawing *d)
{
    jw_obj *c = jw_add(d, JW_SEN);
    int b0, k;

    printf("-- 累進 の文字方向補正\n");
    c->d[0] = 100.0;
    c->d[1] = 50.0;
    c->d[2] = 100.0;
    c->d[3] = 100.0;
    /* 累進: 傾き 90°（寸法線が上向き）だと 字の向き +v が左向き → 入れ替え。
       2419 無補正なら そのまま 左向き（d[0] > d[2]） */
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_box_click(1411);
    for (k = 0; k < 24; k++)
        jw_cmd_box_key(8);
    jw_cmd_box_key('9');
    jw_cmd_box_key('0');
    jw_cmd_box_key(13);
    jw_cmd_bar(d, 1070);                /* 累進（押すたびに入／切）*/
    for (k = 0; k < 2; k++) {
        jw_cmd_sunpo_chk_set(2419, k);
        b0 = d->ndrawn;
        jw_cmd_point(d, app_view(), 100.0, 0.0, 0);
        jw_cmd_point(d, app_view(), 80.0, 0.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
        if (d->ndrawn > b0 && d->obj[d->ndrawn - 1].cls == JW_MOJI) {
            const jw_obj *t = &d->obj[d->ndrawn - 1];
            printf("     累進 90° %s: %.4f,%.4f -> %.4f,%.4f\n",
                   k ? "無補正" : "補正", t->d[0], t->d[1], t->d[2], t->d[3]);
            ck(k ? t->d[0] > t->d[2] : t->d[0] < t->d[2],
               k ? "  累進 無補正: 左向きのまま" : "  累進 補正: 右向きに読む");
        } else
            ck(0, "  累進 90° が描けた");
        while (d->ndrawn > b0)
            jw_cmd_undo(d);
    }
    jw_cmd_sunpo_chk_set(2419, 0);
    jw_cmd_bar(d, 1070);
    jw_cmd_box_click(1411);
    for (k = 0; k < 24; k++)
        jw_cmd_box_key(8);
    jw_cmd_box_key('0');
    jw_cmd_box_key(13);
    jw_cmd_set(0);
}

/* 半径・直径: FUN_007891b0 は 補正に 定数 1（2419 に依らない）。(400,100) 半径 30 の円を
   左（370,100）で指示 → 線は左向きなので 二点を入れ替え 字は右向きに読み、間隔 はその上へ */
static void hosei3_dim(jw_drawing *d)
{
    jw_obj *c = jw_add(d, JW_ENKO);
    int b0, bt;

    c->d[0] = 400.0;
    c->d[1] = 100.0;
    c->d[2] = 30.0;
    c->d[3] = 0.0;
    c->d[4] = 6.283185307179586;
    c->d[5] = 0.0;
    c->d[6] = 1.0;
    c->n = 1;
    printf("-- 半径・直径 の文字方向補正\n");
    for (bt = 1065; bt <= 1066; bt++) {
        b0 = d->ndrawn;
        jw_cmd_set(JW_CMD_SUNPO);
        jw_cmd_bar(d, bt);
        jw_cmd_point(d, app_view(), 370.0, 100.0, 0);
        jw_cmd_set(0);
        if (d->ndrawn == b0 + 4 && d->obj[b0 + 1].cls == JW_MOJI) {
            const jw_obj *t = &d->obj[b0 + 1];
            ck(t->d[0] < t->d[2] && near(t->d[1], t->d[3]) && t->d[1] > 100.0,
               bt == 1065 ? "  半径 左向き: 字は右向き・線の上"
                          : "  直径 左向き: 字は右向き・線の上");
        } else
            ck(0, "  半径・直径 の左向き");
        if (d->ndrawn > b0)
            jw_cmd_undo(d);
    }
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_esc_key(d);                  /* 直径 を ふつうの二点に戻す */
    jw_cmd_esc_key(d);
    jw_cmd_set(0);
}

/* グループ化（2861、bd8c）: FUN_00783730・FUN_007891b0 の頭で 空いている
   いちばん小さい番号（FUN_00479d80）の負を +0x6348 に置き、FUN_00450860 が
   足す要素ごとに +4 へ写す。寸法図形なら 図形の頭だけ */
static void group_dim(jw_drawing *d)
{
    int b0, b1, b2, k, s, g1, g2;

    printf("-- グループ化\n");
    b0 = d->ndrawn;
    line_dim(d);
    for (k = b0, s = 1; k < d->ndrawn; k++)
        s &= d->obj[k].id == 0;
    ck(d->ndrawn > b0 && s, "  切: 曲線属性は 0");
    while (d->ndrawn > b0)
        jw_cmd_undo(d);
    jw_cmd_sunpo_chk_set(2861, 1);
    b0 = d->ndrawn;
    line_dim(d);
    b1 = d->ndrawn;
    line_dim(d);
    b2 = d->ndrawn;
    g1 = d->obj[b0].id;
    g2 = d->obj[b1].id;
    for (k = b0, s = 1; k < b1; k++)
        s &= d->obj[k].id == g1;
    for (k = b1; k < b2; k++)
        s &= d->obj[k].id == g2;
    printf("     一つ目 %d、二つ目 %d\n", g1, g2);
    ck(b1 > b0 && b2 > b1 && s && g1 < 0 && g2 < 0 && g1 != g2,
       "  入: 一回の寸法の要素は同じ負の番号、次の寸法は別の番号");
    {   /* 空いているいちばん小さい番号 */
        int used = 0;
        for (k = 0; k < d->nobj; k++)
            if (k < b0 || k >= b2)
                used |= d->obj[k].id == -g1 || d->obj[k].id == g1;
        ck(!used, "  一つ目の番号は 前からの要素に無い");
    }
    while (d->ndrawn > b0)
        jw_cmd_undo(d);
    /* 寸法図形: 頭（list[1]）だけ、部品は 0、点・引出線 は同じ番号 */
    jw_cmd_sunpo_chk_set(2424, 1);
    line_dim(d);
    k = find_fig(d, b0);
    ck(k == b0 + 4 && d->obj[k].list[1] < 0 && d->obj[k].id == 0
       && d->obj[k + 1].id == 0 && d->obj[b0].id == d->obj[k].list[1]
       && d->obj[b0 + 3].id == d->obj[k].list[1],
       "  寸法図形: 頭の +4 と 点・引出線 が同じ番号、部品は 0");
    while (d->ndrawn > b0)
        jw_cmd_undo(d);
    jw_cmd_sunpo_chk_set(2424, 0);
    /* 寸法値（1069、+0x1c4 == 0x19）も FUN_00783730 が書くので 同じ番号 */
    b0 = d->ndrawn;
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_bar(d, 1069);
    jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 50.0, 0);
    ck(d->ndrawn == b0 + 1 && d->obj[b0].cls == JW_MOJI && d->obj[b0].id < 0,
       "  寸法値: 字に 負の番号");
    while (d->ndrawn > b0)
        jw_cmd_undo(d);
    jw_cmd_set(0);
    jw_cmd_sunpo_chk_set(2861, 0);
}

int main(void)
{
    unsigned char *b, *w = 0;
    long n, wn = 0;
    jw_drawing *d, rd, ans;
    jw_obj *ln;
    int b0, b1, n0, n1, k, f, fa, i, depth, pk0, rd0;
    double rx0, ry0;
    char txt0[64] = "";

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);    /* probe169 と同じ元 */
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    ln = jw_add(d, JW_SEN);
    ln->d[0] = 100.0;
    ln->d[1] = 100.0;
    ln->d[2] = 200.0;
    ln->d[3] = 100.0;
    app_fit();

    /* ---- 切（既定）: これまでどおり、部品の印は無い */
    ck(jw_cmd_sunpo_chk(2424) == 0, "寸法図形 は 切 から");
    b0 = d->ndrawn;
    line_dim(d);
    n0 = d->ndrawn - b0;
    printf("     切: %d 要素\n", n0);
    ck(n0 == 6, "  寸法線・点二つ・引出線二本・値 の 6");
    ck(d->obj[b0].cls == JW_SEN && d->obj[b0 + 5].cls == JW_MOJI,
       "  寸法線が先、値が後");
    for (k = b0, i = 0; k < d->ndrawn; k++)
        i |= d->obj[k].sub;
    ck(i == 0, "  sub は 0");
    if (d->obj[b0 + 5].cls == JW_MOJI)
        snprintf(txt0, sizeof txt0, "%s", jw_str(d, d->obj[b0 + 5].text));

    /* 原点の 拾い・読取点（空の部品は ここに座標 0 で並ぶ）を先に控える */
    {
        double rx = 0.0, ry = 0.0;
        pk0 = jw_pick(d, app_view(), 0.0, 0.0, 0);
        rd0 = jw_read(d, app_view(), 0.0, 0.0, &rx, &ry);
        rx0 = rx;
        ry0 = ry;
    }

    /* ---- 入: 点・引出線 は ふつうに、その後に 部品 1〜8 */
    jw_cmd_sunpo_chk_set(2424, 1);
    ck(jw_cmd_sunpo_chk(2424) == 1, "寸法図形 を 入");
    b1 = d->ndrawn;
    depth = jw_cmd_undo_depth();
    line_dim(d);
    n1 = d->ndrawn - b1;
    printf("     入: %d 要素\n", n1);
    ck(n1 == 4 + 8, "  点二つ・引出線二本 と 部品八つ");
    ck(jw_cmd_undo_depth() == depth + 1, "  一つの 戻る");
    ck(d->obj[b1].cls == JW_TEN && d->obj[b1 + 1].cls == JW_TEN
       && d->obj[b1 + 2].cls == JW_SEN && d->obj[b1 + 3].cls == JW_SEN
       && !d->obj[b1].sub && !d->obj[b1 + 3].sub,
       "  前の四つは ふつうの 点・引出線（p169 と同じ並び）");
    f = find_fig(d, b1);
    ck(f == b1 + 4, "  部品 1〜8 が 一続き");
    if (f >= 0) {
        const jw_obj *p = &d->obj[f], *t = &d->obj[f + 1];
        for (k = 0, i = 1; k < 8; k++)
            i &= d->obj[f + k].cls == CLS[k] && d->obj[f + k].sub == k + 1;
        ck(i, "  部品の型は 線・字・線・線・点・点・点・点");
        ck(near(p->d[0], d->obj[b0].d[0]) && near(p->d[1], d->obj[b0].d[1])
           && near(p->d[2], d->obj[b0].d[2]) && near(p->d[3], d->obj[b0].d[3])
           && p->color == d->obj[b0].color && p->flags == d->obj[b0].flags,
           "  部品 1 は 切 のときの寸法線と同じ");
        ck(!strcmp(jw_str(d, t->text), txt0) && t->flags == d->obj[b0 + 5].flags
           && near(t->d[0], d->obj[b0 + 5].d[0]),
           "  部品 2 は 切 のときの値と同じ");
        for (k = 2, i = 1; k < 8; k++) {
            const jw_obj *q = &d->obj[f + k];
            i &= q->ltype == 1 && q->color == 2 && q->width == 0
                 && q->flags == 0 && q->d[0] == 0.0 && q->d[1] == 0.0
                 && q->d[2] == 0.0 && q->d[3] == 0.0;
        }
        ck(i, "  部品 3〜8 は 空（1・2・0、座標 0、旗 0）");
        ck(p->list[0] == 0 && (p->list[2] & 0xffff) == 0x2000
           && (p->mark & 0xffffff) == (1 | (2 << 8)),
           "  頭は +0x1c0 0・旗 0x2000・線種 1・線色 2");
    }
    {   /* 空の部品は 拾わない・読まない（描き手の sun_part_hidden と同じ） */
        double rx = 0.0, ry = 0.0;
        int pk = jw_pick(d, app_view(), 0.0, 0.0, 0);
        int rr = jw_read(d, app_view(), 0.0, 0.0, &rx, &ry);
        ck(pk == pk0 && !(f >= 0 && pk >= f + 2 && pk < f + 8),
           "  原点で拾っても 空の部品は当たらない");
        ck(rr == rd0 && (!rr || (rx == rx0 && ry == ry0)),
           "  原点の読取点も 図形の前と同じ");
    }

    /* ---- 保存して読み戻すと CDataSunpou 一つ、原典の答えと同じ形 */
    ck(jw_write(d, &w, &wn) && w, "保存できる");
    {
        long k2, hits = 0;
        for (k2 = 0; w && k2 + 11 <= wn; k2++)
            if (!memcmp(w + k2, "CDataSunpou", 11))
                hits++;
        ck(hits == 1, "  クラス名 CDataSunpou が書かれる");
    }
    memset(&rd, 0, sizeof rd);
    ck(w && jw_parse(&rd, w, wn), "  読み戻せる");
    fa = find_fig(&rd, 0);
    ck(fa >= 0 && find_fig(&rd, fa + 8) < 0, "  寸法図形は一つ");
    b = slurp("decomp/res/p169_dimfig.jww", &n);
    memset(&ans, 0, sizeof ans);
    ck(b && jw_parse(&ans, b, n), "原典の答え p169_dimfig.jww を読む");
    i = find_fig(&ans, 0);
    ck(i >= 0, "  答えにも寸法図形");
    if (fa >= 0 && i >= 0) {
        int same = 1;
        for (k = 0; k < 8; k++) {
            const jw_obj *p = &rd.obj[fa + k], *q = &ans.obj[i + k];
            int s = p->cls == q->cls && p->ltype == q->ltype
                    && p->color == q->color && p->layer == q->layer
                    && p->lgroup == q->lgroup && p->flags == q->flags;
            if (k == 1)
                s = p->cls == q->cls && p->flags == q->flags
                    && p->width == q->width;
            if (k >= 2)
                s = s && p->width == q->width && p->d[0] == q->d[0]
                    && p->d[1] == q->d[1] && p->d[2] == q->d[2]
                    && p->d[3] == q->d[3] && p->n == q->n;
            if (!s)
                printf("     部品 %d が違う: 移植 %d %d %d %#x / 答え %d %d %d %#x\n",
                       k + 1, p->ltype, p->color, p->width, p->flags,
                       q->ltype, q->color, q->width, q->flags);
            same &= s;
        }
        ck(same, "  部品 1〜8 の 型・線種・線色・レイヤ・旗（3〜8 は座標も）が答えと同じ");
        ck(rd.obj[fa].list[0] == ans.obj[i].list[0]
           && rd.obj[fa].list[1] == ans.obj[i].list[1]
           && rd.obj[fa].list[2] == ans.obj[i].list[2]
           && rd.obj[fa].mark == ans.obj[i].mark
           && rd.obj[fa].turn == ans.obj[i].turn,
           "  頭（CDataSunpou の CData の欄と +0x1c0）が答えと同じ");
        ck(ans.obj[i - 4].cls == JW_TEN && ans.obj[i - 3].cls == JW_TEN
           && ans.obj[i - 2].cls == JW_SEN && ans.obj[i - 1].cls == JW_SEN
           && ans.obj[i - 4].flags == rd.obj[fa - 4].flags
           && ans.obj[i - 2].flags == rd.obj[fa - 2].flags,
           "  図形の前の 点二つ・引出線二本 も答えと同じ並び・旗");
    }
    free(b);
    free(w);
    jw_free(&ans);
    jw_free(&rd);

    /* ---- 戻る で 八つとも消える */
    jw_cmd_undo(d);
    ck(d->ndrawn == b1, "戻る で 寸法図形ごと消える");

    jw_cmd_sunpo_chk_set(2424, 0);
    fig_pick(d);
    hosei_dim(d);
    hosei2_dim(d);
    group_dim(d);
    radius_dim(d, 1065);
    radius_dim(d, 1066);
    angle_dim(d);
    sen_dim(d);
    hosei3_dim(d);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
