/* What is under the mouse -- src/pick.c against the original.
 *
 *   tests/pick_test.exe orig/Test7.jww
 *
 * Four of the cases were checked against Jw_cad itself, by fitting the
 * drawing, entering 消去 and right clicking, and seeing which element came
 * out of the saved file:
 *
 *   Test7            view 889,538   the text at (79.154, -87.726)
 *   Ａマンション平面例  view 290,246   the line (-114.648,42.123)-(-104.748,…)
 *                    view 333,246   the line  (-96.048,42.123)-(-92.148,…)
 *                    view 357,246   the line  (-85.648,42.123)-(-81.398,…)
 *
 * tmp/jwdraw.ps1 -Cmd 32835 -Clicks 'cmd:32794;r290,246;r333,246;r357,246'
 * took out those three lines and nothing else, out of 1,394.  The last three
 * sit among solids, so they also check that a solid does not win over a line
 * running past it.
 *
 * The rest are properties that have to hold for the pick to be any use at
 * all: the middle of a line finds that line, a point beats a line through
 * it, and far enough away nothing is found.
 */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../src/app.h"
#include "../src/jww.h"
#include "../src/pick.h"
#include "../src/view.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%s %s\n", ok ? "ok  " : "BAD ", what);
    if (!ok)
        fails++;
}

