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
    click(0.0, 40.0);
    cksame(jw_cmd_prompt(), JW_STR_5378, "  一つ入ると次の線・円を指示");

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
    app_command(JW_CMD_ZUKEI);
    ck(!jw_cmd_figure_ready(), "まだ図形を読んでいない");
    cksame(jw_cmd_prompt(), JW_STR_5354,
           "  その間は「【図形】データがありません」");
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

    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
