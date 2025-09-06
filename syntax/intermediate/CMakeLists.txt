cmake_minimum_required(VERSION 3.10)
project(basic_demo)

set(CMAKE_CXX_STANDARD 17)

# 分别编译四个可执行文件
add_executable(my_stl my_stl.cpp)
add_executable(my_string my_string.cpp)
add_executable(template_type template_type.cpp)


# 头文件包含路径
target_include_directories(my_stl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(my_string PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(template_type PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

