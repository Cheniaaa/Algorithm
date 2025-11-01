#include<iostream>
#include<vector>
#include<algorithm>     //sort
#include<ctime>

using namespace std;
const int N = 10;       //桶的个数 数据范围设为0 - 100(左闭右开)


//桶排序 设置几个桶，放入元素并对桶内排序(采用sort)
void BucketSort(vector<int> &a) {
    int n = a.size();
    vector<vector<int>> bucket(N);
    for (int i = 0; i < n; i++)
        bucket[a[i] / 10].push_back(a[i]);
    //将每个元素放入对应桶中

    int k = 0;
    for (int i = 0; i < N; i++) {
        //对每个桶进行排序
        sort(bucket[i].begin(), bucket[i].end());
        int size = bucket[i].size();
        for (int j = 0; j < size; j++)
            a[k++] = bucket[i].at(j);      //放入原数组
    }

    vector<vector<int>>().swap(bucket);    //释放空间
}

void show(vector<int> &v) {
    for (auto &x: v)
        cout << x << " ";
    cout << endl;
}


int main() {
    vector<int> a;
    srand((int) time(0));
    int n = 10;
    while (n--)
        a.push_back(rand() % 100);   //数据范围[0, 99]
    show(a);
    BucketSort(a);
    cout << endl << endl;
    show(a);
}