/* ネイティブ版のファイル操作（src/main_win32.c が #include する。windows.h・
 * commdlg.h・app.h のほかは使わないので、試験 tests/fileops_test.c も読める）。
 *
 * 逆コンパイルの読み、原典は起動していない。
 *
 * 原典の ファイル名変更 (32979, FUN_00505710)・ファイル削除 (32980,
 * FUN_00504dc0)・ファイル属性変更 (32984, FUN_00504490) は Jw の自前の
 * ファイルの窓 CPrtFileDlg（DIALOG 371、FUN_005b0590）を 0x46・0x50・0x6e で
 * DoModal し、選んだファイルを 選択確定 (1064, FUN_005b1d10) で一つずつ:
 *   0x46 名前変更  CNamaeHenkouDlg（DIALOG 373）: 見出し 0x1627
 *                  「ファイル名変更」、字は「ファイル名変更[名前]」、箱に名前。
 *                  OK で フォルダ + "\" + 箱 へ CFile::Rename（FUN_004dd2e0、
 *                  ＝ MoveFile）。替えられなければ 0x1626「ファイル名が
 *                  変更できません。」（その字を出すのは CMyFileDialog 側の
 *                  0x593963。CPrtFileDlg の catch は読み切れていない）
 *   0x50 削除      書込み禁止なら 0x1624+0x1636「書込み禁止ファイルです。
 *                  削除できません。」(MB_OK)。でなければ 名前 "\n\n" 0x1623
 *                  「削除します（復活できません）。」を MB_YESNOCANCEL で:
 *                  はい で _wremove、キャンセル で残りをやめる
 *   0x6e 属性変更  _waccess(,0) が通るものの 読み取り専用 を入れ替える
 *                  （_waccess(,2) が -1 なら _wchmod 0x180、でなければ 0x100。
 *                  移植は同じことを Get/SetFileAttributesW で）。知らせは無い
 * ファイル一括変換 (32977, FUN_00504550) は Windows の 開く（複数選択
 * 0x206）でファイルを取り、CIkkatstHenkanDialog（DIALOG 368）に 作業フォルダ
 * (2252)・変換対象ファイル (2253) を出す。変換先 (1689..1693) と 上書き確認
 * (2254) の素は 0（作り手 FUN_004cadf0）。OK で一つずつ FUN_004fba70
 * （src/fileops.h の注）、最後に記録を CEditDialog（DIALOG 363「確認」）で。
 *
 * 移植で違うところ: ファイルを選ぶのは Windows の 開く（原典も
 * DAT_00a0c7b4 が 0 でなければ そちら。印刷の ファイル連続印刷 と同じ扱い）。
 * フォルダごとの禁止（FUN_004f6b00 が読むフォルダの中の設定ファイル）は
 * 読み切れていないので見ない。一括変換は 変換元と変換先の拡張子が同じなら
 * 飛ばす（自分の上に書き直さない）、.p21 と .jwk は書き手・読み手が無いので
 * 飛ばす。
 */

#include <wchar.h>

typedef int (*fo_ask_fn)(HWND w, const wchar_t *text, UINT type);
/* 名前の窓。in に今の名前、OK なら out へ（cap 字）。1: OK */
typedef int (*fo_name_fn)(HWND w, const wchar_t *caption, const wchar_t *label,
                          const wchar_t *in, wchar_t *out, int cap);

static int fo_ask_box(HWND w, const wchar_t *text, UINT type)
{
    return MessageBoxW(w, text, L"jw_win", type);
}

static int fo_name_box(HWND w, const wchar_t *caption, const wchar_t *label,
                       const wchar_t *in, wchar_t *out, int cap);

static fo_ask_fn fo_ask = fo_ask_box;   /* 試験が差し替える */
static fo_name_fn fo_name = fo_name_box;

/* ---- 窓の型（DLGTEMPLATE を手で組む） ---------------------------------- */
typedef struct {
    short id, x, y, cx, cy;
    DWORD style;
    WORD cls;                           /* 0x80 BUTTON・0x81 EDIT・0x82 STATIC */
    const wchar_t *text;
} fo_item;

static WORD *fo_put_str(WORD *p, const wchar_t *s)
{
    do
        *p++ = (WORD)*s;
    while (*s++);
    return p;
}

