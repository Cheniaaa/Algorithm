#include <vector>
#include "iostream"

using namespace std;

/**
 * 贪心算法：局部最优推广到全局最优
 * 局部最优：假设每一步跨越到最远的位置
 * @param nums
 * @return
 */
int jump(vector<int> &nums) {
    int len = nums.size();
    int maxIndex = 0;
    int curIndex = 0;
    int res = 0;
    for (int i = 0; i < len - 1; ++i) {
        maxIndex = max(maxIndex, nums[i] + i);
        if (i == curIndex) {//当前一步已经走到了最远处
            res++;
            curIndex = maxIndex;
            if (maxIndex >= len - 1) break;
        }
    }
    return res;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums);
}


