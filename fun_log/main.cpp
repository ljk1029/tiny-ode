#include "log.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// 日志测试
void test_log() {
    log_tool::log_colour_set();
    log_tool::log(1, "log:", 45);
}

char *getCmdOption(char **begin, char **end, const std::string &option) {
    char **itr = std::find(begin, end, option);
    if (itr != end && ++itr != end) {
        return *itr;
    }
    return nullptr;
}

bool cmdOptionExists(char **begin, char **end, const std::string &option) {
    return std::find(begin, end, option) != end;
}

// 测试函数入口
int main(int argc, char *argv[]) {
    test_log();
    return 0;
}