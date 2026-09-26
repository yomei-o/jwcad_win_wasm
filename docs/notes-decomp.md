# 逆コンパイル出力から読めること

RESUME.md から分けた作業ノートです。節はそのまま、順番も
そのままにしてあります。本文中の「下記」「上記」は元の並びの
ままなので、別のノートを指していることがあります。

* 押さえた番地
* クラス構成
* リソースの型番
* 設定の置き場所

## 押さえた番地

すべて**イメージ内の仮想番地**です（`ImageBase = 0x00400000`）。

| 番地 | 中身 |
|---|---|
| `0x004d8ef4` | エントリポイント |
| `0x00401000` | `.text` の先頭。5,582,629 バイト |
| `0x00954000` | `.rdata`。RTTI の型記述子とロケータはここ |
| `0x009fe000` | `.data` |
| `0x00a15000` | `.rsrc` |
| `0x00954000` | インポートアドレステーブル（`0xae8` バイト） |
| `0x004d2820` | `CJw_winDoc::Serialize`（vtable スロット 2） |
| `0x00575010` | その本体。22,125 バイト。`"JwwData."` を見るのはここ |
| `0x0096b1ec` | `"JwwData."`（`.rdata`、ANSI）。UTF-16 版は `0x00962518` |
| `0x0042e690` | `CData::Serialize` |
| `0x00420650` | `CArchive::operator>>(double&)` らしきもの |
| `0x00420820` | `CArchive::operator<<(double)` らしきもの |
| `0x0042ddc0` | `CArchive::IsStoring()` らしきもの |
| `0x00a08ae4` | 座標の細工の添字（1〜10 で巡回） |
| `0x00a08ae8` | その表 |

## クラス構成

`decomp/rtti/hierarchy.txt` が全 676 クラスの継承です。Jw_cad 自身の骨格：

```
CJw_winApp  : CWinApp
CMainFrame  : CFrameWnd
CJw_winDoc  : CMiniDoc : CDocument
CJw_winView : CView, CGamenJoken          ← 多重継承。CGamenJoken が画面条件
CScreenWnd  : CWnd
CZoom, CLayer, CLType, CStyle, CGamenJoken
CData  : CObject   → Sen / Enko / Moji / Ten / Solid / Sunpou / Block / List
                      と 3D 版 3 つ
CZukei : CObject   → CZukeiObject   … 点・線・円弧・分割・中心線・2 線 …
                   → CZukeiSentaku  … 複写・移動・複線・コーナー・消去 …
```

`decomp/rtti/vftables.csv` に「クラス, vtable の番地, 何番目, 関数の番地」が
41,443 行あります。`decomp/inventory.csv` と番地で突き合わせれば、
どの関数がどのクラスのものかが引けます。

## リソースの型番

MFC が独自に使う 2 つは `afxres.h` にあります。`tools/rsrc.py` は両方解きます。

| | |
|---|---|
| 240 | `RT_DLGINIT` —— コンボボックスの初期項目。`ctrlId, msg, len, データ` の並び |
| 241 | `RT_TOOLBAR` —— `wVersion, wWidth, wHeight, wItemCount` とコマンド ID の配列。0 が区切り |

ツールバーは同じ並びが **16×15 から 120×75 まで 12 段階**入っています。
ボタンの拡大はビットマップを引き伸ばしているのではなく、大きさごとに
別のビットマップを持っているということです。移植でもそのまま使えます。

## 設定の置き場所

`.ini` ではなく**レジストリ** `HKCU\Software\Jw_cad\jw_win` です
（`AutoMode`、`View` などのサブキー）。`View\Direct2d` が描画経路の切り替え。
移植側が同じ絵を出すには、色や線幅の設定もここから読む必要があります。

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

