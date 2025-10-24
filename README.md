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

Quick Start (using default presets):
# Debug build
cmake --preset default-debug        # Configures debug build
cmake --build --preset default-debug # Builds debug configuration

# Release build
cmake --preset default-release        # Configures release build
cmake --build --preset default-release # Builds release configuration

Platform-Specific Builds:

For Windows:
# Debug build
cmake --preset vcpkg_windows_debug   # Configures debug build with vcpkg and VS2022
cmake --build --preset debug-windows # Builds debug configuration
# Release build
cmake --preset vcpkg_windows_release # Configures release build with vcpkg and VS2022
cmake --build --preset release-windows # Builds release configuration

For Linux:
# Debug build
cmake --preset vcpkg_linux_debug    # Configures debug build with vcpkg
cmake --build --preset debug        # Builds debug configuration
# Release build
cmake --preset vcpkg_linux_release  # Configures release build with vcpkg
cmake --build --preset release      # Builds release configuration

For macOS:
# Debug build
cmake --preset vcpkg_macOS_debug    # Configures debug build with vcpkg and Xcode
cmake --build --preset debug-macos  # Builds debug configuration
# Release build
cmake --preset vcpkg_macOS_release  # Configures release build with vcpkg and Xcode
cmake --build --preset release-macos # Builds release configuration

Notes:
- All presets automatically configure vcpkg with CMAKE_TOOLCHAIN_FILE pointing to ThirdParty/vcpkg/scripts/buildsystems/vcpkg.cmake
- Default presets will automatically select the appropriate configuration for your platform


## Notes
Listing of generators are under
https://docs.conan.io/1/reference/generators.html#generators-reference