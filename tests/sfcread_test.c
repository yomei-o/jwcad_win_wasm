/* SFC 読み込み -- against the drawing the original made of the same file.
 *
 *   tests/sfcread_test.exe
 *
 * tools/refanswers.sh has the original open an SFC and save the result as
 * .jww.  This opens the same base drawing, reads the same SFC into it, and
 * the elements have to come out the same -- the 図形 it makes, the reference
 * to it, and every element inside it.
 *
 * One number cannot match: a definition keeps the moment it was made, and
 * the original's is whenever the answer was recorded.
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
    case JW_SOLID: return 8;
    case JW_BLOCK: return 5;
    }
    return 0;
}

static int same(const jw_drawing *a, const jw_obj *x,
                const jw_drawing *b, const jw_obj *y)
{
    int i;

    if (x->cls != y->cls || x->ltype != y->ltype || x->color != y->color
        || x->width != y->width || x->layer != y->layer
        || x->lgroup != y->lgroup || x->n != y->n || x->block != y->block)
        return 0;
    for (i = 0; i < ndbl(x->cls); i++) {
        double p = x->d[i], q = y->d[i];

        if (fabs(p - q) > 1e-9 * (fabs(p) + fabs(q)) + 1e-9)
            return 0;
    }
    if (x->cls == JW_TEN && x->ltype == 100
        && (x->mark != y->mark || x->turn != y->turn || x->size != y->size))
        return 0;
    if (x->cls == JW_LIST) {
        /* list[2] is when it was made, which cannot be the same */
        if (x->list[0] != y->list[0] || x->list[1] != y->list[1])
            return 0;
        if (strcmp(jw_str(a, x->text), jw_str(b, y->text)))
            return 0;
    }
    return 1;
}

static void show(const jw_drawing *d, const char *who, const jw_obj *o)
{
    int i;

    printf("     %s cls %d ltype %d colour %d width %d layer %d/%d n %d",
           who, o->cls, o->ltype, o->color, o->width, o->lgroup, o->layer,
           o->n);
    for (i = 0; i < ndbl(o->cls); i++)
        printf(" %.12g", o->d[i]);
    if (o->cls == JW_LIST)
        printf(" %d,%d %s", o->list[0], o->list[1], jw_str(d, o->text));
    printf("\n");
}

/* Read `sfc` into a copy of `base` and hold the result against `answer`. */
static void alike(const char *base, const char *sfc, const char *answer,
                  const char *what)
{
    jw_drawing mine, ref;
    unsigned char *b;
    long n;
    int i, j, bad = -1;

    memset(&mine, 0, sizeof mine);
    memset(&ref, 0, sizeof ref);
    if (!open_jww(&mine, base) || !open_jww(&ref, answer))
        return;
    b = slurp(sfc, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", sfc);
        fails++;
        return;
    }
    if (!jw_sfc_read(&mine, b, n)) {
        printf("BAD  %s did not read\n", sfc);
        fails++;
        free(b);
        return;
    }
    free(b);

    /* The original leaves its own memo texts in what it saves, so the two
       are lined up by leaving those out. */
    for (i = 0, j = 0; i < mine.nobj; i++, j++) {
        while (j < ref.nobj && ref.obj[j].cls == JW_MOJI)
            j++;
        if (j >= ref.nobj) {
            printf("BAD  %s: the port made %d elements, the original fewer\n",
                   what, mine.nobj);
            fails++;
            return;
        }
        if (!same(&mine, &mine.obj[i], &ref, &ref.obj[j])) {
            bad = i;
            break;
        }
    }
    ck(bad < 0, what);
    if (bad >= 0) {
        printf("     element %d:\n", bad);
        show(&mine, "port    ", &mine.obj[bad]);
        show(&ref, "original", &ref.obj[j]);
    }
    {
        double s = mine.group[0].scale, t = ref.group[0].scale;

        ck(s == t && mine.paper_hw == ref.paper_hw
           && mine.paper_hh == ref.paper_hh, "the sheet and the scale");
    }
    jw_free(&mine);
    jw_free(&ref);
}

int main(void)
{
    alike("orig/Test5.jww", "decomp/res/pens.sfc", "decomp/res/sfcin.jww",
          "the pen and line type sample, read back");
    /* tools/mksfc.py's arcs both ways round, circles and points */
    alike("orig/Test5.jww", "decomp/res/geo.sfc", "decomp/res/sfcgeo.jww",
          "arcs, circles and points, read back");
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
