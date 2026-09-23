# Read the command bar 複写 or 移動 puts up **after** a range is settled,
# which tools/bars.ps1 cannot reach: it only sends the command.
#
#   powershell -ExecutionPolicy Bypass -File tools/bars2.ps1 `
#       -Cmd 32804 -Out tmp\bar2a.txt
#   cat tmp\bar2a.txt tmp\bar2b.txt > decomp/res/bars2.txt
#   python tools/mkbars.py            # -> src/gen/bars.h
#
# The rows come out headed `=== command 1<cmd>` -- the same command with a 1
# in front -- so mkbars.py can put them in the same table and the port can
# look the second stage up by it.
#
# A rectangle is drawn first because the range has to take something: with
# nothing picked 選択確定 stays grey and the bar never changes.  One command
# per run: after the first one the command is still holding a copy, and the
# next one's clicks do not land where they should.
param(
    [int]$Cmd    = 32804,
    [string]$Out = 'tmp\bar2.txt',
    [string]$Exe = 'orig\Jw_win.exe'
)
$jw = Join-Path $PSScriptRoot 'jwdraw.ps1'
$blank = 'tmp\blank2.jww'
Copy-Item 'decomp/res/new.jww' $blank -Force
$clicks = ('300,300;500,400;cmd:{0};250,250;550,450;m400,350;btn:1120;bar:1{0}' -f $Cmd)
& $jw -Exe $Exe -Open $blank -Cmd 32772 -NoSave -Clicks $clicks -Out $Out
