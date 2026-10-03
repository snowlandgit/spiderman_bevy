@echo off
cd /d "%~dp0"
set WGPU_BACKEND=dx12
set RUST_LOG=warn
spiderman_bevy.exe
