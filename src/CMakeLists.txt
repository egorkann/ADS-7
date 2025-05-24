cmake_minimum_required(VERSION 3.10)
project(ADS-7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_library(ADS-7 SHARED src/train.cpp)

add_executable(ADS-7.info src/main.cpp)
target_link_libraries(ADS-7.info ADS-7)

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(ADS-7_test test/tests.cpp)
target_link_libraries(ADS-7_test ADS-7 ${GTEST_LIBRARIES} pthread)
add_test(NAME TrainTests COMMAND ADS-7_test)
