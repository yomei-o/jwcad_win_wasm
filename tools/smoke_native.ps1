# Smoke test of jw_port.exe, driven with window messages:
#   powershell -ExecutionPolicy Bypass -File tools\smoke_native.ps1
# starts it on a copy of a drawing, draws, lets the autosave happen, saves (a .bak appears),
# asks to close (the unsaved-changes box is answered), drops a file on it, kills it
# mid-edit and checks that the next start offers the recovery.
$ErrorActionPreference = 'Stop'
$root = Split-Path -Parent $PSScriptRoot
$exe = Join-Path $root 'jw_port.exe'
# every path below has Japanese in it (and a space and an ampersand): the folder, the drawing, APPDATA
$jpDir = -join ([char]0x56F3, [char]0x9762, [char]0x30D5, [char]0x30A9, [char]0x30EB, [char]0x30C0, ' & ', [char]0x65E5, [char]0x672C)
$jpName = (-join ([char]0x5E73, [char]0x9762, [char]0x56F3)) + '.jww'
$tmp = Join-Path ([IO.Path]::GetTempPath()) ('jwsmoke' + [Guid]::NewGuid().ToString('N').Substring(0, 8) + ' ' + $jpDir)
New-Item -ItemType Directory -Force $tmp | Out-Null
$app = Join-Path $tmp 'appdata'
New-Item -ItemType Directory -Force $app | Out-Null
$work = Join-Path $tmp $jpName
Copy-Item (Join-Path $root 'orig\Test1.jww') $work
$fails = 0
function Check($ok, $what) { if ($ok) { Write-Host "ok   $what" } else { Write-Host "BAD  $what"; $script:fails++ } }

