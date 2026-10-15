/* The native front end: one window, and the framebuffer put on it.
 *
 * It exists so the port can be held up against the original on the same
 * machine.  The window is sized so its *client* area matches the reference
 * screens (1264x741), which is what tools/cmp.py compares.
 *
 * Nothing is drawn with GDI except the one SetDIBitsToDevice that hands over
 * the finished picture -- if any of the frame came from a Windows control,
 * the browser build could not match it.
 */
#include <windows.h>
#include <commdlg.h>
#include <imm.h>
#include <shellapi.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "app.h"
#include "plot.h"
#include "cmd.h"
#include "image.h"
#include "cp932.h"
#include "outfont.h"
#include "gen/accel.h"
#include "gen/menu.h"

static const wchar_t CLASS_NAME[] = L"JwWinWasmPort";

/* The file the drawing came from, so 上書 knows where to put it back. */
static wchar_t current_path[MAX_PATH];
static void sync_doc(void);
static int uiscale = 1;                 /* see dpi_init */
static void autosave_clear(void);
static int print_gdi(HWND wnd);
/* The words of the program's own boxes (the question about unsaved changes and the like):
   Japanese on a Japanese Windows, English elsewhere; JW_LANG=en|ja or [ui] lang= in the ini
   decides otherwise.  The original's menus, bars and prompts are the original's and stay Japanese. */
static int english;
static const wchar_t *tr(const wchar_t *ja, const wchar_t *en)
{
    return english ? en : ja;
}
static int user_closed;                 /* closed on purpose, changes saved or thrown away */

/* Recent files and the one setting the .jwf does not carry, in
   %APPDATA%\jw_port\jw_port.ini ([moji] OutSJIS, [recent] 1..5) */
#define NRECENT 5
#define RECENT_ID 60001
static wchar_t recent[NRECENT][MAX_PATH];
static HWND main_wnd;

static int ini_path(wchar_t *p)
{
    wchar_t dir[MAX_PATH];

    if (!GetEnvironmentVariableW(L"APPDATA", dir, MAX_PATH))
        return 0;
    swprintf(p, MAX_PATH, L"%ls%cjw_port", dir, (wchar_t)92);
    CreateDirectoryW(p, NULL);
    swprintf(p, MAX_PATH, L"%ls%cjw_port%cjw_port.ini", dir, (wchar_t)92, (wchar_t)92);
    if (GetFileAttributesW(p) == INVALID_FILE_ATTRIBUTES) {
        /* a private-profile file is read in the ANSI page unless it starts with a
           UTF-16 byte order mark: with one, file names keep every character */
        FILE *f = _wfopen(p, L"wb");

        if (f) {
            fputc(0xff, f);
            fputc(0xfe, f);
            fclose(f);
        }
    }
    return 1;
}

static void ini_load(void)
{
    wchar_t p[MAX_PATH], k[8];
    int i;

    if (!ini_path(p))
        return;
    jw_moji_sjis_set(GetPrivateProfileIntW(L"moji", L"OutSJIS", 1, p));
    for (i = 0; i < NRECENT; i++) {
        swprintf(k, 8, L"%d", i + 1);
        GetPrivateProfileStringW(L"recent", k, L"", recent[i], MAX_PATH, p);
    }
}

static void ini_save(void)
{
    wchar_t p[MAX_PATH], k[8];
    int i;

    if (!ini_path(p))
        return;
    WritePrivateProfileStringW(L"moji", L"OutSJIS", jw_moji_sjis() ? L"1" : L"0", p);
    for (i = 0; i < NRECENT; i++) {
        swprintf(k, 8, L"%d", i + 1);
        WritePrivateProfileStringW(L"recent", k, recent[i][0] ? recent[i] : NULL, p);
    }
}

static HMENU build_menu(void);

static void recent_add(const wchar_t *path)
{
    int i, at = NRECENT - 1;

    for (i = 0; i < NRECENT; i++)
        if (!_wcsicmp(recent[i], path)) {
            at = i;
            break;
        }
    for (i = at; i > 0; i--)
        wcscpy(recent[i], recent[i - 1]);
    lstrcpynW(recent[0], path, MAX_PATH);
    if (main_wnd) {
        HMENU old = GetMenu(main_wnd);

        SetMenu(main_wnd, build_menu());
        if (old)
            DestroyMenu(old);
    }
}

static int load_file(const wchar_t *path)
{
    FILE *f = _wfopen(path, L"rb");
    unsigned char *b;
    long n;
    int ok = 0;

    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (b && fread(b, 1, (size_t)n, f) == (size_t)n)
        ok = app_open(b, n);
    fclose(f);
    free(b);
    if (ok) {
        lstrcpynW(current_path, path, MAX_PATH);
        recent_add(path);
        sync_doc();
    }
    return ok;
}

static int save_file(const wchar_t *path)
{
    unsigned char *b;
    long n;
    FILE *f;
    int ok;

    if (!app_save(&b, &n))
        return 0;
    {   /* what was there is kept one save back, as a .bak beside it */
        wchar_t bak[MAX_PATH + 8];

        if (GetFileAttributesW(path) != INVALID_FILE_ATTRIBUTES) {
            swprintf(bak, MAX_PATH + 8, L"%ls.bak", path);
            CopyFileW(path, bak, FALSE);
        }
    }
    f = _wfopen(path, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    ok = fwrite(b, 1, (size_t)n, f) == (size_t)n;
    fclose(f);
    free(b);
    if (ok) {
        lstrcpynW(current_path, path, MAX_PATH);
        recent_add(path);
        sync_doc();
        autosave_clear();
    }
    return ok;
}

/* Where the open drawing is, for the picture command: relative paths and the
   folder the separated pictures go to are measured from it, and a picture a
   drawing names by a relative path is looked for beside it.  (CP932, which is
   what the drawing's texts are.) */
static void sync_doc(void)
{
    char dir[MAX_PATH * 2], stem[MAX_PATH * 2];
    wchar_t w[MAX_PATH];
    int i, last = -1, dot = -1;

    lstrcpynW(w, current_path, MAX_PATH);
    for (i = 0; w[i]; i++) {
        if (w[i] == L'\\' || w[i] == L'/')
            last = i;
        if (w[i] == L'.')
            dot = i;
    }
    if (dot < last)
        dot = -1;
    {
        wchar_t t = last >= 0 ? w[last] : 0;

        if (last >= 0)
            w[last] = 0;
        WideCharToMultiByte(932, 0, last >= 0 ? w : L"", -1, dir, (int)sizeof dir, NULL, NULL);
        if (last >= 0)
            w[last] = t;
    }
    {
        wchar_t nm[MAX_PATH];

        lstrcpynW(nm, w + (last >= 0 ? last + 1 : 0), MAX_PATH);
        for (i = 0; nm[i]; i++)
            ;
        while (i > 0 && nm[i - 1] != L'.')
            i--;
        if (i > 0)
            nm[i - 1] = 0;
        WideCharToMultiByte(932, 0, nm, -1, stem, (int)sizeof stem, NULL, NULL);
    }
    (void)dot;
    app_doc(dir, stem);
    if (main_wnd) {                     /* the window's own title (task bar, Alt+Tab) */
        wchar_t title[MAX_PATH + 32];
        const wchar_t *nm = w + (last >= 0 ? last + 1 : 0);

        if (*nm)
            swprintf(title, MAX_PATH + 32, L"%ls - jw_win (port)", nm);
        else
            lstrcpynW(title, L"jw_win (port)", MAX_PATH + 32);
        SetWindowTextW(main_wnd, title);
    }
}

/* Picture files by the name a drawing keeps them under: an absolute path as
   it is, a relative one beside the drawing. */
static unsigned char *img_loader(const char *name, long *n)
{
    wchar_t wn[MAX_PATH], full[MAX_PATH];
    FILE *f;
    unsigned char *b;

    if (!strncmp(name, "%temp%", 6))
        return 0;
    MultiByteToWideChar(932, 0, name, -1, wn, MAX_PATH);
    if ((wn[0] && wn[1] == L':') || wn[0] == L'\\' || wn[0] == L'/' || !current_path[0]) {
        lstrcpynW(full, wn, MAX_PATH);
    } else {
        int i, last = -1;

        lstrcpynW(full, current_path, MAX_PATH);
        for (i = 0; full[i]; i++)
            if (full[i] == L'\\' || full[i] == L'/')
                last = i;
        full[last + 1] = 0;
        lstrcatW(full, wn);
    }
    f = _wfopen(full, L"rb");
    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    *n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)(*n > 0 ? *n : 1));
    if (!b || fread(b, 1, (size_t)*n, f) != (size_t)*n) {
        free(b);
        b = 0;
    }
    fclose(f);
    return b;
}

/* Insert picture: a bitmap, JPEG or PNG (the original's open dialog lists the
   first and, if Susie is there, more) */
