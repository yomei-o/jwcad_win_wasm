# Read a command bar again after each of its steps.
#
#   powershell -ExecutionPolicy Bypass -File tools/bars4.ps1 `
#       -Cmds '32771,32772,32773' -Out decomp/res/bars4.txt
#   python tools/mkbars.py            # -> src/gen/bars.h
#
# A command is not one bar either: 複写 puts up a different one once a range
# is settled (tools/bars2.ps1 has that one), and others change as the points
# go down.  This walks each command through four clicks on the drawing and
# writes the bar down after every one, so the port can put up what the
# original puts up at that point rather than the bar it was entered with.
#
# The rows come out headed `=== command 3<cmd>_<step>`.
#
# The clicks land on the drawing that is open (orig/Test5.jww), so the ones
# that want to pick something have something to pick.
param(
    [string]$Cmds = '',
    [string]$Out  = 'decomp/res/bars4.txt',
    [string]$Exe  = 'orig\Jw_win.exe',
    [int]$Npoints = 4
)
$jw = Join-Path $PSScriptRoot 'jwdraw.ps1'
$pts = @('500,400', '620,470', '560,330', '700,520')
$steps = @()
foreach ($c in ($Cmds -split ',')) {
    if ($c -notmatch '^\d+$') { continue }
    $steps += ('cmd:{0};bar:3{0}_0' -f $c)
    for ($i = 0; $i -lt $Npoints; $i++) {
        $steps += ('{0};bar:3{1}_{2}' -f $pts[$i], $c, ($i + 1))
    }
    # and back to a clean state for the next command
    $steps += ('cmd:{0}' -f $c)
}
if ($steps.Count -eq 0) { throw 'nothing to do: give -Cmds 32771,32772' }
Copy-Item 'orig\Test5.jww' 'tmp\bars4.jww' -Force
& $jw -Exe $Exe -Open 'tmp\bars4.jww' -NoSave -Clicks ($steps -join ';') -Out $Out
