/**
 * https://kamacoder.com/problempage.php?pid=1152
 * 城市间货物运输 I
 */
#include "iostream"
#include "vector"
#include "list"
#include "queue"
using namespace std;

struct Edge{
    int toNode;
    int val;
    Edge(int toNode, int val) : toNode(toNode), val(val) {}
};

/**
 * Bellman_ford队列优化法（SPFA）
 * 使用队列记录已松弛的边对应节点，避免多数不必要松弛，图需要用到邻接表
 * @return
 */
int main(){
    int n, m, p1, p2, val;
    cin >> n >> m;
    vector<list<Edge>> grid(n + 1);
    vector<bool> inQue(n + 1, false);
    queue<int> queue;
    // 将所有边保存起来
    for(int i = 0; i < m; i++){
        cin >> p1 >> p2 >> val;
        // p1 指向 p2，权值为 val
        grid[p1].push_back(Edge(p2, val));
    }
    int start = 1;  // 起点
    int end = n;    // 终点

    vector<int> minDist(n + 1 , INT_MAX);
    minDist[start] = 0;
    queue.push(start);

    while (!queue.empty()) {//题目给出无负权回路因此循环可以正常退出
        int node=queue.front();
        queue.pop();
        inQue[node] = false;
        for (auto &item: grid[node]) {
            int from = node;
            int to = item.toNode;
            int v = item.val;
            if (minDist[from] != INT_MAX && minDist[to] > minDist[from] + v) {
                minDist[to] = minDist[from] + v;
                if (inQue[to] == false) {
                    queue.push(to);
                    inQue[to] = true;
                }
            }
        }
    }
    if (minDist[end]==INT_MAX) cout << "unconnected" << endl;
    else cout << minDist[end] << endl;
    return 0;
}