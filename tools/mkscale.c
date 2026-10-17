/* A copy of a drawing with every layer group at another scale -- for asking
 * the original what a length that is "in the drawing's units" comes to at
 * 1/50 (or whatever) instead of 1/100.
 *
 *   gcc -O2 -Isrc -o tmp/mkscale.exe tools/mkscale.c src/jww.c src/image.c \
 *       src/imgpic.c src/jwwrite.c src/cp932.c
 *   ./tmp/mkscale.exe decomp/res/new.jww tmp/s50.jww 50
 */
#include <stdio.h>
#include <stdlib.h>

#include "jww.h"

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    int i;

    if (!f)
        return 1;
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
    for (i = 0; i < 16; i++)
        d.group[i].scale = atof(argv[3]);
    if (!jw_write(&d, &w, &m))
        return 1;
    f = fopen(argv[2], "wb");
    if (!f || fwrite(w, 1, (size_t)m, f) != (size_t)m)
        return 1;
    fclose(f);
    return 0;
}