Add-Type @'
using System;
using System.Text;
using System.Runtime.InteropServices;
public class W {
  public delegate bool EnumProc(IntPtr h, IntPtr l);
  [DllImport("user32.dll")] public static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
  [DllImport("user32.dll")] public static extern IntPtr SendMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
  [DllImport("user32.dll")] public static extern bool EnumWindows(EnumProc p, IntPtr l);
  [DllImport("user32.dll")] public static extern bool EnumThreadWindows(uint t, EnumProc p, IntPtr l);
  [DllImport("user32.dll")] public static extern int GetClassName(IntPtr h, StringBuilder s, int n);
  [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
  [DllImport("user32.dll")] public static extern bool IsWindowVisible(IntPtr h);
  [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
  [DllImport("user32.dll")] public static extern bool MoveWindow(IntPtr h, int x, int y, int w, int hh, bool repaint);
  [DllImport("kernel32.dll")] public static extern IntPtr GlobalAlloc(uint f, UIntPtr n);
  [DllImport("kernel32.dll")] public static extern IntPtr GlobalLock(IntPtr h);
  [DllImport("kernel32.dll")] public static extern bool GlobalUnlock(IntPtr h);
  [StructLayout(LayoutKind.Sequential)] public struct RECT { public int l, t, r, b; }
  public static IntPtr Pt(int x, int y) { return (IntPtr)((y << 16) | (x & 0xffff)); }
  // a dialog box (#32770) that belongs to the process
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
  // WM_DROPFILES with one wide path
  public static IntPtr DropOf(string path) {
    byte[] name = Encoding.Unicode.GetBytes(path + "\0\0");
    IntPtr g = GlobalAlloc(0x42, (UIntPtr)(20 + name.Length));
    IntPtr p = GlobalLock(g);
    Marshal.WriteInt32(p, 0, 20);              // pFiles
    Marshal.WriteInt32(p, 16, 1);              // fWide
    Marshal.Copy(name, 0, (IntPtr)(p.ToInt64() + 20), name.Length);
    GlobalUnlock(g);
    return g;
  }
}
'@

function Start-Jw($file, $env2) {
  $psi = New-Object Diagnostics.ProcessStartInfo
  $psi.FileName = $exe
  if ($file) { $psi.Arguments = '"' + $file + '"' }
  $psi.UseShellExecute = $false
  $psi.EnvironmentVariables['APPDATA'] = $app
  $psi.EnvironmentVariables['JW_AUTOSAVE_SEC'] = '2'
  $psi.EnvironmentVariables['JW_UISCALE'] = '1'
  foreach ($k in $env2.Keys) { $psi.EnvironmentVariables[$k] = $env2[$k] }
  $p = [Diagnostics.Process]::Start($psi)
  for ($i = 0; $i -lt 50 -and $p.MainWindowHandle -eq 0; $i++) { Start-Sleep -Milliseconds 200; $p.Refresh() }
  return $p
}
function Click($h, $x, $y) {
  [W]::PostMessage($h, 0x200, [IntPtr]::Zero, [W]::Pt($x, $y)) | Out-Null
  [W]::PostMessage($h, 0x201, [IntPtr]1, [W]::Pt($x, $y)) | Out-Null
  [W]::PostMessage($h, 0x202, [IntPtr]::Zero, [W]::Pt($x, $y)) | Out-Null
  Start-Sleep -Milliseconds 150
}
$auto = Join-Path $app 'jw_port\autosave.jww'

# --- start on a drawing, draw two lines
$p = Start-Jw $work @{}
Check ($p.MainWindowHandle -ne 0) 'the window comes up'
$h = $p.MainWindowHandle
Start-Sleep -Milliseconds 800
Check ($p.MainWindowTitle.StartsWith((-join ([char]0x5E73, [char]0x9762, [char]0x56F3)) + '.jww')) ("the title names the drawing: " + $p.MainWindowTitle)
$sz0 = (Get-Item $work).Length
Click $h 400 300; Click $h 700 420
Click $h 400 450; Click $h 800 500
# --- the autosave appears
$seen = $false
for ($i = 0; $i -lt 20 -and -not $seen; $i++) { Start-Sleep -Milliseconds 500; $seen = Test-Path $auto }
Check $seen 'an autosave copy appears while the drawing is changed'

[W]::PostMessage($h, 0x111, [IntPtr]57603, [IntPtr]::Zero) | Out-Null
Start-Sleep -Milliseconds 1200
Check ((Get-Item $work).Length -gt $sz0) ("the drawing is saved in place ($sz0 -> " + (Get-Item $work).Length + ' bytes)')
Check (Test-Path ($work + '.bak')) 'the previous file is kept as .bak'
Check ((Get-Item ($work + '.bak')).Length -eq $sz0) 'and the .bak is the old one'
Start-Sleep -Milliseconds 2500
Check (-not (Test-Path $auto)) 'a saved drawing leaves no autosave'
# --- a drop: a second drawing opened by dropping it
$drop = Join-Path $tmp ((-join ([char]0x30C9, [char]0x30ED, [char]0x30C3, [char]0x30D7)) + ' Test3.jww')
Copy-Item (Join-Path $root 'orig\Test3.jww') $drop
[W]::PostMessage($h, 0x233, [W]::DropOf($drop), [IntPtr]::Zero) | Out-Null
Start-Sleep -Milliseconds 1200
$p.Refresh()
Check ($p.MainWindowTitle -match 'Test3') ("a dropped .jww opens: " + $p.MainWindowTitle)
# --- changed, then asked to close: the box comes up, Cancel keeps the window, No lets it go
Click $h 400 300; Click $h 700 420
[W]::PostMessage($h, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null     # WM_CLOSE
$dlg = [IntPtr]::Zero
for ($i = 0; $i -lt 20 -and $dlg -eq 0; $i++) { Start-Sleep -Milliseconds 200; $dlg = [W]::Dialog([uint32]$p.Id) }
Check ($dlg -ne 0) 'closing a changed drawing asks first'
[W]::PostMessage($dlg, 0x111, [IntPtr]2, [IntPtr]::Zero) | Out-Null       # IDCANCEL
Start-Sleep -Milliseconds 600
Check (-not $p.HasExited) 'Cancel keeps the window'
[W]::PostMessage($h, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null
$dlg = [IntPtr]::Zero
for ($i = 0; $i -lt 20 -and $dlg -eq 0; $i++) { Start-Sleep -Milliseconds 200; $dlg = [W]::Dialog([uint32]$p.Id) }
[W]::PostMessage($dlg, 0x111, [IntPtr]7, [IntPtr]::Zero) | Out-Null       # IDNO
$p.WaitForExit(5000) | Out-Null
Check $p.HasExited 'No closes it'
$ini = [IO.Path]::Combine($app, 'jw_port', 'jw_port.ini')
$iniText = if (Test-Path $ini) { Get-Content -Raw -Encoding Unicode $ini } else { '' }
Check ($iniText.Contains($jpName)) 'the recent-file list keeps the Japanese name (a Unicode ini)'
Check (-not (Test-Path $auto)) 'a clean close leaves no autosave'

# --- a crash: draw, wait for the autosave, kill the process
$p = Start-Jw $work @{}
$h = $p.MainWindowHandle
Start-Sleep -Milliseconds 800
Click $h 300 300; Click $h 600 380
$seen = $false
for ($i = 0; $i -lt 20 -and -not $seen; $i++) { Start-Sleep -Milliseconds 500; $seen = Test-Path $auto }
Check $seen 'again an autosave appears'
$p.Kill(); $p.WaitForExit()
Check (Test-Path $auto) 'it survives a killed process'
# --- the next start: says yes by environment (JW_RECOVER=yes), and the drawing is back as changed
$p = Start-Jw $null @{ JW_RECOVER = 'yes' }
$h = $p.MainWindowHandle
Start-Sleep -Milliseconds 1000
$p.Refresh()
Check ($p.MainWindowTitle.StartsWith((-join ([char]0x5E73, [char]0x9762, [char]0x56F3)))) ("the recovered drawing has its name back: " + $p.MainWindowTitle)
[W]::PostMessage($h, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null
$dlg = [IntPtr]::Zero
for ($i = 0; $i -lt 20 -and $dlg -eq 0; $i++) { Start-Sleep -Milliseconds 200; $dlg = [W]::Dialog([uint32]$p.Id) }
Check ($dlg -ne 0) 'and it counts as changed (closing asks)'
[W]::PostMessage($dlg, 0x111, [IntPtr]7, [IntPtr]::Zero) | Out-Null
$p.WaitForExit(5000) | Out-Null
if (-not $p.HasExited) { $p.Kill() }

# --- the window comes back where it was left
$p = Start-Jw $work @{}
$h = $p.MainWindowHandle
Start-Sleep -Milliseconds 600
[W]::MoveWindow($h, 123, 77, 900, 650, $true) | Out-Null
Start-Sleep -Milliseconds 300
[W]::PostMessage($h, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null
$p.WaitForExit(5000) | Out-Null
Check $p.HasExited 'an unchanged drawing closes without asking'
$p = Start-Jw $work @{}
$h = $p.MainWindowHandle
Start-Sleep -Milliseconds 600
$r = New-Object W+RECT
[W]::GetWindowRect($h, [ref]$r) | Out-Null
Check (($r.l -in 120..126) -and ($r.t -in 74..80) -and (($r.r - $r.l) -in 897..903)) ("the window position and size are kept: " + $r.l + ',' + $r.t + ' ' + ($r.r - $r.l) + 'x' + ($r.b - $r.t))
[W]::PostMessage($h, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null
$p.WaitForExit(5000) | Out-Null

# --- high DPI: at scale 2 the mouse positions are halved, so the same drawing action lands
$app2 = Join-Path $tmp 'appdata2'
New-Item -ItemType Directory -Force $app2 | Out-Null
$auto2 = [IO.Path]::Combine($app2, 'jw_port', 'autosave.jww')
$p = Start-Jw $work @{ JW_UISCALE = '2'; APPDATA = $app2 }
$h = $p.MainWindowHandle
Start-Sleep -Milliseconds 800
$c = New-Object W+RECT
[W]::GetClientRect($h, [ref]$c) | Out-Null
Check ($c.r -ge 1800) ("at scale 2 the window is twice as big (client " + $c.r + 'x' + $c.b + ')')
Click $h 800 600; Click $h 1400 840
$seen = $false
for ($i = 0; $i -lt 16 -and -not $seen; $i++) { Start-Sleep -Milliseconds 500; $seen = Test-Path $auto2 }
Check $seen 'clicks at doubled positions draw (the drawing is changed)'
[W]::PostMessage($h, 0x10, [IntPtr]::Zero, [IntPtr]::Zero) | Out-Null
$dlg = [IntPtr]::Zero
for ($i = 0; $i -lt 20 -and $dlg -eq 0; $i++) { Start-Sleep -Milliseconds 200; $dlg = [W]::Dialog([uint32]$p.Id) }
if ($dlg -ne 0) { [W]::PostMessage($dlg, 0x111, [IntPtr]7, [IntPtr]::Zero) | Out-Null }
$p.WaitForExit(5000) | Out-Null
if (-not $p.HasExited) { $p.Kill() }
Remove-Item -Recurse -Force $tmp -ErrorAction SilentlyContinue
if ($fails) { Write-Host 'FAILED'; exit 1 } else { Write-Host 'all ok' }
