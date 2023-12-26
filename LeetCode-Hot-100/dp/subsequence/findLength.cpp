//
// Created by Administrator on 2023/12/21.
//

//718. 最长重复子数组
// 也就是最长子序列，连续的
// 必会题目

//A: [1,2,3,2,1]
//B: [3,2,1,4,7]
//输出：3

/**
 * dp[i][j]数组的含义：以num1[i-1],num2[j-1]结尾的最长子序列长度
 */


#include <vector>
#include <iostream>
using namespace std;

// 版本一
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp (nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
        int result = 0;
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                if (dp[i][j] > result)
                    result = dp[i][j];
            }
        }
        return result;
    }
};


int main(){
    vector<int> num1={1,2,3,2,1};
    vector<int> num2={3,2,1,4,7};
    int res;
    Solution s;
    res = s.findLength(num1,num2);
    cout<< "result is :"<<res <<endl;

    return 0;
}