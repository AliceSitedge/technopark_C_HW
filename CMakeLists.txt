cmake_minimum_required(VERSION 3.5.1)
project(technopark_C_HW1)

set(CMAKE_C_STANDARD 11)

include_directories(include)

add_executable(main src/main.c src/matrix.c src/num_counts.c)