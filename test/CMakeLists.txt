file(GLOB test_src ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

foreach(test_src_file ${test_src})
  string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}/" "" test_name ${test_src_file})
  string(REPLACE ".cpp" "" test_name ${test_name})
  add_executable(${test_name} ${test_src_file})
  target_link_libraries(${test_name} lotopp)
  add_test(${test_name} ${test_name})
endforeach(test_src_file ${test_src})