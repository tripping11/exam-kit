cmake_minimum_required(VERSION 3.16)
project(exam_kit CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Common warnings
add_compile_options(-Wall -Wextra -Wshadow -Wconversion)

# Main executable
add_executable(main
  src/main.cpp
  src/solution.cpp
)
target_include_directories(main PRIVATE include)

# Unit test executable
add_executable(unit_tests
  tests/test_solution.cpp
  src/solution.cpp
)
target_include_directories(unit_tests PRIVATE include)

enable_testing()
add_test(NAME unit COMMAND unit_tests)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_options(main PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer -g)
  target_link_options(main PRIVATE -fsanitize=address,undefined)
  target_compile_options(unit_tests PRIVATE -fsanitize=address,undefined -fno-omit-frame-pointer -g)
  target_link_options(unit_tests PRIVATE -fsanitize=address,undefined)
endif()
