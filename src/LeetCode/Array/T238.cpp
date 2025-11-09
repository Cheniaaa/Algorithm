#include "iostream"

using namespace std;

/**
示例 1:
输入: nums = [1,2,3,4]
输出: [24,12,8,6]

示例 2:
输入: nums = [-1,1,0,-3,3]
输出: [0,0,9,0,0]

思路：对于每个数两侧的乘积都有重合的部分，利用存储重合部分降低时间复杂度
 * @param nums
 * @return
 */
vector<int> productExceptSelf(vector<int>& nums) {
    int len = nums.size();
    vector<int> res(len);
    int lp = 1, rp = 1;// 对于两侧的数的左侧和右侧分别可认为是1
    // 计算左侧
    for (int l = 0; l < len; ++l) {
        res[l] = lp;// 存储此位置左侧乘积
        lp *= nums[l];
    }
    // 计算右侧
    for (int r = len - 1; r >= 0; r--) {
        res[r] *= rp;// 相当于此位置左侧*右侧
        rp *= nums[r];
    }
    return res;
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}