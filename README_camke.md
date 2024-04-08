## 1、起始头
###
    cmake_minimum_required(VERSION 3.16)
    要求最小cmake版本
    project(mytool)
    工程名
###
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
    设置编译选项
###
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    设置C++版本
    CMAKE_CXX_STANDARD_REQUIRED: 当这个变量被设置为ON，它告诉CMake所指定的C++标准是必须的
###
    set(TARGET1 "tool_list")
    设置标识，下面可以用这个代替生成物或者c++文件名


## 2、路径
    CMAKE_SOURCE_DIR: 代表了顶级项目的源代码根目录
    CMAKE_CURRENT_SOURCE_DIR: 表示正在被处理的CMakeLists.txt文件所在的目录


## 3、主要功能 
    include_directories(./thirdparty/protobuf/include)
    link_directories(./thirdparty/protobuf/lib)
    链接开源库，指定开源库头路径

    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libspdlog/)
    添加头文件搜索路径

    aux_source_directory(${CMAKE_SOURCE_DIR}/src/common SOURCE_COMMON) 
    包含源文件 ，aux_source_directory将目录所有源文件自动加入

    生成执行文件
    add_executable(myspdlog 
        ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp
        ${SOURCE_API}
        ${SOURCE_COMMON} 
    ) 
    生成动/静态库
    add_library(spdlog
	    STATIC
        #SHARED
        ...
    )

    链接我们需要的库
    target_link_libraries( myapp 
        lpthread 
    ) 


## 4、注册
    将生成执行文件安装到指定目录
    install(
        TARGETS TARGET1 TARGET2
        RUNTIME DESTINATION $ENV{INSTALL_DIR}/bin
        LIBRARY DESTINATION $ENV{INSTALL_DIR}/lib)

    install(
        DIRECTORY config
        DESTINATION $ENV{INSTALL_DIR})

    设置生成执行文件输出路径
    set_target_properties(${TARGET} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin/)

    复制文件到输出目录
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/p.conf ${CMAKE_CURRENT_SOURCE_DIR}/../bin/p.conf COPYONLY)


## 5、子模块
    add_subdirectory(zlog)


### A文件夹下cmake包含B文件夹下cmake
    add_subdirectory(../../B B_build)
    B_build为当前目录下生成目录名称，随便起；当B下cmake是指定相对目录，B_build不生效