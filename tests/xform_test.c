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

/* 基点変更 (1066 -- 全選択's id one stage on).
 *
 * Pressing it asks 「基準点を指示して下さい」 and the next click is the new
 * 基準点; the one after that places the copy, and the status line then reads
 * 「複写先の点を指示して下さい」 with the offset in it.  So the copy lands at
 * click - 基準点 away from where it was, the cursor no longer mattering.
 */
static void run_base(const char *path, const char *what)
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
        if (ref.obj[i].cls == JW_SEN && i >= 4 && nw < 4)
            want[nw++] = &ref.obj[i];
    ck(nw == 4, "  the original's copy is in the file");
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

    jw_cmd_set(JW_CMD_FUKUSHA);
    type_box(1411, "");
    type_box(1412, "");
    jw_cmd_point(d, app_view(), PX(250), PY(250), 0);
    jw_cmd_point(d, app_view(), PX(550), PY(450), 0);
    ck(jw_cmd_sel_count(d) == 4, "  the box takes the rectangle");
    /* the cursor is somewhere else entirely, to show it is not used */
    jw_cmd_track(PX(400), PY(350));
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 can be pressed");
    ck(jw_cmd_bar(d, 1066) == 1, "  基点変更 can be pressed");
    jw_cmd_point(d, app_view(), PX(350), PY(320), 0);
    ck(d->ndrawn == before, "  the 基準点 draws nothing");
    jw_cmd_point(d, app_view(), PX(700), PY(500), 0);
    ck(d->ndrawn == before + 4, "  and the next click leaves the copy");
    if (d->ndrawn != before + 4) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 4; i++) {
        const jw_obj *o = &d->obj[before + i];
        int c;

        for (c = 0; c < 4; c++) {
            double e = fabs(o->d[c] - want[i]->d[c]);

            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6)
        printf("     worst disagreement %.6g\n"
               "     ours   %.4f,%.4f -> %.4f,%.4f\n"
               "     theirs %.4f,%.4f -> %.4f,%.4f\n", worst,
               d->obj[before].d[0], d->obj[before].d[1],
               d->obj[before].d[2], d->obj[before].d[3],
               want[0]->d[0], want[0]->d[1], want[0]->d[2], want[0]->d[3]);
    ck(worst <= 1e-6, "  where the original put it, counted from that point");
    jw_free(&ref);
}

/* 任意方向 (1151): the button cycles 任意方向 → X 方向 → Y 方向 → XY方向.
 *
 * X keeps only the across part of the move, Y only the up-and-down one, and
 * XY keeps whichever is longer.  The original was given the same copy in
 * each of them; the answers here are the four it left.
 */
static void run_dir(const char *path, int presses, int cx, int cy,
                    const char *what)
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
        if (ref.obj[i].cls == JW_SEN && i >= 4 && nw < 4)
            want[nw++] = &ref.obj[i];
    ck(nw == 4, "  the original's copy is in the file");
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

    jw_cmd_set(JW_CMD_FUKUSHA);
    type_box(1411, "");
    type_box(1412, "");
    jw_cmd_point(d, app_view(), PX(250), PY(250), 0);
    jw_cmd_point(d, app_view(), PX(550), PY(450), 0);
    jw_cmd_track(PX(400), PY(350));
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 can be pressed");
    for (i = 0; i < presses; i++)
        ck(jw_cmd_bar(d, 1151) == 1, "  任意方向 can be pressed");
    jw_cmd_point(d, app_view(), PX(cx), PY(cy), 0);
    ck(d->ndrawn == before + 4, "  the click leaves the copy");
    if (d->ndrawn != before + 4) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 4; i++) {
        const jw_obj *o = &d->obj[before + i];
        int c;

        for (c = 0; c < 4; c++) {
            double e = fabs(o->d[c] - want[i]->d[c]);

            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6)
        printf("     worst disagreement %.6g\n"
               "     ours   %.4f,%.4f -> %.4f,%.4f\n"
               "     theirs %.4f,%.4f -> %.4f,%.4f\n", worst,
               d->obj[before].d[0], d->obj[before].d[1],
               d->obj[before].d[2], d->obj[before].d[3],
               want[0]->d[0], want[0]->d[1], want[0]->d[2], want[0]->d[3]);
    ck(worst <= 1e-6, "  squared off the way the original squares it");
    jw_free(&ref);
}

