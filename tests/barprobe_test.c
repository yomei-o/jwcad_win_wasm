/* Every control on every command bar: does it answer, and does it draw?
 *
 *   tests/barprobe_test.exe [--list]
 *
 * Jw_cad is driven through the bars as much as through the drawing area -- a
 * rectangle 1000 mm across is typed into 寸法, not dragged -- and the port
 * draws all of those controls whether or not it answers to them.  Drawing one
 * is not answering to it, and from the outside the two look the same, so this
 * presses every one of them the way a mouse would and asks two questions:
 *
 *   answers   pressing it moved something -- the tick, the caret, the
 *             command in force, the drawing
 *   draws     with it pressed, the same three clicks in the drawing area come
 *             out different
 *
 * The second is the one that matters: a checkbox that only ticks is a
 * checkbox the port has not learnt yet.  What it prints is both counts, and
 * --list names every control that does nothing and every one that only ticks,
 * which is the list of work left on the bars.
 *
 * It fails when a control the port is supposed to act on has stopped acting:
 * MUST[] below is that list, and it is the list to grow as the bars are
 * filled in against answers the original draws.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/bars.h"

static int fails;

/* (command, control, what it is) that have to change what gets drawn.
   Anything here that stops doing so is a regression. */
static const struct { unsigned short cmd, id; const char *what; } MUST[] = {
    { 0x8003, 1332, "線の 矩形" },
    { 0x8003, 1333, "線の 水平・垂直" },
    { 0x8003, 1411, "線の 傾き" },
    { 0x8003, 1412, "線の 寸法" },
    { 0x8004, 1332, "矩形の 矩形" },
    { 0x8004, 1413, "矩形の 寸法" },
    /* 矩形の 傾き (1411) and 水平・垂直 (1333) are not here: the port keeps
       what is typed into them and does nothing with it yet.  They go in the
       day the original is asked what they do. */
    { 0x807e, 1411, "多角形の 寸法" },
    { 0x807e, 1413, "多角形の 角数" },
};

/* enough of the port's state that any of the usual answers shows up */
static int state_of(const jw_drawing *d, int id)
{
    return jw_cmd() * 131 + (jw_cmd_bar_check(id) + 2) * 17
           + (jw_cmd_box_focus() == id ? 7 : 0)
           + (jw_cmd_box(id) ? (int)strlen(jw_cmd_box(id)) : 0)
           + (d ? d->ndrawn : 0);
}

/* Three clicks in the middle of the paper, and what they left behind: the
   objects added, as one number that changes when any of them does.
   Three, not two: 円弧・半円・３点指示 all want a third point, and with two
   they draw nothing at all and look dead. */
static unsigned long drawn_by_clicks(void)
{
    jw_drawing *d = (jw_drawing *)app_drawing();
    unsigned long h = 1469598103u;
    int before = d->ndrawn, i, k;

    jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 160.0, 140.0, 0);
    jw_cmd_point(d, app_view(), 130.0, 60.0, 0);
    for (i = before; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];
        h = h * 16777619u + (unsigned)o->cls;
        h = h * 16777619u + (unsigned)o->color;
        h = h * 16777619u + (unsigned)o->ltype;
        for (k = 0; k < 8; k++) {
            /* a tenth of a micrometre is finer than anything the bars move */
            long v = (long)(o->d[k] * 10000.0);
            h = h * 16777619u + (unsigned long)v;
        }
    }
    return h * 31u + (unsigned)(d->ndrawn - before);
}

/* What a command's box held the first time the command was entered.  The
   slot comes up holding a 1, which is not a state a box can be in. */
static char *box_was(unsigned cmd, int id)
{
    static struct { unsigned cmd; int id; char t[16]; } was[256];
    static int n;
    int i;

    for (i = 0; i < n; i++)
        if (was[i].cmd == cmd && was[i].id == id)
            return was[i].t;
    if (n >= (int)(sizeof was / sizeof was[0]))
        return 0;
    was[n].cmd = cmd;
    was[n].id = id;
    was[n].t[0] = 1;
    was[n].t[1] = 0;
    return was[n++].t;
}

/* The command's own bar, as a press on the control would find it.
 *
 * By way of 点 first: asking for 線 while 線 is already in force is how the
 * original flips 水平・垂直 (jw_cmd_set), so going straight there would turn
 * it over once on the way in -- and then the pass that presses the checkbox
 * turns it back and draws exactly what the other one did. */
