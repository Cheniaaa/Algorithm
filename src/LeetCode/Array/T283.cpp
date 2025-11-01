#include <vector>
#include "iostream"

using namespace std;


vector<int> moveZeroes(vector<int> &nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            count++;
        } else {
            if (count > 0) {
                nums[i - count] = nums[i];
                nums[i] = 0;
            }
        }
    }
    return nums;
}


vector<int> moveZeroes1(vector<int> &nums) {
    int left = 0, right = 0;
    while (right < nums.size()) {
        if (nums[right]) {
            swap(nums[left], nums[right]);
            left++;
        }
        right++;
    }
    return nums;
}


int main() {
    vector<int> nums({1, 0, 0, 2, 0, 3, 4});
    vector<int> res = moveZeroes1(nums);
    for (auto &item: res) {
        cout << item << endl;
    }
}