/* 全選択 (1066) は 編集できるレイヤの要素だけ（原典 CZukeiSentaku の 44 番目 FUN_006fc520:
   守られていなくて FUN_0042dd10 が 3 と言うもの）。表示のみ・非表示のレイヤのものは選ばない */
static void select_all_editable(void)
{
    jw_drawing *d;
    int i;

    app_new();
    app_command(32771);
    app_press(400, 300, 0);
    app_press(500, 300, 0);
    app_press(400, 400, 0);
    app_press(500, 400, 0);
    app_press(400, 500, 0);
    app_press(500, 500, 0);
    d = (jw_drawing *)app_drawing();
    if (d->ndrawn < 3) {
        ck(0, "全選択: 三本の線が引けた");
        return;
    }
    d->obj[1].layer = 1;
    d->obj[2].layer = 2;
    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3) {
            d->group[i].layer[1].state = 1;     /* 表示のみ */
            d->group[i].layer[2].state = 0;     /* 非表示 */
        }
    app_command(32787);
    jw_cmd_bar(d, 1066);
    ck(d->obj[0].sel && !d->obj[1].sel && !d->obj[2].sel,
       "全選択は 編集できるレイヤの線だけ（表示のみ・非表示は選ばない）");
    ck((d->obj[0].flags & 2) && !(d->obj[1].flags & 2) && !(d->obj[2].flags & 2),
       "  選択の印も その線だけ");
}

/* 範囲選択のバーの 基準点変更 (1064): 選んだあとに押すと 次のクリックが基準点になり、
   選択確定は マウスの位置ではなく その点を基準点にする（CZukeiSentaku の 22 番目
   FUN_006f8e00 と FUN_006fd240 の +0xac の枝。逆コンパイルの読み） */
static void base_before_confirm(void)
{
    jw_drawing *d;
    const jw_view *v;
    double x0, y0;
    int n;

    app_new();
    v = app_view();
    app_command(32771);
    app_press(400, 300, 0);
    app_press(500, 300, 0);
    d = (jw_drawing *)app_drawing();
    x0 = d->obj[0].d[0];
    y0 = d->obj[0].d[1];
    app_command(32804);                 /* 複写 */
    ck(jw_cmd_bar_enabled(d, 1064) == 0, "基準点変更 は 範囲が無いうちは死んでいる");
    app_press(350, 250, 0);
    app_press(550, 350, 0);
    ck(jw_cmd_bar_enabled(d, 1064) > 0, "  範囲で拾うと生きる");
    jw_cmd_bar(d, 1064);
    app_press(400, 300, 0);             /* the line's left end: the 基準点 */
    app_move(700, 600);                 /* the mouse elsewhere when it is confirmed */
    jw_cmd_bar(d, 1120);                /* 選択確定 */
    n = d->ndrawn;
    app_press(600, 500, 0);             /* where the 基準点 goes */
    ck(d->ndrawn == n + 1, "  置き先を指すと 写しが一つ");
    if (d->ndrawn == n + 1) {
        const jw_obj *c = &d->obj[d->ndrawn - 1];
        double px = jw_sx(v, c->d[0]), py = jw_sy(v, c->d[1]);

        ck(px >= 598 && px <= 602 && py >= 498 && py <= 502,
           "  写しの左端が置き先に来る（基準点は指した点で、マウスの位置ではない）");
        (void)x0;
        (void)y0;
    }
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
    run_base("decomp/res/basept.jww",
             "複写の基点変更, the cursor no longer the 基準点:");
    run_dir("decomp/res/dirx.jww", 1, 700, 500, "X 方向:");
    run_dir("decomp/res/diry.jww", 2, 700, 500, "Y 方向:");
    run_dir("decomp/res/dirxy1.jww", 3, 700, 500,
            "XY方向 with the wider move:");
    run_dir("decomp/res/dirxy2.jww", 3, 500, 650,
            "XY方向 with the taller one:");
    ck(!strcmp(jw_cmd_dir_text(), "XY\x95\xfb\x8c\xfc"),
       "and the button is carrying XY方向 by now");
    select_all_editable();
    base_before_confirm();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
