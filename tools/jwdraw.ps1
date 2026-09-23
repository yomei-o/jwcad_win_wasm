# Drive the original: open a drawing, press things, and read out what it did.
#
#   powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1 `
#       -Cmd 32883 -Clicks '250,180;450,180;450,320'
#
# Nothing here reads the screen.  Clicks go to the view as posted
# WM_LBUTTONDOWN / WM_LBUTTONUP, and what the original did is read back out of
# the .jww it saves (or, for the layout steps, out of EnumChildWindows).
# tools/shot.ps1 is the one that takes pictures.
#
# The window has to be visible.  It is shown with SW_SHOWNOACTIVATE and pushed
# to HWND_BOTTOM, and that is as far as it can be kept out of the way:
#
#   * SW_HIDE makes Jw_cad lay itself out at a different size, which moves
#     every paper coordinate.
#   * moving it off screen or into a corner makes MFC re-wrap the docking bars
#     and write the new layout back to HKCU -- the left toolbar comes back as
#     one column next time and everything shifts 39 pixels.  tools/refenv.sh
#     puts it back.
#
# Posted mouse messages are not hit-tested, so a click may be outside the
# view's client rectangle; it still lands on the paper point it maps to.  The
# `c` steps are the exception -- they move the real cursor, so they have to be
# somewhere real.
#
# Steps, separated by `;`:
#
#   x,y                 left click in the view's client coordinates
#   r<x>,<y>            right click
#   c<x>,<y>[,r]        move the real cursor there first, then click
#                       (some handlers read GetCursorPos, not lParam)
#   w<x>,<y>[,r]        click in the FRAME's client coordinates -- for the
#                       layer grid, whose buttons are frame children
#   cmd:<id>            WM_COMMAND to the frame, mid-way
#   raw:v,<msg>,<w>,<l> any message to the view (5136 = 選択確定)
#   ch:<id>,<text>      real WM_CHARs into a command-bar control, one at a
#                       time.  WM_SETTEXT does not work: the command keeps
#                       using the value it already has.  The text is
#                       everything after the first comma, commas included.
#   set:<id>,<text>     WM_SETTEXT.  Some commands keep using the value they
#                       already have, but the hatch bar reads its boxes when
#                       実行 is pressed and does take it.
#   read:59393          the status line.  It is a control of the frame like
#                       any other and WM_GETTEXT hands its text over, so what
#                       a command is asking for can be read rather than
#                       photographed -- 「始点を指示してください」 and so on.
#   btn:<id>            BM_CLICK a control (sent -- a button that opens a
#                       modal dialog holds the script here; use pb: or dlg:b)
#   pb:<id>             BM_CLICK posted instead, so a modal dialog does not
#                       stop the rest of the steps
#   m<x>,<y>            move the real cursor into the view without clicking --
#                       複写・移動 read GetCursorPos for their 基準点
#   off:<id>            turn a checkbox off (a click, so the app is told)
#   type:<text>         the 文字 command's box, then Enter
#   type::<text>        the same without Enter
#   top                 list the process's top-level windows and their children
#   bar                 list the command bar's controls
#   bar:<n>             the same, headed `=== command <n>` so tools/mkbars.py
#                       can read it -- for a bar the command only puts up
#                       part way through (複写・移動's second stage)
#   box                 the 文字 command's input box, if it is up
#   all                 every child of the frame
#   size:<w>,<h>        resize the frame (this writes the dock layout back to
#                       HKCU -- run tools/refenv.sh afterwards)
#   shot:<png>          PrintWindow the frame into a PNG (no screen reading)
#   dlg:<cmd>,<png>     open a dialog with a command, write its children out
#                       and paint it into a PNG, then cancel it
#   dlg:b<id>,<png>     the same, opened by pressing a bar button
#   import:<cmd>,<path> open a file of another kind -- 32960 DXF, 32975 SFC,
#                       32809 JWC -- through the same common dialog
#   export:<cmd>,<name> the same, but sending <cmd> instead of 名前を付けて
#                       保存 -- 32961 is DXF形式で保存, 32976 SFC形式で保存,
#                       32810 JWC形式で保存
#   saveas:<name>       名前を付けて保存 to tmp\<name>.jww (or to the path
#                       given, if it looks like one).  Needs the Windows
#                       common dialog, which the script turns on in HKCU for
#                       the run -- tools/refenv.sh afterwards.
#   wait:<ms>           sleep
#
# Rows written out for a control are what tools/mkbars.py and tools/mkzoku.py
# read:  class|id|x|y|w|h|style|checked|enabled|text
# with the rectangle in the parent's client coordinates.
param(
    [string]$Exe    = 'orig\Jw_win.exe',
    [string]$Open   = 'tmp\rect.jww',
    [int]$Cmd       = 0,
    [string]$Clicks = '',
    [int]$After     = 0,
    [int]$Width     = 1280,
    [int]$Height    = 800,
    [int]$SettleMs  = 3000,
    [int]$StepMs    = 450,
    # Send each of these commands in turn and write the frame's controls out
    # after each one -- this is what tools/mkbars.py reads.  One launch, so
    # every bar is captured in the state the original enters the command in.
    [string]$Cmds   = '',
    # Write the rows here as well as to stdout (UTF-8, no BOM, LF).
    [string]$Out    = '',
    [switch]$NoSave,
    [switch]$Keep
)
$ErrorActionPreference = 'Stop'
[Console]::OutputEncoding = [System.Text.Encoding]::UTF8
$script:rows = New-Object System.Collections.Generic.List[string]
function Emit([string]$s) { $script:rows.Add($s); Write-Output $s }

