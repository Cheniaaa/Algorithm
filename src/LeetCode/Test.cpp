#include "iostream"
#include "bits/stdc++.h"

using namespace std;

typedef struct node {
    int x;
    int y;
} node;


void init(vector<int> &cities) {
    for (int i = 0; i < cities.size(); i++) {
        cities[i] = i;
    }
}

int find(vector<int> &cities, int x) {
    return x == cities[x] ? x : cities[x] = find(cities, cities[x]);
}

void Union(vector<int> &cities, int x, int y, vector<int> &rank) {
    int fx = find(cities, x);
    int fy = find(cities, y);
    if (fx == fy) return;
    if (rank[fx] > rank[fy]) cities[fy] = fx;
    else {
        if (rank[fx] == rank[fy]) rank[fy]++;
        cities[fx] = fy;
    }
}

int updateNum(vector<int> cities, vector<int> del) {
    int num = 0;
    for (int i = 0; i < cities.size(); i++) {
        if (cities[i] == i && del[i] == 0) num++;
    }
    return num;
}

int main() {
    int n, m, k, pre = 0, num = 0;
    cin >> n >> m;
    vector<int> cities(n, 0);
    vector<int> rank(n, 0);
    init(cities);
    vector<int> del(n, 0);
    vector <node> edge(m);
    for (int i = 0; i < m; i++) {
        cin >> edge[i].x >> edge[i].y;
        Union(cities, edge[i].x, edge[i].y, rank);
    }
    pre = updateNum(cities, del);
    cin >> k;
    int city;
    for (int i = 0; i < k; i++) {
        cin >> city;
        del[city] = 1;
        init(cities);
        rank.assign(n, 0);
        for (int i = 0; i < m; i++) {
            if (del[edge[i].x] != 1 && del[edge[i].y] != 1) Union(cities, edge[i].x, edge[i].y, rank);
        }
        num = updateNum(cities, del);
        // cout<<pre<<" "<<num<<endl;
        if (num > pre) cout << "Red Alert: City " << city << " is lost!" << endl;
        else cout << "City " << city << " is lost." << endl;
        if (i == n - 1) cout << "Game Over." << endl;
        pre = num;
    }
    return 0;
}
