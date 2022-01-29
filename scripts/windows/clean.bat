@echo off
pushd %~dp0\..\..\

for /R %%f in (Makefile CMakeSettings.json *.sln *.vcxproj.* *.vcxproj) do (
  @IF EXIST "%%f" (
    @echo "Removing %%f"
    del /q "%%f"
  )
)

for /R %%f in (bin lib obj out) do (
  @IF EXIST "%%f" (
    @echo "Removing %%f"
    rmdir /S /Q "%%f"
  )
)

popd

IF %ERRORLEVEL% NEQ 0 (
  pause
) ELSE (
  timeout /t 5
)
