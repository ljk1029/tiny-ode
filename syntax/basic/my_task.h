#ifndef MY_TASK_H
#define MY_TASK_H
#include <iostream>
#include <vector>
#include <functional>
#include <utility>
#include <string>

// 任务调度器
class DemoTaskScheduler {
public:
    using TaskFunc = std::function<void()>;
    struct Task {
        std::string name;
        TaskFunc func;
    };

    void addTask(const std::string& name, TaskFunc func) {
        tasks.emplace_back(Task{name, func});
    }

    void runAll() {
        for (const auto& task : tasks) {
            std::cout << "\n[开始执行] " << task.name << std::endl;
            task.func();
            std::cout << "[结束执行] " << task.name << "\n" << std::endl;
        }
    }
private:
    std::vector<Task> tasks;
};


#endif // MY_TASK_H