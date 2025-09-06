#include "../basic/my_task.h"
#include "template_type.h"


// 测试用例
int main() {
    TemplateExample demo;
    DemoTaskScheduler scheduler;
    scheduler.addTask("类模板演示", [&](){ demo.demo_class_template(); });
    scheduler.addTask("函数模板演示", [&](){ demo.demo_func_template(); });
    scheduler.addTask("模板max演示", [&](){ demo.demo_max(); });
    scheduler.addTask("变参模板演示", [&](){ demo.demo_variadic(); });
    scheduler.addTask("模板默认参数演示", [&](){ demo.demo_default_type(); });
    scheduler.addTask("模板别名演示", [&](){ demo.demo_alias(); });
    scheduler.addTask("类型萃取traits演示", [&](){ demo.demo_traits(); });
    scheduler.runAll();
    return 0;
}
