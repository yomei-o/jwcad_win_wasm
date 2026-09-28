@echo off
:: Import a Windows system binary with its public symbols and analyse it.
::
::   analyze_gdi_box.bat <name> [<projdir>]   e.g. win32kfull.sys proj
::
:: The PDB sits next to the binary in bin\ (tools/pdbid.py says where to get
:: it), which is where Ghidra's PDB Universal analyser looks -- so the 8,440
:: functions come out with Microsoft's own names on them.  ARM64, because that
:: is what this machine's Windows is.
setlocal
set GHIDRA=C:\prog\ghidra\ghidra_12.1.3_PUBLIC\support\analyzeHeadless.bat
set JAVA_HOME=C:\prog\ghidra\jdk21
set GHIDRA_HEADLESS_MAXMEM=24G
set WORK=C:\prog\win32k
set NAME=%1
set PROJ=%2
if "%PROJ%"=="" set PROJ=proj

if not exist %WORK%\out mkdir %WORK%\out
call "%GHIDRA%" %WORK%\%PROJ% gdi ^
  -import %WORK%\bin\%NAME% ^
  -processor AARCH64:LE:64:v8A ^
  -analysisTimeoutPerFile 21600 ^
  -log %WORK%\out\analyze.log ^
  -scriptlog %WORK%\out\analyze.script.log
echo EXITCODE=%ERRORLEVEL%