Add-Type -TypeDefinition @'
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Text;

public static class Jw {
    public delegate bool EnumProc(IntPtr h, IntPtr l);

    [DllImport("user32.dll")] public static extern bool EnumChildWindows(IntPtr h, EnumProc cb, IntPtr l);
    [DllImport("user32.dll")] public static extern bool EnumWindows(EnumProc cb, IntPtr l);
    [DllImport("user32.dll")] public static extern uint GetWindowThreadProcessId(IntPtr h, out uint pid);
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] public static extern int GetClassNameW(IntPtr h, StringBuilder s, int n);
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] public static extern int GetWindowTextW(IntPtr h, StringBuilder s, int n);
    [DllImport("user32.dll")] public static extern int GetDlgCtrlID(IntPtr h);
    [DllImport("user32.dll")] public static extern int GetWindowLong(IntPtr h, int i);
    [DllImport("user32.dll")] public static extern bool IsWindowEnabled(IntPtr h);
    [DllImport("user32.dll")] public static extern bool IsWindowVisible(IntPtr h);
    [DllImport("user32.dll")] public static extern bool IsWindow(IntPtr h);
    [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool ScreenToClient(IntPtr h, ref POINT p);
    [DllImport("user32.dll")] public static extern bool ClientToScreen(IntPtr h, ref POINT p);
    [DllImport("user32.dll")] public static extern bool SetCursorPos(int x, int y);
    [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h, int c);
    [DllImport("user32.dll")] public static extern bool SetWindowPos(IntPtr h, IntPtr after, int x, int y, int w, int c, uint f);
    [DllImport("user32.dll")] public static extern bool MoveWindow(IntPtr h, int x, int y, int w, int c, bool rp);
    [DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr dc, uint f);
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] public static extern IntPtr SendMessageW(IntPtr h, uint m, IntPtr w, IntPtr l);
    [DllImport("user32.dll", EntryPoint = "SendMessageW", CharSet = CharSet.Unicode)] public static extern IntPtr SendMessageStr(IntPtr h, uint m, IntPtr w, string l);
    [DllImport("user32.dll", EntryPoint = "SendMessageW", CharSet = CharSet.Unicode)] public static extern IntPtr SendMessageSb(IntPtr h, uint m, IntPtr w, StringBuilder l);
    [DllImport("user32.dll")] public static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l);

    [StructLayout(LayoutKind.Sequential)] public struct RECT { public int Left, Top, Right, Bottom; }
    [StructLayout(LayoutKind.Sequential)] public struct POINT { public int X, Y; }

    public static IntPtr[] Kids(IntPtr parent) {
        List<IntPtr> l = new List<IntPtr>();
        EnumChildWindows(parent, delegate(IntPtr h, IntPtr p) { l.Add(h); return true; }, IntPtr.Zero);
        return l.ToArray();
    }

    public static IntPtr[] Tops(uint pid) {
        List<IntPtr> l = new List<IntPtr>();
        EnumWindows(delegate(IntPtr h, IntPtr p) {
            uint q; GetWindowThreadProcessId(h, out q);
            if (q == pid) l.Add(h);
            return true;
        }, IntPtr.Zero);
        return l.ToArray();
    }

    public static string Cls(IntPtr h) {
        StringBuilder s = new StringBuilder(256);
        GetClassNameW(h, s, 256);
        return s.ToString();
    }

    /// What a control actually holds.  GetWindowText does not cross a
    /// process boundary for a control -- it reads the window's stored title
    /// and never sends WM_GETTEXT -- so an Edit or a ComboBox in Jw_cad comes
    /// back empty however full it is.  Asking with the message works.
    public static string TxtMsg(IntPtr h) {
        StringBuilder s = new StringBuilder(1024);
        SendMessageSb(h, 0x000D, (IntPtr)1024, s);       // WM_GETTEXT
        return s.ToString();
    }

    public static string Txt(IntPtr h) {
        StringBuilder s = new StringBuilder(1024);
        GetWindowTextW(h, s, 1024);
        return s.ToString().Replace("|", "\\x7c").Replace("\r", " ").Replace("\n", " ");
    }

    /// A child's rectangle in some ancestor's client coordinates.
    public static RECT RectIn(IntPtr h, IntPtr parent) {
        RECT r; GetWindowRect(h, out r);
        POINT a; a.X = r.Left;  a.Y = r.Top;    ScreenToClient(parent, ref a);
        POINT b; b.X = r.Right; b.Y = r.Bottom; ScreenToClient(parent, ref b);
        RECT o; o.Left = a.X; o.Top = a.Y; o.Right = b.X; o.Bottom = b.Y;
        return o;
    }

    /// The biggest child there is: Jw_cad's view.  A window with no children
    /// at all -- the port's, which draws everything itself -- is its own view,
    /// so this can drive both of them.
    public static IntPtr Biggest(IntPtr parent) {
        IntPtr best = parent;
        long area = -1;
        foreach (IntPtr h in Kids(parent)) {
            if (!IsWindowVisible(h)) continue;
            RECT r; GetWindowRect(h, out r);
            long a = (long)(r.Right - r.Left) * (r.Bottom - r.Top);
            if (a > area) { area = a; best = h; }
        }
        return best;
    }

    /// The smallest child of `parent` covering a point given in `parent`'s
    /// client coordinates.  WindowFromPoint answers with whatever is in front,
    /// which for the layer grid is the bar and not the button.
    public static IntPtr At(IntPtr parent, int x, int y) {
        IntPtr best = IntPtr.Zero;
        long area = long.MaxValue;
        foreach (IntPtr h in Kids(parent)) {
            if (!IsWindowVisible(h)) continue;
            RECT r = RectIn(h, parent);
            if (x < r.Left || x >= r.Right || y < r.Top || y >= r.Bottom) continue;
            long a = (long)(r.Right - r.Left) * (r.Bottom - r.Top);
            if (a < area) { area = a; best = h; }
        }
        return best;
    }

    /// A client point of h, on the screen.  Done here rather than with
    /// ClientToScreen and a [ref] from PowerShell: a struct passed that way
    /// came back unchanged, so the cursor went to the client coordinates
    /// taken as screen ones and every `c` click picked the wrong place.
    public static POINT ScreenOf(IntPtr h, int x, int y) {
        POINT p; p.X = x; p.Y = y;
        ClientToScreen(h, ref p);
        return p;
    }

    public static Bitmap Paint(IntPtr h) {
        RECT r; GetWindowRect(h, out r);
        Bitmap b = new Bitmap(r.Right - r.Left, r.Bottom - r.Top,
                              System.Drawing.Imaging.PixelFormat.Format32bppArgb);
        using (Graphics g = Graphics.FromImage(b)) {
            IntPtr dc = g.GetHdc();
            PrintWindow(h, dc, 2);          // PW_RENDERFULLCONTENT
            g.ReleaseHdc(dc);
        }
        return b;
    }
}
'@ -ReferencedAssemblies System.Drawing, System.Windows.Forms

