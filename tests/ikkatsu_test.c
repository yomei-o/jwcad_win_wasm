/* 寸法の一括処理 (1072) -- against the original's own two drawings.
 *
 *   tests/ikkatsu_test.exe
 *
 * The original was driven twice with the same drawing and the same
 * clicks but for the height of the last three (tools/probe41.sh and
 * tools/probe42.sh):
 *
 *   cmd:32847            寸法
 *   300,250  300,280     where the extension lines start, where the line goes
 *   r391,343 r464,343    one dimension by hand, which is what wakes 一括処理
 *   btn:1072             一括処理
 *   391,y  717,y  r900,y the 始線, the 終線, and (R) to draw
 *
 * The drawing is tools/mkikkatsu.c -DJW_IKKATSU_BAND: a wall from
 * (-100,0) to (100,0) with nine verticals standing on it, whose tops are
 * at 20, 20, 20, 20, 20, 19, 15, 10 and 0.  With the last three clicks at
 * y=320 the original dimensioned the ones whose tops reach 15, and with
 * them at y=330 the one whose top is at 10 came in as well -- which is
 * exactly the set the segment between the two clicks crosses.
 *
 *   decomp/res/sunikkatsu_band.jww   what it was given
 *   decomp/res/sunikkatsu3.jww       what it drew with the clicks at 320
 *   decomp/res/sunikkatsu4.jww       and with them at 330
 *
 * This drives the port to the same places **on the paper** and puts
 * every piece of dimension it makes beside the original's, in order.
 *
 * Not the same pixels: the original's view is 1108x686 at 76,32 in the
 * frame and the port's own is a couple of pixels off that, so a pixel
 * there and a pixel here are not the same point.  What is the same is
 * the zoom -- 49 pixels to 30 millimetres in both -- so the clicks are
 * written here as the paper points the original's view turns them into
 * (its 0,0 sits at 554.333,343 in its own client rectangle, which the
 * dimension line landing on 38.5714 and the extension lines on 56.9388
 * pin exactly) and turned back into pixels through the port's view.
 *
 * Rounding those back to whole pixels moves the dimension line by up to
 * a third of a millimetre, so the comparison takes every y relative to
 * that line.  Everything else -- every x, and the extension length,
 * which is a flat 30 pixels in both -- is compared as it stands.
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
#include "../src/gen/bars.h"
#include "../src/gen/sunpo.h"
#include "../src/gen/prompts.h"

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

/* One piece of a dimension: what it is, where it is, and what it says. */
typedef struct {
    int cls;
    double d[4];
    char text[64];
} piece_t;

/* Everything in a drawing that carries one of the dimension flags, in the
 * order it was written.  The six Printer_... notes the original saves at
 * the end are on the 補助 pen and carry none of them, so they drop out. */
static int pieces(jw_drawing *d, piece_t *out, int max)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++) {
        const jw_obj *o = &d->obj[i];
        piece_t *p;

        if (o->cls == JW_SEN) {
            if (!(o->flags & JW_SUN_LINE_FLAGS))
                continue;
        } else if (o->cls == JW_TEN) {
            if (!(o->flags & JW_SUN_TEN_FLAGS))
                continue;
        } else if (o->cls == JW_MOJI) {
            if (!(o->flags & JW_SUN_TEXT_FLAGS))
                continue;
        } else {
            continue;
        }
        p = &out[n++];
        p->cls = o->cls;
        p->d[0] = o->d[0];
        p->d[1] = o->d[1];
        p->d[2] = o->cls == JW_TEN ? o->d[0] : o->d[2];
        p->d[3] = o->cls == JW_TEN ? o->d[1] : o->d[3];
        p->text[0] = 0;
        if (o->cls == JW_MOJI) {
            const char *t = jw_str(d, o->text);
            if (t) {
                strncpy(p->text, t, sizeof p->text - 1);
                p->text[sizeof p->text - 1] = 0;
            }
        }
    }
    return n;
}

static const char *clsname(int cls)
{
    return cls == JW_SEN ? "線" : cls == JW_TEN ? "点" : "文字";
}

/* every y taken from the dimension line, which is the first piece */
static void flatten(piece_t *p, int n)
{
    double tl;
    int i;

    if (n <= 0)
        return;
    tl = p[0].d[1];
    for (i = 0; i < n; i++) {
        p[i].d[1] -= tl;
        p[i].d[3] -= tl;
    }
}

