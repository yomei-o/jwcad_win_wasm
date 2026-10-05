/* The 目盛 of a drawing: its spacing, its least pixel count and its origin.
 *
 *   tools/mesh.exe a.jww [b.jww ...]
 *
 * 目盛基準点 (32912) moves the origin, and the origin is kept in the file,
 * so the command can be measured from what the original saves rather than
 * from a picture of its grid.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"

int main(int argc, char **argv)
{
    static jw_drawing d;
    int k;

    for (k = 1; k < argc; k++) {
        FILE *f = fopen(argv[k], "rb");
        unsigned char *b;
        long n;

        if (!f) {
            printf("%-28s cannot open\n", argv[k]);
            continue;
        }
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        b = (unsigned char *)malloc((size_t)n);
        if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
            printf("%-28s cannot read\n", argv[k]);
            fclose(f);
            free(b);
            continue;
        }
        fclose(f);
        memset(&d, 0, sizeof d);
        if (!jw_parse(&d, b, n))
            printf("%-28s cannot parse\n", argv[k]);
        else
            printf("%-28s min=%g ix=%g iy=%g ox=%.6f oy=%.6f\n", argv[k],
                   d.mesh_min, d.mesh_ix, d.mesh_iy, d.mesh_ox, d.mesh_oy);
        free(b);
    }
    return 0;
}
