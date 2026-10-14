# The native print path, without a dialog: jw_port.exe prints a drawing to "Microsoft Print to PDF"
# (JW_PRINTER names the printer, JW_PRINT_FILE the file it writes), then the PDF is looked at:
#   powershell -ExecutionPolicy Bypass -File tools\print_native.ps1
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$exe = Join-Path $root 'jw_port.exe'
$tmp = Join-Path ([IO.Path]::GetTempPath()) ('jwprint' + [Guid]::NewGuid().ToString('N').Substring(0, 8))
New-Item -ItemType Directory -Force $tmp | Out-Null
$fails = 0
function Check($ok, $what) { if ($ok) { Write-Host "ok   $what" } else { Write-Host "BAD  $what"; $script:fails++ } }
Add-Type 'using System; using System.Runtime.InteropServices; public class W3 { [DllImport("user32.dll")] public static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l); }'
$printer = 'Microsoft Print to PDF'
if (-not (Get-Printer -Name $printer -ErrorAction SilentlyContinue)) { Write-Host "skipped: no '$printer' on this machine"; exit 0 }
$lat = [Text.Encoding]::GetEncoding(28591)
$num = '(-?[0-9.]+)'
$sp = '\s+'

# a drawing, the sheet it is on, and what the PDF should say about it
foreach ($case in @(@{ file = 'orig\Test1.jww'; cmd = 0 }, @{ file = 'orig\Test1.jww'; cmd = 32824 })) {   # as it is, then A-4
  $out = Join-Path $tmp ('out' + $case.cmd + '.pdf')
  $psi = New-Object Diagnostics.ProcessStartInfo
  $psi.FileName = $exe
  $psi.Arguments = '"' + (Join-Path $root $case.file) + '"'
  $psi.UseShellExecute = $false
  $psi.EnvironmentVariables['APPDATA'] = Join-Path $tmp 'ap'
  $psi.EnvironmentVariables['JW_PRINTER'] = $printer
  $psi.EnvironmentVariables['JW_PRINT_FILE'] = $out
  $p = [Diagnostics.Process]::Start($psi)
  for ($i = 0; $i -lt 50 -and $p.MainWindowHandle -eq 0; $i++) { Start-Sleep -Milliseconds 200; $p.Refresh() }
  Start-Sleep -Milliseconds 800
  if ($case.cmd) { [W3]::PostMessage($p.MainWindowHandle, 0x111, [IntPtr]$case.cmd, [IntPtr]::Zero) | Out-Null; Start-Sleep -Milliseconds 500 }
  [W3]::PostMessage($p.MainWindowHandle, 0x111, [IntPtr]57607, [IntPtr]::Zero) | Out-Null    # Print (Ctrl+P)
  for ($i = 0; $i -lt 60 -and -not (Test-Path $out); $i++) { Start-Sleep -Milliseconds 500 }
  Start-Sleep -Seconds 2
  $p.Kill()
  $name = if ($case.cmd) { 'A-4 sheet' } else { 'the sheet as it is (A-2)' }
  Check (Test-Path $out) "$name : the printer wrote a file"
  if (-not (Test-Path $out)) { continue }
  $b = [IO.File]::ReadAllBytes($out)
  $txt = $lat.GetString($b)
  Check ($txt.StartsWith('%PDF-')) "$name : it is a PDF ($($b.Length) bytes)"
  # the page content (Flate): "<k> 0 0 -<k> 0 <page height> cm", then the picture "<w> 0 0 -<h> <x> <y> cm /Image1 Do"
  $content = $null
  foreach ($m in [regex]::Matches($txt, '(?s)stream\r?\n')) {
    $start = $m.Index + $m.Length
    $end = $txt.IndexOf('endstream', $start)
    if ($end -lt 0 -or $end - $start -lt 20) { continue }
    try {
      $ms = New-Object IO.MemoryStream(, $b[($start + 2)..($end - 1)])
      $ds = New-Object IO.Compression.DeflateStream($ms, [IO.Compression.CompressionMode]::Decompress)
      $o = New-Object IO.MemoryStream
      $ds.CopyTo($o)
      $s2 = $lat.GetString($o.ToArray())
      if ($s2 -match ' Do') { $content = $s2; break }
    } catch { }
  }
  Check ($null -ne $content) "$name : the page content has a picture"
  if ($null -eq $content) { continue }
  $k = [regex]::Match($content, '^\s*' + $num + $sp + '0[0-9.]*' + $sp + '0[0-9.]*' + $sp + '-' + $num + $sp + '0[0-9.]*' + $sp + $num + $sp + 'cm')
  $im = [regex]::Match($content, $num + $sp + '0[0-9.]*' + $sp + '0[0-9.]*' + $sp + '-' + $num + $sp + $num + $sp + $num + $sp + 'cm\s+/\w+\s+Do')
  Check ($k.Success -and $im.Success) "$name : the page content is the one expected"
  if (-not ($k.Success -and $im.Success)) { continue }
  $scale = [double]$k.Groups[1].Value
  $pageH = [double]$k.Groups[3].Value
  $dw = [double]$im.Groups[1].Value * $scale
  $dh = [double]$im.Groups[2].Value * $scale
  $dx = [double]$im.Groups[3].Value * $scale
  Check ([Math]::Abs($pageH - 841.9) -lt 3) "$name : the page is A4 portrait (height $pageH pt)"
  Check ($dh -gt $dw) "$name : the sheet is turned a quarter to fit the portrait page ($([Math]::Round($dw)) x $([Math]::Round($dh)) pt)"
  $want = if ($case.cmd) { 297 / 210 } else { 594 / 420 }
  Check ([Math]::Abs($dh / $dw - $want) -lt 0.02) ("$name : its proportions are the sheet's (" + [Math]::Round($dh / $dw, 3) + ' for ' + [Math]::Round($want, 3) + ')')
  Check ($dw -le 596 -and $dh -le 842 -and $dh -ge 0.95 * 842) "$name : it fills the page and does not run off it"
  Check ([Math]::Abs($dx) -lt 3) "$name : and sits at the left edge of the printable area (x $dx)"
}
Remove-Item -Recurse -Force $tmp -ErrorAction SilentlyContinue
if ($fails) { Write-Host 'FAILED'; exit 1 } else { Write-Host 'all ok' }
