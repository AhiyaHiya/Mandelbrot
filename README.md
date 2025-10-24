# Mandelbrot
C++ implementation of the Mandelbrot formula.

This project uses CMake for describing how to build the source code.

This is an academic exercise.

This code is useful for where you need to generate an image in a test app.

## CMake setup
This project uses vcpkg for package management. The ThirdParty folder contains vcpkg as a submodule
and leverages the scripts in there to set up the appropriate CMake files.

### Steps
git submodule update --init --recursive

For Windows
cmake -S . -B build -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build ./build --config Release

For Linux
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build ./build


## Notes
Listing of generators are under
https://docs.conan.io/1/reference/generators.html#generators-reference