@echo off
set SOURCE_FILES=main.cpp BST.cpp
set PROGRAM_NAME=MockDraft

REM First, go to the 'src' directory
cd src

REM Make the 'output' directory if it's not already there
if NOT EXIST ..\out mkdir ..\out

REM Set some flags for the compiler:
REM could add /WX to make warnings become errors
set WARNING_FLAGS=/W4
REM look, ma, I wrote this thing 25 years ago!
REM Does some simple uninitialized memory and basic stack variable checks
set RUNTIME_CHECK_FLAGS=/RTC1
REM Switch to /O2 (or /O2 /LTCG?) to enable optimization. /Od is for debugging
set OPTIMIZATION_FLAGS=/Od
REM This enables C++ exceptions. The compiler (correctly) whines without it
set LANG_CONFIG_FLAGS=/EHsc

REM compile the code
cl %LANG_CONFIG_FLAGS% %WARNING_FLAGS% %RUNTIME_CHECK_FLAGS% %OPTIMIZATION_FLAGS% %SOURCE_FILES% /Fe..\out\%PROGRAM_NAME%.exe
