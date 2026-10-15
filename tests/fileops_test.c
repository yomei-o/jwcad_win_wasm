/* ファイル操作・図面情報コピー・レイヤ一覧（src/fileops.h・src/fonative.h）。
 *
 *   sh tools/qtest.sh fileops
 *
 * 図面情報コピー は文字列の形（-P の五つ、-L の 91 字）を、一括変換 は
 * バイトの変換を、ファイルの名前変更・削除・属性変更・一括変換 は
 * tmp/fo_t の下に作った使い捨てのファイルだけで確かめる（窓の問いは差し替え）。
 * レイヤ一覧 は升目の右押しで書込、左押しで状態が回り、札の左押しで名前。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "../src/app.h"
#include "../src/ui.h"
#include "../src/cmd.h"

#define FO_TEST_ONLY
#include "../src/fonative.h"
#include "png.h"

static int fails;

static void ck(int ok, const char *what)
{
    printf("%-4s %s\n", ok ? "ok" : "BAD", what);
    if (!ok)
        fails++;
}

/* ---- 窓の問いの差し替え ---- */
static int ask_answer = IDOK, ask_count;
static wchar_t ask_text[1024];

static int fake_ask(HWND w, const wchar_t *text, UINT type)
{
    (void)w;
    (void)type;
    ask_count++;
    lstrcpynW(ask_text, text, 1024);
    return ask_answer;
}

static const wchar_t *name_answer;
static wchar_t name_label[512];

static int fake_name(HWND w, const wchar_t *cap, const wchar_t *label,
                     const wchar_t *in, wchar_t *out, int n)
{
    (void)w;
    (void)cap;
    (void)in;
    lstrcpynW(name_label, label, 512);
    if (!name_answer)
        return 0;
    lstrcpynW(out, name_answer, n);
    return 1;
}

static jw_drawing *drw(void)
{
    return (jw_drawing *)app_drawing();
}

static int wg_of(const jw_drawing *d)
{
    int i, wg = 0;

    for (i = 0; i < 16; i++)
        if (d->group[i].state == 3)
            wg = i;
    return wg;
}

/* 一本の線を引いた新しい図面 */
static void one_line(void)
{
    app_new();
    app_command(JW_CMD_SEN);
    app_press(400, 300, 0);
    app_press(700, 400, 0);
    app_key(27);
}

static void zumen_info(void)
{
    const unsigned char *b;
    long n;
    char want[200], s[1200];
    jw_drawing *d;
    int g, l;

    printf("-- 図面情報コピー (32987)\n");
    app_new();
    app_paint();
    d = drw();
    for (g = 0; g < 16; g++) {
        d->group[g].state = 0;
        for (l = 0; l < 16; l++)
            d->group[g].layer[l].state = 0;
    }
    d->group[0].state = 3;
    d->group[0].layer[0].state = 3;
    app_doc_path("C:\\work\\a.jww");
    /* 544 bit: 0 番（グループ 0 の bit0）、16 番（レイヤ 0-0 の bit0）、
       272 番・288 番（bit1）。6 bit ずつ '0' + 値 */
    memset(want, '0', 91);
    want[91] = 0;
    want[0] = '0' + 32;
    want[2] = '0' + 2;
    want[45] = '0' + 8;
    want[48] = '0' + 32;
    snprintf(s, sizeof s, "C:\\work\\a.jww -M -P0,0,1,0,0 -L%s", want);
    {
        char got[1200];

        ck(app_zumen_info(got, (int)sizeof got) && !strcmp(got, s),
           "文字列は 道 -M -P点,点,倍率,枠,枠 -L状態 の形");
        if (strcmp(got, s))
            printf("     got  %s\n     want %s\n", got, s);
    }
    {   /* 図形の控えがあっても捨てる */
        one_line();
        app_command(57634);
    }
    app_new();
    d = drw();
    for (g = 0; g < 16; g++) {
        d->group[g].state = 0;
        for (l = 0; l < 16; l++)
            d->group[g].layer[l].state = 0;
    }
    d->group[0].state = 3;
    d->group[0].layer[0].state = 3;
    ck(app_command(32987) == 1, "押すと受ける");
    ck(app_take_action() == JW_ACT_CLIP_PUT, "表側へは JW_ACT_CLIP_PUT");
    ck(jw_cmd_moji_clip(&b, &n) && n == 3 + (long)strlen(s)
       && b[0] == 0xef && !memcmp(b + 3, s, strlen(s)),
       "字の控えは BOM ＋ その文字列（UTF-8、ASCII はそのまま）");
    ck(!jw_cmd_clip_has(), "図形の控えは捨てる（EmptyClipboard と同じ）");
    app_doc_path("");
}

