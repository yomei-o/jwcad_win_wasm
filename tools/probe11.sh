#!/bin/sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 60 ] && break; sleep 1; done; }
shot() {
    idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 | grep -E "throw|no " | sed 's/^/    /'
}
# the dialog with the layers hidden, and with them 表示のみ
shot lay_hidden 'dlgin:32808,1141=!;dlg:32808,docs/ref_layerdlg_hidden.png'
shot lay_shown  'dlgin:32808,1141=!,1141=!;dlg:32808,docs/ref_layerdlg_shown.png'
idle
