/**
* 并查集
*/
#include "iostream"

using namespace std;

const int MAX_N = 10000;

int PAR[MAX_N];    //父节点, 存储该节点对应的根节点的位置
int RANK[MAX_N];   //树的高度，存储该树的位置

void init(int n)  //初始化n个元素，使得该n个元素最初的根节点均为自身
{
    for (int i = 0; i < n; i++) {
        PAR[i] = i;
        RANK[i] = 0;
    }
}

int find(int x)    //查询第x个节点所在树的根
{
//    if (PAR[x] == x)
//        return x;
//    else
//        return PAR[x] = find(PAR[x]);  //这一步很巧妙，既通过递归找到根节点，又同时完成了路径的压缩
    if (PAR[x] != x) PAR[x] = find(PAR[x]);
    return PAR[x];
}

void unite(int x, int y) //将x和y所在的集合合并
{        //合并时主要考虑两个根即可
    x = find(x);
    y = find(y);

    if (x == y) return;  //在同一集合，不需操作

    if (RANK[x] < RANK[y])   //RANK大的节点作为合并后的根节点
        PAR[x] = y;
    else {
        if (RANK[x] == RANK[y]) RANK[x]++; //如果两个树高度一样，则合并后树的高度加1
        PAR[y] = x;
    }
}

bool same(int x, int y)  //判断x和y是否是同一个集合
{
    return find(x) == find(y);
}


int main() {
    int n = 10;

    init(n);   //初始化10个节点
    for (int i = 0; i < n; i++)
        cout << PAR[i] << ' ';
    cout << endl;

    unite(1, 2);
    unite(2, 3);
    unite(3, 5);   //1,2,3,5在同一集合
    cout << PAR[1] << ' ' << PAR[2] << ' ' << PAR[3] << ' ' << PAR[5] << endl;//same number

    unite(4, 6);
    unite(6, 7);    //4,6,7在同一集合

    cout << same(4, 5) << ' ' << same(4, 6) << endl;  //0 1

    unite(4, 5);
    cout << same(5, 6) << endl;   //1
}