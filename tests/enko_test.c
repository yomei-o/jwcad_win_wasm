/* 円弧 (32773) -- against the original's own circles.
 *
 *   tests/enko_test.exe
 *
 * The command was in the port from early on and had never once been held
 * against a circle the original drew.  Everything that uses circles had
 * been -- 接線, 接円, 曲線, ハッチ, the arc rasteriser against GDI -- but
 * not the command itself and not its command bar.
 *
 * So the original was driven (tools/probe57.sh), eight ways, each from
 * an empty A-2 sheet with the same two or three clicks:
 *
 *   en_plain   centre and a point on it
 *   en_arc     円弧 (1318) ticked: centre, start, end
 *   en_3p      ３点指示 (1321): three points on the circle
 *   en_flat    扁平率 (1412) 0.5
 *   en_tilt    扁平率 0.5 and 傾き (1413) 30
 *   en_r50     半径 (1411) 50 typed, so one click does it
 *   en_multi   多重円 (1417) 3
 *   en_afl     円弧 and 扁平率 0.5 together
 *
 * and five more arcs from tools/probe59.sh, which settled two things the
 * first eight could not:
 *
 *   扁平率 takes either form.  0.5, 50 and 200 for the same drag gave
 *   the ratio 0.5, 0.5 and 2 -- over one it is a percentage, at or under
 *   it the ratio itself.
 *
 *   **Which way an 円弧 goes round is the original's own mouse.**  Of the
 *   five arcs asked for, three came back swept the shorter way and two
 *   came back as the same arc a whole turn the other way.  The original
 *   watches the pointer while it waits for the third click; a posted
 *   click hands it one jump and no path.  So the sweep is compared here
 *   **modulo a whole turn** -- the arc is the same either way and the
 *   number is not something the port can be held to.
 *
 * 半円 (1320) wants **three** clicks, not two, which is why the first go
 * at it drew nothing.  tools/probe60.sh read its prompts:
 *
 *   1. １点目の位置を指示してください
 *   2. ○　２点目の位置を指示してください
 *   3. 　　　　◆　　　　円弧の方向を指示してください。　r = 6,845.106
 *
 * -- two points fix the diameter, and by the third the radius is already
 * known, so that one only says which way the half bulges.
 *
 * What is compared is the 円弧 element itself: centre, radius, start
 * angle, sweep, tilt and flatness, which is everything a CDataEnko has.
 * The port cannot land on the original's own clicks to the last decimal
 * -- a pixel is six tenths of a millimetre on that sheet -- but it is
 * driven to the same **paper points** through its own view, so what is
 * left is only the rounding of a pixel.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/jww.h"
#include "../src/view.h"

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

/* The original's view: 49 pixels to 30 millimetres, the paper origin at
   554.333, 343 in its own client rectangle (tests/ikkatsu_test.c has how
   that was pinned down). */
#define ORIG_PPM (49.0 / 30.0)
static double sheet_x(double px) { return (px - 554.0) / ORIG_PPM; }
static double sheet_y(double py) { return (343.0 - py) / ORIG_PPM; }

static int port_x(double mm)
{
    const jw_view *v = app_view();
    return v->bx + (int)floor((mm - v->ox) / v->mmpp + 0.5);
}

static int port_y(double mm)
{
    const jw_view *v = app_view();
    return v->by - (int)floor((mm - v->oy) / v->mmpp + 0.5);
}

static void click(int px, int py)
{
    app_press(port_x(sheet_x(px)), port_y(sheet_y(py)), 0);
}

static void press_bar(int id)
{
    jw_cmd_bar((jw_drawing *)app_drawing(), id);
}

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (i = 0; s[i]; i++)
        jw_cmd_box_key((unsigned char)s[i]);
    jw_cmd_box_key(13);
}

/* every 円弧 in a drawing, in order */
static int arcs_of(jw_drawing *d, const jw_obj **out, int max)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++)
        if (d->obj[i].cls == JW_ENKO)
            out[n++] = &d->obj[i];
    return n;
}

static const char *FIELD[7] = {
    "中心 x", "中心 y", "半径", "開始角", "回り", "傾き", "扁平率"
};

static void compare(const char *what, jw_drawing *a, jw_drawing *b)
{
    const jw_obj *x[8], *y[8];
    int na = arcs_of(a, x, 8), nb = arcs_of(b, y, 8), i, k;
    char msg[160];

    sprintf(msg, "%s: 円弧の数 (%d / %d)", what, nb, na);
    ck(na == nb && na > 0, msg);
    for (i = 0; i < na && i < nb; i++) {
        sprintf(msg, "  %d 本目は同じ向き（全円か弧か）", i);
        ck(x[i]->n == y[i]->n, msg);
        for (k = 0; k < 7; k++) {
            /* the angles are radians, the rest millimetres of paper; a
               pixel is 0.612 mm, so half of one is the room a click has */
            double tol = k == 3 || k == 4 || k == 5 ? 6e-3 : 0.35;
            double e = x[i]->d[k] - y[i]->d[k];
            int ok;

            if (k == 4) {       /* the sweep, modulo a whole turn */
                while (e > PI)
                    e -= 2.0 * PI;
                while (e <= -PI)
                    e += 2.0 * PI;
            }
            ok = fabs(e) <= tol;

            sprintf(msg, "  %d 本目の%s (%.4f / %.4f)%s", i, FIELD[k],
                    y[i]->d[k], x[i]->d[k], k == 4 ? " 一周の剰余で" : "");
            ck(ok, msg);
        }
    }
}

