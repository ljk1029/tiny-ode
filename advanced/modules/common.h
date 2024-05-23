/**
 * 文件名: common.h
 * 作者: ljk
 * 创建时间: 2023-12-01
 * 文件描述:
 * 版本: V 1.0.0
 */
#pragma once
#include <functional>
#include <filesystem>

#define MY_MODULES_TEST

// time
namespace my_time {
// chrono
using CallbackFuc = std::function<void()>;
// 休眠，这里是线程时间，休眠可能比实际时间长
void sleep_S(int cnt);
void sleepMs(int cnt);
void sleepUs(int cnt);
// 获取系统时间
void getTime();
// 测试函数执行时间
void countTime(CallbackFuc callback);
} // namespace my_time

// file
namespace my_file {
// filesystem
using ConstPath = const std::filesystem::path;
// 获取当前路径
ConstPath getPath();
bool isExist(ConstPath path);
bool isDir(ConstPath path);
bool isFile(ConstPath path);
bool createDir(ConstPath path);
bool createDirs(ConstPath path);
// 只能删除空文件夹
bool reMove(ConstPath path);
// 只能修改单级命名
bool reName(ConstPath path, ConstPath new_path);
// 文件夹遍历
void iteratorDir(ConstPath path);

// ofstream
// 写
void fileWrite(const char *&file, const char *text = "Hello, world!");
// 读
void fileRead(const char *&file);
// 追加
void fileAppend(const char *&file, const char *text = "Appended line");
} // namespace my_file

// thread
namespace my_thread {
// thread
void createThread();
} // namespace my_thread


int thread_main(int argc, char *argv[]);
int process_main(int argc, char *argv[]);