/* A PNG out of an RGB buffer, with no library.
 *
 * The plot has to leave the browser as a file, and a .png is what a person
 * can look at without anything installed.  There is no zlib here: a deflate
 * stream is allowed to be nothing but stored blocks, which costs five bytes
 * per 65,535 and is a hundred lines instead of a dependency.
 */
#ifndef JW_PNG_H
#define JW_PNG_H

/* `rgb` is w*h*3 bytes, row by row from the top.  Returns a malloc'd PNG and
 * puts its length in `*len`; NULL if there was no memory for it. */
unsigned char *png_encode(const unsigned char *rgb, int w, int h, long *len);

#endif
