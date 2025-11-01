#include <vector>
#include <algorithm>
#include "iostream"

using namespace std;


int solution1(vector<int> &nums, int k) {

    return sort(nums.begin(), nums.end(), greater<int>()), nums[k - 1];
}

bool priorityThan(int v1, int v2) { return v1 < v2; }

// 上浮 从下到上调整堆
void swim(vector<int> &heap, int i) {
    while (i > 0 && priorityThan(heap[i], heap[(i - 1) / 2])) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// 下沉 从下到上调整堆
void sink(vector<int> &heap, int i, int N) {
    while (2 * i + 1 <= N) {
        int j = 2 * i + 1;
        if (j + 1 <= N && priorityThan(heap[j + 1], heap[j])) {
            j++;
        }
        if (priorityThan(heap[i], heap[j])) {
            break;
        }
        swap(heap[i], heap[j]);
        i = j;
    }
}

/**
 * 堆排序
 * @param nums
 * @param k
 * @return
 */
int solution2(vector<int> &nums, int k) {
    // 对前k个元素建成小根堆
    for (int i = 0; i < k; i++) {
        swim(nums, i);
    }
    // 剩下的元素与堆顶比较，若大于堆顶则去掉堆顶，再将其插入
    //每次堆顶都是k个数据中最小的，所以将大的数据插入，最后堆顶就是最大中的第k个元素
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > nums[0]) {
            swap(nums[0], nums[i]);
            sink(nums, 0, k - 1);
        }
    }
    // 结束后第k个大的数就是小根堆的堆顶
    return nums[0];
}




int main() {

    vector<int> vector = {{5, 5, 1, 6, 7, 2, 3, 4}};
    cout << solution1(vector, 4);
}