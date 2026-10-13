/* 外部変形 (32913): the BAT header, the JWC_TEMP.TXT that goes out and the
 * one that comes back (tmp/spec_gaibu/A_gaibu_henkei.md).  The program is
 * played by this test. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"

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
    b = (unsigned char *)malloc((size_t)*n);
    if (b && fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

static void pick_all(void)
{
    const fb_t *fb = app_fb();
    rect_t r;

    ui_view_rect(fb->w, fb->h, &r);
    jw_cmd_set(JW_CMD_HANI);
    app_press(r.x + 100, r.y + 100, 0);
    app_press(r.x + r.w - 4, r.y + r.h - 4, 1);
}

static int load(void)
{
    long n;
    unsigned char *b = slurp("orig/Test5.jww", &n);
    int ok = b && app_open(b, n);

    free(b);
    return ok;
}

/* the answer: the file with the lines in `drop` taken out and `add` put first */
static unsigned char *answer(const unsigned char *t, long n, const char *add,
                             long *rn)
{
    unsigned char *o = (unsigned char *)malloc((size_t)n + 64);
    long k = (long)strlen(add), i = 0;

    memcpy(o, add, (size_t)k);
    while (i < n) {
        long j = i;

        while (j < n && t[j] != '\n')
            j++;
        if (!(j - i >= 2 && t[i] == 'h' && t[i + 1] == 'q' && (t[i + 2] == '\r' || t[i + 2] == '\n'))
            && !(t[i] == 'h' && t[i + 1] != 'q')) {
            memcpy(o + k, t + i, (size_t)(j - i + 1 > n - i ? n - i : j - i + 1));
            k += (j - i + 1 > n - i ? n - i : j - i + 1);
        }
        i = j + 1;
    }
    *rn = k;
    return o;
}

