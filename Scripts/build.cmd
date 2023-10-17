@echo off
chcp 65001

echo script start at: %cd%

REM ###################################
REM #         Config zone             #
REM ###################################

SET PYTHON_DIR=C:\ProgramData\anaconda3\
SET OUTPUT_DIR=Generated

REM ###################################
REM #        Script start             #
REM ###################################

echo Start prebuild script

REM get the current directory
set CURRENT_DIR=%~dp0

for %%F in ("%CURRENT_DIR%\.") do set "PROJ_DIR=%%~dpF"
set OUTPUT_DIR= %PROJ_DIR%\%OUTPUT_DIR%

echo CURRENT_DIR = %CURRENT_DIR%
echo PROJ_DIR    = %PROJ_DIR%
echo OUTPUT_DIR  = %OUTPUT_DIR%


MKDIR %OUTPUT_DIR% >nul 2>&1

REM ###################################
REM #        Generate Version         #
REM ###################################
echo Generate version...
SET AUTO_VERSION_SCRIPT=%PROJ_DIR%Scripts\auto_version.py
SET /p VERSION=<%PROJ_DIR%\VERSION
echo Current version: %VERSION%
%PYTHON_DIR%python %PROJ_DIR%/Scripts/auto_version.py -v %VERSION% -o %OUTPUT_DIR%\version.h
if %ERRORLEVEL% NEQ 0 (
    echo Error: version generation failed!
    exit /b 1
)
echo Version generated.

echo Pre-build script done!
