/* Render the whole window -- frame and drawing -- to a PNG, so it can be held
 * up against a screen grab of the original.
 *
 *   tests/shot.exe out.png [drawing.jww [w h]]
 */
#include <stdio.h>
#include <stdlib.h>

#include "../src/app.h"
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
    if (!png_rgb(out, fb->w, fb->h, fb->px)) {
        fprintf(stderr, "cannot write %s\n", out);
        return 1;
    }
    printf("wrote %s (%dx%d)\n", out, fb->w, fb->h);
    return 0;
}
