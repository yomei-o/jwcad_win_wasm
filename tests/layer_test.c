/* The two grids at the bottom right: layers and layer groups.
 *
 *   tests/layer_test.exe [drawing.jww]
 *
 * The original was opened on Test5, cells were pressed and the drawing
 * saved; the layer states in the file are what this checks against:
 *   - the right button makes a cell the one being written to, and the one
 *     that was drops to 編集可;
 *   - the left button steps a cell round 編集可 -> 非表示 -> 表示のみ ->
 *     編集可 (three presses on layer 6 brought it back), and does nothing
 *     on the one being written to;
 *   - the group grid behaves the same way.
 */
#include <stdio.h>
#include <stdlib.h>

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

/* the middle of a cell, the way src/ui.c lays the grids out */
static void cell(int g, int n, int *x, int *y)
{
    static const int gx[2] = { 1188, 1227 }, gy[2] = { 394, 397 };

    *x = gx[g] + (n / 8) * 19 + 9;
    *y = gy[g] + (n % 8) * 21 + 10;
}

static int wg(void)
{
    const jw_drawing *d = app_drawing();
    int i, g = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            g = i;
    return g;
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "orig/Test5.jww";
    const jw_drawing *d;
    FILE *f = fopen(path, "rb");
    unsigned char *b;
    long n;
    int x, y, was;

    app_resize(1264, 741);
    if (!f) {
        printf("BAD  cannot open %s\n", path);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n)
        return 1;
    fclose(f);
    if (!app_open(b, n)) {
        printf("BAD  %s: %s\n", path, app_error());
        return 1;
    }
    free(b);
    d = app_drawing();

    {   /* the hit test finds the cells where they are drawn */
        int g2, k;
        cell(0, 3, &x, &y);
        g2 = ui_layer_hit(x, y, &k);
        ck(g2 == 0 && k == 3, "the layer grid's fourth cell is layer 3");
        cell(1, 9, &x, &y);
        g2 = ui_layer_hit(x, y, &k);
        ck(g2 == 1 && k == 9, "the group grid's tenth is group 9");
        ck(ui_layer_hit(600, 400, &k) < 0, "the drawing area is neither");
    }

    /* the left button steps a layer round */
    was = d->group[wg()].layer[3].state;
    ck(was == 2, "layer 3 starts 編集可");
    cell(0, 3, &x, &y);
    app_press(x, y, 0);
    ck(d->group[wg()].layer[3].state == 0, "one press hides it");
    app_press(x, y, 0);
    ck(d->group[wg()].layer[3].state == 1, "another shows it without editing");
    app_press(x, y, 0);
    ck(d->group[wg()].layer[3].state == 2, "a third puts it back");

    /* the one being written to does not move */
    {
        int w = d->group[wg()].write_layer & 15;
        cell(0, w, &x, &y);
        app_press(x, y, 0);
        ck(d->group[wg()].layer[w].state == 3,
           "the write layer is left alone by the left button");
    }

    /* the right button moves the write layer */
    {
        int w = d->group[wg()].write_layer & 15;
        cell(0, 5, &x, &y);
        app_press(x, y, 1);
        ck((d->group[wg()].write_layer & 15) == 5, "the right button moves it");
        ck(d->group[wg()].layer[5].state == 3, "the new one is the write one");
        ck(w == 5 || d->group[wg()].layer[w].state == 2,
           "and the old one drops to 編集可");
    }

    /* and the write group */
    {
        int g0 = wg();
        cell(1, 3, &x, &y);
        app_press(x, y, 1);
        ck(wg() == 3, "the right button moves the write group too");
        ck(g0 == 3 || d->group[g0].state == 2, "the old group drops to 編集可");
    }

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
