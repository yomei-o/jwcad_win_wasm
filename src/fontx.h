/* FONTX2 fonts, read from memory.
 *
 * Jw_cad asks Windows for a font (CreateFontIndirectW with the face name the
 * drawing carries, usually ＭＳ ゴシック) so the port cannot draw the same
 * glyphs -- it has no licence to that typeface.  What it can match is where
 * the text sits, how big it is and what colour: the shapes are a stand-in.
 *
 * The stand-in is the Shinonome bitmap font, which is public domain; see
 * font/PROVENANCE.md.  Both builds carry the same bytes (src/gen/jwfont.c,
 * built by tools/mkfont.py) so the native and browser screens agree.
 */
#ifndef JW_FONTX_H
#define JW_FONTX_H

typedef struct {
    const unsigned char *data;
    long len;
    int width, height;
    int dbcs;                   /* 1 = two-byte codes with a block table */
    int blocks;
    long images;
} fontx_t;

int fontx_open(fontx_t *f, const unsigned char *data, long len);

/* The glyph for `code`, or NULL.  (width + 7) / 8 * height bytes, one bit a
 * pixel, the leftmost pixel in the high bit. */
const unsigned char *fontx_glyph(const fontx_t *f, unsigned code);

#endif
