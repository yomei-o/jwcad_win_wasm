/* The readout on the end of the status line, against the original's own.
 *
 *   tests/status_test.exe
 *
 * While a command is drawing, the original hangs the size of what is being
 * drawn off the end of the prompt.  Asked of it over decomp/res/new.jww,
 * which is a 1/100 sheet (tools/probe26.sh), these came back word for word:
 *
 *   nothing drawn   始点を指示してください  (L)free  (R)Read
 *   first point in  ◆　　終点を指示してください  (L)free  (R)Read   [ 0.000°]   0.000
 *   the line drawn  始点を指示してください  (L)free  (R)Read   [ -26.565°]   27,380.424
 *   a rectangle     始点を指示してください  (L)free  (R)Read     W=24,489.795    H=12,244.897
 *   a circle        中心点を指示してください  (L)free  (R)Read      r = 6,122.448
 *   after leaving   点位置を指示してください  (L)free  (R)Read
 *
 * So: the angle and the length of the line, the width and height of the
 * rectangle, the radius of the circle, all in real units to three places
 * with a comma every three digits; nothing at all before the command has
 * drawn anything; and leaving the command takes it away again.
 *
 * Two things are checked.  First that the recipe is the original's -- the
 * numbers are read back out of the strings above and put through it, and
 * what comes out has to be those strings to the byte, which pins every
 * space.  Then that the port says the same for what it draws.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../src/app.h"
#include "../src/cmd.h"
#include "../src/jww.h"
#include "../src/view.h"
#include "../src/ui.h"
#include "../src/gen/prompts.h"

#define PI 3.14159265358979323846

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static void cksame(const char *got, const char *want, const char *what)
{
    int ok = !strcmp(got, want);

    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok) {
        printf("     ours   [%s]\n", got);
        printf("     theirs [%s]\n", want);
        fails++;
    }
}

/* the recipe: a real-world length, three places, a comma every three */
static void num3(char *out, int n, double v)
{
    char buf[64];
    int i, len, whole, k = 0, neg = v < 0.0;

    if (neg)
        v = -v;
    snprintf(buf, sizeof buf, "%.3f", v);
    len = (int)strlen(buf);
    whole = (int)(strchr(buf, '.') ? strchr(buf, '.') - buf : len);
    if (neg && k < n - 1)
        out[k++] = '-';
    for (i = 0; i < len && k < n - 1; i++) {
        if (i && i < whole && (whole - i) % 3 == 0)
            out[k++] = ',';
        if (k < n - 1)
            out[k++] = buf[i];
    }
    out[k] = 0;
}

static void tail_line(char *out, int n, const char *prompt,
                      double deg, double real)
{
    char b[64];

    num3(b, (int)sizeof b, real);
    snprintf(out, (size_t)n, "%s   [ %.3f\x81\x8b]   %s", prompt, deg, b);
}

static void tail_box(char *out, int n, const char *prompt,
                     double w, double h)
{
    char a[64], b[64];

    num3(a, (int)sizeof a, w);
    num3(b, (int)sizeof b, h);
    snprintf(out, (size_t)n, "%s     W=%s    H=%s", prompt, a, b);
}

static void tail_circle(char *out, int n, const char *prompt, double r)
{
    char a[64];

    num3(a, (int)sizeof a, r);
    snprintf(out, (size_t)n, "%s      r = %s", prompt, a);
}

/* the prompts, in CP932, as the original's string table has them */
#define P_START "\x8en\x93_\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xc4\x82\xad" \
                "\x82\xbe\x82\xb3\x82\xa2  (L)free  (R)Read"
#define P_END   "\x81\x9f\x81\x40\x81\x40\x8fI\x93_\x82\xf0\x8ew\x8e\xa6" \
                "\x82\xb5\x82\xc4\x82\xad\x82\xbe\x82\xb3\x82\xa2" \
                "  (L)free  (R)Read"
#define P_CEN   "\x92\x86\x90S\x93_\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xc4" \
                "\x82\xad\x82\xbe\x82\xb3\x82\xa2  (L)free  (R)Read"
#define P_TEN   "\x93_\x88\xca\x92u\x82\xf0\x8ew\x8e\xa6\x82\xb5\x82\xc4" \
                "\x82\xad\x82\xbe\x82\xb3\x82\xa2  (L)free  (R)Read"

static void click(double x, double y)
{
    const jw_view *v = app_view();

    app_press(jw_sx(v, x), jw_sy(v, y), 0);
}

static double scale_of(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return d->group[wg].scale;
}

static const jw_obj *last_of(const jw_drawing *d, int cls)
{
    int i;

    for (i = d->ndrawn - 1; i >= 0; i--)
        if (d->obj[i].cls == cls)
            return &d->obj[i];
    return 0;
}

/* 命令ごとの案内文 ―― 原典のどの文字列が出るか。
 *
 * 移植は長いあいだ、持ち場を書いていない命令には線の
 * 「始点を指示してください」を出していた。原典の各クラスは自分の
 * 文字列を持っている（`decomp/byclass/CZukei*.c` の `FUN_004efbb0`
 * 呼び出しがその番号を渡している）。ここで押さえるのは逆コンパイル
 * から読めた四つ。 */
