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
#include "../src/app.h"

/* The damage is the same every run, so a fault found here can be looked at
   again.  JW_FUZZ_SEED picks another set, for a longer soak. */
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
    /* And once in a while, draw it.  Reading and writing a damaged drawing
       was all this ever did, and the numbers in it only reach the screen
       through src/ui.c and src/draw.c -- which is where a text style of
       1e300 went into a sixteen-byte "%.2f" and a sun figure into a
       sixty-four byte one.  Painting is far slower than parsing, so this is
       a sample, at a small window. */
    if (ok && written % 512 == 0 && app_resize(320, 240)) {
        unsigned char *raw = 0;
        long rawn = 0;
        if (jw_write(&d, &raw, &rawn)) {
            if (app_open(raw, rawn))
                app_paint();
            free(raw);
        }
    }
    jw_free(&d);
    (void)t0;
    return ok;
}

/* And a few drawings no file would hold, put together by hand: the writers
 * have to come back from these too.  The text of five thousand characters is
 * the one that matters -- src/sfcwrite.c used to format the string into a
 * buffer of 1,024 bytes on the stack, and a .jww can carry a text as long as
 * it likes. */
static void monsters(void)
{
    jw_drawing d;
    char *big = (char *)malloc(5001);
    jw_obj *o;
    int i;

    if (!big)
        return;
    for (i = 0; i < 5000; i++)
        big[i] = (char)('a' + i % 26);
    big[5000] = 0;

    memset(&d, 0, sizeof d);
    d.version = 700;
    d.paper_hw = 297;
    d.paper_hh = 210;
    d.name = -1;
    for (i = 0; i < 16; i++) {
        int k;
        d.group[i].scale = 1.0;
        d.group[i].name = -1;
        for (k = 0; k < 16; k++)
            d.group[i].layer_name[k] = -1;
    }
    d.group[0].state = 3;
    for (i = 0; i < 10; i++) {
        d.pen_rgb[i] = 0;
        d.pen_width[i] = 1;
    }
    o = jw_add(&d, JW_MOJI);
    if (o) {
        o->d[0] = 0; o->d[1] = 0; o->d[2] = 1000; o->d[3] = 0;
        o->d[4] = 10; o->d[5] = 10;
        o->text = jw_add_str(&d, big);
        o->face = jw_add_str(&d, big);
    }
    o = jw_add(&d, JW_SEN);
    if (o) {                    /* and one at the edge of what is allowed */
        o->d[0] = -9e11; o->d[1] = -9e11;
        o->d[2] = 9e11;  o->d[3] = 9e11;
    }
    d.group[0].layer_name[0] = jw_add_str(&d, big);
    d.name = jw_add_str(&d, big);
    write_every_way(&d);
    jw_free(&d);
    free(big);
}

int main(int argc, char **argv)
{
    int i, files = 0, tries = 0, read_ok = 0;
    const char *seed = getenv("JW_FUZZ_SEED");
    const int trace = getenv("JW_FUZZ_TRACE") != 0;

    if (seed && *seed) {
        rng = strtoul(seed, 0, 0);
        if (!rng)
            rng = 1;            /* the shift register has to start somewhere */
    }

    for (i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "rb");
        unsigned char *b, *c;
        long n, k, step, phase, flips;
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
           all the way through would be quadratic).
           The coarse part is shifted by the seed.  Without that the cuts
           were the same in every run and only the flips below moved, so
           twenty seeds walked the same few thousand truncations twenty
           times; now each seed cuts a big file somewhere else.  The dense
           part is left alone: it covers the headers, which is where both
           the sfcread and the jw_parse_jws holes turned up (a .sfc cut to
           304 bytes and a .jws cut to 348). */
        step = n / 100 + 37;
        phase = (long)(nextr() % (unsigned long)step);
        for (k = 0; k <= n; k += (k < 0x600 ? 1 : step)) {
            long cut = k < 0x600 ? k : k + phase;

            if (cut > n)
                break;
            c = (unsigned char *)malloc((size_t)(cut ? cut : 1));
            if (!c)
                break;
            memcpy(c, b, (size_t)cut);
            /* JW_FUZZ_TRACE prints the case before it is read, so that a
               run that dies inside a reader says which file and how much of
               it was handed over.  A sanitizer build stops at the fault
               with no stack worth reading, and this is what is left. */
            if (trace) {
                printf("try %s cut to %ld\n", argv[i], cut);
                fflush(stdout);
            }
            read_ok += one(c, cut, kind) ? 1 : 0;
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
    monsters();
    printf("%d files, %d damaged copies read without falling over"
           " (%d of them parsed), and the made-up ones written\n",
           files, tries, read_ok);
    return 0;
}
