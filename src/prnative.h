/* ネイティブ版の印刷の窓（src/main_win32.c が print_gdi のあとで #include する）。
 *
 * 逆コンパイルの読み、原典では押していない（印刷は Windows の印刷の窓を
 * 通るので、無人では駆動していない）。
 *
 *   印刷 (57607)        原典は命令に入る前に印刷の窓（OnPreparePrinting
 *                       FUN_0050be70）を出し、キャンセルなら入らない。OK なら
 *                       FUN_004fccb0 がプリンタの GetDeviceCaps(HORZSIZE/
 *                       VERTSIZE) を doc+0x8f08/0x8f0c に取り、枠はその紙。
 *                       移植は jw_pr_entered で入ったのを知って窓を出し、
 *                       キャンセルなら前の命令に戻す。印刷 (L) はその
 *                       プリンタへ窓なしで刷る
 *   プリンタの設定 (1067) FUN_005aeaf0: ID_FILE_PRINT_SETUP (0xe106) を送る
 *                       ＝ MFC の CWinApp::OnFilePrintSetup（PD_PRINTSETUP の
 *                       PrintDlg）。そのあと送る 0x8054（印刷倍率）は 倍率の
 *                       箱を付け直すだけなので、移植は描き直すだけ
 *   出力方法設定 (1069)  FUN_005aeb40: プリント出力形式（DIALOG 344、
 *                       CPrintKeishikiDialog）を DoModal。ファイル連続印刷
 *                       (1066, FUN_005b0300) は +0xb0 を立てて窓を閉じ、
 *                       FUN_005aeb40 が「JWW Files (*.jww)|*.jww||」の複数選択
 *                       （OFN_ALLOWMULTISELECT 0x200、DAT_00a0c7b4 が 0 でない
 *                       とき。0 なら Jw の自前のファイル窓 FUN_005b0590）で
 *                       ファイルを取り、数を **(bar+0xc0)（命令の +0xa8）へ。
 *                       そしてまた窓を出す（OK・キャンセルで抜けるまで）
 *   印刷 (L) の連続印刷  FUN_006d1ae0: +0xa8 が 1 以上なら、図面が変わって
 *                       いれば 5628「データが変更されています。保存しますか？」
 *                       （MB_YESNO）で はい なら保存（名前が無ければ名前を
 *                       付けて）。いまの図面を刷り、選んだファイルを一つずつ
 *                       開いて（FUN_004dd3e0）刷り、最後に元の図面に戻す
 *                       （FUN_004e8d60 で開き直す、名前が無ければ新規）
 *
 * 移植で違うところ・入れなかったもの:
 *   - 元の図面へは開き直さず、刷る前の控え（app_save_backup）から戻す
 *     （いいえ と答えた変更を失わない。変更ありの印も戻す）
 *   - 一枚ずつ別の印刷ジョブ（原典は vtable+0x78 を一度呼んでからループする
 *     ので一つのジョブかもしれないが、読み切れていない）
 *   - プリント出力形式 のほかの箱: 値の行き先と効き目は src/plot.c の
 *     jw_pr_opt の注（FUN_005aeb40 が窓の前に doc から写し IDOK で書き戻す、
 *     FUN_005af810・FUN_005afa70 が 1329・1330）。押せるのは 1323・1324
 *     連続出力、1325 グレー（カラー印刷 で連続出力のときだけ、
 *     FUN_005afbc0 の +0x2e8）・1326、1330 線幅も倍率。キャンセルは捨てる
 *     （1330 は原典では壊し手が戻すのでキャンセルでも残る。移植も残す）。
 *     押せないまま: 1064 レイヤ順・1065 線色順（カラー印刷のときだけ押せる。
 *     重ね順の読み手を読み切っていない）、1327・1329・1331・1333（移植の
 *     刷り上がりが変わらない）、1328・2113・2114（ファイル連続印刷 で
 *     ファイルがあるときだけ押せる。移植は枠・倍率・レイヤ・線色を
 *     ファイルごとに変えないので いつも 現状維持、それを入れて見せる）、
 *     2863 図面情報連続印刷（0x80e6 の命令が移植に無い）
 *   - 連続出力の GDI の印刷は 一頁ずつ別のジョブ（原典は FUN_006d5950 を
 *     頁ごとに呼ぶ一つのジョブ）。PNG で保存は一頁目だけ、PDF は全頁
 *   - 原典の 印刷 の前に いまの図面を刷るかどうかの条件（FUN_004146c0 と
 *     bar+0xd4）は読み切れていないので、いつも刷る
 *   - PageSetupDlg は原典に無い（用紙の向き・大きさは プリンタの設定 の窓で）
 */

