/* What the port's reader makes of a drawing, one element a line -- for
 * diffing what the original saved (tools/whatdid.py cannot decode a
 * CDataSunpou).
 *
 *   gcc -O2 -Isrc -o tmp/jwdump.exe tools/jwdump.c src/jww.c src/image.c \
 *       src/imgpic.c src/jwwrite.c src/cp932.c
 *   ./tmp/jwdump.exe a.jww > a.txt
 */
#include <stdio.h>
#include <stdlib.h>

#include "jww.h"

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    unsigned char *b;
    long n;
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
    printf("group0 state=%d write=%d layers", d.group[0].state, d.group[0].write_layer);
    for (i = 0; i < 16; i++)
        printf(" %d", d.group[0].layer[i].state);
    printf("\n");
    for (i = 0; i < d.ndrawn; i++) {
        const jw_obj *o = &d.obj[i];

        if (o->cls == JW_MOJI && o->layer == 0 && o->d[1] == -1000.0)
            continue;
        printf("%3d cls=%d sub=%d id=%d lt=%d co=%d w=%d lay=%d grp=%d mark=%x"
               " L=%x,%x,%x d=%.9f,%.9f,%.9f,%.9f\n",
               i, o->cls, o->sub, o->id, o->ltype, o->color, o->width, o->layer,
               o->lgroup, (unsigned)o->mark, (unsigned)o->list[0], (unsigned)o->list[1], (unsigned)o->list[2], o->d[0], o->d[1], o->d[2], o->d[3]);
        if (o->cls == JW_MOJI && o->text >= 0 && o->d[1] != -1000.0)
            printf("    text [%s] deg=%.6f size=%.3f,%.3f,%.3f\n", jw_str(&d, o->text), o->d[7],
                   o->d[4], o->d[5], o->d[6]);
    }
    return 0;
}
