/* A two-storey house plan, made the way a person would: only the commands, the
   clicks and the keys the page sends -- walls, partitions, doors by 建具,
   dimensions, room names in Japanese, hatching, two layer groups -- and then
   printed.  The finished drawing is tests/data/house2f.jww; run with --make to
   write it, without to build it again and check it against that file's counts.
     tests/house_test.exe [--make]                                              */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cp932.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/plot.h"
#include "../src/tategu.h"
#include "../src/ui.h"
#include "../src/view.h"

static int fails, verbose = 1;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int count(int cls)
{
    int i, k = 0;
    const jw_drawing *d = app_drawing();

    for (i = 0; i < d->ndrawn; i++)
        k += d->obj[i].cls == cls;
    return k;
}

/* paper millimetres (what the plan is drawn in, at 1/100) to the pixel the page would send */
static void px(double mx, double my, int *x, int *y)
{
    const jw_view *v = app_view();

    *x = (int)floor(v->bx + (mx - v->ox) * v->scale + 0.5);
    *y = (int)floor(v->by - (my - v->oy) * v->scale + 0.5);
}

/* what the status line says now, as UTF-8 */
static void prompt(const char *tag)
{
    const char *p = jw_cmd_prompt();
    unsigned short w[400];
    long n = p ? jw_to_utf16(p, (long)strlen(p), w, 400) : 0, i;
    unsigned char o[1300];
    long k = 0;

    for (i = 0; i < n; i++) {
        unsigned c = w[i];

        if (c < 0x80)
            o[k++] = (unsigned char)c;
        else if (c < 0x800) {
            o[k++] = (unsigned char)(0xc0 | (c >> 6));
            o[k++] = (unsigned char)(0x80 | (c & 63));
        } else {
            o[k++] = (unsigned char)(0xe0 | (c >> 12));
            o[k++] = (unsigned char)(0x80 | ((c >> 6) & 63));
            o[k++] = (unsigned char)(0x80 | (c & 63));
        }
    }
    o[k] = 0;
    printf("     [%s] %s\n", tag, o);
}

static void click(double mx, double my, int button)
{
    int x, y;

    px(mx, my, &x, &y);
    app_move(x, y);
    app_press(x, y, button);
}

static void rect(double x0, double y0, double x1, double y1)
{
    app_command(JW_CMD_KUKEI);
    click(x0, y0, 0);
    click(x1, y1, 0);
}

static void line(double x0, double y0, double x1, double y1)
{
    app_command(JW_CMD_SEN);
    click(x0, y0, 0);
    click(x1, y1, 0);
}

static void say(double x, double y, const unsigned short *s)
{
    app_command(32806);
    for (; *s; s++) {
        unsigned short u = *s;
        char buf[4];
        long m = jw_from_utf16(&u, 1, buf, sizeof buf), i;

        for (i = 0; i < m; i++)
            app_key((unsigned char)buf[i]);
    }
    click(x, y, 0);
    app_key(27);
}

static void floor_plan(double ox, double oy, double w, double h, int storey)
{
    static const unsigned short ldk[] = { 0x30ea, 0x30d3, 0x30f3, 0x30b0, 0 };     /* リビング */
    static const unsigned short kit[] = { 0x53f0, 0x6240, 0 };                      /* 台所 */
    static const unsigned short rm[] = { 0x6d0b, 0x5ba4, 0 };                       /* 洋室 */
    static const unsigned short ent[] = { 0x7384, 0x95a2, 0 };                      /* 玄関 */
    double t = 1.5;                                                                  /* 150 mm walls */

    /* outer wall: two rectangles */
    rect(ox, oy, ox + w, oy + h);
    rect(ox + t, oy + t, ox + w - t, oy + h - t);
    /* partitions */
    line(ox + w * 0.5, oy + t, ox + w * 0.5, oy + h * 0.55);
    line(ox + t, oy + h * 0.55, ox + w * 0.75, oy + h * 0.55);
    line(ox + w * 0.75, oy + h * 0.55, ox + w * 0.75, oy + h - t);
    if (storey == 1) {
        say(ox + 10, oy + 15, ldk);
        say(ox + w * 0.55, oy + 15, kit);
        say(ox + 10, oy + h * 0.7, rm);
        say(ox + w * 0.8, oy + h * 0.7, ent);
    } else {
        say(ox + 10, oy + 15, rm);
        say(ox + w * 0.55, oy + 15, rm);
        say(ox + 10, oy + h * 0.7, rm);
    }
}