static void prompts_of_the_commands(void)
{
    const jw_drawing *d;
    int i;

    app_new();
    d = app_drawing();

    /* 拾うものを置く：横に二本の線と、離れたところに二つの円 */
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* Space: 水平・垂直 off */
    click(-100.0, 40.0);
    click(100.0, 40.0);
    click(-100.0, -40.0);
    click(100.0, -40.0);
    app_command(JW_CMD_ENKO);
    click(-60.0, 0.0);
    click(-40.0, 0.0);
    click(60.0, 0.0);
    click(90.0, 0.0);
    ck(d->ndrawn >= 4, "拾うための線二本と円二つが置けた");

    /* 分割: CZukeiBunkatsu の 0x14ed と 0x14ee */
    app_command(JW_CMD_BUNKATSU);
    cksame(jw_cmd_prompt(), JW_STR_5357, "分割は線・円（Ａ）指示から");
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5358, "  線を拾うと線【Ｂ】指示");

    /* 中心線: 0x14fc・0x14fd のあとは線と同じ対 */
    app_command(JW_CMD_CHUSHIN);
    cksame(jw_cmd_prompt(), JW_STR_5372, "中心線は１番目の線・円から");
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5373, "  次は２番目");
    click(0.0, -40.0);
    cksame(jw_cmd_prompt(), P_START, "  二つ揃うと線と同じ始点");
    click(-80.0, 0.0);
    cksame(jw_cmd_prompt(), P_END, "  そして終点");

    /* 接円: 0x14fc・0x14fd・0x14fe、半径が決まると 0x14ff */
    app_command(JW_CMD_SEKIEN);
    cksame(jw_cmd_prompt(), JW_STR_5372, "接円も１番目の線・円から");
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5373, "  次は２番目");
    click(0.0, -40.0);
    cksame(jw_cmd_prompt(), JW_STR_5374, "  半径が空なら３番目を訊く");
    jw_cmd_box_click(1411);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    jw_cmd_box_key('2');
    jw_cmd_box_key('0');
    jw_cmd_box_key(13);
    cksame(jw_cmd_prompt(), JW_STR_5375,
           "  半径を打つと置く場所を訊く");
    jw_cmd_box_click(1411);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    jw_cmd_box_key(13);

    /* 接線の円→円: 0x14f7 と 0x14f8 */
    app_command(JW_CMD_SESSEN);
    cksame(jw_cmd_prompt(), JW_STR_5367, "接線は円を指示から");
    click(-40.0, 0.0);
    cksame(jw_cmd_prompt(), JW_STR_5368, "  拾うと次の円を指示");

    /* 属性変更: 一つしかない */
    app_command(JW_CMD_ZOKUHEN);
    cksame(jw_cmd_prompt(), JW_STR_5487, "属性変更は変更するデータを指示");
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5487, "  一つ拾っても同じ");

    /* ハッチ: 輪を拾う間は 0x1501 、一つ入ると 0x1502 */
    app_command(JW_CMD_HATCH);
    cksame(jw_cmd_prompt(), JW_STR_5377, "ハッチは始めの線・弧を指示");
    {
        char w0[256];

        snprintf(w0, sizeof w0, "%s   %s %d %s", JW_STR_5377, JW_STR_7006, 0, JW_STR_7000);
        cksame(jw_cmd_status(app_drawing()), w0, "  輪が無ければ 【 0 】");
    }
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5378, "  一つ入ると次の線・円を指示");
    {
        /* 末尾の数（FUN_00672100: 逆コンパイルの読み、原典では押していない） */
        char want[256];

        snprintf(want, sizeof want, "%s     %s %d %s   < %d >", JW_STR_5378,
                 JW_STR_7006, 0, JW_STR_7000, 1);
        cksame(jw_cmd_status(app_drawing()), want, "  ハッチの末尾は 【 0 】   < 1 >");
    }

    /* 曲線: サインは基準線のあと五点、２次は四点 */
    app_command(JW_CMD_KYOKUSEN);
    jw_cmd_bar(0, 1689);                /* サイン曲線 */
    cksame(jw_cmd_prompt(), JW_STR_5345, "サイン曲線は基準線から");
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5404, "  次は原点");
    click(-80.0, 10.0);
    cksame(jw_cmd_prompt(), JW_STR_5417, "  次は振幅の幅の点");
    click(-60.0, 20.0);
    cksame(jw_cmd_prompt(), JW_STR_5418, "  次は１サイクル点");
    click(-20.0, 10.0);
    cksame(jw_cmd_prompt(), P_START, "  次は始点");
    click(0.0, 10.0);
    cksame(jw_cmd_prompt(), P_END, "  そして終点");

    app_command(JW_CMD_KYOKUSEN);
    jw_cmd_bar(0, 1690);                /* ２次曲線 */
    cksame(jw_cmd_prompt(), JW_STR_5345, "２次曲線も基準線から");
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5404, "  次は原点");
    click(-80.0, 10.0);
    cksame(jw_cmd_prompt(), JW_STR_5416, "  次は中間点");
    click(-60.0, 20.0);
    cksame(jw_cmd_prompt(), P_START, "  次は始点");

    app_command(JW_CMD_KYOKUSEN);
    jw_cmd_bar(0, 1691);                /* スプライン */
    cksame(jw_cmd_prompt(), P_START, "スプラインは始点から");
    click(-80.0, 10.0);
    cksame(jw_cmd_prompt(), JW_STR_5416, "  一点入ると中間点");

    /* ２線: 機械語から読んだ 0x14e1・0x1519・0x151a */
    app_command(JW_CMD_NISEN);
    jw_cmd_box_click(1412);             /* 間隔: 空だと線を拾わない */
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    jw_cmd_box_key('5');
    jw_cmd_box_key(13);
    cksame(jw_cmd_prompt(), JW_STR_5345, "２線は基準線から");
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5401, "  拾うと始点");
    click(-80.0, 20.0);
    cksame(jw_cmd_prompt(), JW_STR_5402, "  そして終点");

    /* 整理: 選択確定のあとは 0x152c 実行項目を指示 */
    app_command(JW_CMD_SEIRI);
    click(-150.0, 100.0);
    click(150.0, -100.0);
    {   /* 選択確定 は窓の上にカーソルがあるときだけ効く */
        const jw_view *v = app_view();
        app_move(jw_sx(v, 0.0), jw_sy(v, 0.0));
    }
    jw_cmd_bar((jw_drawing *)d, 1120);  /* 選択確定 */
    cksame(jw_cmd_prompt(), JW_STR_5420, "整理は確定すると実行項目を指示");

    /* 図形読込: 図形がなければ 0x14ea */
    app_take_action();
    app_command(JW_CMD_ZUKEI);
    ck(app_take_action() == JW_ACT_OPEN_FIG,
       "図形 (32862) は表側にファイルの窓を出させる");
    ck(jw_cmd() == JW_CMD_ZUKEI, "  命令には入っている");
    ck(!jw_cmd_figure_ready(), "まだ図形を読んでいない");
    cksame(jw_cmd_prompt(), JW_STR_5354,
           "  その間は「【図形】データがありません」");
}

/* 複線: 線を選んだあとの「間隔を入力するか、複写する位置…」(5312) には、
   線からマウスまでの距離が実寸で付く。逆コンパイルの読み（FUN_00658890 の
   0x14c0 の分岐、空白二つのあとに 三桁区切り・小数 3 桁）。原典の実測は
   18,428.571 などの形だけ分かっていて、どの位置での値かは録っていない */
static void fukusen_tail(void)
{
    const jw_drawing *d;
    const jw_view *v;
    const char *st;
    size_t n = strlen(JW_STR_5312);
    char num[64];
    int i, k = 0;
    double got, want, slack;

    app_new();
    d = app_drawing();
    v = app_view();
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);
    click(-100.0, 0.0);
    click(100.0, 0.0);
    app_command(JW_CMD_FUKUSEN);
    cksame(jw_cmd_status(d), JW_STR_5305, "複線は線を選ぶまで数値なし");
    click(0.0, 0.0);
    app_move(jw_sx(v, 0.0), jw_sy(v, 30.0));
    st = jw_cmd_status(d);
    ck(!strncmp(st, JW_STR_5312, n) && !strncmp(st + n, "  ", 2)
       && st[n + 2] != ' ',
       "  線を選ぶと 5312 の後ろに空白二つで数値");
    for (i = (int)n + 2; st[i] && k < (int)sizeof num - 1; i++)
        if (st[i] != ',')
            num[k++] = st[i];
    num[k] = 0;
    got = atof(num);
    want = 30.0 * scale_of(d);
    slack = 1.5 * v->mmpp * scale_of(d);
    ck(fabs(got - want) <= slack && strchr(st + n, '.')
       && strlen(strchr(st + n, '.')) == 4,
       "  数値は線からマウスまでの距離 × 縮尺、小数 3 桁");
    ck(strchr(st + n, ',') != 0, "  三桁ごとにコンマ");
    app_command(JW_CMD_SEN);
}

/* 複線の末尾: 選んだ線が複数のとき（FUN_006608e0）。選んだ全部のうち 点数（垂線の長さ、足が
   線分の外なら 近い端点までを足す）がいちばん小さいものの距離。逆コンパイルの読み、
   原典では押していない */
static void fukusen_tail_multi(void)
{
    jw_drawing *d;
    const jw_view *v;
    const char *st;
    size_t n = strlen(JW_STR_5312);
    char num[64];
    int i, k = 0;
    double got, want;

    app_new();
    d = (jw_drawing *)app_drawing();
    v = app_view();
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);
    click(-100.0, 50.0);
    click(100.0, 50.0);
    click(-100.0, 0.0);
    click(100.0, 0.0);
    app_command(JW_CMD_SEN);
    for (i = 0; i < d->ndrawn; i++)
        d->obj[i].sel = 1;
    app_command(JW_CMD_FUKUSEN);
    app_move(jw_sx(v, 0.0), jw_sy(v, 20.0));
    st = jw_cmd_status(d);
    ck(!strncmp(st, JW_STR_5312, n), "選んだ二本が元（複数）でも 5312 の末尾に数値");
    for (i = (int)n + 2; st[i] && k < (int)sizeof num - 1; i++)
        if (st[i] != ',')
            num[k++] = st[i];
    num[k] = 0;
    got = atof(num);
    want = 20.0 * scale_of(d);
    ck(fabs(got - want) <= 1.5 * v->mmpp * scale_of(d),
       "  いちばん近い線までの距離（先に描いた遠い線のではない）");
    app_move(jw_sx(v, 0.0), jw_sy(v, 40.0));
    st = jw_cmd_status(d);
    k = 0;
    for (i = (int)n + 2; st[i] && k < (int)sizeof num - 1; i++)
        if (st[i] != ',')
            num[k++] = st[i];
    num[k] = 0;
    got = atof(num);
    want = 10.0 * scale_of(d);
    ck(fabs(got - want) <= 1.5 * v->mmpp * scale_of(d),
       "  線の間のときは近いほう（40 なら y=50 の線まで 10）");
    app_command(JW_CMD_SEN);
}

