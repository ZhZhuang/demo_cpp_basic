
//70. 爬楼梯

// 递归+记忆化搜索

// dp数组的含义：第i个台阶有dp[i]种方法

// dp[i] = dp[i-1] + dp[i-2]

// 难点，递推公式没给

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(long n) {
        if(n<=2)
            return n;
        vector<long> dp(n+1);
        dp[1]=1,dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main(){
    Solution s;
    cout<<"result is: "<<s.climbStairs(10);
    return 0;
}