/* ファイル操作・図面情報コピー・レイヤ一覧（src/app.c が頁の終わりで
 * #include する。app.c の static を使うので単独では組めない）。
 *
 * どれも逆コンパイルの読み。原典は起動していない。
 *
 * ---- 図面情報コピー (32987、FUN_00504bf0) ----------------------------------
 *   命令を +0x8564 に置き、文字列を作ってクリップボードへ（FUN_0044a0b0 →
 *   FUN_0044a020: OpenClipboard・EmptyClipboard・CF_UNICODETEXT だけ）。書式は
 *   L"%s -M -P%lg,%lg,%lg,%lg,%lg -L%s"（0x966410）で、
 *     %s   文書の m_strPathName（view+0x80 の文書の +0x24、FUN_0044f310）
 *     -P   view+0x7aa0・+0x7aa8（画面の真ん中に来る用紙の点）、+0x17b0（画面
 *          倍率）、+0x3038・+0x3040（印刷枠の中心）。起動の引数の -P を読む
 *          所（FUN_00455c60 の上、'P' の枝）がこの五つをこの順に戻す
 *     -L   FUN_00463510: グループの状態 (+0x242c+g*4) の bit0 を 16、レイヤ
 *          (+0x182c+g*0x40+l*4) の bit0 を 256、同じく bit1 を 16 と 256、
 *          計 544 bit を頭から 6 bit ずつ（足りない分は 0）'0'+値 の字に。91 字
 *   移植では 点と倍率は vw_get（app.c の注）、枠の中心は jw_pr_settings、
 *   状態は drawing.group[].state・layer[].state。字の控えは jw_cmd_text_clip
 *   （図形の控えは捨てる。EmptyClipboard と同じ）で、表側は JW_ACT_CLIP_PUT。
 *   メニューの灰色（FUN_00511b50 の DAT_00a0ef7c != 123456）は何の値か読めて
 *   いないので、いつも押せる。
 *
 * ---- ファイル一括変換 (32977、FUN_00504550) の変換 -------------------------
 *   一つずつ FUN_004fba70: 開いて（文書の OnOpenDocument）、名前の拡張子を
 *   変換先（DIALOG 368 の 1689..1693 = .jww .jwc .dxf .sfc .p21、0x9624b8..）に
 *   替えて保存。あれば 上書き確認 (2254) のとき "%s\n\n%s"（名前と 0x157c
 *   「ファイルはすでに存在しています。上書きしますか？」、MB_OKCANCEL）。
 *   記録は 名前 "\r\n"、飛ばしたものは " ..... skip"。ここは バイト → バイトの
 *   変換だけで、ファイルと窓は表側（src/fonative.h）。.p21 は移植に書き手が
 *   無いので 0 を返す。
 *
 * ---- レイヤ一覧 (32917)・レイヤグループ一覧 (32916) -----------------------
 *   FUN_0050eb10・FUN_0050e900: DAT_00a0b3d4 が 0 なら CMyFileDialog
 *   （DIALOG 290、FUN_0058d590）を 0x14（レイヤ）・0x15（グループ）で DoModal。
 *   0 でない枝（書込レイヤの要素に +0x44 の 2 を立てる）は DAT_00a0b3d4 が
 *   何か読み切れていないので入れていない。
 *     窓     見出しは 0x1f41「レイヤ一覧     ( [%X] グループ )」（書込グループ）
 *            と 0x1f40「レイヤグループ一覧」。既定の大きさは
 *            decomp/res/layerlist.txt（窓 1110x640、中 1094x601）
 *     升目   FUN_00594880: 上の 23 画素（FUN_004f74b0(0x17)）の下に 列 × 行
 *            （2086・2087、既定 4 × 4）。i 番は (列*幅 + 2, 23 + 行*高さ)、幅 =
 *            中の幅 / 列、高さ = (中の高さ − 23) / 行。子窓は WS_DLGFRAME
 *     札     FUN_0059bb70: (1,1) に。前置き（保護 1 は "/"、2 は "X"、
 *            グループ +0x2a7c・レイヤ +0x267c）に 状態 0 なら "%s   "、1 なら
 *            "%s %X "、ほかは レイヤ "%s(%X)"・グループ "%s[%X]"、そして名前。
 *            選んだ升目（+0x8540）は 地 0x646464・字 白、ほかは 地 c8c8c8・字 黒
 *     選ぶ   +0x10f4。開いたとき 書込レイヤ（グループ）（FUN_0058e4xx）。
 *            右押し（0x1401、FUN_00593110）で替わる。保護されたものには行かない
 *     左     札の上（y < 19 かつ x ≦ 字数*9）なら 0x1403 → FUN_00593520 で
 *            CNamaeHenkouDlg（DIALOG 373）: 見出し 0x177f「レイヤ名設定」/
 *            0x1780「レイヤグループ名設定」、字 "(%X) %s"/"[%X] %s"（番号と
 *            0x1f44「レイヤ」/0x1f45「レイヤグループ」）、箱に名前。OK で名前に。
 *            札の外なら 書込でないとき バーの升目の左押し FUN_0055ea10
 *            （状態を一つ回す、Ctrl で保護）
 *     右     選んで（上）、書込でないとき バー（frame+0x14a0/0x14a4）へ 0x1401
 *            ＝ 書込にする（FUN_005571b0）。札の上の右押しは DAT_00a0d628 が
 *            0 でなければ窓を閉じる（0x1403 の 9999）が、値が読めていないので
 *            移植は 0 として扱う
 *   入れていないもの: 列・行の数を替える（2086・2087 の Spin）、2575、
 *   リスト表示（1323、押せない）、名前の窓の見出し（移植の 373 は
 *   テンプレートの「名称変更」のまま）、64 字を超える名前の打ち直し。
 */

