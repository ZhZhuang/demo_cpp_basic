
//236. 二叉树的最近公共祖先

// 不好想
//分析：看到这题无从下手，分析不出规律。
//    一定要下画一个树，比划比划


//递归精髓：因为是递归,使用函数后可认为左右子树已经算出结果

//具体思路：
//（1） 如果当前结点 rootrootroot 等于 NULL，则直接返回 NULL
//（2） 如果 rootrootroot 等于 ppp 或者 qqq ，那这棵树一定返回 ppp 或者 qqq
//（3） 然后递归左右子树，因为是递归，使用函数后可认为左右子树已经算出结果，用 leftleftleft 和 rightrightright 表示
//（4） 此时若leftleftleft为空，那最终结果只要看 rightrightright；若 rightrightright 为空，那最终结果只要看 leftleftleft
//（5） 如果 leftleftleft 和 rightrightright 都非空，因为只给了 ppp 和 qqq 两个结点，都非空，说明一边一个，因此 rootrootroot 是他们的最近公共祖先
//（6） 如果 leftleftleft 和 rightrightright 都为空，则返回空（其实已经包含在前面的情况中了）
//
//时间复杂度是 O(n)O(n)O(n)：每个结点最多遍历一次或用主定理，空间复杂度是 O(n)O(n)O(n)：需要系统栈空间

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x),left(left),right(right){}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(!root || root==p || root==q){ return root; }
    auto left=lowestCommonAncestor(root->left,p,q);
    auto right=lowestCommonAncestor(root->right,p,q);
    if(!left) return right;
    if(!right) return left;
    return root;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( root == nullptr || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left,p,q);
        TreeNode *right = lowestCommonAncestor(root->right,p,q);


        if(left == nullptr)
            return right;
        if(right == nullptr)
            return  left;

        if(left && right) // p和q在两侧
            return root;

        return nullptr;
    }
};