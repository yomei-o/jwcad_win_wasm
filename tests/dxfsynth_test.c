/* DXF readers' tolerance, with files made up here: UTF-8 text from a newer
   program, \U+XXXX escapes from an older one, LF-only lines, an entity the
   port does not draw (SPLINE), a file cut off in the middle, and a block
   reference with a scale and a turn. */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/* a fresh drawing to read into: Test5, as the other DXF tests use */
static int base(jw_drawing *d)
{
    long n;
    unsigned char *b = slurp("orig/Test5.jww", &n);
    int ok;

    memset(d, 0, sizeof *d);
    ok = b && jw_parse(d, b, n);
    free(b);
    return ok;
}

static int count(const jw_drawing *d, int cls)
{
    int i, k = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == cls)
            k++;
    return k;
}

static int read_dxf(const char *s, jw_drawing *d)
{
    return base(d) && jw_dxf_read(d, (const unsigned char *)s, (long)strlen(s));
}

static const char *HEAD = "0\nSECTION\n2\nHEADER\n9\n$ACADVER\n1\nAC1015\n0\nENDSEC\n0\nSECTION\n2\nENTITIES\n";
static const char *HEAD21 = "0\nSECTION\n2\nHEADER\n9\n$ACADVER\n1\nAC1021\n0\nENDSEC\n0\nSECTION\n2\nENTITIES\n";
static const char *TAIL = "0\nENDSEC\n0\nEOF\n";

static const char *text_of(const jw_drawing *d)
{
    int i;

    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI)
            return jw_str(d, d->obj[i].text);
    return "";
}

int main(void)
{
    static char buf[8192];
    jw_drawing d;
    int lines0;

    /* the base drawing's own lines, which a DXF read throws away */
    sprintf(buf, "%s0\nLINE\n8\n0\n10\n0\n20\n0\n11\n100\n21\n0\n%s", HEAD, TAIL);
    ck(read_dxf(buf, &d), "a one-line DXF reads");
    lines0 = count(&d, JW_SEN);
    ck(lines0 == 1, "  and makes one line");

    /* UTF-8 text from AC1021 */
    sprintf(buf, "%s0\nTEXT\n8\n0\n10\n0\n20\n0\n40\n2.5\n1\n\xe3\x81\x82\xe6\xbc\xa2\n%s", HEAD21, TAIL);
    ck(read_dxf(buf, &d), "AC1021 with UTF-8 text reads");
    ck(!strcmp(text_of(&d), "\x82\xa0\x8a\xbf"), "  the text is the CP932 of あ漢");

    /* the escapes an older program writes */
    sprintf(buf, "%s0\nTEXT\n8\n0\n10\n0\n20\n0\n40\n2.5\n1\n\x5c" "U+3042\x5c" "U+6F22x\n%s", HEAD, TAIL);
    ck(read_dxf(buf, &d), "escaped text reads");
    ck(!strcmp(text_of(&d), "\x82\xa0\x8a\xbf" "x"), "  the same あ漢x");

    /* CP932 bytes in an old file stay as they are */
    sprintf(buf, "%s0\nTEXT\n8\n0\n10\n0\n20\n0\n40\n2.5\n1\n\x82\xa0\n%s", HEAD, TAIL);
    ck(read_dxf(buf, &d) && !strcmp(text_of(&d), "\x82\xa0"), "CP932 text in an AC1015 file is left alone");

    /* a SPLINE is not drawn, and the lines on both sides are */
    sprintf(buf, "%s0\nLINE\n8\n0\n10\n0\n20\n0\n11\n10\n21\n0\n0\nSPLINE\n8\n0\n70\n8\n71\n3\n73\n4\n"
                  "10\n0\n20\n0\n30\n0\n10\n1\n20\n1\n30\n0\n10\n2\n20\n0\n30\n0\n10\n3\n20\n1\n30\n0\n"
                  "0\nLINE\n8\n0\n10\n0\n20\n5\n11\n10\n21\n5\n%s", HEAD, TAIL);
    ck(read_dxf(buf, &d) && count(&d, JW_SEN) == 2, "a SPLINE between two lines: both lines are read");

    /* CRLF and LF read alike */
    {
        char crlf[8192];
        int i, k = 0;
        jw_drawing d2;

        sprintf(buf, "%s0\nLINE\n8\n0\n10\n0\n20\n0\n11\n10\n21\n7\n%s", HEAD, TAIL);
        for (i = 0; buf[i]; i++) {
            if (buf[i] == '\n')
                crlf[k++] = '\r';
            crlf[k++] = buf[i];
        }
        crlf[k] = 0;
        ck(read_dxf(buf, &d) && read_dxf(crlf, &d2) && d.ndrawn == d2.ndrawn
           && fabs(d.obj[0].d[3] - d2.obj[0].d[3]) < 1e-9, "LF and CRLF lines read the same");
    }

    /* a file cut off in the middle of an entity: no crash, what came before stays */
    sprintf(buf, "%s0\nLINE\n8\n0\n10\n0\n20\n0\n11\n10\n21\n0\n0\nLINE\n8\n0\n10\n0\n20\n3\n11\n", HEAD);
    ck(read_dxf(buf, &d), "a file cut short still reads");
    ck(count(&d, JW_SEN) >= 1, "  with the first line in it");

    /* a block with one line, referenced with scale 2 and a quarter turn */
    sprintf(buf, "0\nSECTION\n2\nBLOCKS\n0\nBLOCK\n8\n0\n2\nB1\n70\n0\n10\n0\n20\n0\n"
                 "0\nLINE\n8\n0\n10\n0\n20\n0\n11\n10\n21\n0\n0\nENDBLK\n0\nENDSEC\n"
                 "0\nSECTION\n2\nENTITIES\n0\nINSERT\n8\n0\n2\nB1\n10\n50\n20\n50\n41\n2\n42\n2\n50\n90\n%s", TAIL);
    ck(read_dxf(buf, &d), "a block and a turned, scaled reference reads");
    ck(count(&d, JW_SEN) + count(&d, JW_BLOCK) >= 1, "  and something is drawn");

    /* numbers that are not numbers, or too big to mean anything: the entity is skipped, the file is not refused */
    sprintf(buf, "%s0\nLINE\n8\n0\n10\n0\n20\n0\n11\n10\n21\n0\n"
                  "0\nLINE\n8\n0\n10\n1e308\n20\n-1e308\n11\nnan\n21\ninf\n"
                  "0\nLINE\n8\n0\n10\n0\n20\n5\n11\n10\n21\n5\n%s", HEAD, TAIL);
    ck(read_dxf(buf, &d), "a DXF with a nan/inf/1e308 entity still reads");
    ck(count(&d, JW_SEN) >= 2, "  and the sound lines on both sides are there");

    /* nothing but garbage is not a DXF */
    ck(!read_dxf("this is not a dxf at all", &d), "garbage is refused");
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
