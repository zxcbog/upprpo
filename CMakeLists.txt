cmake_minimum_required(VERSION 3.0)

project(circ_buffer)

enable_testing()

file(GLOB all_SRCS
        "${PROJECT_SOURCE_DIR}/include/*.h"
        "${PROJECT_SOURCE_DIR}/src/*.cpp"
)
include_directories("include")

add_subdirectory(tests)
add_subdirectory("googletest")
set(CMAKE_CXX_STANDARD 14)
add_library(circular_buffer STATIC ${all_SRCS})
add_executable(app ${all_SRCS})
target_link_libraries(circular_buffer gtest gmock)
