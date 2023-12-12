
//LCR 082. 组合总和 II

// 核心难点：去重
// https://www.bilibili.com/video/BV12V4y1V73A/?spm_id_from=333.788

//给定一个可能有重复数字的整数数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
//
//candidates 中的每个数字在每个组合中只能使用一次，解集不能包含重复的组合。
//示例 1:
//
//输入: candidates = [10,1,2,7,6,1,5], target = 8,
//        输出:
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sum;
    vector<int> path;
    vector<vector<int>> res;


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> used(candidates.size(),0);  // size, 初值
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,used);
        return res;
    }

    void backtracking(vector<int>& candidates, int target, int startindex, vector<int>& used){
        if(sum>target)return;
        if(sum == target){
            res.push_back(path);
            return;
        }
        for(int i=startindex; i<candidates.size(); i++){
            // 难点，重点！！！！！！
            if(i>0 && candidates[i] == candidates[i-1] && used[i-1] == 0){  // 去重逻辑,used[i-1] == 0不易理解
                continue;
            }
            path.push_back(candidates[i]);
            used[i]=1;
            sum+=candidates[i];
            backtracking(candidates,target,i+1,used);   // i+1
            sum-=candidates[i];
            used[i]=0;
            path.pop_back();
        }
    }

};