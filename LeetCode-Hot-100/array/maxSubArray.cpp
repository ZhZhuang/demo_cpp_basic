//
// Created by Administrator on 2023/12/26.
//

//53. 最大子数组和
//子数组 是数组中的一个连续部分。

//输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出：6
//解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。


// 动态规划！
/**
 * dp[i] 表示以nums[i]结尾的最大子序列和
 * dp[i] = max( dp[i-1] + nums[i], nums[i])
 * dp[i - 1] + nums[i]，即：nums[i]加入当前连续子序列和
    nums[i]，即：从头开始计算当前连续子序列和
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        dp[0]= nums[0];
        int result =dp[0];
        for(int i=1;i<nums.size();i++){
            dp[i]=max(nums[i],dp[i-1]+nums[i]);
            result = max(dp[i],result);
        }
        for(int i=0;i<dp.size();i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
        return result;
    }
};