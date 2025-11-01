#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int n, m;
int count;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; // 四个方向

void dfs(vector<vector<int> > &grid, int x, int y, int mark) {
    grid[x][y] = mark;
    count++;
    for (int i = 0; i < 4; ++i) {
        int nextX = x + dir[i][1]; // 计算相邻坐标
        int nextY = y + dir[i][0];
        if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= m) continue;
        if (grid[nextX][nextY] == 1) dfs(grid, nextX, nextY, mark);
    }
}

int biggestSquare(vector<vector<int> > &grid, unordered_map<int, int> gridNum) {
    int res = 0;
    unordered_set<int> visited;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            count = 1; //算上自己
            visited.clear();
            if (grid[i][j] != 0) continue;
            for (int k = 0; k < 4; ++k) {
                int nearX = i + dir[k][1]; // 计算相邻坐标
                int nearY = j + dir[k][0];
                if (nearX < 0 || nearX >= n || nearY < 0 || nearY >= m || visited.count(grid[nearX][nearY])) continue;
                count += gridNum[grid[nearX][nearY]];
                visited.insert(grid[nearX][nearY]);
            }
            res = max(res, count);
        }
    }
    return res;
}

int main() {
    cin >> n >> m;
    vector<vector<int> > grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    unordered_map<int, int> gridNum; //记录各岛屿面积
    int mark = 2; //不同岛屿用不同数字标记
    bool isAllLand = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 0) isAllLand = false;
            if (grid[i][j] == 1) {
                count = 0;
                dfs(grid, i, j, mark);
                gridNum[mark] = count;
                mark++;
            }
        }
    }
    //全图都是陆地
    if (isAllLand) {
        cout << n * m << endl;
        return 0;
    }
    int res = biggestSquare(grid, gridNum);
    cout << res << endl;
    return 0;
}
