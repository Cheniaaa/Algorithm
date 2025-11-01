#include "iostream"
#include "vector"

using namespace std;

int v;

/**
 * 两种写法：
 * 1.不指定初始节点，先找出minDist中最小权值对应的节点再更新minDist
 * 2.默认一个节点为起始，先更新minDist再找出下一个最小权值对应的节点
 * @param grid
 * @param minDist
 * @param isInTree
 * @param cur
 * @return
 */
int prim(vector<vector<int>> &grid, vector<int> &minDist, vector<bool> &isInTree, int cur) {
    int minDis = INT_MAX, minIndex = 1;
    for (int i = 1; i <= v; ++i) {
        if (!isInTree[i]) {
            if (grid[cur][i] < minDist[i]) minDist[i] = grid[cur][i];
            if (minDist[i] < minDis) {
                minDis = minDist[i];
                minIndex = i;
            }
        }
    }
    return minIndex;
}

int main() {
    int e, v1, v2, val;
    cin >> v >> e;
    vector<vector<int>> grid(v + 1, (vector<int>(v + 1, 10001)));
    vector<int> minDist(v + 1, 10001);//minDist的含义是节点到最小生成树的边的权值
    vector<bool> isInTree(v + 1, false);
    for (int i = 0; i < e; ++i) {
        cin >> v1 >> v2 >> val;
        grid[v1][v2] = grid[v2][v1] = val;
    }

    int cur = 1;//指定最小生成树的第一个节点
    //循环v-1次，建立v-1条边
    for (int i = 1; i < v; ++i) {
        isInTree[cur] = true;
        cur = prim(grid, minDist, isInTree, cur);
    }
    int res = 0;
    for (int i = 2; i <= v; ++i) {
        res += minDist[i];
    }
    cout << res << endl;
    return 0;
}
