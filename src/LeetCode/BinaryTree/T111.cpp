/**
* 二叉树的最小深度
*/
#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 递归
 * @param root
 * @return
 */
int minDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }

    if (root->left && !root->right) {
        return 1 + minDepth(root->left);
    }
    if (!root->left && root->right) {
        return 1 + minDepth(root->right);
    }
    return 1 + min(minDepth(root->left), minDepth(root->right));
}


int res;

/**
 * 深度遍历
 * @param node
 * @param depth
 */
void getMinDepth(TreeNode *node, int depth) {
    if (!node->left && !node->right) {
        res = min(depth, res);
        return;
    }

    if (node->left) {
        getMinDepth(node->left, depth + 1);
    }
    if (node->right) {
        getMinDepth(node->right, depth + 1);
    }
}


int minDepth_dfs(TreeNode *root) {
    if (!root) {
        return 0;
    }
    res = INT_MAX;
    getMinDepth(root, 1);
    return res;
}


int main() {

}