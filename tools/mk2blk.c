/* blkmake.jww with a second reference to the same definition, off to the
   right, so that ブロック編集's 選択したブロックのみに can be told apart
   from すべてのブロックに. */
#include <stdio.h>
#include <stdlib.h>
#include "../src/jww.h"
int main(int c, char **v)
{
    FILE *f = fopen(v[1], "rb");
    unsigned char *b, *out; long n, m; jw_drawing d; jw_obj *o; int i, at = -1;
    fseek(f, 0, SEEK_END); n = ftell(f); fseek(f, 0, SEEK_SET);
    b = malloc(n); fread(b, 1, n, f); fclose(f);
    if (!jw_parse(&d, b, n)) return 1;
    free(b);
    for (i = 0; i < d.ndrawn; i++)
        if (d.obj[i].cls == JW_BLOCK) { at = i; break; }
    if (at < 0) return 1;
    o = jw_add(&d, JW_BLOCK);
    if (!o) return 1;
    *o = d.obj[at];
    o->d[0] += 300.0;
    o->id = 0;
    o->sel = 0;
    o->flags = 0;
    if (!jw_write(&d, &out, &m)) return 1;
    f = fopen(v[2], "wb"); fwrite(out, 1, m, f); fclose(f);
    printf("%s %ld bytes, %d drawn\n", v[2], m, d.ndrawn);
    return 0;
}
