# conan_base
Base project for conan package manager

## Conan

### first generate your conan profile, and update your compiler.cppstd to gnu20
```
conan profile detect
```
### then run conan install for both build types

2 cmake presets are then available - conan-debug, conan-release. 

You will need to have cmake installed to compile boost
```
conan install . --build=missing -s build_type=Debug
conan install . --build=missing -s build_type=Release
```
### source the conanbuild.sh to make sure you have the correct cmake available
```
source build/Debug/generators/conanbuild.sh
```

## CMake or IDE

### at this point you could open your IDE, select any of the presets and build. 

But if you want to use cmake, first check you have the correct cmake (3.23.5)
```
$ cmake --version
cmake version 3.23.5
```
### run cmake
```
cmake --preset conan-debug
```
### build
```
cmake --build --preset conan-debug
```
