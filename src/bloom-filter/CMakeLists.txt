FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  bloom-filter
  bloom-filter-app.cpp
  bloom-filter.cpp
)

add_executable(
  bloom-filter-test
  bloom-filter-test.cpp
  bloom-filter.cpp
)

target_link_libraries(
  bloom-filter-test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bloom-filter-test)