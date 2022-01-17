@echo off
pushd %~dp0\..\..\
CALL vendor\premake\windows\premake5.exe vs2022
popd

IF %ERRORLEVEL% NEQ 0 (
  pause
) ELSE (
  timeout /t 5
)
