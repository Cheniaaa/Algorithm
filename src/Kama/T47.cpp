#include "iostream"
#include "vector"

using namespace std;


int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        grid[p1][p2] = val;
    }
    int start = 1;//源点
    int end = n;//终点

    // 存储从源点到每个节点的最短距离
    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;
    // 记录顶点是否被访问过
    vector<bool> visited(n + 1, false);

    int cur = start;
    int minVal, minCur;
    for (int i = 1; i <= n; ++i) {
        minVal = INT_MAX;
        minCur = 1;
        visited[cur] = true;
        for (int v = 1; v <= n; ++v) {
            if (!visited[v]) {
                if (grid[cur][v] != INT_MAX && minDist[v] > minDist[cur] + grid[cur][v]) {
                    minDist[v] = minDist[cur] + grid[cur][v];
                }
                if (minDist[v] < minVal) {
                    minCur = v;
                    minVal = minDist[v];
                }
            }
        }
        cur = minCur;
    }
    if (minDist[end] == INT_MAX) cout << -1 << endl; // 不能到达终点
    else cout << minDist[end] << endl; // 到达终点最短路径
    return 0;
}