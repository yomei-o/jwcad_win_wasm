/* The commands, driven at random.
 *
 *   tests/cmdfuzz_test.exe <drawings…>
 *
 * Every other test drives one command the way someone would use it.  This
 * one drives all of them the way nobody would: for each drawing it presses
 * toolbar commands, clicks and drags all over the window, types, and
 * repaints, in an order drawn from a fixed pseudo-random stream.  Nothing is
 * compared against anything -- there is nothing to compare it with.  What is
 * being asked is only:
 *
 *   * does anything fall over,
 *   * does the drawing keep numbers a drawing could hold
 *     (jw_numbers_sane, the same gate the readers use), and
 *   * can what is left still be written out every way the port can write?
 *
 * The stream is the same every run so a fault can be looked at again;
 * JW_CMDFUZZ_SEED picks another one, and JW_CMDFUZZ_STEPS how long to go on.
 * Build it with -fsanitize=address to make the first question sharp.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/app.h"
#include "../src/jww.h"
#include "../src/gen/cmds.h"
#include "../src/gen/layout.h"

static unsigned long rng = 20260925u;

static unsigned long nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return rng;
}

#define W 1264
#define H 741

/* keys the 文字 command and the dialogs care about, plus a few that no
   command wants at all */
static const int KEYS[] = {
    'a', 'A', '0', '9', ' ', '.', '-', 8, 13, 27, 9, 0x82, 0xa1, 0xff
};

static long written;

static void write_every_way(const jw_drawing *d)
{
    unsigned char *o;
    long m;

    if (!d)
        return;
    written++;
    if (jw_write(d, &o, &m))              free(o);
    if (jw_write_jws(d, 0, 0, &o, &m))    free(o);
    if (jw_dxf_write(d, &o, &m))          free(o);
    if (jw_sfc_write(d, "x", "2026-01-01", &o, &m)) free(o);
    if (jw_jwc_write(d, &o, &m))          free(o);
    if (jw_write_coord(d, 0, 0, &o, &m))  free(o);
}

int main(int argc, char **argv)
{
    const char *seed = getenv("JW_CMDFUZZ_SEED");
    const char *nsteps = getenv("JW_CMDFUZZ_STEPS");
    int steps = nsteps && *nsteps ? atoi(nsteps) : 600;
    int i, bad = 0, files = 0;
    long acts = 0;

    if (seed && *seed) {
        rng = strtoul(seed, 0, 0);
        if (!rng)
            rng = 1;
    }
    if (steps < 1)
        steps = 1;
    if (!app_resize(W, H)) {
        printf("BAD  out of memory\n");
        return 1;
    }

    for (i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "rb");
        unsigned char *b;
        long n;
        int k;
        clock_t t0;

        if (!f) {
            printf("BAD  %s: cannot open\n", argv[i]);
            bad++;
            continue;
        }
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        b = (unsigned char *)malloc((size_t)(n ? n : 1));
        if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
            printf("BAD  %s: cannot read\n", argv[i]);
            fclose(f);
            free(b);
            bad++;
            continue;
        }
        fclose(f);
        if (!app_open(b, n)) {
            printf("BAD  %s: %s\n", argv[i], app_error());
            free(b);
            bad++;
            continue;
        }
        free(b);
        files++;
        t0 = clock();

        for (k = 0; k < steps; k++) {
            unsigned long r = nextr() % 100;

            acts++;
            if (r < 25)
                app_command(jw_btn_cmd[nextr() % JW_NBUTTONS]);
            else if (r < 60)
                app_press((int)(nextr() % W), (int)(nextr() % H),
                          (int)(nextr() % 2));
            else if (r < 75)
                app_move((int)(nextr() % W), (int)(nextr() % H));
            else if (r < 90)
                app_key(KEYS[nextr() % (sizeof KEYS / sizeof KEYS[0])]);
            else
                app_paint();
            if ((k & 63) == 0 && app_drawing()
                && !jw_numbers_sane(app_drawing())) {
                printf("BAD  %s: a number no drawing could hold after"
                       " %d steps\n", argv[i], k);
                bad++;
                break;
            }
        }
        app_paint();
        if (app_drawing() && !jw_numbers_sane(app_drawing())) {
            printf("BAD  %s: a number no drawing could hold at the end\n",
                   argv[i]);
            bad++;
        } else {
            write_every_way(app_drawing());
        }
        {   /* a command that never comes back is as much a fault as one
               that falls over */
            long ms = (long)((clock() - t0) * 1000 / CLOCKS_PER_SEC);
            if (ms > 60000)
                printf("BAD  %s: %ld ms for %d steps\n", argv[i], ms, steps);
        }
    }
    printf("%d drawings, %ld commands, clicks and keys with nothing falling"
           " over, and what was left written out %ld times\n",
           files, acts, written);
    return bad ? 1 : 0;
}
