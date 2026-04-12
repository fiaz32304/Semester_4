# Compile and run linked_list.cpp using available compiler (cl or g++)
# Usage: .\run_linked_list.ps1

$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Path
Set-Location $scriptDir

Write-Host "Working directory: $scriptDir"

# Remove previous exe if exists
if (Test-Path .\linked_list.exe) { Remove-Item .\linked_list.exe -ErrorAction SilentlyContinue }

function Try-Cl {
    $cl = Get-Command cl.exe -ErrorAction SilentlyContinue
    if ($null -ne $cl) {
        Write-Host "Using cl.exe to compile..."
        & cl.exe /EHsc linked_list.cpp
        return $LASTEXITCODE -eq 0
    }
    return $false
}

function Try-Gpp {
    $gpp = Get-Command g++ -ErrorAction SilentlyContinue
    if ($null -ne $gpp) {
        Write-Host "Using g++ to compile..."
        & g++ -std=c++17 linked_list.cpp -o linked_list.exe
        return $LASTEXITCODE -eq 0
    }
    return $false
}

$compiled = $false
if (Try-Cl) { $compiled = $true }
elseif (Try-Gpp) { $compiled = $true }

if (-not $compiled) {
    Write-Host "No supported C++ compiler found in PATH. Install Visual Studio Build Tools (cl) or MinGW (g++)." -ForegroundColor Red
    exit 1
}

# Run the executable
if (Test-Path .\linked_list.exe) {
    Write-Host "Running .\linked_list.exe..."
    & .\linked_list.exe
} else {
    Write-Host "Compilation succeeded but executable not found." -ForegroundColor Yellow
}
