#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
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


void createBiTree(TreeNode **root) {
    int num;
    cin >> num;
    if (num == -1) {
        *root = nullptr;
    } else {
        *root = (TreeNode *) malloc(sizeof(TreeNode));
        if (!(*root)) {
            exit(-1);
        }
        (*root)->val = num;
        createBiTree(&((*root)->left));
        createBiTree(&((*root)->right));
    }
}

//层序遍历（队列）
vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }

    queue<TreeNode *> queue;
    int len;
    queue.push(root);
    while (!queue.empty()) {
        len = queue.size();
        res.push_back(vector<int>());
        for (int i = 0; i < len; ++i) {
            auto node = queue.front();
            queue.pop();
            res.back().push_back(node->val);
            if (node->left) {
                queue.push(node->left);
            }
            if (node->right) {
                queue.push(node->right);
            }
        }
    }
    return res;
}

//使用递归
//vector<vector<int>> res;
//
//void dns(TreeNode *root, int level) {
//    if (!root) {
//        return;
//    }
//    if (res.size() == level) {
//        res.push_back(vector<int>());
//    }
//    res.back().push_back(root->val);
//    dns(root->left, level+1);
//    dns(root->right, level + 1);
//};
//
//vector<vector<int>> levelOrder_dns(TreeNode *root) {
//    if (!root) {
//        return res;
//    }
//    dns(root, 0);
//    return res;
//}


/**
 * 前序遍历写法一（栈）
 */
vector<int> preorderTraversal1(TreeNode *root) {
    vector<int> res;
    if (!root) {
        return res;
    }

    stack<TreeNode *> stack;
    TreeNode *node = root;
    while (!stack.empty() || node) {
        while (node) {
            res.push_back(node->val);
            stack.push(node);
            node = node->left;
        }
        node = stack.top();
        stack.pop();
        node = node->right;
    }
    return res;

}

/**
 * 前序遍历写法二（栈）
 */
vector<int> preorderTraversal2(TreeNode *root) {
    stack<TreeNode *> stack;
    vector<int> result;
    if (root == NULL) return result;
    stack.push(root);
    while (!stack.empty()) {
        TreeNode *node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if (node->right) stack.push(node->right);
        if (node->left) stack.push(node->left);
    }
    return result;
}

/**
 * 中序遍历写法一（栈）
 */
vector<int> inorderTraversal1(TreeNode *root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode *> stack;
    while (!stack.empty() || root) {
        while (root) {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        res.push_back(root->val);
        root = root->right;
    }
    return res;
}

/**
 * 中序遍历写法二（栈）
 */
vector<int> inorderTraversal2(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> stack;
    while (root || !stack.empty()) {
        if (root) {
            stack.push(root);
            root = root->left;
        } else {
            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            root = root->right;
        }
    }
    return result;
}

/**
 * 后序遍历方法一（栈）
 */
vector<int> postorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) {
        return res;
    }
    stack<TreeNode *> stack;
    TreeNode *preNode = nullptr;
    while (!stack.empty() || root) {
        while (root) {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        if (!root->right || root->right == preNode) {
            res.push_back(root->val);
            preNode = root;
            root = nullptr;
        } else {
            stack.push(root);
            root = root->right;
        }
    }
    return res;
}


/**
 * 后序遍历方法二（栈）
 */
vector<int> postorderTraversal2(TreeNode *root) {
    stack<TreeNode *> stack;
    vector<int> result;
    if (root == NULL) return result;
    stack.push(root);
    while (!stack.empty()) {
        TreeNode *node = stack.top();
        stack.pop();
        result.push_back(node->val);
        if (node->left) stack.push(node->left); // 相对于前序遍历，这更改一下入栈顺序 （空节点不入栈）
        if (node->right) stack.push(node->right); // 空节点不入栈
    }
    reverse(result.begin(), result.end()); // 将结果反转之后就是左右中的顺序了
    return result;
}


int main() {
    TreeNode *root;
    createBiTree(&root);
//    vector<vector<int>> res = levelOrder(root);
//    for (auto &items: res) {
//        for (auto &item: items) {
//            cout << item << '\t';
//        }
//        cout << endl;
//    }

//    vector<int> res = preorderTraversal(root);
//    vector<int> res = inorderTraversal(root);
    vector<int> res = postorderTraversal(root);

    for (auto &item: res) {
        cout << item << '\t';
    }
}