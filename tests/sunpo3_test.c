/* 寸法設定 の残り（2026-10-16）: 角度 の 度 表示と 2084、ｿﾘｯﾄﾞ、累進 の 基点円、
 * 角度を次回に継続。
 *
 *   tests/sunpo3_test.exe
 *
 * **逆コンパイルの読みで、原典では押していない。照らす原典の答えは無い**:
 *
 *   度 表示   FUN_00786fb0 の 0x787d98〜: DAT_00a0bd5c が 1 なら 度分秒
 *             （FUN_00459e40）、ほかは FUN_0045a220 に 2084（DAT_00a0bd9c）の
 *             桁、2 でなければ 字 6195「ﾟ」（全角 bd24 なら 6196「°」）を足す
 *   ｿﾘｯﾄﾞ    FUN_00473d00 の 0x474049〜: 矢印は 線二本でなく ソリッド一つ、
 *             四点は 先・+角・-角・-角（四点目 +0x78 は三点目 +0x68 の写し）
 *   基点円    FUN_00783730 の 0x785036〜: 累進 の基点は 点 でなく 半径 2082 の
 *             円（半径がほぼ 0 なら何も置かない）
 *   継続      FUN_005da080（バーの OnInitDialog）が 傾き を 0 にし、
 *             FUN_00779bd0 が DAT_00a0bd88 なら前の 傾き を戻す
 *
 * 末尾の「累進の揃え」だけは例外で、**原典 10.03.6 で実機測定**した
 * （2026-10-19、tools/jwdraw.ps1）。答えは decomp/res/sun3_rui.jww・
 * sun3_ruineg.jww。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/gen/sunpo.h"

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

static int count(const jw_drawing *d, int b0, int cls)
{
    int k, m = 0;

    for (k = b0; k < d->ndrawn; k++)
        if (d->obj[k].cls == cls)
            m++;
    return m;
}

static const jw_obj *first(const jw_drawing *d, int b0, int cls)
{
    int k;

    for (k = b0; k < d->ndrawn; k++)
        if (d->obj[k].cls == cls)
            return &d->obj[k];
    return 0;
}

/* 原点 (100,100) から 0° と a° の二方向の 角度 寸法。値の字を返す */
static const char *angle_dim(jw_drawing *d, double a, int *b0)
{
    double r = a * 3.14159265358979323846 / 180.0;
    const jw_obj *t;
    jw_obj *ln = jw_add(d, JW_SEN);     /* 二つ目の向きは読む点 */

    ln->d[0] = 100.0;
    ln->d[1] = 100.0;
    ln->d[2] = 100.0 + 50.0 * cos(r);
    ln->d[3] = 100.0 + 50.0 * sin(r);
    *b0 = d->ndrawn;
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_bar(d, 1068);
    jw_cmd_point(d, app_view(), 100.0, 100.0, 1);
    jw_cmd_point(d, app_view(), 110.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 130.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 200.0, 100.0, 1);
    jw_cmd_point(d, app_view(), ln->d[2], ln->d[3], 1);
    t = first(d, *b0, JW_MOJI);
    jw_cmd_bar(d, 1064);                /* リセット（角度 は命令を出ても残る） */
    jw_cmd_set(0);
    return t ? jw_str(d, t->text) : "";
}

/* x = 100 の縦の線（引出線）の y の小さいほう・大きいほう */
static int hiki100(const jw_drawing *d, int b0, double *lo, double *hi)
{
    int k;

    for (k = b0; k < d->ndrawn; k++) {
        const jw_obj *o = &d->obj[k];
        if (o->cls == JW_SEN && near(o->d[0], 100.0) && near(o->d[2], 100.0)
            && !near(o->d[1], o->d[3])) {
            *lo = o->d[1] < o->d[3] ? o->d[1] : o->d[3];
            *hi = o->d[1] < o->d[3] ? o->d[3] : o->d[1];
            return 1;
        }
    }
    return 0;
}

