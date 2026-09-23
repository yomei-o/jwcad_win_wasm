/* DXF 読み込み -- against the drawing the original made of the same DXF.
 *
 *   tests/dxfread_test.exe
 *
 * tools/refanswers.sh has the original open a DXF and save the result as
 * .jww.  This opens the same base drawing, reads the same DXF into it, and
 * the elements have to come out the same: the same count, the same class,
 * the same line type, colour, layer and layer group, and the same numbers.
 *
 * The file is then written out and read again, and the parts of the header
 * the import changes -- the scale, the layer names and the colour table --
 * are held against the original's too.  The bytes themselves cannot be
 * compared: the original writes version 700 whatever it read, and the
 * drawings here are version 600, so everything in it moves from CP932 to
 * UTF-16 on the way out.
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

/* How many numbers each class keeps, so the wrong ones are not compared. */
static int ndbl(int cls)
{
    switch (cls) {
    case JW_SEN:   return 4;
    case JW_ENKO:  return 7;
    case JW_TEN:   return 2;
    case JW_SOLID: return 8;
    }
    return 0;
}

static int same(const jw_obj *a, const jw_obj *b)
{
    int i;

    if (a->cls != b->cls || a->ltype != b->ltype || a->color != b->color
        || a->layer != b->layer || a->lgroup != b->lgroup || a->n != b->n)
        return 0;
    for (i = 0; i < ndbl(a->cls); i++) {
        double x = a->d[i], y = b->d[i];

        if (fabs(x - y) > 1e-9 * (fabs(x) + fabs(y)) + 1e-9)
            return 0;
    }
    return 1;
}

static void show(const char *who, const jw_obj *o)
{
    int i;

    printf("     %s cls %d ltype %d colour %d layer %d/%d n %d",
           who, o->cls, o->ltype, o->color, o->lgroup, o->layer, o->n);
    for (i = 0; i < ndbl(o->cls); i++)
        printf(" %.12g", o->d[i]);
    printf("\n");
}

/* Read `dxf` into a copy of `base` and hold the result against `answer`. */
static void alike(const char *base, const char *dxf, const char *answer,
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
    b = slurp(dxf, &n);
    if (!b) {
        printf("BAD  cannot read %s\n", dxf);
        fails++;
        return;
    }
    if (!jw_dxf_read(&mine, b, n)) {
        printf("BAD  %s did not read\n", dxf);
        fails++;
        free(b);
        return;
    }
    free(b);

    /* The original leaves its own memo texts in the drawing; those come
       from the document rather than the DXF, so only what the DXF put
       there is compared -- everything up to the first text. */
    for (i = 0; i < ref.ndrawn && ref.obj[i].cls != JW_MOJI; i++)
        ;
    if (i != mine.ndrawn) {
        printf("BAD  %s: %d elements, the original made %d\n",
               what, mine.ndrawn, i);
        fails++;
    } else {
        for (i = 0; i < mine.ndrawn; i++)
            if (!same(&mine.obj[i], &ref.obj[i])) {
                bad = i;
                break;
            }
        ck(bad < 0, what);
        if (bad >= 0) {
            printf("     element %d:\n", bad);
            show("port    ", &mine.obj[bad]);
            show("original", &ref.obj[bad]);
        }
    }
    {
        double s = mine.group[0].scale, t = ref.group[0].scale;

        ck(s == t, "the scale the extents settle");
        if (s != t)
            printf("     port %g, original %g\n", s, t);
    }

    /* Out and back in again: what the import changed in the header has to
       survive being written. */
    {
        jw_drawing back;
        unsigned char *w;
        long m;
        int g, l, ok = 1;

        memset(&back, 0, sizeof back);
        if (!jw_write(&mine, &w, &m) || !jw_parse(&back, w, m)) {
            printf("BAD  %s: cannot write it back\n", what);
            fails++;
        } else {
            for (g = 0; g < 16 && ok; g++) {
                if (back.group[g].scale != ref.group[g].scale)
                    ok = 0;
                for (l = 0; l < 16 && ok; l++) {
                    const char *a = jw_str(&back, back.group[g].layer_name[l]);
                    const char *b = jw_str(&ref, ref.group[g].layer_name[l]);

                    if (strcmp(a ? a : "", b ? b : "")) {
                        printf("     layer %d-%d: port %s, original %s\n",
                               g, l, a ? a : "", b ? b : "");
                        ok = 0;
                    }
                }
            }
            for (i = 0; i <= 256 && ok; i++)
                if (back.xcolor[i] != ref.xcolor[i]) {
                    printf("     colour %d: port %06x, original %06x\n",
                           100 + i, back.xcolor[i], ref.xcolor[i]);
                    ok = 0;
                }
            ck(ok, "the scale, layers and colours, written and read again");
            jw_free(&back);
        }
        free(w);
    }
    jw_free(&mine);
    jw_free(&ref);
}

int main(void)
{
    alike("orig/Test5.jww", "decomp/res/pens.dxf", "decomp/res/dxfin.jww",
          "the pen and line type sample, read back");
    alike("orig/Test5.jww", "decomp/res/geom.dxf", "decomp/res/geomin.jww",
          "lines, arcs, a circle, points and solids, read back");
    /* the same drawing with its extents halved: the scale the original
       settles on is 1/100 rather than 1/200, and everything is placed
       around the middle of those extents instead */
    alike("orig/Test5.jww", "decomp/res/geomext.dxf",
          "decomp/res/geomextin.jww", "the same with half the extents");
    /* 255 lines, one per colour number: this is the file src/gen/aci.h was
       made from, so it holds the whole colour table to account -- which
       lines share a colour, which make a new one, and what each one is.
       Its entities also name a layer the LAYER table never declared, which
       is the other way a layer comes about. */
    alike("orig/Test5.jww", "decomp/res/aci1.dxf", "decomp/res/aci1.jww",
          "a line of every colour number, 1 to 128");
    alike("orig/Test5.jww", "decomp/res/aci2.dxf", "decomp/res/aci2.jww",
          "and 129 to 255");
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
