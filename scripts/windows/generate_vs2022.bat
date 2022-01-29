@echo off
pushd %~dp0\..\..\
CALL cmake -S . -B out -G "Visual Studio 17 2022" --no-warn-unused-cli -A x64
popd

IF %ERRORLEVEL% NEQ 0 (
  pause
) ELSE (
  timeout /t 5
)
