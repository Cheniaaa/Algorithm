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


void traversal(TreeNode *root, int pre) {
    if (!root) return;
    traversal(root->right, pre);
    root->val += pre;
    pre = root->val;
    traversal(root->left, pre);
}

TreeNode *convertBST(TreeNode *root) {
    traversal(root, 0);
    return root;
}
