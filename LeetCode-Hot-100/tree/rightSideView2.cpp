//
// Created by Administrator on 2024/1/13.
//

#include <vector>
#include <deque>
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
        if(root == nullptr){
            return {};
        }
        vector<int> res;
        deque<TreeNode *> que;
        que.push_back(root);
        while(que.size()){
            TreeNode *t = que.front();
            res.push_back(t->val);
            for(int i=0;i<que.size();i++){  // 错误！！！，必须要先记录que的大小
                TreeNode *temp = que.front();
                //res.push_back(temp->val);
                que.pop_front();
                if(temp->right){
                    que.push_back(temp->right);
                }
                if(temp->left){
                    que.push_back(temp->left);
                }
            }
        }
        return res;
    }
};