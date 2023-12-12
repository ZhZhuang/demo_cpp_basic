//108. 将有序数组转换为二叉搜索树
//给你一个整数数组 nums ，其中元素已经按 升序 排列，请你将其转换为一棵 高度平衡 二叉搜索树。
//
//高度平衡 二叉树是一棵满足「每个节点的左右两个子树的高度差的绝对值不超过 1 」的二叉树。

#include <vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
};

// 前提：nums已经有序
// 手写，一遍成功了
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        int left = 0, right = nums.size()-1;
        TreeNode *root = helper(nums, left, right);
        return root;
    }

    TreeNode *helper(vector<int>& nums, int left, int right){
        if(left > right){
            return nullptr;
        }
        //int left = 0, right = nums.size()-1;
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = helper(nums, left, mid -1);
        root->right = helper(nums, mid+1, right);
        return root;
    }
};