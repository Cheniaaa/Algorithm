#include <vector>
#include "iostream"

using namespace std;

/**
 * 局部贪心推广到全局贪心
 * @param nums
 * @return
 */
int wiggleMaxLength(vector<int> &nums) {
    if (nums.size() <= 1) return nums.size();
    int len = nums.size();
    int curDiff = 0;
    int preDiff = 0;
    int res = 1;//至少有一个（右边）
    for (int i = 0; i < len - 1; ++i) {
        curDiff = nums[i + 1] - nums[i];
        if (preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0) {
            res++;
            preDiff = curDiff;
        }
    }
    return res;
}

int main() {
    vector<int> num = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << wiggleMaxLength(num);
    return 0;
}