#ifndef _SORT_TOOL_H__
#define _SORT_TOOL_H__
#include <vector>
#include <queue>

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

using vector2 = std::vector<std::vector<int>>;

bool DFSUtil(int x, int y, int n, int m, const std::vector<std::vector<int>>& array, std::vector<std::vector<int>>& judge, std::vector<std::pair<int, int>>& path) {
    // 如果到达了最后一个点，记录点并返回成功
    if (x == n - 1 && y == m - 1) {
        judge[x][y] = 1;
        if(array[x][y] == 1){
            path.push_back({x, y}); // 添加终点到路径
            return true;
        }
        else{
            return false;
        }
    }
    // 超出范围或者是不可访问的点
    if(x < 0 || x >= n || y < 0 || y >= m || array[x][y] == 0 || judge[x][y] == 1){
        return false;
    }

    // 标记当前节点为路径的一部分
    judge[x][y] = 1;
    path.push_back({x, y}); // 添加当前点到路径

    // 向右移动
    if (DFSUtil(x + 1, y, n, m, array, judge, path)) return true;

    // 向下移动
    if (DFSUtil(x, y + 1, n, m, array, judge, path)) return true;

    // 如果这条路线不成功，反标记[x][y]并从路径中移除
    judge[x][y] = 0;
    path.pop_back(); // 移除当前点

    // 如果没有找到路径，返回失败
    return false;
}

// 深度搜素，用于查找是否联通等
bool DFS(std::vector<std::vector<int>> array)
{
    bool find_flag = false;
    int n = array.size(), m;
    if( n == 0 )
        return false;
    m = array[0].size();
    if( m == 0 )
        return false;
    std::vector<std::vector<int>> judge(n, std::vector<int>(m, 0));
    std::vector<std::pair<int, int>> path;
    if(DFSUtil(0, 0, n, m, array, judge, path))
    {
        find_flag = true;
        std::cout << "Path found:\n";
        for (const auto& p : path)
            std::cout << '(' << p.first << ',' << p.second << ") -> ";
        std::cout << "END" << std::endl;
    } else {
        std::cout << "No path found" << std::endl;
        for (const auto& p : path)
            std::cout << '(' << p.first << ',' << p.second << ") -> ";
    }

    return find_flag;
}

// 广度搜素，用于查找最优解
bool BFS(std::vector<std::vector<int>> array)
{
    bool find_flag = false;
    int n = array.size();
    if (n == 0) return false;
    int m = array[0].size();
    if (m == 0) return false;

    std::vector<std::vector<int>> judge(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> path;

    // 添加起点进入队列
    q.push({0, 0});
    judge[0][0] = 1; // 标记起点已访问

    // 方向数组，表示相邻的四个方向（上下左右）
    int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    while (!q.empty()) {
        auto p = q.front(); q.pop();
        int x = p.first, y = p.second;
        path.push_back(p); // 将当前点加入路径

        // 如果到达终点
        if (x == n - 1 && y == m - 1) {
            find_flag = true;
            break;
        }

        // 探索相邻节点
        for (auto& dir : dirs) {
            int next_x = x + dir[0];
            int next_y = y + dir[1];

            // 检查新位置是否可访问并且未被访问过
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < m && array[next_x][next_y] == 1 && judge[next_x][next_y] == 0) {
                q.push({next_x, next_y});
                judge[next_x][next_y] = 1; // 标记为已访问
            }
        }
    }

    if(find_flag){
        std::cout << "Path found:\n";
        for (const auto& p : path)
            std::cout << '(' << p.first << ',' << p.second << ") -> ";
        std::cout << "END" << std::endl;
    } 
    else{
        std::cout << "No path found" << std::endl;
    }
    // 找不到路径
    path.clear();
    return find_flag;
}

/*
1、冒泡:遍历 比较大的交换到后面，每次后面都是排好的（所有数）。
2、插入:先排好前面，每次后面往比前面小交换，直到到前面比他小，前面是排好的（已排索引号前的数）。
3、快排:每次选取一个数据，将所有比它小的数都放到它的左边，所有比它大的数都放到它的右边。
4、选择:对每个下标i,从i后面的元素中选择最小的那个和s[i]交换，前面是排好（所有数）
5、希尔:先按间距n/2 ... 2 1个数据分组进行插入排序（也可以按3k+1个元素这样分组）
6、并归:分别n/2...分组，最小组先排，小组组成大组排序，最后整个排序。
7、堆:近似完全二叉树，
    (1)最后子节点往上排，最大点在顶点，次最大点在顶点左右子叶中
	(2)最大点放到最后;剩下的点从顶排序，次最大点会移到顶点，顺着次最大所在子叶会重排
	(3)接着2排到最后
	i的子节点2*i+1 / 2*i+2
8、基: 将数据按位数切割成不同的数字，然后按每个位数分别比较排序，先排个，十，百，千，万顺序
*/

// 1、冒泡排序
void bubble_sort(int array[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - 1 - i; j++)
        {
            if(array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// 2、插入排序
void insert_sort(int array[], int n)
{
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        temp = array[i];
        for(j = i; j > 0 && array[j - 1] > temp; j--)
        {
            array[j] = array[j - 1];
        }
        array[j] = temp;
    }
}

// 3、快速排序 
void quick_sort(int array[], int low, int high)
{
    if(low >= high){
        return;
    }
    int first = low;
    int last  = high;
    int key   = array[first];/*用字表的第一个记录作为枢轴*/
 
    while(first < last)
    {
        while(first < last && array[last] >= key)
        {
            --last;
        }
 
        array[first] = array[last];/*将比第一个小的移到低端*/
 
        while(first < last && array[first] <= key)
        {
            ++first;
        }
         
        array[last] = array[first];/*将比第一个大的移到高端*/
    }
    array[first] = key;/*枢轴记录到位*/
    quick_sort(array, low, first-1);
    quick_sort(array, first+1, high);
}

// 4、选择排序
void select_sort(int array[], int n)
{
    int i,j, min, temp;
    for(i = 0; i < n-1; i++)
    {
        min = i;//查找最小值
        for(j = i + 1; j < n; j++)
        {
            if(array[min] > array[j])
                min = j;//交换
        }
        if(min != i)
        {
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
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