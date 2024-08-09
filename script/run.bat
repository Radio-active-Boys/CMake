@REM Navigate to the build directory
@cd ../build >nul 2>&1

@REM Build the solution with detailed output
@msbuild Code.sln /p:Platform="x64" /p:Configuration=Debug

@REM Check if the build succeeded before proceeding
@IF ERRORLEVEL 1 (
    @echo Build failed
    @exit /b 1
)

@REM Navigate to the Debug directory
@cd Debug >nul 2>&1

@REM Run the executable
@Code
