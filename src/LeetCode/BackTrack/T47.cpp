/**
* 全排列2
*/
#include <vector>
#include <algorithm>
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
        /*
         * 难点：去重的判断条件
         * 此处used[i - 1] == false 和 used[i - 1] == true的结果相同
         * 但是used[i - 1] == false的效率更高，used[i - 1] == true无效搜索量过大
         * used[i - 1] == false以层为主，used[i - 1] == true以迭代为主
         */
        if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
            //此处的条件为前一个元素与当前元素相同，且前一个元素已经回溯
            continue;
        }
        if (!used[i]) {
            temp.push_back(nums[i]);
            used[i] = !used[i];
            backtracking(nums, used);
            temp.pop_back();
            used[i] = !used[i];
        }
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<bool> used(nums.size(), false);
    backtracking(nums, used);
    return res;
}

int main() {
    vector<int> nums({1, 1, 3});
    vector<vector<int>> result = permuteUnique(nums);
    for (auto &items: result) {
        for (auto &item: items) {
            cout << item << '\t';
        }
        cout << '\n';
    }
};