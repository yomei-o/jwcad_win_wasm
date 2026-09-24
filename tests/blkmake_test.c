/* ブロック化 -- against the original.
 *
 *   tests/blkmake_test.exe tests/out/blkname.png
 *
 * docs/ref_blkname.png is the dialog painted into a bitmap by Jw_cad itself
 * (tools/jwdraw.ps1's dlg: step, which never touches the screen).  This puts
 * the port's up in the same state and writes it out to be scored against
 * that picture; tools/check.sh does the scoring.
 *
 * And what the command does.  The original was given tools/mkgeom.c's
 * drawing (four lines, four arcs, two points, two solids), a range over all
 * of it and the name BLK; decomp/res/blkmake.jww is what it saved
 * (tools/refanswers.sh's === blkmake).  The definition it made, where it put
 * the reference, and what is inside it all have to come out the same.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/blkname.h"
#include "../src/gen/cmds.h"
#include "png.h"

#define PI 3.14159265358979323846

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

/* the middle of one of the dialog's controls, in client pixels */
static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_blkname_rect(1264, 741, &r);
    for (i = 0; i < JW_NBLKNAME; i++)
        if (jw_blkname[i].id == id) {
            *x = r.x + JW_BN_BORDER + jw_blkname[i].x + jw_blkname[i].w / 2;
            *y = r.y + JW_BN_CAPTION + jw_blkname[i].y + jw_blkname[i].h / 2;
            return;
        }
    *x = *y = -1;
}

/* the same drawing tools/mkgeom.c makes */
static void geom(jw_drawing *d)
{
    static const double A[4][2] = {
        { 0.0, 1.5707963267948966 },
        { 3.141592653589793, -1.5707963267948966 },
        { 4.71238898038469, 2.0943951023931953 },
        { 0.0, 6.283185307179586 },
    };
    jw_obj *o;
    int i;

    while (d->ndrawn > 0)
        jw_remove(d, d->ndrawn - 1);
#define LAY() do { o->layer = 0; o->lgroup = 0; o->width = 0; } while (0)
    for (i = 0; i < 4; i++) {
        o = jw_add(d, JW_SEN);
        if (!o)
            return;
        o->color = (unsigned short)(i + 1);
        o->ltype = (unsigned char)(i + 1);
        o->d[0] = -90.0;
        o->d[1] = 60.0 - i * 10.0;
        o->d[2] = 90.0;
        o->d[3] = 60.0 - i * 10.0;
        LAY();
    }
    for (i = 0; i < 4; i++) {
        o = jw_add(d, JW_ENKO);
        if (!o)
            return;
        o->color = (unsigned short)(i + 2);
        o->ltype = 1;
        o->d[0] = -60.0 + i * 40.0;
        o->d[1] = -30.0;
        o->d[2] = 15.0;
        o->d[3] = A[i][0];
        o->d[4] = A[i][1];
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        LAY();
    }
    for (i = 0; i < 2; i++) {
        o = jw_add(d, JW_TEN);
        if (!o)
            return;
        o->color = (unsigned short)(i + 3);
        o->ltype = 1;
        o->d[0] = -20.0 + i * 40.0;
        o->d[1] = -70.0;
        LAY();
    }
    o = jw_add(d, JW_SOLID);
    if (o) {
        o->color = 4;
        o->ltype = 1;
        o->d[0] = -80.0; o->d[1] = -80.0;
        o->d[2] = -50.0; o->d[3] = -80.0;
        o->d[4] = -65.0; o->d[5] = -55.0;
        o->d[6] = -65.0; o->d[7] = -55.0;
        LAY();
    }
    o = jw_add(d, JW_SOLID);
    if (o) {
        o->color = 5;
        o->ltype = 1;
        o->d[0] = 50.0; o->d[1] = -80.0;
        o->d[2] = 85.0; o->d[3] = -80.0;
        o->d[4] = 85.0; o->d[5] = -55.0;
        o->d[6] = 55.0; o->d[7] = -50.0;
        LAY();
    }
#undef LAY
}

