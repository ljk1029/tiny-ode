cmake_minimum_required(VERSION 3.16)
project(mybase)

# 添加编译选项
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

# 设置C++版本
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TARGET1 "pro_lock")
set(TARGET2 "pro_test")
set(TARGET3 "pro_thread")

# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# 生成可执行文件
add_executable(${TARGET1} 
        ${CMAKE_CURRENT_SOURCE_DIR}/pro_lock.cpp
    )
add_executable(${TARGET2}
        ${CMAKE_CURRENT_SOURCE_DIR}/pro_test.cpp
    )
add_executable(${TARGET3}
        ${CMAKE_CURRENT_SOURCE_DIR}/pro_thread.cpp
    )
target_link_libraries(${TARGET1} -lpthread)
target_link_libraries(${TARGET2} -lpthread)
target_link_libraries(${TARGET3} -lpthread)

# 设置输出路径
set_target_properties(${TARGET1} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(${TARGET2} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set_target_properties(${TARGET3} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

