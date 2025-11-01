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

TreeNode *trimBST(TreeNode *root, int low, int high) {
    if (!root) return nullptr;

    if (root->val < low) return trimBST(root->right, low, high);//根节点小于low直接裁剪左树,返回一个符合的根节点
    if (root->val > high) return trimBST(root->left, low, high);//根节点大于high直接裁剪右树，返回一个符合的根节点

    root->left = trimBST(root->left, low, high);//接收上面返回的节点
    root->right = trimBST(root->right, low, high);
    return root;

}
