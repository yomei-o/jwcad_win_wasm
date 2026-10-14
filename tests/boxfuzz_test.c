/* Garbage in every box of every command's bar.
 *
 *   tests/boxfuzz_test.exe [orig/Test1.jww]
 *
 * For each command the toolbar offers, every combo box on its bars gets each
 * of a list of awkward strings -- empty, a lone sign, 1e999, nan, a digit
 * from another script, full-width digits, 1+2*3, a/b, 1/0, hex, a
 * thousand-separated number, a 300-digit one, control bytes -- either put in
 * whole (jw_cmd_box_put: what the parsers have to cope with) or typed a key
 * at a time (jw_cmd_box_key: what the box lets in), and then the command is
 * driven with a few presses aimed at the drawing and a few at nothing, with
 * a drawing that has degenerate geometry in it (lines of no length, circles
 * of radius 0 and 1e10, coordinates out at 5e11).  Whatever happens it must
 * not fall over, hang, or leave a number in the drawing that the drawing
 * could not hold (jw_numbers_sane). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/jww.h"
#include "../src/gen/bars.h"
#include "../src/gen/cmds.h"
#include "../src/gen/layout.h"

static const char *G[] = {
    "", "-", "+", ".", "-.", "e", "1e", "1e999", "-1e999", "1e-999", "nan", "NaN", "inf", "-inf",
    "0", "-0", "0.0000000001", "1e12", "-1e12", "9e11", "999999999999999999999",
    "\xd9\xa3", "\x82\x50\x82\x51\x82\x52", "1+2*3", "(1+2)*3", "a/b", "1/0", "0/0", "-1/-1",
    "0x10", "1,000", "1,2,3", "1..2", "..", "((((((1", "))))1", "  12  ", "12abc", "abc12",
    "1e5", "3.14159265358979323846264338327950288", "\x01\x02\x03", "\xff\xfe",
    "1 , 2", "1..5", "10 , 0", "-5", "100000000", "0.5", "180", "360", "-720", "1e308", "5e11"
};

static unsigned long rng = 1234567u;
static unsigned nextr(void)
{
    rng = rng * 1103515245u + 12345u;
    return (unsigned)(rng >> 8);
}

static int fails;

static unsigned char *slurp(const char *p, long *n)
{
    FILE *f = fopen(p, "rb");
    unsigned char *b;

    if (!f) return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) { free(b); b = 0; }
    fclose(f);
    return b;
}

static void awkward(jw_drawing *d)
{
    static const double L[][4] = {
        { 100, 100, 100, 100 }, { 0, 0, 1000, 0 }, { 0, 1e-9, 1000, 2e-9 }, { 0, 5, 1e6, 5.000001 },
        { 10, 10, 10 + 1e-12, 10 }, { -9e11, 0, 9e11, 1 }, { 5e11, 5e11, 5e11 + 1, 5e11 },
        { 300, 100, 300, 400 }, { 300, 100, 300.00001, 400 }
    };
    static const double C[][3] = { { 50, 50, 0 }, { 60, 60, 1e-12 }, { 70, 70, 1e10 }, { 5e11, 5e11, 100 }, { 90, 90, 25 } };
    unsigned k;

    for (k = 0; k < sizeof L / sizeof L[0]; k++) {
        jw_obj *o = jw_add(d, JW_SEN);
        if (o) { o->d[0] = L[k][0]; o->d[1] = L[k][1]; o->d[2] = L[k][2]; o->d[3] = L[k][3]; }
    }
    for (k = 0; k < sizeof C / sizeof C[0]; k++) {
        jw_obj *o = jw_add(d, JW_ENKO);
        if (o) {
            o->d[0] = C[k][0]; o->d[1] = C[k][1]; o->d[2] = C[k][2];
            o->d[4] = 6.283185307179586; o->d[6] = 1;
        }
    }
}

static void drive(void)
{
    const jw_drawing *d = app_drawing();
    const jw_view *v = app_view();
    int k;

    for (k = 0; k < 10; k++) {
        if (k & 1 && d && d->ndrawn > 0 && v) {
            const jw_obj *o = &d->obj[nextr() % (unsigned)d->ndrawn];

            app_press(jw_sx(v, o->d[0]), jw_sy(v, o->d[1]), (int)(nextr() & 1));
        } else
            app_press((int)(nextr() % 1264), (int)(nextr() % 741), (int)(nextr() & 1));
        if (k % 4 == 3)
            app_key(13);
        app_move((int)(nextr() % 1264), (int)(nextr() % 741));
    }
    app_key(27);
    app_key(27);
}

int main(int argc, char **argv)
{
    long n;
    unsigned char *b = slurp(argc > 1 ? argv[1] : "orig/Test1.jww", &n);
    int ci, bi, gi, tried = 0, viaput;
    clock_t t0 = clock();

    if (!b) { printf("BAD  cannot read the drawing\n"); return 1; }
    app_resize(1264, 741);
    for (viaput = 1; viaput >= 0; viaput--)
        for (ci = 0; ci < JW_NBUTTONS; ci++) {
            unsigned cmd = jw_btn_cmd[ci];

            for (gi = 0; gi < (int)(sizeof G / sizeof G[0]); gi++) {
                int boxes[32], nb = 0;

                if (!app_open(b, n)) { printf("BAD  open\n"); return 1; }
                awkward((jw_drawing *)app_drawing());
                app_fit();
                app_command((int)cmd);
                for (bi = 0; bi < JW_NBARS && nb < 32; bi++)
                    if (jw_bars[bi].cmd == cmd || jw_bars[bi].cmd == 100000 + cmd) {
                        int k;
                        for (k = 0; k < jw_bars[bi].n && nb < 32; k++)
                            if (jw_bars[bi].c[k].kind == JW_CTL_COMBO)
                                boxes[nb++] = jw_bars[bi].c[k].id;
                    }
                for (bi = 0; bi < nb; bi++) {
                    if (viaput)
                        jw_cmd_box_put(boxes[bi], G[gi]);
                    else {
                        const char *s;
                        int q;

                        jw_cmd_box_click(boxes[bi]);
                        for (q = 0; q < 24; q++)
                            jw_cmd_box_key(8);
                        for (s = G[gi]; *s; s++)
                            jw_cmd_box_key((unsigned char)*s);
                        jw_cmd_box_key(13);
                    }
                }
                drive();
                tried++;
                if (app_drawing() && !jw_numbers_sane(app_drawing())) {
                    /* the awkward elements are sane to begin with, so this is the command's doing */
                    printf("BAD  command %u, boxes %s with \"%s\": a number no drawing could hold\n",
                           cmd, viaput ? "put" : "typed", G[gi]);
                    {
                        const jw_drawing *dd = app_drawing();
                        int q, w;

                        for (q = 0; q < dd->nobj; q++)
                            for (w = 0; w < 8; w++)
                                if (!(dd->obj[q].d[w] > -1e12 && dd->obj[q].d[w] < 1e12)) {
                                    printf("       obj %d cls %d: %g %g %g %g %g %g\n", q, dd->obj[q].cls,
                                           dd->obj[q].d[0], dd->obj[q].d[1], dd->obj[q].d[2], dd->obj[q].d[3],
                                           dd->obj[q].d[4], dd->obj[q].d[5]);
                                    w = 8;
                                    q = dd->nobj;
                                }
                    }
                    fails++;
                    if (fails > 20)
                        return 1;
                }
                if ((double)(clock() - t0) / CLOCKS_PER_SEC > 1500.0) {
                    printf("BAD  too slow\n");
                    return 1;
                }
            }
        }
    printf("%d box/command/garbage combinations, %d bad\n", tried, fails);
    return fails != 0;
}
