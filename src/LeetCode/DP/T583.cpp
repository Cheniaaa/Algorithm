#include "iostream"

using namespace std;

int minDistance(string word1, string word2) {
    int len_1 = word1.size(), len_2 = word2.size();
    int dp[len_1 + 1][len_2 + 1];
    for (int i = 0; i <= len_1; i++) {
        for (int j = 0; j <= len_2; j++) {
            if (i == 0 || j == 0) {
                if(i==0) dp[0][j] = j;
                else dp[i][0] = i;
                continue;
            }
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + 1;
            }
        }
    }
    return dp[len_1][len_2];
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}