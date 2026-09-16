/* The (R)Read point -- src/pick.c's jw_read against Jw_cad itself.
 *
 *   tests/read_test.exe orig/Test5.jww
 *
 * Every case here was measured by driving the original: the drawing is
 * fitted (全体表示), some geometry is drawn, and then the 点 command is fed
 * right clicks, which places a point exactly where the read landed -- or
 * places nothing at all when there was nothing to read.  The file Jw_cad
 * saved is what the expectations below come from.
 *
 *   tmp/jwdraw.ps1 -Cmd 32835 -Clicks 'cmd:32772;300,200;600,400;\
 *                                      cmd:32785;r450,205;r305,395;r800,600'
 *
 * The port's frame sits 78 across and 34 down from the original's drawing
 * window, so the clicks carry that offset.  The paper millimetres then have
 * to agree exactly.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"

static int fails;
static unsigned char *file;
static long filen;

static void ck(int ok, const char *what)
{
    printf("%s %s\n", ok ? "ok  " : "BAD ", what);
    if (!ok)
        fails++;
}

static void start(void)
{
    app_new();
    app_resize(1264, 741);
    app_open(file, filen);
    app_paint();
}

static void L(int x, int y) { app_press(x + 78, y + 34, 0); }
static void R(int x, int y) { app_press(x + 78, y + 34, 1); }

/* The points the drawing now holds, in the original's view coordinates. */
static int got(int *vx, int *vy, int max)
{
    const jw_drawing *d = app_drawing();
    const jw_view *v = app_view();
    int i, n = 0;

    for (i = 0; i < d->ndrawn && n < max; i++)
        if (d->obj[i].cls == JW_TEN) {
            vx[n] = jw_sx(v, d->obj[i].d[0]) - 78;
            vy[n] = jw_sy(v, d->obj[i].d[1]) - 34;
            n++;
        }
    return n;
}

static void want(const char *what, int n, const int *wx, const int *wy)
{
    int vx[8], vy[8], m = got(vx, vy, 8), i, ok = (m == n);

    for (i = 0; ok && i < n; i++)
        if (abs(vx[i] - wx[i]) > 1 || abs(vy[i] - wy[i]) > 1)
            ok = 0;
    if (!ok) {
        printf("     got %d:", m);
        for (i = 0; i < m; i++)
            printf(" (%d,%d)", vx[i], vy[i]);
        printf("\n");
    }
    ck(ok, what);
}

int main(int argc, char **argv)
{
    FILE *f;
    static const int none[1] = { 0 };

    if (argc < 2) {
        printf("usage: read_test drawing.jww\n");
        return 2;
    }
    f = fopen(argv[1], "rb");
    if (!f) {
        printf("BAD  cannot open %s\n", argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    filen = ftell(f);
    fseek(f, 0, SEEK_SET);
    file = (unsigned char *)malloc((size_t)filen);
    if (!file || fread(file, 1, (size_t)filen, f) != (size_t)filen) {
        printf("BAD  cannot read %s\n", argv[1]);
        return 1;
    }
    fclose(f);
    (void)none;

    {   /* a corner is read; the middle of an edge and open space are not */
        static const int wx[] = { 300 }, wy[] = { 400 };
        start();
        jw_cmd_set(0x8004); L(300, 200); L(600, 400);
        jw_cmd_set(0x8011); R(450, 205); R(305, 395); R(800, 600);
        want("only the corner of the four is read", 1, wx, wy);
    }
    {   /* where two lines cross is read too */
        static const int wx[] = { 300 }, wy[] = { 300 };
        start();
        jw_cmd_set(0x8004); L(300, 200); L(600, 400);
        jw_cmd_set(0x8003); L(250, 300); L(650, 300);
        jw_cmd_set(0x8011); R(300, 303); R(308, 208); R(313, 213);
        want("a crossing is read, and eight pixels away is too far", 1, wx, wy);
    }
    {   /* the boundary: ten pixels of Manhattan distance, no more */
        static const int wx[] = { 300, 600 }, wy[] = { 200, 400 };
        start();
        jw_cmd_set(0x8004); L(300, 200); L(600, 400);
        jw_cmd_set(0x8011); R(307, 203); R(606, 205); R(610, 400); R(311, 400);
        want("(7,3) and (10,0) read, (6,5) and (11,0) do not", 2, wx, wy);
    }
    {   /* a circle gives nothing, a line only its ends */
        static const int wx[] = { 600 }, wy[] = { 500 };
        start();
        jw_cmd_set(0x8005); L(400, 300); L(500, 300);
        jw_cmd_set(0x8003); L(600, 200); L(600, 500);
        jw_cmd_set(0x8011); R(402, 302); R(502, 300); R(602, 350); R(600, 502);
        want("no centre, no rim, no middle -- only the end of the line",
             1, wx, wy);
    }
    {   /* where a line crosses a circle is read too */
        static const int wx[] = { 400, 400 }, wy[] = { 200, 400 };
        start();
        jw_cmd_set(0x8005); L(400, 300); L(500, 300);
        jw_cmd_set(0x8003); L(400, 150); L(400, 450);
        jw_cmd_set(0x8011); R(400, 205); R(403, 400);
        want("both crossings of a line and a circle are read", 2, wx, wy);
    }
    {   /* and where two circles cross */
        static const int wx[] = { 475 }, wy[] = { 234 };
        start();
        jw_cmd_set(0x8005); L(400, 300); L(500, 300); L(550, 300); L(650, 300);
        jw_cmd_set(0x8011); R(475, 237);
        want("two circles crossing are read", 1, wx, wy);
    }
    {   /* a point that is already there is read */
        static const int wx[] = { 400, 400 }, wy[] = { 200, 200 };
        start();
        jw_cmd_set(0x8011); L(400, 200); R(403, 203);
        want("an existing point is read, and lands on top of it", 2, wx, wy);
    }

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails ? 1 : 0;
}
