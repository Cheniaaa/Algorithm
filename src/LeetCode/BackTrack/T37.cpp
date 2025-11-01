/**
* 解数独
*/
#include <vector>
#include "iostream"

using namespace std;

bool isValid(int row, int col, char val, vector<vector<char>> &board) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == val) {
            return false;
        }
    }

    for (int i = 0; i < 9; ++i) {
        if (board[i][col] == val) {
            return false;
        }
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; ++i) {
        for (int j = startCol; j < startCol + 3; ++j) {
            if (board[i][j] == val) {
                return false;
            }
        }
    }
    return true;
}

bool backtracking(vector<vector<char>> &board) {
    for (int row = 0; row < board.size(); ++row) {
        for (int col = 0; col < board[0].size(); ++col) {
            if (board[row][col] == '.') {
                for (char i = '1'; i <= '9'; ++i) {
                    if (isValid(row, col, i, board)) {
                        board[row][col] = i;
                        if (backtracking(board)) { return true; }
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board) {
    backtracking(board);

}

int main() {
    vector<vector<char>> board({
                                       {'.', '.', '.', '1', '.', '.', '8', '.', '.'},
                                       {'2', '5', '.', '.', '3', '.', '.', '.', '.'},
                                       {'.', '4', '.', '.', '.', '.', '.', '.', '.'},
                                       {'.', '.', '8', '.', '.', '5', '.', '.', '.'},
                                       {'.', '.', '.', '.', '4', '.', '.', '.', '.'},
                                       {'.', '.', '9', '.', '.', '.', '7', '3', '.'},
                                       {'.', '.', '7', '9', '.', '.', '.', '.', '.'},
                                       {'.', '.', '.', '.', '.', '.', '.', '2', '4'},
                                       {'.', '.', '.', '.', '.', '.', '.', '.', '6'}
                               });
    solveSudoku(board);

    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            cout << board[i - 1][j - 1] << " ";
            if (j % 3 == 0) {
                cout << "  ";
            }
        }
        cout << '\n';
        if (i % 3 == 0) {
            cout << '\n';
        }
    }
}