/* 複線の残り: (R) 前回値・端点指定 (1065)・範囲選択 (1067)・移動 (1323)。
   どれも CZukeiFukusen の逆コンパイルの読み（slot 11・26・28/34・3、src/cmd.c の
   fk_* の注）で、原典では押していない */
static void fk_box(int id, const char *s)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    for (; *s; s++)
        jw_cmd_box_key((unsigned char)*s);
    jw_cmd_box_key(13);
}

static int fk_has_line(const jw_drawing *d, double x0, double y0,
                       double x1, double y1)
{
    int i;

    for (i = 0; i < d->ndrawn; i++) {
        const jw_obj *o = &d->obj[i];

        if (o->cls != JW_SEN)
            continue;
        if ((fabs(o->d[0] - x0) < 1e-6 && fabs(o->d[1] - y0) < 1e-6
             && fabs(o->d[2] - x1) < 1e-6 && fabs(o->d[3] - y1) < 1e-6)
            || (fabs(o->d[0] - x1) < 1e-6 && fabs(o->d[1] - y1) < 1e-6
                && fabs(o->d[2] - x0) < 1e-6 && fabs(o->d[3] - y0) < 1e-6))
            return 1;
    }
    return 0;
}

static void fukusen_rest(void)
{
    jw_drawing *d;
    const jw_view *v;
    char ten[32], dir[256];
    int n, k;

    app_new();
    d = (jw_drawing *)app_drawing();
    v = app_view();
    snprintf(ten, sizeof ten, "%g", 10.0 * scale_of(d));      /* 紙で 10 mm */
    snprintf(dir, sizeof dir, "%s%s", JW_STR_5310, JW_STR_5708);
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, v, -100.0, 0.0, 0);
    jw_cmd_point(d, v, 100.0, 0.0, 0);
    ck(fk_has_line(d, -100, 0, 100, 0), "複線の残り: 元の線");

    /* (R) 前回値 */
    jw_cmd_set(JW_CMD_FUKUSEN);
    jw_cmd_point(d, v, 50.0, 0.0, 1);
    ck(!strncmp(jw_cmd_status(d), JW_STR_5312, strlen(JW_STR_5312)),
       "  (R) でも 箱が空で まだ写していなければ「間隔を入力するか」");
    app_key(27);
    cksame(jw_cmd_status(d), JW_STR_5305, "  Esc で線を選ぶ段へ");
    jw_cmd_point(d, v, 0.0, 0.0, 0);
    jw_cmd_point(d, v, 0.0, 20.0, 0);
    jw_cmd_point(d, v, 0.0, 20.0, 0);
    ck(fk_has_line(d, -100, 20, 100, 20), "  (L) で自由位置に写す (20 mm)");
    jw_cmd_point(d, v, 50.0, 0.0, 1);
    cksame(jw_cmd_status(d), dir, "  (R) 前回値: すぐ「作図する方向を指示」");
    jw_cmd_point(d, v, 0.0, -3.0, 0);
    ck(fk_has_line(d, -100, -20, 100, -20), "  前回の 20 mm で 反対側へ");
    jw_cmd_set(JW_CMD_FUKUSEN);
    jw_cmd_point(d, v, 50.0, 0.0, 1);
    ck(!strncmp(jw_cmd_status(d), JW_STR_5312, strlen(JW_STR_5312)),
       "  命令に入り直すと前回値はない（箱も空になる）");
    app_key(27);
    fk_box(1411, ten);
    jw_cmd_point(d, v, 50.0, 0.0, 1);
    cksame(jw_cmd_status(d), dir, "  (R): 箱に数があれば それで方向へ");
    jw_cmd_point(d, v, 0.0, 3.0, 0);
    ck(fk_has_line(d, -100, 10, 100, 10), "  箱の 10 mm");

    /* 端点指定 (1065) */
    jw_cmd_set(JW_CMD_FUKUSEN);
    ck(jw_cmd_bar_enabled(d, 1065) == 0, "端点指定: 線を拾う前は死んでいる");
    fk_box(1411, ten);
    jw_cmd_point(d, v, 0.0, 0.0, 0);
    ck(jw_cmd_bar_enabled(d, 1065) == 1, "  間隔があって線を拾えば生きる");
    ck(jw_cmd_bar(d, 1065), "  押せる");
    ck(strstr(jw_cmd_status(d), JW_STR_5320) != 0, "  始点を訊く (5506 + 5320)");
    jw_cmd_point(d, v, -30.0, 50.0, 0);
    ck(strstr(jw_cmd_status(d), JW_STR_5321) != 0, "  終点を訊く (5321)");
    jw_cmd_point(d, v, -30.0, 50.0, 0);
    ck(strstr(jw_cmd_status(d), JW_STR_5321) != 0, "  始点と同じ点は受けない");
    app_key(27);
    ck(strstr(jw_cmd_status(d), JW_STR_5320) != 0, "  Esc で始点へ戻る");
    jw_cmd_point(d, v, -30.0, 50.0, 0);
    jw_cmd_point(d, v, 40.0, 70.0, 0);
    cksame(jw_cmd_status(d), dir, "  二点で方向を訊く段に戻る");
    jw_cmd_point(d, v, 0.0, -3.0, 0);
    ck(fk_has_line(d, -30, -10, 40, -10), "  写しは 二点を落とした所が端");

    /* 移動 (1323) */
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, v, -50.0, 100.0, 0);
    jw_cmd_point(d, v, 50.0, 100.0, 0);
    for (k = 0; k < d->ndrawn; k++)
        if (d->obj[k].cls == JW_SEN && fabs(d->obj[k].d[1] - 100.0) < 1e-9)
            d->obj[k].color = 5;
    jw_cmd_set(JW_CMD_FUKUSEN);
    ck(jw_cmd_bar(d, 1323) && jw_cmd_bar_check(1323) > 0, "移動: 印を入れる");
    fk_box(1411, ten);
    n = d->ndrawn;
    jw_cmd_point(d, v, 0.0, 100.0, 0);
    jw_cmd_point(d, v, 0.0, 103.0, 0);
    ck(d->ndrawn == n && fk_has_line(d, -50, 110, 50, 110)
       && !fk_has_line(d, -50, 100, 50, 100), "  元の線は消えて 写しだけ");
    {
        const jw_obj *o = last_of(d, JW_SEN);

        ck(o && o->color == 5, "  写しは元の線色のまま");
    }
    jw_cmd_undo(d);
    ck(d->ndrawn == n && fk_has_line(d, -50, 100, 50, 100)
       && !fk_has_line(d, -50, 110, 50, 110), "  戻るで元どおり");
    jw_cmd_bar(d, 1323);
    ck(jw_cmd_bar_check(1323) == 0, "  印を外す");

    /* 範囲選択 (1067) */
    jw_cmd_set(JW_CMD_FUKUSEN);
    fk_box(1411, ten);
    ck(jw_cmd_bar_enabled(d, 1067) == 1 && jw_cmd_bar(d, 1067), "範囲選択: 押せる");
    ck(strcmp(jw_cmd_status(d), JW_STR_5305) != 0, "  範囲を訊く");
    jw_cmd_point(d, v, -60.0, 95.0, 0);
    jw_cmd_point(d, v, 60.0, 105.0, 0);
    jw_cmd_track(0, 20);
    ck(jw_cmd_bar(d, 1120), "  選択確定");
    cksame(jw_cmd_status(d), dir, "  複線に戻って 箱の間隔で方向を訊く");
    jw_cmd_point(d, v, 0.0, 97.0, 0);
    ck(fk_has_line(d, -50, 90, 50, 90), "  選んだ線を写す");
    jw_cmd_set(JW_CMD_SEN);
}

