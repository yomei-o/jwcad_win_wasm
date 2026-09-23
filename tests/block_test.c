/* 図形: a reference has to draw as the definition put where it says.
 *
 *   tests/block_test.exe
 *
 * Nothing about this needs the original: it holds the port against itself.
 * One drawing has a definition and three references to it -- as it is, twice
 * as big, and turned -- and the other has the same lines already worked out.
 * Rendered, the two have to come out the same pixels.  That is the one thing
 * src/draw.c's block() does, and a drawing read from a DXF or an SFC is
 * nothing but that.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/fb.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/draw.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* the square a definition holds: four lines about its own origin */
static const double SQ[4][4] = {
    {   0.0,  0.0, 20.0,  0.0 },
    {  20.0,  0.0, 20.0, 20.0 },
    {  20.0, 20.0,  0.0, 20.0 },
    {   0.0, 20.0,  0.0,  0.0 },
};

/* where the three references put it: x, y, how big, how far round */
static const double REF[3][4] = {
    { -80.0, -40.0, 1.0, 0.0 },
    {   0.0, -40.0, 2.0, 0.0 },
    {  60.0, -40.0, 1.0, 30.0 },
};

static jw_obj *add(jw_drawing *d, int cls)
{
    jw_obj *o = jw_add(d, cls);

    if (o) {
        /* the layer jw_add chose is the one being written to, which is the
           one that is shown -- forcing layer 0 would hide everything */
        o->color = 2;
        o->ltype = 1;
        o->width = 0;
    }
    return o;
}

/* the same thing twice: once as a reference to a definition, once as the
   lines it comes to */
static void build(jw_drawing *d, int asblock)
{
    int i, k;

    while (d->nobj > 0)
        jw_remove(d, d->nobj - 1);
    if (!asblock) {
        for (k = 0; k < 3; k++) {
            double c = cos(REF[k][3] * 3.14159265358979323846 / 180.0);
            double s = sin(REF[k][3] * 3.14159265358979323846 / 180.0);

            for (i = 0; i < 4; i++) {
                jw_obj *o = add(d, JW_SEN);
                double x0 = SQ[i][0] * REF[k][2], y0 = SQ[i][1] * REF[k][2];
                double x1 = SQ[i][2] * REF[k][2], y1 = SQ[i][3] * REF[k][2];

                if (!o)
                    return;
                o->d[0] = x0 * c - y0 * s + REF[k][0];
                o->d[1] = x0 * s + y0 * c + REF[k][1];
                o->d[2] = x1 * c - y1 * s + REF[k][0];
                o->d[3] = x1 * s + y1 * c + REF[k][1];
            }
        }
        return;
    }
    for (k = 0; k < 3; k++) {
        jw_obj *o = add(d, JW_BLOCK);

        if (!o)
            return;
        o->d[0] = REF[k][0];
        o->d[1] = REF[k][1];
        o->d[2] = REF[k][2];
        o->d[3] = REF[k][2];
        o->d[4] = REF[k][3] * 3.14159265358979323846 / 180.0;
        o->block = 0;
    }
    {   /* the definition, after what is drawn */
        int at;
        jw_obj *o = add(d, JW_LIST);

        if (!o)
            return;
        at = (int)(o - d->obj);
        d->obj[at].list[0] = 0;
        d->obj[at].n = 4;
        for (i = 0; i < 4; i++) {
            jw_obj *m = add(d, JW_SEN);

            if (!m)
                return;
            m->d[0] = SQ[i][0];
            m->d[1] = SQ[i][1];
            m->d[2] = SQ[i][2];
            m->d[3] = SQ[i][3];
        }
        /* only the three references are drawn; the rest is the definition */
        d->ndrawn = 3;
    }
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

int main(void)
{
    jw_drawing d;
    unsigned char *b;
    long n;
    fb_t fb;
    jw_view v;
    rect_t r;
    unsigned int *one = 0;
    int i, ink = 0, differ = 0;

    b = slurp("orig/Test5.jww", &n);
    if (!b || !jw_parse(&d, b, n)) {
        printf("BAD  cannot read orig/Test5.jww\n");
        return 1;
    }
    free(b);

    memset(&fb, 0, sizeof fb);
    if (!fb_init(&fb, 600, 400)) {
        printf("BAD  out of memory\n");
        return 1;
    }
    r.x = 0;
    r.y = 0;
    r.w = 600;
    r.h = 400;
    memset(&v, 0, sizeof v);
    jw_view_fit(&v, &r, d.paper_hw, d.paper_hh);
    v.clip = r;

    {   /* first the drawing as it came, to be sure the view is set up */
        int k, any = 0;

        for (k = 0; k < 600 * 400; k++)
            fb.px[k] = 0xffffff;
        jw_draw(&fb, &v, &d);
        for (k = 0; k < 600 * 400; k++)
            if (fb.px[k] != 0xffffff)
                any++;
        ck(any > 0, "the drawing it starts from is on the screen");
    }
    for (i = 0; i < 2; i++) {
        int k;

        build(&d, i == 0);
        for (k = 0; k < 600 * 400; k++)
            fb.px[k] = 0xffffff;
        jw_draw(&fb, &v, &d);
        if (i == 0) {
            one = (unsigned int *)malloc(600 * 400 * sizeof *one);
            if (!one) {
                printf("BAD  out of memory\n");
                return 1;
            }
            memcpy(one, fb.px, 600 * 400 * sizeof *one);
        } else {
            for (k = 0; k < 600 * 400; k++) {
                if (one[k] != 0xffffff)
                    ink++;
                if (one[k] != fb.px[k])
                    differ++;
            }
        }
    }
    printf("     %d pixels of ink, %d differ\n", ink, differ);
    ck(ink > 200, "the references put something on the screen");
    ck(differ == 0, "and it is where the lines themselves would be");
    free(one);
    jw_free(&d);
    printf(fails ? "%d BAD\n" : "all ok\n", fails);
    return fails ? 1 : 0;
}
