/* Write a drawing out, read it back, write it again -- and the two
 * writings have to be the same bytes.
 *
 * Why this is worth having.  The byte-for-byte tests hold the port's output
 * against files the original wrote, which is the strongest check there is
 * -- but only for the drawings someone made the original write.  Two files
 * cover the coordinate format and they use three of the ten words a text
 * can go out under; the other seven went out wrong for months and nothing
 * noticed (docs/notes-formats.md,「文字の語を 3 から 10 に広げました」).
 *
 * A round trip needs no answer file at all.  It cannot say the bytes are
 * what Jw_cad would write, but it does say the writer and the reader agree
 * -- so anything the writer puts down that the reader drops, or reads back
 * as something else, shows up at once.  That is exactly the shape of the
 * bug above, and it covers every drawing rather than the two with answers.
 *
 * What it cannot check: whether the first writing is right.  A writer that
 * is wrong in the same way twice passes.  This is a net under the answer
 * files, not a replacement for them.
 *
 * **It reports rather than judges, and check.sh does not run it.**  Most of
 * what it finds is a format being lossy on purpose -- a coordinate file
 * read back comes in as a 図形 with its layers flattened, so the second
 * writing is legitimately shorter, and the SFC reader wraps what it reads
 * in a 図形 as the original does.  Telling those from a real disagreement
 * needs a model of what each format carries, which is a job of its own.
 * Until then this prints the sizes and where two writings part, for
 * someone to look at.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%s %s
", ok ? "same" : "----", what);
    if (!ok)
        fails++;
}

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;
    long k;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    k = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)k + 1);
    if (!b) {
        fclose(f);
        return 0;
    }
    if (fread(b, 1, (size_t)k, f) != (size_t)k) {
        fclose(f);
        free(b);
        return 0;
    }
    fclose(f);
    *n = k;
    return b;
}

enum { F_DXF, F_SFC, F_JWC, F_COORD, F_N };

static const char *fname[F_N] = { "DXF", "SFC", "JWC", "座標ファイル" };

static int put(int kind, const jw_drawing *d, unsigned char **out, long *n)
{
    switch (kind) {
    case F_DXF:
        return jw_dxf_write(d, out, n);
    case F_SFC:
        return jw_sfc_write(d, "x.sfc", "2026-09-27T00:00:00", out, n);
    case F_JWC:
        return jw_jwc_write(d, out, n);
    default:
        return jw_write_coord(d, 0.0, 0.0, out, n);
    }
}

static int get(int kind, jw_drawing *d, const jw_drawing *host,
               const unsigned char *b, long n)
{
    switch (kind) {
    case F_DXF:
        return jw_dxf_read(d, b, n);
    case F_SFC:
        return jw_sfc_read(d, b, n);
    case F_JWC:
        return jw_jwc_read(d, b, n);
    default:
        return jw_parse_coord(d, host, b, n);
    }
}

static void trip(const char *path, int kind)
{
    jw_drawing d, back;
    unsigned char *b, *one = 0, *two = 0;
    long n = 0, n1 = 0, n2 = 0, i;
    char what[200];

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot open %s\n", path);
        fails++;
        return;
    }
    memset(&d, 0, sizeof d);
    if (!jw_parse(&d, b, n)) {
        printf("BAD  cannot read %s\n", path);
        fails++;
        free(b);
        return;
    }
    free(b);
    for (i = 0; i < d.nobj; i++)
        d.obj[i].sel = 1;

    if (!put(kind, &d, &one, &n1) || !one) {
        sprintf(what, "  %s -> %s: writes nothing", path, fname[kind]);
        ck(0, what);
        jw_free(&d);
        return;
    }
    memset(&back, 0, sizeof back);
    if (!get(kind, &back, &d, one, n1)) {
        sprintf(what, "  %s -> %s: cannot read its own output", path,
                fname[kind]);
        ck(0, what);
        free(one);
        jw_free(&d);
        return;
    }
    for (i = 0; i < back.nobj; i++)
        back.obj[i].sel = 1;
    if (!put(kind, &back, &two, &n2) || !two) {
        sprintf(what, "  %s -> %s: the second writing is empty", path,
                fname[kind]);
        ck(0, what);
        free(one);
        jw_free(&d);
        jw_free(&back);
        return;
    }
    sprintf(what, "  %s -> %s -> back -> %s: the same bytes (%ld)",
            path, fname[kind], fname[kind], n1);
    if (n1 != n2) {
        printf("     first %ld bytes, second %ld\n", n1, n2);
        ck(0, what);
    } else {
        long bad = -1;

        for (i = 0; i < n1; i++)
            if (one[i] != two[i]) {
                bad = i;
                break;
            }
        if (bad >= 0)
            printf("     they part at byte %ld: %02x against %02x\n",
                   bad, one[bad], two[bad]);
        ck(bad < 0, what);
    }
    free(one);
    free(two);
    jw_free(&d);
    jw_free(&back);
}

int main(int argc, char **argv)
{
    static const char *drawings[] = {
        "orig/Test1.jww", "orig/Test5.jww", "orig/Test6.jww",
        "orig/Test7.jww"
    };
    int k, i;

    (void)argc;
    (void)argv;
    for (k = 0; k < F_N; k++)
        for (i = 0; i < (int)(sizeof drawings / sizeof drawings[0]); i++)
            trip(drawings[i], k);
    printf("%d of the round trips came back with the same bytes, %d did"
           " not -- read the note at the top of this file before calling"
           " any of them a fault\n", F_N * 4 - fails, fails);
    return 0;
}
