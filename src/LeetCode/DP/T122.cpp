/**
 * 买卖股票的最佳时机1，2，3，4
 */
#include "iostream"
#include "bits/stdc++.h"

using namespace std;

/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 */
int maxProfit_1(vector<int> &prices) {
    int len = prices.size();
    if (len < 2) return 0;
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; ++i) {
        dp[i][0] = max(-prices[i], dp[i - 1][0]);//由于只有一次买卖所以不包含前一次不持有的利润
        dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
    }
    return dp[len - 1][1];
}

/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/
 * @return
 */
int maxProfit_2(vector<int> &prices) {
    int len = prices.size();
    if (len < 2) return 0;
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] -= prices[0];
    dp[0][1] = 0;
    for (int i = 1; i < len; ++i) {
        dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);//包含前一次不持有的利润
        dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
    }
    return dp[len - 1][1];
}

/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/
 * @return
 * 包含四种状态：1次持有，1次未持有，2次持有，2次未持有
 */
int maxProfit_3(vector<int> &prices) {
    int len = prices.size();
    if (len < 2) return 0;
    vector<vector<int>> dp(len, vector<int>(4, 0));
    dp[0][0] -= prices[0];
    dp[0][2] -= prices[0];
    for (int i = 1; i < len; ++i) {
        dp[i][0] = max(-prices[i], dp[i - 1][0]);//第一次持有
        dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);//第一次未持有
        dp[i][2] = max(dp[i - 1][1] - prices[i], dp[i - 1][2]);//第二次持有
        dp[i][3] = max(dp[i - 1][2] + prices[i], dp[i - 1][3]);//第二次未持有
    }
    return dp[len - 1][3];
}

/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
 * @return
 * 可以采用类似3的情况，使用二维数组2*k+1个状态
 * 或者采用三维数组分别表示天数，次数，持有状态
 */
int maxProfit_4(int k, vector<int> &prices) {
    int len = prices.size();
    if (len < 2) return 0;
    vector<vector<int>> dp(len, vector<int>(2 * k + 1, 0));
    for (int i = 1; i < 2 * k; i += 2) {
        dp[0][i] -= prices[0];
    }
    for (int i = 1; i < len; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][2 * j - 1] = max(dp[i - 1][2 * j - 1], dp[i - 1][2 * j - 2] - prices[i]);
            dp[i][2 * j] = max(dp[i - 1][2 * j], dp[i - 1][2 * j - 1] + prices[i]);
        }
    }
    return dp[len - 1][2 * k];
}

/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 * @return
 *0：持有状态，1：未持有状态（冷冻期后或未操作），2：未持有状态（今日卖出），3：冷冻状态
 * 对于代码状态1和3可以合并，但是容易逻辑混乱
 */
int maxProfit_5(vector<int> &prices) {
    int len = prices.size();
    if (len < 2) return 0;
    vector<vector<int>> dp(len, vector<int>(4, 0));
    dp[0][0] -= prices[0];
    for (int i = 1; i < len; ++i) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][3] - prices[i], dp[i - 1][1] - prices[i]));//持有状态
        dp[i][1] = max(dp[i - 1][3], dp[i - 1][1]);
        dp[i][2] = dp[i - 1][0] + prices[i];//今日卖出
        dp[i][3] = dp[i - 1][2];//冷冻状态
    }
    return max(dp[len - 1][1], max(dp[len - 1][2], dp[len - 1][3]));
}


int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    cout << "股票买卖1：" << maxProfit_1(prices) << endl;
    cout << "股票买卖2：" << maxProfit_2(prices) << endl;


//    prices = {3, 3, 5, 0, 0, 3, 1, 4};
    prices = {3, 2, 6, 5, 0, 3};
    cout << "股票买卖3：" << maxProfit_3(prices) << endl;
    cout << "股票买卖4：" << maxProfit_4(2, prices) << endl;

    prices = {1, 2, 3, 0, 2};
    cout << "股票买卖5：" << maxProfit_5(prices) << endl;
}