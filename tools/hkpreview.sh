#!/bin/sh
# 日影図 (32943) の 確認 (1067) の窓の画面を原典から撮る（2026-10-14）→ decomp/res/hk_pv1〜pv6.png
#   pv1: 初め（−45・30）  pv2: 左 2・下 3  pv3: ０，０  pv4: 等角  pv5: 建物二つ  pv6: 建物二つ + 左 1・下 1
# 原典を独占するので ほかの駆動と同時に走らせない。
cd "$(dirname "$0")/.."
PRE='400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;'
H='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,500;wait:300;405,500;wait:300;'
PRE2='400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;650,380;750,380;750,380;750,450;750,450;650,450;650,450;650,380;'
H2="${H}ch:1491,6;wait:300;655,380;wait:300;745,380;wait:300;745,450;wait:300;655,450;wait:300;"
run() {
    sh tools/refenv.sh >/dev/null
    cp decomp/res/new.jww tmp/rect.jww
    powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1 -Open tmp/rect.jww -NoSave -Clicks "off:1333;$1cmd:32943;wait:1500;$2" 2>&1 | grep -E "throw|no "
}
run "$PRE" "${H}pb:1067;wait:2000;shot:decomp/res/hk_pv1.png;pb:1123;wait:500;pb:1123;wait:500;pb:1126;wait:500;pb:1126;wait:500;pb:1126;wait:500;shot:decomp/res/hk_pv2.png;pb:1084;wait:800;shot:decomp/res/hk_pv3.png;pb:1129;wait:800;shot:decomp/res/hk_pv4.png;"
run "$PRE2" "${H2}pb:1067;wait:2000;shot:decomp/res/hk_pv5.png;pb:1123;wait:500;pb:1126;wait:500;shot:decomp/res/hk_pv6.png;"