/* 複線の 連続線選択 (1066): 拾った線から つながった線をまとめて選び、
   それを複線の元にする（CZukeiFukusen の slot 27 FUN_0065b780 → FUN_0040f830
   → FUN_00659200 の読み、原典では押していない） */
static void fukusen_chain(void)
{
    jw_drawing *d;
    const jw_view *v;
    char ten[32], dir[256];
    int n, k;

    app_new();
    d = (jw_drawing *)app_drawing();
    v = app_view();
    snprintf(ten, sizeof ten, "%g", 10.0 * scale_of(d));
    snprintf(dir, sizeof dir, "%s%s", JW_STR_5310, JW_STR_5708);
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, v, 0.0, 0.0, 0);
    jw_cmd_point(d, v, 50.0, 0.0, 0);
    jw_cmd_point(d, v, 50.0, 0.0, 0);
    jw_cmd_point(d, v, 50.0, 30.0, 0);
    jw_cmd_point(d, v, 100.0, 100.0, 0);
    jw_cmd_point(d, v, 150.0, 100.0, 0);
    ck(fk_has_line(d, 0, 0, 50, 0) && fk_has_line(d, 50, 0, 50, 30)
       && fk_has_line(d, 100, 100, 150, 100), "連続線選択: L 字と離れた線");

    jw_cmd_set(JW_CMD_FUKUSEN);
    fk_box(1411, ten);
    ck(jw_cmd_bar_enabled(d, 1066) == 0, "  線を拾う前は死んでいる");
    jw_cmd_point(d, v, 25.0, 0.0, 0);
    ck(jw_cmd_bar_enabled(d, 1066) == 1, "  線を拾うと生きる");
    ck(jw_cmd_bar(d, 1066) == 1, "  押せる");
    ck(jw_cmd_sel_count(d) == 2, "  つながった二本が選ばれ、離れた線は入らない");
    cksame(jw_cmd_status(d), dir, "  箱の間隔で 方向を訊く段");
    n = d->ndrawn;
    jw_cmd_point(d, v, 25.0, -3.0, 0);
    ck(d->ndrawn == n + 2, "  一度のクリックで二本");
    ck(fk_has_line(d, 0, -10, 60, -10) && fk_has_line(d, 60, -10, 60, 30),
       "  角を延ばして つないだ外側の複線");

    /* 全円は端点が無いので連続線にならず、線を選ぶ段に戻る */
    {
        jw_obj *o = jw_add(d, JW_ENKO);

        o->d[0] = 0.0;
        o->d[1] = 200.0;
        o->d[2] = 20.0;
        o->d[3] = 0.0;
        o->d[4] = 2.0 * PI;
        o->d[5] = 0.0;
        o->d[6] = 1.0;
        for (k = 0; k < d->ndrawn; k++)
            d->obj[k].sel = 0, d->obj[k].flags &= (unsigned short)~2u;
    }
    jw_cmd_set(JW_CMD_FUKUSEN);
    jw_cmd_point(d, v, 20.0, 200.0, 0);
    ck(jw_cmd_bar_enabled(d, 1066) == 1, "  円を拾っても生きる");
    ck(jw_cmd_bar(d, 1066) == 1, "  押すと");
    cksame(jw_cmd_status(d), JW_STR_5305, "  円は鎖にならず 線を選ぶ段へ");
    ck(jw_cmd_bar_enabled(d, 1066) == 0, "  そこでは死んでいる");
    jw_cmd_set(JW_CMD_SEN);
}

/* 範囲選択の 選択図形登録 (1068): 選んだものが ハッチの 図形 (1693) の型になる
   （CZukeiSentaku の 29 番目 FUN_006fb760 の読み、原典では押していない） */
static void hani_figreg(void)
{
    jw_drawing *d;
    const jw_view *v;
    char p[32];
    int n, k, hatched = 0;

    app_new();
    d = (jw_drawing *)app_drawing();
    v = app_view();
    jw_cmd_set(JW_CMD_SEN);
    jw_cmd_point(d, v, -100.0, -60.0, 0);
    jw_cmd_point(d, v, 100.0, -60.0, 0);
    jw_cmd_point(d, v, 100.0, -60.0, 0);
    jw_cmd_point(d, v, 100.0, 60.0, 0);
    jw_cmd_point(d, v, 100.0, 60.0, 0);
    jw_cmd_point(d, v, -100.0, 60.0, 0);
    jw_cmd_point(d, v, -100.0, 60.0, 0);
    jw_cmd_point(d, v, -100.0, -60.0, 0);
    jw_cmd_point(d, v, -10.0, -10.0, 0);
    jw_cmd_point(d, v, 10.0, -10.0, 0);
    jw_cmd_point(d, v, 10.0, -10.0, 0);
    jw_cmd_point(d, v, 10.0, 10.0, 0);

    jw_cmd_set(JW_CMD_HANI);
    ck(jw_cmd_bar_enabled(d, 1068) == 0, "選択図形登録: 範囲の前は死んでいる");
    jw_cmd_point(d, v, -20.0, -20.0, 0);
    jw_cmd_point(d, v, 20.0, 20.0, 0);
    ck(jw_cmd_sel_count(d) == 2, "  枠で L 字の二本");
    ck(jw_cmd_bar_enabled(d, 1068) == 1, "  範囲が決まると生きる");
    ck(jw_cmd_bar(d, 1068) == 1, "  押せる");
    ck(jw_cmd_sel_count(d) == 2, "  選択はそのまま残る");
    for (k = 0; k < d->ndrawn; k++)     /* ハッチの試験（hatchfig）と同じく選択なしで */
        d->obj[k].sel = 0, d->obj[k].flags &= (unsigned short)~2u;

    jw_cmd_set(JW_CMD_HATCH);
    ck(jw_cmd_bar(d, 1693) == 1, "  ハッチの 図形 に");
    snprintf(p, sizeof p, "%g", 40.0 * scale_of(d));
    fk_box(1419, "0");
    fk_box(1411, p);
    fk_box(1412, p);
    n = d->ndrawn;
    jw_cmd_point(d, v, 0.0, -60.0, 1);
    ck(jw_cmd_bar(d, 1148) == 1, "  実行");
    for (k = n; k < d->ndrawn; k++)
        if ((d->obj[k].flags & 0x20) && d->obj[k].cls == JW_SEN
            && fabs(hypot(d->obj[k].d[2] - d->obj[k].d[0],
                          d->obj[k].d[3] - d->obj[k].d[1]) - 20.0) < 1e-6)
            hatched++;
    ck(hatched > 0, "  登録した L 字の写しで敷き詰める");
    jw_cmd_set(JW_CMD_SEN);
}

/* 接円: 一つ目・二つ目を訊く間、半径が箱にあれば「    [ r = %.3lf ]」
   （CZukeiSetuEn の 0x14fc・0x14fd。逆コンパイルの読み） */