$WM_MOUSEMOVE   = 0x0200
$WM_LBUTTONDOWN = 0x0201
$WM_LBUTTONUP   = 0x0202
$WM_RBUTTONDOWN = 0x0204
$WM_RBUTTONUP   = 0x0205
$WM_COMMAND     = 0x0111
$WM_CHAR        = 0x0102
$WM_SETTEXT     = 0x000C
$BM_CLICK       = 0x00F5
$BM_GETCHECK    = 0x00F0
$EM_SETSEL      = 0x00B1

# Not named LP: PowerShell ships an alias lp for Out-Printer, and an alias
# beats a function, so every click went to the printer instead.
function LParam([int]$x, [int]$y) { [IntPtr](($y -shl 16) -bor ($x -band 0xffff)) }

function Row($h, $parent) {
    $r = [Jw]::RectIn($h, $parent)
    $chk = 0
    if ([Jw]::Cls($h) -eq 'Button') {
        $chk = [int][Jw]::SendMessageW($h, $BM_GETCHECK, [IntPtr]::Zero, [IntPtr]::Zero)
    }
    Emit ('{0}|{1}|{2}|{3}|{4}|{5}|{6:x8}|{7}|{8}|{9}' -f `
        [Jw]::Cls($h), [Jw]::GetDlgCtrlID($h),
        $r.Left, $r.Top, ($r.Right - $r.Left), ($r.Bottom - $r.Top),
        [Jw]::GetWindowLong($h, -16),
        $chk, [int][Jw]::IsWindowEnabled($h), [Jw]::Txt($h))
}

function Dump($parent) { foreach ($k in [Jw]::Kids($parent)) { Row $k $parent } }
# The same, but for one subtree, with the rectangles still measured in
# the frame -- which is the coordinate system tools/mkbars.py wants.
# Only the controls that are actually up: the bar templates carry a second
# set for the modes that are off (the line command has a third combobox
# sitting exactly on top of 1412), and tools/mkbars.py does not filter, so
# they have to be left out here or the port draws them over each other.
function DumpIn($container, $frame) {
    foreach ($k in [Jw]::Kids($container)) {
        if (-not [Jw]::IsWindowVisible($k)) { continue }
        Row $k $frame
    }
}

# --- start it -----------------------------------------------------------

$exePath = (Resolve-Path $Exe).Path
$needCommon = $Clicks -match '(saveas|export|import):'
if ($needCommon) {
    # The original's own file box (resource 290) has a read-only name field
    # that ignores WM_SETTEXT.  This makes it use Windows' common dialog,
    # whose name field can be written.  tools/refenv.sh puts it back.
    New-Item -Path 'HKCU:\Software\Jw_cad\jw_win\Dialog' -Force | Out-Null
    Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Dialog' `
                     -Name 'FileCommonDialog' -Value 1 -Type DWord
}

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
    $frame = $p.MainWindowHandle
    [void][Jw]::ShowWindow($frame, 4)                       # SW_SHOWNOACTIVATE
    # Put it at the size docs/ref_*.png were taken at, the way tools/shot.ps1
    # does.  Jw_cad normally comes up at the WindowPos in HKCU, which
    # tools/refenv.sh restores to 1280x800 -- but not always: a few runs came
    # up 1440x745 instead, and the view being a different size moves every
    # paper coordinate the clicks land on.  Setting the size it should already
    # have costs nothing when it is right and fixes it when it is not.
    $wa = [System.Windows.Forms.Screen]::PrimaryScreen.WorkingArea
    [void][Jw]::MoveWindow($frame, $wa.X, $wa.Y,
                           [math]::Min($Width, $wa.Width),
                           [math]::Min($Height, $wa.Height), $true)
    # HWND_BOTTOM, no move, no size, no activate
    [void][Jw]::SetWindowPos($frame, [IntPtr]1, 0, 0, 0, 0, 0x0013)
    Start-Sleep -Milliseconds $SettleMs

    $view = [Jw]::Biggest($frame)
    $fc = New-Object Jw+RECT; [void][Jw]::GetClientRect($frame, [ref]$fc)
    $vc = New-Object Jw+RECT; [void][Jw]::GetClientRect($view,  [ref]$vc)
    $vr = [Jw]::RectIn($view, $frame)
    Write-Host ("frame {0}x{1}  view {2}x{3} at {4},{5} in the frame" -f `
        $fc.Right, $fc.Bottom, $vc.Right, $vc.Bottom, $vr.Left, $vr.Top)

    # The command bar is the docking bar that carries the CDialogBar -- the
    # only one of the frame's bars with a #32770 inside it.  Only its controls
    # belong in bars.txt; the layer grid down the right is Buttons too, and
    # walking the whole frame sweeps all 60 of them into every command.
    function CmdBar {
        foreach ($k in [Jw]::Kids($frame)) {
            if ([Jw]::Cls($k) -notlike 'AfxControlBar*') { continue }
            foreach ($g in [Jw]::Kids($k)) {
                if ([Jw]::Cls($g) -eq '#32770') { return $k }
            }
        }
        throw 'no command bar in the frame'
    }

    if ($Cmd -ne 0) {
        [void][Jw]::SendMessageW($frame, $WM_COMMAND, [IntPtr]$Cmd, [IntPtr]::Zero)
        Start-Sleep -Milliseconds $StepMs
    }

    function Ctl([int]$id) {
        foreach ($k in [Jw]::Kids($frame)) {
            if ([Jw]::GetDlgCtrlID($k) -eq $id -and [Jw]::IsWindowVisible($k)) { return $k }
        }
        foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
            if ($t -eq $frame) { continue }
            foreach ($k in [Jw]::Kids($t)) {
                if ([Jw]::GetDlgCtrlID($k) -eq $id -and [Jw]::IsWindowVisible($k)) { return $k }
            }
        }
        return [IntPtr]::Zero
    }

    # A combobox's text lives in the Edit inside it.
    function EditOf($h) {
        if ([Jw]::Cls($h) -like 'ComboBox*') {
            foreach ($k in [Jw]::Kids($h)) {
                if ([Jw]::Cls($k) -eq 'Edit') { return $k }
            }
        }
        return $h
    }

    function Chars($h, [string]$s, [switch]$Enter) {
        $e = EditOf $h
        $r = [Jw]::RectIn($e, $frame)
        $mid = LParam ([int](($r.Right - $r.Left) / 2)) ([int](($r.Bottom - $r.Top) / 2))
        [void][Jw]::PostMessage($e, $WM_LBUTTONDOWN, [IntPtr]1, $mid)
        [void][Jw]::PostMessage($e, $WM_LBUTTONUP,   [IntPtr]0, $mid)
        Start-Sleep -Milliseconds 120
        [void][Jw]::SendMessageW($e, $EM_SETSEL, [IntPtr]0, [IntPtr](-1))
        for ($i = 0; $i -lt 24; $i++) {
            [void][Jw]::PostMessage($e, $WM_CHAR, [IntPtr]8, [IntPtr]1)
        }
        Start-Sleep -Milliseconds 80
        foreach ($c in $s.ToCharArray()) {
            [void][Jw]::PostMessage($e, $WM_CHAR, [IntPtr][int][char]$c, [IntPtr]1)
            Start-Sleep -Milliseconds 25
        }
        if ($Enter) { [void][Jw]::PostMessage($e, $WM_CHAR, [IntPtr]13, [IntPtr]1) }
        Start-Sleep -Milliseconds 150
    }

    function Click($h, [int]$x, [int]$y, [bool]$right, [bool]$real, [bool]$shift = $false) {
        if ($real) {
            $pt = [Jw]::ScreenOf($h, $x, $y)
            [void][Jw]::SetCursorPos($pt.X, $pt.Y)
            Start-Sleep -Milliseconds 120
        }
        $l = LParam $x $y
        [void][Jw]::PostMessage($h, $WM_MOUSEMOVE, [IntPtr]0, $l)
        Start-Sleep -Milliseconds 60
        if ($right) {
            [void][Jw]::PostMessage($h, $WM_RBUTTONDOWN, [IntPtr]2, $l)
            [void][Jw]::PostMessage($h, $WM_RBUTTONUP,   [IntPtr]0, $l)
        } else {
            # MK_LBUTTON, and MK_SHIFT with it when the step asked for it
            $wp = if ($shift) { 5 } else { 1 }
            [void][Jw]::PostMessage($h, $WM_LBUTTONDOWN, [IntPtr]$wp, $l)
            [void][Jw]::PostMessage($h, $WM_LBUTTONUP,   [IntPtr]0, $l)
        }
        Start-Sleep -Milliseconds $StepMs
    }

    # A top-level #32770 of ours that was not there before.
    # The handle goes into a variable rather than out of the function: a
    # PowerShell function returns everything its body writes, so anything that
    # leaks into the output stream comes back as an array instead of a handle.
    function NewDialog($seen, [int]$waitMs = 6000) {
        $script:dlg = [IntPtr]::Zero
        $deadline = (Get-Date).AddMilliseconds($waitMs)
        while ((Get-Date) -lt $deadline) {
            foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                if ($seen -contains $t) { continue }
                if (-not [Jw]::IsWindowVisible($t)) { continue }
                if ([Jw]::Cls($t) -eq '#32770') { $script:dlg = $t; return }
            }
            Start-Sleep -Milliseconds 200
        }
    }

    # What is on screen, for when a dialog does not turn up.
    function Tops2 {
        foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
            Write-Host ('    top {0} {1} vis={2} "{3}"' -f `
                $t, [Jw]::Cls($t), [int][Jw]::IsWindowVisible($t), [Jw]::Txt($t))
        }
    }

    foreach ($step in ($Clicks -split ';')) {
        $s = $step.Trim()
        if (-not $s) { continue }

        switch -regex ($s) {

            '^wait:(\d+)$' {
                Start-Sleep -Milliseconds ([int]$Matches[1]); break
            }

            '^cmd:(\d+)$' {
                [void][Jw]::SendMessageW($frame, $WM_COMMAND, [IntPtr][int]$Matches[1], [IntPtr]::Zero)
                Start-Sleep -Milliseconds $StepMs; break
            }

            '^raw:v,(\d+),(-?\d+),(-?\d+)$' {
                [void][Jw]::SendMessageW($view, [uint32]$Matches[1],
                                         [IntPtr][int]$Matches[2], [IntPtr][int]$Matches[3])
                Start-Sleep -Milliseconds $StepMs; break
            }

            '^ch:(\d+),(.*)$' {
                $h = Ctl ([int]$Matches[1])
                if ($h -eq [IntPtr]::Zero) { throw "no control $($Matches[1])" }
                Chars $h $Matches[2]
                break
            }

            # what the status line is asking for: the original tells you
            # what it wants next there, which is how its stages are read off
            '^stat$' {
                $sb = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($frame)) {
                    if ([Jw]::Cls($k) -eq 'msctls_statusbar32') { $sb = $k; break }
                }
                if ($sb -eq [IntPtr]::Zero) { Write-Host 'no status bar'; break }
                Emit ('=== status [{0}]' -f [Jw]::TxtMsg($sb))
                break
            }

            '^read:(\d+)$' {
                $h = Ctl ([int]$Matches[1])
                if ($h -eq [IntPtr]::Zero) { throw "no control $($Matches[1])" }
                $e = EditOf $h
                Write-Host ('read {0}: [{1}]' -f $Matches[1], [Jw]::TxtMsg($e))
                break
            }

            '^set:(\d+),(.*)$' {
                $h = Ctl ([int]$Matches[1])
                if ($h -eq [IntPtr]::Zero) { throw "no control $($Matches[1])" }
                [void][Jw]::SendMessageStr((EditOf $h), $WM_SETTEXT, [IntPtr]::Zero, $Matches[2])
                Start-Sleep -Milliseconds $StepMs; break
            }

            '^m(-?\d+),(-?\d+)$' {
                # Move the real cursor into the view without clicking.  Some
                # stages read GetCursorPos rather than the message: 複写 and
                # 移動 take their 基準点 from wherever the cursor is sitting
                # when 選択確定 is pressed, not from any click.
                $mx = [int]$Matches[1]
                $my = [int]$Matches[2]
                $pt = [Jw]::ScreenOf($view, $mx, $my)
                [void][Jw]::SetCursorPos($pt.X, $pt.Y)
                [void][Jw]::PostMessage($view, $WM_MOUSEMOVE, [IntPtr]0,
                                        (LParam $mx $my))
                Start-Sleep -Milliseconds $StepMs
                break
            }

            '^pb:(\d+)$' {
                # BM_CLICK posted rather than sent: a button that opens a
                # modal dialog would otherwise hold this script until the
                # dialog closes, and nothing here can close it.
                $h = Ctl ([int]$Matches[1])
                if ($h -eq [IntPtr]::Zero) { throw "no control $($Matches[1])" }
                [void][Jw]::PostMessage($h, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            '^btn:(\d+)$' {
                $h = Ctl ([int]$Matches[1])
                if ($h -eq [IntPtr]::Zero) { throw "no control $($Matches[1])" }
                [void][Jw]::SendMessageW($h, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                Start-Sleep -Milliseconds $StepMs; break
            }

            '^off:(\d+)$' {
                $h = Ctl ([int]$Matches[1])
                if ($h -eq [IntPtr]::Zero) { throw "no control $($Matches[1])" }
                if ([int][Jw]::SendMessageW($h, $BM_GETCHECK, [IntPtr]::Zero, [IntPtr]::Zero)) {
                    [void][Jw]::SendMessageW($h, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                }
                Start-Sleep -Milliseconds $StepMs; break
            }

            '^type::(.*)$' {
                $h = Ctl 1422
                if ($h -eq [IntPtr]::Zero) { throw 'the 文字 box is not up' }
                Chars $h $Matches[1]
                break
            }

            '^type:(.*)$' {
                $h = Ctl 1422
                if ($h -eq [IntPtr]::Zero) { throw 'the 文字 box is not up' }
                Chars $h $Matches[1] -Enter
                break
            }

            '^top$' {
                foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                    if (-not [Jw]::IsWindowVisible($t)) { continue }
                    $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($t, [ref]$r)
                    Emit ('=== top {0} {1} "{2}" {3},{4} {5}x{6}' -f `
                        $t, [Jw]::Cls($t), [Jw]::Txt($t), $r.Left, $r.Top,
                        ($r.Right - $r.Left), ($r.Bottom - $r.Top))
                    Dump $t
                }
                break
            }

            '^bar:(\d+)$' {
                # the same as `bar`, but headed the way tools/mkbars.py reads
                # it -- for the bars a command only puts up part way through
                Emit ('=== command {0}' -f [int]$Matches[1])
                DumpIn (CmdBar) $frame
                break
            }

            '^bar$' {
                Emit '=== bar'
                DumpIn (CmdBar) $frame
                break
            }

            '^all$' {
                Emit '=== frame'
                Dump $frame
                break
            }

            '^box$' {
                $h = Ctl 1422
                if ($h -eq [IntPtr]::Zero) { Write-Host 'the 文字 box is not up'; break }
                $dlg = $h
                while ([Jw]::GetDlgCtrlID($dlg) -ne 0) {
                    $dlg = [Jw]::SendMessageW($dlg, 0, [IntPtr]::Zero, [IntPtr]::Zero)
                    break
                }
                foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                    if ([Jw]::Cls($t) -ne '#32770') { continue }
                    $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($t, [ref]$r)
                    $c = New-Object Jw+RECT; [void][Jw]::GetClientRect($t, [ref]$c)
                    $inf = [Jw]::RectIn($t, $frame)
                    Emit ('=== box at {0},{1} in the frame, window {2}x{3}, client {4}x{5}' -f `
                        $inf.Left, $inf.Top, ($r.Right - $r.Left), ($r.Bottom - $r.Top),
                        $c.Right, $c.Bottom)
                    Dump $t
                }
                break
            }

            '^size:(\d+),(\d+)$' {
                [void][Jw]::MoveWindow($frame, 0, 0, [int]$Matches[1], [int]$Matches[2], $true)
                Start-Sleep -Milliseconds 1200
                break
            }

            '^shot:(.+)$' {
                $b = [Jw]::Paint($frame)
                $b.Save((Join-Path (Get-Location) $Matches[1]),
                        [System.Drawing.Imaging.ImageFormat]::Png)
                $b.Dispose()
                break
            }

            '^dlg:(b?)(\d+),(.+)$' {
                # every -match rewrites $Matches, so read the groups first
                $byButton = $Matches[1] -eq 'b'
                $id  = [int]$Matches[2]
                $png = $Matches[3]
                $before = [Jw]::Tops([uint32]$p.Id)
                if ($byButton) {
                    $h = Ctl $id
                    if ($h -eq [IntPtr]::Zero) { throw "no button $id" }
                    [void][Jw]::PostMessage($h, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                } else {
                    [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$id, [IntPtr]::Zero)
                }
                NewDialog $before
                $dlg = $script:dlg
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw "no dialog came up for $id" }
                Start-Sleep -Milliseconds 700
                $b = [Jw]::Paint($dlg)
                $b.Save((Join-Path (Get-Location) $png),
                        [System.Drawing.Imaging.ImageFormat]::Png)
                $b.Dispose()
                $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($dlg, [ref]$r)
                $c = New-Object Jw+RECT; [void][Jw]::GetClientRect($dlg, [ref]$c)
                $inf = [Jw]::RectIn($dlg, $frame)
                Emit ('=== dialog {0} window {1}x{2} client {3}x{4} at {5},{6} in the frame' -f `
                    $id, ($r.Right - $r.Left), ($r.Bottom - $r.Top),
                    $c.Right, $c.Bottom, $inf.Left, $inf.Top)
                Dump $dlg
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]2, [IntPtr]::Zero)   # IDCANCEL
                Start-Sleep -Milliseconds $StepMs
                break
            }

            '^menu:(.),(.+)$' {
                # Open a menu the way Alt+<letter> does and paint the popup.
                # The popup is a top-level #32768 of its own, so PrintWindow on
                # the frame does not contain it -- it has to be painted itself.
                # SC_KEYMENU puts the original into a modal menu loop, so this
                # is posted, never sent.
                $key = [int][char]$Matches[1]
                $png = $Matches[2]
                $before = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($frame, 0x0112, [IntPtr]0xF100, [IntPtr]$key)  # WM_SYSCOMMAND SC_KEYMENU
                $pop = [IntPtr]::Zero
                $deadline = (Get-Date).AddSeconds(6)
                while ((Get-Date) -lt $deadline -and $pop -eq [IntPtr]::Zero) {
                    Start-Sleep -Milliseconds 200
                    foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                        if ([Jw]::Cls($t) -eq '#32768' -and [Jw]::IsWindowVisible($t)) {
                            $pop = $t
                        }
                    }
                }
                if ($pop -eq [IntPtr]::Zero) { Tops2; throw "no popup opened for $($Matches[1])" }
                Start-Sleep -Milliseconds 500
                $b = [Jw]::Paint($pop)
                $b.Save((Join-Path (Get-Location) $png),
                        [System.Drawing.Imaging.ImageFormat]::Png)
                $b.Dispose()
                $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($pop, [ref]$r)
                $c = New-Object Jw+RECT; [void][Jw]::GetClientRect($pop, [ref]$c)
                $inf = [Jw]::RectIn($pop, $frame)
                Emit ('=== popup {0} window {1}x{2} client {3}x{4} at {5},{6} in the frame' -f `
                    $Matches[1], ($r.Right - $r.Left), ($r.Bottom - $r.Top),
                    $c.Right, $c.Bottom, $inf.Left, $inf.Top)
                [void][Jw]::PostMessage($pop, 0x0100, [IntPtr]27, [IntPtr]1)     # VK_ESCAPE
                Start-Sleep -Milliseconds 300
                [void][Jw]::PostMessage($frame, 0x0100, [IntPtr]27, [IntPtr]1)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            '^import:(\d+),(.+)$' {
                # Open a file of another kind: 32960 is DXFファイルを開く,
                # 32975 SFCファイルを開く, 32809 JWCファイルを開く.  The same
                # common dialog as saveas:, without the overwrite question.
                $cmdid = [int]$Matches[1]
                $full = [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $Matches[2]))
                if (-not (Test-Path $full)) { throw "import: $full is not there" }
                $before = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$cmdid, [IntPtr]::Zero)
                NewDialog $before 10000
                $dlg = $script:dlg
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'the open dialog did not come up' }
                Start-Sleep -Milliseconds 600
                $edit = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($dlg)) {
                    if ([Jw]::Cls($k) -eq 'Edit') { $edit = $k; break }
                }
                if ($edit -eq [IntPtr]::Zero) { throw 'no name field in the open dialog' }
                [void][Jw]::SendMessageStr($edit, $WM_SETTEXT, [IntPtr]::Zero, $full)
                Start-Sleep -Milliseconds 250
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]1, [IntPtr]::Zero)
                Start-Sleep -Milliseconds 2500
                break
            }

            '^(?:saveas|export):(?:(\d+),)?(.+)$' {
                # saveas: is 名前を付けて保存 (57604); export: sends another
                # command first -- DXF形式で保存 is 32961 and SFC形式で保存
                # 32976 -- and then drives the same common dialog.
                $cmdid = if ($Matches[1]) { [int]$Matches[1] } else { 57604 }
                $name = $Matches[2]
                if ($name -notmatch '[\\/]' -and $name -notmatch '\.[a-zA-Z0-9]+$') {
                    $name = "tmp\$name.jww"
                }
                $full = [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $name))
                $dir = Split-Path -Parent $full
                if ($dir -and -not (Test-Path $dir)) { New-Item -ItemType Directory -Force -Path $dir | Out-Null }
                # Take the old one out of the way first.  The overwrite
                # confirmation is not reliably dismissed from here, and when it
                # is not the save quietly does not happen -- which used to look
                # like success, because the check below found the file that was
                # already there.  A run that then failed kept handing back the
                # previous run's drawing.
                Remove-Item -LiteralPath $full -Force -ErrorAction SilentlyContinue
                $before = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$cmdid, [IntPtr]::Zero)
                NewDialog $before 10000
                $dlg = $script:dlg
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'the save dialog did not come up' }
                Start-Sleep -Milliseconds 600
                # The name box: a ComboBoxEx32 (1148) around a ComboBox around
                # an Edit, or a bare Edit (1152) on the plain template.
                $edit = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($dlg)) {
                    if ([Jw]::Cls($k) -eq 'Edit') { $edit = $k; break }
                }
                if ($edit -eq [IntPtr]::Zero) { throw 'no name field in the save dialog' }
                [void][Jw]::SendMessageStr($edit, $WM_SETTEXT, [IntPtr]::Zero, $full)
                Start-Sleep -Milliseconds 250
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]1, [IntPtr]::Zero)      # IDOK
                # "already exists -- replace it?"
                $deadline = (Get-Date).AddSeconds(8)
                while ((Get-Date) -lt $deadline) {
                    Start-Sleep -Milliseconds 300
                    $gone = -not ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg))
                    foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                        if ($before -contains $t -or $t -eq $dlg) { continue }
                        if ([Jw]::Cls($t) -eq '#32770' -and [Jw]::IsWindowVisible($t)) {
                            [void][Jw]::SendMessageW($t, $WM_COMMAND, [IntPtr]6, [IntPtr]::Zero)  # IDYES
                        }
                    }
                    if ($gone) { break }
                }
                Start-Sleep -Milliseconds 800
                if (Test-Path $full) {
                    Write-Host ("saved {0} ({1:n0} bytes)" -f $name, (Get-Item $full).Length)
                } else {
                    throw "saveas: $name was not written"
                }
                break
            }

            '^w(\d+),(\d+)(,r)?$' {
                $x = [int]$Matches[1]; $y = [int]$Matches[2]
                $right = $Matches[3] -ne ''
                $h = [Jw]::At($frame, $x, $y)
                if ($h -eq [IntPtr]::Zero) { throw "nothing at $x,$y in the frame" }
                $r = [Jw]::RectIn($h, $frame)
                Click $h ($x - $r.Left) ($y - $r.Top) $right $false
                break
            }

            '^c(\d+),(\d+)(,r)?$' {
                Click $view ([int]$Matches[1]) ([int]$Matches[2]) ($Matches[3] -ne '') $true
                break
            }

            '^r(\d+),(\d+)$' {
                Click $view ([int]$Matches[1]) ([int]$Matches[2]) $true $false
                break
            }

            # the left button with Shift held, which some commands read as a
            # third way of clicking (包絡処理's 中間消去, for one).  The
            # original asks GetKeyState, so this does not reach it; the drag
            # below is the way in.
            '^s(\d+),(\d+)$' {
                Click $view ([int]$Matches[1]) ([int]$Matches[2]) $false $false $true
                break
            }

            # press at a point, pull by dx,dy, let go -- which is how the
            # original's 「Ｌ←」 and the clock menus are given
            '^d(\d+),(\d+),(-?\d+),(-?\d+)$' {
                $x = [int]$Matches[1]; $y = [int]$Matches[2]
                $dx = [int]$Matches[3]; $dy = [int]$Matches[4]
                $l0 = LParam $x $y
                $l1 = LParam ($x + $dx) ($y + $dy)
                [void][Jw]::PostMessage($view, $WM_MOUSEMOVE, [IntPtr]0, $l0)
                Start-Sleep -Milliseconds 60
                $pt = [Jw]::ScreenOf($view, $x, $y)
                [void][Jw]::SetCursorPos($pt.X, $pt.Y)
                Start-Sleep -Milliseconds 120
                [void][Jw]::PostMessage($view, $WM_LBUTTONDOWN, [IntPtr]1, $l0)
                Start-Sleep -Milliseconds 120
                for ($k = 1; $k -le 6; $k++) {
                    $mx = $x + [int]($dx * $k / 6)
                    $my = $y + [int]($dy * $k / 6)
                    $pt = [Jw]::ScreenOf($view, $mx, $my)
                    [void][Jw]::SetCursorPos($pt.X, $pt.Y)
                    [void][Jw]::PostMessage($view, $WM_MOUSEMOVE, [IntPtr]1, (LParam $mx $my))
                    Start-Sleep -Milliseconds 60
                }
                [void][Jw]::PostMessage($view, $WM_LBUTTONUP, [IntPtr]0, $l1)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            '^(\d+),(\d+)$' {
                Click $view ([int]$Matches[1]) ([int]$Matches[2]) $false $false
                break
            }

            default { throw "step not understood: $s" }
        }
    }

    if ($Cmds) {
        foreach ($c in ($Cmds -split '[,;\s]+')) {
            if (-not $c) { continue }
            [void][Jw]::SendMessageW($frame, $WM_COMMAND, [IntPtr][int]$c, [IntPtr]::Zero)
            Start-Sleep -Milliseconds 700
            Emit ('=== command {0}' -f [int]$c)
            DumpIn (CmdBar) $frame
        }
    }

    if ($After -ne 0) {
        [void][Jw]::SendMessageW($frame, $WM_COMMAND, [IntPtr]$After, [IntPtr]::Zero)
        Start-Sleep -Milliseconds $StepMs
    }

    if (-not $NoSave -and $Open -and $Clicks -notmatch 'saveas:') {
        # 上書 -- writes back to whatever was opened, which is a copy in tmp/.
        [void][Jw]::SendMessageW($frame, $WM_COMMAND, [IntPtr]57603, [IntPtr]::Zero)
        Start-Sleep -Milliseconds 1200
    }
    if ($Out) {
        $dir = Split-Path -Parent (Join-Path (Get-Location) $Out)
        if ($dir -and -not (Test-Path $dir)) { New-Item -ItemType Directory -Force -Path $dir | Out-Null }
        [System.IO.File]::WriteAllText(
            (Join-Path (Get-Location) $Out),
            (($script:rows -join "`n") + "`n"),
            (New-Object System.Text.UTF8Encoding($false)))
        Write-Host ("wrote {0} ({1} rows)" -f $Out, $script:rows.Count)
    }
} finally {
    if (-not $Keep -and -not $p.HasExited) {
        $p.CloseMainWindow() | Out-Null
        Start-Sleep -Milliseconds 1500
        # "save your changes?" -- no, everything wanted has been saved already
        foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
            if ([Jw]::Cls($t) -eq '#32770' -and [Jw]::IsWindowVisible($t)) {
                [void][Jw]::SendMessageW($t, $WM_COMMAND, [IntPtr]7, [IntPtr]::Zero)   # IDNO
            }
        }
        Start-Sleep -Milliseconds 1000
        $p.Refresh()
        if (-not $p.HasExited) { $p.Kill() }
        # Wait for it to be really gone.  The next run starts at once, and
        # Jw_cad writes its window placement and bar layout to HKCU on the way
        # out: a run that begins before that lands gets the previous run's
        # layout back over the one tools/refenv.sh just restored.
        [void]$p.WaitForExit(15000)
        Start-Sleep -Milliseconds 700
    }
}
