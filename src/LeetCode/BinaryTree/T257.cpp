/**
 * 二叉树的所有路径
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

vector<string> res;
/**
 * 回溯
 * 本题回溯不明显，回溯部分隐藏在 traversal(node->left, path + "->")中，因为path不是引用，所有失败之后前一个递归的path不变，相当于回溯
 * @param node
 * @param path
 */
void traversal(TreeNode *node, string path) {
    path += to_string(node->val); //中
    if (!node->left && !node->right) {
        res.push_back(path);
        return;
    }
    if (node->left) {
        traversal(node->left, path + "->");//左
    }
    if (node->right) {
        traversal(node->right, path + "->");//右
    }
}

vector<string> binaryTreePaths(TreeNode *root) {
    if (!root) {
        return res;
    }
    string path;
    traversal(root, path);
    return res;
}