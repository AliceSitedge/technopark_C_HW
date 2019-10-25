cmake_minimum_required(VERSION 3.5.1)
project(technopark_C_HW1)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_FILES
        src/matrix.c
        src/num_counts.c)

add_library(study_std_lib STATIC ${SOURCE_FILES})

include_directories(
        include
        ${GTEST_INCLUDE_DIRS}
)

add_executable(main src/main.c)
add_executable(gtests src/gtests.cpp)

target_link_libraries(main study_std_lib)
target_link_libraries(gtests study_std_lib)

target_link_libraries(gtests ${GTEST_LIBRARIES} Threads::Threads)