static int ask_image(HWND wnd)
{
    static const wchar_t filter[] = L"Bitmap, JPEG, PNG\0*.bmp;*.jpg;*.jpeg;*.png\0"
                                    L"Bitmap (*.bmp)\0*.bmp\0JPEG (*.jpg)\0*.jpg;*.jpeg\0"
                                    L"PNG (*.png)\0*.png\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    char name[MAX_PATH * 2];
    unsigned char *b;
    long n;
    FILE *f;
    int ok = 0;

    path[0] = 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    if (!GetOpenFileNameW(&o))
        return 0;
    f = _wfopen(path, L"rb");
    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)(n > 0 ? n : 1));
    if (b && fread(b, 1, (size_t)n, f) == (size_t)n) {
        WideCharToMultiByte(932, 0, path, -1, name, (int)sizeof name, NULL, NULL);
        ok = app_image(name, b, n);
    }
    fclose(f);
    free(b);
    return ok;
}

/* Separate embedded pictures: the files go into <drawing folder>\<name>~(bunri gazou) */
static int save_images(HWND wnd)
{
    int i, ok = 0;
    const char *nm;
    const unsigned char *b;
    long n;
    wchar_t dir[MAX_PATH], stem[MAX_PATH], full[MAX_PATH], wn[MAX_PATH];

    (void)wnd;
    if (!current_path[0])
        return 0;
    lstrcpynW(dir, current_path, MAX_PATH);
    for (i = 0; dir[i]; i++)
        ;
    while (i > 0 && dir[i - 1] != L'\\' && dir[i - 1] != L'/')
        i--;
    lstrcpynW(stem, dir + i, MAX_PATH);
    dir[i] = 0;
    for (i = 0; stem[i]; i++)
        ;
    while (i > 0 && stem[i - 1] != L'.')
        i--;
    if (i > 0)
        stem[i - 1] = 0;
    wsprintfW(full, L"%s%s\uff5e\u5206\u96e2\u753b\u50cf", dir, stem);
    CreateDirectoryW(full, NULL);
    for (i = 0; app_image_out(i, &nm, &b, &n); i++) {
        wchar_t path[MAX_PATH];
        FILE *f;

        MultiByteToWideChar(932, 0, nm, -1, wn, MAX_PATH);
        wsprintfW(path, L"%s\\%s", full, wn);
        f = _wfopen(path, L"wb");
        if (!f)
            continue;
        fwrite(b, 1, (size_t)n, f);
        fclose(f);
        ok = 1;
    }
    return ok;
}

/* DXF形式で保存: the same drawing through src/dxf.c.  The name it offers
 * is the open file's with .dxf in place of .jww, and writing it does not make
 * the DXF "the file" -- 上書 still goes to the .jww it came from. */
static int save_dxf(HWND wnd)
{
    static const wchar_t filter[] = L"DXF (*.dxf)\0*.dxf\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    unsigned char *b;
    long n;
    FILE *f;
    int ok, i;

    lstrcpynW(path, current_path, MAX_PATH);
    for (i = 0; path[i]; i++)
        ;
    while (i > 0 && path[i] != L'.' && path[i] != L'\\' && path[i] != L'/')
        i--;
    if (i > 0 && path[i] == L'.')
        path[i] = 0;
    if (!app_save_dxf(&b, &n))
        return 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.lpstrDefExt = L"dxf";
    o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&o)) {
        free(b);
        return 0;
    }
    f = _wfopen(path, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    ok = fwrite(b, 1, (size_t)n, f) == (size_t)n;
    fclose(f);
    free(b);
    return ok;
}

/* 「JWC形式で保存」, which goes the same way as a DXF: the bytes first and
 * the dialog after, because nothing in a JWC is the name it is saved under. */
static int save_jwc(HWND wnd)
{
    static const wchar_t filter[] = L"JWC (*.jwc)\0*.jwc\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    unsigned char *b;
    long n;
    FILE *f;
    int ok, i;

    lstrcpynW(path, current_path, MAX_PATH);
    for (i = 0; path[i]; i++)
        ;
    while (i > 0 && path[i] != L'.' && path[i] != L'\\' && path[i] != L'/')
        i--;
    if (i > 0 && path[i] == L'.')
        path[i] = 0;
    if (!app_save_jwc(&b, &n))
        return 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.lpstrDefExt = L"jwc";
    o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&o)) {
        free(b);
        return 0;
    }
    f = _wfopen(path, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    ok = fwrite(b, 1, (size_t)n, f) == (size_t)n;
    fclose(f);
    free(b);
    return ok;
}

/* 環境設定ファイル 書出し: the dialog asks for a .jwf (the original's own
 * filter is "Jwf|*.JWF|JwL|*.JWL|"); the file's first line holds its name, so
 * the name is asked first and the text made after. */
static int save_env(HWND wnd)
{
    static const wchar_t filter[] = L"Jwf (*.jwf)\0*.jwf\0JwL (*.jwl)\0*.jwl\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    char nm[MAX_PATH * 2];
    unsigned char *b;
    long n;
    FILE *f;
    int ok, i;

    lstrcpynW(path, L"env.jwf", MAX_PATH);
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.lpstrDefExt = L"jwf";
    o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&o))
        return 0;
    for (i = 0; path[i]; i++)
        ;
    while (i > 0 && path[i - 1] != L'\\' && path[i - 1] != L'/')
        i--;
    if (!WideCharToMultiByte(932, 0, path + i, -1, nm, (int)sizeof nm, 0, 0))
        nm[0] = 0;
    if (!app_save_env(nm, &b, &n))
        return 0;
    f = _wfopen(path, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    ok = fwrite(b, 1, (size_t)n, f) == (size_t)n;
    fclose(f);
    free(b);
    return ok;
}

/* 環境設定ファイル 編集・作成: the configuration as a .jwf in the temp folder,
 * open in Notepad. */
static int edit_env(void)
{
    wchar_t path[MAX_PATH + 32], cmd[MAX_PATH + 64];
    unsigned char *b;
    long n;
    FILE *f;
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    if (!app_save_env("jw_env.jwf", &b, &n))
        return 0;
    if (!GetTempPathW(MAX_PATH, path)) {
        free(b);
        return 0;
    }
    lstrcatW(path, L"jw_env.jwf");
    f = _wfopen(path, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    fwrite(b, 1, (size_t)n, f);
    fclose(f);
    free(b);
    /* the full path of Notepad: "notepad.exe" alone is looked for in the program's folder and the
       current folder first (and 外部変形 changes the current folder to the BAT's) */
    {
        wchar_t win[MAX_PATH];

        if (!GetWindowsDirectoryW(win, MAX_PATH)) {
            return 0;
        }
        swprintf(cmd, MAX_PATH + 64, L"\"%ls%cNOTEPAD.EXE\" \"%ls\"", win, (wchar_t)92, path);
    }
    ZeroMemory(&si, sizeof si);
    si.cb = sizeof si;
    if (CreateProcessW(0, cmd, 0, 0, FALSE, 0, 0, 0, &si, &pi)) {
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
    return 0;
}

/* 「印刷」.  The original prints the sheet one to one and clips whatever
 * runs off the printer's paper; there is no printer here, so what the port
 * hands over is a file of that sheet -- a PDF to send to one or a PNG to
 * look at, whichever the name asks for (src/plot.h). */
static int save_plot(HWND wnd)
{
    static const wchar_t filter[] =
        L"PDF (*.pdf)\0*.pdf\0PNG (*.png)\0*.png\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    unsigned char *b;
    long n;
    FILE *f;
    int ok, i, png;

    lstrcpynW(path, current_path, MAX_PATH);
    for (i = 0; path[i]; i++)
        ;
    while (i > 0 && path[i] != L'.' && path[i] != L'\\' && path[i] != L'/')
        i--;
    if (i > 0 && path[i] == L'.')
        path[i] = 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.lpstrDefExt = L"pdf";
    o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&o))
        return 0;
    for (i = 0; path[i]; i++)
        ;
    png = i > 4 && (path[i - 3] == L'p' || path[i - 3] == L'P')
              && (path[i - 2] == L'n' || path[i - 2] == L'N')
              && (path[i - 1] == L'g' || path[i - 1] == L'G');
    {
        jw_plot_frame fr;               /* 印刷の命令の枠・倍率・回転・カラー印刷 */

        jw_pr_settings(&fr);
        b = png ? jw_plot_png_at(app_drawing(), &fr, 4.0, &n)
                : jw_plot_pdf_at(app_drawing(), &fr, &n);
    }
    if (!b)
        return 0;
    f = _wfopen(path, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    ok = fwrite(b, 1, (size_t)n, f) == (size_t)n;
    fclose(f);
    free(b);
    return ok;
}

/* 「SFC形式で保存」.  The name it is saved under goes in the file, so the
 * dialog comes first here and the bytes are made afterwards. */
static int save_sfc(HWND wnd)
{
    static const wchar_t filter[] = L"SXF (*.sfc)\0*.sfc\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    char name[MAX_PATH];
    unsigned char *b;
    long n;
    FILE *f;
    int ok, i, j;

    lstrcpynW(path, current_path, MAX_PATH);
    for (i = 0; path[i]; i++)
        ;
    while (i > 0 && path[i] != L'.' && path[i] != L'\\' && path[i] != L'/')
        i--;
    if (i > 0 && path[i] == L'.')
        path[i] = 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.lpstrDefExt = L"sfc";
    o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&o))
        return 0;
    for (i = 0, j = 0; path[i]; i++)    /* the last part of the path, in 932 */
        if (path[i] == L'\\' || path[i] == L'/')
            j = i + 1;
    WideCharToMultiByte(932, 0, path + j, -1, name, MAX_PATH, NULL, NULL);
    if (!app_save_sfc(name, &b, &n))
        return 0;
    f = _wfopen(path, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    ok = fwrite(b, 1, (size_t)n, f) == (size_t)n;
    fclose(f);
    free(b);
    return ok;
}

