# 整理の記録（2026-10-14）

「どこからも 参照されていない」ことを `grep` で確かめて 消したもの、確かめた上で 残したもの。
参照とは: `tools/`・`src/`・`tests/`・`docs/`・`README.md`・`RESUME.md`・`nokori.md` のどこかに その名前
（拡張子を除いたものも）が出てくること。`tmp/`・`decomp/`・`orig/`・`dist/` は数えていない。

## 消した（`tools/`）

どれも 他のスクリプト・文書・テストから 名前が出てこず、置き換わった版か 一度きりの作業用だったもの。
git の履歴に残っています。

| ファイル | 何だったか |
|---|---|
| `analyze_gdi_box.bat`, `decomp_gdi_box.bat` | GDI の箱の逆コンパイル作業用（結果は `src/draw.c` と `docs/notes-pixels.md`） |
| `calibrate2.exe` | 実行ファイルだけ（原典の画面の目盛り合わせ。ソースは無い） |
| `blkdump.c`, `blkdump2.c`, `mesh.c` | 一度きりのダンプ・格子の確認用 C |
| `cp932lit.py`, `cpsolve.py`, `fixline.py`, `newobjs.py`, `unesc.py`, `scorecanvas.py`, `barlist.py` | 一度きりの変換・採点の Python |
| `imgres.sh`, `escprobe2.sh`, `keysweep2.sh`, `autotest.sh`, `sun2probe.sh`, `skshow.sh` | 同名の最初の版（`escprobe.sh`・`keysweep.sh` など）に 置き換わった駆動用 |

## 確かめて 残した

* `tools/probe*.sh`・`skbatch*.sh`・`hkbatch*.sh`・`arc*.py`: 名前に 番号が付いた**組**として
  `RESUME.md`・`docs/` が「`tools/probeNN.sh`」「`skbatch*`」のように 指していて、原典の答え
  （`decomp/res`）を どう取ったかの出どころになっている。番号ごとの参照が無くても 組で参照されている。
* `src/cmd.c` の `pv_round`（使われていない static）と `jw_cmd_hikage_preview` の `s`（代入だけ）: 日影図の
  確認窓を いま書いている人の領域なので 触っていない。コンパイラは「未使用」と言っている。
* `tests/hk_test.c` のリンクエラー（`png_rgb` が未定義）: 同じく 他の作業の途中。`tools/ci.sh` の
  tests の段が 落ちるのはこのため（私の削除とは無関係: 削除の前後で 同じ）。

## 方針

* 消すのは 参照が 本当に 無いものだけ。迷ったら 残して ここに 書く。
* ソースの未使用は コンパイラ（`-Wall -Wextra`、`tools/build_native.sh`）が 言うものだけを 数えた。
