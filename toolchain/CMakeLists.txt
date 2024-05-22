cmake_minimum_required(VERSION 3.0)
project(MyProject)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CHAINTOOL_PATH  /home/li/Tool/gcc-linaro-7.5.0-2019.12-x86_64_aarch64-linux-gnu)
set(CHAINTOOL_GCC  bin/aarch64-linux-gnu-gcc)
set(CHAINTOOL_GXX  bin/aarch64-linux-gnu-g++)
set(CHAINTOOL_INC  aarch64-linux-gnu/include)
set(CHAINTOOL_LIB  aarch64-linux-gnu/lib)


# 指定交叉编译工具链位置
set(CROSS_COMPILE_PATH ${CHAINTOOL_PATH})
set(CMAKE_C_COMPILER   ${CROSS_COMPILE_PATH}/${CHAINTOOL_GCC})
set(CMAKE_CXX_COMPILER ${CROSS_COMPILE_PATH}/${CHAINTOOL_GXX})

# 添加头文件目录
include_directories(${CROSS_COMPILE_PATH}/${CHAINTOOL_INC})

# 添加库文件目录
link_directories(${CROSS_COMPILE_PATH}/${CHAINTOOL_LIB})

add_executable(MyProject test.cpp)

# 链接你的项目所需要的库，例如：libmylib.a or -lmylib
#target_link_libraries(MyProject mylib)