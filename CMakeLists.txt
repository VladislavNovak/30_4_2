cmake_minimum_required(VERSION 3.26)
project(30_4_2)

set(CMAKE_CXX_STANDARD 17)
set(BUILD_CPR_TESTS OFF)
set(CMAKE_USE_OPENSSL OFF)
# Синхронизирует библиотеки
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git GIT_TAG 0817715923c9705e68994eb52ef9df3f6845beba)
FetchContent_MakeAvailable(cpr)

add_executable(30_4_2 main.cpp
        src/utilities.cpp
        headers/utilities.h)

target_link_libraries(30_4_2 PRIVATE cpr::cpr)