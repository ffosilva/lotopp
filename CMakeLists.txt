cmake_minimum_required(VERSION 3.10)
project(lotopp CXX)

set(CMAKE_MODULE_PATH "${lotopp_SOURCE_DIR}/cmake")

include(BuildType)

set(LOTOPP_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LOTOPP_EXAMPLES_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/examples)
set(LOTOPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

file(GLOB src ${LOTOPP_SRC_ROOT}/*.cpp)

include_directories(${LOTOPP_INCLUDE_DIR})

add_library(lotopp SHARED ${src})

install(TARGETS lotopp
        DESTINATION lib
)

enable_testing()
add_subdirectory(${lotopp_SOURCE_DIR}/test)