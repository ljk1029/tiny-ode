#include "stl_list.h"
#include "stl_map.h"
#include "stl_set.h"
#include "stl_vector.h"
#include "../run_print.h"



// vector 测试
void stlVectorTset(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("vector") ){
        test_runner.funcPrint("verctorMake()",     my_base::stl_vector::verctorMake);
        test_runner.funcPrint("verctorAt()",       my_base::stl_vector::verctorAt);
        test_runner.funcPrint("verctorErase()",    my_base::stl_vector::verctorErase);
        test_runner.funcPrint("verctorIterator()", my_base::stl_vector::verctorIterator);
    }
}

// map 测试
void stlMapTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("map") ){
        test_runner.funcPrint("mapMake()",     my_base::stl_map::mapMake);
        test_runner.funcPrint("mapIterator()", my_base::stl_map::mapIterator);
        test_runner.funcPrint("mapFind()",     my_base::stl_map::mapFind);
        test_runner.funcPrint("mapErase()",    my_base::stl_map::mapErase);
    }
}

// list 测试
void stlListTest(my_base::TestRunner &test_runner) {
    if( test_runner.getRunStatus("list") ){
        test_runner.funcPrint("listMake()",     my_base::stl_list::listMake);
        test_runner.funcPrint("listIterator()", my_base::stl_list::listIterator);
        test_runner.funcPrint("listRemove()",   my_base::stl_list::listRemove);
    }
}

// set 测试
void stlSetTest(my_base::TestRunner &test_runner) { 
    if( test_runner.getRunStatus("set") ){
        test_runner.funcPrint("set()", my_base::stl_set::setAll); 
    }
}

int mainStlTest(int argc, char *argv[]) {
    my_base::TestRunner test_runner(argc, argv);
    stlVectorTset(test_runner);
    stlMapTest(test_runner);
    stlListTest(test_runner);
    stlSetTest(test_runner);
    return 0;
}

// 测试用例
int main(int argc, char *argv[]) {
    mainStlTest(argc, argv);
    return 0;
}
