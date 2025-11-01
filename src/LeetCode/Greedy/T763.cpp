/**
*划分字母区间
 * https://leetcode.cn/problems/partition-labels/
*/
#include <vector>
#include "iostream"

using namespace std;

vector<int> partitionLabels(string s) {
    int position[27] = {0};
    for (int i = 0; i < s.size(); ++i) {
        position[s[i] - 'a'] = i;
    }
    vector<int> res;
    int max = 0;
    int left = -1;//记录最左侧的下标
    for (int i = 0; i < s.size(); ++i) {
        if (position[s[i] - 'a'] > max) {
            max = position[s[i] - 'a'];
        }
        if (max == i) {
            res.push_back(i - left);
            left = i;
            max = position[s[i] - 'a'];
        }
    }
    return res;
}

int main() {
    string s = "ababcbacadefegdehijhklij";
    vector<int> res = partitionLabels(s);
    for (auto &item: res) {
        cout << item << '\t';
    }
    return 0;
}