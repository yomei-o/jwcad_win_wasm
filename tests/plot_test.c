/* 印刷 -- the PDF and the PNG, against the PDF the original printed.
 *
 *   tests/plot_test.exe [tests/out/plot.pdf tests/out/plot.png]
 *
 * decomp/res/print_small.txt is what came out of the original when it was
 * made to print (tools/probe29.sh .. probe33.sh): ファイル > 印刷 puts up
 * the Windows printer dialog, OK takes it into a print mode whose bar has
 * 印刷 (L) on 1065, and the printer here is Microsoft Print To PDF, so
 * what it wrote is a PDF that can be read.
 *
 * The drawing was a new A-2 sheet with one line on it, from
 * (-33.0612,-4.2857) to (28.1633,-34.8980) in sheet millimetres, and the
 * printer's page was A4, 210 x 297.  What the original put on that page:
 *
 *     0.750000 0 0 -0.750000 0 841.920044 cm   96 dpi, y downwards
 *     0 0 0 RG        black
 *     1 J  1 j        round caps, round joins
 *     0.640 w         the width
 *     271.839996 577.440002 m  503.200012 693.119995 l  S
 *
 * and four things come out of those numbers, which this checks first:
 *
 *   one to one   the line is 231.36 by 115.68 units at 96 dpi, which is
 *                61.2245 by 30.6122 mm -- the length it has on the sheet
 *   centred      its start is 71.92, 152.76 mm from the top left of the
 *                page, and the page's middle is 105, 148.5: the sheet's
 *                own (-33.0612, -4.2857) with y the other way up
 *   the width    0.640 units at 96 dpi is 0.1693 mm, and the drawing's
 *                print_width for that pen is 2: 2/300 of an inch
 *   black        カラー印刷 is off as the print bar comes up
 *
 * Then the port is made to print the same line and held to the same four.
 * Its page is the sheet rather than a printer's paper -- there is no
 * printer to ask -- so what is compared is the place on the page relative
 * to the middle, which is what the original's own numbers fix.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/plot.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void cknear(double got, double want, double tol, const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.4f / %.4f)\n", ok ? "ok" : "BAD", what, got, want);
    if (!ok)
        fails++;
}

/* what the original printed, read off decomp/res/print_small.txt */
#define O_X0   271.839996           /* device units, 96 dpi, y downwards */
#define O_Y0   577.440002
#define O_X1   503.200012
#define O_Y1   693.119995
#define O_W      0.640              /* the line width, same units */
#define O_PAGE_W 595.32001          /* the page, in points */
#define O_PAGE_H 841.92004
#define SHEET_X0 (-33.0612)         /* the line, in sheet millimetres */
#define SHEET_Y0  (-4.2857)
#define SHEET_X1  28.1633
#define SHEET_Y1 (-34.8980)

/* find "<x> <y> m" and "<x> <y> l" in a content stream */
static int two_points(const char *s, double *x0, double *y0,
                      double *x1, double *y1)
{
    const char *m = strstr(s, " m ");
    const char *l;
    const char *p;

    if (!m)
        return 0;
    for (p = m; p > s && p[-1] != '\n'; p--)
        ;
    if (sscanf(p, "%lf %lf m %lf %lf l", x0, y0, x1, y1) == 4)
        return 1;
    l = strstr(m, " l");
    return l && sscanf(p, "%lf %lf", x0, y0) == 2
        && sscanf(m + 3, "%lf %lf", x1, y1) == 2;
}

