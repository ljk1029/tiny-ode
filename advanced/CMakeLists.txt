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

# 将配置文件内容读取到一个变量中
file(READ config.ini configContents)

# 定义一个函数，用于从配置内容中解析特定节下的设置
function(parse_ini_section section key var)
    string(REGEX MATCH "\\[${section}\\][^\[]*" sectionContent "${configContents}")
    string(REGEX MATCH "${key}=([A-Za-z0-9]+)" keyValue "${sectionContent}")
    if(NOT "${keyValue}" STREQUAL "")
        string(REPLACE "${key}=" "" value "${keyValue}")
        set(${var} ${value} PARENT_SCOPE)
    endif()
endfunction()

# 解析配置文件下参数
parse_ini_section("Build" "Debug" BUILD_DEBUG)
parse_ini_section("Function" "USE_TEST" FUNCTION_USE_TEST)
parse_ini_section("Function" "USE_FUN"  FUNCTION_USE_FUN)

# 打印解析结果验证
message("BUILD_DEBUG: ${BUILD_DEBUG}")
message("FUNCTION_USE_TES: ${FUNCTION_USE_TEST}")
message("FUNCTION_USE_FUN: ${FUNCTION_USE_FUN}")

# 设置编译选项, 与CMAKE_CXX_FLAGS是重复的
if (BUILD_DEBUG)
    message("Debug mode enabled")
    set(CMAKE_BUILD_TYPE Debug)
else()
    message("Release mode enabled")
    set(CMAKE_BUILD_TYPE Release)
endif()


if(FUNCTION_USE_TEST)
    add_executable(a.out ${CMAKE_CURRENT_SOURCE_DIR}/my_demo.cpp)
    set_target_properties(a.out PROPERTIES  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
endif()

# 功能模块编译开关
if(FUNCTION_USE_FUN)    
# 添加头文件搜索路径
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/base/)

# 1、base模块 生成可执行文件
add_executable(${TARGET1} 
    ${CMAKE_CURRENT_SOURCE_DIR}/base/demo_base.cpp
)
add_executable(${TARGET4} 
    ${CMAKE_CURRENT_SOURCE_DIR}/base/demo_class.cpp
)

# 2、stl模块
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/stl/)
add_executable(${TARGET2}
    ${CMAKE_CURRENT_SOURCE_DIR}/base_stl/demo_stl.cpp
)

# 3、template模块
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/template/)
add_executable(${TARGET3}
    ${CMAKE_CURRENT_SOURCE_DIR}/base_template/demo_type.cpp
)

# 设置输出路径
set_target_properties(${TARGET1} ${TARGET4} ${TARGET2} ${TARGET3} 
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin
)

# 4、添加子目录
add_subdirectory(modules)

endif()
