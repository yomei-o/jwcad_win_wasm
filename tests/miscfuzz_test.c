/* The readers that are not .jww/.dxf/.sfc/.jwc/pictures, against damaged input:
 * the 外部変形 BAT (header, script, arguments, points), the program's answer
 * (JWC_TEMP.TXT), 座標ファイル, 図形読込, 文読, and the app-level paths that
 * take a file's bytes.
 *
 *   tests/miscfuzz_test.exe orig/*.BAT tmp/spec_gaibu/probe/*.bat orig/Test1.jww
 *
 * The seeds are the files named, plus what the port itself writes (the
 * answer file, a coordinate file, a figure).  Each is cut short at many
 * lengths and has bytes changed; every copy is allocated at exactly its
 * length so -fsanitize=address (tools/asanone.sh miscfuzz_test ...) sees a
 * read past the end.  JW_FUZZ_SEED / JW_FUZZ_ROUNDS as in imgfuzz_test. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

static unsigned long rng = 362436069u;
static unsigned long nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return rng;
}

static unsigned char *slurp(const char *p, long *n)
{
    FILE *f = fopen(p, "rb");
    unsigned char *b;

    if (!f) return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)*n + 1);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) { free(b); b = 0; }
    fclose(f);
    return b;
}

static long ntry;
static jw_drawing host;
static unsigned char *jwbytes;
static long jwn;

/* every consumer, one damaged copy */
static void feed(const unsigned char *src, long n)
{
    unsigned char *b = (unsigned char *)malloc(n ? (size_t)n : 1);
    char *t = (char *)malloc((size_t)n + 1);
    jw_gaibu g;
    jw_gaibu_out go;
    jw_gscript *sc = (jw_gscript *)malloc(sizeof *sc);
    jw_drawing res;
    unsigned char *o;
    long on;
    char msg[200], args[400], val[200][128];
    double xy[200][2];
    int item;

    if (!b || !t || !sc) { free(b); free(t); free(sc); return; }
    memset(val, 0, sizeof val);
    memset(xy, 0, sizeof xy);
    memcpy(b, src, (size_t)n);
    memcpy(t, src, (size_t)n);
    if (getenv("JW_FUZZ_TRACE")) {
        FILE *tf = fopen("tmp/miscfuzz_last.bin", "wb");

        if (tf) { fwrite(src, 1, (size_t)n, tf); fclose(tf); }
        fprintf(stderr, "case %ld len %ld\n", ntry + 1, n);
    }
    t[n] = 0;
    ntry++;

    /* a BAT */
    memset(&g, 0, sizeof g);
    jw_gaibu_header(t, n, &g);
    for (item = 0; item < 3; item++) {
        memset(sc, 0, sizeof *sc);
        if (jw_gaibu_script(t, n, item, sc)) {
            memset(val, 0, sizeof val);
            memset(xy, 0, sizeof xy);
            jw_gaibu_args(sc, val, args, (int)sizeof args);
            jw_gaibu_points(sc, (const double (*)[2])xy, args, (int)sizeof args);
        }
    }
    /* the answer */
    memset(&res, 0, sizeof res);
    memset(&go, 0, sizeof go);
    if (host.nobj >= 0 && jw_gaibu_read(&res, &host, b, n, &go))
        jw_free(&res);
    else
        jw_free(&res);

    /* the app: it keeps its own drawing, so it is the one thing that changes */
    if (ntry % 4 == 0) {
        const char *only = getenv("JW_MF_ONLY");   /* a letter: run just that consumer */
        int all = !only;

        if (all || *only == 'c') app_coord(b, n);
        if (all || *only == 'f') app_figure(b, n);
        if (all || *only == 't') app_text(b, n);
        if (all || *only == 'e') app_gaibu_end(b, n, msg, (int)sizeof msg);
        if ((all || *only == 'b') && app_gaibu_begin(t, n, &o, &on) == 1)
            free(o);
        memset(xy, 0, sizeof xy);
        if ((all || *only == 'B') && app_gaibu_begin2(t, n, 0, (const double (*)[2])xy, val, &o, &on, args, (int)sizeof args) == 1)
            free(o);
        if (ntry % 64 == 0) {
            app_press(300, 300, 0);
            app_press(400, 350, 0);
            app_paint();
        }
    }
    free(b);
    free(t);
    free(sc);
}

int main(int argc, char **argv)
{
    const char *s = getenv("JW_FUZZ_SEED");
    const char *r = getenv("JW_FUZZ_ROUNDS");
    int rounds = r ? atoi(r) : 300;
    int a, nseed = 0;
    unsigned char *seed[64];
    long seedn[64];

    if (s) rng = rng * 31u + (unsigned long)atol(s) * 2654435761u + 1u;
    app_resize(640, 480);
    app_new();
    for (a = 1; a < argc && nseed < 60; a++) {
        long n;
        unsigned char *b = slurp(argv[a], &n);

        if (!b) continue;
        if (n > 1 && b[0] == 'J' && jwbytes == 0 && strstr(argv[a], ".jww")) {
            /* the host drawing the answer is read against */
            jwbytes = b;
            jwn = n;
            continue;
        }
        if (strstr(argv[a], ".jww")) { free(b); continue; }
        seed[nseed] = b;
        seedn[nseed++] = n;
    }
    if (!jwbytes) {
        jwbytes = slurp("orig/Test1.jww", &jwn);
    }
    memset(&host, 0, sizeof host);
    if (jwbytes)
        jw_parse(&host, jwbytes, jwn);
    if (jwbytes && app_open(jwbytes, jwn)) {
        /* what the port writes itself are seeds as well */
        unsigned char *o;
        long on;
        jw_gaibu g;

        memset(&g, 0, sizeof g);
        if (jw_gaibu_write(&host, &g, 0, 0, 0, 0, 1000, 1000, &o, &on) && nseed < 63) {
            seed[nseed] = o;
            seedn[nseed++] = on;
        }
        if (app_coord_save(&o, &on) && nseed < 63) {
            seed[nseed] = o;
            seedn[nseed++] = on;
        }
        if (app_figure_save(&o, &on) && nseed < 63) {
            seed[nseed] = o;
            seedn[nseed++] = on;
        }
    }
    for (a = 0; a < nseed; a++) {
        long n = seedn[a], i, k, step = n > 2000 ? n / 1000 : 1;
        unsigned char *c;

        feed(seed[a], n);
        for (i = 0; i < n; i += step)
            feed(seed[a], i);
        c = (unsigned char *)malloc((size_t)(n ? n : 1));
        if (!c || n < 1) { free(c); continue; }
        for (k = 0; k < rounds; k++) {
            long m = 1 + (long)(nextr() % 4);

            memcpy(c, seed[a], (size_t)n);
            while (m-- > 0) {
                long p = (long)(nextr() % (unsigned long)n);
                static const unsigned char E[] = { 0, 1, 10, 13, 35, 124, 127, 128, 255, '%', '-', '9' };

                if (nextr() & 1) c[p] = (unsigned char)nextr();
                else c[p] = E[nextr() % sizeof E];
            }
            feed(c, n);
            feed(c, (long)(nextr() % (unsigned long)(n + 1)));
        }
        free(c);
    }
    for (a = 0; a < nseed; a++)
        free(seed[a]);
    jw_free(&host);
    free(jwbytes);
    printf("miscfuzz: %ld damaged inputs, %d seeds\nok   nothing crashed or hung\n", ntry, nseed);
    return 0;
}