static void sekien_tail(void)
{
    const jw_drawing *d;
    char want[256];
    int i;

    app_new();
    d = app_drawing();
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);
    click(-100.0, 40.0);
    click(100.0, 40.0);
    app_command(JW_CMD_SEKIEN);
    jw_cmd_box_click(1411);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    jw_cmd_box_key(13);
    cksame(jw_cmd_status(d), JW_STR_5372, "接円は半径が空なら末尾なし");
    jw_cmd_box_click(1411);
    jw_cmd_box_key('1');
    jw_cmd_box_key('5');
    jw_cmd_box_key('0');
    jw_cmd_box_key('0');
    jw_cmd_box_key(13);
    snprintf(want, sizeof want, "%s    [ r = 1500.000 ]", JW_STR_5372);
    cksame(jw_cmd_status(d), want, "  半径 1500 なら [ r = 1500.000 ]");
    click(0.0, 40.0);
    snprintf(want, sizeof want, "%s    [ r = 1500.000 ]", JW_STR_5373);
    cksame(jw_cmd_status(d), want, "  一つ目を選んだあとも");
    jw_cmd_box_click(1411);
    for (i = 0; i < 24; i++)
        jw_cmd_box_key(8);
    jw_cmd_box_key(13);
    app_command(JW_CMD_SEN);
}

static void type_into(int id, const char *t);

/* 接円の三つ目の段（0x14ff）の末尾「     【 解の数 - マウスにいちばん近い候補の番号 】」
   （FUN_007063b0・FUN_0070b570。逆コンパイルの読み、番号の順は原典で録っていない） */
static void sekien_third(void)
{
    jw_drawing *d;
    const jw_view *v;
    char box[32], head[256], got[4][256];
    static const double q[4][2] = { { 30, 30 }, { -30, 30 }, { -30, -30 }, { 30, -30 } };
    int i, k, seen = 0, ok = 1;

    app_new();
    d = (jw_drawing *)app_drawing();
    v = app_view();
    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);
    click(-100.0, 0.0);
    click(100.0, 0.0);
    click(0.0, -100.0);
    click(0.0, 100.0);
    app_command(JW_CMD_SEKIEN);
    snprintf(box, sizeof box, "%.6g", 20.0 * scale_of(d));
    type_into(1411, box);
    jw_cmd_box_key(13);
    click(60.0, 0.0);
    click(0.0, 60.0);
    snprintf(head, sizeof head, "%s     %s 4 - ", JW_STR_5375, JW_STR_7006);
    for (i = 0; i < 4; i++) {
        app_move(jw_sx(v, q[i][0]), jw_sy(v, q[i][1]));
        snprintf(got[i], sizeof got[i], "%s", jw_cmd_status(d));
        if (strncmp(got[i], head, strlen(head)))
            ok = 0;
        else {
            k = atoi(got[i] + strlen(head));
            if (k < 1 || k > 4 || (seen & (1 << k)))
                ok = 0;
            seen |= 1 << k;
        }
    }
    if (!ok)
        printf("        %s\n", got[0]);
    ck(ok, "接円の三つ目の段: 四つの解、象限ごとに 1〜4 の別の番号");
    ck(strstr(got[0], JW_STR_7000) != 0, "  終わりは 】");
    jw_cmd_set(JW_CMD_SEN);
}

/* バーの箱は式を取る（原典は値を FUN_004f2220・FUN_004f47b0 の式の読み手に通す）。
   移植は四則と括弧を、Enter か 箱を離れたときに計算して 答えを箱に残す */
static void type_into(int id, const char *t)
{
    int i;

    jw_cmd_box_click(id);
    for (i = 0; i < 40; i++)
        jw_cmd_box_key(8);
    while (*t)
        jw_cmd_box_key((unsigned char)*t++);
}

static void box_sums(void)
{
    app_new();
    app_command(JW_CMD_TAKAKU);
    type_into(1411, "900+75");
    jw_cmd_box_key(13);
    cksame(jw_cmd_box(1411), "975", "箱の 900+75 は Enter で 975");
    type_into(1411, "(1000-200)/4");
    jw_cmd_box_click(1413);             /* to another box: the sum is done */
    cksame(jw_cmd_box(1411), "200", "  (1000-200)/4 は 箱を離れると 200");
    jw_cmd_box_click(0);
    app_command(JW_CMD_KUKEI);
    type_into(1413, "1000*2,300+300");
    jw_cmd_box_key(13);
    cksame(jw_cmd_box(1413), "2000,600", "  二つの数は それぞれ計算");
    type_into(1413, "2^10+24");
    jw_cmd_box_key(13);
    cksame(jw_cmd_box(1413), "1048", "  ^ は 直前の数の累乗（2^10+24）");
    type_into(1413, "-500");
    jw_cmd_box_key(13);
    cksame(jw_cmd_box(1413), "-500", "  式でない数は そのまま");
    type_into(1413, "1+");
    jw_cmd_box_key(13);
    cksame(jw_cmd_box(1413), "1+", "  読み切れない式も そのまま");
    {
        /* the rest of the original's reader (FUN_004f2480 and its parts,
           逆コンパイルの読み -- 原典では打っていない) */
        static const struct { const char *in, *out, *what; } c[] = {
            { "s30+1", "1.5", "s は 次の数の sin（度）" },
            { "2c60", "1", "  数と関数のあいだは掛け算（2×cos60）" },
            { "q2*q2", "2", "  q は √" },
            { "//1", "45", "  // は 勾配の角度（atan）" },
            { "a1", "45", "  a も atan" },
            { "i7.9+b(-2)", "9", "  i は 整数に切る・b は 絶対値" },
            { "l1000", "3", "  l は log10" },
            { "n(j2)", "2", "  n は 自然対数・j は exp" },
            { "2p", "6.283185307", "  p は π（前の数と掛ける）" },
            { "3m", "3000", "  m は ×1000" },
            { "3mm", "3", "  mm は そのまま" },
            { "0x10+&a", "26", "  0x と & は 16 進" },
            { "1.5e3", "1500", "  e は 10 の累乗" },
            { "2^3^2", "64", "  ^ は 左から" },
            { "17%5", "2", "  % は 整数の余り" },
            { "30:30", "30.5", "  : は 度（分を足す）" },
            { "1:30'36\"", "1.51", "  度分秒" },
            { "2(3+4)", "14", "  数と括弧のあいだも掛け算" },
            { "-(2+3)*2", "-10", "  頭の負号" },
            { "2*-3", "-6", "  演算子のあとの負号は数のうち" },
            { "1/0", "1/0", "  0 で割ると 原典は知らせて終わり（そのまま）" },
            { "q(-1)", "q(-1)", "  負の √ も（そのまま）" },
            { "(1+2", "(1+2", "  閉じない括弧も（そのまま）" },
            { "1++2", "1++2", "  演算子が二つ続くのも（そのまま）" },
            { "2x", "40", "  x は 目盛間隔の横 × 縮尺（FUN_004f3b80、+0x7a28。ここは 10×2）" },
            { "x+y", "30", "  y は 縦（+0x7a30、5×2）" },
            { "2@+1", "1", "  @ は 式の読み手の第二引数、箱では 0" },
            { "\\", "20", "  2525 が切のとき \\ は x" },
            { "\\\\", "10", "  \\\\ は y（x のあとの \\ は y）" },
            { "12@@30@36@", "12.51", "  @@ は 度、@ は 分・秒（12゜30'36\"）" },
            { "12**30*36*", "12.51", "  ** も 度（* が 分・秒）" },
            { "@@30@", "0.5", "  度の前が数でなければ 0 を補う（0゜30'）" },
            { "3m^u2", "3", "  m^u2 は 単位の三字が落ち ×1000 も付かない（FUN_004f67d0）" },
            { "3mm^c3", "3", "  mm^c3 も" },
        };
        size_t i;

        {
            jw_drawing *wd = (jw_drawing *)app_drawing();
            int g;

            wd->mesh_ix = 10.0;
            wd->mesh_iy = 5.0;
            for (g = 0; g < 16; g++)
                wd->group[g].scale = 2.0;
        }

        for (i = 0; i < sizeof c / sizeof c[0]; i++) {
            type_into(1413, c[i].in);
            jw_cmd_box_key(13);
            if (strcmp(jw_cmd_box(1413), c[i].out))
                printf("        %s -> %s\n", c[i].in, jw_cmd_box(1413));
            cksame(jw_cmd_box(1413), c[i].out, c[i].what);
        }
    }
    type_into(1413, "");
    jw_cmd_box_key(13);
    app_command(JW_CMD_SEN);
}

