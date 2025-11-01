/**
* 李白打酒
 * https://www.lanqiao.cn/problems/2114/learning/?page=1&first_category_id=1&sort=students_count&second_category_id=3&tags=2022&name=%E6%9D%8E%E7%99%BD%E6%89%93%E9%85%92
*/
#include "iostream"

using namespace std;

const long mod = 1000000007;
long num = 0;

int dp[101][101][101];


/**
 * 回溯法（容易超时）
 * @param store
 * @param flower
 * @param wine
 */
void backtrack(int store, int flower, int wine) {
    if (store > 0) backtrack(store - 1, flower, wine * 2);
    if (flower > 0) backtrack(store, flower - 1, wine - 1);
    if (store == 0 && flower == 1 && wine == 1) num++;
}

int dfs(int store, int flower, int wine) {
    if (store < 0 || flower < 0 || wine < 0) return 0;
    if (wine > flower) return 0;
    if (store == 0 && flower == 1 && wine == 1) return 1;
    return dp[store][flower][wine] = (dfs(store - 1, flower, wine * 2) + dfs(store, flower - 1, wine - 1)) % mod;
}

int main() {
    int store, flower;
    cin >> store >> flower;
//    backtrack(store, flower, 2);
//    cout << num;

    cout << dfs(store, flower, 2);

}


