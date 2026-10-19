/* 字の長さ、間隔 0.01 の枝（FUN_00493410: decomp/decomp/all_004894cd.c:
 * 5299-5368）の読みを 実測で裏付ける。src/outfont.c jw_outfont_text_width
 * は GDI を呼ばず（WASM 版でも同じ値になるように）、stb_truetype の字形
 * データから
 *
 *     Σ_i advance_i(font units) / (F[].asc - F[].desc)
 *
 * を計算している。これは FUN_00493410 の式
 *
 *     measured_px / DAT_009fe124 * 幅(mm)
 *       where measured_px = GetTextExtentExPointW(..., フォント高さ = DAT_009fe124)
 *
 * から DAT_009fe124 が約分されて消える、という手計算の結果（outfont.c の
 * 注）であって、原典・この port のどちらでも GDI の `GetTextExtentExPointW`
 * そのものを呼んで確かめたわけではない。ここでは `Jw_win.exe` を一切動か
 * さず、この port が同梱する TrueType（fonts/jwsubgothic.ttf・
 * jwsubmincho.ttf、中身は IPAexGothic・IPAexMincho の字形データそのもの）
 * を `AddFontResourceExW`（プロセス専用、他に影響しない）で読み込み、
 * 実物の GDI に `GetTextExtentExPointW` を呼ばせて、同じフォントファイル
 * を stb_truetype で読んだ advance の和から出す上の式と比べる。
 *
 * 期待: 両者は（GDI 側の整数画素への丸めを除けば）一致するはず。一致すれば
 * 「DAT_009fe124 が約分される」という手計算が この２つのフォントファイルに
 * ついて実際に正しいことの裏付けになる。GDI 側の整数丸めの誤差が高さ H を
 * 大きくするほど小さくなることも 一緒に出す。
 *
 * 結果（2026-10-19、このマシンで実測。ログは下の表そのもの）:
 *   JwSubGothic「ABCDE」「WWWWW」「iiiii」・JwSubMincho「ABCDE」「WWWWW」の
 *   いずれも、H=50 で ±0.2〜3.6%、H=200 で ±0.2% 未満、H=800 で ±0.06% 未満
 *   まで縮み、GDI 側の整数画素丸め（cx は int）で説明できる差しか残らない。
 *   `jw_outfont_text_width` の Σadvance/(asc-desc) という式が、この２つの
 *   フォントファイルについて GetTextExtentExPointW と確かに同じ量を計算して
 *   いることを 実測で確認した（(asc-desc) と upem が この２ファイルでは
 *   たまたま同値〔どちらも 2048〕なので、この実測だけでは「DAT_009fe124 が
 *   割るべきは asc-desc か upem か」という一般論までは決められない。
 *   jw_outfont_run の注（758-803 行）はこれとは別に、Windows の負の
 *   lfHeight が font の design em（head.unitsPerEm）を |lfHeight| に写す、
 *   という GDI の文書化された仕様から upem 側を使っており、両者が一致する
 *   のはこの２ファイルの設計がたまたま asc-desc == upem だから）。
 *
 * 脇道（このツールを書く過程で踏んだ地雷、本筋ではないが記録）:
 *   最初 lfFaceName に src/outfont.c の F[].name どおり "IPAexGothic"・
 *   "IPAexMincho" を渡したところ GDI が別フォントへすり替えて測り、両者が
 *   同じ cx を返す明らかにおかしい結果になった。`EnumFontFamiliesExW` で
 *   確かめると、fonts/jwsubgothic.ttf・jwsubmincho.ttf 自体の name テーブル
 *   はそれぞれ "JwSubGothic"・"JwSubMincho" に改名されており、"IPAexGothic"
 *   という家族名の私的フォントは存在しなかった。F[].name はこの port 内部の
 *   論理名（JWW の書体名の表引き用）であって TTF の実際の家族名ではない、
 *   という区別に気づかないまま GDI へ渡すと静かに違うフォントを測ってしまう
 *   ことが分かったので、残しておく。
 *
 * ビルド:
 *   gcc -O2 -o tmp/gditextwidth.exe tools/gditextwidth.c -lgdi32
 *   ./tmp/gditextwidth.exe
 */
