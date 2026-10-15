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
#include "../src/jww.h"

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

/* the middle of one of the four small buttons under the grids */
static void small(int k, int *x, int *y)
{
    static const int sx[4] = { 1194, 1194, 1234, 1234 },
                     sy[4] = { 564, 587, 567, 590 };

    *x = sx[k] + 12;
    *y = sy[k] + 10;
}

static void press_small(int k, int button)
{
    int x, y;

    small(k, &x, &y);
    app_press(x, y, button);
}

/* every layer of the write group that All would set (not the write one,
   not protected with 2) is at st */
static int layers_at(int st)
{
    const jw_drawing *d = app_drawing();
    const jw_group *gr = &d->group[wg()];
    int i;

    for (i = 0; i < 16; i++)
        if (gr->layer[i].state != 3 && gr->layer[i].state2 != 2
            && gr->layer[i].state != st)
            return 0;
    return 1;
}

/* All・0・All・× under the grids.  Read off the decompilation
 * (FUN_00555b70 makes them; FUN_00557600, FUN_0056a080, FUN_00508a50),
 * not pressed in the original. */
static void small_buttons(void)
{
    jw_drawing *d = (jw_drawing *)app_drawing();
    int x, y, k, i, keep[16][16], keepg[16], same;

    for (k = 0; k < 4; k++) {
        small(k, &x, &y);
        ck(ui_layer_small_hit(1264, x, y) == k, "the small buttons are hit where drawn");
    }
    ck(ui_layer_small_hit(1264, 600, 400) < 0, "  and not in the drawing");

    /* All under the layers: 2 -> 0 -> 1 -> 2 on the left, 2 on the right */
    press_small(0, 0);
    ck(layers_at(0), "レイヤの All 一回で 書込以外のレイヤが 非表示");
    ck(d->group[wg()].layer[d->group[wg()].write_layer & 15].state == 3,
       "  書込レイヤはそのまま");
    press_small(0, 0);
    ck(layers_at(1), "  二回で 表示のみ");
    press_small(0, 1);
    ck(layers_at(2), "  右で 編集可");
    press_small(0, 0);
    press_small(0, 0);
    press_small(0, 0);
    ck(layers_at(2), "  左三回で 編集可 に戻る");

    /* All under the groups */
    press_small(2, 0);
    same = 1;
    for (i = 0; i < 16; i++)
        if (d->group[i].state != 3 && d->group[i].c != 2 && d->group[i].state != 0)
            same = 0;
    ck(same, "グループの All 一回で 書込以外のグループが 非表示");
    press_small(2, 1);
    same = 1;
    for (i = 0; i < 16; i++)
        if (d->group[i].state != 3 && d->group[i].c != 2 && d->group[i].state != 2)
            same = 0;
    ck(same, "  右で 編集可");

    /* the X: 反転表示 and back */
    for (i = 0; i < 16; i++) {
        keepg[i] = d->group[i].state;
        for (k = 0; k < 16; k++)
            keep[i][k] = d->group[i].layer[k].state;
    }
    d->group[wg()].layer[1].state = 0;
    keep[wg()][1] = 0;
    d->group[wg()].layer[1].state2 = 0;
    d->group[wg()].layer[2].state2 = 0;
    d->group[wg()].layer[2].state = 2;
    keep[wg()][2] = 2;
    press_small(3, 0);
    ck(d->group[wg()].layer[1].state == 2, "× で 非表示のレイヤが 編集可");
    ck(d->group[wg()].layer[2].state == 0, "  編集可のレイヤが 非表示");
    cell(0, 2, &x, &y);
    app_press(x, y, 0);
    ck(d->group[wg()].layer[2].state == 0, "  反転の間は升目が効かない");
    press_small(3, 0);
    same = 1;
    for (i = 0; i < 16; i++) {
        if (d->group[i].state != keepg[i])
            same = 0;
        for (k = 0; k < 16; k++)
            if (d->group[i].layer[k].state != keep[i][k])
                same = 0;
    }
    ck(same, "  もう一度で元に戻る");
    press_small(3, 0);
    app_command(JW_CMD_UNDO);
    ck(d->group[wg()].layer[1].state == 0 && d->group[wg()].layer[2].state == 2,
       "  戻る でも元に戻る");
    press_small(3, 0);
    app_command(JW_CMD_SEN);
    ck(d->group[wg()].layer[1].state == 0 && d->group[wg()].layer[2].state == 2,
       "  命令を選んでも元に戻る");

    /* the button under the layers' All puts the group bar away */
    press_small(1, 0);
    ck(!ui_glayer_shown(), "レイヤの下の釦で グループのバーが消える");
    cell(1, 3, &x, &y);
    ck(ui_layer_hit(1264, x, y, &k) < 0, "  消えている間 グループの升目は当たらない");
    small(3, &x, &y);
    ck(ui_layer_small_hit(1264, x, y) < 0, "  その下の釦も");
    press_small(1, 0);
    ck(ui_glayer_shown(), "  もう一度で出る");
}

