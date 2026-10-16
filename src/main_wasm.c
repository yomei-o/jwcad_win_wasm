/* The browser front end.
 *
 * The page only ever calls jw_resize and then putImageData on what
 * jw_rgba() points at: no canvas drawing, no WebGL.  Every pixel comes from
 * the same src/ui.c the native build uses.
 *
 *   sh tools/build_wasm.sh     -> jwcad.js + jwcad.wasm
 */
#include <emscripten/emscripten.h>

#include <stdlib.h>
#include <string.h>

#include "image.h"
#include "app.h"
#include "clock.h"
#include "plot.h"
#include "cp932.h"
#include "cmd.h"
#include "ui.h"
#include "outfont.h"

/* The page hands over the whole canvas; the client is what is left under
   the caption and the menu bar the port draws for it. */
EMSCRIPTEN_KEEPALIVE int jw_resize(int w, int h)
{
    h -= app_chrome_h();
    if (h < 1)
        h = 1;
    if (!app_resize(w, h))
        return 0;
    app_paint();
    return 1;
}

/* The outline fonts (src/outfont.h) are not in the wasm: the page fetches
 * the file of one the moment a drawing wants it.  After every paint it asks
 * jw_font_pending, which answers an index once; it fetches
 * fonts/<jw_font_file(i)>, hands the bytes to jw_font_put (or tells
 * jw_font_fail), and calls jw_repaint so the text comes out in it.  Until
 * then, and if the fetch fails, the bitmap font draws the text. */
EMSCRIPTEN_KEEPALIVE int jw_font_pending(void)
{
    return jw_outfont_pending();
}

EMSCRIPTEN_KEEPALIVE const char *jw_font_file(int i)
{
    return jw_outfont_file(i);
}

EMSCRIPTEN_KEEPALIVE int jw_font_put(const unsigned char *b, int n, int i)
{
    return jw_outfont_put(i, b, n);
}

EMSCRIPTEN_KEEPALIVE void jw_font_fail(int i)
{
    jw_outfont_fail(i);
}

EMSCRIPTEN_KEEPALIVE void jw_repaint(void)
{
    app_paint();
}

EMSCRIPTEN_KEEPALIVE int jw_chrome_h(void)
{
    return app_chrome_h();
}

/* The page hands over the bytes of a .jww it read itself: nothing is
 * uploaded anywhere, and the build carries no drawings of its own. */
EMSCRIPTEN_KEEPALIVE int jw_open(const unsigned char *b, int n)
{
    if (!app_open(b, n))
        return 0;
    app_paint();
    return 1;
}

EMSCRIPTEN_KEEPALIVE const char *jw_error(void) { return app_error(); }

EMSCRIPTEN_KEEPALIVE int jw_nobj(void)
{
    const jw_drawing *d = app_drawing();
    return d ? d->nobj : 0;
}

EMSCRIPTEN_KEEPALIVE void jw_zoom(double factor, int sx, int sy)
{
    /* the page's coordinates are the canvas's, which has the chrome on top */
    app_zoom(factor, sx, sy - app_chrome_h());
    app_paint();
}

EMSCRIPTEN_KEEPALIVE void jw_pan(int dx, int dy)
{
    app_pan(dx, dy);
    app_paint();
}

/* 基本設定 2362: 矢印・PageUp・PageDown（Windows の仮想キーの番号で）。受けたら 1 */
EMSCRIPTEN_KEEPALIVE int jw_arrow(int vk)
{
    if (!app_arrow_key(vk))
        return 0;
    app_paint();
    return 1;
}

/* 基本設定 一般(2) ﾏｳｽﾎｲｰﾙ ＋・－ (2266・2267): ホイール一刻みの倍率（delta > 0 は
   奥へ）。0 なら 表側の 1.25 のまま（src/kihon3.h） */
EMSCRIPTEN_KEEPALIVE double jw_wheel_factor(int delta)
{
    return app_wheel_factor(delta);
}

EMSCRIPTEN_KEEPALIVE void jw_fit(void)
{
    app_fit();
    app_paint();
}

/* A click: on a toolbar button it changes the command, in the drawing area
   it gives the command a point. */
/* Returns 1 when the page should repaint, or what the button asked the page
   to do: 2 to pick a file to open, 3 to hand one back to be saved. */
/* A character for the 文字 command, in CP932.  The page converts what the
   browser gives it (UTF-16, and a whole run at a time when an IME finishes)
   with jw_from_utf16 before calling this. */
