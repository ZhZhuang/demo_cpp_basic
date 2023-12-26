

//474. 一和零

// 0-1背包问题，理解和转化这个问题有一定的难度
// 难点：背包的限制从一个维度变为2个维度

#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp(m,vector<int>(n,0));     // 二维滚动数组

        for(auto &str : strs){
            int x=0, y=0;
            for(char c: str){
                if(c=='0')
                    x++;
                else
                    y++;
            }
            for(int i= m;i>=x;i--){
                for(int j=n;j>=y;j--){
                    dp[i][j] = max(dp[i][j], dp[i-x][j-y] + 1);
                }
            }
        }

    }
};

// 代码随想录
class Solution_1 {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0)); // 默认初始化0
        for (string str : strs) { // 遍历物品
            int oneNum = 0, zeroNum = 0;
            for (char c : str) {
                if (c == '0') zeroNum++;
                else oneNum++;
            }
            for (int i = m; i >= zeroNum; i--) { // 遍历背包容量且从后向前遍历！
                for (int j = n; j >= oneNum; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeroNum][j - oneNum] + 1);
                }
            }
        }
        return dp[m][n];
    }
};