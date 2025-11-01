/**
 * 快速排序
 */
#include <vector>
#include "iostream"

using namespace std;

/**
 * @param arr
 * @param left
 * @param right
 * @return
 */
int partition(vector<int> &arr, int left, int right) {
    int key = arr[right];//将最后一位作为拆分点
    int L = left, R = right;
    while (L < R) {
        while (L < R && arr[L] <= key) L++;
        arr[R] = arr[L];
        while (L < R && arr[R] >= key) R--;
        arr[L] = arr[R];
    }
    arr[L] = key;
    return L;
}

/**
 * 遍历拆分元素
 * @param arr
 * @param start
 * @param end
 */
void sort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int mid = partition(arr, start, end);//记录上一次遍历后的中心下标
        sort(arr, start, mid - 1);
        sort(arr, mid + 1, end);
    }
}

int main() {
    vector<int> arr({3, 2, 6, 1, 8, 5, 0});
    sort(arr, 0, arr.size() - 1);
    for (auto &item: arr) {
        cout << item << '\t';
    }
}

