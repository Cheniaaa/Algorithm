#include "iostream"

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    int index = 1;
    vector<vector<int>> res(n, vector<int>(n));
    while (index <= n * n) {
        for (int i = left; i <= right; i++, index++) res[top][i] = index;
        top++;
        for (int i = top; i <= bottom; i++, index++) res[i][right] = index;
        right--;
        for (int i = right; i >= left; i--, index++) res[bottom][i] = index;
        bottom--;
        for (int i = bottom; i >= top; i--, index++) res[i][left] = index;
        left++;
    }
    return res;
}

int main() {
    vector<vector<int>> res = generateMatrix(1);
    for (auto item: res) {
        for (auto i: item) {
            cout << i << '\t';
        }
        cout << endl;
    }
}