static HGLOBAL pr_devmode;              /* 選んだプリンタ（PrintDlg が持たせたもの。
                                           pr_devnames は main_win32.c の頭） */
static int pr_prev_cmd;                  /* 印刷に入る前の命令（キャンセルで戻す） */
static wchar_t *pr_files;                /* ファイル連続印刷: 名前を \0 で区切って */
static int pr_nfiles;

static HDC pr_dc(void)
{
    DEVNAMES *dn;
    DEVMODEW *dm;
    HDC dc;

    if (!pr_devnames || !(dn = (DEVNAMES *)GlobalLock(pr_devnames)))
        return NULL;
    dm = pr_devmode ? (DEVMODEW *)GlobalLock(pr_devmode) : NULL;
    dc = CreateDCW((const wchar_t *)dn + dn->wDriverOffset,
                   (const wchar_t *)dn + dn->wDeviceOffset, NULL, dm);
    if (dm)
        GlobalUnlock(pr_devmode);
    GlobalUnlock(pr_devnames);
    return dc;
}

/* 枠と刷る紙をそのプリンタの紙に（FUN_004fccb0） */
static void pr_take_paper(HDC dc)
{
    if (dc)
        jw_pr_printer_paper((double)GetDeviceCaps(dc, HORZSIZE),
                            (double)GetDeviceCaps(dc, VERTSIZE));
}

/* 1 なら OK。setup は PD_PRINTSETUP（プリンタの設定） */
static int pr_dialog(HWND wnd, int setup)
{
    PRINTDLGW pd;
    HDC dc;

    ZeroMemory(&pd, sizeof pd);
    pd.lStructSize = sizeof pd;
    pd.hwndOwner = wnd;
    pd.hDevMode = pr_devmode;
    pd.hDevNames = pr_devnames;
    pd.nCopies = 1;
    pd.Flags = setup ? PD_PRINTSETUP
                     : PD_RETURNDC | PD_NOSELECTION | PD_NOPAGENUMS | PD_USEDEVMODECOPIESANDCOLLATE;
    if (!PrintDlgW(&pd))
        return 0;
    pr_devmode = pd.hDevMode;
    pr_devnames = pd.hDevNames;
    if (pd.hDC) {
        pr_take_paper(pd.hDC);
        DeleteDC(pd.hDC);
    } else if ((dc = pr_dc()) != NULL) {
        pr_take_paper(dc);
        DeleteDC(dc);
    }
    return 1;
}

/* ---- プリント出力形式（DIALOG 344）を写した窓 ---------------------------- */
typedef struct {
    short id, x, y, cx, cy;
    DWORD style;
    const wchar_t *text;
} pr_item;

