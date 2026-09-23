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

/* A drawing big enough that CArchive cannot say an object's number in a
   word any more.  Past 0x3ffe it writes 0x7fff and then a long, and a
   reader that does not know that gives up in the middle -- which is what
   this port used to do with any drawing of more than about sixteen
   thousand elements.  Nothing here needs the original: the drawing is
   written, read again, and the two have to agree. */
static int many(const char *base)
{
    FILE *f = fopen(base, "rb");
    unsigned char *b, *out = 0;
    long n, m = 0;
    jw_drawing d, back;
    int i, bad = 0;
    const int N = 20000;

    if (!f) {
        printf("BAD   %s: cannot open\n", base);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
        printf("BAD   %s: cannot read\n", base);
        fclose(f);
        free(b);
        return 1;
    }
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        printf("BAD   %s: %s\n", base, d.error);
        free(b);
        return 1;
    }
    free(b);
    while (d.nobj > 0)
        jw_remove(&d, d.nobj - 1);
    for (i = 0; i < N; i++) {
        jw_obj *o = jw_add(&d, JW_SEN);

        if (!o) {
            printf("BAD   out of memory at %d\n", i);
            return 1;
        }
        o->color = (unsigned short)(i % 8 + 1);
        o->ltype = (unsigned char)(i % 9 + 1);
        o->d[0] = (double)(i % 200) - 100.0;
        o->d[1] = (double)(i / 200) - 50.0;
        o->d[2] = o->d[0] + 1.0;
        o->d[3] = o->d[1];
    }
    if (!jw_write(&d, &out, &m)) {
        printf("BAD   %d elements: cannot write\n", N);
        return 1;
    }
    if (!jw_parse(&back, out, m)) {
        printf("BAD   %d elements: %s\n", N, back.error);
        free(out);
        return 1;
    }
    free(out);
    if (back.ndrawn != N) {
        printf("BAD   %d elements went out, %d came back\n", N, back.ndrawn);
        bad = 1;
    } else {
        for (i = 0; i < N; i++)
            if (back.obj[i].color != d.obj[i].color
                || back.obj[i].ltype != d.obj[i].ltype
                || back.obj[i].d[0] != d.obj[i].d[0]
                || back.obj[i].d[1] != d.obj[i].d[1]) {
                printf("BAD   element %d came back different\n", i);
                bad = 1;
                break;
            }
    }
    if (!bad)
        printf("ok    %d elements, past the word-sized tag, out and back\n",
               N);
    jw_free(&d);
    jw_free(&back);
    return bad;
}

int main(int argc, char **argv)
{
    int i, bad = 0;

    for (i = 1; i < argc; i++)
        bad += one(argv[i]);
    if (argc > 1)
        bad += many(argv[1]);
    printf("%s\n", bad ? "FAILED" : "all ok");
    return bad ? 1 : 0;
}
