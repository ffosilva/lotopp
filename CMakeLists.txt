cmake_minimum_required(VERSION 3.10)

project(lotopp CXX)

set(LOTOPP_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(LOTOPP_TEST_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/test)
set(LOTOPP_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src/include)

file(GLOB src ${LOTOPP_SRC_ROOT}/*.cpp)

file(GLOB test_src ${LOTOPP_TEST_ROOT}/*.cpp)

include_directories(${LOTOPP_INCLUDE_DIR})

add_library(lotopp SHARED ${src})

link_libraries(lotopp)

enable_testing()
foreach(test_src_file ${test_src})
  string(REPLACE "${LOTOPP_TEST_ROOT}/" "" test_name ${test_src_file})
  string(REPLACE ".cpp" "" test_name ${test_name})
  add_executable(${test_name} ${test_src_file})
  add_test(${test_name} ${test_name})
endforeach(test_src_file ${test_src})

install(TARGETS lotopp
        DESTINATION lib
)
