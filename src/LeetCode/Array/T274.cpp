#include "iostream"

using namespace std;

/**
 * 输入：citations = [3,0,6,1,5]
 * 输出：3
 * @param citations
 * @return
 */
int hIndex(vector<int> &citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end(),
         [](int a, int b) { return a > b; });
    int res = 0;
    bool flag;
    for (int i = 0; i < n; ++i) {
        flag = true;
        if (citations[i] >= i + 1) {
            res = i + 1;
            flag = false;
        }
        if (flag)
            break;
    }
    return res;
}

int main() {
    vector<int> citations = {3, 0, 0};
    int res = hIndex(citations);
    cout << res;
    return 0;
}