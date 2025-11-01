#include "iostream"
#include "vector"
#include "list"
using namespace std;


void dfs(vector<list<int> > grid, int node, vector<bool> &visted) {
    if (visted[node]) return;
    visted[node] = true;
    for (int toNode: grid[node]) dfs(grid, toNode, visted);
}

int main() {
    int N, K;
    cin >> N >> K;
    int fromNode, toNode;
    vector<list<int> > grid(N + 1);
    for (int i = 0; i < K; ++i) {
        cin >> fromNode >> toNode;
        grid[fromNode].push_back(toNode);
    }
    vector<bool> visited(N + 1, false);
    dfs(grid, 1, visited);
    for (int i = 1; i <= N; ++i) {
        if (visited[i] == false) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
    return 0;
}
