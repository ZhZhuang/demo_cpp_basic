
//199. 二叉树的右视图

// 思路：层次遍历，输出每一层的最后一个

// 深度优先也是可以的

#include <vector>
#include <queue>
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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode *> que;
        vector<int> res;
        if(root == nullptr)
            return res;
        que.push(root);
        while(!que.empty()){
            // 每层周后一个元素
            res.push_back((que.back())->val);
            int count = que.size(); // 很重要！！！
            for(int i=0;i< count;i++){
                TreeNode *temp = que.front();
                que.pop();   // 出队
                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right    );
                }
            }
        }
        return res;
    }
};