/* Which command is in force, so the page can tell when to put its hidden
   input where the 文字 box is and keep it focused. */
EMSCRIPTEN_KEEPALIVE int jw_cmd_id(void)
{
    return jw_cmd();
}

/* Which box on the command bar is taking typing, if any.  The page has to
   know: while one is, the keys are its business and not the drawing's. */
EMSCRIPTEN_KEEPALIVE int jw_box_focus(void)
{
    return jw_cmd_box_focus();
}

static int finish(int redraw);

/* A key can leave an action behind too -- Enter that settles 外部エディタ's
   range, or a 外部変形 step -- so what it asked for comes back the way a
   press's does (finish).  app_key has painted already. */
EMSCRIPTEN_KEEPALIVE int jw_key(int c)
{
    int r = app_key(c), f = finish(0);

    return f ? f : r;
}

/* Shift+Enter: see app_shift_enter.  A DOM keydown carries shiftKey itself,
   so the page checks that before calling this instead of jw_key(13)
   (RESUME.md 2026-10-13). */
EMSCRIPTEN_KEEPALIVE int jw_shift_enter(void)
{
    int r = app_shift_enter(), f = finish(0);

    return f ? f : r;
}

/* One UTF-16 unit from the page, converted here.  This is the way the page
   sends what an IME gives it: it needs no memory of its own on the wasm
   side, so there is nothing to get wrong about heap views or malloc. */
EMSCRIPTEN_KEEPALIVE int jw_key_u(int c)
{
    unsigned short u = (unsigned short)c;
    char buf[4];
    long m = jw_from_utf16(&u, 1, buf, sizeof buf), i;

    for (i = 0; i < m && i < (long)sizeof buf; i++)
        app_key((unsigned char)buf[i]);
    return m > 0;
}

/* The same for what an IME is still converting: -1 clears it, otherwise one
   UTF-16 unit is added. */
EMSCRIPTEN_KEEPALIVE int jw_compose_u(int c)
{
    unsigned short u;
    char buf[4];
    long m, i;

    if (c < 0)
        return app_compose(-1);
    u = (unsigned short)c;
    m = jw_from_utf16(&u, 1, buf, sizeof buf);
    for (i = 0; i < m && i < (long)sizeof buf; i++)
        app_compose((unsigned char)buf[i]);
    return 1;
}

/* UTF-16 straight from the page, converted here. */
EMSCRIPTEN_KEEPALIVE int jw_text_in(const unsigned short *s, int n)
{
    char buf[512];
    long m = jw_from_utf16(s, n, buf, sizeof buf), i;

    for (i = 0; i < m && i < (long)sizeof buf; i++)
        app_key((unsigned char)buf[i]);
    return m > 0;
}

/* What the caption says: the page hands over the name of the file it just
   opened, in UTF-16, and the port puts " - jw_win" after it. */
EMSCRIPTEN_KEEPALIVE void jw_name(const unsigned short *s, int n)
{
    char buf[128];
    long m = jw_from_utf16(s, n, buf, sizeof buf - 1);

    /* jw_from_utf16 returns what the name WOULD take, not what fitted, so a
       long one gives an m past the end of buf -- jw_key_u and jw_text_in
       above guard against that with their `i < sizeof buf`, and this had
       nothing.  A file name of a couple of hundred characters wrote the NUL
       off the end of the stack frame. */
    if (m < 0)
        m = 0;
    if (m > (long)sizeof buf - 1)
        m = (long)sizeof buf - 1;   /* cut it, lead byte and all */
    buf[m] = 0;
    app_title(buf);
    app_paint();
}

/* What a press or a command asked for.  Returns what the page has to do --
   2 to pick a file to open, 3 to hand one back to be saved, 4 a figure, 5 a
   coordinate file, 6 a text file to read, 7 to ask whether to throw the
   drawing away for a 新規 -- or 1 when it only wants repainting. */
