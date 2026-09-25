# Jw_cad for Windows — 解析と C 移植

Windows 用の 2 次元汎用 CAD **Jw_cad Version 10.03.6**（Jiro Shimizu &
Yoshifumi Tanaka、2026-09-05 版）を、実行ファイルを Ghidra で逆コンパイルして
解析し、C に書き直して最終的に WASM で動かすためのリポジトリです。

**動かす: https://yomei-o.github.io/jwcad_win_wasm/**
手元の **`.jww`・`.dxf`・`.sfc`・`.jwc`・`.jws`（図形）・座標ファイルを
開けて**、**`.jww`・`.dxf`・`.sfc`・`.jwc` で保存できます**（どれも手元だけで、
どこにも送られません）。ホイールで拡大縮小、ドラッグで移動、Home で全体。

進め方は [lord_monarch_online_wasm](https://github.com/yomei-o/lord_monarch_online_wasm)
と [jwcad_dos_wasm](https://github.com/yomei-o/jwcad_dos_wasm) と同じ
——逆コンパイル出力と突き合わせて C に書き直し、ネイティブと WASM を同じ
ソースから作り、**原典の画面と 1 画素ずつ突き合わせて**検証する——ですが、
規模がまるで違います。

| | コード | 関数 |
|---|---:|---:|
| Super Depth | 70,731 バイト | 239 |
| JW_CAD for DOS | 1,451,937 バイト | 約 1,500 |
| **Jw_cad for Windows** | **5,582,629 バイト**（`.text`） | **26,061** |

うち相当量が静的リンクされた MFC と MSVC ランタイムなので、最初の仕事は
「何をする関数か」ではなく「**どれが Jw_cad 自身のコードか**」を切り分けることです。
それは RTTI から機械的に出せて、すでに出してあります（下記「クラス構成」）。

**いまできていること: CAD として一通り使えるところまで。** 画面・メニュー・
ダイアログ・文字列・ツールバーを取り出し、C++ のクラス構成と継承関係、どの関数が
どのクラスの何番目の仮想関数かまで復元したうえで、**描く・消す・編集する・
保存する**をひととおり移しました。**メニューも開いて押せます** ——
ネイティブは原典のメニュー資源とアクセラレータ資源をそのまま Windows に
渡し、ブラウザは同じ木からポップアップを自分で描きます。続きに入る人は
[RESUME.md](RESUME.md) から読んでください。

**ファイルの出し入れは 6 形式、読み書き両方あります。**

| | 読む | 書く | 突き合わせ |
|---|---|---|---|
| `.jww` | ✓ | ✓ | 原典の保存したものと 1 バイト違わず（2 万要素の往復も） |
| DXF | ✓ | ✓ | 原典の書いた DXF と 1 バイト違わず |
| SFC（SXF） | ✓ | ✓ | 同上。楕円弧・任意色・任意線種まで |
| JWC | ✓ | ✓ | 同上（頭の CSV の 5 つだけは原典のものを焼いています） |
| `.jws`（図形） | ✓ | ✓ | 図形読込／図形登録。書いたものは原典と 1 バイト違わず |
| 座標ファイル | ✓ | ✓ | 同上。文字（`cz`・`ck`・`ch`）まで |

どれも**原典に同じファイルを作らせて 1 バイトずつ**、あるいは**原典に
同じファイルを開かせた `.jww` と要素ごとに**突き合わせてあります。

**コマンドも主なものは入っています** —— 線・矩形・円・点・文字・寸法・
複線・コーナー・面取・伸縮・分割・中心線・2 線・多角形・接線・接円・
曲線・ハッチ・**包絡処理**・属性取得・属性変更・属性選択・範囲選択・
複写・移動・**データ整理**・**ブロック**（化・解除・属性・編集・名前変更）・
**図形読込／図形登録**・**座標ファイル**・読取（中心点・線上点・交点・
円周1/4点）、それに**線属性・書込み文字種変更・基本設定（8 枚のタブ）・
軸角・寸法設定・画面倍率・用紙サイズ**のダイアログ。
`sh tools/check.sh` が **1,190 項目**を通し、そのうえで同梱の図形 341 個・
図面 170 枚を読んで書き戻し、**壊れたファイル 95 万通り**を読ませます。

## 目標

**ネイティブの画面と WASM の画面が、ビットマップとして完全に一致すること。**
フォントの字形だけは環境が持つものに依存するので一致しなくてよい、という条件です。

そのため原典側の基準画像を先に取ってあります（`tools/shot.ps1`）。

```sh
powershell -ExecutionPolicy Bypass -File tools/shot.ps1 \
    -Exe orig/Jw_win.exe -Out docs/ref_test1.png -Open orig/Test1.jww -Screen
```

![起動直後](docs/ref_start.png)

**`-Screen` が要ります。** Jw_cad 10.x は既定で Direct2D に描くので、
`PrintWindow` では枠だけ返ってきて**図面の部分が真っ白**になります。
デスクトップから画素を読む方が確実です。
（移植の突き合わせ対象としては、[設定]→[基本設定]→[一般(1)] で
**Direct2D を切った GDI 経路**を正解にするのが筋です。そちらは決定的で、
Direct2D のアンチエイリアスに追随する必要がなくなります。）

## 対象

`jww10036.exe` が配布されているインストーラ（Inno Setup 6.4.2）です。
**このリポジトリに入れてあります** —— ダウンロードしたそのままの 1 ファイルで、
中身は一切変えていません。Jw_cad の使用条件（`Jw_win.txt` の「（３）転載及び
配布」）が「プログラムを改変しないこと」「このままの形態で配布すること」の
二つなので、配布された形のまま置くのがいちばん条件に合います。

**著作権者は Jiro Shimizu & Yoshifumi Tanaka** で、Jw_cad はフリーソフト
ウェアです。使用条件の全文はインストーラを展開して `orig/Jw_win.txt` を
読んでください。

展開した `orig/` と、そこから機械的に作った `decomp/`・`src/gen/` は
リポジトリに入れていません（展開した形は「このままの形態」ではないし、
逆コンパイルは原プログラムの改変にあたりうるため）。どちらも手元で作れます。

サイレントインストールで中身が出ます。

```sh
./jww10036.exe /VERYSILENT /SUPPRESSMSGBOXES /NORESTART /NOICONS \
    "/DIR=C:\prog\claude3\jwcad_win_wasm\orig"
```

| ファイル | サイズ | 中身 |
|---|---:|---|
| `Jw_win.exe` | 8,537,840 | 本体。PE32 / i386、MSVC 2019（リンカ 14.29）、MFC 静的リンク |
| `common_lib.dll` | 3,687,296 | SXF（SFC/P21）入出力 |
| `common_lib_AP202.dll` | 4,376,960 | 同上 |
| `JWW2DXFConv.dll` | 383,072 | DXF 変換 |
| `JW_OPT*.DAT` | 22 本 | 建具などのパラメトリック図形。テキスト |
| `*.jww` | 14 枚 | サンプル図面 |
| `Jw_cad.chm` | 2,417,065 | ヘルプ |

`Jw_win.txt` によれば開発環境は **Visual Studio Community 2019**、
対応 OS は Windows 10 / 11 です。

### 手元で作り直すもの

`orig/` を展開したら、あとは 1 本で作れます。

```sh
sh tools/gen.sh          # 生成物を全部（-q で原典を動かす手前まで）
sh tools/check.sh        # 全部の検査
```

`tools/gen.sh` の前半は `Jw_win.exe` を読むだけの計算で 1 分ほど、後半は
**原典を実際に起動して**コマンドバー・線属性ダイアログ・検査用の図面を
読み出すので 20 分ほどかかります。順番に意味があります
（`btnmap.py` は `rsrc.py` の出力を、`mkcmd.py` は `btnmap.py` の出力を要る）。

中身は次のとおりで、個別に叩いても同じです。

```sh
python tools/rsrc.py   orig/Jw_win.exe decomp/res         # メニュー・文字列・絵
python tools/mkres.py  orig/Jw_win.exe src/gen --maxh 21  # 枠の画像と文字列
python tools/btnmap.py docs/ref_start.png decomp/res/bitmap src/gen/layout.h
python tools/mkcmd.py --write                             # ボタンが送るコマンド
python tools/mkfont.py font src/gen                       # 東雲フォント
python tools/mkcp932.py                                   # CP932 ↔ UTF-16
python tools/mkicon.py orig/Jw_win.exe src/gen            # 窓のアイコン
python tools/mkmenu.py                                    # メニュー
python tools/mkstr.py                                     # ステータス行の文言
python tools/mkpen.py                                     # 新規図面のペン
python tools/mksunpo.py                                   # 寸法の設定
gcc -O2 -o tmp/gdicirc.exe tools/gdicirc.c -lgdi32
tmp/gdicirc.exe > decomp/res/circles.txt
python tools/mkcirc.py                                    # GDI の円
# ここから原典が動きます
sh  tools/refenv.sh                                       # 基準のレジストリ
powershell -File tools/bars.ps1 -Out decomp/res/bars.txt  # コマンドバー
python tools/mkbars.py
powershell -File tools/jwdraw.ps1 -Open tmp/rect.jww -NoSave     -Out decomp/res/zoku.txt -Clicks 'dlg:32807,tmp/zoku.png'   # 線属性
python tools/mkzoku.py
sh  tools/refanswers.sh                                   # 検査用の図面 9 枚
python tools/mknew.py decomp/res/new.jww src/gen          # 新規図面のひな型
```

**原典を駆動するスクリプトは `tools/` にあります。**
README と RESUME の古い版は `tmp/jwdraw.ps1`・`tmp/bars.ps1` と書いて
いましたが、`tmp/` はリポジトリに入らないので、新しい環境ではそこが
まるごと欠けます。いまは `tools/jwdraw.ps1`・`tools/bars.ps1` が本体で、
`tmp/` の同名は転送するだけです（古い手順もそのまま動きます）。

### 撮る側の環境

基準画像は**画面の拡大縮小 100%** で撮ったものです。`Jw_win.exe` は
マニフェストに `<dpiAware>true</dpiAware>` を持つ system DPI aware な
アプリなので、150% のまま起動すると 144dpi で自分を描き直し、字も枠の
位置も基準と別物になります。`tools/shot.ps1` は窓を 1280×800 にするので、
作業領域も 800 行以上要ります。

この条件さえ合っていれば**機械が変わっても画素は同じ**です
（Intel の Windows 11 で撮り直して、`docs/ref_start.png`・`docs/ref_test1.png`・
`docs/ref_zoku.png` のいずれも文字とテーマの枠を除いて 0 画素差でした）。

### Jw_win.exe の構成

```
.text    VA 0x00401000  5,582,629 バイト   コード
.rdata   VA 0x00954000    694,806 バイト   定数・RTTI・インポート
.data    VA 0x009fe000     93,292 バイト   （仮想 93,292、ファイル上 40,960）
.rsrc    VA 0x00a15000  2,205,760 バイト   リソース
```

インポートは 22 DLL・676 関数。**GDI32 が 122、USER32 が 226** で、
古典的な Win32 / MFC のアプリです。加えて **d2d1 / DWrite**（Direct2D 描画）、
**gdiplus**（画像）、**MSVFW32**（`DrawDib`）、**IMM32**（日本語入力）。

```sh
python tools/peinfo.py orig/Jw_win.exe    # セクションとインポート一覧
```

## わかっていること

### 画面まわりは逆コンパイルしなくても正確に取り出せる

メニュー・ダイアログ・文字列・ツールバー・ビットマップは `.rsrc` に
文書化された形式でそのまま入っています。機械語から起こす必要はありません。

```sh
python tools/rsrc.py orig/Jw_win.exe decomp/res
```

| 出力 | 中身 |
|---|---|
| `menu.txt` | メニュー 3 本、270 行。コマンド ID 付き |
| `dialog.txt` | ダイアログ 108 枚、2,754 行。全コントロールの位置・大きさ・スタイル・ID |
| `string.txt` | 文字列 1,598 本 |
| `toolbar.txt` | ツールバー 183 本。**16×15 から 120×75 まで 12 段階の大きさ違い**を持っている |
| `dlginit.txt` | コンボボックスの初期項目（MFC の `RT_DLGINIT`） |
| `accel.txt` | アクセラレータ 2 本 |
| `bitmap/` | ビットマップ 469 枚（1.9 MB） |

ツールバーの `RT_TOOLBAR` は MFC の型番 **241**、`RT_DLGINIT` は **240** です
（`afxres.h`）。`tools/rsrc.py` は両方を解きます。

**ツールバーが 12 段階あるのは、Jw_cad が画面のボタンを段階的に拡大できるからです。**
移植でもこの 12 枚をそのまま使えば、どの倍率でもボタンが 1 画素まで一致します。

### クラス構成は RTTI から完全に出る

RTTI を有効にしてビルドされているので、`.rdata` にクラスごとの型記述子と、
vtable の直前に完全オブジェクトロケータが残っています。そこから
**クラス名・継承関係・どの関数が何番目の仮想関数か**が機械的に出ます。

```sh
python tools/rtti.py orig/Jw_win.exe decomp/rtti
# type descriptors 714, locators 749, classes with vtables 676
# vftable slots 41443 -> decomp/rtti/vftables.csv
# hierarchies 676 -> decomp/rtti/hierarchy.txt
```

714 クラスのうち MFC・ATL・STL を除いた **Jw_cad 自身のクラスは約 240**。
これが移植先のファイル構成そのものになります。

#### アプリの骨格

```
CJw_winApp   : CWinApp
CMainFrame   : CFrameWnd
CJw_winDoc   : CMiniDoc : CDocument
CJw_winView  : CView, CGamenJoken      ← 多重継承
CScreenWnd   : CWnd
CZoom        : CObject
CLayer / CLType / CStyle / CGamenJoken : （非多態、素のクラス）
```

#### 図面の要素 —— `CData` 系

```
CData : CObject
 ├ CDataSen     線        ├ CDataEnko   円弧    ├ CDataMoji   文字
 ├ CDataTen     点        ├ CDataSolid  ソリッド ├ CDataSunpou 寸法
 ├ CDataBlock   ブロック   ├ CDataList
 └ CData3DSen / CData3DEnko / CData3DSolid   （それぞれ 2D 版を継承）
CDataHensuu / CDataHenkei / CDataHndl : CObject
```

#### コマンド —— `CZukei` 系

コマンド 1 つに 1 クラス。メニューと 1 対 1 に対応します。

```
CZukei : CObject
 ├ CZukeiObject   ← 点・線・円弧・分割・中心線・2 線・曲線・多角形 …
 └ CZukeiSentaku  ← 範囲選択を伴うもの（複写・移動・複線・コーナー・面取・
                     消去・伸縮・包絡・整理・属性変更・図形・画像 …）
```

仮想関数から辿れるコードだけで、`CZukei*` と `CData*` と `CJw_win*` の
**69 クラスで 1,331,542 バイト**あります。これが移植の主戦場です。

| クラス | 仮想 | バイト |
|---|---:|---:|
| `CZukeiGazou`（画像） | 40 | 45,158 |
| `CZukeiMoji`（文字） | 50 | 42,855 |
| `CZukeiFukusha`（複写） | 48 | 42,781 |
| `CZukeiParametric`（建具等） | 46 | 35,770 |
| `CZukeiSentaku`（範囲選択） | 41 | 34,510 |
| `CZukeiShinshuku`（伸縮） | 46 | 33,440 |
| `CZukeiFukusen`（複線） | 49 | 32,622 |
| `CZukeiSunpo`（寸法） | 37 | 31,798 |
| …（以下 60 クラス） | | |

### 関数の棚卸し

```
26,061 関数 / 5,314,476 バイト
  名前あり  12,860 /   410,892   MFC・CRT（RTTI と復号したシンボルから）
  FUN_      13,201 / 4,903,584   まだ名前がないもの
```

`decomp/inventory.csv` が全関数の一覧です（番地・大きさ・呼び元数・呼び先数）。

### 逆コンパイル

```sh
ssh ... 'powershell -File C:\prog\jwwin\decomp_box.ps1 -Shards 10'
sh tools/decomp_get.sh
# 25983 functions, 25921 decompiled (99.8%)
# 25983 functions -> 654 files
```

26 MB の C が出ます。`tools/byclass.py` が vtable の割り当てを使って
**クラスごとのファイル**に仕分けます（`decomp/byclass/CJw_winDoc.c` など)。
仮想関数から辿れないものは `_unassigned.c` に入ります（20,316 関数）。

**MFC 派生クラスの vtable の並びは `CObject` の宣言順**です。

| スロット | |
|---|---|
| 0 | `GetRuntimeClass` |
| 1 | スカラ削除デストラクタ |
| **2** | **`Serialize`** |
| 3, 4 | `AssertValid` / `Dump` |

つまり `decomp/rtti/vftables.csv` で「スロット 2」を引けば、
どのクラスの読み書きもすぐ出ます。

| クラス | `Serialize` | 大きさ |
|---|---|---:|
| `CJw_winDoc` | `0x004d2820` → 本体 `0x00575010` | 22,125 |
| `CData` | `0x0042e690` | 345 |
| `CDataSen`（線） | `0x0042ea30` | 446 |
| `CDataEnko`（円弧） | `0x0042e7f0` | 569 |
| `CDataTen`（点） | `0x0042f340` | 437 |
| `CDataMoji`（文字） | `0x0048cff0` | 1,115 |
| `CDataSolid` | `0x0042ebf0` | 1,302 |
| `CDataSunpou`（寸法） | `0x0042f110` | 548 |
| `CDataBlock` | `0x0049b2c0` | 324 |

### 図面ファイル `.jww` —— 解けています

MFC の `CArchive` によるシリアライズです。`CJw_winDoc::Serialize`
（`0x004d2820` → 本体 `0x00575010`）を読み写して Python で書き直し、
**同梱の図面 15 枚すべてが末尾ぴったりで読めます**。

```sh
sh tools/jwwcheck.sh      # 15 枚とも「+0」で終われば形が合っている
python tools/jww.py orig/Test1.jww
```

```
version 600
16 groups -> 0x979  (scales 100 1 1 1)
names -> 0xb49
pens and line types -> 0x3752
hatch and dimensions -> 0x38ce
1686 objects at 0x38d0
  CDataSen 1642, CDataEnko 4, CDataMoji 36, CDataTen 4
file is 0x1851a bytes; stopped at 0x1851a (+0)
```

#### 全体の形

| | |
|---|---|
| `"JwwData."` | 8 バイト |
| 版 | `long`。同梱のものは **600**。読み手は版ごとに項目を足し引きします |
| 図面名 | 文字列（版 > 0x40） |
| レイヤ | `long` 2 本 ＋ **グループ 16 個**。1 個につき `long, long, double(縮尺), long` と**レイヤ 16 枚**の `long, long` |
| 設定 | `long` 21 本、`double` 数本 |
| 名前 | **レイヤ名 16×16 ＋ グループ名 16**。MFC の長さ前置文字列 |
| 用紙・ペン | `double` の並び。用紙寸法 4900/600/2000… が見えます |
| 色と線種 | **色 257 個**（`名前, long, long, double`）と**線種 33 個**（`名前, long, double×10`）。名前は `black` `red` … `continuous` `dashed` … と英語 |
| ハッチ・寸法 | `FUN_004eee80` が読む 380 バイト |
| 要素 | `CObList::Serialize` —— 個数（`WORD`）のあと `CArchive` のタグ付きオブジェクト |
| ブロック | もう 1 本の `CObList`（版 > 0x13） |

#### 要素

`CArchive` のタグは **クラスとオブジェクトを 1 つの番号列**で数えます。
`0xffff` が「初出のクラス」（スキーマと名前が続く）、`0x8000` 付きが
既出のクラスの番号、それ以外はすでに読んだオブジェクトへの参照です。

```
ff ff  58 02  08 00  "CDataSen"   初出。スキーマ 600
80 01                              2 個目以降は「1 番のクラス」
```

`CData::Serialize` が共通の 15 バイトを読みます（版 600）。

| | |
|---|---|
| `long` | `+0x04` |
| `byte` | `+0x28` 線色。100 以上は別の意味（点の種類、ソリッドの形） |
| `word` | `+0x2a` 線種 |
| `word` | `+0x2c` 線幅（版 > 0x15e） |
| `word` `word` | `+0x2e` `+0x2f` |
| `word` | `+0x44` |

そのあとがクラスごとの中身です。

| クラス | 中身 |
|---|---|
| `CDataSen` 線 | `double` 4（x0,y0,x1,y1） |
| `CDataEnko` 円弧 | `double` 7 ＋ `long` |
| `CDataTen` 点 | `double` 2 ＋ `long`。線色が 100 なら `long` ＋ `double` 2 |
| `CDataMoji` 文字 | `double` 4 ＋ `long` ＋ `double` 4 ＋ **書体名** ＋ **本文** |
| `CDataSolid` | `double` 8（4 点）。線種が 10 なら `long`（任意色の RGB） |

**`CJw_winDoc::Serialize` から直接は見えない読み手が 1 つあります。**
`FUN_004eee80` が要素の直前に 380 バイト読みます。ここを忘れると、
オブジェクトの個数のつもりで別の数を読んで、そこから全部ずれます。

## 道具

| | |
|---|---|
| `tools/pe.py` | PE の読み取り（セクション、RVA→ファイル位置、リソース木） |
| `tools/peinfo.py` | セクションとインポートの一覧 |
| `tools/rsrc.py` | メニュー・ダイアログ・文字列・ツールバー・ビットマップを取り出す |
| `tools/rtti.py` | RTTI からクラス名・継承・vtable を復元 |
| `tools/shot.ps1` | 原典の画面を PNG で撮る（基準画像） |
| `tools/analyze_box.bat` | ビルドマシンで Ghidra の自動解析（342 秒） |
| `tools/inventory_box.bat` | 全関数の棚卸し CSV |
| `tools/decomp_box.ps1` | `.text` を 10 分割して並列に逆コンパイル |
| `tools/ghidra_scripts/` | 上の 2 つが呼ぶ Ghidra スクリプト |

### ビルドマシンで回す

192.168.6.14 に Ghidra 12.1.3 と Temurin JDK 21 が入れてあります
（`jwcad_dos_wasm` の `tools/build_box_setup.ps1` で入れたもの。同じ版なので
ラップトップと出力が一致します）。5.5 MB の `.text` はラップトップで解析すると
一日仕事なので、ここは必ずビルドマシンを使います。

```sh
scp -i ~/.claude/keys/ort_build_key orig/Jw_win.exe yomei@192.168.6.14:C:/prog/jwwin/bin/
ssh -i ~/.claude/keys/ort_build_key yomei@192.168.6.14 'C:\prog\jwwin\analyze_box.bat'
ssh -i ~/.claude/keys/ort_build_key yomei@192.168.6.14 'C:\prog\jwwin\inventory_box.bat'
ssh -i ~/.claude/keys/ort_build_key yomei@192.168.6.14 \
    'powershell -ExecutionPolicy Bypass -File C:\prog\jwwin\decomp_box.ps1 -Shards 10'
```

自動解析は**一度だけ**走らせてプロジェクトを残します。逆コンパイルは
`-process -noanalysis -readOnly` で同じプロジェクトを開き直すので、
何度やり直しても解析し直しになりません。

## いまできること

**線・矩形・円・点・連続線・文字**（日本語入力つき）を描き、**消去**
（部分・図形・範囲）・**コーナー処理・線伸縮・複線・面取・分割・２線・
中心線・多角形・寸法**で編集し、**範囲選択して複写・移動**し、**線属性**で
色と線種を選び、**レイヤ**を切り替え、**新規図面から保存**までできます。
保存した `.jww` は原典がそのまま開きます。

そのうえで、**ブロック**（化・解除・属性・編集・名前変更）・**データ整理**・
**属性選択／属性変更**（「指定」の線色・線種は OK を押すと出てくる
線属性ダイアログで選びます）・**図形の読込と登録**（`.jws`）・
**座標ファイルの読み書き**・**読取モード**（線の中点と円の中心・線上点・
交点・円周 1/4 点）が入っています。ダイアログは**基本設定の 8 枚のタブ**・
**軸角**・**寸法設定**・**画面倍率**・**用紙サイズ**まで、どれも文字を除いて
**原典と 0 画素違い**です。

ネイティブの窓（`jw_port.exe`）とブラウザ（`index.html`）が同じ C を通ります。
窓の大きさを変えると原典と同じように右のバーとステータス行が端に付いてきて、
ブラウザ版は窓を持たないぶんのキャプションとメニューバーも自分で描きます。

![移植側で Test1.jww を開いたところ](docs/port_test1.png)

同じ図面を原典で開いたのが下です。**違うのは字形だけ**です
（原典は Windows の書体、こちらは東雲フォント）。

![原典](docs/ref_test1.png)

## いまの一致具合

```sh
sh tools/check.sh
```

```
=== the frame against the original
docs/ref_start.png vs tests/out/frame.png: 1264x741, 4076 of 936624 differ (0.435%)
outside the text areas: 0 differ (0.000%)

=== 別の大きさの枠 —— 右端と下端に付いてくるか
docs/ref_start_big.png vs tests/out/frame_big.png: 1484x841, ... (0.327%)
outside the text areas: 0 differ (0.000%)

=== キャプションとメニューバー（ブラウザ版が自分で描く分）
1264x51, ... (4.311%)
outside the text areas: 0 differ (0.000%)

=== native against WASM, pixel for pixel
tests/out/frame.png vs tests/out/wasm.png: 1264x741, 0 of 936624 differ (0.000%)

=== drawings against the original
    Test1  outside the text areas: 0 differ (0.000%)
    Test7  outside the text areas: 3 differ (0.000%)
           --, 0 are one pixel out (0%) and 3 are somewhere else entirely
```

検査は全部で **1,190 項目**あり（このほかに、同梱のファイルを広く読む
ものが増えました —— 図形 341 個の読みと書き戻し、図面 170 枚の読みと
書き戻し、それに**壊れたファイル 95 万通り**を読ませて落ちないか）、その多くは**原典に同じ操作をさせて保存させた
`.jww` と突き合わせる**ものです（寸法・多角形・面取・分割・２線・中心線は
座標が 1e-9 まで一致）。ダイアログは**原典が自分で描いた絵**と画素で、
ファイル形式は**原典が書いたものと 1 バイトずつ**比べています。

**破線の円弧は入りました。**原典は**実線の円弧だけ**を GDI の `Arc` に
渡し、線種が付いていれば弦の折れ線にしてから、直線と同じ線種の描き手に
渡していました（刻み幅は「図面のミリ」の階段で決まり、パターンの位置は
弦をまたいで持ち回されます）。同梱 15 枚の残差が **4,445 → 1,933 画素**、
`天空率表.jww` は 1,487 → 132、`Test1` は 193 → 28 になりました
（RESUME.md の「破線の円弧」）。**レイヤの格子の印**も直して
（2652 の升は左上ではなく「書き込んでいる升」）、合計 **1,416 画素**。
**仮点の形**も入れて（十字・3×3・1 画素の描き分け）、合計 **1,169 画素**、
**`Test1.jww`・`Test5.jww`・`円地図.jww` は 1 画素も違いません**。
残るのは線の位置が 1 画素ずれるものです。

同梱 15 枚ぶんは `sh tools/refshots.sh && sh tools/scoreall.sh`
（基準画像は**前面で**撮る必要があります。背景の `PrintWindow` では
作図領域が当てになりません）。いまは画布に対して 0.000%〜0.056%、
`Test1.jww`・`Test5.jww`・`円地図.jww` が 0 画素、悪いのが
`Ａマンション平面例` の 426 画素（0.056%）です。

図面のほうは、**字形の入る矩形を別勘定**にしてこの数字です
（`tests/shot.exe` が図面から矩形を書き出し、`tools/cmp.py` がそれを外します）。
**残りの 9 割は「1 画素ずれ」**——線は正しい場所にあって、画素の丸めだけが
違うものです。`tools/cmp.py --near` がそれと「別の場所にある」ものを分けます。

**枠は原典と 1 画素も違いません。** 残る 0.435% は全部、原典が Windows の
フォントで描いている文字です（`docs/textareas.txt` に列挙）。そこは
同じ字形を出せないので、別勘定にしてあります。窓の大きさを変えても、
ブラウザ版が自分で描くキャプションとメニューバーも同じで、**文字のほかは
1 画素も違いません**。

内訳の作り方は次のとおりです。

| | |
|---|---|
| `src/fb.c` | 32bit のフレームバッファ。矩形塗り・3D 枠・4bpp 転送だけ |
| `src/app.c` | 両方の入口が共有する画面。大きさを受け取って描くだけ |
| `src/main_win32.c` | ネイティブの窓。`SetDIBitsToDevice` を 1 回呼ぶだけ |
| `src/main_wasm.c` | ブラウザ側。`putImageData` するだけ |
| `src/jww.c` | `.jww` を読む。`tools/jww.py` がその読みやすい版 |
| `src/view.c` | 用紙のミリを画面の画素へ |
| `src/draw.c` | 線・円弧・点・ソリッド。線種は 32 ビットのパターン |
| `src/text.c` `src/fontx.c` | 文字。字形は東雲フォント（Public Domain、`font/`） |
| `src/ui.c` | 枠を描く。ドックバー・ボタン・レイヤ升目・ステータス行 |
| `src/gen/` | `.rsrc` から焼いたビットマップと、ボタンの配置表（生成物、非コミット） |
| `tests/frame.c` | 窓を開かずに PNG に落とす |
| `tools/cmp.py` | 原典と 1 画素ずつ比べて差分画像を出す |

ネイティブと WASM が**同じ `src/*.c` を通る**ので、両者が食い違ったら
それは移植が環境に依存した印になります。いまのところ**差は 0 画素**です。

ネイティブの窓（`jw_port.exe`）そのものを撮って原典と比べても同じ結果になります。

```sh
sh tools/build_native.sh
powershell -File tools/shot.ps1 -Exe jw_port.exe -Out tests/out/native.png -Client -NoResize
python tools/cmp.py docs/ref_start.png tests/out/native.png -i docs/textareas.txt
```

### 分かったこと

- **ツールバーのボタンの「文字」は絵**です。4bpp のビットマップ帯に焼かれていて、
  アンチエイリアスがありません。だからフォントを合わせなくても一致します。
- 無効なボタンは「地を 1 ドットずらして白、その上に影色」で描かれます。
- 押されたボタンは**窓に位相を合わせた市松**の地に、画像を 1 ドットずらして、
  **地の色を透過**して置きます。
- レイヤ升目は 19x21 のビットマップ（`2652` が左上用、`2662` がそれ以外）。
  ツールバーと違い**灰色は読み替えません**——`0xc0c0c0` だけが地の色になります。
- ボタンの立体枠は `DrawEdge` のどの組み合わせでもありません
  （外が `COLOR_BTNHIGHLIGHT`、内が `COLOR_3DLIGHT`）。自前で描いています。

## 進め方

規模からして一気には終わりません。原典の画面に近い側から順に積みます。

1. ~~**枠。**~~ 済み。文字以外は 1 画素も違いません。
2. ~~**`.jww` を読む。**~~ 済み。同梱 15 枚すべて末尾ぴったり。
3. **描画。** 線・円弧・点・ソリッドは描けています。残りは**文字**と、
   用紙の合わせ方（原典は 1.63125 px/mm、素直に合わせると 1.63333）。
4. **マウスとコマンド。** `CZukei*` を 1 つずつ。クロックメニューも。
5. **WASM。** ネイティブと同じ `src/*.c` を Emscripten で。

## 検証

`tools/shot.ps1` で撮った原典の画面を正解として、同じ図面・同じ窓の大きさで
移植側の画面と 1 画素ずつ比べます。**フォントの字形だけは除外**します
（原典は Windows の MS ゴシックを `CreateFontIndirectW` で取るので、
ブラウザ側と同じにはなりません）。

## 著作権

Jw_cad の著作権は Jiro Shimizu & Yoshifumi Tanaka にあります。
`orig/` と `decomp/` はこのリポジトリに入れていません。手元の
`jww10036.exe` から上の手順で作ってください。
