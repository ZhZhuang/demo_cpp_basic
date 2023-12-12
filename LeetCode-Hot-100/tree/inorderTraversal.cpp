//
// Created by Administrator on 2023/11/29.
//

// 三种方法：
/**
 * 1 递归
 * 2 迭代 !
 * 3 morris （将二叉树转化为链表，即每一个node都只可能有右孩子）
 */

#include <vector>
#include<stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> res;
vector<int> inorderTraversal(TreeNode *root){
    if(root == nullptr)
        return res;
    inorderTraversal(root->left);
    res.push_back(root->val);
    inorderTraversal(root->right);
    return res;
}

// 推荐写法：
class Solution_1 {
public:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};


class Solution_2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (root != nullptr || !stk.empty()) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};
