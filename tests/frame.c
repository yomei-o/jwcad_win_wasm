/* Render the window as it is when the port starts and write it out, so
 * tools/cmp.py can put it next to the original.  No window, no event loop --
 * the point is the pixels.
 *
 * It goes through app_new() for the same reason the browser build does: the
 * original always has a drawing open, an empty A-2 one until a file is
 * loaded, and its status line says so.
 */
#include <stdio.h>
#include <stdlib.h>

#include "../src/app.h"
#include "png.h"

int main(int argc, char **argv)
{
    const char *out = argc > 1 ? argv[1] : "tests/out/frame.png";
    int w = argc > 3 ? atoi(argv[2]) : 1264;
    int h = argc > 3 ? atoi(argv[3]) : 741;
    const fb_t *fb;

    app_new();
    if (!app_resize(w, h)) {
        fprintf(stderr, "out of memory\n");
        return 1;
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
