# Decompile all of .text on the build box, several shards at a time.
#
# The decompiler is single threaded, so one run over 5.5 MB of .text would use
# one of the box's 20 cores.  Each shard re-opens the same already-analysed
# project read-only (-process -noanalysis -readOnly) and takes a slice of the
# address space, so they do not contend for the project database.
#
#   powershell -ExecutionPolicy Bypass -File C:\prog\jwwin\decomp_box.ps1 [-Shards 8]
param(
    [int]$Shards = 8,
    [string]$Work = 'C:\prog\jwwin',
    # .text of Jw_win.exe: 0x00401000 .. 0x00953f25
    [long]$Lo = 0x00401000,
    [long]$Hi = 0x00954000
)
$ErrorActionPreference = 'Stop'
# The build box's paths are the defaults; another machine sets these in the
# environment before calling.  The JDK is not on PATH on either.
if (-not $env:GHIDRA_HOME) { $env:GHIDRA_HOME = 'C:\prog\ghidra\ghidra_12.1.3_PUBLIC' }
if (-not $env:JAVA_HOME)   { $env:JAVA_HOME   = 'C:\prog\ghidra\jdk21' }
if (-not $env:GHIDRA_HEADLESS_MAXMEM) { $env:GHIDRA_HEADLESS_MAXMEM = '4G' }
$ghidra = Join-Path $env:GHIDRA_HOME 'support\analyzeHeadless.bat'

$out = Join-Path $Work 'out\decomp'
New-Item -ItemType Directory -Force -Path $out | Out-Null

# Ghidra takes an exclusive lock on a project directory even for -readOnly, so
# shards cannot share one: the first wins and the other nine die with
# "Unable to lock project!" while the run still reports DONE.  The analysed
# project is only ~146 MB, so each shard gets its own copy of it.
$projs = @()
for ($i = 0; $i -lt $Shards; $i++) {
    $p = if ($i -eq 0) { Join-Path $Work 'proj' } else { Join-Path $Work "proj$i" }
    if ($i -gt 0) {
        if (Test-Path $p) { Remove-Item $p -Recurse -Force }
        Write-Host "copying project for shard $i ..."
        & robocopy.exe (Join-Path $Work 'proj') $p /E /NFL /NDL /NJH /NJS /NP | Out-Null
    }
    $projs += $p
}

$step = [long][math]::Ceiling(($Hi - $Lo) / $Shards)
$running = @()
for ($i = 0; $i -lt $Shards; $i++) {
    # NOT $lo / $hi: PowerShell variable names are case insensitive, so those
    # would overwrite the $Lo / $Hi parameters and every shard after the first
    # would get a start past its own end.
    $rlo = $Lo + $i * $step
    $rhi = [math]::Min($Lo + ($i + 1) * $step, $Hi)
    $tag = '{0:x8}' -f $rlo
    $log = Join-Path $out "shard_$tag.log"
    $argv = @(
        $projs[$i], 'jwwin',
        '-process', 'Jw_win.exe', '-noanalysis', '-readOnly',
        '-scriptPath', "$Work\ghidra_scripts",
        '-postScript', 'DecompileRange', $out, ('{0:x}' -f $rlo), ('{0:x}' -f $rhi)
    )
    $p = Start-Process -FilePath $ghidra -ArgumentList $argv -NoNewWindow -PassThru `
                       -RedirectStandardOutput $log -RedirectStandardError "$log.err"
    $p.PriorityClass = 'BelowNormal'
    $running += $p
    Write-Host ("started shard {0}  {1:x8}..{2:x8}" -f $i, $rlo, $rhi)
}
while ($running.Count -gt 0) {
    $running = @($running | Where-Object { -not $_.HasExited })
    if ($running.Count -gt 0) { Start-Sleep -Seconds 15 }
}

Write-Host ''
Get-ChildItem $out -Filter 'index_*.csv' | ForEach-Object {
    $n = (Get-Content $_.FullName).Count - 1
    Write-Host ("{0,-22}{1,8} functions" -f $_.Name, $n)
}
$tarball = Join-Path $Work 'decomp.tgz'
Remove-Item $tarball -Force -ErrorAction SilentlyContinue
# Windows' own tar, by full path: a Git Bash tar earlier on PATH reads
# C:\... as a remote host and dies with "Cannot connect to C".
$tar = Join-Path $env:SystemRoot 'System32\tar.exe'
& $tar --force-local -czf $tarball -C $out .
Write-Host ("packed {0} ({1:n0} bytes)" -f $tarball, (Get-Item $tarball).Length)
Write-Host 'DONE'
