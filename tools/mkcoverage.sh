#!/bin/sh
# docs/command-coverage.md: every item of the original's menus (decomp/res/menu.txt)
# and what the port does with it.  The status comes from sending each id to the
# port (tests/menusweep_test.c for the main menu, tests/cmdcover_test.c for the
# rest); the reasons for the ones that do not change the drawing are written
# down in the awk below.
cd "$(dirname "$0")/.."
sh tools/qtest.sh menusweep cmdcover >/dev/null 2>&1
./tmp/q_menusweep.exe --list 2>&1 | grep -a -E "^ +[0-9]+ (took|dead)" | awk '{print $1, $2}' > tmp/cov_status.txt
grep -a -o 'MENUITEM ".*", [0-9]*' decomp/res/menu.txt | sed 's/.*, //' | sort -u > tmp/cov_ids.txt
awk 'NR==FNR { s[$1] = 1; next } !($1 in s) { print $1 }' tmp/cov_status.txt tmp/cov_ids.txt | tr '\n' ' ' > tmp/cov_try.txt
./tmp/q_cmdcover.exe $(cat tmp/cov_try.txt) > tmp/cov_other.txt 2>/dev/null
awk -v status=tmp/cov_status.txt -v other=tmp/cov_other.txt '
function note(id) {
  if (id in R) return R[id]
  if ((id >= 20001 && id <= 20007)) return "寸法の右クリックメニュー: 寸法のバーの釦（半径・直径・円周・角度・設定・累進）が同じ働き"
  if (id == 32781 || id == 32782) return "読取りのポップアップ: 取得コマンドと右ボタンの (R)Read が同じ働き"
  if (id >= 32838 && id <= 32841) return "範囲選択のバーの釦（基準点変更・前範囲・全選択・選択解除）が同じ働き"
  if (id == 32836) return "画面倍率ダイアログ（32844）と 拡大縮小で代替"
  if (id == 32916 || id == 32917) return "レイヤ（グループ）升目の操作と ダイアログで代替"
  if (id >= 32989 && id <= 32994) return "ブロック一覧（ツリー）の右クリック。ブロックのコマンドで代替"
  if (id == 32991 || id == 32992 || id == 32993) return "MFC の内部（ツリー表示）。移植に無い"
  if (id == 59394 || id == 59395 || id == 59396 || id == 59397 || (id >= 32954 && id <= 32959 && id != 32954) || id == 32845 || id == 32861 || (id >= 32999 && id <= 33004) || id == 32854 || id == 32856 || id == 32951 || id == 32972) return "ツールバー・バーの表示切替。移植の枠は固定（原典の既定の並び）"
  if (id == 134 || id == 32832 || id == 32833 || id == 32850 || id == 32852 || id == 32855 || id == 32857 || id == 32858 || id == 32949 || id == 32950 || id == 32973 || id == 32974 || id == 32996 || id == 33010 || id == 33011 || id == 33038 || id == 33039) return "原典の内部の更新・デバッグ用で メニューには出ない。移植に無い"
  if (id == 32965) return "ソリッド: コマンドとして移植済み（バーの釦）"
  return "移植の表に無い"
}
BEGIN {
  while ((getline l < status) > 0) { split(l, a, " "); S[a[1]] = a[2] }
  while ((getline l < other) > 0) { split(l, a, " "); O[a[1]] = a[2] }
  F[57600]="新規 (ブラウザは 変更があれば確認)"
  F[57601]="ファイル選択 (File System Access API / input)"
  F[57603]="上書き保存 (ブラウザはダウンロードか 開いたファイルへ書き戻し)"
  F[57604]="名前を付けて保存"
  F[57607]="印刷 (ブラウザは PDF / PNG のボタンと Ctrl+P)"
  F[57606]="移植に無い (Windows のプリンタ設定)"
  F[57612]="移植に無い (送信)"
  F[32809]="JWC を開く"; F[32810]="JWC で保存"
  F[32960]="DXF を開く"; F[32961]="DXF で保存"
  F[32975]="SFC を開く"; F[32976]="SFC で保存"
  F[32862]="図形読込のファイル窓"; F[32946]="図形登録の名前"; F[32869]="ファイル窓"
  F[32848]="ファイル窓"; F[32865]="ファイル窓"; F[32866]="ファイル窓"
  F[32977]="移植に無い (ファイル一括変換)"; F[32979]="移植に無い (ファイル名変更)"
  F[32980]="移植に無い (ファイル削除)"; F[32982]="移植に無い (ファイル比較)"
  F[32984]="移植に無い (ファイル属性変更)"; F[32987]="移植に無い (図面情報コピー)"
  F[57664]="移植に無い (バージョン情報)"; F[57665]="窓を閉じる"; F[57667]="移植に無い (ヘルプ)"
  F[57616]="Win32: 最近のファイルがここに入る (無ければ灰色)。ブラウザ: 「最近のファイル」の選択欄"
  R[32967]="文字を選んでいなければ灰色（app_menu_state）。選ぶとフロントエンドが対象のファイルを開く"
  R[57644]="やり直すものが無ければ灰色"
  R[57643]="戻すものが無ければ灰色"
  R[57635]="範囲を選んでから。無ければ何も起きない（原典も同じ、probe56）"
  R[57634]="範囲を選んでから。無ければ何も起きない（原典も同じ、probe56）"
  R[32853]="範囲を選んでから（掃引では範囲が無い）"
  R[32909]="ブロックを選んでから"; R[32970]="ブロックを選んでから"
  R[32986]="ブロックを選んでから"; R[32985]="ブロック編集中だけ"
  R[32923]="フロントエンドの仕事: .jwf を読む"
  R[32924]="フロントエンドの仕事: .jwf を書く"
  R[32954]="Win32: メモ帳で .jwf を開く。ブラウザでは灰色"
  R[33032]="灰色（SPEED Data は移植に無い）"
  R[32835]="全体再表示: 図面全体を表示（app_fit）"
  print "# 原典のメニュー項目と移植の対応"
  print ""
  print "`decomp/res/menu.txt` の MENUITEM を全部。`tools/mkcoverage.sh` が作ります。"
  print "**動く** = 送ると 命令が替わる・ダイアログが出る・図面が変わる・アクションが立つ。"
  print "**反応なし** = そのままでは何も変わらない（理由を右に）。**フロントエンド** = ファイル窓・印刷など、"
  print "`src/main_win32.c` と `index.html` の仕事。**別の形** = 原典の右クリックメニューや 内部用の項目で、"
  print "移植は同じ働きをバーの釦などで持つか、持たない。"
  print ""
  print "| id | 項目 | 状態 | 理由・備考 |"
  print "|---:|---|---|---|"
}
/MENUITEM "/ {
  line = $0
  n = line; sub(/^[ ]*MENUITEM "/, "", n); sub(/".*/, "", n)
  gsub(/&/, "", n); sub(/\t.*/, "", n)
  i = line; sub(/.*", /, "", i); sub(/ .*/, "", i)
  id = i + 0
  if (id in F) { st = "フロントエンド"; why = F[id] }
  else if (id in S) { st = (S[id] == "took") ? "動く" : "反応なし"; why = (id in R) ? R[id] : "" }
  else if (O[id] == "took") { st = "動く"; why = (id in R) ? R[id] : "" }
  else if (id >= 57345 && id <= 57359) { st = "フロントエンド"; why = "最近のファイルの欄" }
  else { st = "別の形"; why = note(id) }
  if (id in seen) next
  seen[id] = 1
  printf "| %d | %s | %s | %s |\n", id, n, st, why
}' decomp/res/menu.txt > docs/command-coverage.md
awk -F'|' 'NR>7 { gsub(/ /, "", $4); c[$4]++ } END { for (k in c) print k, c[k] }' docs/command-coverage.md
