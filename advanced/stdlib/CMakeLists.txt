cmake_minimum_required(VERSION 3.16)
project(mystdapp)


# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


# 设置C++版本
#set(CMAKE_CXX_STANDARD 11)
# 设置C++版本为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)



# 生成可执行文件
add_executable(mystdapp 
        mytest.cpp
    )


# 链接库
target_link_libraries(mystdapp 
    -lpthread
    )    

# 设置输出路径
set_target_properties(mystdapp PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin)