static void compare(const piece_t *a, int na, const piece_t *b, int nb)
{
    int i;
    char what[160];

    sprintf(what, "寸法の部品の数が原典と同じ (%d / %d)", nb, na);
    ck(na == nb, what);
    for (i = 0; i < na && i < nb; i++) {
        int ok = a[i].cls == b[i].cls
                 && fabs(a[i].d[0] - b[i].d[0]) < 1e-6
                 && fabs(a[i].d[1] - b[i].d[1]) < 1e-6
                 && fabs(a[i].d[2] - b[i].d[2]) < 1e-6
                 && fabs(a[i].d[3] - b[i].d[3]) < 1e-6
                 && !strcmp(a[i].text, b[i].text);

        sprintf(what, "%2d %-4s (%.4f,%.4f)-(%.4f,%.4f) %s", i,
                clsname(a[i].cls), a[i].d[0], a[i].d[1],
                a[i].d[2], a[i].d[3], a[i].text);
        ck(ok, what);
        if (!ok)
            printf("     移植は %-4s (%.4f,%.4f)-(%.4f,%.4f) %s\n",
                   clsname(b[i].cls), b[i].d[0], b[i].d[1],
                   b[i].d[2], b[i].d[3], b[i].text);
    }
}

static void press_bar(int id)
{
    int i, k;

    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != (unsigned)jw_cmd())
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            int x = c->x + c->w / 2, y = c->y + c->h / 2;
            if (c->id != id || ui_bar_hit(x, y) != id)
                continue;
            app_press(x, y, 0);
            return;
        }
    }
    ck(0, "  その釦がバーに無い");
}

/* One stage of the walk: what the status line says and whether 実行 is
 * alive.  A null `prompt` means only the button is looked at. */
static void step(const char *what, const char *prompt, int jikko)
{
    const jw_drawing *d = (const jw_drawing *)app_drawing();
    const char *p = jw_cmd_prompt();
    char buf[200];

    if (prompt) {
        sprintf(buf, "%s: 状態行", what);
        ck(p && !strcmp(p, prompt), buf);
        if (p && strcmp(p, prompt))
            printf("     [%s]\n", p);
    }
    sprintf(buf, "%s: 実行 は%s", what, jikko ? "有効" : "無効");
    ck(!jw_cmd_bar_enabled(d, 1120) == !jikko, buf);
}

/* What the original's answer holds. */
static int theirs(const char *path, piece_t *out, int max)
{
    unsigned char *b;
    long n;
    int k;

    b = slurp(path, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  %s が開けない\n", path);
        fails++;
        free(b);
        return 0;
    }
    free(b);
    k = pieces((jw_drawing *)app_drawing(), out, max);
    return k;
}

/* The original's view, as its own clicks pin it down. */
#define ORIG_PPM  (49.0 / 30.0)
#define ORIG_CX   554.333
#define ORIG_CY   343.0
static double sheet_x(double px) { return (px - ORIG_CX) / ORIG_PPM; }
static double sheet_y(double py) { return (ORIG_CY - py) / ORIG_PPM; }

/* and the port's pixel for a point on the paper */
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

/* And what the port makes of the same drawing and the same places. */
static int ours(const char *base, int y, int jikko,
                const int (*tog)[2], int ntog,
                int ex0, int ex1, int rb0, int rb1,
                piece_t *out, int max)
{
    unsigned char *b;
    long n;
    int hy;

    b = slurp(base, &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  元の図が開けない\n");
        fails++;
        free(b);
        return 0;
    }
    free(b);
    ck(app_command(JW_CMD_SUNPO) != 0, "  寸法 を出す");
    ck(jw_cmd_bar_enabled((const jw_drawing *)app_drawing(), 1072) == 0,
       "  一括処理 はまだ無効");
    /* the dimension line first, then the extension start a flat 30
       pixels above it, which is what the original's two clicks were */
    hy = port_y(sheet_y(280));
    app_press(port_x(sheet_x(300)), hy - 30, 0);
    app_press(port_x(sheet_x(300)), hy, 0);
    app_press(port_x(sheet_x(391)), port_y(sheet_y(343)), 1);   /* (R) */
    app_press(port_x(sheet_x(464)), port_y(sheet_y(343)), 1);
    ck(jw_cmd_bar_enabled((const jw_drawing *)app_drawing(), 1072) != 0,
       "  寸法を一本引くと有効になる");
    /* 実行 (1120) is alive at exactly one place in the walk.  These five
       are what tools/probe45.sh read off the original's own bar:
       58010f00, 58010f00, 58010f00, 50010f00, 58010f00. */
    step("  寸法を一本引いたところ", 0, 0);
    press_bar(1072);
    step("  一括処理 を押したところ", JW_STR_5391, 0);
    app_press(port_x(sheet_x(ex0)), port_y(sheet_y(y)), rb0);   /* 始線 */
    step("  始線を指示したところ", JW_STR_5392, 0);
    app_press(port_x(sheet_x(ex1)), port_y(sheet_y(y)), rb1);   /* 終線 */
    step("  終線を指示したところ —— ここだけ 実行 が有効", JW_STR_5393, 1);
    {   /* 追加・除外: each (L) here turns its own line over */
        int i;
        for (i = 0; i < ntog; i++) {
            app_press(port_x(sheet_x(tog[i][0])),
                      port_y(sheet_y(tog[i][1])), 0);
            step("  追加・除外 を一つ指示したところ", JW_STR_5393, 1);
        }
    }
    if (jikko) {
        /* 実行 draws the same thing and stays on the third prompt */
        press_bar(1120);
        step("  実行 で描いたところ —— 三つ目の問いのまま", JW_STR_5393, 1);
    } else {
        app_press(port_x(sheet_x(900)), port_y(sheet_y(y)), 1); /* (R) */
        step("  (R) で確定したところ —— 始線の問いに戻る", JW_STR_5391, 0);
    }
    return pieces((jw_drawing *)app_drawing(), out, max);
}

