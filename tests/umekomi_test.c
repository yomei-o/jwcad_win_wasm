/* 埋め込み文字（%f・&F・=F・&J・%SS ほか）の置き換え（src/umekomi.c）。
 *
 * 置き方は原典 FUN_00490050 の読み（src/umekomi.c の注）と原典のヘルプ
 * （Jw_cad.chm の「埋め込み文字」）。原典では押していない。ここで確かめる
 * のは 移植がその読みどおりに置くこと、刷るとき（PDF・PNG）に効くこと、
 * 基本設定 一般(2) 2531 で画面にも効くこと。 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "../src/app.h"
#include "../src/draw.h"
#include "../src/jww.h"
#include "../src/plot.h"
#include "../src/ui.h"
#include "../src/umekomi.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

static time_t at_local(int y, int mo, int d, int h, int mi, int s)
{
    struct tm t;

    memset(&t, 0, sizeof t);
    t.tm_year = y - 1900;
    t.tm_mon = mo - 1;
    t.tm_mday = d;
    t.tm_hour = h;
    t.tm_min = mi;
    t.tm_sec = s;
    t.tm_isdst = -1;
    return mktime(&t);
}

static jw_drawing dd;
static jw_obj oo;

static void is(const char *in, const char *want, const char *what)
{
    const char *got = jw_umekomi_text(&dd, &oo, in, 1);
    char line[200];

    snprintf(line, sizeof line, "%s: 「%s」", what, in);
    ck(got && !strcmp(got, want), line);
    if (!got || strcmp(got, want))
        printf("     got [%s] want [%s]\n", got ? got : "(null)", want);
}

static void same(const char *in, const char *what)
{
    ck(jw_umekomi_text(&dd, &oo, in, 1) == in, what);
}

static int hit(int want)
{
    const fb_t *fb = app_fb();
    int x, y;

    for (y = 0; y < fb->h; y++)
        for (x = 0; x < fb->w; x++)
            if (ui_kihon_hit(fb->w, fb->h, app_kihon_tab(), x, y) == want) {
                app_press(x, y, 0);
                return 1;
            }
    return 0;
}

static int kh_press(int tab, int id)
{
    if (!app_kihon_open())
        app_command(32891);
    if (!app_kihon_open())
        return 0;
    if (app_kihon_tab() != tab && !hit(-tab - 1))
        return 0;
    return hit(id);
}

/* PDF の字は <16 進> Tj で出る */
static int pdf_has(const unsigned char *b, long n, const char *s)
{
    char hex[200];
    long i, m;
    int k;

    hex[0] = '<';
    for (k = 0; s[k]; k++)
        sprintf(hex + 1 + 2 * k, "%02X", (unsigned char)s[k]);
    strcat(hex, ">");
    m = (long)strlen(hex);
    for (i = 0; i + m <= n; i++)
        if (!memcmp(b + i, hex, (size_t)m))
            return 1;
    return 0;
}

