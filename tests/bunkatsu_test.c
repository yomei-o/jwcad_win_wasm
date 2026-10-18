/* 分割 -- against the dividers the original drew.
 *
 *   tests/bunkatsu_test.exe [decomp/res/bunkatsu.jww]
 *
 * That file is Test5 with two lines on it -- neither parallel nor the same
 * length -- divided three ways, 分割数 3 typed into the command bar.  The
 * test draws the same two lines, types the same number, picks them, and
 * holds its two dividers up against the original's.  The original wrote the
 * ends of its pair the other way round, so the comparison takes a line
 * either way about.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-9;
}

/* 原典を tools/jwdraw.ps1 で直接叩いて読み出した数との突き合わせ用
   （2026-10-13、RESUME.md 参照）。.jww のテキスト往復ぶんのゆるさを見る。 */
static int near3(double a, double b)
{
    return fabs(a - b) < 5e-3;
}

static int same_line(const jw_obj *a, const jw_obj *b)
{
    return (near(a->d[0], b->d[0]) && near(a->d[1], b->d[1])
            && near(a->d[2], b->d[2]) && near(a->d[3], b->d[3]))
        || (near(a->d[0], b->d[2]) && near(a->d[1], b->d[3])
            && near(a->d[2], b->d[0]) && near(a->d[3], b->d[1]));
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

static void type_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

int main(int argc, char **argv)
{
    const char *path = argc > 1 ? argv[1] : "decomp/res/bunkatsu.jww";
    unsigned char *b;
    long n;
    jw_drawing ref, *d;
    const jw_obj *r[4] = { 0, 0, 0, 0 };
    int i, k = 0, before, ok;

    b = slurp(path, &n);
    if (!b) {
        printf("BAD  cannot read %s -- drive the original first\n", path);
        return 1;
    }
    if (!jw_parse(&ref, b, n)) {
        printf("BAD  %s: %s\n", path, ref.error);
        return 1;
    }
    free(b);
    /* the two lines that were drawn and the two dividers are the last four */
    for (i = 0; i < ref.ndrawn; i++)
        if (ref.obj[i].cls == JW_SEN) {
            r[0] = r[1];
            r[1] = r[2];
            r[2] = r[3];
            r[3] = &ref.obj[i];
            k++;
        }
    ck(k >= 4, "the original's dividers are in the file");
    if (k < 4)
        return 1;

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    {   /* the same two lines */
        jw_obj *o = jw_add(d, JW_SEN);
        o->d[0] = r[0]->d[0]; o->d[1] = r[0]->d[1];
        o->d[2] = r[0]->d[2]; o->d[3] = r[0]->d[3];
        o = jw_add(d, JW_SEN);
        o->d[0] = r[1]->d[0]; o->d[1] = r[1]->d[1];
        o->d[2] = r[1]->d[2]; o->d[3] = r[1]->d[3];
    }
    app_fit();
    before = d->ndrawn;

    jw_cmd_set(JW_CMD_BUNKATSU);
    ck(jw_cmd_box(1411) && !*jw_cmd_box(1411),
       "分割 starts with an empty 分割数");
    {   /* pick the two lines by their middles */
        double a1x = (r[0]->d[0] + r[0]->d[2]) / 2;
        double a1y = (r[0]->d[1] + r[0]->d[3]) / 2;
        double b1x = (r[1]->d[0] + r[1]->d[2]) / 2;
        double b1y = (r[1]->d[1] + r[1]->d[3]) / 2;
        jw_cmd_point(d, app_view(), a1x, a1y, 0);
        jw_cmd_point(d, app_view(), b1x, b1y, 0);
        ck(d->ndrawn == before + 1, "and divides in two while it is empty");
        while (d->ndrawn > before && jw_cmd_can_undo())
            jw_cmd_undo(d);
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "3");
        jw_cmd_point(d, app_view(), a1x, a1y, 0);
        jw_cmd_point(d, app_view(), b1x, b1y, 0);
    }
    ck(d->ndrawn == before + 2, "3 leaves two lines between them");
    if (d->ndrawn != before + 2)
        return 1;
    ok = same_line(&d->obj[before], r[2]) && same_line(&d->obj[before + 1], r[3]);
    if (!ok) {
        for (i = 0; i < 2; i++)
            printf("     ours %.4f,%.4f -> %.4f,%.4f\n",
                   d->obj[before + i].d[0], d->obj[before + i].d[1],
                   d->obj[before + i].d[2], d->obj[before + i].d[3]);
        for (i = 2; i < 4; i++)
            printf("     the original's %.4f,%.4f -> %.4f,%.4f\n",
                   r[i]->d[0], r[i]->d[1], r[i]->d[2], r[i]->d[3]);
    }
    ck(ok, "both exactly where the original put them");
    ck(d->obj[before].color == 2 && d->obj[before].ltype == 1,
       "in the pen new elements get");
    jw_cmd_undo(d);
    ck(d->ndrawn == before, "元に戻る takes both back");

    /* A 分割数 that is not a whole number, and ones out of range.  These are
       read out of the decompilation (FUN_007668f0, FUN_0075d660 and
       FUN_007674b0, the note on bunkatsu() in src/cmd.c), not measured: a
       step of (end - start) / n, (int)n - 1 lines and one more for a
       fractional part, 1.01 at the least and 10000 at the most. */
    {
        static const struct {
            const char *n;
            int lines;
            double first, last;     /* how far along, 0..1 */
            const char *after;      /* what the box holds afterwards */
            const char *what;
        } F[] = {
            { "2.5", 2, 0.4, 0.8, "2.5",
              "2.5 leaves two lines, at 0.4 and 0.8 of the way" },
            { "1.5", 1, 1 / 1.5, 1 / 1.5, "1.5",
              "1.5 leaves one, two thirds of the way" },
            { "1", 1, 1 / 1.01, 1 / 1.01, "1.01",
              "1 is taken as 1.01, and the box says so" },
            { "10001", 0, 0, 0, "10000",
              "more than 10000 is refused, and the box is set to 10000" },
            { "5000", 4999, 1 / 5000.0, 4999 / 5000.0, "5000",
              "5000 is not too many (the port refused anything past 1000)" },
        };
        double a1x = (r[0]->d[0] + r[0]->d[2]) / 2;
        double a1y = (r[0]->d[1] + r[0]->d[3]) / 2;
        double b1x = (r[1]->d[0] + r[1]->d[2]) / 2;
        double b1y = (r[1]->d[1] + r[1]->d[3]) / 2;
        const jw_obj *p0 = &d->obj[before - 2], *q0 = &d->obj[before - 1];
        unsigned f;

        for (f = 0; f < sizeof F / sizeof F[0]; f++) {
            int was = d->ndrawn, good;

            jw_cmd_set(JW_CMD_BUNKATSU);
            type_box(1411, F[f].n);
            jw_cmd_point(d, app_view(), a1x, a1y, 0);
            jw_cmd_point(d, app_view(), b1x, b1y, 0);
            p0 = &d->obj[before - 2];
            q0 = &d->obj[before - 1];
            good = d->ndrawn - was == F[f].lines;
            if (good && F[f].lines > 0) {
                const jw_obj *a = &d->obj[was], *z = &d->obj[d->ndrawn - 1];
                double ex = p0->d[0] + (q0->d[0] - p0->d[0]) * F[f].first;
                double ey = p0->d[1] + (q0->d[1] - p0->d[1]) * F[f].first;
                double zx = p0->d[0] + (q0->d[0] - p0->d[0]) * F[f].last;
                double zy = p0->d[1] + (q0->d[1] - p0->d[1]) * F[f].last;

                /* the original writes the longer rung's end first
                   (decomp/res/bunkatsu.jww; tools/fzcheck.py), so the line
                   may run from either side */
                double ex2 = p0->d[2] + (q0->d[2] - p0->d[2]) * F[f].first;
                double ey2 = p0->d[3] + (q0->d[3] - p0->d[3]) * F[f].first;
                double zx2 = p0->d[2] + (q0->d[2] - p0->d[2]) * F[f].last;
                double zy2 = p0->d[3] + (q0->d[3] - p0->d[3]) * F[f].last;

                good = (near(a->d[0], ex) && near(a->d[1], ey)
                        && near(z->d[0], zx) && near(z->d[1], zy))
                       || (near(a->d[0], ex2) && near(a->d[1], ey2)
                           && near(z->d[0], zx2) && near(z->d[1], zy2));
            }
            good = good && jw_cmd_box(1411)
                   && !strcmp(jw_cmd_box(1411), F[f].after);
            if (!good)
                printf("     %s: %d lines, box \"%s\"\n", F[f].n,
                       d->ndrawn - was,
                       jw_cmd_box(1411) ? jw_cmd_box(1411) : "(none)");
            ck(good, F[f].what);
            while (d->ndrawn > was && jw_cmd_can_undo())
                jw_cmd_undo(d);
        }
    }

    /* 分割始点 (R): 点＋線・点＋円・円Ａ＋円Ｂ・２点間（直線・線上・円周）・
     * 円全周分割。tools/jwdraw.ps1 で原典を直接叩いた実測（2026-10-13、
     * RESUME.md 同日の節、各 bk_* 関数のコメントに番地と式）との突き合わせ。
     * 幾何はその実測と同じものをここに作り直す。 */
    {
        jw_obj *o_;             /* only for the one that has just been made: the array moves */
        int i0;
        const jw_view *v = app_view();
        int g;

#define MKSEN(o, x0, y0, x1, y1) \
        do { (o) = jw_add(d, JW_SEN); (o)->d[0] = (x0); (o)->d[1] = (y0); \
             (o)->d[2] = (x1); (o)->d[3] = (y1); } while (0)
#define MKENKO(o, cx, cy, rr) \
        do { (o) = jw_add(d, JW_ENKO); (o)->d[0] = (cx); (o)->d[1] = (cy); \
             (o)->d[2] = (rr); (o)->d[3] = 0.0; \
             (o)->d[4] = 6.283185307179586; (o)->d[5] = 0.0; \
             (o)->d[6] = 1.0; (o)->n = 1; } while (0)

        MKSEN(o_, -155.51, 26.3265, -94.2857, 26.3265);
        MKSEN(o_, -155.51, -4.28571, -94.2857, -4.28571);
        MKSEN(o_, 28.1633, 26.3265, 89.3878, 26.3265);
        MKSEN(o_, -106.531, 56.9388, -106.531, -47.1429);
        MKENKO(o_, -33.0612, -96.1224, 36.7347);
        MKENKO(o_, 58.7755, -96.1224, 24.4898);
        o_ = jw_add(d, JW_TEN);
        o_->d[0] = -33.0612; o_->d[1] = -59.3878; o_->n = 0;
        o_ = jw_add(d, JW_TEN);
        o_->d[0] = 3.67347; o_->d[1] = -96.1224; o_->n = 0;
        /* the commands below add elements too, and the array moves when it grows:
           so the eight are found by their place every time they are used */
        i0 = d->ndrawn - 8;
#define l1 (&d->obj[i0 + 0])
#define l2 (&d->obj[i0 + 1])
#define l3 (&d->obj[i0 + 2])
#define l4 (&d->obj[i0 + 3])
#define ca (&d->obj[i0 + 4])
#define cb (&d->obj[i0 + 5])
#define pt_top (&d->obj[i0 + 6])
#define pt_right (&d->obj[i0 + 7])

        /* 始点＋線 Ｂ (L): 点 P=l1 の始点、線 B=l2、n=3 */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "3");
        jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);          /* (R) 始点 */
        jw_cmd_point(d, v, (l2->d[0] + l2->d[2]) / 2, l2->d[1], 0); /* (L) 線B */
        ck(d->ndrawn == g + 2
           && near3(d->obj[g].d[0], -155.51) && near3(d->obj[g].d[1], 16.1224)
           && near3(d->obj[g].d[2], -135.102) && near3(d->obj[g].d[3], 16.1224)
           && near3(d->obj[g + 1].d[0], -155.51) && near3(d->obj[g + 1].d[1], 5.91837)
           && near3(d->obj[g + 1].d[2], -114.694) && near3(d->obj[g + 1].d[3], 5.91837),
           "分割始点 (R) ＋ 線【B】(L): 点 P から扇");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 始点＋円 Ｂ (L): 点 P=l4 の上端、円 B=cb、n=3 */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "3");
        jw_cmd_point(d, v, l4->d[0], l4->d[1], 1);
        jw_cmd_point(d, v, cb->d[0] + cb->d[2], cb->d[1], 0); /* 円周の右端 */
        ck(d->ndrawn == g + 2
           && near3(d->obj[g].d[0], -51.4286) && near3(d->obj[g].d[1], 5.91837)
           && near3(d->obj[g].d[2], 8.16327)
           && near3(d->obj[g + 1].d[0], 3.67347) && near3(d->obj[g + 1].d[1], -45.102)
           && near3(d->obj[g + 1].d[2], 16.3265),
           "分割始点 (R) ＋ 円【B】(L): 中心 P+(C-P)k/n・半径 r・k/n");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 円Ａ (L) ＋ 円Ｂ (L)（classic、円どうし）、n=3 */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "3");
        jw_cmd_point(d, v, ca->d[0] + ca->d[2], ca->d[1], 0);
        jw_cmd_point(d, v, cb->d[0] + cb->d[2], cb->d[1], 0);
        ck(d->ndrawn == g + 2
           && near3(d->obj[g].d[0], -2.44898) && near3(d->obj[g].d[1], -96.1224)
           && near3(d->obj[g].d[2], 32.6531)
           && near3(d->obj[g + 1].d[0], 28.1633) && near3(d->obj[g + 1].d[1], -96.1224)
           && near3(d->obj[g + 1].d[2], 28.5714),
           "円Ａ(L)＋円Ｂ(L): 中心・半径の線形補間（点＋円と同じ式）");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 線 A (L) ＋ 点 E (R)（逆向き）: formula の対称性だけの確認
           （「E から A への同じ扇」、原典でこの組み合わせ自体は未確認） */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "3");
        jw_cmd_point(d, v, (l1->d[0] + l1->d[2]) / 2, l1->d[1], 0); /* (L) 線A */
        jw_cmd_point(d, v, l3->d[2], l3->d[3], 1);                  /* (R) 点E */
        ck(d->ndrawn == g + 2, "線Ａ(L)＋点Ｅ(R) も扇を 2 本引く（対称性のみ）");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 始点＋第二点 (R)(R)、(R) で確定する２点間分割（線・円を介さない） */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "4");
        jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);
        jw_cmd_point(d, v, l3->d[2], l3->d[3], 1);
        jw_cmd_point(d, v, 900.0, 900.0, 1);         /* 線・円にかからない(R) */
        ck(d->ndrawn == g + 3
           && near3(d->obj[g].d[0], -94.2857) && near3(d->obj[g].d[1], 26.3265)
           && near3(d->obj[g + 1].d[0], -33.0612) && near3(d->obj[g + 1].d[1], 26.3265)
           && near3(d->obj[g + 2].d[0], 28.1633) && near3(d->obj[g + 2].d[1], 26.3265),
           "始点＋第二点(R)(R)、(R)確定: P1-P2 をそのまま線形補間");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 同じ二点のあと、(L) で線を指示: 線の方向へ射影した媒介変数を補間 */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "3");
        jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);
        jw_cmd_point(d, v, l3->d[2], l3->d[3], 1);
        jw_cmd_point(d, v, (l2->d[0] + l2->d[2]) / 2, l2->d[1], 0);
        ck(d->ndrawn == g + 2
           && near3(d->obj[g].d[0], -73.8776) && near3(d->obj[g].d[1], -4.28571)
           && near3(d->obj[g + 1].d[0], 7.7551) && near3(d->obj[g + 1].d[1], -4.28571),
           "始点＋第二点(R)(R)、線(L): 射影した媒介変数を補間");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 円の上の二点 (R)(R) のあと、(L) でその円を指示: 円の２点間分割 */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "4");
        jw_cmd_point(d, v, pt_top->d[0], pt_top->d[1], 1);
        jw_cmd_point(d, v, pt_right->d[0], pt_right->d[1], 1);
        jw_cmd_point(d, v, ca->d[0] + ca->d[2] * 0.70710678, ca->d[1] + ca->d[2] * 0.70710678, 0);
                                                                /* 円周の 45°（短い弧の上） */
        ck(d->ndrawn == g + 3
           && near3(d->obj[g].d[0], -19.0035) && near3(d->obj[g].d[1], -62.184)
           && near3(d->obj[g + 1].d[0], -7.08587) && near3(d->obj[g + 1].d[1], -70.1471)
           && near3(d->obj[g + 2].d[0], 0.877207) && near3(d->obj[g + 2].d[1], -82.0647),
           "始点＋第二点(R)(R)、円(L): 円の２点間分割（指示した側が短い弧ならそれを等分、bk_w10）");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 指示が 180° のほうなら 長い弧 270°（反時計回り）を等分する（bk_w3） */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "4");
        jw_cmd_point(d, v, pt_top->d[0], pt_top->d[1], 1);
        jw_cmd_point(d, v, pt_right->d[0], pt_right->d[1], 1);
        jw_cmd_point(d, v, ca->d[0] - ca->d[2], ca->d[1], 0);   /* 円周の左端 */
        ck(d->ndrawn == g + 3
           && near3(d->obj[g].d[0], -66.9997) && near3(d->obj[g].d[1], -82.0647)
           && near3(d->obj[g + 1].d[0], -59.0366) && near3(d->obj[g + 1].d[1], -122.098)
           && near3(d->obj[g + 2].d[0], -19.0035) && near3(d->obj[g + 2].d[1], -130.061),
           "円の２点間分割: 指示した側の長い弧を等分（bk_w3）");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 円全周分割 (R)円指示。原典実測 2 通り（θP はいずれも円の中心から
           点 P への向き、外積の符号で回る向きが決まる） */
        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "5");
        jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);           /* P, θP=135° */
        jw_cmd_point(d, v, -7.3465, -70.408, 1);             /* 円周上、時計回り側 */
        ck(d->ndrawn == g + 4
           && near3(d->obj[g].d[0], -16.384) && near3(d->obj[g].d[1], -63.3916)
           && near3(d->obj[g + 1].d[0], 3.2212) && near3(d->obj[g + 1].d[1], -101.869)
           && near3(d->obj[g + 2].d[0], -27.3147) && near3(d->obj[g + 2].d[1], -132.405)
           && near3(d->obj[g + 3].d[0], -65.7921) && near3(d->obj[g + 3].d[1], -112.8),
           "円全周分割 (R)円指示: θP から時計回りに 360/n");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        g = d->ndrawn;
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "4");
        jw_cmd_point(d, v, l4->d[0], l4->d[1], 1);           /* P, θP=115.7° */
        jw_cmd_point(d, v, -33.061, -132.857, 1);            /* 円周上、反時計回り側 */
        ck(d->ndrawn == g + 3
           && near3(d->obj[g].d[0], -66.1784) && near3(d->obj[g].d[1], -112.019)
           && near3(d->obj[g + 1].d[0], -17.165) && near3(d->obj[g + 1].d[1], -129.24)
           && near3(d->obj[g + 2].d[0], 0.055949) && near3(d->obj[g + 2].d[1], -80.2262),
           "円全周分割 (R)円指示: 外積の符号が逆なら反時計回り");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 連続点分割 (RR)。tools/bkprobe.sh で原典を叩いた答え
         * （decomp/res/bk_rrA.jww・bk_rrD.jww・bk_rr2.jww、2026-10-13）。
         * 画面 (sx,sy) は紙の (-155.510204+(sx-300)*30/49, 26.326531-(sy-300)*30/49)。
         * (L) の自由点はその式で置き直す。src/cmd.c の bk_points_between・
         * bk_rr_finish に番地。 */
        {
            static const struct { double x, y; } A[] = {
                { -155.510204, 26.326531 }, { -33.061224, 56.938776 },
                { -94.403819, 67.064121 }, { -75.218139, 52.917011 },
                { -84.991666, 5.008334 },
            }, D[] = {
                { 28.163265, 26.326531 }, { 89.387755, 26.326531 },
                { 46.051809, 62.103618 }, { 63.940353, 77.221335 },
                { 81.828897, 41.444247 },
            }, D2[] = {
                { 28.163265, 26.326531 }, { 84.489796, 26.326531 },
                { 40.429518, 50.859037 }, { 58.318062, 86.636124 },
                { 73.868715, 51.614818 },
            };
            char box[32];
            int wg = 0, j, okk;
            jw_obj *pe;

            for (j = 0; j < 16; j++)
                if (d->group[j].state == 3)
                    wg = j;
            /* 原典は 1/100 に 4000（= 40mm）。ここの縮尺で同じ 40mm にする */
            snprintf(box, sizeof box, "%.6g", 40.0 * d->group[wg].scale);

            /* 分割数 4: 始点を (R)(R)、(L) 自由点、(R) 線の端、(L) 自由点、(L) 同じ点で閉じる */
            g = d->ndrawn;
            jw_cmd_set(JW_CMD_BUNKATSU);
            type_box(1411, "4");
            jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);
            ck(!strcmp(jw_cmd_prompt(), JW_STR_5361), "連続点分割: (R) 一回目は 5361");
            jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);
            ck(!strcmp(jw_cmd_prompt(), JW_STR_5819) && jw_cmd_midway(),
               "連続点分割: 同じ点をもう一度 (R) で 5819（1 点）");
            jw_cmd_point(d, v, -63.673469, 87.551020, 0);
            ck(!strcmp(jw_cmd_prompt(), JW_STR_5820), "連続点分割: (L) で足して 5820");
            jw_cmd_point(d, v, l2->d[2], l2->d[3], 1);
            {
                /* 途中の仮表示（原典 FUN_007614c0）: 点を順に結ぶ線と、最後の点からカーソルまで。
                   線種は原典を tools/jwdraw.ps1 で直接叩いた実測（2026-10-18、既存の
                   線の上に重ねて XOR させ、100 画素連続でシアンになる＝実線／白地の上の
                   破線を測って 点 4 個の塊・隙間 5 画素・周期 8 ＝線種 3「点線2」）:
                   積んだ点どうしを結ぶ分は実線（既定の線種 1）、最後の点からカーソル
                   までの分だけ線種 3 になる（src/cmd.c の jw_cmd_pending、注に番地）。 */
                jw_obj tmp[8];
                int np;

                jw_cmd_track(10.0, 20.0);
                np = jw_cmd_pending(d, tmp, 8);
                ck(np == 3 && tmp[0].cls == JW_SEN
                   && near3(tmp[0].d[0], l1->d[0]) && near3(tmp[0].d[2], -63.673469)
                   && near3(tmp[1].d[2], l2->d[2]) && near3(tmp[1].d[3], l2->d[3])
                   && near3(tmp[2].d[0], l2->d[2]) && near3(tmp[2].d[2], 10.0)
                   && near3(tmp[2].d[3], 20.0),
                   "連続点分割: 途中は点を結ぶ線と、最後の点からカーソルまでの線を仮に出す");
                ck(tmp[0].ltype == 1 && tmp[1].ltype == 1 && tmp[2].ltype == 3,
                   "連続点分割の仮表示: 積んだ点どうしは実線、最後からカーソルまでは点線2（原典実測）");
            }
            jw_cmd_point(d, v, -33.061224, 56.938776, 0);
            ck(d->ndrawn == g, "連続点分割: 閉じるまでは何も置かない");
            jw_cmd_point(d, v, -33.061224, 56.938776, 0);
            okk = d->ndrawn == g + 5;
            for (j = 0; okk && j < 5; j++)
                okk = d->obj[g + j].cls == JW_TEN
                      && near3(d->obj[g + j].d[0], A[j].x) && near3(d->obj[g + j].d[1], A[j].y);
            ck(okk && !jw_cmd_midway() && !strcmp(jw_cmd_prompt(), JW_STR_5357),
               "連続点分割 分割数 4: 両端の 2 点のあとに弧長 L/4 おきの 3 点（bk_rrA）");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);

            /* Esc は点を一つずつ外す（3 点 → 5820 → 5819 → 5357） */
            g = d->ndrawn;
            jw_cmd_set(JW_CMD_BUNKATSU);
            jw_cmd_point(d, v, l2->d[0], l2->d[1], 1);
            jw_cmd_point(d, v, l2->d[0], l2->d[1], 1);
            jw_cmd_point(d, v, -63.673469, -34.897959, 0);
            jw_cmd_point(d, v, -2.448980, -34.897959, 0);
            jw_cmd_esc_key(d);
            okk = !strcmp(jw_cmd_prompt(), JW_STR_5820);
            jw_cmd_esc_key(d);
            okk = okk && !strcmp(jw_cmd_prompt(), JW_STR_5819);
            jw_cmd_esc_key(d);
            ck(okk && !strcmp(jw_cmd_prompt(), JW_STR_5357) && !jw_cmd_midway()
               && d->ndrawn == g, "連続点分割の Esc: 一点ずつ外して第一案内へ（bk_rr2）");

            /* 割付 40mm（振分なし）: (R)(R) 線の端、(L) 自由点、(R)(R) もう一方の端 */
            g = d->ndrawn;
            jw_cmd_set(JW_CMD_BUNKATSU);
            if (jw_cmd_bar_check(1324) <= 0)
                jw_cmd_bar(d, 1324);
            if (jw_cmd_bar_check(1325) > 0)
                jw_cmd_bar(d, 1325);
            type_box(1412, box);
            jw_cmd_point(d, v, l3->d[0], l3->d[1], 1);
            jw_cmd_point(d, v, l3->d[0], l3->d[1], 1);
            jw_cmd_point(d, v, 58.775510, 87.551020, 0);
            jw_cmd_point(d, v, l3->d[2], l3->d[3], 1);
            jw_cmd_point(d, v, l3->d[2], l3->d[3], 1);
            okk = d->ndrawn == g + 5;
            for (j = 0; okk && j < 5; j++)
                okk = near3(d->obj[g + j].d[0], D[j].x) && near3(d->obj[g + j].d[1], D[j].y);
            ck(okk, "連続点分割 割付 40mm: 両端と弧長 40mm おきの 3 点（bk_rrD）");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);

            /* 割付 40mm の２点間 (R)(R)(R): 両端なしで 40mm おきに 6 点 */
            g = d->ndrawn;
            jw_cmd_set(JW_CMD_BUNKATSU);
            type_box(1412, box);
            jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);
            jw_cmd_point(d, v, l3->d[2], l3->d[3], 1);
            jw_cmd_point(d, v, 900.0, 900.0, 1);
            okk = d->ndrawn == g + 6;
            for (j = 0; okk && j < 6; j++)
                okk = near3(d->obj[g + j].d[0], -115.510204 + 40.0 * j)
                      && near3(d->obj[g + j].d[1], 26.326531);
            ck(okk, "２点間分割 割付 40mm: 40mm おきに 6 点、両端は置かない（bk_rr2）");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);

            /* 仮点 (1323) を入れた２点間分割（分割数 3）: 点が仮点 (kind=1) になる
               （decomp/res/bk_kari.jww） */
            jw_cmd_bar(d, 1324);                        /* 割付 を外す */
            g = d->ndrawn;
            jw_cmd_set(JW_CMD_BUNKATSU);
            if (jw_cmd_bar_check(1323) <= 0)
                jw_cmd_bar(d, 1323);
            type_box(1411, "3");
            jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);
            jw_cmd_point(d, v, l3->d[2], l3->d[3], 1);
            jw_cmd_point(d, v, 900.0, 900.0, 1);
            ck(d->ndrawn == g + 2 && d->obj[g].n == 1 && d->obj[g + 1].n == 1
               && near3(d->obj[g].d[0], -73.877551) && near3(d->obj[g + 1].d[0], 7.755102),
               "２点間分割 仮点 (1323): 点が仮点になる（bk_kari）");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);
            jw_cmd_bar(d, 1323);
            jw_cmd_bar(d, 1324);                        /* 割付 に戻す */

            /* 割付＋振分: 終点は原典では先の答えの点 (84.49,26.33) を読んでいた */
            pe = jw_add(d, JW_TEN);
            pe->d[0] = 84.489796; pe->d[1] = 26.326531; pe->n = 0;
            g = d->ndrawn;
            jw_cmd_set(JW_CMD_BUNKATSU);
            jw_cmd_bar(d, 1325);
            type_box(1412, box);
            jw_cmd_point(d, v, l3->d[0], l3->d[1], 1);
            jw_cmd_point(d, v, l3->d[0], l3->d[1], 1);
            jw_cmd_point(d, v, 58.775510, 87.551020, 0);
            jw_cmd_point(d, v, 84.489796, 26.326531, 1);
            jw_cmd_point(d, v, 84.489796, 26.326531, 1);
            okk = d->ndrawn == g + 5;
            for (j = 0; okk && j < 5; j++)
                okk = near3(d->obj[g + j].d[0], D2[j].x) && near3(d->obj[g + j].d[1], D2[j].y);
            ck(okk, "連続点分割 割付＋振分: 余りを半分ずつ（bk_rr2）");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);
            jw_cmd_bar(d, 1325);
            jw_cmd_bar(d, 1324);
        }

        /* 円の 割付（原典実測 2026-10-14、decomp/res/bk_w1〜w9.jww）。
         * 割付 30mm（箱 3000）で 円の２点間（指示 180°）・円全周・円 A→円 B の扇 */
        {
            static const struct { double x, y; } T2[] = {
                { -59.8360, -70.9719 }, { -69.7241, -98.4182 }, { -56.4893, -124.417 },
                { -28.4786, -132.570 }, { -3.3582, -117.736 } },
            T2V[] = {
                { -57.3624, -68.5745 }, { -69.7780, -94.9740 }, { -59.0366, -122.098 },
                { -31.9128, -132.839 }, { -5.5133, -120.424 } },
            T2K[] = {
                { -59.0366, -70.1471 }, { -69.7959, -96.1224 }, { -59.0366, -122.098 },
                { -33.0612, -132.857 }, { -7.0859, -122.098 } },
            TF[] = {
                { -59.8360, -70.9719 }, { -69.7241, -98.4182 }, { -56.4893, -124.417 },
                { -28.4786, -132.570 }, { -3.3582, -117.736 }, { 3.0289, -89.2710 },
                { -13.3458, -65.1267 } },
            TFV[] = {
                { -9.6331, -67.8282 }, { 3.6017, -93.8267 }, { -6.2865, -121.273 },
                { -33.0612, -132.857 }, { -59.8360, -121.273 }, { -69.7241, -93.8267 },
                { -56.4893, -67.8282 } },
            TFK[] = {
                { -59.0366, -70.1471 }, { -69.7959, -96.1224 }, { -59.0366, -122.098 },
                { -33.0612, -132.857 }, { -7.0859, -122.098 }, { 3.6735, -96.1224 },
                { -7.0859, -70.1471 } };
            static const struct { double x, y, r; } FAN[] = {
                { -3.06122, -96.1224, 32.2347 }, { 26.9388, -96.1224, 27.7347 },
                { 56.9388, -96.1224, 23.2347 }, { 86.9388, -96.1224, 18.7347 } };
            int j, okk, wg = 0;
            char box30[32];
            jw_obj *cc;

            for (j = 0; j < 16; j++)
                if (d->group[j].state == 3)
                    wg = j;
            snprintf(box30, sizeof box30, "%.6g", 30.0 * d->group[wg].scale);

            jw_cmd_set(JW_CMD_BUNKATSU);
            if (jw_cmd_bar_check(1324) <= 0)
                jw_cmd_bar(d, 1324);
            if (jw_cmd_bar_check(1325) > 0)
                jw_cmd_bar(d, 1325);
#define ARCRUN(label, cnt, TAB, click_x, click_y, rr) \
            g = d->ndrawn; \
            jw_cmd_set(JW_CMD_BUNKATSU); \
            jw_cmd_point(d, v, pt_top->d[0], pt_top->d[1], 1); \
            if (rr) jw_cmd_point(d, v, (click_x), (click_y), 1); \
            else { jw_cmd_point(d, v, pt_right->d[0], pt_right->d[1], 1); \
                   jw_cmd_point(d, v, (click_x), (click_y), 0); } \
            okk = d->ndrawn == g + (cnt); \
            for (j = 0; okk && j < (cnt); j++) \
                okk = near3(d->obj[g + j].d[0], TAB[j].x) && near3(d->obj[g + j].d[1], TAB[j].y); \
            ck(okk, label); \
            while (d->ndrawn > g && jw_cmd_can_undo()) \
                jw_cmd_undo(d);

            type_box(1412, box30);
            ARCRUN("円の２点間分割 割付 30mm: 30mm おきに 5 点（長い弧、bk_w2）", 5, T2,
                   ca->d[0] - ca->d[2], ca->d[1], 0)
            jw_cmd_bar(d, 1325);
            ARCRUN("円の２点間分割 割付＋振分: 余りを半分ずつ（bk_w4）", 5, T2V,
                   ca->d[0] - ca->d[2], ca->d[1], 0)
            jw_cmd_bar(d, 1325);
            jw_cmd_bar(d, 1326);
            ARCRUN("円の２点間分割 割付距離以下: 6 等分（bk_w5）", 5, T2K,
                   ca->d[0] - ca->d[2], ca->d[1], 0)
            ARCRUN("円全周分割 割付距離以下: 8 等分、反時計回り（bk_w9）", 7, TFK,
                   ca->d[0] - ca->d[2], ca->d[1], 1)
            jw_cmd_bar(d, 1326);
            ARCRUN("円全周分割 割付 30mm: 7 点、反時計回り（bk_w7）", 7, TF,
                   ca->d[0] - ca->d[2], ca->d[1], 1)
            jw_cmd_bar(d, 1325);
            ARCRUN("円全周分割 割付＋振分: 時計回り（bk_w8）", 7, TFV,
                   ca->d[0] + ca->d[2] * 0.70710678, ca->d[1] - ca->d[2] * 0.70710678, 1)
            jw_cmd_bar(d, 1325);
#undef ARCRUN
            /* 円 A（ca）→ 円 B（中心(89.3878,-96.1224) 半径 18.3673）の扇 */
            MKENKO(cc, 89.3878, -96.1224, 18.3673);
            g = d->ndrawn;
            jw_cmd_set(JW_CMD_BUNKATSU);
            jw_cmd_point(d, v, ca->d[0] - ca->d[2], ca->d[1], 0);
            jw_cmd_point(d, v, cc->d[0] + cc->d[2], cc->d[1], 0);
            okk = d->ndrawn == g + 4;
            for (j = 0; okk && j < 4; j++)
                okk = d->obj[g + j].cls == JW_ENKO && d->obj[g + j].n == 1
                      && near3(d->obj[g + j].d[0], FAN[j].x) && near3(d->obj[g + j].d[1], FAN[j].y)
                      && near3(d->obj[g + j].d[2], FAN[j].r);
            ck(okk, "円 A＋円 B の扇 割付 30mm: 中心 30 ずつ・半径 4.5 ずつ（bk_w1）");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);
            /* 点 P（線 l1 の始点）→ 線 l4 の扇 割付 15mm: P から線までの垂直距離
               48.98 を 15 ずつ。x=-140.51・-125.51・-110.51 の 3 本（bk_w12） */
            {
                static const double W12[3][4] = {
                    { -140.51, 35.7015, -140.51, 3.82653 },
                    { -125.51, 45.0765, -125.51, -18.6735 },
                    { -110.51, 54.4515, -110.51, -41.1735 } };
                char b15[32];

                snprintf(b15, sizeof b15, "%.6g", 15.0 * d->group[wg].scale);
                type_box(1412, b15);
                g = d->ndrawn;
                jw_cmd_set(JW_CMD_BUNKATSU);
                jw_cmd_point(d, v, l1->d[0], l1->d[1], 1);
                jw_cmd_point(d, v, l4->d[0], -30.0, 0);
                okk = d->ndrawn == g + 3;
                for (j = 0; okk && j < 3; j++)
                    okk = near3(d->obj[g + j].d[0], W12[j][0]) && near3(d->obj[g + j].d[1], W12[j][1])
                          && near3(d->obj[g + j].d[2], W12[j][2]) && near3(d->obj[g + j].d[3], W12[j][3]);
                ck(okk, "点＋線の扇 割付 15mm: 垂直距離 48.98 を 15 ずつ（bk_w12）");
                while (d->ndrawn > g && jw_cmd_can_undo())
                    jw_cmd_undo(d);
            }
            jw_cmd_bar(d, 1324);                        /* 割付 を外す */
        }
