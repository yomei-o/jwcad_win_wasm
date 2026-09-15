/* A minimal truecolour PNG writer for the test harnesses (tests/png.c). */
#ifndef JW_PNG_H
#define JW_PNG_H

/* px is w*h pixels of 0x00RRGGBB. */
int png_rgb(const char *path, int w, int h, const unsigned int *px);

#endif
