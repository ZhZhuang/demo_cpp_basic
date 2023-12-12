//230. 二叉搜索树中第K小的元素

// 注意不用vector的写法

#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
};

class Solution {
public:
    vector<int> vec;
    int kthSmallest(TreeNode* root, int k) {
        midTrival(root);
        return vec[k-1];
    }

    void midTrival(TreeNode *root){
        if(root == nullptr)
            return;
        midTrival(root->left);
        vec.push_back(root->val);
        midTrival(root->right);
    }
};

class Solution_pro {
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        dfs(root);
        return res;
    }
private:
    int res, k;
    void dfs(TreeNode* root) {
        if (root == nullptr) return;
        dfs(root->left);
        if (k == 0) return;
        if (--k == 0) res = root->val;
        dfs(root->right);
    }
};