static INT_PTR fo_dialog(HWND wnd, const wchar_t *caption, short cx, short cy,
                         const fo_item *it, int n, DLGPROC proc, LPARAM lp)
{
    WORD *buf = (WORD *)calloc(16384, sizeof(WORD)), *p;
    DLGTEMPLATE *t;
    INT_PTR r;
    int i;

    if (!buf)
        return -1;
    t = (DLGTEMPLATE *)buf;
    t->style = 0x80c800c0u | DS_SETFONT;
    t->cdit = (WORD)n;
    t->cx = cx;
    t->cy = cy;
    p = (WORD *)(t + 1);
    *p++ = 0;
    *p++ = 0;
    p = fo_put_str(p, caption);
    *p++ = 9;
    p = fo_put_str(p, L"ＭＳ Ｐゴシック");
    for (i = 0; i < n; i++) {
        DLGITEMTEMPLATE *d;

        if (((p - buf) & 1) != 0)
            *p++ = 0;
        d = (DLGITEMTEMPLATE *)p;
        d->style = it[i].style;
        d->dwExtendedStyle = 0;
        d->x = it[i].x;
        d->y = it[i].y;
        d->cx = it[i].cx;
        d->cy = it[i].cy;
        d->id = (WORD)it[i].id;
        p = (WORD *)(d + 1);
        *p++ = 0xffff;
        *p++ = it[i].cls;
        p = fo_put_str(p, it[i].text);
        *p++ = 0;
    }
    r = DialogBoxIndirectParamW(GetModuleHandleW(NULL), t, wnd, proc, lp);
    free(buf);
    return r;
}

/* ---- 名称変更（DIALOG 373） --------------------------------------------- */
typedef struct {
    const wchar_t *label, *in;
    wchar_t *out;
    int cap;
} fo_name_arg;

static INT_PTR CALLBACK fo_name_proc(HWND dlg, UINT msg, WPARAM wp, LPARAM lp)
{
    fo_name_arg *a = (fo_name_arg *)GetWindowLongPtrW(dlg, DWLP_USER);

    if (msg == WM_INITDIALOG) {
        SetWindowLongPtrW(dlg, DWLP_USER, lp);
        a = (fo_name_arg *)lp;
        SetDlgItemTextW(dlg, 1920, a->label);
        SetDlgItemTextW(dlg, 2214, a->in);
        SendDlgItemMessageW(dlg, 2214, EM_SETSEL, 0, -1);
        SetFocus(GetDlgItem(dlg, 2214));
        return FALSE;
    }
    if (msg == WM_COMMAND && a) {
        if (LOWORD(wp) == IDOK) {
            GetDlgItemTextW(dlg, 2214, a->out, a->cap);
            EndDialog(dlg, 1);
            return TRUE;
        }
        if (LOWORD(wp) == IDCANCEL) {
            EndDialog(dlg, 0);
            return TRUE;
        }
    }
    return FALSE;
}

static int fo_name_box(HWND w, const wchar_t *caption, const wchar_t *label,
                       const wchar_t *in, wchar_t *out, int cap)
{
    static const fo_item IT[] = {
        { 1, 130, 20, 50, 14, 0x50010001u, 0x80, L"OK" },
        { 2, 130, 38, 50, 14, 0x50010000u, 0x80, L"ｷｬﾝｾﾙ" },
        { 2214, 7, 20, 118, 13, 0x50810080u, 0x81, L"" },
        { 1920, 7, 5, 173, 10, 0x50020000u, 0x82, L"" },
    };
    fo_name_arg a;

    a.label = label;
    a.in = in;
    a.out = out;
    a.cap = cap;
    return fo_dialog(w, caption, 187, 59, IT, 4, fo_name_proc, (LPARAM)&a) == 1;
}

/* ---- 一つずつの仕事（試験はこれらを直に呼ぶ） --------------------------- */

/* 道のフォルダの長さ（最後の \ / の前まで）。無ければ -1 */
static int fo_dir_len(const wchar_t *f)
{
    int i, last = -1;

    for (i = 0; f[i]; i++)
        if (f[i] == L'\\' || f[i] == L'/')
            last = i;
    return last;
}

/* 0x6e: 1 替えた・0 無い・-1 替えられない */
static int fo_toggle_ro(const wchar_t *f)
{
    DWORD a = GetFileAttributesW(f);

    if (a == INVALID_FILE_ATTRIBUTES || (a & FILE_ATTRIBUTE_DIRECTORY))
        return 0;
    a ^= FILE_ATTRIBUTE_READONLY;
    if (!(a & ~(DWORD)FILE_ATTRIBUTE_NORMAL))
        a = FILE_ATTRIBUTE_NORMAL;
    return SetFileAttributesW(f, a) ? 1 : -1;
}

