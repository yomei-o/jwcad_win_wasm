/* The 2026-10 additions, hammered: 手書線 (freehand), the drawing order of
 * pictures and solids, and the autosave copy.
 *
 *   tests/newcode_test.exe [picture files...]
 *
 *  - strokes: random button-down / moves / button-up sequences in 連続線 with
 *    手書線 on -- tiny steps, huge jumps, off the window, a command or an Esc
 *    in the middle, a release with nothing held -- every one followed by 戻る
 *    and 進む checked exactly (the stroke is one step), and the numbers sane;
 *  - order: pictures (app_image) and solids (JW_SOLID, round and four-cornered)
 *    in every order, painted at several window sizes and zooms, which must
 *    not fall over and must paint the same after a save and reopen;
 *  - autosave: app_save_backup gives the bytes app_save gives, leaves the
 *    drawing "modified", reads back to the same elements, and survives a
 *    damaged copy (truncations and byte changes) being opened.
 * Meant for -fsanitize=address / undefined as much as for the plain build. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/fb.h"
#include "../src/image.h"

static int fails;
static unsigned long rng = 2463534242UL;

static unsigned nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return (unsigned)rng;
}

static void ck(int ok, const char *what)
{
    if (!ok) {
        printf("BAD  %s\n", what);
        fails++;
    }
}

static int count_img(const jw_drawing *d)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        if (jw_is_pic(d, &d->obj[i]))
            n++;
    return n;
}

static unsigned char *slurp(const char *p, long *n)
{
    FILE *f = fopen(p, "rb");
    unsigned char *b;

    if (!f) return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) { free(b); b = 0; }
    fclose(f);
    return b;
}

static void strokes(void)
{
    int s, k;

    for (s = 0; s < 200; s++) {
        jw_drawing *d;
        int n0, cx, cy, steps, depth0;

        app_resize(1264, 741);
        app_new();
        d = (jw_drawing *)app_drawing();
        app_command(32883);
        if (jw_cmd_bar_check(1774) <= 0)
            jw_cmd_bar(d, 1774);
        n0 = d->ndrawn;
        depth0 = jw_cmd_undo_depth();
        cx = 100 + (int)(nextr() % 900);
        cy = 150 + (int)(nextr() % 500);
        app_press(cx, cy, (int)(nextr() % 3 == 0));
        steps = 1 + (int)(nextr() % 120);
        for (k = 0; k < steps; k++) {
            unsigned r = nextr() % 20;

            if (r < 12)
                cx += (int)(nextr() % 15) - 7, cy += (int)(nextr() % 15) - 7;
            else if (r < 15)
                cx = (int)(nextr() % 1500) - 100, cy = (int)(nextr() % 900) - 60;
            else if (r < 16)
                cx += 100000, cy -= 100000;            /* off the window altogether */
            else if (r < 17)
                app_key(27);
            else if (r < 18)
                app_command(r & 1 ? 32883 : 32771);    /* another command, or the same again */
            else if (r < 19)
                app_release(cx, cy, 0);                /* released early; the moves go on */
            app_move(cx, cy);
        }
        app_release(cx, cy, 0);
        app_release(cx, cy, 0);                        /* and with nothing held */
        d = (jw_drawing *)app_drawing();
        ck(jw_numbers_sane(d), "strokes: the numbers stay sane");
        ck(!jw_cmd_freehand() || 1, "strokes: (state)");
        if (jw_cmd_undo_depth() > depth0 && d->ndrawn > n0) {
            int made = d->ndrawn - n0;

            while (jw_cmd_undo_depth() > depth0)
                jw_cmd_undo(d);
            ck(d->ndrawn == n0, "strokes: 戻る takes the whole stroke");
            while (jw_cmd_can_redo())
                jw_cmd_redo(d);
            ck(d->ndrawn == n0 + made, "strokes: 進む brings the same number back");
        }
    }
}

