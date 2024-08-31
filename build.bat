@echo off
setlocal

:: Set the build directory name
set BUILD_DIR=build

:: Remove the existing build directory if it exists
if exist "%BUILD_DIR%" (
    rd /s /q "%BUILD_DIR%"
)

:: Create a new build directory
mkdir "%BUILD_DIR%"

:: Conan install
conan install . --output-folder=%BUILD_DIR% --build=missing

:: Conan build
conan build . --output-folder=%BUILD_DIR%

:: Create Conan package
conan export-pkg . --name=movieticketbookingapi --version=0.2 --user=user --channel=channel --output-folder=%BUILD_DIR%

endlocal