static void convert_bytes(void)
{
    unsigned char *jw = 0, *o = 0, *o2 = 0;
    long n = 0, on = 0, on2 = 0;
    jw_drawing d;
    int i, lines = 0;

    printf("-- 一括変換の変換（バイト）\n");
    one_line();
    ck(app_save(&jw, &n) && n > 0, "線一本の .jww");
    ck(app_fo_convert(jw, n, "jww", 2, "a.dxf", &o, &on) && on > 0
       && strstr((const char *)o, "LINE") != 0, ".jww → .dxf に LINE がある");
    free(o);
    o = 0;
    ck(app_fo_convert(jw, n, "JWW", 1, "a.jwc", &o, &on) && on > 0,
       ".jww → .jwc（拡張子の大小は見ない）");
    ck(app_fo_convert(o, on, "jwc", 0, "a.jww", &o2, &on2) && on2 > 0,
       ".jwc → .jww");
    if (o2 && jw_parse(&d, o2, on2)) {
        for (i = 0; i < d.ndrawn; i++)
            if (d.obj[i].cls == JW_SEN)
                lines++;
        jw_free(&d);
    }
    ck(lines == 1, "戻した .jww に線が一本");
    free(o);
    free(o2);
    o = o2 = 0;
    ck(app_fo_convert(jw, n, "jww", 3, "a.sfc", &o, &on) && on > 0
       && strstr((const char *)o, "ISO-10303-21") != 0, ".jww → .sfc");
    free(o);
    o = 0;
    ck(!app_fo_convert(jw, n, "jww", 4, "a.p21", &o, &on), ".p21 は書かない");
    ck(!app_fo_convert(jw, n, "jwk", 0, "a.jww", &o, &on), ".jwk は読まない");
    free(jw);
}

/* ---- tmp/fo_t の下の使い捨てのファイル ---- */
static wchar_t dir[MAX_PATH];

static void path(wchar_t *out, const wchar_t *name)
{
    swprintf(out, MAX_PATH, L"%ls\\%ls", dir, name);
}

static void put(const wchar_t *f, const unsigned char *b, long n)
{
    FILE *fp = _wfopen(f, L"wb");

    if (fp) {
        fwrite(b, 1, (size_t)n, fp);
        fclose(fp);
    }
}

static int exists(const wchar_t *f)
{
    return GetFileAttributesW(f) != INVALID_FILE_ATTRIBUTES;
}

static int is_ro(const wchar_t *f)
{
    DWORD a = GetFileAttributesW(f);

    return a != INVALID_FILE_ATTRIBUTES && (a & FILE_ATTRIBUTE_READONLY);
}