/* DXFファイルを開く and SFCファイルを開く.  What either of them
 * makes is not the file that 上書 writes, so what was open stays the file it
 * came from. */
static int open_other(HWND wnd, const wchar_t *filter,
                     int (*take)(const unsigned char *, long))
{
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    unsigned char *b;
    long n;
    FILE *f;
    int ok = 0;

    path[0] = 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    if (!GetOpenFileNameW(&o))
        return 0;
    f = _wfopen(path, L"rb");
    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)n);
    if (b && fread(b, 1, (size_t)n, f) == (size_t)n)
        ok = take(b, n);
    fclose(f);
    free(b);
    return ok;
}

static int ask_save(HWND wnd)
{
    static const wchar_t filter[] = L"Jw_cad (*.jww)\0*.jww\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];

    lstrcpynW(path, current_path, MAX_PATH);
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.lpstrDefExt = L"jww";
    o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
    if (!GetSaveFileNameW(&o))
        return 0;
    return save_file(path);
}

/* jw_port.exe [drawing.jww] -- opening one on the command line, as well as
 * through the 開く button. */
static void open_arg(PWSTR cmd)
{
    wchar_t path[MAX_PATH];
    int i = 0, j = 0;

    while (cmd[i] == L' ')
        i++;
    if (cmd[i] == L'"') {
        i++;
        while (cmd[i] && cmd[i] != L'"' && j < MAX_PATH - 1)
            path[j++] = cmd[i++];
    } else {
        while (cmd[i] && cmd[i] != L' ' && j < MAX_PATH - 1)
            path[j++] = cmd[i++];
    }
    path[j] = 0;
    if (j && j < MAX_PATH - 1)
        load_file(path);
}

/* What the 開く button asks for.  The dialog is the operating system's: the
 * original's own is a Windows common dialog too, and nothing of the frame
 * this port draws comes from Windows. */
static int ask_open(HWND wnd)
{
    static const wchar_t filter[] = L"Jw_cad (*.jww)\0*.jww\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];

    path[0] = 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    if (!GetOpenFileNameW(&o))
        return 0;
    return load_file(path);
}

/* The menu bar, out of the tree tools/mkmenu.py took from the original's
 * menu resource -- the same 176 entries, with the same command ids, so a
 * menu item and the toolbar button beside it arrive at app_command() as the
 * same number.  The browser build draws its own; this one hands the tree to
 * Windows, which is why nothing of the client area changes.
 *
 * The names are CP932 in the resource and the window is Unicode, so each one
 * goes through jw_to_utf16 on the way.
 */
static void wide(const char *s, wchar_t *out, int cap)
{
    long n = jw_to_utf16(s, (long)strlen(s), (unsigned short *)out, cap - 1);

    out[n < cap - 1 ? n : cap - 1] = 0;
}

static HMENU build_menu(void)
{
    /* stack[d] is the menu an entry of depth d is appended to; the bar is
       depth 0, and a popup at depth d is what depth d+1 goes into.  The
       original's tree is three deep. */
    HMENU stack[8];
    wchar_t text[256];
    int i;



    stack[0] = CreateMenu();
    if (!stack[0])
        return NULL;
    for (i = 0; i < JW_NMENU_TREE; i++) {
        const jw_menu_item_t *m = &jw_menu_tree[i];
        int d = m->depth;

        if (d + 1 >= (int)(sizeof stack / sizeof stack[0]))
            continue;
        switch (m->kind) {
        case 1: {                       /* a popup that opens */
            HMENU sub = CreatePopupMenu();
            wide(m->text, text, 256);
            AppendMenuW(stack[d], MF_POPUP | MF_STRING, (UINT_PTR)sub, text);
            stack[d + 1] = sub;
            break;
        }
        case 2:
            AppendMenuW(stack[d], MF_SEPARATOR, 0, NULL);
            break;
        default:
            if (m->id == 57616) {
                /* 最新のﾌｧｲﾙ: the placeholder is where the files opened last
                   go; with none it stays, grayed */
                if (recent[0][0]) {
                    int r;

                    for (r = 0; r < NRECENT && recent[r][0]; r++) {
                        wchar_t t[MAX_PATH + 8];

                        {   /* an & in a name would underline the next letter: double it */
                            wchar_t *o = t + swprintf(t, MAX_PATH + 8, L"&%d ", r + 1);
                            const wchar_t *q;

                            for (q = recent[r]; *q && o < t + MAX_PATH + 4; q++) {
                                if (*q == L'&')
                                    *o++ = L'&';
                                *o++ = *q;
                            }
                            *o = 0;
                        }
                        AppendMenuW(stack[d], MF_STRING, RECENT_ID + r, t);
                    }
                    break;
                }
                wide(m->text, text, 256);
                AppendMenuW(stack[d], MF_STRING | MF_GRAYED, m->id, text);
                break;
            }
            wide(m->text, text, 256);
            AppendMenuW(stack[d], MF_STRING, m->id, text);
            break;
        }
    }
    return stack[0];
}

/* The keyboard shortcuts, from the original's own ACCELERATOR resource.
 * The menu names them because the menu resource spells them out; this is what
 * makes them work.  They arrive as WM_COMMAND, so they go the same way a menu
 * item does. */
static HACCEL build_accel(void)
{
    ACCEL a[JW_NACCEL];
    int i;

    for (i = 0; i < JW_NACCEL; i++) {
        a[i].fVirt = jw_accel[i].virt;
        a[i].key = jw_accel[i].key;
        a[i].cmd = jw_accel[i].cmd;
    }
    return CreateAcceleratorTableW(a, JW_NACCEL);
}

/* ファイル > タグジャンプ: the picked text names a file.  The original tries
 * the name as it is and then with .jww on it, starting from the folder the
 * open drawing is in (tools/jwdraw.ps1 over a text "tagtarget": the file
 * tagtarget.jww next to the open one was found), says nothing when there is
 * no such file, and otherwise does what 開く does -- including asking
 * whether to keep the changes first. */
static int tag_jump(HWND wnd)
{
    wchar_t name[MAX_PATH], path[MAX_PATH], dir[MAX_PATH];
    const char *s = app_tag_name();
    long n = jw_to_utf16(s, (long)strlen(s), (unsigned short *)name,
                         MAX_PATH - 8);
    int i, pass, found = 0, abs_ = 0;

    if (n <= 0)
        return 0;
    name[n] = 0;
    for (i = 0; name[i]; i++)
        if (name[i] == L'/')
            name[i] = L'\\';
    abs_ = (name[0] && name[1] == L':') || (name[0] == L'\\' && name[1] == L'\\');
    lstrcpynW(dir, current_path, MAX_PATH);
    for (i = lstrlenW(dir); i > 0 && dir[i - 1] != L'\\'; i--)
        ;
    dir[i] = 0;
    for (pass = 0; pass < 2 && !found; pass++) {
        if (abs_)
            lstrcpynW(path, name, MAX_PATH);
        else {
            lstrcpynW(path, dir, MAX_PATH);
            lstrcatW(path, name);
        }
        if (pass)
            lstrcatW(path, L".jww");
        if (GetFileAttributesW(path) != INVALID_FILE_ATTRIBUTES
            && !(GetFileAttributesW(path) & FILE_ATTRIBUTE_DIRECTORY))
            found = 1;
    }
    if (!found)
        return 0;
    if (app_modified()) {
        int r = MessageBoxW(wnd, L"Save the changes first?", L"jw_win",
                            MB_YESNOCANCEL | MB_ICONQUESTION);

        if (r == IDCANCEL)
            return 0;
        if (r == IDYES) {
            if (current_path[0])
                save_file(current_path);
            else if (!ask_save(wnd))
                return 0;
        }
    }
    return load_file(path);
}

