#include <vector>
#include "iostream"
#include "unordered_set"

using namespace std;

int longestConsecutive(vector<int> &nums) {

    unordered_set<int> set;
    for (auto &item: nums) {
        set.emplace(item);
    }
    int maxLen = 0, currentLen = 0, currentNum = 0;

    for (auto &item: set) {
        if (!set.count(item - 1)) {
            currentNum = item;
            currentLen = 1;


            while (set.count(currentNum + 1)) {
                currentNum++;
                currentLen++;
            }
            maxLen = max(maxLen, currentLen);
            if (maxLen >= nums.size() / 2 + 1) {
                break;
            }
        }
    }
    return maxLen;
}

//优化
int longestConsecutive_modify(vector<int> &nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int maxLen = 0, currentLen = 0;
    for (int item: set) {
        if (!set.count(item - 1)) {
            currentLen = 1;
            while (set.count(++item)) {
                currentLen++;
            }
            maxLen = max(maxLen, currentLen);
            if (maxLen >= nums.size() / 2 + 1) {
                break;
            }
        }
    }
    return maxLen;
}

//进一步修改,使用迭代器
int longestConsecutive_modify2(vector<int> &nums) {
    unordered_set<int> set(nums.begin(), nums.end());
    int maxLen = 0, currentLen = 0;
    for (unordered_set<int>::iterator iter = set.begin(); iter != set.end(); ++iter) {
        if (set.find((*iter) - 1) == set.end()) {
            currentLen = 1;
            for (int next = (*iter) + 1; set.find(next) != set.end(); next++) {
                currentLen++;
            }
            if (currentLen > maxLen) {
                maxLen = currentLen;
            }
            if (maxLen >= nums.size() / 2 + 1) {
                break;
            }
        }
    }
    return maxLen;
}

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive_modify2(nums);
    return 0;
}