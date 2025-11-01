/**
 * 课程表2
 * https://leetcode.cn/problems/course-schedule-ii/
 */

#include <algorithm>
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
void dfs(vector<vector<int>> &course, vector<int> &visited, vector<int> &result, int index) {
    visited[index] = 1;
    for (auto item: course[index]) {
        if (visited[item] == 0) {
            dfs(course, visited, result, item);
            if (!valid) {
                return;
            }
        } else if (visited[item] == 1) {
            valid = false;
            return;
        }
    }
    visited[index] = 2;
    result.push_back(index);
}

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> course(numCourses);
    vector<int> visited(numCourses, 0);
    vector<int> result;
    for (auto &item: prerequisites) {
        course[item[1]].push_back(item[0]);
    }
    for (int i = 0; i < numCourses && valid; ++i) {
        if (visited[i] == 0) dfs(course, visited, result, i);
    }
    if (!valid) return {};

    //需要反向输出
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int numCourses;
    vector<vector<int>> prerequisites({{1, 0},
                                       {2, 1},
                                       {3, 1}});
    vector<int> res = findOrder(4, prerequisites);
    for (auto &item: res) {
        cout << item << '\t';
    }
}