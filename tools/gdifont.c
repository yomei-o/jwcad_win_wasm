/* Ask real Windows GDI what it does with the CreateFontW the original makes
 * for 斜体 (italic) and 太字 (bold), on faces that have no italic/bold
 * variant of their own (ＭＳ ゴシック, ＭＳ 明朝) -- the same CreateFontW
 * call FUN_0048b130 makes (decomp/decomp/all_004894cd.c:1116-1119):
 *
 *   FID_conflict_CreateFontW(nHeight, nWidth, 0, 0, weight, italic, 0, 0,
 *                             1 (DEFAULT_CHARSET), 0, 0, 2 (PROOF_QUALITY),
 *                             6 (VARIABLE_PITCH|FF_DONTCARE), faceName)
 *
 * weight is 400 or 700 (param_7 != 0 ? 700 : 400, line 1097-1098 of the
 * same file); italic is param_6 as a boolean 0/1 (斜体, +0xdc bit 0).
 *
 * Nothing is captured from a screen or a window: everything is drawn to an
 * in-memory 32bpp DIB section with GDI directly, on this native Windows
 * machine -- the same technique as tools/gdiwide.c and tools/gdipoly.c.
 * This sidesteps the exe entirely for the *synthesis* (what GDI's font
 * engine does with lfWeight/lfItalic), which lives outside the exe anyway
 * (gdi32's font engine, not something to decompile); the exe-side fact
 * (which values it passes) is read from the decompilation above, not
 * guessed.
 *
 *   gcc -O2 -o tmp/gdifont.exe tools/gdifont.c -lgdi32
 *   ./tmp/gdifont.exe
 */
#include <windows.h>
#include <stdio.h>
#include <string.h>

#define W 900
#define H 900

static HDC dc;
static unsigned *px;

static HFONT mkfont(int height, int weight, int italic, const wchar_t *face)
{
    return CreateFontW(height, 0, 0, 0, weight, (DWORD)italic, 0, 0,
                        1 /* DEFAULT_CHARSET */, 0, 0, 2 /* PROOF_QUALITY */,
                        6 /* VARIABLE_PITCH|FF_DONTCARE */, face);
}

static void clear(void)
{
    int i;
    for (i = 0; i < W * H; i++)
        px[i] = 0xffffff;
}

/* leftmost/rightmost ink column of row y; -1/-1 if the row is blank */
static void row_span(int y, int *l, int *r)
{
    int x;
    *l = -1; *r = -1;
    for (x = 0; x < W; x++)
        if (px[(size_t)y * W + x] != 0xffffff) {
            if (*l < 0) *l = x;
            *r = x;
        }
}

/* total ink pixels (any channel darker than white) in the whole bitmap */
static long ink_count(void)
{
    long n = 0;
    int i;
    for (i = 0; i < W * H; i++)
        if (px[i] != 0xffffff)
            n++;
    return n;
}

static void draw1(const wchar_t *s, HFONT f)
{
    HFONT old;
    clear();
    old = (HFONT)SelectObject(dc, f);
    SetBkMode(dc, TRANSPARENT);
    SetTextColor(dc, RGB(0, 0, 0));
    TextOutW(dc, 40, 40, s, (int)wcslen(s));
    SelectObject(dc, old);
}

/* Height h: find the topmost and bottommost ink rows, then the midpoint of
   the ink span on each, and report how far the bottom span's centre sits
   from the top span's (positive = the top leans right of the foot, which is
   how the original's own box-widening math points -- see outfont.c and
   nokori.md "書体"). */
static void measure_lean(const wchar_t *s, int height, const wchar_t *face)
{
    HFONT f = mkfont(-height, 400, 1 /* italic */, face);
    int y0 = -1, y1 = -1, y;
    double top_mid = 0, bot_mid = 0;
    int l, r;

    if (!f) { printf("  (no font)\n"); return; }
    draw1(s, f);
    for (y = 0; y < H; y++) {
        row_span(y, &l, &r);
        if (l >= 0) { if (y0 < 0) y0 = y; y1 = y; }
    }
    if (y0 < 0) { printf("  (blank)\n"); DeleteObject(f); return; }
    row_span(y0, &l, &r); top_mid = (l + r) / 2.0;
    row_span(y1, &l, &r); bot_mid = (l + r) / 2.0;
    printf("  h=%d  rows %d..%d (%d)  top_mid=%.1f bot_mid=%.1f  "
           "lean=%.3f (dx/dy, +x per +1 up)\n",
           height, y0, y1, y1 - y0, top_mid, bot_mid,
           (top_mid - bot_mid) / (y1 - y0));
    DeleteObject(f);
}

