/**
* 最大子数组和
 * https://leetcode.cn/problems/maximum-subarray/
*/

#include <vector>
#include "iostream"

using namespace std;

/**
 * 贪心算法
 * @param nums
 * @return
 */
int maxSubArray(vector<int>& nums) {
    int result = INT32_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
        sum += nums[i];
        if (result < sum) {
            result = sum;
        }
        //如果此时总和为负数则加上下一个数相当于拖累下一个数变得更小
        if (sum < 0) {
            sum = 0;
        }
    }
    return result;
}


/**
 * 动态规划
 * @param nums
 * @return
 */
int maxSubArray_dp(vector<int>& nums) {
    int result = INT32_MIN;
    int preSum = 0;
    for (auto &item: nums) {
        //preSum是将此元素的前面元素看作整体时可以达到的最大总和
        preSum = max(preSum + item, item);
        result = max(result, preSum);
    }
    return result;
}

int main(){
    vector<int> nums({-1, 2, 3, 1, -2, -3, 5});
    int res = maxSubArray(nums);
    cout << res;

}