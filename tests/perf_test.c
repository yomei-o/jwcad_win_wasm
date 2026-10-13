/* How long the window takes: a redraw, a zoom, a pick, a move of the cursor,
 * a save, on the biggest drawings (and one made bigger by tiling it), and
 * whether memory keeps growing over a long session.
 *
 *   tests/perf_test.exe orig/Test7.jww ...
 *
 * Prints times in milliseconds per operation.  Limits are generous (they are
 * for a build under emulation); what is being looked for is a cost that is
 * quadratic in the drawing, or a session that leaks. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#endif

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"

static double now(void) { return (double)clock() * 1000.0 / CLOCKS_PER_SEC; }

static long rss(void)
{
#ifdef _WIN32
    PROCESS_MEMORY_COUNTERS pc;

    if (GetProcessMemoryInfo(GetCurrentProcess(), &pc, sizeof pc))
        return (long)(pc.WorkingSetSize / 1024);
#endif
    return 0;
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

static int bad;

static void limit(const char *what, double ms, double max)
{
    printf("    %-28s %9.2f ms%s\n", what, ms, ms > max ? "   <-- SLOW" : "");
    if (ms > max)
        bad++;
}

int main(int argc, char **argv)
{
    int a;

    app_resize(1264, 741);
    for (a = 1; a < argc; a++) {
        long n;
        unsigned char *b = slurp(argv[a], &n);
        double t0;
        int i, N = 20;
        long m0, m1;

        if (!b || !app_open(b, n)) { printf("skip %s\n", argv[a]); free(b); continue; }
        free(b);
        if (getenv("JW_PERF_TILE")) {
            /* the drawing again and again, shifted, to make it large */
            jw_drawing *d = (jw_drawing *)app_drawing();
            int t, tiles = atoi(getenv("JW_PERF_TILE")), n0 = d->nobj;

            for (t = 1; t <= tiles; t++)
                for (i = 0; i < n0; i++) {
                    jw_obj *o = jw_add(d, d->obj[i].cls);
                    int id;

                    if (!o) break;
                    id = o->id;
                    {
                        const jw_obj *src = &d->obj[i];
                        memcpy(o, src, sizeof *o);
                    }
                    o->id = id;
                    o->d[0] += 30.0 * t; o->d[2] += 30.0 * t;
                }
        }
        printf("%s: %d elements\n", argv[a], app_drawing() ? app_drawing()->ndrawn : 0);
        app_fit();
        app_paint();
        t0 = now();
        for (i = 0; i < N; i++) app_paint();
        limit("redraw (cached)", (now() - t0) / N, 200);
        t0 = now();
        for (i = 0; i < N; i++) { app_zoom(i & 1 ? 1.0 / 1.3 : 1.3, 600, 400); app_paint(); }
        limit("zoom + redraw", (now() - t0) / N, 1000);
        app_fit();
        app_paint();
        t0 = now();
        for (i = 0; i < 200; i++) app_move(50 + (i * 37) % 1100, 100 + (i * 53) % 600);
        limit("cursor move", (now() - t0) / 200, 50);
        app_command(0x801a);          /* 消去: a pick under every press */
        t0 = now();
        for (i = 0; i < 100; i++) app_press(50 + (i * 71) % 1100, 100 + (i * 97) % 600, 1);
        limit("pick (right press)", (now() - t0) / 100, 100);
        app_command(0x8003);
        {
            unsigned char *o;
            long on;

            t0 = now();
            if (app_save(&o, &on)) free(o);
            limit("save .jww", now() - t0, 3000);
            t0 = now();
            if (app_save_dxf(&o, &on)) free(o);
            limit("save .dxf", now() - t0, 5000);
        }
        /* a long session: memory must settle */
        m0 = 0;
        for (i = 0; i < 3000; i++) {
            switch (i % 6) {
            case 0: app_command(0x8003); break;
            case 1: app_press(300 + i % 400, 300 + i % 200, 0); break;
            case 2: app_press(600 + i % 300, 400 + i % 100, 0); break;
            case 3: app_zoom(i & 8 ? 1.1 : 1.0 / 1.1, 500, 400); break;
            case 4: app_paint(); break;
            case 5: if (jw_cmd_can_undo()) jw_cmd_undo((jw_drawing *)app_drawing()); break;
            }
            if (i == 500) m0 = rss();
        }
        m1 = rss();
        printf("    memory after 500 / 3000 steps %ld / %ld KB%s\n", m0, m1,
               m1 > m0 * 2 + 20000 ? "   <-- GROWS" : "");
        if (m1 > m0 * 2 + 20000)
            bad++;
        app_new();
    }
    printf(bad ? "BAD  %d slow or growing\n" : "ok   fast enough, memory steady\n", bad);
    return bad != 0;
}
