/**
* https://leetcode.cn/problems/partition-equal-subset-sum/
 * 分割等和子集
*/
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

bool canPartition(vector<int> &nums) {
    if (nums.size() < 2) return false;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
    }
    if (sum != (sum / 2) * 2) return false;
    int target = sum / 2;

    /**
     * 计算最后结果是否与目标相同
     */
//    vector<int> dp(target + 1, 0);
//    for (int i = 0; i < nums.size(); ++i) {
//        for (int j = target; j >= nums[i]; j--) {
//            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
//        }
//    }
//    if (dp[target] != target) return false;
//    return true;

/**
 * 直接使用布尔值判断
 */
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = target; j >= nums[i]; j--) {
            dp[j] = dp[j] | dp[j - nums[i]];
        }
    }
    return dp[target];
}


int main() {
    vector<int> nums = {1, 5, 11, 5};
//    vector<int> nums = {1, 2, 3, 5};
    cout << canPartition(nums);
}