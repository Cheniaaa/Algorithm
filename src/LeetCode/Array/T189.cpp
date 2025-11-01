/**
 *https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
 */
#include "iostream"


using namespace std;


/**
 * 数组翻转（手写reverse方法）
 * @param nums
 * @param k
 */
void rotate(vector<int> &nums, int k) {
    k %= nums.size();
    auto reverse = [&](int start, int end) {
        while (start < end) {
            swap(nums[start++], nums[end--]);
        }
    };

    reverse(0, nums.size() - 1);
    reverse(0, k - 1);
    reverse(k, nums.size() - 1);
}

/**
 * 使用自带的reverse函数
 * @param nums
 * @param k
 */
void rotate_1(vector<int> &nums, int k) {
    k %= nums.size();
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
