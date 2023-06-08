project(test_func)

add_executable(test_function test_function.cpp)

enable_testing()
add_subdirectory(googletest)

include_directories(googletest/include)
include_directories(../common)
include_directories(..)

target_link_libraries(test_function PRIVATE gtest)
