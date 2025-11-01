/**
* 组合
* 范围 [1, n] 中所有可能的 k 个数的组合
*/
#include <vector>
#include "iostream"

using namespace std;


vector<vector<int>> res;
vector<int> temp;

void backtracking(int n, int k, int index) {
    if (temp.size() == k) {
        res.push_back(temp);
        return;
    }
    //执行回溯
//    for (int i = index; i <= n; ++i) {
//        temp.push_back(i);
//        backtracking(n, k, i + 1);
//        temp.pop_back();
//    }

//优化(剪枝后续数据不足的情况)
    for (int i = index; i <= n - (k - temp.size()) + 1; ++i) {
        temp.push_back(i);
        backtracking(n, k, i + 1);
        temp.pop_back();
    }
}


vector<vector<int>> combine(int n, int k) {
    backtracking(n, k, 1);
    return res;
}

int main() {
    vector<vector<int>> res = combine(4, 2);
    for (auto &items: res) {
        for (auto &item: items) {
            cout << item << '\t';
        }
        cout << endl;
    }
}