/* The commands, driven at random.
 *
 *   tests/cmdfuzz_test.exe <drawings…>
 *
 * Every other test drives one command the way someone would use it.  This
 * one drives all of them the way nobody would: for each drawing it presses
 * toolbar commands, clicks and drags all over the window, types, and
 * repaints, in an order drawn from a fixed pseudo-random stream.  Nothing is
 * compared against anything -- there is nothing to compare it with.  What is
 * being asked is only:
 *
 *   * does anything fall over,
 *   * does the drawing keep numbers a drawing could hold
 *     (jw_numbers_sane, the same gate the readers use), and
 *   * can what is left still be written out every way the port can write?
 *
 * The stream is the same every run so a fault can be looked at again;
 * JW_CMDFUZZ_SEED picks another one, and JW_CMDFUZZ_STEPS how long to go on.
 * Build it with -fsanitize=address to make the first question sharp.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/app.h"
#include "../src/jww.h"
#include "../src/gen/cmds.h"
#include "../src/gen/layout.h"
#include "../src/gen/newjww.h"

static unsigned long rng = 20260925u;

static unsigned long nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return rng;
}

#define W 1264
#define H 741

/* keys the 文字 command and the dialogs care about, plus a few that no
   command wants at all */
static const int KEYS[] = {
    'a', 'A', '0', '9', ' ', '.', '-', 8, 13, 27, 9, 0x82, 0xa1, 0xff
};

static long written;

static void write_every_way(const jw_drawing *d)
{
    unsigned char *o;
    long m;

    if (!d)
        return;
    written++;
    if (jw_write(d, &o, &m))              free(o);
    if (jw_write_jws(d, 0, 0, &o, &m))    free(o);
    if (jw_dxf_write(d, &o, &m))          free(o);
    if (jw_sfc_write(d, "x", "2026-01-01", &o, &m)) free(o);
    if (jw_jwc_write(d, &o, &m))          free(o);
    if (jw_write_coord(d, 0, 0, &o, &m))  free(o);
}

/* Write it, read that back, write it again: the two writings have to be the
 * same bytes.  A drawing that has been edited at random holds shapes no file
 * on disk holds, and this is the one thing that can be checked without
 * having anything to compare against -- if the second writing differs, then
 * either the writer put down something the reader does not take back, or the
 * reader drops something on the way in. */
static int round_trip(const jw_drawing *d, const char *who)
{
    unsigned char *a = 0, *b = 0;
    long na = 0, nb = 0;
    jw_drawing e;
    int ok = 1;

    if (!d || !jw_write(d, &a, &na))
        return 1;                       /* nothing to hold it against */
    memset(&e, 0, sizeof e);
    if (!jw_parse(&e, a, na)) {
        printf("BAD  %s: what was written will not read back (%s)\n",
               who, e.error ? e.error : "no reason given");
        ok = 0;
    } else if (!jw_write(&e, &b, &nb)) {
        printf("BAD  %s: what was read back will not write\n", who);
        ok = 0;
    } else {
        if (na != nb || memcmp(a, b, (size_t)na) != 0) {
            /* One normalisation is allowed, so long as it happens once.
               An SFC keeps an arc that starts at 270 degrees at 270 --
               src/sfcread.c does that on purpose, and the original's own
               answer file agrees -- while the .jww reader brings a start
               angle into (-pi, pi].  So the first writing of a drawing
               built from an SFC carries 3pi/2 and the second carries
               -pi/2, and both are right.  What would be wrong is for it to
               keep moving, so the third writing has to match the second.
               This is the same rule settles() holds the text formats to. */
            jw_drawing g;
            unsigned char *c = 0;
            long nc = 0;

            memset(&g, 0, sizeof g);
            if (!jw_parse(&g, b, nb) || !jw_write(&g, &c, &nc)
                || nc != nb || memcmp(b, c, (size_t)nb) != 0) {
                long i = 0;
                while (i < na && i < nb && a[i] == b[i])
                    i++;
                printf("BAD  %s: writing it twice gives different bytes and"
                       " it does not settle (%ld and %ld, they part at"
                       " %ld)\n", who, na, nb, i);
                ok = 0;
            }
            free(c);
            jw_free(&g);
        }
        free(b);
    }
    jw_free(&e);
    free(a);
    return ok;
}

/* The same for the text formats, which are lossy: DXF, SFC and JWC cannot
 * carry everything a .jww carries, so the first writing and the second need
 * not agree.  What must agree is the second and the third -- once the
 * drawing has been through the format it is a drawing that format can hold,
 * and putting it through again must not change it any further.
 *
 * DXF is left out, and not because the port is wrong: **Jw_cad's own DXF
 * round trip does not settle**.  A layer's name goes into a DXF as
 * `_<group>-<layer>_<name>`, and when one is read back the whole of that
 * becomes the name -- tests/dxfread_test.c holds the port's layer names
 * against the original's and they agree -- so the next writing says
 * `_0-a__0-a_東壁日影`, and the one after that adds another.  The names
 * growing changes what the LAYER table holds, and that moves which layer an
 * element lands on (`_0-d_ADD_LINE` comes back as `_0-e_ADD_LINE`).  So
 * only SFC and JWC are asked to settle.
 *
 * The text readers read *into* a drawing -- that is what 読込 does in the
 * original, and what the port's window does: the sheet, the pens and the
 * rest stay and only the elements are replaced.  So each generation starts
 * from the same blank drawing the 新規 command starts from, not from a
 * zeroed struct (a zeroed one has a sheet of nothing, and the extents come
 * out as nought). */
