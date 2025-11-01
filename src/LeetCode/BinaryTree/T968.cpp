/**
* 监控二叉树
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
 * 0代表无覆盖
 * 1代表有摄像头
 * 2代表有覆盖
 *
 * 使用二叉树递归后序遍历 + 状态转移
 * */
int res = 0;

int judgeStatus(TreeNode* node){
    if (!node) {
        //空节点当作有覆盖，减少后续的判断
        return 2;
    }
    int leftChild = judgeStatus(node->left);
    int rightChild = judgeStatus(node->right);

    if (leftChild == 2 && rightChild == 2) {
        return 0;
    } else if (leftChild == 0 || rightChild == 0) {
        res++;
        return 1;
    } else {
        return 2;
    }
}

int minCameraCover(TreeNode* root) {
    if (judgeStatus(root) == 0) {
        res++;
    }
    return res;
}


int main() {


}