/* 基本設定 2466「文字コマンドのとき文字位置指示後に文字入力を行う」: 字の無いうちの
   クリックが位置になり、そのあと打った字が Enter でそこへ行く（FUN_006bc120 の
   DAT_00a0cc64。逆コンパイルの読み） */
static void moji_point_first(void)
{
    const jw_drawing *d;
    int n;

    app_new();
    d = app_drawing();
    jw_cmd_moji_point_first(1);
    app_command(JW_CMD_MOJI);
    n = d->ndrawn;
    click(-40.0, 25.0);
    ck(d->ndrawn == n, "2466: 字の無いうちのクリックは何も置かない");
    app_key('A');
    app_key('B');
    app_key(13);
    ck(d->ndrawn == n + 1 && d->obj[d->ndrawn - 1].cls == JW_MOJI
       && fabs(d->obj[d->ndrawn - 1].d[0] - -40.0) < 1.0
       && fabs(d->obj[d->ndrawn - 1].d[1] - 25.0) < 1.0,
       "  打った字が Enter で その位置に置かれる");
    jw_cmd_moji_point_first(0);
    app_command(JW_CMD_SEN);
}

/* 文字 5316「文字を入力するか、移動・変更(L)、複写(R)で文字を指示して下さい」:
   入力欄が空のとき (L) で既存の文字を拾うと字が入力欄に入り、次のクリックで
   そこへ動く（元は消える）。(R) は複写。書き換えて Enter は元の基点の所。
   CZukeiMoji の FUN_006c71f0・FUN_006c7ae0・FUN_006c6160・FUN_006c83a0。
   逆コンパイルの読み、原典では押していない */
static void moji_pick_move(void);

/* 文字の 範囲選択 (2407) で選んだ字と コピー・切り取り・貼付・命令の切り替え。
   コピーは字を「字＋\n」のデータ順で控え（FUN_004fb140）、貼付 (1065) はその行を
   選んだ字へ。文字から種別の違う命令（消去・移動など）へ出ると選択は外れる
   （FUN_004fdc40 の +0x856c/+0x8570/+0x85b4）、線（同じ種別 1）へは残る。
   逆コンパイルの読み、原典では押していない */
static int moji_texts(const jw_drawing *d)
{
    int i, k = 0;

    for (i = 0; i < d->ndrawn; i++)
        k += d->obj[i].cls == JW_MOJI;
    return k;
}

static void moji_box(double x0, double y0, double x1, double y1)
{
    const jw_view *v = app_view();

    jw_cmd_bar((jw_drawing *)app_drawing(), 2407);
    app_press(jw_sx(v, x0), jw_sy(v, y0), 0);
    app_press(jw_sx(v, x1), jw_sy(v, y1), 1);      /* (R): 文字も */
    app_key(13);
}

static int bar_press(int id)
{
    const fb_t *fb = app_fb();
    int x, y;

    for (y = 0; y < fb->h; y += 2)
        for (x = 0; x < fb->w; x += 2)
            if (ui_bar_hit(x, y) == id) {
                app_press(x + 1, y + 1, 0);
                return 1;
            }
    return 0;
}

static void moji_hani_clip(void)
{
    jw_drawing *d;
    const unsigned char *b;
    long n;
    int i, k, t0, cd = -1;
    double top;

    app_new();
    d = (jw_drawing *)app_drawing();
    app_command(JW_CMD_MOJI);
    app_key('A');
    app_key('B');
    click(-40.0, 40.0);
    app_key('C');
    app_key('D');
    click(-40.0, 0.0);
    t0 = moji_texts(d);
    ck(t0 == 2, "字を二つ置く");
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI && !strcmp(jw_str(d, d->obj[i].text), "CD"))
            cd = i;
    top = cd >= 0 ? d->obj[cd].d[1] + d->obj[cd].d[5] : 0.0;

    moji_box(-80.0, 60.0, 60.0, -10.0);
    ck(jw_cmd() == JW_CMD_MOJI && jw_cmd_moji_ready() && jw_cmd_moji_count(d) == 2,
       "2407 の範囲で二つとも選ぶ");
    ck(app_command(57634) && app_take_action() == JW_ACT_CLIP_PUT
       && jw_cmd_moji_clip(&b, &n)
       && n == 9 && !memcmp(b, "\xef\xbb\xbf" "AB\nCD\n", 9),
       "コピーは字も控える（データの順、一字一行、LF）");
    ck(jw_cmd_moji_count(d) == 2 && moji_texts(d) == 2, "  コピーでは何も変わらない");

    /* 選び直して CD だけ、貼付 で AB・CD の二行: CD が AB に、CD が下に足される */
    click(50.0, -30.0);
    ck(!jw_cmd_moji_ready() && jw_cmd_sel_count(d) == 0, "図面のクリックで選択を外す");
    moji_box(-80.0, top + 2.0 < 39.0 ? top + 2.0 : 39.0, 60.0, -10.0);
    ck(jw_cmd_moji_count(d) == 1, "CD だけ選ぶ");
    ck(bar_press(1065) && moji_texts(d) == 3 && app_take_action() == 0,
       "貼付 は控えの行を選んだ字へ（表側には頼まない）");
    k = 0;
    for (i = 0; i < d->ndrawn; i++)
        if (d->obj[i].cls == JW_MOJI)
            k += !strcmp(jw_str(d, d->obj[i].text), "AB") * 10
               + !strcmp(jw_str(d, d->obj[i].text), "CD");
    ck(k == 21, "  AB が二つ、CD が一つ");
    ck(!jw_cmd_moji_ready() && jw_cmd_sel_count(d) == 0, "  貼付のあと選択は外れる");
    jw_cmd_undo(d);
    ck(moji_texts(d) == 2 && cd >= 0 && !strcmp(jw_str(d, d->obj[cd].text), "CD"),
       "  戻るで元どおり");
    ck(jw_cmd_moji_apply(d, (const unsigned char *)"\xef\xbb\xbf" "JWCLIP:QUJD", 14) == 0,
       "ブラウザの図形のクリップボード（JWCLIP:）は字の行にしない");

    /* 命令の切り替え */
    moji_box(-80.0, 60.0, 60.0, -10.0);
    app_command(JW_CMD_SEN);
    ck(jw_cmd_sel_count(d) == 2, "文字から 線（同じ種別）へは選択が残る");
    app_command(JW_CMD_MOJI);
    moji_box(-80.0, 60.0, 60.0, -10.0);
    app_command(JW_CMD_SHOUKYO);
    ck(jw_cmd_sel_count(d) == 0 && moji_texts(d) == 2,
       "文字から 消去 へ出ると選択は外れる（消しはしない）");
    app_command(JW_CMD_MOJI);
    moji_box(-80.0, 60.0, 60.0, -10.0);
    app_command(JW_CMD_IDOU);
    ck(jw_cmd_sel_count(d) == 0, "移動 へも持ち越さない");
    app_command(JW_CMD_MOJI);
    moji_box(-80.0, 60.0, 60.0, -10.0);
    app_command(JW_CMD_MOJI);
    ck(jw_cmd_sel_count(d) == 0, "文字に入り直すと外れる");

    /* 切り取り: 字が消えて控えに残る */
    moji_box(-80.0, 60.0, 60.0, -10.0);
    ck(app_command(57635) && moji_texts(d) == 0
       && jw_cmd_moji_clip(&b, &n) && n == 9, "切り取りは字を消して控える");
    ck(jw_cmd_notice_id() == 5299, "  札「コピー」（0x14b3）");
    ck(jw_cmd_moji_ready(), "  バー（+0x5d4）は下ろさない");
    click(50.0, -30.0);
    ck(!jw_cmd_moji_ready(), "  図面を押すと下りる");
    app_command(JW_CMD_MOJI);
    ck(!app_command(57634) && jw_cmd_notice_id() == 5201,
       "選択が空のコピーは札「図形がありません」（0x1451）");
    app_command(JW_CMD_SEN);
    click(0.0, 0.0);
    click(10.0, 0.0);
    app_command(JW_CMD_HANI);
    {
        const jw_view *v = app_view();

        app_press(jw_sx(v, -5.0), jw_sy(v, 5.0), 0);
        app_press(jw_sx(v, 15.0), jw_sy(v, -5.0), 0);
    }
    ck(app_command(57634) && !jw_cmd_moji_clip(&b, &n), "字の無いコピーで控えは空に");
}

