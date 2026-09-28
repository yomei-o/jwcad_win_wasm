# Windows GDI の逆コンパイル（円弧まわりだけ）

移植の残り画素は**ほぼ全部が部分円弧**で、GDI がどう画素を置いているかが
分からないところで止まっていました（[`../../docs/notes-pixels.md`](../../docs/notes-pixels.md)）。
ここはその答えを **GDI 自身から** 取ったものです。

## どこから来たものか

`C:\Windows\System32\win32kfull.sys`（ARM64、この機械の Windows 11 の
もの）と、**Microsoft が公開している** そのシンボル `win32kfull.pdb` です。
PDB の在処は PE の CodeView レコードから作れます:

```sh
python tools/pdbid.py C:/Windows/System32/win32kfull.sys
# win32kfull.pdb
#   https://msdl.microsoft.com/download/symbols/win32kfull.pdb/<GUID><Age>/win32kfull.pdb
```

Ghidra の PDB Universal 解析器は、PDB を binary と同じ場所に置いておけば
自分で見つけます。**名前つき関数 8,440 個**が付くので、Jw_win.exe のときの
ような無名関数の海にはなりません。

```sh
sh tools/gdi_decomp.sh          # 一式（転送・解析・逆コンパイル・持ち帰り）
```

## 中身

* `arc.c` —— `Arc`/`Chord`/`Pie` から画素までの道筋にある関数だけ。
  名前で選んでいます（`ArcInternal`・`PartialArc`・`BEZIER`・`bFlatten`・
  `DDA_CLIPLINE`・`Arctan`）

**これは Microsoft の著作物から機械的に起こしたものです。**読むために
置いてあり、移植に写してはいません —— 移植の答えは今までどおり
「原典に描かせた画素」で確かめます。
