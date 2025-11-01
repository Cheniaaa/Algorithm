#include <iostream>
#include <vector>
#include <stack>

using namespace std;


int largestRectangleArea(vector<int> &heights) {
    unsigned long size = heights.size();
    if (size == 1) {
        return heights[0];
    }
    int res = 0;
    stack<int> stk;
    int height, weight;
    for (int i = 0; i <= size; ++i) {
        while (!stk.empty() && (i == size || heights[i] < heights[stk.top()])) {
            height = heights[stk.top()];
            stk.pop();
            weight = stk.empty() ? i : i - stk.top() - 1;
            res = max(res, height * weight);
        }
        if (i < size) stk.push(i);
    }
    return res;
}


int main() {
    vector<int> vector = {2, 1, 5, 6, 2, 3};
    int res = largestRectangleArea(vector);
    cout << res;

};
