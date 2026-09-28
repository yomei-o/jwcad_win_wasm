@echo off
:: Decompile the handful of functions worth reading out of an already-analysed
:: system binary.
::
::   decomp_gdi_box.bat <binary> <projdir> <out.c> <pattern> ...
::
:: Re-opens the project read-only with -process, the way decomp_box.ps1 does,
:: so the analysis is not redone.
setlocal enabledelayedexpansion
set GHIDRA=C:\prog\ghidra\ghidra_12.1.3_PUBLIC\support\analyzeHeadless.bat
set JAVA_HOME=C:\prog\ghidra\jdk21
set GHIDRA_HEADLESS_MAXMEM=8G
set WORK=C:\prog\win32k
set NAME=%1
shift
set PROJ=%1
shift
set OUT=%1
shift
set PATS=
:loop
if "%1"=="" goto done
set PATS=!PATS! %1
shift
goto loop
:done

call "%GHIDRA%" %WORK%\!PROJ! gdi ^
  -process !NAME! ^
  -noanalysis -readOnly ^
  -scriptPath %WORK%\ghidra_scripts ^
  -postScript DecompileNamed %WORK%\out\!OUT! !PATS! ^
  -scriptlog %WORK%\out\decomp.script.log
echo EXITCODE=%ERRORLEVEL%
