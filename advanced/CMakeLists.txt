cmake_minimum_required(VERSION 3.16)
project(mybase)


# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


# 设置C++版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/base/)

# 生成可执行文件
add_executable(mybase 
        ${CMAKE_CURRENT_SOURCE_DIR}/base/demo.cpp
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stl/)
add_executable(mystl
        ${CMAKE_CURRENT_SOURCE_DIR}/stl/demo.cpp
    )

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/type/)
add_executable(mytype
    ${CMAKE_CURRENT_SOURCE_DIR}/type/demo.cpp
)

# 设置输出路径
set_target_properties(mybase PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(mystl PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(mytype PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


# 添加子目录
add_subdirectory(stdlib)
