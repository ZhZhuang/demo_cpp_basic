
//114. 二叉树展开为链表

// 注意：本题可以不用额外的空间

#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 力扣报错，
// 过了一天就明白了，少了一个判断
class Solution {
public:
    vector<TreeNode *> vec;

    void flatten(TreeNode *root) {
        // 没有这个判断，报错
        if(root == nullptr)
            return;
        preorder(root);
        for (int i = 0; i < vec.size() - 1; i++) {
            vec[i]->left = nullptr;
            vec[i]->right = vec[i + 1];
        }
    }

    void preorder(TreeNode *root) {
        if (root == nullptr)
            return;
        vec.push_back(root);
        preorder(root->left);
        preorder(root->right);
    }
};