/* Ctrl + left: protection (FUN_0055ea10), and that it is saved */
static void protect(void)
{
    jw_drawing *d = (jw_drawing *)app_drawing();
    int x, y, g = wg(), w, st, i;
    unsigned char *out = 0;
    long n = 0;
    jw_drawing r;

    w = d->group[g].write_layer & 15;
    d->group[g].layer[4].state2 = 0;
    d->group[g].layer[6].state2 = 0;
    d->group[g].layer[4].state = 2;
    d->group[g].layer[6].state = 2;

    app_keymods(0, 1);
    cell(0, 4, &x, &y);
    app_press(x, y, 0);
    ck(d->group[g].layer[4].state2 == 1 && d->group[g].layer[4].state == 2,
       "Ctrl+左 でレイヤが保護され 状態はそのまま");
    app_keymods(1, 1);
    cell(0, 6, &x, &y);
    app_press(x, y, 0);
    ck(d->group[g].layer[6].state2 == 2, "  Shift+Ctrl+左 で 2");
    cell(0, w, &x, &y);
    app_press(x, y, 0);
    ck(d->group[g].layer[w].state2 == 0, "  書込レイヤは保護しない");
    app_keymods(0, 0);

    cell(0, 4, &x, &y);
    app_press(x, y, 1);
    ck((d->group[g].write_layer & 15) == w, "保護したレイヤは右で書込にならない");
    app_press(x, y, 0);
    ck(d->group[g].layer[4].state == 0, "  保護 1 は左で回る");
    cell(0, 6, &x, &y);
    app_press(x, y, 0);
    ck(d->group[g].layer[6].state == 2, "  保護 2 は回らない");
    press_small(0, 0);
    ck(d->group[g].layer[6].state == 2, "  All でも変わらない");

    /* the group grid, and All with Ctrl */
    i = g == 2 ? 5 : 2;
    d->group[i].c = 0;
    app_keymods(0, 1);
    cell(1, i, &x, &y);
    app_press(x, y, 0);
    ck(d->group[i].c == 1, "Ctrl+左 でグループも保護");
    press_small(0, 0);
    st = 1;
    for (x = 0; x < 16; x++)
        if (d->group[g].layer[x].state != 3 && d->group[g].layer[x].state2 != 1)
            st = 0;
    ck(st, "Ctrl+All で書込以外のレイヤがみな保護");
    press_small(0, 0);
    st = 1;
    for (x = 0; x < 16; x++)
        if (x != w && d->group[g].layer[x].state2 != 0)
            st = 0;
    ck(st, "  もう一度で外れる");
    cell(0, 4, &x, &y);
    app_press(x, y, 0);
    app_keymods(0, 0);

    /* both kinds are in the saved file */
    ck(jw_write(d, &out, &n) && out, "保存できる");
    if (out && jw_parse(&r, out, n)) {
        ck(r.group[g].layer[4].state2 == 1, "  レイヤの保護が残る");
        ck(r.group[i].c == 1, "  グループの保護も残る");
        jw_free(&r);
    } else
        ck(0, "  読み直せる");
    free(out);
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
        g2 = ui_layer_hit(1264, x, y, &k);
        ck(g2 == 0 && k == 3, "the layer grid's fourth cell is layer 3");
        cell(1, 9, &x, &y);
        g2 = ui_layer_hit(1264, x, y, &k);
        ck(g2 == 1 && k == 9, "the group grid's tenth is group 9");
        ck(ui_layer_hit(1264, 600, 400, &k) < 0, "the drawing area is neither");
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

    small_buttons();
    protect();

    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
