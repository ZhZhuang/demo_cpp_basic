//
// Created by Administrator on 2023/11/30.
//

// 注意：官网代码比较简洁；


#include <vector>
#include <queue>
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
    // 本人的写法，不够简洁
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode *> que;
        queue<TreeNode *> que2;
        vector<vector<int>> res;
        que.push(root);
        while(que.size() || que2.size()){
            if(que.size()){
                vector<int> temp;
                while(que.size()){
                    TreeNode *t = que.front();
                    temp.push_back(t->val); // 一层
                    que.pop();
                    if(t->left){
                        que2.push(t->left);
                    }
                    if(t->right){
                        que2.push(t->right);
                    }
                }
                res.push_back(temp);
            }

            if(que2.size()){
                vector<int> temp2;
                while(que2.size()){
                    TreeNode *t = que2.front();
                    temp2.push_back(t->val); // 一层
                    que2.pop();
                    if(t->left){
                        que.push(t->left);
                    }
                    if(t->right){
                        que.push(t->right);
                    }
                }
                res.push_back(temp2);
            }
        }
        return res;
    }
};


class Solution_2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return ret;
    }
};
//
//作者：力扣官方题解
//        链接：https://leetcode.cn/problems/binary-tree-level-order-traversal/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

vector<int> levelOrder(TreeNode* root) {
    if(root == nullptr)
        return {};
    queue<TreeNode *> que;
    vector<int> res;
    que.push(root);
    while(que.size()){
        TreeNode *t = que.front();
        res.push_back(t->val);
        que.pop();
        if(t->left){
            que.push(t->left);
        }
        if(t->right){
            que.push(t->right);
        }
    }
    return res;
}