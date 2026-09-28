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

必要なものは**2 つのモジュールに分かれています**。弧を Bézier にする
ところは `win32kfull.sys`、**平坦化と路は `win32kbase.sys`**（前者からは
`__imp_` で呼ぶだけなので、`win32kfull` を見ても中身はありません）。

```sh
# 片方ずつ。ビルド機（20 コア）で解析 1 分、逆コンパイルは数秒
scp win32kfull.sys win32kfull.pdb <box>:C:/prog/win32k/bin/
ssh <box> 'C:\prog\win32knalyze_gdi_box.bat win32kfull.sys proj'
ssh <box> 'C:\prog\win32k\decomp_gdi_box.bat win32kfull.sys proj arc.c ArcInternal PartialArc Arctan'
```

## 中身

| | |
|---|---|
| [`HANDOVER.md`](HANDOVER.md) | **まずこれ。**何が問題で、何が確定で、何を否定したか、次の一手 |
| `arc.c` | `win32kfull.sys` から 7 関数 —— `NtGdiArcInternal`・`bPartialArc`・`vArctan` ほか |
| `flatten.c` | `win32kbase.sys` から 9 関数 —— **`BEZIER32::bInit`/`bNext`・`BEZIER64`**・`EPATHOBJ::bFlatten` ほか |

`DecompileNamed.java` は**完全修飾名**で照合します（`BEZIER32::bNext` の
`getName()` は `bNext` だけなので、クラス名で探すならこれが要ります）。

**これは Microsoft の著作物から機械的に起こしたものです。**読むために
置いてあり、移植に写してはいません —— 移植の答えは今までどおり
「原典に描かせた画素」で確かめます。
