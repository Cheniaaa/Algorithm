#include "iostream"
#include "numeric"

using namespace std;

/**
示例 1：
输入：ratings = [1,0,2]
输出：5
解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。

示例 2：
输入：ratings = [1,2,2]
输出：4
解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。

思路：左右分别做一次贪婪遍历
 * @param ratings
 * @return
 */
int candy(vector<int> &ratings) {
    int len = ratings.size();
    vector<int> nums(len, 1);
    for (int l = 1; l < len; ++l) {
        if (ratings[l] > ratings[l - 1]) nums[l] = nums[l - 1] + 1;
    }
    for (int r = len - 2; r >= 0; r--) {
        if (ratings[r] > ratings[r + 1]) nums[r] = max(nums[r], nums[r + 1] + 1);
    }
//    for_each(nums.begin(), nums.end(), [&res](int num) { res += num; });
    auto res = accumulate(nums.begin(), nums.end(), 0);
    return res;
}

int main() {
    vector<int> ratings = {1, 0, 2};
    cout << candy(ratings) << endl;
    return 0;
}