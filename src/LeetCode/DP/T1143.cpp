/**
* https://leetcode.cn/problems/longest-common-subsequence/description/
*/
#include "iostream"
#include "vector"

using namespace std;

int longestCommonSubsequence(string text1, string text2) {
    int len_1 = text1.size(), len_2 = text2.size();
    vector<vector<int>> dp(len_2 + 1, vector<int>(len_1 + 1, 0));
    for (int i = 1; i <= len_2; ++i) {
        for (int j = 1; j <= len_1; ++j) {
            if (text1[j - 1] == text2[i - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[len_2][len_1];
}

int main() {
    cout << longestCommonSubsequence("abcde", "ace") << endl;
    cout << longestCommonSubsequence("abc", "def") << endl;
    return 0;
}