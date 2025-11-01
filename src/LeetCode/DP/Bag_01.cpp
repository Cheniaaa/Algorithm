/*
 * 01背包
 */
#include "iostream"
#include "vector"

using namespace std;

//使用二维数组
void solve_1(int n, int baggageW) {
    vector<int> weight(n, 0);
    vector<int> value(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }
    vector<vector<int>> dp(n, vector<int>(baggageW + 1, 0));
    for (int j = weight[0]; j <= baggageW; ++j) dp[0][j] = value[0];
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= baggageW; ++j) {
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[n - 1][baggageW];
}


//使用一维数组（滚动数组）
void solve_2(int n, int baggageW) {
    vector<int> weight(n, 0);
    vector<int> value(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }
    vector<int> dp(baggageW + 1, 0);
    for (int i = 0; i < n; ++i) {
//        只能为倒序，防止重复放入
        for (int j = baggageW; j >= weight[i]; j--) {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }
    cout << dp[baggageW];
}


int main() {
//    solve_1(3, 4);
    solve_2(3, 4);

}