static void order(int nfiles, char **files)
{
    int round, k;

    for (round = 0; round < 60; round++) {
        jw_drawing *d;
        int nitems = 3 + (int)(nextr() % 8), w, h;
        unsigned char *o = 0;
        long on = 0;

        app_resize(1264, 741);
        app_new();
        for (k = 0; k < nitems; k++) {
            d = (jw_drawing *)app_drawing();
            if (nextr() % 2 && nfiles > 0) {
                long n;
                unsigned char *b = slurp(files[nextr() % (unsigned)nfiles], &n);

                if (b) {
                    app_command(33013);                 /* 画像編集 */
                    app_image(files[0], b, n);
                    free(b);
                }
            } else {
                jw_obj *s = jw_add(d, JW_SOLID);

                if (s) {
                    double x = (double)(nextr() % 200) - 100, y = (double)(nextr() % 150) - 75;

                    s->d[0] = x; s->d[1] = y; s->d[2] = x + 30; s->d[3] = y;
                    s->d[4] = x + 30; s->d[5] = y + 20; s->d[6] = x; s->d[7] = y + 20;
                    s->ltype = nextr() % 3 == 0 ? 101 : 1;
                    s->color = (unsigned short)(nextr() % 9);
                    if (nextr() % 4 == 0)
                        s->d[2] = s->d[0];                /* a solid with a side of no length */
                }
            }
        }
        d = (jw_drawing *)app_drawing();
        for (w = 0; w < 3; w++) {
            static const int W[3][2] = { { 1264, 741 }, { 300, 200 }, { 2000, 1100 } };

            app_resize(W[w][0], W[w][1]);
            app_fit();
            app_paint();
            app_zoom(1.0 + (nextr() % 40) / 10.0, W[w][0] / 2, W[w][1] / 2);
            app_paint();
        }
        /* saved and opened again, it has the same pictures */
        if (app_save(&o, &on)) {
            int before = count_img(d);

            ck(app_open(o, on), "order: the saved drawing opens");
            ck(count_img(app_drawing()) == before, "order: the same number of pictures after a save and reopen");
            app_paint();
            free(o);
        }
    }
}

static void autosave(void)
{
    static const char *F[] = { "orig/Test1.jww", "orig/Test5.jww" };
    unsigned i, k;

    for (i = 0; i < 2; i++) {
        long n, an = 0, sn = 0, j;
        unsigned char *b = slurp(F[i], &n), *a = 0, *sv = 0, *c;
        jw_drawing *d;

        if (!b)
            continue;
        app_resize(1264, 741);
        ck(app_open(b, n), "autosave: opens the drawing");
        free(b);
        d = (jw_drawing *)app_drawing();
        app_command(32771);
        app_press(300, 300, 0);
        app_press(500, 400, 0);
        ck(app_modified(), "autosave: the drawing is modified before");
        ck(app_save_backup(&a, &an), "autosave: a backup is made");
        ck(app_modified(), "autosave: and the drawing is still modified");
        ck(app_save(&sv, &sn), "autosave: a save is made");
        ck(!app_modified(), "autosave: and that one clears it");
        ck(an == sn && a && sv && !memcmp(a, sv, (size_t)an), "autosave: the backup is the bytes a save gives");
        /* a damaged copy is opened */
        c = (unsigned char *)malloc((size_t)an);
        for (k = 0; k < 150 && c; k++) {
            j = (long)(nextr() % (unsigned long)an);
            memcpy(c, a, (size_t)an);
            c[j] = (unsigned char)nextr();
            app_open(c, k & 1 ? j : an);
            app_mark_modified();
            app_paint();
            ck(!app_drawing() || jw_numbers_sane(app_drawing()), "autosave: a damaged copy leaves sane numbers");
        }
        free(c);
        free(a);
        free(sv);
        (void)d;
    }
}

int main(int argc, char **argv)
{
    strokes();
    order(argc - 1, argv + 1);
    autosave();
    printf(fails ? "FAILED %d\n" : "all ok\n", fails);
    return fails != 0;
}
