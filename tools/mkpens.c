/* Make a drawing with one line of every pen and every line type, so the
 * original can be asked what colour and line type each one comes out as in
 * its DXF.
 *
 *   gcc -O2 -Isrc -o tmp/mkpens.exe tools/mkpens.c src/jww.c src/jwwrite.c \
 *       src/cp932.c
 *   ./tmp/mkpens.exe orig/Test5.jww tmp/pens.jww
 *
 * It starts from a drawing that is already there, throws its elements away
 * and puts eighteen short lines in their place -- nine across for the pens,
 * nine down for the line types.  Writing it with the port's own writer keeps
 * everything else about the file exactly as it was, which is what makes the
 * original open it without a murmur.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

int main(int argc, char **argv)
{
    const char *in = argc > 1 ? argv[1] : "orig/Test5.jww";
    const char *out = argc > 2 ? argv[2] : "tmp/pens.jww";
    FILE *f = fopen(in, "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    int i;

    if (!f) {
        printf("cannot read %s\n", in);
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
        printf("%s: %s\n", in, d.error);
        return 1;
    }
    free(b);
    while (d.ndrawn > 0)
        jw_remove(&d, d.ndrawn - 1);
    for (i = 1; i <= 9; i++) {
        jw_obj *o = jw_add(&d, JW_SEN);

        if (!o)
            break;
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
        jw_obj *o = jw_add(&d, JW_SEN);

        if (!o)
            break;
        o->color = 2;
        o->ltype = (unsigned short)i;
        o->layer = 0;
        o->lgroup = 0;
        o->d[0] = (double)(i * 10);
        o->d[1] = -100.0;
        o->d[2] = (double)(i * 10);
        o->d[3] = -10.0;
    }
    if (!jw_write(&d, &w, &m)) {
        printf("cannot write\n");
        return 1;
    }
    f = fopen(out, "wb");
    if (!f || fwrite(w, 1, (size_t)m, f) != (size_t)m) {
        printf("cannot write %s\n", out);
        return 1;
    }
    fclose(f);
    printf("%s: %d elements, %ld bytes\n", out, d.ndrawn, m);
    return 0;
}
