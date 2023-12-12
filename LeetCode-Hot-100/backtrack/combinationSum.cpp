
//39. 组合总和

// 画树分析！！！！！！


//给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
//
//candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。
//
//对于给定的输入，保证和为 target 的不同组合数少于 150 个。
//输入: candidates = [2,3,6,7], target = 7
//输出: [[7],[2,2,3]]

#include <vector>
//#include<math.h>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex) {
        if (sum == target) {
            result.push_back(path);
            return;
        }

        // 剪枝
        // 如果 sum + candidates[i] > target 就终止遍历
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            sum += candidates[i];
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum, i);
            sum -= candidates[i];
            path.pop_back();

        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        result.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); // 需要排序
        backtracking(candidates, target, 0, 0);
        return result;
    }
};

// 剪枝,优化
class Solution_my {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());  //
        backtracking(candidates,target,0);
        return res;
    }


    // 剪枝
    void backtracking(vector<int> &conditates, int target, int startindex){
        if(sum == target){
            res.push_back(path);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=startindex;i<conditates.size();i++){  //
            path.push_back(conditates[i]);
            sum+=conditates[i];
            if(sum>target){
                sum-=conditates[i];
                path.pop_back();
                break;
            }
            backtracking(conditates,target,i);   // 注意 i
            sum-=conditates[i];
            path.pop_back();
        }
    }
};

class Solution_1 {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtracking(candidates,target,0);
        return res;
    }


    // 原始，未剪枝
    void backtracking(vector<int> &conditates, int target, int startindex){
        if(sum == target){
            res.push_back(path);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=startindex;i<conditates.size();i++){
            path.push_back(conditates[i]);
            sum+=conditates[i];
            backtracking(conditates,target,i);   // 注意 i
            sum-=conditates[i];
            path.pop_back();
        }
    }
};