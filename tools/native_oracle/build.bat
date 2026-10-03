@echo off
rem Builds oracle.exe (low priority, one core). Needs the VS 2019 Build Tools and ArkWeb's harness in H:\arkre\harness.
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat" >nul 2>nul || exit /b 1
cd /d "%~dp0"
start "" /low /affinity 1 /wait /b cl /nologo /O2 /EHsc /std:c++17 /W3 /D_CRT_SECURE_NO_WARNINGS /DNOMINMAX oracle.cpp /Feoracle.exe /link /DYNAMICBASE /BASE:0x7FF600000000