/* 0x50: 1 消した・0 消さない・-1 キャンセル（残りもやめる） */
static int fo_delete_one(HWND w, const wchar_t *f)
{
    DWORD a = GetFileAttributesW(f);
    wchar_t m[MAX_PATH * 2 + 64];
    int r;

    if (a == INVALID_FILE_ATTRIBUTES || (a & FILE_ATTRIBUTE_DIRECTORY))
        return 0;
    if (a & FILE_ATTRIBUTE_READONLY) {
        fo_ask(w, L"書込み禁止ファイルです。削除できません。", MB_OK);
        return 0;
    }
    swprintf(m, sizeof m / sizeof m[0], L"%ls\n\n削除します（復活できません）。", f);
    r = fo_ask(w, m, MB_YESNOCANCEL);
    if (r == IDYES)
        return DeleteFileW(f) ? 1 : 0;
    return r == IDCANCEL ? -1 : 0;
}

/* 0x46: 1 替えた・0 取り消した・-1 替えられなかった */
static int fo_rename_one(HWND w, const wchar_t *f)
{
    wchar_t lab[MAX_PATH + 32], nm[MAX_PATH], to[MAX_PATH * 2];
    int dl = fo_dir_len(f);
    const wchar_t *base = f + dl + 1;

    swprintf(lab, sizeof lab / sizeof lab[0], L"ファイル名変更[%ls]", base);
    nm[0] = 0;
    if (!fo_name(w, L"ファイル名変更", lab, base, nm, MAX_PATH) || !nm[0])
        return 0;
    if (dl >= 0)
        swprintf(to, sizeof to / sizeof to[0], L"%.*ls\\%ls", dl, f, nm);
    else
        swprintf(to, sizeof to / sizeof to[0], L"%ls", nm);
    if (MoveFileW(f, to))
        return 1;
    fo_ask(w, L"ファイル名が変更できません。", MB_OK);
    return -1;
}

static unsigned char *fo_read_all(const wchar_t *f, long *n)
{
    FILE *fp = _wfopen(f, L"rb");
    unsigned char *b;
    long sz;

    *n = 0;
    if (!fp)
        return NULL;
    fseek(fp, 0, SEEK_END);
    sz = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    b = sz > 0 ? (unsigned char *)malloc((size_t)sz) : NULL;
    if (b && fread(b, 1, (size_t)sz, fp) != (size_t)sz) {
        free(b);
        b = NULL;
    }
    fclose(fp);
    if (b)
        *n = sz;
    return b;
}

/* 変換先の番号（1689 から）と拡張子 */
static const wchar_t *const FO_EXT[5] = { L".jww", L".jwc", L".dxf", L".sfc", L".p21" };

/* FUN_004fba70: 1 書いた・0 飛ばした・-1 キャンセル（上書きの問いで） */
static int fo_convert_one(HWND w, const wchar_t *f, int to, int confirm)
{
    int dot = -1, dl = fo_dir_len(f), i, r = 0;
    wchar_t out[MAX_PATH * 2], m[MAX_PATH * 2 + 64];
    char ext[8], name[MAX_PATH * 2];
    unsigned char *b, *ob = NULL;
    long n, on = 0;
    FILE *fp;

    for (i = 0; f[i]; i++)
        if (f[i] == L'.')
            dot = i;
    if (dot <= dl || to < 0 || to > 4 || wcslen(f + dot) > 4)
        return 0;
    for (i = 0; f[dot + 1 + i] && i < 7; i++)
        ext[i] = (char)f[dot + 1 + i];
    ext[i] = 0;
    if (!_wcsicmp(f + dot, FO_EXT[to]))
        return 0;                       /* 自分の上には書かない */
    swprintf(out, sizeof out / sizeof out[0], L"%.*ls%ls", dot, f, FO_EXT[to]);
    if (confirm && GetFileAttributesW(out) != INVALID_FILE_ATTRIBUTES) {
        swprintf(m, sizeof m / sizeof m[0],
                 L"%ls\n\nファイルはすでに存在しています。上書きしますか？", out);
        if (fo_ask(w, m, MB_OKCANCEL) != IDOK)
            return 0;
    }
    if (!(b = fo_read_all(f, &n)))
        return 0;
    WideCharToMultiByte(932, 0, out + dl + 1, -1, name, (int)sizeof name, NULL, NULL);
    if (app_fo_convert(b, n, ext, to, name, &ob, &on) && ob && on > 0
        && (fp = _wfopen(out, L"wb")) != NULL) {
        r = fwrite(ob, 1, (size_t)on, fp) == (size_t)on;
        if (fclose(fp) != 0)
            r = 0;
    }
    free(b);
    free(ob);
    return r;
}

#ifndef FO_TEST_ONLY                    /* 試験は ここから下（開く の窓）を読まない */
/* ---- 窓とファイルの選び ------------------------------------------------- */

