#include <string.h>

#include "cp932.h"
#include "gen/cp932.h"

static int find(const unsigned short *tab, int n, unsigned v)
{
    int lo = 0, hi = n - 1;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (tab[mid] == v)
            return mid;
        if (tab[mid] < v)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

long jw_from_utf16(const void *src, long n, char *out, long cap)
{
    /* The units are taken a byte pair at a time rather than through an
       `unsigned short *`: a .jww's strings sit wherever they fall in the
       file, so jww.c's pool_put hands this an odd address as often as not,
       and reading a short from there is undefined.  x86 and wasm both let
       it through, which is why it went unnoticed until the port was built
       with -fsanitize=undefined (tools/asan.sh). */
    const unsigned char *b = (const unsigned char *)src;
    long i, m = 0;

    for (i = 0; i < n; i++) {
        unsigned short w;
        unsigned u;

        memcpy(&w, b + 2 * i, sizeof w);
        u = w;
        unsigned c;
        int k;
        if (u < 0x80) {
            c = u;
        } else {
            k = find(jw_cp932_wide, JW_CP932_NENC, u);
            c = k < 0 ? '?' : jw_cp932_narrow[k];
        }
        if (c > 0xff) {
            if (m < cap)
                out[m] = (char)(unsigned char)(c >> 8);
            m++;
        }
        if (m < cap)
            out[m] = (char)(unsigned char)c;
        m++;
    }
    return m;
}

long jw_to_utf16(const char *s, long n, unsigned short *out, long cap)
{
    long i = 0, m = 0;

    while (i < n) {
        unsigned c = (unsigned char)s[i];
        unsigned u;
        int k;
        if (c < 0x80) {
            u = c;
            i++;
        } else {
            unsigned pair = c;
            /* a lead byte takes the next one with it */
            if (((c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc))
                && i + 1 < n)
                pair = (c << 8) | (unsigned char)s[i + 1];
            k = find(jw_cp932_code, JW_CP932_NDEC, pair);
            if (k < 0 && pair > 0xff) {
                pair = c;
                k = find(jw_cp932_code, JW_CP932_NDEC, pair);
            }
            u = k < 0 ? 0xfffd : jw_cp932_uni[k];
            i += pair > 0xff ? 2 : 1;
        }
        if (m < cap)
            out[m] = (unsigned short)u;
        m++;
    }
    return m;
}
