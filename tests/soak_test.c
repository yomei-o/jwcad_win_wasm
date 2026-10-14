/* A long random session, to watch what grows.
 *
 *   tests/soak_test.exe [steps] [seed] [drawing] [reload]   (default 1000000 steps, orig/Test1.jww)
 *   reload: open the file again every that many steps (0 = never) -- the random commands include 全消去
 *   and 新規, so without it the drawing is mostly empty and nothing much is being held
 *
 * The same kind of walk as tests/cmdfuzz_test.c -- toolbar commands, presses aimed at the drawing and
 * at nothing, moves, keys -- but with none of its per-step checks, so that millions of steps are cheap.
 * Every `steps/20` it prints the working set, the undo depth, the number of elements and the size of
 * the string pool, and at the end says whether any of them is still climbing after the first third
 * (the drawing is put back to the file's own every 20,000 steps when it has grown past 3x, so that
 * what is left growing is the program's, not the drawing's).  Written for Windows' working-set figure;
 * elsewhere the memory column is 0 and only the counts are watched. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#endif

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/gen/layout.h"
#include "../src/gen/cmds.h"

static unsigned long rng = 88172645463325252UL;
static unsigned nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 7;
    rng ^= rng << 17;
    return (unsigned)(rng >> 16);
}

static long rss_kb(void)
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

int main(int argc, char **argv)
{
    long steps = argc > 1 ? atol(argv[1]) : 1000000L, k, n;
    const char *name = argc > 3 ? argv[3] : "orig/Test1.jww";
    unsigned char *b;
    long mem[21], undo[21], pool[21], objs[21];
    int row = 0;
    long reload = argc > 4 ? atol(argv[4]) : 0;

    if (argc > 2)
        rng = rng * 31 + (unsigned long)atol(argv[2]) * 2654435761UL + 1;
    b = slurp(name, &n);
    if (!b) { printf("BAD  cannot read %s\n", name); return 1; }
    app_resize(1264, 741);
    app_open(b, n);
    app_fit();
    for (k = 0; k < steps; k++) {
        const jw_drawing *d = app_drawing();
        const jw_view *v = app_view();
        unsigned r = nextr() % 100;

        if (r < 20)
            app_command(jw_btn_cmd[nextr() % JW_NBUTTONS]);
        else if (r < 45 && d && v && d->ndrawn > 0) {
            const jw_obj *o = &d->obj[nextr() % (unsigned)d->ndrawn];

            app_press(jw_sx(v, o->d[0]), jw_sy(v, o->d[1]), (int)(nextr() & 1));
        } else if (r < 65)
            app_press((int)(nextr() % 1264), (int)(nextr() % 741), (int)(nextr() & 1));
        else if (r < 80)
            app_move((int)(nextr() % 1264), (int)(nextr() % 741));
        else if (r < 90)
            app_key("0123456789.-\r\x1b"[nextr() % 14]);
        else if (r < 95)
            app_paint();
        else if (jw_cmd_can_undo())
            jw_cmd_undo((jw_drawing *)app_drawing());
        if (reload > 0 && k % reload == reload - 1) {
            app_open(b, n);
            app_fit();
        }
        if (k % 20000 == 19999) {
            d = app_drawing();
            if (d && d->nobj > 3 * 1700 + 3000) {            /* grown far past the file's own */
                app_open(b, n);
                app_fit();
            }
        }
        if (steps >= 20 && k % (steps / 20) == (steps / 20) - 1 && row < 20) {
            d = app_drawing();
            row++;
            mem[row] = rss_kb();
            undo[row] = jw_cmd_undo_depth();
            pool[row] = d ? d->npool : 0;
            objs[row] = d ? d->nobj : 0;
            printf("  %9ld steps: %8ld KB, undo depth %6ld, %6ld elements, pool %8ld bytes\n", k + 1, mem[row],
                   undo[row], objs[row], pool[row]);
            fflush(stdout);
        }
    }
    if (row >= 15) {
        /* climbing: the last quarter's figure well above that of the first third */
        long a = mem[row / 3], z = mem[row];
        int bad = 0;

        if (a > 0 && z > a * 3 / 2 + 20000) {
            printf("BAD  the working set keeps climbing: %ld KB at a third, %ld KB at the end\n", a, z);
            bad = 1;
        }
        if (pool[row] > pool[row / 3] * 3 + 1000000) {
            printf("BAD  the string pool keeps climbing: %ld bytes at a third, %ld at the end\n", pool[row / 3], pool[row]);
            bad = 1;
        }
        printf(bad ? "FAILED\n" : "ok   nothing keeps growing\n");
        return bad;
    }
    printf("ok   (too short to judge)\n");
    return 0;
}
