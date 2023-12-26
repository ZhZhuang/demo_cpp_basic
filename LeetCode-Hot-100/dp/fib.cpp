
//LCR 126. 斐波那契数
//F(0) = 0，F(1) = 1
//F(n) = F(n - 1) + F(n - 2)，其中 n > 1

/// 分析：没有形成自己解题的套路
//      简单，简单在哪里？为什么简单？

// 方法很多
//1，递归
//2，带记忆的递归
//3，动态规划

#include <vector>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        return fib(n-1) + fib(n-2);
    }
};

//答案需要取模 1e9+7(1000000007) ，如计算初始结果为：1000000008，请返回 1。
class Solution_dp {
public:
    int fib(int n) {
        if(n==0 || n==1){
            return n;
        }
        vector<int> dp(n+1,0);
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};