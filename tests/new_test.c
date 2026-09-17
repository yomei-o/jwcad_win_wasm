/* A drawing begun from nothing, drawn on, saved, and read back.
 *
 *   tests/new_test.exe [out.jww]
 *
 * The point of it is the save: until the new drawing carried a real header
 * (src/gen/newjww.c, from the original's own empty file) app_save could not
 * write one at all.  Checked here:
 *   - a new drawing has the sheet, scale and pens the original starts with;
 *   - it is empty of drawn elements -- the six records Jw_cad keeps its
 *     printer and view settings in are on layer 9 and are not drawn;
 *   - two clicks put a line in it, and saving gives bytes back;
 *   - reading those bytes back gives the same line, on the same layer, with
 *     the same pen.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "../src/gen/layout.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

int main(int argc, char **argv)
{
    const jw_drawing *d;
    unsigned char *out = 0;
    long n = 0;
    jw_drawing back;
    int i, nsen = 0;
    double x0 = 0, y0 = 0, x1 = 0, y1 = 0;

    app_resize(1916, 1030);
    app_new();
    d = app_drawing();
    ck(d != 0, "a new drawing exists");
    if (!d)
        return 1;
    ck(d->version == 700, "it is a version 700 drawing");
    ck(d->paper_size == 2, "the sheet is A-2");
    ck(d->group[0].scale == 100, "group 0 is at 1/100");
    ck(d->group[0].state == 3 && d->group[0].layer[0].state == 3,
       "group 0 layer 0 is the one written to");
    ck(d->pen_rgb[1] == 0x00c0c0u && d->pen_rgb[2] == 0x000000u,
       "the pens are the original's");
    ck(d->nhead > 0, "it has a header to save with");
    for (i = 0; i < d->nobj; i++)
        if (d->obj[i].cls == JW_SEN)
            nsen++;
    ck(nsen == 0, "there is nothing drawn in it yet");

    /* 線 is the command it starts in; two clicks in the drawing area */
    app_press(300, 200, 0);
    app_press(500, 300, 0);
    d = app_drawing();
    nsen = 0;
    for (i = 0; i < d->nobj; i++)
        if (d->obj[i].cls == JW_SEN) {
            nsen++;
            x0 = d->obj[i].d[0]; y0 = d->obj[i].d[1];
            x1 = d->obj[i].d[2]; y1 = d->obj[i].d[3];
        }
    ck(nsen == 1, "two clicks put one line in it");

    ck(app_save(&out, &n) && n > 0, "and it can be saved");
    if (!out)
        return 1;
    ck(jw_parse(&back, out, n), "the bytes read back as a drawing");
    nsen = 0;
    for (i = 0; i < back.nobj; i++)
        if (back.obj[i].cls == JW_SEN) {
            nsen++;
            ck(back.obj[i].d[0] == x0 && back.obj[i].d[1] == y0
               && back.obj[i].d[2] == x1 && back.obj[i].d[3] == y1,
               "with the line where it was");
            ck(back.obj[i].ltype == 1 && back.obj[i].color == 2
               && back.obj[i].width == 0,
               "and the attributes it was given");
        }
    ck(nsen == 1, "and just the one line");
    if (argc > 1) {
        FILE *f = fopen(argv[1], "wb");
        if (f) {
            fwrite(out, 1, (size_t)n, f);
            fclose(f);
            printf("wrote %s, %ld bytes\n", argv[1], n);
        }
    }
    jw_free(&back);
    free(out);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
