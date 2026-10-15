/* 埋め込み文字の置き換え -- see src/umekomi.h.
 *
 * これは src/plot.c が #include して一緒に作る（ビルドの一覧を触らずに
 * 済むように。plot.c はどのビルドにも入っている）。
 *
 * 原典 FUN_00490050（12 KB、字の定数は objdump の即値から .rdata を引いて
 * 読んだ）。引数は 字（CString）・長さ（CP932 のバイト数、2..8）。
 *
 *  - 1 字目が = _ $ % & でなければ置かない（0x4900b1〜）。
 *  - 時刻は FUN_00493240: 1 字目が = か _ なら **ファイルの保存日時**
 *    （図面のありか doc+0x16d8 が空なら置かない、FUN_004de030）、
 *    ほかは今の時刻（_time64 → CTime、ローカル時刻）。
 *  - 長さ 4 で 2・3 字目が "fs" なら &fsN（1 字目が & でなければ置かない）:
 *    拡張子なしのファイル名を半角空白で区切った N 個目（N は 4 字目の
 *    %x、1..15）。区切りが尽きたら残りをそのまま（0x4903ae〜0x4905de）。
 *  - 1 字目が % で長さ 3:
 *      %fN  拡張子なしのファイル名の頭 N 字（N は %x で 1..15。CString は
 *           UTF-16 なので字数）
 *      %mm・%m1・%m2  ファイルメモ（doc+0x2c8）。**移植は図面のメモを
 *           持っていないので置かない**
 *      %ss・%SS・%sp・%SP（3 字目は s p S P のどれか）: その文字のレイヤ
 *           グループの縮尺 doc+0x24f0[+0x2f]。1e-5 未満なら置かない、1 未満なら
 *           逆数にして「%lg/1」、ほかは「1/%lg」（2 字目が s なら数だけ）。
 *           10 未満は 0.01 に、10 以上は 0.1 に丸める。3 字目が p・P で
 *           刷っているときは doc+0x2fa0 で割る（0x490f36）が、doc+0x2fa0 は
 *           ファイルから読むだけ（0x577d70、新規は 1.0 @0x4b3137）で移植は
 *           読んでいないので 1 として扱う
 *  - 長さ 3 の 3 字目は 1..9（J1..J9・F1..F9 の数）か a（ma・wa）。ほかの
 *    3 字目なら置かない。数があって 2 字目が j J F でなければ置かない。
 *  - 2 字目で（0x49140c〜）:
 *      y 西暦の下 2 桁、Y 平成の年（年 − 1988）、E・G 元号の年（令和は
 *      年×100＋月 ≥ 201905 から、年 − 2018。平成は − 1988。1 なら「元」）、
 *      m 月（長さ 3 なら JAN..DEC、字列 6243..）、d 日。m 以外は長さ 3 なら
 *      置かない。
 *      h 時（12 時間）、H 時、M 分、S 秒（長さ 3 なら置かない）。
 *      w・W 曜日（長さ 3 なら SUN..SAT 6257..、ほかは 日..土 6264..。
 *      表は FUN_004df... の作り 0x4dfc98〜で +0x32e4 の 1..7 と 11..17）。
 *      n 「AM」「PM」、N 「前」「後」（字列 5280・5281）。
 *      F（1 字目が = _ でない）: フルパス。長さ 4 以上は置かない。
 *        F1..F9 は 末尾から '\' を N 回切った残りの最後の名前（上へ数えて
 *        N 個目のフォルダ）。
 *      f（1 字目が = _ でない、長さ 2）: 1 字目が % なら拡張子付きの名前
 *        （FUN_0044eff0）、ほかは拡張子なし（FUN_0044f150）。
 *      f・F（1 字目が = _）: 保存日時の「年/月/日」（年は %d、月日は %02d、
 *        _ なら 10 未満は % d。長さ 3 なら月は JAN..）、F は後ろに
 *        「 %02d:%02d:%02d」。
 *      j・J: 「年/月/日」（j、年は西暦）か「元号xx年xx月xx日」（J）。月日は
 *        %d で 10 未満は % d。J1..J9 は均等割付けの広げ（下の残し）。
 *      T 作図時間（doc+0x398）。**移植は作図時間を数えていないので置かない**
 *  - 数の置き方（0x492cf8）: 10 未満なら & _ は「% d」、% = は「%02d」、
 *    $ は「%d 」、−999 は「元」。10 以上は「%d」。そのあと 2 字目からが
 *    「GＧ」なら元号の名、「GＧＥ」なら 名＋数、「GＧＥＥ」なら 名＋数＋年。
 *
 * **残したもの**: ファイルメモ (%mm %m1 %m2)、作図時間 (&T)、「%%」で始まる
 * 字（doc+0x821c の文字ファイルから引く FUN_0048fd50）、J1..J9 の均等割付け
 * （FUN_00490050 が param_6 に返す (n−1+N)/(n−1) を 原典の描き手が字の送りに
 * 掛ける 0x4858f4。移植の字の描き手に送りの倍率が無い）、印刷の命令の中で
 * 画面も置き換えること（doc+0x8558）。
 */
