/* Outline fonts: a text that names one of ours is set in it.
 *
 *   tests/font_test.exe [sample.png [drawing.jww]]
 *
 * Run from the repository root: the fonts are read from fonts/ (src/outfont.c).
 * Checks, for each of IPAexGothic, IPAexMincho and BIZ UD Gothic, that a
 * string comes out non-blank and different from the others, upright, turned,
 * italic and bold; that the original's own face and a face nobody has heard
 * of still come out as the bitmap font, byte for byte; that Arial, Times New
 * Roman and Century are set in the Latin stand-ins at the width Windows gives
 * them, with IPAex for their Japanese; that 斜体 leans 0.3256 and 太字 has
 * more ink, in the outline and the bitmap font; that the 文字種
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

/* `s` in `face` along a run `run` mm long from (12,2), 8 mm high and cw
   across; answers the ink: how many pixels, the leftmost and rightmost
   column, and the mean column of the rows top..top+7 (*top8) and of the
   eight rows above the baseline row 91 (*foot8) */
static int ink(const char *face, const char *s, double run, double cw,
               int style, int *x0, int *x1, double *top8, double *foot8)
{
    fb_t fb;
    jw_view v = view();
    int i, n = 0, top = H, nt = 0, nf = 0;
    double st = 0.0, sf = 0.0;

    fb.w = W;
    fb.h = H;
    fb.px = img;
    for (i = 0; i < W * H; i++)
        img[i] = 0xffffff;
    jw_text_run_face(&fb, &v, s, 12.0, 2.0, 12.0 + run, 2.0, cw, 8.0,
                     0x000000, 0, face, style);
    *x0 = W;
    *x1 = -1;
    for (i = 0; i < W * H; i++)
        if (img[i] != 0xffffff) {
            n++;
            if (i % W < *x0) *x0 = i % W;
            if (i % W > *x1) *x1 = i % W;
            if (i / W < top) top = i / W;
        }
    for (i = 0; i < W * H; i++)
        if (img[i] != 0xffffff) {
            if (i / W < top + 8) {
                st += i % W;
                nt++;
            }
            if (i / W >= 84 && i / W < 92) {
                sf += i % W;
                nf++;
            }
        }
    *top8 = nt ? st / nt : 0.0;
    *foot8 = nf ? sf / nf : 0.0;
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

    printf("-- Arial, Times New Roman, Century: the Latin stand-ins\n");
    {
        static const char PUDG[] = "BIZ UD\x82o\x83S\x83V\x83" "b\x83N";
        static const char MINCHO[] = "\x82l\x82r \x96\xbe\x92\xa9";
        /* 日本語漢字 */
        static const char JA[] = "\x93\xfa\x96\x7b\x8c\xea\x8a\xbf\x8e\x9a";
        int pr, a0, a1, b0, b1, na, nb2, nr;
        double t, f;
        unsigned long hg;

        ck(jw_outfont_enabled(), "(switched on)");
        ck(jw_outfont_resolve("Arial", &pr) == JW_NOUTFONT && (pr & 1),
           "Arial is the sans stand-in, proportional");
        ck(jw_outfont_resolve("arial", &pr) == JW_NOUTFONT,
           "  whatever the case");
        ck(jw_outfont_resolve("Times New Roman", &pr) == JW_NOUTFONT + 1
           && jw_outfont_resolve("Century", &pr) == JW_NOUTFONT + 1,
           "Times New Roman and Century are the serif one");
        ck(jw_outfont_resolve("Century Gothic", &pr) == JW_NOUTFONT,
           "  but Century Gothic is the sans");
        ck(jw_outfont_resolve(PUDG, &pr) == 2 && (pr & 1),
           "BIZ UDＰゴシック is BIZ UD Gothic, proportional");
        {
            /* メイリオ, CP932: see src/outfont.c resolve_core -- the
               original queries the real font (FUN_004e0fa0,
               decomp/decomp/all_004894cd.c:5218-5245) for
               tmPitchAndFamily, not a name pattern, and this port
               approximates it by name as it already does for the
               "Ｐ"-suffixed MS fonts. */
            static const char MEIRYO[] = "\x83\x81\x83\x43\x83\x8a\x83\x49";

            ck(jw_outfont_resolve(MEIRYO, &pr) == 0 && (pr & 1),
               "メイリオ (Meiryo) is the gothic, proportional");
        }
        ck(jw_outfont_count() == 3 && jw_outfont_find("JwSubSans") < 0,
           "  the stand-ins are not listed, nor found by name");
        ck(jw_outfont_ready(JW_NOUTFONT) && jw_outfont_ready(JW_NOUTFONT + 1),
           "  they are read from fonts/ (jwsubsans.ttf, jwsubserif.ttf)");
        ck(!strcmp(jw_outfont_file(JW_NOUTFONT), "jwsubsans.ttf"),
           "  and the page asks for them by that name");

        draw(MSGOTHIC, 0.0, 0, 0);
        hg = hash();
        draw("Arial", 0.0, 0, 0);
        ck(hash() != hg, "a string in Arial is not the gothic's picture");
        na = ink(MSGOTHIC, JA, 40.0, 8.0, 0, &a0, &a1, &t, &f);
        hg = hash();
        ink("Arial", JA, 40.0, 8.0, 0, &a0, &a1, &t, &f);
        ck(na > 300 && hash() == hg,
           "  its Japanese letters are IPAex Gothic, as ＭＳ ゴシック's");
        ink(MINCHO, JA, 40.0, 8.0, 0, &a0, &a1, &t, &f);
        hg = hash();
        ink("Century", JA, 40.0, 8.0, 0, &a0, &a1, &t, &f);
        ck(hash() == hg, "  and Century's are IPAex Mincho, as ＭＳ 明朝's");

        /* Windows sizes a face by its average width, so Arial Narrow at the
           same width comes out about as wide as Arial, and Century, whose
           average (951) is more above Times New Roman's (821) than its
           letters are wider (1.094), a little narrower than Times */
        na = ink("Arial", "WWWW", 0.0, 8.0, 0, &a0, &a1, &t, &f);
        nb2 = ink("Arial Narrow", "WWWW", 0.0, 8.0, 0, &b0, &b1, &t, &f);
        snprintf(msg, sizeof msg, "Arial Narrow is as wide as Arial (%d, %d px)",
                 b1 - b0, a1 - a0);
        ck(na > 100 && nb2 > 100 && abs((b1 - b0) - (a1 - a0)) <= 3, msg);
        ink("Times New Roman", "abcdefgh", 0.0, 8.0, 0, &a0, &a1, &t, &f);
        nr = ink("Century", "abcdefgh", 0.0, 8.0, 0, &b0, &b1, &t, &f);
        snprintf(msg, sizeof msg, "  Century is 0.944 of Times (%d, %d px)",
                 b1 - b0, a1 - a0);
        ck(nr > 100 && b1 - b0 < a1 - a0 && b1 - b0 > (a1 - a0) * 0.9, msg);
        /* Windows sizes Arial so that its average, 904/2048 of the em, is half
           the width: a W (1933 units) at 8 mm across is 8/2 * 1933/904 mm */
        ink("Arial", "W", 0.0, 8.0, 0, &a0, &a1, &t, &f);
        snprintf(msg, sizeof msg, "  an Arial W 8 mm across is 8.55 mm wide (%d px)",
                 a1 - a0 + 1);
        ck(fabs((a1 - a0 + 1) * 0.25 - 4.0 * 1933 / 904) < 0.75, msg);
        ink("Arial", "W", 0.0, 4.0, 0, &b0, &b1, &t, &f);
        ck(abs((b1 - b0 + 1) * 2 - (a1 - a0 + 1)) <= 3,
           "  and half as wide at 4 mm");

        /* 基線 (baseline, nokori.md「書体」, investigated 2026-10-18):
           src/outfont.c jw_outfont_run reads the Latin stand-in's own
           ascent/descent for the baseline it sits an Arial/Times New
           Roman/etc. text on -- correct only so long as jwsubsans.ttf and
           jwsubserif.ttf stay metric-compatible with the real Arial and
           Times New Roman.  Checked against C:\Windows\Fonts\arial.ttf and
           times.ttf directly (head.unitsPerEm, hhea ascender/descender),
           not by running the original: both match bit for bit (2048 em;
           Arial/jwsubsans.ttf 1854/-434; Times/jwsubserif.ttf 1825/-443).
           This locks that fact down so a future font swap that broke it
           would be caught here. */
        {
            int asc, desc, upem;

            ck(jw_outfont_vmetrics(JW_NOUTFONT, &asc, &desc, &upem)
               && upem == 2048 && asc == 1854 && desc == -434,
               "jwsubsans.ttf's ascent/descent (1854/-434 of 2048 upem) are Arial's, "
               "bit for bit (checked against arial.ttf's head/hhea tables)");
            ck(jw_outfont_vmetrics(JW_NOUTFONT + 1, &asc, &desc, &upem)
               && upem == 2048 && asc == 1825 && desc == -443,
               "jwsubserif.ttf's are Times New Roman's (1825/-443 of 2048), "
               "likewise (checked against times.ttf)");
        }
    }

    /* 2026-10-19: JW_TEXT_ITALIC (0.34) and jw_text_bold_mm's slope/floor
       (src/outfont.h) were measured directly against real Windows GDI --
       CreateFontW with the exact argument list FUN_0048b130 uses
       (decomp/decomp/all_004894cd.c:1116-1119), on ＭＳ ゴシック/ＭＳ 明朝
       (the two faces of the original's own that carry no italic or bold of
       their own), drawn into an in-memory bitmap -- tools/gdifont.c:
       ./tmp/gdifont.exe, no window, no screen read.  Italic lean
       (dx of lean per dy of rise, top-of-ink to bottom-of-ink) came out
       0.336-0.341 for ＭＳ ゴシック and 0.336-0.350 for ＭＳ 明朝 across
       nHeight -30..-400 -- not the same as the 0.3256 FUN_00481d50's box
       widens by (nokori.md "書体"), so 0.34 (real GDI) replaced it.  Bold
       stem widening was +1 device px at every nHeight from 12 to 64 (the
       sizes this test and most on-screen drawing use), growing to +3/+4/+6
       px by 100/200/400 -- not the height/24 "Wine fake bold" smear this
       port used to copy (height/24 would already be 2-3x too much by
       100px). */
    printf("-- 斜体 and 太字\n");
    for (i = 0; i < 2; i++) {
        /* "IIII" upright and italic; bitmap (switched off) and outline */
        int a0, a1, n0, n1, n2;
        double t0, f0, t1, f1, lean;

        jw_outfont_enable(i);
        n0 = ink(MSGOTHIC, "IIII", 30.0, 8.0, 0, &a0, &a1, &t0, &f0);
        n1 = ink(MSGOTHIC, "IIII", 30.0, 8.0, 1, &a0, &a1, &t1, &f1);
        lean = (t1 - f1) - (t0 - f0);
        snprintf(msg, sizeof msg,
                 "%s: italic leans 0.34, real GDI's own (top vs foot %.1f px, 4..10)",
                 i ? "outline" : "bitmap", lean);
        ck(n0 > 100 && n1 > 100 && lean > 4.0 && lean < 10.0, msg);
        n2 = ink(MSGOTHIC, "IIII", 30.0, 8.0, 2, &a0, &a1, &t1, &f1);
        snprintf(msg, sizeof msg, "  bold has more ink (%d > %d)", n2, n0);
        ck(n2 > n0 + n0 / 20, msg);
    }
    {
        /* jw_text_bold_mm itself, against the numbers tools/gdifont.c
           measured: at 8 mm/0.25 mm-per-px = 32 device px (this test's own
           v.mmpp, "view" above), real GDI's extra stem width on ＭＳ ゴシッ
           ク is the +1 device px floor, not a fraction of the height. */
        double got = jw_text_bold_mm(8.0, 0.25);
        snprintf(msg, sizeof msg,
                 "jw_text_bold_mm(8mm, 0.25mm/px) is the 1-device-px floor "
                 "(0.25mm), not Wine's height/24 (0.33mm): got %.4f", got);
        ck(fabs(got - 0.25) < 1e-9, msg);
    }
    jw_outfont_enable(0);
    draw(MSGOTHIC, 0.0, 0, 0);
    ck(hash() == hbit, "upright and light, the bitmap font is as it was");
    jw_outfont_enable(1);

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
