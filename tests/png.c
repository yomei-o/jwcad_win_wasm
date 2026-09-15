/* Just enough of zlib to write a valid PNG: CRC-32, Adler-32 and a deflate
 * stream made only of stored (uncompressed) blocks.  The files come out
 * bigger than they need to be, but they are throwaway comparison output and
 * this keeps the tests free of external dependencies.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "png.h"

static unsigned crc_tab[256];
static int crc_ready;

static void crc_init(void)
{
    unsigned n, k, c;

    for (n = 0; n < 256; n++) {
        c = n;
        for (k = 0; k < 8; k++)
            c = (c & 1) ? 0xedb88320u ^ (c >> 1) : c >> 1;
        crc_tab[n] = c;
    }
    crc_ready = 1;
}

static unsigned crc32x(unsigned crc, const unsigned char *b, size_t n)
{
    if (!crc_ready)
        crc_init();
    crc ^= 0xffffffffu;
    while (n--)
        crc = crc_tab[(crc ^ *b++) & 0xff] ^ (crc >> 8);
    return crc ^ 0xffffffffu;
}

static unsigned adler32x(const unsigned char *b, size_t n)
{
    unsigned a = 1, s = 0;
    size_t i;

    for (i = 0; i < n; i++) {
        a = (a + b[i]) % 65521;
        s = (s + a) % 65521;
    }
    return (s << 16) | a;
}

static void be32(unsigned char *p, unsigned v)
{
    p[0] = (unsigned char)(v >> 24);
    p[1] = (unsigned char)(v >> 16);
    p[2] = (unsigned char)(v >> 8);
    p[3] = (unsigned char)v;
}

static void chunk(FILE *f, const char *tag, const unsigned char *d, size_t n)
{
    unsigned char hdr[8];
    unsigned char crc[4];
    unsigned c;

    be32(hdr, (unsigned)n);
    memcpy(hdr + 4, tag, 4);
    fwrite(hdr, 1, 8, f);
    if (n)
        fwrite(d, 1, n, f);
    c = crc32x(0, hdr + 4, 4);
    c = crc32x(c, d, n);
    be32(crc, c);
    fwrite(crc, 1, 4, f);
}

int png_rgb(const char *path, int w, int h, const unsigned int *px)
{
    static const unsigned char sig[8] = {137, 80, 78, 71, 13, 10, 26, 10};
    unsigned char ihdr[13];
    unsigned char *raw, *z;
    size_t rawn, zn, o, i;
    int y, x;
    FILE *f;

    /* one filter byte then 3 bytes a pixel, per row */
    rawn = (size_t)h * (1 + (size_t)w * 3);
    raw = (unsigned char *)malloc(rawn);
    if (!raw)
        return 0;
    o = 0;
    for (y = 0; y < h; y++) {
        raw[o++] = 0;                       /* filter: none */
        for (x = 0; x < w; x++) {
            unsigned int c = px[(size_t)y * w + x];
            raw[o++] = (unsigned char)(c >> 16);
            raw[o++] = (unsigned char)(c >> 8);
            raw[o++] = (unsigned char)c;
        }
    }

    /* 2 bytes of zlib header, then stored blocks of at most 65535, then the
     * Adler-32 of the uncompressed data. */
    zn = 2 + 4 + ((rawn + 65534) / 65535) * 5 + rawn;
    z = (unsigned char *)malloc(zn);
    if (!z) {
        free(raw);
        return 0;
    }
    o = 0;
    z[o++] = 0x78;
    z[o++] = 0x01;
    for (i = 0; i < rawn; ) {
        size_t n = rawn - i;
        int last;
        if (n > 65535)
            n = 65535;
        last = (i + n == rawn);
        z[o++] = (unsigned char)last;
        z[o++] = (unsigned char)(n & 0xff);
        z[o++] = (unsigned char)(n >> 8);
        z[o++] = (unsigned char)(~n & 0xff);
        z[o++] = (unsigned char)((~n >> 8) & 0xff);
        memcpy(z + o, raw + i, n);
        o += n;
        i += n;
    }
    be32(z + o, adler32x(raw, rawn));
    o += 4;

    f = fopen(path, "wb");
    if (!f) {
        free(raw);
        free(z);
        return 0;
    }
    fwrite(sig, 1, 8, f);
    be32(ihdr, (unsigned)w);
    be32(ihdr + 4, (unsigned)h);
    ihdr[8] = 8;        /* bit depth   */
    ihdr[9] = 2;        /* colour type: truecolour */
    ihdr[10] = 0;
    ihdr[11] = 0;
    ihdr[12] = 0;
    chunk(f, "IHDR", ihdr, 13);
    chunk(f, "IDAT", z, o);
    chunk(f, "IEND", 0, 0);
    fclose(f);
    free(raw);
    free(z);
    return 1;
}
