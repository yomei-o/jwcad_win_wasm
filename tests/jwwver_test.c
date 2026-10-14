/* A .jww whose version field says something older (or newer) than the file
   really is: the reader may refuse it or read nonsense, but it must come
   back -- no crash, no endless loop, no gigantic allocation.  Also the
   two versions the samples really have (600 and 700) must read. */
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
    static const char *const files[] = { "orig/Test5.jww", "orig/Test1.jww", "decomp/res/bt_nest2.jww" };
    int f, v, tried = 0, read = 0;

    for (f = 0; f < 3; f++) {
        long n;
        unsigned char *b = slurp(files[f], &n), *c;
        jw_drawing d;

        if (!b) {
            printf("BAD  cannot read %s\n", files[f]);
            fails++;
            continue;
        }
        memset(&d, 0, sizeof d);
        ck(jw_parse(&d, b, n), files[f]);
        jw_free(&d);
        c = (unsigned char *)malloc((size_t)n);
        for (v = 0; v <= 900; v += 3) {
            memcpy(c, b, (size_t)n);
            c[8] = (unsigned char)(v & 255);
            c[9] = (unsigned char)(v >> 8);
            c[10] = c[11] = 0;
            memset(&d, 0, sizeof d);
            tried++;
            if (jw_parse(&d, c, n))
                read++;
            jw_free(&d);
        }
        free(c);
        free(b);
    }
    printf("     %d odd versions tried, %d read\n", tried, read);
    ck(tried > 800, "every odd version came back");
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
