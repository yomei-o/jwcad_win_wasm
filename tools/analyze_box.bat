@echo off
:: Import Jw_win.exe into a Ghidra project on the build box and run auto-analysis.
:: The project is kept (no -deleteProject): decompiling is a separate, later pass
:: that re-opens it with -process, so the 5.5 MB of .text is only analyzed once.
setlocal
set GHIDRA=C:\prog\ghidra\ghidra_12.1.3_PUBLIC\support\analyzeHeadless.bat
set JAVA_HOME=C:\prog\ghidra\jdk21
set GHIDRA_HEADLESS_MAXMEM=24G
set WORK=C:\prog\jwwin

call "%GHIDRA%" %WORK%\proj jwwin ^
  -import %WORK%\bin\Jw_win.exe ^
  -processor x86:LE:32:default ^
  -analysisTimeoutPerFile 21600 ^
  -log %WORK%\out\analyze.log ^
  -scriptlog %WORK%\out\analyze.script.log
echo EXITCODE=%ERRORLEVEL%
