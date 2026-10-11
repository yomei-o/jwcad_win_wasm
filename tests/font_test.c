/* Outline fonts: a text that names one of ours is set in it.
 *
 *   tests/font_test.exe [sample.png [drawing.jww]]
 *
 * Run from the repository root: the fonts are read from fonts/ (src/outfont.c).
 * Checks, for each of IPAexGothic, IPAexMincho and BIZ UD Gothic, that a
 * string comes out non-blank and different from the others, upright, turned,
 * italic and bold; that the original's own face and a face nobody has heard
 * of still come out as the bitmap font, byte for byte; that the 文字種
 * dialog's フォント box lists ours and OK makes new texts carry the pick; and
 * that the pick is in the saved .jww, so a reopened file keeps it.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/text.h"
#include "../src/outfont.h"
#include "../src/jww.h"
#include "../src/gen/layout.h"
#include "../src/gen/moji.h"
#include "../src/gen/cmds.h"
#include "../src/gen/bars.h"
/* src/png.h and tests/png.h share a guard, so this one is spelled out */
unsigned char *png_encode(const unsigned char *rgb, int w, int h, long *len);

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

#define W 420
#define H 120
static unsigned int img[W * H];

/* "日本語 ABC 漢字ｱｲ" in CP932 */
static const char SAMPLE[] = "\x93\xfa\x96\x7b\x8c\xea ABC \x8a\xbf\x8e\x9a\xb1\xb2";
static const char MSGOTHIC[] = "\x82l\x82r \x83S\x83V\x83" "b\x83N";

static jw_view view(void)
{
    jw_view v;

    memset(&v, 0, sizeof v);
    v.mmpp = 0.25;
    v.scale = 4.0;
    v.bx = 0;
    v.by = H - 20;
    v.clip.x = 0;
    v.clip.y = 0;
    v.clip.w = W;
    v.clip.h = H;
    return v;
}

/* the sample at (10,0) mm, 8 mm a character, the run as long as its
   characters say; draws into img and answers how many pixels are not white */
static int draw(const char *face, double ang, int style, int tate)
{
    fb_t fb;
    jw_view v = view();
    int i, n = 0;
    double c = cos(ang), s = sin(ang), run = 8.0 * 9 + 4.0 * 5 + 0.5 * 4;

    fb.w = W;
    fb.h = H;
    fb.px = img;
    for (i = 0; i < W * H; i++)
        img[i] = 0xffffff;
    jw_text_run_face(&fb, &v, SAMPLE, 12.0, 2.0, 12.0 + run * c, 2.0 + run * s,
                     tate ? 4.0 : 8.0, 8.0, 0x000000, tate, face, style);
    for (i = 0; i < W * H; i++)
        n += img[i] != 0xffffff;
    return n;
}

static void save_png(const char *path)
{
    static unsigned char rgb[W * H * 3];
    long len;
    unsigned char *p;
    FILE *f;
    int i;

    for (i = 0; i < W * H; i++) {
        rgb[i * 3] = (unsigned char)(img[i] >> 16);
        rgb[i * 3 + 1] = (unsigned char)(img[i] >> 8);
        rgb[i * 3 + 2] = (unsigned char)img[i];
    }
    p = png_encode(rgb, W, H, &len);
    f = p ? fopen(path, "wb") : 0;
    if (f) {
        fwrite(p, 1, (size_t)len, f);
        fclose(f);
    }
    free(p);
}

