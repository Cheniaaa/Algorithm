/**
* 路经总和2
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
 * 回溯
 * @param node
 * @param sum
 */
void traversal(TreeNode *node, int sum) {
    if (!node->left && !node->right) {
        if (sum == 0) {
            res.push_back(path);
        }
        return;
    }
    if (node->left) {
        path.push_back(node->left->val);
        sum -= node->left->val;
        traversal(node->left, sum);
        sum += node->left->val;
        path.pop_back();
    }
    if (node->right) {
        path.push_back(node->right->val);
        sum -= node->right->val;
        traversal(node->right, sum);
        sum += node->right->val;
        path.pop_back();
    }
}

vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
    if (!root) {
        return res;
    }
    path.push_back(root->val);
    traversal(root, targetSum - root->val);
    return res;
}