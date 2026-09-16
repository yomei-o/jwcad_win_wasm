/* Read a drawing and write it straight back: the bytes have to be the same.
 *
 *   tests/write_test.exe orig/[every drawing]
 *
 * That is the whole check.  The header is copied through, so what this
 * really tests is the element list -- the class tags, CArchive's numbering,
 * CData::Serialize and each class's body -- and it only passes if every one
 * of them is written exactly the way the original wrote it.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"

static int one(const char *path)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b, *out = 0;
    long n, m = 0, i;
    jw_drawing d;
    int ok = 0;

    if (!f) {
        printf("BAD   %s: cannot open\n", path);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
        printf("BAD   %s: cannot read\n", path);
        fclose(f);
        free(b);
        return 1;
    }
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        printf("BAD   %s: %s\n", path, d.error);
        free(b);
        jw_free(&d);
        return 1;
    }
    if (!jw_write(&d, &out, &m)) {
        printf("BAD   %s: cannot write it back\n", path);
    } else if (m != n) {
        printf("BAD   %-28s %ld bytes in, %ld out\n", path, n, m);
    } else {
        for (i = 0; i < n && b[i] == out[i]; i++)
            ;
        if (i < n)
            printf("BAD   %-28s first difference at %ld of %ld\n", path, i, n);
        else {
            printf("ok    %-28s %ld bytes, identical\n", path, n);
            ok = 1;
        }
    }
    free(out);
    free(b);
    jw_free(&d);
    return !ok;
}

int main(int argc, char **argv)
{
    int i, bad = 0;

    for (i = 1; i < argc; i++)
        bad += one(argv[i]);
    printf("%s\n", bad ? "FAILED" : "all ok");
    return bad ? 1 : 0;
}
