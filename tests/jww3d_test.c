/* CData3DSen / CData3DEnko / CData3DSolid: no sample drawing exists, so the
 * shape (common 15 bytes, then 6 / 7 / 12 doubles -- FUN_00442860,
 * FUN_004426f0, FUN_00442990) is checked by writing and reading back, among
 * ordinary elements, and by writing the result again byte for byte. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"
#include "../src/gen/newjww.h"

static int bad;

static void check(int ok, const char *what)
{
    if (!ok) {
        printf("BAD   %s\n", what);
        bad++;
    }
}

int main(void)
{
    jw_drawing d, back;
    unsigned char *out = 0, *out2 = 0;
    long n = 0, n2 = 0;
    int i, k;
    static const int NUM[3] = { 6, 7, 12 };
    static const int CLS[3] = { JW_3DSEN, JW_3DENKO, JW_3DSOLID };

    check(jw_parse(&d, jw_new_jww, jw_new_jww_len), "parse new.jww");
    for (i = 0; i < JW_NCLASS; i++)
        if (!d.schema[i])
            d.schema[i] = 700;

    for (i = 0; i < 7; i++) {
        int c = i % 4 == 3 ? JW_SEN : CLS[i % 4 % 3];
        jw_obj *o = jw_add(&d, c);

        check(o != 0, "add");
        if (!o)
            return 1;
        o->color = (unsigned short)(i + 1);
        o->ltype = (unsigned char)(i + 1);
        o->width = (unsigned short)i;
        if (c == JW_SEN) {
            o->d[0] = 1; o->d[1] = 2; o->d[2] = 3; o->d[3] = 4;
        } else {
            int m = c == JW_3DSEN ? 6 : c == JW_3DENKO ? 7 : 12;
            for (k = 0; k < m; k++) {
                double x = i * 100.0 + k + 0.25;
                if (k < 8)
                    o->d[k] = x;
                else
                    o->e[k - 8] = x;
            }
        }
    }
    check(jw_write(&d, &out, &n), "write");
    check(jw_parse(&back, out, n), back.error ? back.error : "parse");
    check(back.ndrawn == d.ndrawn, "count");
    for (i = 0; i < back.ndrawn; i++) {
        const jw_obj *a = &d.obj[i], *b = &back.obj[i];
        int m = a->cls == JW_3DSEN ? 6 : a->cls == JW_3DENKO ? 7
              : a->cls == JW_3DSOLID ? 12 : 4;

        check(a->cls == b->cls, "class");
        check(a->color == b->color && a->ltype == b->ltype
              && a->width == b->width, "common fields");
        for (k = 0; k < m; k++)
            check((k < 8 ? a->d[k] == b->d[k] : a->e[k - 8] == b->e[k - 8]),
                  "double");
    }
    check(jw_write(&back, &out2, &n2) && n2 == n && !memcmp(out, out2, (size_t)n),
          "second write identical");
    (void)NUM;
    printf("%s\n", bad ? "FAILED" : "all ok (3 classes, out and back)");
    return bad ? 1 : 0;
}
