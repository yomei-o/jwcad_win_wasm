/* データ整理 -- 重複整理 and 連結整理, against the original.
 *
 *   tests/seiri_test.exe
 *
 * tools/mkseiri.c makes a drawing of ten pairs, each pair a different kind
 * of "the same": lines on top of each other, lines that overlap along part
 * of their length, lines that meet end to end, a bent pair, three pairs that
 * differ only in colour, line type or layer, and pairs of arcs, points and
 * texts.  The original was given it, a range over the whole of it, 選択確定
 * and then one button; decomp/res/seiridup.jww and seirijoin.jww are what it
 * was left with (tools/refanswers.sh's === seiri).
 *
 * This builds the same drawing, does the same, and the two have to come out
 * with the same elements -- every one of them, to 1e-9.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/cmds.h"

static int fails;

static int alike_d(double a, double b)
{
    double e = a - b;

    return e < 1e-9 && e > -1e-9;
}

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

static void line(jw_drawing *d, double x0, double y0, double x1, double y1,
                 int col, int lt, int layer)
{
    jw_obj *o = jw_add(d, JW_SEN);

    if (!o)
        return;
    o->color = (unsigned short)col;
    o->ltype = (unsigned char)lt;
    o->layer = (unsigned short)layer;
    o->lgroup = 0;
    o->width = 0;
    o->d[0] = x0;
    o->d[1] = y0;
    o->d[2] = x1;
    o->d[3] = y1;
}

/* the same drawing tools/mkseiri.c makes */
static void pairs(jw_drawing *d, int face)
{
    jw_obj *o;
    int i;

    while (d->ndrawn > 0)
        jw_remove(d, d->ndrawn - 1);
    line(d, -80.0, 70.0, -30.0, 70.0, 1, 1, 0);
    line(d, -80.0, 70.0, -30.0, 70.0, 1, 1, 0);
    line(d, -80.0, 60.0, -30.0, 60.0, 1, 1, 0);
    line(d, -55.0, 60.0,  -5.0, 60.0, 1, 1, 0);
    line(d, -80.0, 50.0, -55.0, 50.0, 1, 1, 0);
    line(d, -55.0, 50.0, -30.0, 50.0, 1, 1, 0);
    line(d, -80.0, 40.0, -55.0, 40.0, 1, 1, 0);
    line(d, -55.0, 40.0, -30.0, 45.0, 1, 1, 0);
    line(d, -80.0, 30.0, -30.0, 30.0, 1, 1, 0);
    line(d, -80.0, 30.0, -30.0, 30.0, 2, 1, 0);
    line(d, -80.0, 20.0, -30.0, 20.0, 1, 1, 0);
    line(d, -80.0, 20.0, -30.0, 20.0, 1, 2, 0);
    line(d, -80.0, 10.0, -30.0, 10.0, 1, 1, 0);
    line(d, -80.0, 10.0, -30.0, 10.0, 1, 1, 1);
    for (i = 0; i < 2; i++) {
        o = jw_add(d, JW_ENKO);
        if (!o)
            return;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->d[0] = 20.0;
        o->d[1] = 50.0;
        o->d[2] = 15.0;
        o->d[3] = 0.0;
        o->d[4] = 1.5707963267948966;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
    }
    for (i = 0; i < 2; i++) {
        o = jw_add(d, JW_TEN);
        if (!o)
            return;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->d[0] = 20.0;
        o->d[1] = 20.0;
    }
    for (i = 0; i < 2; i++) {
        o = jw_add(d, JW_MOJI);
        if (!o)
            return;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->n = 1;
        o->d[0] = 20.0;
        o->d[1] = 0.0;
        o->d[2] = 40.0;
        o->d[3] = 0.0;
        o->d[4] = 3.0;
        o->d[5] = 3.0;
        o->d[6] = 0.5;
        o->d[7] = 0.0;
        o->text = jw_add_str(d, "ABC");
        o->face = face;
    }
}

