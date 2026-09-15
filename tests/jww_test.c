/* Read every drawing named on the command line and report what came out.
 * The parse has to land exactly on the end of the file: get one record length
 * wrong and everything after it is out of step, which shows up here. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/jww.h"

static int one(const char *path)
{
    static const char *NAMES[JW_NCLASS] = {
        "line", "arc", "point", "text", "solid"
    };
    unsigned char *b;
    long n;
    FILE *f = fopen(path, "rb");
    jw_drawing d;
    int i, count[JW_NCLASS];

    if (!f) {
        printf("BAD   %s: cannot open\n", path);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
        printf("BAD   %s: cannot read\n", path);
        fclose(f);
        free(b);
        return 1;
    }
    fclose(f);

    if (!jw_parse(&d, b, n)) {
        printf("BAD   %s: %s\n", path, d.error);
        free(b);
        jw_free(&d);
        return 1;
    }
    memset(count, 0, sizeof count);
    for (i = 0; i < d.nobj; i++)
        count[d.obj[i].cls]++;
    printf("ok    %-30s v%d  %5d objects ", path, d.version, d.nobj);
    for (i = 0; i < JW_NCLASS; i++)
        if (count[i])
            printf(" %s %d", NAMES[i], count[i]);
    printf("\n");
    free(b);
    jw_free(&d);
    return 0;
}

int main(int argc, char **argv)
{
    int i, bad = 0;

    for (i = 1; i < argc; i++)
        bad |= one(argv[i]);
    return bad;
}