/* ======================================================== 図面情報コピー == */

static char fo_path[520];       /* 文書の道（CP932）。表側が app_doc_path で */

void app_doc_path(const char *p)
{
    strncpy(fo_path, p ? p : "", sizeof fo_path - 1);
    fo_path[sizeof fo_path - 1] = 0;
}

/* FUN_00463510: 状態の 544 bit を 6 bit ずつ '0'+値 に。out は 92 字以上 */
static void fo_layer_code(char *out)
{
    unsigned char bit[544];
    int k = 0, g, l, i, n, acc = 0, m = 0, b;

    for (b = 1; b <= 2; b++) {
        for (g = 0; g < 16; g++)
            bit[k++] = (drawing.group[g].state & b) != 0;
        for (g = 0; g < 16; g++)
            for (l = 0; l < 16; l++)
                bit[k++] = (drawing.group[g].layer[l].state & b) != 0;
    }
    n = (k + 5) / 6 * 6;
    for (i = 0; i < n; i++) {
        acc = (acc << 1) | (i < k ? bit[i] : 0);
        if (i % 6 == 5) {
            out[m++] = (char)((acc & 0x3f) + 0x30);
            acc = 0;
        }
    }
    out[m] = 0;
}

/* 文字列（CP932）。図面が無ければ 0 */
static int fo_info(char *s, int cap)
{
    vw_t c = vw_get();
    jw_plot_frame f;
    char lay[100], nm[160];
    const char *path = fo_path;

    if (!have_drawing)
        return 0;
    if (!*path) {
        /* ブラウザは道を持たない: 見出しの名前（app_title）を */
        size_t n = strlen(title), t = strlen(" - jw_win");

        nm[0] = 0;
        if (n > t && !strcmp(title + n - t, " - jw_win")
            && strcmp(title, "\x96\xb3\x91\xe8 - jw_win")) {
            n -= t;
            if (n > sizeof nm - 1)
                n = sizeof nm - 1;
            memcpy(nm, title, n);
            nm[n] = 0;
        }
        path = nm;
    }
    memset(&f, 0, sizeof f);
    jw_pr_settings(&f);
    fo_layer_code(lay);
    snprintf(s, (size_t)cap, "%s -M -P%g,%g,%g,%g,%g -L%s", path,
             c.x, c.y, c.z, f.cx, f.cy, lay);
    return 1;
}

static int fo_info_clip(void)
{
    char s[1200];

    if (!fo_info(s, (int)sizeof s) || !jw_cmd_text_clip(s))
        return 0;
    action = JW_ACT_CLIP_PUT;
    return 1;
}

/* 試験用: いま作る文字列 */
int app_zumen_info(char *s, int cap)
{
    return fo_info(s, cap);
}

/* ================================================== ファイル操作の命令 == */

static int fo_kind;

int app_fileops_kind(void)
{
    return fo_kind;
}

/* 32977・32979・32980・32984。ネイティブは表側（src/fonative.h）が窓と
   ファイルを受け持つ。ブラウザでは押せない（app_menu_state） */
static int fo_command(int cmd)
{
#ifdef __EMSCRIPTEN__
    (void)cmd;
    return 0;
#else
    fo_kind = cmd;
    action = JW_ACT_FILEOPS;
    return 1;
#endif
}