/* 開く（複数）。名前を並べて返す（呼び手が free）。数は *n */
static wchar_t **fo_pick(HWND wnd, const wchar_t *title, const wchar_t *filter, int *n)
{
    enum { N = 0x8000 };
    wchar_t *b = (wchar_t *)calloc(N + 2, sizeof(wchar_t)), **v = NULL, *q;
    OPENFILENAMEW o;
    int k = 0, i;
    size_t dl;

    *n = 0;
    if (!b)
        return NULL;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = b;
    o.nMaxFile = N;
    o.lpstrTitle = title;
    o.Flags = OFN_ALLOWMULTISELECT | OFN_EXPLORER | OFN_FILEMUSTEXIST
              | OFN_PATHMUSTEXIST | OFN_HIDEREADONLY | OFN_NOCHANGEDIR;
    if (!GetOpenFileNameW(&o)) {
        free(b);
        return NULL;
    }
    dl = wcslen(b);
    for (q = b + dl + 1; *q; q += wcslen(q) + 1)
        k++;
    v = (wchar_t **)calloc((size_t)(k ? k : 1), sizeof *v);
    if (!v) {
        free(b);
        return NULL;
    }
    if (k == 0) {                       /* 一つだけ: 全部の道 */
        v[0] = _wcsdup(b);
        *n = v[0] ? 1 : 0;
    } else {
        for (i = 0, q = b + dl + 1; *q; q += wcslen(q) + 1) {
            size_t l = dl + 1 + wcslen(q) + 1;
            wchar_t *s = (wchar_t *)malloc(l * sizeof(wchar_t));

            if (!s)
                continue;
            swprintf(s, l, L"%ls\\%ls", b, q);
            v[i++] = s;
        }
        *n = i;
    }
    free(b);
    return v;
}

static void fo_free(wchar_t **v, int n)
{
    int i;

    for (i = 0; i < n; i++)
        free(v[i]);
    free(v);
}

/* ファイル一括変換（DIALOG 368） */
typedef struct {
    const wchar_t *dir, *list;
    int to, confirm;
} fo_ik_arg;

static INT_PTR CALLBACK fo_ik_proc(HWND dlg, UINT msg, WPARAM wp, LPARAM lp)
{
    fo_ik_arg *a = (fo_ik_arg *)GetWindowLongPtrW(dlg, DWLP_USER);
    int i;

    if (msg == WM_INITDIALOG) {
        SetWindowLongPtrW(dlg, DWLP_USER, lp);
        a = (fo_ik_arg *)lp;
        SetDlgItemTextW(dlg, 2252, a->dir);
        SetDlgItemTextW(dlg, 2253, a->list);
        CheckRadioButton(dlg, 1689, 1693, 1689 + a->to);
        CheckDlgButton(dlg, 2254, a->confirm ? BST_CHECKED : BST_UNCHECKED);
        EnableWindow(GetDlgItem(dlg, 1693), FALSE);     /* .p21: 書き手が無い */
        return TRUE;
    }
    if (msg == WM_COMMAND && a) {
        if (LOWORD(wp) == IDOK) {
            for (i = 0; i < 5; i++)
                if (IsDlgButtonChecked(dlg, 1689 + i) == BST_CHECKED)
                    a->to = i;
            a->confirm = IsDlgButtonChecked(dlg, 2254) == BST_CHECKED;
            EndDialog(dlg, 1);
            return TRUE;
        }
        if (LOWORD(wp) == IDCANCEL) {
            EndDialog(dlg, 0);
            return TRUE;
        }
    }
    return FALSE;
}

static INT_PTR CALLBACK fo_log_proc(HWND dlg, UINT msg, WPARAM wp, LPARAM lp)
{
    if (msg == WM_INITDIALOG) {
        SetDlgItemTextW(dlg, 1491, (const wchar_t *)lp);
        return TRUE;
    }
    if (msg == WM_COMMAND && (LOWORD(wp) == IDOK || LOWORD(wp) == IDCANCEL)) {
        EndDialog(dlg, 1);
        return TRUE;
    }
    return FALSE;
}

