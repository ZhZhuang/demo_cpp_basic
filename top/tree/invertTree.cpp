//
// Created by Administrator on 2024/1/9.
//

//226. 翻转二叉树

/**
 * 方法一：递归实现
 * 方法二：非递归实现    ,有难度
 */

#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)
            return nullptr;
        TreeNode *left = root->right;
        TreeNode *right = root->left;
        invertTree(root->left);
        invertTree(root->right);
        root->left = left;
        root->right = right;
        return root;
    }
};


class Solution_2 {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode* node = stack.top();
            stack.pop();
            if (node->left != nullptr) stack.push(node->left);
            if (node->right != nullptr) stack.push(node->right);
            TreeNode* tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }
        return root;
    }
};
//
//作者：Krahets
//        链接：https://leetcode.cn/problems/invert-binary-tree/solutions/2361621/226-fan-zhuan-er-cha-shu-fen-zhi-qing-xi-tqlf/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。