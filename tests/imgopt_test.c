/* 基本設定 一般 の 画像･ソリッドを最初に描画 (2405) and 透過属性 (2860).
 *
 * Not checked against the original (it could not be driven for these): what is held
 * here is only what the dialog's words say -- the pictures go down with the solids
 * instead of over everything, and a picture's 透過色 is honoured or not -- and that
 * the defaults (off, on) draw as the port always has.  See src/draw.c. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/draw.h"
#include "../src/image.h"
#include "../src/jww.h"
#include "../src/ui.h"
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

/* a 2x2 BMP: top-left white, top-right red, bottom-left red, bottom-right white */
static long quad_bmp(unsigned char *o)
{
    static const unsigned char rows[16] = {
        0, 0, 255,  255, 255, 255,  0, 0,          /* the bottom row: red, white (+2 pad) */
        255, 255, 255,  0, 0, 255,  0, 0           /* the top row: white, red */
    };
    memset(o, 0, 70);
    memcpy(o, "BM", 2);
    o[2] = 70; o[10] = 54; o[14] = 40; o[18] = 2; o[22] = 2; o[26] = 1; o[28] = 24; o[34] = 16;
    memcpy(o + 54, rows, 16);
    return 70;
}

static unsigned int pixel_at(double mx, double my)
{
    const fb_t *fb = app_fb();
    const jw_view *v = app_view();
    int x = (int)(v->bx + (mx - v->ox) * v->scale + 0.5);
    int y = (int)(v->by - (my - v->oy) * v->scale + 0.5);

    return fb->px[(size_t)y * fb->w + x] & 0xffffffu;
}

static void paint(void)
{
    /* a different view and back: the picture is made again, not taken from the last one */
    app_pan(1, 0);
    app_paint();
    app_pan(-1, 0);
    app_paint();
}

