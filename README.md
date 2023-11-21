# Mandelbrot
C++ implementation of the Mandelbrot formula.

This project uses CMake for describing how to build the source code.

This is an academic exercise.

This code is useful for where you need to generate an image in a test app.

## CMake setup
This project uses conan 2.0 for package management ( https://docs.conan.io/2/ )

You can use Python3 (`python3 -m pip3`) to install conan.

### Steps
conan install . --output-folder=build --build=missing

For Windows
cmake -S . -B build -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake
cmake --build ./build --config Release

For Linux
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build ./build


## Notes
For conan 2.0 profile setting options, check under
https://docs.conan.io/1/reference/config_files/settings.yml.html

Listing of generators are under
https://docs.conan.io/1/reference/generators.html#generators-reference