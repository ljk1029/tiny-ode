#include "my_sort.h"


// test switch
void testSortAlgorithm(int args) {
    int  num_len  = 10;
    int* number;
    if(sort_tool::genrateSort(number, num_len)){ 
        switch (args) {
        case 1:
            sort_tool::bubbleSort(number, num_len);
            break;
        case 2:
            sort_tool::insertSort(number, num_len);
            break;
        case 3:
            sort_tool::quickSort(number, 0, num_len - 1);
            break;
        case 4:
            sort_tool::selectSort(number, num_len);
            break;

        default:
            break;
        }
        sort_tool::printSort(number, num_len, 1);
        delete[] number;
    }
}

// 获取参数
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

#define RUN_SORT_3(task_number)                                                                                        \
    if (cases_run == nullptr ||                                                                                        \
        (cases_string.find("f" #task_number) != std::string::npos && cases_string.size() == 3)) {                      \
        std::cout << "sort" #task_number << std::endl;                                                                 \
        testSortAlgorithm(task_number);                                                                              \
    }

// 测试函数入口
int main(int argc, char *argv[]) {
    char *cases_run = getCmdOption(argv, argv + argc, "-case");
    std::string cases_string;
    if (cases_run) {
        cases_string = cases_run;
    }
    RUN_SORT_3(1)
    RUN_SORT_3(2)
    RUN_SORT_3(3)
    RUN_SORT_3(4)
    return 0;
}