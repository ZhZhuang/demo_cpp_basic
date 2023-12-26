//
// Created by Administrator on 2023/12/23.
//

//516. 最长回文子序列
// 注意：区别于5. 最长回文子串；本题不要求连续

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            dp[i][i]=1;
        }
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i+1;j<s.size();j++){
                if(s[i]== s[j]){
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};

int main(){
    Solution s;
    //string  str = "bbbab";
    string str = "cbbd";
    cout<< s.longestPalindromeSubseq(str)<<endl;
}

class Solution_carl {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};