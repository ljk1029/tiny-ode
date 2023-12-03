cmake_minimum_required(VERSION 3.16)
project(mygtest)

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../) # 这里假设gtest和mytool目录在同一级目录下


# 添加源文件
file(GLOB_RECURSE GTEST_SRC_FILES 
    ${CMAKE_CURRENT_SOURCE_DIR}/gtest_main.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/gtest-all.cc
)

# 生成可执行文件
add_executable(mygtest
    ${GTEST_SRC_FILES}
)

target_link_libraries(mygtest 
    -lpthread
    )    

# 设置输出路径
set_target_properties(mygtest PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)