#include <windows.h>
#include <stdio.h>
#include <string.h>

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wunused-function"
#pragma GCC diagnostic ignored "-Wunused-parameter"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif
#define STB_TRUETYPE_IMPLEMENTATION
#define STBTT_STATIC
#include "../src/stb_truetype.h"

static unsigned char *read_file(const char *path, long *len)
{
    FILE *f = fopen(path, "rb");
    unsigned char *buf;
    long n;

    if (!f) {
        fprintf(stderr, "open %s: failed\n", path);
        exit(1);
    }
    fseek(f, 0, SEEK_END);
    n = ftell(f);
    fseek(f, 0, SEEK_SET);
    buf = (unsigned char *)malloc(n);
    fread(buf, 1, n, f);
    fclose(f);
    *len = n;
    return buf;
}

/* jw_outfont_text_width と同じ式（src/outfont.c 660-678 行）: ASCII のみの
 * 文字列について Σ advance_i / (asc-desc) を 1 字ずつ足す。`denom` に
 * (asc-desc) か upem のどちらかを渡して どちらが GDI と合うか比べる。 */
static double stb_ratio(stbtt_fontinfo *info, double denom, const char *s)
{
    double sum = 0.0;

    for (; *s; s++) {
        int gl = stbtt_FindGlyphIndex(info, (unsigned char)*s);
        int adv = 0, lsb = 0;

        if (gl) {
            stbtt_GetGlyphHMetrics(info, gl, &adv, &lsb);
            sum += (double)adv / denom;
        }
    }
    return sum;
}

static void probe(const char *ttf_path, const wchar_t *face, const char *s)
{
    long len;
    unsigned char *data = read_file(ttf_path, &len);
    stbtt_fontinfo info;
    int asc, desc, lg;
    int upem;
    double ratio_ad, ratio_upem;
    int H;
    HDC dc;
    LOGFONTW lf;
    HFONT font, old;
    SIZE sz;

    if (!stbtt_InitFont(&info, data, 0)) {
        fprintf(stderr, "stbtt_InitFont %s: failed\n", ttf_path);
        exit(1);
    }
    stbtt_GetFontVMetrics(&info, &asc, &desc, &lg);
    upem = (int)(1.0 / stbtt_ScaleForMappingEmToPixels(&info, 1.0f) + 0.5);
    ratio_ad = stb_ratio(&info, (double)(asc - desc), s);
    ratio_upem = stb_ratio(&info, (double)upem, s);

    dc = GetDC(0);
    printf("== %s (face \"%ls\") string \"%s\" ==\n", ttf_path, face, s);
    printf("stb: asc=%d desc=%d (asc-desc)=%d upem=%d ratio(asc-desc)=%.10f ratio(upem)=%.10f\n",
           asc, desc, asc - desc, upem, ratio_ad, ratio_upem);
    for (H = 50; H <= 1600; H *= 4) {
        memset(&lf, 0, sizeof lf);
        lf.lfHeight = -H;           /* FUN_00493410: local_70.lfHeight = -DAT_009fe124 */
        lf.lfCharSet = DEFAULT_CHARSET;             /* 1 */
        lf.lfPitchAndFamily = VARIABLE_PITCH | FF_DONTCARE; /* 6 */
        lf.lfWeight = FW_NORMAL;                    /* 400 */
        lf.lfItalic = 0;
        lf.lfOutPrecision = OUT_DEFAULT_PRECIS;     /* 0 */
        lf.lfClipPrecision = CLIP_DEFAULT_PRECIS;   /* 0 */
        wcsncpy(lf.lfFaceName, face, LF_FACESIZE - 1);
        font = CreateFontIndirectW(&lf);
        old = (HFONT)SelectObject(dc, font);
        GetTextExtentPoint32A(dc, s, (int)strlen(s), &sz);
        SelectObject(dc, old);
        DeleteObject(font);
        {
            double ad = ratio_ad * H, up = ratio_upem * H;
            double gdi = sz.cx;

            printf("  H=%5d  GDI.cx=%5ld  (asc-desc)*H=%9.4f diff%%=%7.4f   upem*H=%9.4f diff%%=%7.4f\n",
                   H, (long)sz.cx, ad, 100.0 * (gdi - ad) / (gdi ? gdi : 1),
                   up, 100.0 * (gdi - up) / (gdi ? gdi : 1));
        }
    }
    ReleaseDC(0, dc);
    free(data);
}

