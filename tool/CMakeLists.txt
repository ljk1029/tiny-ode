cmake_minimum_required(VERSION 3.16)
project(mytool)


# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


# 设置C++版本
#set(CMAKE_CXX_STANDARD 11)
# 设置C++版本为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)


# 开源库
#include_directories(./thirdparty/protobuf/include)
#link_directories(./thirdparty/protobuf/lib)

# 搜索指定的库文件
#find_library(LIB_PROTOBUF protobuf HINTS ./thirdparty/protobuf/lib)


# 添加源文件
file(GLOB_RECURSE SRC_FILES 
    #./app/src/*.cpp
    )

# 生成可执行文件
add_executable(mytool 
        tool.cpp
        #${SRC_FILES}
    )


# 链接线程库
#find_package(Threads REQUIRED)
target_link_libraries(mytool 
    -lpthread
    #${LIB_PROTOBUF}
    )    

# 设置输出路径
set_target_properties(mytool PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)




##
#   添加一个子模块
##
# 添加子目录，包含 gtest 的构建
add_subdirectory(gtest)




##
#   添加第二个执行文件
##
# 添加源文件
add_executable(mygtool gtool.cpp ${CMAKE_CURRENT_SOURCE_DIR}/gtest/gtest-all.cc)

target_link_libraries(mygtool 
    -lpthread
    )    

# 设置输出路径
set_target_properties(mygtool PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)