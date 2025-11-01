/**
 * 最大二叉树
 */
#include <vector>
#include "deque"
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
 * 递归法
 * @param nums
 * @param left
 * @param right
 * @return
 */
TreeNode *traversal(vector<int> &nums, int left, int right) {
    if (left > right) {
        return nullptr;
    }
    int maxIndex = left;
    for (int i = left + 1; i <= right; ++i) {
        if (nums[i] > nums[maxIndex]) {
            maxIndex = i;
        }
    }
    auto *node = new TreeNode(nums[maxIndex]);

    node->left = traversal(nums, left, maxIndex - 1);
    node->right = traversal(nums, maxIndex + 1, right);
    return node;
}


TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return traversal(nums, 0, nums.size() - 1);
}


/**
 * 单调栈(此处采用双端队列)
 * 输入：nums = [3,2,1,6,0,5]
 * 输出：[6,3,5,null,2,0,null,null,1]
 * @param nums
 * @return
 */
TreeNode *constructMaximumBinaryTree_improve(vector<int> &nums) {
    int size = nums.size();
    vector<TreeNode *> tree(size);
    deque<int> deque;//存放下标
    for (int i = 0; i < size; ++i) {
        tree[i] = new TreeNode(nums[i]);
        //与栈中元素对比，放入单调栈
        while (!deque.empty() && nums[i] > nums[deque.back()]) {
            tree[i]->left = tree[deque.back()];
            deque.pop_back();
        }
        //如果栈不为空，则需要将该元素加入顶元素的右节点
        if (!deque.empty()) {
            tree[deque.back()]->right = tree[i];
        }
        deque.push_back(i);
    }
    return tree[deque.front()];
}

