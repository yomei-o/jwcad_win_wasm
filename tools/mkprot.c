/* A drawing for asking the original what AM 5 does on a protected layer:
 * a line on layer 0 (protected: layer.state2 = 1 -- or the group's `c` with
 * argv[3] = "g"), a control line on layer 1, write layer 2.
 *
 *   gcc -O2 -Isrc -o tmp/mkprot.exe tools/mkprot.c src/jww.c src/image.c \
 *       src/imgpic.c src/jwwrite.c src/cp932.c
 *   ./tmp/mkprot.exe decomp/res/new.jww tmp/prot.jww [g]
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    jw_obj *o;
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
    for (i = 0; i < 2; i++) {
        o = jw_add(&d, JW_SEN);
        o->color = 2;
        o->ltype = 1;
        o->layer = (unsigned short)i;
        o->lgroup = 0;
        o->d[0] = -155.510204;
        o->d[2] = 89.387755;
        o->d[1] = o->d[3] = i ? -187.959184 : -157.346939;
    }
    d.group[0].layer[d.group[0].write_layer].state = 2;
    d.group[0].write_layer = 2;
    d.group[0].layer[2].state = 3;
    if (argc > 3 && argv[3][0] == 'g')
        d.group[0].c = 1;
    else
        d.group[0].layer[0].state2 = 1;
    if (!jw_write(&d, &w, &m))
        return 1;
    f = fopen(argv[2], "wb");
    if (!f || fwrite(w, 1, (size_t)m, f) != (size_t)m)
        return 1;
    fclose(f);
    return 0;
}
