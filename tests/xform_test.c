/* 複写・移動 の 倍率 と 回転角 -- against the two the original made.
 *
 *   tests/xform_test.exe
 *
 * The second stage of both commands puts up 倍率 (1411) and 回転角 (1412).
 * What they do, read off the original: every point goes to
 *
 *     click + R(回転角) * 倍率 * (point - 基準点)
 *
 * with the 基準点 the place the cursor was sitting when 選択確定 was pressed
 * (not a click -- that is why tools/jwdraw.ps1 has an `m` step now).  A
 * rectangle copied at 倍率 2, 回転角 30 and the same one moved at 0.5 and
 * -45 both came out on that formula to four decimals
 * (decomp/res/copyxf.jww, movexf.jww).
 *
 * The clicks are written down here as the pixels the original was given, and
 * turned into the drawing's units through the rectangle it drew with two of
 * them -- the same trick tests/curve_test.c uses.
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

static void type_box(int id, const char *v)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *v; v++)
        jw_cmd_box_key((unsigned char)*v);
    jw_cmd_box_key(13);
}

/* the four lines of the rectangle the original drew, from the copy answer */
static jw_obj rect[4];
static int nrect;
static double k, ox, oy;                /* paper = o + k * pixel */

static int read_rect(void)
{
    unsigned char *b;
    long n;
    jw_drawing ref;
    int i, m = 0;

    b = slurp("decomp/res/copyxf.jww", &n);
    if (!b) {
        printf("BAD  cannot read decomp/res/copyxf.jww -- drive the original first\n");
        fails++;
        return 0;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  decomp/res/copyxf.jww: %s\n", ref.error);
        fails++;
        return 0;
    }
    free(b);
    for (i = 0; i < ref.ndrawn && m < 4; i++)
        if (ref.obj[i].cls == JW_SEN)
            rect[m++] = ref.obj[i];
    nrect = m;
    if (m == 4) {
        /* it was drawn with clicks at (300,300) and (500,400) */
        k = (rect[1].d[0] - rect[0].d[0]) / 200.0;
        ox = rect[0].d[0] - k * 300.0;
        oy = rect[0].d[1] + k * 300.0;
    }
    jw_free(&ref);
    return m == 4;
}

static double PX(double x) { return ox + k * x; }
static double PY(double y) { return oy - k * y; }

/* `moving` picks 移動 rather than 複写; `want` is how many lines the answer
   holds beside the ones that were there before. */
static void run(const char *path, int moving, const char *scale,
                const char *turn, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *want[4];
    int i, nw = 0, before;
    double worst = 0;

    printf("%s\n", what);
    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        fails++;
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN) {
            if (!moving && nw < 4 && i < 4)
                continue;       /* 複写 keeps the first rectangle as it was */
            if (nw < 4)
                want[nw++] = &ref.obj[i];
        }
    ck(nw == 4, "  the original's four lines are in the file");
    if (nw != 4) {
        jw_free(&ref);
        return;
    }

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    for (i = 0; i < 4; i++) {
        jw_obj *o = jw_add(d, JW_SEN);
        int c;

        for (c = 0; c < 4; c++)
            o->d[c] = rect[i].d[c];
    }
    before = d->ndrawn;

    jw_cmd_set(moving ? JW_CMD_IDOU : JW_CMD_FUKUSHA);
    type_box(1411, scale);
    type_box(1412, turn);
    /* the box round it, as the original was given it */
    jw_cmd_point(d, app_view(), PX(250), PY(250), 0);
    jw_cmd_point(d, app_view(), PX(550), PY(450), 0);
    ck(jw_cmd_sel_count(d) == 4, "  the box takes the rectangle");
    /* the cursor is the 基準点 */
    jw_cmd_track(PX(400), PY(350));
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 can be pressed");
    jw_cmd_point(d, app_view(), PX(700), PY(500), 0);
    ck(d->ndrawn == (moving ? before : before + 4),
       moving ? "  移動 leaves the count alone" : "  複写 leaves four more");
    if (d->ndrawn != (moving ? before : before + 4)) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 4; i++) {
        const jw_obj *o = &d->obj[moving ? before - 4 + i : before + i];
        int c;

        for (c = 0; c < 4; c++) {
            double e = fabs(o->d[c] - want[i]->d[c]);

            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6) {
        const jw_obj *o = &d->obj[moving ? before - 4 : before];

        printf("     worst disagreement %.6g\n"
               "     ours   %.4f,%.4f -> %.4f,%.4f\n"
               "     theirs %.4f,%.4f -> %.4f,%.4f\n", worst,
               o->d[0], o->d[1], o->d[2], o->d[3],
               want[0]->d[0], want[0]->d[1], want[0]->d[2], want[0]->d[3]);
    }
    ck(worst <= 1e-6, "  every corner where the original put it");
    jw_free(&ref);
}

