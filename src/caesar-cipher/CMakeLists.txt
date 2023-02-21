FetchContent_MakeAvailable(googletest)

add_library(utils.a utils.cpp)
add_library(decoder.a decoder.cpp)
target_link_libraries(decoder.a utils.a)

enable_testing()

add_executable(
  decoder-test
  decoder-test.cpp
)
target_link_libraries(
  decoder-test
  GTest::gtest_main
  decoder.a
  utils.a
)

add_executable(
  encoder 
  encoder.cpp
)

target_link_libraries(
  encoder 
  utils.a
)

add_executable(
  decoder-app 
  decoder-app.cpp
)
target_link_libraries(
  decoder-app 
  decoder.a 
  utils.a
)

include(GoogleTest)
gtest_discover_tests(decoder-test)