#define PR_ON  0x50010000u              /* WS_CHILD|WS_VISIBLE|WS_TABSTOP */
#define PR_OFF (0x50010000u | WS_DISABLED)
static const pr_item PR_KEISHIKI[] = {
    { 1, 110, 3, 80, 17, PR_ON | BS_DEFPUSHBUTTON, L"OK" },
    { 2, 129, 23, 61, 14, PR_ON, L"ｷｬﾝｾﾙ" },
    { 1064, 10, 4, 59, 16, PR_OFF, L"レイヤ　順" },
    { 1065, 10, 22, 59, 16, PR_OFF, L"線色　　順" },
    { 1323, 10, 44, 115, 13, PR_ON | BS_AUTOCHECKBOX, L"レイヤグループごとの連続出力" },
    { 1324, 10, 59, 80, 13, PR_ON | BS_AUTOCHECKBOX, L"レイヤごとの連続出力" },
    { 1325, 10, 74, 186, 13, PR_OFF | BS_AUTOCHECKBOX, L"共通連続出力レイヤ(表示のみレイヤ)をグレー色" },
    { 1326, 10, 89, 119, 13, PR_ON | BS_AUTOCHECKBOX, L"表示のみレイヤは印刷しない" },
    { 1329, 10, 105, 119, 10, PR_OFF | BS_AUTOCHECKBOX, L"実点を指定半径でプリンタ出力" },
    { 1327, 129, 45, 67, 10, PR_OFF | BS_AUTOCHECKBOX, L"円を線変換出力" },
    { 1330, 129, 60, 56, 10, PR_ON | BS_AUTOCHECKBOX, L"線幅も倍率" },
    { 1331, 129, 90, 67, 10, PR_OFF | BS_AUTOCHECKBOX, L"BMPに展開出力" },
    { 1333, 129, 105, 67, 10, PR_OFF | BS_AUTOCHECKBOX, L"用紙全体を展開" },
    { 1066, 10, 122, 180, 16, PR_ON, L"ファイル連続印刷" },
    { 1328, 10, 141, 119, 11, PR_OFF | BS_AUTOCHECKBOX, L"印刷範囲・倍率を現状維持で印刷" },
    { 2113, 10, 153, 119, 12, PR_OFF | BS_AUTOCHECKBOX, L"レイヤ状態を現状維持で印刷" },
    { 2114, 10, 166, 119, 12, PR_OFF | BS_AUTOCHECKBOX, L"線色・線幅を現状維持で印刷" },
    { 2863, 129, 139, 61, 20, PR_OFF, L"図面情報連続印刷" },
};
#define PR_NKEISHIKI ((int)(sizeof PR_KEISHIKI / sizeof PR_KEISHIKI[0]))

static WORD *pr_put_str(WORD *p, const wchar_t *s)
{
    do
        *p++ = (WORD)*s;
    while (*s++);
    return p;
}

static WORD *pr_align4(WORD *p, const WORD *base)
{
    if (((p - base) & 1) != 0)
        *p++ = 0;
    return p;
}

/* 窓で押せて値を持つ箱（src/plot.c の jw_pr_opt） */
static const short PR_LIVE[] = { 1323, 1324, 1325, 1326, 1330 };

/* FUN_005afbc0: 1325 は カラー印刷 で 1323 か 1324 が入っているときだけ */
static void pr_keishiki_grey(HWND dlg)
{
    jw_plot_frame f;

    jw_pr_settings(&f);
    EnableWindow(GetDlgItem(dlg, 1325),
                 f.colour && (IsDlgButtonChecked(dlg, 1323) == BST_CHECKED
                              || IsDlgButtonChecked(dlg, 1324) == BST_CHECKED));
}

