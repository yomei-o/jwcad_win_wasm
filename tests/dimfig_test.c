/* 寸法設定 の 寸法図形（2424）: ふつうの寸法を 寸法図形（CDataSunpou）一つに。
 *
 *   tests/dimfig_test.exe
 *
 * 根拠は逆コンパイルの読み（src/cmd.c の sun_fig_close の注）と原典の答え
 * decomp/res/p169_dimfig.jww（寸法図形化 したもの、tools/probe169.sh）:
 *
 *   FUN_00783730  bda0 なら 寸法線を足さず CDataSunpou の +0x68 に写し、
 *                 値の段で 字を +0xd0 に書いて 図形一つとして足す。
 *                 点・引出線 は ふつうに その前。部品 3〜8 は ctor のまま
 *   p169          部品 3〜8 は 線種 1・線色 2・座標 0、頭は 1・2・0x2000
 *
 * 2424 で作った図形を原典に描かせた答えは無い（寸法図形化 の答えと形を照らす）。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static int near(double a, double b)
{
    return fabs(a - b) < 1e-6;
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

/* (100,100)-(200,100) の線の両端を測る ふつうの寸法 */
static void line_dim(jw_drawing *d)
{
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_point(d, app_view(), 100.0, 120.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 110.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 200.0, 100.0, 0);
    jw_cmd_set(0);
}

/* 図面の中の 寸法図形 の頭（部品 1）。無ければ -1 */
static int find_fig(const jw_drawing *d, int from)
{
    int k;

    for (k = from; k + 7 < d->ndrawn; k++)
        if (d->obj[k].sub == 1 && d->obj[k + 7].sub == 8)
            return k;
    return -1;
}

static const unsigned char CLS[8] = {
    JW_SEN, JW_MOJI, JW_SEN, JW_SEN, JW_TEN, JW_TEN, JW_TEN, JW_TEN
};