typedef struct {
    const char *answer, *what;
    int check, ntick;           /* a bar checkbox to tick */
    const char *box[3][2];      /* boxes to type into */
    int click[3][2];            /* and the clicks, in the original's view */
    int nclick;
} run_t;

static const run_t RUNS[] = {
    { "decomp/res/enko_plain.jww", "素の円", 0, 0, {{0,0}},
      {{300,300},{500,400}}, 2 },
    { "decomp/res/enko_arc.jww", "円弧 (1318)", 1318, 1, {{0,0}},
      {{300,300},{500,400},{500,200}}, 3 },
    { "decomp/res/enko_3p.jww", "３点指示 (1321)", 1321, 1, {{0,0}},
      {{300,300},{500,400},{400,200}}, 3 },
    { "decomp/res/enko_flat.jww", "扁平率 0.5", 0, 0, {{"1412","0.5"}},
      {{300,300},{500,400}}, 2 },
    { "decomp/res/enko_tilt.jww", "扁平率 0.5 と 傾き 30", 0, 0,
      {{"1412","0.5"},{"1413","30"}}, {{300,300},{500,400}}, 2 },
    { "decomp/res/enko_r50.jww", "半径 50", 0, 0, {{"1411","50"}},
      {{300,300}}, 1 },
    { "decomp/res/enko_multi.jww", "多重円 3", 0, 0, {{"1417","3"}},
      {{300,300},{500,400}}, 2 },
    { "decomp/res/enko_afl.jww", "円弧と扁平率 0.5", 1318, 1,
      {{"1412","0.5"}}, {{300,300},{500,400},{500,200}}, 3 },
    { "decomp/res/enko_arc_b.jww", "円弧、終点をすぐ隣に", 1318, 1, {{0,0}},
      {{300,300},{500,400},{496,340}}, 3 },
    { "decomp/res/enko_arc_c.jww", "円弧、終点を左下に", 1318, 1, {{0,0}},
      {{300,300},{500,400},{217,482}}, 3 },
    { "decomp/res/enko_fl50.jww", "扁平率 50 —— 0.5 と同じ", 0, 0,
      {{"1412","50"}}, {{300,300},{500,400}}, 2 },
    { "decomp/res/enko_fl200.jww", "扁平率 200 —— 縦長の 2", 0, 0,
      {{"1412","200"}}, {{300,300},{500,400}}, 2 },
    { "decomp/res/enko_afl2.jww", "円弧と扁平率、終点を左下に", 1318, 1,
      {{"1412","0.5"}}, {{300,300},{500,400},{217,482}}, 3 },
    { "decomp/res/enko_half.jww", "半円 (1320) —— 三クリック", 1320, 1,
      {{0,0}}, {{300,300},{500,400},{500,200}}, 3 },
};

int main(void)
{
    static jw_drawing theirs;
    unsigned char *b;
    long n;
    int k;

    app_resize(1264, 741);
    for (k = 0; k < (int)(sizeof RUNS / sizeof RUNS[0]); k++) {
        const run_t *r = &RUNS[k];
        int i;

        printf("-- %s\n", r->what);
        b = slurp(r->answer, &n);
        if (!b) {
            printf("BAD  %s が読めない\n", r->answer);
            fails++;
            continue;
        }
        memset(&theirs, 0, sizeof theirs);
        if (!jw_parse(&theirs, b, n)) {
            printf("BAD  %s が開けない\n", r->answer);
            fails++;
            free(b);
            continue;
        }
        free(b);

        app_new();
        app_command(JW_CMD_ENKO);
        /* the boxes and the ticks are the command's own state and
           outlive a new drawing, just as they do in the original -- every
           run of tools/probe57.sh started Jw_cad afresh, so each run here
           starts by putting them back the way they come up */
        {
            static const int TICK[3] = { 1318, 1320, 1321 };
            int t;
            for (t = 0; t < 3; t++)
                if (jw_cmd_bar_check(TICK[t]) > 0)
                    press_bar(TICK[t]);
        }
        type_box(1411, "");
        type_box(1412, "");
        type_box(1413, "");
        type_box(1417, "");
        if (r->ntick && jw_cmd_bar_check(r->check) <= 0)
            press_bar(r->check);
        for (i = 0; i < 3 && r->box[i][0]; i++)
            type_box(atoi(r->box[i][0]), r->box[i][1]);
        for (i = 0; i < r->nclick; i++)
            click(r->click[i][0], r->click[i][1]);
        compare(r->what, &theirs, (jw_drawing *)app_drawing());
        jw_free(&theirs);
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
