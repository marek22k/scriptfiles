@echo off

:: A script from www.hundert-prozent.net

title List all files

for /R \ %%f in (*) do (
  echo File: %%f
)

pause > nul
exit