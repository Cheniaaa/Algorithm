#include <vector>
#include <stack>
#include "iostream"

using namespace std;

int maximalRectangle(vector<vector<char>> &matrix) {
    int length = matrix[0].size();
    if (matrix.empty()) {
        return 0;
    }
    int res = 0;
    vector<int> heights;
    heights.resize(length);
    int height, weight;
    stack<int> stack;
    for (auto &row: matrix) {
        for (int col = 0; col <= length; ++col) {
            if (col < length) {
                if (row[col] == '1') {
                    heights[col]++;
                } else {
                    heights[col] = 0;
                }
            }
            while (!stack.empty() && (col == length || heights[col] < heights[stack.top()])) {
                height = heights[stack.top()];
                stack.pop();
                weight = stack.empty() ? col : col - stack.top() - 1;
                res = max(res, height * weight);
            }
            if (col < length) {
                stack.push(col);
            }
        }
    }
    return res;
}


int main() {
    vector<vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                   {'1', '0', '1', '1', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    int res = maximalRectangle(matrix);
    cout << res;



}
