/* CP932 <-> UTF-16, for the strings in a version 700 drawing.
 *
 * Everything else in the port holds CP932: that is what the shipped drawings
 * hold, and what the fonts are indexed by.  Jw_cad 10 writes UTF-16 in the
 * file, so these two sit at the edge and nothing else has to know.
 *
 * The tables are src/gen/cp932.h, written by tools/mkcp932.py.
 */
#ifndef JW_CP932_H
#define JW_CP932_H

/* `n` UTF-16 units -> CP932 bytes.  Returns how many bytes it would take,
   whether or not they fitted; `out` gets at most `cap` of them and is not
   terminated.  A character CP932 has no room for becomes '?', which is what
   WideCharToMultiByte does with no best-fit table. */
long jw_from_utf16(const unsigned short *s, long n, char *out, long cap);

/* CP932 bytes -> UTF-16 units, the same way round.  A trailing lead byte or
   an unmapped pair becomes U+FFFD, so the length is never a surprise. */
long jw_to_utf16(const char *s, long n, unsigned short *out, long cap);

#endif
