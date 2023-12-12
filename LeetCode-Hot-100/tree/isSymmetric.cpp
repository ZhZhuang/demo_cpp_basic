// 有难度
// 层次遍历的方法不好用

#include <queue>
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
        bool isSymmetric(TreeNode* root) {
            return root == nullptr || recur(root->left, root->right);
        }
    private:
        bool recur(TreeNode* L, TreeNode* R) {
            if (L == nullptr && R == nullptr) return true;
            if (L == nullptr || R == nullptr || L->val != R->val) return false;
            return recur(L->left, R->right) && recur(L->right, R->left);
        }
    };

    // 层次遍历的方法不好用
    bool isSymmetric_1(TreeNode* root){
        if(root == nullptr)
            return true;
        queue<TreeNode *> que;
        int count = 1;
        que.push(root);
        while (que.size()){
            count = que.size();
            for(int i=0;i<count;i++){
                TreeNode *temp = que.back(); que.pop();
                que.push(temp->left);
                que.push(temp->right);
                //if(temp->left){
                //    que.push(temp->left);
                //}
                //if(temp->right){
                //    que.push(temp->right);
                //}
            }
        }
        return false;
    }
};

// 力扣官方
class Solution_1 {
public:
    bool check(TreeNode *p, TreeNode *q) {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/symmetric-tree/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。