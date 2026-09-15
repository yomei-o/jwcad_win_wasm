/* Render the frame and write it out, so tools/cmp.py can put it next to the
 * original.  No window, no event loop -- the point is the pixels. */
#include <stdio.h>
#include <stdlib.h>

#include "../src/fb.h"
#include "../src/ui.h"
#include "png.h"

int main(int argc, char **argv)
{
    const char *out = argc > 1 ? argv[1] : "tests/out/frame.png";
    int w = argc > 3 ? atoi(argv[2]) : 1264;
    int h = argc > 3 ? atoi(argv[3]) : 741;
    fb_t fb;

    if (!fb_init(&fb, w, h)) {
        fprintf(stderr, "out of memory\n");
        return 1;
    }
    ui_paint(&fb);
    if (!png_rgb(out, fb.w, fb.h, fb.px)) {
        fprintf(stderr, "cannot write %s\n", out);
        return 1;
    }
    printf("wrote %s (%dx%d)\n", out, fb.w, fb.h);
    fb_free(&fb);
    return 0;
}
