/* SFC 書き出し -- against the ones the original wrote.
 *
 *   tests/sfcwrite_test.exe
 *
 * tools/refanswers.sh has the original open a drawing and pick ファイル ->
 * SFC書き出し (32976).  This writes the same drawing itself and the two have
 * to be the same bytes.  Two things in the header are not the drawing's: the
 * name it was saved under and the moment it was written, so both are read
 * back out of the answer and handed to the writer.
 */
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
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    if (b)
        b[*n] = 0;
    fclose(f);
    return b;
}

/* What is between the n'th pair of single quotes, which is how both the name
   and the moment sit in FILE_NAME. */
static int quoted(const char *s, int nth, char *out, size_t max)
{
    const char *p = s;
    int i;

    for (i = 0; i < nth; i++) {
        p = strchr(p, '\'');
        if (!p)
            return 0;
        p++;
        if (i + 1 < nth) {
            p = strchr(p, '\'');
            if (!p)
                return 0;
            p++;
        }
    }
    {
        const char *e = strchr(p, '\'');
        size_t k;

        if (!e)
            return 0;
        k = (size_t)(e - p);
        if (k + 1 > max)
            return 0;
        memcpy(out, p, k);
        out[k] = 0;
    }
    return 1;
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

static void one(const char *jww, const char *sfc, int aspens)
{
    unsigned char *b, *mine = 0, *want;
    long n, m = 0, wn, i;
    char name[128], stamp[64], *nl;
    jw_drawing d;

    printf("%s -> %s\n", jww, sfc);
    b = slurp(jww, &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read %s\n", jww);
        fails++;
        free(b);
        return;
    }
    free(b);
    if (aspens)
        pens(&d);
    want = slurp(sfc, &wn);
    if (!want) {
        printf("BAD  cannot read %s -- drive the original first\n", sfc);
        fails++;
        jw_free(&d);
        return;
    }
    /* FILE_NAME('<name>',\r\n\t'<moment>', */
    nl = strstr((char *)want, "FILE_NAME(");
    if (!nl || !quoted(nl, 1, name, sizeof name)
        || !quoted(nl, 2, stamp, sizeof stamp)) {
        printf("BAD  %s has no FILE_NAME to read the name out of\n", sfc);
        fails++;
        free(want);
        jw_free(&d);
        return;
    }
    ck(jw_sfc_write(&d, name, stamp, &mine, &m), "  the port writes an SFC");
    for (i = 0; i < m && i < wn; i++)
        if (mine[i] != want[i])
            break;
    if (i < m || i < wn) {
        long a = i > 60 ? i - 60 : 0;
        FILE *g = fopen("tmp/mine.sfc", "wb");

        if (g) {
            fwrite(mine, 1, (size_t)m, g);
            fclose(g);
        }
        printf("     ours %ld bytes, theirs %ld, they part at %ld\n", m, wn, i);
        printf("     ours   ...%.80s\n", (const char *)mine + a);
        printf("     theirs ...%.80s\n", (const char *)want + a);
    }
    ck(m == wn && i == m, "  byte for byte the original's");
    free(mine);
    free(want);
    jw_free(&d);
}

int main(void)
{
    one("orig/Test5.jww", "decomp/res/pens.sfc", 1);
    one("orig/Test5.jww", "decomp/res/sfcw5.sfc", 0);
    one("orig/Test6.jww", "decomp/res/sfcw6.sfc", 0);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
