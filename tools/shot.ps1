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
    [switch]$Foreground,
    [switch]$NoResize,
    [switch]$Repaint,
    [int]$StableMs = 0,
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
    [DllImport("user32.dll")] public static extern bool RedrawWindow(
        IntPtr h, IntPtr r, IntPtr rgn, uint flags);
    [DllImport("user32.dll")] public static extern bool SetWindowPos(
        IntPtr h, IntPtr after, int x, int y, int w, int c, uint flags);
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

    /// Ask the window to paint itself into an off-screen DC.  Nothing has to
    /// be on top, or even visible, so this does not disturb whoever is using
    /// the machine -- but it only works with Direct2D off, because a D2D swap
    /// chain is not part of what WM_PRINT redraws.
    /// A cheap checksum of a bitmap, to tell whether the window has stopped
    /// changing.
    public static long Sum(Bitmap b) {
        System.Drawing.Imaging.BitmapData d = b.LockBits(
            new Rectangle(0, 0, b.Width, b.Height),
            System.Drawing.Imaging.ImageLockMode.ReadOnly,
            System.Drawing.Imaging.PixelFormat.Format32bppArgb);
        int n = Math.Abs(d.Stride) * b.Height;
        byte[] buf = new byte[n];
        Marshal.Copy(d.Scan0, buf, 0, n);
        b.UnlockBits(d);
        long s = 1469598103934665603L;
        for (int i = 0; i < n; i++) { s ^= buf[i]; s *= 1099511628211L; }
        return s;
    }

    public static Bitmap Grab(IntPtr h, bool clientOnly) {
        RECT wr; GetWindowRect(h, out wr);
        Bitmap full = new Bitmap(wr.Right - wr.Left, wr.Bottom - wr.Top,
                                System.Drawing.Imaging.PixelFormat.Format32bppArgb);
        using (Graphics g = Graphics.FromImage(full)) {
            IntPtr dc = g.GetHdc();
            // 2 = PW_RENDERFULLCONTENT.
            PrintWindow(h, dc, 2);
            g.ReleaseHdc(dc);
        }
        if (!clientOnly) {
            return full;
        }
        RECT cr; GetClientRect(h, out cr);
        POINT p; p.X = 0; p.Y = 0; ClientToScreen(h, ref p);
        Bitmap bmp = full.Clone(
            new Rectangle(p.X - wr.Left, p.Y - wr.Top,
                          cr.Right - cr.Left, cr.Bottom - cr.Top),
            full.PixelFormat);
        full.Dispose();
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
    # 4 = SW_SHOWNOACTIVATE: show it at its normal size without taking focus.
    [void][Shot]::ShowWindow($h, 4)
    # Clamp to the work area: a window taller than the desktop leaves the
    # taskbar showing through the bottom of a screen grab.
    if (-not $NoResize) {
        $wa = [System.Windows.Forms.Screen]::PrimaryScreen.WorkingArea
        $w = [math]::Min($Width, $wa.Width)
        $c = [math]::Min($Height, $wa.Height)
        [void][Shot]::MoveWindow($h, $wa.X, $wa.Y, $w, $c, $true)
    }
    # A screen grab returns whatever is actually on the glass, so anything
    # overlapping the window ends up in the picture -- a terminal sitting on
    # top once produced a "reference" that was mostly scrollback.
    # SetForegroundWindow alone is not enough; Windows refuses it when the
    # caller is not the foreground process.  HWND_TOPMOST always works.
    if ($Foreground -or $Screen) {
        # A screen grab returns whatever is actually on the glass, so anything
        # overlapping the window ends up in the picture -- a terminal sitting
        # on top once produced a "reference" that was mostly scrollback.
        # SetForegroundWindow alone is not enough; Windows refuses it when the
        # caller is not the foreground process.  HWND_TOPMOST always works,
        # but it steals the screen from whoever is using the machine.
        [void][Shot]::SetForegroundWindow($h)
        [void][Shot]::SetWindowPos($h, [IntPtr](-1), 0, 0, 0, 0, 0x0003)
    }
    if ($Repaint) {
        # Jw_cad paints the drawing lazily, and a grab taken soon after it
        # opens a file catches a half-finished picture -- サンプル.jww came
        # out with 3,580 ink pixels that way against 15,492 once it had
        # settled.  Shrinking the window and restoring it forces the lot,
        # and the count then stops changing.
        # Minimise and restore.  Not a resize: resizing re-wraps the
        # toolbars, which moves the whole frame and makes the shot
        # incomparable with the others.
        [void][Shot]::ShowWindow($h, 6)     # SW_MINIMIZE
        Start-Sleep -Milliseconds 1200
        [void][Shot]::ShowWindow($h, 9)     # SW_RESTORE
        Start-Sleep -Milliseconds 1200
        [void][Shot]::SetForegroundWindow($h)
        [void][Shot]::SetWindowPos($h, [IntPtr](-1), 0, 0, 0, 0, 0x0003)
    }
    # Ask for a full repaint of the window and every child before grabbing.
    # Without it PrintWindow can hand back a stale or half-drawn view: the
    # shadow diagram of 日影図.jww came out with a sixth of its ink.
    # 0x0001 RDW_INVALIDATE | 0x0100 RDW_UPDATENOW | 0x0080 RDW_ALLCHILDREN
    [void][Shot]::RedrawWindow($h, [IntPtr]::Zero, [IntPtr]::Zero, 0x0181)
    Start-Sleep -Milliseconds $SettleMs

    if ($StableMs -gt 0) {
        # Jw_cad draws a big drawing slowly -- on this machine it is an x86
        # binary under emulation -- and a grab taken too early catches a half
        # finished picture.  Test1.jww gives 6,467 ink pixels after five
        # seconds and 16,597 once it has finished.  So wait until two grabs
        # in a row are the same instead of guessing a delay.
        # Five samples in a row have to agree: the painting comes in phases
        # with a pause between them, so "the same twice" fires in the gap
        # before the text is drawn.
        $prev = -1
        $same = 0
        $deadline = (Get-Date).AddMilliseconds($StableMs)
        while ((Get-Date) -lt $deadline) {
            Start-Sleep -Milliseconds 2000
            $b = if ($Screen) { [Shot]::GrabScreen($h, $Client) }
                 else { [Shot]::Grab($h, $Client) }
            $sum = [Shot]::Sum($b)
            $b.Dispose()
            if ($sum -eq $prev) { $same++ } else { $same = 0 }
            $prev = $sum
            if ($same -ge 4) { break }
        }
    }

    $dir = Split-Path -Parent $Out
    if ($dir -and -not (Test-Path $dir)) { New-Item -ItemType Directory -Force -Path $dir | Out-Null }
    $bmp = if ($Screen) { [Shot]::GrabScreen($h, $Client) } else { [Shot]::Grab($h, $Client) }
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
