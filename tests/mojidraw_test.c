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
 * and then all nine 基点 (tools/probe62.sh), which needed the dialog the
 * button puts up to be walked -- `dlgin:b1064,<radio>=!` presses one of
 * its 3x3 and then OK.  The radios are 1689..1697 in the order 左上 左中
 * 左下 中上 中中 中下 右上 右中 右下, and 左下 is the one it comes up on.
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
    int tick2;                  /* a second one, for 垂直 + 縦字 */
    const char *box, *val;      /* and a box to type into */
    int base;                   /* 基点 0..8, or -1 to leave it alone */
    int zure;                   /* ずれ使用, and the pair that goes with
                                   the cell: 横 then 縦 */
    double zx, zy;
} run_t;

static const run_t RUNS[] = {
    { "decomp/res/moji_plain.jww", "素の文字", 0, 0, 0, 0, -1, 0, 0, 0 },
    { "decomp/res/moji_ang.jww", "角度 30", 0, 0, "1411", "30", -1, 0, 0, 0 },
    { "decomp/res/moji_tate.jww", "縦字", 1325, 0, 0, 0, -1, 0, 0, 0 },
    /* 垂直 (1324) lays the run a quarter turn **up** -- and with
       縦字 as well it lays it **down** instead, which is the way
       縦書き reads (tools/probe95.sh) */
    { "decomp/res/moji_vert.jww", "垂直", 1324, 0, 0, 0, -1, 0, 0, 0 },
    { "decomp/res/moji_vert_tate.jww", "垂直＋縦字",
      1324, 1325, 0, 0, -1, 0, 0, 0 },
    { "decomp/res/moji_k0.jww", "基点 左上", 0, 0, 0, 0, 0, 0, 0, 0 },
    { "decomp/res/moji_k1.jww", "基点 左中", 0, 0, 0, 0, 1, 0, 0, 0 },
    { "decomp/res/moji_k2.jww", "基点 左下", 0, 0, 0, 0, 2, 0, 0, 0 },
    { "decomp/res/moji_k3.jww", "基点 中上", 0, 0, 0, 0, 3, 0, 0, 0 },
    { "decomp/res/moji_k4.jww", "基点 中中", 0, 0, 0, 0, 4, 0, 0, 0 },
    { "decomp/res/moji_k5.jww", "基点 中下", 0, 0, 0, 0, 5, 0, 0, 0 },
    { "decomp/res/moji_k6.jww", "基点 右上", 0, 0, 0, 0, 6, 0, 0, 0 },
    { "decomp/res/moji_k7.jww", "基点 右中", 0, 0, 0, 0, 7, 0, 0, 0 },
    { "decomp/res/moji_k8.jww", "基点 右下", 0, 0, 0, 0, 8, 0, 0, 0 },
    { "decomp/res/moji_zure_lt.jww", "左上に ずれ 横5 縦3",
      0, 0, 0, 0, 0, 1, 5, 3 },
    { "decomp/res/moji_zure_rb.jww", "右下に ずれ 横7 縦2",
      0, 0, 0, 0, 8, 1, 7, 2 },
    { "decomp/res/moji_zure_off.jww", "ずれ使用を入れないと効かない",
      0, 0, 0, 0, 0, 0, 5, 3 },
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
        jw_cmd_moji_base(r->base >= 0 ? r->base : 2);
        jw_cmd_moji_zure(r->zure);
        {
            int t;
            for (t = 0; t < 3; t++) {
                jw_cmd_moji_zure_at(1, t, 0.0);
                jw_cmd_moji_zure_at(0, t, 0.0);
            }
        }
        if (r->zx != 0.0 || r->zy != 0.0) {
            int col = (r->base >= 0 ? r->base : 2) / 3;
            int row = (r->base >= 0 ? r->base : 2) % 3;
            jw_cmd_moji_zure_at(1, col, r->zx);
            jw_cmd_moji_zure_at(0, row, r->zy);
        }
        if (r->tick && jw_cmd_bar_check(r->tick) <= 0)
            jw_cmd_bar((jw_drawing *)app_drawing(), r->tick);
        if (r->tick2 && jw_cmd_bar_check(r->tick2) <= 0)
            jw_cmd_bar((jw_drawing *)app_drawing(), r->tick2);
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
    /* 文読 (1069): a file's lines, 行間 apart -- and 行間 is **twice** the
       box, in millimetres of paper, whatever the characters measure.  The
       original read the same two line file six ways (tools/probe67.sh ..
       probe69.sh): empty, 5, 20 and 40 at 文字種10 gave steps of 10, 10,
       40 and 80, and empty and 20 at 文字種4 gave 10 and 40. */
    {
        static const struct { const char *answer, *what, *gyou; } Y[] = {
            { "decomp/res/moji_yomi0.jww",  "文読、行間なし", "" },
            { "decomp/res/moji_yomi20.jww", "文読、行間 20", "20" },
            { "decomp/res/moji_yomi5.jww",  "文読、行間 5",  "5" },
            { "decomp/res/moji_yomi40.jww", "文読、行間 40", "40" },
        };
        static const unsigned char FILE2[] = "ABC\r\nDEF\r\n";
        int k;

        for (k = 0; k < (int)(sizeof Y / sizeof Y[0]); k++) {
            const jw_obj *a, *c;
            jw_drawing *ours;
            int i, na = 0, nc = 0;
            const jw_obj *ta[4], *tc[4];

            printf("-- %s\n", Y[k].what);
            b = slurp(Y[k].answer, &n);
            if (!b) {
                printf("BAD  %s が読めない\n", Y[k].answer);
                fails++;
                continue;
            }
            memset(&theirs, 0, sizeof theirs);
            if (!jw_parse(&theirs, b, n)) {
                printf("BAD  %s が開けない\n", Y[k].answer);
                fails++;
                free(b);
                continue;
            }
            free(b);
            app_new();
            ours = (jw_drawing *)app_drawing();
            app_command(JW_CMD_MOJI);
            jw_cmd_moji_base(2);
            jw_cmd_moji_zure(0);
            type_box(1411, "");
            type_box(1418, Y[k].gyou);
            ck(jw_cmd_text_load(ours, FILE2, (long)sizeof FILE2 - 1) != 0,
               "  文書が読める");
            app_press(port_x(sheet_x(400)), port_y(sheet_y(400)), 0);
            for (i = 0; i < theirs.ndrawn && na < 4; i++)
                if (theirs.obj[i].cls == JW_MOJI && theirs.obj[i].color != 9)
                    ta[na++] = &theirs.obj[i];
            for (i = 0; i < ours->ndrawn && nc < 4; i++)
                if (ours->obj[i].cls == JW_MOJI && ours->obj[i].color != 9)
                    tc[nc++] = &ours->obj[i];
            ck(na == 2 && nc == na, "  二行とも置かれる");
            for (i = 0; i < na && i < nc; i++) {
                char msg[160];
                a = ta[i];
                c = tc[i];
                sprintf(msg, "  %d 行目 (%.4f,%.4f)", i, a->d[0], a->d[1]);
                ck(fabs(a->d[0] - c->d[0]) < 0.35
                   && fabs(a->d[1] - c->d[1]) < 0.35
                   && !strcmp(jw_str(&theirs, a->text), jw_str(ours, c->text)),
                   msg);
                if (fabs(a->d[1] - c->d[1]) >= 0.35)
                    printf("     移植は (%.4f,%.4f)\n", c->d[0], c->d[1]);
            }
            jw_free(&theirs);
        }
    }

    /* 下線作図 (1327)・上線作図 (1328)・左右縦線 (1329): the lines the
       dialog rules round a text (tools/probe71.sh).  下線 runs along the
       baseline end to end, 上線 the character height across from it, and
       左右縦線 is two up from the ends -- and with all three on they come
       out 下・上・左・右 and then the text, on the writing pen. */
    {
        static const struct {
            const char *answer, *what;
            int a, b2, c;
        } R[] = {
            { "decomp/res/moji_under.jww", "下線作図", 1, 0, 0 },
            { "decomp/res/moji_over.jww",  "上線作図", 0, 1, 0 },
            { "decomp/res/moji_side.jww",  "左右縦線", 0, 0, 1 },
            { "decomp/res/moji_rule3.jww", "三つとも", 1, 1, 1 },
        };
        int k;

        for (k = 0; k < (int)(sizeof R / sizeof R[0]); k++) {
            jw_drawing *ours;
            const jw_obj *la[4], *lc[4];
            int i, na = 0, nc = 0;

            printf("-- %s\n", R[k].what);
            b = slurp(R[k].answer, &n);
            if (!b) {
                printf("BAD  %s が読めない\n", R[k].answer);
                fails++;
                continue;
            }
            memset(&theirs, 0, sizeof theirs);
            if (!jw_parse(&theirs, b, n)) {
                printf("BAD  %s が開けない\n", R[k].answer);
                fails++;
                free(b);
                continue;
            }
            free(b);
            app_new();
            ours = (jw_drawing *)app_drawing();
            app_command(JW_CMD_MOJI);
            jw_cmd_moji_base(2);
            jw_cmd_moji_zure(0);
            type_box(1411, "");
            type_box(1418, "");
            jw_cmd_moji_rule(1327, R[k].a);
            jw_cmd_moji_rule(1328, R[k].b2);
            jw_cmd_moji_rule(1329, R[k].c);
            app_key('A');
            app_key('B');
            app_key('C');
            app_press(port_x(sheet_x(400)), port_y(sheet_y(400)), 0);
            jw_cmd_moji_rule(1327, 0);
            jw_cmd_moji_rule(1328, 0);
            jw_cmd_moji_rule(1329, 0);
            for (i = 0; i < theirs.ndrawn && na < 4; i++)
                if (theirs.obj[i].cls == JW_SEN)
                    la[na++] = &theirs.obj[i];
            for (i = 0; i < ours->ndrawn && nc < 4; i++)
                if (ours->obj[i].cls == JW_SEN)
                    lc[nc++] = &ours->obj[i];
            ck(na == nc, "  線の数が同じ");
            for (i = 0; i < na && i < nc; i++) {
                char msg[160];
                int ok = fabs(la[i]->d[0] - lc[i]->d[0]) < 1e-6
                         && fabs(la[i]->d[1] - lc[i]->d[1]) < 1e-6
                         && fabs(la[i]->d[2] - lc[i]->d[2]) < 1e-6
                         && fabs(la[i]->d[3] - lc[i]->d[3]) < 1e-6
                         && la[i]->color == lc[i]->color;

                sprintf(msg, "  %d 本目 (%.4f,%.4f)-(%.4f,%.4f)", i,
                        la[i]->d[0], la[i]->d[1], la[i]->d[2], la[i]->d[3]);
                ck(ok, msg);
                if (!ok)
                    printf("     移植は (%.4f,%.4f)-(%.4f,%.4f)\n",
                           lc[i]->d[0], lc[i]->d[1], lc[i]->d[2], lc[i]->d[3]);
            }
            jw_free(&theirs);
        }
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
