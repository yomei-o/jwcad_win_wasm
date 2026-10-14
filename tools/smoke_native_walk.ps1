# Random walk over jw_port.exe with window messages, on every orig/*.jww:
#   powershell -ExecutionPolicy Bypass -File tools\smoke_native_walk.ps1 [-Steps 20] [-Seed 1] [-Files Test1,Test5]
# For each drawing: start the program on a copy, send -Steps random actions (a toolbar command by
# its WM_COMMAND id, a click, a right click, a mouse move, Esc / Enter / a digit), answer any dialog
# box that comes up with Cancel, check the process still answers, save (WM_COMMAND 57603), close it
# (answering "No" to the unsaved-changes box) and check that it exits.  A crash, a hang or a window
# that stops answering is a BAD, and the actions that led to it are printed so it can be replayed
# (same -Seed).
param([int]$Steps = 20, [int]$Seed = 1, [string[]]$Files = @(), [int]$Rounds = 1)
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$exe = Join-Path $root 'jw_port.exe'
if (-not (Test-Path $exe)) { Write-Host 'BAD  jw_port.exe is not built (sh tools/build_native.sh)'; exit 1 }
$tmp = Join-Path ([IO.Path]::GetTempPath()) ('jwwalk' + [Guid]::NewGuid().ToString('N').Substring(0, 8))
New-Item -ItemType Directory -Force $tmp | Out-Null
$app = Join-Path $tmp 'appdata'
New-Item -ItemType Directory -Force $app | Out-Null
$fails = 0
function Check($ok, $what) { if ($ok) { Write-Host "ok   $what" } else { Write-Host "BAD  $what"; $script:fails++ } }

Add-Type @'
using System;
using System.Text;
using System.Runtime.InteropServices;
public class WK {
  public delegate bool EnumProc(IntPtr h, IntPtr l);
  [DllImport("user32.dll")] public static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
  [DllImport("user32.dll")] public static extern bool EnumWindows(EnumProc p, IntPtr l);
  [DllImport("user32.dll")] public static extern int GetClassName(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  [DllImport("user32.dll")] public static extern bool IsWindowVisible(IntPtr h);
  [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RECT r);
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int l, t, r, b; }
  public static IntPtr Pt(int x, int y) { return (IntPtr)((y << 16) | (x & 0xffff)); }
  public static IntPtr Dialog(uint pid) {
    IntPtr found = IntPtr.Zero;
    EnumWindows((h, l) => {
      uint p; GetWindowThreadProcessId(h, out p);
      if (p != pid || !IsWindowVisible(h)) return true;
      StringBuilder sb = new StringBuilder(64); GetClassName(h, sb, 64);
      if (sb.ToString() == "#32770") { found = h; return false; }
      return true;
    }, IntPtr.Zero);
    return found;
  }
}
'@

# the commands: every toolbar button's id, out of the table the port is compiled with
$cmds = @()
foreach ($m in [regex]::Matches((Get-Content -Raw (Join-Path $root 'src\gen\cmds.h')), '\b(\d{5})\b')) { $cmds += [int]$m.Groups[1].Value }
$cmds = @($cmds | Sort-Object -Unique | Where-Object { $_ -ge 32768 -and $_ -lt 40000 })
# not these: they leave the program (a batch file, a printer, the editor) rather than test it
$skip = @(32913, 32954)
$cmds = @($cmds | Where-Object { $skip -notcontains $_ })

