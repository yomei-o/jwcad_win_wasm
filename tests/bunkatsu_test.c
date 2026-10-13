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
    const jw_obj *r[4];
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
        jw_obj *l1, *l2, *l3, *l4, *ca, *cb, *pt_top, *pt_right;
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

        MKSEN(l1, -155.51, 26.3265, -94.2857, 26.3265);
        MKSEN(l2, -155.51, -4.28571, -94.2857, -4.28571);
        MKSEN(l3, 28.1633, 26.3265, 89.3878, 26.3265);
        MKSEN(l4, -106.531, 56.9388, -106.531, -47.1429);
        MKENKO(ca, -33.0612, -96.1224, 36.7347);
        MKENKO(cb, 58.7755, -96.1224, 24.4898);
        pt_top = jw_add(d, JW_TEN);
        pt_top->d[0] = -33.0612; pt_top->d[1] = -59.3878; pt_top->n = 0;
        pt_right = jw_add(d, JW_TEN);
        pt_right->d[0] = 3.67347; pt_right->d[1] = -96.1224; pt_right->n = 0;

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
        jw_cmd_point(d, v, ca->d[0] - ca->d[2], ca->d[1], 0);   /* 円周の左端 */
        ck(d->ndrawn == g + 3
           && near3(d->obj[g].d[0], -19.0035) && near3(d->obj[g].d[1], -62.184)
           && near3(d->obj[g + 1].d[0], -7.08587) && near3(d->obj[g + 1].d[1], -70.1471)
           && near3(d->obj[g + 2].d[0], 0.877207) && near3(d->obj[g + 2].d[1], -82.0647),
           "始点＋第二点(R)(R)、円(L): 円の２点間分割（短いほうの弧を等分）");
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

#undef MKSEN
#undef MKENKO
    }

    jw_free(&ref);
    printf(fails ? "%d failed\n" : "all passed\n", fails);
    return fails != 0;
}
