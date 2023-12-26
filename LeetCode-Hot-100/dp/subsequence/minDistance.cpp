//
// Created by Administrator on 2023/12/22.
//

//72. 编辑距离
// 对比最大子序列


#include <string>
#include <vector>
#include <algorithm>    //min
using namespace std;

/*
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

        for(int i=0;i<=word1.size();i++){
            dp[i][0] = word2.size();
        }
        for(int j=0;j<=word2.size();j++){
            dp[0][j] = word1.size();
        }

        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i-1][j-1];
                } else{
                    //增
                    //删
                    //换
                    min()
                }
            }
        }
    }
};*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};