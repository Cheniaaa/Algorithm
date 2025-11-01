/**
* 二叉树的最大深度
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
int maxDepth(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

/**
 * 深度优先遍历
 * @return
 */
int result;

void getDepth(TreeNode *node, int depth) {
    result = depth > result ? depth : result; // 中
    if (node->left == nullptr && node->right == nullptr) return;
    if (node->left) { // 左
        getDepth(node->left, depth + 1);
    }
    if (node->right) { // 右
        getDepth(node->right, depth + 1);
    }
}

int maxDepth_dfs(TreeNode *root) {
    result = 0;
    if (!root) {
        return result;
    }
    getDepth(root, 1);
    return result;
}


int main() {

};

