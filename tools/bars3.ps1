# Read a command bar again with one of its checkboxes ticked.
#
#   powershell -ExecutionPolicy Bypass -File tools/bars3.ps1 `
#       -Pairs '32772:1334,32771:1333' -Out decomp/res/bars3.txt
#   python tools/mkbars.py            # -> src/gen/bars.h
#
# A Jw_cad command bar is not one fixed row of controls: ticking a box can
# take some away and put others there.  矩形's ソリッド is the plain case --
# with it on, 多重 (1417 and its label) go, and (対角線) 1335, 任意色 2553
# and the colour button 2552 arrive.  Without this the port draws the bar it
# was captured in and the rest of the command is unreachable.
#
# The rows come out headed `=== command 2<cmd>_<id>`, which tools/mkbars.py
# files as a variant of that command's bar.
param(
    [string]$Pairs = '',
    [string]$Out   = 'decomp/res/bars3.txt',
    [string]$Exe   = 'orig\Jw_win.exe'
)
$jw = Join-Path $PSScriptRoot 'jwdraw.ps1'
$steps = @()
foreach ($p in ($Pairs -split ',')) {
    if ($p -notmatch '^(\d+):(\d+)$') { continue }
    $cmd = $Matches[1]
    $id  = $Matches[2]
    # enter the command, tick the box, read the bar, untick it again
    $steps += ('cmd:{0};pb:{1};dlgoff;bar:2{0}_{1};pb:{1};dlgoff' -f $cmd, $id)
}
if ($steps.Count -eq 0) { throw 'nothing to do: give -Pairs cmd:id,cmd:id' }
& $jw -Exe $Exe -Open '' -NoSave -Clicks ($steps -join ';') -Out $Out
