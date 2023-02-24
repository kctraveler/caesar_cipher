

FetchContent_MakeAvailable(googletest)
enable_testing()
find_package(Boost 1.70.0 REQUIRED system filesystem)
find_package(OpenSSL REQUIRED)

add_executable(
  bloom-filter
  bloom-filter-app.cpp
  BloomFilter.cpp
)
target_link_libraries(
  bloom-filter
  Boost::boost
  OpenSSL::SSL
)

add_executable(
  bloom-filter-test
  bloom-filter-test.cpp
  BloomFilter.cpp
)

target_link_libraries(
  bloom-filter-test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(bloom-filter-test)