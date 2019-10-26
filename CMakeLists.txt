cmake_minimum_required(VERSION 3.5.1)
project(technopark_C_HW)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(STATIC_SOURCE_FILES
        src/static_sort.c)

#set(SHARED_SOURCE_FILES
#        src/shared_sort.c)

add_library(static_sort STATIC ${STATIC_SOURCE_FILES})
#add_library(shared_sort SHARED ${SHARED_SOURCE_FILES})

include_directories(
        include
        ${GTEST_INCLUDE_DIRS}
)

add_executable(main src/main.c)
add_executable(gtests src/gtests.cpp)

target_link_libraries(main static_sort)
target_link_libraries(gtests static_sort)

target_link_libraries(gtests ${GTEST_LIBRARIES} Threads::Threads)
