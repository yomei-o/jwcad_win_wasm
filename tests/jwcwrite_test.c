/* JWC 書き出し -- against the ones the original wrote.
 *
 *   tests/jwcwrite_test.exe
 *
 * tools/refanswers.sh has the original open a drawing and pick ファイル ->
 * JWC形式で保存 (32810).  This writes the same drawing itself and the two
 * have to be the same bytes.
 *
 * Both answers come out of drawings that share Test5.jww's settings, which
 * is what makes a byte comparison fair: five fields of the first line of a
 * JWC are not understood and are baked from one of them (tools/mkjwc.py).
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
    for (i = 0; i < m && i < wn; i++)
        if (mine[i] != want[i])
            break;
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
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
