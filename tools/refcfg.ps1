# Put Jw_cad into the configuration the port is measured against.
#
#   powershell -ExecutionPolicy Bypass -File tools/refcfg.ps1        # set
#   powershell -ExecutionPolicy Bypass -File tools/refcfg.ps1 -Show  # just look
#
# Jw_cad keeps everything in HKCU\Software\Jw_cad\jw_win, not in an .ini.
# The one setting that matters for pixel comparison is Direct2D: with it on,
# lines are antialiased by the GPU and text goes through DirectWrite, neither
# of which a browser canvas can be made to match.  With it off Jw_cad draws
# through GDI -- integer rasterisation, no antialiasing -- which is
# reproducible exactly.  It is [設定]→[基本設定]→[一般(1)] in the UI.
param([switch]$Show)
$key = 'HKCU:\Software\Jw_cad\jw_win\View'
if (-not (Test-Path $key)) {
    Write-Host "$key does not exist yet -- run Jw_cad once first."
    exit 1
}
$cur = (Get-ItemProperty $key).Direct2d
if ($Show) {
    Write-Host ("Direct2d = {0}" -f $cur)
    exit 0
}
Set-ItemProperty $key -Name Direct2d -Value 0 -Type DWord
Write-Host ("Direct2d {0} -> 0 (GDI)" -f $cur)
