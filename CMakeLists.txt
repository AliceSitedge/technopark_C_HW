cmake_minimum_required(VERSION 3.5.1)
project(technopark_C_HW1)

find_package(GTest REQUIRED)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        include
        ${GTEST_INCLUDE_DIRS}
)

add_executable(main src/main.c src/matrix.c src/num_counts.c)