/* DXF files with numbers no drawing can hold, read the way 開く reads them.
 *
 *   tests/dxfextreme_test.exe
 *
 * 1e999 (infinity), nan, 1e308, -1e12 and the like in every place a DXF
 * keeps a number: the reader must come back, and what it leaves in the
 * drawing must be numbers a drawing can hold (jw_numbers_sane), which then
 * paint and write out every way the port can write. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static const char *V[] = { "1e999", "-1e999", "nan", "inf", "1e308", "-1e308", "999999999999999",
                           "1e12", "-1e12", "0", "-0", "1e-320", "abc", "", "--5", "5e", "0x10" };

int main(void)
{
    static const char *ENT[] = { "LINE", "CIRCLE", "ARC", "POINT", "TEXT", "LWPOLYLINE", "ELLIPSE", "SOLID",
                                 "INSERT", "DIMENSION", "SPLINE" };
    char buf[4096];
    unsigned e, v, w;
    int bad = 0, tried = 0;

    app_resize(640, 480);
    for (e = 0; e < sizeof ENT / sizeof ENT[0]; e++)
        for (v = 0; v < sizeof V / sizeof V[0]; v++)
            for (w = 0; w < 3; w++) {
                /* the value goes into group codes 10,20,30,11,21,31,40,41,50,51 in turn
                   (all of them with it, or only one) */
                static const int CODES[] = { 10, 20, 30, 11, 21, 31, 40, 41, 50, 51, 42, 43, 70, 71 };
                char *p = buf;
                unsigned k;
                jw_drawing d;
                unsigned char *o;
                long n;

                p += sprintf(p, "0\r\nSECTION\r\n2\r\nENTITIES\r\n0\r\n%s\r\n8\r\n0\r\n", ENT[e]);
                for (k = 0; k < sizeof CODES / sizeof CODES[0]; k++)
                    p += sprintf(p, "%d\r\n%s\r\n", CODES[k],
                                 (w == 0 || (w == 1 && k % 2 == 0) || (w == 2 && k == v % 8)) ? V[v] : "10");
                p += sprintf(p, "0\r\nENDSEC\r\n0\r\nEOF\r\n");
                memset(&d, 0, sizeof d);
                tried++;
                if (jw_dxf_read(&d, (const unsigned char *)buf, (long)(p - buf))) {
                    if (!jw_numbers_sane(&d)) {
                        printf("   %s with %s (variant %u) leaves an insane number\n", ENT[e], V[v], w);
                        bad++;
                    }
                    if (jw_write(&d, &o, &n))
                        free(o);
                    if (jw_dxf_write(&d, &o, &n))
                        free(o);
                    if (jw_jwc_write(&d, &o, &n))
                        free(o);
                    if (jw_sfc_write(&d, "x", "2026-01-01", &o, &n))
                        free(o);
                    if (jw_write(&d, &o, &n)) {
                        if (app_open(o, n))
                            app_paint();
                        free(o);
                    }
                }
                jw_free(&d);
            }
    ck(bad == 0, "no DXF value leaves a number a drawing cannot hold");
    printf("%d files tried\n", tried);
    return fails != 0;
}