int main(void)
{
    /* 2026-10-16（金）9:05:07 */
    time_t now = at_local(2026, 10, 16, 9, 5, 7);

    memset(&dd, 0, sizeof dd);
    memset(&oo, 0, sizeof oo);
    dd.group[0].scale = 50.0;
    dd.group[1].scale = 0.5;
    dd.group[2].scale = 1.0 / 3.0;
    dd.group[3].scale = 1.5;
    jw_umekomi_clock(now);
    jw_umekomi_saved(0);
    jw_umekomi_doc("C:\\prj\\\x95\x5c\x8e\xa6\\sub",   /* C:\prj\表示\sub */
                   "A-1001 \x82\x51\x8a\x4b \x8f\xda\x8d\xd7.jww");  /* ２階 詳細 */

    /* ---- 今の日時（& % $） ---- */
    is("%y", "26", "西暦の下 2 桁");
    is("&m", "10", "月");
    is("%d", "16", "日");
    is("&h", " 9", "時 12 時間（& は 1 桁の前に空白）");
    is("%H", "09", "時 24 時間（% は 0）");
    is("$H", "9 ", "（$ は 1 桁の後に空白）");
    is("%M", "05", "分");
    is("&S", " 7", "秒");
    is("%ma", "OCT", "月の英字");
    is("&wa", "FRI", "曜日の英字");
    is("&w", "\x8b\xe0", "曜日（金）");
    is("&n", "AM", "AM");
    is("&N", "\x91\x4f", "前");
    is("&E", " 8", "元号の年（令和 8）");
    is("%E", "08", "  % なら 0 を前に");
    is("&Y", "38", "Y は平成の年");
    is("&G\x82\x66", "\x97\xdf\x98\x61", "元号の名（令和）");
    is("&G\x82\x66\x82\x64", "\x97\xdf\x98\x61 8", "名＋年");
    is("&G\x82\x66\x82\x64\x82\x64", "\x97\xdf\x98\x61 8\x94\x4e", "名＋年＋「年」");
    is("&j", "2026/10/16", "日付の一括（j）");
    is("&J", "\x97\xdf\x98\x61" "8\x94\x4e" "10\x8c\x8e" "16\x93\xfa", "日付の一括（J）");
    jw_umekomi_clock(at_local(2026, 10, 16, 15, 30, 0));
    is("&h", " 3", "午後の 12 時間表示");
    is("&n", "PM", "PM");
    is("&N", "\x8c\xe3", "後");
    jw_umekomi_clock(at_local(2019, 4, 30, 12, 0, 0));
    is("&G\x82\x66\x82\x64\x82\x64", "\x95\xbd\x90\xac" "31\x94\x4e", "2019-04-30 は平成31年");
    jw_umekomi_clock(at_local(2019, 5, 1, 12, 0, 0));
    is("&E", "\x8c\xb3", "令和元年は「元」");
    is("&J", "\x97\xdf\x98\x61\x8c\xb3\x94\x4e 5\x8c\x8e 1\x93\xfa", "令和元年 5月 1日");
    jw_umekomi_clock(now);

    /* ---- ファイル名 ---- */
    is("%f", "A-1001 \x82\x51\x8a\x4b \x8f\xda\x8d\xd7.jww", "%f は拡張子付き");
    is("&f", "A-1001 \x82\x51\x8a\x4b \x8f\xda\x8d\xd7", "&f は拡張子なし");
    is("&F", "C:\\prj\\\x95\x5c\x8e\xa6\\sub\\A-1001 \x82\x51\x8a\x4b \x8f\xda\x8d\xd7.jww",
       "&F はフルパス");
    is("&F1", "sub", "&F1 は置かれたフォルダ");
    is("&F2", "\x95\x5c\x8e\xa6", "&F2 は一つ上（「表」の後ろの字の 0x5c を区切りにしない）");
    is("&fs1", "A-1001", "&fs1");
    is("&fs2", "\x82\x51\x8a\x4b", "&fs2");
    is("&fs3", "\x8f\xda\x8d\xd7", "&fs3");
    is("%f3", "A-1", "%f3 は頭 3 字");
    is("%f8", "A-1001 \x82\x51", "  字で数える（二バイト字も 1 字）");

    /* ---- 保存日時（= _） ---- */
    same("=F", "保存日時が分からなければ置かない");
    jw_umekomi_saved(at_local(2026, 3, 5, 8, 9, 10));
    is("=F", "2026/03/05 08:09:10", "=F は保存の日付と時刻");
    is("=f", "2026/03/05", "=f は日付だけ");
    is("_f", "2026/ 3/ 5", "_f は 1 桁の前に空白");
    is("=m", "03", "=m は保存の月");
    is("_d", " 5", "_d");
    jw_umekomi_doc("", "");
    same("=f", "ファイル名が無ければ = は置かない");
    same("%f", "  %f も");
    jw_umekomi_doc("", "a.jww");
    jw_umekomi_saved(0);

    /* ---- 縮尺 ---- */
    is("%SS", "1/50", "%SS");
    is("%ss", "50", "%ss");
    is("%SP", "1/50", "%SP（印刷倍率 doc+0x2fa0 は 1）");
    oo.lgroup = 1;
    is("%SS", "2/1", "1 より小さい縮尺は 2/1");
    oo.lgroup = 2;
    is("%ss", "3", "1/3 の逆数は 3");
    oo.lgroup = 3;
    is("%SS", "1/1.5", "1.5");
    oo.lgroup = 0;

    /* ---- 置かないもの ---- */
    same("ab", "1 字目が記号でなければ そのまま");
    same("%z", "知らない字");
    /* 続けて書いたもの: ヘルプは「無効」と言うが、FUN_00490050 は 3 字目から
       後ろを見ないので 年だけになる（続きは消える） */
    is("%y&m", "26", "続けて書いたものは 2 字目だけが効く");
    same("%y1", "3 字目に数のつく年");
    same("%mm", "ファイルメモ（移植は持たない）");
    same("&T", "作図時間（移植は数えない）");
    same("%yyyyyyyy", "9 バイト以上");
    same("%", "1 字");

    /* ---- 刷るとき（PDF）と画面（2531） ---- */
    {
        jw_drawing *d;
        jw_obj *o;
        unsigned char *pdf;
        long n;

        app_resize(1264, 741);
        app_new();
        d = (jw_drawing *)app_drawing();
        o = jw_add(d, JW_MOJI);
        o->text = jw_add_str(d, "%y");
        o->d[0] = 0.0;
        o->d[1] = 0.0;
        o->d[2] = 10.0;
        o->d[3] = 0.0;
        o->d[4] = o->d[5] = 5.0;
        o->color = 2;
        d->ndrawn = d->nobj;
        pdf = jw_plot_pdf(d, 0, &n);
        ck(pdf && pdf_has(pdf, n, "26") && !pdf_has(pdf, n, "%y"),
           "PDF には置き換えた字が出る");
        free(pdf);
        ck(jw_draw_text_subst == 0, "既定（2531 切）は画面では置き換えない");
        ck(kh_press(1, 2531), "一般(2) の 埋め込み文字を画面にも を押す");
        hit(1);
        ck(!app_kihon_open() && jw_umekomi_screen == 1 &&
           jw_draw_text_subst == jw_umekomi_screen_hook, "  OK で画面にも置き換える");
        kh_press(1, 2531);
        hit(1);
        ck(jw_draw_text_subst == 0, "  もう一度押して OK で戻る");
    }

    printf("%s\n", fails ? "FAILED" : "all ok");
    return fails != 0;
}
