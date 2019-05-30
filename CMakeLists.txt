cmake_minimum_required(VERSION 3.10)

project(lotopp CXX)

set(LOTOPP_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LOTOPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

set(src ${LOTOPP_SRC_ROOT}/Utils.cpp)

set(test_src ${LOTOPP_SRC_ROOT}/Utils.cpp)

include_directories(${LOTOPP_INCLUDE_DIR})

add_library(lotopp SHARED ${src})

add_executable(test_comb ${CMAKE_CURRENT_SOURCE_DIR}/test/test_comb.cpp)
target_link_libraries(test_comb lotopp)

install(TARGETS lotopp
        DESTINATION lib
)

install(TARGETS test_comb
        DESTINATION bin
)