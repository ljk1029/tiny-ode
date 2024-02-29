cmake_minimum_required(VERSION 3.16)
project(mytool)

# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 设置C++版本
#set(CMAKE_CXX_STANDARD 11)
# 设置C++版本为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET1 "tool_list")
set(TARGET2 "tool_tree")
set(TARGET3 "tool_search")
set(TARGET4 "tool_base")
set(TARGET5 "tool_gtest")


# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)

##
#   1、添加第一个执行文件
##
# 生成可执行文件
add_executable(${TARGET1} data_list.cpp)
add_executable(${TARGET2} data_tree.cpp)
add_executable(${TARGET3} sort_search.cpp)
add_executable(${TARGET4} sort_base.cpp)
add_executable(${TARGET5} tool_gtest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/gtest/gtest-all.cc)

# 链接线程库
target_link_libraries(${TARGET1}  -lpthread)    
target_link_libraries(${TARGET5}  -lpthread)    

# 设置输出路径
set_target_properties(${TARGET1} ${TARGET2} ${TARGET3} ${TARGET4} ${TARGET5}  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

##
#   3、添加一个子模块
##
# 添加子目录，包含 gtest 的构建
add_subdirectory(gtest)