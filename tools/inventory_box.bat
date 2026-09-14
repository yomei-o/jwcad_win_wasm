@echo off
:: Re-open the analysed project read-only and dump one CSV row per function.
setlocal
set GHIDRA=C:\prog\ghidra\ghidra_12.1.3_PUBLIC\support\analyzeHeadless.bat
set JAVA_HOME=C:\prog\ghidra\jdk21
set GHIDRA_HEADLESS_MAXMEM=16G
set WORK=C:\prog\jwwin

call "%GHIDRA%" %WORK%\proj jwwin ^
  -process Jw_win.exe -noanalysis -readOnly ^
  -scriptPath %WORK%\ghidra_scripts ^
  -postScript Inventory %WORK%\out\inventory.csv ^
  -log %WORK%\out\inventory.log
echo EXITCODE=%ERRORLEVEL%
