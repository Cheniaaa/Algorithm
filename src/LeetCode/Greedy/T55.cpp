#include <vector>
#include "iostream"

using namespace std;

bool canJump(vector<int> &nums) {
    int len = nums.size();
    int maxIndex = 0;
    int curIndex = 0;

    while (curIndex <= maxIndex) {
        if (maxIndex >= len - 1) return true;
        if (nums[curIndex] + curIndex > maxIndex) {
            maxIndex = nums[curIndex] + curIndex;
        }
        curIndex++;
    }
    if (curIndex > maxIndex) {
        return false;
    }
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << canJump(nums) << endl;

    nums = {3, 2, 1, 0, 4};
    cout << canJump(nums);
}