/**
 * 积木画
 *https://www.lanqiao.cn/problems/2110/learning/?page=1&first_category_id=1&sort=students_count&second_category_id=3&tags=2022&name=%E7%A7%AF%E6%9C%A8
 */
#include "algorithm"
#include "iostream"

using namespace std;

const int mod = 1000000007;
long dp[10000010][3];

/**
 * dp[i][0]：铺满
 * dp[i][1]：缺上
 * dp[i][2]：缺下
 * 状态方程：  dp[i][0] = dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]
             dp[i][1] = dp[i - 2][0] + dp[i - 1][2]
             dp[i][2] = dp[i - 2][0] + dp[i - 1][1]
 * @return
 */

int main() {
    int n;
    cin >> n;
    dp[1][0] = 1;
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[2][0] = 2;
    dp[2][1] = 1;
    dp[2][2] = 1;

    for (int i = 3; i <= n; ++i) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % mod;
    }
    cout << dp[n][0];
}
