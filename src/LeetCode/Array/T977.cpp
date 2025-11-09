#include "iostream"

using namespace std;


vector<int> sortedSquares(vector<int> &nums) {
    int n = nums.size();

    int l = 0, r = n - 1, index = n - 1;
    vector<int> res(n);
    if (nums[l] >= 0) {

//        for_each(nums.begin(), nums.end(), [](int &num) { num *= num; });//使用for_each数组原地操作

//        transform(nums.begin(), nums.end(), nums.begin(), [](int num) { return num *= num; });//使用transform数组原地操作

        //使用transform在另一个数组操作
        transform(nums.begin(), nums.end(), res.begin(), [](int num) { return num *= num; });
        return res;
    }

    if (nums[r] <= 0) {
        for_each(nums.begin(), nums.end(), [&res, &index](int num) { res[index--] = num * num; });
        return res;
    }

    while (l <= r) {
        if (abs(nums[l]) < abs(nums[r])) {
            res[index] = nums[r] * nums[r];
            r--;
        } else {
            res[index] = nums[l] * nums[l];
            l++;
        }
        index--;
    }
    return res;
}

int main() {
    cout << "Hello World!" << endl;
    return 0;
}