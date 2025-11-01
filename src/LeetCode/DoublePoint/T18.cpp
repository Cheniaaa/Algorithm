/**
 * 四数之和
 */

#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

/**
 * 在三数之和的基础上多一层for，四个数的顺序 k，i，left，right
 * @param nums
 * @param target
 * @return
 */
vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    int left = 0, right = 0;
    sort(nums.begin(), nums.end());
    for (int k = 0; k < nums.size(); ++k) {
        if (nums[k] > target && nums[k] >= 0) {
            break;
        }
        if (k > 0 && nums[k] == nums[k - 1]) {
            continue;
        }
        //第二个数
        for (int i = k + 1; i < nums.size(); ++i) {
            if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                break;
            }
            if (i > k + 1 && nums[i] == nums[i - 1]) {
                continue;
            }

            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                    right--;
                } else if ((long) nums[k] + nums[i] + nums[left] + nums[right] < target) {
                    left++;
                } else {
                    res.push_back(vector<int>({nums[k], nums[i], nums[left], nums[right]}));

                    //去重
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> nums({1, 0, -1, 0, -2, 2});
    vector<vector<int>> res = fourSum(nums, 0);
    for (auto &items: res) {
        for (auto &item: items) {
            cout << item << '\t';
        }
        cout << '\n';
    }
}
