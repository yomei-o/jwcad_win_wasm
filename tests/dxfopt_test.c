/* 基本設定 DXF・SXF・JWC タブの DXF書出し（2202 点を円で・2203 レイヤ名に番号・
 * 2214 UTF-8）を DXF の書き出し（src/dxf.c の jw_dxf_write_opt）に渡したもの。
 *
 * 書き方は原典の読み（点 FUN_00429a10、レイヤ名 FUN_0049dea0、字の書き手
 * FUN_004a7e90。src/dxf.c の注）で、原典では押していない。原典の既定のまま
 * なら今までと一字も変わらないこと（tests/dxf_test.c が答えと比べている）も
 * 確かめる。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/jww.h"
#include "../src/ui.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int has(const unsigned char *b, long n, const char *s)
{
    long m = (long)strlen(s), i;

    for (i = 0; i + m <= n; i++)
        if (!memcmp(b + i, s, (size_t)m))
            return 1;
    return 0;
}

static int hit(int want)
{
    const fb_t *fb = app_fb();
    int x, y;

    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == want) {
                app_press(x, y, 0);
                return 1;
            }
    return 0;
}

static int kh_press(int tab, int id)
{
    if (!app_kihon_open())
        app_command(32891);
    if (!app_kihon_open())
        return 0;
    if (app_kihon_tab() != tab && !hit(-tab - 1))
        return 0;
    return hit(id);
}

static jw_obj *put(jw_drawing *d, int cls, int g, int l, double x, double y)
{
    jw_obj *o = jw_add(d, cls);

    o->color = 2;
    o->ltype = 1;
    o->lgroup = (unsigned short)g;
    o->layer = (unsigned short)l;
    o->d[0] = x;
    o->d[1] = y;
    o->d[2] = x + 10.0;
    o->d[3] = y;
    o->d[4] = o->d[5] = 3.0;
    return o;
}

int main(void)
{
    jw_drawing *d;
    jw_dxf_opt opt;
    unsigned char *a = 0, *b = 0;
    long an = 0, bn = 0;
    jw_obj *t;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    d->group[0].scale = 100.0;
    put(d, JW_TEN, 0, 0, 0.0, 0.0);
    put(d, JW_SEN, 0, 1, 0.0, 0.0);
    put(d, JW_SEN, 0, 2, 0.0, 5.0);
    put(d, JW_SEN, 1, 3, 0.0, 9.0);
    t = put(d, JW_MOJI, 0, 1, 0.0, 20.0);
    t->text = jw_add_str(d, "\x90\x7d\x96\xca");                  /* 図面 */
    d->group[0].layer_name[1] = jw_add_str(d, "\x95\xc7 A");      /* 壁 A */
    d->group[0].layer_name[2] = jw_add_str(d, "");                /* 名無し */
    d->group[1].layer_name[3] = jw_add_str(d, "\x95\xc7 A");      /* 同じ名 */
    d->ndrawn = d->nobj;

    /* ---- 既定は今までどおり ---- */
    opt.point_circle = 0;
    opt.layer_number = 1;
    opt.utf8 = 0;
    ck(jw_dxf_write(d, &a, &an) && jw_dxf_write_opt(d, &opt, &b, &bn) &&
       an == bn && !memcmp(a, b, (size_t)an), "既定の箱は jw_dxf_write と同じ");
    ck(has(a, an, "\r\nPOINT\r\n") && has(a, an, "_0-1_\x95\xc7_A\r\n"),
       "  点は POINT、レイヤ名は番号付き");
    free(b);
    b = 0;
    ck(app_save_dxf(&b, &bn) && bn == an && !memcmp(a, b, (size_t)an),
       "  app_save_dxf も（基本設定 既定のまま）同じ");
    free(b);
    b = 0;

    /* ---- 2202 点を円で ---- */
    opt.point_circle = 1;
    ck(jw_dxf_write_opt(d, &opt, &b, &bn), "点を円で");
    ck(!has(b, bn, "\r\nPOINT\r\n") &&
       has(b, bn, "  0\r\nCIRCLE\r\n  8\r\n_0-0_\r\n 62\r\n   18\r\n 10\r\n"),
       "  POINT の代わりに CIRCLE（8・62・10・20 は同じ）");
    ck(has(b, bn, " 40\r\n40\r\n  0\r\n"), "  40 は 0.4 × 縮尺 100 = 40");
    free(b);
    b = 0;
    opt.point_circle = 0;

    /* ---- 2203 レイヤ名に番号 切 ---- */
    opt.layer_number = 0;
    ck(jw_dxf_write_opt(d, &opt, &b, &bn), "レイヤ名に番号を付けない");
    ck(has(b, bn, "  8\r\n\x95\xc7_A\r\n") && !has(b, bn, "_0-1_"),
       "  名のあるレイヤは名前だけ（空白は '_'）");
    ck(has(b, bn, "  8\r\n_0-2_\r\n"), "  名の無いレイヤは番号");
    ck(has(b, bn, "  8\r\n_1-3_\x95\xc7_A\r\n"), "  前のレイヤと同じ名なら番号付き");
    ck(has(b, bn, "  8\r\n_0-0_\r\n"), "  名の無い 0-0 も番号");
    free(b);
    b = 0;
    opt.layer_number = 1;

    /* ---- 2214 UTF-8 ---- */
    opt.utf8 = 1;
    ck(jw_dxf_write_opt(d, &opt, &b, &bn), "UTF-8");
    ck(has(b, bn, "  1\r\n\xe5\x9b\xb3\xe9\x9d\xa2\r\n"), "  字は UTF-8（図面）");
    ck(has(b, bn, "_0-1_\xe5\xa3\x81_A\r\n"), "  レイヤ名も UTF-8（壁）");
    ck(!has(b, bn, "\x90\x7d\x96\xca"), "  Shift-JIS の字は残らない");
    free(b);
    b = 0;

    /* ---- 基本設定から ---- */
    ck(kh_press(7, 2202), "DXF・SXF・JWC の 点を円で出力する を押す");
    ck(kh_press(7, 2203), "  レイヤ名に番号を付加する を切る");
    hit(1);
    ck(!app_kihon_open(), "  OK");
    ck(app_save_dxf(&b, &bn) && has(b, bn, "\r\nCIRCLE\r\n") &&
       has(b, bn, "  8\r\n\x95\xc7_A\r\n"), "  app_save_dxf に効く");
    free(b);
    free(a);

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
