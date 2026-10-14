/* A drawing made up here, with the awkward values -- a line of no length, a
   very far one, arcs both ways round, a whole circle, a text of every kind, a
   point and a solid -- through each writer and back through its reader. */
#include <math.h>
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

static jw_obj *add(jw_drawing *d, int cls, double a, double b, double c, double e)
{
    jw_obj *o = jw_add(d, cls);

    o->d[0] = a; o->d[1] = b; o->d[2] = c; o->d[3] = e;
    o->color = 1; o->ltype = 1; o->layer = 0; o->lgroup = 0;
    o->text = o->face = -1;
    return o;
}

static int drawn(const jw_drawing *d, int cls)
{
    int i, k = 0;

    for (i = 0; i < d->ndrawn; i++)
        k += d->obj[i].cls == cls;
    return k;
}

int main(void)
{
    jw_drawing d, e;
    long n, wn = 0;
    unsigned char *b = slurp("orig/Test5.jww", &n), *w = 0;
    jw_obj *o;

    memset(&d, 0, sizeof d);
    ck(b && jw_parse(&d, b, n), "base reads");
    while (d.nobj > 0)
        jw_remove(&d, d.nobj - 1);
    add(&d, JW_SEN, 10, 10, 200, 10);
    add(&d, JW_SEN, 50, 50, 50, 50);                    /* no length */
    add(&d, JW_SEN, -1e5, -1e5, 1e5, 1e5);              /* far */
    o = add(&d, JW_ENKO, 100, 100, 30, 0.5); o->d[4] = 1.0; o->d[5] = 0; o->d[6] = 1;
    o = add(&d, JW_ENKO, 100, 100, 20, 1.0); o->d[4] = -2.0; o->d[5] = 0; o->d[6] = 1;
    o = add(&d, JW_ENKO, 200, 100, 15, 0.0); o->d[4] = 6.283185307179586; o->d[5] = 0; o->d[6] = 1;
    o = add(&d, JW_TEN, 20, 20, 0, 0);
    o = add(&d, JW_SOLID, 0, 0, 10, 0); o->d[4] = 10; o->d[5] = 10; o->d[6] = 0; o->d[7] = 10;
    o = add(&d, JW_MOJI, 10, 150, 80, 150); o->d[4] = 3; o->d[5] = 3; o->d[6] = 0.5; o->d[7] = 0;
    o->text = jw_add_str(&d, "ABC\x82\xa0\x8a\xbf");
    o->face = jw_add_str(&d, "MS Gothic");
    d.ndrawn = d.nobj;
    ck(d.ndrawn == 9, "nine elements made");

    ck(jw_write(&d, &w, &wn) && w, ".jww writes");
    memset(&e, 0, sizeof e);
    ck(jw_parse(&e, w, wn) && e.ndrawn == 9, "  and reads back whole");
    ck(fabs(e.obj[2].d[0] + 1e5) < 1e-6 && drawn(&e, JW_ENKO) == 3, "  the far line and the three arcs");
    free(w);
    w = 0;

    ck(jw_jwc_write(&d, &w, &wn) && w, "JWC writes");
    {
        jw_drawing j;

        memset(&j, 0, sizeof j);
        jw_parse(&j, slurp("orig/Test5.jww", &n), n);
        ck(jw_jwc_read(&j, w, wn), "  and reads back");
        ck(j.ndrawn > 0, "  with something in it");
        jw_free(&j);
    }
    free(w);
    w = 0;

    ck(jw_write_jws(&d, 0, 0, &w, &wn) && w, ".jws writes");
    {
        jw_drawing j;
        double bx, by;

        memset(&j, 0, sizeof j);
        ck(jw_parse_jws(&j, w, wn, &bx, &by) && j.ndrawn >= 8, "  and reads back (" );
        printf("     %d elements\n", j.ndrawn);
        jw_free(&j);
    }
    free(w);
    w = 0;

    {
        unsigned char *s1 = 0, *s2 = 0;
        long n1 = 0, n2 = 0;

        ck(jw_sfc_write(&d, "t.sfc", "20260101000000", &s1, &n1) && s1, "SFC writes");
        {
            jw_drawing j;

            memset(&j, 0, sizeof j);
            jw_parse(&j, slurp("orig/Test5.jww", &n), n);
            ck(jw_sfc_read(&j, s1, n1), "  and reads back");
            jw_free(&j);
        }
        ck(jw_sfc_write(&d, "t.sfc", "20260101000000", &s2, &n2) && n1 == n2 && !memcmp(s1, s2, (size_t)n1),
           "  and writing the same drawing twice gives the same bytes");
        free(s1);
        free(s2);
    }
    ck(1, "(done)");
    free(b);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
