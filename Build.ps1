$ErrorActionPreference='Stop'
Push-Location -LiteralPath $PSScriptRoot
try {
    $taskLocalRustup=Join-Path $PSScriptRoot 'tools/rustup'
    if (Test-Path -LiteralPath (Join-Path $taskLocalRustup 'toolchains/1.99.0-x86_64-pc-windows-msvc/bin/rustc.exe')) {
        $env:RUSTUP_HOME=$taskLocalRustup
    }
    cargo build --locked
    if ($LASTEXITCODE -ne 0) {throw 'Cargo build failed.'}
    Copy-Item -LiteralPath target/debug/spiderman_bevy.exe -Destination spiderman_bevy.exe -Force
    Write-Host 'Ready: Play.bat'
} finally {Pop-Location}
