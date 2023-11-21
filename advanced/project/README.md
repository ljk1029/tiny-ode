## gtest 安装
地址:https://github.com/google/googletest.git

编译 cmake .. / make

拷贝生成静态库
sudo cp *.a /usr/local/lib
拷贝头文件
sudo cp -r include/gtest /usr/local/include


测试代码编译
g++ -std=c++17 list.cpp -lgtest -lgtest_main -lpthread