static int near_(double a, double b)
{
    double e = a - b;

    return e < 1e-9 && e > -1e-9;
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    const jw_drawing *d;
    jw_drawing ref;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j, ra = -1, ma = -1, bad = 0;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    geom((jw_drawing *)app_drawing());

    ck(!app_blkname_open(), "the dialog is not up to start with");
    ck(!app_command(JW_CMD_BLOCK),
       "and the command does nothing with nothing picked");
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
    ck(jw_cmd_sel_count(app_drawing()) == 12, "a range over all twelve");
    ck(app_command(JW_CMD_BLOCK), "the command puts the dialog up");
    ck(app_blkname_open(), "which says so");

    /* the picture, in the state the original's was in */
    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_blkname_rect(fb->w, fb->h, &r);
        px = (unsigned int *)malloc((size_t)r.w * r.h * sizeof *px);
        if (px) {
            for (j = 0; j < r.h; j++)
                for (i = 0; i < r.w; i++)
                    px[j * r.w + i] = fb->px[(size_t)(r.y + j) * fb->w
                                             + r.x + i];
            png_rgb(argv[1], r.w, r.h, px);
            free(px);
            printf("     wrote %s, %dx%d\n", argv[1], r.w, r.h);
        }
    }

    app_key('B');
    app_key('L');
    app_key('K');
    ck(!strcmp(app_blkname(), "BLK"), "the box takes what is typed");
    ctl(1, &x, &y);                     /* OK */
    app_press(x, y, 0);
    ck(!app_blkname_open(), "and Ok takes the dialog down");

    /* and what it made, against the original's */
    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/blkmake.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/blkmake.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
        return fails ? 1 : 0;
    }
    free(b);
    d = app_drawing();
    for (i = 0; i < ref.nobj; i++) {
        if (ref.obj[i].cls == JW_BLOCK && ra < 0)
            ra = i;
        if (ref.obj[i].cls == JW_LIST && ma < 0)
            ma = i;
    }
    ck(ra >= 0 && ma >= 0, "the original's file has a reference and a list");
    ck(d->ndrawn == 1 && d->obj[0].cls == JW_BLOCK,
       "the port is left with one reference and nothing else");
    if (ra >= 0 && d->ndrawn >= 1 && d->obj[0].cls == JW_BLOCK) {
        const jw_obj *a = &d->obj[0], *o = &ref.obj[ra];

        if (!near_(a->d[0], o->d[0]) || !near_(a->d[1], o->d[1]))
            printf("     ours at %.9f,%.9f, the original's at %.9f,%.9f\n",
                   a->d[0], a->d[1], o->d[0], o->d[1]);
        ck(near_(a->d[0], o->d[0]) && near_(a->d[1], o->d[1]),
           "and it sits where the original put its own");
        ck(near_(a->d[2], 1.0) && near_(a->d[3], 1.0) && near_(a->d[4], 0.0),
           "at the same scale and turn");
        ck((a->layer & 15) == (o->layer & 15) && a->color == o->color,
           "on the write layer and in the write colour, as the original's is");
    }
    /* the definition: its name, its count, and every element inside it */
    if (ma >= 0 && d->nobj > d->ndrawn) {
        const jw_obj *a = &d->obj[d->ndrawn], *o = &ref.obj[ma];

        ck(a->cls == JW_LIST, "the port made a definition");
        ck(!strcmp(jw_str(d, a->text), jw_str(&ref, o->text)),
           "with the name the original gave its own");
        if (strcmp(jw_str(d, a->text), jw_str(&ref, o->text)))
            printf("     ours '%s', theirs '%s'\n", jw_str(d, a->text),
                   jw_str(&ref, o->text));
        ck(a->n == o->n && a->list[0] == o->list[0]
           && a->list[1] == o->list[1], "and the same count and numbers");
        for (i = 0; i < o->n && i < a->n; i++) {
            const jw_obj *p = &d->obj[d->ndrawn + 1 + i];
            const jw_obj *q = &ref.obj[ma + 1 + i];
            int k;

            if (p->cls != q->cls || p->color != q->color
                || p->ltype != q->ltype || (p->layer & 15) != (q->layer & 15))
                bad = 1;
            for (k = 0; k < 8; k++) {
                double pv = p->d[k], qv = q->d[k];

                /* An arc's start angle is not compared as it stands: the
                   original brings it into -pi..pi when it reads the file,
                   so the 3/2 pi this drawing was written with comes back as
                   -pi/2.  That is the reader's doing and not ブロック化's --
                   the port leaves the angle as it found it. */
                if (p->cls == JW_ENKO && k == 3) {
                    while (pv > PI) pv -= 2.0 * PI;
                    while (pv <= -PI) pv += 2.0 * PI;
                    while (qv > PI) qv -= 2.0 * PI;
                    while (qv <= -PI) qv += 2.0 * PI;
                }
                if (!near_(pv, qv)) {
                    printf("     the %dth inside is %.9f where the "
                           "original's is %.9f (field %d)\n", i, p->d[k],
                           q->d[k], k);
                    bad = 1;
                }
            }
        }
        ck(!bad, "and every element inside it is the original's");
    }
    /* and 元に戻る puts the twelve back and takes the definition away */
    jw_cmd_undo((jw_drawing *)app_drawing());
    d = app_drawing();
    ck(d->ndrawn == 12 && d->nobj == 12,
       "元に戻る brings the twelve back and drops the definition");
    jw_free(&ref);

    /* 元データのレイヤを優先する: the only thing it changes is one bit of
       the reference's own +0x28 -- the same drawing blocked with it ticked
       came back from the original with 65 there where the plain one has 1 */
    jw_cmd_set(JW_CMD_HANI);
    ui_view_rect(fb->w, fb->h, &r);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
    app_command(JW_CMD_BLOCK);
    ctl(1323, &x, &y);
    app_press(x, y, 0);
    app_key('B');
    ctl(1, &x, &y);
    app_press(x, y, 0);
    d = app_drawing();
    ck(d->ndrawn == 1 && d->obj[0].cls == JW_BLOCK && d->obj[0].ltype == 65,
       "元データのレイヤを優先する puts 65 in the reference's line type");
    jw_cmd_undo((jw_drawing *)app_drawing());

    /* ブロック解除: the original's own file, a range over it, and the
       command -- and what is left has to be its own decomp/res/blkfree.jww */
    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/blkfree.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/blkfree.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
    } else {
        free(b);
        b = slurp("decomp/res/blkmake.jww", &n);
        if (b && app_open(b, n)) {
            int nr = 0, nm = 0;

            free(b);
            ui_view_rect(fb->w, fb->h, &r);
            jw_cmd_set(JW_CMD_HANI);
            app_press(r.x + 4, r.y + 4, 0);
            app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
            ck(app_command(JW_CMD_BLOCK_FREE),
               "ブロック解除 takes the one reference apart");
            d = app_drawing();
            for (i = 0; i < ref.ndrawn; i++)
                if (jw_text_drawn(&ref.obj[i]))
                    nr++;
            for (i = 0; i < d->ndrawn; i++)
                if (jw_text_drawn(&d->obj[i]))
                    nm++;
            ck(nm == nr, "leaving as many elements as the original was left");
            ck(d->nobj == d->ndrawn, "and no definition behind");
            bad = 0;
            for (i = 0, j = 0; i < ref.ndrawn; i++) {
                const jw_obj *q = &ref.obj[i], *p;
                int k;

                if (!jw_text_drawn(q))
                    continue;
                while (j < d->ndrawn && !jw_text_drawn(&d->obj[j]))
                    j++;
                if (j >= d->ndrawn)
                    break;
                p = &d->obj[j++];
                if (p->cls != q->cls || p->color != q->color
                    || (p->layer & 15) != (q->layer & 15))
                    bad = 1;
                for (k = 0; k < 8; k++) {
                    double pv = p->d[k], qv = q->d[k];

                    if (p->cls == JW_ENKO && k == 3) {
                        while (pv > PI) pv -= 2.0 * PI;
                        while (pv <= -PI) pv += 2.0 * PI;
                        while (qv > PI) qv -= 2.0 * PI;
                        while (qv <= -PI) qv += 2.0 * PI;
                    }
                    if (!near_(pv, qv)) {
                        printf("     the %dth back is %.12f where the "
                               "original's is %.12f (field %d)\n", i, p->d[k],
                               q->d[k], k);
                        bad = 1;
                    }
                }
            }
            ck(!bad, "and every one of them is the original's, on its layer");
            jw_cmd_undo((jw_drawing *)app_drawing());
            d = app_drawing();
            ck(d->nobj > d->ndrawn,
               "元に戻る puts the block and its definition back");
        }
        jw_free(&ref);
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