static INT_PTR CALLBACK pr_keishiki_proc(HWND dlg, UINT msg, WPARAM wp, LPARAM lp)
{
    int i;

    (void)lp;
    if (msg == WM_INITDIALOG) {
        CheckDlgButton(dlg, 1328, BST_CHECKED);   /* 移植の刷り方（枠を変えない）を見せる */
        for (i = 0; i < (int)(sizeof PR_LIVE / sizeof PR_LIVE[0]); i++)
            CheckDlgButton(dlg, PR_LIVE[i], jw_pr_opt(PR_LIVE[i]) ? BST_CHECKED : BST_UNCHECKED);
        pr_keishiki_grey(dlg);
        return TRUE;
    }
    if (msg == WM_COMMAND) {
        switch (LOWORD(wp)) {
        case 1323: case 1324: case 1325: case 1326: {
            /* 組の片方を入れると他方を切る（FUN_005b0320・0370・03c0・0400） */
            int id = LOWORD(wp), other = id == 1323 ? 1324 : id == 1324 ? 1323
                                       : id == 1325 ? 1326 : 1325;

            if (IsDlgButtonChecked(dlg, id) == BST_CHECKED)
                CheckDlgButton(dlg, other, BST_UNCHECKED);
            pr_keishiki_grey(dlg);
            return TRUE;
        }
        case 1330:
            return TRUE;
        case IDOK:                    /* FUN_005aeb40: IDOK なら書き戻す。1066 も */
        case 1066:                      /* OnOK で閉じる（FUN_005b0300: +0xb0 = 1） */
            for (i = 0; i < (int)(sizeof PR_LIVE / sizeof PR_LIVE[0]); i++)
                jw_pr_set_opt(PR_LIVE[i], IsDlgButtonChecked(dlg, PR_LIVE[i]) == BST_CHECKED);
            EndDialog(dlg, LOWORD(wp) == 1066 ? 2 : 1);
            return TRUE;
        case IDCANCEL:                  /* 1330 だけは壊し手 FUN_005afa70 が戻すので残る */
            jw_pr_set_opt(1330, IsDlgButtonChecked(dlg, 1330) == BST_CHECKED);
            EndDialog(dlg, 0);
            return TRUE;
        }
    }
    return FALSE;
}

static INT_PTR pr_keishiki_box(HWND wnd)
{
    WORD *buf = (WORD *)calloc(8192, sizeof(WORD)), *p;
    DLGTEMPLATE *t;
    INT_PTR r;
    int i;

    if (!buf)
        return 0;
    t = (DLGTEMPLATE *)buf;
    t->style = DS_MODALFRAME | DS_SETFONT | WS_POPUP | WS_CAPTION | WS_SYSMENU;
    t->cdit = (WORD)PR_NKEISHIKI;
    t->x = 0;
    t->y = 0;
    t->cx = 198;
    t->cy = 183;
    p = (WORD *)(t + 1);
    *p++ = 0;                           /* menu */
    *p++ = 0;                           /* class */
    p = pr_put_str(p, L"プリント出力形式");
    *p++ = 9;
    p = pr_put_str(p, L"ＭＳ Ｐゴシック");
    for (i = 0; i < PR_NKEISHIKI; i++) {
        DLGITEMTEMPLATE *it;

        p = pr_align4(p, buf);
        it = (DLGITEMTEMPLATE *)p;
        it->style = PR_KEISHIKI[i].style;
        it->dwExtendedStyle = 0;
        it->x = PR_KEISHIKI[i].x;
        it->y = PR_KEISHIKI[i].y;
        it->cx = PR_KEISHIKI[i].cx;
        it->cy = PR_KEISHIKI[i].cy;
        it->id = (WORD)PR_KEISHIKI[i].id;
        p = (WORD *)(it + 1);
        *p++ = 0xffff;
        *p++ = 0x0080;                  /* BUTTON */
        p = pr_put_str(p, PR_KEISHIKI[i].text);
        *p++ = 0;                       /* creation data */
    }
    r = DialogBoxIndirectParamW(GetModuleHandleW(NULL), t, wnd, pr_keishiki_proc, 0);
    free(buf);
    return r;
}