static unsigned long hash(void)
{
    unsigned long h = 5381;
    int i;

    for (i = 0; i < W * H; i++)
        h = h * 33 + img[i];
    return h;
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

static int ctl_xy(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_moji_rect(1264, 741, &r);
    for (i = 0; i < JW_NMOJI; i++)
        if (jw_moji[i].id == id) {
            *x = r.x + JW_MOJI_BORDER + jw_moji[i].x + jw_moji[i].w / 2;
            *y = r.y + JW_MOJI_CAPTION + jw_moji[i].y + jw_moji[i].h / 2;
            return 1;
        }
    return 0;
}

static int bar_xy(int id, int *x, int *y)
{
    int i;

    for (i = 0; i < (int)(sizeof jw_bar_32806 / sizeof jw_bar_32806[0]); i++)
        if (jw_bar_32806[i].id == id) {
            *x = jw_bar_32806[i].x + jw_bar_32806[i].w / 2;
            *y = jw_bar_32806[i].y + jw_bar_32806[i].h / 2;
            return 1;
        }
    return 0;
}

/* the last text in the drawing, or NULL */
static const jw_obj *last_text(const jw_drawing *d)
{
    int i;

    for (i = d->ndrawn - 1; i >= 0; i--)
        if (d->obj[i].cls == JW_MOJI)
            return &d->obj[i];
    return 0;
}

int main(int argc, char **argv)
{
    unsigned long hf[JW_NOUTFONT], hbit;
    int i, n, x, y, nbit;
    char msg[200];
    unsigned char fill[16];

    (void)fill;
    printf("-- the outline fonts\n");
    ck(jw_outfont_count() == 3, "three outline fonts");
    ck(jw_outfont_find("IPAexGothic") == 0 && jw_outfont_find("ipaexmincho") == 1
       && jw_outfont_find("BIZ UDGothic") == 2,
       "their names are found, whatever the case");
    ck(jw_outfont_find("IPAex\x83\x53\x83\x56\x83\x62\x83\x4e") == 0
       && jw_outfont_find("IPAex\x96\xbe\x92\xa9") == 1
       && jw_outfont_find("BIZ UD\x83\x53\x83\x56\x83\x62\x83\x4e") == 2,
       "and so are the Japanese spellings");
    ck(jw_outfont_find(MSGOTHIC) < 0 && jw_outfont_find("") < 0
       && jw_outfont_find(0) < 0 && jw_outfont_find("IPAexGothi") < 0,
       "the original's faces and strangers are not ours");

    /* what the bitmap font made of it, before any outline font has been read */
    nbit = draw(MSGOTHIC, 0.0, 0, 0);
    hbit = hash();
    ck(nbit > 100, "the original's face is drawn with the bitmap font");
    ck(draw(0, 0.0, 0, 0) == nbit && hash() == hbit,
       "  and so is no face at all, the same pixels");
    ck(draw("Nobody Sans", 0.0, 0, 0) == nbit && hash() == hbit,
       "  and a face nobody has heard of");

    for (i = 0; i < jw_outfont_count(); i++) {
        int ok = jw_outfont_ready(i);

        snprintf(msg, sizeof msg, "%s is read from fonts/", jw_outfont_name(i));
        ck(ok, msg);
        n = draw(jw_outfont_name(i), 0.0, 0, 0);
        hf[i] = hash();
        snprintf(msg, sizeof msg, "  and a string in it is not blank (%d pixels)", n);
        ck(ok && n > 300, msg);
        ck(hf[i] != hbit, "  and is not the bitmap font's");
        if (argc > 1 && i == 0)
            save_png(argv[1]);
        n = draw(jw_outfont_name(i), 0.5236, 0, 0);
        snprintf(msg, sizeof msg, "  turned 30 degrees it is not blank (%d)", n);
        ck(n > 300, msg);
        n = draw(jw_outfont_name(i), 1.5708, 0, 0);
        ck(n > 300, "  nor turned a quarter");
        n = draw(jw_outfont_name(i), 0.0, 1, 0);
        ck(n > 300 && hash() != hf[i], "  italic is a different picture");
        n = draw(jw_outfont_name(i), 0.0, 2, 0);
        ck(n > 300 && hash() != hf[i], "  and so is bold");
        n = draw(jw_outfont_name(i), 0.0, 0, 1);
        ck(n > 300, "  and 縦書き is not blank");
        /* the hand-over of the face as the file stores it */
        n = draw(jw_outfont_name(i), 0.0, 0, 0);
        ck(hash() == hf[i], "  and it comes out the same again (the cache)");
    }
    ck(hf[0] != hf[1] && hf[0] != hf[2] && hf[1] != hf[2],
       "the three fonts draw three different pictures");
    ck(draw(MSGOTHIC, 0.0, 0, 0) == nbit && hash() == hbit,
       "the original's face is still the bitmap font once they are loaded");

    printf("-- the original's own faces, once outline fonts are switched on\n");
    {
        static const char PGOTHIC[] = "\x82l\x82r \x82o\x83S\x83V\x83" "b\x83N";
        static const char MINCHO[] = "\x82l\x82r \x96\xbe\x92\xa9";
        static const char PMINCHO[] = "\x82l\x82r \x82o\x96\xbe\x92\xa9";
        unsigned long hg, hm;

        ck(!jw_outfont_enabled(), "they are off in the library, as the pixel tests need");
        draw("IPAexGothic", 0.0, 0, 0);
        hg = hash();
        draw("IPAexMincho", 0.0, 0, 0);
        hm = hash();
        jw_outfont_enable(1);
        n = draw(MSGOTHIC, 0.0, 0, 0);
        ck(n > 300 && hash() == hg, "ＭＳ ゴシック is then IPAexGothic, pixel for pixel");
        draw(0, 0.0, 0, 0);
        ck(hash() == hg, "  and so is a text with no face");
        draw("Nobody Sans", 0.0, 0, 0);
        ck(hash() == hg, "  and a face nobody has heard of");
        draw(MINCHO, 0.0, 0, 0);
        ck(hash() == hm, "ＭＳ 明朝 is IPAexMincho");
        n = draw(PGOTHIC, 0.0, 0, 0);
        ck(n > 300 && hash() != hg, "ＭＳ Ｐゴシック is proportional: not the gothic's picture");
        n = draw(PMINCHO, 0.0, 0, 0);
        ck(n > 300 && hash() != hm, "ＭＳ Ｐ明朝 likewise");
        jw_outfont_enable(0);
        draw(MSGOTHIC, 0.0, 0, 0);
        ck(hash() == hbit, "switched off again it is the bitmap font");
        jw_outfont_enable(1);
    }

    printf("-- picking one in the 文字種 dialog\n");
    app_resize(1264, 741);
    {
        long len;
        unsigned char *b = slurp("orig/Test5.jww", &len);

        ck(b && app_open(b, len), "Test5.jww opens");
        free(b);
    }
    jw_cmd_set(JW_CMD_MOJI);
    ck(!strcmp(jw_cmd_moji_face(), MSGOTHIC), "new texts start out in the original's face");
    ck(bar_xy(1843, &x, &y), "the 文字 bar has the 文字種 button");
    app_press(x, y, 0);
    ck(app_moji_open() && app_moji_font() == 0, "the dialog is up, on the default font");
    ck(app_moji_font_n() == 7, "the フォント box lists the four MS faces and the three");
    ck(ctl_xy(1423, &x, &y), "the dialog has the フォント box");
    app_press(x, y, 0);
    ck(app_moji_drop() == 2, "  pressing it drops the font list");
    app_paint();
    {   /* row 5: IPAexMincho */
        rect_t dr;
        int k, cy = 0, th = jw_text_height();

        ui_moji_rect(1264, 741, &dr);
        for (k = 0; k < JW_NMOJI; k++)
            if (jw_moji[k].id == 1423)
                cy = dr.y + JW_MOJI_CAPTION + jw_moji[k].y + jw_moji[k].h;
        ck(ui_moji_drop_hit(1264, 741, x, cy + 1 + 5 * th + th / 2) == 5,
           "  its sixth row is under the cursor there");
        app_press(x, cy + 1 + 5 * th + th / 2, 0);
    }
    ck(app_moji_font() == 5 && !strcmp(app_moji_font_item(5), "IPAexMincho")
       && !app_moji_drop(), "  and a press on it picks IPAexMincho");
    ck(!strcmp(jw_cmd_moji_face(), MSGOTHIC), "  which is not in force until OK");
    app_paint();
    ck(ctl_xy(1, &x, &y), "OK is there");
    app_press(x, y, 0);
    ck(!app_moji_open() && !strcmp(jw_cmd_moji_face(), "IPAexMincho"),
       "OK makes it the face new texts carry");

    {   /* write a text */
        const jw_drawing *d;
        const jw_obj *o;
        rect_t vr;
        unsigned char *out;
        long olen;
        jw_drawing *d2;

        app_key('A');
        ui_view_rect(1264, 741, &vr);
        app_press(vr.x + 500, vr.y + 400, 0);
        d = app_drawing();
        o = last_text(d);
        ck(o && !strcmp(jw_str(d, o->text), "A") && o->face >= 0
           && !strcmp(jw_str(d, o->face), "IPAexMincho"),
           "a new text carries IPAexMincho as its face");
        app_paint();
        ck(app_save(&out, &olen) && olen > 0, "the drawing saves");
        if (argc > 2) {     /* for tests/wasm_check.js --font */
            FILE *f = fopen(argv[2], "wb");

            if (f) {
                fwrite(out, 1, (size_t)olen, f);
                fclose(f);
            }
        }
        ck(app_open(out, olen), "  and the saved file opens again");
        d = app_drawing();
        o = last_text(d);
        ck(o && o->face >= 0 && !strcmp(jw_str(d, o->face), "IPAexMincho"),
           "  and its text still names IPAexMincho");
        (void)d2;
        app_paint();
    }
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
