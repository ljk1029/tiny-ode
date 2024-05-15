cmake_minimum_required(VERSION 3.16)
project(mybase)

# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 设置C++版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET1 "my_base")
set(TARGET2 "my_stl")
set(TARGET3 "my_type")
set(TARGET4 "my_class")

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/base/)

# 生成可执行文件
# base
add_executable(${TARGET1} 
    ${CMAKE_CURRENT_SOURCE_DIR}/base/demo_base.cpp
)

# class
add_executable(${TARGET4} 
    ${CMAKE_CURRENT_SOURCE_DIR}/base/my_class.cpp
)

# stl
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stl/)
add_executable(${TARGET2}
    ${CMAKE_CURRENT_SOURCE_DIR}/stl/demo_stl.cpp
)

# template
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/template/)
add_executable(${TARGET3}
    ${CMAKE_CURRENT_SOURCE_DIR}/template/demo_type.cpp
)

# 设置输出路径
set_target_properties(${TARGET1} ${TARGET4} ${TARGET2} ${TARGET3} 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


# 添加子目录
add_subdirectory(lib)