#undef MKSEN
#undef MKENKO
    }

    /* 逆分割（分割数が負）と補助設定の釦（逆分割 1066・線長割合分割 1064）。
     * 逆コンパイルの読み（FUN_007668f0・FUN_007674b0・FUN_007697b0・
     * FUN_0075d660・FUN_00417640）、原典では押していない。平行な二本
     * A=(0,0)-(100,0)・B=(0,100)-(100,100)（短い B は (0,100)-(50,100)）。 */
    {
        const jw_view *v;
        int g, j, okk, sh, nb;

        app_new();
        d = (jw_drawing *)app_drawing();
#define MK2(x1) do { jw_obj *o2 = jw_add(d, JW_SEN); \
        o2->d[0] = 0; o2->d[1] = 0; o2->d[2] = 100; o2->d[3] = 0; \
        o2 = jw_add(d, JW_SEN); \
        o2->d[0] = 0; o2->d[1] = 100; o2->d[2] = (x1); o2->d[3] = 100; } while (0)
        MK2(100.0);
        app_fit();
        v = app_view();
        jw_cmd_set(JW_CMD_BUNKATSU);
        {
            static const struct { const char *n, *after; int cnt; double y[3]; const char *what; } N[] = {
                { "-4.5", "-4.5", 3, { 100.0 / 3, 100.0 * (1 + 5.0 / 6) / 3, 100.0 * 2.5 / 3 },
                  "分割数 -4.5: r=0.5 で間隔が 1・5/6・4/6・3/6（全長 3）" },
                { "-1", "-2.01", 1, { 100.0 / 1.01, 0, 0 },
                  "分割数 -1 は -2.01 に直して書き戻し、r=0.01（全長 1.01）" },
                { "-3", "-3", 2, { 100.0 / 3, 200.0 / 3, 0 },
                  "分割数 -3: 端数が無ければ r=1 で等分" },
            };
            int f;

            for (f = 0; f < (int)(sizeof N / sizeof N[0]); f++) {
                g = d->ndrawn;
                type_box(1411, N[f].n);
                jw_cmd_point(d, v, 50, 0, 0);
                jw_cmd_point(d, v, 50, 100, 0);
                okk = d->ndrawn == g + N[f].cnt && jw_cmd_box(1411)
                      && !strcmp(jw_cmd_box(1411), N[f].after);
                for (j = 0; okk && j < N[f].cnt; j++)
                    okk = fabs(d->obj[g + j].d[1] - N[f].y[j]) < 1e-6
                          && fabs(d->obj[g + j].d[3] - N[f].y[j]) < 1e-6;
                ck(okk, N[f].what);
                while (d->ndrawn > g && jw_cmd_can_undo())
                    jw_cmd_undo(d);
            }
        }

        /* 等比: .jwf の S_COMM_7 の 8 番目が 1 なら（FUN_007674b0 の DAT_00a0bfa8）
           r=0.5 の -4.5 は 間隔 1・0.5・0.25・0.125、全長 (1-0.5^4)/0.5 = 1.875。
           端数の無い -3（r=1）は 0.01〜0.99 を外れるので等分のまま */
        {
            static const char on[] = "S_COMM_7 =     0    0    0   50  100   20    1    1    1 \r\n";
            static const char off[] = "S_COMM_7 =     0    0    0   50  100   20    1    0    1 \r\n";
            static const double yg[3] = { 100.0 / 1.875, 150.0 / 1.875, 175.0 / 1.875 };

            jw_env_read(d, (const unsigned char *)on, (long)strlen(on));
            g = d->ndrawn;
            type_box(1411, "-4.5");
            jw_cmd_point(d, v, 50, 0, 0);
            jw_cmd_point(d, v, 50, 100, 0);
            okk = d->ndrawn == g + 3;
            for (j = 0; okk && j < 3; j++)
                okk = fabs(d->obj[g + j].d[1] - yg[j]) < 1e-6
                      && fabs(d->obj[g + j].d[3] - yg[j]) < 1e-6;
            ck(okk, "等比（S_COMM_7 の 8 番目 1）: -4.5 は 間隔 1・1/2・1/4・1/8");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);
            type_box(1411, "-3");
            jw_cmd_point(d, v, 50, 0, 0);
            jw_cmd_point(d, v, 50, 100, 0);
            okk = d->ndrawn == g + 2 && fabs(d->obj[g].d[1] - 100.0 / 3) < 1e-6
                  && fabs(d->obj[g + 1].d[1] - 200.0 / 3) < 1e-6;
            ck(okk, "等比でも r=1（-3）は等分");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);
            jw_env_read(d, (const unsigned char *)off, (long)strlen(off));
            type_box(1411, "-4.5");
            jw_cmd_point(d, v, 50, 0, 0);
            jw_cmd_point(d, v, 50, 100, 0);
            okk = d->ndrawn == g + 3 && fabs(d->obj[g].d[1] - 100.0 / 3) < 1e-6;
            ck(okk, "8 番目 0 に戻すと等差");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);
        }

        /* 補助設定の釦: 線（Ａ）を指すまでは出ない */
        type_box(1411, "3");
        sh = jw_cmd_bunkatsu_hojo();
        jw_cmd_point(d, v, 50, 0, 0);
        {
            int id, kind, x, y, w, h;

            nb = 0;
            for (j = 0; ui_bar_item(j, &id, &kind, &x, &y, &w, &h); j++)
                if (id == 1064 || id == 1065 || id == 1066)
                    nb++;
        }
        ck(!sh && jw_cmd_bunkatsu_hojo() && nb == 3
           && jw_cmd_bar_enabled(d, 1066) && jw_cmd_bar_enabled(d, 1064)
           && jw_cmd_bar_enabled(d, 1065),
           "線（Ａ）のあとバーに 逆分割・線長割合分割・馬目地分割");
        g = d->ndrawn;
        ck(jw_cmd_bar(d, 1066), "逆分割 の釦が効く");
        jw_cmd_point(d, v, 50, 100, 0);
        okk = d->ndrawn == g + 2;
        for (j = 0; okk && j < 2; j++) {
            double t = (j + 1) / 3.0, lo = 100.0 * t, hi = 100.0 - lo;
            double x0 = d->obj[g + j].d[0], x1 = d->obj[g + j].d[2];

            okk = fabs(d->obj[g + j].d[1] - lo) < 1e-6 && fabs(d->obj[g + j].d[3] - lo) < 1e-6
                  && fabs((x0 < x1 ? x0 : x1) - (lo < hi ? lo : hi)) < 1e-6
                  && fabs((x0 < x1 ? x1 : x0) - (lo < hi ? hi : lo)) < 1e-6;
        }
        ck(okk && !jw_cmd_bunkatsu_hojo(),
           "逆分割: Ｂの端を入れ替えて交差に組む（A0→B1）、分割のあと旗は戻る");
        while (d->ndrawn > g && jw_cmd_can_undo())
            jw_cmd_undo(d);

        /* 馬目地分割（FUN_00763d20・FUN_00767990）: 縦分割数 3・分割数 4.5（箱は 4 に
           書き戻す）。縦の線は x = 100/3・200/3 の二本、横の目地は y = 25・75 で
           中の一つ、y = 50 で左右の二つ（逆分割を入れると互い違いが逆） */
        {
            static const double W[2][7][4] = {
                { { 100.0 / 3, 0, 100.0 / 3, 100 }, { 200.0 / 3, 0, 200.0 / 3, 100 },
                  { 100.0 / 3, 25, 200.0 / 3, 25 }, { 0, 50, 100.0 / 3, 50 },
                  { 200.0 / 3, 50, 100, 50 }, { 100.0 / 3, 75, 200.0 / 3, 75 } },
                { { 100.0 / 3, 0, 100.0 / 3, 100 }, { 200.0 / 3, 0, 200.0 / 3, 100 },
                  { 0, 25, 100.0 / 3, 25 }, { 200.0 / 3, 25, 100, 25 },
                  { 100.0 / 3, 50, 200.0 / 3, 50 }, { 0, 75, 100.0 / 3, 75 },
                  { 200.0 / 3, 75, 100, 75 } },
            };
            static const int WN[2] = { 6, 7 };
            int gy, um;

            for (gy = 0; gy < 2; gy++) {
                jw_cmd_set(JW_CMD_BUNKATSU);
                type_box(1411, "4.5");
                g = d->ndrawn;
                jw_cmd_point(d, v, 50, 0, 0);
                if (gy)
                    jw_cmd_bar(d, 1066);
                um = -1;
                okk = jw_cmd_bar(d, 1065) && jw_cmd_bunkatsu_umeji_ask(&um)
                      && !jw_cmd_bunkatsu_umeji_ask(&um) && !jw_cmd_bunkatsu_umeji();
                jw_cmd_bunkatsu_umeji_set("3");
                okk = okk && jw_cmd_bunkatsu_umeji();
                jw_cmd_point(d, v, 50, 100, 0);
                okk = okk && d->ndrawn == g + WN[gy] && jw_cmd_box(1411)
                      && !strcmp(jw_cmd_box(1411), "4") && !jw_cmd_bunkatsu_umeji();
                for (j = 0; okk && j < WN[gy]; j++) {
                    int q, hit = 0;

                    for (q = 0; q < WN[gy] && !hit; q++) {
                        const double *o4 = d->obj[g + q].d, *w4 = W[gy][j];

                        hit = (fabs(o4[0] - w4[0]) < 1e-6 && fabs(o4[1] - w4[1]) < 1e-6
                               && fabs(o4[2] - w4[2]) < 1e-6 && fabs(o4[3] - w4[3]) < 1e-6)
                           || (fabs(o4[0] - w4[2]) < 1e-6 && fabs(o4[1] - w4[3]) < 1e-6
                               && fabs(o4[2] - w4[0]) < 1e-6 && fabs(o4[3] - w4[1]) < 1e-6);
                    }
                    okk = hit;
                }
                if (!okk)
                    for (j = 0; j < d->ndrawn - g; j++)
                        printf("     %g,%g - %g,%g\n", d->obj[g + j].d[0], d->obj[g + j].d[1],
                               d->obj[g + j].d[2], d->obj[g + j].d[3]);
                ck(okk, gy ? "馬目地分割＋逆分割: 横の目地の互い違いが逆"
                           : "馬目地分割 縦 3・分割数 4.5: 縦の線 2 本と互い違いの横の目地 4 本、箱は 4");
                while (d->ndrawn > g && jw_cmd_can_undo())
                    jw_cmd_undo(d);
            }
            /* 縦 2000 × 分割数 60 は 100000 を超える: 5613 で何も作らない。
               線長割合 (1064) は 馬目地を切る */
            jw_cmd_set(JW_CMD_BUNKATSU);
            type_box(1411, "60");
            g = d->ndrawn;
            jw_cmd_point(d, v, 50, 0, 0);
            jw_cmd_bar(d, 1065);
            jw_cmd_bunkatsu_umeji_set("5000");
            jw_cmd_bar(d, 1064);
            okk = !jw_cmd_bunkatsu_umeji();
            jw_cmd_bar(d, 1064);
            jw_cmd_bar(d, 1065);
            jw_cmd_bunkatsu_umeji_ask(&um);
            okk = okk && um == 2000;
            jw_cmd_bunkatsu_umeji_set(0);       /* キャンセル: 入らない */
            okk = okk && !jw_cmd_bunkatsu_umeji();
            jw_cmd_bar(d, 1065);
            jw_cmd_bunkatsu_umeji_set("9999");
            jw_cmd_point(d, v, 50, 100, 0);
            ck(okk && d->ndrawn == g && jw_cmd_notice_id() == 5613,
               "馬目地: 縦分割数は 2〜2000、線長割合で切れる、キャンセルは入らない、縦×分割数が 100000 超は 5613");
            while (d->ndrawn > g && jw_cmd_can_undo())
                jw_cmd_undo(d);

            /* 表側: 1065 で 数値入力 275 が出て、札 1995 は 5610、箱 1491 は いまの
               縦分割数（上で 2000）。Esc は入れず、Enter は入れる */
            {
                int t = ui_tdlg_find(275), i1995 = ui_tdlg_index(t, 1995);
                int i1491 = ui_tdlg_index(t, 1491);

                jw_cmd_set(JW_CMD_BUNKATSU);
                type_box(1411, "4");
                jw_cmd_point(d, v, 50, 0, 0);
                jw_cmd_bar(d, 1065);
                app_paint();
                okk = app_tdlg_open() >= 0 && app_tdlg_tpl() == 275
                      && !strcmp(app_tdlg_text(i1995), JW_STR_5610)
                      && !strcmp(app_tdlg_text(i1491), "2000");
                app_key(27);
                okk = okk && app_tdlg_open() < 0 && !jw_cmd_bunkatsu_umeji();
                jw_cmd_bar(d, 1065);
                app_paint();
                app_key(13);
                okk = okk && app_tdlg_open() < 0 && jw_cmd_bunkatsu_umeji();
                ck(okk, "馬目地分割の窓（275）: 札 5610・箱に縦分割数、Esc は切のまま、Enter で入る");
                jw_cmd_set(JW_CMD_BUNKATSU);
            }
        }

        /* 線長割合分割: 短い方を先に指しても 長い A から短い B へ、割合 0.5 */
        app_new();
        d = (jw_drawing *)app_drawing();
        MK2(50.0);
        app_fit();
        v = app_view();
        jw_cmd_set(JW_CMD_BUNKATSU);
        type_box(1411, "4");
        g = d->ndrawn;
        jw_cmd_point(d, v, 25, 100, 0);
        jw_cmd_bar(d, 1064);
        jw_cmd_point(d, v, 50, 0, 0);
        {
            static const double Y[3] = { 100.0 / 3, 100.0 * (1 + 5.0 / 6) / 3, 100.0 * 2.5 / 3 };

            okk = d->ndrawn == g + 3 && jw_cmd_box(1411)
                  && !strcmp(jw_cmd_box(1411), "-4.5");
            for (j = 0; okk && j < 3; j++)
                okk = fabs(d->obj[g + j].d[1] - Y[j]) < 1e-6
                      && fabs(d->obj[g + j].d[3] - Y[j]) < 1e-6;
            ck(okk, "線長割合分割 n=4・長さ 100 と 50: 箱は -4.5、間隔 1 から 0.5 へ");
        }
