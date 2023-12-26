//
// Created by Administrator on 2023/12/20.
//

//494. 目标和
//给你一个非负整数数组 nums 和一个整数 target 。

//【问题转化】：01背包，思路类似于分割等和子集，把元素分为左右（正负）两个部分
//left - right = target,
//left + right = sum
//得到，left = (sum + target) / 2
//等价于放满背包容量为 left 的背包有多少种方法，
//注意：如果left不能整除，说明没有方法。

//例子：
//nums = [1,1,1,1,1], target = 3，
//当target= 2 时，无解
// 所有可能的解 5，3，1，-1，-3，-5

//dp[j]的含义，装满容量为j的背包，有dp[j]种方法，
// 类似于爬楼梯的递推公式，注意求得是方法
//dp[j] += dp[j - nums[i]]

//递推公式的由来：
//https://www.bilibili.com/video/BV1o8411j73x/?spm_id_from=333.788&vd_source=f48666313e287bbf423762465f29de45

// 类似问题：
//  不同路径
//  零钱兑换2

/**
 * 方法一：回溯法
 * 方法二：动态规划
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+= nums[i];
        }
        int temp = (sum+target) % 2;
        if(abs(target)>sum)
            return 0;
        if(temp== 1)
            return 0;
        int left = (sum+target) / 2;    // 背包容量
        vector<int> dp(left+1, 0);
        dp[0]=1;
        for(int i=0;i<nums.size();i++){
            for(int j=left; j>=nums[i]; j--){     // 01背包 倒序遍历
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[left];
    }
};