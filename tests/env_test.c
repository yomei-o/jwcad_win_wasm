/* 環境設定ファイル 書出し / 読込み (src/cmd.c jw_env_write / jw_env_read)
 * against what the original wrote (decomp/res/env_new.jwf, env_t1.jwf,
 * env_t5.jwf: tools/refenv.sh), and a round trip: the file written from
 * Test5, read into Test1, writes back as Test5's file.
 *
 *   tests/env_test.exe
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static unsigned char *slurp(const char *path, long *n)
{
    FILE *f = fopen(path, "rb");
    unsigned char *b;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

static int same(const unsigned char *a, long an, const unsigned char *b,
                long bn, const char *what)
{
    long i, line = 1;

    if (an == bn && !memcmp(a, b, (size_t)an)) {
        ck(1, what);
        return 1;
    }
    for (i = 0; i < an && i < bn && a[i] == b[i]; i++)
        if (a[i] == '\n')
            line++;
    printf("     first difference at byte %ld (line %d), sizes %ld/%ld\n", i,
           (int)line, an, bn);
    ck(0, what);
    return 0;
}

static int load(jw_drawing *d, const char *path)
{
    long n;
    unsigned char *b = slurp(path, &n);
    int ok;

    memset(d, 0, sizeof *d);
    ok = b && jw_parse(d, b, n);
    free(b);
    return ok;
}

static void against(const char *jww, const char *want, const char *name)
{
    jw_drawing d;
    unsigned char *out = 0, *ref;
    long n = 0, rn;
    char msg[160];

    sprintf(msg, "%s -> %s", jww, want);
    ref = slurp(want, &rn);
    if (!ref || !load(&d, jww) || !jw_env_write(&d, name, &out, &n)) {
        ck(0, msg);
        return;
    }
    same(out, n, ref, rn, msg);
    free(out);
    free(ref);
    jw_free(&d);
}

int main(void)
{
    jw_drawing a, b;
    unsigned char *o1 = 0, *o2 = 0, *ref;
    long n1 = 0, n2 = 0, rn;
    int took;

    against("orig/Test1.jww", "decomp/res/env_t1.jwf", "env_t1.jwf");
    against("orig/Test5.jww", "decomp/res/env_t5.jwf", "env_t5.jwf");

    /* a fresh start */
    app_new();
    ref = slurp("decomp/res/env_new.jwf", &rn);
    if (app_drawing() && ref && app_save_env("env_new.jwf", &o1, &n1))
        same(o1, n1, ref, rn, "new drawing -> env_new.jwf");
    else
        ck(0, "new drawing -> env_new.jwf");
    free(o1);
    o1 = 0;
    free(ref);

    /* round trip: Test5's file read into Test5 after spoiling what the file
       holds, and into Test1, where only the sheet line (S_COMM_0, which is
       not read) may differ */
    ref = slurp("decomp/res/env_t5.jwf", &rn);
    if (!ref || !load(&b, "orig/Test5.jww")) {
        ck(0, "round trip setup");
    } else {
        b.pen_rgb[1] ^= 0x123456;
        b.pen_width[2] += 3;
        b.print_rgb[3] ^= 0x654321;
        b.group[4].scale += 1.0;
        took = jw_env_read(&b, ref, rn);
        ck(took > 0, "read took some lines");
        ck(jw_env_write(&b, "env_t5.jwf", &o2, &n2), "write after read");
        same(o2, n2, ref, rn, "spoiled Test5 + env_t5.jwf -> env_t5.jwf");
        free(o2);
        o2 = 0;
        jw_free(&b);
        if (load(&b, "orig/Test1.jww")) {
            long i = 0, j = 0;
            int ln;
            unsigned char *x = 0;
            long xn = 0, same_lines = 1;

            jw_env_read(&b, ref, rn);
            jw_env_write(&b, "env_t5.jwf", &x, &xn);
            /* compare line by line, leaving the third out */
            for (ln = 1; i < xn && j < rn; ln++) {
                long ie = i, je = j;

                while (ie < xn && x[ie] != '\n')
                    ie++;
                while (je < rn && ref[je] != '\n')
                    je++;
                if (ln != 3 && (ie - i != je - j
                                || memcmp(x + i, ref + j, (size_t)(ie - i)))) {
                    printf("     line %d differs\n", ln);
                    same_lines = 0;
                }
                i = ie + 1;
                j = je + 1;
            }
            ck(same_lines && xn == rn, "Test1 + env_t5.jwf -> env_t5.jwf but for the sheet line");
            free(x);
        }
    }
    free(ref);
    (void)a;
    (void)n1;
    (void)o1;
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
