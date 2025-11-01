/**
 * 前k个高频元素
 */
#include <vector>
#include <unordered_map>
#include <queue>
#include "iostream"

using namespace std;

/*
优先队列：priority_queue<Type, Container, Functional>

//小顶堆
priority_queue <int,vector<int>,greater<int>> q;
//大顶堆
priority_queue <int,vector<int>,less<int>> q;
//默认大顶堆
priority_queue<int> a;
*/

class myComparator {
public:
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
        return lhs.second > rhs.second;//小顶堆
    };
};

vector<int> topKFrequent(vector<int> &nums, int k) {
    unordered_map<int, int> map;
    vector<int> res(k);
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, myComparator> priorityQueue;//采用自定义仿函数

    for (unordered_map<int, int>::iterator t = map.begin(); t != map.end(); t++) {
        priorityQueue.push(*t);
        if (priorityQueue.size() > k) {
            priorityQueue.pop();
        }
    }
    for (int i = k - 1; i >= 0; i--) {
        res[i] = priorityQueue.top().first;
        priorityQueue.pop();
    }
    return res;
}


int main() {
    vector<int> nums({1, 1, 1, 2, 2, 3});
    vector<int> result = topKFrequent(nums, 2);
    for (auto &item: result) {
        cout << item << '\t';
    }
}