int main(void)
{
    unsigned char *b, *w = 0;
    long n, wn = 0;
    jw_drawing *d, rd, ans;
    jw_obj *ln;
    int b0, b1, n0, n1, k, f, fa, i, depth;
    char txt0[64] = "";

    app_resize(1264, 741);
    b = slurp("decomp/res/new.jww", &n);    /* probe169 と同じ元 */
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open decomp/res/new.jww\n");
        return 1;
    }
    free(b);
    d = (jw_drawing *)app_drawing();
    ln = jw_add(d, JW_SEN);
    ln->d[0] = 100.0;
    ln->d[1] = 100.0;
    ln->d[2] = 200.0;
    ln->d[3] = 100.0;
    app_fit();

    /* ---- 切（既定）: これまでどおり、部品の印は無い */
    ck(jw_cmd_sunpo_chk(2424) == 0, "寸法図形 は 切 から");
    b0 = d->ndrawn;
    line_dim(d);
    n0 = d->ndrawn - b0;
    printf("     切: %d 要素\n", n0);
    ck(n0 == 6, "  寸法線・点二つ・引出線二本・値 の 6");
    ck(d->obj[b0].cls == JW_SEN && d->obj[b0 + 5].cls == JW_MOJI,
       "  寸法線が先、値が後");
    for (k = b0, i = 0; k < d->ndrawn; k++)
        i |= d->obj[k].sub;
    ck(i == 0, "  sub は 0");
    if (d->obj[b0 + 5].cls == JW_MOJI)
        snprintf(txt0, sizeof txt0, "%s", jw_str(d, d->obj[b0 + 5].text));

    /* ---- 入: 点・引出線 は ふつうに、その後に 部品 1〜8 */
    jw_cmd_sunpo_chk_set(2424, 1);
    ck(jw_cmd_sunpo_chk(2424) == 1, "寸法図形 を 入");
    b1 = d->ndrawn;
    depth = jw_cmd_undo_depth();
    line_dim(d);
    n1 = d->ndrawn - b1;
    printf("     入: %d 要素\n", n1);
    ck(n1 == 4 + 8, "  点二つ・引出線二本 と 部品八つ");
    ck(jw_cmd_undo_depth() == depth + 1, "  一つの 戻る");
    ck(d->obj[b1].cls == JW_TEN && d->obj[b1 + 1].cls == JW_TEN
       && d->obj[b1 + 2].cls == JW_SEN && d->obj[b1 + 3].cls == JW_SEN
       && !d->obj[b1].sub && !d->obj[b1 + 3].sub,
       "  前の四つは ふつうの 点・引出線（p169 と同じ並び）");
    f = find_fig(d, b1);
    ck(f == b1 + 4, "  部品 1〜8 が 一続き");
    if (f >= 0) {
        const jw_obj *p = &d->obj[f], *t = &d->obj[f + 1];
        for (k = 0, i = 1; k < 8; k++)
            i &= d->obj[f + k].cls == CLS[k] && d->obj[f + k].sub == k + 1;
        ck(i, "  部品の型は 線・字・線・線・点・点・点・点");
        ck(near(p->d[0], d->obj[b0].d[0]) && near(p->d[1], d->obj[b0].d[1])
           && near(p->d[2], d->obj[b0].d[2]) && near(p->d[3], d->obj[b0].d[3])
           && p->color == d->obj[b0].color && p->flags == d->obj[b0].flags,
           "  部品 1 は 切 のときの寸法線と同じ");
        ck(!strcmp(jw_str(d, t->text), txt0) && t->flags == d->obj[b0 + 5].flags
           && near(t->d[0], d->obj[b0 + 5].d[0]),
           "  部品 2 は 切 のときの値と同じ");
        for (k = 2, i = 1; k < 8; k++) {
            const jw_obj *q = &d->obj[f + k];
            i &= q->ltype == 1 && q->color == 2 && q->width == 0
                 && q->flags == 0 && q->d[0] == 0.0 && q->d[1] == 0.0
                 && q->d[2] == 0.0 && q->d[3] == 0.0;
        }
        ck(i, "  部品 3〜8 は 空（1・2・0、座標 0、旗 0）");
        ck(p->list[0] == 0 && (p->list[2] & 0xffff) == 0x2000
           && (p->mark & 0xffffff) == (1 | (2 << 8)),
           "  頭は +0x1c0 0・旗 0x2000・線種 1・線色 2");
    }

    /* ---- 保存して読み戻すと CDataSunpou 一つ、原典の答えと同じ形 */
    ck(jw_write(d, &w, &wn) && w, "保存できる");
    {
        long k2, hits = 0;
        for (k2 = 0; w && k2 + 11 <= wn; k2++)
            if (!memcmp(w + k2, "CDataSunpou", 11))
                hits++;
        ck(hits == 1, "  クラス名 CDataSunpou が書かれる");
    }
    memset(&rd, 0, sizeof rd);
    ck(w && jw_parse(&rd, w, wn), "  読み戻せる");
    fa = find_fig(&rd, 0);
    ck(fa >= 0 && find_fig(&rd, fa + 8) < 0, "  寸法図形は一つ");
    b = slurp("decomp/res/p169_dimfig.jww", &n);
    memset(&ans, 0, sizeof ans);
    ck(b && jw_parse(&ans, b, n), "原典の答え p169_dimfig.jww を読む");
    i = find_fig(&ans, 0);
    ck(i >= 0, "  答えにも寸法図形");
    if (fa >= 0 && i >= 0) {
        int same = 1;
        for (k = 0; k < 8; k++) {
            const jw_obj *p = &rd.obj[fa + k], *q = &ans.obj[i + k];
            int s = p->cls == q->cls && p->ltype == q->ltype
                    && p->color == q->color && p->layer == q->layer
                    && p->lgroup == q->lgroup && p->flags == q->flags;
            if (k == 1)
                s = p->cls == q->cls && p->flags == q->flags
                    && p->width == q->width;
            if (k >= 2)
                s = s && p->width == q->width && p->d[0] == q->d[0]
                    && p->d[1] == q->d[1] && p->d[2] == q->d[2]
                    && p->d[3] == q->d[3] && p->n == q->n;
            if (!s)
                printf("     部品 %d が違う: 移植 %d %d %d %#x / 答え %d %d %d %#x\n",
                       k + 1, p->ltype, p->color, p->width, p->flags,
                       q->ltype, q->color, q->width, q->flags);
            same &= s;
        }
        ck(same, "  部品 1〜8 の 型・線種・線色・レイヤ・旗（3〜8 は座標も）が答えと同じ");
        ck(rd.obj[fa].list[0] == ans.obj[i].list[0]
           && rd.obj[fa].list[1] == ans.obj[i].list[1]
           && rd.obj[fa].list[2] == ans.obj[i].list[2]
           && rd.obj[fa].mark == ans.obj[i].mark
           && rd.obj[fa].turn == ans.obj[i].turn,
           "  頭（CDataSunpou の CData の欄と +0x1c0）が答えと同じ");
        ck(ans.obj[i - 4].cls == JW_TEN && ans.obj[i - 3].cls == JW_TEN
           && ans.obj[i - 2].cls == JW_SEN && ans.obj[i - 1].cls == JW_SEN
           && ans.obj[i - 4].flags == rd.obj[fa - 4].flags
           && ans.obj[i - 2].flags == rd.obj[fa - 2].flags,
           "  図形の前の 点二つ・引出線二本 も答えと同じ並び・旗");
    }
    free(b);
    free(w);
    jw_free(&ans);
    jw_free(&rd);

    /* ---- 戻る で 八つとも消える */
    jw_cmd_undo(d);
    ck(d->ndrawn == b1, "戻る で 寸法図形ごと消える");

    jw_cmd_sunpo_chk_set(2424, 0);
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
