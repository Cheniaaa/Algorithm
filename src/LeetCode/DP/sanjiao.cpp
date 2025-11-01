#include "iostream"
#include "vector"

using namespace std;

int main() {
    int n, m;
    cin >> n;
    vector<vector<int>> nums;
    nums.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> m;
            if (i == 0) {
                nums[i].push_back(m);
            } else if (j == 0) {
                nums[i].push_back(m + nums[i - 1][j]);
            } else if (j == i) {
                nums[i].push_back(m + nums[i - 1][j - 1]);
            } else {
                nums[i].push_back(m + max(nums[i - 1][j - 1], nums[i - 1][j]));
            }
        }
    }

    if (n % 2 == 1) {
        cout << nums[n - 1][(n - 1) / 2];
    } else {
        cout << max(nums[n - 1][n / 2 - 1], nums[n - 1][n / 2]);
    }

    for (const auto &item: nums) {
        for (const auto &elem: item) {
            cout << elem << '\t';
        }
        cout << '\n';
    }
}