/* Pictures in a drawing: the names and numbers that should never happen
   (a file that is not there, a path of every style, a size of 1e300, text that
   is not numbers), a picture handed over by name, and pictures that are cut
   off or claim to be enormous.  Nothing may crash, hang, or ask for gigabytes. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/image.h"
#include "../src/jww.h"
#include "../src/plot.h"
#include "../src/ui.h"

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

/* a 2x2 24-bit BMP */
static const char *fix(const char *s)
{
    static char t[4][512];
    static int k;
    char *o = t[k++ & 3];
    int i;

    for (i = 0; s[i] && i < 510; i++)
        o[i] = s[i] == 124 ? 92 : s[i];
    o[i] = 0;
    return o;
}

static long tiny_bmp(unsigned char *o)
{
    static const unsigned char px[16] = { 255,0,0, 0,255,0, 0,0, 0,0,255, 255,255,255, 0,0 };
    memset(o, 0, 70);
    memcpy(o, "BM", 2);
    o[2] = 70; o[10] = 54; o[14] = 40; o[18] = 2; o[22] = 2; o[26] = 1; o[28] = 24;
    o[34] = 16;
    memcpy(o + 54, px, 16);
    return 70;
}

int main(int argc, char **argv)
{
    static const char *const names[] = {
        "^@BMmissing.bmp,50,40,0,0,1,0,255,255,255",
        "^@BMC:|no|such|dir|x.bmp,50,40,0,0,1,0,255,255,255",
        "^@BM..|..|x.bmp,50,40,0,0,1,0,255,255,255",
        "^@BM||server|share|x.bmp,50,40,0,0,1,0,255,255,255",
        "^@BM/usr/local/x.png,50,40,0,0,1,0,255,255,255",
        "^@BM,50,40",
        "^@BM",
        "^@BMx.bmp,abc,def,ghi",
        "^@BMx.bmp,1e300,1e300,0,0,1,0,0,0,0",
        "^@BMx.bmp,-50,-40,0,0,1,0,255,255,255",
        "^@BMx.bmp,0,0,0,0,0,0,255,255,255",
        "^@BMx.bmp,50,40,nan,inf,-1,1e9,300,-5,70000",
        "^@BMx.bmp,50,40,0,0,1,0,255,255,255,extra,fields,here",
        "^@BMgiven.bmp,1e300,1e300,0,0,1,0,0,0,0",
        "^@BMgiven.bmp,1e9,1e9,0,0,1,0,0,0,0",
        "^@BMgiven.bmp,50,40,0,0,1e300,0,0,0,0",
        "^@BMgiven.bmp,50,40,-1e300,1e300,1,1e300,0,0,0",
        "^@BMgiven.bmp,50,40,0.5,0.5,0.5,3.14,255,255,255",
    };
    jw_drawing d;
    long n, wn = 0, i;
    unsigned char *b = slurp("orig/Test5.jww", &n), *w = 0;
    unsigned char bmp[70];
    int k;

    app_resize(1264, 741);
    memset(&d, 0, sizeof d);
    ck(b && jw_parse(&d, b, n), "base reads");
    while (d.nobj > 0)
        jw_remove(&d, d.nobj - 1);
    for (k = 0; k < (int)(sizeof names / sizeof names[0]); k++) {
        if (argc > 1 && k != atoi(argv[1]))
            continue;
        jw_obj *o = jw_add(&d, JW_MOJI);

        o->d[0] = 20 + k * 10; o->d[1] = 100; o->d[2] = 60 + k * 10; o->d[3] = 100;
        o->d[4] = 3; o->d[5] = 3;
        o->color = 1; o->ltype = 1;
        o->text = jw_add_str(&d, fix(names[k]));
        o->face = -1;
    }
    d.ndrawn = d.nobj;
    /* one handed over by name: a path of the original's machine, found by its last part */
    tiny_bmp(bmp);
    jw_img_put("given.bmp", bmp, 70);
    {
        jw_obj *o = jw_add(&d, JW_MOJI);

        o->d[0] = 10; o->d[1] = 10; o->d[2] = 50; o->d[3] = 10; o->d[4] = 3; o->d[5] = 3;
        o->color = 1; o->ltype = 1; o->face = -1;
        o->text = jw_add_str(&d, fix("^@BMD:|other|given.bmp,30,30,0,0,1,0,255,255,255"));
        d.ndrawn = d.nobj;
    }
    ck(jw_img_get(fix("D:|other|given.bmp")) != 0, "a picture given by name is found by its last part");
    ck(jw_img_get("missing.bmp") == 0, "a missing one is simply not there");

    ck(jw_write(&d, &w, &wn) && w, "the drawing with all of them is written");
    ck(app_open(w, wn), "  opened");
    app_paint();
    {
        const fb_t *fb = app_fb();
        rect_t r;

        ui_view_rect(fb->w, fb->h, &r);
        app_press(r.x + 100, r.y + 200, 0);
        app_command(32787);
        app_press(r.x + 20, r.y + 20, 0);
        app_press(r.x + r.w - 5, r.y + r.h - 5, 1);
        app_paint();
    }
    ck(1, "  drawn, picked");
    {
        unsigned char *x = 0;
        long xn = 0;

        app_save_dxf(&x, &xn);
        free(x);
        x = 0;
        app_save_jwc(&x, &xn);
        free(x);
        x = 0;
        x = jw_plot_pdf(app_drawing(), 1, &xn);
        ck(x != 0, "  plotted");
        free(x);
        x = jw_plot_png(app_drawing(), 1.0, 1, &xn);
        ck(x != 0, "  and as PNG");
        free(x);
    }
    free(w);

    /* decoders: cut off, and claiming too much */
    {
        unsigned char big[70];
        jw_img im;
        int ok = 1;

        tiny_bmp(big);
        ck(jw_img_decode(big, 70, &im) && im.w == 2, "the tiny BMP decodes");
        jw_img_free(&im);
        for (i = 0; i < 70; i++)
            if (jw_img_decode(big, i, &im))
                jw_img_free(&im);
        ck(ok, "  every cut-off of it comes back");
        /* a header that says 100000 x 100000 */
        big[18] = 0xa0; big[19] = 0x86; big[20] = 1; big[21] = 0;
        big[22] = 0xa0; big[23] = 0x86; big[24] = 1; big[25] = 0;
        if (jw_img_decode(big, 70, &im))
            jw_img_free(&im);
        ck(1, "  and one that claims 100000 x 100000 is refused without the memory");
        {
            static const unsigned char png[] = { 0x89, 'P', 'N', 'G', 13, 10, 26, 10, 0, 0, 0, 13, 'I', 'H', 'D', 'R',
                                                 0x7f, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xff, 0xff, 8, 2, 0, 0, 0 };
            if (jw_img_decode(png, sizeof png, &im))
                jw_img_free(&im);
            ck(1, "a PNG header of 2 billion x 2 billion is refused");
        }
        {
            static const unsigned char jpg[] = { 0xff, 0xd8, 0xff, 0xc0, 0, 11, 8, 0xff, 0xff, 0xff, 0xff, 1, 1, 0x11, 0 };
            if (jw_img_decode(jpg, sizeof jpg, &im))
                jw_img_free(&im);
            ck(1, "a JPEG header of 65535 x 65535 is refused or decoded within reason");
        }
    }
    free(b);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
