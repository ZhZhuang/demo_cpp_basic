//
// Created by Administrator on 2023/12/22.
//

//647. 回文子串
// 给你一个字符串 s ，请你统计并返回这个字符串中 回文子串 的数目。

// 妙！！！

#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size(),vector<bool>(s.size(),false));
        int result =0;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i] == s[j]){
                    if(j-i<=1){
                        dp[i][j]=true;
                        result++;
                    }else{
                        if(dp[i+1][j-1]){
                            dp[i][j]=true;
                            result++;
                        }
                    }
                }
            }
        }
        return result;
    }
};