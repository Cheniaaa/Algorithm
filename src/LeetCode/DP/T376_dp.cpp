#include <vector>
#include "iostream"

using namespace std;

/**
 * dp[当前数的索引][山峰或者山谷]
 * dp[i][0]表示当前数为山峰时的最大长度，反之
 *
 * @param nums
 * @return
 */
int wiggleMaxLength(vector<int> &nums) {
    int len = nums.size();
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] = dp[0][1] = 1;
    for (int i = 1; i < len; ++i) {
        dp[i][0] = dp[i][1] = 1;//每一个都可以作为起始.
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);//将当前山峰拼接到前一个山谷
            else if (nums[j] > nums[i]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);//将当前山谷拼接到前一个山峰
        }
    }
    return max(dp[len - 1][0], dp[len - 1][1]);
}

int main() {
    vector<int> num = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << wiggleMaxLength(num);
    return 0;
}