int main(int argc, char **argv)
{
    const jw_drawing *d;
    const jw_view *v;
    unsigned char *b;
    long n;
    FILE *f;
    int i, lines = 0, found = 0, text = -1;

    /* run bare (tools/qtest.sh pick), the first of the ones tools/check.sh gives it */
    if (argc < 2) {
        static char *def[] = { "pick_test", "orig/Test1.jww", 0 };
        argc = 2;
        argv = def;
    }
    app_new();
    app_resize(1264, 741);
    f = fopen(argv[1], "rb");
    if (!f) {
        printf("BAD  cannot open %s\n", argv[1]);
        return 1;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (!b || fread(b, 1, (size_t)n, f) != (size_t)n || !app_open(b, n)) {
        printf("BAD  cannot read %s\n", argv[1]);
        return 1;
    }
    fclose(f);
    app_paint();
    d = app_drawing();
    v = app_view();

    /* the middle of a line finds a line, and one that goes through there.
       Only lines that can be edited count: a layer set to "display only"
       cannot be picked, which is what the original's own list holds. */
    for (i = 0; i < d->ndrawn && lines < 200; i++) {
        const jw_obj *o = &d->obj[i];
        double mx, my;
        int k, g = o->lgroup & 15, l = o->layer & 15;
        if (o->cls != JW_SEN)
            continue;
        {   /* the same fold src/pick.c uses: 0 stays 0, 1 stays 1, the
               rest count as 3 */
            int gs = d->group[g].state, ls = d->group[g].layer[l].state;
            gs = gs == 0 ? 0 : gs == 1 ? 1 : 3;
            ls = ls == 0 ? 0 : ls == 1 ? 1 : 3;
            if ((gs & ls) != 3 || (o->flags & 1))
                continue;
        }
        lines++;
        mx = (o->d[0] + o->d[2]) / 2;
        my = (o->d[1] + o->d[3]) / 2;
        k = jw_pick(d, v, mx, my, 0);
        if (k >= 0 && d->obj[k].cls != JW_MOJI)
            found++;
        else
            printf("     %d: (%.3f,%.3f)-(%.3f,%.3f) found %d\n", i,
                   o->d[0], o->d[1], o->d[2], o->d[3], k);
    }
    if (lines == 0)
        printf("ok   nothing here can be edited, so nothing can be picked\n");
    else
        ck(found == lines, "the middle of every line finds something there");

    /* the text the original itself deleted */
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI
            && fabs(d->obj[i].d[0] - 79.154) < 0.001
            && fabs(d->obj[i].d[1] + 87.726) < 0.001)
            text = i;
    if (text >= 0) {
        const jw_obj *o = &d->obj[text];
        double mx = (o->d[0] + o->d[2]) / 2;
        double my = (o->d[1] + o->d[3]) / 2 + o->d[5] / 2;
        ck(jw_pick(d, v, mx, my, 0) == text,
           "the text Jw_cad deleted is the one the pick lands on");
        ck(jw_pick(d, v, mx, my, 3) != text,
           "and mode 3 -- which is not the one 消去 uses -- leaves text alone");
    }

    /* the three lines Jw_cad itself took out of the flat's plan */
    {
        static const struct { double px, py, x0, y0, x1, y1; } want[] = {
            { -114.297376, 41.995627, -114.648, 42.123, -104.748, 42.123 },
            {  -95.680758, 41.995627,  -96.048, 42.123,  -92.148, 42.123 },
            {  -85.290087, 41.995627,  -85.648, 42.123,  -81.398, 42.123 }
        };
        int w;
        for (w = 0; w < 3; w++) {
            int k = -1;
            for (i = 0; i < d->ndrawn; i++) {
                const jw_obj *o = &d->obj[i];
                if (o->cls == JW_SEN
                    && fabs(o->d[0] - want[w].x0) < 0.0005
                    && fabs(o->d[1] - want[w].y0) < 0.0005
                    && fabs(o->d[2] - want[w].x1) < 0.0005
                    && fabs(o->d[3] - want[w].y1) < 0.0005)
                    k = i;
            }
            if (k < 0)
                continue;       /* a different drawing */
            printf("%s the line Jw_cad took out at (%.3f, %.3f)\n",
                   jw_pick(d, v, want[w].px, want[w].py, 0) == k
                   ? "ok  " : "BAD ", want[w].px, want[w].py);
            if (jw_pick(d, v, want[w].px, want[w].py, 0) != k)
                fails++;
        }
    }

    /* nothing within reach of a point well outside the paper */
    ck(jw_pick(d, v, 1e6, 1e6, 0) < 0, "nothing is found out in the wild");

    /* the tolerance is ten pixels of paper */
    ck(fabs(jw_pick_tol(v) * v->scale - 10.0) < 1e-9,
       "the tolerance is the original's ten screen pixels");

    /* 逆順サーチ (基本設定 2445): 同じ所に重ねた二本は ふだん先の線、逆順なら後の線
       （FUN_0044a270 の +0x82bc） */
    {
        jw_drawing *two = (jw_drawing *)d;
        jw_obj *o;
        int n0 = two->ndrawn, a, b2;

        o = jw_add(two, JW_SEN);
        o->d[0] = 9000; o->d[1] = 9000; o->d[2] = 9100; o->d[3] = 9000;
        o = jw_add(two, JW_SEN);
        o->d[0] = 9000; o->d[1] = 9000; o->d[2] = 9100; o->d[3] = 9000;
        a = jw_pick(two, v, 9050.0, 9000.0, 0);
        jw_pick_reverse = 1;
        b2 = jw_pick(two, v, 9050.0, 9000.0, 0);
        jw_pick_reverse = 0;
        ck(a == n0 && b2 == n0 + 1, "逆順サーチ: 重なった二本の 先の線（ふだん）と 後の線（逆順）");
    }

    /* モード 0・2: 点を見たあとに来る線は、点より近くても 勝てない（FUN_0044a270 の bVar11。
       逆コンパイルの読み、原典では押していない）。モード 1 は ふつうに近い方 */
    {
        jw_drawing *two = (jw_drawing *)d;
        jw_obj *o;
        int n0 = two->ndrawn;
        double t = jw_pick_tol(v);

        o = jw_add(two, JW_TEN);
        o->d[0] = 7000; o->d[1] = 7000 + t * 0.8;
        o = jw_add(two, JW_SEN);
        o->d[0] = 6900; o->d[1] = 7000; o->d[2] = 7100; o->d[3] = 7000;
        ck(jw_pick(two, v, 7000.0, 7000.0, 0) == n0, "モード 0: 点のあとの近い線は 点に勝てない");
        ck(jw_pick(two, v, 7000.0, 7000.0, 2) == n0, "モード 2: 同じ");
        ck(jw_pick(two, v, 7000.0, 7000.0, 1) == n0 + 1, "モード 1: 近い線が勝つ");
    }

    /* 負の高さの字（反転したブロックの中の字）も拾えること。
       src/pick.c の dist_moji はかつて `if (ch <= 0.0) return 0;` を
       持っていたが、decomp/byclass/CDataMoji.c の FUN_0048a1e0
       （255-587行）には高さが 0 以下なら拾わないという枝が無いため
       この早期 return を削った（詳しくは src/pick.c の該当コメント）。
       ここでは ch を負にして字を作り、ベースラインから見て ch の側
       （本来なら字が無いはずの反対側）にある、字の箱の奥の辺のど真ん中
       を拾えることを確かめる。直す前は ch<=0 で即 return 0 だった
       ので、どこを押しても拾えなかった。 */
    {
        jw_drawing *two = (jw_drawing *)d;
        jw_obj *o;
        int n0 = two->ndrawn;
        double x0 = 8000, y0 = 8000, len = 100, ch = -20;

        o = jw_add(two, JW_MOJI);
        o->d[0] = x0; o->d[1] = y0;
        o->d[2] = x0 + len; o->d[3] = y0;
        o->d[4] = 10;   /* cw */
        o->d[5] = ch;   /* ch: negative -- the box sits below the baseline */
        ck(jw_pick(two, v, x0 + len / 2, y0 + ch, 0) == n0,
           "負の高さの字: 反転したブロックで ch 側に出る箱の奥の辺を拾える");
    }

    printf("%s\n", fails ? "FAILED": "all ok");
    return fails ? 1 : 0;
}
