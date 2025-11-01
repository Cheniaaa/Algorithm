/**
 * 课程表
 *https://leetcode.cn/problems/course-schedule/description/
 */
#include "iostream"
#include "vector"

using namespace std;

bool valid = true;

/**
 *深度优先算法
 * 寻找出度为零（逆向思维，从后往前寻找是否有环）
 * @param course
 * @param visited  0：未搜索，1：搜索中，2：搜索完成
 * @param index
 */
void dfs(vector<vector<int>> &course, vector<int> &visited, int index) {
    visited[index] = 1;
    for (auto item: course[index]) {
        if (visited[item] == 0) {
            dfs(course, visited, item);
            if (!valid) {
                return;
            }
        } else if (visited[item] == 1) {
            valid = false;
            return;
        }
    }
    visited[index] = 2;
}

bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> course(numCourses);
    vector<int> visited(numCourses, 0);
    for (auto &item: prerequisites) {
        course[item[1]].push_back(item[0]);
    }
    for (int i = 0; i < numCourses && valid; ++i) {
        if (visited[i] == 0) dfs(course, visited, i);
    }
    return valid;
}


int main() {
    int numCourses;
    vector<vector<int>> prerequisites({{1, 0},
                                       {2, 1},
                                       {3, 1}});
    cout << canFinish(4, prerequisites);
}