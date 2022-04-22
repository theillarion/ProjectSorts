cmake_minimum_required(VERSION 3.18)
project(ProjectSorts)

#set(CMAKE_CXX_COMPILER clang)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")
set(CMAKE_CXX_STANDARD 20)
#set(SRC_SORTS "")



include_directories(includes)

add_executable(ProjectSorts srcs/main.cpp includes/sorts/bubble/bubble_sort.hpp includes/sorts/shaker/shaker_sort.hpp includes/sorts/odd_even/odd_even_sort.hpp includes/sorts/comb/comb_sort.hpp includes/sorts/insertion/insertion_sort.hpp includes/sorts/selection/selection_sort.hpp includes/common/common.hpp includes/sorts/quick/quick_sort.hpp includes/data/date.hpp srcs/data/date.cpp srcs/timer/timer.cpp includes/timer/timer.hpp includes/random/generate_random.hpp srcs/tests/tests.cpp includes/tests/tests.hpp includes/tests/tests.hpp includes/sorts/heap/heap_sort.hpp srcs/common/common.cpp includes/sorts/sorts.hpp)