int main(int argc, char **argv)
{
    const double u2mm = 25.4 / 96.0;    /* the original's device units */
    const double mm2pt = 72.0 / 25.4;
    jw_drawing *d;
    unsigned char *pdf, *png;
    long plen, glen;
    double wide, tall, x0, y0, x1, y1;
    char *text;

    /* --- the rule, out of the original's own numbers ----------------- */
    /* The sheet coordinates above are worked back from where the two
       clicks landed, so they are only good to a hundredth of a
       millimetre; the rule they are being held to -- one to one, the
       sheet's middle on the page's middle -- is pinned far tighter than
       the 0.03 allowed here. */
    cknear((O_X1 - O_X0) * u2mm, SHEET_X1 - SHEET_X0, 0.03,
           "原典: 印刷は横も原寸");
    cknear((O_Y1 - O_Y0) * u2mm, -(SHEET_Y1 - SHEET_Y0), 0.03,
           "原典: 縦も原寸（y は逆向き）");
    cknear(O_X0 * u2mm, O_PAGE_W / mm2pt / 2.0 + SHEET_X0, 0.03,
           "原典: 用紙の中心が紙の中心に来る（x）");
    cknear(O_Y0 * u2mm, O_PAGE_H / mm2pt / 2.0 - SHEET_Y0, 0.03,
           "原典: 同じく y");
    cknear(O_W * u2mm, 2.0 * 25.4 / 300.0, 5e-4,
           "原典: 太さは print_width の 300dpi ドット");

    /* --- and the port, printing the same line ------------------------ */
    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *o = jw_add(d, JW_SEN);
        ck(o != 0, "線を一本置く");
        if (!o)
            return 1;
        o->color = 2;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->d[0] = SHEET_X0;
        o->d[1] = SHEET_Y0;
        o->d[2] = SHEET_X1;
        o->d[3] = SHEET_Y1;
    }
    jw_plot_paper(d, &wide, &tall);
    cknear(wide, 594.0, 1e-9, "頁は用紙の幅（A-2）");
    cknear(tall, 420.0, 1e-9, "頁は用紙の高さ");

    pdf = jw_plot_pdf(d, 0, &plen);
    ck(pdf != 0 && plen > 400, "PDF が出る");
    if (!pdf)
        return 1;
    text = (char *)malloc((size_t)plen + 1);
    memcpy(text, pdf, (size_t)plen);
    text[plen] = 0;
    {
        char want[128];
        sprintf(want, "/MediaBox[0 0 %.2f %.2f]", wide * mm2pt, tall * mm2pt);
        ck(strstr(text, want) != 0, "  MediaBox は用紙そのもの");
        if (!strstr(text, want))
            printf("     %s がない\n", want);
    }
    ck(strstr(text, "1 J\n1 j\n") != 0, "  丸い端と丸い角（原典と同じ）");
    ck(strstr(text, "0.000 0.000 0.000 RG") != 0, "  墨で刷る");
    {
        char want[64];
        sprintf(want, "%.3f w", 2.0 * 25.4 / 300.0 * mm2pt);
        ck(strstr(text, want) != 0, "  太さも原典と同じ");
        if (!strstr(text, want))
            printf("     %s がない\n", want);
    }
    if (two_points(text, &x0, &y0, &x1, &y1)) {
        cknear(x0 / mm2pt - wide / 2.0, SHEET_X0, 1e-2,
               "  始点は用紙の中心から測って同じところ（x）");
        cknear(y0 / mm2pt - tall / 2.0, SHEET_Y0, 1e-2, "  同じく y");
        cknear((x1 - x0) / mm2pt, SHEET_X1 - SHEET_X0, 1e-2,
               "  長さも原寸（x）");
        cknear((y1 - y0) / mm2pt, SHEET_Y1 - SHEET_Y0, 1e-2, "  同じく y");
    } else {
        ck(0, "  PDF から線が読み取れる");
    }
    if (argc > 1) {
        FILE *f = fopen(argv[1], "wb");
        if (f) {
            fwrite(pdf, 1, (size_t)plen, f);
            fclose(f);
            printf("     wrote %s (%ld bytes)\n", argv[1], plen);
        }
    }
    free(text);
    free(pdf);

    /* the nine line types: eight dash arrays and no 補助線, which is
       what came back from the original's own printer (probe34.sh, and
       decomp/res/print_dash.txt) */
    {
        static const char *WANT[] = {
            "[1.693 1.693] 0 d", "[3.429 3.429] 0 d", "[5.165 1.736] 0 d",
            "[8.932 1.778 1.778 1.778] 0 d",
            "[23.199 1.778 1.778 1.778] 0 d",
            "[7.154 1.778 0.889 1.778 0.889 1.778] 0 d",
            "[21.421 1.778 0.889 1.778 0.889 1.778] 0 d"
        };
        jw_drawing *e;
        unsigned char *q;
        long qn;
        char *t;
        int i, ok = 1;

        app_new();
        e = (jw_drawing *)app_drawing();
        for (i = 1; i <= 9; i++) {
            jw_obj *o = jw_add(e, JW_SEN);
            if (!o)
                break;
            o->color = 2;
            o->ltype = (unsigned char)i;
            o->layer = 0;
            o->lgroup = 0;
            o->d[0] = -100.0;
            o->d[1] = 100.0 - i * 20.0;
            o->d[2] = 100.0;
            o->d[3] = 100.0 - i * 20.0;
        }
        q = jw_plot_pdf(e, 0, &qn);
        ck(q != 0, "九つの線種を刷る");
        if (q) {
            t = (char *)malloc((size_t)qn + 1);
            memcpy(t, q, (size_t)qn);
            t[qn] = 0;
            for (i = 0; i < 7; i++)
                if (!strstr(t, WANT[i])) {
                    printf("     %s がない\n", WANT[i]);
                    ok = 0;
                }
            ck(ok, "  八つの線種が原典の刻みで出る");
            /* 補助線 is nine lines in and eight out */
            {
                int n = 0;
                const char *r = t;
                while ((r = strstr(r, " m ")) != 0) {
                    n++;
                    r += 3;
                }
                ck(n == 8, "  引いた九本のうち刷られるのは八本（補助線は出ない）");
                if (n != 8)
                    printf("     %d 本出ている\n", n);
            }
            free(t);
            free(q);
        }
        app_new();
        d = (jw_drawing *)app_drawing();
        {
            jw_obj *o = jw_add(d, JW_SEN);
            if (o) {
                o->color = 2;
                o->ltype = 1;
                o->d[0] = SHEET_X0;
                o->d[1] = SHEET_Y0;
                o->d[2] = SHEET_X1;
                o->d[3] = SHEET_Y1;
            }
        }
    }

    /* points, colours and a solid: tools/probe35.sh printed
       tools/mkpoints.c's drawing twice, once black and once with
       カラー印刷 ticked, and decomp/res/print_points.txt is the second.
       Four things came out of it. */
    {
        jw_drawing *e;
        unsigned char *q;
        long qn;
        char *t;
        int i;

        app_new();
        e = (jw_drawing *)app_drawing();
        for (i = 0; i < 2; i++) {       /* one point of each kind */
            jw_obj *o = jw_add(e, JW_TEN);
            if (!o)
                break;
            o->color = 2;
            o->ltype = 1;
            o->d[0] = -80.0 + i * 40.0;
            o->d[1] = 60.0;
            o->n = 1 - i;
        }
        for (i = 1; i <= 9; i++) {      /* one line of each colour */
            jw_obj *o = jw_add(e, JW_SEN);
            if (!o)
                break;
            o->color = (unsigned short)i;
            o->ltype = 1;
            o->d[0] = -80.0;
            o->d[1] = 20.0 - i * 10.0;
            o->d[2] = 80.0;
            o->d[3] = 20.0 - i * 10.0;
        }
        {
            jw_obj *o = jw_add(e, JW_SOLID);
            if (o) {
                o->color = 4;
                o->ltype = 1;
                o->d[0] = -80; o->d[1] = -80;
                o->d[2] = -40; o->d[3] = -80;
                o->d[4] = -40; o->d[5] = -60;
                o->d[6] = -80; o->d[7] = -60;
            }
        }
        q = jw_plot_pdf(e, 1, &qn);     /* カラー印刷 */
        ck(q != 0, "点と色と塗りを刷る");
        if (q) {
            int n = 0;
            const char *r;
            t = (char *)malloc((size_t)qn + 1);
            memcpy(t, q, (size_t)qn);
            t[qn] = 0;
            /* the widths are print_width in 300 dpi dots */
            ck(strstr(t, "0.240 w") != 0, "  太さは print_width のドット数");
            /* the colours are print_rgb */
            ck(strstr(t, "0.000 1.000 1.000 RG") != 0, "  線色1 は水色");
            ck(strstr(t, "1.000 1.000 0.000 RG") != 0, "  線色4 は黄");
            ck(strstr(t, "0.000 0.502 0.502 RG") != 0, "  線色7 は鴨の羽色");
            /* 補助線色 (9) does not print: nine lines in, eight out */
            r = t;
            while ((r = strstr(r, " m ")) != 0) {
                n++;
                r += 3;
            }
            ck(n == 8 + 5 + 1,
               "  線は八本、点は一つ（五筆）、塗りが一つ");
            if (n != 14)
                printf("     %d 本出ている\n", n);
            ck(strstr(t, "h B*") != 0, "  塗りは塗って縁もなぞる");
            free(t);
            free(q);
        }
        app_new();
        d = (jw_drawing *)app_drawing();
        {
            jw_obj *o = jw_add(d, JW_SEN);
            if (o) {
                o->color = 2;
                o->ltype = 1;
                o->d[0] = SHEET_X0;
                o->d[1] = SHEET_Y0;
                o->d[2] = SHEET_X1;
                o->d[3] = SHEET_Y1;
            }
        }
    }

    png = jw_plot_png(d, 2.0, 0, &glen);
    ck(png != 0 && glen > 100, "PNG も出る");
    if (png) {
        ck(png[0] == 0x89 && png[1] == 'P' && png[2] == 'N' && png[3] == 'G',
           "  PNG の印がある");
        if (argc > 2) {
            FILE *f = fopen(argv[2], "wb");
            if (f) {
                fwrite(png, 1, (size_t)glen, f);
                fclose(f);
                printf("     wrote %s (%ld bytes)\n", argv[2], glen);
            }
        }
        free(png);
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
