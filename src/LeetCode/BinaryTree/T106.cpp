/**
 * 中序后序构造二叉树
 */
#include <vector>
#include <stack>
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
 * 将后序和中序从后向前遍历就可以当作左右节点互换的先序中序构造二叉树
 * @param inorder
 * @param postorder
 * @return
 */
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (postorder.empty()) {
        return nullptr;
    }
    int length = postorder.size();
    auto *root = new TreeNode(postorder[length - 1]);
    int index = length - 1;
    stack<TreeNode *> stack;
    stack.push(root);
    for (int i = length - 2; i >= 0; i--) {
        TreeNode *node = stack.top();
        if (node->val != inorder[index]) {
            node->right = new TreeNode(postorder[i]);
            stack.push(node->right);
        } else {
            while (!stack.empty() && stack.top()->val == inorder[index]) {
                node = stack.top();
                stack.pop();
                index--;
            }
            node->left = new TreeNode(postorder[i]);
            stack.push(node->left);
        }

    }
    return root;
}
