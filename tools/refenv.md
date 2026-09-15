# 基準環境

原典の画面と比べる以上、**原典の設定が変わると比較の意味がなくなります**。
`tools/refenv.reg` は `docs/ref_*.png` を撮ったときの
`HKCU\Software\Jw_cad\jw_win` を丸ごと書き出したものです。

```sh
powershell -Command "Remove-Item 'HKCU:\Software\Jw_cad' -Recurse -Force"
powershell -Command "reg import 'tools\refenv.reg'"
```

これを入れると `docs/ref_start.png` と**差分 0 画素**になります。

## なぜ要るか

一度、撮り方を変えようとして窓を 900×600 に縮めて戻したら、Jw_cad が
**ツールバーの配置を保存してしまい**、以後どう撮っても枠が 48,656 画素
違うようになりました。`orig/Bars.reg`（インストーラ同梱）は
`ToolBar-Summary\Bars` を書くだけで配置は戻せず、`ToolBar-*` を消して
作り直させると 1 列になってしまいます。
このファイルは、そのとき偶然手元にあったレジストリのダンプから
起こしたものです。

## 中身のうち比較に効くもの

| | |
|---|---|
| `View\Direct2d` | **0**（GDI 経路）。`tools/refcfg.ps1` が設定します |
| `ToolBar-Bar0`〜`Bar31` | ツールバーの配置。1 つ違うと枠が全部ずれます |
| `LayerBar` `LayerGroupBar` `SenCollBar` `SenCollBar2` | 右側のバー |
| `Color` | 線色 1〜9 と「表示のみ」の灰色 |
| `Line` | 線種のパターン（`Type_01`〜`09`）とその単位 |
