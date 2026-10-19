/* 図面に貼った画像（"^@BM" で始まる字）を ほかの命令がどう扱うか。
 *
 * どれも原典の逆コンパイルの読み（原典では押していない）で、ここで確かめる
 * のは その読みどおりに移植が動くこと:
 *   拾い      FUN_0048a1e0: 画像は枠の四辺で拾い、字の箱では拾わない
 *             （「文字のスペースを表示する」2103 が入っていれば箱でも）
 *   読取点    FUN_00451f30 → FUN_0045d910: 枠が近ければ 四隅を読む
 *   倍率      FUN_00465f40／FUN_00466e30 → FUN_0048f7f0: w・h を掛け、字の大きさは保つ
 *   回転      FUN_0046d800 → FUN_0048fb30: 文字列の角度に足す（丸めない）
 *   JWC       FUN_00521d10・FUN_0051be70: w・h を 用紙幅/518 の目盛で書き、読んで戻す
 *   ブロック  描画 FUN_0049a3d0 → FUN_0042b460・解除 FUN_00458440: 定義の要素の写しに
 *             倍率・回転を掛けるので 画像は 複写・移動と同じ（w・h と角度）
 * src/imgpic.c の末尾の注。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/cmd.h"
#include "../src/draw.h"
#include "../src/fb.h"
#include "../src/image.h"
#include "../src/jww.h"
#include "../src/pick.h"
#include "../src/view.h"

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

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

/* 字の要素を一つ。始点 (x,y)、字は 2mm、基線は字の長さだけ角 deg の向きへ */
static int put_text(jw_drawing *d, const char *s, double x, double y, double deg)
{
    jw_obj *o = jw_add(d, JW_MOJI);
    double len = (double)strlen(s) * 2.0 / 2.0, a = deg * 3.14159265358979323846 / 180.0;

    o->d[0] = x;
    o->d[1] = y;
    o->d[2] = x + cos(a) * len;
    o->d[3] = y + sin(a) * len;
    o->d[4] = 2.0;
    o->d[5] = 2.0;
    o->d[6] = 0.0;
    o->d[7] = deg;
    o->color = 1;
    o->ltype = 1;
    o->face = -1;
    o->text = jw_add_str(d, s);
    d->ndrawn = d->nobj;
    return d->nobj - 1;
}

static const char *txt(const jw_drawing *d, int i)
{
    return jw_str(d, d->obj[i].text);
}

