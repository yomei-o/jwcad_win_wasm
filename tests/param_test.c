/* パラメトリック変形 (32898 = 0x8082)。
 *
 *   tests/param_test.exe
 *
 * 原典（CZukeiParametric）の逆コンパイルの読みに対して確かめる。原典は
 * 押していない。読んだこと（src/cmd.c の「パラメトリック変形」の節）:
 *   - 範囲の枠に端点が**厳密に**入った線は拾われ、その端点だけが動く。丸ごと
 *     入った要素は移動する。跨ぐだけの線、跨ぐ円は拾わない
 *   - ソリッド は入った角だけ動く
 *   - 選択確定 のとき マウスのところが 基準点、クリックで 移動先 − 基準点 だけ
 *     変わり、基準点は移動先に移る（続けて伸ばせる）
 *   - 戻る は一手ぶん戻し、基準点も戻る
 *   - 数値位置 (1413) に "x,y" があれば Enter でそれだけ（実寸 ÷ 縮尺）
 *   - 任意方向 (1151) の X 方向 は縦のずれを捨てる
 *   - 二枚目のバーの 1069 は 再選択 で、選んだものを残して 追加・除外 の段へ
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
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

static void type_box(int id, const char *v)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *v; v++)
        jw_cmd_box_key((unsigned char)*v);
    jw_cmd_box_key(13);
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

static int line_is(const jw_obj *o, double a, double b, double c, double e)
{
    return near(o->d[0], a) && near(o->d[1], b)
        && near(o->d[2], c) && near(o->d[3], e);
}

static jw_obj *line(jw_drawing *d, double a, double b, double c, double e)
{
    jw_obj *o = jw_add(d, JW_SEN);

    o->d[0] = a;
    o->d[1] = b;
    o->d[2] = c;
    o->d[3] = e;
    return o;
}

static double scale_of(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale > 0.0 ? d->group[wg].scale : 1.0;
}

int main(void)
{
    unsigned char *b;
    long n;
    jw_drawing *d;
    const jw_view *v;
    int L1, L2, L3, L4, L5, C1, C2, S, first;
    jw_obj *o;

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    v = app_view();
    first = d->ndrawn;
    line(d, 0, 0, 100, 0);              /* 終点だけ枠に入る */
    line(d, 100, 5, 200, 5);            /* 始点だけ */
    line(d, 60, 10, 140, 10);           /* 丸ごと */
    line(d, 0, 50, 200, 50);            /* 外 */
    line(d, 0, -5, 200, -5);            /* 跨ぐだけ */
    o = jw_add(d, JW_ENKO);             /* 丸ごと入る円 */
    o->d[0] = 100; o->d[1] = 0; o->d[2] = 5;
    o->d[3] = 0; o->d[4] = 2 * 3.14159265358979323846; o->d[5] = 1;
    o = jw_add(d, JW_ENKO);             /* 跨ぐ円 */
    o->d[0] = 150; o->d[1] = 0; o->d[2] = 10;
    o->d[3] = 0; o->d[4] = 2 * 3.14159265358979323846; o->d[5] = 1;
    o = jw_add(d, JW_SOLID);            /* 右の二つの角だけ入る */
    o->ltype = 1;
    o->d[0] = 40; o->d[1] = -10;
    o->d[2] = 60; o->d[3] = -10;
    o->d[4] = 60; o->d[5] = 10;
    o->d[6] = 40; o->d[7] = 10;
    L1 = first; L2 = first + 1; L3 = first + 2; L4 = first + 3;
    L5 = first + 4; C1 = first + 5; C2 = first + 6; S = first + 7;

    jw_cmd_set(JW_CMD_PARAM);
    ck(jw_cmd() == JW_CMD_PARAM, "パラメトリック変形 に入る");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5383), "  案内は 範囲選択の始点");
    jw_cmd_point(d, v, 50, -20, 0);
    jw_cmd_point(d, v, 150, 20, 0);
    ck(d->obj[L1].sel && d->obj[L2].sel && d->obj[L3].sel,
       "  端点が入った線も 丸ごとの線も 拾う");
    ck(!d->obj[L4].sel && !d->obj[L5].sel, "  外の線・跨ぐだけの線は 拾わない");
    ck(d->obj[C1].sel && !d->obj[C2].sel, "  円は丸ごと入ったときだけ");
    ck(d->obj[S].sel, "  角の入ったソリッドも拾う");
    ck(jw_cmd_sel_count(d) == 5, "  拾ったのは五つ");

    jw_cmd_track(100, 0);
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 が押せる");
    ck(jw_cmd_sel_stage() == 3, "  基準点 はマウスのところで 移動先待ち");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5311), "  案内は 移動先の点");
    ck(jw_cmd_bar_enabled(d, 1069) == 1, "  二枚目の 再選択 は生きている");
    {
        jw_drawing pv;

        jw_cmd_track(130, 0);
        ck(jw_cmd_param_preview(d, &pv) && pv.ndrawn == 5
           && line_is(&pv.obj[0], 0, 0, 130, 0), "  仮表示は 終点だけ動いた線");
    }
    {
        int depth = jw_cmd_undo_depth();

        jw_cmd_point(d, v, 130, 0, 0);
        ck(jw_cmd_undo_depth() == depth + 1, "  一手は 戻る 一つ");
    }
    ck(line_is(&d->obj[L1], 0, 0, 130, 0), "  終点の入った線は 終点だけ伸びる");
    ck(line_is(&d->obj[L2], 130, 5, 200, 5), "  始点の入った線は 始点だけ縮む");
    ck(line_is(&d->obj[L3], 90, 10, 170, 10), "  丸ごとの線は 移動");
    ck(line_is(&d->obj[L4], 0, 50, 200, 50) && line_is(&d->obj[L5], 0, -5, 200, -5),
       "  拾わなかった線は そのまま");
    ck(near(d->obj[C1].d[0], 130) && near(d->obj[C1].d[1], 0)
       && near(d->obj[C1].d[2], 5), "  円は 移動（半径はそのまま）");
    ck(near(d->obj[C2].d[0], 150), "  跨ぐ円は そのまま");
    ck(near(d->obj[S].d[0], 40) && near(d->obj[S].d[2], 90)
       && near(d->obj[S].d[4], 90) && near(d->obj[S].d[6], 40),
       "  ソリッドは 入った角だけ動く");
    ck(d->obj[L1].sel && jw_cmd_sel_stage() == 3, "  選んだまま次を待つ");

    jw_cmd_point(d, v, 140, 0, 0);
    ck(line_is(&d->obj[L1], 0, 0, 140, 0), "  続けると 移動先から測る（基準点が移った）");
    jw_cmd_undo(d);
    ck(line_is(&d->obj[L1], 0, 0, 130, 0), "  戻る で一手ぶん戻る");
    jw_cmd_point(d, v, 135, 0, 0);
    ck(line_is(&d->obj[L1], 0, 0, 135, 0), "  基準点も一手ぶん戻っている");
    jw_cmd_undo(d);
    jw_cmd_undo(d);
    ck(line_is(&d->obj[L1], 0, 0, 100, 0) && line_is(&d->obj[L2], 100, 5, 200, 5)
       && near(d->obj[S].d[2], 60), "  戻る を重ねると 元どおり");

    /* 任意方向 → X 方向: 縦のずれは捨てる */
    ck(jw_cmd_bar(d, 1151) == 1, "  任意方向 を押すと X 方向");
    jw_cmd_point(d, v, 110, 30, 0);
    ck(line_is(&d->obj[L1], 0, 0, 110, 0) && line_is(&d->obj[L3], 70, 10, 150, 10),
       "  X 方向 は横だけ");
    jw_cmd_bar(d, 1151);
    jw_cmd_bar(d, 1151);
    jw_cmd_bar(d, 1151);                /* 任意方向 に戻す */
    jw_cmd_undo(d);

    /* 数値位置: 実寸の "x,y" を縮尺で割ったぶん、Enter で */
    {
        double s = scale_of(d);
        char t[64];

        snprintf(t, sizeof t, "%g,%g", 25.0 * s, 0.0);
        type_box(1413, t);
        ck(jw_cmd_box(1413) && !strcmp(jw_cmd_prompt(), JW_STR_5410),
           "  数値位置 があると 案内は 位置を確定");
        ck(jw_cmd_enter_key(d) == 1, "  Enter で決まる");
        ck(line_is(&d->obj[L1], 0, 0, 125, 0), "  数値位置 のぶんだけ伸びる");
        type_box(1413, "");
        jw_cmd_undo(d);
        ck(line_is(&d->obj[L1], 0, 0, 100, 0), "  それも 戻る で戻る");
    }

    /* 基点変更: 次のクリックが基準点 */
    ck(jw_cmd_bar(d, 1066) == 1, "  基点変更 が押せる");
    ck(!strcmp(jw_cmd_prompt(), JW_STR_5314), "  案内は 基準点");
    jw_cmd_point(d, v, 0, 0, 0);
    jw_cmd_point(d, v, 7, 0, 0);
    ck(line_is(&d->obj[L1], 0, 0, 107, 0), "  新しい基準点から測る");
    jw_cmd_undo(d);

    /* 再選択 */
    ck(jw_cmd_bar(d, 1069) == 1, "  再選択 が押せる");
    ck(jw_cmd_sel_stage() == 2 && jw_cmd_sel_count(d) == 5,
       "  選んだものを残して 追加・除外 の段へ");
    jw_cmd_track(100, 0);
    ck(jw_cmd_enter_key(d) == 1 && jw_cmd_sel_stage() == 3,
       "  Enter で もう一度 選択確定");
    jw_cmd_point(d, v, 90, 0, 0);
    ck(line_is(&d->obj[L1], 0, 0, 90, 0) && line_is(&d->obj[L2], 90, 5, 200, 5),
       "  端点の印は残っている");

    /* 寸法図形（sub 1..8）: 寸法線の端だけ枠に入れば その端の側だけ動き、
       値を書き直す（FUN_006ce8b0 0x6cedaa〜・FUN_0047e400 の読み） */
    {
        int D, q, depth, oldtext;
        jw_obj ln, want;
        const char *s;
        char ws[64];

        ck(d->version > 0x1a3, "  寸法図形は 八つの部品の版");
        D = d->ndrawn;
        line(d, 1000, 20, 1100, 20);                    /* 1 寸法線 */
        jw_add(d, JW_MOJI);                             /* 2 値 */
        line(d, 1000, 0, 1000, 20);                     /* 3 始点の側の補助線 */
        line(d, 1100, 0, 1100, 20);                     /* 4 終点の側 */
        for (q = 0; q < 4; q++) {                       /* 5..8 点 */
            o = jw_add(d, JW_TEN);
            o->d[0] = q == 1 || q == 3 ? 1100 : 1000;
            o->d[1] = q < 2 ? 20 : 0;
            o->turn = 0.0;
        }
        jw_cmd_dim_value(d, &d->obj[D], &d->obj[D + 1]);
        for (q = 0; q < 8; q++)
            d->obj[D + q].sub = (unsigned char)(q + 1);
        oldtext = d->obj[D + 1].text;

        jw_cmd_set(JW_CMD_PARAM);
        jw_cmd_point(d, v, 1050, -30, 0);
        jw_cmd_point(d, v, 1150, 40, 0);
        ck(jw_cmd_sel_count(d) == 8, "  寸法図形は 寸法線の終点だけで 部品八つを拾う");
        jw_cmd_track(1100, 20);
        jw_cmd_bar(d, 1120);
        {
            jw_drawing pv;
            int ok = 0;

            jw_cmd_track(1130, 20);
            if (jw_cmd_param_preview(d, &pv) && pv.ndrawn == 8)
                for (q = 0; q < 8; q++)
                    if (pv.obj[q].sub == 1 && line_is(&pv.obj[q], 1000, 20, 1130, 20))
                        ok = 1;
            ck(ok, "  仮表示も 寸法線の終点だけ動く");
        }
        depth = jw_cmd_undo_depth();
        jw_cmd_point(d, v, 1130, 20, 0);
        ck(jw_cmd_undo_depth() == depth + 1, "  一手は 戻る 一つ");
        ck(line_is(&d->obj[D], 1000, 20, 1130, 20), "  寸法線は 終点だけ伸びる");
        ck(line_is(&d->obj[D + 2], 1000, 0, 1000, 20)
           && near(d->obj[D + 4].d[0], 1000) && near(d->obj[D + 6].d[0], 1000),
           "  始点の側の補助線と点は そのまま");
        ck(line_is(&d->obj[D + 3], 1130, 0, 1130, 20)
           && near(d->obj[D + 5].d[0], 1130) && near(d->obj[D + 5].d[1], 20)
           && near(d->obj[D + 7].d[0], 1130) && near(d->obj[D + 7].d[1], 0),
           "  終点の側の補助線と点は 一緒に動く");
        ln = d->obj[D];
        jw_cmd_dim_value(d, &ln, &want);
        s = jw_str(d, d->obj[D + 1].text);
        snprintf(ws, sizeof ws, "%s", jw_str(d, want.text));
        ck(s && !strcmp(s, ws), "  値は 新しい長さで書き直す");
        printf("     値 %s\n", s ? s : "(null)");
        ck(near((d->obj[D + 1].d[0] + d->obj[D + 1].d[2]) / 2, 1065)
           && near(d->obj[D + 1].d[1], want.d[1]),
           "  字は 真ん中のまま 新しい寸法線の真ん中へ（高さはそのまま）");
        jw_cmd_undo(d);
        ck(line_is(&d->obj[D], 1000, 20, 1100, 20)
           && d->obj[D + 1].text == oldtext
           && line_is(&d->obj[D + 3], 1100, 0, 1100, 20), "  戻る で元どおり");

        /* 斜めへ: 点の角が 寸法線の向きの変わりだけ回る */
        jw_cmd_point(d, v, 1130, 50, 0);
        ck(line_is(&d->obj[D], 1000, 20, 1130, 50), "  斜めにも 終点だけ");
        ck(near(d->obj[D + 4].turn, atan2(30.0, 130.0))
           && near(d->obj[D + 5].turn, atan2(30.0, 130.0)),
           "  端の点（sub 5・6）の角に 向きの変わりを足す");
        ck(fabs(d->obj[D + 1].d[7] - atan2(30.0, 130.0) * 180.0 / 3.14159265358979323846)
           < 1e-9, "  字も新しい寸法線の向き");
        jw_cmd_undo(d);
    }

    printf(fails ? "%d failed\n" : "all ok\n", fails);
    return fails != 0;
}