/* Height h: compare the stroke width of a single vertical stem ('I') at
   weight 400 vs 700, by scanning a row through the middle of the glyph and
   counting the run of ink pixels there. */
static void measure_bold(const wchar_t *s, int height, const wchar_t *face)
{
    HFONT f0 = mkfont(-height, 400, 0, face), f1 = mkfont(-height, 700, 0, face);
    int y0, y1, ymid, l, r, w0, w1;
    long ink0, ink1;

    if (!f0 || !f1) { printf("  (no font)\n"); return; }
    draw1(s, f0);
    for (y0 = 0; y0 < H; y0++) { row_span(y0, &l, &r); if (l >= 0) break; }
    for (y1 = H - 1; y1 >= 0; y1--) { row_span(y1, &l, &r); if (l >= 0) break; }
    ymid = (y0 + y1) / 2;
    row_span(ymid, &l, &r);
    w0 = (l >= 0) ? r - l + 1 : 0;
    ink0 = ink_count();

    draw1(s, f1);
    row_span(ymid, &l, &r);
    w1 = (l >= 0) ? r - l + 1 : 0;
    ink1 = ink_count();

    printf("  h=%d  stem width @row%d: regular=%d bold=%d (+%d, "
           "+%.4f*h)  ink: regular=%ld bold=%ld (x%.3f)\n",
           height, ymid, w0, w1, w1 - w0,
           (double)(w1 - w0) / height, ink0, ink1, (double)ink1 / ink0);
    DeleteObject(f0);
    DeleteObject(f1);
}

int main(void)
{
    HBITMAP bm, old;
    BITMAPINFO bi;
    /* ＭＳ ゴシック, ＭＳ 明朝 in CP932 */
    unsigned char gothic_cp932[] = {0x82,0x6c,0x82,0x72,0x20,0x83,0x53,0x83,
                                     0x56,0x83,0x62,0x83,0x4e,0};
    unsigned char mincho_cp932[] = {0x82,0x6c,0x82,0x72,0x20,0x96,0xbe,0x92,
                                     0xa9,0};
    wchar_t gothic[32], mincho[32];
    int hs[] = { 30, 60, 100, 200, 400 };
    int hs2[] = { 12, 16, 20, 24, 32, 48, 64 };
    int i;

    memset(&bi, 0, sizeof bi);
    bi.bmiHeader.biSize = sizeof bi.bmiHeader;
    bi.bmiHeader.biWidth = W;
    bi.bmiHeader.biHeight = -H;        /* top-down */
    bi.bmiHeader.biPlanes = 1;
    bi.bmiHeader.biBitCount = 32;
    bi.bmiHeader.biCompression = BI_RGB;

    dc = CreateCompatibleDC(NULL);
    bm = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, (void **)&px, NULL, 0);
    old = (HBITMAP)SelectObject(dc, bm);
    (void)old;

    MultiByteToWideChar(932, 0, (char *)gothic_cp932, -1, gothic, 32);
    MultiByteToWideChar(932, 0, (char *)mincho_cp932, -1, mincho, 32);

    printf("-- italic lean, MS Gothic, \"III\" (vertical stems only) --\n");
    for (i = 0; i < 5; i++)
        measure_lean(L"III", hs[i], gothic);
    printf("-- italic lean, MS Mincho --\n");
    for (i = 0; i < 5; i++)
        measure_lean(L"III", hs[i], mincho);

    printf("-- bold stem widening, MS Gothic, \"I\" --\n");
    for (i = 0; i < 5; i++)
        measure_bold(L"I", hs[i], gothic);
    printf("-- bold stem widening, MS Mincho --\n");
    for (i = 0; i < 5; i++)
        measure_bold(L"I", hs[i], mincho);

    printf("-- bold stem widening, Arial (has a real bold -- for contrast) --\n");
    for (i = 0; i < 5; i++)
        measure_bold(L"I", hs[i], L"Arial");

    printf("-- bold stem widening, MS Gothic, finer steps at the sizes "
           "this port actually draws text at (tests/font_test.c: ch=8mm "
           "at 0.25mm/px = 32px) --\n");
    for (i = 0; i < 7; i++)
        measure_bold(L"I", hs2[i], gothic);
    printf("-- same, MS Mincho --\n");
    for (i = 0; i < 7; i++)
        measure_bold(L"I", hs2[i], mincho);
    printf("-- bold stem widening, MS Gothic, \"H\" (a different glyph, "
           "for a sanity check against \"I\") --\n");
    for (i = 0; i < 7; i++)
        measure_bold(L"H", hs2[i], gothic);

    return 0;
}
