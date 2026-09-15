/* Render the whole window -- frame and drawing -- to a PNG, so it can be held
 * up against a screen grab of the original.
 *
 *   tests/shot.exe out.png [drawing.jww [w h]]
 */
#include <stdio.h>
#include <stdlib.h>

#include "../src/app.h"
#include "../src/ui.h"
#include "../src/view.h"
#include "png.h"

int main(int argc, char **argv)
{
    const char *out = argc > 1 ? argv[1] : "tests/out/shot.png";
    int w = argc > 4 ? atoi(argv[3]) : 1264;
    int h = argc > 4 ? atoi(argv[4]) : 741;
    const fb_t *fb;

    if (!app_resize(w, h)) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    if (argc > 2) {
        FILE *f = fopen(argv[2], "rb");
        unsigned char *b;
        long n;
        if (!f) {
            fprintf(stderr, "cannot open %s\n", argv[2]);
            return 1;
        }
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        b = (unsigned char *)malloc((size_t)n);
        if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
            fprintf(stderr, "cannot read %s\n", argv[2]);
            return 1;
        }
        fclose(f);
        if (!app_open(b, n)) {
            fprintf(stderr, "%s: %s\n", argv[2], app_error());
            return 1;
        }
        free(b);
    }
    app_paint();
    fb = app_fb();

    /* Alongside the picture, the rectangles the text lands in.  The glyphs
     * cannot match -- the original draws them with a Windows font -- so
     * tools/cmp.py is given these to score separately, and what is left is
     * the geometry. */
    {
        const jw_drawing *d = app_drawing();
        char maskpath[512];
        FILE *m;
        snprintf(maskpath, sizeof maskpath, "%s.mask", out);
        m = fopen(maskpath, "w");
        if (m) {
            fprintf(m, "# text rectangles of %s, from tests/shot.c\n",
                    argc > 2 ? argv[2] : "(no drawing)");
            if (d) {
                jw_view v;
                rect_t r;
                int i;
                ui_view_rect(fb->w, fb->h, &r);
                jw_view_fit(&v, &r, d->paper_hw, d->paper_hh);
                for (i = 0; i < d->nobj; i++) {
                    const jw_obj *o = &d->obj[i];
                    int x0, y0, x1, y1, pad;
                    if (o->cls != JW_MOJI)
                        continue;
                    x0 = jw_sx(&v, o->d[0] < o->d[2] ? o->d[0] : o->d[2]);
                    x1 = jw_sx(&v, o->d[0] > o->d[2] ? o->d[0] : o->d[2]);
                    y0 = jw_sy(&v, o->d[1] > o->d[3] ? o->d[1] : o->d[3]);
                    y1 = jw_sy(&v, o->d[1] < o->d[3] ? o->d[1] : o->d[3]);
                    pad = (int)(o->d[5] * v.scale) + 4;
                    fprintf(m, "%d %d %d %d\n", x0 - pad, y0 - pad,
                            x1 - x0 + 2 * pad, y1 - y0 + 2 * pad);
                }
            }
            fclose(m);
        }
    }
    if (!png_rgb(out, fb->w, fb->h, fb->px)) {
        fprintf(stderr, "cannot write %s\n", out);
        return 1;
    }
    printf("wrote %s (%dx%d)\n", out, fb->w, fb->h);
    return 0;
}
