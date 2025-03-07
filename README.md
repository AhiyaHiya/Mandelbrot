# Mandelbrot
C++ implementation of the Mandelbrot formula.

This project uses CMake for describing how to build the source code.

This is an academic exercise.

This code is useful for where you need to generate an image in a test app.

## CMake setup
This project uses conan 2.0 for package management ( https://docs.conan.io/2/ )

You can use Python3 (`python3 -m pip3`) to install conan.

### Steps

**Set up Python virtual environment**

**For Linux and macOS**
```sh
python3 -m venv venv_1
source venv_1/bin/activate
pip install -r requirements.txt
```

**For Windows**
```sh
"C:\Program Files\Python311\python.exe" -m venv venv_1
venv_1\Scripts\activate.bat
pip install -r requirements.txt
```

**Conan Installation:**

Linux

```sh
conan install . --output-folder=build --build=missing
```

macOS

```sh
conan install ./conan/conanfile.txt --output-folder=build --build=missing --profile:host=conan/macos.txt --profile:build=default
```

**For Windows**

```sh
cmake --preset conan-default
cmake --build ./build --config Release
```

**For Linux**

```sh
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE=build/conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
cmake --build ./build
```


## Notes
For conan 2.0 profile setting options, check under
 - https://docs.conan.io/1/reference/config_files/settings.yml.html

Listing of generators are under
 - https://docs.conan.io/1/reference/generators.html#generators-reference