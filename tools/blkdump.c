/* list the block references and definitions of a .jww: tools/blkdump.exe file */
#include <stdio.h>
#include <stdlib.h>
#include "../src/jww.h"
int main(int c, char **v)
{
    FILE *f = fopen(v[1], "rb");
    unsigned char *b; long n; jw_drawing d; int i;
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    b = malloc(n); fread(b, 1, n, f); fclose(f);
    if (!jw_parse(&d, b, n)) return 1;
    for (i = 0; i < d.nobj; i++) {
        const jw_obj *o = &d.obj[i];
        if (o->cls == JW_BLOCK)
            printf("%s[%d] BLOCK ->%d at %g,%g sc %g,%g rot %g layer %d/%d col %d lt %d fl %x\n",
                   i < d.ndrawn ? "draw" : "def ", i, o->block, o->d[0], o->d[1], o->d[2], o->d[3], o->d[4], o->lgroup, o->layer, o->color, o->ltype, o->flags);
        else if (o->cls == JW_LIST)
            printf("def [%d] LIST num=%d fl=%d t=%d n=%d '%s'\n", i, o->list[0], o->list[1], o->list[2], o->n, jw_str(&d, o->text));
        else if (i >= d.ndrawn)
            printf("def [%d]   cls %d\n", i, o->cls);
    }
    return 0;
}
