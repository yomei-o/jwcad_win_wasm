/* 文字 (32806) -- against the text the original placed.
 *
 *   tests/mojidraw_test.exe
 *
 * tests/moji_test.c is about the 書込み文字種変更 dialog.  The command
 * itself -- type something, click, and a text lands -- had never been
 * held against one the original wrote, any more than 円弧 had.
 *
 * So the original was driven from an empty A-2 sheet (tools/probe57.sh),
 * typing ABC into its box and clicking once at view (400,400):
 *
 *   mo_plain  as the bar comes up
 *   mo_ang    角度 (1411) 30
 *   mo_tate   縦字 (1325) ticked
 *
 * and 基点 (1064) is left out: pressing it puts a modal window up, which
 * the probe cannot walk past, so nothing is known about it yet.
 *
 * What is compared is the text element: where it starts, where its run
 * ends, the size and spacing, the 文字種, the flags and the string.
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

/* The original's view: 49 pixels to 30 millimetres, its paper origin at
   554, 343 in its own client rectangle.  Both numbers come from free
   clicks the original then wrote down -- a 寸法線 asked for at py 280
   landed on 38.5714 and a circle centred at px 300 landed on -155.51. */
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

/* the first text in a drawing that is not one of the six Printer_... notes
   the original saves on the 補助 pen */
static const jw_obj *text_of(jw_drawing *d)
{
    int i;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        const char *t;
        if (o->cls != JW_MOJI || o->color == 9)
            continue;
        t = jw_str(d, o->text);
        if (t && *t)
            return o;
    }
    return 0;
}

static void cknear(double got, double want, double tol, const char *what)
{
    int ok = fabs(got - want) <= tol;

    printf("%-4s %s (%.4f / %.4f)\n", ok ? "ok" : "BAD", what, got, want);
    if (!ok)
        fails++;
}

typedef struct {
    const char *answer, *what;
    int tick;                   /* a checkbox to put on */
    const char *box, *val;      /* and a box to type into */
} run_t;

static const run_t RUNS[] = {
    { "decomp/res/moji_plain.jww", "素の文字", 0, 0, 0 },
    { "decomp/res/moji_ang.jww",   "角度 30",  0, "1411", "30" },
    { "decomp/res/moji_tate.jww",  "縦字",     1325, 0, 0 },
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
        const jw_obj *a, *c;
        jw_drawing *ours;

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
        app_command(JW_CMD_MOJI);
        /* the bar is the command's own state and outlives a new drawing,
           and every run of the probe started the original afresh */
        {
            static const int TICK[3] = { 1323, 1324, 1325 };
            int t;
            for (t = 0; t < 3; t++)
                if (jw_cmd_bar_check(TICK[t]) > 0)
                    jw_cmd_bar((jw_drawing *)app_drawing(), TICK[t]);
        }
        type_box(1411, "");
        if (r->tick && jw_cmd_bar_check(r->tick) <= 0)
            jw_cmd_bar((jw_drawing *)app_drawing(), r->tick);
        if (r->box)
            type_box(atoi(r->box), r->val);
        app_key('A');
        app_key('B');
        app_key('C');
        app_press(port_x(sheet_x(400)), port_y(sheet_y(400)), 0);

        ours = (jw_drawing *)app_drawing();
        a = text_of(&theirs);
        c = text_of(ours);
        ck(a != 0, "  原典の図に文字がある");
        ck(c != 0, "  移植も文字を置く");
        if (a && c) {
            const char *ta = jw_str(&theirs, a->text);
            const char *tc = jw_str(ours, c->text);

            ck(ta && tc && !strcmp(ta, tc), "  中身が同じ");
            /* a pixel is 0.612 mm on that sheet, so half of one is the
               room the click has; the run itself is arithmetic */
            cknear(c->d[0], a->d[0], 0.35, "  始点の x");
            cknear(c->d[1], a->d[1], 0.35, "  始点の y");
            cknear(c->d[2] - c->d[0], a->d[2] - a->d[0], 1e-6, "  走りの x");
            cknear(c->d[3] - c->d[1], a->d[3] - a->d[1], 1e-6, "  走りの y");
            cknear(c->d[4], a->d[4], 1e-9, "  文字の幅");
            cknear(c->d[5], a->d[5], 1e-9, "  文字の高さ");
            cknear(c->d[6], a->d[6], 1e-9, "  字間");
            ck(c->n == a->n, "  文字種");
            ck(c->color == a->color, "  ペン");
            ck((c->flags & 0x20u) == (a->flags & 0x20u), "  縦字の印");
        }
        jw_free(&theirs);
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
