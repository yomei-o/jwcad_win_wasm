/* png_encode -- see src/png.h. */
#include "png.h"

#include <stdlib.h>
#include <string.h>

static unsigned long crc_table[256];
static int crc_ready;

static void crc_init(void)
{
    unsigned long c;
    int n, k;

    for (n = 0; n < 256; n++) {
        c = (unsigned long)n;
        for (k = 0; k < 8; k++) {
            c = (c & 1) ? 0xedb88320UL ^ (c >> 1) : c >> 1;
        }
        crc_table[n] = c;
    }
    crc_ready = 1;
}

static unsigned long crc32_of(const unsigned char *p, long n)
{
    unsigned long c = 0xffffffffUL;
    long i;

    if (!crc_ready) {
        crc_init();
    }
    for (i = 0; i < n; i++) {
        c = crc_table[(c ^ p[i]) & 0xff] ^ (c >> 8);
    }
    return c ^ 0xffffffffUL;
}

static unsigned long adler32_of(const unsigned char *p, long n)
{
    unsigned long a = 1, b = 0;
    long i;

    for (i = 0; i < n; i++) {
        a = (a + p[i]) % 65521;
        b = (b + a) % 65521;
    }
    return (b << 16) | a;
}

static void put32(unsigned char *p, unsigned long v)
{
    p[0] = (unsigned char)(v >> 24);
    p[1] = (unsigned char)(v >> 16);
    p[2] = (unsigned char)(v >> 8);
    p[3] = (unsigned char)v;
}

/* One chunk: length, type, data, CRC over type+data. */
static long chunk(unsigned char *out, const char *type,
                  const unsigned char *data, long n)
{
    put32(out, (unsigned long)n);
    memcpy(out + 4, type, 4);
    if (n) {
        memcpy(out + 8, data, (size_t)n);
    }
    put32(out + 8 + n, crc32_of(out + 4, n + 4));
    return n + 12;
}

/* Deflate with the fixed Huffman code.
 *
 * Stored blocks alone made an A-1 plot twelve megabytes: a sheet of paper is
 * mostly white, and white is the same three bytes over and over.  The fixed
 * code costs no table and turns a run into a length/distance pair, which is
 * all that is needed here -- the rows also go through PNG's Up filter first,
 * so a row that repeats the one above it is a run of zeroes.
 */
typedef struct {
    unsigned char *p;
    long n, cap;
    unsigned long bits;
    int nbits;
} Bits;

static void bits_put(Bits *b, unsigned long v, int n)
{
    b->bits |= v << b->nbits;
    b->nbits += n;
    while (b->nbits >= 8) {
        if (b->n < b->cap) {
            b->p[b->n++] = (unsigned char)(b->bits & 0xff);
        }
        b->bits >>= 8;
        b->nbits -= 8;
    }
}

/* Huffman codes go in most-significant-bit first, which is the other way
 * round from everything else in a deflate stream. */
static void bits_code(Bits *b, unsigned long v, int n)
{
    int i;

    for (i = n - 1; i >= 0; i--) {
        bits_put(b, (v >> i) & 1, 1);
    }
}

static void fixed_literal(Bits *b, int c)
{
    if (c < 144) {
        bits_code(b, 0x30 + c, 8);
    } else if (c < 256) {
        bits_code(b, 0x190 + c - 144, 9);
    } else if (c < 280) {
        bits_code(b, c - 256, 7);
    } else {
        bits_code(b, 0xc0 + c - 280, 8);
    }
}

static const short LEN_BASE[29] = {
    3, 4, 5, 6, 7, 8, 9, 10, 11, 13, 15, 17, 19, 23, 27, 31, 35, 43, 51, 59,
    67, 83, 99, 115, 131, 163, 195, 227, 258
};
static const unsigned char LEN_EXTRA[29] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4,
    5, 5, 5, 5, 0
};
static const short DIST_BASE[30] = {
    1, 2, 3, 4, 5, 7, 9, 13, 17, 25, 33, 49, 65, 97, 129, 193, 257, 385, 513,
    769, 1025, 1537, 2049, 3073, 4097, 6145, 8193, 12289, 16385, 24577
};
static const unsigned char DIST_EXTRA[30] = {
    0, 0, 0, 0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 9, 10, 10,
    11, 11, 12, 12, 13, 13
};

#define HASH_BITS 15
#define HASH_SIZE (1 << HASH_BITS)

