
// 完全背包


/**
 * 任务：
 * 1 打印正序和倒序遍历的一维滚动数组     ！！！
 * 2 区分01背包，和完全背包的状态转移方程的区别
 */


//  硬想！
// 不可取

// 可以颠倒for两层for循环

#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int>& weight, vector<int>& value, int C) {
    int n = weight.size();
    vector<vector<int>> dp(n + 1, vector<int>(C + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= C; j++) {
            if (weight[i - 1] <= j) {
                // 第 i 个元素可以重复放
                dp[i][j] = max(dp[i - 1][j],
                               dp[i][j - weight[i - 1]] + value[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // 打印
    cout<<"dp:"<<endl;
    for(int i=0;i<dp.size();i++){
        for(int j=0;j<dp[0].size();j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][C];
}

int main() {
    //vector<int> weight = {2, 3, 4, 5};
    //vector<int> value = {3, 4, 5, 6};
    //int C = 8;

    vector<int> weight = {1, 3, 4};
    vector<int> value = {15, 20, 30};
    int C = 4;
    cout << knapsack(weight, value, C) << endl; // Output: 13
    return 0;
}