int main(void)
{
    unsigned char bmp[70], *base, *w = 0;
    long bn, wn = 0;
    jw_drawing d;
    jw_obj *o;
    unsigned int black, white = 0xffffffu, p;

    app_resize(1264, 741);
    base = slurp("orig/Test5.jww", &bn);
    memset(&d, 0, sizeof d);
    jw_parse(&d, base, bn);
    while (d.nobj > 0)
        jw_remove(&d, d.nobj - 1);
    quad_bmp(bmp);
    jw_img_put("quad.bmp", bmp, 70);
    /* a vertical black line through what is the picture's white top-left quarter */
    o = jw_add(&d, JW_SEN);
    o->d[0] = o->d[2] = 110.0;
    o->d[1] = 100.0;
    o->d[3] = 150.0;
    o->color = 2;
    /* the picture: 40 mm square, lower left at (100, 100) */
    o = jw_add(&d, JW_MOJI);
    o->d[0] = 100.0; o->d[1] = 100.0; o->d[2] = 140.0; o->d[3] = 100.0; o->d[4] = 3; o->d[5] = 3;
    o->color = 1; o->ltype = 1; o->face = -1;
    o->text = jw_add_str(&d, "^@BMquad.bmp,40,40,0,0,1,0,255,255,255");
    d.ndrawn = d.nobj;
    jw_write(&d, &w, &wn);
    ck(app_open(w, wn), "the drawing opens");
    app_fit();

    /* (110, 130) is in the picture's top-left quarter, which is white and so transparent;
       the line runs through it.  (130, 110) is the bottom-right quarter, white too. */
    jw_draw_images_first = 0;
    jw_draw_transparent = 1;
    paint();
    black = pixel_at(110.0, 145.0);           /* the line's own colour, above the picture */
    ck(black != white, "the line is drawn (colour " "reference taken above the picture)");
    p = pixel_at(110.0, 130.0);
    ck(p == black, "defaults: the line shows through the picture's white (transparent) quarter");
    p = pixel_at(130.0, 130.0);
    ck(p != white && p != black, "and the red quarter is red");
    printf("     (red quarter reads %06x)\n", p);

    jw_draw_transparent = 0;
    paint();
    p = pixel_at(110.0, 130.0);
    ck(p == white, "透過属性 off: the white quarter is white and covers the line");

    jw_draw_images_first = 1;
    paint();
    p = pixel_at(110.0, 130.0);
    ck(p == black, "最初に描画 on: the picture goes down first and the line is over it, whatever the transparency");

    jw_draw_transparent = 1;
    paint();
    p = pixel_at(110.0, 130.0);
    ck(p == black, "both: the line is there");
    p = pixel_at(130.0, 130.0);
    ck(p != white && p != black, "and the red quarter is still red");

    /* the line's own picture away from the picture is the same either way */
    p = pixel_at(110.0, 145.0);
    ck(p == black, "the line above the picture is black in every case");

    /* through the dialog: 基本設定, the 一般 tab's two boxes, OK */
    jw_draw_images_first = 0;
    jw_draw_transparent = 1;
    {
        const fb_t *fb = app_fb();
        int x, y, tab, found, pass;

        ck(app_command(32891) || app_kihon_open(), "基本設定 opens");
        for (pass = 0; pass < 2; pass++) {
            int want = pass == 0 ? 2405 : 2860;

            found = 0;
            for (tab = 0; tab < 8 && !found; tab++) {
                /* click the tab by its (negative) id, then look for the box on it */
                for (y = 0; y < fb->h && !found; y++)
                    for (x = 0; x < fb->w; x++)
                        if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == -tab - 1) {
                            app_press(x, y, 0);
                            y = fb->h;
                            break;
                        }
                for (y = 0; y < fb->h && !found; y++)
                    for (x = 0; x < fb->w; x++)
                        if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == want) {
                            app_press(x, y, 0);
                            found = 1;
                            break;
                        }
            }
            ck(found, pass == 0 ? "the 画像･ソリッドを最初に描画 box is found and ticked" : "the 透過属性 box is found and put out");
        }
        ck(jw_draw_images_first == 0, "nothing changes until OK");
        for (y = 0; y < fb->h; y++)
            for (x = 0; x < fb->w; x++)
                if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == 1) {
                    app_press(x, y, 0);
                    y = fb->h;
                    break;
                }
        ck(!app_kihon_open(), "OK closes it");
        ck(jw_draw_images_first == 1 && jw_draw_transparent == 0, "and now the two options are on and off");
    }
    /* 逆順描画 (2444): 同じ所に重ねた二本の線は、ふだん後の線の色、逆順なら先の線の色。
       画面をずらさずに描き直しても変わる（描いた絵の控えの鍵に旗が入っている） */
    {
        jw_drawing *d;
        jw_obj *o;
        unsigned int c0, c1, c2;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_SEN);
        o->d[0] = -50; o->d[1] = 0; o->d[2] = 50; o->d[3] = 0; o->color = 2;
        o = jw_add(d, JW_SEN);
        o->d[0] = -50; o->d[1] = 0; o->d[2] = 50; o->d[3] = 0; o->color = 5;
        jw_draw_reverse = 0;
        app_paint();
        c0 = pixel_at(0.0, 0.0);
        jw_draw_reverse = 1;
        app_paint();
        c1 = pixel_at(0.0, 0.0);
        jw_draw_reverse = 0;
        app_paint();
        c2 = pixel_at(0.0, 0.0);
        ck(c0 == (d->pen_rgb[4] & 0xffffffu) || c0 != c1,
           "two lines on top of each other: the later one shows");
        ck(c1 != c0 && c2 == c0, "逆順描画 puts the earlier one on top, and a repaint alone shows it");
    }
    /* 2112「TextFileをUTF-8出力」は 文字の範囲選択の SJIS/UTF8 釦と同じ旗（DAT_00a0b458） */
    {
        const fb_t *fb = app_fb();
        int x, y, tab, found = 0;

        jw_moji_sjis_set(1);
        app_command(32891);
        for (tab = 0; tab < 8 && !found; tab++) {
            for (y = 0; y < fb->h && !found; y++)
                for (x = 0; x < fb->w; x++)
                    if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == -tab - 1) {
                        app_press(x, y, 0);
                        y = fb->h;
                        break;
                    }
            for (y = 0; y < fb->h && !found; y++)
                for (x = 0; x < fb->w; x++)
                    if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == 2112) {
                        app_press(x, y, 0);
                        found = 1;
                        break;
                    }
        }
        ck(found && jw_moji_sjis() == 1, "2112 is found and ticked; nothing changes until OK");
        for (y = 0; y < fb->h; y++)
            for (x = 0; x < fb->w; x++)
                if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == 1) {
                    app_press(x, y, 0);
                    y = fb->h;
                    break;
                }
        ck(!app_kihon_open() && jw_moji_sjis() == 0, "and OK makes text files UTF-8 (the SJIS button's flag)");
        jw_moji_sjis_set(1);
    }
    /* 1887「文字（寸法図形､ブロック図形）を最後に描画」（既定で印あり）: 字の上を後から
       線が横切っても 字が上に描かれる。印を外すと 要素の順（線が上） */
    {
        jw_drawing *d;
        jw_obj *o;
        unsigned int on, off;

        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_MOJI);
        o->d[0] = -20; o->d[1] = -10; o->d[2] = 0; o->d[3] = -10;
        o->d[4] = 20; o->d[5] = 20; o->color = 5;
        o->text = jw_add_str(d, "\x81\xa1");        /* ■ */
        o = jw_add(d, JW_SEN);
        o->d[0] = -40; o->d[1] = 0; o->d[2] = 40; o->d[3] = 0; o->color = 2;
        jw_draw_texts_last = 1;
        app_paint();
        on = pixel_at(-10.0, 0.0);
        jw_draw_texts_last = 0;
        app_paint();
        off = pixel_at(-10.0, 0.0);
        jw_draw_texts_last = 1;
        ck(off == 0x000000u && on != off,
           "1887: 字は最後に描かれ 線の上に来る（印を外すと 線が上）");
    }
    jw_draw_reverse = 0;
    jw_draw_images_first = 0;
    jw_draw_transparent = 1;
    free(w);
    free(base);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
