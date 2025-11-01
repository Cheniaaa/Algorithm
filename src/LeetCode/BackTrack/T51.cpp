/**
* N皇后
*/
#include <vector>
#include "iostream"

using namespace std;

vector<vector<string>> res;


bool isValid(int row, int col, vector<string> &chess, int n) {
    // 检查列
    for (int i = 0; i < row; i++) { // 这是一个剪枝
        if (chess[i][col] == 'Q') {
            return false;
        }
    }
    // 检查 45度角是否有皇后
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (chess[i][j] == 'Q') {
            return false;
        }
    }
    // 检查 135度角是否有皇后
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if (chess[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

void backtracking(int n, int row, vector<string> &chess) {
    if (row == n) {
        res.push_back(chess);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isValid(row, col, chess, n)) {
            chess[row][col] = 'Q';
            backtracking(n, row + 1, chess);
            chess[row][col] = '.';
        }
    }
};


vector<vector<string>> solveNQueens(int n) {
    vector<string> chess(n, string(n, '.'));
    backtracking(n, 0, chess);

    return res;
}


int main() {
    vector<vector<string>> result = solveNQueens(4);
    for (auto &items: result) {
        for (auto &item: items) {
            cout << item << '\n';
        }
        cout << '\n' << '\n';
    }
}