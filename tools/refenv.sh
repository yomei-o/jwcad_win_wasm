#!/bin/sh
# Put the original back into the state docs/ref_start.png was taken in.
#
#   sh tools/refenv.sh
#
# tools/refenv.reg is the whole HKCU\Software\Jw_cad\jw_win subtree, but
# importing it is not enough on its own: MFC stores the screen size the
# toolbar layout was saved at in ToolBar-Summary\ScreenCX/CY and throws the
# layout away when it no longer matches, falling back to a default that puts
# the bars in different places (32,640 pixels of frame).  This machine's
# screen went from 1916x1081 to 1916x1273 part way through the work and that
# is exactly what happened.  So stamp the current screen size on the saved
# layout and MFC will use it.
set -e
cd "$(dirname "$0")/.."
reg.exe delete 'HKCU\Software\Jw_cad\jw_win' //f >/dev/null 2>&1 || true
reg.exe import tools/refenv.reg
# Retried: under load a PowerShell start-up now and then comes back with
# nothing, and reg.exe refuses an empty /d -- which used to leave the toolbar
# layout unstamped and the next run framed differently.
n=0
while :; do
    cx=$(powershell -NoProfile -Command "Add-Type -AssemblyName System.Windows.Forms; [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Width" | tr -d '\r')
    cy=$(powershell -NoProfile -Command "Add-Type -AssemblyName System.Windows.Forms; [System.Windows.Forms.Screen]::PrimaryScreen.Bounds.Height" | tr -d '\r')
    case "$cx$cy" in
        '' | *[!0-9]*) ;;
        *) break ;;
    esac
    n=$((n + 1))
    if [ $n -gt 5 ]; then
        echo "cannot read the screen size" >&2
        exit 1
    fi
    sleep 1
done
reg.exe add 'HKCU\Software\Jw_cad\jw_win\ToolBar-Summary' //v ScreenCX //t REG_DWORD //d "$cx" //f >/dev/null
reg.exe add 'HKCU\Software\Jw_cad\jw_win\ToolBar-Summary' //v ScreenCY //t REG_DWORD //d "$cy" //f >/dev/null
# 貼付 is drawn enabled when the clipboard has something in it
powershell -NoProfile -Command "Set-Clipboard -Value ''" >/dev/null 2>&1 || true
echo "restored, screen ${cx}x${cy}"
