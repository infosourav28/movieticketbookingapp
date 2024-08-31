#!/bin/bash

# Set the build directory name
BUILD_DIR="build"

# Remove the existing build directory if it exists
if [ -d "$BUILD_DIR" ]; then
  rm -rf "$BUILD_DIR"
fi

# Create a new build directory
mkdir "$BUILD_DIR"


#conan install
conan install . -of build --build=missing

#conan build
conan build . -of build

#create conan package
conan export-pkg . --name=movieticketbookingapi --version=0.2 --user=user --channel=channel -of=build


