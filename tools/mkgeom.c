/* Make a drawing of everything the DXF reader understands, so the original
 * can be asked what it makes of it.
 *
 *   gcc -O2 -Isrc -o tmp/mkgeom.exe tools/mkgeom.c src/jww.c src/jwwrite.c \
 *       src/cp932.c
 *   ./tmp/mkgeom.exe orig/Test5.jww tmp/geom.jww
 *
 * Lines, arcs both ways round, a whole circle, points and solids -- and no
 * text, because a text is the one thing tests/dxfread_test.c cannot line up
 * (the original leaves its own memo texts in every drawing it saves).  The
 * drawing goes through the original twice: out as DXF, and back in.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

static jw_obj *add(jw_drawing *d, int cls, int color, int ltype)
{
    jw_obj *o = jw_add(d, cls);

    if (o) {
        o->color = (unsigned short)color;
        o->ltype = (unsigned char)ltype;
        o->layer = 0;
        o->lgroup = 0;
    }
    return o;
}

int main(int argc, char **argv)
{
    const char *in = argc > 1 ? argv[1] : "orig/Test5.jww";
    const char *out = argc > 2 ? argv[2] : "tmp/geom.jww";
    FILE *f = fopen(in, "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    jw_obj *o;
    int i;

    if (!f) {
        printf("cannot read %s\n", in);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
        printf("cannot read %s\n", in);
        return 1;
    }
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        printf("%s: %s\n", in, d.error);
        return 1;
    }
    free(b);
    while (d.ndrawn > 0)
        jw_remove(&d, d.ndrawn - 1);

    /* four lines, so the colours and line types are in there too */
    for (i = 0; i < 4; i++) {
        o = add(&d, JW_SEN, i + 1, i + 1);
        if (!o)
            break;
        o->d[0] = -90.0;
        o->d[1] = 60.0 - i * 10.0;
        o->d[2] = 90.0;
        o->d[3] = 60.0 - i * 10.0;
    }
    /* arcs: a quarter, a half the other way round, one that starts past the
       top, and a whole circle */
    {
        static const double A[4][3] = {
            { 0.0, 1.5707963267948966, 0.0 },
            { 3.141592653589793, -1.5707963267948966, 0.0 },
            { 4.71238898038469, 2.0943951023931953, 0.0 },
            { 0.0, 6.283185307179586, 0.0 },
        };
        for (i = 0; i < 4; i++) {
            o = add(&d, JW_ENKO, i + 2, 1);
            if (!o)
                break;
            o->d[0] = -60.0 + i * 40.0;
            o->d[1] = -30.0;
            o->d[2] = 15.0;
            o->d[3] = A[i][0];
            o->d[4] = A[i][1];
            o->d[5] = A[i][2];
            o->d[6] = 1.0;
        }
    }
    /* two points */
    for (i = 0; i < 2; i++) {
        o = add(&d, JW_TEN, i + 3, 1);
        if (!o)
            break;
        o->d[0] = -20.0 + i * 40.0;
        o->d[1] = -70.0;
    }
    /* two solids: a triangle (the last corner doubled) and a quadrilateral */
    o = add(&d, JW_SOLID, 4, 1);
    if (o) {
        o->d[0] = -80.0; o->d[1] = -80.0;
        o->d[2] = -50.0; o->d[3] = -80.0;
        o->d[4] = -65.0; o->d[5] = -55.0;
        o->d[6] = -65.0; o->d[7] = -55.0;
    }
    o = add(&d, JW_SOLID, 5, 1);
    if (o) {
        o->d[0] = 50.0; o->d[1] = -80.0;
        o->d[2] = 85.0; o->d[3] = -80.0;
        o->d[4] = 85.0; o->d[5] = -55.0;
        o->d[6] = 55.0; o->d[7] = -50.0;
    }

    if (!jw_write(&d, &w, &m)) {
        printf("cannot write\n");
        return 1;
    }
    f = fopen(out, "wb");
    if (!f || fwrite(w, 1, (size_t)m, f) != (size_t)m) {
        printf("cannot write %s\n", out);
        return 1;
    }
    fclose(f);
    printf("%s: %d elements, %ld bytes\n", out, d.ndrawn, m);
    return 0;
}
