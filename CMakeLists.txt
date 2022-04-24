cmake_minimum_required(VERSION 3.18)
project(ProjectSorts)

#set(CMAKE_CXX_COMPILER clang)
#set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra")

set(CMAKE_CXX_STANDARD 20)

include_directories(includes)

set(SRCS    srcs/main.cpp
            srcs/data/date.cpp
            srcs/timer/timer.cpp
            
            srcs/common/common.cpp)

add_executable(ProjectSorts ${SRCS})