#include "umekomi.h"

#include <stdio.h>
#include <string.h>

int jw_umekomi_screen;

static char um_dir[520], um_name[260];
static time_t um_saved, um_clock;
static char um_out[600];

void jw_umekomi_doc(const char *dir, const char *name)
{
    snprintf(um_dir, sizeof um_dir, "%s", dir ? dir : "");
    snprintf(um_name, sizeof um_name, "%s", name ? name : "");
}

void jw_umekomi_saved(time_t t)
{
    um_saved = t;
}

time_t jw_umekomi_saved_at(void)
{
    return um_saved;
}

void jw_umekomi_clock(time_t t)
{
    um_clock = t;
}

static int um_lead(unsigned char c)
{
    return (c >= 0x81 && c <= 0x9f) || (c >= 0xe0 && c <= 0xfc);
}

/* i 字目の先頭のバイト位置（字が尽きれば -1） */
static int um_at(const char *s, int i)
{
    int k = 0;

    while (s[k] && i > 0) {
        k += (um_lead((unsigned char)s[k]) && s[k + 1]) ? 2 : 1;
        i--;
    }
    return (i == 0 && s[k]) ? k : -1;
}

/* 最後の c の位置（二バイト字の後ろの字は数えない）、無ければ -1 */
static int um_rfind(const char *s, char c)
{
    int k = 0, r = -1;

    while (s[k]) {
        if (s[k] == c)
            r = k;
        k += (um_lead((unsigned char)s[k]) && s[k + 1]) ? 2 : 1;
    }
    return r;
}

static int um_find(const char *s, char c)
{
    int k = 0;

    while (s[k]) {
        if (s[k] == c)
            return k;
        k += (um_lead((unsigned char)s[k]) && s[k + 1]) ? 2 : 1;
    }
    return -1;
}

/* doc+0x16d8: 図面のフルパス */
static void um_path(char *p, int cap)
{
    if (!um_name[0])
        p[0] = 0;
    else if (!um_dir[0])
        snprintf(p, (size_t)cap, "%s", um_name);
    else {
        size_t n = strlen(um_dir);
        int sep = um_dir[n - 1] == '\\' || um_dir[n - 1] == '/';

        snprintf(p, (size_t)cap, "%s%s%s", um_dir, sep ? "" : "\\", um_name);
    }
}

/* FUN_0044eff0: 最後の '\' の後ろ。FUN_0044f150: それから最後の '.' の前
   （'.' が頭なら切らない） */
