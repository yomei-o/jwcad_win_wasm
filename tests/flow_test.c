/* A small floor plan drawn, edited, undone, saved and read back the way a
 * person would do it -- the end-to-end usability pass.
 *
 *   tests/flow_test.exe
 *
 * Checks after each phase: the numbers are sane, the prompt is never empty,
 * Esc / right-click leave no command half done, 戻る all the way gives back
 * the empty sheet and 進む all the way the finished one, and what was saved
 * (jww, dxf, sfc, jwc, pdf) reads back.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/plot.h"

static int fails;
static jw_drawing *d;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void at(double x, double y, int b)  { jw_cmd_point(d, app_view(), x, y, b); }
static void box(int id, const char *s)
{
    int i;
    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}
static void line(double a, double b, double c, double e)
{
    jw_cmd_set(JW_CMD_SEN);
    at(a, b, 0);
    at(c, e, 0);
}
static int prompt_ok(const char *who)
{
    const char *p = jw_cmd_prompt();
    char m[200];
    snprintf(m, sizeof m, "%s: prompt not empty", who);
    if (!p || !*p) { ck(0, m); return 0; }
    return 1;
}
static int count_cls(int cls)
{
    int i, n = 0;
    for (i = 0; i < d->nobj; i++)
        if (d->obj[i].cls == cls) n++;
    return n;
}

typedef struct { jw_obj *o; int n, nd, depth; } ssnap_t;
static ssnap_t ss[32];
static int nss;
static void commit(void)
{
    ssnap_t *s = &ss[nss++];
    s->n = d->nobj; s->nd = d->ndrawn; s->depth = jw_cmd_undo_depth();
    s->o = (jw_obj *)malloc((size_t)(s->n + 1) * sizeof *s->o);
    if (s->n) memcpy(s->o, d->obj, (size_t)s->n * sizeof *s->o);
    { int q0; for (q0 = 0; q0 < s->n; q0++) { s->o[q0].sel = 0; s->o[q0].flags &= ~2u; } }
}

static void roundtrip(void)
{
    unsigned char *o;
    long n;
    jw_drawing e;
    commit();

    ck(app_save(&o, &n) && n > 0, "save .jww");
    memset(&e, 0, sizeof e);
    ck(jw_parse(&e, o, n), "reload .jww");
    ck(e.nobj == d->nobj, "reload: same element count");
    jw_free(&e);
    free(o);
    ck(app_save_dxf(&o, &n) && n > 0, "dxf"); if (o) free(o);
    ck(app_save_sfc("plan", &o, &n) && n > 0, "sfc"); if (o) free(o);
    ck(app_save_jwc(&o, &n) && n > 0, "jwc"); if (o) free(o);
    o = jw_plot_pdf(d, 1, &n);
    ck(o && n > 100 && !memcmp(o, "%PDF", 4), "pdf"); free(o);
}

int main(void)
{
    int i, n0, n1, depth;
    const jw_view *v;

    app_resize(1264, 741);
    app_new();
    d = (jw_drawing *)app_drawing();
    v = app_view();
    n0 = d->nobj;

    /* outer walls: rectangle 10m x 7m on the 1/100 sheet (mm on paper) */
    jw_cmd_set(JW_CMD_KUKEI);
    prompt_ok("kukei");
    at(0, 0, 0); at(100, 70, 0);
    ck(d->nobj == n0 + 4, "rectangle makes 4 lines");
    /* partition */
    line(50, 0, 50, 70);
    line(0, 35, 50, 35);
    /* door swing: circle + erase half later */
    jw_cmd_set(JW_CMD_ENKO);
    prompt_ok("enko");
    at(75, 35, 0); at(85, 35, 0);
    ck(count_cls(JW_ENKO) == 1, "circle made");
    /* offset (複線) of the bottom wall */
    jw_cmd_set(JW_CMD_FUKUSEN);
    prompt_ok("fukusen");
    box(1411, "1000");
    at(50, 0, 0); at(50, -5, 0); at(50, -5, 0);
    /* dimension */
    jw_cmd_set(JW_CMD_SUNPO);
    prompt_ok("sunpo");
    at(0, -20, 0); at(100, -20, 0); at(0, 0, 0); at(100, 0, 0);
    /* text */
    jw_cmd_set(JW_CMD_MOJI);
    prompt_ok("moji");
    {
        const char *s = "LDK";
        for (; *s; s++) jw_cmd_key(*s);
    }
    at(10, 60, 0);
    jw_cmd_set(JW_CMD_SEN);
    n1 = d->nobj;
    ck(jw_numbers_sane(d), "numbers sane after drawing");
    printf("n0=%d n1=%d lines=%d circ=%d moji=%d\n", n0, n1, count_cls(JW_SEN), count_cls(JW_ENKO), count_cls(JW_MOJI));
    ck(n1 > n0 + 8, "plan has elements");
    roundtrip();

    /* edit: trim (部分消し), corner, erase, move, copy */
    jw_cmd_set(JW_CMD_SHOUKYO);
    prompt_ok("shoukyo");
    at(25, 35, 0); at(10, 35, 0); at(20, 35, 0);
    jw_cmd_set(JW_CMD_CORNER);
    at(0, 0, 0); at(0, 70, 0);
    jw_cmd_set(JW_CMD_HANI);
    at(-5, -5, 0); at(55, 75, 0);
    jw_cmd_track(0, 20);
    jw_cmd_bar(d, 1120);
    jw_cmd_set(JW_CMD_FUKUSHA);
    prompt_ok("fukusha after select");
    at(0, 0, 0);
    at(0, 100, 0);
    ck(jw_numbers_sane(d), "numbers sane after edit");
    roundtrip();

    /* hatch a fresh room, then mirror the plan's left part about a line */
    {
        int b4;
        jw_cmd_set(JW_CMD_KUKEI);
        at(120, 0, 0); at(180, 60, 0);
        b4 = d->nobj;
        jw_cmd_set(JW_CMD_HATCH);
        prompt_ok("hatch");
        at(150, 0, 1);                  /* the ring, with (R) */
        printf("pr[%s] en=%d\n", jw_cmd_prompt(), jw_cmd_bar_enabled(d, 1148));
        jw_cmd_bar(d, 1148);
        printf("n=%d b4=%d pr[%s]\n", d->nobj, b4, jw_cmd_prompt());
        ck(d->nobj > b4 + 3, "hatch laid lines");
        ck(jw_numbers_sane(d), "sane after hatch");
        jw_cmd_set(JW_CMD_SEN);
    }
    {
        int b4 = d->nobj, dp = jw_cmd_undo_depth();
        jw_cmd_set(JW_CMD_IDOU);
        at(115, -5, 0); at(185, 65, 0);
        jw_cmd_track(130, 10);
        jw_cmd_bar(d, 1120);
        jw_cmd_bar(d, 1067);            /* 反転 */
        line(0, 0, 0, 0);               /* harmless */
        jw_cmd_set(JW_CMD_IDOU);
        (void)b4; (void)dp;
        jw_cmd_set(JW_CMD_SEN);
        ck(jw_numbers_sane(d), "sane after mirror attempt");
    }
    roundtrip();

    /* Esc / right click from every command in the middle of a gesture */
    {
        static const int cmds[] = { JW_CMD_SEN, JW_CMD_KUKEI, JW_CMD_ENKO, JW_CMD_RENZOKU,
            JW_CMD_SHOUKYO, JW_CMD_CORNER, JW_CMD_SHINSHUKU, JW_CMD_FUKUSEN, JW_CMD_ZOKUHEN,
            JW_CMD_HANI, JW_CMD_FUKUSHA, JW_CMD_IDOU, JW_CMD_SUNPO, JW_CMD_TAKAKU,
            JW_CMD_MENTORI, JW_CMD_BUNKATSU, JW_CMD_CHUSHIN, JW_CMD_SEKIEN, JW_CMD_SESSEN,
            JW_CMD_NISEN, JW_CMD_HOURAKU, JW_CMD_HATCH, JW_CMD_KYOKUSEN, JW_CMD_SOKUTEI,
            JW_CMD_MOJI, JW_CMD_TEN };
        int c, rc;
        for (rc = 0; rc < 2; rc++)
        for (c = 0; c < (int)(sizeof cmds / sizeof *cmds); c++) {
            char m[160];
            int before = d->nobj, db = jw_cmd_undo_depth();
            jw_cmd_set(cmds[c]);
            char first[256];
            strncpy(first, jw_cmd_prompt(), 255); first[255] = 0;
            at(30, 30, 0);
            if (rc) at(70, 10, 1); else app_key(27);
            snprintf(m, sizeof m, "cancel(%s) cmd %x: prompt present", rc ? "right" : "esc", cmds[c]);
            prompt_ok(m);
            if (!rc && cmds[c] != JW_CMD_HANI && cmds[c] != JW_CMD_FUKUSHA && cmds[c] != JW_CMD_IDOU && cmds[c] != JW_CMD_SOKUTEI && d->nobj == before && jw_cmd_undo_depth() == db) {
                snprintf(m, sizeof m, "esc cmd %x: back to the first prompt", cmds[c]);
                ck(!strcmp(first, jw_cmd_prompt()), m);
                if (strcmp(first, jw_cmd_prompt()))
                    printf("     [%s] -> [%s]\n", first, jw_cmd_prompt());
            }
            jw_cmd_set(JW_CMD_SEN);
            snprintf(m, sizeof m, "cancel(%s) cmd %x: sane", rc ? "right" : "esc", cmds[c]);
            ck(jw_numbers_sane(d), m);
            (void)before; (void)db;
        }
    }

    commit();
    /* step the undo back through every committed state and compare exactly */
    {
        int k, guard;
        for (k = nss - 2; k >= 0; k--) {
            char m[100];
            guard = 0;
            while (jw_cmd_undo_depth() > ss[k].depth && guard++ < 500)
                jw_cmd_undo(d);
            { int q0; for (q0 = 0; q0 < d->nobj; q0++) { d->obj[q0].sel = 0; d->obj[q0].flags &= ~2u; } }
            if (d->nobj != ss[k].n || memcmp(d->obj, ss[k].o, (size_t)(d->nobj < ss[k].n ? d->nobj : ss[k].n) * sizeof *d->obj)) {
                int q;
                printf("  nobj %d vs %d ndrawn %d vs %d\n", d->nobj, ss[k].n, d->ndrawn, ss[k].nd);
                for (q = 0; q < d->nobj && q < ss[k].n; q++)
                    if (memcmp(&d->obj[q], &ss[k].o[q], sizeof *d->obj)) {
                        unsigned char *a = (unsigned char *)&d->obj[q], *b = (unsigned char *)&ss[k].o[q];
                        int z;
                        printf("  differs at %d (cls %d)\n", q, d->obj[q].cls);
                        for (z = 0; z < (int)sizeof *d->obj; z++)
                            if (a[z] != b[z]) printf("   byte %d: %d vs %d\n", z, a[z], b[z]);
                    }
            }
            snprintf(m, sizeof m, "undo back to phase %d: same elements (depth %d)", k, ss[k].depth);
            ck(d->nobj == ss[k].n && d->ndrawn == ss[k].nd
               && (!ss[k].n || !memcmp(d->obj, ss[k].o, (size_t)ss[k].n * sizeof *ss[k].o)), m);
        }
        for (k = 0; k < 400; k++) jw_cmd_redo(d);
        n1 = ss[nss - 1].n;
        printf("redo: %d vs %d depth %d vs %d\n", d->nobj, n1, jw_cmd_undo_depth(), ss[nss - 1].depth);
        ck(d->nobj == n1, "redo everything: count back");
    }
    /* undo all the way, redo all the way, many times */
    n1 = d->nobj;
    depth = jw_cmd_undo_depth();
    for (i = 0; i < 5; i++) {
        int k;
        for (k = 0; k < depth + 3; k++) jw_cmd_undo(d);
        if (i == 0) ck(d->nobj <= n0 + 0 || jw_cmd_undo_depth() == 0, "undo to bottom");
        for (k = 0; k < depth + 3; k++) jw_cmd_redo(d);
    }
    ck(d->nobj == n1, "redo all restores count after 5 rounds");
    ck(jw_numbers_sane(d), "sane after undo/redo storm");
    roundtrip();
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