static int finish(int redraw)
{
    switch (app_take_action()) {
    case JW_ACT_OPEN:
    case JW_ACT_TAG:        /* タグジャンプ: the page has no folder to look in, so it
                               lets the user pick the file */
    case JW_ACT_OPEN_DXF:   /* DXF・SFC・JWC ファイルを開く: the page reads the */
    case JW_ACT_OPEN_SFC:   /* kind off the name it was given, so the same */
    case JW_ACT_OPEN_JWC:   /* file window does for all of them */
        return 2;
    case JW_ACT_SAVE_DXF:
        return 17;              /* DXF形式で保存 (the menu's, not only the page's button) */
    case JW_ACT_SAVE_SFC:
        return 18;              /* SFC形式で保存 */
    case JW_ACT_SAVE_JWC:
        return 19;              /* JWC形式で保存 */
    case JW_ACT_PLOT:
        return 20;              /* 印刷 (Ctrl+P too): the sheet as a PDF */
    case JW_ACT_SAVE:
    case JW_ACT_SAVE_AS:
        return 3;
    case JW_ACT_SAVE_FIG:
        return 4;               /* 図形登録: the figure wants a name */
    case JW_ACT_SAVE_COORD:
        return 5;               /* 座標ファイル: so does that one */
    case JW_ACT_OPEN_TEXT:
        return 6;               /* 文読: a text file to read */
    case JW_ACT_ENV_WRITE:
        return 8;               /* 環境設定ファイル 書出し: a .jwf to download */
    case JW_ACT_ENV_READ:
        return 9;               /* and 読込み: a .jwf to pick */
    case JW_ACT_NEW_ASK:
        return 7;               /* 新規 over changes: ask first */
    case JW_ACT_OPEN_IMAGE:
        return 10;              /* 画像挿入: a bitmap, PNG or JPEG to pick */
    case JW_ACT_SAVE_IMAGES:
        return 11;              /* 同梱画像分離: the pictures to hand out */
    case JW_ACT_MOJI_DOC:
        return 13;              /* 文書: the picked texts as a .txt */
    case JW_ACT_MOJI_EDIT:
        return 14;              /* 外部エディタ: the page edits the lines */
    case JW_ACT_MOJI_PASTE:
        return 15;              /* 貼付: the clipboard's lines */
    case JW_ACT_GAIBU_RUN:
    case JW_ACT_GAIBU:
        return 12;              /* 外部変形: a browser cannot run a BAT */
    case JW_ACT_CLIP_PUT:
        app_paint();            /* 切り取り は図面を変えている */
        return 16;              /* コピー・切り取り: システムのクリップボードへ */
    case JW_ACT_OPEN_FIG:
        return 21;              /* 図形 (32862): .jws を選ばせて jw_figure へ */
    case JW_ACT_EXIT:
        break;                  /* Jw_cadの終了: 頁は自分を閉じられない */
    }
    if (redraw)
        app_paint();
    return redraw;
}

/* A command by id, the way a menu item or one of the original's keyboard
   shortcuts (src/gen/accel.h) asks for it.  The page maps the keys. */
EMSCRIPTEN_KEEPALIVE int jw_command(int id)
{
    return finish(app_command(id));
}

/* クロックメニュー（src/clock.h）の左・右の離し: 離した向きの命令へ移り、
   その命令の求め（図形の窓など）は press と同じ数で返す */
EMSCRIPTEN_KEEPALIVE int jw_clock_end(void)
{
    return finish(app_clock_end());
}

/* Whether there are changes since the drawing was opened or last saved. */
EMSCRIPTEN_KEEPALIVE int jw_modified(void)
{
    return app_modified();
}

EMSCRIPTEN_KEEPALIVE int jw_new_count(void)
{
    return app_new_count();
}

/* 新規 once the page has been told yes. */
EMSCRIPTEN_KEEPALIVE void jw_new(void)
{
    app_new();
    app_paint();
}

EMSCRIPTEN_KEEPALIVE int jw_press(int x, int y, int button)
{
    int redraw;

    /* the canvas carries the chrome as well, so the client starts lower */
    y -= app_chrome_h();
    if (y < 0) {
        /* on the caption or the menu bar: a name there opens its popup */
        redraw = app_chrome_press(x, y + app_chrome_h());
        if (redraw)
            app_paint();
        return redraw;
    }
    return finish(app_press(x, y, button));
}

/* The drawing as a .jww, for the page to hand to the browser as a download.
   jw_saved_len() is how long it is; the page copies it out and then calls
   jw_saved_free(). */
static unsigned char *saved;
static long saved_n;

EMSCRIPTEN_KEEPALIVE unsigned char *jw_save(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save(&saved, &saved_n))
        return 0;
    return saved;
}

/* 「DXFファイルを開く」: a DXF goes into whatever is open, so the page
   hands the bytes over the same way it hands over a .jww. */