static long deflate_fixed(const unsigned char *in, long n,
                          unsigned char *out, long cap)
{
    Bits b;
    long *head = (long *)malloc(sizeof(long) * HASH_SIZE);
    long *prev = (long *)malloc(sizeof(long) * (size_t)(n > 0 ? n : 1));
    long i;

    if (!head || !prev) {
        free(head);
        free(prev);
        return -1;
    }
    for (i = 0; i < HASH_SIZE; i++) {
        head[i] = -1;
    }
    b.p = out;
    b.n = 0;
    b.cap = cap;
    b.bits = 0;
    b.nbits = 0;
    bits_put(&b, 1, 1);         /* BFINAL */
    bits_put(&b, 1, 2);         /* fixed Huffman */
    i = 0;
    while (i < n) {
        long best = 0, best_at = 0, stop;

        if (i + 3 <= n) {
            const unsigned h = (unsigned)(((unsigned)in[i] << 10)
                                          ^ ((unsigned)in[i + 1] << 5)
                                          ^ (unsigned)in[i + 2])
                               & (HASH_SIZE - 1);
            long at = head[h];
            int tries = 0;

            while (at >= 0 && i - at <= 32768 && tries < 32) {
                long k = 0;

                while (k < 258 && i + k < n && in[at + k] == in[i + k]) {
                    k++;
                }
                if (k > best) {
                    best = k;
                    best_at = at;
                    if (best >= 258) {
                        break;
                    }
                }
                at = prev[at];
                tries++;
            }
            prev[i] = head[h];
            head[h] = i;
        }
        if (best >= 3) {
            int lc = 0, dc = 0;

            while (lc < 28 && LEN_BASE[lc + 1] <= best) {
                lc++;
            }
            while (dc < 29 && DIST_BASE[dc + 1] <= i - best_at) {
                dc++;
            }
            fixed_literal(&b, 257 + lc);
            bits_put(&b, (unsigned long)(best - LEN_BASE[lc]), LEN_EXTRA[lc]);
            bits_code(&b, (unsigned long)dc, 5);
            bits_put(&b, (unsigned long)(i - best_at - DIST_BASE[dc]),
                     DIST_EXTRA[dc]);
            /* The bytes inside a match still have to go in the table, or
             * the next match cannot reach back past them.  `stop` is where
             * the match ends -- **counted from here**, not from where the
             * match was found; taking it from there put twice as many bytes
             * in the stream. */
            stop = i + best;
            for (i++; i < stop; i++) {
                if (i + 3 <= n) {
                    const unsigned h =
                        (unsigned)(((unsigned)in[i] << 10)
                                   ^ ((unsigned)in[i + 1] << 5)
                                   ^ (unsigned)in[i + 2]) & (HASH_SIZE - 1);

                    prev[i] = head[h];
                    head[h] = i;
                }
            }
        } else {
            fixed_literal(&b, in[i]);
            i++;
        }
    }
    fixed_literal(&b, 256);     /* end of block */
    if (b.nbits) {
        bits_put(&b, 0, 8 - b.nbits);
    }
    free(head);
    free(prev);
    return b.n <= b.cap ? b.n : -1;
}

unsigned char *png_encode(const unsigned char *rgb, int w, int h, long *len)
{
    static const unsigned char SIG[8] =
        { 137, 'P', 'N', 'G', 13, 10, 26, 10 };
    const long raw_len = (long)h * ((long)w * 3 + 1);
    unsigned char *raw, *z, *out, ihdr[13];
    long zi = 0, at = 0, i;
    int y;

    if (w <= 0 || h <= 0) {
        return 0;
    }
    /* The filtered rows: filter 0 (none) in front of each. */
    raw = (unsigned char *)malloc((size_t)raw_len);
    if (!raw) {
        return 0;
    }
    for (y = 0; y < h; y++) {
        const long row = (long)y * ((long)w * 3 + 1);
        const unsigned char *src = rgb + (long)y * (long)w * 3;
        long x;

        /* Filter 2, Up: a row the same as the one above it becomes zeroes,
         * which is what most of a sheet of paper is. */
        raw[row] = (unsigned char)(y ? 2 : 0);
        if (y) {
            const unsigned char *above = src - (long)w * 3;

            for (x = 0; x < (long)w * 3; x++) {
                raw[row + 1 + x] = (unsigned char)(src[x] - above[x]);
            }
        } else {
            memcpy(raw + row + 1, src, (size_t)w * 3);
        }
    }
    /* zlib: two header bytes, stored deflate blocks, the Adler sum. */
    z = (unsigned char *)malloc((size_t)(raw_len + raw_len / 65535 + 64));
    if (!z) {
        free(raw);
        return 0;
    }
    z[zi++] = 0x78;
    z[zi++] = 0x01;
    i = deflate_fixed(raw, raw_len, z + zi, raw_len + raw_len / 65535 + 32);
    if (i < 0) {
        /* No memory for the tables, or it came out longer than the bytes
         * themselves: fall back on stored blocks, which always fit. */
        zi = 2;
        for (i = 0; i < raw_len; i += 65535) {
            long n = raw_len - i < 65535 ? raw_len - i : 65535;

            z[zi++] = (unsigned char)(i + n >= raw_len);    /* BFINAL */
            z[zi++] = (unsigned char)(n & 0xff);
            z[zi++] = (unsigned char)(n >> 8);
            z[zi++] = (unsigned char)(~n & 0xff);
            z[zi++] = (unsigned char)((~n >> 8) & 0xff);
            memcpy(z + zi, raw + i, (size_t)n);
            zi += n;
        }
    } else {
        zi += i;
    }
    put32(z + zi, adler32_of(raw, raw_len));
    zi += 4;
    free(raw);

    out = (unsigned char *)malloc((size_t)(zi + 128));
    if (!out) {
        free(z);
        return 0;
    }
    memcpy(out, SIG, sizeof SIG);
    at = sizeof SIG;
    put32(ihdr, (unsigned long)w);
    put32(ihdr + 4, (unsigned long)h);
    ihdr[8] = 8;                /* eight bits a channel */
    ihdr[9] = 2;                /* truecolour */
    ihdr[10] = 0;
    ihdr[11] = 0;
    ihdr[12] = 0;
    at += chunk(out + at, "IHDR", ihdr, 13);
    at += chunk(out + at, "IDAT", z, zi);
    at += chunk(out + at, "IEND", 0, 0);
    free(z);
    *len = at;
    return out;
}