/* External transform: pick a BAT and hand it over (the steps are then asked in
   the drawing window), and when they are answered run it: write JWC_TEMP.TXT
   in the BAT's folder, start the BAT with its arguments and wait, read the
   file back (tmp/spec_gaibu/A_gaibu_henkei.md) */
static wchar_t gaibu_bat[MAX_PATH];

static int pick_gaibu(HWND wnd)
{
    static const wchar_t filter[] = L"BAT (*.bat)\0*.bat\0\0";
    OPENFILENAMEW o;
    wchar_t path[MAX_PATH];
    unsigned char *bat;
    long bn;
    FILE *f;
    int ok;

    path[0] = 0;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = filter;
    o.lpstrFile = path;
    o.nMaxFile = MAX_PATH;
    o.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    if (!GetOpenFileNameW(&o))
        return 0;
    f = _wfopen(path, L"rb");
    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    bn = ftell(f);
    fseek(f, 0, SEEK_SET);
    bat = (unsigned char *)malloc((size_t)bn + 1);
    if (!bat || fread(bat, 1, (size_t)bn, f) != (size_t)bn) {
        fclose(f);
        free(bat);
        return 0;
    }
    fclose(f);
    bat[bn] = 0;
    ok = app_gaibu_load((const char *)bat, bn);
    free(bat);
    if (!ok) {
        MessageBoxW(wnd, L"Not a batch file for Jw_cad (no #jw line).", L"jw_win", MB_OK);
        return 0;
    }
    lstrcpynW(gaibu_bat, path, MAX_PATH);
    return 1;
}

