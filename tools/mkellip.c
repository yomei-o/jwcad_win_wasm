/* Make a drawing of squashed circles and arcs, so the original can be asked
 * what it writes for them in an SFC.
 *
 *   gcc -O2 -Isrc -o tmp/mkellip.exe tools/mkellip.c src/jww.c src/jwwrite.c \
 *       src/cp932.c
 *   ./tmp/mkellip.exe orig/Test5.jww tmp/ellip.jww
 *
 * src/sfcwrite.c has an arm for ellipse_feature and one for
 * ellipse_arc_feature; the whole ellipse turns up in Test6.jww but a part of
 * one does not, so this makes six: whole and part, upright and turned, both
 * ways round.  tools/refanswers.sh has the original write the SFC and
 * tests/sfcwrite_test.c scores the port's against it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

#define PI 3.14159265358979323846

int main(int argc, char **argv)
{
    const char *in = argc > 1 ? argv[1] : "orig/Test5.jww";
    const char *out = argc > 2 ? argv[2] : "tmp/ellip.jww";
    FILE *f = fopen(in, "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    int i;
    /* centre x, radius, how flat, the turn, where it starts, how far it goes */
    static const double E[6][6] = {
        { -140.0, 30.0, 0.5,  0.0,           0.0,             2.0 * PI },
        {  -70.0, 30.0, 0.25, 30.0 * PI / 180.0, 0.0,          2.0 * PI },
        {    0.0, 30.0, 0.5,  0.0,           0.0,             PI / 2.0 },
        {   70.0, 30.0, 0.5,  0.0,           PI,             -PI / 2.0 },
        {  140.0, 30.0, 0.4,  45.0 * PI / 180.0, PI / 4.0,     PI },
        {  210.0, 30.0, 0.8, -30.0 * PI / 180.0, 3.0 * PI / 2.0, PI / 3.0 },
    };

    if (!f) {
        printf("cannot open %s\n", in);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
        printf("cannot read %s\n", in);
        return 1;
    }
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        printf("%s is not a drawing\n", in);
        return 1;
    }
    free(b);
    while (d.nobj > 0)
        jw_remove(&d, d.nobj - 1);
    for (i = 0; i < 6; i++) {
        jw_obj *o = jw_add(&d, JW_ENKO);

        if (!o)
            break;
        o->color = (unsigned short)(i + 1);
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->d[0] = E[i][0];
        o->d[1] = 0.0;
        o->d[2] = E[i][1];
        o->d[3] = E[i][4];
        o->d[4] = E[i][5];
        o->d[5] = E[i][3];
        o->d[6] = E[i][2];
        o->n = E[i][5] >= 2.0 * PI - 1e-9;
    }
    if (!jw_write(&d, &w, &m)) {
        printf("cannot write\n");
        return 1;
    }
    f = fopen(out, "wb");
    if (!f) {
        printf("cannot make %s\n", out);
        return 1;
    }
    fwrite(w, 1, (size_t)m, f);
    fclose(f);
    printf("%s: %d elements, %ld bytes\n", out, d.ndrawn, m);
    return 0;
}
