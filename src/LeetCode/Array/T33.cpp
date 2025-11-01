#include <vector>
#include "iostream"

using namespace std;


int search(vector<int> &nums, int target) {
    int len = nums.size();
    if (!len) {
        return -1;
    }
    if (len == 1) {
        return target == nums[0] ? 0 : -1;
    }

    int l = 0, r = len - 1, mid = 0;
    while (l <= r) {
        mid = (l + r) / 2;
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[0] <= nums[mid]) {
            if (target < nums[mid] && target >= nums[0]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[len - 1]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }
    return -1;
}


int main() {
    vector<int> nums;
    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0);
}