/* ファイル連続印刷のファイルを選ぶ（複数）。選ばなければ 0 本 */
static void pr_pick_files(HWND wnd)
{
    enum { N = 0x63c7 };
    wchar_t *b = (wchar_t *)calloc(N + 2, sizeof(wchar_t));
    OPENFILENAMEW o;

    free(pr_files);
    pr_files = NULL;
    pr_nfiles = 0;
    if (!b)
        return;
    ZeroMemory(&o, sizeof o);
    o.lStructSize = sizeof o;
    o.hwndOwner = wnd;
    o.lpstrFilter = L"JWW Files (*.jww)\0*.jww\0\0";
    o.lpstrFile = b;
    o.nMaxFile = N;
    o.lpstrDefExt = L"jww";
    o.Flags = OFN_ALLOWMULTISELECT | OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    if (!GetOpenFileNameW(&o)) {
        free(b);
        return;
    }
    if (b[wcslen(b) + 1] == 0) {        /* 一つだけ: 全部の道 */
        pr_files = b;
        pr_nfiles = 1;
        b[wcslen(b) + 1] = 0;
        return;
    }
    {   /* 先頭がフォルダ、あとは名前。道に組み直す */
        size_t dl = wcslen(b), total = 0;
        const wchar_t *q;
        wchar_t *out, *w;

        for (q = b + dl + 1; *q; q += wcslen(q) + 1)
            total += dl + 1 + wcslen(q) + 1;
        out = (wchar_t *)calloc(total + 2, sizeof(wchar_t));
        if (!out) {
            free(b);
            return;
        }
        w = out;
        for (q = b + dl + 1; *q; q += wcslen(q) + 1) {
            memcpy(w, b, dl * sizeof(wchar_t));
            w += dl;
            if (dl && b[dl - 1] != L'\\')
                *w++ = L'\\';
            wcscpy(w, q);
            w += wcslen(q) + 1;
            pr_nfiles++;
        }
        *w = 0;
        pr_files = out;
        free(b);
    }
}

/* 出力方法設定 (1069): FUN_005aeb40 のループ */
static void pr_keishiki(HWND wnd)
{
    while (pr_keishiki_box(wnd) == 2)
        pr_pick_files(wnd);
}

/* 開くだけ（最近のファイル・いまの名前は触らない） */
static int pr_load(const wchar_t *path)
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
    b = (unsigned char *)malloc((size_t)(n > 0 ? n : 1));
    if (b && fread(b, 1, (size_t)n, f) == (size_t)n)
        ok = app_open(b, n);
    fclose(f);
    free(b);
    return ok;
}

/* 印刷 (L)。連続印刷のファイルがあれば FUN_006d1ae0 のとおり */
static int pr_print(HWND wnd)
{
    unsigned char *keep = NULL;
    long nkeep = 0;
    int was_mod, i;
    const wchar_t *q;

    if (pr_nfiles < 1)
        return print_gdi(wnd);
    if (app_modified()
        && MessageBoxW(wnd, L"データが変更されています。 保存しますか ？", L"Jw_cad",
                       MB_YESNO | MB_ICONQUESTION) == IDYES) {
        if (current_path[0])
            save_file(current_path);
        else
            ask_save(wnd);
    }
    was_mod = app_modified();
    app_save_backup(&keep, &nkeep);
    print_gdi(wnd);
    for (i = 0, q = pr_files; i < pr_nfiles && q && *q; i++, q += wcslen(q) + 1)
        if (pr_load(q))
            print_gdi(wnd);
    if (keep) {                         /* 元の図面へ */
        app_open(keep, nkeep);
        free(keep);
        if (was_mod)
            app_mark_modified();
    }
    sync_doc();
    if (jw_cmd() != JW_PRINT_CMD) {     /* 開いて命令が替わっていれば、窓なしで戻る */
        app_command(57607);
        jw_pr_entered();
    }
    return 1;
}

/* do_action のたびに: 印刷の命令に入った・窓の釦が押された */
static int pr_hooks(HWND wnd)
{
    int r = 0, a;

    if (jw_pr_entered()) {
        free(pr_files);                 /* 連続印刷は命令ごと（命令の +0xa8） */
        pr_files = NULL;
        pr_nfiles = 0;
        if (!(_wgetenv(L"JW_PRINTER") && *_wgetenv(L"JW_PRINTER")) && !pr_dialog(wnd, 0)) {
            /* キャンセル: 原典は命令に入らない */
            app_command(pr_prev_cmd && pr_prev_cmd != JW_PRINT_CMD ? pr_prev_cmd : JW_CMD_SEN);
            jw_pr_entered();
        }
        r = 1;
    }
    while ((a = jw_pr_ask()) != 0) {
        if (a == 1067)
            pr_dialog(wnd, 1);
        else if (a == 1069)
            pr_keishiki(wnd);
        r = 1;
    }
    if (jw_cmd() != JW_PRINT_CMD)
        pr_prev_cmd = jw_cmd();
    return r;
}
