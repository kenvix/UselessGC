cmake_minimum_required(VERSION 3.17)
project(UselessGC)

set(CMAKE_CXX_STANDARD 17)

add_library(libs
        UselessGC/GC.cpp
        UselessGC/SysLog.cpp
        UselessGC/XString.cpp
        UselessGC/R.cpp
        UselessGC/Object.cpp
        UselessGC/XString.h UselessGC/XString.cpp)

link_libraries(libs)
add_executable(UselessGC UselessGC/Test.cpp)