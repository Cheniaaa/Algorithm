/**
 * 前序中序构造二叉树
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


TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) {
        return nullptr;
    }
    int size = preorder.size();
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> stack;
    stack.push(root);
    int index = 0;//中序遍历的下标
    for (int i = 1; i < size; ++i) {
        auto node = stack.top();

        //node是前一个先序遍历的元素，与中序遍历的最大深度的左节点比较
        if (node->val != inorder[index]) {
            node->left = new TreeNode(preorder[i]);
            stack.push(node->left);
        } else {
            while (!stack.empty() && (stack.top())->val == inorder[index]) {
                node = stack.top();
                index++;
                stack.pop();
            }
            //在中序遍历某一处停止while循环，说明存在右节点，将本次的先序遍历的元素作为出栈元素的右节点
            node->right = new TreeNode(preorder[i]);
            stack.push(node->right);
        }
    }
    return root;
}