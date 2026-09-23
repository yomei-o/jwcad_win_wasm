/* A drawing to ask the original what データ整理 does.
 *
 *   tools/mkseiri.exe orig/Test5.jww tmp/seiri.jww
 *
 * Pairs of elements, each pair a different kind of "the same":
 *
 *   0,1   two lines exactly on top of each other
 *   2,3   two lines that overlap along part of their length
 *   4,5   two lines that meet end to end and run the same way
 *   6,7   two lines that meet end to end but do not (one is bent)
 *   8,9   two lines exactly on top of each other in different colours
 *  10,11  two lines exactly on top of each other in different line types
 *  12,13  two lines exactly on top of each other on different layers
 *  14,15  two arcs exactly on top of each other
 *  16,17  two points in the same place
 *  18,19  two texts in the same place saying the same thing
 *
 * Each pair is on a row of its own so the answer can be read by looking at
 * what is left where.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"

static jw_obj *line(jw_drawing *d, double x0, double y0, double x1,
                    double y1, int col, int lt, int layer)
{
    jw_obj *o = jw_add(d, JW_SEN);

    if (!o)
        return 0;
    o->color = (unsigned short)col;
    o->ltype = (unsigned char)lt;
    o->layer = (unsigned short)layer;
    o->lgroup = 0;
    o->width = 0;
    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
    return o;
}

int main(int argc, char **argv)
{
    FILE *f;
    unsigned char *b, *out;
    long n, m;
    jw_drawing d;
    jw_obj *o;
    int i, face = -1;

    if (argc < 3) {
        printf("mkseiri <in.jww> <out.jww>\n");
        return 1;
    }
    f = fopen(argv[1], "rb");
    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    if (!jw_parse(&d, b, n))
        return 1;
    free(b);
    for (i = 0; i < d.ndrawn; i++)
        if (d.obj[i].cls == JW_MOJI && d.obj[i].face >= 0) {
            face = d.obj[i].face;
            break;
        }
    while (d.ndrawn > 0)
        jw_remove(&d, d.ndrawn - 1);

    line(&d, -80.0,  70.0, -30.0,  70.0, 1, 1, 0);      /* 0 */
    line(&d, -80.0,  70.0, -30.0,  70.0, 1, 1, 0);      /* 1 */
    line(&d, -80.0,  60.0, -30.0,  60.0, 1, 1, 0);      /* 2 */
    line(&d, -55.0,  60.0,  -5.0,  60.0, 1, 1, 0);      /* 3 */
    line(&d, -80.0,  50.0, -55.0,  50.0, 1, 1, 0);      /* 4 */
    line(&d, -55.0,  50.0, -30.0,  50.0, 1, 1, 0);      /* 5 */
    line(&d, -80.0,  40.0, -55.0,  40.0, 1, 1, 0);      /* 6 */
    line(&d, -55.0,  40.0, -30.0,  45.0, 1, 1, 0);      /* 7 */
    line(&d, -80.0,  30.0, -30.0,  30.0, 1, 1, 0);      /* 8 */
    line(&d, -80.0,  30.0, -30.0,  30.0, 2, 1, 0);      /* 9 */
    line(&d, -80.0,  20.0, -30.0,  20.0, 1, 1, 0);      /* 10 */
    line(&d, -80.0,  20.0, -30.0,  20.0, 1, 2, 0);      /* 11 */
    line(&d, -80.0,  10.0, -30.0,  10.0, 1, 1, 0);      /* 12 */
    line(&d, -80.0,  10.0, -30.0,  10.0, 1, 1, 1);      /* 13 */

    for (i = 0; i < 2; i++) {                           /* 14, 15 */
        o = jw_add(&d, JW_ENKO);
        if (!o)
            return 1;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->d[0] = 20.0;
        o->d[1] = 50.0;
        o->d[2] = 15.0;
        o->d[3] = 0.0;
        o->d[4] = 1.5707963267948966;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
    }
    for (i = 0; i < 2; i++) {                           /* 16, 17 */
        o = jw_add(&d, JW_TEN);
        if (!o)
            return 1;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->d[0] = 20.0;
        o->d[1] = 20.0;
    }
    for (i = 0; i < 2; i++) {                           /* 18, 19 */
        o = jw_add(&d, JW_MOJI);
        if (!o)
            return 1;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->n = 1;
        o->d[0] = 20.0;
        o->d[1] = 0.0;
        o->d[2] = 40.0;
        o->d[3] = 0.0;
        o->d[4] = 3.0;
        o->d[5] = 3.0;
        o->d[6] = 0.5;
        o->d[7] = 0.0;
        o->text = jw_add_str(&d, "ABC");
        o->face = face;
    }

    if (!jw_write(&d, &out, &m))
        return 1;
    f = fopen(argv[2], "wb");
    if (!f)
        return 1;
    fwrite(out, 1, (size_t)m, f);
    fclose(f);
    printf("%s: %d elements, %ld bytes\n", argv[2], d.ndrawn, m);
    return 0;
}