static void real_files(void)
{
    wchar_t a[MAX_PATH], b[MAX_PATH], c[MAX_PATH], x[MAX_PATH];
    unsigned char *jw = 0;
    long n = 0;

    printf("-- ファイル（tmp/fo_t の下だけ）\n");
    GetCurrentDirectoryW(MAX_PATH, dir);
    lstrcatW(dir, L"\\tmp");
    CreateDirectoryW(dir, NULL);
    lstrcatW(dir, L"\\fo_t");
    CreateDirectoryW(dir, NULL);
    path(a, L"a.jww");
    path(b, L"b.jww");
    path(c, L"b.dxf");
    path(x, L"x.jww");
    SetFileAttributesW(a, FILE_ATTRIBUTE_NORMAL);
    SetFileAttributesW(b, FILE_ATTRIBUTE_NORMAL);
    SetFileAttributesW(x, FILE_ATTRIBUTE_NORMAL);
    DeleteFileW(a);
    DeleteFileW(b);
    DeleteFileW(c);
    DeleteFileW(x);
    one_line();
    app_save(&jw, &n);
    put(a, jw, n);
    ck(exists(a) && !is_ro(a), "a.jww を作った");
    fo_ask = fake_ask;
    fo_name = fake_name;

    /* 属性変更 */
    ck(fo_toggle_ro(a) == 1 && is_ro(a), "属性変更: 読み取り専用に");
    ck(fo_toggle_ro(a) == 1 && !is_ro(a), "もう一度で外れる");
    ck(fo_toggle_ro(x) == 0, "無いファイルは 0");

    /* 名前変更 */
    name_answer = 0;
    ck(fo_rename_one(NULL, a) == 0 && exists(a), "名前の窓を取り消すと変えない");
    ck(!wcscmp(name_label, L"ファイル名変更[a.jww]"), "窓の字は ファイル名変更[名前]");
    name_answer = L"b.jww";
    ck(fo_rename_one(NULL, a) == 1 && !exists(a) && exists(b), "a.jww → b.jww");
    put(a, jw, n);
    ask_count = 0;
    ck(fo_rename_one(NULL, a) == -1 && exists(a) && ask_count == 1
       && !wcscmp(ask_text, L"ファイル名が変更できません。"),
       "あれば替えられず「ファイル名が変更できません。」");

    /* 一括変換の一つ */
    ck(fo_convert_one(NULL, b, 2, 0) == 1 && exists(c), "b.jww → b.dxf");
    ask_answer = IDCANCEL;
    ask_count = 0;
    ck(fo_convert_one(NULL, b, 2, 1) == 0 && ask_count == 1
       && wcsstr(ask_text, L"上書きしますか") != 0,
       "上書き確認: あれば問い、キャンセルで飛ばす");
    ask_count = 0;
    ck(fo_convert_one(NULL, b, 2, 0) == 1 && ask_count == 0, "上書き確認が無ければ問わない");
    ck(fo_convert_one(NULL, b, 0, 1) == 0, "同じ拡張子へは書かない");

    /* 削除 */
    ask_answer = IDNO;
    ck(fo_delete_one(NULL, a) == 0 && exists(a), "削除: いいえ なら残る");
    ck(wcsstr(ask_text, L"削除します（復活できません）。") != 0
       && wcsstr(ask_text, L"a.jww\n\n") != 0, "問いは 名前 \\n\\n 削除します（復活できません）。");
    ask_answer = IDCANCEL;
    ck(fo_delete_one(NULL, a) == -1 && exists(a), "キャンセル は -1（残りをやめる）");
    fo_toggle_ro(a);
    ask_answer = IDYES;
    ask_count = 0;
    ck(fo_delete_one(NULL, a) == 0 && exists(a) && ask_count == 1
       && !wcscmp(ask_text, L"書込み禁止ファイルです。削除できません。"),
       "読み取り専用は消さない");
    fo_toggle_ro(a);
    ck(fo_delete_one(NULL, a) == 1 && !exists(a), "はい で消える");
    ck(fo_delete_one(NULL, b) == 1 && fo_delete_one(NULL, c) == 1
       && !exists(b) && !exists(c), "後片付け");
    fo_ask = fo_ask_box;
    fo_name = fo_name_box;
    RemoveDirectoryW(dir);
    free(jw);

    printf("-- 命令\n");
    ck(app_command(32979) == 1 && app_take_action() == JW_ACT_FILEOPS
       && app_fileops_kind() == 32979, "ファイル名変更 は表側へ");
    ck(app_command(32977) == 1 && app_take_action() == JW_ACT_FILEOPS
       && app_fileops_kind() == 32977, "一括変換 も");
    ck(!app_modal(), "移植の窓は出さない");
}

static void click_pane(int i, int button, int on_label)
{
    rect_t p;

    app_laylist_pane(i, &p);
    if (on_label)
        app_press(p.x + 3 + 2, p.y + 3 + 5, button);
    else
        app_press(p.x + p.w / 2, p.y + p.h / 2, button);
}

