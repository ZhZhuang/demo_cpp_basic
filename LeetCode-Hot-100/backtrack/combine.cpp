
// LCR 080. 组合

// 收割：结果在叶子节点上

//经典分析：回溯可以理解为一层for循环，一层递归就是一层for循环

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combine(int n, int k) {
        backtracking(n,k,1);
        return res;
    }

    // 引入剪枝
    void backtracking(int n ,int k, int startindex){
        //if(k<=0){
        if(path.size()==k){
            res.push_back(path);
            return;
        }
        for(int i = startindex;i<=n-(k-path.size())+1;i++){   // 剪枝 !!!
            path.push_back(i);
            backtracking(n,k,i+1);
            path.pop_back();
        }
    }

    //void backtracking(int n ,int k, int startindex){
    //    //if(k<=0){
    //    if(path.size()==k){
    //        res.push_back(path);
    //        return;
    //    }
    //    for(int i = startindex;i<=n;i++){
    //        path.push_back(i);
    //        //backtracking(n,k-1,startindex+1);
    //        backtracking(n,k,i+1);
    //        path.pop_back();
    //    }
    //}

     void backtracking_error(int n ,int k, int startindex){
         if(k<=0){
             res.push_back(path);
             return;
         }
         for(int i = startindex;i<=n;i++){
             path.push_back(i);
             backtracking(n,k-1,startindex+1);  // 错误，起不到作用
             path.pop_back();
         }
     }
};