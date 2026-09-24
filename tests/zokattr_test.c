/* 属性選択・属性変更の「指定」もの -- against the original.
 *
 *   tests/zokattr_test.exe
 *
 * **Where the "指定" comes from.**  Ticking 指定【線色】指定 (1810) or
 * 指定 線種 指定 (1811) in 属性選択 and pressing OK does not filter
 * anything there and then: it puts the **線属性 dialog** up, and the colour
 * or the line type picked there is what the filter means.  属性変更's
 * 指定【線色】に変更 (1822) and 指定 線種 に変更 (1823) do the same.
 *
 * The four answers, all over tools/mkgeom.c's twelve elements with a range
 * round the lot and 線色3 / 線種3 picked in that dialog:
 *
 *   zokcol  filter to colour 3, then 消去 -- the three colour-3 elements go
 *   zoklt   filter to line type 3, then 消去 -- only the one line goes
 *   zhcol   change to colour 3 -- every one of the twelve, line types kept
 *   zhlt    change to line type 3 -- **lines and arcs only**: the two
 *           points and the two solids stayed at 1
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/zokusel.h"
#include "../src/gen/zokuhen.h"
#include "../src/gen/zoku.h"
#include "../src/gen/bars.h"

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

static void sel_ctl(int id, int *x, int *y)
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

static void hen_ctl(int id, int *x, int *y)
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

static void zoku_ctl(int id, int *x, int *y)
{
    rect_t r;
    int i;

    ui_zoku_rect(1264, 741, &r);
    for (i = 0; i < JW_NZOKU; i++)
        if (jw_zoku[i].id == id) {
            *x = r.x + JW_ZOKU_BORDER + jw_zoku[i].x + jw_zoku[i].w / 2;
            *y = r.y + JW_ZOKU_CAPTION + jw_zoku[i].y + jw_zoku[i].h / 2;
            return;
        }
    *x = *y = -1;
}

/* Open the drawing the answers were made from and take a range over it. */
static int start(void)
{
    const fb_t *fb = app_fb();
    unsigned char *b;
    long n;
    rect_t r;

    b = slurp("tmp/geom.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open tmp/geom.jww -- run tools/refanswers.sh\n");
        free(b);
        fails++;
        return 0;
    }
    free(b);
    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    /* The original was driven with the far corner at (1150, 650), which is
       outside its 1108x686 view -- a posted message is not hit-tested, so
       it landed on the paper point it maps to all the same.  app_press
       would drop it, so the points go straight in. */
    {
        const jw_view *v = app_view();
        double x0 = v->ox + (100 - v->bx + r.x) / v->scale;
        double y0 = v->oy + (v->by - (100 + r.y)) / v->scale;
        double x1 = v->ox + (1150 - v->bx + r.x) / v->scale;
        double y1 = v->oy + (v->by - (650 + r.y)) / v->scale;

        jw_cmd_point((jw_drawing *)app_drawing(), v, x0, y0, 0);
        jw_cmd_point((jw_drawing *)app_drawing(), v, x1, y1, 1);
    }
    return jw_cmd_sel_count(app_drawing()) == 12;
}

/* What the original left, compared with what the port has. */
static void against(const char *answer)
{
    const jw_drawing *d = app_drawing();
    jw_drawing ref;
    unsigned char *b;
    long n;
    int i, j, bad = 0, nref = 0, nmine = 0;

    memset(&ref, 0, sizeof ref);
    b = slurp(answer, &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read %s -- drive the original first\n", answer);
        fails++;
        free(b);
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++)
        if (jw_text_drawn(&ref.obj[i]))
            nref++;
    for (i = 0; i < d->ndrawn; i++)
        if (jw_text_drawn(&d->obj[i]))
            nmine++;
    if (nref != nmine)
        printf("     the port left %d, the original %d\n", nmine, nref);
    ck(nref == nmine, "  as many elements as the original left");
    for (i = 0, j = 0; i < ref.ndrawn && j < d->ndrawn; i++) {
        const jw_obj *q = &ref.obj[i], *p;

        if (!jw_text_drawn(q))
            continue;
        while (j < d->ndrawn && !jw_text_drawn(&d->obj[j]))
            j++;
        if (j >= d->ndrawn)
            break;
        p = &d->obj[j++];
        if (p->cls != q->cls || p->color != q->color
            || p->ltype != q->ltype) {
            printf("     the %dth is cls=%d col=%d lt=%d where the "
                   "original's is cls=%d col=%d lt=%d\n", i, p->cls,
                   p->color, p->ltype, q->cls, q->color, q->ltype);
            bad = 1;
        }
    }
    ck(!bad, "  and each carries the original's colour and line type");
    jw_free(&ref);
}

/* 属性選択: tick `tick`, OK, pick `pen` in the 線属性 dialog, Ok, 消去. */
static void filter(int tick, int pen, const char *answer)
{
    int x, y;

    printf("%s\n", answer);
    if (!start()) {
        printf("BAD  the range did not take all twelve\n");
        fails++;
        return;
    }
    ck(bar_button(1069, &x, &y), "  the bar has 属性選択");
    app_press(x, y, 0);
    ck(app_zokusel_open(), "  and it puts the dialog up");
    sel_ctl(tick, &x, &y);
    app_press(x, y, 0);
    sel_ctl(1, &x, &y);                 /* OK */
    app_press(x, y, 0);
    ck(!app_zokusel_open(), "  OK takes it down");
    ck(app_zoku_open(), "  and puts the 線属性 dialog up in its place");
    zoku_ctl(pen, &x, &y);
    app_press(x, y, 0);
    zoku_ctl(1, &x, &y);                /* Ok */
    app_press(x, y, 0);
    ck(!app_zoku_open(), "  which Ok takes down");
    app_command(JW_CMD_SHOUKYO);        /* 消去 -- what is left goes */
    against(answer);
}

/* 属性変更: the same, with the other half of the dialog and no 消去. */
static void change(int tick, int pen, const char *answer)
{
    int x, y;

    printf("%s\n", answer);
    if (!start()) {
        printf("BAD  the range did not take all twelve\n");
        fails++;
        return;
    }
    ck(bar_button(1070, &x, &y), "  the bar has 属性変更");
    app_press(x, y, 0);
    ck(app_zokuhen_open(), "  and it puts the dialog up");
    hen_ctl(tick, &x, &y);
    app_press(x, y, 0);
    hen_ctl(1, &x, &y);                 /* OK */
    app_press(x, y, 0);
    ck(!app_zokuhen_open(), "  OK takes it down");
    ck(app_zoku_open(), "  and puts the 線属性 dialog up in its place");
    zoku_ctl(pen, &x, &y);
    app_press(x, y, 0);
    zoku_ctl(1, &x, &y);                /* Ok */
    app_press(x, y, 0);
    ck(!app_zoku_open(), "  which Ok takes down");
    against(answer);
}

int main(void)
{
    app_resize(1264, 741);
    filter(1810, 1403, "decomp/res/zokcol.jww");
    filter(1811, 2451, "decomp/res/zoklt.jww");
    change(1822, 1403, "decomp/res/zhcol.jww");
    change(1823, 2451, "decomp/res/zhlt.jww");
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
