/* The picture decoders (BMP, PNG, JPEG) and the gzip reader against damaged
 * files.
 *
 *   tests/imgfuzz_test.exe tmp/img/dec_*.bmp tmp/img/dec_*.png tmp/img/dec_*.jpg ...
 *
 * Every copy is allocated at exactly its length, so with -fsanitize=address
 * (tools/asanone.sh imgfuzz_test files...) a read past the end is a report.
 * Each file is cut short at every length (small files) or on a grid (large
 * ones) and has single bytes, runs of bytes and the 32-bit fields of its
 * header overwritten with extreme values.  A decode may fail, but it has to
 * come back quickly and leave something jw_img_free can let go of.
 * JW_FUZZ_SEED picks another set of damage, JW_FUZZ_ROUNDS the number of
 * mutated copies per file (default 4000). */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/image.h"

static unsigned long rng = 88172645u;
static unsigned long nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return rng;
}

static long ndec, nok;
static double worst;
static const char *worst_name = "";

static void try_one(const unsigned char *src, long n, const char *what)
{
    unsigned char *b = (unsigned char *)malloc(n ? (size_t)n : 1);
    jw_img im;
    clock_t t0 = clock();
    double dt;
    unsigned char *o;
    long on;

    if (!b) return;
    memcpy(b, src, (size_t)n);
    if (getenv("JW_FUZZ_TRACE")) {
        FILE *t = fopen("tmp/imgfuzz_last.bin", "wb");
        if (t) { fwrite(b, 1, (size_t)n, t); fclose(t); }
    }
    if (jw_img_decode(b, n, &im)) {
        nok++;
        jw_img_free(&im);
    }
    ndec++;
    /* the gzip reader sees the same rubbish */
    if (jw_gunzip(b, n, &o, &on)) free(o);
    free(b);
    dt = (double)(clock() - t0) / CLOCKS_PER_SEC;
    if (dt > worst) { worst = dt; worst_name = what; }
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

static const unsigned char EXT[] = { 0x00, 0x01, 0x7f, 0x80, 0xff, 0xfe, 0x10, 0x20 };

int main(int argc, char **argv)
{
    const char *s = getenv("JW_FUZZ_SEED");
    const char *r = getenv("JW_FUZZ_ROUNDS");
    int rounds = r ? atoi(r) : 4000;
    int a;

    if (s) rng = rng * 31u + (unsigned long)atol(s) * 2654435761u + 1u;
    for (a = 1; a < argc; a++) {
        long n, i, k;
        unsigned char *b = slurp(argv[a], &n);
        unsigned char *c;
        long step;

        if (!b) { printf("skip %s\n", argv[a]); continue; }
        /* the whole file first, then every prefix or a grid of them */
        try_one(b, n, argv[a]);
        step = n > 3000 ? n / 1500 : 1;
        for (i = 0; i < n; i += step)
            try_one(b, i, argv[a]);
        c = (unsigned char *)malloc((size_t)n);
        if (!c) { free(b); continue; }
        for (k = 0; k < rounds; k++) {
            long m = 1 + (long)(nextr() % 4);

            memcpy(c, b, (size_t)n);
            while (m-- > 0) {
                long p;

                /* half the damage lands in the first 128 bytes: headers,
                   dimensions, table sizes */
                p = (nextr() & 1) ? (long)(nextr() % (unsigned long)(n < 128 ? n : 128))
                                  : (long)(nextr() % (unsigned long)n);
                switch (nextr() % 4) {
                case 0: c[p] = (unsigned char)nextr(); break;
                case 1: c[p] = EXT[nextr() % sizeof EXT]; break;
                case 2: c[p] ^= (unsigned char)(1u << (nextr() % 8)); break;
                default: {
                    long q, len = 1 + (long)(nextr() % 8);

                    for (q = p; q < p + len && q < n; q++)
                        c[q] = EXT[nextr() % sizeof EXT];
                }
                }
            }
            try_one(c, n, argv[a]);
            /* and the same cut short somewhere */
            try_one(c, (long)(nextr() % (unsigned long)(n + 1)), argv[a]);
        }
        free(c);
        free(b);
    }
    printf("imgfuzz: %ld decodes, %ld read, slowest %.2fs (%s)\n", ndec, nok, worst, worst_name);
    if (worst > 20.0) { printf("BAD  a decode took %.1fs\n", worst); return 1; }
    printf("ok   nothing crashed or hung\n");
    return 0;
}
