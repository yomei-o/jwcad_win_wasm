# ネイティブ版の印刷の窓（src/prnative.h）を出して閉じるだけの試し。何も刷らない:
#   powershell -ExecutionPolicy Bypass -File tools\print_dialogs.ps1
# (1) 印刷 (57607) で入る前に印刷の窓が出て、閉じれば（キャンセル）命令に入らない。
#     Windows 11 の PrintDlgW は別のプロセス（PrintDialog.exe）の新しい印刷の窓に
#     なることがあるので、自分の #32770 か、主窓を持ち主にした窓が増えたかで見る
# (2) JW_PRINTER を付けて（窓なしで入る）、バーの 出力方法設定 (1069) で
#     プリント出力形式、プリンタの設定 (1067) でプリンタの設定の窓が出る
# バーの釦の位置は decomp/res/bars8.txt（1069 は x 648 幅 86、1067 は x 475 幅 88、y 5 高さ 24）。
# JW_UISCALE=1 で画面の拡大率に関わらず 1 倍で描かせる。
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$exe = Join-Path $root 'jw_port.exe'
if (-not (Test-Path $exe)) { Write-Host "skipped: no jw_port.exe (sh tools/build_native.sh)"; exit 0 }
$fails = 0
function Check($ok, $what) { if ($ok) { Write-Host "ok   $what" } else { Write-Host "BAD  $what"; $script:fails++ } }
Add-Type @'
using System; using System.Text; using System.Runtime.InteropServices; using System.Collections.Generic;
public class PW {
  public delegate bool EnumProc(IntPtr h, IntPtr l);
  [DllImport("user32.dll")] public static extern bool EnumWindows(EnumProc f, IntPtr l);
  [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  [DllImport("user32.dll")] public static extern bool IsWindowVisible(IntPtr h);
  [DllImport("user32.dll")] public static extern IntPtr GetWindow(IntPtr h, uint c);
  [DllImport("user32.dll", CharSet = CharSet.Unicode)] public static extern int GetClassName(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll", CharSet = CharSet.Unicode)] public static extern int GetWindowText(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll")] public static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
  public static string Cls(IntPtr h) { var c = new StringBuilder(64); GetClassName(h, c, 64); return c.ToString(); }
  public static string Text(IntPtr h) { var s = new StringBuilder(256); GetWindowText(h, s, 256); return s.ToString(); }
  public static List<IntPtr> Top() {
    var r = new List<IntPtr>();
    EnumWindows((h, l) => { if (IsWindowVisible(h)) r.Add(h); return true; }, IntPtr.Zero);
    return r;
  }
  public static uint Pid(IntPtr h) { uint p; GetWindowThreadProcessId(h, out p); return p; }
}
'@
function Start-Port($printer) {
  $psi = New-Object Diagnostics.ProcessStartInfo
  $psi.FileName = $exe
  $psi.Arguments = '"' + (Join-Path $root 'orig\Test1.jww') + '"'
  $psi.UseShellExecute = $false
  $psi.EnvironmentVariables['JW_UISCALE'] = '1'      # 釦の位置を画素どおりに
  $psi.EnvironmentVariables['APPDATA'] = Join-Path $tmp 'ap'
  if ($printer) { $psi.EnvironmentVariables['JW_PRINTER'] = $printer } else { $psi.EnvironmentVariables.Remove('JW_PRINTER') }
  $q = [Diagnostics.Process]::Start($psi)
  for ($i = 0; $i -lt 50 -and $q.MainWindowHandle -eq 0; $i++) { Start-Sleep -Milliseconds 200; $q.Refresh() }
  Start-Sleep -Milliseconds 800
  return $q
}
# 主窓から見て増えた窓: 自分の #32770、または主窓が持ち主の窓（別のプロセスの印刷の窓の代理）、
# またはそのとき増えた ApplicationFrameWindow（新しい印刷の窓そのもの）
function New-Dialogs($q, $before) {
  $w = $q.MainWindowHandle
  [PW]::Top() | Where-Object {
    ($before -notcontains $_) -and (
      (([PW]::Pid($_) -eq $q.Id) -and ([PW]::Cls($_) -eq '#32770')) -or
      ([PW]::GetWindow($_, 4) -eq $w) -or ([PW]::Cls($_) -eq 'ApplicationFrameWindow'))
  }
}
function Wait-Dialogs($q, $before) { for ($i = 0; $i -lt 40; $i++) { $d = @(New-Dialogs $q $before); if ($d.Count) { Start-Sleep -Milliseconds 400; return @(New-Dialogs $q $before) }; Start-Sleep -Milliseconds 250 }; return @() }
function Close-Dialogs($ds) { foreach ($d in ($ds | Where-Object { $_ })) { if ([PW]::Cls($d) -eq '#32770') { [PW]::PostMessage($d, 0x111, [IntPtr]2, [IntPtr]::Zero) | Out-Null } elseif ([PW]::Cls($d) -eq 'ApplicationFrameWindow') { [PW]::PostMessage($d, 0x10, [IntPtr]0, [IntPtr]::Zero) | Out-Null } } }
function Wait-Gone($q, $before) { for ($i = 0; $i -lt 40; $i++) { if (-not @(New-Dialogs $q $before).Count) { return $true }; Start-Sleep -Milliseconds 250 }; return $false }
function Click($q, $x, $y) { $w = $q.MainWindowHandle; $l = [IntPtr](($y -shl 16) -bor $x); [PW]::PostMessage($w, 0x200, [IntPtr]0, $l) | Out-Null; [PW]::PostMessage($w, 0x201, [IntPtr]1, $l) | Out-Null; [PW]::PostMessage($w, 0x202, [IntPtr]0, $l) | Out-Null }
function Names($ds) { ($ds | Where-Object { $_ } | ForEach-Object { [PW]::Cls($_) + ':' + [PW]::Text($_) }) -join ', ' }

