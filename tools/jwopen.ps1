# Let the original open a drawing, optionally send it a menu command, and
# close it again.  No screen grab: the window is shown without taking focus,
# so it can run while someone is working.
#
#   powershell -File tools/jwopen.ps1 -Open tmp/mod.jww -Cmd 57603
param(
    [string]$Exe = 'orig\Jw_win.exe',
    [string]$Open = '',
    [int]$Cmd = 0,
    [int]$WaitMs = 8000
)
$ErrorActionPreference = 'Stop'
Add-Type -TypeDefinition @'
using System;
using System.Runtime.InteropServices;
public static class Jw {
    [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h, int cmd);
    [DllImport("user32.dll")] public static extern IntPtr SendMessage(
        IntPtr h, uint msg, IntPtr w, IntPtr l);
}
'@
$p = Start-Process -FilePath (Resolve-Path $Exe).Path `
    -ArgumentList (Resolve-Path $Open).Path -PassThru
try {
    $deadline = (Get-Date).AddSeconds(30)
    while (-not $p.MainWindowHandle -or $p.MainWindowHandle -eq [IntPtr]::Zero) {
        if ((Get-Date) -gt $deadline) { throw 'no main window after 30 s' }
        Start-Sleep -Milliseconds 200
        $p.Refresh()
    }
    [void][Jw]::ShowWindow($p.MainWindowHandle, 4)   # SW_SHOWNOACTIVATE
    Start-Sleep -Milliseconds 2500
    if ($Cmd -ne 0) {
        [void][Jw]::SendMessage($p.MainWindowHandle, 0x0111, [IntPtr]$Cmd, [IntPtr]::Zero)
        Start-Sleep -Milliseconds $WaitMs
    }
    Write-Host ("opened {0}{1}" -f $Open, $(if ($Cmd) { ", sent $Cmd" } else { '' }))
} finally {
    if (-not $p.HasExited) {
        $p.CloseMainWindow() | Out-Null
        Start-Sleep -Milliseconds 1500
        if (-not $p.HasExited) { $p.Kill() }
    }
}
