cmake_minimum_required(VERSION 3.14)
project(CS-378 CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Core Engine Library
add_library(cs378_core 
    src/common.cpp
    src/apriori.cpp 
    src/declat.cpp
)
target_include_directories(cs378_core PUBLIC include)

# Main Executable
add_executable(cs378_engine src/main.cpp)
target_link_libraries(cs378_engine cs378_core)

# Google Test Integration (v1.17.0)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Functional Tests
add_executable(cs378_tests_functional tests/test_functional.cpp)
target_link_libraries(cs378_tests_functional GTest::gtest_main cs378_core)
add_test(NAME FunctionalTests COMMAND cs378_tests_functional)

# Performance Tests
add_executable(cs378_tests_performance tests/test_performance.cpp)
target_link_libraries(cs378_tests_performance GTest::gtest_main cs378_core)
add_test(NAME PerformanceTests COMMAND cs378_tests_performance)
