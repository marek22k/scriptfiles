set jversion=jdk1.8.0_121
set file=HelloWorld











@echo off
title Running java file
color 0a
cls

set path=%ProgramFiles%\Java\%jversion%\bin;%path%

copy %file%.java %temp%\%file%.java > nul

cd %temp%

javac %file%.java
java %file%

pause > nul