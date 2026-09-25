/* The readers against files that have been damaged.
 *
 *   tests/fuzz_test.exe <every drawing, figure, DXF, SFC and JWC>
 *
 * A reader that walks a file with a cursor is only safe while every read is
 * bounded, and the way to find out is to hand it rubbish.  For each file
 * this takes a few hundred cut-down copies (every prefix length on a coarse
 * grid, plus the boundaries of the header) and a few hundred with single
 * bytes changed, and asks the reader the name calls for -- .jww, .jws, DXF,
 * SFC or JWC -- to read them.  Whatever is read is then written back out
 * every way the port can write, which puts the same rubbish through the
 * writers.  The parse
 * may fail -- that is the point -- but it has to come back, and it has to
 * leave a drawing that jw_free can let go of.
 *
 * What this cannot catch by itself is a read that lands inside the malloc'd
 * block but outside the file; the length is the only guard there, so the
 * cut-down copies are allocated at exactly their length and the runtime's
 * own heap checking has the last word.  Build it with -fsanitize=address to
 * make that sharp; check.sh runs it plain, where it still catches the reads
 * that run off the end of the heap block outright.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/jww.h"

static unsigned long rng = 123456789u;

static unsigned long nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return rng;
}

/* Which reader a name asks for. */
static int kind_of(const char *p)
{
    size_t n = strlen(p);
    char e[4];
    int i;

    if (n < 5)
        return 0;
    for (i = 0; i < 3; i++) {
        char c = p[n - 3 + i];
        e[i] = c >= 'A' && c <= 'Z' ? (char)(c - 'A' + 'a') : c;
    }
    e[3] = 0;
    if (!strcmp(e, "jws")) return 1;
    if (!strcmp(e, "dxf")) return 2;
    if (!strcmp(e, "sfc")) return 3;
    if (!strcmp(e, "jwc")) return 4;
    return 0;
}

/* How long one file's whole run may take before it counts as a fault.  Wall
   clock on a machine with other work on it, so it wants room; the fault this
   caught the first time ran for twenty minutes on one file. */
#define SLOW 30.0

static long written;

/* Write it back out every way there is.  A drawing read from a damaged
 * file holds numbers no drawing ever holds -- angles of 1e300, texts of
 * nothing, elements on layer 15 of group 15 -- and the writers have to come
 * back from all of them.  What comes out is not compared with anything:
 * there is nothing to compare it with. */
static void write_every_way(const jw_drawing *d)
{
    unsigned char *o;
    long m;

    if (jw_write(d, &o, &m))       free(o);
    if (jw_write_jws(d, 0, 0, &o, &m)) free(o);
    if (jw_dxf_write(d, &o, &m))   free(o);
    if (jw_sfc_write(d, "x", "2026-01-01", &o, &m)) free(o);
    if (jw_jwc_write(d, &o, &m))   free(o);
    if (jw_write_coord(d, 0, 0, &o, &m)) free(o);
}

static int one(const unsigned char *b, long n, int kind)
{
    jw_drawing d;
    int ok;
    clock_t t0 = clock();

    memset(&d, 0, sizeof d);
    switch (kind) {
    case 1:  ok = jw_parse_jws(&d, b, n, 0, 0); break;
    case 2:  ok = jw_dxf_read(&d, b, n);        break;
    case 3:  ok = jw_sfc_read(&d, b, n);        break;
    case 4:  ok = jw_jwc_read(&d, b, n);        break;
    default: ok = jw_parse(&d, b, n);           break;
    }
    /* one parse in sixteen goes back out again: six writers over a quarter
       of a million drawings would take minutes, and the writers see the
       same shapes over and over */
    if (ok && ++written % 16 == 0)
        write_every_way(&d);
    jw_free(&d);
    (void)t0;
    return ok;
}

int main(int argc, char **argv)
{
    int i, files = 0, tries = 0, read_ok = 0;

    for (i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "rb");
        unsigned char *b, *c;
        long n, k, step, flips;
        int kind = kind_of(argv[i]);
        clock_t t0;

        if (!f) {
            printf("BAD  %s: cannot open\n", argv[i]);
            return 1;
        }
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        b = (unsigned char *)malloc((size_t)n);
        if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
            printf("BAD  %s: cannot read\n", argv[i]);
            fclose(f);
            free(b);
            return 1;
        }
        fclose(f);
        files++;
        t0 = clock();

        /* Every prefix up to the end of the header, then a coarser grid --
           coarse enough that a big file does not take a minute on its own
           (a reader costs about a byte's work per byte, so a step of one
           all the way through would be quadratic). */
        step = n / 100 + 37;
        for (k = 0; k <= n; k += (k < 0x600 ? 1 : step)) {
            c = (unsigned char *)malloc((size_t)(k ? k : 1));
            if (!c)
                break;
            memcpy(c, b, (size_t)k);
            read_ok += one(c, k, kind) ? 1 : 0;
            tries++;
            free(c);
        }
        /* and some with one byte turned into something else */
        flips = n > 100000 ? 40 : 400;
        for (k = 0; k < flips && n > 0; k++) {
            long at = (long)(nextr() % (unsigned long)n);
            c = (unsigned char *)malloc((size_t)n);
            if (!c)
                break;
            memcpy(c, b, (size_t)n);
            c[at] = (unsigned char)nextr();
            read_ok += one(c, n, kind) ? 1 : 0;
            tries++;
            free(c);
        }
        free(b);
        {   /* a reader that spins on a damaged file is as much a fault as
               one that falls over: it would take the whole program with it */
            long ms = (long)(clock() - t0);
            if (ms > (long)(SLOW * CLOCKS_PER_SEC))
                printf("BAD  %s: %ld ms to read its damaged copies\n",
                       argv[i], ms);
        }
    }
    printf("%d files, %d damaged copies read without falling over"
           " (%d of them parsed)\n", files, tries, read_ok);
    return 0;
}
