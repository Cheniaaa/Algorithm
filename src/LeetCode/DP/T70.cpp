/**
* 爬楼梯
*/
#include <vector>
#include "iostream"

using namespace std;

/**
 * 递归法
 * 性能较低，有很多重复的计算，超时
 * @param n
 * @return
 */
int climbStairs(int n) {
    if (n == 1 || n == 2) {
        return n;
    }
    return climbStairs(n - 1) + climbStairs(n - 2);
}

/**
 * 动态规划
 * 增加记录数据的数组，避免重复计算
 * @param n
 * @return
 */
int climbStairs_dp(int n) {
    if (n <= 1) {
        return n;
    }
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int m = climbStairs_dp(4);
    cout << m;
    return 0;
}
