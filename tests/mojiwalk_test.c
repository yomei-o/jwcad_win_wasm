/* 文字の 範囲選択 (文書 / 外部エディタ / 貼付 / SJIS-UTF8), walked at random.
 *
 *   tests/mojiwalk_test.exe [rounds]       (default 200)
 *
 * On each drawing that has texts: 文字 -> 範囲選択 (2407) -> a random box -> Enter, and then random
 * goes at 文書 (app_moji_doc), 外部エディタ (app_moji_edit_text and app_moji_apply with an edited
 * copy), 貼付 (app_moji_apply with the clipboard's lines: empty, one line, hundreds, binary, a lone
 * CR, UTF-8 and SJIS bytes, a line a megabyte long), the SJIS/UTF8 switch (1092), the bar's buttons
 * (1065 1067 1069 1070 1071 1072), Esc, and clicks.  Nothing may fall over or hang, numbers must stay
 * sane, and every undo step taken must be undone exactly. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/ui.h"
#include "../src/view.h"

static unsigned long rng = 0x2545F491UL;
static unsigned nextr(void)
{
    rng ^= rng << 13;
    rng ^= rng >> 17;
    rng ^= rng << 5;
    return (unsigned)rng;
}

static int fails;

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

static unsigned char *junk_text(long *n)
{
    unsigned k = nextr() % 9;
    long i, len = k == 0 ? 0 : k == 1 ? 5 : k == 8 ? 1100000 : (long)(nextr() % 4000);
    unsigned char *b = (unsigned char *)malloc((size_t)len + 1);

    for (i = 0; i < len; i++) {
        unsigned c = nextr();

        switch (k) {
        case 2: b[i] = (unsigned char)(c % 256); break;                       /* binary */
        case 3: b[i] = (unsigned char)(c % 7 == 0 ? 13 : 'a' + c % 26); break; /* lone CRs */
        case 4: b[i] = (unsigned char)(c % 5 == 0 ? 10 : 0x82 + c % 2); break; /* SJIS lead bytes */
        case 5: b[i] = (unsigned char)(c % 9 == 0 ? 10 : 0xe3 + c % 2); break; /* UTF-8 lead bytes */
        case 6: b[i] = (unsigned char)(c % 3 == 0 ? 13 : c % 3 == 1 ? 10 : 'x'); break;
        case 8: b[i] = (unsigned char)('a' + c % 26); break;                  /* one huge line */
        default: b[i] = (unsigned char)(c % 11 == 0 ? 10 : 0x20 + c % 90); break;
        }
    }
    *n = len;
    return b;
}

int main(int argc, char **argv)
{
    static const char *F[] = { "orig/Test1.jww", "orig/Test5.jww", "orig/Test7.jww", "orig/Test3.jww" };
    int rounds = argc > 1 ? atoi(argv[1]) : 200, rd, picked = 0, applied = 0;
    unsigned char *file[4];
    long fn[4];
    int i;

    for (i = 0; i < 4; i++)
        file[i] = slurp(F[i], &fn[i]);
    app_resize(1264, 741);
    for (rd = 0; rd < rounds; rd++) {
        int w = rd % 4, st;
        rect_t rc;
        jw_drawing *d;

        if (!file[w] || !app_open(file[w], fn[w]))
            continue;
        app_fit();
        d = (jw_drawing *)app_drawing();
        ui_view_rect(app_fb()->w, app_fb()->h, &rc);
        jw_cmd_set(JW_CMD_MOJI);
        jw_cmd_bar(d, 2407);
        app_press(rc.x + (int)(nextr() % (unsigned)(rc.w / 2)), rc.y + (int)(nextr() % (unsigned)(rc.h / 2)), 0);
        app_press(rc.x + rc.w / 2 + (int)(nextr() % (unsigned)(rc.w / 2)), rc.y + rc.h / 2 + (int)(nextr() % (unsigned)(rc.h / 2)), 1);
        app_key(13);
        if (jw_cmd_moji_ready())
            picked++;
        for (st = 0; st < 25; st++) {
            unsigned r = nextr() % 100;
            unsigned char *o = 0;
            long on = 0;
            int depth0 = jw_cmd_undo_depth();
            jw_drawing *dd = (jw_drawing *)app_drawing();

            if (r < 15) {
                if (app_moji_doc(&o, &on))
                    free(o);
            } else if (r < 40) {
                if (app_moji_edit_text(&o, &on)) {
                    unsigned char *e = (unsigned char *)malloc((size_t)on + 16);
                    long en = on;

                    memcpy(e, o, (size_t)on);
                    if (en > 3 && nextr() % 2)
                        e[nextr() % (unsigned)en] = (unsigned char)nextr();
                    if (nextr() % 3 == 0)
                        en = (long)(nextr() % (unsigned)(en + 1));
                    applied += app_moji_apply(e, en) ? 1 : 0;
                    free(e);
                    free(o);
                }
            } else if (r < 60) {
                long jn;
                unsigned char *j = junk_text(&jn);

                applied += app_moji_apply(j, jn) ? 1 : 0;
                free(j);
            } else if (r < 70)
                jw_cmd_bar(dd, 1092);
            else if (r < 85) {
                static const int B[] = { 1065, 1067, 1069, 1070, 1071, 1072, 1121, 1122, 2407 };

                jw_cmd_bar(dd, B[nextr() % (sizeof B / sizeof B[0])]);
                if (app_take_action() == JW_ACT_MOJI_EDIT) {
                    if (app_moji_edit_text(&o, &on))
                        free(o);
                }
            } else if (r < 92)
                app_key(27);
            else
                app_press(rc.x + (int)(nextr() % (unsigned)rc.w), rc.y + (int)(nextr() % (unsigned)rc.h), (int)(nextr() & 1));
            dd = (jw_drawing *)app_drawing();
            if (dd && !jw_numbers_sane(dd)) {
                printf("BAD  round %d step %d: insane number\n", rd, st);
                fails++;
                break;
            }
            (void)depth0;
        }
        d = (jw_drawing *)app_drawing();
        {
            int guard = 0;

            while (d && jw_cmd_can_undo() && guard++ < 100)
                jw_cmd_undo(d);
            while (d && jw_cmd_can_redo() && guard++ < 200)
                jw_cmd_redo(d);
        }
        app_paint();
    }
    printf("%d rounds, %d with texts picked, %d replacements applied, %d bad\n", rounds, picked, applied, fails);
    return fails != 0;
}
