/**
* 二叉搜索树
*/
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
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


TreeNode *addNode(TreeNode *root, int val) {
    if (!root) {
        root = new TreeNode(val);
        return root;
    } else if (root->val > val) {
        root->left = addNode(root->left, val);
    } else {
        root->right = addNode(root->right, val);
    }
    return root;
}

TreeNode *searchNode(TreeNode *root, int val) {
    if (!root || root->val == val) {
        return root;
    } else if (root->val > val) {
        return searchNode(root->left, val);
    } else {
        return searchNode(root->right, val);
    }
}

TreeNode *removeNode(TreeNode *root, int val) {
    if (!root) return NULL;
    else if (root->val > val) {
        root->left = removeNode(root->left, val);
    } else if (root->val < val) {
        root->right = removeNode(root->right, val);
    } else {
        //四种节点的情况
        if (!root->right && !root->left) {
            delete root;
            root = NULL;
        } else if (!root->left) {
            TreeNode *tempNode = root;
            root = root->right;
            delete tempNode;
        } else if (!root->right) {
            TreeNode *tempNode = root;
            root = root->left;
            delete tempNode;
        } else {
            //找到需要删除节点的右子树中的最小节点放置在要删除节点的位置
            TreeNode *minNode = root->right;
            while (minNode->left != NULL) {
                minNode = minNode->left;
            }
            root->val = minNode->val;
            //删除右子树中的最小节点（因为已经放置在需要删除的节点的位置）
            root->right = removeNode(root->right, minNode->val);
        }
    }
    return root;
}

/**
 * 中序遍历返回节点数组
 * @param root 根节点
 * @return 中序遍历节点数组
 */
vector<TreeNode *> inorderTraversal(TreeNode *root) {
    vector<TreeNode *> res;
    stack<TreeNode *> stk;
    while (root != nullptr || !stk.empty()) {
        while (root != nullptr) {
            stk.push(root);
            root = root->left;
        }
        root = stk.top();
        stk.pop();
        res.push_back(root);
        root = root->right;
    }
    return res;
}


/**
 * 利用下划线和正反斜杠打印出美观的二叉树，没有破坏二叉树结构，但传入的root会有变化
 * @param root  二叉树根节点
 */
void printTree(TreeNode *root) {
    if (!root)return;
    auto tmp = root;
    vector<TreeNode *> intv = inorderTraversal(tmp);//中序遍历节点数组
    string template_str;//模板string，表示每行打印string的长度
    int location = 0;
    unordered_map<TreeNode *, int> first_locations;//存储节点对应在本行string中的首位置
    for (auto &i: intv) {
        location = template_str.size();
        template_str += to_string(i->val) + " ";
        first_locations[i] = location;
    }
    for (auto &i: template_str)i = ' ';//把模板全部置为空格方便后续使用
    //层序遍历
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int currentLevelSize = q.size();
        int cur_loc = 0;
        string tmp_str1 = template_str, tmp_str2 = template_str;//1为节点所在行，2为其下一行
        for (int i = 1; i <= currentLevelSize; ++i) {
            auto node = q.front();
            q.pop();
            cur_loc = first_locations[node];
            string num_str = to_string(node->val);
            //左边，如果存在左孩子，那么在第二行对应位置打印'/'，在第一行补上'_'
            if (node->left) {
                q.push(node->left);
                int first_loc = first_locations[node->left] + 1;
                tmp_str2[first_loc++] = '/';
                while (first_loc < cur_loc)tmp_str1[first_loc++] = '_';

            }
            //中间,对应位置打印节点值（有可能为多位数）
            for (int j = 0; j < num_str.length(); ++j, ++cur_loc) {
                tmp_str1[cur_loc] = num_str[j];
            }
            //右边，如果存在右孩子，那么在第二行对应位置打印'\'，在第一行补上'_'
            if (node->right) {
                q.push(node->right);
                int last_loc = first_locations[node->right] - 1;
                tmp_str2[last_loc] = '\\';
                while (cur_loc < last_loc) {
                    tmp_str1[cur_loc++] = '_';
                }
            }
        }
        //打印两行
        cout << tmp_str1 << endl;
        cout << tmp_str2 << endl;
    }
}


int main() {
    TreeNode *root = NULL;
    root = addNode(root, 1);
    root = addNode(root, 3);
    root = addNode(root, 2);
    root = addNode(root, 4);
    root = addNode(root, 6);
    printTree(root);
}