static int fo_ext_kind(const char *ext)
{
    static const char *const E[] = { "jww", "jwc", "dxf", "sfc", "p21" };
    int i, k;

    if (!ext)
        return -1;
    if (*ext == '.')
        ext++;
    for (i = 0; i < 5; i++) {
        for (k = 0; k < 3; k++) {
            int a = (unsigned char)ext[k], b = (unsigned char)E[i][k];

            if (a >= 'A' && a <= 'Z')
                a += 32;
            if (a != b)
                break;
        }
        if (k == 3 && ext[3] == 0)
            return i;
    }
    return -1;
}

int app_fo_convert(const unsigned char *b, long n, const char *ext, int to,
                   const char *name, unsigned char **out, long *on)
{
    jw_drawing d;
    jw_obj hid[8];
    int nh = 0, ok, i, have = 0, kind = fo_ext_kind(ext);

    *out = 0;
    *on = 0;
    if (kind < 0 || kind > 3 || to < 0 || to > 3 || !b || n <= 0)
        return 0;
    if (kind == 0) {
        if (!jw_parse(&d, b, n)) {
            jw_free(&d);
            return 0;
        }
    } else {
        /* 新しい文書に読む（app_new と同じ雛形、隠れた六つは書くときに） */
        if (!jw_parse(&d, jw_new_jww, jw_new_jww_len)) {
            jw_free(&d);
            return 0;
        }
        nh = d.nobj > 8 ? 8 : d.nobj;
        memcpy(hid, d.obj, (size_t)nh * sizeof hid[0]);
        d.nobj = 0;
        d.ndrawn = 0;
        ok = kind == 1 ? jw_jwc_read(&d, b, n)
           : kind == 2 ? jw_dxf_read(&d, b, n) : jw_sfc_read(&d, b, n);
        if (!ok) {
            jw_free(&d);
            return 0;
        }
    }
    if (to == 0) {
        for (i = 0; i < d.ndrawn; i++)
            if (d.obj[i].cls == JW_MOJI && d.obj[i].d[1] == -1000.0)
                have = 1;
        if (!have)
            for (i = 0; i < nh; i++) {
                jw_obj *p = jw_add(&d, hid[i].cls);

                if (!p)
                    break;
                *p = hid[i];
            }
        ok = jw_write(&d, out, on);
    } else if (to == 1) {
        ok = jw_jwc_write(&d, out, on);
    } else if (to == 2) {
        jw_dxf_opt opt;

        opt.point_circle = kh_value_tab(7, 2202);
        opt.layer_number = kh_value_tab(7, 2203);
        opt.utf8 = kh_value_tab(7, 2214);
        ok = jw_dxf_write_opt(&d, &opt, out, on);
    } else {
        char stamp[64];
        time_t now = time(0);
        struct tm *t = localtime(&now);

        sprintf(stamp, "%d-%d-%dT%02d:%02d:%02d", t->tm_year + 1900,
                t->tm_mon + 1, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
        ok = jw_sfc_write(&d, name ? name : "", stamp, out, on);
    }
    jw_free(&d);
    return ok;
}

/* ============================================================ レイヤ一覧 == */

#define LYL_CW 1094                     /* 中の既定（layerlist.txt） */
#define LYL_CH 601
#define LYL_TOP 23                      /* FUN_004f74b0(0x17) */

static int lyl_open;                    /* 0、1 レイヤ一覧 (0x14)、2 グループ一覧 (0x15) */
static int lyl_sel;                     /* +0x10f4 */
static int lyl_ren = -1;                /* 名前を打っている升目 */
static char lyl_ren0[64];               /* 箱に入れた名前（替えなければ書かない） */

int app_laylist_open(void)
{
    return lyl_open;
}

int app_laylist_sel(void)
{
    return lyl_open ? lyl_sel : -1;
}

static void lyl_rect(rect_t *r)
{
    int cw = LYL_CW, ch = LYL_CH;

    if (cw > fb.w - 16)
        cw = fb.w - 16;
    if (ch > fb.h - 39 - 42)
        ch = fb.h - 39 - 42;
    if (cw < 160)
        cw = 160;
    if (ch < 120)
        ch = 120;
    r->w = cw + 16;
    r->h = ch + 39;
    r->x = (fb.w - r->w) / 2;
    r->y = (fb.h - 42 - r->h) / 2;
    if (r->x < 0)
        r->x = 0;
    if (r->y < 0)
        r->y = 0;
}

/* i 番の子窓（枠こみ） */
void app_laylist_pane(int i, rect_t *p)
{
    rect_t r;
    int cw, ch;

    lyl_rect(&r);
    cw = r.w - 16;
    ch = r.h - 39;
    p->w = cw / 4;
    p->h = (ch - LYL_TOP) / 4;
    p->x = r.x + 8 + (i % 4) * p->w + 2;
    p->y = r.y + 31 + LYL_TOP + (i / 4) * p->h;
}

static int lyl_is_write(int i)
{
    int wg = ly_wg();

    return lyl_open == 1 ? i == (drawing.group[wg].write_layer & 15) : i == wg;
}

static int lyl_prot(int i)
{
    return lyl_open == 1 ? drawing.group[ly_wg()].layer[i].state2
                         : drawing.group[i].c;
}

static const char *lyl_name(int i)
{
    const jw_group *gr = &drawing.group[lyl_open == 1 ? ly_wg() : i];

    return jw_str(&drawing, lyl_open == 1 ? gr->layer_name[i] : gr->name);
}

/* FUN_0059bb70 の札 */
static void lyl_label(int i, char *s, int cap)
{
    int st = lyl_open == 1 ? drawing.group[ly_wg()].layer[i].state
                           : drawing.group[i].state;
    int pr = lyl_prot(i);
    const char *pre = pr == 1 ? "/" : pr == 2 ? "X" : "";

    if (st == 0)
        snprintf(s, (size_t)cap, "%s   %s", pre, lyl_name(i));
    else if (st == 1)
        snprintf(s, (size_t)cap, "%s %X %s", pre, i, lyl_name(i));
    else
        snprintf(s, (size_t)cap, lyl_open == 1 ? "%s(%X)%s" : "%s[%X]%s",
                 pre, i, lyl_name(i));
}

static int lyl_start(int kind)
{
    int wg;

    if (!have_drawing)
        return 0;
    wg = ly_wg();
    lyl_open = kind;
    lyl_sel = kind == 1 ? (drawing.group[wg].write_layer & 15) : wg;
    lyl_ren = -1;
    return 1;
}

/* 0x1401 → FUN_00593110: 保護されていなければ選ぶ */
static void lyl_select(int i)
{
    if (lyl_prot(i) == 0)
        lyl_sel = i;
}

/* 0x1403 → FUN_00593520: 名前の窓 */
static void lyl_rename(int i)
{
    int k;

    if (!td_start(373))
        return;
    lyl_ren = i;
    k = ui_tdlg_index(td_t, 1920);
    if (k >= 0 && k < TD_MAX) {
        snprintf(td_txt[k], sizeof td_txt[k], lyl_open == 1 ? "(%X) %s" : "[%X] %s", i,
                 lyl_open == 1 ? "\x83\x8c\x83" "C\x83\x84"
                               : "\x83\x8c\x83" "C\x83\x84\x83O\x83\x8b\x81[\x83v");
        td_txtp[k] = td_txt[k];
    }
    k = ui_tdlg_index(td_t, 2214);
    if (k >= 0 && k < TD_MAX) {
        const char *s = lyl_name(i);
        size_t n = strlen(s), j = 0;

        while (j < n && j < sizeof td_txt[k] - 1) {
            size_t w = jw_is_lead((unsigned char)s[j]) && s[j + 1] ? 2 : 1;

            if (j + w > sizeof td_txt[k] - 1)
                break;
            j += w;
        }
        memcpy(td_txt[k], s, j);
        td_txt[k][j] = 0;
        memcpy(lyl_ren0, td_txt[k], j + 1);
        td_caret = 2214;
    }
}

static void lyl_ren_close(int ok)
{
    int k = ui_tdlg_index(td_t, 2214), off, i = lyl_ren;

    td_open = 0;
    lyl_ren = -1;
    if (!ok || i < 0 || !have_drawing || k < 0 || k >= TD_MAX
        || !strcmp(td_txt[k], lyl_ren0))
        return;
    off = jw_add_str_w(&drawing, td_txt[k], drawing.version > 0x275);
    if (off < 0)
        return;
    if (lyl_open == 1)
        drawing.group[ly_wg()].layer_name[i] = off;
    else
        drawing.group[i].name = off;
}

/* FUN_0059c640（左）・FUN_0059ce70（右）。窓の外は何もしない（モーダル） */
static int lyl_press(int x, int y, int button)
{
    rect_t r, p;
    int i;

    if (!have_drawing) {
        lyl_open = 0;
        return 1;
    }
    lyl_rect(&r);
    if (x < r.x || x >= r.x + r.w || y < r.y || y >= r.y + r.h)
        return 0;
    if (ui_win_close_hit(&r, x, y)) {
        lyl_open = 0;
        return 1;
    }
    for (i = 0; i < 16; i++) {
        char s[300];
        int lx, ly, on_label;

        app_laylist_pane(i, &p);
        if (x < p.x || x >= p.x + p.w || y < p.y || y >= p.y + p.h)
            continue;
        lx = x - (p.x + 3);
        ly = y - (p.y + 3);
        lyl_label(i, s, (int)sizeof s);
        on_label = ly < 0x13 && lx <= jw_text_count(s) * 9;
        if (button == 0) {
            if (on_label)
                lyl_rename(i);
            else if (!lyl_is_write(i))
                press_layer_in(lyl_open == 1 ? 0 : 1, i, 0, 1);
        } else {
            lyl_select(i);
            if (!lyl_is_write(i))
                press_layer_in(lyl_open == 1 ? 0 : 1, i, 1, 1);
        }
        return 1;
    }
    return 1;
}

/* 一つの升目: その レイヤ（グループ）だけを 用紙全体 で */
static void lyl_paint_pane(int i, const rect_t *p)
{
    fb_t t;
    jw_drawing d;
    jw_view v;
    rect_t rr;
    char s[300];
    int g, l, x, y, wg = ly_wg(), sel = i == lyl_sel;
    int iw = p->w - 6, ih = p->h - 6, th = jw_text_height();

    ui_win_dlgframe(&fb, p->x, p->y, p->w, p->h);
    if (iw <= 0 || ih <= 0 || !fb_init(&t, iw, ih))
        return;
    fb_fill(&t, 0, 0, iw, ih, 0xffffffu);
    d = drawing;                        /* 浅い写し: 状態だけ替える */
    for (g = 0; g < 16; g++) {
        d.group[g].state = 0;
        if (lyl_open == 1 && g == wg)
            for (l = 0; l < 16; l++)
                d.group[g].layer[l].state = l == i ? 2 : 0;
    }
    d.group[lyl_open == 1 ? wg : i].state = 2;
    rr.x = rr.y = 0;
    rr.w = iw;
    rr.h = ih;
    jw_view_fit(&v, &rr, d.paper_hw, d.paper_hh);
    jw_draw(&t, &v, &d);
    for (y = 0; y < ih; y++) {
        int fy = p->y + 3 + y;

        if (fy < 0 || fy >= fb.h)
            continue;
        for (x = 0; x < iw; x++) {
            int fx = p->x + 3 + x;

            if (fx >= 0 && fx < fb.w)
                fb.px[fy * fb.w + fx] = t.px[y * iw + x];
        }
    }
    fb_free(&t);
    lyl_label(i, s, (int)sizeof s);
    {
        int w = jw_text_px_w(s);

        if (w > iw - 1)
            w = iw - 1;
        fb_fill(&fb, p->x + 4, p->y + 4, w, th, sel ? 0x646464u : 0xc8c8c8u);
        jw_text_px_fit(&fb, p->x + 4, p->y + 4, s, sel ? 0xffffffu : 0x000000u,
                       iw - 1);
    }
}

static void lyl_paint(void)
{
    rect_t r, p;
    char t[160], s[300];
    int i, cx, cy, wg;

    if (!lyl_open)
        return;
    if (!have_drawing) {
        lyl_open = 0;
        return;
    }
    wg = ly_wg();
    lyl_rect(&r);
    if (lyl_open == 1)
        snprintf(t, sizeof t, "\x83\x8c\x83" "C\x83\x84\x88\xea\x97\x97     ( [%X] "
                 "\x83O\x83\x8b\x81[\x83v )", wg);
    else
        snprintf(t, sizeof t, "\x83\x8c\x83" "C\x83\x84\x83O\x83\x8b\x81[\x83v"
                 "\x88\xea\x97\x97");
    ui_win_frame(&fb, &r, t);
    cx = r.x + 8;
    cy = r.y + 31;
    /* 上の帯（decomp/res/layerlist.txt の位置）: リスト表示 は押せない、
       列 × 行、2575、選んだもの (1487) */
    ui_win_check(&fb, cx + 4, cy + 3, 17, "\x83\x8a\x83X\x83g\x95\x5c\x8e\xa6", 1);
    ui_win_edit(&fb, cx + 84, cy, 23, 20, "4");
    jw_text_px(&fb, cx + 126, cy + 5, "\x81~", 0x000000u);
    ui_win_edit(&fb, cx + 142, cy, 23, 20, "4");
    ui_win_edit(&fb, cx + 252, cy, 23, 20, "0");
    snprintf(s, sizeof s, lyl_open == 1 ? "(%X) %s" : "[%X] %s", lyl_sel,
             lyl_name(lyl_sel));
    jw_text_px_fit(&fb, cx + 389, cy + 5, s, 0x000000u, r.w - 16 - 389 - 4);
    for (i = 0; i < 16; i++) {
        app_laylist_pane(i, &p);
        lyl_paint_pane(i, &p);
    }
}