/* the same element, give or take a billionth */
static int alike(const jw_drawing *da, const jw_obj *a,
                 const jw_drawing *db, const jw_obj *b)
{
    int k;

    if (a->cls != b->cls || a->color != b->color || a->ltype != b->ltype
        || (a->layer & 15) != (b->layer & 15))
        return 0;
    for (k = 0; k < 8; k++) {
        /* The far end of a text's baseline is not compared: the original
           works it out again from the text's own length when it reads the
           file, so ABC at 3 wide with 0.5 between the letters comes back
           5 long however far apart the two points were written.  That is
           the reader's doing and not データ整理's -- the port leaves the
           two points alone. */
        if (a->cls == JW_MOJI && (k == 2 || k == 3))
            continue;
        {
            double e = a->d[k] - b->d[k];

            if (e > 1e-9 || e < -1e-9)
                return 0;
        }
    }
    if (a->cls == JW_MOJI)
        return !strcmp(jw_str(da, a->text), jw_str(db, b->text));
    return 1;
}

static void one(int join, const char *answer)
{
    const fb_t *fb = app_fb();
    jw_drawing ref;
    const jw_drawing *d;
    unsigned char *b;
    long n;
    rect_t r;
    int face = -1, i, j, nr = 0, bad = 0;

    printf("%s -> %s\n", join ? "連結整理" : "重複整理", answer);
    memset(&ref, 0, sizeof ref);
    b = slurp(answer, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", answer);
        fails++;
        free(b);
        return;
    }
    free(b);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot read orig/Test5.jww\n");
        fails++;
        free(b);
        jw_free(&ref);
        return;
    }
    free(b);
    d = app_drawing();
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].face >= 0) {
            face = d->obj[i].face;
            break;
        }
    pairs((jw_drawing *)d, face);

    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_SEIRI);
    app_press(r.x + 60, r.y + 60, 0);
    app_press(r.x + r.w - 6, r.y + r.h - 6, 1);     /* (R): texts as well */
    ck(jw_cmd_sel_count(app_drawing()) == 20, "  the range takes all twenty");
    app_move(r.x + 300, r.y + 300);     /* 基準点 is where the mouse is */
    ck(jw_cmd_bar((jw_drawing *)app_drawing(), 1120) == 1,
       "  選択確定 settles it");
    ck(jw_cmd_sel_stage() == 3, "  and the bar moves on a stage");
    ck(jw_cmd_bar((jw_drawing *)app_drawing(), join ? 1065 : 1064) == 1,
       "  the button does something");

    d = app_drawing();
    /* the original's own six memo texts are not part of the drawing */
    for (i = 0; i < ref.ndrawn; i++)
        if (jw_text_drawn(&ref.obj[i]))
            nr++;
    if (d->ndrawn != nr) {
        printf("     ours %d elements, the original's %d\n", d->ndrawn, nr);
        bad = 1;
    }
    for (i = 0, j = 0; i < ref.ndrawn && !bad; i++) {
        if (!jw_text_drawn(&ref.obj[i]))
            continue;
        if (j >= d->ndrawn || !alike(d, &d->obj[j], &ref, &ref.obj[i])) {
            printf("     the %dth is not the original's: ours "
                   "cls=%d %g,%g %g,%g, theirs cls=%d %g,%g %g,%g\n", j,
                   j < d->ndrawn ? d->obj[j].cls : -1,
                   j < d->ndrawn ? d->obj[j].d[0] : 0.0,
                   j < d->ndrawn ? d->obj[j].d[1] : 0.0,
                   j < d->ndrawn ? d->obj[j].d[2] : 0.0,
                   j < d->ndrawn ? d->obj[j].d[3] : 0.0,
                   ref.obj[i].cls, ref.obj[i].d[0], ref.obj[i].d[1],
                   ref.obj[i].d[2], ref.obj[i].d[3]);
            bad = 1;
        }
        j++;
    }
    ck(!bad, "  and every element is the original's, in its order");
    /* and 元に戻る puts the whole lot back */
    jw_cmd_undo((jw_drawing *)app_drawing());
    ck(app_drawing()->ndrawn == 20, "  元に戻る brings the twenty back");
    jw_free(&ref);
}

/* the drawing tools/mksort.c makes: six lines whose colours are in no
   order (or all one colour and out of order down the sheet), and six texts
   turned six ways */
