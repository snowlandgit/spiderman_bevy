# cargo_low.ps1 <cargo args...>: runs cargo at below-normal priority with two jobs (this PC is sensitive to load),
# using the project's pinned toolchain. Prints the errors, warnings and the summary.
$ErrorActionPreference = 'Stop'
$root = Resolve-Path (Join-Path $PSScriptRoot '..\..')
Push-Location -LiteralPath $root
try {
    $local = Join-Path $root 'tools/rustup'
    if (Test-Path -LiteralPath (Join-Path $local 'toolchains')) { $env:RUSTUP_HOME = $local }
    $env:CARGO_BUILD_JOBS = '2'
    $out = Join-Path $env:TEMP 'cargo_low.out'
    $err = Join-Path $env:TEMP 'cargo_low.err'
    $p = Start-Process -FilePath cargo -ArgumentList $args -NoNewWindow -PassThru -RedirectStandardOutput $out -RedirectStandardError $err
    try { $p.PriorityClass = 'BelowNormal' } catch {}
    $p.WaitForExit()
    Get-Content -LiteralPath $err | Where-Object { $_ -match 'error|warning|Finished|test result|panicked' -or $_ -match '^\s+-->' }
    Get-Content -LiteralPath $out
    exit $p.ExitCode
} finally { Pop-Location }
