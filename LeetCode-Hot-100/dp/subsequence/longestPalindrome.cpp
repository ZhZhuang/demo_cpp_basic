//
// Created by Administrator on 2023/12/23.
//

//5. 最长回文子串

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int result = 0;
        int start=0, end = 0;
        for(int i=s.size()-1;i>=0;i--){
            for(int j=i;j<s.size();j++){
                if(s[i]==s[j]){
                    if(j-i<=1){
                        dp[i][j]=true;
                        if(j-i+1>result){
                            result =j-i+1;
                            start =i;
                            end = j;
                        }
                    } else{
                        if(dp[i+1][j-1]==true){
                            dp[i][j]=true;
                            if(j-i+1>result){
                                result =j-i+1;
                                start =i;
                                end = j;
                            }
                        }
                    }
                }
            }
        }
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return s.substr(start, result);
    }
};

int main(){
    Solution s;
    string  str = "babad";
    cout<< s.longestPalindrome(str)<<endl;
}