#undef MK2
    }

    /* 楕円（扁平 0.5・傾き 30°・半径 50、中心 (0,0)）の２点間分割・円全周分割。
     * 逆コンパイルの読み（FUN_00762870・FUN_0045c760・FUN_0045cb90・FUN_0045af50、
     * 等角度は FUN_00761c60）、原典では押していない。答えは ここで別に積分した
     * 弧長で見る: 等距離なら点が弧長を等分し、等角度なら中心からの向きが等分 */
    {
        const jw_view *v;
        const double T = 30.0 * M_PI / 180.0, R = 50.0, F = 0.5;
        double ang[8];
        int g, j, okk;

        app_new();
        d = (jw_drawing *)app_drawing();
        {
            jw_obj *e = jw_add(d, JW_ENKO), *t;
            static const double pa[2] = { 0.0, M_PI / 2 };   /* P1・P2 の媒介変数の角 */

            e->d[0] = 0; e->d[1] = 0; e->d[2] = R; e->d[3] = 0;
            e->d[4] = 2 * M_PI; e->d[5] = T; e->d[6] = F; e->n = 1;
            for (j = 0; j < 2; j++) {
                double lx = R * cos(pa[j]), ly = R * F * sin(pa[j]);

                t = jw_add(d, JW_TEN);
                t->d[0] = cos(T) * lx - sin(T) * ly;
                t->d[1] = sin(T) * lx + cos(T) * ly;
            }
            /* 円全周の始点 P（楕円の外、中心から 媒介変数の角 0 の向き） */
            t = jw_add(d, JW_TEN);
            t->d[0] = cos(T) * 80.0;
            t->d[1] = sin(T) * 80.0;
        }
        app_fit();
        v = app_view();
#define EPT(i, a) do { double lx_ = R * cos(a), ly_ = R * F * sin(a); \
        (void)i; ex = cos(T) * lx_ - sin(T) * ly_; ey = sin(T) * lx_ + cos(T) * ly_; } while (0)
        {
            double ex, ey;
            /* 点 k の 局所の角（媒介変数）と 局所の向き（真の角） */
#define LOC(k, par, tru) do { double x_ = d->obj[k].d[0], y_ = d->obj[k].d[1]; \
            double lx_ = cos(T) * x_ + sin(T) * y_, ly_ = cos(T) * y_ - sin(T) * x_; \
            (tru) = atan2(ly_, lx_); (par) = atan2(ly_ / F, lx_); \
            okk = okk && fabs(lx_ * lx_ / (R * R) + ly_ * ly_ / (R * R * F * F) - 1) < 1e-6; } while (0)
            struct { const char *what; double qa; int whole, kaku, n, cnt; double want[3]; } C[] = {
                /* 媒介変数 0→90°、指示は 45°: 弧長を 4 等分 */
                { "楕円の２点間分割: 指示した側（短い弧）の弧長を等分", M_PI / 4, 0, 0, 4, 3, { 0 } },
                /* 指示が 180°: 0→90° を 時計回りに 270° */
                { "楕円の２点間分割: 指示した側の長い弧（時計回り）を等分", M_PI, 0, 0, 4, 3, { 0 } },
                /* 全周: 中心→P と 中心→指示点（200°）の外積が負 → 時計回り。
                   半周の弧長は 媒介変数で -180° */
                { "楕円の円全周分割: 弧長を等分（二つ目が 180°）", 200 * M_PI / 180, 1, 0, 4, 3, { 0 } },
                /* 等角度: 中心からの向きが 30°・60° */
                { "楕円の２点間分割 等角度: 中心からの向きを等分", M_PI / 4, 0, 1, 3, 2, { 0 } },
            };
            int f;

            for (f = 0; f < 4; f++) {
                char nb[8];

                g = d->ndrawn;
                jw_cmd_set(JW_CMD_BUNKATSU);
                if (C[f].kaku)
                    jw_cmd_bar(d, 1690);
                snprintf(nb, sizeof nb, "%d", C[f].n);
                type_box(1411, nb);
                if (C[f].whole) {
                    jw_cmd_point(d, v, d->obj[3].d[0], d->obj[3].d[1], 1);
                    EPT(0, C[f].qa);
                    jw_cmd_point(d, v, ex, ey, 1);
                } else {
                    jw_cmd_point(d, v, d->obj[1].d[0], d->obj[1].d[1], 1);
                    jw_cmd_point(d, v, d->obj[2].d[0], d->obj[2].d[1], 1);
                    EPT(0, C[f].qa);
                    jw_cmd_point(d, v, ex, ey, 0);
                }
                okk = d->ndrawn == g + C[f].cnt;
                for (j = 0; okk && j < C[f].cnt; j++) {
                    double par, tru;

                    LOC(g + j, par, tru);
                    ang[j] = C[f].kaku ? tru : par;
                }
                if (okk && C[f].kaku) {
                    okk = fabs(ang[0] - M_PI / 6) < 1e-6 && fabs(ang[1] - M_PI / 3) < 1e-6;
                } else if (okk) {
                    /* 媒介変数の角の並び a0..a4 の 区間ごとの弧長（Simpson、細かく） */
                    double a[5], seg[4], sw;
                    int s2, m = 20000;

                    a[0] = 0.0;
                    sw = f == 0 ? M_PI / 2 : f == 1 ? -3 * M_PI / 2 : -2 * M_PI;
                    for (j = 0; j < 3; j++) {
                        double x = ang[j];

                        if (sw > 0) while (x < a[j] - 1e-9) x += 2 * M_PI;
                        else while (x > a[j] + 1e-9) x -= 2 * M_PI;
                        a[j + 1] = x;
                    }
                    a[4] = sw;
                    for (j = 0; j < 4; j++) {
                        double h = (a[j + 1] - a[j]) / m, sum = 0;

                        for (s2 = 0; s2 <= m; s2++) {
                            double t = a[j] + h * s2;
                            double sp = R * sqrt(sin(t) * sin(t) + F * F * cos(t) * cos(t));

                            sum += sp * (s2 == 0 || s2 == m ? 1 : s2 % 2 ? 4 : 2);
                        }
                        seg[j] = fabs(sum * h / 3);
                    }
                    for (j = 1; j < 4; j++)
                        okk = okk && fabs(seg[j] - seg[0]) < 1e-3;
                    if (f == 2)
                        okk = okk && fabs(a[2] + M_PI) < 1e-4;
                    if (!okk)
                        printf("     弧長 %g %g %g %g\n", seg[0], seg[1], seg[2], seg[3]);
                }
                ck(okk, C[f].what);
                while (d->ndrawn > g && jw_cmd_can_undo())
                    jw_cmd_undo(d);
                if (C[f].kaku)
                    jw_cmd_bar(d, 1689);
            }
#undef LOC
        }
#undef EPT
    }

    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
