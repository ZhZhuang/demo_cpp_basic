
// 377. 组合总和 Ⅳ

// 给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。请你从 nums 中找出并返回总和为 target 的元素 组合 的个数。
// 题目数据保证答案符合 32 位整数范围。

//分析：完全背包问题
//  等价于 ： 排列数 ！！！
//  零钱兑换2 是 组合数


/**
 * 方法一：动态规划
 * 方法二：记忆的dfs
 */

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1,0);
        dp[0]=1;
        for(int j =1;j<=target;j++){
            for(int i=0;i<nums.size();i++){
                //if(j-nums[i]>=0)
                if(j-nums[i]>=0 && dp[j] < INT_MAX - dp[j - nums[i]])   // 考虑溢出
                    dp[j] += dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};


//@从心开始 用记忆化dfs啊，
// 击败 100% 运行时间
class Solution_2 {
public:
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums, target);
    }

    //备忘录，保存每层递归的计算结果，用于实现记忆化。
    unordered_map<int, int> memo;

    //dfs(target)的定义： 用nums中的元素凑成总和为target（每个元素可以使用多次），用多少中凑法。
    int dfs(vector<int>& nums, int target){
        if(target == 0)
            return 1;
        if(target < 0)
            return 0;
        if(memo.count(target) == 1)
            return memo[target];
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            res += dfs(nums, target - nums[i]);
        }
        memo[target] = res;
        return res;
    }
};