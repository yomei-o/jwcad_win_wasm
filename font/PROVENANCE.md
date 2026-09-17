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
