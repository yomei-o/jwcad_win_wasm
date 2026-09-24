/* 属性変更 from a range (範囲選択's 1070) -- against the original.
 *
 *   tests/zokuhen2_test.exe tests/out/zokuhen.png
 *
 * The same window as 属性選択 with the other half of its controls showing.
 * docs/ref_zokuhen.png is it painted into a bitmap by Jw_cad itself.
 *
 * What it does: only 書込【レイヤ】に変更 could be driven to any effect.
 * tools/mkgeom.c's twelve elements, all on layer 0, came back on layer 8 --
 * the write layer -- with everything else untouched
 * (decomp/res/zhlayer.jww).  指定【線色】に変更 and 指定 線種 に変更
 * changed nothing at all, the same way the 指定【線色】指定 filter matches
 * everything, so where the "指定" one comes from is still unknown.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/zokuhen.h"
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

static void ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_zokuhen_rect(1264, 741, &r);
    for (i = 0; i < JW_NZOKUHEN; i++)
        if (jw_zokuhen[i].id == id) {
            *x = r.x + JW_ZH_BORDER + jw_zokuhen[i].x + jw_zokuhen[i].w / 2;
            *y = r.y + JW_ZH_CAPTION + jw_zokuhen[i].y + jw_zokuhen[i].h / 2;
            return;
        }
    *x = *y = -1;
}

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

int main(int argc, char **argv)
{
    const fb_t *fb;
    const jw_drawing *d;
    jw_drawing ref;
    unsigned char *b;
    long n;
    rect_t r;
    int x, y, i, j, bad = 0;

    app_resize(1264, 741);
    fb = app_fb();
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    geom((jw_drawing *)app_drawing());

    ck(!app_zokuhen_open(), "the dialog is not up to start with");
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
    ck(jw_cmd_sel_count(app_drawing()) == 12, "a range over all twelve");
    ck(bar_button(1070, &x, &y), "the bar has 属性変更");
    app_press(x, y, 0);
    ck(app_zokuhen_open(), "and pressing it puts the dialog up");

    app_paint();
    if (argc > 1) {
        unsigned int *px;

        ui_zokuhen_rect(fb->w, fb->h, &r);
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

    ctl(1825, &x, &y);                  /* 書込【レイヤ】に変更 */
    app_press(x, y, 0);
    ctl(1, &x, &y);                     /* OK */
    app_press(x, y, 0);
    ck(!app_zokuhen_open(), "OK takes it down");

    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/zhlayer.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/zhlayer.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
        printf("%s\n", fails ? "SOME BAD" : "all ok");
        return fails ? 1 : 0;
    }
    free(b);
    d = app_drawing();
    for (i = 0, j = 0; i < ref.ndrawn; i++) {
        const jw_obj *q = &ref.obj[i], *p;

        if (!jw_text_drawn(q))
            continue;                   /* the original's own memo texts */
        while (j < d->ndrawn && !jw_text_drawn(&d->obj[j]))
            j++;
        if (j >= d->ndrawn)
            break;
        p = &d->obj[j++];
        if (p->cls != q->cls || p->color != q->color
            || p->ltype != q->ltype || (p->layer & 15) != (q->layer & 15)
            || (p->lgroup & 15) != (q->lgroup & 15)) {
            printf("     the %dth is cls=%d col=%d lt=%d lay=%d where the "
                   "original's is cls=%d col=%d lt=%d lay=%d\n", i, p->cls,
                   p->color, p->ltype, p->layer & 15, q->cls, q->color,
                   q->ltype, q->layer & 15);
            bad = 1;
        }
    }
    ck(!bad, "and every element carries what the original's does");
    jw_free(&ref);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