/* a right click on the group's cell of the layer-group grid makes it the one written to */
static void write_layer_group(int g)
{
    const fb_t *fb = app_fb();
    int x, y, n, hit;

    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++) {
            hit = ui_layer_hit(fb->w, x, y, &n);
            if (hit == 1 && n == g) {
                app_press(x, y, 1);
                return;
            }
        }
    printf("BAD  no cell for layer group %d\n", g);
    fails++;
}

int main(int argc, char **argv)
{
    int make = argc > 1 && !strcmp(argv[1], "--make");
    unsigned char *out = 0;
    long n = 0;
    int lines1, texts1;

    (void)verbose;
    app_resize(1264, 741);
    app_new();
    app_command(32822);                 /* A-2 */
    app_fit();
    {
        const jw_view *v = app_view();
        printf("     view: %.3f px/mm, origin %.1f,%.1f\n", v->scale, v->ox, v->oy);
    }
    /* ground floor on layer group 0 */
    floor_plan(-100, -60, 91, 72.8, 1);
    lines1 = count(JW_SEN);
    texts1 = count(JW_MOJI);
    printf("     ground floor: %d lines, %d texts\n", lines1, texts1);
    ck(lines1 >= 11, "walls and partitions are drawn (rectangles are four lines each)");
    ck(texts1 == 4, "four room names");

    /* a door by 建具 */
    {
        int before = app_drawing()->ndrawn;

        app_command(32848);
        app_paint();                    /* the picker comes up as the page paints */
        prompt("建具");
        app_key(9);                     /* Tab: the next catalogue file ... */
        app_key(9);
        app_key(9);
        app_key(9);                     /* ... round to the first again */
        app_key('1');                   /* 1: the first fitting on the page, as a click on it */
        prompt("建具 chosen");
        click(-100 + 20, -60 + 0.75, 0);
        click(-100 + 20, -60 + 0.75, 0);
        printf("     建具: %d -> %d elements\n", before, app_drawing()->ndrawn);
        ck(app_drawing()->ndrawn > before, "a fitting is placed in the wall");
    }

    /* an outer dimension */
    {
        int before = app_drawing()->ndrawn;

        app_command(JW_CMD_SUNPO);
        prompt("寸法 0");
        click(-100 + 45, -60 - 8, 0);       /* where the dimension line goes (the first prompt calls it 引出し線の始点) */
        prompt("寸法 a");
        click(-100 + 45, -60 - 8, 0);
        prompt("寸法 b");
        click(-100, -60, 0);
        prompt("寸法 1");
        click(-100 + 91, -60, 0);
        prompt("寸法 2");
        app_key(13);
        prompt("寸法 done");
        printf("     寸法: %d -> %d elements\n", before, app_drawing()->ndrawn);
        ck(app_drawing()->ndrawn > before, "a dimension is drawn");
    }

    /* hatching: the entrance's tiled floor, a small closed room of its own */
    {
        int before;
        double ex = -100 + 91 * 0.75 + 2, ey = -60 + 72.8 * 0.55 + 4, ew = 91 * 0.25 - 5, eh = 12;

        rect(ex, ey, ex + ew, ey + eh);
        before = app_drawing()->ndrawn;
        app_command(JW_CMD_HATCH);
        prompt("ハッチ");
        click(ex + ew / 2, ey, 0);                  /* the four sides, one click each */
        click(ex + ew, ey + eh / 2, 0);
        click(ex + ew / 2, ey + eh, 0);
        prompt("ハッチ 3");
        click(ex, ey + eh / 2, 0);
        prompt("ハッチ 4");
        click(ex + ew / 2, ey, 0);                  /* the first side again closes the ring */
        prompt("ハッチ closed");
        /* the pitch is typed into its box and 実行 (1148) does it: nothing hatches without a pitch */
        jw_cmd_box_click(1411);
        printf("     pitch box held '%s'" "\n", jw_cmd_box(1411));
        for (int q = 0; q < 8; q++)
            app_key(8);                 /* a click does not select what is there */
        app_key('3');
        app_key(13);
        jw_cmd_bar((jw_drawing *)app_drawing(), 1148);
        ck(app_drawing()->ndrawn - before >= 3, "the ring is hatched with several lines");
        printf("     ハッチ: %d -> %d elements\n", before, app_drawing()->ndrawn);
    }

    /* the upper storey: its own layer group, a smaller footprint, on the same sheet to the right */
    write_layer_group(1);
    floor_plan(5, -60, 80, 60, 2);
    printf("     with the upper floor: %d lines, %d texts, %d elements\n", count(JW_SEN), count(JW_MOJI), app_drawing()->ndrawn);
    ck(count(JW_SEN) > lines1, "the upper floor adds walls");
    {
        int i, g1 = 0;
        const jw_drawing *d = app_drawing();

        for (i = 0; i < d->ndrawn; i++)
            g1 += d->obj[i].lgroup == 1;
        ck(g1 > 0, "and they are on layer group 1");
    }

    /* print */
    {
        long pn = 0;
        unsigned char *pdf = jw_plot_pdf(app_drawing(), 1, &pn);

        ck(pdf && pn > 2000 && !memcmp(pdf, "%PDF-", 5), "it prints to a PDF");
        free(pdf);
    }

    ck(app_save(&out, &n) && n > 0, "and saves as a .jww");
    if (make) {
        FILE *f = fopen("tests/data/house2f.jww", "wb");

        if (f) {
            fwrite(out, 1, (size_t)n, f);
            fclose(f);
            printf("     wrote tests/data/house2f.jww (%ld bytes)\n", n);
        }
    }
    /* against the plan kept in tests/data: the same number of each kind of element */
    if (!make) {
        FILE *f = fopen("tests/data/house2f.jww", "rb");
        unsigned char *kept;
        long kn = 0;
        jw_drawing k;
        int c, same = 1, gsame = 1, i;
        jw_drawing nowd;
        const jw_drawing *now = &nowd;

        /* what a save and a load make of the plan built now: a dimension comes back
           as the parts the file keeps for it, so the plan is compared as loaded */
        memset(&nowd, 0, sizeof nowd);
        if (!jw_parse(&nowd, out, n))
            printf("BAD  the plan just saved does not read\n");

        if (!f) {
            printf("BAD  tests/data/house2f.jww is missing (run with --make)\n");
            fails++;
        } else {
            fseek(f, 0, SEEK_END);
            kn = ftell(f);
            fseek(f, 0, SEEK_SET);
            kept = (unsigned char *)malloc((size_t)kn);
            if (fread(kept, 1, (size_t)kn, f) != (size_t)kn)
                kn = 0;
            fclose(f);
            memset(&k, 0, sizeof k);
            ck(jw_parse(&k, kept, kn), "the kept plan reads");
            for (c = 0; c < JW_NCLASS; c++) {
                int a = 0, b = 0;

                for (i = 0; i < k.ndrawn; i++)
                    a += k.obj[i].cls == c;
                for (i = 0; i < now->ndrawn; i++)
                    b += now->obj[i].cls == c;
                if (a != b)
                    same = 0;
            }
            for (i = 0; i < k.ndrawn && i < now->ndrawn; i++)
                if (k.obj[i].lgroup != now->obj[i].lgroup || k.obj[i].cls != now->obj[i].cls)
                    gsame = 0;
            ck(k.ndrawn == now->ndrawn && same, "the plan built now has the kept plan's elements");
            ck(gsame, "in the same order and on the same layer groups");
            for (i = 0; i < k.ndrawn && i < now->ndrawn && gsame; i++)
                if (k.obj[i].cls == JW_SEN && (fabs(k.obj[i].d[0] - now->obj[i].d[0]) > 1e-6
                                               || fabs(k.obj[i].d[3] - now->obj[i].d[3]) > 1e-6))
                    gsame = 0;
            ck(gsame, "and the lines are where they were");
            jw_free(&k);
            jw_free(&nowd);
            free(kept);
        }
    }
    free(out);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
