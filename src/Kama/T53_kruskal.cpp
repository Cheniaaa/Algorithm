#include <algorithm>
#include "iostream"
#include "vector"

using namespace std;

int V;
vector<int> PAR;

struct Edge {
    int u, v, val;
};

void init() {
    PAR.resize(V + 1, 0);
    for (int i = 1; i <= V; ++i) {
        PAR[i] = i;
    }
}

int find(int u) {
    return u == PAR[u] ? u : PAR[u] = find(PAR[u]);
}

bool isSame(int u, int v) {
    return find(u) == find(v);
}

void unit(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) PAR[u] = v;
}

//从小到大
bool cmp(Edge a, Edge b) {
    return a.val < b.val;
}

/**
 * Kruskal是对边操作，保存时需要两个节点和权值
 * Prim是对节点操作，保存可以用邻接矩阵
 * @return
 */
int main() {
    int E, v1, v2, val;
    cin >> V >> E;
    int res = 0;
    vector<Edge> edges;
    while (E--) {
        cin >> v1 >> v2 >> val;
        edges.push_back({v1, v2, val});
    }
    sort(edges.begin(), edges.end(), cmp);
    init();
    for (auto edge: edges) {
        if (!isSame(edge.u, edge.v)) {
            res += edge.val;
            unit(edge.u, edge.v);
        }
    }
    cout << res << endl;
    return 0;
}