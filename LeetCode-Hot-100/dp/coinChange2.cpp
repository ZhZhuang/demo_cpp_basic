
//518. 零钱兑换 II
// 请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
// 求 【组合】数
// 联系：目标和  dp[j] += dp[j-coins[i]]       ！！！！！！！！！分析为什么，看代码

// 本题：dp[j] += dp[j-coins[i]]
//dp[0]=1   // 0 的含义也说得过去，但是算法代码进行不下去

// dp[j]:表示容量为j的背包，所能存放的硬币的组合数dp[j]

/************************************************************/
// 先遍历物品，再遍历背包，表示组合树
// 链遍历背包，再遍历物品，表示排列数

// 正序遍历是完全背包
// 倒序遍历是01背包

//对于完全背包而言：
// 装不装满与物品和背包的遍历顺序无关

//【排列】和【组合】的递推公式：
// dp[j] += dp[j-coins[i]]
// 初始化：dp[0]=1


/************************************************************/


// 视频教程：
// https://www.bilibili.com/video/BV1KM411k75j/?spm_id_from=333.788&vd_source=f48666313e287bbf423762465f29de45

// 区别：322. 零钱兑换

//

#include <vector>
using namespace std;

// 二维数组，
// error
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1,0));
        //for(int i=1;i<=amount;i++){
        //    if(amount>=coins[0])
        //     dp[0][i] = amount/coins[0];
        //}
        for(int i=0;i<coins.size();i++){
                dp[i][0] = 1;
        }
        for(int i =0;i<coins.size();i++){
            for(int j=coins[i];j<=amount;j++){  // 必须正序
                dp[i][j] += dp[i][j-coins[i]];      // 没想明白， error
            }
        }
        return dp[coins.size()-1][amount];
    }
};

// 官方
class Solution_1 {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < coins.size(); i++) { // 遍历物品
            for (int j = coins[i]; j <= amount; j++) { // 遍历背包, 正序是完全背包
                dp[j] += dp[j - coins[i]];  //
            }
        }
        return dp[amount];
    }
};