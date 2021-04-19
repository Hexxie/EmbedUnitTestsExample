cmake_minimum_required(VERSION 3.16)

project(UnitTests) 

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(
    src 
    test 
    C:/msys64/mingw64/include
)

link_directories(
    C:/msys64/mingw64/lib
)

add_definitions(-g)
add_definitions(-std=gnu++11)
add_definitions(
    -DUNIT
    -DCYCURLIB_NOT_USED
)
add_definitions(-DTEST_HAS_PTHREAD=1)

set ( C_SRCS
    src/awesome_header.c
)

# Define the CXX sources
set ( CXX_SRCS
    test/main.cpp
    test/AwesomeUT.cpp
)

add_executable(UnitTests ${CXX_SRCS} ${C_SRCS})
target_link_libraries(UnitTests
    gtest
    gmock
    pthread
)