/* 反転: the same two commands, flipping across a line instead of placing.
 *
 * Pressing 反転 (1067 -- 選択解除's id one stage on) changes the status line
 * to 「基準線を指示してください。 文字方向補正無(L) 有(R)」 and the next click
 * picks that line; there is no placing click afterwards.  The answers have
 * the axis as their first line, then what came of the rectangle.
 */
static void run_flip(const char *path, int moving, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *axis, *want[4];
    int i, nl = 0, nw = 0, before;
    double worst = 0;

    printf("%s\n", what);
    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        fails++;
        return;
    }
    free(b);
    axis = 0;
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN) {
            if (!axis)
                axis = &ref.obj[i];     /* the 基準線 was drawn first */
            else if (moving || nl >= 4)
                { if (nw < 4) want[nw++] = &ref.obj[i]; }
            else
                nl++;                   /* 複写 keeps the first rectangle */
        }
    ck(axis && nw == 4, "  the original's line and four are in the file");
    if (!axis || nw != 4) {
        jw_free(&ref);
        return;
    }

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {   /* the axis first, the way the original drew it */
        jw_obj *o = jw_add(d, JW_SEN);
        int c;

        for (c = 0; c < 4; c++)
            o->d[c] = axis->d[c];
    }
    for (i = 0; i < 4; i++) {
        jw_obj *o = jw_add(d, JW_SEN);
        int c;

        for (c = 0; c < 4; c++)
            o->d[c] = rect[i].d[c];
    }
    before = d->ndrawn;

    jw_cmd_set(moving ? JW_CMD_IDOU : JW_CMD_FUKUSHA);
    type_box(1411, "");
    type_box(1412, "");
    jw_cmd_point(d, app_view(), PX(250), PY(250), 0);
    jw_cmd_point(d, app_view(), PX(550), PY(450), 0);
    ck(jw_cmd_sel_count(d) == 4, "  the box takes the rectangle, not the line");
    jw_cmd_track(PX(400), PY(350));
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 can be pressed");
    ck(jw_cmd_bar(d, 1067) == 1, "  反転 can be pressed");
    ck(d->ndrawn == before, "  and draws nothing on its own");
    /* point at the middle of the axis */
    jw_cmd_point(d, app_view(), (axis->d[0] + axis->d[2]) / 2,
                 (axis->d[1] + axis->d[3]) / 2, 0);
    ck(d->ndrawn == (moving ? before : before + 4),
       moving ? "  移動 leaves the count alone" : "  複写 leaves four more");
    if (d->ndrawn != (moving ? before : before + 4)) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 4; i++) {
        const jw_obj *o = &d->obj[moving ? before - 4 + i : before + i];
        int c;

        for (c = 0; c < 4; c++) {
            double e = fabs(o->d[c] - want[i]->d[c]);

            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6) {
        const jw_obj *o = &d->obj[moving ? before - 4 : before];

        printf("     worst disagreement %.6g\n"
               "     ours   %.4f,%.4f -> %.4f,%.4f\n"
               "     theirs %.4f,%.4f -> %.4f,%.4f\n", worst,
               o->d[0], o->d[1], o->d[2], o->d[3],
               want[0]->d[0], want[0]->d[1], want[0]->d[2], want[0]->d[3]);
    }
    ck(worst <= 1e-6, "  every corner across the line, ends in their order");
    jw_free(&ref);
}

int main(void)
{
    if (!read_rect()) {
        printf("%d failed\n", fails ? fails : 1);
        return 1;
    }
    run("decomp/res/copyxf.jww", 0, "2", "30",
        "複写, 倍率 2 and 回転角 30:");
    run("decomp/res/movexf.jww", 1, "0.5", "-45",
        "移動, 倍率 0.5 and 回転角 -45:");
    run_flip("decomp/res/flip.jww", 0,
             "複写の反転, across an upright line:");
    run_flip("decomp/res/flipmv.jww", 1,
             "移動の反転, across a sloping one:");
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
