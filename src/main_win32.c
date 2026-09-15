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

#include "app.h"

static const wchar_t CLASS_NAME[] = L"JwWinWasmPort";

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
    switch (msg) {
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
    (void)cmd;
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
