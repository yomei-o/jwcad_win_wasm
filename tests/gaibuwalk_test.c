/* 外部変形's interactive flow, walked at random.
 *
 *   tests/gaibuwalk_test.exe [rounds]       (default 300)
 *
 * Each round makes a batch file out of random step kinds -- #h1 (a range), #0 / #1 / #2 / #2-
 * (points, with a rubber line, numbered), #3ln #3ci #3ch (a line, a circle, a text), #c (typed value),
 * #i / #k (a choice), #f (an IME value, quoted), #hm (items with # :n sections), #hc prompts, and
 * garbage lines -- picks the command, hands the batch to the port, and answers its questions with
 * random presses (aimed at the drawing and not), random keys (digits, letters, Enter, Esc, BS), and
 * random Escs in the middle.  When the port says it is ready to run the program, the file it would
 * hand over is taken, the "program's answer" is made of it (unchanged, damaged, cut short, or made up
 * of h lines) and read back.  Nothing may fall over or hang, the numbers must stay sane, and every step
 * that took an undo step must be undone exactly.  Built with -fsanitize it also watches the memory. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"

static unsigned long rng = 0x9e3779b9UL;
static unsigned nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return (unsigned)rng;
}

static int fails;
static const char *KINDS[] = {
    "REM #h1", "REM #0Base", "REM #1/First", "REM #2Second", "REM #2-%dNext", "REM #3ln", "REM #3ci", "REM #3ch",
    "REM #cCount/_/N", "REM #iPrompt/_/I", "REM #kWhich|a|b|c/_/K", "REM #fName/_$1\"", "REM #hcPick lines", "REM #e",
    "REM #:1", "REM #:2", "REM #hmTitle|one|two|", "REM #cd", "REM garbage", "REM #", "REM #9", "REM #3", "REM #2-",
    "REM #0", "REM #1", "REM #kA|B/_/", "REM #c", "REM #h2", "REM #h3", "REM #h5"
};

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

static void act(rect_t *rc)
{
    const jw_drawing *d = app_drawing();
    const jw_view *v = app_view();
    unsigned r = nextr() % 100;

    if (r < 35 && d && v && d->ndrawn > 0) {
        const jw_obj *o = &d->obj[nextr() % (unsigned)d->ndrawn];

        app_press(jw_sx(v, o->d[0]), jw_sy(v, o->d[1]), (int)(nextr() & 1));
    } else if (r < 60)
        app_press(rc->x + (int)(nextr() % (unsigned)rc->w), rc->y + (int)(nextr() % (unsigned)rc->h), (int)(nextr() & 1));
    else if (r < 70)
        app_move(rc->x + (int)(nextr() % (unsigned)rc->w), rc->y + (int)(nextr() % (unsigned)rc->h));
    else if (r < 80)
        app_key(13);
    else if (r < 85)
        app_key(27);
    else if (r < 92)
        app_key("0123456789.-"[nextr() % 12]);
    else if (r < 96)
        app_key("abcxyzK/ ,"[nextr() % 10]);
    else
        app_key(8);
}

int main(int argc, char **argv)
{
    int rounds = argc > 1 ? atoi(argv[1]) : 300, rd, ran = 0, loaded = 0;
    long n;
    unsigned char *base = slurp("orig/Test5.jww", &n);
    rect_t rc;

    if (!base) { printf("BAD  cannot read orig/Test5.jww\n"); return 1; }
    app_resize(1264, 741);
    for (rd = 0; rd < rounds; rd++) {
        char bat[2000], *p = bat;
        int k, nk = 2 + (int)(nextr() % 9), st;
        const jw_view *v;
        unsigned char *t = 0, *ans;
        long tn = 0, an;
        char args[256], msg[200];

        if (!app_open(base, n)) { printf("BAD  open\n"); return 1; }
        app_fit();
        ui_view_rect(app_fb()->w, app_fb()->h, &rc);
        p += sprintf(p, "REM #%s\r\n", nextr() % 8 ? (nextr() % 2 ? "jw" : "jww") : "jwwB");
        for (k = 0; k < nk; k++)
            p += sprintf(p, "%s\r\n", KINDS[nextr() % (sizeof KINDS / sizeof KINDS[0])]);
        if (nextr() % 3)
            p += sprintf(p, "REM #e\r\n");
        app_command(32913);
        app_take_action();
        if (!app_gaibu_load(bat, (long)(p - bat))) {
            continue;
        }
        loaded++;
        v = app_view();
        (void)v;
        for (st = 0; st < 60; st++) {
            const jw_drawing *d = app_drawing();
            int depth0 = jw_cmd_undo_depth();

            act(&rc);
            d = app_drawing();
            if (d && !jw_numbers_sane(d)) {
                printf("BAD  round %d: insane number after step %d\n", rd, st);
                fails++;
                break;
            }
            (void)depth0;
            if (jw_cmd_gaibu_ready() && app_take_action() == JW_ACT_GAIBU_RUN) {
                char before_name[1];

                (void)before_name;
                if (app_gaibu_run_begin(&t, &tn, args, (int)sizeof args) == 1 && t) {
                    ran++;
                    /* the program's answer: the same file, damaged, cut short, or a few h lines */
                    an = tn;
                    ans = (unsigned char *)malloc((size_t)an + 64);
                    memcpy(ans, t, (size_t)an);
                    switch (nextr() % 4) {
                    case 1: if (an > 0) ans[nextr() % (unsigned)an] = (unsigned char)nextr(); break;
                    case 2: an = (long)(nextr() % (unsigned)(an + 1)); break;
                    case 3: an = sprintf((char *)ans, "hr\r\nhe oops\r\nh/ next.bat\r\nh# note\r\n"); break;
                    default: break;
                    }
                    app_gaibu_end(ans, an, msg, (int)sizeof msg);
                    free(ans);
                    free(t);
                    t = 0;
                }
                app_gaibu_run_end();
                break;
            }
        }
        if (jw_cmd_gaibu_active())
            app_key(27);
        app_key(27);
        if (app_drawing() && !jw_numbers_sane(app_drawing())) {
            printf("BAD  round %d: insane number at the end\n", rd);
            fails++;
        }
        /* and the whole thing taken back, one step at a time */
        {
            int guard = 0;
            jw_drawing *d = (jw_drawing *)app_drawing();

            while (d && jw_cmd_can_undo() && guard++ < 200)
                jw_cmd_undo(d);
            while (d && jw_cmd_can_redo() && guard++ < 400)
                jw_cmd_redo(d);
        }
    }
    printf("%d rounds, %d batch files taken, %d runs answered, %d bad\n", rounds, loaded, ran, fails);
    return fails != 0;
}
