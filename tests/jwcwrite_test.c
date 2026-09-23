/* JWC 書き出し -- against the ones the original wrote.
 *
 *   tests/jwcwrite_test.exe
 *
 * tools/refanswers.sh has the original open a drawing and pick ファイル ->
 * JWC形式で保存 (32810).  This writes the same drawing itself and the two
 * have to be the same bytes.
 *
 * Five fields of the first line are not understood and are baked from one
 * of the answers (tools/mkjwc.py), so those five are allowed to differ --
 * and they do: the 19th moves by one between runs, which is how we know it
 * is not the drawing's.  Everything else has to be the same byte for byte.
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
    fclose(f);
    return b;
}

/* the same drawing tools/mkgeom.c makes: four lines, four arcs, two points
   and two solids, which between them cover every record a JWC has */
static void geom(jw_drawing *d)
{
    static const double A[4][2] = {
        { 0.0, 1.5707963267948966 },
        { 3.141592653589793, -1.5707963267948966 },
        { 4.71238898038469, 2.0943951023931953 },
        { 0.0, 6.283185307179586 },
    };
    jw_obj *o;
    int i;

    while (d->ndrawn > 0)
        jw_remove(d, d->ndrawn - 1);
    /* tools/mkgeom.c puts everything on layer 0 of group 0 */
#define LAY() do { o->layer = 0; o->lgroup = 0; o->width = 0; } while (0)
    for (i = 0; i < 4; i++) {
        o = jw_add(d, JW_SEN);
        if (!o)
            return;
        o->color = (unsigned short)(i + 1);
        o->ltype = (unsigned short)(i + 1);
        o->d[0] = -90.0;
        o->d[1] = 60.0 - i * 10.0;
        o->d[2] = 90.0;
        o->d[3] = 60.0 - i * 10.0;
        LAY();
    }
    for (i = 0; i < 4; i++) {
        o = jw_add(d, JW_ENKO);
        if (!o)
            return;
        o->color = (unsigned short)(i + 2);
        o->ltype = 1;
        o->d[0] = -60.0 + i * 40.0;
        o->d[1] = -30.0;
        o->d[2] = 15.0;
        o->d[3] = A[i][0];
        o->d[4] = A[i][1];
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        LAY();
    }
    for (i = 0; i < 2; i++) {
        o = jw_add(d, JW_TEN);
        if (!o)
            return;
        o->color = (unsigned short)(i + 3);
        o->ltype = 1;
        o->d[0] = -20.0 + i * 40.0;
        o->d[1] = -70.0;
        LAY();
    }
    o = jw_add(d, JW_SOLID);
    if (o) {
        o->color = 4;
        o->ltype = 1;
        o->d[0] = -80.0; o->d[1] = -80.0;
        o->d[2] = -50.0; o->d[3] = -80.0;
        o->d[4] = -65.0; o->d[5] = -55.0;
        o->d[6] = -65.0; o->d[7] = -55.0;
        LAY();
    }
    o = jw_add(d, JW_SOLID);
    if (o) {
        o->color = 5;
        o->ltype = 1;
        o->d[0] = 50.0; o->d[1] = -80.0;
        o->d[2] = 85.0; o->d[3] = -80.0;
        o->d[4] = 85.0; o->d[5] = -55.0;
        o->d[6] = 55.0; o->d[7] = -50.0;
        LAY();
    }
#undef LAY
}

/* the first line of text in a JWC, which sits at 0xc8 and ends at a NUL */
static void line_of(const unsigned char *b, long n, char *out, size_t max)
{
    size_t k = 0;

    out[0] = 0;
    if (n < 0xc8 + 1)
        return;
    while (0xc8 + k < (size_t)n && b[0xc8 + k] && k + 1 < max) {
        out[k] = (char)b[0xc8 + k];
        k++;
    }
    out[k] = 0;
}

static void one(const char *jww, const char *jwc, int asgeom)
{
    unsigned char *b, *mine = 0, *want;
    long n, m = 0, wn, i;
    jw_drawing d;

    printf("%s -> %s\n", jww, jwc);
    b = slurp(jww, &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read %s\n", jww);
        fails++;
        free(b);
        return;
    }
    free(b);
    if (asgeom)
        geom(&d);
    ck(jw_jwc_write(&d, &mine, &m), "  the port writes a JWC");
    want = slurp(jwc, &wn);
    if (!want) {
        printf("BAD  cannot read %s -- drive the original first\n", jwc);
        fails++;
        free(mine);
        jw_free(&d);
        return;
    }
    {   /* the first line, field by field: the five we cannot work out may
           differ, and the test says so when they do */
        static const int LOOSE[] = { 5, 6, 11, 12, 19 };
        char a[256], b[256];
        int fa = 0, fb = 0, k, loose = 0, bad = 0;
        char *pa = a, *pb = b;

        line_of(mine, m, a, sizeof a);
        line_of(want, wn, b, sizeof b);
        for (k = 1;; k++) {
            char *ea = strchr(pa, ','), *eb = strchr(pb, ',');
            size_t na = ea ? (size_t)(ea - pa) : strlen(pa);
            size_t nb = eb ? (size_t)(eb - pb) : strlen(pb);
            int soft = 0, j;

            for (j = 0; j < (int)(sizeof LOOSE / sizeof LOOSE[0]); j++)
                if (LOOSE[j] == k)
                    soft = 1;
            if (na != nb || memcmp(pa, pb, na)) {
                if (soft) {
                    loose++;
                } else {
                    printf("     the %dth of the first line is %.*s, the "
                           "original's is %.*s\n", k, (int)na, pa,
                           (int)nb, pb);
                    bad = 1;
                }
            }
            if (!ea || !eb)
                break;
            pa = ea + 1;
            pb = eb + 1;
        }
        (void)fa;
        (void)fb;
        if (loose)
            printf("     (%d of the five we cannot work out differ)\n",
                   loose);
        ck(!bad, "  the first line's fields, but for the five unknown ones");
    }
    /* and the rest of it to the byte, the first line left out */
    for (i = 0; i < m && i < wn; i++) {
        if (i >= 0xc8 && i < 0x190)
            continue;
        if (mine[i] != want[i])
            break;
    }
    if (i < m || i < wn) {
        FILE *g = fopen("tmp/mine.jwc", "wb");

        if (g) {
            fwrite(mine, 1, (size_t)m, g);
            fclose(g);
        }
        printf("     ours %ld bytes, theirs %ld, they part at %ld (0x%lx)\n",
               m, wn, i, i);
    }
    ck(m == wn && i == m, "  byte for byte the original's");
    free(mine);
    free(want);
    jw_free(&d);
}

int main(void)
{
    one("orig/Test5.jww", "decomp/res/geom.jwc", 1);
    one("orig/Test5.jww", "decomp/res/t5.jwc", 0);
    /* and a drawing with 円ソリッド in it, which is written as arcs */
    one("decomp/res/hatin.jww", "decomp/res/rsolid.jwc", 0);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
