/**
* 岛屿数量
 * https://leetcode.cn/problems/number-of-islands/description/
 * 并查集
*/

#include <vector>
#include "iostream"

using namespace std;

vector<int> PAR;//也可以使用二维
vector<int> RANK;//高度
int count = 0;

/**
 * 初始化
 * 每个1位置的父节点都初始化本身
 * 将1的地方都当作岛屿并统计量加一
 * @param grid
 */
void init(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                PAR.push_back(i * n + j);
                ++count;
            } else {
                PAR.push_back(-1);
            }
            RANK.push_back(0);
        }
    }
}

/**
 * 查询父节点
 * @param i
 * @return
 */
int find(int i) {
    if (PAR[i] == i) {
        return i;
    }
    return find(PAR[i]);
}

/**
 * 合并节点并减少一个岛屿数量
 * @param x
 * @param y
 */
void unit(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;//父节点相同（属于同一个集合）
    //合并到高度高的集合
    if (RANK[x] < RANK[y]) {
        PAR[x] = y;
    } else {
        if (RANK[x] == RANK[y]) {
            RANK[x]++;
        }
        PAR[y] = x;
    }
    count--;
}

int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    init(grid);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1') {
                grid[i][j] = '0';
                if (i - 1 >= 0 && grid[i - 1][j] == '1') unit(i * n + j, (i - 1) * n + j);
                if (i + 1 < m && grid[i + 1][j] == '1') unit(i * n + j, (i + 1) * n + j);
                if (j - 1 >= 0 && grid[i][j - 1] == '1') unit(i * n + j, i * n + j - 1);
                if (j + 1 < n && grid[i][j + 1] == '1') unit(i * n + j, i * n + j + 1);
            }
        }
    }
    return count;
}


int main() {
    vector<vector<char>> grid({
                                      {'1', '1', '0', '0', '0'},
                                      {'1', '1', '0', '0', '0'},
                                      {'0', '0', '1', '0', '0'},
                                      {'0', '0', '0', '1', '1'}
                              }
    );
    cout << numIslands(grid);
}