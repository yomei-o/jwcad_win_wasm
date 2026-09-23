/* ハッチ (0x806a), 1線 -- against the two the original drew.
 *
 *   tests/hatch_test.exe
 *
 * The boundary is settled with the right button -- 「閉鎖連続線・円をマウス(R)で
 * 指示してください」 -- and 実行 stays greyed until one is: picking a rectangle's
 * four sides one at a time with the left button left it greyed and drew
 * nothing, while one right click on any of them took the whole ring.
 *
 * What it draws then is simple, and came out exact both times.  The lines sit
 * where the normal of the 角度 direction times the point is a whole multiple
 * of the ピッチ -- anchored at zero rather than at the region, so a hatch over
 * two regions lines up -- and each line is exactly the chord of the region at
 * that offset.  A circle of radius 129.88 at 45 degrees and pitch 10 gave 26
 * chords at offsets 190 down to -60, and a rectangle 49 at 300 down to -180
 * (decomp/res/hatch_*.jww).  They come out far side first.
 *
 * ２線 (1690) and ３線 (1691) draw two and three lines per ピッチ, 線間隔
 * apart and centred on where the one line would have been: the same rectangle
 * came back with 98 lines at 300.5, 299.5, 290.5, 289.5 ... and with 147 at
 * 301, 300, 299, 291, 290, 289 ... (decomp/res/hatch_r169*.jww).  So the
 * group still goes far side first, and so does the group's own inside.
 *
 * ┬┴┬ (1692) is a running bond: lines all the way across every 縦ピッチ, and
 * between them cross pieces every half a 横ピッチ, drawn where m + k is even
 * (m counts the columns, k the courses) so they stagger.  Two runs of the
 * original pin it down -- 角度 0・縦 3・横 6 as the bar comes up, and
 * 角度 30・縦 20・横 50 typed in -- 6,467 pieces and 146.
 *
 * The bar keeps a set of numbers per mode: 1線 comes up 45・10・1 and ┬┴┬
 * comes up 0・3・6, and going back shows 45・10・1 again.
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

/* Test5's own 46 lines come first; `skip` more are the boundary the run drew
   before the hatch itself. */
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

/* `set` is the three numbers to type in, or 0 to leave the bar as the mode
   brings it up; `jisun` presses 実寸 first, which puts the ピッチ into the
   drawing's own units instead of paper millimetres; `base` presses 基点変 and
   gives it the rectangle's own first corner, so the pattern counts from
   there rather than from zero. */
