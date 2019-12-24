cmake_minimum_required(VERSION 3.9)

project(atm_service)

set(CMAKE_CXX_STANDARD 17)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Boost COMPONENTS system filesystem REQUIRED)
find_package(Threads)

include_directories(${Boost_INCLUDE_DIRS})
add_executable(atm_service main.cpp)
target_link_libraries(atm_service ${Boost_LIBRARIES} Threads::Threads)
