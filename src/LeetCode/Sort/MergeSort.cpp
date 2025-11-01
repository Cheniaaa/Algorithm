/**
* 归并排序
*/
#include <vector>
#include "iostream"

using namespace std;


void merge(vector<int> &arr, int l, int r, int mid) {
    vector<int> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    //按从小到大将两个容器中数据合并
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];
    k = 0;
    for (int m = l; m <= r; ++m) {
        arr[m] = temp[k++];
    }
    temp.clear();
}


void merge_sort(vector<int> &arr, int l, int r) {

    //利用二分拆分
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        //合并
        merge(arr, l, r, mid);
    }
}

int main() {
    vector<int> arr({5, 1, 4, 3, 9, 6, 2});
    cout << "原数据：";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << '\t';
    }
    cout << '\n';
    merge_sort(arr, 0, arr.size() - 1);
    cout << "排序数据：";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << '\t';
    }
}