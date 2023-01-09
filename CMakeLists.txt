cmake_minimum_required(VERSION 3.9.1)
project(BasicProject)
set(CMAKE_CXX_STANDARD 17)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColorReset "${Esc}[m")
  set(Red         "${Esc}[31m")
  set(Yellow      "${Esc}[33m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldYellow  "${Esc}[1;33m")
endif()

if((NOT CMAKE_BUILD_TYPE) OR (${CMAKE_BUILD_TYPE} MATCHES Debug))
    message("${BoldYellow} Debug Build ${ColorReset}")
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    message("${BoldRed} Release Build ${ColorReset}")
endif()

# Mac install using Homebrew, Windows with Msys2, Unix using Conda
if ((${CMAKE_HOST_SYSTEM_NAME} MATCHES "Windows") OR (${CMAKE_HOST_SYSTEM_NAME} MATCHES "Darwin"))
    set(CONAN_COMMAND "conan")
elseif(${CMAKE_HOST_SYSTEM_NAME} MATCHES "Unix")
    set(CONAN_COMMAND "$ENV{HOME}/.local/bin/conan")
endif()

execute_process(COMMAND ${CONAN_COMMAND} install ${CMAKE_HOME_DIRECTORY}/conanfile.txt --build=missing)

include(${CMAKE_HOME_DIRECTORY}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(main main.cpp src/random.cpp)
target_include_directories(main PRIVATE ${CMAKE_HOME_DIRECTORY}/include)
target_link_libraries(main ${CONAN_LIBS})