/* The four runs the original was put through. */
/* the 追加・除外 clicks, in the original's own view coordinates: x=70 is
   at 669 and x=-70 at 440, and sheet y=-12 is at 363 */
static const int TOG_ADD[1][2]  = { { 669, 363 } };
static const int TOG_DROP[1][2] = { { 440, 363 } };
static const int TOG_BOTH[2][2] = { { 669, 363 }, { 440, 363 } };

/* the 始線・終線 clicks: where, and with which button.  (R) there is
   同一線種選択, so the two that use it name a line of the type wanted --
   x=-100 (px 391) and x=100 (px 717) are 実線, x=-70 (440) and x=10
   (571) are 点線1. */
#define LL 391, 717, 0, 0

static const struct {
    const char *base, *answer, *what;
    int y, jikko, ntog;
    const int (*tog)[2];
    int ex0, ex1, rb0, rb1;
} RUNS[] = {
    { "decomp/res/sunikkatsu_base.jww", "decomp/res/sunikkatsu.jww",
      "縦五本を素直に (probe39)", 320, 0, 0, 0, LL },
    { "decomp/res/sunikkatsu2_base.jww", "decomp/res/sunikkatsu2.jww",
      "斜めの線と、届かない短い縦線 (probe40)", 320, 0, 0, 0, LL },
    { "decomp/res/sunikkatsu_band.jww", "decomp/res/sunikkatsu3.jww",
      "天端 20/19/15/10/0 を y=320 で (probe41)", 320, 0, 0, 0, LL },
    { "decomp/res/sunikkatsu_band.jww", "decomp/res/sunikkatsu4.jww",
      "同じ図を y=330 で —— 天端 10 の一本も入る (probe42)", 330, 0, 0, 0, LL },
    { "decomp/res/sunikkatsu_band.jww", "decomp/res/sunikkatsu5.jww",
      "(R) の代わりに 実行 を押して (probe46)", 330, 1, 0, 0, LL },
    { "decomp/res/sunikkatsu_band.jww", "decomp/res/sunikkatsu6.jww",
      "追加: 拾われない x=70 を指示すると入る (probe50)",
      330, 0, 1, TOG_ADD, LL },
    { "decomp/res/sunikkatsu_band.jww", "decomp/res/sunikkatsu7.jww",
      "除外: 拾われている x=-70 を指示すると抜ける (probe50)",
      330, 0, 1, TOG_DROP, LL },
    { "decomp/res/sunikkatsu_band.jww", "decomp/res/sunikkatsu8.jww",
      "両方いっぺんに (probe50)", 330, 0, 2, TOG_BOTH, LL },
    { "decomp/res/sunikkatsu_types.jww", "decomp/res/sunikkatsu12.jww",
      "線種混じりの図を素直に (probe55)", 330, 0, 0, 0, LL },
    { "decomp/res/sunikkatsu_types.jww", "decomp/res/sunikkatsu9.jww",
      "同一線種選択: 両端とも実線を (R) で (probe55)",
      330, 0, 0, 0, 391, 717, 1, 1 },
    { "decomp/res/sunikkatsu_types.jww", "decomp/res/sunikkatsu10.jww",
      "同一線種選択: 両端とも点線を (R) で (probe55)",
      330, 0, 0, 0, 440, 571, 1, 1 },
    { "decomp/res/sunikkatsu_types.jww", "decomp/res/sunikkatsu11.jww",
      "始線は (L)、終線だけ (R) —— 一度で効く (probe55)",
      330, 0, 0, 0, 391, 717, 0, 1 },
};

int main(void)
{
    static piece_t a[256], b[256];
    int na, nb, k;

    app_resize(1264, 741);

    for (k = 0; k < (int)(sizeof RUNS / sizeof RUNS[0]); k++) {
        printf("-- %s\n", RUNS[k].what);
        na = theirs(RUNS[k].answer, a, 256);
        nb = ours(RUNS[k].base, RUNS[k].y, RUNS[k].jikko,
                  RUNS[k].tog, RUNS[k].ntog,
                  RUNS[k].ex0, RUNS[k].ex1, RUNS[k].rb0, RUNS[k].rb1,
                  b, 256);
        flatten(a, na);
        flatten(b, nb);
        compare(a, na, b, nb);
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
