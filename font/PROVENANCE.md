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
| （一覧に出ない。Arial ほかの代わり） | `jwsubsans.ttf` | Liberation Sans Regular 2.1.5 | SIL OFL 1.1 |
| （一覧に出ない。Times New Roman・Century ほかの代わり） | `jwsubserif.ttf` | Liberation Serif Regular 2.1.5 | SIL OFL 1.1 |
| （一覧に出ない。Courier New の代わり） | `jwsubmono.ttf` | Liberation Mono Regular 2.1.5 | SIL OFL 1.1 |
| （一覧に出ない。Calibri の代わり） | `jwsubcalibri.ttf` | Carlito Regular 1.104 | SIL OFL 1.1 |

| 取得元 | |
|---|---|
| IPAex | https://moji.or.jp/wp-content/ipafont/IPAexfont/IPAexfont00401.zip （`ipaexg.ttf` sha256 `3b9955a5…00dd`、`ipaexm.ttf` `7a306386…71c7`） |
| BIZ UDGothic | https://github.com/googlefonts/morisawa-biz-ud-gothic （`fonts/ttf/BIZUDGothic-Regular.ttf` sha256 `7d2b48d8…92b0`、`OFL.txt`） |
| Liberation 2.1.5 | https://github.com/liberationfonts/liberation-fonts/files/7261482/liberation-fonts-ttf-2.1.5.tar.gz （tar.gz sha256 `7191c669…25d0`、`LiberationSans-Regular.ttf` `76d04c18…8ee8`、`LiberationSerif-Regular.ttf` `058ea808…fb74`、`LiberationMono-Regular.ttf` `f2b83c76…922c1`、`LICENSE`） |
| Carlito 1.104 | https://github.com/googlefonts/carlito （main branch、取得時点の HEAD は commit `3a810cab78ebd6e2e4eed42af9e8453c4f9b850a`「Carlito 1.104」。`fonts/ttf/Carlito-Regular.ttf` sha256 `f6418f70…6595`、`OFL.txt` sha256 `58402f82…9a00`） |
| stb_truetype.h | https://github.com/nothings/stb v1.26、**パブリックドメイン**（無改変で `src/` に置いてあります）。範囲検査をしないので、同梱のフォントにしか使いません |

ライセンス本文: `IPA_Font_License_Agreement_v1.0.txt`・`Readme_IPAexfont00401.txt`
（IPAex）、`OFL-BIZUDGothic.txt`（BIZ UD）。`fonts/` にも同じ本文を置いてあります。
Carlito の本文（`OFL-Carlito.txt`、Liberation と同じ OFL 1.1 の条文）も `fonts/` に
同梱しました（Liberation Mono は既存の `OFL-Liberation.txt` と同じ配布物・同じ本文
なので、Mono 用に別ファイルは要りません）。

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

**Liberation のサブセット。** Liberation Sans・Serif・Mono は Arial・Times New
Roman・Courier New と**送り幅が同じ**（ASCII 95 字で一字も違わないことを Windows の
arial.ttf・times.ttf・cour.ttf と比べて確かめた）。残すのは ASCII（0x20〜0x7e）だけ
で、一つ 9〜12KB ほど（`tools/mksublatin.py`）。Liberation の OFL には予約フォント名
（Red Hat の Liberation、Google の Arimo・Tinos・Cousine）があり、サブセットは改変版
なので**その名前を使えない**。ファイル名もフォント名も `JwSubSans` / `JwSubSerif` /
`JwSubMono` にした。本文は `OFL-Liberation.txt`（`fonts/` にも）。

```sh
python tools/mksublatin.py LiberationSans-Regular.ttf LiberationSerif-Regular.ttf \
    LiberationMono-Regular.ttf Carlito-Regular.ttf fonts
```

**Carlito のサブセット。** Carlito は Calibri と**送り幅が同じ**（同じく ASCII 95 字
を Windows の calibri.ttf と比べて一字も違わないことを確かめた）。OS/2 の平均幅
（xAvgCharWidth）は Carlito 自身が 1048、Calibri 自身は 1067 とわずかに違うが、これは
OS/2 の集計方法の違いで、実際の送り幅（0x20〜0x7e の `hmtx`）は一つも違わない。
また、ascent/descent（stb_truetype が読む `hhea` テーブル）は Carlito が 1950/-550
（2048 中）、Calibri 自身は 1536/-512 と**一致しない**（Carlito 独自の意図的な作り――
LibreOffice などの行送りを Calibri に似せつつ `hhea` の行間だけ広げてある。両者の
OS/2 "typo" アセント・ディセントは 1536/-512 で一致する）。`src/outfont.c` の基線計算
は `hhea` を読むので、Calibri の名で書いた欧文の基線はこの差（2048 分の 38 単位、この
移植が描く大きさでは 2 画素未満）だけ実物からずれる――Tahoma・Verdana・Georgia の節
（下の `tests/font_test.c` 参照）と同種の、直していない既知の小さな差として記録する。
Carlito の OFL には予約フォント名「Carlito」があり、サブセットは改変版なので**その
名前を使えない**。ファイル名もフォント名も `JwSubCalibri` にした（"Calibri" 自体は
OFL の予約名ではなくマイクロソフト自身の書体名で、このファイルには含まれていない
ので、`bizudgothic-sub.ttf` 同様、代わりを指す名前として残した）。本文は
`OFL-Carlito.txt`（`fonts/` にも）。取得元は GitHub の `googlefonts/carlito` リポジトリ
の `main` ブランチで、バージョンタグがないため取得時点の commit ハッシュを上の表に
記録した。

**どの字形で描くか。** `IPAexGothic`・`IPAexMincho`・`BIZ UDGothic` の名前の文字は
それで、**原典の書体名**は ＭＳ ゴシック・ＭＳ Ｐゴシック・名前に「ゴシック」を含む／
不明／空 → IPAex ゴシック、「明朝」を含む → IPAex 明朝（`Ｐ` の付く名前は字ごとの
送り幅＝プロポーショナル）、「BIZ UD」を含む → BIZ UD ゴシック。
Arial・Arial Narrow・Century Gothic・Tahoma・Verdana → JwSubSans、
Times New Roman・Century・Georgia・Bookman Old Style → JwSubSerif、
Courier New → JwSubMono、Calibri → JwSubCalibri（どれも
プロポーショナル。かなと漢字は IPAex ゴシック／明朝。Windows のフォントの関連付けが
欧文の書体の日本語を ＭＳ ゴシック／ＭＳ 明朝 で描くのに倣った。Courier New・Calibri
はどちらも「明朝」系の名前ではないので IPAex ゴシック側）。大きさは原典の
`CreateFontW(-高さ, 幅/2, …)` を Windows がするように、em を高さに、その書体の平均幅
（OS/2 xAvgCharWidth。Arial 904・Times New Roman 821・Century 951・Courier New
1229・Calibri 1067 など、手元の Windows の書体ファイルから読んだ数）を幅の半分に
合わせる。書体名の文字列は図面のまま保存します。

