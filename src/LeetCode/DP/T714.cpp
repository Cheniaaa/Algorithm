/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */
#include "iostream"
#include "vector"

using namespace std;


/**
 输入：prices = [1, 3, 2, 8, 4, 9], fee = 2
输出：8
解释：能够达到的最大利润:
在此处买入 prices[0] = 1
在此处卖出 prices[3] = 8
在此处买入 prices[4] = 4
在此处卖出 prices[5] = 9
总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8

输入：prices = [1,3,7,5,10,3], fee = 3
输出：6
 * @param prices
 * @param fee
 * @return
 */
int maxProfit(vector<int> &prices, int fee) {
    if (prices.size() < 2) return 0;
    int len = prices.size();
    vector<vector<int>> dp(2, vector<int>(len, 0));//纵向表示是否持有股票，横向表示天数
    dp[0][0] = 0, dp[1][0] = -prices[0];
    for (int day = 1; day < len; ++day) {
        dp[0][day] = max(dp[1][day - 1] + prices[day] - fee, dp[0][day - 1]);//当天没有持有股票(包含当天卖和未买的情况)
        dp[1][day] = max(dp[0][day - 1] - prices[day], dp[1][day - 1]);//当天持有股票（包含保持之前的股票和当天买股票）
    }
    return dp[0][len - 1];
    //TODO 猜测也可以拆分成四种状态
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}
