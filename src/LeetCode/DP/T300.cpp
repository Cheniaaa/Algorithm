#include <algorithm>
#include "iostream"
#include "vector"

using namespace std;

/**
 * DP动态规划
 * @param nums
 * @return
 */
int lengthOfLIS(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) return 0;
    vector<int> dp(len, 1);
    for (int i = 0; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

/**
 * 使用贪心和二分进行优化，时间复杂度：O(nlogn)
 * 注意：最后获得的数组实际并不是正确序列，只是长度相同
 * @param nums
 * @return
 */
int lengthOfLIS_Optimize(vector<int> &nums) {
    int len = nums.size();
    if (len == 0) return 0;
    vector<int> res(len, INT_MAX);
    for (auto &num: nums) {
//        前提是有序的情况下，lower_bound 返回第一个大于等于val值的位置。（通过二分查找）
        res[lower_bound(res.begin(), res.end(), num) - res.begin()] = num;
    }
    return lower_bound(res.begin(), res.end(), INT_MAX) - res.begin();
}


int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << lengthOfLIS(nums) << endl;
    cout << lengthOfLIS_Optimize(nums) << endl;
    return 0;
}