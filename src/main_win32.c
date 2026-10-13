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
    swprintf(p, MAX_PATH, L"%s%cjw_port", dir, (wchar_t)92);
    CreateDirectoryW(p, NULL);
    swprintf(p, MAX_PATH, L"%s%cjw_port%cjw_port.ini", dir, (wchar_t)92, (wchar_t)92);
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
    lstrcpyW(cmd, L"notepad.exe \"");
    lstrcatW(cmd, path);
    lstrcatW(cmd, L"\"");
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
    b = png ? jw_plot_png(app_drawing(), 4.0, 0, &n)
            : jw_plot_pdf(app_drawing(), 0, &n);
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
    if (j)
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

    HMENU file_popup = NULL;

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
            if (d == 0 && !file_popup)
                file_popup = sub;
            break;
        }
        case 2:
            AppendMenuW(stack[d], MF_SEPARATOR, 0, NULL);
            break;
        default:
            wide(m->text, text, 256);
            AppendMenuW(stack[d], MF_STRING, m->id, text);
            break;
        }
    }
    if (file_popup && recent[0][0]) {
        /* the files opened last, under the file menu */
        AppendMenuW(file_popup, MF_SEPARATOR, 0, NULL);
        for (i = 0; i < NRECENT && recent[i][0]; i++) {
            wchar_t t[MAX_PATH + 8];

            swprintf(t, MAX_PATH + 8, L"&%d %s", i + 1, recent[i]);
            AppendMenuW(file_popup, MF_STRING, RECENT_ID + i, t);
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
    wchar_t dir[MAX_PATH], cmd[MAX_PATH + 160], *sl, wargs[160];
    unsigned char *t = 0, *back = 0;
    long tn = 0, kn = 0;
    char args[128], msg[160];
    FILE *f;
    int r;
    STARTUPINFOW si;
    PROCESS_INFORMATION pi;

    (void)wnd;
    args[0] = 0;
    if (app_gaibu_run_begin(&t, &tn, args, (int)sizeof args) != 1) {
        app_gaibu_run_end();
        return 0;
    }
    wcscpy(dir, gaibu_bat);
    sl = wcsrchr(dir, (wchar_t)92);
    if (sl)
        *sl = 0;
    SetCurrentDirectoryW(dir);
    f = _wfopen(L"JWC_TEMP.TXT", L"wb");
    if (!f) {
        free(t);
        app_gaibu_run_end();
        return 0;
    }
    fwrite(t, 1, (size_t)tn, f);
    fclose(f);
    free(t);
    MultiByteToWideChar(932, 0, args, -1, wargs, 160);
    swprintf(cmd, MAX_PATH + 160, L"\"%s\" %s", gaibu_bat, wargs);
    ZeroMemory(&si, sizeof si);
    si.cb = sizeof si;
    if (CreateProcessW(NULL, cmd, NULL, NULL, FALSE, 0, NULL, dir, &si, &pi)) {
        WaitForSingleObject(pi.hProcess, INFINITE);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
    }
    f = _wfopen(L"JWC_TEMP.TXT", L"rb");
    if (!f) {
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
        swprintf(cmd, 2 * MAX_PATH + 16, L"\"%s%cNOTEPAD.EXE\" \"%s\"", win, (wchar_t)92, tmp);
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
    SetDIBitsToDevice(dc, 0, 0, fb->w, fb->h, 0, 0, 0, fb->h,
                      fb->px, &bi, DIB_RGB_COLORS);
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
        app_zoom((short)HIWORD(wp) > 0 ? 1.25 : 1.0 / 1.25, p.x, p.y);
        app_paint();
        InvalidateRect(wnd, NULL, FALSE);
        return 0;
    }
    case WM_LBUTTONDOWN: {
        int redraw = app_press((short)LOWORD(lp), (short)HIWORD(lp), 0);
        redraw |= do_action(wnd);
        if (redraw) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    }
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
        dragging = 1;
        moved = 0;
        lastx = downx = (short)LOWORD(lp);
        lasty = downy = (short)HIWORD(lp);
        SetCapture(wnd);
        return 0;
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
        dragging = 0;
        ReleaseCapture();
        if (msg == WM_RBUTTONUP && !moved
            && app_press((short)LOWORD(lp), (short)HIWORD(lp), 1)) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    case WM_MOUSEMOVE: {
        int x = (short)LOWORD(lp), y = (short)HIWORD(lp);
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
            if (done) {
                app_paint();
                InvalidateRect(wnd, NULL, FALSE);
            }
            return 0;
        }
        if (wp >= 0x20 || wp == 8 || wp == 27) {
            if (app_key((int)wp)) {
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
        if (app_resize(LOWORD(lp), HIWORD(lp)))
            app_paint();
        return 0;
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
        ini_save();
        settings_save();
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(wnd, msg, wp, lp);
}

/* The configuration (app_save_env, a .jwf) is kept in %APPDATA%\jw_port between
   runs: read at start, written when the window is closed. */
static int settings_path(wchar_t *p)
{
    wchar_t dir[MAX_PATH];

    if (!GetEnvironmentVariableW(L"APPDATA", dir, MAX_PATH))
        return 0;
    swprintf(p, MAX_PATH, L"%s%cjw_port", dir, (wchar_t)92);
    CreateDirectoryW(p, NULL);
    swprintf(p, MAX_PATH, L"%s%cjw_port%csettings.jwf", dir, (wchar_t)92, (wchar_t)92);
    return 1;
}

static void settings_load(void)
{
    wchar_t p[MAX_PATH];
    FILE *f;
    long n;
    unsigned char *b;

    if (!settings_path(p) || !(f = _wfopen(p, L"rb")))
        return;
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    b = (unsigned char *)malloc((size_t)(n > 0 ? n : 1));
    if (b && n > 0 && fread(b, 1, (size_t)n, f) == (size_t)n)
        app_open_env(b, n);
    fclose(f);
    free(b);
}

static void settings_save(void)
{
    wchar_t p[MAX_PATH];
    unsigned char *b = 0;
    long n = 0;
    FILE *f;

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
            if (WideCharToMultiByte(CP_ACP, 0, w, -1, dir, sizeof dir, NULL, NULL))
                jw_outfont_dir(dir);
        }
    }
    jw_outfont_enable(1);               /* IPAex for every face */
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
    r.right = 1264;
    r.bottom = 741;
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
    SetMenu(wnd, build_menu());
    accel = build_accel();
    ShowWindow(wnd, show);

    while (GetMessageW(&msg, NULL, 0, 0) > 0) {
        if (accel && TranslateAcceleratorW(wnd, accel, &msg))
            continue;
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
