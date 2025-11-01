/**
* 岛屿数量
 * https://leetcode.cn/problems/number-of-islands/description/
*/

#include <vector>
#include <deque>
#include "iostream"

using namespace std;


/**
 * 深度优先算法
 * @param grid
 * @param row
 * @param line
 * @param visited
 */
void dfs(vector<vector<char>> &grid, int row, int line, vector<vector<bool>> &visited) {

    //回溯条件
    if (row < 0 || line < 0 || row >= grid.size() || line >= grid[0].size() || visited[row][line] ||
        grid[row][line] == '0')
        return;

    //符合条件
    visited[row][line] = true;
    dfs(grid, row - 1, line, visited);
    dfs(grid, row + 1, line, visited);
    dfs(grid, row, line + 1, visited);
    dfs(grid, row, line - 1, visited);
}


/**
 * 广度优先算法
 * @param grid
 * @param row
 * @param line
 * @param visited
 */
void bfs(vector<vector<char>> &grid, int row, int line, vector<vector<bool>> &visited) {
    deque<pair<int, int>> deque;
    deque.push_back({row, line});
    visited[row][line] = true;
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    while (!deque.empty()) {
        pair<int, int> cur = deque.front();
        deque.pop_front();
        for (int i = 0; i < 4; ++i) {
            int next_x = cur.first + dir[i][0];
            int next_y = cur.second + dir[i][1];
            if (next_x < 0 || next_y < 0 || next_x >= grid.size() || next_y >= grid[0].size()) continue;
            if (!visited[next_x][next_y] && grid[next_x][next_y] == '1') {
                deque.push_back({next_x, next_y});
                visited[next_x][next_y] = true;
            }
        }
    }
}


int numIslands(vector<vector<char>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int num = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                num++;
//                dfs(grid, i, j, visited);
                bfs(grid, i, j, visited);
            }
        }
    }
    return num;
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
