/**
* 平衡二叉树
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
 * 自底向上的递归（类似后序遍历）
 * 时间复杂度：O(n)
 * @param node
 * @return
 */
int balance(TreeNode *node) {
    if (!node) {
        return 0;
    }
//    int leftHeight = balance(node->left); //左
//    if (leftHeight == -1) {
//        return -1;
//    }
//    int rightHeight = balance(node->right);//右
//    if (rightHeight == -1) {
//        return -1;
//    }
//    return abs(leftHeight - rightHeight) > 1 ? -1 : 1 + max(leftHeight, rightHeight); //中

//代码精简
    int leftHeight, rightHeight;
    if ((leftHeight = balance(node->left)) == -1 || (rightHeight = balance(node->right)) == -1 ||
        abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    return 1 + max(leftHeight, rightHeight);

}

bool isBalanced(TreeNode *root) {
    return balance(root) != -1;
}

/**
 * 自顶向下（类似于先序遍历）
 * 时间复杂度：O(n^2)
 * 重复执行大量的getHeight方法
 * @param node
 * @return
 */
int getHeight(TreeNode *node) {
    if (!node) {
        return 0;
    }
    return 1 + max(getHeight(node->left), getHeight(node->right));
}

bool isBalanced2(TreeNode *root) {
    if (!root) {
        return true;
    }
    //中 左 右
    if (abs(getHeight(root->left) - getHeight(root->right)) > 1 || !isBalanced2(root->left) ||
        !isBalanced2(root->right)) {
        return false;
    }
    return true;
}

