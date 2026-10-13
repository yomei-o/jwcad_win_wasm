#!/bin/sh
# 天空図 (32971) のオプションの答え（2026-10-13）。tools/hkprobe.sh で
# decomp/res/hk_<名前>.jww を作る。下地・高さ・測定点・中心は hk_s1 と同じ。
# 太陽軌跡 (1325) は真北が無いと「真北が設定されていません。」が出るので OK を押す
# （真北を 日影図 の 1068 で上向きに置いたときと同じ絵になった、hk_t5n）。
#   sh tools/tnbatch.sh [名前...]
cd "$(dirname "$0")/.."
PRE='400,300;600,300;600,300;600,500;600,500;400,500;400,500;400,300;'
H='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,500;wait:300;405,500;wait:300;'
run() {
    [ -n "$ONLY" ] && ! echo " $ONLY " | grep -q " $1 " && return
    echo "== $1"
    sh tools/hkprobe.sh "$1" 32971 "$PRE" "$H$2"
}
ONLY="$*"
run s1x  'pb:1064;wait:500;500,600;wait:500;900,300;wait:1500;'
run s2   'pb:1064;wait:500;500,600;wait:500;pb:1323;wait:300;900,300;wait:2500;'
run s3   'pb:1064;wait:500;500,600;wait:500;pb:1323;wait:300;pb:1327;wait:300;900,300;wait:6000;'
run s4   'pb:1064;wait:500;500,600;wait:500;pb:1323;wait:300;pb:1324;wait:300;900,300;wait:2500;'
run s5   'pb:1064;wait:500;500,600;wait:500;pb:1325;wait:300;900,300;wait:1500;dlgnow:x;wait:2500;'
run s6   'pb:1064;wait:500;500,600;wait:500;pb:1325;wait:300;pb:1326;wait:300;900,300;wait:1500;dlgnow:x;wait:2500;'
run s7   'pb:1064;wait:500;500,600;wait:500;pb:1325;wait:300;pb:2113;wait:300;900,300;wait:1500;dlgnow:x;wait:2500;'
run s8   'pb:1064;wait:500;500,600;wait:500;pb:1325;wait:300;pb:2115;wait:300;900,300;wait:1500;dlgnow:x;wait:2500;'
run s9   'pb:1064;wait:500;ch:2216,3;wait:300;500,600;wait:500;900,300;wait:1500;'
run s10  'pb:1065;wait:500;500,600;wait:500;900,300;wait:1500;'
run s11  'pb:1064;wait:500;ch:1493,40;wait:300;ch:1492,1.5;wait:300;500,600;wait:500;900,300;wait:1500;'
