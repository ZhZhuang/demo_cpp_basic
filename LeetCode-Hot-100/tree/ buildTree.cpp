
//105. 从前序与中序遍历序列构造二叉树
//前提: preorder 和 inorder 均 无重复 元素

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

// 思路清晰
// 大量的数组复制,比较耗费时间和内存
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
            return nullptr;
        TreeNode *node = new TreeNode(preorder[0]);
        int i ;
        for(i=0;i<inorder.size();i++){
            if(inorder[i] == preorder[0]){
                break;
            }
        }
        vector<int> in_l, in_r;
        for(int j=0;j<i;j++){
            in_l.push_back(inorder[j]);
        }
        for(int j=i+1;j<inorder.size();j++){
            in_r.push_back(inorder[j]);
        }

        vector<int> pr_l, pr_r;
        for(int j=0;j<in_l.size();j++){
            pr_l.push_back(preorder[j+1]);
        }
        for(int j=0;j<in_r.size();j++){
            pr_r.push_back(preorder[j+1+pr_l.size()]);
        }

        node->left = buildTree(pr_l, in_l);
        node->right = buildTree(pr_r, in_r);
        return node;
    }
};

// 优化,使用索引而不是,复制的方式