static void moji_pick_move(void)
{
    jw_drawing *d;
    const jw_obj *o;
    int n, k;
    double mx, my, x0, y0;

    app_new();
    d = (jw_drawing *)app_drawing();
    app_command(JW_CMD_MOJI);
    app_key('A');
    app_key('B');
    click(-40.0, 25.0);
    n = d->ndrawn;
    o = &d->obj[n - 1];
    ck(o->cls == JW_MOJI && o->ltype == 1, "置いた字の線種 byte は 基点 左下 = 1");
    x0 = o->d[0];
    y0 = o->d[1];
    mx = (o->d[0] + o->d[2]) / 2.0;
    my = o->d[1] + o->d[5] * 0.3;
    d->obj[n - 1].layer = 3;            /* 拾った字のレイヤで置き直される */
    click(mx, my);
    ck(d->ndrawn == n && strcmp(jw_cmd_line(), "AB") == 0,
       "入力欄が空の (L): 字を拾って入力欄へ、何も置かない");
    click(10.0, 10.0);
    k = d->ndrawn - 1;
    ck(d->ndrawn == n && d->obj[k].cls == JW_MOJI
       && fabs(d->obj[k].d[0] - 10.0) < 1.0 && fabs(d->obj[k].d[1] - 10.0) < 1.0
       && d->obj[k].layer == 3 && strcmp(jw_str(d, d->obj[k].text), "AB") == 0,
       "  次のクリックへ移動（元は消える、レイヤは拾った字のまま）");
    ck(jw_cmd_line()[0] == 0, "  置いたら入力欄は空");
    jw_cmd_undo(d);
    ck(d->ndrawn == n && fabs(d->obj[n - 1].d[0] - x0) < 1e-6
       && fabs(d->obj[n - 1].d[1] - y0) < 1e-6, "  戻るで元の所に戻る");

    /* (R) は複写: 元が残る。置くのは (L) の free で */
    o = &d->obj[n - 1];
    mx = (o->d[0] + o->d[2]) / 2.0;
    my = o->d[1] + o->d[5] * 0.3;
    app_press(jw_sx(app_view(), mx), jw_sy(app_view(), my), 1);
    ck(d->ndrawn == n && strcmp(jw_cmd_line(), "AB") == 0, "入力欄が空の (R): 字を拾う");
    click(10.0, 10.0);
    ck(d->ndrawn == n + 1 && fabs(d->obj[n - 1].d[0] - x0) < 1e-6
       && fabs(d->obj[n].d[0] - 10.0) < 1.0, "  次のクリックへ複写（元は残る）");

    /* 書き換えて Enter: 最初の一打が全部を置き換え、元の基点の所へ */
    o = &d->obj[n];
    x0 = o->d[0];
    y0 = o->d[1];
    mx = (o->d[0] + o->d[2]) / 2.0;
    my = o->d[1] + o->d[5] * 0.3;
    click(mx, my);
    app_key('C');
    ck(strcmp(jw_cmd_line(), "C") == 0, "拾った直後の一打は 入力欄の字を置き換える");
    app_key(13);
    k = d->ndrawn - 1;
    ck(d->ndrawn == n + 1 && strcmp(jw_str(d, d->obj[k].text), "C") == 0
       && fabs(d->obj[k].d[0] - x0) < 1e-6 && fabs(d->obj[k].d[1] - y0) < 1e-6,
       "  Enter で 元の基点の所に 書き換わる（変更）");
    app_command(JW_CMD_SEN);
}

/* 距離指定点 (32930) の 連続 (1066): 置いた点の先へ、いまの箱の距離を
   もう一つ足した所に点。CZukeiKyori の 27 番 FUN_006ba0b0 → FUN_006baad0
   → FUN_006b9940 の読み（逆コンパイルの読み、原典では押していない）。
   釦は一つ置いてから生き、新しいクリックで死ぬ（FUN_006baa70）。 */
static int ten_count(const jw_drawing *d)
{
    int i, n = 0;

    for (i = 0; i < d->ndrawn; i++)
        n += d->obj[i].cls == JW_TEN;
    return n;
}

static void kyori_ren(void)
{
    jw_drawing *d;
    const jw_obj *o;
    double s;
    int n0;

    app_new();
    d = app_drawing();
    s = scale_of(d);
    app_command(JW_CMD_KYORITEN);
    type_into(1412, "1000");
    jw_cmd_box_key(13);
    jw_cmd_box_click(0);
    ck(jw_cmd_bar_enabled(d, 1066) == 0, "距離指定点の 連続 は始めは死んでいる");
    n0 = ten_count(d);
    click(0.0, 0.0);
    click(50.0, 0.0);
    o = last_of(d, JW_TEN);
    ck(ten_count(d) == n0 + 1 && o && fabs(o->d[0] - 1000.0 / s) < 1e-6
       && fabs(o->d[1]) < 1e-6, "  一つ目は始点から 1000 の所");
    ck(jw_cmd_bar_enabled(d, 1066) > 0, "  置くと 連続 が生きる");
    ck(jw_cmd_bar(d, 1066), "  連続 を押す");
    o = last_of(d, JW_TEN);
    ck(ten_count(d) == n0 + 2 && o && fabs(o->d[0] - 2000.0 / s) < 1e-6,
       "  二つ目は 2000 の所");
    type_into(1412, "500");
    jw_cmd_box_key(13);
    jw_cmd_box_click(0);
    jw_cmd_bar(d, 1066);
    o = last_of(d, JW_TEN);
    ck(ten_count(d) == n0 + 3 && o && fabs(o->d[0] - 2500.0 / s) < 1e-6,
       "  箱を 500 にすると その先 500 の所");
    click(10.0, 10.0);
    ck(jw_cmd_bar_enabled(d, 1066) == 0, "  新しいクリックで 連続 は切れる");
}

/* 図形読込のバー: 90ﾟ毎 (1064)・マウス角 (1068)・作図属性 (1067)。
   CTourokuZuDialog の 1064（CMy3Button、左 FUN_005f50c0）、1068 → slot 29
   FUN_00758b40・左 FUN_00758da0・FUN_00757c70、1067 → slot 28 FUN_00758840
   の読み（逆コンパイルの読み、原典では押していない） */
