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
#include <stdio.h>
#include <stdlib.h>

#include "app.h"

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

static LRESULT CALLBACK wndproc(HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
{
    static int dragging, lastx, lasty;

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
        switch (app_take_action()) {
        case JW_ACT_OPEN:
            redraw |= ask_open(wnd);
            break;
        case JW_ACT_SAVE:
            if (current_path[0])
                save_file(current_path);
            else
                ask_save(wnd);
            break;
        case JW_ACT_SAVE_AS:
            ask_save(wnd);
            break;
        }
        if (redraw) {
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
        }
        return 0;
    }
    case WM_MBUTTONDOWN:
    case WM_RBUTTONDOWN:
        dragging = 1;
        lastx = (short)LOWORD(lp);
        lasty = (short)HIWORD(lp);
        SetCapture(wnd);
        return 0;
    case WM_MBUTTONUP:
    case WM_RBUTTONUP:
        dragging = 0;
        ReleaseCapture();
        return 0;
    case WM_MOUSEMOVE: {
        int x = (short)LOWORD(lp), y = (short)HIWORD(lp);
        if (dragging) {
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
    case WM_KEYDOWN:
        if (wp == VK_HOME) {
            app_fit();
            app_paint();
            InvalidateRect(wnd, NULL, FALSE);
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
    AdjustWindowRectEx(&r, WS_OVERLAPPEDWINDOW, FALSE, 0);

    wnd = CreateWindowExW(0, CLASS_NAME, L"jw_win (port)", WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT,
                          r.right - r.left, r.bottom - r.top,
                          NULL, NULL, inst, NULL);
    if (!wnd)
        return 1;
    ShowWindow(wnd, show);

    while (GetMessageW(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}