/* (100,100)-(200,100) の線の両端を測る ふつうの寸法 */
static void line_dim(jw_drawing *d)
{
    jw_cmd_point(d, app_view(), 100.0, 120.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 110.0, 0);
    jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
    jw_cmd_point(d, app_view(), 200.0, 100.0, 0);
}

int main(void)
{
    unsigned char *b;
    long n;
    jw_drawing *d;
    jw_obj *ln;
    const jw_obj *o;
    const char *s;
    int b0, k, ok;
    char want[64];
    size_t l;

    app_resize(1264, 741);
    b = slurp("orig/Test5.jww", &n);
    if (!b || !app_open(b, n)) {
        printf("BAD  cannot open orig/Test5.jww\n");
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

    /* ---- 角度: 既定は 度分秒 */
    ck(jw_cmd_sunpo_chk(1727) == 1, "角度単位は 度分秒 から");
    s = angle_dim(d, 90.0, &b0);
    printf("     port [%s]\n", s);
    l = strlen(s);
    ck(l > 0 && s[l - 1] == '"', "  度分秒 は \" で終わる（これまでどおり）");

    /* ---- 度: 2084 の 4 桁、0表示 無 で末尾の 0 は落ちる */
    jw_cmd_sunpo_chk_set(1726, 1);
    ck(jw_cmd_sunpo_chk(1726) == 1 && jw_cmd_sunpo_chk(1727) == 0, "度 を選ぶ");
    s = angle_dim(d, 90.0, &b0);
    printf("     port [%s]\n", s);
    ck(!strcmp(s, "90\xdf"), "  90 度は「90ﾟ」（字 6195）");
    s = angle_dim(d, 100.0 / 3.0, &b0);
    printf("     port [%s]\n", s);
    ck(!strcmp(s, "33.3333\xdf"), "  33.333.. 度は 2084 の 4 桁で「33.3333ﾟ」");
    /* 2084 は原典の窓でも押せない箱（DDX だけで EnableWindow は無い）。
       桁は .jwf／レジストリの DEGKETA の 4 のまま */
    s = angle_dim(d, 200.0 / 3.0, &b0);
    printf("     port [%s]\n", s);
    ck(!strcmp(s, "66.6667\xdf"), "  四捨五入: 66.66.. 度は「66.6667ﾟ」");
    jw_cmd_sunpo_chk_set(2490, 1);      /* 切捨 */
    s = angle_dim(d, 200.0 / 3.0, &b0);
    printf("     port [%s]\n", s);
    ck(!strcmp(s, "66.6666\xdf"), "  切捨 も効く（「66.6666ﾟ」）");
    jw_cmd_sunpo_chk_set(2489, 1);
    jw_cmd_sunpo_chk_set(1801, 1);      /* 全角文字 */
    s = angle_dim(d, 90.0, &b0);
    printf("     port [%s]\n", s);
    ck(!strcmp(s, "\x82\x58\x82\x4f\x81\x8b"), "  全角文字 なら「９０°」（字 6196）");
    jw_cmd_sunpo_chk_set(1801, 0);
    jw_cmd_sunpo_chk_set(1727, 1);

    /* ---- ｿﾘｯﾄﾞ: 矢印は ソリッド一つずつ */
    jw_cmd_set(JW_CMD_SUNPO);
    while (jw_cmd_sunpo_arrows() != 1)
        jw_cmd_bar(d, 1062);
    b0 = d->ndrawn;
    line_dim(d);
    ck(count(d, b0, JW_SOLID) == 0, "ｿﾘｯﾄﾞ 無し: ソリッドは無い");
    k = count(d, b0, JW_SEN);
    jw_cmd_sunpo_chk_set(2842, 1);
    b0 = d->ndrawn;
    line_dim(d);
    ck(count(d, b0, JW_SOLID) == 2, "ｿﾘｯﾄﾞ 有り: 矢印はソリッド二つ");
    ck(count(d, b0, JW_SEN) == k - 4, "  矢印の線四本が無くなる");
    o = first(d, b0, JW_SOLID);
    ok = o && near(o->d[4], o->d[6]) && near(o->d[5], o->d[7])
         && !(near(o->d[2], o->d[4]) && near(o->d[3], o->d[5]))
         && (o->flags & 0x2000u) && o->ltype == 1;
    ck(ok, "  四点目は三点目と同じ（三角）、+0x44 に 0x2000");
    ck(o && near(o->d[0], 100.0) && near(o->d[1], 110.0), "  一点目は寸法線の端（先）");
    if (o)
        printf("     (%g,%g) (%g,%g) (%g,%g) (%g,%g)\n", o->d[0], o->d[1],
               o->d[2], o->d[3], o->d[4], o->d[5], o->d[6], o->d[7]);
    jw_cmd_sunpo_chk_set(2842, 0);
    while (jw_cmd_sunpo_arrows() != 0)
        jw_cmd_bar(d, 1062);
    jw_cmd_set(0);

    /* ---- 累進 の 基点円 */
    jw_cmd_set(JW_CMD_SUNPO);
    jw_cmd_bar(d, 1070);
    b0 = d->ndrawn;
    line_dim(d);
    ck(count(d, b0, JW_TEN) == 1 && count(d, b0, JW_ENKO) == 0, "累進: 基点は 点");
    jw_cmd_sunpo_chk_set(2417, 1);
    b0 = d->ndrawn;
    line_dim(d);
    o = first(d, b0, JW_ENKO);
    ck(count(d, b0, JW_TEN) == 0 && o, "基点円: 点 の代わりに 円");
    ck(o && near(o->d[2], 0.75) && o->n == 1 && near(o->d[4], 2.0 * 3.14159265358979323846)
       && near(o->d[6], 1.0), "  半径は 2082 の 0.75、まるい円");
    ck(o && near(o->d[0], 100.0) && near(o->d[1], 110.0), "  中心は寸法線の基点の端");
    /* 半径がほぼ 0 なら何も置かない読みだが、窓の OK は 2082 を 0.1 より
       下にさせない（FUN_005d34b0）ので試せない */
    jw_cmd_sunpo_box_set(2082, "2");
    b0 = d->ndrawn;
    line_dim(d);
    o = first(d, b0, JW_ENKO);
    ck(o && near(o->d[2], 2.0), "  2082 を 2 にすれば半径 2");
    jw_cmd_sunpo_box_set(2082, "0.75");
    jw_cmd_sunpo_chk_set(2417, 0);
    jw_cmd_bar(d, 1070);
    jw_cmd_set(0);

    /* ---- ふつうの寸法の 突出寸法 は 引出線の端と反対の側へ */
    {
        double lo = 0, hi = 0;

        jw_cmd_sunpo_box_set(1479, "2");
        jw_cmd_set(JW_CMD_SUNPO);
        b0 = d->ndrawn;
        line_dim(d);                    /* 端 120 は寸法線 110 の上 */
        ck(hiki100(d, b0, &lo, &hi) && near(lo, 108.0) && near(hi, 120.0),
           "突出寸法: 端が寸法線の上なら 下へ 2（108..120）");
        printf("     %g..%g\n", lo, hi);
        jw_cmd_set(0);
        jw_cmd_set(JW_CMD_SUNPO);
        b0 = d->ndrawn;
        jw_cmd_point(d, app_view(), 100.0, 80.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 90.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
        jw_cmd_point(d, app_view(), 200.0, 100.0, 0);
        ck(hiki100(d, b0, &lo, &hi) && near(lo, 80.0) && near(hi, 92.0),
           "  端が寸法線の下なら 上へ 2（80..92、probe147 の向き）");
        printf("     %g..%g\n", lo, hi);
        jw_cmd_sunpo_box_set(1479, "0");
        jw_cmd_set(0);
    }

    /* ---- 段 3 から先の 1060 は 引出角 */
    {
        static const double tab[1] = { 30.0 };
        double t30 = tan(30.0 * 3.14159265358979323846 / 180.0);
        char lab[32];
        const jw_obj *dl = 0;

        jw_cmd_set(JW_CMD_SUNPO);
        ck(!jw_cmd_sunpo_hikikaku(lab, sizeof lab), "引出角: 段 1・2 では ＝ の釦");
        jw_cmd_point(d, app_view(), 100.0, 120.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 110.0, 0);
        ck(jw_cmd_sunpo_hikikaku(lab, sizeof lab) && !strcmp(lab, "\x88\xf8\x8f\x6f\x8a\x70 0"),
           "  始点を訊く段では 名札「引出角 0」");
        ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_eq() == 0
           && jw_cmd_sunpo_hikikaku(lab, sizeof lab) && !strcmp(lab, "\x88\xf8\x8f\x6f\x8a\x70 0"),
           "  S_SET5 が無ければ 押しても 0 のまま、＝ も回らない");
        jw_cmd_sunpo_hikikaku_tab(tab, 1);
        ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_hikikaku(lab, sizeof lab)
           && !strcmp(lab, "30\xdf"), "  表 30 なら 名札「30ﾟ」");
        b0 = d->ndrawn;
        jw_cmd_point(d, app_view(), 100.0, 100.0, 0);
        jw_cmd_point(d, app_view(), 200.0, 100.0, 0);
        for (k = b0; k < d->ndrawn; k++)
            if (d->obj[k].cls == JW_SEN) {
                dl = &d->obj[k];
                break;
            }
        ck(dl && near(dl->d[0], 100.0 - 10.0 * t30) && near(dl->d[2], 200.0 - 10.0 * t30)
           && near(dl->d[1], 110.0), "  寸法線は -tan30·10 ずれる");
        ok = 0;
        for (k = b0; k < d->ndrawn; k++) {
            const jw_obj *e = &d->obj[k];
            if (e->cls == JW_SEN && near(e->d[2], 100.0) && near(e->d[3], 120.0)
                && near(e->d[0], 100.0 - 10.0 * t30) && near(e->d[1], 110.0))
                ok = 1;
        }
        ck(ok, "  引出線は 寸法線の端から 引出線の端 (100,120) へ 30° 傾く");
        ck(jw_cmd_bar(d, 1060) && jw_cmd_sunpo_hikikaku(lab, sizeof lab)
           && !strcmp(lab, "\x88\xf8\x8f\x6f\x8a\x70 0"), "  もう一度で 0 に戻る");
        jw_cmd_bar(d, 1060);
        jw_cmd_set(JW_CMD_SEN);
        jw_cmd_set(JW_CMD_SUNPO);
        jw_cmd_point(d, app_view(), 100.0, 120.0, 0);
        jw_cmd_point(d, app_view(), 100.0, 110.0, 0);
        ck(jw_cmd_sunpo_hikikaku(lab, sizeof lab) && !strcmp(lab, "\x88\xf8\x8f\x6f\x8a\x70 0"),
           "  別の命令から入り直せば 0（バーを作り直す）");
        jw_cmd_set(0);
    }

    /* ---- 角度を次回に継続 */
    jw_cmd_set(JW_CMD_SUNPO);
    type_box(1411, "30");
    ck(!strcmp(jw_cmd_box(1411), "30"), "傾き 30 を打つ");
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_set(JW_CMD_SUNPO);
    sprintf(want, "%s", jw_cmd_box(1411));
    ck(!strcmp(want, "0"), "  継続 無しなら 入り直すと 0");
    type_box(1411, "30");
    jw_cmd_set(JW_CMD_SUNPO);
    ck(!strcmp(jw_cmd_box(1411), "30"), "  寸法 のまま入り直しても残る");
    jw_cmd_sunpo_chk_set(2416, 1);
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_set(JW_CMD_SUNPO);
    ck(!strcmp(jw_cmd_box(1411), "30"), "  継続 有りなら 30 のまま");
    jw_cmd_sunpo_chk_set(2416, 0);
    type_box(1411, "0");
    jw_cmd_set(0);

    /* ---- 累進の揃え（原典実機で測った。2026-10-19、原典 10.03.6）:
       寸法線の位置を 測った線の上（隔たり tl-th = 0）に置くと、字は
       寸法線を挟んで 既定の反対側（下）に出て ltype=3。文字種類
       （箱 1488）に -1 を打つと 逆に 上に出て ltype=1、大きさも 文字種
       -1 の表（2.0）に変わる——どちらも 字の u 位置（寸法線の 現在
       打った側の端）は 同じまま。tools/jwdraw.ps1 で cmd:32771 の水平線・
       cmd:32847;btn:1070 の累進・寸法線の位置を その線の上で読んで、
       箱 1488 を 既定 2 のときと -1 のときで比べて測った（tmp/dbg2.jww・
       tmp/case3_mojineg_fwd.jww、答えは decomp/res/sun3_rui.jww・
       sun3_ruineg.jww）。隔たりを線の上・下・線上の三通りに変えても
       同じ式で揃った（tmp/case7・case8・case9、cmd.c sunpo_make の
       flip の式のコメント）。累進の継続を後ろ向きに打つ（終点の u 射影
       を始点より小さくする）ことは 原典がそもそも受け付けず
       （tmp/case4_dip・case5_dip2・case6_dip_negmoji.jww、ステータス行も
       図形も変わらない）ため、nokori.md の三因子目は今回も確かめられ
       ないまま。 */
    {
        jw_drawing rp, rn;
        const jw_obj *rpf[6], *rnf[6], *a;
        int mp = 0, mn = 0, mok;

        b = slurp("decomp/res/sun3_rui.jww", &n);
        ok = b && jw_parse(&rp, b, n);
        free(b);
        if (ok)
            for (k = 0; k < rp.ndrawn && mp < 6; k++)
                if (rp.obj[k].cls != JW_MOJI
                    || (rp.obj[k].flags & JW_SUN_TEXT_FLAGS))
                    rpf[mp++] = &rp.obj[k];
        ck(ok && mp == 6, "decomp/res/sun3_rui.jww が開ける（六つ）");
        b = slurp("decomp/res/sun3_ruineg.jww", &n);
        ok = ok && b && jw_parse(&rn, b, n);
        free(b);
        if (ok)
            for (k = 0; k < rn.ndrawn && mn < 6; k++)
                if (rn.obj[k].cls != JW_MOJI
                    || (rn.obj[k].flags & JW_SUN_TEXT_FLAGS))
                    rnf[mn++] = &rn.obj[k];
        ck(ok && mn == 6, "decomp/res/sun3_ruineg.jww が開ける（六つ）");
        if (ok && mp == 6 && mn == 6) {
            app_new();
            d = (jw_drawing *)app_drawing();
            /* 測った線そのもの（rpf[0]）を引いてから寸法に入る
               （dim_progressive と同じ手順） */
            jw_cmd_set(JW_CMD_TEN);
            jw_cmd_set(JW_CMD_SEN);
            if (jw_cmd_bar_check(1333) > 0)
                app_key(32);
            jw_cmd_point(d, app_view(), rpf[0]->d[0], rpf[0]->d[1], 0);
            jw_cmd_point(d, app_view(), rpf[0]->d[2], rpf[0]->d[3], 0);
            jw_cmd_set(JW_CMD_SUNPO);
            type_box(1411, "0");
            jw_cmd_bar(d, 1070);         /* 累進 */
            b0 = d->ndrawn;
            jw_cmd_point(d, app_view(), 0.0, rpf[0]->d[1], 0);  /* 引出線の端 */
            jw_cmd_point(d, app_view(), 0.0, rpf[0]->d[1], 0);  /* 寸法線の位置（線の上） */
            jw_cmd_point(d, app_view(), rpf[0]->d[0], rpf[0]->d[1], 1);
            jw_cmd_point(d, app_view(), rpf[0]->d[2], rpf[0]->d[3], 1);
            ck(d->ndrawn - b0 == 5, "文字種 既定: 寸法線・点・矢羽根二本・値");
            mok = d->ndrawn - b0 == 5;
            if (mok)
                for (k = 0; k < 5; k++) {
                    const jw_obj *want_o = rpf[1 + k];
                    int j, same;

                    a = &d->obj[b0 + k];
                    same = a->cls == want_o->cls && a->ltype == want_o->ltype;
                    for (j = 0; j < 4; j++)
                        if (!near(a->d[j], want_o->d[j]))
                            same = 0;
                    if (!same) {
                        mok = 0;
                        printf("     %d ours cls=%d t=%d %.4f,%.4f -> %.4f,%.4f\n"
                               "       sun3_rui's cls=%d t=%d %.4f,%.4f -> %.4f,%.4f\n",
                               k, a->cls, a->ltype, a->d[0], a->d[1], a->d[2], a->d[3],
                               want_o->cls, want_o->ltype, want_o->d[0], want_o->d[1],
                               want_o->d[2], want_o->d[3]);
                    }
                }
            ck(mok, "  sun3_rui.jww と同じ（既定は寸法線の下、ltype=3）");

            jw_cmd_sunpo_box_set(1488, "-1");
            jw_cmd_bar(d, 1070);        /* 累進 を切って 入れ直す（続きにしない） */
            jw_cmd_set(0);
            jw_cmd_set(JW_CMD_SUNPO);
            type_box(1411, "0");
            jw_cmd_bar(d, 1070);
            b0 = d->ndrawn;
            jw_cmd_point(d, app_view(), 0.0, rpf[0]->d[1], 0);
            jw_cmd_point(d, app_view(), 0.0, rpf[0]->d[1], 0);
            jw_cmd_point(d, app_view(), rpf[0]->d[0], rpf[0]->d[1], 1);
            jw_cmd_point(d, app_view(), rpf[0]->d[2], rpf[0]->d[3], 1);
            ck(d->ndrawn - b0 == 5, "文字種 -1: 寸法線・点・矢羽根二本・値");
            mok = d->ndrawn - b0 == 5;
            if (mok)
                for (k = 0; k < 5; k++) {
                    const jw_obj *want_o = rnf[1 + k];
                    int j, same;

                    a = &d->obj[b0 + k];
                    same = a->cls == want_o->cls && a->ltype == want_o->ltype;
                    for (j = 0; j < 4; j++)
                        if (!near(a->d[j], want_o->d[j]))
                            same = 0;
                    if (!same) {
                        mok = 0;
                        printf("     %d ours cls=%d t=%d %.4f,%.4f -> %.4f,%.4f\n"
                               "       sun3_ruineg's cls=%d t=%d %.4f,%.4f -> %.4f,%.4f\n",
                               k, a->cls, a->ltype, a->d[0], a->d[1], a->d[2], a->d[3],
                               want_o->cls, want_o->ltype, want_o->d[0], want_o->d[1],
                               want_o->d[2], want_o->d[3]);
                    }
                }
            ck(mok, "  sun3_ruineg.jww と同じ（文字種 -1 は寸法線の上、ltype=1）");
            if (mok) {
                const jw_obj *tp = rpf[5], *tn = rnf[5];

                ck(near(tn->d[4], 2.0) && near(tn->d[5], 2.0)
                   && near(tp->d[4], 2.5) && near(tp->d[5], 2.5),
                   "  文字種 -1 は大きさも変わる（表の違う行、2.0 対 2.5）");
            }
            jw_cmd_sunpo_box_set(1488, "2");
            jw_cmd_bar(d, 1070);
            jw_cmd_set(0);
        }
    }

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
