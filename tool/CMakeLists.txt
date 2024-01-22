cmake_minimum_required(VERSION 3.16)
project(mytool)

# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 设置C++版本
#set(CMAKE_CXX_STANDARD 11)
# 设置C++版本为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET1 "my_tool")
set(TARGET2 "my_gtool")

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)

# 指定搜索开源库头文件位置
#include_directories(./thirdparty/protobuf/include)
#link_directories(./thirdparty/protobuf/lib)

# 指定搜索开源库库文件位置
#find_library(LIB_PROTOBUF protobuf HINTS ./thirdparty/protobuf/lib)

# 添加源文件
file(GLOB_RECURSE SRC_FILES 
    #./app/src/*.cpp
    )

##
#   1、添加第一个执行文件
##
# 生成可执行文件
add_executable(${TARGET1} 
        tool.cpp
        #${SRC_FILES}
    )

# 链接线程库
#find_package(Threads REQUIRED)
target_link_libraries(${TARGET1}  
        -lpthread
    #${LIB_PROTOBUF}
    )    

##
#   2、添加第二个执行文件
##
# 添加源文件
add_executable(${TARGET2}  gtool.cpp ${CMAKE_CURRENT_SOURCE_DIR}/gtest/gtest-all.cc)
target_link_libraries(${TARGET2}  
        -lpthread
    )    

# 设置输出路径
set_target_properties(${TARGET1}  ${TARGET2}  PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

##
#   3、添加一个子模块
##
# 添加子目录，包含 gtest 的构建
add_subdirectory(gtest)