static void fo_ikkatsu(HWND wnd)
{
    static const fo_item IK[] = {
        { 1, 149, 7, 50, 14, 0x50030001u, 0x80, L"OK" },
        { 2, 149, 24, 50, 14, 0x50010000u, 0x80, L"ｷｬﾝｾﾙ" },
        { 2253, 7, 55, 86, 95, 0x50a31884u, 0x81, L"" },
        { -1, 101, 52, 38, 98, 0x50020007u, 0x80, L"変換先" },
        { 1689, 108, 69, 28, 10, 0x50030009u, 0x80, L".jww" },
        { 1690, 108, 85, 28, 10, 0x50000009u, 0x80, L".jwc" },
        { 1691, 108, 101, 28, 10, 0x50000009u, 0x80, L".dxf" },
        { 1692, 108, 117, 28, 10, 0x50000009u, 0x80, L".sfc" },
        { 1693, 108, 133, 28, 10, 0x50000009u, 0x80, L".p21" },
        { -1, 13, 45, 69, 8, 0x50020000u, 0x82, L"変換対象ファイル" },
        { 2252, 7, 22, 119, 13, 0x50810880u, 0x81, L"" },
        { -1, 13, 13, 69, 8, 0x50020000u, 0x82, L"作業フォルダ" },
        { 2254, 145, 58, 50, 14, 0x50010003u, 0x80, L"上書き確認" },
        { -1, 149, 134, 44, 8, 0x50020001u, 0x82, L".jwk ⇒ .jws" },
    };
    static const fo_item LOG[] = {
        { 1, 286, 246, 50, 14, 0x50010001u, 0x80, L"OK" },
        { 1491, 7, 7, 329, 231, 0x50a11884u, 0x81, L"" },
    };
    fo_ik_arg a;
    wchar_t **v, dir[MAX_PATH], *list, *log;
    size_t cap = 0, ll = 0, lg = 0;
    int n, i, dl;

    v = fo_pick(wnd, L"ファイル一括変換",
                L"Jw_cad (*.jww;*.jwc;*.dxf;*.sfc)\0*.jww;*.jwc;*.dxf;*.sfc\0"
                L"All (*.*)\0*.*\0\0", &n);
    if (!v || n <= 0) {
        if (v)
            fo_free(v, n);
        return;
    }
    dl = fo_dir_len(v[0]);
    swprintf(dir, MAX_PATH, L"%.*ls", dl > 0 ? dl : 0, v[0]);
    for (i = 0; i < n; i++)
        cap += wcslen(v[i]) + 16;
    list = (wchar_t *)calloc(cap + 1, sizeof(wchar_t));
    log = (wchar_t *)calloc(cap + 32 * (size_t)n + 1, sizeof(wchar_t));
    if (!list || !log) {
        free(list);
        free(log);
        fo_free(v, n);
        return;
    }
    for (i = 0; i < n; i++)
        ll += (size_t)swprintf(list + ll, cap + 1 - ll, L"%ls\r\n", v[i] + dl + 1);
    a.dir = dir;
    a.list = list;
    a.to = 0;
    a.confirm = 0;
    if (fo_dialog(wnd, L"ファイル一括変換", 206, 157, IK,
                  (int)(sizeof IK / sizeof IK[0]), fo_ik_proc, (LPARAM)&a) == 1) {
        for (i = 0; i < n; i++) {
            int r = fo_convert_one(wnd, v[i], a.to, a.confirm);

            lg += (size_t)swprintf(log + lg, cap + 32 * (size_t)n + 1 - lg, L"%ls%ls\r\n",
                                   v[i], r > 0 ? L"" : L" ..... skip");
        }
        fo_dialog(wnd, L"確認", 343, 267, LOG, 2, fo_log_proc, (LPARAM)log);
    }
    free(list);
    free(log);
    fo_free(v, n);
}

/* JW_ACT_FILEOPS: app_fileops_kind の命令。図面は変えない（0） */
static int fo_run(HWND wnd)
{
    static const wchar_t FILTER[] =
        L"JWW Files (*.jww)\0*.jww\0"
        L"Jw_cad (*.jww;*.jwc;*.jws;*.jwk;*.dxf;*.sfc)\0*.jww;*.jwc;*.jws;*.jwk;*.dxf;*.sfc\0"
        L"All (*.*)\0*.*\0\0";
    int kind = app_fileops_kind(), n = 0, i;
    wchar_t **v;

    if (kind == 32977) {
        fo_ikkatsu(wnd);
        return 0;
    }
    v = fo_pick(wnd, kind == 32979 ? L"ファイル名変更"
                   : kind == 32980 ? L"ファイル削除"
                                   : L"ファイル読込専用属性-設定／解除", FILTER, &n);
    if (!v)
        return 0;
    for (i = 0; i < n; i++) {
        if (kind == 32979)
            fo_rename_one(wnd, v[i]);
        else if (kind == 32980) {
            if (fo_delete_one(wnd, v[i]) < 0)
                break;
        } else if (kind == 32984)
            fo_toggle_ro(v[i]);
    }
    fo_free(v, n);
    return 0;
}
#endif