int main(void)
{
    static const char bat[] =
        "@echo off\r\nREM Test program\r\nREM #jww\r\nREM #cd\r\n"
        "REM #hmTitle|one|two|##|three|\r\nREM #h1\r\nREM #0\r\nREM #e\r\n"
        "echo nothing\r\n";
    static const char plain[] = "@echo off\r\nREM just a note\r\n";
    jw_gaibu g;
    unsigned char *t = 0, *back;
    long tn = 0, bn;
    int n0, r;
    char msg[160];

    app_resize(1264, 741);
    ck(!jw_gaibu_header(plain, (long)strlen(plain), &g), "a BAT without #jw is refused");
    ck(jw_gaibu_header(bat, (long)strlen(bat), &g), "a BAT with #jww is taken");
    ck(g.jww == 1 && g.cd == 1, "  #jww and #cd read");
    ck(g.nitems == 3 && !strcmp(g.title, "Title") && !strcmp(g.item[2], "three"),
       "  #hm gives a title and three items (## makes none)");

    ck(load(), "Test5 opens");
    ck(app_gaibu_begin(bat, (long)strlen(bat), &t, &tn) == -1, "nothing picked: no file written");
    pick_all();
    n0 = jw_cmd_sel_count(app_drawing());
    ck(n0 > 0, "a range over the drawing");
    ck(app_command(32913), "外部変形 entered");
    ck(app_take_action() == JW_ACT_GAIBU, "  which hands the front end the action");
    ck(app_gaibu_begin(plain, (long)strlen(plain), &t, &tn) == 0, "plain BAT: 0");
    ck(app_gaibu_begin(bat, (long)strlen(bat), &t, &tn) == 1 && t, "JWC_TEMP.TXT written");
    ck(tn > 8 && !memcmp(t, "hq\r\n", 4), "  it starts with hq");
    ck(strstr((char *)t, "\r\nhs ") && strstr((char *)t, "\r\nhn "), "  and carries hs and hn");

    /* the program that did not run leaves hq there */
    ck(app_gaibu_end(t, tn, msg, sizeof msg) == -2, "hq still there: not run (-2)");

    /* a program that gives it back unchanged: the picked data stays and a copy comes */
    n0 = app_drawing()->ndrawn;
    back = answer(t, tn, "", &bn);
    r = app_gaibu_end(back, bn, msg, sizeof msg);
    ck(r > 0, "an unchanged answer adds its elements");
    ck(app_drawing()->ndrawn == n0 + r, "  to the drawing");
    free(back);

    /* and with hd the original data goes */
    pick_all();
    app_command(32913);
    app_take_action();
    free(t);
    ck(app_gaibu_begin(bat, (long)strlen(bat), &t, &tn) == 1, "written again");
    n0 = app_drawing()->ndrawn;
    back = answer(t, tn, "hd\r\nh#done\r\n", &bn);
    r = app_gaibu_end(back, bn, msg, sizeof msg);
    ck(r > 0 && app_drawing()->ndrawn == n0, "hd: the originals go and the answer comes in");
    ck(!strcmp(msg, "done"), "  and its h# note comes back");
    free(back);
    free(t);

    /* the script's steps */
    {
        static const char sb[] =
            "REM #jww\r\nREM #hmTitle|one|two|\r\nREM #h1\r\nREM #hcPick lines\r\n"
            "REM #0Base\r\nREM #2-%dSecond\r\nREM #3ln\r\nREM #cCount/_/N\r\n"
            "REM #kWhich|a|b|c/_/K\r\nREM #fName/_$1\"\r\nREM #e\r\n";
        jw_gscript *sc = (jw_gscript *)calloc(1, sizeof *sc);
        char val[200][128];
        char args[256], pts[512];
        double xy[200][2];

        memset(val, 0, sizeof val);
        memset(xy, 0, sizeof xy);
        ck(jw_gaibu_script(sb, (long)strlen(sb), 0, sc) && sc->nsteps == 7, "script: seven steps");
        ck(sc->step[0].type == JW_GS_RANGE && !strcmp(sc->step[0].prompt, "Pick lines"), "  #h1 with its #hc");
        ck(sc->step[1].type == JW_GS_POINT && sc->step[1].n == 0, "  #0 is a point");
        ck(sc->step[2].mode == 1 && sc->step[2].number == 1 && !strcmp(sc->step[2].prompt, "Second"),
           "  #2- with a rubber line and a number");
        ck(sc->step[3].type == JW_GS_LINE, "  #3ln picks a line");
        ck(sc->step[4].type == JW_GS_INPUT && !strcmp(sc->step[4].prefix, "/N"), "  #c input and its prefix");
        ck(sc->step[5].type == JW_GS_CHOICE_LR && sc->step[5].nitems == 3, "  #k with three items");
        ck(sc->step[6].type == JW_GS_INPUT_IME && sc->step[6].quote, "  #f quotes its value");
        strcpy(val[4], "5");
        strcpy(val[5], "2");
        strcpy(val[6], "abc");
        jw_gaibu_args(sc, val, args, sizeof args);
        ck(!strcmp(args, "/N5 /K2 $1\"abc\" "), "arguments: /N5 /K2 $1\"abc\"");
        xy[1][0] = 10;
        xy[1][1] = 20;
        xy[2][0] = 30;
        xy[2][1] = 40;
        jw_gaibu_points(sc, (const double (*)[2])xy, pts, sizeof pts);
        ck(strstr(pts, "hp0  10 20\r\n") && strstr(pts, "hp2- 30 40\r\n"), "points as hp lines");
        free(sc);
    }
    {
        static const char sb2[] =
            "REM #jw\r\nREM #hmT|x|y|\r\nREM #:1\r\nREM #h1\r\nREM #:2\r\nREM #cOnly two/_/N\r\nREM #e\r\n";
        jw_gscript *sc = (jw_gscript *)calloc(1, sizeof *sc);

        ck(jw_gaibu_script(sb2, (long)strlen(sb2), 2, sc) && sc->nsteps == 1
           && sc->step[0].type == JW_GS_INPUT, "item 2 of #hm: only its own section");
        free(sc);
    }

    /* a BAT whose steps are answered: hp lines in the header, args for the run */
    {
        static const char sb3[] =
            "REM #jw\r\nREM #h1\r\nREM #0Base\r\nREM #2-Next\r\nREM #cN/_/N\r\nREM #e\r\n";
        double xy[200][2];
        char val[200][128], args[128];
        unsigned char *t3 = 0;
        long n3 = 0;

        memset(xy, 0, sizeof xy);
        memset(val, 0, sizeof val);
        xy[1][0] = 100; xy[1][1] = 200;
        xy[2][0] = 300; xy[2][1] = 400;
        strcpy(val[3], "7");
        pick_all();
        ck(app_gaibu_begin2(sb3, (long)strlen(sb3), 0, (const double (*)[2])xy, val, &t3, &n3,
                            args, sizeof args) == 1 && t3, "begin2 writes the file");
        t3[n3] = 0;
        ck(strstr((char *)t3, "\r\nhn ") && strstr((char *)t3, "\r\nhp0  100 200\r\nhp2- 300 400\r\n"),
           "  with hp lines after hn");
        ck(!strcmp(args, "/N7 "), "  and the argument string /N7");
        free(t3);
    }
    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
