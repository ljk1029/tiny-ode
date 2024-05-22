cmake_minimum_required(VERSION 3.16)
project(my_module)

# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 设置C++版本
#set(CMAKE_CXX_STANDARD 11)
# 设置C++版本为C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(TARGET1 "my_module")

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/)

# 生成可执行文件
add_executable(${TARGET1} 
    ${CMAKE_CURRENT_SOURCE_DIR}/my_time.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/my_file.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/my_process.cpp
    demo_modules.cpp
)

# 链接库
target_link_libraries(${TARGET1}  
    -lpthread
)    

# 设置输出路径
set_target_properties(${TARGET1} 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin
)


