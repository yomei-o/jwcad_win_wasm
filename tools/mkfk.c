/* decomp/res/new.jww に 線・円・円弧を置いた図面（複線 1068・1069 を原典に訊くため、tools/fksel.sh は
 * 画面の画素で線を引くので 円弧の端を線の端に ぴったり合わせられない）。
 *
 *   gcc -O2 -Isrc -o tmp/mkfk.exe tools/mkfk.c src/jww.c src/image.c src/imgpic.c \
 *       src/jwwrite.c src/cp932.c
 *   ./tmp/mkfk.exe decomp/res/new.jww tmp/x.jww  L x1 y1 x2 y2  C cx cy r  A cx cy r a0° sweep°  E cx cy r a0° sweep° 扁平 傾き°
 *
 * 座標は図面の mm（新しい図面は 1/100）。 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "rb");
    unsigned char *b, *w = 0;
    long n, m = 0;
    jw_drawing d;
    int i = 3;
    const double D = 3.141592653589793 / 180.0;

    if (!f)
        return 1;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    if (!jw_parse(&d, b, n)) {
        printf("%s: %s\n", argv[1], d.error);
        return 1;
    }
    int at_lt = 1, at_co = 2, at_lay = 0, at_grp = 0;

    /* 環境 MKFK_ATTR="線種,色,レイヤ,グループ" で 置く図形の属性を変える */
    if (getenv("MKFK_ATTR"))
        sscanf(getenv("MKFK_ATTR"), "%d,%d,%d,%d", &at_lt, &at_co, &at_lay, &at_grp);
    while (i < argc) {
        const char *k = argv[i];
        jw_obj *o;

        if (k[0] == 'L') {
            o = jw_add(&d, JW_SEN);
            if (!o)
                return 1;
            o->ltype = (unsigned char)at_lt; o->layer = (unsigned short)at_lay; o->lgroup = (unsigned short)at_grp;
            o->color = (unsigned short)at_co;
            o->d[0] = atof(argv[i + 1]);
            o->d[1] = atof(argv[i + 2]);
            o->d[2] = atof(argv[i + 3]);
            o->d[3] = atof(argv[i + 4]);
            i += 5;
        } else if (k[0] == 'C' || k[0] == 'A' || k[0] == 'E') {
            o = jw_add(&d, JW_ENKO);
            if (!o)
                return 1;
            o->ltype = (unsigned char)at_lt; o->layer = (unsigned short)at_lay; o->lgroup = (unsigned short)at_grp;
            o->color = (unsigned short)at_co;
            o->d[0] = atof(argv[i + 1]);
            o->d[1] = atof(argv[i + 2]);
            o->d[2] = atof(argv[i + 3]);
            o->d[6] = 1.0;
            if (k[0] == 'C') {
                o->d[3] = 0.0;
                o->d[4] = 2.0 * 3.141592653589793;
                o->n = 1;
                i += 4;
            } else {
                o->d[3] = atof(argv[i + 4]) * D;
                o->d[4] = atof(argv[i + 5]) * D;
                i += 6;
                if (k[0] == 'E') {
                    o->d[6] = atof(argv[i]);
                    o->d[5] = atof(argv[i + 1]) * D;
                    i += 2;
                }
            }
        } else
            return 2;
    }
    if (!jw_write(&d, &w, &m))
        return 1;
    f = fopen(argv[2], "wb");
    if (!f || fwrite(w, 1, (size_t)m, f) != (size_t)m)
        return 1;
    fclose(f);
    return 0;
}
