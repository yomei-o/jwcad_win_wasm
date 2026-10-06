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
#   LL<x>,<y>       a **double** left click, which is what the original
#                   calls (LL).  Windows delivers one as down, up,
#                   WM_LBUTTONDBLCLK, up, and the view takes all four
#                   posted, so no real mouse is needed
#   raw:v,<msg>,<w>,<l> any message to the view (5136 = 選択確定)
#   raw:f,<msg>,<w>,<l> the same to the frame -- keys have to go here,
#                       because posted clicks never give the view the focus
#   chr:<id>,<text>     the same as ch: but with a return at the end, which
#                       is how a number typed into a bar box is taken
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
#   dlgnc:<cmd>         what the dialog's non-client area really is: the
#                       visible frame (DWMWA_EXTENDED_FRAME_BOUNDS) against
#                       GetWindowRect, and what WM_NCHITTEST answers over
#                       the caption -- which is where the close cross is
#                       (HTCLOSE = 20) without reading the screen
#   dlgshot:<cmd>,<png> the dialog as it is **on the screen**, four pixels
#                       wider each way.  This one does read the screen, and
#                       it is only for the one pixel of frame that DWM, not
#                       the program, draws
#   dlgx:<cmd>,<ctl>=…  the same as dlgin: but finished with the close
#                       cross instead of OK
#   import:<cmd>,<path> open a file of another kind -- 32960 DXF, 32975 SFC,
#                       32809 JWC -- through the same common dialog
#   import:b<id>,<path> the same, opened by pressing a bar button instead of
#                       sending a command (座標ファイル's ファイル名設定)
#   figin:b<id>,<path>  the same, opened by pressing a bar button instead
#                       of sending a command (the hatch bar's 図形 1693)
#   figin:<cmd>,<path>  the same for Jw_cad's own 「ファイル選択」 window --
#                       the one 図形読込 (32862)・図形登録 (32946)・
#                       線記号変形 (32869)・建具 (32848/32866/32865) and the
#                       hatch bar's 図形 put up.  It is not a common dialog:
#                       it draws the figures itself, so there is nothing to
#                       click with a posted message.  It does take a path
#                       typed into its wide Edit 1487 and then OK, which is
#                       what this does.
#   figout:<path>       the other way: 図形登録 (32946) writes a .jws.  Send
#                       32946, take a range, press 選択確定 (btn:1120),
#                       click the 基準点, and then this presses 《図形登録》
#                       (1070), 新規 (2408) in the file window, types the
#                       name into the 新規作成 dialog and presses OK.  The
#                       file lands in the folder the window is on (tmp\figsel
#                       -- see figin:) and is copied to <path>.
#   dlgnow:<ctl>=<val>,… the same as dlgin: but for a dialog that is already
#                       up -- 属性選択's 指定【線色】指定 puts the 線属性
#                       dialog up when its own OK is pressed
#   export:<cmd>,<name> the same, but sending <cmd> instead of 名前を付けて
#                       保存 -- 32961 is DXF形式で保存, 32976 SFC形式で保存,
#                       32810 JWC形式で保存
#   savedlg:<path>     type <path> into whatever modal file dialog is up
#                       (or comes up) and press OK -- printing goes
#                       through one of those
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
    [DllImport("user32.dll")] public static extern IntPtr SetFocus(IntPtr h);
    [DllImport("user32.dll")] public static extern int GetWindowLong(IntPtr h, int i);
    [DllImport("user32.dll")] public static extern bool IsWindowEnabled(IntPtr h);
    [DllImport("user32.dll")] public static extern bool IsWindowVisible(IntPtr h);
    [DllImport("user32.dll")] public static extern bool IsWindow(IntPtr h);
    [DllImport("user32.dll")] public static extern bool GetWindowRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern bool GetClientRect(IntPtr h, out RECT r);
    [DllImport("user32.dll")] public static extern IntPtr WindowFromPoint(POINT p);
    [DllImport("dwmapi.dll")] public static extern int DwmGetWindowAttribute(IntPtr h, int a, out RECT r, int n);
    [DllImport("user32.dll")] public static extern bool ScreenToClient(IntPtr h, ref POINT p);
    [DllImport("user32.dll")] public static extern bool ClientToScreen(IntPtr h, ref POINT p);
    [DllImport("user32.dll")] public static extern bool SetCursorPos(int x, int y);
    [DllImport("user32.dll")] public static extern void mouse_event(uint f, int dx, int dy, uint d, UIntPtr e);
    [DllImport("user32.dll")] public static extern bool ShowWindow(IntPtr h, int c);
    [DllImport("user32.dll")] public static extern bool SetWindowPos(IntPtr h, IntPtr after, int x, int y, int w, int c, uint f);
    [DllImport("user32.dll")] public static extern bool MoveWindow(IntPtr h, int x, int y, int w, int c, bool rp);
    [DllImport("user32.dll")] public static extern bool PrintWindow(IntPtr h, IntPtr dc, uint f);
    [DllImport("user32.dll", CharSet = CharSet.Unicode)] public static extern IntPtr SendMessageW(IntPtr h, uint m, IntPtr w, IntPtr l);
    [DllImport("user32.dll", EntryPoint = "SendMessageW", CharSet = CharSet.Unicode)] public static extern IntPtr SendMessageStr(IntPtr h, uint m, IntPtr w, string l);
    [DllImport("user32.dll", EntryPoint = "SendMessageW", CharSet = CharSet.Unicode)] public static extern IntPtr SendMessageSb(IntPtr h, uint m, IntPtr w, StringBuilder l);
    [DllImport("user32.dll")] public static extern bool PostMessage(IntPtr h, uint m, IntPtr w, IntPtr l);
    [DllImport("user32.dll", EntryPoint = "SendMessageW")] public static extern IntPtr SendMessageRect(IntPtr h, uint m, IntPtr w, ref RECT r);

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

    /// What is actually on the screen inside r -- the only way to see the
    /// one pixel of frame that DWM, not the program, draws.  PrintWindow
    /// cannot show it: it renders what the window paints, and the window
    /// paints nothing there.
    public static Bitmap Shot(RECT r) {
        Bitmap b = new Bitmap(r.Right - r.Left, r.Bottom - r.Top,
                              System.Drawing.Imaging.PixelFormat.Format32bppArgb);
        using (Graphics g = Graphics.FromImage(b)) {
            g.CopyFromScreen(r.Left, r.Top, 0, 0,
                             new Size(r.Right - r.Left, r.Bottom - r.Top));
        }
        return b;
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
$WM_LBUTTONDBLCLK = 0x0203
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

if ($Clicks -match 'figout:') {
    # 図形登録 writes into the folder the file window is on, which is the
    # same HKCU key -- and it too is read at start-up.  An empty folder,
    # so what comes out is the only thing in it.
    $figPen = Join-Path (Get-Location) 'tmp\figsel'
    if (Test-Path $figPen) { Remove-Item "$figPen\*" -Force -ErrorAction SilentlyContinue }
    else { [void](New-Item -ItemType Directory -Force -Path $figPen) }
    New-Item -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Force | Out-Null
    Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' `
                     -Name 'ZUKEI' -Value $figPen
}

if ($Clicks -match 'figin:b?\d+,([^;]+)') {
    # Jw_cad's own 「ファイル選択」 window opens at the folder HKCU keeps in
    # Folder\ZUKEI, and it reads that **at start-up** -- writing it once the
    # process is up does nothing.  So the figure is copied into a folder of
    # its own and that folder is pointed at before the launch; the one file
    # is then the only row of the list, and the figin: step takes it from
    # there.  tools/refenv.sh puts the key back.
    $figFull = [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $Matches[1].Trim()))
    if (-not (Test-Path $figFull)) { throw "figin: $figFull is not there" }
    $figPen = Join-Path (Get-Location) 'tmp\figsel'
    if (Test-Path $figPen) { Remove-Item "$figPen\*" -Force -ErrorAction SilentlyContinue }
    else { [void](New-Item -ItemType Directory -Force -Path $figPen) }
    Copy-Item $figFull $figPen
    New-Item -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Force | Out-Null
    Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' `
                     -Name 'ZUKEI' -Value $figPen
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
    # The frame is the process's own visible top-level window that is not a
    # dialog.  MainWindowHandle is no use for it: at startup it often points
    # at the .jww association dialog instead (Jw_cad asks whenever HKCR names
    # another copy of itself, and ours runs out of orig\), and once that is
    # cancelled the handle is dead -- every client rect off it comes back 0x0,
    # the view is never found, and the run dies with `no control ...` or `the
    # save dialog did not come up`.  Half of one gen.sh run went that way.
    # So: cancel anything modal, then find the frame, and wait for it to lay
    # itself out.
    function Find-Frame {
        $best = [IntPtr]::Zero
        $area = -1
        foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
            if (-not [Jw]::IsWindowVisible($t)) { continue }
            if ([Jw]::Cls($t) -eq '#32770') { continue }
            if ([Jw]::Txt($t) -eq '') { continue }
            $r = New-Object Jw+RECT
            [void][Jw]::GetClientRect($t, [ref]$r)
            if ($r.Right * $r.Bottom -gt $area) {
                $area = $r.Right * $r.Bottom
                $best = $t
            }
        }
        return $best
    }
    $frame = [IntPtr]::Zero
    $deadline = (Get-Date).AddSeconds(30)
    while ($true) {
        if ((Get-Date) -gt $deadline) { throw 'the frame never laid itself out' }
        $modal = [IntPtr]::Zero
        foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
            if ([Jw]::Cls($t) -ne '#32770' -or -not [Jw]::IsWindowVisible($t)) { continue }
            if ([Jw]::Txt($t) -eq '') { continue }      # the command bar's own
            $modal = $t
        }
        if ($modal -ne [IntPtr]::Zero) {
            Write-Host ("dismissed a dialog at startup: [{0}]" -f [Jw]::Txt($modal))
            [void][Jw]::SendMessageW($modal, 0x0111, [IntPtr]2, [IntPtr]::Zero)  # IDCANCEL
            Start-Sleep -Milliseconds 700
            continue
        }
        $frame = Find-Frame
        if ($frame -ne [IntPtr]::Zero) {
            $fr0 = New-Object Jw+RECT
            [void][Jw]::GetClientRect($frame, [ref]$fr0)
            if ($fr0.Right -gt 0 -and $fr0.Bottom -gt 0) { break }
        }
        Start-Sleep -Milliseconds 300
    }
    [void][Jw]::ShowWindow($frame, 4)                       # SW_SHOWNOACTIVATE
    # Put it at the size docs/ref_*.png were taken at, the way tools/shot.ps1
    # does.  Jw_cad normally comes up at the WindowPos in HKCU, which
    # tools/refenv.sh restores to 1280x800 -- but not always: a few runs came
    # up 1440x745 instead, and the view being a different size moves every
    # paper coordinate the clicks land on.  Setting the size it should already
    # have costs nothing when it is right and fixes it when it is not.
    #
    # It goes in the **bottom right** of the working area, not the top left:
    # whoever is at this machine is working in the top left, and a window
    # that keeps appearing there is in the way.  Nothing here depends on
    # where it sits -- the clicks are posted in client coordinates and the
    # two steps that move the real cursor go through ClientToScreen -- so
    # this is only about staying out of the way.
    $wa = [System.Windows.Forms.Screen]::PrimaryScreen.WorkingArea
    $w = [math]::Min($Width, $wa.Width)
    $h = [math]::Min($Height, $wa.Height)
    [void][Jw]::MoveWindow($frame, $wa.Right - $w, $wa.Bottom - $h,
                           $w, $h, $true)
    # HWND_BOTTOM, no move, no size, no activate
    [void][Jw]::SetWindowPos($frame, [IntPtr]1, 0, 0, 0, 0, 0x0013)
    Start-Sleep -Milliseconds $SettleMs

    # Anything modal that came up on the way in gets キャンセル.  Jw_cad asks
    # about the .jww association whenever HKCR points at another copy of
    # itself (ours runs out of orig\, the association says C:\jww\), and
    # while that dialog is up the frame has not laid itself out -- the view
    # comes back 264x41 and every click lands somewhere else.

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
        # Twice.  The *first* text typed into one of these boxes part way
        # through a command loses its first character -- "20000" arrived as
        # "0000" in 複線's second stage, and an offset of nothing drew the
        # copy on top of the line -- while anything typed after that arrives
        # whole.  Clearing and typing again costs a moment and leaves the
        # box with exactly what was asked for.
        for ($pass = 0; $pass -lt 2; $pass++) {
            [void][Jw]::SendMessageW($e, $EM_SETSEL, [IntPtr]0, [IntPtr](-1))
            for ($i = 0; $i -lt 24; $i++) {
                [void][Jw]::PostMessage($e, $WM_CHAR, [IntPtr]8, [IntPtr]1)
            }
            Start-Sleep -Milliseconds 80
            foreach ($c in $s.ToCharArray()) {
                [void][Jw]::PostMessage($e, $WM_CHAR, [IntPtr][int][char]$c, [IntPtr]1)
                Start-Sleep -Milliseconds 25
            }
            Start-Sleep -Milliseconds 60
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

            '^raw:f,(\d+),(-?\d+),(-?\d+)$' {
                # the same, to the frame -- a key goes through the frame's
                # PreTranslateMessage, and the view never has the focus in a
                # driven session because the clicks are posted, not real
                [void][Jw]::PostMessage($frame, [uint32]$Matches[1],
                                        [IntPtr][int]$Matches[2], [IntPtr][int]$Matches[3])
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

            '^chr:(\d+),(.*)$' {
                # the same, then Enter -- 複線's second stage says
                # 「間隔を入力するか、複写する位置を指示」, and a number typed
                # there without a return is not taken
                $h = Ctl ([int]$Matches[1])
                if ($h -eq [IntPtr]::Zero) { throw "no control $($Matches[1])" }
                Chars $h $Matches[2] -Enter
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

            '^tops$' {
                # every top-level window the original has up: a dialog or a
                # pop-up menu shows here, which is how a status-line pane says
                # what it opened
                foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                    if (-not [Jw]::IsWindowVisible($t)) { continue }
                    Write-Host ('top {0} [{1}] [{2}]' -f $t, [Jw]::Cls($t), [Jw]::Txt($t))
                }
                foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                    foreach ($k in [Jw]::Kids($t)) {
                        if (-not [Jw]::IsWindowVisible($k)) { continue }
                        Write-Host ('  kid {0} id={1} [{2}] [{3}]' -f $k,
                                    [Jw]::GetDlgCtrlID($k), [Jw]::Cls($k), [Jw]::Txt($k))
                    }
                }
                break
            }

            '^sb$' {
                # every pane of the status line, as the original fills it
                $sb = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($frame)) {
                    if ([Jw]::Cls($k) -eq 'msctls_statusbar32') { $sb = $k; break }
                }
                if ($sb -eq [IntPtr]::Zero) { Write-Host 'no status bar'; break }
                $n = [int][Jw]::SendMessageW($sb, 0x0406, [IntPtr]0, [IntPtr]0)
                for ($i = 0; $i -lt $n; $i++) {
                    $t = New-Object System.Text.StringBuilder 512
                    [void][Jw]::SendMessageSb($sb, 0x040D, [IntPtr]$i, $t)
                    Write-Host ('sb {0}: [{1}]' -f $i, $t.ToString())
                }
                break
            }

            '^sb:(-?\d+),(-?\d+)$' {
                # press the status line where it is told, the way a mouse
                # does.  The panes are not windows -- CMyStatusBar hit-tests
                # the click against the pane rectangles itself
                # (FUN_00596cf0) and acts on the release (FUN_005973b0).
                $sx = [int]$Matches[1]
                $sy = [int]$Matches[2]
                $sb = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($frame)) {
                    if ([Jw]::Cls($k) -eq 'msctls_statusbar32') { $sb = $k; break }
                }
                if ($sb -eq [IntPtr]::Zero) { throw 'no status bar' }
                [void][Jw]::PostMessage($sb, 0x0201, [IntPtr]1, (LParam $sx $sy))
                Start-Sleep -Milliseconds $StepMs
                [void][Jw]::PostMessage($sb, 0x0202, [IntPtr]0, (LParam $sx $sy))
                Start-Sleep -Milliseconds $StepMs
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
                #
                # **無ければ黙って先へ進みます。**掃き出しでは一本の起動で
                # 何十も押すので、一つ見つからないだけで残り全部を
                # 取りこぼしていました（連続線 の 1065 がそれ）。
                $h = [IntPtr]::Zero
                for ($try = 0; $try -lt 10; $try++) {
                    $h = Ctl ([int]$Matches[1])
                    if ($h -ne [IntPtr]::Zero) { break }
                    Start-Sleep -Milliseconds 100
                }
                if ($h -eq [IntPtr]::Zero) {
                    Write-Host "no control $($Matches[1])"
                    break
                }
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

            # 「押してあったら押し戻す」。**無ければ何もしません** ——
            # 掃き出しで、保存の直後はバーの部品が一瞬見えなくなることが
            # あって、そこで止まっていました。戻すものが無いのは誤りでは
            # ないので、黙って先へ進みます。
            '^off:(\d+)$' {
                $h = [IntPtr]::Zero
                for ($try = 0; $try -lt 10; $try++) {
                    $h = Ctl ([int]$Matches[1])
                    if ($h -ne [IntPtr]::Zero) { break }
                    Start-Sleep -Milliseconds 100
                }
                if ($h -eq [IntPtr]::Zero) { break }
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

            '^bar:([\d_]+)$' {
                # the same as `bar`, but headed the way tools/mkbars.py reads
                # it -- for the bars a command only puts up part way through
                Emit ('=== command {0}' -f $Matches[1])
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

            # What the dialog's non-client area really is: where Windows
            # puts the visible frame (DWMWA_EXTENDED_FRAME_BOUNDS, 9) as
            # against GetWindowRect, and what WM_NCHITTEST answers over the
            # caption -- which is how the close cross is found without
            # reading the screen.  HTCLOSE is 20, HTCAPTION 2, HTSYSMENU 3.
            #   dlgnc:32944
            '^dlgnc:(b?)(\d+)$' {
                $byButton = $Matches[1] -eq 'b'
                $id = [int]$Matches[2]
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
                $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($dlg, [ref]$r)
                $e = New-Object Jw+RECT
                $rc = [Jw]::DwmGetWindowAttribute($dlg, 9, [ref]$e, 16)
                $c = New-Object Jw+RECT; [void][Jw]::GetClientRect($dlg, [ref]$c)
                $o = [Jw]::ScreenOf($dlg, 0, 0)
                $w = $r.Right - $r.Left; $hh = $r.Bottom - $r.Top
                Emit ('=== nc {0} window {1}x{2} at {3},{4}' -f $id, $w, $hh, $r.Left, $r.Top)
                Emit ('    visible hr={0} {1}x{2}  inset l={3} t={4} r={5} b={6}' -f `
                    $rc, ($e.Right - $e.Left), ($e.Bottom - $e.Top),
                    ($e.Left - $r.Left), ($e.Top - $r.Top),
                    ($r.Right - $e.Right), ($r.Bottom - $e.Bottom))
                Emit ('    client {0}x{1} at {2},{3} in the window' -f `
                    $c.Right, $c.Bottom, ($o.X - $r.Left), ($o.Y - $r.Top))
                $box = @{}
                for ($yy = 0; $yy -lt $hh; $yy++) {
                    if ($yy -ge 40 -and $yy -lt $hh - 12 -and ($yy % 8) -ne 0) { continue }
                    for ($xx = 0; $xx -lt $w; $xx++) {
                        if ($yy -ge 40 -and $xx -ge 12 -and $xx -lt $w - 12 -and ($xx % 8) -ne 0) { continue }
                        $lp = [IntPtr]((((($r.Top + $yy) -band 0xffff) -shl 16) -bor (($r.Left + $xx) -band 0xffff)))
                        $k = [int][Jw]::SendMessageW($dlg, 0x0084, [IntPtr]::Zero, $lp)
                        if (-not $box.ContainsKey($k)) { $box[$k] = @($xx, $yy, $xx, $yy) }
                        else {
                            $b = $box[$k]
                            if ($xx -lt $b[0]) { $b[0] = $xx }
                            if ($yy -lt $b[1]) { $b[1] = $yy }
                            if ($xx -gt $b[2]) { $b[2] = $xx }
                            if ($yy -gt $b[3]) { $b[3] = $yy }
                            $box[$k] = $b
                        }
                    }
                }
                foreach ($k in ($box.Keys | Sort-Object)) {
                    $b = $box[$k]
                    Emit ('    HT {0,3}  x {1}..{2}  y {3}..{4}' -f $k, $b[0], $b[2], $b[1], $b[3])
                }
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]2, [IntPtr]::Zero)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # The dialog as it really is on the screen, frame and all,
            # four pixels wider each way than GetWindowRect.  This one does
            # read the screen -- there is no other way to see the pixel DWM
            # draws -- so it is only for the frame question.
            #   dlgshot:32944,tmp/nc_shakudo.png
            '^dlgshot:(\d+),(.+)$' {
                $id  = [int]$Matches[1]
                $png = $Matches[2]
                $before = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$id, [IntPtr]::Zero)
                NewDialog $before
                $dlg = $script:dlg
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw "no dialog came up for $id" }
                Start-Sleep -Milliseconds 900
                $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($dlg, [ref]$r)
                $q = New-Object Jw+RECT
                $q.Left = $r.Left - 4; $q.Top = $r.Top - 4
                $q.Right = $r.Right + 4; $q.Bottom = $r.Bottom + 4
                $b = [Jw]::Shot($q)
                $b.Save((Join-Path (Get-Location) $png),
                        [System.Drawing.Imaging.ImageFormat]::Png)
                $b.Dispose()
                Emit ('=== shot {0} window {1}x{2}, the png is 4 px wider each way' -f `
                    $id, ($r.Right - $r.Left), ($r.Bottom - $r.Top))
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]2, [IntPtr]::Zero)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # Open a dialog, click a spot inside one of its controls, and
            # then read it -- which is how the 基本設定 tabs past the first
            # are reached: the original does not build a tab's controls
            # until it is shown.
            #   dlgat:32891,docs/ref_kihon2.png,12320,77,10
            '^dlgat:(\d+),([^,]+),(\d+),(\d+),(\d+)$' {
                $id  = [int]$Matches[1]
                $png = $Matches[2]
                $cid = [int]$Matches[3]
                $cx  = [int]$Matches[4]
                $cy  = [int]$Matches[5]
                $before = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$id, [IntPtr]::Zero)
                NewDialog $before
                $dlg = $script:dlg
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw "no dialog came up for $id" }
                Start-Sleep -Milliseconds 700
                $box = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($dlg)) {
                    if ([Jw]::GetDlgCtrlID($k) -eq $cid) { $box = $k; break }
                }
                if ($box -eq [IntPtr]::Zero) { throw "no control $cid in the dialog" }
                Click $box $cx $cy $false $false
                Start-Sleep -Milliseconds 700
                $b = [Jw]::Paint($dlg)
                $b.Save((Join-Path (Get-Location) $png),
                        [System.Drawing.Imaging.ImageFormat]::Png)
                $b.Dispose()
                $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($dlg, [ref]$r)
                $c = New-Object Jw+RECT; [void][Jw]::GetClientRect($dlg, [ref]$c)
                Emit ('=== dialog {0} window {1}x{2} client {3}x{4}' -f `
                    $id, ($r.Right - $r.Left), ($r.Bottom - $r.Top),
                    $c.Right, $c.Bottom)
                Dump $dlg
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]2, [IntPtr]::Zero)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # Open a dialog, click a spot inside one of its controls (to
            # reach a property-sheet page), press one of its buttons, and
            # then read **the dialog that button puts up** -- a dialog on
            # top of a dialog, which is how 基本設定 の 色・画面 の 色１
            # reaches the colour picker.
            #   dlgsub:32891,tmp/sub.png,12320,128,10,1059
            # The tab part is skipped with a control id of 0.
            '^dlgsub:(\d+),([^,]+),(\d+),(-?\d+),(-?\d+),(\d+)$' {
                $id  = [int]$Matches[1]
                $png = $Matches[2]
                $cid = [int]$Matches[3]
                $cx  = [int]$Matches[4]
                $cy  = [int]$Matches[5]
                $bid = [int]$Matches[6]
                $before = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$id, [IntPtr]::Zero)
                NewDialog $before
                $outer = $script:dlg
                if ($outer -eq [IntPtr]::Zero) { Tops2; throw "no dialog came up for $id" }
                Start-Sleep -Milliseconds 700
                if ($cid -ne 0) {
                    $box = [IntPtr]::Zero
                    foreach ($k in [Jw]::Kids($outer)) {
                        if ([Jw]::GetDlgCtrlID($k) -eq $cid) { $box = $k; break }
                    }
                    if ($box -eq [IntPtr]::Zero) { throw "no control $cid in the dialog" }
                    Click $box $cx $cy $false $false
                    Start-Sleep -Milliseconds 700
                }
                # the button lives on the page, which is a child dialog, so
                # look for it all the way down
                $btn = [IntPtr]::Zero
                $stack = New-Object System.Collections.Stack
                $stack.Push($outer)
                while ($stack.Count -gt 0 -and $btn -eq [IntPtr]::Zero) {
                    $w = $stack.Pop()
                    foreach ($k in [Jw]::Kids($w)) {
                        if ([Jw]::GetDlgCtrlID($k) -eq $bid) { $btn = $k; break }
                        $stack.Push($k)
                    }
                }
                if ($btn -eq [IntPtr]::Zero) { Dump $outer; throw "no button $bid" }
                $seen = [Jw]::Tops([uint32]$p.Id)
                Click $btn 5 5 $false $false
                NewDialog $seen
                $sub = $script:dlg
                if ($sub -eq [IntPtr]::Zero) { Tops2; throw "button $bid put nothing up" }
                Start-Sleep -Milliseconds 700
                $b = [Jw]::Paint($sub)
                $b.Save((Join-Path (Get-Location) $png),
                        [System.Drawing.Imaging.ImageFormat]::Png)
                $b.Dispose()
                $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($sub, [ref]$r)
                $c = New-Object Jw+RECT; [void][Jw]::GetClientRect($sub, [ref]$c)
                Emit ('=== sub dialog of {0} button {1} class "{2}" title "{3}" window {4}x{5} client {6}x{7}' -f `
                    $id, $bid, [Jw]::Cls($sub), [Jw]::Txt($sub),
                    ($r.Right - $r.Left), ($r.Bottom - $r.Top),
                    $c.Right, $c.Bottom)
                Dump $sub
                [void][Jw]::SendMessageW($sub, $WM_COMMAND, [IntPtr]2, [IntPtr]::Zero)
                Start-Sleep -Milliseconds 400
                [void][Jw]::SendMessageW($outer, $WM_COMMAND, [IntPtr]2, [IntPtr]::Zero)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # Press a spot inside the dialog that is already up, by its
            # position in the dialog's client area.  The 建具 and 図形
            # choosers lay their panes out as child windows that all carry
            # id 1, so `Ctl` cannot tell them apart -- this walks down to
            # the deepest child at that point and clicks it.
            #   dlgpos:300,60
            '^dlgpos(R?)(L?L?):(-?\d+),(-?\d+)$' {
                $realc = $Matches[1] -eq 'R'
                $dbl = $Matches[2] -eq 'LL'
                $cx = [int]$Matches[3]
                $cy = [int]$Matches[4]
                $dlg = [IntPtr]::Zero
                foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                    if (-not [Jw]::IsWindowVisible($t)) { continue }
                    if ([Jw]::Cls($t) -ne '#32770') { continue }
                    $dlg = $t; break
                }
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'no dialog is up' }
                # the deepest child whose rectangle holds the point
                $h = $dlg
                $hx = $cx
                $hy = $cy
                for ($depth = 0; $depth -lt 8; $depth++) {
                    $next = [IntPtr]::Zero
                    foreach ($k in [Jw]::Kids($h)) {
                        if (-not [Jw]::IsWindowVisible($k)) { continue }
                        $r = [Jw]::RectIn($k, $h)
                        if ($hx -ge $r.Left -and $hx -lt $r.Right -and
                            $hy -ge $r.Top  -and $hy -lt $r.Bottom) {
                            $next = $k
                            $nx = $hx - $r.Left
                            $ny = $hy - $r.Top
                            break
                        }
                    }
                    if ($next -eq [IntPtr]::Zero) { break }
                    $h = $next; $hx = $nx; $hy = $ny
                }
                Emit ('=== dlgpos {0},{1} -> {2} [{3}] at {4},{5}' -f `
                    $cx, $cy, $h, [Jw]::Cls($h), $hx, $hy)
                Click $h $hx $hy $false $realc
                if ($dbl) {
                    # a chooser pane wants a double click: the second
                    # press has to be a real WM_LBUTTONDBLCLK
                    $l2 = LParam $hx $hy
                    [void][Jw]::PostMessage($h, 0x0203, [IntPtr]1, $l2)
                    [void][Jw]::PostMessage($h, 0x0202, [IntPtr]0, $l2)
                    Start-Sleep -Milliseconds 200
                }
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # Send keys to one control of the dialog that is up, by its
            # window class.  The 建具 chooser's tree takes no posted
            # click, so this walks it with the arrow keys instead.
            #   dlgvk:SysTreeView32,40,9      VK_DOWN nine times
            '^dlgvk:([A-Za-z0-9_]+),(\d+),(\d+)$' {
                $cls = $Matches[1]
                $vk  = [int]$Matches[2]
                $rep = [int]$Matches[3]
                $dlg = [IntPtr]::Zero
                foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                    if (-not [Jw]::IsWindowVisible($t)) { continue }
                    if ([Jw]::Cls($t) -ne '#32770') { continue }
                    $dlg = $t; break
                }
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'no dialog is up' }
                $h = [IntPtr]::Zero
                $stack = New-Object System.Collections.Stack
                $stack.Push($dlg)
                while ($stack.Count -gt 0 -and $h -eq [IntPtr]::Zero) {
                    $w = $stack.Pop()
                    foreach ($k in [Jw]::Kids($w)) {
                        if ([Jw]::Cls($k) -eq $cls) { $h = $k; break }
                        $stack.Push($k)
                    }
                }
                if ($h -eq [IntPtr]::Zero) { throw "no $cls in the dialog" }
                for ($i = 0; $i -lt $rep; $i++) {
                    [void][Jw]::PostMessage($h, 0x0100, [IntPtr]$vk, [IntPtr]1)
                    [void][Jw]::PostMessage($h, 0x0101, [IntPtr]$vk, [IntPtr]1)
                    Start-Sleep -Milliseconds 90
                }
                Emit ('=== dlgvk {0} vk={1} x{2}' -f $cls, $vk, $rep)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # Close whatever modal window is up, if any.  A bar button
            # like 寸法 の 設定 (1071) puts one up, and the rest of the
            # run then has nowhere to go -- this gets back to the frame.
            # Does nothing when no window is up.
            '^dlgoff$' {
                $shut = 0
                for ($try = 0; $try -lt 12; $try++) {
                    $any = [IntPtr]::Zero
                    foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                        if ($t -eq $frame) { continue }
                        if (-not [Jw]::IsWindowVisible($t)) { continue }
                        if ([Jw]::Cls($t) -ne '#32770') { continue }
                        $any = $t; break
                    }
                    if ($any -eq [IntPtr]::Zero) { break }
                    [void][Jw]::PostMessage($any, $WM_COMMAND, [IntPtr]2, [IntPtr]::Zero)
                    $shut++
                    Start-Sleep -Milliseconds 250
                }
                if ($shut) { Emit ('=== dlgoff shut {0}' -f $shut) }
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # Open a dialog, type into some of its boxes and press OK.
            #   dlgin:b1843,1491=30,1492=40,1493=2
            # A value of ! presses the control instead, for a checkbox:
            #   dlgin:b1069,1804=!
            # and #n picks the nth row of a combo box:
            #   dlgin:b1843,2358=#3
            # The leading b means the id is a button to press rather than a
            # command to send.  The text goes in as real WM_CHARs after the
            # box is selected whole, because Jw_cad keeps its own copy of
            # what a box holds and only updates it as the keys arrive --
            # WM_SETTEXT alone leaves the command using the old value.
            '^dlgin:(b?)(\d+),(.+)$' {
                $byButton = $Matches[1] -eq 'b'
                $id = [int]$Matches[2]
                $sets = $Matches[3] -split ','
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
                foreach ($set in $sets) {
                    if ($set -notmatch '^(\d+)=(.*)$') { continue }
                    $cid = [int]$Matches[1]
                    $txt = $Matches[2]
                    $box = [IntPtr]::Zero
                    foreach ($k in [Jw]::Kids($dlg)) {
                        if ([Jw]::GetDlgCtrlID($k) -eq $cid) { $box = $k; break }
                    }
                    if ($box -eq [IntPtr]::Zero) { throw "no control $cid in the dialog" }
                    # a lone ! means press it rather than type into it, which
                    # is how a checkbox or a radio in a dialog is worked
                    if ($txt -eq '!') {
                        [void][Jw]::PostMessage($box, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                        Start-Sleep -Milliseconds 200
                    } elseif ($txt -match '^#(\d+)$') {
                        # a combo: pick that row and tell the dialog, which
                        # is what Windows does when the user picks one
                        $row = [int]$Matches[1]
                        [void][Jw]::SendMessageW($box, 0x014E, [IntPtr]$row, [IntPtr]::Zero)   # CB_SETCURSEL
                        $wp = ($cid -band 0xffff) -bor (1 -shl 16)                              # CBN_SELCHANGE
                        [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]$wp, $box)
                        Start-Sleep -Milliseconds 200
                    } else {
                        [void][Jw]::SetFocus($box)
                        [void][Jw]::SendMessageW($box, 0x00B1, [IntPtr]0, [IntPtr](-1))  # EM_SETSEL
                        Start-Sleep -Milliseconds 80
                        Chars $box $txt
                    }
                }
                Start-Sleep -Milliseconds 200
                Emit ('=== dialog {0} filled' -f $id)
                Dump $dlg
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]1, [IntPtr]::Zero)   # IDOK
                Start-Sleep -Milliseconds $StepMs
                break
            }

            # The same as dlgin:, but finished with the close cross
            # instead of OK -- which is how "does the X apply or cancel?"
            # is asked of the original.
            #   dlgx:32944,1470=5
            '^dlgx:(b?)(\d+),(.+)$' {
                $byButton = $Matches[1] -eq 'b'
                $id = [int]$Matches[2]
                $sets = $Matches[3] -split ','
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
                foreach ($set in $sets) {
                    if ($set -notmatch '^(\d+)=(.*)$') { continue }
                    $cid = [int]$Matches[1]
                    $txt = $Matches[2]
                    $box = [IntPtr]::Zero
                    foreach ($k in [Jw]::Kids($dlg)) {
                        if ([Jw]::GetDlgCtrlID($k) -eq $cid) { $box = $k; break }
                    }
                    if ($box -eq [IntPtr]::Zero) { throw "no control $cid in the dialog" }
                    # a lone ! means press it rather than type into it, which
                    # is how a checkbox or a radio in a dialog is worked
                    if ($txt -eq '!') {
                        [void][Jw]::PostMessage($box, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                        Start-Sleep -Milliseconds 200
                    } elseif ($txt -match '^#(\d+)$') {
                        # a combo: pick that row and tell the dialog, which
                        # is what Windows does when the user picks one
                        $row = [int]$Matches[1]
                        [void][Jw]::SendMessageW($box, 0x014E, [IntPtr]$row, [IntPtr]::Zero)   # CB_SETCURSEL
                        $wp = ($cid -band 0xffff) -bor (1 -shl 16)                              # CBN_SELCHANGE
                        [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]$wp, $box)
                        Start-Sleep -Milliseconds 200
                    } else {
                        [void][Jw]::SetFocus($box)
                        [void][Jw]::SendMessageW($box, 0x00B1, [IntPtr]0, [IntPtr](-1))  # EM_SETSEL
                        Start-Sleep -Milliseconds 80
                        Chars $box $txt
                    }
                }
                Start-Sleep -Milliseconds 200
                Emit ('=== dialog {0} filled' -f $id)
                # Press the close cross the way a mouse does: find it with
                # WM_NCHITTEST (HTCLOSE = 20) and send the non-client
                # button down and up there.
                $r = New-Object Jw+RECT; [void][Jw]::GetWindowRect($dlg, [ref]$r)
                $hit = $null
                for ($yy = 8; $yy -lt 30 -and $hit -eq $null; $yy++) {
                    for ($xx = ($r.Right - $r.Left) - 30; $xx -lt ($r.Right - $r.Left) - 10; $xx++) {
                        $lp = [IntPtr]((((($r.Top + $yy) -band 0xffff) -shl 16) -bor (($r.Left + $xx) -band 0xffff)))
                        if ([int][Jw]::SendMessageW($dlg, 0x0084, [IntPtr]::Zero, $lp) -eq 20) {
                            $hit = $lp; break
                        }
                    }
                }
                if ($hit -eq $null) { throw "no close box on dialog $id" }
                [void][Jw]::PostMessage($dlg, 0x00A1, [IntPtr]20, $hit)   # WM_NCLBUTTONDOWN
                Start-Sleep -Milliseconds 120
                [void][Jw]::PostMessage($dlg, 0x00A2, [IntPtr]20, $hit)   # WM_NCLBUTTONUP
                Start-Sleep -Milliseconds 400
                Emit ('=== the cross was pressed; the dialog is {0}' -f `
                    $(if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) { 'still up' } else { 'gone' }))
                if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) {
                    # DefWindowProc tracks the press with a loop of its own
                    # that wants real mouse input, so a posted button up can
                    # go unseen.  SC_CLOSE is what that loop ends up sending.
                    [void][Jw]::SendMessageW($dlg, 0x0112, [IntPtr]0xF060, $hit)   # WM_SYSCOMMAND
                    Start-Sleep -Milliseconds 400
                    Emit ('=== SC_CLOSE sent; the dialog is {0}' -f `
                        $(if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) { 'still up' } else { 'gone' }))
                }
                if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) {
                    [void][Jw]::SendMessageW($dlg, 0x0010, [IntPtr]::Zero, [IntPtr]::Zero)   # WM_CLOSE
                    Start-Sleep -Milliseconds 400
                    Emit ('=== WM_CLOSE sent; the dialog is {0}' -f `
                        $(if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) { 'still up' } else { 'gone' }))
                }
                if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) {
                    # Last resort: the real pointer.  Nothing posted gets
                    # the frame to act on its own close box, so this is the
                    # only way to see what a person pressing it would get.
                    $cx = ($hit.ToInt32() -band 0xffff)
                    $cy = (($hit.ToInt32() -shr 16) -band 0xffff)
                    [void][Jw]::SetCursorPos($cx, $cy)
                    Start-Sleep -Milliseconds 200
                    [Jw]::mouse_event(0x0002, 0, 0, 0, [UIntPtr]::Zero)
                    Start-Sleep -Milliseconds 120
                    [Jw]::mouse_event(0x0004, 0, 0, 0, [UIntPtr]::Zero)
                    Start-Sleep -Milliseconds 500
                    Emit ('=== the pointer pressed it; the dialog is {0}' -f `
                        $(if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) { 'still up' } else { 'gone' }))
                }
                Start-Sleep -Milliseconds $StepMs
                break
            }

            '^dlgnow:(.+)$' {
                # The same as dlgin:, but for a dialog that is **already**
                # up -- 属性選択's 指定【線色】指定 puts the 線属性 dialog up
                # when its OK is pressed, and that is where the colour it
                # means is chosen.
                $sets = $Matches[1] -split ','
                $dlg = [IntPtr]::Zero
                foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                    if ($t -eq $frame) { continue }
                    if ([Jw]::Cls($t) -eq '#32770' -and [Jw]::IsWindowVisible($t)) {
                        $dlg = $t
                    }
                }
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'no dialog is up' }
                Start-Sleep -Milliseconds 500
                foreach ($set in $sets) {
                    if ($set -notmatch '^(\d+)=(.*)$') { continue }
                    $cid = [int]$Matches[1]
                    $txt = $Matches[2]
                    $box = [IntPtr]::Zero
                    foreach ($k in [Jw]::Kids($dlg)) {
                        if ([Jw]::GetDlgCtrlID($k) -eq $cid) { $box = $k; break }
                    }
                    if ($box -eq [IntPtr]::Zero) { throw "no control $cid in the dialog" }
                    if ($txt -eq '!') {
                        [void][Jw]::PostMessage($box, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                        Start-Sleep -Milliseconds 200
                    } else {
                        [void][Jw]::SetFocus($box)
                        [void][Jw]::SendMessageW($box, 0x00B1, [IntPtr]0, [IntPtr](-1))
                        Start-Sleep -Milliseconds 80
                        Chars $box $txt
                    }
                }
                Start-Sleep -Milliseconds 200
                Emit '=== the dialog that was up, filled'
                Dump $dlg
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]1, [IntPtr]::Zero)
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

            # Put the real pointer at a screen point.  TrackPopupMenu
            # takes a point from the program, so this is how to find out
            # whether a popup follows the cursor.
            #   cursor:800,600
            # Where the view sits now.  The bars can be turned off
            # (59392 ツールバー, 59393 ステータスバー, 32953 ダイアログ
            # ボックス) and then the frame lays itself out again, so this
            # is how to measure what each band was worth.
            #   viewrect
            '^viewrect$' {
                $v2 = [Jw]::Biggest($frame)
                $fc2 = New-Object Jw+RECT
                [void][Jw]::GetClientRect($frame, [ref]$fc2)
                $vc2 = New-Object Jw+RECT
                [void][Jw]::GetClientRect($v2, [ref]$vc2)
                $vr2 = [Jw]::RectIn($v2, $frame)
                Emit ('=== view {0}x{1} at {2},{3} in a frame of {4}x{5}' -f `
                    $vc2.Right, $vc2.Bottom, $vr2.Left, $vr2.Top,
                    $fc2.Right, $fc2.Bottom)
                break
            }

            '^cursor:(\d+),(\d+)$' {
                [void][Jw]::SetCursorPos([int]$Matches[1], [int]$Matches[2])
                Start-Sleep -Milliseconds 200
                break
            }

            '^popcmd:(\d+),(.+)$' {
                # A command whose answer is a popup menu rather than a
                # dialog -- the status line's 用紙 box (32825) is one.
                # Painted the same way menu: paints the menu bar's.
                $cmdid = [int]$Matches[1]
                $png = $Matches[2]
                $before = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$cmdid, [IntPtr]::Zero)
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
                Emit ('=== popup {0} window {1}x{2} client {3}x{4} at {5},{6} in the frame, {7},{8} on the screen' -f `
                    $Matches[1], ($r.Right - $r.Left), ($r.Bottom - $r.Top),
                    $c.Right, $c.Bottom, $inf.Left, $inf.Top, $r.Left, $r.Top)
                [void][Jw]::PostMessage($pop, 0x0100, [IntPtr]27, [IntPtr]1)     # VK_ESCAPE
                Start-Sleep -Milliseconds 300
                [void][Jw]::PostMessage($frame, 0x0100, [IntPtr]27, [IntPtr]1)
                Start-Sleep -Milliseconds $StepMs
                break
            }

            '^import:(b?)(\d+),(.+)$' {
                # Open a file of another kind: 32960 is DXFファイルを開く,
                # 32975 SFCファイルを開く, 32809 JWCファイルを開く.  The same
                # common dialog as saveas:, without the overwrite question.
                $byButton = $Matches[1] -eq 'b'
                $cmdid = [int]$Matches[2]
                $full = [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $Matches[3]))
                if (-not (Test-Path $full)) { throw "import: $full is not there" }
                $before = [Jw]::Tops([uint32]$p.Id)
                if ($byButton) {
                    $h = Ctl $cmdid
                    if ($h -eq [IntPtr]::Zero) { throw "no button $cmdid" }
                    [void][Jw]::PostMessage($h, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                } else {
                    [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$cmdid, [IntPtr]::Zero)
                }
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

            '^figin:(b?)(\d+),(.+)$' {
                # Jw_cad's own file window, not a common dialog: 1110x640,
                # a folder tree on the left and the figures drawn into the
                # right by the window itself.  Nothing there answers a
                # posted click, but the wide Edit at the top (1487) takes a
                # path, and OK then opens it.
                # The folder was pointed at the figure before the launch (see
                # above), so the window opens on it.  The figures themselves
                # are drawn into the right-hand pane by the window, and
                # nothing there answers a posted click -- but 「リスト表示」
                # (1323) turns that pane into a plain SysListView32, and a
                # standard control does answer one.  One row, so row 0.
                # A leading b means the id is a bar button to press
                # rather than a command to send -- the hatch bar's 図形
                # (1693) is one of those.
                $byButton = $Matches[1] -eq 'b'
                $cmdid = [int]$Matches[2]
                $before = [Jw]::Tops([uint32]$p.Id)
                if ($byButton) {
                    $h = Ctl $cmdid
                    if ($h -eq [IntPtr]::Zero) { throw "no button $cmdid" }
                    [void][Jw]::PostMessage($h, $BM_CLICK, [IntPtr]::Zero, [IntPtr]::Zero)
                } else {
                    [void][Jw]::PostMessage($frame, $WM_COMMAND, [IntPtr]$cmdid, [IntPtr]::Zero)
                }
                NewDialog $before 10000
                $dlg = $script:dlg
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'the file window did not come up' }
                Start-Sleep -Milliseconds 1200
                $box = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($dlg)) {
                    if ([Jw]::GetDlgCtrlID($k) -eq 1323 -and [Jw]::Cls($k) -eq 'Button') { $box = $k }
                }
                if ($box -eq [IntPtr]::Zero) { throw 'no リスト表示 box in the file window' }
                [void][Jw]::SendMessageW($box, 0x00F5, [IntPtr]::Zero, [IntPtr]::Zero)  # BM_CLICK
                Start-Sleep -Milliseconds 1200
                $lv = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($dlg)) {
                    if ([Jw]::Cls($k) -eq 'SysListView32') { $lv = $k }
                }
                if ($lv -eq [IntPtr]::Zero) { throw 'the file window has no list' }
                $lp = [IntPtr](((8 -shl 16) -bor 40))
                [void][Jw]::PostMessage($lv, $WM_LBUTTONDOWN, [IntPtr]1, $lp)
                Start-Sleep -Milliseconds 150
                [void][Jw]::PostMessage($lv, $WM_LBUTTONUP, [IntPtr]::Zero, $lp)
                Start-Sleep -Milliseconds 200
                [void][Jw]::PostMessage($lv, 0x0203, [IntPtr]1, $lp)    # DBLCLK
                Start-Sleep -Milliseconds 150
                [void][Jw]::PostMessage($lv, $WM_LBUTTONUP, [IntPtr]::Zero, $lp)
                Start-Sleep -Milliseconds 2000
                if ([Jw]::IsWindow($dlg) -and [Jw]::IsWindowVisible($dlg)) {
                    throw 'the file window would not take the figure'
                }
                break
            }

            '^figout:(.+)$' {
                # The 《図形登録》 button is the bar's 1070 at this stage.
                # It puts the file window up; 新規 (2408) there opens a
                # 新規作成 dialog with the name in Edit 1491, and OK writes
                # the .jws.  A posted BM_CLICK on that OK does nothing --
                # the dialog wants the WM_COMMAND itself, the way the file
                # window does.
                # not $out: PowerShell's variables do not mind case, and
                # that is the -Out parameter
                $figTo = [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $Matches[1]))
                $name = [System.IO.Path]::GetFileNameWithoutExtension($figTo)
                $pen = Join-Path (Get-Location) 'tmp\figsel'
                $before = [Jw]::Tops([uint32]$p.Id)
                $b = Ctl 1070
                if ($b -eq [IntPtr]::Zero) { throw 'the bar has no 《図形登録》' }
                [void][Jw]::PostMessage($b, 0x00F5, [IntPtr]::Zero, [IntPtr]::Zero)
                NewDialog $before 10000
                $dlg = $script:dlg
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'the file window did not come up' }
                Start-Sleep -Milliseconds 1200
                $nw = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($dlg)) {
                    if ([Jw]::GetDlgCtrlID($k) -eq 2408) { $nw = $k }
                }
                if ($nw -eq [IntPtr]::Zero) { throw 'no 新規 in the file window' }
                $before2 = [Jw]::Tops([uint32]$p.Id)
                [void][Jw]::PostMessage($nw, 0x00F5, [IntPtr]::Zero, [IntPtr]::Zero)
                NewDialog $before2 10000
                $mk = $script:dlg
                if ($mk -eq [IntPtr]::Zero) { Tops2; throw '新規作成 did not come up' }
                Start-Sleep -Milliseconds 800
                $edit = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($mk)) {
                    if ([Jw]::GetDlgCtrlID($k) -eq 1491) { $edit = $k }
                }
                if ($edit -eq [IntPtr]::Zero) { throw 'no name field in 新規作成' }
                [void][Jw]::SendMessageStr($edit, $WM_SETTEXT, [IntPtr]::Zero, $name)
                Start-Sleep -Milliseconds 300
                [void][Jw]::SendMessageW($mk, $WM_COMMAND, [IntPtr]1, [IntPtr]::Zero)
                Start-Sleep -Milliseconds 2500
                $made = Join-Path $pen "$name.jws"
                if (-not (Test-Path $made)) { throw "figout: $name.jws was not written" }
                Copy-Item $made $figTo -Force
                Write-Host ("wrote {0} ({1:n0} bytes)" -f $Matches[1], (Get-Item $figTo).Length)
                break
            }

            '^savedlg:(.+)$' {
                # Whatever modal file dialog is up now (or comes up in the
                # next few seconds): put this path in its name box and press
                # OK.  Printing goes through one of these -- the printer on
                # this machine is Microsoft Print To PDF, which asks where to
                # put the PDF -- and so does anything else that saves through
                # the shell rather than through Jw_cad's own dialog.
                $name = $Matches[1]
                $full = [System.IO.Path]::GetFullPath((Join-Path (Get-Location) $name))
                $dir = Split-Path -Parent $full
                if ($dir -and -not (Test-Path $dir)) { New-Item -ItemType Directory -Force -Path $dir | Out-Null }
                Remove-Item -LiteralPath $full -Force -ErrorAction SilentlyContinue
                $dlg = [IntPtr]::Zero
                $deadline = (Get-Date).AddSeconds(12)
                while ((Get-Date) -lt $deadline -and $dlg -eq [IntPtr]::Zero) {
                    foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                        if ([Jw]::Cls($t) -ne '#32770') { continue }
                        if (-not [Jw]::IsWindowVisible($t)) { continue }
                        foreach ($k in [Jw]::Kids($t)) {
                            if ([Jw]::Cls($k) -eq 'Edit') { $dlg = $t; break }
                        }
                        if ($dlg -ne [IntPtr]::Zero) { break }
                    }
                    if ($dlg -eq [IntPtr]::Zero) { Start-Sleep -Milliseconds 300 }
                }
                if ($dlg -eq [IntPtr]::Zero) { Tops2; throw 'no file dialog came up' }
                $edit = [IntPtr]::Zero
                foreach ($k in [Jw]::Kids($dlg)) {
                    if ([Jw]::Cls($k) -eq 'Edit') { $edit = $k; break }
                }
                [void][Jw]::SendMessageStr($edit, $WM_SETTEXT, [IntPtr]::Zero, $full)
                Start-Sleep -Milliseconds 300
                [void][Jw]::SendMessageW($dlg, $WM_COMMAND, [IntPtr]1, [IntPtr]::Zero)
                $deadline = (Get-Date).AddSeconds(20)
                while ((Get-Date) -lt $deadline) {
                    Start-Sleep -Milliseconds 400
                    foreach ($t in [Jw]::Tops([uint32]$p.Id)) {
                        if ($t -eq $dlg) { continue }
                        if ([Jw]::Cls($t) -eq '#32770' -and [Jw]::IsWindowVisible($t)) {
                            [void][Jw]::SendMessageW($t, $WM_COMMAND, [IntPtr]6, [IntPtr]::Zero)
                        }
                    }
                    if (Test-Path $full) { break }
                }
                Start-Sleep -Milliseconds 800
                if (Test-Path $full) {
                    Write-Host ("saved {0} ({1:n0} bytes)" -f $name, (Get-Item $full).Length)
                } else {
                    throw "savedlg: $name was not written"
                }
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

            '^LL(\d+),(\d+)$' {
                # A double click, the way Windows sends one: down, up,
                # WM_LBUTTONDBLCLK, up.  The original's 連 calls it (LL)
                # and uses it for 移動.
                $x = [int]$Matches[1]; $y = [int]$Matches[2]
                $l = LParam $x $y
                [void][Jw]::PostMessage($view, $WM_MOUSEMOVE, [IntPtr]0, $l)
                Start-Sleep -Milliseconds 60
                [void][Jw]::PostMessage($view, $WM_LBUTTONDOWN, [IntPtr]1, $l)
                [void][Jw]::PostMessage($view, $WM_LBUTTONUP, [IntPtr]0, $l)
                Start-Sleep -Milliseconds 30
                [void][Jw]::PostMessage($view, $WM_LBUTTONDBLCLK, [IntPtr]1, $l)
                [void][Jw]::PostMessage($view, $WM_LBUTTONUP, [IntPtr]0, $l)
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