static void um_base(const char *path, int noext, char *o, int cap)
{
    int k = um_rfind(path, '\\');

    if (k < 0)
        k = um_rfind(path, '/');        /* ブラウザ・ネイティブの '/' も */
    snprintf(o, (size_t)cap, "%s", k >= 0 && path[k + 1] ? path + k + 1 : path);
    if (noext) {
        int e = um_rfind(o, '.');

        if (e > 0)
            o[e] = 0;
    }
}

static int um_hex(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return 0;
}

static const char *const UM_MON[13] = {
    "/", "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP",
    "OCT", "NOV", "DEC"
};
static const char *const UM_WA[8] = {
    "", "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"
};
static const char *const UM_WJ[8] = {
    "", "\x93\xfa", "\x8c\x8e", "\x89\xce", "\x90\x85", "\x96\xd8", "\x8b\xe0",
    "\x93\x79"                          /* 日 月 火 水 木 金 土 */
};
#define UM_REIWA "\x97\xdf\x98" "a"     /* 令和 */
#define UM_HEISEI "\x95\xbd\x90\xac"    /* 平成 */
#define UM_GAN "\x8c\xb3"               /* 元 */
#define UM_NEN "\x94N"                  /* 年 */
#define UM_TSUKI "\x8c\x8e"             /* 月 */
#define UM_HI "\x93\xfa"                /* 日 */

/* 0x492cf8: 数の置き方 */
static void um_num(char c0, int v, char *o, int cap)
{
    if (v < 10) {
        if (c0 == '&' || c0 == '_')
            snprintf(o, (size_t)cap, "% d", v);
        else if (c0 == '%' || c0 == '=')
            snprintf(o, (size_t)cap, "%02d", v);
        else
            snprintf(o, (size_t)cap, "%d ", v);
        if (v == -999)
            snprintf(o, (size_t)cap, "%s", UM_GAN);
    } else
        snprintf(o, (size_t)cap, "%d", v);
}

