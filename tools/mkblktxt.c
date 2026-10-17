/* decomp/res/blkmake.jww with texts in the block's definition and four
 * references to it with the four sign combinations of (x, y) -- for asking
 * the original what ブロック解除 (32909) makes of a text under a reflection.
 *
 *   gcc -O2 -Isrc -o tmp/mkblktxt.exe tools/mkblktxt.c src/jww.c \
 *       src/image.c src/imgpic.c src/jwwrite.c src/cp932.c
 *   ./tmp/mkblktxt.exe decomp/res/blkmake.jww tmp/blktxt.jww
 *
 * Texts (start -> end, angle): horizontal 0 deg, 30 deg, 90 deg, 150 deg
 * (a baseline that points left and up, with the angle that says so), -60.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

static double SZ = 3.0;

static void put_text(jw_drawing *d, jw_obj *o, double x0, double y0, double len,
                     double deg, const char *s)
{
    double a = deg * 3.141592653589793 / 180.0;

    memset(o, 0, sizeof *o);
    o->cls = JW_MOJI;
    o->ltype = 1;
    o->color = 2;
    o->layer = 0;
    o->lgroup = 0;
    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x0 + len * cos(a);
    o->d[3] = y0 + len * sin(a);
    o->d[4] = SZ;
    o->d[5] = SZ;
    o->d[6] = 0.5;
    o->d[7] = deg;
    o->text = jw_add_str(d, s);
    o->face = -1;
    o->n = 0;
}

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    int i, at = -1, ref = -1, k;
    static const double deg[5] = { 0, 30, 90, 150, -60 };
    static const double sgn[4][2] = { { -1, 1 }, { 1, -1 }, { -1, -1 }, { 1, 1 } };

    if (!f)
        return 1;
    if (argc > 3)
        SZ = atof(argv[3]);
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        printf("%s: %s\n", argv[1], d.error);
        return 1;
    }
    for (i = 0; i < d.ndrawn; i++)
        if (d.obj[i].cls == JW_BLOCK) {
            ref = i;
            break;
        }
    for (i = d.ndrawn; i < d.nobj; i++)
        if (d.obj[i].cls == JW_LIST) {
            at = i;
            break;
        }
    if (ref < 0 || at < 0 || d.obj[at].n < 5)
        return 1;
    for (k = 0; k < 5; k++) {
        char s[16];

        if (argc > 4)
            strcpy(s, k > 0 ? " " : "FR");
        else
            sprintf(s, "T%d", k);
        put_text(&d, &d.obj[at + 1 + k], 0.0, 10.0 * k, SZ * 1.0833333333333333, deg[k], s);
    }
    for (k = 1; k < 4; k++) {
        jw_obj *o = jw_add(&d, JW_BLOCK);

        if (!o)
            return 1;
        *o = d.obj[ref];
        o->d[1] += 70.0 * k;
        o->id = 0;
        o->sel = 0;
        o->flags = 0;
    }
    for (k = 0; k < 4; k++) {
        jw_obj *o = k ? &d.obj[d.ndrawn - 4 + k] : &d.obj[ref];

        o->d[2] = sgn[k][0];
        o->d[3] = sgn[k][1];
    }
    if (!jw_write(&d, &w, &m))
        return 1;
    f = fopen(argv[2], "wb");
    if (!f || fwrite(w, 1, (size_t)m, f) != (size_t)m)
        return 1;
    fclose(f);
    return 0;
}
