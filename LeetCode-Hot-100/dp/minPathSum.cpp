//
// Created by Administrator on 2023/12/23.
//

//64. 最小路径和

// 简简单单的一题，状况百出
// 速度不够

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int >> dp(grid.size(), vector<int>(grid[0].size(),0));
        int temp =0;
        for(int i=0;i<grid.size();i++){
            temp += grid[i][0];
            dp[i][0] = temp;
        }
        // 初始化可以优化
        temp =0;
        for(int i=0;i<grid[0].size();i++){
            temp += grid[0][i];
            dp[0][i] = temp;
        }

        for(int i=1;i<grid.size();i++){
            for(int j=1;j<grid[0].size();j++){
                dp[i][j]= min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
            }
        }
        //for(int i=0;i<dp.size();i++){
        //    for(int j=0;j<dp[0].size();j++){
        //        cout<<dp[i][j]<<" ";
        //    }
        //    cout<<endl;
        //}
        return dp[grid.size()-1][grid[0].size()-1];
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid={{1,3,1},
                              {1,5,1},
                              {4,2,1}};
    cout<<"result: "<<s.minPathSum(grid)<<endl;
    return 0;
}