static int um_do(const jw_drawing *d, const jw_obj *o, const char *s,
                 int printing, char *out, int cap)
{
    int n = (int)strlen(s), k2, k3, J = 0, v = 0, reiwa;
    char c0, c1, c2 = 0, path[800], name[300];
    const char *rest;
    time_t t;
    struct tm tmv, *tp;
    int year, mon, day, hour, min, sec, wday;

    if (n < 2 || n > 8)
        return 0;
    c0 = s[0];
    if (!strchr("=_$%&", c0) || !c0)
        return 0;
    c1 = s[1];
    rest = s + 1;
    k2 = um_at(s, 2);
    k3 = um_at(s, 3);
    if (k2 >= 0)
        c2 = s[k2];
    um_path(path, sizeof path);

    /* FUN_00493240 */
    if (c0 == '=' || c0 == '_') {
        if (!path[0] || !um_saved)
            return 0;
        t = um_saved;
    } else
        t = um_clock ? um_clock : time(0);
    tp = localtime(&t);
    if (!tp)
        return 0;
    tmv = *tp;
    year = tmv.tm_year + 1900;
    mon = tmv.tm_mon + 1;
    day = tmv.tm_mday;
    hour = tmv.tm_hour;
    min = tmv.tm_min;
    sec = tmv.tm_sec;
    wday = tmv.tm_wday + 1;             /* CTime::GetDayOfWeek: 1 = 日 */

    /* &fsN */
    if (n == 4 && rest[0] == 'f' && rest[1] == 's') {
        int N, sp, i;
        char w[300];

        if (c0 != '&')
            return 0;
        N = k3 >= 0 ? um_hex(s[k3]) : 0;
        if (N < 1 || N > 15)
            return 0;
        um_base(path, 1, w, sizeof w);
        sp = um_find(w, ' ');
        for (i = 1; i < N; i++) {
            memmove(w, w + sp + 1, strlen(w + sp + 1) + 1);
            sp = um_find(w, ' ');
            if (sp < 0)
                break;
        }
        if (sp > 0)
            w[sp] = 0;
        snprintf(out, (size_t)cap, "%s", w);
        return 1;
    }

    if (c0 == '%' && n == 3) {
        if (c1 == 'f') {
            int N = um_hex(c2), e;

            if (!path[0] || N < 1 || N > 15)
                return 0;
            um_base(path, 1, name, sizeof name);
            if (!name[0])
                return 0;
            e = um_at(name, N);
            if (e >= 0)
                name[e] = 0;
            snprintf(out, (size_t)cap, "%s", name);
            return 1;
        }
        if (c1 == 'm' && (c2 == 'm' || c2 == '1' || c2 == '2'))
            return 0;                   /* ファイルメモ: 移植は持たない */
        if (c1 == 's' || c1 == 'S') {
            double sc;
            int inv;

            if (!strchr("spSP", c2) || !c2)
                return 0;
            if (!d || !o || o->lgroup > 15)
                return 0;
            sc = d->group[o->lgroup].scale;
            if (sc < 1e-5)
                return 0;
            inv = sc < 1.0;
            if ((c2 == 'p' || c2 == 'P') && printing)
                sc /= 1.0;              /* doc+0x2fa0（上の注） */
            if (inv)
                sc = 1.0 / sc;
            if (sc < 10.0)
                sc = (double)(int)(sc * 100.0 + 0.5) / 100.0;
            else
                sc = (double)(int)(sc * 10.0 + 0.5) / 10.0;
            if (c1 == 's')
                snprintf(out, (size_t)cap, "%g", sc);
            else
                snprintf(out, (size_t)cap, inv ? "%g/1" : "1/%g", sc);
            return 1;
        }
    }

    if (n == 3) {
        if (c2 >= '1' && c2 <= '9')
            J = c2 - '0';
        else if (c2 != 'a')
            return 0;
        if (J && c1 != 'j' && c1 != 'J' && c1 != 'F')
            return 0;
    }

    reiwa = year * 100 + mon >= 201905;
    if (strchr("yYmdEG", c1) && c1) {
        int yy = year;

        if (yy >= 2000)
            yy -= 2000;
        while (yy >= 100)
            yy -= 100;
        if (c1 == 'y')
            v = yy;
        if (c1 == 'Y')
            v = year - 1988;
        if (c1 == 'E' || c1 == 'G') {
            v = reiwa ? year - 2018 : year - 1988;
            if (v == 1)
                v = -999;
        }
        if (c1 == 'm') {
            v = mon;
            if (n == 3) {
                snprintf(out, (size_t)cap, "%s", UM_MON[mon]);
                return 1;
            }
        } else if (n == 3)
            return 0;
        if (c1 == 'd')
            v = day;
    } else if (strchr("hHMS", c1) && c1) {
        if (n == 3)
            return 0;
        if (c1 == 'h') {
            v = hour;
            if (v >= 12)
                v -= 12;
        }
        if (c1 == 'H')
            v = hour;
        if (c1 == 'M')
            v = min;
        if (c1 == 'S')
            v = sec;
    } else if (c1 == 'w' || c1 == 'W') {
        if (wday < 1 || wday > 7)
            return 0;
        snprintf(out, (size_t)cap, "%s", n == 3 ? UM_WA[wday] : UM_WJ[wday]);
        return 1;
    } else if (c1 == 'n' || c1 == 'N') {
        if (n == 3)
            return 0;
        if (hour < 12)
            snprintf(out, (size_t)cap, "%s", c1 == 'n' ? "AM" : "\x91O");
        else
            snprintf(out, (size_t)cap, "%s", c1 == 'n' ? "PM" : "\x8c\xe3");
        return 1;
    } else if (c0 != '=' && c0 != '_' && c1 == 'F') {
        int i, k;

        if (n >= 4 || !path[0])
            return 0;
        snprintf(out, (size_t)cap, "%s", path);
        if (J < 1 || J > 9)
            return 1;
        k = um_rfind(out, '\\');
        for (i = 1; i <= J; i++) {
            if (k >= 0)
                out[k] = 0;             /* Left(k)。k < 0 なら原典も空になる */
            else
                out[0] = 0;
            k = um_rfind(out, '\\');
            if (k < 0)
                break;
        }
        memmove(out, out + k + 1, strlen(out + k + 1) + 1);
        return 1;
    } else if (c0 != '=' && c0 != '_' && c1 == 'f') {
        if (n == 3 || !path[0])
            return 0;
        um_base(path, c0 != '%', out, cap);
        return 1;
    } else if ((c0 == '=' || c0 == '_') && (c1 == 'f' || c1 == 'F')) {
        char ys[16], ms[16], ds[16];

        snprintf(ys, sizeof ys, "%d", year);
        snprintf(ms, sizeof ms, "%02d", mon);
        snprintf(ds, sizeof ds, "%02d", day);
        if (c0 == '_' && mon < 10)
            snprintf(ms, sizeof ms, "% d", mon);
        if (c0 == '_' && day < 10)
            snprintf(ds, sizeof ds, "% d", day);
        if (n == 3 && mon >= 1 && mon <= 12)
            snprintf(ms, sizeof ms, "%s", UM_MON[mon]);
        snprintf(out, (size_t)cap, "%s/%s/%s", ys, ms, ds);
        if (c1 == 'F') {
            size_t m = strlen(out);

            snprintf(out + m, (size_t)cap - m, " %02d:%02d:%02d", hour, min, sec);
        }
        return 1;
    } else if (c1 == 'j' || c1 == 'J') {
        char ys[16], ms[16], ds[16];
        int y = year;

        if (c1 == 'J') {
            y = reiwa ? year - 2018 : year - 1988;
            if (y == 1)
                y = -999;
        }
        snprintf(ys, sizeof ys, "%d", y);
        if (y == -999)
            snprintf(ys, sizeof ys, "%s", UM_GAN);
        snprintf(ms, sizeof ms, mon < 10 ? "% d" : "%d", mon);
        snprintf(ds, sizeof ds, day < 10 ? "% d" : "%d", day);
        if (c1 == 'J')
            snprintf(out, (size_t)cap, "%s%s" UM_NEN "%s" UM_TSUKI "%s" UM_HI,
                     reiwa ? UM_REIWA : UM_HEISEI, ys, ms, ds);
        else
            snprintf(out, (size_t)cap, "%s/%s/%s", ys, ms, ds);
        return 1;
    } else
        return 0;                       /* T（作図時間）ほか */

    um_num(c0, v, out, cap);
    {
        const char *era = reiwa ? UM_REIWA : UM_HEISEI;
        char num[32];

        snprintf(num, sizeof num, "%s", out);
        if (!strcmp(rest, "G\x82\x66"))
            snprintf(out, (size_t)cap, "%s", era);
        else if (!strcmp(rest, "G\x82\x66\x82\x64"))
            snprintf(out, (size_t)cap, "%s%s", era, num);
        else if (!strcmp(rest, "G\x82\x66\x82\x64\x82\x64"))
            snprintf(out, (size_t)cap, "%s%s" UM_NEN, era, num);
    }
    return 1;
}

const char *jw_umekomi_text(const jw_drawing *d, const jw_obj *o,
                            const char *s, int printing)
{
    if (!s || !s[0] || !s[1])
        return s;
    if (um_do(d, o, s, printing, um_out, sizeof um_out))
        return um_out;
    return s;
}

const char *jw_umekomi_print_hook(const jw_drawing *d, const jw_obj *o,
                                  const char *s)
{
    return jw_umekomi_text(d, o, s, 1);
}

const char *jw_umekomi_screen_hook(const jw_drawing *d, const jw_obj *o,
                                   const char *s)
{
    return jw_umekomi_text(d, o, s, 0);
}
