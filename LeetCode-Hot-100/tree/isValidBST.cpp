//98. 验证二叉搜索树

// 正确思路：
// 中序遍历时，判断当前节点是否大于中序遍历的前一个节点，如果大于，说明满足 BST，继续遍历；否则直接返回 false。
// 中序遍历，将元素放到数组中


#include <climits> // LLONG_MIN
#include <cstddef>  // NULL
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

class Solution {
public:
    vector<int> vec;
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        midTraval(root);
        if(vec.size()==1)
            return true;
        for(int i=1;i<vec.size();i++){
            if(vec[i]<vec[i-1])
                return false;
        }
        return true;
    }
    void midTraval(TreeNode *root){
        if(root == nullptr){
            return;
        }
        midTraval(root->left);
        vec.push_back(root->val);
        midTraval(root->right);
    }
};


// 方法：中序遍历，比较前一个值
class Solution_1 {
public:
    long long maxVal = LLONG_MIN; // 因为后台测试数据中有int最小值
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        bool left = isValidBST(root->left);
        // 中序遍历，验证遍历的元素是不是从小到大
        if (maxVal < root->val) maxVal = root->val;
        else return false;
        bool right = isValidBST(root->right);

        return left && right;
    }
};

//作者：代码随想录
//        链接：https://leetcode.cn/problems/validate-binary-search-tree/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


class Solution_error {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return true;
        }

        bool left = isValidBST(root->left);
        bool right = isValidBST(root->right);
        bool temp;
        if(root->left == nullptr && root->right == nullptr){
            return temp = true;
        }
        //if(root->left != nullptr && root->val > root->left->val ||
        //root->right != nullptr && root->val >root->right->val ||
        //root->val> root->left->val && root->val > root->right->val){
        else if((root->left != nullptr && root->val > root->left->val) ||
           (root->right != nullptr && root->val >root->right->val )||
           (root->val> root->left->val && root->val > root->right->val)){
            return temp = true;
        } else{
            return temp = false;
        }

        return left && right && temp;
    }
};