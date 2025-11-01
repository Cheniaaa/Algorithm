/**
* 判断二分图
 * https://leetcode.cn/problems/is-graph-bipartite/description/
*/
#include <queue>
#include "iostream"
#include "vector"

using namespace std;

bool valid = true;

/**
 * 深度优先遍历+涂色法
 * 遍历时相邻节点采用不同的颜色
 * @param node
 * @param c  颜色 ——> 0：无颜色，1：绿色，2：红色
 * @param graph
 */
void dfs(int node, int c, vector<vector<int>> &graph, vector<int> &color) {
    color[node] = c;
    c = 3 - c;//下一个颜色需要反转
    for (auto &item: graph[node]) {
        if (color[item] == 0) {
            dfs(item, c, graph, color);
            if (!valid) return;
        } else if (color[item] == color[node]) {
            valid = false;
            return;
        }
    }
}

bool isBipartite(vector<vector<int>> &graph) {
    vector<int> color(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
        if (color[i] == 0) {
            dfs(i, 2, graph, color);
        }
    }
    return valid;
}

/**
 * 广度优先遍历+涂色法
 * @param graph
 * @return
 */
bool isBipartite_bfs(vector<vector<int>> &graph) {
    vector<int> color(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
        if (color[i] == 0) {
            queue<int> queue;
            queue.push(i);
            color[i] = 2;
            while (!queue.empty()) {
                int node = queue.front();
                queue.pop();
                int nextColor = 3 - color[node];//相邻节点的颜色（与本节点不同颜色）
                for (auto &item: graph[node]) {
                    if (color[item] == 0) {
                        queue.push(item);
                        color[item] = nextColor;
                    } else if (color[item] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}



int main() {
    vector<vector<int>> prerequisites(
            {
                    {1, 3},
                    {0, 2},
                    {1, 3},
                    {0, 2}
            }
    );
//    cout << isBipartite(prerequisites);
    cout << isBipartite_bfs(prerequisites);
}