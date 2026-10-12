#include <stdio.h>
#include <stdlib.h>
#include "../src/jww.h"
int main(int c, char **v)
{
    FILE *f = fopen(v[1], "rb"); unsigned char *b; long n; jw_drawing d; int i;
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    b = malloc(n); fread(b, 1, n, f); fclose(f);
    if (!jw_parse(&d, b, n)) return 1;
    for (i = 0; i < d.nobj; i++) {
        const jw_obj *o = &d.obj[i];
        printf("%s%d cls%d %g %g %g %g | lay %d/%d col %d fl %x\n", i < d.ndrawn ? "draw" : "def", i, o->cls, o->d[0], o->d[1], o->d[2], o->d[3], o->lgroup, o->layer, o->color, o->flags);
    }
    return 0;
}
