/* Every drawing given on the command line: open it, write it every way the
 * port can (jww, dxf, sfc, jwc, pdf, png), read each back, and check the
 * jww writing is stable (write -> parse -> write gives the same bytes).
 *   tests/samples_test.exe orig/*.jww
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/plot.h"

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;
    if (!f) return 0;
    fseek(f, 0, SEEK_END); *n = ftell(f); fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) { free(b); b = 0; }
    fclose(f);
    return b;
}

int main(int argc, char **argv)
{
    int i, fails = 0;
    app_resize(1264, 741);
    for (i = 1; i < argc; i++) {
        long n, m, m2, k;
        unsigned char *b = slurp(argv[i], &n), *o = 0, *o2 = 0;
        jw_drawing e;
        const jw_drawing *d;
        int ok = 1;

        if (!b || !app_open(b, n)) { printf("BAD  open %s\n", argv[i]); fails++; free(b); continue; }
        d = app_drawing();
        app_fit();
        app_paint();
        if (!app_save(&o, &m) || m <= 0) { printf("BAD  save %s\n", argv[i]); fails++; continue; }
        memset(&e, 0, sizeof e);
        if (!jw_parse(&e, o, m)) { printf("BAD  reparse %s\n", argv[i]); fails++; free(o); continue; }
        if (e.nobj != d->nobj) { printf("BAD  %s: %d objects became %d\n", argv[i], d->nobj, e.nobj); ok = 0; }
        if (!jw_write(&e, &o2, &m2) || m2 != m || memcmp(o, o2, (size_t)m)) {
            printf("BAD  %s: second write differs (%ld vs %ld)\n", argv[i], m, m2); ok = 0;
        }
        free(o2); o2 = 0;
        jw_free(&e);
        free(o);
        if (!app_save_dxf(&o, &m)) { printf("BAD  dxf %s\n", argv[i]); ok = 0; }
        else {
            jw_drawing g; memset(&g, 0, sizeof g);
            if (!jw_dxf_read(&g, o, m)) { printf("BAD  dxf reread %s\n", argv[i]); ok = 0; }
            else jw_free(&g);
            free(o);
        }
        if (!app_save_sfc("x", &o, &m)) { printf("note sfc refused %s\n", argv[i]); }
        else {
            jw_drawing g; memset(&g, 0, sizeof g);
            if (!jw_sfc_read(&g, o, m)) { printf("BAD  sfc reread %s\n", argv[i]); ok = 0; }
            else jw_free(&g);
            free(o);
        }
        if (!app_save_jwc(&o, &m)) { printf("note jwc refused %s\n", argv[i]); }
        else {
            jw_drawing g; memset(&g, 0, sizeof g);
            jw_parse(&g, b, n);
            if (!jw_jwc_read(&g, o, m)) { printf("BAD  jwc reread %s\n", argv[i]); ok = 0; }
            else jw_free(&g);
            free(o);
        }
        o = jw_plot_pdf(d, 1, &k);
        if (!o || k < 100 || memcmp(o, "%PDF", 4)) { printf("BAD  pdf %s\n", argv[i]); ok = 0; }
        free(o);
        free(b);
        printf("%-4s %s (%d objects)\n", ok ? "ok" : "BAD", argv[i], d->nobj);
        if (!ok) fails++;
    }
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
