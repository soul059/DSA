@echo off
g++ -g %1 -o %2
if %errorlevel% neq 0 exit /b %errorlevel%
%2 < input.txt > output.txt
