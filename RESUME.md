# 引き継ぎ

## いまどこまで

**実行ファイルの構造を解いたところまで。** 移植のコードはまだ 1 行もありません。

| | |
|---|---|
| 済 | インストーラの展開（Inno Setup 6.4.2、`/VERYSILENT /DIR=`） |
| 済 | PE の構成、インポート 22 DLL / 676 関数（`tools/peinfo.py`） |
| 済 | リソース全部 —— メニュー 3・ダイアログ 108・文字列 1,598・ツールバー 183・ビットマップ 469（`tools/rsrc.py`） |
| 済 | RTTI からクラス 714・vtable 676・継承関係（`tools/rtti.py`） |
| 済 | Ghidra 自動解析（ビルドマシンで 342 秒）、関数 26,061 の棚卸し |
| 済 | 原典の基準画像（`tools/shot.ps1`、`docs/ref_*.png`） |
| 済 | 逆コンパイル 25,983 関数 / 99.8% 成功 / 26 MB。クラスごとに仕分け済み |
| 済 | `CJw_winDoc::Serialize` と `CData*::Serialize` 8 本の位置 |
| 次 | `.jww` の形を閉じる、枠の再現、描画 |

## 次にやること

1. **`.jww` の形を閉じる。** 出発点は `decomp/byclass/CJw_winDoc.c` の
   `FUN_004d2820`（スロット 2 ＝ `Serialize`）と、その先の
   `FUN_00575010`（22,125 バイト、本体）。要素は `CData*` の
   スロット 2 を順に読めば出ます（README の表）。
   **座標の細工に注意**——書き出しで 10 個の表の値を足し、読みで引きます。
   添字 `DAT_00a08ae4` は要素ごとに 1 つ進んで 10 で巡回するので、
   飛ばし読みすると座標がずれます。同梱の 14 枚が全部読めて
   末尾がぴったり合えば閉じたと判断できます（DOS 版と同じやり方）。
2. **枠を画素まで合わせる。** メニュー・ツールバー・レイヤバー・ステータスバーは
   リソースにそのまま入っているので、逆コンパイルを待たずに組めます。
   `docs/ref_start.png`（1280×800、図面なし）が正解です。
3. **描画経路をどちらに合わせるか決める。** 10.x は既定で Direct2D です。
   移植の正解は **Direct2D を切った GDI 経路**にするのが筋
   （[設定]→[基本設定]→[一般(1)]）。決定的で、アンチエイリアスを
   真似しなくて済みます。決めたらこの行を消してください。
4. **`CZukei*` を 1 つずつ。** 55 クラスあります。メニューと 1 対 1 なので
   どれから手を付けても独立しています。

## 刺された罠

**PowerShell の変数名は大文字小文字を区別しない。** `param([long]$Lo)` の下で
`$lo = $Lo + $i * $step` と書くと**同じ変数**です。分割して逆コンパイルする
`tools/decomp_box.ps1` で、2 番目以降のシャードが「開始 > 終了」になって
黙って 0 関数を出しました。ログは正常、`DONE` も出るので気づきにくいです。
いまは `$rlo` / `$rhi` にしてあります。

**`PrintWindow` では図面が撮れない。** 枠とメニューは返ってきますが、
Direct2D のスワップチェーンは見えないので**作図領域が真っ白**になります。
`tools/shot.ps1 -Screen` はデスクトップから画素を読みます。

**`analyzeHeadless` は先にプロジェクトの親ディレクトリが無いと落ちる。**
`Directory not found: C:\prog\jwwin\proj` で止まります。しかも
`launch.bat` がそこで「続行するには何かキーを押してください」を出すので、
ssh 越しだと固まったように見えます。

**Ghidra の `DIALOGEX` 判定。** `DLGTEMPLATEEX` は先頭が
`WORD dlgVer=1; WORD signature=0xffff` です。`signature` だけ見て
`dlgVer` を 1 つ後ろから読むと、ダイアログ 108 枚のうち
`DIALOGEX` のものが全部ずれて `struct.error` になります（一度やりました）。

**Ghidra は `-readOnly` でもプロジェクトを排他ロックする。** 同じ
プロジェクトに 10 個の headless を向けると、最初の 1 つだけが動いて残りは
`Unable to lock project!` で死にます。**それでも実行は `DONE` を出す**ので、
出力が 1 つしか無いことに気づくまで成功に見えます。`tools/decomp_box.ps1` は
プロジェクト（146 MB）をシャードごとに複製します。

**Git Bash から Windows のパスを渡すとバックスラッシュが消える。**
`-Exe orig\Jw_win.exe` が `origJw_win.exe` になります。スラッシュを使うこと。
日本語のファイル名は ssh / PowerShell の間で CP932 に落ちて壊れるので、
`orig/Test1.jww` のような ASCII 名で試すこと。

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
