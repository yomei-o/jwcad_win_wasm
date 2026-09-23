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
#include "cmd.h"
#include "cp932.h"
#include "gen/accel.h"
#include "gen/menu.h"

static const wchar_t CLASS_NAME[] = L"JwWinWasmPort";

/* The file the drawing came from, so 上書 knows where to put it back. */
static wchar_t current_path[MAX_PATH];

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
    if (ok)
        lstrcpynW(current_path, path, MAX_PATH);
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
    if (ok)
        lstrcpynW(current_path, path, MAX_PATH);
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

/* DXFファイルを開く.  The drawing it makes is not the file that 上書
 * writes, so what was open stays the file it came from. */
static int open_dxf(HWND wnd)
{
    static const wchar_t filter[] = L"DXF (*.dxf)\0*.dxf\0\0";
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
        ok = app_open_dxf(b, n);
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

/* A command from a menu item is taken the same way a toolbar press is: what
   needs a file or a dialog comes back through app_take_action().
   Whatever app_command() or app_press() asked for that needs a file or a
   dialog.  Only 開く changes what is on screen. */
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
        return open_dxf(wnd);
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
        if (wp >= 0x20 || wp == 8) {
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
                if (id != (UINT)-1 && id != 0)
                    CheckMenuItem(m, id,
                                  MF_BYCOMMAND | ((int)id == jw_cmd()
                                                  ? MF_CHECKED : MF_UNCHECKED));
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
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProcW(wnd, msg, wp, lp);
}

int WINAPI wWinMain(HINSTANCE inst, HINSTANCE prev, PWSTR cmd, int show)
{
    WNDCLASSEXW wc;
    RECT r;
    HWND wnd;
    HACCEL accel;
    MSG msg;

    (void)prev;
    app_new();
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

    wnd = CreateWindowExW(0, CLASS_NAME, L"jw_win (port)", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          r.right - r.left, r.bottom - r.top,
                          NULL, NULL, inst, NULL);
    if (!wnd)
        return 1;
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
