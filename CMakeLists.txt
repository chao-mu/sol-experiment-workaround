cmake_minimum_required(VERSION 3.10)
project(solexp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pthread")

add_executable(${PROJECT_NAME} src/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE thirdparty/)

find_package(Lua REQUIRED)
include_directories(${LUA_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${LUA_LIBRARIES})

target_compile_options(${PROJECT_NAME} PRIVATE "-Wextra" "-Wall")
