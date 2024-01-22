# C++
  C++ study
  Qt study

## doc
  文档说明

## qt
  qt部分


# code
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

  树的旋转说明
  ![image](https://github.com/ljk1029/ToyTool/tree/main/img/tree.png)


# c++工具
## gtest 安装
  1、地址:https://github.com/google/googletest.git

  2、编译 cmake .. / make

  3、依赖
  拷贝生成静态库
  sudo cp *.a /usr/local/lib
  拷贝头文件
  sudo cp -r include/gtest /usr/local/include

  4、测试代码编译
  g++ -std=c++17 test.cpp -lgtest -lgtest_main -lpthread

## 提交类型
  - feat:     新功能（feature）
  - fix:      修补bug
  - refactor: 重构
  - update:   更新