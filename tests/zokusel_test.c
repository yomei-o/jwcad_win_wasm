/* 属性選択 -- the 範囲選択 bar's ＜属性選択＞ (1069), against the original.
 *
 *   tests/zokusel_test.exe tests/out/zokusel.png
 *
 * docs/ref_zokusel.png is the dialog painted into a bitmap by Jw_cad itself
 * (tools/jwdraw.ps1's dlg:b step, which never touches the screen).  This
 * puts the port's up in the same state -- a box taken on a drawing and
 * nothing ticked but 【指定属性選択】, which is what the original had -- and
 * writes it out to be scored against that picture; tools/check.sh does the
 * scoring, with the text left out of it the same way the frame is.
 *
 * And what it is for.  The original was given the same box and one tick at
 * a time, then 消去, and what it was left with is in decomp/res/zok*.jww
 * (tools/refanswers.sh's === zoku).  The drawing is tools/mkgeom.c's -- four
 * lines, four arcs, two points and two solids -- except for 文字指定, which
 * is on Test5 because that one has texts.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/layout.h"
#include "../src/gen/zokusel.h"
#include "../src/gen/cmds.h"
#include "../src/gen/bars.h"
#include "png.h"

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

    ui_zokusel_rect(1264, 741, &r);
    for (i = 0; i < JW_NZOKUSEL; i++)
        if (jw_zokusel[i].id == id) {
            *x = r.x + JW_ZS_BORDER + jw_zokusel[i].x + jw_zokusel[i].w / 2;
            *y = r.y + JW_ZS_CAPTION + jw_zokusel[i].y + jw_zokusel[i].h / 2;
            return;
        }
    *x = *y = -1;
}

/* the middle of a control on the 範囲選択 bar */
static int bar_button(int id, int *x, int *y)
{
    int i;

    for (i = 0; i < (int)(sizeof jw_bar_32787 / sizeof jw_bar_32787[0]); i++)
        if (jw_bar_32787[i].id == id) {
            *x = jw_bar_32787[i].x + jw_bar_32787[i].w / 2;
            *y = jw_bar_32787[i].y + jw_bar_32787[i].h / 2;
            return 1;
        }
    return 0;
}

/* the same drawing tools/mkgeom.c makes, which is what the original was
   given: four lines, four arcs, two points and two solids */
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

/* How many of each class a drawing has, the texts with no length left out:
   the original writes six memo lines of its own into every file it saves
   (Printer_Orientation and the rest, at 0,-1000 with no length), and those
   are not part of what was drawn. */
static void counts(const jw_drawing *d, int *c)
{
    int i;

    for (i = 0; i < 5; i++)
        c[i] = 0;
    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];

        if (!jw_text_drawn(o))
            continue;
        if (o->cls < 5)
            c[o->cls]++;
    }
}

/* Open a drawing, take a box over the whole view, tick one box in the
   dialog, press Ok and then 消去 -- and see that what is left is what the
   original was left with. */
static void one(const char *jww, int useGeom, int id, int exclude,
                int bx0, int by0, int bx1, int by1, const char *answer)
{
    const fb_t *fb = app_fb();
    jw_drawing ref;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, mine[5], want[5], k, bad = 0;

    printf("%s: %d%s -> %s\n", useGeom ? "geom" : jww, id,
           exclude ? " 除外" : "", answer);
    memset(&ref, 0, sizeof ref);
    b = slurp(answer, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", answer);
        fails++;
        free(b);
        return;
    }
    free(b);
    b = slurp(jww, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot read %s\n", jww);
        fails++;
        free(b);
        jw_free(&ref);
        return;
    }
    free(b);
    if (useGeom)
        geom((jw_drawing *)app_drawing());

    ui_view_rect(fb->w, fb->h, &r);
    if (bx1 > r.w - 4)                  /* the original's box ran out to the
                                           edge of a view of its own size */
        bx1 = r.w - 4;
    if (by1 > r.h - 4)
        by1 = r.h - 4;
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + bx0, r.y + by0, 0);
    app_press(r.x + bx1, r.y + by1, 1);             /* (R): texts as well */
    ck(jw_cmd_sel_count(app_drawing()) > 0, "  the box picks the drawing up");
    ck(jw_cmd_bar_enabled(app_drawing(), 1069) > 0,
       "  and the button comes alive");
    if (bar_button(1069, &x, &y))
        app_press(x, y, 0);
    ck(app_zokusel_open(), "  pressing it puts the dialog up");
    ctl(id, &x, &y);
    app_press(x, y, 0);
    if (exclude) {
        ctl(1324, &x, &y);
        app_press(x, y, 0);
    }
    ctl(1, &x, &y);                                 /* Ok */
    app_press(x, y, 0);
    ck(!app_zokusel_open(), "  and Ok takes it down again");
    app_command(JW_CMD_SHOUKYO);

    counts(app_drawing(), mine);
    counts(&ref, want);
    for (k = 0; k < 5; k++)
        if (mine[k] != want[k])
            bad = 1;
    if (bad)
        printf("     ours  sen=%d enko=%d ten=%d moji=%d solid=%d\n"
               "     theirs sen=%d enko=%d ten=%d moji=%d solid=%d\n",
               mine[0], mine[1], mine[2], mine[3], mine[4],
               want[0], want[1], want[2], want[3], want[4]);
    ck(!bad, "  and 消去 leaves what the original was left with");
    jw_free(&ref);
}

int main(int argc, char **argv)
{
    const fb_t *fb;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);

    ck(!app_zokusel_open(), "the dialog is not up to start with");
    jw_cmd_set(JW_CMD_HANI);
    ck(jw_cmd_bar_enabled(app_drawing(), 1069) == 0,
       "and ＜属性選択＞ is dead until a box is in");
    ui_view_rect(fb->w, fb->h, &r);
    app_press(r.x + 250, r.y + 250, 0);
    app_press(r.x + 850, r.y + 550, 1);
    ck(jw_cmd_bar_enabled(app_drawing(), 1069) > 0,
       "the box brings it alive");
    ck(bar_button(1069, &x, &y), "the bar has the button");
    app_press(x, y, 0);
    ck(app_zokusel_open(), "and pressing it puts the dialog up");

    /* the picture, in the state the original's was in */
    app_paint();
    if (argc > 1) {
        unsigned int *px;
        int i, j;

        ui_zokusel_rect(fb->w, fb->h, &r);
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
    ctl(2, &x, &y);                     /* the second Ok closes it as well */
    app_press(x, y, 0);
    ck(!app_zokusel_open(), "either Ok takes it down");

    /* and what it does, one kind at a time */
    one("orig/Test5.jww", 1, 1812, 0, 100, 100, 1150, 650,
        "decomp/res/zoksen.jww");
    one("orig/Test5.jww", 1, 2434, 0, 100, 100, 1150, 650,
        "decomp/res/zokenko.jww");
    one("orig/Test5.jww", 1, 2430, 0, 100, 100, 1150, 650,
        "decomp/res/zokten.jww");
    one("orig/Test5.jww", 1, 2433, 0, 100, 100, 1150, 650,
        "decomp/res/zoksol.jww");
    one("orig/Test5.jww", 1, 2434, 1, 100, 100, 1150, 650,
        "decomp/res/zokout.jww");
    one("orig/Test5.jww", 0, 1804, 0, 250, 250, 850, 550,
        "decomp/res/zokmoji.jww");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
