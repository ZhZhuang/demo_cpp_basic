

// 分析，简化问题

#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 错误：仔细一想和深度差不多,
// 可能不经过根节点
class Solution_error {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return depth(root->left) + depth(root->right);
    }

    int depth(TreeNode * root){
        if( root == nullptr)
            return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
};


// 官方
class Solution {
    int ans;
    int depth(TreeNode* rt){
        if (rt == NULL) {
            return 0; // 访问到空节点了，返回0
        }
        int L = depth(rt->left); // 左儿子为根的子树的深度
        int R = depth(rt->right); // 右儿子为根的子树的深度
        ans = max(ans, L + R + 1); // 计算d_node即L+R+1 并更新ans
        return max(L, R) + 1; // 返回该节点为根的子树的深度
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};
//
//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/diameter-of-binary-tree/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。