/* 文字の 連 (1068) -- 連結 and 切断, against the original's own.
 *
 *   tests/mojiren_test.exe
 *
 * The button is not「place one after another」: the status line it puts up
 * is 5473,「文字を指示してください。 連結（L) 移動（LL) 文字切断位置指示
 * (R)」, and once one text is picked, 5474,「連結文字指示 （L)移動
 * （R)複写」.  So it joins two texts, moves one, or cuts one in two.
 *
 * The original was driven five ways (tools/probe64.sh, probe65.sh), each
 * from an empty A-2 sheet with 文字種10 (10 across, 10 tall, 1 apart):
 *
 *   join    AB at view 400,400 and CD at 440,400; 連; (L) on AB, (L) on CD
 *   join2   the same two; (L) on CD, (L) on AB
 *   joinR   the same two; (L) on AB, (R) on CD
 *   cut     ABCD at 400,400; 連; (R) at 417,395
 *   cut2    the same; (R) at 409,395
 *
 * and what came back says the text picked **second** goes in front, the
 * result sits where the **first** one was, (R) copies the second instead
 * of moving it, and a cut takes the character boundary nearest the click.
 *
 * 移動 (LL) is a double click, which the probe cannot post, so nothing is
 * known about it and the port does not do it.
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

/* the original's view: 49 pixels to 30 mm, its paper origin at 554,343 */
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

static void click(int px, int py, int button)
{
    app_press(port_x(sheet_x(px)), port_y(sheet_y(py)), button);
}

static void place(const char *t, int px, int py)
{
    int i;

    for (i = 0; t[i]; i++)
        app_key((unsigned char)t[i]);
    click(px, py, 0);
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

/* every text in a drawing that is not one of the six Printer_... notes */
static int texts_of(jw_drawing *d, const jw_obj **out, int max)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++) {
        const jw_obj *o = &d->obj[i];
        const char *t;
        if (o->cls != JW_MOJI || o->color == 9)
            continue;
        t = jw_str(d, o->text);
        if (t && *t)
            out[n++] = o;
    }
    return n;
}

static void compare(const char *what, jw_drawing *a, jw_drawing *b)
{
    const jw_obj *x[8], *y[8];
    int na = texts_of(a, x, 8), nb = texts_of(b, y, 8), i;
    char msg[200];

    sprintf(msg, "  文字の数 (%d / %d)", nb, na);
    ck(na == nb, msg);
    for (i = 0; i < na && i < nb; i++) {
        const char *ta = jw_str(a, x[i]->text);
        const char *tb = jw_str(b, y[i]->text);
        int ok = ta && tb && !strcmp(ta, tb)
                 && fabs(x[i]->d[0] - y[i]->d[0]) < 1e-6
                 && fabs(x[i]->d[1] - y[i]->d[1]) < 1e-6
                 && fabs(x[i]->d[2] - y[i]->d[2]) < 1e-6
                 && fabs(x[i]->d[3] - y[i]->d[3]) < 1e-6;

        sprintf(msg, "  %d 本目 '%s' (%.4f,%.4f)-(%.4f,%.4f)", i,
                ta ? ta : "?", x[i]->d[0], x[i]->d[1],
                x[i]->d[2], x[i]->d[3]);
        ck(ok, msg);
        if (!ok)
            printf("     移植は '%s' (%.4f,%.4f)-(%.4f,%.4f)\n",
                   tb ? tb : "?", y[i]->d[0], y[i]->d[1],
                   y[i]->d[2], y[i]->d[3]);
    }
    (void)what;
}

int main(void)
{
    static jw_drawing theirs;
    static const struct {
        const char *answer, *what;
        int two;                /* two texts to start with, or one ABCD */
        int c1x, c1y, b1;       /* the first click, and its button */
        int c2x, c2y, b2;       /* and the second, when there is one */
    } RUNS[] = {
        { "decomp/res/mojiren_join.jww",  "連結: AB を先に", 1,
          405, 395, 0, 445, 395, 0 },
        { "decomp/res/mojiren_join2.jww", "連結: CD を先に", 1,
          445, 395, 0, 405, 395, 0 },
        { "decomp/res/mojiren_joinR.jww", "連結の (R) は複写", 1,
          405, 395, 0, 445, 395, 1 },
        { "decomp/res/mojiren_cut.jww",   "切断: 10.41 のところ", 0,
          417, 395, 1, 0, 0, -1 },
        { "decomp/res/mojiren_cut2.jww",  "切断: 5.50 のところ", 0,
          409, 395, 1, 0, 0, -1 },
    };
    unsigned char *b;
    long n;
    int k;

    app_resize(1264, 741);
    for (k = 0; k < (int)(sizeof RUNS / sizeof RUNS[0]); k++) {
        jw_drawing *d;

        printf("-- %s\n", RUNS[k].what);
        b = slurp(RUNS[k].answer, &n);
        if (!b) {
            printf("BAD  %s が読めない\n", RUNS[k].answer);
            fails++;
            continue;
        }
        memset(&theirs, 0, sizeof theirs);
        if (!jw_parse(&theirs, b, n)) {
            printf("BAD  %s が開けない\n", RUNS[k].answer);
            fails++;
            free(b);
            continue;
        }
        free(b);

        app_new();
        d = (jw_drawing *)app_drawing();
        app_command(JW_CMD_MOJI);
        jw_cmd_moji_base(2);
        if (RUNS[k].two) {
            place("AB", 400, 400);
            place("CD", 440, 400);
        } else {
            place("ABCD", 400, 400);
        }
        press_bar(1068);
        ck(jw_cmd_prompt() && *jw_cmd_prompt(), "  連 で状態行が変わる");
        click(RUNS[k].c1x, RUNS[k].c1y, RUNS[k].b1);
        if (RUNS[k].b2 >= 0)
            click(RUNS[k].c2x, RUNS[k].c2y, RUNS[k].b2);
        compare(RUNS[k].what, &theirs, d);
        jw_free(&theirs);
    }
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
