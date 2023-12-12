

//437. 路径总和 III
//路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。

//https://blog.csdn.net/qq_17550379/article/details/82284240

//区别于
//Leetcode 112：路径总和（最详细的解法！！！）
//Leetcode 113：路径总和 II（最详细的解法！！！）

// 方法一：暴力
// 方法二：前缀和 hashmap


#include <unordered_map>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
};


class Solution {
public:
    int sum;
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)
            return 0;
        sum+=root->val;
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        sum-=root->val;

    }
};

// 暴力 O(N^2)，其中 N为该二叉树节点的个数， 空间复杂度0（N）
class Solution_1 {
public:
    // 用于查找当前节点的路径和
    int rootSum(TreeNode* root, long targetSum) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        if (root->val == targetSum) {
            ret++;
        }

        ret += rootSum(root->left, targetSum - root->val);
        ret += rootSum(root->right, targetSum - root->val);
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return 0;
        }

        int ret = rootSum(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        return ret;
    }
};

// 升级版
class Solution_2 {
public:
    unordered_map<long long, int> prefix;

    int dfs(TreeNode *root, long long curr, int targetSum) {
        if (!root) {
            return 0;
        }

        int ret = 0;
        curr += root->val;
        if (prefix.count(curr - targetSum)) {
            ret = prefix[curr - targetSum];
        }

        prefix[curr]++;
        ret += dfs(root->left, curr, targetSum);
        ret += dfs(root->right, curr, targetSum);
        prefix[curr]--;

        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        prefix[0] = 1;
        return dfs(root, 0, targetSum);
    }
};
