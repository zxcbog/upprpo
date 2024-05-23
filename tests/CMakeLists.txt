add_executable(
  hello_test2
  tests.cpp
)
target_link_libraries(
  hello_test2
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(hello_test2)
