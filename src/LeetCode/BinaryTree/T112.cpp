/**
* 路径总和
*/
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

/**
 * 回溯
 * 采用减到 0 判断结果（减少一个参数）
 * @param root
 * @param targetSum
 * @return
 */
bool traversal(TreeNode *root, int sum) {

    if (!root->left && !root->right) {
        return root->val == sum;
    }
    if (root->left) {
        if (traversal(root->left, sum - root->val)) {
            return true;
        }
    }
    if (root->right) {
        if (traversal(root->right, sum - root->val)) {
            return true;
        }
    }

    return false;
}


bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
        return false;
    }
    return traversal(root, targetSum);
}


/**
 * 回溯简化版
 * @param root
 * @param targetSum
 * @return
 */
bool hasPathSum_improve(TreeNode *root, int targetSum) {
    if (!root) {
        return false;
    }
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }

    return hasPathSum_improve(root->left, targetSum - root->val) || hasPathSum_improve(root->right, targetSum - root->val);
}