static void sorted(jw_drawing *d, int face, int scramble, int twocol)
{
    static const int COL[6] = { 3, 1, 5, 2, 4, 6 };
    static const double ANG[6] = { 0.0, 45.0, 90.0, 135.0, 180.0, 270.0 };
    static const double Y[6] = { 60.0, 10.0, 40.0, 30.0, 50.0, 20.0 };
    jw_obj *o;
    int i;

    while (d->ndrawn > 0)
        jw_remove(d, d->ndrawn - 1);
    for (i = 0; i < 6; i++) {
        o = jw_add(d, JW_SEN);
        if (!o)
            return;
        o->color = (unsigned short)(twocol ? (i % 2) + 1
                                    : scramble ? 1 : COL[i]);
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->d[0] = -50.0;
        o->d[1] = scramble ? Y[i] : 60.0 - i * 10.0;
        o->d[2] = 50.0;
        o->d[3] = o->d[1];
    }
    for (i = 0; i < 6; i++) {
        double a = ANG[i] * 3.14159265358979323846 / 180.0;

        o = jw_add(d, JW_MOJI);
        if (!o)
            return;
        o->color = 1;
        o->ltype = 1;
        o->layer = 0;
        o->lgroup = 0;
        o->width = 0;
        o->n = 1;
        o->d[0] = -50.0 + i * 20.0;
        o->d[1] = -40.0;
        o->d[2] = o->d[0] + 6.0 * cos(a);
        o->d[3] = o->d[1] + 6.0 * sin(a);
        o->d[4] = 3.0;
        o->d[5] = 3.0;
        o->d[6] = 0.0;
        o->d[7] = ANG[i];
        o->text = jw_add_str(d, "ABCD");
        o->face = face;
    }
}

/* One of the four buttons that only put things in order. */
static void order(int id, int scramble, int twocol, const char *answer)
{
    const fb_t *fb = app_fb();
    jw_drawing ref;
    const jw_drawing *d;
    unsigned char *b;
    long n;
    rect_t r;
    int face = -1, i, j, bad = 0;

    printf("%d%s -> %s\n", id, twocol ? " (two colours)"
           : scramble ? " (out of order)" : "", answer);
    memset(&ref, 0, sizeof ref);
    b = slurp(answer, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", answer);
        fails++;
        free(b);
        return;
    }
    free(b);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot read orig/Test5.jww\n");
        fails++;
        free(b);
        jw_free(&ref);
        return;
    }
    free(b);
    d = app_drawing();
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && d->obj[i].face >= 0) {
            face = d->obj[i].face;
            break;
        }
    sorted((jw_drawing *)d, face, scramble, twocol);

    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_SEIRI);
    app_press(r.x + 60, r.y + 60, 0);
    app_press(r.x + r.w - 6, r.y + r.h - 6, 1);
    app_move(r.x + 300, r.y + 300);
    jw_cmd_bar((jw_drawing *)app_drawing(), 1120);
    ck(jw_cmd_bar((jw_drawing *)app_drawing(), id) == 1,
       "  the button does something");

    d = app_drawing();
    for (i = 0, j = 0; i < ref.ndrawn; i++) {
        const jw_obj *q = &ref.obj[i], *p;
        int k;

        if (!jw_text_drawn(q))
            continue;
        while (j < d->ndrawn && !jw_text_drawn(&d->obj[j]))
            j++;
        if (j >= d->ndrawn) {
            bad = 1;
            break;
        }
        p = &d->obj[j++];
        if (p->cls != q->cls || p->color != q->color) {
            printf("     the %dth is cls=%d col=%d where the original's is "
                   "cls=%d col=%d\n", i, p->cls, p->color, q->cls, q->color);
            bad = 1;
        }
        for (k = 0; k < 8; k++)
            if (!alike_d(p->d[k], q->d[k])) {
                printf("     the %dth is %.9f where the original's is "
                       "%.9f (field %d)\n", i, p->d[k], q->d[k], k);
                bad = 1;
            }
    }
    ck(!bad, "  and everything is where the original put it");
    jw_free(&ref);
}

int main(void)
{
    app_resize(1264, 741);
    one(0, "decomp/res/seiridup.jww");
    one(1, "decomp/res/seirijoin.jww");
    order(1068, 0, 0, "decomp/res/seiri_col.jww");
    order(1069, 0, 0, "decomp/res/seiri_ang.jww");
    order(1066, 0, 0, "decomp/res/seiri_line.jww");
    order(1066, 1, 0, "decomp/res/seiri_line2.jww");
    order(1067, 0, 0, "decomp/res/seiri_colline.jww");
    order(1067, 1, 1, "decomp/res/seiri_colline2.jww");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
