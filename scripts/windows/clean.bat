@echo off
pushd %~dp0\..\..\

for /R %%f in (Makefile *.sln *.vcxproj.* *.vcxproj) do (
  @IF EXIST "%%f" (
    @echo "Removing %%f"
    del /q "%%f"
  )
)

for /R %%f in (.vs _bin _obj) do (
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
