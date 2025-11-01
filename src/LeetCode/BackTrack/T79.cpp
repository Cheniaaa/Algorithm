#include <vector>
#include "iostream"

using namespace std;

// 四个方向的下标偏移量
int dx[4] = {0, -1, 1, 0};
int dy[4] = {-1, 0, 0, 1};

/**
 * 进入方法亲爱前判断越界问题，进入方法后修改访问记录
 */
/*bool dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string word, int i, int j, int index) {

    if (word[index] != board[i][j]) {
        return false;
    }
    if (index == word.length() - 1) {
        return true;
    }

    bool res = false;

    visited[i][j] = true;
    for (int p = 0; p < 4; p++) {
        if (i + dx[p] < board.size() && j + dy[p] < board[0].size() && i + dx[p] >= 0 && j + dy[p] >= 0) {
            if (!visited[i + dx[p]][j + dy[p]]) {
                bool flag = dfs(board, visited, word, i + dx[p], j + dy[p], index + 1);
                if (flag) {
                    res = true;
                    break;
                }
            }
        }
    }
    visited[i][j] = false;
    return res;

};

bool exist(vector<vector<char>> &board, string word) {
    int height = board.size();
    int weight = board[0].size();
    vector<vector<int>> visited(height, vector<int>(weight));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < weight; ++j) {
            bool res = dfs(board, visited, word, i, j, 0);
            if (res) {
                return true;
            }
        }
    }
    return false;
}*/


/**
 * 进入方法再判断越界
 * @param board
 * @param visited
 * @param word
 * @param i
 * @param j
 * @param index
 * @return
 */

//bool res = false;
//
//bool dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string word, int i, int j, int index) {
//
//    if (i == board.size() || j == board[0].size() || i < 0 || j < 0 || visited[i][j]) {
//        return false;
//    }
//
//    if (word[index] != board[i][j]) {
//        return false;
//    }
//    if (index == word.length() - 1) {
//        return true;
//    }
//
//
//    visited[i][j] = true;
//    for (int p = 0; p < 4; p++) {
//        bool flag = dfs(board, visited, word, i + dx[p], j + dy[p], index + 1);
//        if (flag) {
//            res = true;
//            break;
//        }
//    }
//    visited[i][j] = false;//每次回溯需要重置访问历史
//    return res;
//
//};
//
//bool exist(vector<vector<char>> &board, string word) {
//    int height = board.size();
//    int weight = board[0].size();
//    vector<vector<int>> visited(height, vector<int>(weight));
//
//    for (int i = 0; i < height; ++i) {
//        for (int j = 0; j < weight; ++j) {
//            if (dfs(board, visited, word, i, j, 0)) {
//                return true;
//            }
//        }
//    }
//    return false;
//}



/**
 * 提前判断越界问题，提前修改下一个位置的访问记录
 * @param board
 * @param visited
 * @param word
 * @param i
 * @param j
 * @param index
 * @return
 */
bool dfs(vector<vector<char>> &board, vector<vector<int>> &visited, string word, int i, int j, int index) {

    if (word[index] != board[i][j]) {
        return false;
    }
    if (index == word.length() - 1) {
        return true;
    }

    for (int p = 0; p < 4; p++) {
        int row = i + dx[p], col = j + dy[p];
        if (row < board.size() && col < board[0].size() && row >= 0 && col >= 0 && !visited[row][col]) {
            visited[row][col] = true;
            if (dfs(board, visited, word, row, col, index + 1)) {
                return true;
            }
            visited[row][col] = false;
        }
    }
    return false;
};

bool exist(vector<vector<char>> &board, string word) {
    int height = board.size();
    int weight = board[0].size();
    vector<vector<int>> visited(height, vector<int>(weight));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < weight; ++j) {
            visited[i][j] = true;
            if (dfs(board, visited, word, i, j, 0)) {
                return true;
            }
            visited[i][j] = false;
        }
    }
    return false;
}


int main() {
    vector<vector<char>> board({{'A', 'B', 'C', 'E'},
                                {'S', 'F', 'C', 'S'},
                                {'A', 'D', 'E', 'E'}});
    string word = "ABFDA";
    cout << exist(board, word);

};