EMSCRIPTEN_KEEPALIVE int jw_open_dxf(unsigned char *b, int n)
{
    if (!app_open_dxf(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 図形読込 (32862): the original puts up a file window of its own, so the
   page picks the .jws and hands the bytes over.  The figure then hangs on
   the cursor and the next press puts it down. */
EMSCRIPTEN_KEEPALIVE int jw_figure(unsigned char *b, int n)
{
    if (!app_figure(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 文読 (1069): the original puts up an ordinary 「開く」, so the
   page picks the text file and hands the bytes over.  Its lines then go
   down from the next click, 行間 apart -- twice what that box holds. */
EMSCRIPTEN_KEEPALIVE int jw_bunyomi(unsigned char *b, int n)
{
    if (!app_text(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 図形登録 (32946) the other way: once the 基準点 has been clicked the
   press hands back 4, and the page calls this for the bytes to download. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_fig(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_figure_save(&saved, &saved_n))
        return 0;
    return saved;
}

/* And the text of a coordinate file, which the original reads as a 図形. */
EMSCRIPTEN_KEEPALIVE int jw_coord(unsigned char *b, int n)
{
    if (!app_coord(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 画像挿入 (画像編集): the page picked a picture file and hands over its name
   (UTF-16, what the drawing will call it) and its bytes. */
EMSCRIPTEN_KEEPALIVE int jw_image(const unsigned short *name, int nlen, unsigned char *b, int n)
{
    char buf[300];
    long m = jw_from_utf16(name, nlen, buf, sizeof buf - 1);

    if (m < 0)
        m = 0;
    if (m > (long)sizeof buf - 1)
        m = (long)sizeof buf - 1;
    buf[m] = 0;
    if (!app_image(buf, b, n))
        return 0;
    app_paint();
    return 1;
}

/* A picture file handed over without being put in: so that a drawing that
   names it by file name finds it. */
EMSCRIPTEN_KEEPALIVE int jw_image_store(const unsigned short *name, int nlen, unsigned char *b, int n)
{
    char buf[300];
    long m = jw_from_utf16(name, nlen, buf, sizeof buf - 1);

    if (m < 0)
        m = 0;
    if (m > (long)sizeof buf - 1)
        m = (long)sizeof buf - 1;
    buf[m] = 0;
    jw_img_put(buf, b, n);
    app_paint();
    return 1;
}

/* 同梱画像分離's pictures, one at a time: how many, the i-th name (UTF-16
   into `out`, its length returned), its bytes' address and length. */
EMSCRIPTEN_KEEPALIVE int jw_image_out_count(void)
{
    const char *nm;
    const unsigned char *b;
    long n;
    int i = 0;

    while (app_image_out(i, &nm, &b, &n))
        i++;
    return i;
}

EMSCRIPTEN_KEEPALIVE int jw_image_out_name(int i, unsigned short *out, int cap)
{
    const char *nm;
    const unsigned char *b;
    long n;

    if (!app_image_out(i, &nm, &b, &n))
        return 0;
    return (int)jw_to_utf16(nm, (long)strlen(nm), out, cap);
}

EMSCRIPTEN_KEEPALIVE const unsigned char *jw_image_out_ptr(int i)
{
    const char *nm;
    const unsigned char *b;
    long n;

    return app_image_out(i, &nm, &b, &n) ? b : 0;
}

EMSCRIPTEN_KEEPALIVE int jw_image_out_len(int i)
{
    const char *nm;
    const unsigned char *b;
    long n;

    return app_image_out(i, &nm, &b, &n) ? (int)n : 0;
}

/* 座標ファイル (32895): the command hands back 5 from a press, and the page
   calls this for the text to download. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_coord(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_coord_save(&saved, &saved_n))
        return 0;
    return saved;
}


/* 文字の 範囲選択: 文書 and 外部エディタ hand a text file to the page, and
   外部エディタ and 貼付 take one back. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_moji_doc(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_moji_doc(&saved, &saved_n))
        return 0;
    return saved;
}

EMSCRIPTEN_KEEPALIVE unsigned char *jw_moji_edit_text(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_moji_edit_text(&saved, &saved_n))
        return 0;
    return saved;
}

EMSCRIPTEN_KEEPALIVE int jw_moji_apply(unsigned char *b, int n)
{
    if (!app_moji_apply(b, n))
        return 0;
    app_paint();
    return 1;
}

EMSCRIPTEN_KEEPALIVE int jw_moji_sjis_get(void)
{
    return jw_moji_sjis();
}

EMSCRIPTEN_KEEPALIVE void jw_moji_sjis_put(int on)
{
    jw_moji_sjis_set(on);
}

/* The 図形 clipboard as bytes, to and from the system clipboard. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_clip_get(void)
{
    const unsigned char *b;
    long n;

    free(saved);
    saved = 0;
    saved_n = 0;
    if (!jw_cmd_clip_get(&b, &n))
        return 0;
    saved = (unsigned char *)malloc((size_t)n);
    if (!saved)
        return 0;
    memcpy(saved, b, (size_t)n);
    saved_n = n;
    return saved;
}

EMSCRIPTEN_KEEPALIVE int jw_clip_set(unsigned char *b, int n)
{
    return jw_cmd_clip_set(b, n);
}

/* コピー・切り取りで選んでいた字（UTF-8、BOM 付き、一行一字）。原典は図形と
   一緒に CF_UNICODETEXT にも置くので、ページは text/plain で出す。字が
   無ければ 0。長さは jw_saved_len、あとで jw_saved_free。 */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_moji_clip_get(void)
{
    const unsigned char *b;
    long n;

    free(saved);
    saved = 0;
    saved_n = 0;
    if (!jw_cmd_moji_clip(&b, &n))
        return 0;
    saved = (unsigned char *)malloc((size_t)n);
    if (!saved)
        return 0;
    memcpy(saved, b, (size_t)n);
    saved_n = n;
    return saved;
}
/* 「SFCファイルを開く」, the same way. */
EMSCRIPTEN_KEEPALIVE int jw_open_sfc(unsigned char *b, int n)
{
    if (!app_open_sfc(b, n))
        return 0;
    app_paint();
    return 1;
}

/* 「JWCファイルを開く」, the same way. */
EMSCRIPTEN_KEEPALIVE int jw_open_jwc(unsigned char *b, int n)
{
    if (!app_open_jwc(b, n))
        return 0;
    app_paint();
    return 1;
}

/* The same, as DXF: the page offers it as a second download. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_dxf(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_dxf(&saved, &saved_n))
        return 0;
    return saved;
}

/* The same, as SFC.  The name it is being saved under goes in the file, so
   the page passes it in. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_sfc(const char *name)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_sfc(name, &saved, &saved_n))
        return 0;
    return saved;
}

/* 環境設定ファイル: 書出し gives the bytes, 読込み takes them. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_env(const char *name)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_env(name, &saved, &saved_n))
        return 0;
    return saved;
}

EMSCRIPTEN_KEEPALIVE int jw_open_env(unsigned char *b, int n)
{
    if (!app_open_env(b, n))
        return 0;
    app_paint();
    return 1;
}

/* What the original keeps in its registry (基本設定 の箱と押し釦、寸法設定 の
   押し釦: app_prefs_write), as an ASCII string for the page to put in
   localStorage, and back.  0 when there is nothing to give. */
EMSCRIPTEN_KEEPALIVE const char *jw_save_prefs(void)
{
    unsigned char *b = 0;
    long n = 0;

    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_prefs_write(&b, &n))
        return 0;
    saved = (unsigned char *)realloc(b, (size_t)n + 1);
    if (!saved) {
        free(b);
        return 0;
    }
    saved[n] = 0;
    saved_n = n;
    return (const char *)saved;
}

EMSCRIPTEN_KEEPALIVE int jw_open_prefs(const char *s)
{
    return s ? app_prefs_read((const unsigned char *)s, (long)strlen(s)) : 0;
}

/* The same, as JWC. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_jwc(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_jwc(&saved, &saved_n))
        return 0;
    return saved;
}

/* 印刷: the drawing as a PDF to send to a printer, or a PNG to look at.
   The page is the sheet, one to one -- see src/plot.h for what the
   original was asked and what it answered.  `colour` is カラー印刷, which
   the original has off as its print bar comes up. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_plot(int as_png, int colour)
{
    const jw_drawing *d = app_drawing();
    jw_plot_frame f;

    free(saved);
    saved = 0;
    saved_n = 0;
    if (!d)
        return 0;
    /* the print command's frame, 倍率, 回転 and カラー印刷 (src/plot.h);
       untouched they are the sheet one to one, as before */
    jw_pr_settings(&f);
    f.colour = f.colour || colour;
    saved = as_png ? jw_plot_png_at(d, &f, 4.0, &saved_n)
                   : jw_plot_pdf_at(d, &f, &saved_n);
    return saved;
}

EMSCRIPTEN_KEEPALIVE int jw_saved_len(void) { return (int)saved_n; }

EMSCRIPTEN_KEEPALIVE void jw_saved_free(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
}

/* 指で叩くとき (LL) の幅を広げ、間が空いたら預かりを渡す（app_ll_slop） */
EMSCRIPTEN_KEEPALIVE void jw_ll_slop(int px)
{
    app_ll_slop(px);
}

EMSCRIPTEN_KEEPALIVE int jw_ll_break(void)
{
    return finish(app_ll_break());
}

EMSCRIPTEN_KEEPALIVE int jw_move(int x, int y)
{
    y -= app_chrome_h();
    if (y < 0) {
        if (!app_chrome_move(x, y + app_chrome_h()))
            return 0;
        app_paint();
        return 1;
    }
    if (!app_move(x, y))
        return 0;
    app_paint();
    return 1;
}

EMSCRIPTEN_KEEPALIVE int jw_width(void)  { return app_fb()->w; }
EMSCRIPTEN_KEEPALIVE int jw_height(void)
{
    return app_fb()->h + app_chrome_h();
}
EMSCRIPTEN_KEEPALIVE unsigned char *jw_rgba(void) { return app_rgba(); }

int main(void)
{
    /* the browser has no window of its own, so the port draws one */
    app_chrome(1);
    jw_outfont_enable(1);       /* IPAex for every face, once fetched */
    app_new();
    jw_resize(1264, 741 + JW_CHROME_H);
    return 0;
}

/* for the headless-Chrome sweep (tmp/features_wasm/cdp_sweep.js): is a dialog up? */
EMSCRIPTEN_KEEPALIVE int jw_modal(void)
{
    return app_modal();
}

/* the tool tip for the toolbar button under the pointer (the canvas's own pixels) */
EMSCRIPTEN_KEEPALIVE const char *jw_tip(int x, int y)
{
    return app_tip(x, y - app_chrome_h());
}

/* A copy of the drawing for the page to keep in case the tab dies (autosave):
   unlike jw_save it does not call the drawing saved. */
EMSCRIPTEN_KEEPALIVE unsigned char *jw_save_backup(void)
{
    free(saved);
    saved = 0;
    saved_n = 0;
    if (!app_save_backup(&saved, &saved_n))
        return 0;
    return saved;
}

/* how often (minutes) to keep that copy: 基本設定 一般(1) の オートセーブ時間 */
EMSCRIPTEN_KEEPALIVE int jw_autosave_min(void)
{
    return app_autosave_minutes();
}

/* a drawing brought back from such a copy has not been saved */
EMSCRIPTEN_KEEPALIVE void jw_mark_modified(void)
{
    app_mark_modified();
}

/* the left button came up (連続線's 手書線 ends its stroke there) */
EMSCRIPTEN_KEEPALIVE int jw_release(int x, int y)
{
    int r = app_release(x, y - app_chrome_h(), 0);

    if (r)
        app_paint();
    return r;
}

/* ---- for tools/web/cdp_bars.js: the bar in force, and the status line in UTF-8 ---- */
/* control i of the bar: id, kind, x, y, w, h in the canvas (chrome included), 0 past the end */
EMSCRIPTEN_KEEPALIVE int *jw_bar_ctl(int i)
{
    static int v[6];
    int id, kind, x, y, w, h;

    if (!ui_bar_item(i, &id, &kind, &x, &y, &w, &h))
        return 0;
    v[0] = id;
    v[1] = kind;
    v[2] = x;
    v[3] = y + app_chrome_h();
    v[4] = w;
    v[5] = h;
    return v;
}

EMSCRIPTEN_KEEPALIVE const char *jw_prompt(void)
{
    static char out[1500];
    const char *p = jw_cmd_prompt();
    unsigned short wbuf[400];
    long n, i, k = 0;

    if (!p)
        return "";
    n = jw_to_utf16(p, (long)strlen(p), wbuf, 400);
    if (n > 400)
        n = 400;
    for (i = 0; i < n && k < (long)sizeof out - 4; i++) {
        unsigned c = wbuf[i];

        if (c < 0x80)
            out[k++] = (char)c;
        else if (c < 0x800) {
            out[k++] = (char)(0xc0 | (c >> 6));
            out[k++] = (char)(0x80 | (c & 63));
        } else {
            out[k++] = (char)(0xe0 | (c >> 12));
            out[k++] = (char)(0x80 | ((c >> 6) & 63));
            out[k++] = (char)(0x80 | (c & 63));
        }
    }
    out[k] = 0;
    return out;
}
