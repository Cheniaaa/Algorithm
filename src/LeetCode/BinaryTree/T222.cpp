/**
* 完全二叉树的节点个数
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
 * 普通二叉树方法
 * 时间复杂度 O(n)
 * @param root
 * @return
 */
int countNodes_common(TreeNode *root) {
    if (!root) {
        return 0;
    }
    return countNodes_common(root->left) + countNodes_common(root->right) + 1;
}

/**
 * 使用完全二叉树的性质（满二叉树节点数2^n-1，此处使用位运算加快幂计算）
 * 时间复杂度：O(log n * log n)
 * @param root
 * @return
 */
int countNodes(TreeNode *root) {
    if (!root) {
        return 0;
    }
    TreeNode *leftNode = root->left;
    TreeNode *rightNode = root->right;
    int leftLevel = 0, rightLevel = 0;
    while (leftNode) {
        leftLevel++;
        leftNode = leftNode->left;
    }
    while (rightNode) {
        rightLevel++;
        rightNode = rightNode->right;
    }
    if (leftLevel == rightLevel) {
        return (2 << leftLevel) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}


int main() {

}