static void laylist(void)
{
    jw_drawing *d;
    const fb_t *f;
    rect_t p;
    int wg, s0, want, i;
    const char *nm;

    printf("-- レイヤ一覧 (32917)・レイヤグループ一覧 (32916)\n");
    one_line();
    d = drw();
    wg = wg_of(d);
    ck(app_command(32917) == 1 && app_laylist_open() == 1 && app_modal(), "開く");
    ck(app_laylist_sel() == (d->group[wg].write_layer & 15), "書込レイヤを選んでいる");
    app_paint();
    f = app_fb();
    app_laylist_pane(app_laylist_sel(), &p);
    ck(f->px[(p.y + 4) * f->w + p.x + 4] == 0x646464u, "選んだ札の地は 646464");
    app_laylist_pane((app_laylist_sel() + 1) & 15, &p);
    ck(f->px[(p.y + 4) * f->w + p.x + 4] == 0xc8c8c8u, "ほかの札の地は c8c8c8");
    {   /* 線は 書込レイヤ の升目にだけ描かれる */
        int k, inked[2] = { 0, 0 };

        for (k = 0; k < 2; k++) {
            int x, y, li = k == 0 ? app_laylist_sel() : (app_laylist_sel() + 1) & 15;

            app_laylist_pane(li, &p);
            for (y = p.y + 24; y < p.y + p.h - 3; y++)
                for (x = p.x + 3; x < p.x + p.w - 3; x++)
                    if (f->px[y * f->w + x] != 0xffffffu)
                        inked[k]++;
        }
        ck(inked[0] > 0 && inked[1] == 0, "線は自分のレイヤの升目にだけ");
    }

    click_pane(5, 1, 0);
    ck((d->group[wg].write_layer & 15) == 5 && d->group[wg].layer[5].state == 3
       && app_laylist_sel() == 5, "右押しで 書込レイヤ に、選ぶ");
    s0 = d->group[wg].layer[6].state;
    want = s0 == 2 ? 0 : s0 == 0 ? 1 : 2;
    click_pane(6, 0, 0);
    ck(d->group[wg].layer[6].state == want && app_laylist_open(), "左押しで状態が一つ回る");
    click_pane(5, 0, 0);
    ck(d->group[wg].layer[5].state == 3, "書込の升目の左押しは何もしない");
    d->group[wg].layer[7].state2 = 1;   /* 保護 */
    click_pane(7, 1, 0);
    ck(app_laylist_sel() == 5 && (d->group[wg].write_layer & 15) == 5,
       "保護されたものは選ばず、書込にもならない");
    d->group[wg].layer[7].state2 = 0;

    click_pane(9, 0, 1);
    ck(app_tdlg_tpl() == 373, "札の左押しで 名前の窓 (373)");
    for (i = 0; i < 40; i++)
        app_key(8);
    app_key('A');
    app_key('B');
    app_key(13);
    nm = jw_str(d, d->group[wg].layer_name[9]);
    ck(app_tdlg_tpl() == 0 && !strcmp(nm, "AB") && app_laylist_open(),
       "打った名前になり、一覧は残る");
    click_pane(10, 0, 1);
    app_key('Z');
    app_key(27);
    ck(app_tdlg_tpl() == 0 && strcmp(jw_str(d, d->group[wg].layer_name[10]), "Z")
       && app_laylist_open(), "Esc なら名前は変えない");
    app_key(27);
    ck(!app_laylist_open() && !app_modal(), "Esc で閉じる");

    ck(app_command(32916) == 1 && app_laylist_open() == 2
       && app_laylist_sel() == wg, "グループ一覧は 書込グループ を選んで開く");
    app_paint();
    click_pane(3, 1, 0);
    ck(wg_of(d) == 3 && d->group[3].state == 3 && app_laylist_sel() == 3,
       "右押しで 書込グループ に");
    {
        rect_t r;

        /* × で閉じる（窓の右上、ui_tdlg と同じ所） */
        app_laylist_pane(3, &r);
        app_laylist_pane(0, &p);
        r.x = p.x - 2 - 8;
        r.y = p.y - 23 - 31;
        app_press(r.x + (p.w * 4 + 16) - 20, r.y + 15, 0);
    }
    ck(!app_laylist_open(), "× で閉じる");
}

/* FO_PNG があれば 見本の図面の レイヤ一覧 を tmp/fo_laylist.png に（目で見る用） */
static void dump_png(const char *jww, const char *out, int cmd)
{
    FILE *fp = fopen(jww, "rb");
    unsigned char *b;
    long n;
    const fb_t *f;

    if (!fp)
        return;
    fseek(fp, 0, SEEK_END);
    n = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (b && fread(b, 1, (size_t)n, fp) == (size_t)n && app_open(b, n)) {
        app_command(cmd);
        app_paint();
        f = app_fb();
        png_rgb(out, f->w, f->h, f->px);
        app_key(27);
    }
    free(b);
    fclose(fp);
}

int main(void)
{
    app_resize(1264, 741);
    if (getenv("FO_PNG")) {
        dump_png(getenv("FO_PNG"), "tmp/fo_laylist.png", 32917);
        dump_png(getenv("FO_PNG"), "tmp/fo_grplist.png", 32916);
        return 0;
    }
    zumen_info();
    convert_bytes();
    real_files();
    laylist();
    printf("%s\n", fails ? "SOME BAD" : "all ok");
    return fails ? 1 : 0;
}
