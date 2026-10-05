# Read the command bar for each command out of the running original.
#
#   powershell -ExecutionPolicy Bypass -File tools/bars.ps1 `
#       -Cmds '32771,32773,...' -Out decomp/res/bars.txt
#   python tools/mkbars.py            # -> src/gen/bars.h
#
# One launch, each command sent in turn, and after each one the controls of
# the CDialogBar written down in the frame's client coordinates.  Nothing is
# drawn or captured.  The work is all in tools/jwdraw.ps1 -- this is the name
# README.md and RESUME.md call it by.
#
# The default list is every command the port has a bar for (src/cmd.h), plus
# 測定 (32897) and 距離指定点 (32930), which the port is growing one for.  Note
# ２線 is 32892: 32860 is not a command at all and leaves the 線 bar showing.
# The ones that open a window of their own the moment they are entered --
# 図形読込 32862, ブロック編集 32986 and the rest -- are left out: the launch
# is one run through the whole list and a modal dialog would stop it.  A
# command that is not here gets 線's bar drawn for it, which is wrong on the
# screen and wrong to click on, so anything the port grows a bar for belongs
# in this list.
param(
    [string]$Cmds = '32771,32785,32772,32773,32883,32794,32786,32791,32800,32931,32787,32804,32918,32847,32894,32859,32867,32892,32873,32806,32846,32870,32872,32874,32908,32910,32915,32952,32897,32930',
    [string]$Out  = 'decomp/res/bars.txt',
    [string]$Exe  = 'orig\Jw_win.exe'
)
& (Join-Path $PSScriptRoot 'jwdraw.ps1') -Exe $Exe -Open '' -NoSave -Cmds $Cmds -Out $Out
