/* How long the things a person waits for take, on the biggest drawings there
   are.  Run it by itself to see the numbers; under qtest it only fails if one
   is far past a limit that is generous on purpose (a slow machine, a loaded one).
     tests/perf_test.exe [file ...]                                             */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/pick.h"
#include "../src/ui.h"

static int fails;

static double now(void)
{
    LARGE_INTEGER f, c;

    QueryPerformanceFrequency(&f);
    QueryPerformanceCounter(&c);
    return (double)c.QuadPart * 1000.0 / (double)f.QuadPart;
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

static void run(const char *path, double limit)
{
    long n;
    unsigned char *b = slurp(path, &n);
    const fb_t *fb;
    rect_t r;
    double t, zoomms, paint, pick, undo, open_ms, sel;
    int i, objs;

    if (!b) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        return;
    }
    t = now();
    if (!app_open(b, n)) {
        printf("BAD  cannot open %s\n", path);
        fails++;
        free(b);
        return;
    }
    open_ms = now() - t;
    free(b);
    fb = app_fb();
    ui_view_rect(fb->w, fb->h, &r);
    objs = app_drawing()->ndrawn;
    t = now();
    for (i = 0; i < 10; i++) {
        app_pan((i & 1) ? 40 : -40, 0);        /* a different picture each time */
        app_paint();
    }
    paint = (now() - t) / 10;
    t = now();
    for (i = 0; i < 10; i++) {
        app_zoom((i & 1) ? 0.8 : 1.25, r.x + 400, r.y + 300);
        app_paint();
    }
    zoomms = (now() - t) / 10;
    app_command(JW_CMD_SEN);
    t = now();
    for (i = 0; i < 100; i++) {
        app_move(r.x + 50 + (i * 13) % (r.w - 100), r.y + 50 + (i * 7) % (r.h - 100));
        app_press(r.x + 50 + (i * 13) % (r.w - 100), r.y + 50 + (i * 7) % (r.h - 100), 0);
    }
    pick = (now() - t) / 100;       /* a move and a click, which look for what to snap to */
    app_command(32787);
    t = now();
    app_press(r.x + 20, r.y + 20, 0);
    app_press(r.x + r.w - 5, r.y + r.h - 5, 1);
    sel = now() - t;
    app_command(32794);                         /* 消去 */
    t = now();
    for (i = 0; i < 40; i++)
        jw_cmd_undo(app_drawing());
    undo = (now() - t) / 40;
    printf("     %-34s %6d objects: open %5.0f ms, paint %5.1f ms, zoom %5.1f ms, click %5.2f ms, select %5.0f ms, undo %5.0f ms\n",
           path, objs, open_ms, paint, zoomms, pick, sel, undo);
    if (paint > limit || pick > limit || open_ms > limit * 20 || undo > limit * 20) {
        printf("BAD  %s is past the limit (%.0f ms)\n", path, limit);
        fails++;
    }
}

int main(int argc, char **argv)
{
    int i;

    app_resize(1264, 741);
    if (argc > 1) {
        for (i = 1; i < argc; i++)
            run(argv[i], 1e9);
        return 0;
    }
    run("orig/Test1.jww", 100);
    run("decomp/res/tenkuhyo.jww", 150);
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