static void run(const char *path, int skip, int want, int mode,
                const char *const *set, int jisun, int base, const char *what)
{
    unsigned char *b;
    long len;
    jw_drawing ref, *d;
    const jw_obj *all[8192], *circle = 0, *seg[8192];
    int i, na = 0, before, ns = 0;
    double worst = 0;

    printf("%s\n", what);
    b = slurp(path, &len);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        fails++;
        return;
    }
    if (!jw_parse(&ref, b, len)) {
        printf("BAD  %s: %s\n", path, ref.error);
        fails++;
        return;
    }
    free(b);
    for (i = 0; i < ref.ndrawn; i++) {
        if (ref.obj[i].cls == JW_SEN && na < 8192)
            all[na++] = &ref.obj[i];
        if (ref.obj[i].cls == JW_ENKO)
            circle = &ref.obj[i];
    }
    ck(na >= want + skip, "  the original's hatch is in the file");
    if (na < want + skip) {
        jw_free(&ref);
        return;
    }
    for (i = na - want; i < na && ns < 8192; i++)
        seg[ns++] = all[i];

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &len);
    if (!b || !app_open(b, len)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        fails++;
        jw_free(&ref);
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    if (skip) {
        /* the boundary ring the original drew, before its hatch */
        for (i = 0; i < skip; i++) {
            jw_obj *o = jw_add(d, JW_SEN);
            const jw_obj *r = all[na - want - skip + i];
            o->d[0] = r->d[0];
            o->d[1] = r->d[1];
            o->d[2] = r->d[2];
            o->d[3] = r->d[3];
        }
    } else {
        jw_obj *o = jw_add(d, JW_ENKO);
        int k;
        ck(circle != 0, "  and so is the circle it hatched");
        if (!circle) {
            jw_free(&ref);
            return;
        }
        for (k = 0; k < 7; k++)
            o->d[k] = circle->d[k];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_HATCH);
    ck(jw_cmd_box(1419) && !strcmp(jw_cmd_box(1419), "45")
       && jw_cmd_box(1411) && !strcmp(jw_cmd_box(1411), "10")
       && jw_cmd_box(1412) && !strcmp(jw_cmd_box(1412), "1"),
       "  角度 45・ピッチ 10・線間隔 1 to start with, as the original has them");
    if (mode != 1689)
        ck(jw_cmd_bar(d, mode) == 1, "  the mode button can be pressed");
    /* only worth looking at when this run has not typed its own numbers in:
       the boxes keep what an earlier one left there */
    if (mode >= 1692 && !set)
        ck(jw_cmd_box(1419) && !strcmp(jw_cmd_box(1419), "0")
           && jw_cmd_box(1411) && !strcmp(jw_cmd_box(1411), "3")
           && jw_cmd_box(1412) && !strcmp(jw_cmd_box(1412), "6"),
           "  and brings up 角度 0・縦ピッチ 3・横ピッチ 6");
    ck(jw_cmd_bar_check(1323) == 0, "  実寸 is off to start with");
    if (jisun) {
        ck(jw_cmd_bar(d, 1323) == 1, "  実寸 can be pressed");
        ck(jw_cmd_bar_check(1323) == 1, "  and goes down");
    }
    if (set) {
        type_box(1419, set[0]);
        type_box(1411, set[1]);
        type_box(1412, set[2]);
    }
    if (base) {
        /* the corner of the rectangle the original was given, which is the
           very pixel it was clicked at */
        ck(jw_cmd_bar(d, 1147) == 1, "  基点変 can be pressed");
        jw_cmd_point(d, app_view(), d->obj[before - skip].d[0],
                     d->obj[before - skip].d[1], 0);
        ck(d->ndrawn == before, "  and the point it takes draws nothing");
    }
    /* the left button picks one line at a time, which is not done and which
       the original leaves 実行 greyed for anyway */
    jw_cmd_point(d, app_view(), seg[0]->d[0], seg[0]->d[1], 0);
    ck(jw_cmd_bar(d, 1148) == 1, "  実行 can be pressed");
    ck(d->ndrawn == before, "  but with no boundary it draws nothing");

    /* the right button on the boundary */
    if (skip)
        jw_cmd_point(d, app_view(),
                     (d->obj[before - skip].d[0] + d->obj[before - skip].d[2]) / 2,
                     (d->obj[before - skip].d[1] + d->obj[before - skip].d[3]) / 2, 1);
    else
        jw_cmd_point(d, app_view(), circle->d[0] + circle->d[2], circle->d[1], 1);
    ck(d->ndrawn == before, "  picking the boundary draws nothing on its own");
    ck(jw_cmd_bar(d, 1148) == 1, "  実行 runs");
    ck(d->ndrawn == before + want, "  and leaves as many lines as the original");
    if (d->ndrawn != before + want) {
        printf("     ours %d, the original's %d\n", d->ndrawn - before, want);
        jw_free(&ref);
        return;
    }
    for (i = 0; i < want; i++) {
        int k;
        for (k = 0; k < 4; k++) {
            double e = fabs(d->obj[before + i].d[k] - seg[i]->d[k]);
            if (e > worst)
                worst = e;
        }
    }
    if (worst > 1e-6)
        printf("     worst disagreement %.6g\n"
               "     ours   %.6f,%.6f -> %.6f,%.6f\n"
               "     theirs %.6f,%.6f -> %.6f,%.6f\n", worst,
               d->obj[before].d[0], d->obj[before].d[1],
               d->obj[before].d[2], d->obj[before].d[3],
               seg[0]->d[0], seg[0]->d[1], seg[0]->d[2], seg[0]->d[3]);
    ck(worst <= 1e-6, "  every line where the original put it, in its order");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "  in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the whole hatch back");
    if (jisun)
        jw_cmd_bar(d, 1323);    /* it stays on across commands, so put it back */
    jw_free(&ref);
}

/* 範囲選択 (1067): a boxful of closed figures instead of one ring.
 *
 * The original was given two rectangles on a blank sheet, boxed them both,
 * pressed 選択確定 and then 実行, and drew one run of offsets across the pair
 * -- the chords of both rectangles interleaved, far side first, in the same
 * places the phase would have put them for either on its own
 * (decomp/res/hatch_sel.jww).
 */
