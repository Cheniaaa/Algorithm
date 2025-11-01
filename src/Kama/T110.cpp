#include "iostream"
#include "unordered_set"
#include "queue"
using namespace std;


int main() {
    int n;
    string beginStr, endStr, str;
    queue<string> que;
    cin >> n;
    cin >> beginStr >> endStr;
    unordered_set<string> strSet(n);
    unordered_set<string> visited(n);
    for (int i = 0; i < n; ++i) {
        cin >> str;
        strSet.insert(str);
    }
    que.push(beginStr);
    visited.insert(beginStr);
    int minDist = 1;
    int preNum = 1, nextNum = 0; //分别代表队列中当前距离和下一距离的字符串的个数
    while (!que.empty()) {
        str = que.front();
        que.pop();
        preNum--;
        for (int i = 0; i < str.size(); ++i) {
            string newStr = str;
            for (int j = 0; j < 26; ++j) {
                newStr[i] = 'a' + j;
                if (newStr == endStr) {
                    cout << minDist + 1 << endl;
                    return 0;
                }
                if (strSet.find(newStr) != strSet.end() && visited.find(newStr) == visited.end()) {
                    que.push(newStr);
                    visited.insert(newStr);
                    nextNum++;
                }
            }
        }
        if (preNum == 0) {//当前距离的字符串都已遍历过
            minDist++;
             preNum = nextNum;
            nextNum = 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
