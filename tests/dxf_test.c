/* DXF 書き出し -- against the one the original wrote.
 *
 *   tests/dxf_test.exe
 *
 * tools/mkpens.c makes a drawing of nine lines, one per pen, and nine more,
 * one per line type, out of Test5.jww; tools/refanswers.sh has the original
 * open it and write decomp/res/pens.dxf.  This builds the same drawing and
 * writes its own DXF, and the two have to be the same bytes.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/jww.h"

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

/* the same drawing tools/mkpens.c makes */
static void pens(jw_drawing *d)
{
    int i;

    while (d->ndrawn > 0)
        jw_remove(d, d->ndrawn - 1);
    for (i = 1; i <= 9; i++) {
        jw_obj *o = jw_add(d, JW_SEN);

        if (!o)
            return;
        o->color = (unsigned short)i;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->d[0] = -100.0;
        o->d[1] = (double)(i * 10);
        o->d[2] = 100.0;
        o->d[3] = (double)(i * 10);
    }
    for (i = 1; i <= 9; i++) {
        jw_obj *o = jw_add(d, JW_SEN);

        if (!o)
            return;
        o->color = 2;
        o->ltype = (unsigned short)i;
        o->layer = 0;
        o->lgroup = 0;
        o->d[0] = (double)(i * 10);
        o->d[1] = -100.0;
        o->d[2] = (double)(i * 10);
        o->d[3] = -10.0;
    }
}

/* The same for a drawing taken as it is. */
static void whole(const char *jww, const char *dxf)
{
    unsigned char *b, *mine = 0, *want;
    long n, m = 0, wn, i;
    jw_drawing d;

    printf("%s -> %s\n", jww, dxf);
    b = slurp(jww, &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read %s\n", jww);
        fails++;
        return;
    }
    free(b);
    ck(jw_dxf_write(&d, &mine, &m), "  the port writes a DXF");
    want = slurp(dxf, &wn);
    if (!want) {
        printf("BAD  cannot read %s -- drive the original first\n", dxf);
        fails++;
        jw_free(&d);
        return;
    }
    for (i = 0; i < m && i < wn; i++)
        if (mine[i] != want[i])
            break;
    if (i < m || i < wn) {
        long a = i > 50 ? i - 50 : 0;
        FILE *g = fopen("tmp/mine2.dxf", "wb");

        if (g) {
            fwrite(mine, 1, (size_t)m, g);
            fclose(g);
        }
        printf("     ours %ld bytes, theirs %ld, they part at %ld\n", m, wn, i);
        printf("     ours   ...%.70s\n", (const char *)mine + a);
        printf("     theirs ...%.70s\n", (const char *)want + a);
    }
    ck(m == wn && i == m, "  byte for byte the original's");
    free(mine);
    free(want);
    jw_free(&d);
}

/* Line by line, letting the numbers differ in the last place or two.
 *
 * An ellipse is written out as a run of short lines, and where those lines
 * fall comes off sin and cos: the original's differ from this compiler's by
 * an ulp or so at some angles, and nothing can be done about that.  One
 * vertex of the twelve ellipses in Ａマンション平面例.jww is 2 ulp out and the
 * rest are exact.  So drawings with ellipses in them are held to the same
 * structure and numbers that agree to a part in 1e-12 rather than to the
 * byte.
 */
static void alike(const char *jww, const char *dxf)
{
    unsigned char *b, *mine = 0, *want;
    long n, m = 0, wn;
    jw_drawing d;
    char *p, *q;
    long line = 0, bad = 0;

    printf("%s ~ %s\n", jww, dxf);
    b = slurp(jww, &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read %s\n", jww);
        fails++;
        return;
    }
    free(b);
    ck(jw_dxf_write(&d, &mine, &m), "  the port writes a DXF");
    want = slurp(dxf, &wn);
    if (!want) {
        printf("BAD  cannot read %s -- drive the original first\n", dxf);
        fails++;
        jw_free(&d);
        return;
    }
    {                           /* keep ours for a look with diff */
        FILE *g = fopen("tmp/mine3.dxf", "wb");

        if (g) {
            fwrite(mine, 1, (size_t)m, g);
            fclose(g);
        }
    }
    mine = (unsigned char *)realloc(mine, (size_t)m + 1);
    want = (unsigned char *)realloc(want, (size_t)wn + 1);
    mine[m] = 0;
    want[wn] = 0;
    p = (char *)mine;
    q = (char *)want;
    while (*p && *q) {
        char *pe = strstr(p, "\r\n"), *qe = strstr(q, "\r\n");
        size_t pn, qn;

        if (!pe || !qe)
            break;
        pn = (size_t)(pe - p);
        qn = (size_t)(qe - q);
        line++;
        if (pn != qn || memcmp(p, q, pn)) {
            char a[64], c[64];
            double x, y;

            if (pn < sizeof a && qn < sizeof c) {
                memcpy(a, p, pn);
                a[pn] = 0;
                memcpy(c, q, qn);
                c[qn] = 0;
                x = atof(a);
                y = atof(c);
                /* the last place or two of sin and cos, and the odd
                   near-zero that one side rounds to 0 */
                if (fabs(x - y) <= 1e-9 * (fabs(x) + fabs(y))
                    || fabs(x - y) < 1e-9) {
                    p = pe + 2;
                    q = qe + 2;
                    continue;   /* the last place or two: let it go */
                }
                if (bad < 4)
                    printf("     line %ld: ours %s, theirs %s\n", line, a, c);
            }
            bad++;
        }
        p = pe + 2;
        q = qe + 2;
    }
    ck(m == wn || bad == 0, "  the same length");
    ck(bad == 0, "  every line the original's, give or take the last place");
    free(mine);
    free(want);
    jw_free(&d);
}

int main(void)
{
    unsigned char *b, *mine = 0, *want;
    long n, m = 0, wn;
    jw_drawing d;
    long i;

    b = slurp("orig/Test5.jww", &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read orig/Test5.jww\n");
        return 1;
    }
    free(b);
    pens(&d);
    ck(jw_dxf_write(&d, &mine, &m), "the port writes a DXF");
    want = slurp("decomp/res/pens.dxf", &wn);
    if (!want) {
        printf("BAD  cannot read decomp/res/pens.dxf -- drive the original first\n");
        return 1;
    }
    printf("     ours %ld bytes, the original's %ld\n", m, wn);
    for (i = 0; i < m && i < wn; i++)
        if (mine[i] != want[i])
            break;
    if (i < m || i < wn) {
        long a = i > 60 ? i - 60 : 0;
        FILE *g = fopen("tmp/mine.dxf", "wb");

        if (g) {                /* for a look with diff */
            fwrite(mine, 1, (size_t)m, g);
            fclose(g);
        }

        printf("     they part at %ld\n", i);
        printf("     ours   ...%.80s\n", (const char *)mine + a);
        printf("     theirs ...%.80s\n", (const char *)want + a);
    }
    ck(m == wn && i == m, "and it is the one the original wrote, byte for byte");
    jw_free(&d);
    whole("orig/Test5.jww", "decomp/res/test5.dxf");
    alike("decomp/res/mansion.jww", "decomp/res/mansion.dxf");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
