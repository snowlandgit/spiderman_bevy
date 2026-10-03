param([switch]$Rebuild)
$ErrorActionPreference='Stop'
Push-Location -LiteralPath $PSScriptRoot
try {
    $taskPassedTests=$null
    if ($Rebuild) {
        & './Build.ps1'
        $taskTestOutput=& cargo test --locked --message-format=json
        if ($LASTEXITCODE -ne 0) {throw 'Physics tests failed.'}
        $taskTestExecutable=$null
        foreach ($taskLine in $taskTestOutput) {
            if ($taskLine.StartsWith('{')) {
                $taskArtifact=$taskLine | ConvertFrom-Json
                if ($taskArtifact.reason -eq 'compiler-artifact' -and $taskArtifact.target.name -eq 'spiderman_bevy' -and $taskArtifact.profile.test) {
                    $taskTestExecutable=$taskArtifact.executable
                }
            } else {
                Write-Host $taskLine
                if ($taskLine -match 'test result: ok\. (\d+) passed') {$taskPassedTests=[int]$Matches[1]}
            }
        }
        if (!$taskTestExecutable -or !(Test-Path -LiteralPath $taskTestExecutable)) {throw 'Cargo did not identify the physics-test executable.'}
        Copy-Item -LiteralPath $taskTestExecutable -Destination tools/physics_tests.exe -Force
    } else {
        $taskTestResults=& './tools/physics_tests.exe'
        if ($LASTEXITCODE -ne 0) {throw 'Bundled physics tests failed.'}
        foreach ($taskLine in $taskTestResults) {
            Write-Host $taskLine
            if ($taskLine -match 'test result: ok\. (\d+) passed') {$taskPassedTests=[int]$Matches[1]}
        }
    }
    if ($null -eq $taskPassedTests) {throw 'Physics test summary is missing.'}
    & './spiderman_bevy.exe' --physics-report
    if ($LASTEXITCODE -ne 0) {throw 'Trajectory comparison failed.'}
    $env:WGPU_BACKEND='dx12'
    $env:RUST_LOG='warn'
    & './spiderman_bevy.exe' --smoke-test --headless
    if ($LASTEXITCODE -ne 0) {throw 'Rendered traversal failed.'}
    $taskSmokeReport=Get-Content -LiteralPath smoke_report.json -Raw | ConvertFrom-Json
    if (!$taskSmokeReport.passed) {throw 'Rendered traversal report failed.'}
    & './spiderman_bevy.exe' --direction-smoke-test --headless
    if ($LASTEXITCODE -ne 0) {throw 'Rendered direction reversal failed.'}
    $taskDirectionReport=Get-Content -LiteralPath direction_smoke_report.json -Raw | ConvertFrom-Json
    if (!$taskDirectionReport.passed) {throw 'Rendered direction reversal report failed.'}
    & './spiderman_bevy.exe' --zip-smoke-test --headless
    if ($LASTEXITCODE -ne 0) {throw 'Rendered web zip failed.'}
    $taskZipReport=Get-Content -LiteralPath zip_smoke_report.json -Raw | ConvertFrom-Json
    if (!$taskZipReport.passed) {throw 'Rendered web zip report failed.'}
    & './spiderman_bevy.exe' --jump-smoke-test --headless
    if ($LASTEXITCODE -ne 0) {throw 'Rendered charged jumps failed.'}
    $taskJumpReport=Get-Content -LiteralPath jump_smoke_report.json -Raw | ConvertFrom-Json
    if (!$taskJumpReport.passed) {throw 'Rendered charged jump report failed.'}
    $taskPython=Join-Path $env:USERPROFILE '.cache/codex-runtimes/codex-primary-runtime/dependencies/python/python.exe'
    if (!(Test-Path -LiteralPath $taskPython)) {$taskPython='python'}
    & $taskPython tools/validate_assets.py
    if ($LASTEXITCODE -ne 0) {throw 'Asset validation failed.'}
    & $taskPython tools/verify_animation_poses.py
    if ($LASTEXITCODE -ne 0) {throw 'Original animation pose validation failed.'}
    & $taskPython tools/validate_world.py
    if ($LASTEXITCODE -ne 0) {throw 'World asset validation failed.'}
    & $taskPython tools/record_validation.py --tests-passed $taskPassedTests
    if ($LASTEXITCODE -ne 0) {throw 'Validation record failed.'}
} finally {Pop-Location}
