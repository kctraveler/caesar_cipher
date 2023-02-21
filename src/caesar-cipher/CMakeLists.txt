FetchContent_MakeAvailable(googletest)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_library(utils utils.cpp)
add_library(decoder decoder.cpp)
target_link_libraries(decoder utils)

enable_testing()

add_executable(
  decoder-test
  decoder-test.cpp
)
target_link_libraries(
  decoder-test
  GTest::gtest_main
  decoder
  utils
)

add_executable(
  encoder 
  encoder.cpp
)

target_link_libraries(
  encoder 
  utils
)

add_executable(
  decoder-app 
  decoder-app.cpp
)
target_link_libraries(
  decoder-app 
  decoder
  utils
)

include(GoogleTest)
gtest_discover_tests(decoder-test)