#include <string.h>

#include "fontx.h"

static unsigned rd16(const unsigned char *p)
{
    return (unsigned)(p[0] | (p[1] << 8));
}

int fontx_open(fontx_t *f, const unsigned char *data, long len)
{
    memset(f, 0, sizeof *f);
    if (len < 18 || memcmp(data, "FONTX2", 6) != 0)
        return 0;
    f->data = data;
    f->len = len;
    f->width = data[14];
    f->height = data[15];
    f->dbcs = data[16];
    if (f->dbcs) {
        f->blocks = data[17];
        f->images = 18 + 4L * f->blocks;
    } else {
        f->blocks = 0;
        f->images = 17;
    }
    return f->images <= f->len;
}

const unsigned char *fontx_glyph(const fontx_t *f, unsigned code)
{
    long size, at, before = 0;
    int i;

    if (!f->data)
        return 0;
    size = (f->width + 7) / 8 * f->height;
    if (!f->dbcs) {
        if (code > 0xff)
            return 0;
        at = f->images + (long)code * size;
        return at + size <= f->len ? f->data + at : 0;
    }
    /* The images are in code order with the gaps left out, so walk the block
     * table counting the codes that come before this one. */
    for (i = 0; i < f->blocks; i++) {
        unsigned lo = rd16(f->data + 18 + i * 4);
        unsigned hi = rd16(f->data + 20 + i * 4);

        if (code >= lo && code <= hi) {
            at = f->images + (before + (long)(code - lo)) * size;
            return at + size <= f->len ? f->data + at : 0;
        }
        before += (long)(hi - lo) + 1;
    }
    return 0;
}
