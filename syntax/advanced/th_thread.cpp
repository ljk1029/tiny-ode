
#include "th_thread.h"

template<typename Func>
void run_thread_test(const std::string& title, Func&& func) {
	std::cout << "[开始执行] " << title << std::endl;
	func();
	std::cout << "[结束执行] " << title << std::endl;
}

int main() {
	ThreadDemo demo;
	run_thread_test("简单线程创建", [&](){ demo.demo_simple(); });
	run_thread_test("带参数线程", [&](){ demo.demo_with_args(123); });
	run_thread_test("多线程并发", [&](){ demo.demo_multi_threads(); });
	run_thread_test("线程成员函数", [&](){ demo.demo_member_func(); });
	run_thread_test("线程返回值 future", [&](){ demo.demo_return_value(); });
	run_thread_test("只执行一次（线程安全）", [&](){ demo.demo_once_flag(); });
	return 0;
}
