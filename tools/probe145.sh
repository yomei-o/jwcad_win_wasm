#!/bin/sh
# 測定 は画面に何か描くのか。
#
#   sh tools/probe145.sh
#
# 読み出しは合わせましたが、**測っている間に画面へ何か出るか**は見て
# いません。移植は何も描きません。原典はどうか、撮って較べます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |wrote" | sed 's/^/    /'
}
S='raw:f,273,32897,0;wait:800;'

run base "${S}wait:500;shot:tmp/p145_base.png"
run len  "${S}300,300;700,300;700,500;wait:500;shot:tmp/p145_len.png"
run area "${S}pb:1065;wait:400;300,300;700,300;700,500;300,500;wait:500;shot:tmp/p145_area.png"
idle
echo
for f in len area; do
    printf '%-6s ' $f
    python tools/cmp.py tmp/p145_base.png "tmp/p145_$f.png" 2>&1 | sed -n 1p
done
