#include "iostream"
#include "vector"

using namespace std;
int n, m;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};

void dfs(vector<vector<int> > &grid, vector<vector<bool> > &visited, int X, int Y) {
    if (visited[X][Y]) return;
    visited[X][Y] = true;
    for (int i = 0; i < 4; ++i) {
        int nextX = X + dir[i][0];
        int nextY = Y + dir[i][1];
        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
        if (grid[nextX][nextY] < grid[X][Y]) continue; //因为反向判断
        dfs(grid, visited, nextX, nextY);
    }
}

/**
 * 法一：遍历全部节点，使用dfs和bfs判断是否能到达第一组和第二组边界（超时）
 * 法二：只遍历边缘节点，反向思维，寻找两组边界都能到达的节点
 * @param grid
 */
void travel(vector<vector<int> > &grid) {
    vector<vector<bool> > visited_1(n, vector<bool>(m, false));
    vector<vector<bool> > visited_2(n, vector<bool>(m, false));
    //左右
    for (int i = 0; i < n; ++i) {
        dfs(grid, visited_1, i, 0);
        dfs(grid, visited_2, i, m - 1);
    }
    for (int i = 0; i < m; ++i) {
        dfs(grid, visited_1, 0, i);
        dfs(grid, visited_2, n - 1, i);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (visited_1[i][j] && visited_2[i][j]) cout << i << " " << j << endl;
        }
    }
}

int main() {
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    travel(grid);
    return 0;
}

/**
 输入示例
5 5
1 3 1 2 4
1 2 1 3 2
2 4 7 2 1
4 5 6 1 1
1 4 1 2 1
输出示例
0 4
1 3
2 2
3 0
3 1
3 2
4 0
4 1
 */
