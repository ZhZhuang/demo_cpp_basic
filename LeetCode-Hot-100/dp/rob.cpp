

// 198. 打家劫舍

//dp[i]的含义：到第i间房间为止(考虑第i个房间)，所偷的最大价值

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        if(len==1)
            return nums[0];
        vector<int> dp(len, 0);
        dp[0]=nums[0];
        dp[1]= max(nums[0],nums[1]);
        for(int i=2;i<len;i++){
            //
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        //for(int i=0;i<len;i++)
        //    cout<<dp[i]<<" ";
        return dp[len-1];
    }
};