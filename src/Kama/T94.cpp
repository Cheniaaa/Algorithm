/**
 * https://kamacoder.com/problempage.php?pid=1152
 * 城市间货物运输 I
 */
#include "iostream"
#include "vector"

using namespace std;

/**
 * Bellman_ford法
 * n-1次松弛
 * @return
 */
int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<vector<int>> grid;
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        // p1 指向 p2，权值为 val
        grid.push_back({p1, p2, val});
    }
    int start = 1;  // 起点
    int end = n;    // 终点
    vector<int> minDistance(n + 1, INT_MAX);
    minDistance[start] = 0;
    for (int i = 1; i < n; ++i) {//对所有边进行n-1次松弛
        for (auto &item: grid) {
            int from = item[0];
            int to = item[1];
            int v = item[2];
            if (minDistance[from] != INT_MAX && minDistance[to] > minDistance[from] + v) {
                minDistance[to] = minDistance[from] + v;
            }
        }
    }
    if (minDistance[end]==INT_MAX) cout << "unconnected" << endl;
    else cout << minDistance[end] << endl;
    return 0;
}