cmake_minimum_required(VERSION 3.14)

project(laba_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_executable(figure
    include/point.h
    include/figure.h
    include/rectangle.h
    include/triangle.h
    include/square.h
    include/array.h
    src/main.cpp
)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests 
    tests/main_test.cpp
    tests/point_test.cpp
    tests/array_test.cpp
    tests/rectangle_test.cpp
    tests/square_test.cpp
    tests/triangle_test.cpp
    include/point.h
    include/figure.h
    include/rectangle.h
    include/triangle.h
    include/square.h
    include/array.h
)

target_link_libraries(tests GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)