#include <iostream>
#include <vector>
#include "queue"
#include "unordered_map"
#include "map"

using namespace std;

/**
13
3,3,7,4,4,4,4,7,7,3,5,5,5
53,80,68,24,39,76,66,16,100,55,53,80,55
 * @return
 */
int main() {
    int n;
    cin >> n;
    vector<int> shotID(n);
    unordered_map<int, priority_queue<int>> score_map;
    map<int, priority_queue<int, vector<int>>, greater<int>> res;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        cin >> shotID[i];
        getchar();
    }

    int score;
    for (int i = 0; i < n; ++i) {
        cin >> score;
        getchar();
        score_map[shotID[i]].push(score);
    }
    for (auto &item: score_map) {
        int sum = 0;
        bool flag = true;
        for (int i = 0; i < 3; ++i) {
            if (item.second.empty()){
                flag = false;
                break;
            }
            sum += item.second.top();
            item.second.pop();
        }
        if (flag) {
            res[sum].push(item.first);
            count++;
        }

    }
    for (auto &item: res) {
        while (!item.second.empty()) {
            cout << item.second.top();
            item.second.pop();
            count--;
            if (count != 0) cout << ',';
        }
    }
    return 0;
}