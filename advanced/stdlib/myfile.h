/**
 * 文件名: Xxx.c
 * 作者: ljk
 * 创建时间: 2023-12-01
 * 文件描述: 
 * 版本: V 1.0.0
 */
#pragma once
#include <fstream>
#include <filesystem>
#include <iostream>


/*
std::filesystem::path：表示文件系统中的路径。
std::filesystem::current_path()：获取当前工作目录的路径。
std::filesystem::exists(const std::filesystem::path&)：检查文件或目录是否存在。
std::filesystem::is_directory(const std::filesystem::path&)：检查路径是否为目录。
std::filesystem::is_regular_file(const std::filesystem::path&)：检查路径是否为普通文件。
std::filesystem::create_directory(const std::filesystem::path&)：创建目录。
std::filesystem::create_directories(const std::filesystem::path&)：创建目录，包括中间目录。
std::filesystem::remove(const std::filesystem::path&)：删除文件或目录。
std::filesystem::rename(const std::filesystem::path&, const std::filesystem::path&)：重命名文件或目录。
std::filesystem::directory_iterator：用于遍历目录中的文件项。
std::filesystem::recursive_directory_iterator：递归遍历目录中的文件项。
*/

namespace myfile{
using Path = const std::filesystem::path;

Path dir_path{"mydir"};
Path dirs_path{"mydir/dirB"};

Path getPath()
{
    return std::filesystem::current_path();
}

bool isExist(Path path)
{
    return std::filesystem::exists(path);
}

bool isDir(Path path)
{
    return std::filesystem::is_directory(path);
}

// 是否普通文件，非目录，软连接，设备文件
bool isFile(Path path)
{
    return std::filesystem::is_regular_file(path);
}

bool createDir(Path path)
{
    return std::filesystem::create_directory(path);
}

bool createDirs(Path path)
{
    return std::filesystem::create_directories(path);
}

// 只能删除空文件夹
void reMove(Path path)
{
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        if (std::filesystem::is_directory(entry)) {
            reMove(entry); // 递归删除子文件夹
        }
        else {
            std::filesystem::remove(entry); // 删除文件
        }
    }
    
    std::filesystem::remove(path); // 删除空的文件夹
}

// 只能修改单级命名
void reName(Path path, Path new_path)
{
    std::filesystem::rename(path, new_path);
}

void iteratorDir(Path path)
{
    // 遍历本文件夹下文件
    for (const auto& file : std::filesystem::directory_iterator(path)) {
        std::cout << "dir:" << file.path() << std::endl;
    }

    // 遍历本文件下文件和所有子目录下文件夹
    for (const auto& file : std::filesystem::recursive_directory_iterator(path)) {
        std::cout << "file:" << file.path() << std::endl;
    }
}



// 写
void writeFile(const char* &file)
{
    std::ofstream outputFile(file); // 打开文件，如果不存在则创建新文件

    if (outputFile.is_open()) {           // 检查文件是否成功打开
        outputFile << "Hello, world!";    // 写入内容
        outputFile.close();               // 关闭文件
    }
}

// 读
void readFile(const char* &file)
{
    std::ifstream inputFile(file); 

    if (inputFile.is_open()) {     
        std::string line;
        while (std::getline(inputFile, line)) { 
            std::cout << line << std::endl;     
        }
        inputFile.close(); 
    }
}

// 追加
void appFile(const char* &file)
{
    std::ofstream outputFile(file, std::ios::app);
    if (outputFile.is_open()) { // 检查文件是否成功打开
        outputFile << "Appended line"; // 追加内容
        outputFile.close(); // 关闭文件
    }
}

}