int main(void)
{
    jw_drawing d;
    jw_view v;
    long n, wn = 0;
    unsigned char *b = slurp("orig/Test5.jww", &n), *w = 0;
    int a, r, k;
    double rx, ry;

    memset(&d, 0, sizeof d);
    ck(b && jw_parse(&d, b, n), "Test5 を土台に");
    while (d.nobj > 0)
        jw_remove(&d, d.nobj - 1);
    d.ndrawn = 0;
    memset(&v, 0, sizeof v);
    v.scale = 10.0;             /* 拾いの幅 1mm */
    v.mmpp = 0.1;

    /* ------------------------------------------------ 拾い・読取点 */
    a = put_text(&d, "^@BMa.bmp,50,40", 10.0, 10.0, 0.0);              /* (10,10)-(60,50) */
    r = put_text(&d, "^@BMb.bmp,50,40,0,0,1,90,255,255,255", 200.0, 10.0, 90.0);
    ck(jw_pick(&d, &v, 35.0, 50.4, 0) == a, "画像の上の辺で拾う");
    ck(jw_pick(&d, &v, 59.6, 30.0, 0) == a, "右の辺でも");
    ck(jw_pick(&d, &v, 35.0, 30.0, 0) < 0, "枠の中ほどは拾わない");
    ck(jw_pick(&d, &v, 14.0, 11.6, 0) < 0, "字の箱の縁（画像の枠からは 1.6mm）でも拾わない");
    jw_pick_pic_text = 1;
    ck(jw_pick(&d, &v, 14.0, 11.6, 0) == a, "  2103 が入っていれば字の箱でも拾う");
    jw_pick_pic_text = 0;
    ck(jw_pick_moji(&d, &v, 35.0, 50.4) == a, "文字を指示する拾いも枠で");
    ck(jw_pick(&d, &v, 180.0, 60.3, 0) == r, "回した画像（90°）は回った枠で: 上の辺 (200,60)-(160,60)");
    ck(jw_pick(&d, &v, 230.0, 10.5, 0) < 0, "  回す前の場所では拾わない");
    ck(jw_read(&d, &v, 60.4, 50.3, &rx, &ry) && near(rx, 60.0) && near(ry, 50.0),
       "(R) は 画像の右上の隅を読む");
    ck(jw_read(&d, &v, 9.7, 49.6, &rx, &ry) && near(rx, 10.0) && near(ry, 50.0), "  左上も");
    ck(jw_read(&d, &v, 160.3, 59.8, &rx, &ry) && near(rx, 160.0) && near(ry, 60.0),
       "  回した画像の隅");
    ck(!jw_read(&d, &v, 35.0, 30.0, &rx, &ry), "  枠から遠ければ読まない");

    /* ------------------------------------------------ 倍率・回転 */
    {
        jw_obj was = d.obj[a], *o = &d.obj[a];

        jw_obj_xform(o, 0.0, 0.0, 2.0, 0.0, 100.0, 0.0);
        ck(jw_pic_xform(&d, o, &was, 2.0, 0.0) == 1, "倍率 2");
        ck(!strcmp(txt(&d, a), "^@BMa.bmp,100,80"), "  w・h が倍、二つの形のまま");
        ck(near(o->d[0], 120.0) && near(o->d[1], 20.0), "  始点（左下）は基準点まわりに倍");
        ck(near(o->d[4], 2.0) && near(o->d[5], 2.0), "  字の大きさは保つ");
        ck(near(o->d[2], 120.0 + 16.0) && near(o->d[3], 20.0), "  終点は 始点＋字の長さ");
    }
    {
        jw_obj was = d.obj[a], *o = &d.obj[a];
        double c = cos(30.0 * 3.14159265358979323846 / 180.0);
        double s = sin(30.0 * 3.14159265358979323846 / 180.0);

        jw_obj_xform(o, 120.0, 20.0, 1.0, 30.0 * 3.14159265358979323846 / 180.0, 0.0, 0.0);
        jw_pic_xform(&d, o, &was, 1.0, 30.0 * 3.14159265358979323846 / 180.0);
        ck(!strcmp(txt(&d, a), "^@BMa.bmp,100,80,0,0,1,30,255,255,255"),
           "回転 30°: 九つの形になり 角度が 30");
        ck(near(o->d[7], 30.0), "  字の角度も 30");
        ck(near(o->d[2], 120.0 + c * 37.0) && near(o->d[3], 20.0 + s * 37.0),
           "  基線は 30° の向きへ字の長さだけ");
    }
    {
        int t = put_text(&d, "^@BMc.bmp,50,40,0,0,1,350,255,255,255", 0.0, 0.0, 350.0);
        jw_obj was = d.obj[t], *o = &d.obj[t];

        jw_obj_xform(o, 0.0, 0.0, 1.0, 20.0 * 3.14159265358979323846 / 180.0, 0.0, 0.0);
        jw_pic_xform(&d, o, &was, 1.0, 20.0 * 3.14159265358979323846 / 180.0);
        ck(!strcmp(txt(&d, t), "^@BMc.bmp,50,40,0,0,1,370,255,255,255"),
           "350° に 20°: 文字列の角度は丸めず 370");
        ck(near(o->d[7], 10.0), "  字の角度は (-180,180] へ 10");

        was = d.obj[t];
        jw_obj_xform(o, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0);
        jw_pic_xform(&d, o, &was, -1.0, 0.0);
        ck(!strcmp(txt(&d, t), "^@BMc.bmp,50,40,0,0,1,370,255,255,255"),
           "倍率 -1: w・h が 0.001 未満になるので書き直さない");

        was = d.obj[t];
        jw_obj_xform(o, 0.0, 0.0, 1.0, 0.0, 5.0, 5.0);
        ck(jw_pic_xform(&d, o, &was, 1.0, 0.0) == 1 && near(o->d[0], was.d[0] + 5.0)
           && near(o->d[2], was.d[2] + 5.0) && !strcmp(txt(&d, t), txt(&d, t)),
           "ずらすだけなら字はそのまま");
    }
    {
        int t = put_text(&d, "ふつうの字", 0.0, 0.0, 0.0);
        jw_obj was = d.obj[t];

        jw_obj_xform(&d.obj[t], 0.0, 0.0, 2.0, 0.0, 0.0, 0.0);
        ck(jw_pic_xform(&d, &d.obj[t], &was, 2.0, 0.0) == 0 && near(d.obj[t].d[4], 4.0),
           "画像でない字は jw_obj_xform のまま");
    }

    /* ------------------------------------------------ JWC */
    {
        jw_drawing e;
        double unit = 518.0 / (d.paper_hw * 2.0);
        char want[64];
        int found = 0;

        while (d.nobj > 0)
            jw_remove(&d, d.nobj - 1);
        d.ndrawn = 0;
        put_text(&d, "^@BMa.bmp,50,40,0,0,1,0,255,255,255", 10.0, 10.0, 0.0);
        ck(jw_jwc_write(&d, &w, &wn) && w, "JWC に書く");
        snprintf(want, sizeof want, "^@BMa.bmp,%g,%g,0,0,1,0,255,255,255", 50.0 * unit, 40.0 * unit);
        for (k = 0; w && k + (long)strlen(want) <= wn; k++)
            if (!memcmp(w + k, want, strlen(want) + 1))
                found = 1;
        ck(found, "  w・h は 用紙幅/518 の目盛で");
        memset(&e, 0, sizeof e);
        ck(jw_parse(&e, b, n), "  読む先");
        while (e.nobj > 0)
            jw_remove(&e, e.nobj - 1);
        e.ndrawn = 0;
        ck(jw_jwc_read(&e, w, wn), "  JWC を読む");
        found = 0;
        for (k = 0; k < e.nobj; k++) {
            jw_pic p;

            /* %g の六桁で行って帰るので 39.9999 のように端が欠ける（原典も
               同じ書式で書いて読む） */
            if (e.obj[k].cls == JW_MOJI && jw_pic_parse(&e, &e.obj[k], &p) && p.nfield == 9
                && !strcmp(p.name, "a.bmp") && fabs(p.w - 50.0) < 1e-3 && fabs(p.h - 40.0) < 1e-3)
                found = 1;
        }
        ck(found, "  読めば mm に戻る（六桁のうちで）");
        for (k = 0; !found && k < e.nobj; k++)
            if (e.obj[k].cls == JW_MOJI)
                printf("     read back: %s\n", txt(&e, k));
    }

    /* ------------------------------------------------ ブロック */
    {
        static const double REFS[2][4] = { { 0.0, 0.0, 2.0, 0.0 }, { 100.0, 0.0, 1.0, 90.0 } };
        fb_t fb;
        jw_view bv;
        rect_t rr;
        int t, at, x, y, x0[2], x1[2], y0[2], y1[2];

        for (t = 0; t < 2; t++) {
            jw_obj *o;

            while (d.nobj > 0)
                jw_remove(&d, d.nobj - 1);
            d.ndrawn = 0;
            o = jw_add(&d, JW_BLOCK);
            o->d[0] = REFS[t][0];
            o->d[1] = REFS[t][1];
            o->d[2] = REFS[t][2];
            o->d[3] = REFS[t][2];
            o->d[4] = REFS[t][3] * 3.14159265358979323846 / 180.0;
            o->block = 0;
            o->color = 2;
            o->ltype = 1;
            o = jw_add(&d, JW_LIST);
            at = (int)(o - d.obj);
            d.obj[at].list[0] = 0;
            d.obj[at].n = 1;
            put_text(&d, "^@BMnone.bmp,20,10", 0.0, 0.0, 0.0);
            d.ndrawn = 1;

            /* 描画: 読めない画像は枠を (0,192,192) の点で描く。その枠の大きさ */
            memset(&fb, 0, sizeof fb);
            ck(fb_init(&fb, 600, 400), "ブロックの描画の画面");
            rr.x = rr.y = 0;
            rr.w = 600;
            rr.h = 400;
            memset(&bv, 0, sizeof bv);
            jw_view_fit(&bv, &rr, d.paper_hw, d.paper_hh);
            bv.clip = rr;
            for (k = 0; k < 600 * 400; k++)
                fb.px[k] = 0xffffff;
            jw_draw(&fb, &bv, &d);
            x0[t] = y0[t] = 99999;
            x1[t] = y1[t] = -1;
            for (y = 0; y < 400; y++)
                for (x = 0; x < 600; x++)
                    if (fb.px[y * 600 + x] == 0x00c0c0u) {
                        if (x < x0[t]) x0[t] = x;
                        if (x > x1[t]) x1[t] = x;
                        if (y < y0[t]) y0[t] = y;
                        if (y > y1[t]) y1[t] = y;
                    }
            fb_free(&fb);
            printf("     枠 %d..%d x %d..%d（1mm = %g 画素）\n", x0[t], x1[t], y0[t], y1[t],
                   jw_ux(&bv, 1.0) - jw_ux(&bv, 0.0));
            if (t == 0) {
                double ww = jw_ux(&bv, 40.0) - jw_ux(&bv, 0.0);
                double hh = jw_uy(&bv, 20.0) - jw_uy(&bv, 0.0);

                ck(x1[0] >= 0 && fabs((x1[0] - x0[0]) - ww) <= 2.0 && fabs((y1[0] - y0[0]) - hh) <= 2.0,
                   "倍率 2 のブロックの中の画像は 40×20 の枠で描く");
            } else {
                double ww = jw_ux(&bv, 10.0) - jw_ux(&bv, 0.0);
                double hh = jw_uy(&bv, 20.0) - jw_uy(&bv, 0.0);

                ck(x1[1] >= 0 && fabs((x1[1] - x0[1]) - ww) <= 2.0 && fabs((y1[1] - y0[1]) - hh) <= 2.0,
                   "90° のブロックの中の画像は 縦長（10×20）の枠で描く");
                ck(x1[1] >= 0 && abs(x0[1] - jw_sx(&bv, 90.0)) <= 2,
                   "  基点の左へ立つ");
            }
            ck(!strcmp(txt(&d, 2), "^@BMnone.bmp,20,10"), "  描いても図面の字はそのまま");

            /* ブロック解除 */
            d.obj[0].sel = 1;
            ck(jw_cmd_block_free(&d) > 0, "ブロック解除");
            for (k = 0, at = -1; k < d.ndrawn; k++)
                if (d.obj[k].cls == JW_MOJI)
                    at = k;
            if (t == 0) {
                ck(at >= 0 && !strcmp(txt(&d, at), "^@BMnone.bmp,40,20"),
                   "  倍率 2: 解いた画像は w・h が倍");
                ck(at >= 0 && near(d.obj[at].d[4], 2.0), "  字の大きさは保つ");
            } else {
                ck(at >= 0 && !strcmp(txt(&d, at), "^@BMnone.bmp,20,10,0,0,1,90,255,255,255"),
                   "  90°: 解いた画像は 文字列の角度が 90");
                ck(at >= 0 && near(d.obj[at].d[0], 100.0) && near(d.obj[at].d[7], 90.0),
                   "  始点は基点、字の角度も 90");
            }
            if (at >= 0)
                printf("     解いた字: %s\n", txt(&d, at));
        }
    }

    /* ------------------------------------------------ 反転した参照の中の画像
       （nokori.md「ブロック」の残り: 画像の文字列の角度を反転でどう変えるか）
       FUN_0048f7f0（decomp/byclass/_unassigned.c:62975-63092、818 バイト、
       9 callers）を読んだ: 名前のあとの数を "%lg,...,%d,%d,%d" で読み、w・h が
       0.001 未満なら何もせず、そうでなければ "^@BM" を書き直すだけの関数
       （名前が "d:\data\030806\" のときの作者の試しの行も入っている）。角度
       には関わらない。これを呼ぶ 倍率の字の枝 FUN_00465f40（同 45148 行、
       3817 バイト。blk_text_post の注にある「前は 始点と終点を入れ替えて
       いた」の読みもここ）は、画像でも ほかの字でも +0xd0（d[7]）を 写った
       基線（始点・終点）から取り直すだけで、"^@BM" の中の角度（六つ目の数、
       jw_pic_angle）を書き換える枝は無い。回転の字の枝 FUN_0046e210 →
       FUN_0046d800 → FUN_0048fb30 が その角度に足すが、それは src/imgpic.c
       の jw_pic_xform にすでに入っていて、倍率が 1・回転が 0 のとき
       （反転だけで 追加の回転が無いとき）は 何もしない（jw_pic_xform の
       scaled・turned が両方 0、行 605-611）。つまり 画像の枠そのものの角度
       （jw_pic_angle）は 反転でも変わらず、字としての向き（+0xd0）・幅・
       高さ・間隔の符号だけが ふつうの字と同じに反転する。すでに
       jw_obj_blkput（blkput0 → blk_text_post）が どの JW_MOJI にも同じ式を
       使っているので、ここでは 同じ始点・終点・大きさ・角の 字と画像を
       同じ反転参照に掛けて d[] が一致すること・画像自身の角度だけ変わらない
       ことを確かめる。逆コンパイルの読み、原典では押していない */
    {
        jw_obj ref, txt_o, pic_o;
        jw_pic p;
        double a0 = 20.0 * 3.14159265358979323846 / 180.0, len = 8.0;
        const char *pic_text = "^@BMnone.bmp,20,10,0,0,1,30,255,255,255";

        memset(&ref, 0, sizeof ref);
        ref.cls = JW_BLOCK;
        ref.d[2] = -1.0;        /* sx: 反転（符号違い） */
        ref.d[3] = 1.0;         /* sy */

        memset(&txt_o, 0, sizeof txt_o);
        txt_o.cls = JW_MOJI;
        txt_o.d[0] = 5.0;
        txt_o.d[1] = 3.0;
        txt_o.d[2] = txt_o.d[0] + cos(a0) * len;
        txt_o.d[3] = txt_o.d[1] + sin(a0) * len;
        txt_o.d[4] = 2.0;
        txt_o.d[5] = 2.0;
        txt_o.d[6] = 0.3;
        txt_o.d[7] = 20.0;
        pic_o = txt_o;
        pic_o.text = jw_add_str(&d, pic_text);

        jw_obj_blkput(&txt_o, &ref);
        jw_obj_blkput(&pic_o, &ref);

        ck(near(pic_o.d[0], txt_o.d[0]) && near(pic_o.d[1], txt_o.d[1]) &&
           near(pic_o.d[2], txt_o.d[2]) && near(pic_o.d[3], txt_o.d[3]) &&
           near(pic_o.d[4], txt_o.d[4]) && near(pic_o.d[5], txt_o.d[5]) &&
           near(pic_o.d[6], txt_o.d[6]) && near(pic_o.d[7], txt_o.d[7]),
           "反転した参照: 画像の字としての向き（+0xd0）・幅高さ間隔の符号は ふつうの字と同じ式");
        ck(!strcmp(jw_str(&d, pic_o.text), pic_text), "  \"^@BM\" の字はそのまま");
        ck(jw_pic_parse(&d, &pic_o, &p) && near(p.d, 30.0),
           "  画像自身の角度（\"^@BM\" の六つ目の数、jw_pic_angle）は 反転でも変わらない");
    }

    /* ------------------------------------------------ 入れ子のブロック
       内: 基点 (10,0)・倍率 x2 y1・0°、外: 基点 (50,0)・倍率 x1 y2・90°。
       原典の FUN_0042b460 は 段ごとに内から 倍率・回転・移動 を掛けるので
       画像 20×10 は 内で ×2（40×20）、外で ×max(1,2)=2（80×40）、90° で
       縦長 40×80。始点は (10,0) を 90° 回して (0,10)+(50,0) = (50,10)、
       幅は +y へ・高さは -x へ伸びるので 枠は x 10..50・y 10..90。
       逆コンパイルの読み、原典では押していない（src/draw.c の block） */
    {
        fb_t fb;
        jw_view bv;
        rect_t rr;
        jw_obj *o;
        int x, y, x0 = 99999, x1 = -1, y0 = 99999, y1 = -1;
        double ww, hh;

        while (d.nobj > 0)
            jw_remove(&d, d.nobj - 1);
        d.ndrawn = 0;
        o = jw_add(&d, JW_BLOCK);
        o->d[0] = 50.0;
        o->d[1] = 0.0;
        o->d[2] = 1.0;
        o->d[3] = 2.0;
        o->d[4] = 90.0 * 3.14159265358979323846 / 180.0;
        o->block = 0;
        o->color = 2;
        o->ltype = 1;
        o = jw_add(&d, JW_LIST);
        o->list[0] = 0;
        o->n = 1;
        o = jw_add(&d, JW_BLOCK);
        o->d[0] = 10.0;
        o->d[1] = 0.0;
        o->d[2] = 2.0;
        o->d[3] = 1.0;
        o->d[4] = 0.0;
        o->block = 1;
        o->color = 2;
        o->ltype = 1;
        o = jw_add(&d, JW_LIST);
        o->list[0] = 1;
        o->n = 1;
        put_text(&d, "^@BMnone.bmp,20,10", 0.0, 0.0, 0.0);
        d.ndrawn = 1;

        memset(&fb, 0, sizeof fb);
        ck(fb_init(&fb, 600, 400), "入れ子のブロックの画面");
        rr.x = rr.y = 0;
        rr.w = 600;
        rr.h = 400;
        memset(&bv, 0, sizeof bv);
        jw_view_fit(&bv, &rr, d.paper_hw, d.paper_hh);
        bv.clip = rr;
        for (k = 0; k < 600 * 400; k++)
            fb.px[k] = 0xffffff;
        jw_draw(&fb, &bv, &d);
        for (y = 0; y < 400; y++)
            for (x = 0; x < 600; x++)
                if (fb.px[y * 600 + x] == 0x00c0c0u) {
                    if (x < x0) x0 = x;
                    if (x > x1) x1 = x;
                    if (y < y0) y0 = y;
                    if (y > y1) y1 = y;
                }
        fb_free(&fb);
        printf("     枠 %d..%d x %d..%d（x 10..50 = %d..%d、y 10..90 = %d..%d）\n", x0, x1, y0, y1,
               jw_sx(&bv, 10.0), jw_sx(&bv, 50.0), jw_sy(&bv, 90.0), jw_sy(&bv, 10.0));
        ww = jw_ux(&bv, 40.0) - jw_ux(&bv, 0.0);
        hh = jw_uy(&bv, 80.0) - jw_uy(&bv, 0.0);
        ck(x1 >= 0 && fabs((x1 - x0) - ww) <= 2.0 && fabs((y1 - y0) - hh) <= 2.0,
           "入れ子: 段ごとに max を取って 40×80 の枠");
        ck(x1 >= 0 && abs(x0 - jw_sx(&bv, 10.0)) <= 2 && abs(x1 - jw_sx(&bv, 50.0)) <= 2,
           "  外の 90° が内の基点も回す（x 10..50）");
        ck(x1 >= 0 && abs(y1 - jw_sy(&bv, 10.0)) <= 2 && abs(y0 - jw_sy(&bv, 90.0)) <= 2,
           "  y 10..90");
        ck(!strcmp(txt(&d, 4), "^@BMnone.bmp,20,10"), "  描いても図面の字はそのまま");
    }

    /* ------------------------------------------------ 図形の置くとき（FUN_00758fb0） */
    {
        jw_drawing f;
        unsigned char *jb = 0;
        long jn = 0;
        int before, last;
        const jw_obj *o;

        memset(&f, 0, sizeof f);
        jw_parse(&f, b, n);
        while (f.nobj > 0)
            jw_remove(&f, f.nobj - 1);
        f.ndrawn = 0;
        put_text(&f, "^@BMfig.bmp,50,40", 10.0, 10.0, 0.0);
        ck(jw_write_jws(&f, 10.0, 10.0, &jb, &jn) && jb, "図形に画像の字を一つ");
        jw_cmd_figure_load(&d, jb, jn);
        jw_cmd_figure_at(2.0, 90.0);
        before = d.nobj;
        jw_cmd_point_ll(&d, &v, 100.0, 100.0);
        for (last = d.nobj - 1; last > 0; last--)
            if (d.obj[last].cls == JW_MOJI && strstr(txt(&d, last), "fig.bmp"))
                break;
        ck(d.nobj == before + 1, "  置くと字が一つ増える");
        o = &d.obj[last];
        printf("     置いた字: %s\n", txt(&d, last));
        ck(!strncmp(txt(&d, last), "^@BMfig.bmp,100,80,0,0,1,90", 27),
           "  倍率 2 で w・h が倍、回転角 90 が画像の角度に");
        ck(near(o->d[4], 2.0) && near(o->d[5], 2.0), "  字の大きさは保つ");
        {
            jw_drawing pvd;
            int pvn;

            jw_cmd_track(150.0, 150.0);
            pvn = jw_cmd_figure_preview(&d, &pvd);
            ck(pvn && pvd.nobj >= 1, "  仮表示が出る");
            if (pvn && pvd.nobj >= 1) {
                printf("     仮表示の字: %s\n", txt(&pvd, 0));
                ck(!strncmp(txt(&pvd, 0), "^@BMfig.bmp,100,80,0,0,1,90", 27),
                   "  仮表示も 倍率 2 で w・h が倍、回転角 90 が画像の角度に");
            }
        }
        free(jb);
        jw_free(&f);
    }

    /* ------------------------------------------------ 画像同梱の図形 (.jws)
     * .jww の画像同梱（jw_write/jw_parse の `version > 0x275` の枝）と同じ
     * tail を .jws にも足した（src/jwwrite.c の jw_write_jws、src/jww.c の
     * jw_parse_jws）。原典の CMiniDoc::Serialize（decomp/byclass/CMiniDoc.c
     * の一つの関数 FUN_00575010）は ".jws"（584 行、DAT_00a0b414）も
     * ".jww"（676 行、DAT_00a0b3e8）も 同じ形の `0x275 < 版` の枝（1729 行・
     * 1832 行）で 画像を読んでおり、.jws だけ埋め込み画像を運べないという
     * 理由は無い（原典を動かしては確かめていない。figreg.jws を含め
     * Jw_cad が同梱の図形を書いた例が手元に無い）。ここは 書いて読み直す
     * 往復だけを確かめる。 */
    {
        jw_drawing f, g;
        unsigned char *jb = 0, *pic = 0;
        long jn = 0, pn = 0;
        const unsigned char *got;
        long gotn = 0;
        int i;

        pn = 600;
        pic = (unsigned char *)malloc((size_t)pn);
        for (i = 0; i < pn; i++)
            pic[i] = (unsigned char)(i * 37 + 11);
        jw_img_put("%temp%embed.bmp", pic, pn);

        memset(&f, 0, sizeof f);
        jw_parse(&f, b, n);
        while (f.nobj > 0)
            jw_remove(&f, f.nobj - 1);
        f.ndrawn = 0;
        f.version = JW_JWS_VERSION;
        put_text(&f, "^@BM%temp%embed.bmp,50,40", 10.0, 10.0, 0.0);
        ck(jw_write_jws(&f, 10.0, 10.0, &jb, &jn) && jb, "画像同梱の図形を書く");

        jw_img_forget();
        ck(!jw_img_get("%temp%embed.bmp"), "  (消してから) 読む前は画像が無い");

        memset(&g, 0, sizeof g);
        ck(jw_parse_jws(&g, jb, jn, 0, 0), "  読み直せる");
        got = jw_img_bytes("%temp%embed.bmp", &gotn);
        ck(got && gotn == pn && !memcmp(got, pic, (size_t)pn),
           "  埋め込んだ画像のバイト列がそのまま戻る");

        free(jb);
        free(pic);
        jw_free(&f);
        jw_free(&g);
        jw_img_forget();
    }

    free(w);
    free(b);
    printf("%s\n", fails ? "FAIL" : "all ok");
    return fails != 0;
}
