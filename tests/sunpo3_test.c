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

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
