cmake_minimum_required(VERSION 3.18)
project(ProjectSorts)

#set(CMAKE_CXX_COMPILER clang)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_CXX_STANDARD 20)

include_directories(includes)

add_executable(ProjectSorts srcs/main.cpp includes/bubble_sort.hpp includes/shaker_sort.hpp includes/odd_even_sort.hpp includes/comb_sort.hpp includes/insertion_sort.hpp includes/selection_sort.hpp includes/common.hpp includes/quick_sort.hpp includes/date.hpp srcs/date.cpp includes/timer.cpp includes/timer.hpp includes/generate_random.hpp srcs/tests.cpp includes/tests.hpp includes/tests.hpp)
