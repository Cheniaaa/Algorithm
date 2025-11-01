/**
* 全排列
*/
#include <vector>
#include "iostream"

using namespace std;

vector<vector<int>> res;
vector<int> temp;

void backtracking(vector<int> &nums, vector<bool> &used) {
    if (temp.size() == nums.size()) {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (used[i]) {
            continue;
        }
        temp.push_back(nums[i]);
        used[i] = !used[i];
        backtracking(nums, used);
        temp.pop_back();
        used[i] = !used[i];
    }
}

vector<vector<int>> permute(vector<int> &nums) {
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}

int main() {
    vector<int> nums({1, 2, 3});
    vector<vector<int>> result = permute(nums);
    for (auto &items: result) {
        for (auto &item: items) {
            cout << item << '\t';
        }
        cout << '\n';
    }
};