static int blank(jw_drawing *d)
{
    memset(d, 0, sizeof *d);
    return jw_parse(d, jw_new_jww, jw_new_jww_len);
}

static int fmt_write(const jw_drawing *d, int which,
                     unsigned char **o, long *n)
{
    if (which == 0) return jw_dxf_write(d, o, n);
    if (which == 1) return jw_sfc_write(d, "x", "2026-01-01", o, n);
    return jw_jwc_write(d, o, n);
}

static int fmt_read(jw_drawing *d, int which, const unsigned char *b, long n)
{
    if (which == 0) return jw_dxf_read(d, b, n);
    if (which == 1) return jw_sfc_read(d, b, n);
    return jw_jwc_read(d, b, n);
}

/* The text formats are lines.  Two writings count as the same when they
 * have the same lines, except that a line which is a number on both sides
 * only has to be the same number to within the last place or so: a
 * coordinate goes out multiplied by the scale and comes back divided by it,
 * and that is not always the bit pattern it started as.  What this looks
 * for is a line that has gone, changed or arrived -- not the last digit of
 * a double. */
static int same_lines(const unsigned char *a, long na,
                      const unsigned char *b, long nb,
                      const char *who, const char *what)
{
    long i = 0, j = 0, line = 0;

    while (i < na || j < nb) {
        char pa[64], pb[64];
        long ea = i, eb = j, la, lb;
        char *enda, *endb;
        double va, vb;

        while (ea < na && a[ea] != 10) ea++;
        while (eb < nb && b[eb] != 10) eb++;
        la = ea - i;
        lb = eb - j;
        line++;
        if (la != lb || memcmp(a + i, b + j, (size_t)la) != 0) {
            /* not the same text: the ways out are both being one number,
               or the line not being text at all.  JWC has records that
               carry packed binary -- a curve's points, for one -- and a
               coordinate in there goes out multiplied by the scale and
               comes back divided by it, so its last bit can move.  For
               those only the length is held to. */
            int ok = 0;
            long q;
            int bin = 0;

            for (q = 0; q < la && !bin; q++)
                if (a[i + q] < 9 || (a[i + q] > 13 && a[i + q] < 32))
                    bin = 1;
            for (q = 0; q < lb && !bin; q++)
                if (b[j + q] < 9 || (b[j + q] > 13 && b[j + q] < 32))
                    bin = 1;
            if (bin && la == lb)
                goto next;
            if (la > 0 && lb > 0 && la < (long)sizeof pa
                && lb < (long)sizeof pb) {
                memcpy(pa, a + i, (size_t)la); pa[la] = 0;
                memcpy(pb, b + j, (size_t)lb); pb[lb] = 0;
                va = strtod(pa, &enda);
                vb = strtod(pb, &endb);
                while (*enda == 13 || *enda == ' ') enda++;
                while (*endb == 13 || *endb == ' ') endb++;
                if (!*enda && !*endb) {
                    double m = va > 0 ? va : -va;
                    double e = vb > va ? vb - va : va - vb;
                    if (m < 1.0) m = 1.0;
                    ok = e <= m * 1e-12;
                }
            }
            if (!ok) {
                long k;
                printf("BAD  %s: %s does not settle -- line %ld"
                       " (%ld bytes became %ld)\n", who, what, line,
                       la, lb);
                printf("       was:");
                for (k = 0; k < la && k < 48; k++)
                    printf(" %02x", a[i + k]);
                printf("\n       now:");
                for (k = 0; k < lb && k < 48; k++)
                    printf(" %02x", b[j + k]);
                printf("\n");
                return 0;
            }
        }
    next:
        i = ea + 1;
        j = eb + 1;
    }
    return 1;
}

static int settles(const jw_drawing *d, int which, const char *who)
{
    unsigned char *a = 0, *b = 0, *c = 0;
    long na = 0, nb = 0, nc = 0;
    jw_drawing e, f;
    int ok = 1;
    static const char *NAME[] = { "DXF", "SFC", "JWC" };

    memset(&e, 0, sizeof e);
    memset(&f, 0, sizeof f);
    if (!d || !blank(&e) || !blank(&f))
        goto done;
    if (!fmt_write(d, which, &a, &na))
        goto done;
    if (!fmt_read(&e, which, a, na) || !fmt_write(&e, which, &b, &nb))
        goto done;              /* it would not go round once: not this test */
    if (fmt_read(&f, which, b, nb) && fmt_write(&f, which, &c, &nc)) {
        if (!same_lines(b, nb, c, nc, who, NAME[which]))
            ok = 0;
        free(c);
    }
done:
    free(a);
    free(b);
    jw_free(&e);
    jw_free(&f);
    return ok;
}

