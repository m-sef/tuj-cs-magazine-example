cmake_minimum_required(VERSION 3.28.3)
project(greedy-maximal-independent-set)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Wextra -Werror -DUSE_HASH_SET")

find_package(Boost REQUIRED)

add_executable(
    ${PROJECT_NAME}
    src/main.cpp
    src/greedy_maximal_independent_set.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC ${CMAKE_SOURCE_DIR}/include
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE ${Boost_INCLUDE_DIRS}
)
