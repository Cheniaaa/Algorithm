#include "iostream"
#include "vector"

using namespace std;

int N;
vector<int> PAR;

void init() {
    PAR.resize(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
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
    if (u == v) return;
    PAR[u] = v;
}

void case_1(vector<pair<int, int>> &edge, vector<int> inDegree) {
    vector<pair<int, int>> ans;
    for (auto item: edge) {
        if (inDegree[item.second] == 2) ans.push_back({item.first, item.second});
        else unit(item.first, item.second);
    }
    if (isSame(ans[1].first, ans[1].second) ||
        !isSame(ans[1].first, ans[1].second) && !isSame(ans[0].first, ans[0].second)) {
        cout << ans[1].first << " " << ans[1].second << endl;
    } else {
        cout << ans[0].first << " " << ans[0].second << endl;
    }
}

void case_2(vector<pair<int, int>> &edge) {
    for (auto item: edge) {
        if (isSame(item.first, item.second)) {
            cout << item.first << " " << item.second << endl;
            return;
        } else {
            unit(item.first, item.second);
        }
    }
}

int main() {
    int s, t;
    cin >> N;
    vector<pair<int, int>> edge;
    vector<int> inDegree(N + 1, 0);//存储入度
    bool inc_2_deg = false;//是否包含入度为2的节点
    for (int i = 0; i < N; ++i) {
        cin >> s >> t;
        edge.push_back({s, t});
        inDegree[t]++;
        if (inDegree[t] == 2) inc_2_deg = true;
    }
    init();
    if (inc_2_deg) case_1(edge, inDegree);//包含入度为2节点的情况
    else case_2(edge);//不包含入度为2节点的情况（存在环，使用并查集）
    return 0;
}