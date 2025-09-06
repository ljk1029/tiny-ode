cmake_minimum_required(VERSION 3.10)
project(basic_demo)

set(CMAKE_CXX_STANDARD 17)

# 分别编译四个可执行文件
add_executable(memory memory.cpp)
add_executable(my_dbg my_dbg.cpp)
add_executable(my_io my_io.cpp)
add_executable(my_ptr my_ptr.cpp)

# 头文件包含路径
target_include_directories(memory PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(my_dbg PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(my_io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(my_ptr PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
