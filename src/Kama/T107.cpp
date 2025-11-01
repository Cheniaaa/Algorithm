#include "iostream"
#include "vector"

using namespace std;

int N;
vector<int> Par;


void init() {
    Par.resize(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        Par[i] = i;
    }
}

//寻找父节点（包含路径压缩）
int find(int u) {
    return u == Par[u] ? u : Par[u] = find(Par[u]);
}

bool isSame(int source, int destination) {
    return find(source) == find(destination);
}

void unit(int s, int t) {
    s = find(s);
    t = find(t);
    if (s == t) return;
    Par[s] = t;
}


int main() {
    int M, s, t, source, destination;
    cin >> N >> M;
    init();
    while (M--) {
        cin >> s >> t;
        unit(s, t);
    }
    cin >> source >> destination;
    if (isSame(source, destination)) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}

