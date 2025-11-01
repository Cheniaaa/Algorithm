/**
* 对称二叉树
*/
#include <stack>
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
 * 递归解法
 * @param leftNode
 * @param rightNode
 * @return
 */
bool check(TreeNode *leftNode, TreeNode *rightNode) {

    if (!leftNode && !rightNode) {
        //两边都为null
        return true;
    } else if (!leftNode || !rightNode) {
        //其中一个为null
        return false;
    }
    return (leftNode->val == rightNode->val) &&
           check(leftNode->left, rightNode->right) &&
           check(leftNode->right, rightNode->left);
}

bool isSymmetric(TreeNode *root) {
    if (!root) {
        return true;
    }
    return check(root->left, root->right);
}

/**
 * 使用栈的解法（也可以使用队列）
 * @param root
 * @return
 */
bool isSymmetric_stack(TreeNode *root) {
    if (!root) {
        return true;
    }
    stack<TreeNode *> stack;
    stack.push(root->left);
    stack.push(root->right);
    while (!stack.empty()) {
        TreeNode *rightNode = stack.top();
        stack.pop();
        TreeNode *leftNode = stack.top();
        stack.pop();
        if (!leftNode && !rightNode) {
            continue;
        }
        if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
            return false;
        }
        stack.push(leftNode->left);
        stack.push(rightNode->right);
        stack.push(leftNode->right);
        stack.push(rightNode->left);
    }
    return true;
}


int main() {

}