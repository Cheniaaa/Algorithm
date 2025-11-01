#include "iostream"
#include <vector>
#include <list>
#include <queue>
#include <climits>

using namespace std;

// 定义一个结构体来表示带权重的边
struct Edge {
    int to;  // 邻接顶点
    int val; // 边的权重

    Edge(int t, int w) : to(t), val(w) {}  // 构造函数
};


/**
 * 法一：自定义比较器（使用struct或者class），重载内部函数对象
 * 法二：重载自定义结构体的运算符，再使用默认的比较器
 * 法三：使用lambda函数
 */
struct cmp {
    bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
        return lhs.second > rhs.second;
    }
};


int main() {
    int n, m, p1, p2, val;
    cin >> n >> m;

    vector<list<Edge>> grid(n + 1);
    for (int i = 0; i < m; i++) {
        cin >> p1 >> p2 >> val;
        // p1 指向 p2，权值为 val
        grid[p1].push_back(Edge(p2, val));

    }

    int start = 1;  // 起点
    int end = n;    // 终点

    // 存储从源点到每个节点的最短距离
    vector<int> minDist(n + 1, INT_MAX);
    minDist[start] = 0;
    // 记录顶点是否被访问过
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push(pair<int, int>(start, 0));

    /**
     * Tips:
     * 不需要clear堆，每次只压入修改过的边
     * 对于此轮修改的边，压入堆，一定是小于堆中之前压入的同一条边的val，所以不影响
     * 对于此轮未修改的边，不压入堆，堆中可能已经包含此条边的值
     */
    while (!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (visited[cur.first]) continue;
        visited[cur.first] = true;
        for (auto &edge: grid[cur.first]) {
            if (!visited[edge.to] && minDist[edge.to] > cur.second + edge.val) {
                minDist[edge.to] = cur.second + edge.val;
                //若只压入修改过的，就不需要clear堆；如果压入全部未访问的边，则重复的过多，不过可以每次都clear，但是要修改逻辑
                pq.push(pair<int, int>(edge.to, minDist[edge.to]));
            }
        }
    }
    if (minDist[end] == INT_MAX) cout << -1 << endl; // 不能到达终点
    else cout << minDist[end] << endl; // 到达终点最短路径
    return 0;
}