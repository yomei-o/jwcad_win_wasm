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
            show("入れ子の参照", &d.obj[at]);
            ck(d.obj[at].block == 2, "  入れ子の参照は 定義 2 を指す");
            ck(near(d.obj[at].d[0], 100.0) && near(d.obj[at].d[1], 70.0),
               "  基点は 外の参照で写る（2 倍して 90° 回し (100,50) へ）");
            ck(near(d.obj[at].d[2], 3.0) && near(d.obj[at].d[3], 1.5),
               "  倍率は 外の倍率 x・y を掛ける（1.5×2、0.5×3）");
            ck(near(d.obj[at].d[4], 120.0 * PI / 180.0), "  角は 30°+90°");
        }
        for (k = 0; k < d.ndrawn; k++)
            if (d.obj[k].cls == JW_SEN)
                ck(near(d.obj[k].d[0], 100.0) && near(d.obj[k].d[1], 50.0)
                   && near(d.obj[k].d[2], 100.0) && near(d.obj[k].d[3], 70.0),
                   "  線は (100,50)-(100,70)");
        jw_free(&d);
    }

    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
