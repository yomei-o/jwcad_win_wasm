/* DXF 書き出しの BLOCK/INSERT -- against the ones the original wrote.
 *
 *   tests/dxfblock_test.exe
 *
 * 2026-10-19, tools/jwdraw.ps1 export:32961 drove the original on two
 * drawings that carry a ブロック reference and saved what it wrote:
 *
 *   decomp/res/blktxt_base.jww -> decomp/res/blktxt.dxf
 *     one 定義 "-000-BLK" (five 字 at 0,30,90,150,-60 degrees and some
 *     lines/arcs/circles/points/solids), referenced four times with every
 *     combination of x/y scale sign (mirrored, not, both) -- group 41/42 of
 *     the four INSERT carry the mirroring; the definition's own elements
 *     keep their original, unmirrored angles and coordinates.
 *
 *   decomp/res/bt_nest2.jww -> decomp/res/bt_nest2.dxf
 *     three definitions -- "-000-BLK", "-001-OUTER", "-002-LN" -- where
 *     OUTER holds two nested INSERT "-000-BLK" of its own (a ブロック
 *     reference inside a ブロックの定義), at local, unshifted coordinates
 *     the same way any other element inside a BLOCK is.
 *
 * Both compare line by line against the original's output, the way
 * tests/dxf_test.c's alike() does for Ａマンション平面例.jww's ellipses --
 * one of the ARCs inside "-000-BLK" lands on 29.999999999999992 degrees in
 * the original's group 51 where this writes the exact 30 the drawing holds
 * (sin/cos/atan2 one ulp off between compilers, same story as the ellipse
 * vertices there), which changes the digit run's length and so cannot go
 * through dxf_test.c's whole() (byte for byte, with only a same-length
 * last-place difference let through).  This is its own file rather than
 * more cases added to dxf_test.c's because of that -- it needed its own
 * comparison, not because the two share nothing (ck/slurp are copied).
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

/* Byte for byte, except that a run of digits that only differs the way
 * sin/cos/atan2 differ between compilers -- one ulp, which can round the
 * last digit away and so change how many digits print, the way this file's
 * header explains -- is let through.  tests/dxf_test.c's whole() asks for
 * m == wn first and only then tries lastplace() on the one spot that
 * differs; that does not reach the case these two files have, where the
 * digit run itself is a different length (30 here, 29.999999999999992 in
 * the original's ARC group 51 -- decomp/res/blktxt.dxf, the 中 ARC inside
 * "-000-BLK"), so this compares a digit run at a time instead. */
static void whole(const char *jww, const char *dxf)
{
    unsigned char *b, *mine = 0, *want;
    long n, m = 0, wn;
    jw_drawing d;
    const char *p, *q;
    long bad = 0, lines = 0;

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
    mine = (unsigned char *)realloc(mine, (size_t)m + 1);
    want = (unsigned char *)realloc(want, (size_t)wn + 1);
    mine[m] = 0;
    want[wn] = 0;
    p = (const char *)mine;
    q = (const char *)want;
    while (*p && *q) {
        const char *pe = strstr(p, "\r\n"), *qe = strstr(q, "\r\n");
        size_t pn, qn;

        if (!pe || !qe)
            break;
        pn = (size_t)(pe - p);
        qn = (size_t)(qe - q);
        lines++;
        if (pn != qn || memcmp(p, q, pn)) {
            char a[64], c[64];

            if (pn < sizeof a && qn < sizeof c
                && strspn(p, "0123456789.+-eE") == pn
                && strspn(q, "0123456789.+-eE") == qn) {
                double x, y;

                memcpy(a, p, pn); a[pn] = 0;
                memcpy(c, q, qn); c[qn] = 0;
                x = atof(a);
                y = atof(c);
                if (fabs(x - y) <= fabs(x) * 7e-16 + 1e-300) {
                    p = pe + 2;
                    q = qe + 2;
                    continue;    /* one ulp of sin/cos/atan2: let it go */
                }
            }
            if (bad == 0) {
                char sa[101], sb[101];
                size_t na = pn < 100 ? pn : 100, nb = qn < 100 ? qn : 100;

                memcpy(sa, p, na); sa[na] = 0;
                memcpy(sb, q, nb); sb[nb] = 0;
                printf("     line %ld: ours %s, theirs %s\n", lines, sa, sb);
            }
            bad++;
        }
        p = pe + 2;
        q = qe + 2;
    }
    if (bad) {
        FILE *g = fopen("tmp/mineblk.dxf", "wb");

        if (g) {
            fwrite(mine, 1, (size_t)m, g);
            fclose(g);
        }
    }
    ck(bad == 0, "  every line the original's, give or take the last place");
    free(mine);
    free(want);
    jw_free(&d);
}

int main(void)
{
    whole("decomp/res/blktxt_base.jww", "decomp/res/blktxt.dxf");
    whole("decomp/res/bt_nest2.jww", "decomp/res/bt_nest2.dxf");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