$tmp = Join-Path ([IO.Path]::GetTempPath()) ('jwprdlg' + [Guid]::NewGuid().ToString('N').Substring(0, 8))
New-Item -ItemType Directory -Force $tmp | Out-Null
$p = $null
try {
  # (1) 窓あり
  $p = Start-Port $null
  $before = [PW]::Top()
  [PW]::PostMessage($p.MainWindowHandle, 0x111, [IntPtr]57607, [IntPtr]::Zero) | Out-Null
  $d = Wait-Dialogs $p $before
  Check ($d.Count -gt 0) ('印刷 で入る前に印刷の窓が出る (' + (Names $d) + ')')
  Close-Dialogs $d
  Check (Wait-Gone $p $before) '  閉じる（キャンセル）'
  Start-Sleep -Milliseconds 500
  Click $p 690 17
  $d = Wait-Dialogs $p $before
  Check ($d.Count -eq 0) ('キャンセルなら印刷の命令に入らない（1069 の所を押しても窓は出ない） ' + (Names $d))
  Close-Dialogs $d
  $p.Kill(); $p = $null
  # (2) JW_PRINTER: 窓なしで入って、バーの二つ
  $p = Start-Port 'Microsoft Print to PDF'
  $before = [PW]::Top()
  [PW]::PostMessage($p.MainWindowHandle, 0x111, [IntPtr]57607, [IntPtr]::Zero) | Out-Null
  Start-Sleep -Milliseconds 800
  Check (@(New-Dialogs $p $before).Count -eq 0) 'JW_PRINTER なら窓なしで印刷の命令に'
  Click $p 690 17
  $d = Wait-Dialogs $p $before
  Check ($d.Count -gt 0 -and [PW]::Text($d[0]) -eq 'プリント出力形式') ('出力方法設定 (1069) で プリント出力形式 (' + (Names $d) + ')')
  Close-Dialogs $d
  Check (Wait-Gone $p $before) '  ｷｬﾝｾﾙ で閉じる'
  Click $p 518 17
  $d = Wait-Dialogs $p $before
  Check ($d.Count -gt 0) ('プリンタの設定 (1067) でプリンタの設定の窓 (' + (Names $d) + ')')
  Close-Dialogs $d
  Check (Wait-Gone $p $before) '  キャンセルで閉じる'
} finally {
  if ($p -and -not $p.HasExited) { $p.Kill() }
  Remove-Item -Recurse -Force $tmp -ErrorAction SilentlyContinue
}
if ($fails) { Write-Host 'FAILED'; exit 1 } else { Write-Host 'all ok' }