function Close-Dialogs($p) {
  $n = 0
  for ($i = 0; $i -lt 6; $i++) {
    $d = [WK]::Dialog([uint32]$p.Id)
    if ($d -eq 0) { break }
    [WK]::PostMessage($d, 0x111, [IntPtr]2, [IntPtr]::Zero) | Out-Null     # IDCANCEL
    [WK]::PostMessage($d, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null  # and WM_CLOSE
    Start-Sleep -Milliseconds 150
    $n++
  }
  return $n
}

$all = Get-ChildItem (Join-Path $root 'orig') -Filter *.jww | Sort-Object Name
if ($Files.Count) { $all = @($all | Where-Object { $Files -contains $_.BaseName }) }
$total = 0
for ($round = 0; $round -lt $Rounds; $round++) {
  foreach ($f in $all) {
    $rnd = New-Object System.Random ($Seed * 1000 + $round * 97 + ($total % 50))
    $total++
    $work = Join-Path $tmp ('w' + $total + '.jww')
    Copy-Item $f.FullName $work
    $psi = New-Object Diagnostics.ProcessStartInfo
    $psi.FileName = $exe
    $psi.Arguments = '"' + $work + '"'
    $psi.UseShellExecute = $false
    $psi.EnvironmentVariables['APPDATA'] = $app
    $psi.EnvironmentVariables['JW_UISCALE'] = '1'
    $p = [Diagnostics.Process]::Start($psi)
    for ($i = 0; $i -lt 50 -and $p.MainWindowHandle -eq 0; $i++) { Start-Sleep -Milliseconds 200; $p.Refresh() }
    $h = $p.MainWindowHandle
    if ($h -eq 0) { Check $false ($f.Name + ': the window does not come up'); try { $p.Kill() } catch {}; continue }
    Start-Sleep -Milliseconds 500
    $c = New-Object WK+RECT
    [WK]::GetClientRect($h, [ref]$c) | Out-Null
    $W = [Math]::Max(200, $c.r); $H = [Math]::Max(200, $c.b)
    $log = @()
    $ok = $true
    for ($s = 0; $s -lt $Steps -and $ok; $s++) {
      $r = $rnd.Next(100)
      $x = $rnd.Next(0, $W); $y = $rnd.Next(60, $H)
      if ($r -lt 35) {
        $id = $cmds[$rnd.Next($cmds.Count)]
        $log += "cmd $id"
        [WK]::PostMessage($h, 0x111, [IntPtr]$id, [IntPtr]::Zero) | Out-Null
      } elseif ($r -lt 70) {
        $log += "click $x,$y"
        [WK]::PostMessage($h, 0x200, [IntPtr]::Zero, [WK]::Pt($x, $y)) | Out-Null
        [WK]::PostMessage($h, 0x201, [IntPtr]1, [WK]::Pt($x, $y)) | Out-Null
        [WK]::PostMessage($h, 0x202, [IntPtr]::Zero, [WK]::Pt($x, $y)) | Out-Null
      } elseif ($r -lt 80) {
        $log += "rclick $x,$y"
        [WK]::PostMessage($h, 0x204, [IntPtr]2, [WK]::Pt($x, $y)) | Out-Null
        [WK]::PostMessage($h, 0x205, [IntPtr]::Zero, [WK]::Pt($x, $y)) | Out-Null
      } elseif ($r -lt 90) {
        $log += "move $x,$y"
        [WK]::PostMessage($h, 0x200, [IntPtr]::Zero, [WK]::Pt($x, $y)) | Out-Null
      } else {
        $k = @(0x1B, 0x0D, 0x31, 0x2E, 0x08)[$rnd.Next(5)]
        $log += "key $k"
        [WK]::PostMessage($h, 0x100, [IntPtr]$k, [IntPtr]::Zero) | Out-Null
        [WK]::PostMessage($h, 0x101, [IntPtr]$k, [IntPtr]::Zero) | Out-Null
      }
      Start-Sleep -Milliseconds 60
      Close-Dialogs $p | Out-Null
      if ($p.HasExited) { $ok = $false; Check $false ($f.Name + ': the program exited after: ' + ($log[-3..-1] -join '; ')) }
      elseif ($s % 5 -eq 4) {
        $p.Refresh()
        if (-not $p.Responding) {
          Start-Sleep -Milliseconds 1500; Close-Dialogs $p | Out-Null; $p.Refresh()
          if (-not $p.Responding) { $ok = $false; Check $false ($f.Name + ': the window stopped answering after: ' + ($log -join '; ')) }
        }
      }
    }
    if ($ok) {
      # save in place, then close, saying No to the unsaved-changes box if it comes
      $p.Refresh(); $h = $p.MainWindowHandle
      [WK]::PostMessage($h, 0x111, [IntPtr]57603, [IntPtr]::Zero) | Out-Null
      Start-Sleep -Milliseconds 500
      Close-Dialogs $p | Out-Null
      [WK]::PostMessage($h, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null
      for ($i = 0; $i -lt 25 -and -not $p.HasExited; $i++) {
        Start-Sleep -Milliseconds 200
        $d = [WK]::Dialog([uint32]$p.Id)
        if ($d -ne 0) { [WK]::PostMessage($d, 0x111, [IntPtr]7, [IntPtr]::Zero) | Out-Null }
      }
      if (-not $p.HasExited) { Check $false ($f.Name + ': it does not close; actions: ' + ($log -join '; ')) }
      else { Check $true ($f.Name + ': ' + $Steps + ' random actions, saved, closed') }
    }
    if (-not $p.HasExited) { try { $p.Kill() } catch {} }
  }
}
Remove-Item -Recurse -Force $tmp -ErrorAction SilentlyContinue
if ($fails) { Write-Host "FAILED $fails"; exit 1 } else { Write-Host 'all ok' }
