/**
 * 分饼干
 * https://leetcode.cn/problems/assign-cookies/
 */
#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;


int findContentChildren(vector<int> &g, vector<int> &s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int index = s.size() - 1;
    for (int i = g.size() - 1; i >= 0; i--) {
        if (index < 0) {
            return s.size();
        }
        if (s[index] >= g[i]) {
            index--;
        }
    }
    return s.size() - index - 1;
}

int main() {
    vector<int> s({1, 3, 5, 9});
    vector<int> g({1, 2, 7, 10});
    int res = findContentChildren(g, s);
    cout << res;

}