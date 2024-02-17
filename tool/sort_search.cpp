#include <iostream>
#include <vector>
#include <queue>

/**
 * 搜索
*/
using vector2 = std::vector<std::vector<int>>;

bool DFSUtil(int x, int y, int n, int m, const vector2& array, vector2& judge, std::vector<std::pair<int, int>>& path) {
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
bool DFS(vector2 array) {
    bool find_flag = false;
    int n = array.size(), m;
    if( n == 0 ) {
        std::cout << "Err: array size n==0\n";
        return false;
    }
    m = array[0].size();
    if( m == 0 ) {
        std::cout << "Err: array size m==0\n";
        return false;
    }
    vector2 judge(n, std::vector<int>(m, 0));
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
bool BFS(vector2 array) {
    bool find_flag = false;
    int n = array.size();
    if (n == 0) return false;
    int m = array[0].size();
    if (m == 0) return false;

    vector2 judge(n, std::vector<int>(m, 0));
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> path;

    // 添加起点进入队列
    if(array[0][0] == 0) return false; 
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



/**
 * 搜素算法测试
*/
std::vector<std::vector<int>> genrate_rand_array() {
    std::vector<std::vector<int>> ret;
    // 使用当前时间作为随机数生成器的种子
    srand((unsigned) time(NULL));
    //int n = rand()%20+1;
    //int m = rand()%20+1;
    int n = 5, m = 7;
    std::cout <<  "n: " << n << " m: " << m << std::endl;
    ret.resize(n);
    for(int i=0; i<n; i++)
    {
        std::cout << "[ ";
        ret[i].reserve(m);
        for(int j=0; j<m; j++)
        {
            int t = rand()%2;
            ret[i].push_back(t);
            std::cout << t << ", ";
        }
        std::cout << "]" << std::endl;
    }
    return ret;
}

// 算法测试
void test_DFS_BFS() {
#if 0
    std::vector<std::vector<int>> array = genrate_rand_array();
#else
    std::vector<std::vector<int>> array = {
        {1, 1, 1, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 0, 1, 0},  
        {1, 0, 0, 1, 0, 0, 0},  
        {0, 1, 0, 1, 1, 1, 1}
    };
#endif
    std::cout << std::boolalpha << "DFS find path result: " << DFS(array) << std::endl;
    std::cout << "BFS find path result: " << BFS(array) << std::endl;
    std::cout << std::noboolalpha << std::endl;
}

// 测试函数入口
int main(int argc, char *argv[]) {
    test_DFS_BFS();
    return 0;
}