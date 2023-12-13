#ifndef _SORT_TOOL_H__
#define _SORT_TOOL_H__

/**
1. 冒泡排序（Bubble Sort）：适用于小规模的数据排序，实现简单但效率较低。
2. 选择排序（Selection Sort）：适用于小规模的数据排序，也适合于数据基本有序的情况。
3. 插入排序（Insertion Sort）：适用于对小规模或者基本有序的数据进行排序。
4. 希尔排序（Shell Sort）：对插入排序进行了优化，适用于较大规模的数据排序。
5. 归并排序（Merge Sort）：适用于所有规模的数据排序，效率较高，但需要额外的内存空间。
6. 快速排序（Quick Sort）：适用于所有规模的数据排序，平均情况下效率较高。
7. 堆排序（Heap Sort）：适用于大规模的数据排序，尤其适用于动态数据集。
8. 计数排序（Counting Sort）：适用于非负整数的排序，且数值范围不大。
9. 桶排序（Bucket Sort）：适用于非负整数的排序，适合于数据分布均匀的情况。
10. 基数排序（Radix Sort）：适用于数字进行排序，可用于字符串排序。
11. 鸡尾酒排序（Cocktail Sort）：适用于需要稳定排序结果和对数据重复值较多的情况。
12. 梳排序（Comb Sort）：适用于乱序数据的排序，相对于冒泡排序有较好的性能。
13. 混合排序（Tim Sort）：适用于大规模的数据排序，结合了归并排序和插入排序的特点。
14. 块排序（Bucket Sort）：适用于大规模数据排序，利用外部存储进行排序。
15. 外部排序（External Sort）：适用于数据量大于内存容量的情况，利用外部存储进行排序。
*/


namespace sort_tool{

// 深度搜素
void DFS(int array[][], int n, int m)
{

}

// 广度搜素
void BFS(int array[][], int n, int m)
{

}

// 1、冒泡排序
void bubble_sort(int array[], int n)
{

}

// 2、插入排序
void insert_sort(int array[], int n)
{

}

// 3、快速排序 
void quick_sort(int array[], int low, int high)
{

}

// 4、选择排序
void select_sort(int array[], int n)
{

}

//  5、希尔排序
void shell_sort(int array[],int n,int t)
{

}

// 6、并归排序
void merge_sort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{

}

// 7、堆排序
void heap_sort(int array[], int n)
{

}

// 8、基排序
void radix_sort(int array[], int n)
{

}




}

#endif