static void run_sel(const char *path, const char *what)
{
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *el[64];
    int i, nb, nel = 0, before, want;

    printf("%s\n", what);
    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        fails++;
        return;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    nb = d->ndrawn;

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
    /* the eight lines of the two rectangles come first, the hatch after.
       The original moves its six settings texts to the end of the file when
       it saves, so the lines start at the very front. */
    for (i = 0; i < ref.ndrawn && nel < 64; i++)
        if (ref.obj[i].cls == JW_SEN)
            el[nel++] = &ref.obj[i];
    (void)nb;
    want = nel - 8;
    ck(nel > 8, "  the original's rectangles and hatch are in the file");
    if (nel <= 8) {
        jw_free(&ref);
        return;
    }
    for (i = 0; i < 8; i++) {
        jw_obj *o = jw_add(d, JW_SEN);
        int k;

        for (k = 0; k < 4; k++)
            o->d[k] = el[i]->d[k];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_HATCH);
    /* the boxes keep what earlier runs typed into them */
    type_box(1419, "45");
    type_box(1411, "10");
    type_box(1412, "1");
    ck(jw_cmd_bar(d, 1067) == 1, "  範囲選択 can be pressed");
    /* a box round the pair, well clear of both */
    {
        double x0 = el[0]->d[0], x1 = x0, y0 = el[0]->d[1], y1 = y0;

        for (i = 0; i < 8; i++) {
            int k;

            for (k = 0; k < 2; k++) {
                double px = el[i]->d[2 * k], py = el[i]->d[2 * k + 1];

                if (px < x0) x0 = px;
                if (px > x1) x1 = px;
                if (py < y0) y0 = py;
                if (py > y1) y1 = py;
            }
        }
        jw_cmd_point(d, app_view(), x0 - 10, y0 - 10, 0);
        jw_cmd_point(d, app_view(), x1 + 10, y1 + 10, 0);
    }
    ck(jw_cmd_sel_count(d) == 8, "  the box takes both rectangles");
    ck(jw_cmd_bar(d, 1120) == 1, "  選択確定 can be pressed");
    ck(d->ndrawn == before, "  and draws nothing on its own");
    ck(jw_cmd_bar(d, 1148) == 1, "  実行 runs");
    ck(d->ndrawn == before + want, "  as many lines as the original");
    if (d->ndrawn != before + want) {
        printf("     ours %d, the original's %d\n", d->ndrawn - before, want);
        jw_free(&ref);
        return;
    }
    {
        double worst = 0;

        for (i = 0; i < want; i++) {
            int k;

            for (k = 0; k < 4; k++) {
                double e = fabs(d->obj[before + i].d[k] - el[8 + i]->d[k]);

                if (e > worst)
                    worst = e;
            }
        }
        if (worst > 1e-6)
            printf("     worst disagreement %.6g\n"
                   "     ours   %.6f,%.6f -> %.6f,%.6f\n"
                   "     theirs %.6f,%.6f -> %.6f,%.6f\n", worst,
                   d->obj[before].d[0], d->obj[before].d[1],
                   d->obj[before].d[2], d->obj[before].d[3],
                   el[8]->d[0], el[8]->d[1], el[8]->d[2], el[8]->d[3]);
        ck(worst <= 1e-6,
           "  every line where the original put it, both rectangles in one run");
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "  元に戻る takes the lot back");
    jw_free(&ref);
}

/* The boundary picked one line at a time with the left button: the same
   rectangle drawn here, its four sides picked in turn, and then the first
   one again, which is what closes the ring. */
static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
}

