/**
 * 课程表
 *https://leetcode.cn/problems/course-schedule/description/
 */
#include <queue>
#include "iostream"
#include "vector"

using namespace std;


/**
 * 广度优先算法
 * 寻找入度为零（正向思维，遍历一个点就删除与其他点的连接）
 * @param numCourses
 * @param prerequisites
 * @return
 */
bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> course(numCourses);
    vector<int> in(numCourses, 0);
    for (auto &item: prerequisites) {
        course[item[1]].push_back(item[0]);
        in[item[0]]++;//入度加一
    }


    queue<int> queue;
    //将入度为零的压入队列
    for (int i = 0; i < numCourses; ++i) {
        if (in[i] == 0) {
            queue.push(i);
        }
    }
    int finishNum = 0;
    while (!queue.empty()) {
        int item = queue.front();
        queue.pop();
        finishNum++;
        for (auto &c: course[item]) {
            in[c]--;
            if (in[c]==0) queue.push(c);
        }
    }
    return finishNum == numCourses;
}

int main() {
    int numCourses;
    vector<vector<int>> prerequisites({{1, 0},
                                       {2, 1},
                                       {3, 1}});
    cout << canFinish(4, prerequisites);
}
