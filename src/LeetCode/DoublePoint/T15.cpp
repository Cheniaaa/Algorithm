/**
* 三数之和
*/

#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;

/**
 * 双指针法，三个数的顺序为 i，left，right
 * @param nums
 * @return
 */
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int left = 0, right = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] > 0) {//第一个数已经大于0就不需要继续判断
            return res;
        }
        //当有重复数据
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        left = i + 1;
        right = nums.size() - 1;
        while (left < right) {
            if (nums[i] + nums[left] + nums[right] > 0) {
                right--;
            } else if (nums[i] + nums[left] + nums[right] < 0) {
                left++;
            } else {
                res.push_back(vector<int>({nums[i], nums[left], nums[right]}));

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
    return res;
}

int main(){
    vector<int> nums({-4, -1, -1, 0, 1, 2});
    vector<vector<int>> res = threeSum(nums);
    for (auto &items: res) {
        for (auto &item: items) {
            cout << item << '\t';
        }
        cout << '\n';
    }
}