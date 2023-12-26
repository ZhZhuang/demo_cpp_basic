
//279. 完全平方数

// 给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。

// 自己再【问题转化上】面有很大的【不足】！！！！！！

// 代码随想录中的分析：把这个问题转化为完全背包问题
//   也就是，容量为n的背包，从小于n的完全平方数中选取最少的数量。
//   等价于【零钱兑换】

#include<vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i*i <=n;i++){
            for(int j=i*i;j<=n;j++){
                if (dp[j - i*i] != INT_MAX)
                    dp[j] = min( dp[j-i*i] +1,
                                    dp[j]);
            }
        }
        return dp[n];

    }
};