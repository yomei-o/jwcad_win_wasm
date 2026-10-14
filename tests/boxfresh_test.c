/* A click on a number box on the command bar selects what is in it: the first key typed replaces it (the
   hatch pitch's default 10 used to have to be backspaced away), and a backspace first clears it. */
#include <stdio.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"

static int fails;

static void is(const char *what, const char *got, const char *want)
{
    int ok = got && !strcmp(got, want);

    printf("%s  %s: \"%s\"%s\n", ok ? "ok  " : "BAD ", what, got ? got : "(none)", ok ? "" : " (wanted a different one)");
    if (!ok)
        fails++;
}

int main(void)
{
    app_resize(1264, 741);
    app_new();
    jw_cmd_set(JW_CMD_HIKAGE);
    is("日影's 高さ starts as the default", jw_cmd_box(1491), "10");
    jw_cmd_box_click(1491);
    jw_cmd_box_key('7');
    is("a digit after the click replaces it", jw_cmd_box(1491), "7");
    jw_cmd_box_key('5');
    is("the next one is appended", jw_cmd_box(1491), "75");
    jw_cmd_box_key(8);
    is("backspace removes one", jw_cmd_box(1491), "7");
    jw_cmd_box_click(1491);
    jw_cmd_box_key(8);
    is("backspace right after a click clears the box", jw_cmd_box(1491), "");
    jw_cmd_box_key('3');
    jw_cmd_box_key('.');
    jw_cmd_box_key('5');
    jw_cmd_box_key(13);
    is("typing, then Enter", jw_cmd_box(1491), "3.5");
    jw_cmd_box_click(1491);
    jw_cmd_box_key(13);
    is("Enter right after a click leaves it as it was", jw_cmd_box(1491), "3.5");
    printf(fails ? "FAILED\n" : "all ok\n");
    return fails != 0;
}
