# 図面ファイル `.jww` の形

MFC の `CArchive` によるシリアライズです。`CJw_winDoc::Serialize`
（`0x004d2820` → 本体 `0x00575010`）を読み写しました。**同梱の図面 15 枚
すべてが末尾ぴったりで読めます。**

```sh
sh tools/jwwcheck.sh      # 15 枚とも「+0」で終われば形が合っている
python tools/jww.py orig/Test1.jww
```

```
version 600
16 groups -> 0x979  (scales 100 1 1 1)
names -> 0xb49
pens and line types -> 0x3752
hatch and dimensions -> 0x38ce
1686 objects at 0x38d0
  CDataSen 1642, CDataEnko 4, CDataMoji 36, CDataTen 4
file is 0x1851a bytes; stopped at 0x1851a (+0)
```

#### 全体の形

| | |
|---|---|
| `"JwwData."` | 8 バイト |
| 版 | `long`。同梱のものは **600**。読み手は版ごとに項目を足し引きします |
| 図面名 | 文字列（版 > 0x40） |
| レイヤ | `long` 2 本 ＋ **グループ 16 個**。1 個につき `long, long, double(縮尺), long` と**レイヤ 16 枚**の `long, long` |
| 設定 | `long` 21 本、`double` 数本 |
| 名前 | **レイヤ名 16×16 ＋ グループ名 16**。MFC の長さ前置文字列 |
| 用紙・ペン | `double` の並び。用紙寸法 4900/600/2000… が見えます |
| 色と線種 | **色 257 個**（`名前, long, long, double`）と**線種 33 個**（`名前, long, double×10`）。名前は `black` `red` … `continuous` `dashed` … と英語 |
| ハッチ・寸法 | `FUN_004eee80` が読む 380 バイト |
| 要素 | `CObList::Serialize` —— 個数（`WORD`）のあと `CArchive` のタグ付きオブジェクト |
| ブロック | もう 1 本の `CObList`（版 > 0x13） |

#### 要素

`CArchive` のタグは **クラスとオブジェクトを 1 つの番号列**で数えます。
`0xffff` が「初出のクラス」（スキーマと名前が続く）、`0x8000` 付きが
既出のクラスの番号、それ以外はすでに読んだオブジェクトへの参照です。

```
ff ff  58 02  08 00  "CDataSen"   初出。スキーマ 600
80 01                              2 個目以降は「1 番のクラス」
```

`CData::Serialize` が共通の 15 バイトを読みます（版 600）。

| | |
|---|---|
| `long` | `+0x04` |
| `byte` | `+0x28` 線色。100 以上は別の意味（点の種類、ソリッドの形） |
| `word` | `+0x2a` 線種 |
| `word` | `+0x2c` 線幅（版 > 0x15e） |
| `word` `word` | `+0x2e` `+0x2f` |
| `word` | `+0x44` |

そのあとがクラスごとの中身です。

| クラス | 中身 |
|---|---|
| `CDataSen` 線 | `double` 4（x0,y0,x1,y1） |
| `CDataEnko` 円弧 | `double` 7 ＋ `long` |
| `CDataTen` 点 | `double` 2 ＋ `long`。線色が 100 なら `long` ＋ `double` 2 |
| `CDataMoji` 文字 | `double` 4 ＋ `long` ＋ `double` 4 ＋ **書体名** ＋ **本文** |
| `CDataSolid` | `double` 8（4 点）。線種が 10 なら `long`（任意色の RGB） |

**`CJw_winDoc::Serialize` から直接は見えない読み手が 1 つあります。**
`FUN_004eee80` が要素の直前に 380 バイト読みます。ここを忘れると、
オブジェクトの個数のつもりで別の数を読んで、そこから全部ずれます。

