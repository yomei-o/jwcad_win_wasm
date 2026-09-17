/* 寸法 -- against the dimension the original itself drew.
 *
 *   tests/sunpo_test.exe [decomp/res/sunpo.jww]
 *
 * That file is Test5 with one line drawn on it and one dimension put on the
 * line's two ends, made by driving Jw_cad (RESUME.md says how).  The test
 * replays the same four clicks here and holds every number the port makes
 * up against the original's.
 *
 * The clicks are taken out of the original's own answer, so nothing is
 * assumed about the window it was drawn in: the first click's height is
 * where its extension lines end, the second's is where its dimension line
 * sits, and the two measured points are the ends of the drawn line.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
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

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "decomp/res/sunpo.jww";
    unsigned char *b;
    long n;
    jw_drawing ref;
    jw_drawing *d;
    const jw_obj *r_line = 0, *r_dim = 0, *r_ext = 0, *r_ext2 = 0, *r_txt = 0;
    const jw_obj *r_ten[2];
    int i, nten = 0, before;
    double ax, ay, bx, by, hy, ly;

    r_ten[0] = r_ten[1] = 0;
    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        return 1;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        return 1;
    }
    free(b);
    /* the six parts the original made, and the line they were put on */
    for (i = 0; i < ref.ndrawn; i++) {
        const jw_obj *o = &ref.obj[i];
        if (o->cls == JW_SEN && o->flags == 0 && o->color == 2)
            r_line = o;                         /* the line that was drawn */
        if (o->cls == JW_SEN && (o->flags & 0x2000)) {
            if (o->d[1] == o->d[3])
                r_dim = o;                      /* level: the dimension    */
            else if (!r_ext)
                r_ext = o;                      /* upright: an extension   */
            else if (!r_ext2)
                r_ext2 = o;
        }
        if (o->cls == JW_TEN && (o->flags & 0x40) && nten < 2)
            r_ten[nten++] = o;
        if (o->cls == JW_MOJI && (o->flags & 0x4000))
            r_txt = o;
    }
    ck(r_line && r_dim && r_ext && r_ext2 && r_txt && nten == 2,
       "the original's dimension is in the file");
    if (!r_line || !r_dim || !r_ext || !r_ext2 || !r_txt || nten != 2)
        return 1;
    ax = r_line->d[0];
    ay = r_line->d[1];
    bx = r_line->d[2];
    by = r_line->d[3];
    hy = r_ext->d[3];                   /* 引出し線の始点 */
    ly = r_dim->d[1];                   /* 寸法線の位置   */

    /* the same drawing, with the same line on it */
    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = ax;
        o->d[1] = ay;
        o->d[2] = bx;
        o->d[3] = by;
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_SUNPO);
    ck(jw_cmd() == JW_CMD_SUNPO, "寸法 is the command");
    jw_cmd_point(d, app_view(), 0.0, hy, 0);        /* 引出し線の始点 */
    jw_cmd_point(d, app_view(), 0.0, ly, 0);        /* 寸法線の位置   */
    ck(d->ndrawn == before, "the first two clicks draw nothing");
    jw_cmd_point(d, app_view(), ax + 1e6, ay, 0);   /* nothing to read here */
    ck(d->ndrawn == before, "a click with no point to read is ignored");
    jw_cmd_point(d, app_view(), ax, ay, 0);         /* 寸法の始点 */
    ck(d->ndrawn == before, "and the start on its own draws nothing");
    jw_cmd_point(d, app_view(), bx, by, 0);         /* 寸法の終点 */
    ck(d->ndrawn == before + 6, "the end makes the six elements");
    if (d->ndrawn != before + 6)
        return 1;

    {
        const jw_obj *dim = &d->obj[before];
        const jw_obj *t0 = &d->obj[before + 1], *t1 = &d->obj[before + 2];
        const jw_obj *e0 = &d->obj[before + 3], *e1 = &d->obj[before + 4];
        const jw_obj *tx = &d->obj[before + 5];

        ck(dim->cls == JW_SEN && near(dim->d[0], r_dim->d[0])
           && near(dim->d[1], r_dim->d[1]) && near(dim->d[2], r_dim->d[2])
           && near(dim->d[3], r_dim->d[3]),
           "the dimension line is where it was");
        ck(dim->color == r_dim->color && dim->ltype == r_dim->ltype
           && dim->flags == r_dim->flags, "with its colour and its flags");
        ck(t0->cls == JW_TEN && near(t0->d[0], r_ten[0]->d[0])
           && near(t0->d[1], r_ten[0]->d[1])
           && t1->cls == JW_TEN && near(t1->d[0], r_ten[1]->d[0])
           && near(t1->d[1], r_ten[1]->d[1]), "a point at each of its ends");
        ck(t0->color == r_ten[0]->color && t0->flags == r_ten[0]->flags,
           "in the colour the settings give, with the same flags");
        ck(near(e0->d[0], r_ext->d[0]) && near(e0->d[1], r_ext->d[1])
           && near(e0->d[2], r_ext->d[2]) && near(e0->d[3], r_ext->d[3]),
           "the first extension line runs where the original's does");
        ck(near(e1->d[0], r_ext2->d[0]) && near(e1->d[1], r_ext2->d[1])
           && near(e1->d[2], r_ext2->d[2]) && near(e1->d[3], r_ext2->d[3]),
           "and so does the second");
        ck(e0->color == r_ext->color && e0->flags == r_ext->flags,
           "both with the extension colour and flags");
        ck(tx->cls == JW_MOJI
           && !strcmp(jw_str(d, tx->text), jw_str(&ref, r_txt->text)),
           "the value reads the same");
        printf("     port [%s]  original [%s]\n", jw_str(d, tx->text),
               jw_str(&ref, r_txt->text));
        ck(near(tx->d[0], r_txt->d[0]) && near(tx->d[1], r_txt->d[1])
           && near(tx->d[2], r_txt->d[2]) && near(tx->d[3], r_txt->d[3]),
           "and sits exactly where the original put it");
        ck(tx->d[4] == r_txt->d[4] && tx->d[5] == r_txt->d[5]
           && tx->color == r_txt->color && tx->n == r_txt->n,
           "at the same size, colour and text style");
        ck(tx->ltype == r_txt->ltype && tx->width == r_txt->width
           && tx->flags == r_txt->flags, "and carrying the same three words");
    }

    /* 元に戻る takes the whole dimension back */
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "元に戻る takes all six back at once");

    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
