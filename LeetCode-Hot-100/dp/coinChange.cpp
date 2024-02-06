
//322. 零钱兑换
//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。s
//你可以认为每种硬币的数量是无限的。


//方法一：回溯法

// 这题与【排列】或是【组合】无关，因此物品与背包的遍历顺序无所谓
// 属于能否【装满】的问题
// 背包的遍历顺序,很有讲究
//https://www.bilibili.com/video/BV14K411R7yv/?spm_id_from=333.788&vd_source=f48666313e287bbf423762465f29de45

// dp[j] : 表示装容量为j的背包，最少的物品数量
// dp[j] = min( dp[j-coins[i]] + 1,     // 放置
//                  dp[j])              // 不放置物品

#include <vector>
#include <climits>
#include <iostream>
#include <iomanip>  // 控制输出位数 setw()
using namespace std;


class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {      // 完全背包
                if (dp[j - coins[i]] != INT_MAX) { // 如果dp[j - coins[i]]是初始值则跳过
                    dp[j] = min(dp[j - coins[i]] + 1,   /*放物品*/
                                dp[j]);           /*不放物品*/
                }
            }
            for (auto &e: dp) {
                cout << setw(20) << e;
            }
            cout << endl;
        }
        if (dp[amount] == INT_MAX)
            return -1;   //
        return dp[amount];
    }
};

int main(){
    //vector<int> coins={1,2,5};
    //int amount= 11;

    // 分析为什么要有这句
    // if (dp[j - coins[i]] != INT_MAX)
    vector<int> coins={2,3};
    int amount= 3;

    Solution s;
    int res = s.coinChange(coins,amount);
    cout<<res<<endl;

    return 0;
}