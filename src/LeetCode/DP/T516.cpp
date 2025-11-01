/**
* https://leetcode.cn/problems/longest-palindromic-subsequence/description/
*/
#include "iostream"
#include "vector"

using namespace std;

/**
    输入：s = "bbbab"
    输出：4
    解释：一个可能的最长回文子序列为 "bbbb" 。

    输入：s = "cbbd"
    输出：2
    解释：一个可能的最长回文子序列为 "bb" 。
 * @param s
 * @return
 * 解法：动态规划
 * 关于回文，可以采用前后对比或者字符串反转转化为最长公共序列问题
 */
int longestPalindromeSubseq(string s) {
    int len = s.size();
    if (len <= 1) return len;
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = 0; i < len; ++i) dp[i][i] = 1;
    //由于递推公式需要dp[i+1][j]所以只能先遍历left且后向前遍历（或者整体从后开始遍历）
    for (int right = 1; right < len; right++) {
        for (int left = right - 1; left >= 0; left--) {
            if (s[left] == s[right]) {
                dp[left][right] = dp[left + 1][right - 1] + 2;
            } else {
                dp[left][right] = max(dp[left][right - 1], dp[left + 1][right]);
            }
        }
    }
    return dp[0][len - 1];
}

int main() {
    cout << longestPalindromeSubseq("abaabc")<< endl;
    return 0;
}