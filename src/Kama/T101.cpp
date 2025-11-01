#include <iostream>
#include <vector>

using namespace std;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1}; // 保存四个方向
/**
输入：
4 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
输出：1
 * @return
 */
void dfs(vector<vector<int>> &grid, int x, int y) {
    grid[x][y] = 0;//将与边缘接触的陆地都变为海洋
    for (int i = 0; i < 4; ++i) {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
        // 超过边界
        if (nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;
        if (grid[nextX][nextY] == 1) dfs(grid, nextX, nextY);
    }

}

/**
 * 要找出边缘接触的岛屿，只需要遍历边缘一圈同时向中间将满足条件的岛屿变成海洋
 * @param grid
 * @return
 */
int travel(vector<vector<int>> &grid) {
    int height = grid.size();
    int wight = grid[0].size();
    //遍历左右边缘
    for (int i = 0; i < height; ++i) {
        if (grid[i][0] == 1) dfs(grid, i, 0);
        if (grid[i][wight - 1] == 1) dfs(grid, i, wight - 1);
    }
    for (int i = 1; i < wight - 1; ++i) {
        if (grid[0][i] == 1) dfs(grid, 0, i);
        if (grid[height - 1][i] == 1) dfs(grid, height - 1, i);
    }

    int res = 0;//孤岛总面积
    //遍历整个图，统计所有1就是孤岛总面积
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < wight; ++j) {
            if (grid[i][j] == 1) res++;
        }
    }
    return res;
}


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << travel(grid) << endl;
    return 0;
}