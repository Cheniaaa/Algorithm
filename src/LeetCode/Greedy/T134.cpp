#include <vector>
#include "iostream"

using namespace std;

/**
 * 解法一：暴力循环解法
 * @param gas
 * @param cost
 * @return
 */
int canCompleteCircuit_1(vector<int> &gas, vector<int> &cost) {

}

/**
 * 解法二：全局最优
 * @param gas
 * @param cost
 * @return
 */
int canCompleteCircuit_2(vector<int> &gas, vector<int> &cost) {

}

/**
 * 解法三：局部最优
 * @param gas
 * @param cost
 * @return
 */
int canCompleteCircuit_3(vector<int> &gas, vector<int> &cost) {
    int totalSum = 0;
    int curSum = 0;
    int start = 0;
    for (int i = 0; i < gas.size(); ++i) {
        totalSum += gas[i] - cost[i];
        curSum += gas[i] - cost[i];
        if (curSum < 0) {
            curSum = 0;
            start = i + 1;
        }
    }
    if (totalSum < 0) return -1;
    return start;
}


int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {1, 4, 3, 5, 2};
    cout << canCompleteCircuit_3(gas, cost);
}