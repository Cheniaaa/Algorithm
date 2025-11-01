/**
* 验证二叉搜索树
 * https://leetcode.cn/problems/validate-binary-search-tree/
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


TreeNode *pre = nullptr;//用于记录前一个节点
/**
 * 中序遍历
 * 二叉树中序遍历应该是单调递增的序列
 * @param root
 * @return
 */
bool isValidBST(TreeNode *root) {
    if (!root) return true;

    //左
    bool left = isValidBST(root->left);

    //中
    if (pre && root->val <= pre->val) {
        return false;
    }
    pre = root;

    //右
    bool right = isValidBST(root->right);
    return left && right;
}