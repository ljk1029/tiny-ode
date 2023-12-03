# C++
C++ study
Qt study


## doc


## qt



## advanced
C++ 一些使用 
### base
基础语法使用

### algorithm
算法、例题

### type
template模板使用

### stl
stl 使用

## tool
数据结构

### gtest 安装
地址:https://github.com/google/googletest.git

编译 cmake .. / make

拷贝生成静态库
sudo cp *.a /usr/local/lib
拷贝头文件
sudo cp -r include/gtest /usr/local/include

测试代码编译
g++ -std=c++17 test.cpp -lgtest -lgtest_main -lpthread

## 提交类型
  - feat: 新功能（feature）
  - fix: 修补bug
  - refactor: 重构