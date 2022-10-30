# conan_base
Base project for conan package manager

### first run cmake
```
cmake -Bbuild
```
### then build
```
cmake --build build/
```

## for vscode

Update the path for `conanbuildinfo.cmake` in `CMakeLists.txt`, line 23

```
include(${CMAKE_HOME_DIRECTORY}/build/conanbuildinfo.cmake)
```