static int run_gaibu(HWND wnd)
{
    wchar_t dir[MAX_PATH], home[MAX_PATH], cmd[MAX_PATH + 160], *sl, wargs[160];
    unsigned char *t = 0, *back = 0;
    long tn = 0, kn = 0;
    char args[128], msg[160];
    FILE *f;
    int r;
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    (void)wnd;
    args[0] = 0;
    /* only a batch file is run, whatever the dialog let through */
    {
        size_t bl = wcslen(gaibu_bat);

        if (bl < 5 || (_wcsicmp(gaibu_bat + bl - 4, L".bat") && _wcsicmp(gaibu_bat + bl - 4, L".cmd")))
            return 0;
    }
    if (app_gaibu_run_begin(&t, &tn, args, (int)sizeof args) != 1) {
        app_gaibu_run_end();
        return 0;
    }
    wcscpy(dir, gaibu_bat);
    sl = wcsrchr(dir, (wchar_t)92);
    if (sl)
        *sl = 0;
    GetCurrentDirectoryW(MAX_PATH, home);
    SetCurrentDirectoryW(dir);
    f = _wfopen(L"JWC_TEMP.TXT", L"wb");
    if (!f) {
        free(t);
        SetCurrentDirectoryW(home);
        app_gaibu_run_end();
        return 0;
    }
    fwrite(t, 1, (size_t)tn, f);
    fclose(f);
    free(t);
    MultiByteToWideChar(932, 0, args, -1, wargs, 160);
    wargs[159] = 0;
    {   /* the typed answers become the batch file's arguments; a line break would end the line */
        wchar_t *q;

        for (q = wargs; *q; q++)
            if (*q < 32)
                *q = L' ';
    }
    swprintf(cmd, MAX_PATH + 160, L"\"%ls\" %ls", gaibu_bat, wargs);
    ZeroMemory(&si, sizeof si);
    si.cb = sizeof si;
    if (CreateProcessW(NULL, cmd, NULL, NULL, FALSE, 0, NULL, dir, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    f = _wfopen(L"JWC_TEMP.TXT", L"rb");
    if (!f) {
        SetCurrentDirectoryW(home);
        app_gaibu_run_end();
        return 0;
    }
    fseek(f, 0, SEEK_END);
    kn = ftell(f);
    fseek(f, 0, SEEK_SET);
    back = (unsigned char *)malloc((size_t)kn + 1);
    if (back && fread(back, 1, (size_t)kn, f) == (size_t)kn)
        r = app_gaibu_end(back, kn, msg, (int)sizeof msg);
    else
        r = -1;
    fclose(f);
    free(back);
    SetCurrentDirectoryW(home);
    app_gaibu_run_end();
    return r >= 0;
}

/* Moji range selection: 'Document' writes the picked texts to a .TXT,
   'External editor' round-trips them through TEMP.TXT in NOTEPAD, 'Paste'
   puts the clipboard's lines onto them (tmp/spec_gaibu/B_moji_hani.md) */
static int moji_file(HWND wnd, int what)
{
    unsigned char *b = 0, *back = 0;
    long n = 0, kn = 0;
    wchar_t path[MAX_PATH], tmp[MAX_PATH];
    FILE *f;
    int ok = 0;

    if (what == 2) {                    /* paste */
        HGLOBAL h;
        const wchar_t *w;
        size_t wl;

        if (!OpenClipboard(wnd))
            return 0;
        h = GetClipboardData(CF_UNICODETEXT);
        w = h ? (const wchar_t *)GlobalLock(h) : NULL;
        if (w) {
            wl = wcslen(w);
            back = (unsigned char *)malloc(wl * 2 + 4);
            if (back) {
                back[0] = 0xff;
                back[1] = 0xfe;
                memcpy(back + 2, w, wl * 2);
                kn = (long)(wl * 2 + 2);
            }
            GlobalUnlock(h);
        }
        CloseClipboard();
        if (back)
            ok = app_moji_apply(back, kn);
        free(back);
        return ok;
    }
    if (what == 0) {                    /* document */
        OPENFILENAMEW o;

        if (!app_moji_doc(&b, &n))
            return 0;
        path[0] = 0;
        ZeroMemory(&o, sizeof o);
        o.lStructSize = sizeof o;
        o.hwndOwner = wnd;
        o.lpstrFilter = L"TXT File (*.TXT)\0*.TXT\0\0";
        o.lpstrFile = path;
        o.nMaxFile = MAX_PATH;
        o.lpstrDefExt = L"txt";
        o.Flags = OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST;
        if (GetSaveFileNameW(&o) && (f = _wfopen(path, L"wb")) != NULL) {
            ok = fwrite(b, 1, (size_t)n, f) == (size_t)n;
            fclose(f);
        }
        free(b);
        return ok;
    }
    /* external editor */
    if (!app_moji_edit_text(&b, &n))
        return 0;
    GetTempPathW(MAX_PATH, tmp);
    wcscat(tmp, L"jw_TEMP.TXT");
    f = _wfopen(tmp, L"wb");
    if (!f) {
        free(b);
        return 0;
    }
    fwrite(b, 1, (size_t)n, f);
    fclose(f);
    free(b);
    {
        wchar_t win[MAX_PATH], cmd[2 * MAX_PATH + 16];
        STARTUPINFOW si;
        PROCESS_INFORMATION pi;

        GetWindowsDirectoryW(win, MAX_PATH);
        swprintf(cmd, 2 * MAX_PATH + 16, L"\"%ls%cNOTEPAD.EXE\" \"%ls\"", win, (wchar_t)92, tmp);
        ZeroMemory(&si, sizeof si);
        si.cb = sizeof si;
        if (!CreateProcessW(NULL, cmd, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
            return 0;
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    f = _wfopen(tmp, L"rb");
    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    kn = ftell(f);
    fseek(f, 0, SEEK_SET);
    back = (unsigned char *)malloc((size_t)kn + 1);
    if (back && fread(back, 1, (size_t)kn, f) == (size_t)kn)
        ok = app_moji_apply(back, kn);
    fclose(f);
    free(back);
    DeleteFileW(tmp);
    return ok;
}

/* コピー・切り取りで選んでいた字を CF_UNICODETEXT へ（原典 FUN_004fb140 が
   図形と一緒に置く分）。控えは UTF-8・BOM 付き・一行一字の LF なので、
   UTF-16 にして行末を CRLF に。字が無ければ何もしない（図形は移植の中だけ） */
static void clip_put(HWND wnd)
{
    const unsigned char *b;
    long n, i, k = 0;
    int wl;
    wchar_t *w, *g;
    HGLOBAL h;

    if (!jw_cmd_moji_clip(&b, &n) || n <= 3)
        return;
    wl = MultiByteToWideChar(CP_UTF8, 0, (const char *)b + 3, (int)(n - 3), NULL, 0);
    if (wl <= 0 || !(w = (wchar_t *)malloc((size_t)wl * sizeof *w)))
        return;
    MultiByteToWideChar(CP_UTF8, 0, (const char *)b + 3, (int)(n - 3), w, wl);
    h = GlobalAlloc(GMEM_MOVEABLE, ((size_t)wl * 2 + 1) * sizeof *w);
    g = h ? (wchar_t *)GlobalLock(h) : NULL;
    if (g) {
        for (i = 0; i < wl; i++) {
            if (w[i] == L'\n')
                g[k++] = L'\r';
            g[k++] = w[i];
        }
        g[k] = 0;
        GlobalUnlock(h);
        if (OpenClipboard(wnd)) {
            EmptyClipboard();
            if (SetClipboardData(CF_UNICODETEXT, h))
                h = NULL;               /* 窓の側のものになった */
            CloseClipboard();
        }
    }
    if (h)
        GlobalFree(h);
    free(w);
}

/* A command from a menu item is taken the same way a toolbar press is: what
   needs a file or a dialog comes back through app_take_action().
   Whatever app_command() or app_press() asked for that needs a file or a
   dialog.  Only 開く changes what is on screen. */
static void settings_save(void);

static int do_action(HWND wnd)
{
    switch (app_take_action()) {
    case JW_ACT_OPEN:
        return ask_open(wnd);
    case JW_ACT_SAVE:
        if (current_path[0])
            save_file(current_path);
        else
            ask_save(wnd);
        break;
    case JW_ACT_SAVE_AS:
        ask_save(wnd);
        break;
    case JW_ACT_SAVE_DXF:
        save_dxf(wnd);
        break;
    case JW_ACT_OPEN_DXF:
        return open_other(wnd, L"DXF (*.dxf)\0*.dxf\0\0", app_open_dxf);
    case JW_ACT_OPEN_SFC:
        return open_other(wnd, L"SXF (*.sfc)\0*.sfc\0\0", app_open_sfc);
    case JW_ACT_SAVE_SFC:
        save_sfc(wnd);
        break;
    case JW_ACT_SAVE_JWC:
        save_jwc(wnd);
        break;
    case JW_ACT_ENV_WRITE:
        save_env(wnd);
        break;
    case JW_ACT_ENV_READ:
        return open_other(wnd, L"Jwf (*.jwf)\0*.jwf\0JwL (*.jwl)\0*.jwl\0\0",
                          app_open_env);
    case JW_ACT_ENV_EDIT:
        edit_env();
        break;
    case JW_ACT_PLOT:
        /* a printer, or a file of the sheet (PDF / PNG) */
        if ((_wgetenv(L"JW_PRINTER") && *_wgetenv(L"JW_PRINTER")) || MessageBoxW(wnd, tr(L"\u30d7\u30ea\u30f3\u30bf\u306b\u5370\u5237\u3057\u307e\u3059\u304b\uff1f\n\uff08\u300c\u3044\u3044\u3048\u300d\u306f PDF / PNG \u30d5\u30a1\u30a4\u30eb\u306b\u3057\u307e\u3059\uff09", L"Print on a printer?\n(No: write a PDF / PNG file)"),
                        L"jw_win", MB_YESNO | MB_ICONQUESTION) == IDYES)
            print_gdi(wnd);
        else
            save_plot(wnd);
        break;
    case JW_ACT_OPEN_JWC:
        return open_other(wnd, L"JWC (*.jwc)\0*.jwc\0\0", app_open_jwc);
    case JW_ACT_NEW_ASK:
        /* "discard the changes and start a new drawing?" */
        if (MessageBoxW(wnd, L"\u5909\u66f4\u3092\u7834\u68c4\u3057\u3066\u65b0\u898f\u4f5c\u6210\u3057\u307e\u3059\u304b\uff1f",
                        L"Jw_cad", MB_YESNO | MB_ICONQUESTION) == IDYES) {
            app_new();
            current_path[0] = 0;
            return 1;
        }
        break;
    case JW_ACT_TAG:
        return tag_jump(wnd);
    case JW_ACT_OPEN_IMAGE:
        return ask_image(wnd);
    case JW_ACT_MOJI_DOC:
        return moji_file(wnd, 0);
    case JW_ACT_MOJI_EDIT:
        return moji_file(wnd, 1);
    case JW_ACT_MOJI_PASTE:
        return moji_file(wnd, 2);
    case JW_ACT_CLIP_PUT:
        clip_put(wnd);
        return 1;                       /* 切り取り は図面を変えている */
    case JW_ACT_GAIBU:
        return pick_gaibu(wnd);
    case JW_ACT_GAIBU_RUN:
        return run_gaibu(wnd);
    case JW_ACT_SAVE_IMAGES:
        save_images(wnd);
        break;
    case JW_ACT_OPEN_TEXT:
        /* the text file whose lines go down from the next click */
        return open_other(wnd, L"Text (*.txt)\0*.txt\0"
                               L"All (*.*)\0*.*\0\0", app_text);
    case JW_ACT_OPEN_FIG:
        /* 図形 (32862): 選んだ .jws が カーソルに付く（取り消せば命令のまま）。
           .jwk（DOS 版の図形）は読み手が無いので出さない */
        return open_other(wnd, L"図形 (*.jws)\0*.jws\0\0", app_figure);
    case JW_ACT_EXIT:
        /* Jw_cadの終了 (57665): 原典の ID_APP_EXIT と同じく主窓に WM_CLOSE
           （保存の問いはそこで） */
        PostMessageW(wnd, WM_CLOSE, 0, 0);
        break;
    }
    return 0;
}

static void do_command(HWND wnd, int id)
{
    int redraw = app_command(id);

    redraw |= do_action(wnd);
    if (redraw) {
        app_paint();
        InvalidateRect(wnd, NULL, FALSE);
    }
}

static void present(HDC dc)
{
    const fb_t *fb = app_fb();
    BITMAPINFO bi;

    if (!fb->px)
        return;
    ZeroMemory(&bi, sizeof bi);
    bi.bmiHeader.biSize = sizeof bi.bmiHeader;
    bi.bmiHeader.biWidth = fb->w;
    bi.bmiHeader.biHeight = -fb->h;     /* top-down */
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;
    if (uiscale > 1) {
        SetStretchBltMode(dc, COLORONCOLOR);
        StretchDIBits(dc, 0, 0, fb->w * uiscale, fb->h * uiscale, 0, 0, fb->w, fb->h,
                      fb->px, &bi, DIB_RGB_COLORS, SRCCOPY);
        return;
    }
    SetDIBitsToDevice(dc, 0, 0, fb->w, fb->h, 0, 0, 0, fb->h,
                      fb->px, &bi, DIB_RGB_COLORS);
}

static int lang_is_english(void)
{
    const wchar_t *e = _wgetenv(L"JW_LANG");
    wchar_t p[MAX_PATH], v[16];

    if (e && *e)
        return e[0] == L'e';
    if (ini_path(p)) {
        GetPrivateProfileStringW(L"ui", L"lang", L"", v, 16, p);
        if (v[0])
            return v[0] == L'e';
    }
    return (GetUserDefaultUILanguage() & 0x3ff) != 0x11;      /* LANG_JAPANESE */
}

/* ---- high DPI -------------------------------------------------------------
   The frame is a bitmap drawn at 96 dpi.  The process says it knows about DPI
   (so Windows does not blur it), and on a screen with more dots the bitmap is
   shown a whole number of times larger, which keeps it sharp; mouse positions
   are divided back down. */
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wcast-function-type"
static void dpi_init(void)
{
    HMODULE u = GetModuleHandleW(L"user32.dll");
    UINT dpi = 96;
    const wchar_t *e = _wgetenv(L"JW_UISCALE");

    if (u) {
        BOOL (WINAPI *ctx)(HANDLE) = (BOOL (WINAPI *)(HANDLE))GetProcAddress(u, "SetProcessDpiAwarenessContext");
        BOOL (WINAPI *old)(void) = (BOOL (WINAPI *)(void))GetProcAddress(u, "SetProcessDPIAware");
        UINT (WINAPI *gds)(void) = (UINT (WINAPI *)(void))GetProcAddress(u, "GetDpiForSystem");

        if (!(ctx && ctx((HANDLE)-4)) && old)       /* per monitor v2, else system */
            old();
        if (gds)
            dpi = gds();
    }
    uiscale = (int)((dpi + 48) / 96);
    if (e && *e >= L'1' && *e <= L'4')
        uiscale = *e - L'0';
    if (uiscale < 1)
        uiscale = 1;
    if (uiscale > 4)
        uiscale = 4;
}

#pragma GCC diagnostic pop

#define MX(v) ((int)(short)(v) / uiscale)

/* ---- asking before work is lost ------------------------------------------- */
static int ask_save(HWND wnd);

/* 1 if it is all right to go on: nothing to lose, or saved, or thrown away on purpose */
static int ask_save_changes(HWND wnd)
{
    int r;

    if (!app_modified())
        return 1;
    r = MessageBoxW(wnd, tr(L"変更を保存しますか？", L"Save the changes?"), L"jw_win",
                    MB_YESNOCANCEL | MB_ICONQUESTION);
    if (r == IDCANCEL)
        return 0;
    if (r == IDYES) {
        if (current_path[0])
            return save_file(current_path);
        return ask_save(wnd);
    }
    return 1;
}

/* ---- autosave and recovery -------------------------------------------------
   While the drawing is changed and not saved, a copy of it goes to
   %APPDATA%\jw_port\autosave.jww every couple of minutes (JW_AUTOSAVE_SEC
   changes that), with the name it came from beside it.  A clean close or a save
   takes the copy away.  If one is found at the start the program died, and it
   offers to bring it back. */
static int autosave_paths(wchar_t *jww, wchar_t *txt)
{
    wchar_t dir[MAX_PATH];

    if (!GetEnvironmentVariableW(L"APPDATA", dir, MAX_PATH))
        return 0;
    swprintf(jww, MAX_PATH, L"%ls%cjw_port", dir, (wchar_t)92);
    CreateDirectoryW(jww, NULL);
    swprintf(jww, MAX_PATH, L"%ls%cjw_port%cautosave.jww", dir, (wchar_t)92, (wchar_t)92);
    swprintf(txt, MAX_PATH, L"%ls%cjw_port%cautosave.txt", dir, (wchar_t)92, (wchar_t)92);
    return 1;
}

static void autosave_clear(void)
{
    wchar_t a[MAX_PATH], b[MAX_PATH];

    if (autosave_paths(a, b)) {
        DeleteFileW(a);
        DeleteFileW(b);
    }
}

static void autosave_write(void)
{
    wchar_t a[MAX_PATH], b[MAX_PATH];
    unsigned char *buf = 0;
    long n = 0;
    FILE *f;

    if (!app_modified()) {
        autosave_clear();               /* saved since: nothing to keep */
        return;
    }
    if (!autosave_paths(a, b) || !app_save_backup(&buf, &n))
        return;
    f = _wfopen(a, L"wb");
    if (f) {
        fwrite(buf, 1, (size_t)n, f);
        fclose(f);
    }
    free(buf);
    f = _wfopen(b, L"wb");
    if (f) {
        fwrite(current_path, sizeof(wchar_t), wcslen(current_path), f);
        fclose(f);
    }
}

/* at the start: is there a copy left from a run that did not end properly? */
static void autosave_recover(HWND wnd)
{
    wchar_t a[MAX_PATH], b[MAX_PATH], name[MAX_PATH];
    FILE *f;
    long n;
    unsigned char *buf;
    const wchar_t *auto_answer = _wgetenv(L"JW_RECOVER");
    int yes;

    if (!autosave_paths(a, b) || GetFileAttributesW(a) == INVALID_FILE_ATTRIBUTES)
        return;
    if (auto_answer)
        yes = auto_answer[0] == L'y';
    else
        yes = MessageBoxW(wnd, tr(L"前回、保存されていない図面がありました。復元しますか？", L"A drawing with unsaved changes was left from the last run. Restore it?"),
                          L"jw_win", MB_YESNO | MB_ICONQUESTION) == IDYES;
    if (!yes) {
        autosave_clear();
        return;
    }
    f = _wfopen(a, L"rb");
    if (!f)
        return;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (unsigned char *)malloc((size_t)(n > 0 ? n : 1));
    if (buf && n > 0 && fread(buf, 1, (size_t)n, f) == (size_t)n && app_open(buf, n)) {
        name[0] = 0;
        fclose(f);
        f = _wfopen(b, L"rb");
        if (f) {
            size_t got = fread(name, sizeof(wchar_t), MAX_PATH - 1, f);

            name[got] = 0;
        }
        lstrcpynW(current_path, name, MAX_PATH);
        sync_doc();
        app_mark_modified();
        app_paint();
    }
    if (f)
        fclose(f);
    free(buf);
}

/* ---- where the window was -------------------------------------------------- */
static void placement_save(HWND wnd)
{
    wchar_t p[MAX_PATH];
    WINDOWPLACEMENT wp;
    wchar_t v[96];

    if (!ini_path(p))
        return;
    wp.length = sizeof wp;
    if (!GetWindowPlacement(wnd, &wp))
        return;
    swprintf(v, 96, L"%d,%d,%d,%d,%d", (int)wp.rcNormalPosition.left, (int)wp.rcNormalPosition.top,
             (int)wp.rcNormalPosition.right, (int)wp.rcNormalPosition.bottom,
             wp.showCmd == SW_SHOWMAXIMIZED ? 1 : 0);
    WritePrivateProfileStringW(L"window", L"placement", v, p);
}

/* put the window where it was, if that is still on a screen; returns the show command */
static int placement_restore(HWND wnd, int show)
{
    wchar_t p[MAX_PATH], v[96];
    int l, t, r, b, mx;
    WINDOWPLACEMENT wp;
    RECT rc;

    if (!ini_path(p))
        return show;
    GetPrivateProfileStringW(L"window", L"placement", L"", v, 96, p);
    if (swscanf(v, L"%d,%d,%d,%d,%d", &l, &t, &r, &b, &mx) != 5 || r - l < 200 || b - t < 150)
        return show;
    rc.left = l; rc.top = t; rc.right = r; rc.bottom = b;
    if (!MonitorFromRect(&rc, MONITOR_DEFAULTTONULL))
        return show;                    /* that screen is gone */
    wp.length = sizeof wp;
    GetWindowPlacement(wnd, &wp);
    wp.rcNormalPosition = rc;
    wp.showCmd = show;
    SetWindowPlacement(wnd, &wp);
    return mx && show != SW_SHOWMINIMIZED ? SW_SHOWMAXIMIZED : show;
}

/* ---- opening what is dropped on the window ---------------------------------- */
static int open_any(HWND wnd, const wchar_t *path)
{
    size_t n = wcslen(path);
    const wchar_t *e = n > 4 ? path + n - 4 : path;
    int (*take)(const unsigned char *, long) = 0;
    unsigned char *b;
    long len;
    FILE *f;
    int ok = 0;

    if (!_wcsicmp(e, L".jww")) {
        if (!ask_save_changes(wnd))
            return 0;
        return load_file(path);
    }
    if (!_wcsicmp(e, L".dxf"))
        take = app_open_dxf;
    else if (!_wcsicmp(e, L".sfc"))
        take = app_open_sfc;
    else if (!_wcsicmp(e, L".jwc"))
        take = app_open_jwc;
    if (!take)
        return 0;
    f = _wfopen(path, L"rb");
    if (!f)
        return 0;
    fseek(f, 0, SEEK_END);
    len = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)(len > 0 ? len : 1));
    if (b && fread(b, 1, (size_t)len, f) == (size_t)len)
        ok = take(b, len);
    fclose(f);
    free(b);
    return ok;
}

/* ---- 印刷 on a printer --------------------------------------------------------
   The sheet is rendered by the port's own drawing code (src/plot.h) at the
   printer's resolution, then stretched onto the page: at its own size when it
   fits, scaled down to fit when it does not, and turned a quarter if that makes
   it bigger.  Cancelling the dialog prints nothing. */
static int print_gdi(HWND wnd)
{
    PRINTDLGW pd;
    DOCINFOW di;
    HDC dc;
    double sw, sh, dpmm, s;
    int pw, ph, dpix, iw, ih, rot, x, y, dw, dh, i, j;
    unsigned char *png, *pix, *bits;
    long pn = 0;
    jw_img im;
    BITMAPINFO bi;

    const wchar_t *named = _wgetenv(L"JW_PRINTER");        /* a printer by name, no dialog: for the tests */
    const wchar_t *to_file = _wgetenv(L"JW_PRINT_FILE");   /* and the file it is to write, for a PDF/XPS printer */

    ZeroMemory(&pd, sizeof pd);
    pd.lStructSize = sizeof pd;
    pd.hwndOwner = wnd;
    pd.Flags = PD_RETURNDC | PD_NOSELECTION | PD_NOPAGENUMS | PD_USEDEVMODECOPIESANDCOLLATE;
    pd.nCopies = 1;
    if (named && *named) {
        dc = CreateDCW(L"WINSPOOL", named, NULL, NULL);
        if (!dc)
            return 0;
    } else {
        if (!PrintDlgW(&pd))
            return 0;
        dc = pd.hDC;
    }
    pw = GetDeviceCaps(dc, HORZRES);
    ph = GetDeviceCaps(dc, VERTRES);
    dpix = GetDeviceCaps(dc, LOGPIXELSX);
    jw_plot_paper(app_drawing(), &sw, &sh);
    dpmm = dpix / 25.4;
    if (dpmm > 6.0)
        dpmm = 6.0;                     /* more than that is only a bigger file */
    {
        jw_plot_frame fr;               /* 印刷の命令の枠・倍率・回転・カラー印刷 */

        jw_pr_settings(&fr);
        png = jw_plot_png_at(app_drawing(), &fr, dpmm, &pn);
    }
    if (!png || !jw_img_decode(png, pn, &im)) {
        free(png);
        DeleteDC(dc);
        if (pd.hDevMode) GlobalFree(pd.hDevMode);
        if (pd.hDevNames) GlobalFree(pd.hDevNames);
        return 0;
    }
    free(png);
    /* the picture, and the way it sits: turned when that fits better */
    rot = (im.w > im.h) != (pw > ph);
    iw = rot ? im.h : im.w;
    ih = rot ? im.w : im.h;
    pix = (unsigned char *)malloc((size_t)iw * ih * 3 + 3);
    bits = pix;
    if (!pix) {
        jw_img_free(&im);
        DeleteDC(dc);
        return 0;
    }
    for (j = 0; j < ih; j++)
        for (i = 0; i < iw; i++) {
            const unsigned char *q = rot ? im.rgb + ((size_t)(im.h - 1 - i) * im.w + j) * 3
                                         : im.rgb + ((size_t)j * im.w + i) * 3;
            unsigned char *o = pix + ((size_t)j * iw + i) * 3;

            o[0] = q[2];                /* BGR */
            o[1] = q[1];
            o[2] = q[0];
        }
    /* its size on paper: sw x sh millimetres of the sheet, at the printer's dots */
    s = 1.0;
    {
        double wpx = (rot ? sh : sw) * dpix / 25.4, hpx = (rot ? sw : sh) * dpix / 25.4;

        if (wpx > pw)
            s = pw / wpx;
        if (hpx * s > ph)
            s = ph / hpx;
        dw = (int)(wpx * s);
        dh = (int)(hpx * s);
    }
    x = (pw - dw) / 2;
    y = (ph - dh) / 2;
    ZeroMemory(&bi, sizeof bi);
    bi.bmiHeader.biSize = sizeof bi.bmiHeader;
    bi.bmiHeader.biWidth = iw;
    bi.bmiHeader.biHeight = -ih;
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 24;
    bi.bmiHeader.biCompression = BI_RGB;
    /* a 24 bit row is padded to four bytes: pad the rows */
    {
        int stride = (iw * 3 + 3) & ~3;
        unsigned char *padded = (unsigned char *)calloc((size_t)stride, (size_t)ih);

        if (padded) {
            for (j = 0; j < ih; j++)
                memcpy(padded + (size_t)j * stride, pix + (size_t)j * iw * 3, (size_t)iw * 3);
            free(pix);
            bits = pix = padded;
        }
    }
    ZeroMemory(&di, sizeof di);
    di.cbSize = sizeof di;
    di.lpszDocName = L"Jw_cad";
    if (to_file && *to_file)
        di.lpszOutput = to_file;
    if (StartDocW(dc, &di) > 0) {
        StartPage(dc);
        SetStretchBltMode(dc, HALFTONE);
        StretchDIBits(dc, x, y, dw, dh, 0, 0, iw, ih, bits, &bi, DIB_RGB_COLORS, SRCCOPY);
        EndPage(dc);
        EndDoc(dc);
    }
    free(pix);
    jw_img_free(&im);
    DeleteDC(dc);
    if (pd.hDevMode)
        GlobalFree(pd.hDevMode);
    if (pd.hDevNames)
        GlobalFree(pd.hDevNames);
    return 1;
}

/* The right button does two jobs: dragged it moves the drawing, clicked it is
 * a point for the command in force -- which is what the original's status
 * line means by "(R)".  Which one it was is settled on the way up, by whether
 * it moved: a couple of pixels of shake while clicking should not count. */
#define DRAG_SLOP 3

static LRESULT CALLBACK wndproc(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
{
    static int dragging, moved, lastx, lasty, downx, downy;

    switch (msg) {
    case WM_MOUSEWHEEL: {
        POINT p;
        p.x = (short)LOWORD(lp);
        p.y = (short)HIWORD(lp);
        ScreenToClient(wnd, &p);
        app_zoom((short)HIWORD(wp) > 0 ? 1.25 : 1.0 / 1.25, p.x / uiscale, p.y / uiscale);
        app_paint();
        InvalidateRect(wnd, NULL, FALSE);
        return 0;
    }
    case WM_LBUTTONDOWN: {
        int redraw;
        app_keymods((wp & MK_SHIFT) != 0, (wp & MK_CONTROL) != 0);
        redraw = app_press(MX(LOWORD(lp)), MX(HIWORD(lp)), 0);
        redraw |= do_action(wnd);
        if (redraw) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    }
    case WM_LBUTTONUP:
        if (app_release(MX(LOWORD(lp)), MX(HIWORD(lp)), 0)) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
        dragging = 1;
        moved = 0;
        lastx = downx = MX(LOWORD(lp));
        lasty = downy = MX(HIWORD(lp));
        SetCapture(wnd);
        return 0;
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
        dragging = 0;
        ReleaseCapture();
        app_keymods((wp & MK_SHIFT) != 0, (wp & MK_CONTROL) != 0);
        if (msg == WM_RBUTTONUP && !moved
            && app_press(MX(LOWORD(lp)), MX(HIWORD(lp)), 1)) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    case WM_MOUSEMOVE: {
        int x = MX(LOWORD(lp)), y = MX(HIWORD(lp));
        if (dragging) {
            if (abs(x - downx) > DRAG_SLOP || abs(y - downy) > DRAG_SLOP)
                moved = 1;
            app_pan(x - lastx, y - lasty);
            lastx = x;
            lasty = y;
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        } else if (app_move(x, y)) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    }
    /* Typing for the 文字 command.  Plain bytes arrive as WM_CHAR already in
     * the system code page, which here is CP932 -- the same bytes the drawing
     * stores -- so nothing has to be converted.  A kanji conversion comes in
     * one piece as the IME's result string, in the same code page. */
    case WM_CHAR:
        /* 0x1b as well: Esc lets go of the points the command has taken, and
           it was being dropped here along with the other control codes.
           13 (Enter) used to be dropped the same way -- the 文字 box takes
           it as nothing (app_key already declines it in text mode), but a
           settled 複写・移動 range takes it as 範囲確定 (jw_cmd_enter_key),
           so it has to reach app_key too.  Shift held at the same time is
           ShiftEnter-基点変更 instead (RESUME.md 2026-10-13); WM_CHAR does
           not carry that in wp, so GetKeyState reads it here, while the key
           is actually down. */
        if (wp == 13) {
            int done = (GetKeyState(VK_SHIFT) & 0x8000) ? app_shift_enter() : 0;
            if (!done)
                done = app_key(13);
            done |= do_action(wnd);     /* Enter が残した 外部エディタ・外部変形 など */
            if (done) {
                app_paint();
                InvalidateRect(wnd, NULL, FALSE);
            }
            return 0;
        }
        if (wp >= 0x20 || wp == 8 || wp == 27) {
            int done = app_key((int)wp);

            done |= do_action(wnd);
            if (done) {
                app_paint();
                InvalidateRect(wnd, NULL, FALSE);
            }
        }
        return 0;
    case WM_IME_COMPOSITION:
        if (lp & GCS_COMPSTR) {
            /* what is still being converted: shown in the box, underlined */
            HIMC imc = ImmGetContext(wnd);
            app_compose(-1);
            if (imc) {
                char buf[512];
                LONG n = ImmGetCompositionStringA(imc, GCS_COMPSTR,
                                                  buf, sizeof buf);
                LONG i;
                for (i = 0; i < n; i++)
                    app_compose((unsigned char)buf[i]);
                ImmReleaseContext(wnd, imc);
            }
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        if (lp & GCS_RESULTSTR) {
            HIMC imc = ImmGetContext(wnd);
            if (imc) {
                char buf[512];
                LONG n = ImmGetCompositionStringA(imc, GCS_RESULTSTR,
                                                  buf, sizeof buf);
                LONG i;
                for (i = 0; i < n; i++)
                    app_key((unsigned char)buf[i]);
                ImmReleaseContext(wnd, imc);
                app_compose(-1);
                if (n > 0) {
                    app_paint();
                    InvalidateRect(wnd, NULL, FALSE);
                }
            }
            return 0;
        }
        break;
    case WM_KEYDOWN:
        if (wp == VK_HOME) {
            app_fit();
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    case WM_COMMAND:
        if ((HIWORD(wp) == 0 || HIWORD(wp) == 1)
            && LOWORD(wp) >= RECENT_ID && LOWORD(wp) < RECENT_ID + NRECENT) {
            wchar_t path[MAX_PATH];

            lstrcpynW(path, recent[LOWORD(wp) - RECENT_ID], MAX_PATH);
            if (load_file(path)) {
                app_paint();
                InvalidateRect(wnd, NULL, FALSE);
            }
            return 0;
        }
        if (HIWORD(wp) == 0 || HIWORD(wp) == 1) {       /* menu or accelerator */
            do_command(wnd, LOWORD(wp));
            return 0;
        }
        break;
    case WM_INITMENUPOPUP:
        /* Tick the command in force, which is what the original's
           ON_UPDATE_COMMAND_UI does: SetCheck(current == id). */
        {
            HMENU m = (HMENU)wp;
            int n = GetMenuItemCount(m), k;
            for (k = 0; k < n; k++) {
                UINT id = GetMenuItemID(m, k);
                if (id != (UINT)-1 && id != 0) {
                    int st = app_menu_state((int)id);

                    CheckMenuItem(m, id,
                                  MF_BYCOMMAND | (((int)id == jw_cmd()
                                                   || (st & 1))
                                                  ? MF_CHECKED : MF_UNCHECKED));
                    EnableMenuItem(m, id, MF_BYCOMMAND
                                   | ((st & 2) ? MF_GRAYED : MF_ENABLED));
                }
            }
        }
        return 0;
    case WM_SIZE:
        if (app_resize(LOWORD(lp) / uiscale, HIWORD(lp) / uiscale))
            app_paint();
        return 0;
    case WM_CLOSE:
        if (!ask_save_changes(wnd))
            return 0;                   /* cancelled: stay */
        user_closed = 1;
        break;                          /* DefWindowProc destroys the window */
    case WM_QUERYENDSESSION:
        autosave_write();               /* Windows is going down: keep a copy at least */
        return TRUE;
    case WM_TIMER:
        if (wp == 1)
            autosave_write();
        return 0;
    case WM_DROPFILES: {
        wchar_t dropped[MAX_PATH];

        if (DragQueryFileW((HDROP)wp, 0, NULL, 0) < MAX_PATH - 1
            && DragQueryFileW((HDROP)wp, 0, dropped, MAX_PATH) && open_any(wnd, dropped)) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        DragFinish((HDROP)wp);
        return 0;
    }
    case 0x02E0: {                      /* WM_DPICHANGED: another screen, another scale */
        const RECT *r = (const RECT *)lp;
        UINT dpi = HIWORD(wp);
        int ns = (int)((dpi + 48) / 96);

        if (ns < 1) ns = 1;
        if (ns > 4) ns = 4;
        uiscale = ns;
        SetWindowPos(wnd, NULL, r->left, r->top, r->right - r->left, r->bottom - r->top,
                     SWP_NOZORDER | SWP_NOACTIVATE);
        return 0;
    }
    case WM_ERASEBKGND:
        return 1;                       /* the repaint covers everything */
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC dc = BeginPaint(wnd, &ps);
        present(dc);
        EndPaint(wnd, &ps);
        return 0;
    }
    case WM_DESTROY:
        KillTimer(wnd, 1);
        placement_save(wnd);
        if (user_closed || !app_modified())
            autosave_clear();           /* a clean end: nothing to recover */
        ini_save();
        settings_save();
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(wnd, msg, wp, lp);
}

/* The configuration (app_save_env, a .jwf) is kept in %APPDATA%\jw_port between
   runs: read at start, written when the window is closed. */
static int settings_path_of(wchar_t *p, const wchar_t *name)
{
    wchar_t dir[MAX_PATH];

    if (!GetEnvironmentVariableW(L"APPDATA", dir, MAX_PATH))
        return 0;
    swprintf(p, MAX_PATH, L"%ls%cjw_port", dir, (wchar_t)92);
    CreateDirectoryW(p, NULL);
    swprintf(p, MAX_PATH, L"%ls%cjw_port%c%ls", dir, (wchar_t)92, (wchar_t)92, name);
    return 1;
}

static int settings_path(wchar_t *p)
{
    return settings_path_of(p, L"settings.jwf");
}

/* and beside it what the original keeps in its registry (app_prefs_write:
   基本設定 の箱と押し釦、寸法設定 の押し釦), read and written with it */
static void prefs_load(void)
{
    wchar_t p[MAX_PATH];
    FILE *f;
    long n;
    unsigned char *b;

    if (!settings_path_of(p, L"jw_win_reg.txt") || !(f = _wfopen(p, L"rb")))
        return;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)(n > 0 ? n : 1));
    if (b && n > 0 && fread(b, 1, (size_t)n, f) == (size_t)n)
        app_prefs_read(b, n);
    fclose(f);
    free(b);
}

static void prefs_save(void)
{
    wchar_t p[MAX_PATH];
    unsigned char *b = 0;
    long n = 0;
    FILE *f;

    if (!settings_path_of(p, L"jw_win_reg.txt") || !app_prefs_write(&b, &n))
        return;
    f = _wfopen(p, L"wb");
    if (f) {
        fwrite(b, 1, (size_t)n, f);
        fclose(f);
    }
    free(b);
}

static void settings_load(void)
{
    wchar_t p[MAX_PATH];
    FILE *f;
    long n;
    unsigned char *b;

    if (!settings_path(p) || !(f = _wfopen(p, L"rb"))) {
        prefs_load();
        return;
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)(n > 0 ? n : 1));
    if (b && n > 0 && fread(b, 1, (size_t)n, f) == (size_t)n)
        app_open_env(b, n);
    fclose(f);
    free(b);
    prefs_load();
}

static void settings_save(void)
{
    wchar_t p[MAX_PATH];
    unsigned char *b = 0;
    long n = 0;
    FILE *f;

    prefs_save();
    if (!settings_path(p) || !app_save_env("settings.jwf", &b, &n))
        return;
    f = _wfopen(p, L"wb");
    if (f) {
        fwrite(b, 1, (size_t)n, f);
        fclose(f);
    }
    free(b);
}

int WINAPI wWinMain(HINSTANCE inst, HINSTANCE prev, PWSTR cmd, int show)
{
    jw_img_set_loader(img_loader);
    WNDCLASSEXW wc;
    RECT r;
    HWND wnd;
    HACCEL accel;
    MSG msg;

    (void)prev;
    {   /* the outline fonts are read from fonts/ beside the exe */
        wchar_t w[MAX_PATH];
        char dir[MAX_PATH * 2];
        DWORD k = GetModuleFileNameW(NULL, w, MAX_PATH);

        while (k > 0 && w[k - 1] != L'\\' && w[k - 1] != L'/')
            k--;
        if (k > 0 && k < MAX_PATH - 8) {
            wcscpy(w + k, L"fonts");
            BOOL lost = FALSE;

            dir[0] = 0;
            if (!WideCharToMultiByte(CP_ACP, WC_NO_BEST_FIT_CHARS, w, -1, dir, sizeof dir, NULL, &lost) || lost) {
                wchar_t sh[MAX_PATH];

                if (GetShortPathNameW(w, sh, MAX_PATH))
                    WideCharToMultiByte(CP_ACP, 0, sh, -1, dir, sizeof dir, NULL, NULL);
            }
            if (dir[0])
                jw_outfont_dir(dir);
        }
    }
    jw_outfont_enable(1);               /* IPAex for every face */
    dpi_init();
    english = lang_is_english();
    app_new();
    ini_load();
    settings_load();
    open_arg(cmd);
    ZeroMemory(&wc, sizeof wc);
    wc.cbSize = sizeof wc;
    wc.lpfnWndProc = wndproc;
    wc.hInstance = inst;
    wc.hCursor = LoadCursorW(NULL, IDC_ARROW);
    wc.lpszClassName = CLASS_NAME;
    RegisterClassExW(&wc);

    /* the reference screens are of a 1264x741 client area */
    r.left = 0;
    r.top = 0;
    r.right = 1264 * uiscale;
    r.bottom = 741 * uiscale;
    /* TRUE: with a menu bar on it, which is one row taller */
    AdjustWindowRectEx(&r, WS_OVERLAPPEDWINDOW, TRUE, 0);

    main_wnd = NULL;
    wnd = CreateWindowExW(0, CLASS_NAME, L"jw_win (port)", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          r.right - r.left, r.bottom - r.top,
                          NULL, NULL, inst, NULL);
    if (!wnd)
        return 1;
    main_wnd = wnd;
    sync_doc();                         /* the title: a drawing opened from the command line */
    SetMenu(wnd, build_menu());
    accel = build_accel();
    DragAcceptFiles(wnd, TRUE);
    show = placement_restore(wnd, show);
    ShowWindow(wnd, show);
    {
        const wchar_t *sec = _wgetenv(L"JW_AUTOSAVE_SEC");
        int secs = sec ? _wtoi(sec) : 120;

        SetTimer(wnd, 1, (UINT)((secs > 0 ? secs : 120) * 1000), NULL);
    }
    autosave_recover(wnd);

    while (GetMessageW(&msg, NULL, 0, 0) > 0) {
        if (accel && TranslateAcceleratorW(wnd, accel, &msg))
            continue;
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
