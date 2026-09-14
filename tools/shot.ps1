# Capture the original's window to a PNG, so the port has something to be
# compared against pixel for pixel.
#
#   powershell -ExecutionPolicy Bypass -File tools/shot.ps1 `
#       -Exe orig\Jw_win.exe -Out docs\ref_start.png [-Open orig\Test1.jww]
#
# The window is moved to 0,0 and resized before the shot so two runs frame the
# drawing identically; without that the capture depends on where Windows
# happened to place the window.
param(
    [string]$Exe = 'orig\Jw_win.exe',
    [string]$Out = 'docs\ref.png',
    [string]$Open = '',
    [int]$Width = 1280,
    [int]$Height = 800,
    [int]$SettleMs = 4000,
    [switch]$Screen,
    [switch]$Client,
    [switch]$Keep
)
$ErrorActionPreference = 'Stop'

Add-Type -TypeDefinition @'
using System;
using System.Drawing;
using System.Runtime.InteropServices;

public static class Shot {
    [DllImport("user32.dll")] public static extern bool MoveWindow(
        IntPtr h, int x, int y, int w, int c, bool repaint);
    [DllImport("user32.dll")] public static extern bool SetForegroundWindow(IntPtr h);
    [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool PrintWindow(
        IntPtr h, IntPtr dc, uint flags);
    [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h, int cmd);
    [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool ClientToScreen(IntPtr h, ref POINT p);

    [StructLayout(LayoutKind.Sequential)]
    public struct POINT { public int X, Y; }

    [StructLayout(LayoutKind.Sequential)]
    public struct RECT { public int Left, Top, Right, Bottom; }

    /// Read the pixels off the desktop instead of asking the window to
    /// redraw itself.  Jw_cad draws the document through Direct2D, whose
    /// swap chain PrintWindow cannot see: the frame comes back but the
    /// drawing area is blank white.
    public static Bitmap GrabScreen(IntPtr h, bool clientOnly) {
        RECT r; int x, y, w, c;
        if (clientOnly) {
            GetClientRect(h, out r);
            POINT p; p.X = r.Left; p.Y = r.Top; ClientToScreen(h, ref p);
            x = p.X; y = p.Y; w = r.Right - r.Left; c = r.Bottom - r.Top;
        } else {
            GetWindowRect(h, out r);
            x = r.Left; y = r.Top; w = r.Right - r.Left; c = r.Bottom - r.Top;
        }
        Bitmap bmp = new Bitmap(w, c,
                                System.Drawing.Imaging.PixelFormat.Format32bppArgb);
        using (Graphics g = Graphics.FromImage(bmp)) {
            g.CopyFromScreen(x, y, 0, 0, new Size(w, c),
                             CopyPixelOperation.SourceCopy);
        }
        return bmp;
    }

    public static Bitmap Grab(IntPtr h) {
        RECT r; GetWindowRect(h, out r);
        Bitmap bmp = new Bitmap(r.Right - r.Left, r.Bottom - r.Top,
                                System.Drawing.Imaging.PixelFormat.Format32bppArgb);
        using (Graphics g = Graphics.FromImage(bmp)) {
            IntPtr dc = g.GetHdc();
            // 2 = PW_RENDERFULLCONTENT: without it a Direct2D or layered
            // surface comes back blank.
            PrintWindow(h, dc, 2);
            g.ReleaseHdc(dc);
        }
        return bmp;
    }
}
'@ -ReferencedAssemblies System.Drawing, System.Windows.Forms

$exePath = (Resolve-Path $Exe).Path
$argList = @()
if ($Open) { $argList += (Resolve-Path $Open).Path }

$p = if ($argList.Count) {
    Start-Process -FilePath $exePath -ArgumentList $argList -PassThru
} else {
    Start-Process -FilePath $exePath -PassThru
}

try {
    $deadline = (Get-Date).AddSeconds(30)
    while (-not $p.MainWindowHandle -or $p.MainWindowHandle -eq [IntPtr]::Zero) {
        if ((Get-Date) -gt $deadline) { throw 'no main window after 30 s' }
        Start-Sleep -Milliseconds 200
        $p.Refresh()
    }
    $h = $p.MainWindowHandle
    [void][Shot]::ShowWindow($h, 1)            # SW_SHOWNORMAL, undo any maximise
    # Clamp to the work area: a window taller than the desktop leaves the
    # taskbar showing through the bottom of a screen grab.
    $wa = [System.Windows.Forms.Screen]::PrimaryScreen.WorkingArea
    $w = [math]::Min($Width, $wa.Width)
    $c = [math]::Min($Height, $wa.Height)
    [void][Shot]::MoveWindow($h, $wa.X, $wa.Y, $w, $c, $true)
    [void][Shot]::SetForegroundWindow($h)
    Start-Sleep -Milliseconds $SettleMs

    $dir = Split-Path -Parent $Out
    if ($dir -and -not (Test-Path $dir)) { New-Item -ItemType Directory -Force -Path $dir | Out-Null }
    $bmp = if ($Screen -or $Client) { [Shot]::GrabScreen($h, $Client) } else { [Shot]::Grab($h) }
    $bmp.Save((Join-Path (Get-Location) $Out), [System.Drawing.Imaging.ImageFormat]::Png)
    $bmp.Dispose()
    Write-Host ("wrote {0} ({1} x {2})" -f $Out, $Width, $Height)
} finally {
    if (-not $Keep -and -not $p.HasExited) {
        $p.CloseMainWindow() | Out-Null
        Start-Sleep -Milliseconds 1500
        if (-not $p.HasExited) { $p.Kill() }
    }
}
