// docs/index.md: every file in docs/ with what it is.   node tools/mkdocsindex.js
const fs = require('fs');
const path = require('path');
const dir = 'docs';
const nl = String.fromCharCode(10);
const files = fs.readdirSync(dir).filter(f => f !== 'index.md').sort();

// what a name says about the file, for the groups of files with no title of their own
const groups = [
  [/^ref_.*\.png$/, '原典の画面（参照画像）', 'ダイアログ・バー・図面を原典で開いて撮った画面。移植の画素比較の正解'],
  [/_textareas.*\.txt$|^textareas.*\.txt$/, '文字の入る矩形', '原典の文字は Windows のフォントで描かれ、移植とは字形が違うので、その矩形を比較から外すための座標'],
  [/^port_.*\.png$/, '移植側の画面', 'READMEなどに載せる移植の画面'],
];
function title(f) {
  const t = fs.readFileSync(path.join(dir, f), 'utf8').split(nl).find(l => /^#\s/.test(l));
  return t ? t.replace(/^#\s+/, '') : null;
}
const rows = [];
const grouped = new Map();
for (const f of files) {
  let g = groups.find(x => x[0].test(f));
  if (g) {
    if (!grouped.has(g[1])) grouped.set(g[1], { desc: g[2], list: [] });
    grouped.get(g[1]).list.push(f);
    continue;
  }
  const t = f.endsWith('.md') ? title(f) : null;
  rows.push([f, t]);
}
let o = '# docs/ の案内' + nl + nl
  + '`tools/mkdocsindex.js` が作ります。ここに無い文書: 上の階層の `README.md`（概要と使い方）・`RESUME.md`（やったことの記録）・'
  + '`nokori.md`（これからやること）・`tmp/features_report.md`（機能・安定性の作業記録）。' + nl + nl
  + '## 文書' + nl + nl + '| ファイル | 中身 |' + nl + '|---|---|' + nl;
const known = {
  'notes-commands.md': '命令ごとの調べ（原典の動き・移植の対応）',
  'notes-decomp.md': '逆コンパイルの読み方と 関数・クラスの対応',
  'notes-formats.md': 'ファイル形式（.jww・DXF・SFC・JWC・座標ファイル）の調べと 読み手の寛容さ',
  'notes-history.md': '調べの経緯',
  'notes-machine.md': '原典を動かす機械まわり（駆動・撮影・環境）',
  'notes-pixels.md': '画素を原典に合わせた記録',
  'notes-tests.md': 'テストの網の説明',
  'format-jww.md': '.jww の形式',
  'command-coverage.md': '原典のメニュー項目ぜんぶと 移植の対応（tools/mkcoverage.sh が作る）',
  'dogfood-house.md': '二階建ての間取りを作ってみた記録（引っかかりの一覧）',
  'cleanup.md': '整理で 消したもの・消さなかったもの',
};
for (const [f, t] of rows) o += '| [' + f + '](' + f + ') | ' + (known[f] || t || '') + ' |' + nl;
o += nl + '## 参照の材料' + nl + nl;
for (const [name, g] of grouped) {
  o += '* **' + name + '** (' + g.list.length + ' 件): ' + g.desc + '。' + nl + '  ' + g.list.map(f => '`' + f + '`').join('、') + nl;
}
fs.writeFileSync(path.join(dir, 'index.md'), o);
console.log('docs/index.md: ' + rows.length + ' documents, ' + [...grouped.values()].reduce((a, g) => a + g.list.length, 0) + ' reference files');
