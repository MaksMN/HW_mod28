echo off
mkdir .\bin
cls
echo Build...
g++ -std=c++20 %cd%/*.cpp -o %cd%\bin\mergesort.exe
echo Build client complete
pause