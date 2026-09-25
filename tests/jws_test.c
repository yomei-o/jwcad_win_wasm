/* The 図形 reader and writer against every figure Jw_cad ships.
 *
 *   tests/jws_test.exe <every figure>   (tools/check.sh hands it the lot)
 *
 * Two checks per file.  The first is the one tests/jww_test.c makes of the
 * drawing reader: a file is understood only when the parse **lands exactly
 * on its end**.  Anything else means a record was read with the wrong shape
 * and everything after it is guesswork.
 *
 * The second is the round trip.  Reading a figure and writing it straight
 * back out has to give the same bytes, which is a far stricter statement
 * than the parse landing right: every field has to come back in the order
 * and the width it went in, and the header has to be kept rather than
 * invented.  That is what 図形登録 needs to be able to lean on.
 *
 * Jw_cad comes with 341 of them, in six folders of its own and five more
 * below those, and they are a wider sample than anything the port makes
 * itself: two versions of the format (351 and 600), all the element kinds,
 * and figures with blocks in them.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"

int main(int argc, char **argv)
{
    int i, ok = 0, bad = 0, same = 0;

    for (i = 1; i < argc; i++) {
        jw_drawing d;
        unsigned char *b, *w = 0;
        long n, wn = 0;
        double bx = 0, by = 0;
        FILE *f = fopen(argv[i], "rb");

        if (!f) {
            printf("BAD  %s: cannot open\n", argv[i]);
            bad++;
            continue;
        }
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        b = (unsigned char *)malloc((size_t)n);
        if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
            printf("BAD  %s: cannot read\n", argv[i]);
            fclose(f);
            free(b);
            bad++;
            continue;
        }
        fclose(f);
        memset(&d, 0, sizeof d);
        if (!jw_parse_jws(&d, b, n, &bx, &by)) {
            printf("BAD  %s: %s\n", argv[i], d.error ? d.error : "?");
            bad++;
            jw_free(&d);
            free(b);
            continue;
        }
        ok++;
        if (!jw_write_jws(&d, bx, by, &w, &wn)) {
            printf("BAD  %s: cannot write it back\n", argv[i]);
            bad++;
        } else if (wn != n) {
            printf("BAD  %s: written back as %ld bytes, not %ld\n",
                   argv[i], wn, n);
            bad++;
        } else {
            long k = 0;

            while (k < n && w[k] == b[k])
                k++;
            if (k < n) {
                printf("BAD  %s: byte %ld is %02x, was %02x\n",
                       argv[i], k, w[k], b[k]);
                bad++;
            } else {
                same++;
            }
        }
        free(w);
        jw_free(&d);
        free(b);
    }
    printf("%d read, %d written back the same, of %d\n", ok, same, argc - 1);
    return bad ? 1 : 0;
}
