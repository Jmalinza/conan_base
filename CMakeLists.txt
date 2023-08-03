cmake_minimum_required(VERSION 3.9.1)
project(starter)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColorReset "${Esc}[m")
  set(Red         "${Esc}[31m")
  set(Yellow      "${Esc}[33m")
  set(BoldRed     "${Esc}[1;31m")
  set(BoldYellow  "${Esc}[1;33m")
endif()

if((NOT CMAKE_BUILD_TYPE) OR (${CMAKE_BUILD_TYPE} MATCHES Debug))
    message("${BoldYellow} Debug Build ${ColorReset} ~ c++${CMAKE_CXX_STANDARD}")
elseif(${CMAKE_BUILD_TYPE} MATCHES Release)
    message("${BoldRed} Release Build ${ColorReset} ~ c++${CMAKE_CXX_STANDARD}")
endif()

find_package(Boost REQUIRED COMPONENTS random)

add_executable(${PROJECT_NAME} src/main.cpp src/random.cpp)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_HOME_DIRECTORY}/include)
target_link_libraries(${PROJECT_NAME} Boost::random)