static void enter(unsigned short cmd, unsigned short on)
{
    int i, k;

    app_new();
    jw_cmd_set(JW_CMD_TEN);
    jw_cmd_set(cmd);
    /* and put every checkbox back the way the original has it.  They keep
       what they were left at, which is right for the port and wrong for a
       measurement: one press of ソリッド would otherwise colour every later
       reading on that bar. */
    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != cmd || jw_bars[i].on)
            continue;           /* the plain bar's own starting state */
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            if (c->kind != JW_CTL_CHECK)
                continue;
            if (jw_cmd_bar_check(c->id) != (c->checked != 0))
                jw_cmd_bar((jw_drawing *)app_drawing(), c->id);
        }
    }
    /* and put the boxes back as the command found them.  What the combo pass
       types into 傾き or 寸法 stays there otherwise, and a line of a fixed
       length and angle no longer moves when the next checkbox is pressed,
       which reads as a checkbox that does nothing.  Emptying them would be
       just as wrong -- 多角形 comes up with 3 in its 角数 and draws nothing
       without it -- so what is restored is what the box held the first time
       the command was entered. */
    for (i = 0; i < JW_NBARS; i++) {
        if (jw_bars[i].cmd != cmd || jw_bars[i].on)
            continue;
        for (k = 0; k < jw_bars[i].n; k++) {
            const jw_ctl_t *c = &jw_bars[i].c[k];
            const char *now;
            char *want;
            int j;
            if (c->kind != JW_CTL_COMBO)
                continue;
            want = box_was(cmd, c->id);
            now = jw_cmd_box(c->id);
            if (!want)
                continue;
            if (*want == 1) {           /* not seen yet: this is the state */
                want[0] = 0;
                if (now)
                    strncpy(want, now, 15);
                continue;
            }
            if (now && !strcmp(now, want))
                continue;
            jw_cmd_box_click(c->id);
            for (j = 0; j < 24; j++)
                jw_cmd_box_key(8);
            for (j = 0; want[j]; j++)
                jw_cmd_box_key((unsigned char)want[j]);
            jw_cmd_box_key(13);
        }
    }
    /* a variant bar is only up while its own box is ticked, so tick it --
       otherwise its controls are not on the bar at all and every one of
       them reads as dead */
    if (on && jw_cmd_bar_check(on) <= 0)
        jw_cmd_bar((jw_drawing *)app_drawing(), on);
}

int main(int argc, char **argv)
{
    int list = argc > 1 && !strcmp(argv[1], "--list");
    int i, k, n = 0, live = 0, draws = 0;

    app_resize(1264, 741);
    app_new();
    for (i = 0; i < JW_NBARS; i++) {
        const jw_bar_t *b = &jw_bars[i];
        /* the bars filed under 100000 + the command are the ones a command
           puts up once a range is settled; jw_cmd_set does not reach them */
        if (b->cmd >= 100000u)
            continue;
        for (k = 0; k < b->n; k++) {
            const jw_ctl_t *c = &b->c[k];
            const jw_drawing *d;
            unsigned long plain, pressed;
            int before, after, x, y, j, moved, drew;

            if (c->kind == JW_CTL_STATIC)
                continue;
            n++;
            x = c->x + c->w / 2;
            y = c->y + c->h / 2;

            /* what the two clicks draw with the bar as it comes up */
            enter(b->cmd, b->on);
            plain = drawn_by_clicks();

            /* and with this one control pressed */
            enter(b->cmd, b->on);
            d = app_drawing();
            before = state_of(d, c->id);
            app_press(x, y, 0);
            d = app_drawing();
            after = state_of(d, c->id);
            moved = after != before;
            /* a combo takes typing rather than a press: put a number in it */
            if (c->kind == JW_CTL_COMBO) {
                const char *was = jw_cmd_box(c->id);
                char keep[16];
                keep[0] = 0;
                if (was) {
                    strncpy(keep, was, sizeof keep - 1);
                    keep[sizeof keep - 1] = 0;
                }
                jw_cmd_box_click(c->id);
                for (j = 0; j < 24; j++)
                    jw_cmd_box_key(8);
                jw_cmd_box_key('7');   /* not 3: 多角形 comes up with 3 sides */
                jw_cmd_box_key(13);
                moved = moved || (jw_cmd_box(c->id)
                                  && strcmp(jw_cmd_box(c->id), keep));
            }
            pressed = drawn_by_clicks();
            if (getenv("JWDBG") && b->cmd == 32771 && !b->on)
                printf("dbg %d chk=%d plain=%lu pressed=%lu\n", c->id,
                       jw_cmd_bar_check(c->id), plain, pressed);
            drew = pressed != plain;
            live += moved;
            draws += drew;
            if (list && !drew)
                printf("     %5d%c%-5d %5d %-6s %-5s %s\n", b->cmd,
                       b->on ? '/' : ' ', b->on, c->id,
                       c->kind == JW_CTL_CHECK ? "check"
                       : c->kind == JW_CTL_COMBO ? "combo" : "button",
                       moved ? "held" : "dead", c->text);
            if (drew)
                continue;
            /* MUST says what a command's own bar does; a variant is the
               bar with one box already ticked, where the same control may
               rightly do something else (寸法 does not resize a ソリッド). */
            for (j = 0; !b->on && j < (int)(sizeof MUST / sizeof MUST[0]); j++)
                if (MUST[j].cmd == b->cmd && MUST[j].id == c->id) {
                    printf("BAD  %s no longer changes what is drawn\n",
                           MUST[j].what);
                    fails++;
                }
        }
    }
    printf("ok   %d of %d controls answer to a press\n", live, n);
    printf("ok   %d of %d change what three clicks draw\n", draws, n);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