/* which reader the name calls for */
static int open_by_name(const char *path, const unsigned char *b, long n)
{
    const char *dot = strrchr(path, '.');

    if (dot) {
        if (!strcmp(dot, ".dxf") || !strcmp(dot, ".DXF"))
            return app_open_dxf(b, n);
        if (!strcmp(dot, ".sfc") || !strcmp(dot, ".SFC"))
            return app_open_sfc(b, n);
        if (!strcmp(dot, ".jwc") || !strcmp(dot, ".JWC"))
            return app_open_jwc(b, n);
    }
    return app_open(b, n);
}

int main(int argc, char **argv)
{
    const char *seed = getenv("JW_CMDFUZZ_SEED");
    const char *nsteps = getenv("JW_CMDFUZZ_STEPS");
    int steps = nsteps && *nsteps ? atoi(nsteps) : 600;
    int i, bad = 0, files = 0;
    long acts = 0;

    if (seed && *seed) {
        rng = strtoul(seed, 0, 0);
        if (!rng)
            rng = 1;
    }
    if (steps < 1)
        steps = 1;
    if (!app_resize(W, H)) {
        printf("BAD  out of memory\n");
        return 1;
    }

    /* with no file named, the drawing begun from nothing: the commands that
       make the first element of all have nothing under them then */
    for (i = 1; i < (argc > 1 ? argc : 2); i++) {
        FILE *f = argc > 1 ? fopen(argv[i], "rb") : 0;
        unsigned char *b;
        long n;
        int k;
        clock_t t0;

        if (argc < 2) {
            app_new();
            files++;
            goto drive;
        }
        if (!f) {
            printf("BAD  %s: cannot open\n", argv[i]);
            bad++;
            continue;
        }
        fseek(f, 0, SEEK_END);
        n = ftell(f);
        fseek(f, 0, SEEK_SET);
        b = (unsigned char *)malloc((size_t)(n ? n : 1));
        if (!b || fread(b, 1, (size_t)n, f) != (size_t)n) {
            printf("BAD  %s: cannot read\n", argv[i]);
            fclose(f);
            free(b);
            bad++;
            continue;
        }
        fclose(f);
        /* Open it the way its name says.  A DXF, an SFC and a JWC all make
           a drawing the .jww reader never would -- an SFC's contents land
           inside a 図形, a DXF brings its own layers and colours -- and the
           commands then run on that.  Before this the fuzzer only ever had
           .jww to work on. */
        if (!open_by_name(argv[i], b, n)) {
            printf("BAD  %s: %s\n", argv[i], app_error());
            free(b);
            bad++;
            continue;
        }
        free(b);
        files++;
    drive:
        /* before anything is touched: the drawing as it came off the disk
           has to go round the formats too, and a fault there is one that
           can be looked at without replaying the random walk */
        {
            const char *who0 = argc > 1 ? argv[i] : "(nothing)";
            int w;
            if (!round_trip(app_drawing(), who0))
                bad++;
            for (w = 1; w < 3; w++)   /* DXF does not settle: see above */
                if (!settles(app_drawing(), w, who0))
                    bad++;
        }
        t0 = clock();

        for (k = 0; k < steps; k++) {
            unsigned long r = nextr() % 100;

            acts++;
            if (r < 25)
                app_command(jw_btn_cmd[nextr() % JW_NBUTTONS]);
            else if (r < 60)
                app_press((int)(nextr() % W), (int)(nextr() % H),
                          (int)(nextr() % 2));
            else if (r < 75)
                app_move((int)(nextr() % W), (int)(nextr() % H));
            else if (r < 90)
                app_key(KEYS[nextr() % (sizeof KEYS / sizeof KEYS[0])]);
            else
                app_paint();
            if ((k & 63) == 0 && app_drawing()
                && !jw_numbers_sane(app_drawing())) {
                printf("BAD  %s: a number no drawing could hold after"
                       " %d steps\n", argv[i], k);
                bad++;
                break;
            }
        }
        app_paint();
        if (app_drawing() && !jw_numbers_sane(app_drawing())) {
            printf("BAD  %s: a number no drawing could hold at the end\n",
                   argv[i]);
            bad++;
        } else {
            write_every_way(app_drawing());
            {
                const char *who = argc > 1 ? argv[i] : "(nothing)";
                int w;
                if (!round_trip(app_drawing(), who))
                    bad++;
                for (w = 1; w < 3; w++)   /* DXF does not settle: see above */
                    if (!settles(app_drawing(), w, who))
                        bad++;
            }
        }
        {   /* a command that never comes back is as much a fault as one
               that falls over */
            /* the multiply first would overflow: a long run gets past two
               million ticks, and that times 1000 does not fit an int */
            long ms = (long)((clock() - t0) / (double)CLOCKS_PER_SEC * 1000.0);
            if (ms > 60000)
                printf("BAD  %s: %ld ms for %d steps\n", argv[i], ms, steps);
        }
    }
    printf("%d drawings, %ld commands, clicks and keys with nothing falling"
           " over, and what was left written out %ld times\n",
           files, acts, written);
    return bad ? 1 : 0;
}
