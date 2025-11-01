#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty()) {
        return {};
    }
    vector<vector<int>> vector;
    int left, right;
    sort(intervals.begin(), intervals.end(), [](::vector<int> a, ::vector<int> b) { return a[0] < b[0]; });
    for (int i = 0; i < intervals.size(); ++i) {
        left = intervals[i][0];
        right = intervals[i][1];
        /*
         * vector.back()返回末尾的元素
         * vector.pop_back()删除末尾元素
         *  vector.push_back()增加元素到末尾
         * */
        if (vector.empty() || vector.back()[1] < left) {
            vector.push_back({left, right});
        } else {
            vector.back()[1] = max(vector.back()[1], right);
        }
    }
    return vector;
}

int main() {

    vector<vector<int>> list = {{1, 5},
                                {2, 4},
                                {6, 7},
                                {7, 9},
                                {8, 10}};
    vector<vector<int>> result = merge(list);
    for (auto &item: result) {
        cout << '[' << item[0] << ',' << item[1] << ']' << '\t';
    }

};