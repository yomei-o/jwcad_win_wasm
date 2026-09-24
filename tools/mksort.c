/* A drawing to ask the original what データ整理's other buttons do.
 *
 *   tools/mksort.exe orig/Test5.jww tmp/sort.jww
 *
 * Six lines whose colours are in no order, and six texts turned to six
 * different angles.  色順整理 is meant to put the lines in colour order and
 * 文字角度整理 to do something to the angles; this is a drawing where both
 * would show.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../src/jww.h"

int main(int argc, char **argv)
{
    static const int COL[6] = { 3, 1, 5, 2, 4, 6 };
    static const double ANG[6] = { 0.0, 45.0, 90.0, 135.0, 180.0, 270.0 };
    FILE *f;
    unsigned char *b, *out;
    long n, m;
    jw_drawing d;
    jw_obj *o;
    int i, face = -1;

    if (argc < 3) {
        printf("mksort <in.jww> <out.jww>\n");
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

    for (i = 0; i < 6; i++) {
        /* with a third argument the lines are all one colour and out of
           order down the sheet, to see whether 線ソート moves them */
        static const double Y[6] = { 60.0, 10.0, 40.0, 30.0, 50.0, 20.0 };

        o = jw_add(&d, JW_SEN);
        if (!o)
            return 1;
        o->color = (unsigned short)(argc > 4 ? (i % 2) + 1
                                    : argc > 3 ? 1 : COL[i]);
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->d[0] = -50.0;
        o->d[1] = argc > 3 ? Y[i] : 60.0 - i * 10.0;
        o->d[2] = 50.0;
        o->d[3] = o->d[1];
    }
    for (i = 0; i < 6; i++) {
        double a = ANG[i] * 3.14159265358979323846 / 180.0;

        o = jw_add(&d, JW_MOJI);
        if (!o)
            return 1;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->n = 1;
        o->d[0] = -50.0 + i * 20.0;
        o->d[1] = -40.0;
        /* the baseline runs at the angle, six long for four letters at
           three wide with nothing between them */
        o->d[2] = o->d[0] + 6.0 * cos(a);
        o->d[3] = o->d[1] + 6.0 * sin(a);
        o->d[4] = 3.0;
        o->d[5] = 3.0;
        o->d[6] = 0.0;
        o->d[7] = ANG[i];
        o->text = jw_add_str(&d, "ABCD");
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