static void pick_case(void)
{
    static const int RECT[] = {
        300, 200, 700, 200,  700, 200, 700, 500,
        700, 500, 300, 500,  300, 500, 300, 200
    };
    static const int PICK[] = {
        500, 200,  700, 350,  500, 500,  300, 350,  480, 200
    };
    jw_drawing ref;
    unsigned char *b;
    long n;
    const jw_drawing *d;
    int i, nr = 0, nm = 0, bad = 0;

    printf("a rectangle whose sides are picked one at a time:\n");
    memset(&ref, 0, sizeof ref);
    b = slurp("decomp/res/hatch_pick.jww", &n);
    if (!b || !jw_parse(&ref, b, n)) {
        printf("BAD  cannot read decomp/res/hatch_pick.jww -- drive the "
               "original first\n");
        fails++;
        free(b);
        return;
    }
    free(b);
    app_new();
    {
        const fb_t *fb = app_fb();
        rect_t r;

        ui_view_rect(fb->w, fb->h, &r);
        jw_cmd_set(JW_CMD_SEN);
        for (i = 0; i + 1 < (int)(sizeof RECT / sizeof RECT[0]); i += 2)
            app_press(r.x + RECT[i], r.y + RECT[i + 1], 0);
        jw_cmd_set(JW_CMD_HATCH);
        for (i = 0; i + 1 < (int)(sizeof PICK / sizeof PICK[0]); i += 2) {
            app_press(r.x + PICK[i], r.y + PICK[i + 1], 0);
            if (i + 2 < (int)(sizeof PICK / sizeof PICK[0]))
                ck(app_drawing()->ndrawn == 4,
                   "  a pick on its own draws nothing");
        }
    }
    ck(jw_cmd_bar((jw_drawing *)app_drawing(), 1148) == 1, "  実行 runs");
    d = app_drawing();
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN)
            nr++;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_SEN)
            nm++;
    if (nm != nr) {
        printf("     %d lines, the original made %d\n", nm, nr);
        bad = 1;
    }
    for (i = 0; i < d->ndrawn && !bad; i++) {
        int k, got = 0;

        if (d->obj[i].cls != JW_SEN)
            continue;
        for (k = 0; k < ref.ndrawn && !got; k++) {
            const jw_obj *o = &ref.obj[k];

            if (o->cls != JW_SEN)
                continue;
            got = (near(o->d[0], d->obj[i].d[0])
                   && near(o->d[1], d->obj[i].d[1])
                   && near(o->d[2], d->obj[i].d[2])
                   && near(o->d[3], d->obj[i].d[3]))
                || (near(o->d[0], d->obj[i].d[2])
                    && near(o->d[1], d->obj[i].d[3])
                    && near(o->d[2], d->obj[i].d[0])
                    && near(o->d[3], d->obj[i].d[1]));
        }
        if (!got) {
            printf("     ours has (%.4f %.4f)-(%.4f %.4f), the original has "
                   "no such line\n", d->obj[i].d[0], d->obj[i].d[1],
                   d->obj[i].d[2], d->obj[i].d[3]);
            bad = 1;
        }
    }
    ck(!bad, "  the same lines as the original's");
    jw_free(&ref);
}

int main(void)
{
    static const char *const b[3] = { "30", "20", "50" };
    static const char *const j[3] = { "45", "2000", "1" };

    run("decomp/res/hatch_circle.jww", 0, 26, 1689, 0, 0, 0,
        "a circle, 45 degrees, pitch 10:");
    run("decomp/res/hatch_rect.jww", 4, 49, 1689, 0, 0, 0,
        "a rectangle, the same:");
    run("decomp/res/hatch_r1690.jww", 4, 98, 1690, 0, 0, 0,
        "the same rectangle, ２線, 線間隔 1:");
    run("decomp/res/hatch_r1691.jww", 4, 147, 1691, 0, 0, 0,
        "the same rectangle, ３線, 線間隔 1:");
    run("decomp/res/hatch_r1692.jww", 4, 6467, 1692, 0, 0, 0,
        "the same rectangle, ┬┴┬, 角度 0・縦 3・横 6:");
    run("decomp/res/hatch_r1692b.jww", 4, 146, 1692, b, 0, 0,
        "the same rectangle, ┬┴┬, 角度 30・縦 20・横 50:");
    run("decomp/res/hatch_base.jww", 4, 48, 1689, 0, 0, 1,
        "the same rectangle, 基点変 to its own corner:");
    run("decomp/res/hatch_base92.jww", 4, 143, 1692, b, 0, 1,
        "and ┬┴┬ counting from that corner:");
    jw_cmd_set(JW_CMD_HATCH);
    jw_cmd_bar((jw_drawing *)app_drawing(), 1692);
    jw_cmd_bar((jw_drawing *)app_drawing(), 1689);
    ck(jw_cmd_box(1419) && !strcmp(jw_cmd_box(1419), "45")
       && jw_cmd_box(1411) && !strcmp(jw_cmd_box(1411), "10"),
       "going back to 1線 brings back 角度 45・ピッチ 10");
    run("decomp/res/hatch_jisun.jww", 4, 49, 1689, j, 1, 0,
        "the same rectangle again, 実寸 with ピッチ 2000 in a 1/200 drawing:");
    run_sel("decomp/res/hatch_sel.jww",
            "範囲選択 over two rectangles at once:");
    pick_case();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
