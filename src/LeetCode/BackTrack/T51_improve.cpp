/**
* N皇后优化版（使用位运算）
*/
#include <vector>
#include "iostream"

using namespace std;

vector<vector<string>> res;

/**
 * x&(−x)可以获得 x 的二进制表示中的最低位的 1 的位置；
 * x&(x−1) 可以将 x 的二进制表示中的最低位的 1 置成 0。
 * 棋盘左侧是二进制的低位（两者方向相反）
 * @param chess
 * @param n
 * @param row
 * @param columns 存放不可选的列的位置
 * @param diagonals1 存放左上到右下不可选的位置
 * @param diagonals2 存放右上到左下不可选的位置
 */
void backtracking(vector<string> &chess, int n, int row, int columns, int diagonals1, int diagonals2) {
    if (row == n) {
        res.push_back(chess);
        return;
    }
    //找出全部可以放的位置，用1表示
    int availablePosition = ((1 << n) - 1) & (~(columns | diagonals1 | diagonals2));
    while (availablePosition != 0) {
        int position = (availablePosition) & (-availablePosition);
        int col = __builtin_ctz(position);//低位0的个数（相当于获取最后一位1的位置）
        chess[row][col] = 'Q';
        availablePosition = (availablePosition) & (availablePosition - 1);
        backtracking(chess, n, row + 1, columns | position, (diagonals1 | position) << 1, (diagonals2 | position) >> 1);
        chess[row][col] = '.';
    }
};


vector<vector<string>> solveNQueens(int n) {
    vector<string> chess(n, string(n, '.'));
    backtracking(chess, n, 0, 0, 0, 0);
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