cmake_minimum_required(VERSION 3.16)
project(mygtest)

set(TARGET1 "mygtest")

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../) # 这里假设gtest和mytool目录在同一级目录下


# 添加源文件
file(GLOB_RECURSE GTEST_SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/gtest_main.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/gtest-all.cc
)

# 生成可执行文件
add_executable(${TARGET1}
    ${GTEST_SRC_FILES}
)

target_link_libraries(${TARGET1} 
    -lpthread
    )    

# 设置输出路径
set_target_properties(${TARGET1} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)