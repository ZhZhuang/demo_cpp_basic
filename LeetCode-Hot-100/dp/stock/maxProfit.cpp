//
// Created by Administrator on 2023/12/25.
//

//121. 买卖股票的最佳时机 1
//输入：[7,1,5,3,6,4]
//输出：5
//解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
//
//输入：prices = [7,6,4,3,1]
//输出：0
//解释：在这种情况下, 没有交易完成, 所以最大利润为 0。




// 方法一：暴力  超时
// 方法二：动态规划
// 方法三：贪心


// dp[i][0] 的含义第i天持有股票的最大利润
// dp[i][1] 表示第i天不持有股票的最大利润

#include <vector>
using namespace std;


// 股票类通用解题方法，速度不快，但是能通过
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2,0));
        dp[0][0] = -prices[0];  // 持有股票0的最大利润
        dp[0][1] = 0;           // 不持有股票0的最大利润
        for(int i=1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0],  // 之前就不持有
                           -prices[i]); // 现在持有
           dp[i][1] = max(dp[i-1][1],               // 之前就不持有
                          dp[i-1][0]+prices[i]);     // 现在不持有
        }
        return dp[prices.size()-1][1];
    }
};


class Solution_greed {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int result = 0;
        for (int i = 0; i < prices.size(); i++) {
            low = min(low, prices[i]);  // 取最左最小价格
            result = max(result, prices[i] - low); // 直接取最大区间利润
        }
        return result;
    }
};




class Solution_brute{
public:
    int maxProfit(vector<int>& prices) {
        int result=0;
        for(int i=0;i<prices.size()-1;i++){
            for(int j=i+1;j<prices.size();j++){
                result = max(prices[j]-prices[i], result);
            }
        }
        return result;
    }
};