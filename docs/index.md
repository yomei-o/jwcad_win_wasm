# docs/ の案内

`tools/mkdocsindex.js` が作ります。ここに無い文書: 上の階層の `README.md`（概要と使い方）・`RESUME.md`（やったことの記録）・`nokori.md`（これからやること）・`tmp/features_report.md`（機能・安定性の作業記録）。

## 文書

| ファイル | 中身 |
|---|---|
| [cleanup.md](cleanup.md) | 整理で 消したもの・消さなかったもの |
| [command-coverage.md](command-coverage.md) | 原典のメニュー項目ぜんぶと 移植の対応（tools/mkcoverage.sh が作る） |
| [dogfood-house.md](dogfood-house.md) | 二階建ての間取りを作ってみた記録（引っかかりの一覧） |
| [format-jww.md](format-jww.md) | .jww の形式 |
| [notes-commands.md](notes-commands.md) | 命令ごとの調べ（原典の動き・移植の対応） |
| [notes-decomp.md](notes-decomp.md) | 逆コンパイルの読み方と 関数・クラスの対応 |
| [notes-formats.md](notes-formats.md) | ファイル形式（.jww・DXF・SFC・JWC・座標ファイル）の調べと 読み手の寛容さ |
| [notes-history.md](notes-history.md) | 調べの経緯 |
| [notes-machine.md](notes-machine.md) | 原典を動かす機械まわり（駆動・撮影・環境） |
| [notes-pixels.md](notes-pixels.md) | 画素を原典に合わせた記録 |
| [notes-tests.md](notes-tests.md) | テストの網の説明 |
| [todo-stubs.md](todo-stubs.md) | 「ここでは まだ」と書いた所の仕分け（古い・原典が要る・大きい） |

## 参照の材料

* **文字の入る矩形** (23 件): 原典の文字は Windows のフォントで描かれ、移植とは字形が違うので、その矩形を比較から外すための座標。
  `bairitsu_textareas.txt`、`blkedit_textareas.txt`、`blkname_textareas.txt`、`chrome_textareas.txt`、`colordlg_textareas.txt`、`jikkaku_textareas.txt`、`kihon_textareas.txt`、`kihon_textareas2.txt`、`kihon_textareas3.txt`、`kihon_textareas4.txt`、`kihon_textareas5.txt`、`kihon_textareas6.txt`、`kihon_textareas7.txt`、`kihon_textareas8.txt`、`layerdlg_textareas.txt`、`moji_textareas.txt`、`mojikijun_textareas.txt`、`shakudo_textareas.txt`、`sunpodlg_textareas.txt`、`textareas.txt`、`zoku_textareas.txt`、`zokuhen_textareas.txt`、`zokusel_textareas.txt`
* **移植側の画面** (1 件): READMEなどに載せる移植の画面。
  `port_test1.png`
* **原典の画面（参照画像）** (36 件): ダイアログ・バー・図面を原典で開いて撮った画面。移植の画素比較の正解。
  `ref_bairitsu.png`、`ref_blkedit.png`、`ref_blkname.png`、`ref_blktree.png`、`ref_blktree_found.png`、`ref_colordlg.png`、`ref_jikkaku.png`、`ref_kihon1.png`、`ref_kihon2.png`、`ref_kihon3.png`、`ref_kihon4.png`、`ref_kihon5.png`、`ref_kihon6.png`、`ref_kihon7.png`、`ref_kihon8.png`、`ref_layerdlg.png`、`ref_layerdlg_emptygroup.png`、`ref_layerdlg_emptywrite.png`、`ref_layerdlg_hidden.png`、`ref_layerdlg_shown.png`、`ref_layerlist.png`、`ref_moji.png`、`ref_mojikijun.png`、`ref_shakudo.png`、`ref_sokutei_area.png`、`ref_sokutei_len.png`、`ref_start.png`、`ref_start_big.png`、`ref_sunpodlg.png`、`ref_test1.png`、`ref_test7.png`、`ref_window.png`、`ref_youshi.png`、`ref_zoku.png`、`ref_zokuhen.png`、`ref_zokusel.png`
