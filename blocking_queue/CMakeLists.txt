cmake_minimum_required(VERSION 3.17)
project(blocking_queue)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.75.0 COMPONENTS system filesystem thread chrono REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(blocking_queue main.cpp blocking_queue.hpp)
target_link_libraries(blocking_queue ${Boost_LIBRARIES})