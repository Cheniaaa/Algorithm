/*
 * https://leetcode.cn/problems/integer-break/description/
*/
#include "iostream"
#include "vector"

using namespace std;

int integerBreak(int n) {
    vector<int> dp(n + 1);
    dp[2] = 1;
    for (int i = 3; i <= n; ++i) {
        for (int j = 1; j <= i / 2; ++j) {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        }
    }
    cout << dp[n];
}

int main(){
    integerBreak(10);
}