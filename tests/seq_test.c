/* Reading one format on top of another.
 *
 *   tests/seq_test.exe <a .jww> <a .dxf> <an .sfc> <a .jwc>
 *
 * Every other test hands a reader one file and starts again.  The program
 * does not: a DXF, an SFC and a JWC all go *into* whatever is already open,
 * so what one reader leaves behind is what the next one starts from.  That
 * is a seam nothing was watching, and it had a hole in it.
 *
 * What it watches are the counts a reader leaves behind, because those are
 * what the next one indexes its tables by.
 *
 * A drawing holds 257 任意色 (xcolor[257]); an SFC may name up to 259.
 * src/sfcread.c stopped the write-back at 256 but let the *count* through,
 * and src/dxfread.c turns that count into the top index of a 357-long
 * table -- so an SFC with more than 256 colours, followed by a DXF, walked
 * off the end of it (`index 357 out of bounds`, caught with
 * -fsanitize=undefined; AddressSanitizer cannot see it, because the two
 * elements past the end are other fields of the same struct).
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"

static int bad;

static void ck(int ok, const char *what)
{
    printf("%s   %s\n", ok ? "ok " : "BAD", what);
    if (!ok)
        bad++;
}

static unsigned char *slurp(const char *p, long *n)
{
    FILE *f = fopen(p, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)(*n > 0 ? *n : 1));
    if (!b || fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        fclose(f);
        free(b);
        return 0;
    }
    fclose(f);
    return b;
}

static int read_as(jw_drawing *d, int kind, const unsigned char *b, long n)
{
    switch (kind) {
    case 1:  return jw_dxf_read(d, b, n);
    case 2:  return jw_sfc_read(d, b, n);
    case 3:  return jw_jwc_read(d, b, n);
    default: return jw_parse(d, b, n);
    }
}

static const char *kind_name(int k)
{
    return k == 1 ? "DXF" : k == 2 ? "SFC" : k == 3 ? "JWC" : ".jww";
}

/* An SFC with more colours than a drawing can hold.  The bundled ones have
   a `user_defined_colour_feature`; three hundred more go in beside it. */
static unsigned char *pad_colours(const unsigned char *b, long n, long *out_n)
{
    const char *mark = "user_defined_colour_feature";
    long at = -1, i, m = 0, cap;
    unsigned char *big;
    char one[128];

    for (i = 0; i + (long)strlen(mark) < n; i++)
        if (!memcmp(b + i, mark, strlen(mark))) { at = i; break; }
    if (at < 0)
        return 0;
    while (at > 0 && memcmp(b + at, "/*SXF", 5))
        at--;
    cap = n + 300 * 128 + 16;
    big = (unsigned char *)malloc((size_t)cap);
    if (!big)
        return 0;
    memcpy(big, b, (size_t)at);
    m = at;
    for (i = 0; i < 300; i++) {
        int k = sprintf(one, "/*SXF\r\n#%ld = user_defined_colour_feature"
                             "('%ld','%ld','%ld')\r\nSXF*/\r\n\r\n",
                        (long)(9000 + i), i % 256, (i * 7) % 256,
                        (i * 13) % 256);
        memcpy(big + m, one, (size_t)k);
        m += k;
    }
    memcpy(big + m, b + at, (size_t)(n - at));
    *out_n = m + n - at;
    return big;
}

int main(int argc, char **argv)
{
    unsigned char *f[4];
    long fn[4];
    int i, j;

    if (argc < 5) {
        printf("BAD  want a .jww, a .dxf, an .sfc and a .jwc\n");
        return 1;
    }
    for (i = 0; i < 4; i++) {
        f[i] = slurp(argv[i + 1], &fn[i]);
        if (!f[i]) {
            printf("BAD  cannot read %s\n", argv[i + 1]);
            return 1;
        }
    }

    /* every ordered pair, read into the one drawing */
    for (i = 0; i < 4; i++)
        for (j = 0; j < 4; j++) {
            jw_drawing d;
            char what[80];

            memset(&d, 0, sizeof d);
            read_as(&d, i, f[i], fn[i]);
            read_as(&d, j, f[j], fn[j]);
            sprintf(what, "%s then %s: the counts stay in their tables",
                    kind_name(i), kind_name(j));
            /* xcolor_n indexes xcolor[257] and, through src/dxfread.c,
               col[357]; sxf_n indexes sxf[33]; and ndrawn is the bound of
               dozens of `for (i = 0; i < d->ndrawn; i++) d->obj[i]` walks,
               so it must not outrun the objects there are. */
            ck(d.xcolor_n >= 0 && d.xcolor_n <= 256
               && d.sxf_n >= 0 && d.sxf_n <= 32
               && d.nobj >= 0 && d.nobj <= d.cobj
               && d.ndrawn >= 0 && d.ndrawn <= d.nobj, what);
            jw_free(&d);
        }

    /* and the one that was wrong: more colours than a drawing can hold,
       then a DXF, which is what indexes a table by that count */
    {
        long bign = 0;
        unsigned char *big = pad_colours(f[2], fn[2], &bign);

        if (!big) {
            printf("BAD  %s has no user_defined_colour_feature to pad\n",
                   argv[3]);
            bad++;
        } else {
            jw_drawing d;

            memset(&d, 0, sizeof d);
            ck(jw_sfc_read(&d, big, bign), "an SFC of 300 colours reads");
            ck(d.xcolor_n <= 256, "and leaves a count inside xcolor[257]");
            read_as(&d, 1, f[1], fn[1]);
            ck(d.xcolor_n <= 256, "a DXF on top of it keeps it there");
            jw_free(&d);
            free(big);
        }
    }

    for (i = 0; i < 4; i++)
        free(f[i]);
    printf("%s\n", bad ? "some failed" : "all passed");
    return bad ? 1 : 0;
}
