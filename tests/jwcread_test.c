/* JWC 読み込み -- against the drawing the original made of the same file.
 *
 *   tests/jwcread_test.exe
 *
 * tools/refanswers.sh has the original write a JWC and open it again.  This
 * opens the same base drawing, reads the same JWC into it, and the elements
 * have to come out the same.
 */
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

static int open_jww(jw_drawing *d, const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);
    int ok;

    if (!b) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        return 0;
    }
    ok = jw_parse(d, b, n);
    free(b);
    if (!ok) {
        printf("BAD  %s: %s\n", path, d->error);
        fails++;
    }
    return ok;
}

static int ndbl(int cls)
{
    switch (cls) {
    case JW_SEN:   return 4;
    case JW_ENKO:  return 7;
    case JW_TEN:   return 2;
    case JW_MOJI:  return 7;    /* the turn is not kept in a JWC */
    }
    return 0;
}

static const jw_drawing *ja, *jb;

static int same(const jw_obj *a, const jw_obj *b)
{
    int i;

    if (a->cls != b->cls || a->ltype != b->ltype || a->color != b->color
        || a->layer != b->layer || a->lgroup != b->lgroup || a->n != b->n)
        return 0;
    if (a->cls == JW_MOJI && strcmp(jw_str(ja, a->text), jw_str(jb, b->text)))
        return 0;
    for (i = 0; i < ndbl(a->cls); i++) {
        double x = a->d[i], y = b->d[i];

        /* a JWC keeps its coordinates as 32-bit floats, so they come back
           to about seven figures and no further */
        if (fabs(x - y) > 1e-6 * (fabs(x) + fabs(y)) + 1e-6)
            return 0;
    }
    return 1;
}

static void show(const jw_drawing *d, const char *who, const jw_obj *o)
{
    int i;

    printf("     %s cls %d ltype %d colour %d layer %d n %d",
           who, o->cls, o->ltype, o->color, o->layer, o->n);
    for (i = 0; i < ndbl(o->cls); i++)
        printf(" %.8g", o->d[i]);
    printf(" %s\n", jw_str(d, o->text));
}

/* Read `jwc` into a copy of `base` and hold the result against `answer`. */
static void alike(const char *base, const char *jwc, const char *answer,
                  const char *what)
{
    jw_drawing mine, ref;
    unsigned char *b;
    long n;
    int i, bad = -1;

    memset(&mine, 0, sizeof mine);
    memset(&ref, 0, sizeof ref);
    if (!open_jww(&mine, base) || !open_jww(&ref, answer))
        return;
    b = slurp(jwc, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", jwc);
        fails++;
        return;
    }
    ja = &mine;
    jb = &ref;
    if (!jw_jwc_read(&mine, b, n)) {
        printf("BAD  %s did not read\n", jwc);
        fails++;
        free(b);
        return;
    }
    free(b);

    /* the original's own six memo texts sit at the end, at 0,-1000 */
    i = ref.ndrawn;
    while (i > 0 && ref.obj[i - 1].cls == JW_MOJI
           && ref.obj[i - 1].d[1] == -1000.0)
        i--;
    if (i != mine.ndrawn) {
        printf("BAD  %s: %d elements, the original made %d\n",
               what, mine.ndrawn, i);
        fails++;
        return;
    }
    for (i = 0; i < mine.ndrawn; i++)
        if (!same(&mine.obj[i], &ref.obj[i])) {
            bad = i;
            break;
        }
    ck(bad < 0, what);
    if (bad >= 0) {
        printf("     element %d:\n", bad);
        show(&mine, "port    ", &mine.obj[bad]);
        show(&ref, "original", &ref.obj[bad]);
    }
    jw_free(&mine);
    jw_free(&ref);
}

int main(void)
{
    alike("orig/Test5.jww", "decomp/res/geom.jwc", "decomp/res/jwcin.jww",
          "lines, arcs, a circle, points and solid outlines, read back");
    alike("orig/Test5.jww", "decomp/res/t5.jwc", "decomp/res/jwct5.jww",
          "Test5's own lines and texts, read back");
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