static unsigned char *fig_bytes(long *n)
{
    FILE *f = fopen("decomp/res/fig.jws", "rb");
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

static void fig_bar(void)
{
    jw_drawing *d, fg;
    unsigned char *b;
    long n;
    int n0, i, figlayer = -1, ok;
    double bx, by;

    app_new();
    d = app_drawing();
    b = fig_bytes(&n);
    ck(b != 0, "decomp/res/fig.jws を読む");
    if (!b)
        return;
    memset(&fg, 0, sizeof fg);
    if (jw_parse_jws(&fg, b, n, &bx, &by) && fg.ndrawn > 0)
        figlayer = fg.obj[0].layer;
    ck(app_figure(b, n) && jw_cmd() == JW_CMD_ZUKEI, "図形を読むと 図形読込");

    jw_cmd_bar(d, 1064);
    cksame(jw_cmd_box(1412), "90", "90ﾟ毎: 空の回転角は 90 に");
    jw_cmd_bar(d, 1064);
    cksame(jw_cmd_box(1412), "180", "  もう一度で 180");
    jw_cmd_box_put(1412, "45");
    jw_cmd_bar(d, 1064);
    cksame(jw_cmd_box(1412), "90", "  45 は 90 に");
    jw_cmd_box_put(1412, "300");
    jw_cmd_bar(d, 1064);
    cksame(jw_cmd_box(1412), "0", "  300 は 0 に");

    n0 = d->ndrawn;
    jw_cmd_bar(d, 1068);                /* マウス角: Ｘ方向 */
    click(10.0, 10.0);
    ck(d->ndrawn == n0, "マウス角: 一つ目のクリックでは置かない");
    cksame(jw_cmd_prompt(), JW_STR_10118, "  角度点の問い");
    click(10.0, 30.0);
    ck(d->ndrawn > n0, "  二つ目で置く");
    cksame(jw_cmd_box(1412), "90", "  その向き（真上）が回転角に");
    ck(strcmp(jw_cmd_prompt(), JW_STR_10118) != 0, "  一回きりで戻る");
    jw_cmd_bar(d, 1068);
    jw_cmd_bar(d, 1068);                /* Ｙ方向 */
    click(0.0, 0.0);
    click(0.0, 20.0);
    cksame(jw_cmd_box(1412), "0", "  Ｙ方向では真上が 0");

    ck(!jw_cmd_fzoku(0) && !jw_cmd_fzoku(1) && jw_cmd_fzoku(2) && jw_cmd_fzoku(3),
       "作図属性の既定は 書込レイヤ・書込グループ");
    jw_cmd_fzoku_set(2, 0);             /* 元レイヤ */
    n0 = d->ndrawn;
    click(50.0, 50.0);
    ok = d->ndrawn > n0;
    for (i = n0; i < d->ndrawn; i++)
        ok &= d->obj[i].layer == figlayer;
    ck(ok && figlayer >= 0, "  元レイヤ なら図形のレイヤのまま");
    jw_cmd_fzoku_set(2, 1);
    ck(bar_press(1067) && app_tdlg_open() && app_tdlg_tpl() == 342,
       "  作図属性 (1067) は 作図属性設定 の窓");
    app_key(13);
    ck(jw_cmd_fzoku(2) && jw_cmd_fzoku(3), "  開いて OK でもそのまま");
    jw_free(&fg);
    free(b);
}

int main(void)
{
    const jw_drawing *d;
    const jw_obj *o;
    char want[256];
    double s;

    /* --- the recipe against the original's own strings --------------- */
    tail_line(want, (int)sizeof want, P_START, -26.565, 27380.424);
    cksame(want, P_START "   [ -26.565\x81\x8b]   27,380.424",
           "原典の一行目どおりに組み立てられる（線）");
    tail_line(want, (int)sizeof want, P_END, 0.0, 0.0);
    cksame(want, P_END "   [ 0.000\x81\x8b]   0.000",
           "始点だけ入れたところも");
    tail_box(want, (int)sizeof want, P_START, 24489.795, 12244.897);
    cksame(want, P_START "     W=24,489.795    H=12,244.897",
           "矩形の W と H も");
    tail_circle(want, (int)sizeof want, P_CEN, 6122.448);
    cksame(want, P_CEN "      r = 6,122.448", "円の r も");

    /* --- and the port, drawing the same things ----------------------- */
    app_resize(1264, 741);
    app_new();
    d = app_drawing();
    s = scale_of(d);
    ck(s > 0.0, "紙の縮尺が取れる");
    cksame(jw_cmd_status(d), P_START, "何も描く前は尻尾なし");

    app_command(JW_CMD_SEN);
    if (jw_cmd_bar_check(1333) > 0)
        app_key(32);                    /* Space: 水平・垂直 off */
    cksame(jw_cmd_status(d), P_START, "コマンドを出しただけでも尻尾なし");
    click(-155.51, 26.3265);
    tail_line(want, (int)sizeof want, P_END, 0.0, 0.0);
    cksame(jw_cmd_status(d), want, "始点を入れると 0.000");
    click(89.3878, -96.1224);
    o = last_of(d, JW_SEN);
    ck(o != 0, "線が引ける");
    if (o) {
        double dx = o->d[2] - o->d[0], dy = o->d[3] - o->d[1];
        tail_line(want, (int)sizeof want, P_START,
                  atan2(dy, dx) * 180.0 / PI,
                  sqrt(dx * dx + dy * dy) * s);
        cksame(jw_cmd_status(d), want, "引いた線の角と長さ");
    }

    app_command(JW_CMD_KUKEI);
    cksame(jw_cmd_status(d), P_START, "矩形に移ると尻尾は消える");
    click(-155.51, 26.3265);
    click(89.3878, -96.1224);
    {
        double x0 = 0, y0 = 0, x1 = 0, y1 = 0;
        int i, k, first = 1;
        for (i = d->ndrawn - 4; i < d->ndrawn; i++) {
            if (i < 0 || d->obj[i].cls != JW_SEN)
                continue;
            for (k = 0; k < 4; k += 2) {
                double px = d->obj[i].d[k], py = d->obj[i].d[k + 1];
                if (first) {
                    x0 = x1 = px;
                    y0 = y1 = py;
                    first = 0;
                } else {
                    if (px < x0) x0 = px;
                    if (px > x1) x1 = px;
                    if (py < y0) y0 = py;
                    if (py > y1) y1 = py;
                }
            }
        }
        ck(!first, "四角が引ける");
        tail_box(want, (int)sizeof want, P_START, (x1 - x0) * s, (y1 - y0) * s);
        cksame(jw_cmd_status(d), want, "その W と H");
    }

    app_command(JW_CMD_ENKO);
    cksame(jw_cmd_status(d), P_CEN, "円に移ると尻尾は消える");
    click(0.0, 0.0);
    click(61.2245, 0.0);
    o = last_of(d, JW_ENKO);
    ck(o != 0, "円が描ける");
    if (o) {
        tail_circle(want, (int)sizeof want, P_CEN, o->d[2] * s);
        cksame(jw_cmd_status(d), want, "その半径");
    }

    app_command(JW_CMD_TEN);
    cksame(jw_cmd_status(d), P_TEN, "点に移ると尻尾は消える");

    prompts_of_the_commands();
    fukusen_tail();
    fukusen_tail_multi();
    fukusen_rest();
    fukusen_chain();
    hani_figreg();
    sekien_tail();
    sekien_third();
    box_sums();
    moji_point_first();
    moji_pick_move();
    moji_hani_clip();

    kyori_ren();
    fig_bar();

    /* Jw_cadの終了 (57665): 表側に窓を閉じさせる（ネイティブは WM_CLOSE） */
    app_take_action();
    ck(app_command(57665) && app_take_action() == JW_ACT_EXIT,
       "Jw_cadの終了 は表側に閉じさせる");

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
