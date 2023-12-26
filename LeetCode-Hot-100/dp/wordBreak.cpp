
//139. 单词拆分

/**
 * 问题分析：转化为完全背包，是否能装满的问题
 * 装满问题可以分为组合和排列
 */

//  方法一：回溯法，！！！
//  方法二：动态规划

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        for(auto &st : wordDict){
            for(int j=st.size();j<=s.size(); j++){

            }
        }
    }
};