//
// Created by Administrator on 2023/12/18.
//


// 1049. 最后一块石头的重量 II   // 动态规划， 从中选出任意两块石头
//注意：区别于// 1046. 最后一块石头的重量      // 堆问题， 从中选出两块 最重的 石头

//输入：[2,7,4,1,8,1]
//输出：1

// 问题转化：把石头分成重量相近的两堆，【想不到！！！！！】
// 类似分割等和子集
// 0-1背包

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lastStoneWeight11(vector<int>& stones) {
        //int len = stones.size();
        int total_w = 0;
        for(auto &e:stones){
            total_w += e;
        }
        int capacity = total_w/2;
        //if(total_w%2==1)   //奇数
        //    capacity++;
        cout<<capacity<<endl;
        vector<int> dp(capacity+1,0);
        for(int i=0;i<stones.size();i++){
            for(int j=capacity;j>=stones[i];j--){
                dp[j] = max(dp[j],
                            dp[j-stones[i]]+stones[i]);
            }
            for(auto &e:dp)
                cout<<e<<" ";
            cout<<endl;
        }
        return total_w - 2 * dp[capacity];
    }
};