int main(void)
{
    int h1 = AddFontResourceExW(L"fonts\\jwsubgothic.ttf", FR_PRIVATE, 0);
    int h2 = AddFontResourceExW(L"fonts\\jwsubmincho.ttf", FR_PRIVATE, 0);

    if (!h1 || !h2) {
        fprintf(stderr, "AddFontResourceExW failed (h1=%d h2=%d); "
                        "run from the worktree root\n", h1, h2);
        return 1;
    }
    /* `EnumFontFamiliesExW` 確認（別途使い捨てのツールで確かめた）で、これら
     * の私的フォントは TTF 内部の家族名が "IPAexGothic"／"IPAexMincho" では
     * なく "JwSubGothic"／"JwSubMincho" に変わっていることが分かった
     * （fonts/jwsubgothic.ttf・jwsubmincho.ttf 自体の name テーブル）。
     * src/outfont.c の F[].name "IPAexGothic" はこの port 内部の論理名
     * （JWW の書体名の表引き用）であって、ファイルの実際の家族名ではない
     * ので、ここは実際の家族名で CreateFontIndirectW を呼ぶ。 */
    probe("fonts/jwsubgothic.ttf", L"JwSubGothic", "ABCDE");
    probe("fonts/jwsubgothic.ttf", L"JwSubGothic", "WWWWW");
    probe("fonts/jwsubgothic.ttf", L"JwSubGothic", "iiiii");
    probe("fonts/jwsubmincho.ttf", L"JwSubMincho", "ABCDE");
    probe("fonts/jwsubmincho.ttf", L"JwSubMincho", "WWWWW");
    RemoveFontResourceExW(L"fonts\\jwsubgothic.ttf", FR_PRIVATE, 0);
    RemoveFontResourceExW(L"fonts\\jwsubmincho.ttf", FR_PRIVATE, 0);

    /* Latin 代用書体（JW_OF_SANS 等、Arial 等の名前を resolve_core が
     * 振り分ける先）は asc-desc と upem が違う（jwsubsans.ttf は
     * asc=1854 desc=-434 (asc-desc)=2288 upem=2048、/tmp/metrics.c で
     * 全 7 ファイルを確認した使い捨て調べで分かった）。
     * jw_outfont_text_width は常に (asc-desc) で割っており、jw_outfont_run
     * が Latin 代用書体には upem で割っている（758-819 行の注、GDI の
     * 負の lfHeight は upem を写す、という文書化された仕様）のと食い違う。
     * どちらが実際の GDI の挙動と合うか、ここで実測して確かめる。 */
    {
        int h = AddFontResourceExW(L"fonts\\jwsubsans.ttf", FR_PRIVATE, 0);

        if (!h) {
            fprintf(stderr, "AddFontResourceExW(jwsubsans) failed\n");
            return 1;
        }
        probe("fonts/jwsubsans.ttf", L"JwSubSans", "ABCDE");
        probe("fonts/jwsubsans.ttf", L"JwSubSans", "WWWWW");
        RemoveFontResourceExW(L"fonts\\jwsubsans.ttf", FR_PRIVATE, 0);
    }
    return 0;
}
