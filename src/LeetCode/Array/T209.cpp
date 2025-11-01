#include <vector>
#include "iostream"

using namespace std;


int minSubArrayLen(int target, vector<int> &nums) {
    int left = 0, res = 0, len = nums.size() + 1;
    int size = nums.size();
    for (int right = 0; right < size; right++) {
        res += nums[right];
        if (res < target) {
            continue;
        } else {
            while (left <= right) {
                if (res - nums[left] < target) {
                    break;
                }
                res -= nums[left++];
            }
            len = min(len, right - left + 1);
        }
    }
    if (res < target) {
        return 0;
    }
    return len;
}


/**
 * 优化版
 * @param s
 * @param nums
 * @return
 */
int minSubArrayLen_improve(int target, vector<int> &nums) {
    int size = nums.size();
    int result = size + 1;
    int sum = 0; // 滑动窗口数值之和
    int left = 0; // 滑动窗口起始位置
    int subLength = 0; // 滑动窗口的长度
    for (int j = 0; j < size; j++) {
        sum += nums[j];
        while (sum >= target) {
            subLength = (j - left + 1); // 取子序列的长度
            result = result < subLength ? result : subLength;
            sum -= nums[left++];
        }
    }
    // 如果result没有被赋值的话，就返回0，说明没有符合条件的子序列
    return result == size + 1 ? 0 : result;
}


int main() {
    vector<int> nums({1, 2, 3, 4, 5});
    int len = minSubArrayLen_improve(11, nums);

    cout << len;
};