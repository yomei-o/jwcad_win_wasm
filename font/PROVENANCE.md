# フォントの出どころ

Jw_cad は**フォントを持っていません**。図面が持っている書体名
（同梱のサンプルはどれも「ＭＳ ゴシック」）で `CreateFontIndirectW` して
Windows から借ります。移植側にその書体を配る権利はないので、
**字形は一致しません**——合わせられるのは位置と大きさと色です。

代わりに置いてあるのは **東雲（しののめ）フォント**から作った FONTX2 です。

| | |
|---|---|
| 原典 | [/efont/ 東雲フォントファミリー](http://openlab.ring.gr.jp/efont/shinonome/) |
| 取得元 | https://github.com/code4fukui/shinonome-font （原典のミラー） |
| 作者 | 古川泰之さん（原作）、/efont/（保守） |
| ライセンス | **Public Domain**（`SHINONOME-LICENSE.txt`） |

BDF から FONTX2 への変換は `tools/mkfontx.py`、C への焼き込みは
`tools/mkfont.py` です。

```sh
git clone https://github.com/code4fukui/shinonome-font.git
python tools/mkfontx.py shinonome-font font
python tools/mkfont.py font src/gen
```

| ファイル | |
|---|---|
| `JWANK16.FNT` | 8×16、256 字（JIS X 0201） |
| `JWKAN16.FNT` | 16×16、6,879 字（JIS X 0208。Shift-JIS で索く） |
| `JWANK12.FNT` | 6×12、256 字 |
| `JWKAN12.FNT` | 12×12、6,879 字 |

**16 は図面の文字、12 は枠の文字**に使います。原典は枠をダイアログ
フォント（ＭＳ Ｐゴシック 9pt、字の高さ 12 画素）で描くので、16 画素で
描くとラベルがボタンからはみ出します。

ネイティブとブラウザが**同じバイト列**を持つので、両者の画面は一致します。
姉妹リポジトリ [jwcad_dos_wasm](https://github.com/yomei-o/jwcad_dos_wasm)
と同じファイルです。

## アウトラインフォント（TrueType）

画面・ブラウザの文字は、フォントが読めれば**アウトライン**で描きます
（`src/outfont.c`、ラスタライズは `src/stb_truetype.h`）。読めない間・読めない
ときだけ上の東雲ビットマップが描きます。ファイルは `fonts/` にあり、wasm には
焼き込まず、ブラウザは使う分だけ `fetch()` します。ネイティブは exe の隣の
`fonts/`（なければ `font/`、`../fonts/`、環境変数 `JW_FONTS`）から読みます。

| 画面の名前 | ファイル（`fonts/`） | 元 | ライセンス |
|---|---|---|---|
| IPAexGothic（IPAexゴシック） | `jwsubgothic.ttf` | IPAex ゴシック Ver.004.01 | IPA Font License v1.0 |
| IPAexMincho（IPAex明朝） | `jwsubmincho.ttf` | IPAex 明朝 Ver.004.01 | IPA Font License v1.0 |
| BIZ UDGothic（BIZ UDゴシック） | `bizudgothic-sub.ttf` | BIZ UDGothic Regular 1.051 | SIL OFL 1.1 |

| 取得元 | |
|---|---|
| IPAex | https://moji.or.jp/wp-content/ipafont/IPAexfont/IPAexfont00401.zip （`ipaexg.ttf` sha256 `3b9955a5…00dd`、`ipaexm.ttf` `7a306386…71c7`） |
| BIZ UDGothic | https://github.com/googlefonts/morisawa-biz-ud-gothic （`fonts/ttf/BIZUDGothic-Regular.ttf` sha256 `7d2b48d8…92b0`、`OFL.txt`） |
| stb_truetype.h | https://github.com/nothings/stb v1.26、**パブリックドメイン**（無改変で `src/` に置いてあります）。範囲検査をしないので、同梱のフォントにしか使いません |

ライセンス本文: `IPA_Font_License_Agreement_v1.0.txt`・`Readme_IPAexfont00401.txt`
（IPAex）、`OFL-BIZUDGothic.txt`（BIZ UD）。`fonts/` にも同じ本文を置いてあります。

**サブセットです。** 図面の文字が持てるのは CP932 の字だけなので、CP932 の全文字
（ASCII・半角カナ・JIS X 0208・NEC/IBM 拡張、約 7,500 字）だけを残し、ヒンティングと
レイアウト表を落としました（`tools/mksubfont.py`、要 `pip install fonttools`）。

```sh
python tools/mksubfont.py ipaexg.ttf ipaexm.ttf BIZUDGothic-Regular.ttf fonts
```

IPA Font License 第 3 条 (4) は、派生プログラム（＝サブセット）にもとのフォント名
を使うことを禁じています。そのため IPAex のサブセットは**ファイル名もフォント名も
`JwSubGothic` / `JwSubMincho`** にしてあります（図面に書く書体名 `IPAexGothic` は
ただのラベルです）。第 3 条 (1)(2) の「もとのプログラムに戻す手段」は、上の取得元と
`tools/mksubfont.py` です。派生物もこの契約（本文を同梱）に従います。BIZ UD は
予約フォント名がないのでそのままの名前です。

**どの字形で描くか。** `IPAexGothic`・`IPAexMincho`・`BIZ UDGothic` の名前の文字は
それで、**原典の書体名**は ＭＳ ゴシック・ＭＳ Ｐゴシック・名前に「ゴシック」を含む／
不明／空 → IPAex ゴシック、「明朝」を含む → IPAex 明朝（`Ｐ` の付く名前は字ごとの
送り幅＝プロポーショナル）。書体名の文字列は図面のまま保存します。

