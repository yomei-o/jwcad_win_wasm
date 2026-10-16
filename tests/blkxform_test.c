/* ブロックの参照（JW_BLOCK）の 複写・移動・倍率・回転 と、ブロック解除で
   出てくる入れ子の参照。d[] の並びは CDataBlock::Serialize（0x0049b2c0）:
   d[0],d[1] 基点、d[2],d[3] 倍率 x・y、d[4] 角。変えるのは基点だけを点として
   写し、倍率には掛け、角には足す（原典の 移動 FUN_0046ba40・倍率 FUN_00464870・
   回転 FUN_0046d050）。逆コンパイルの読み、原典では押していない。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/cmd.h"
#include "../src/jww.h"

#define PI 3.14159265358979323846

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

static void ref(jw_obj *o, double x, double y, double sx, double sy,
                double deg, int block)
{
    o->d[0] = x;
    o->d[1] = y;
    o->d[2] = sx;
    o->d[3] = sy;
    o->d[4] = deg * PI / 180.0;
    o->block = block;
}

static void show(const char *what, const jw_obj *o)
{
    printf("     %s: (%g, %g) 倍率 %g,%g 角 %g°\n", what, o->d[0], o->d[1],
           o->d[2], o->d[3], o->d[4] * 180.0 / PI);
}

int main(void)
{
    jw_obj o;

    /* 移動 */
    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 10.0, 20.0, 2.0, 3.0, 30.0, 1);
    jw_obj_move(&o, 5.0, -7.0);
    show("移動 (5,-7)", &o);
    ck(near(o.d[0], 15.0) && near(o.d[1], 13.0), "移動: 基点が動く");
    ck(near(o.d[2], 2.0) && near(o.d[3], 3.0), "移動: 倍率はそのまま");
    ck(near(o.d[4], 30.0 * PI / 180.0), "移動: 角はそのまま");

    /* 複写・移動の 倍率・回転（基準点 (10,0)、倍率 2、90°、(100,50) へ） */
    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 20.0, 0.0, 1.5, 0.5, 10.0, 1);
    jw_obj_xform(&o, 10.0, 0.0, 2.0, PI / 2.0, 100.0, 50.0);
    show("倍率 2・90° 回して (100,50) ずらす", &o);
    ck(near(o.d[0], 110.0) && near(o.d[1], 70.0),
       "倍率・回転: 基点は 基準点まわりに 2 倍して 90° 回る");
    ck(near(o.d[2], 3.0) && near(o.d[3], 1.0), "倍率・回転: 倍率 x・y に 2 を掛ける");
    ck(near(o.d[4], 100.0 * PI / 180.0), "倍率・回転: 角に 90° を足す");

    /* 回転だけ・倍率だけ */
    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 1.0, 0.0, 1.0, 1.0, 0.0, 1);
    jw_obj_xform(&o, 0.0, 0.0, 1.0, PI, 0.0, 0.0);
    ck(near(o.d[0], -1.0) && fabs(o.d[1]) < 1e-9 && near(o.d[2], 1.0)
       && near(o.d[3], 1.0) && near(o.d[4], PI), "回転 180°: 基点が回り、角が足される");
    jw_obj_xform(&o, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0);
    ck(near(o.d[0], -0.5) && near(o.d[2], 0.5) && near(o.d[3], 0.5)
       && near(o.d[4], PI), "倍率 0.5: 基点と倍率が半分、角はそのまま");

    /* ブロック解除: 入れ子の参照が出る */
    {
        jw_drawing d;
        jw_obj *p;
        int at, k, nb = 0, ns = 0;

        memset(&d, 0, sizeof d);
        p = jw_add(&d, JW_BLOCK);          /* 外の参照 */
        ref(p, 100.0, 50.0, 2.0, 3.0, 90.0, 1);
        p = jw_add_def(&d, JW_LIST);       /* 定義 1: 線と 定義 2 の参照 */
        p->list[0] = 1;
        p->n = 2;
        p = jw_add_def(&d, JW_SEN);
        p->d[0] = 0.0; p->d[1] = 0.0; p->d[2] = 10.0; p->d[3] = 0.0;
        p = jw_add_def(&d, JW_BLOCK);
        p->ltype = 1;
        ref(p, 10.0, 0.0, 1.5, 0.5, 30.0, 2);
        p = jw_add_def(&d, JW_LIST);       /* 定義 2: 線 */
        p->list[0] = 2;
        p->n = 1;
        p = jw_add_def(&d, JW_SEN);
        p->d[0] = 0.0; p->d[1] = 0.0; p->d[2] = 1.0; p->d[3] = 0.0;

        d.obj[0].sel = 1;
        ck(jw_cmd_block_free(&d) > 0, "ブロック解除");
        for (k = 0, at = -1; k < d.ndrawn; k++) {
            if (d.obj[k].cls == JW_BLOCK) {
                at = k;
                nb++;
            } else if (d.obj[k].cls == JW_SEN)
                ns++;
        }
        ck(nb == 1 && ns == 1, "  線一つと入れ子の参照一つが出る");
        if (at >= 0) {
            /* 外の倍率 (2,3) は x・y 違い、入れ子は 30° 回っているので
               FUN_00464870 は定義を作り直す: 新しい定義（名前 "" の
               "@@SfigorgFlag@@4"）に 基点 (0,0)・30°・(1.5,0.5) で 定義 2 を
               指す参照を一つ入れ、入れ子の参照は 倍率 (2,3)・角 0 から 90° */
            int nl2 = -1;

            show("入れ子の参照", &d.obj[at]);
            for (k = d.ndrawn; k < d.nobj; k++)
                if (d.obj[k].cls == JW_LIST && d.obj[k].list[0] == d.obj[at].block)
                    nl2 = k;
            ck(d.obj[at].block != 1 && d.obj[at].block != 2 && nl2 >= 0,
               "  入れ子の参照は 作り直した新しい定義を指す");
            if (nl2 >= 0 && nl2 + 1 < d.nobj) {
                const jw_obj *m = &d.obj[nl2 + 1];

                ck(d.obj[nl2].n == 1 && !strcmp(jw_str(&d, d.obj[nl2].text),
                                                 "@@SfigorgFlag@@4"),
                   "  新しい定義は 名前 \"\"（@@SfigorgFlag@@4）で 要素一つ");
                show("新しい定義の中の参照", m);
                ck(m->cls == JW_BLOCK && m->block == 2 && near(m->d[0], 0.0)
                   && near(m->d[1], 0.0) && near(m->d[2], 1.5) && near(m->d[3], 0.5)
                   && near(m->d[4], 30.0 * PI / 180.0),
                   "  その中は 定義 2 を 基点 (0,0)・(1.5,0.5)・30° で");
            }
            ck(near(d.obj[at].d[0], 100.0) && near(d.obj[at].d[1], 70.0),
               "  基点は 外の参照で写る（2 倍して 90° 回し (100,50) へ）");
            ck(near(d.obj[at].d[2], 2.0) && near(d.obj[at].d[3], 3.0),
               "  倍率は 外の倍率 (2,3)");
            ck(near(d.obj[at].d[4], 90.0 * PI / 180.0), "  角は 0° から 90°");
        }
        for (k = 0; k < d.ndrawn; k++)
            if (d.obj[k].cls == JW_SEN)
                ck(near(d.obj[k].d[0], 100.0) && near(d.obj[k].d[1], 50.0)
                   && near(d.obj[k].d[2], 100.0) && near(d.obj[k].d[3], 70.0),
                   "  線は (100,50)-(100,70)");
        jw_free(&d);
    }

    /* 反転（jw_obj_mirror）。原典は 倍率の関数で裏返す: FUN_00653fe0 が
       基準線の角を (-90°,90°] に寄せ、45° 未満なら a=角・倍率 (1,-1)、でなければ
       a=角∓90°・(-1,1)。CDataBlock の枝 FUN_00464870 は基点を写し、倍率 x・y を
       掛け、角を a で折り返す。逆コンパイルの読み、原典では押していない */
    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 10.0, 20.0, 2.0, 3.0, 30.0, 1);
    jw_obj_mirror(&o, 0.0, 5.0, 1.0, 0.0);
    show("反転 y=5 の横線", &o);
    ck(near(o.d[0], 10.0) && near(o.d[1], -10.0), "反転 横: 基点が裏返る");
    ck(near(o.d[2], 2.0) && near(o.d[3], -3.0), "反転 横: 倍率 (1,-1) を掛ける");
    ck(near(o.d[4], -30.0 * PI / 180.0), "反転 横: 角は 0° で折り返す");
    jw_obj_mirror(&o, 0.0, 5.0, -1.0, 0.0);
    ck(near(o.d[0], 10.0) && near(o.d[1], 20.0) && near(o.d[2], 2.0)
       && near(o.d[3], 3.0) && near(o.d[4], 30.0 * PI / 180.0),
       "反転 横を逆向きの線でもう一度: 元に戻る");

    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 10.0, 20.0, 2.0, 3.0, 30.0, 1);
    jw_obj_mirror(&o, 5.0, 0.0, 0.0, 1.0);
    show("反転 x=5 の縦線", &o);
    ck(near(o.d[0], 0.0) && near(o.d[1], 20.0), "反転 縦: 基点が裏返る");
    ck(near(o.d[2], -2.0) && near(o.d[3], 3.0), "反転 縦: 90° は 0° と (-1,1) に");
    ck(near(o.d[4], -30.0 * PI / 180.0), "反転 縦: 角は 0° で折り返す");

    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 2.0, 0.0, 1.0, 1.0, 0.0, 1);
    jw_obj_mirror(&o, 0.0, 0.0, cos(PI / 6.0), sin(PI / 6.0));
    show("反転 30° の線", &o);
    ck(near(o.d[0], 1.0) && near(o.d[1], sqrt(3.0)), "反転 30°: 基点が裏返る");
    ck(near(o.d[2], 1.0) && near(o.d[3], -1.0) && near(o.d[4], PI / 3.0),
       "反転 30°: 倍率 (1,-1)、角は 30° で折り返して 60°");

    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 0.0, 0.0, 1.0, 1.0, 0.0, 1);
    jw_obj_mirror(&o, 0.0, 0.0, cos(PI / 3.0), sin(PI / 3.0));
    ck(near(o.d[2], -1.0) && near(o.d[3], 1.0) && near(o.d[4], -PI / 3.0),
       "反転 60°: -30° と (-1,1)、角は -60°");

    memset(&o, 0, sizeof o);
    o.cls = JW_BLOCK;
    ref(&o, 0.0, 0.0, 2.0, 0.0, 0.0, 1);
    jw_obj_mirror(&o, 0.0, 0.0, 1.0, 0.0);
    ck(near(o.d[2], 2.0) && near(o.d[3], -2.0), "反転: 倍率 y の 0 は x と同じに読む");

    /* 反転した参照のブロック解除: 定義の線と入れ子の参照が 裏返って出る */
    {
        static const double fl[2][2] = { { 1.0, -1.0 }, { -1.0, 1.0 } };
        int c;

        for (c = 0; c < 2; c++) {
            jw_drawing d;
            jw_obj *p;
            int k;
            char what[96];

            memset(&d, 0, sizeof d);
            p = jw_add(&d, JW_BLOCK);
            ref(p, 100.0, 50.0, fl[c][0], fl[c][1], 0.0, 1);
            p = jw_add_def(&d, JW_LIST);
            p->list[0] = 1;
            p->n = 2;
            p = jw_add_def(&d, JW_SEN);
            p->d[0] = 0.0; p->d[1] = 0.0; p->d[2] = 10.0; p->d[3] = 5.0;
            p = jw_add_def(&d, JW_BLOCK);
            p->ltype = 1;
            ref(p, 10.0, 0.0, 1.5, 0.5, 30.0, 2);
            p = jw_add_def(&d, JW_LIST);
            p->list[0] = 2;
            p->n = 1;
            p = jw_add_def(&d, JW_SEN);
            p->d[0] = 0.0; p->d[1] = 0.0; p->d[2] = 1.0; p->d[3] = 0.0;

            d.obj[0].sel = 1;
            snprintf(what, sizeof what, "ブロック解除 倍率 (%g,%g)", fl[c][0], fl[c][1]);
            ck(jw_cmd_block_free(&d) > 0, what);
            for (k = 0; k < d.ndrawn; k++) {
                const jw_obj *q = &d.obj[k];

                if (q->cls == JW_SEN) {
                    double ex = 100.0 + 10.0 * fl[c][0], ey = 50.0 + 5.0 * fl[c][1];

                    printf("     線 (%g,%g)-(%g,%g)\n", q->d[0], q->d[1], q->d[2], q->d[3]);
                    ck(near(q->d[0], 100.0) && near(q->d[1], 50.0)
                       && near(q->d[2], ex) && near(q->d[3], ey), "  線が裏返る");
                } else if (q->cls == JW_BLOCK) {
                    /* 写した入れ子の参照の x 軸・y 軸の行き先を、
                       外 diag(fx,fy) ∘ R(30°) diag(1.5,0.5) と比べる */
                    double c4 = cos(q->d[4]), s4 = sin(q->d[4]);
                    double c3 = cos(PI / 6.0), s3 = sin(PI / 6.0);

                    show("入れ子の参照", q);
                    ck(near(q->d[0], 100.0 + 10.0 * fl[c][0]) && near(q->d[1], 50.0),
                       "  入れ子の基点が裏返る");
                    ck(near(c4 * q->d[2], fl[c][0] * c3 * 1.5)
                       && near(s4 * q->d[2], fl[c][1] * s3 * 1.5)
                       && near(-s4 * q->d[3], fl[c][0] * -s3 * 0.5)
                       && near(c4 * q->d[3], fl[c][1] * c3 * 0.5),
                       "  入れ子の 倍率・角 が 外の反転と合う");
                }
            }
            jw_free(&d);
        }
    }

    /* x・y 違いの倍率（jw_block_scale_xy、FUN_00464870）。軸角 ax・中心 (cx,cy) */
    {
        jw_drawing d;
        jw_obj *p, r;
        int got, k, nlist;

        /* (1) 回っていない参照: 基点を写し 倍率に x・y を掛けるだけ */
        memset(&d, 0, sizeof d);
        memset(&o, 0, sizeof o);
        o.cls = JW_BLOCK;
        ref(&o, 10.0, 20.0, 1.5, 0.5, 0.0, 1);
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 2.0, 3.0, 0.0);
        show("回っていない参照に (2,3)", &o);
        ck(got == 0 && d.nobj == 0 && near(o.d[0], 20.0) && near(o.d[1], 60.0)
           && near(o.d[2], 3.0) && near(o.d[3], 1.5) && near(o.d[4], 0.0)
           && o.block == 1, "x・y 違い (1): 角が軸角と同じなら 倍率に掛けるだけ");

        /* 軸角 30° で 30° 回った参照も (1) */
        memset(&o, 0, sizeof o);
        o.cls = JW_BLOCK;
        ref(&o, 0.0, 0.0, 1.0, 1.0, 30.0, 1);
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 2.0, 0.5, 30.0 * PI / 180.0);
        ck(got == 0 && d.nobj == 0 && near(o.d[2], 2.0) && near(o.d[3], 0.5)
           && near(o.d[4], 30.0 * PI / 180.0), "x・y 違い (1): 軸角 30° と 30° の参照");

        /* 範囲の外・1 倍は 何もしない */
        memset(&o, 0, sizeof o);
        o.cls = JW_BLOCK;
        ref(&o, 10.0, 20.0, 1.5, 0.5, 30.0, 1);
        r = o;
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 1e-6, 2.0, 0.0);
        ck(got == 0 && !memcmp(o.d, r.d, sizeof o.d), "x・y 違い: 1e-5 未満の倍率は何もしない");
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 1.0, 1.0 + 1e-8, 0.0);
        ck(got == 0 && !memcmp(o.d, r.d, sizeof o.d), "x・y 違い: 1 倍は何もしない");

        /* (2) -x == y は 反転と同じ: 角を軸角で折り返す */
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 2.0, -2.0, 0.0);
        ck(got == 0 && near(o.d[0], 20.0) && near(o.d[1], -40.0) && near(o.d[2], 3.0)
           && near(o.d[3], -1.0) && near(o.d[4], -30.0 * PI / 180.0),
           "x・y 違い (2): (2,-2) は 倍率を掛け 角を 0° で折り返す");

        /* (3) 回った参照: 定義を作り直す */
        p = jw_add(&d, JW_SEN);             /* 図面に線一本（数合わせ） */
        p = jw_add_def(&d, JW_LIST);        /* 定義 5: 線 (0,0)-(10,4) */
        p->list[0] = 5;
        p->n = 1;
        p->text = jw_add_str(&d, "A@@SfigorgFlag@@4");
        p = jw_add_def(&d, JW_SEN);
        p->d[0] = 0.0; p->d[1] = 0.0; p->d[2] = 10.0; p->d[3] = 4.0;
        memset(&o, 0, sizeof o);
        o.cls = JW_BLOCK;
        o.layer = 3;
        o.color = 2;
        ref(&o, 10.0, 0.0, 1.5, 0.5, 40.0, 5);
        r = o;
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 2.0, 1.0, 0.0);
        show("40° 回った参照に (2,1)", &o);
        ck(got == 2 && d.nobj == 5, "x・y 違い (3): 定義と その中の参照 二つを末尾に足す");
        ck(near(o.d[0], 20.0) && near(o.d[1], 0.0) && near(o.d[2], 2.0)
           && near(o.d[3], 1.0) && near(o.d[4], 0.0) && o.block == 6,
           "x・y 違い (3): 参照は 倍率 (2,1)・角 0（軸角）、新しい定義 6 を指す");
        if (d.nobj == 5) {
            const jw_obj *l = &d.obj[3], *m = &d.obj[4];

            ck(l->cls == JW_LIST && l->list[0] == 6 && l->n == 1 && l->list[1] == 0
               && !strcmp(jw_str(&d, l->text), "@@SfigorgFlag@@4"),
               "  新しい定義: 番号 6・要素一つ・名前 \"\"（@@SfigorgFlag@@4）");
            ck(m->cls == JW_BLOCK && m->block == 5 && m->layer == 3 && m->color == 2
               && near(m->d[0], 0.0) && near(m->d[1], 0.0) && near(m->d[2], 1.5)
               && near(m->d[3], 0.5) && near(m->d[4], 40.0 * PI / 180.0),
               "  中の参照: 元の参照の写しで 基点 (0,0)・角 40°−0°・倍率そのまま");
            /* 線の端 (10,4) の行き先: 作り直した二段 と diag(2,1)·(T + R(40)·diag(1.5,0.5)·p) */
            {
                jw_obj ln = d.obj[2];
                double c = cos(40.0 * PI / 180.0), s4 = sin(40.0 * PI / 180.0);
                double ex = 15.0 * c - 2.0 * s4 + 10.0, ey = 15.0 * s4 + 2.0 * c;

                jw_obj_blkput(&ln, m);
                jw_obj_blkput(&ln, &o);
                printf("     線の端 (%g,%g)、計算 (%g,%g)\n", ln.d[2], ln.d[3], 2.0 * ex, ey);
                ck(near(ln.d[0], 20.0) && near(ln.d[1], 0.0) && near(ln.d[2], 2.0 * ex)
                   && near(ln.d[3], ey), "  二段で写した線が 元の参照に x だけ 2 倍した所");
            }
        }
        /* 同じ中身の二つ目は 定義を使い回す（FUN_0049bdb0 が等しい） */
        o = r;
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 2.0, 1.0, 0.0);
        ck(got == 0 && d.nobj == 5 && o.block == 6, "x・y 違い (3): 同じ中身なら 定義 6 を使い回す");
        /* 色が違えば別の定義 */
        o = r;
        o.color = 3;
        got = jw_block_scale_xy(&d, &o, 0.0, 0.0, 2.0, 1.0, 0.0);
        ck(got == 2 && o.block == 7, "x・y 違い (3): 色の違う参照は 新しい定義 7");
        /* 図面が無い（仮表示）なら (1) と同じ */
        o = r;
        got = jw_block_scale_xy(0, &o, 0.0, 0.0, 2.0, 1.0, 0.0);
        ck(got == 0 && o.block == 5 && near(o.d[2], 3.0) && near(o.d[3], 0.5)
           && near(o.d[4], 40.0 * PI / 180.0), "x・y 違い (3): 図面が無ければ 倍率に掛けるだけ");
        /* 軸角 90°・中心 (10,0) */
        o = r;
        got = jw_block_scale_xy(&d, &o, 10.0, 0.0, 1.0, 3.0, PI / 2.0);
        show("軸角 90° で (1,3)", &o);
        for (k = d.ndrawn, nlist = -1; k < d.nobj; k++)
            if (d.obj[k].cls == JW_LIST && d.obj[k].list[0] == o.block)
                nlist = k;
        ck(got == 2 && nlist >= 0 && near(o.d[0], 10.0) && near(o.d[1], 0.0)
           && near(o.d[2], 1.0) && near(o.d[3], 3.0) && near(o.d[4], PI / 2.0)
           && near(d.obj[nlist + 1].d[4], -50.0 * PI / 180.0),
           "x・y 違い (3): 軸角 90° なら 中は 40°−90°、参照の角は 90°");
        jw_free(&d);
    }

    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
