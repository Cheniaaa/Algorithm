/**
* 路经总和2 改版
*/
#include <vector>
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> res;
vector<int> path;

/**
 * 回溯（版本2）
 * @param node
 * @param sum
 */
void traversal(TreeNode *node, int sum) {
    if (!node) {
        return;
    }
    path.push_back(node->val);
    sum -= node->val;
    if (!node->left && !node->right && sum == 0) {
        res.push_back(path);
    }
    traversal(node->left, sum);
    traversal(node->right, sum);
    path.pop_back();
}


vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    traversal(root, targetSum);
    return res;
}