cmake_minimum_required(VERSION 3.7)

project(atm_service)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

find_package(Threads)

add_executable(atm_service main.cpp)
target_link_libraries(atm_service ${Boost_LIBRARIES} Threads::Threads)
