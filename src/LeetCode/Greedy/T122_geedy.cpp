#include "iostream"
#include "bits/stdc++.h"

using namespace std;

/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 */
int maxProfit_1(vector<int> &prices) {
    int lowPrice = INT32_MAX;
    int res = 0;
    for (int i = 0; i < prices.size(); ++i) {
        lowPrice = min(lowPrice, prices[i]);
        res = max(res, prices[i] - lowPrice);
    }
    return res;
}


int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit_1(prices);
}