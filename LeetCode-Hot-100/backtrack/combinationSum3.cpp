
//216. 组合总和 III

// 题干
//  找出所有相加之和为 n 的 k 个数的组合，且满足下列条件：
//  只使用数字1到9
//  每个数字 最多使用一次

// 剪枝：1 根据sum
// 剪枝：2 根据元素数量

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k,n,1);
        return res;
    }

    // 剪枝：1
    // 剪枝：2
    void backtracking(int k, int n, int startindex){
        if(path.size() == k){
            int sum =0 ;
            for(int j=0;j<path.size();j++)
                sum+=path[j];
            if(sum == n)
                res.push_back(path);
            return;
        }
        for(int i=startindex; i<= 9; i++){
            path.push_back(i);
            backtracking(k,n,i+1);
            path.pop_back();
        }
    }

};