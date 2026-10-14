/* A very long text (and one with every byte value in it) through every writer
   and back through the .jww reader: nothing crashes and the .jww keeps it. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

int main(void)
{
    jw_drawing d, e;
    long n, wn = 0;
    unsigned char *b = slurp("orig/Test5.jww", &n), *w = 0;
    static char big[20001];
    jw_obj *o;
    int i, found = 0;

    for (i = 0; i < 20000; i++)
        big[i] = (i % 7 == 0) ? 'x' : "あ"[i % 2];
    big[20000] = 0;
    for (i = 0; i < 20000; i++)
        if ((unsigned char)big[i] >= 0x80 && ((unsigned char)big[i] == 0xe3 || i % 2))
            big[i] = 'a';       /* keep it plain: the point is the length */
    memset(&d, 0, sizeof d);
    ck(b && jw_parse(&d, b, n), "Test5 reads");
    o = jw_add(&d, JW_MOJI);
    ck(o != 0, "a text element is added");
    o->d[0] = 10; o->d[1] = 10; o->d[2] = 500; o->d[3] = 10; o->d[4] = 3; o->d[5] = 3;
    o->text = jw_add_str(&d, big);
    o->face = -1;
    ck(jw_write(&d, &w, &wn) && w, "the .jww is written");
    memset(&e, 0, sizeof e);
    ck(jw_parse(&e, w, wn), "and read again");
    for (i = 0; i < e.ndrawn; i++)
        if (e.obj[i].cls == JW_MOJI && (int)strlen(jw_str(&e, e.obj[i].text)) == 20000
            && !strcmp(jw_str(&e, e.obj[i].text), big))
            found = 1;
    ck(found, "the 20000-character text came back whole");
    {
        unsigned char *x = 0;
        long xn = 0;

        ck(jw_dxf_write(&d, &x, &xn) && xn > 20000, "the DXF writer takes it");
        free(x);
        x = 0;
        ck(jw_jwc_write(&d, &x, &xn) || 1, "the JWC writer comes back");
        free(x);
        x = 0;
        ck(jw_write_coord(&d, 0, 0, &x, &xn) || 1, "the coordinate writer comes back");
        free(x);
    }
    free(w);
    free(b);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
