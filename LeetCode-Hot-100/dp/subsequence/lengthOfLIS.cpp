
//300. 最长递增子序列
// 注意：元素之间可以不连续
// 对比：1143. 最长公共子序列
// 【必须回】！！！

//dp[i]数组的含义：以nums[i]结尾的最长递增子序列

//dp[i] = max(dp[i], dp[j] + 1);
// 不太好想

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res=0;
        for (int i = 1; i < nums.size(); i++) {
            // j其实就是遍历0到i-1，那么是从前到后，还是从后到前遍历都无所谓，
            // 只要吧 0 到 i-1 的元素都遍历了就行了。 所以默认习惯 从前向后遍历。
            for (int j = 0; j < i; j++) {   // 反着试试
                if (nums[i] > nums[j])
                    dp[i] = max(dp[i], dp[j] + 1);  // 找众多dp[j]中找一个最大的
            }
            if (dp[i] > res) res = dp[i]; // 取长的子序列
            for(auto &e : dp){
                cout<<e<<" ";
            }
            cout<<endl;
        }

        return res;
    }
};


int main(){
    Solution s;
    //vector<int> nums ={10,9,2,5,3,7,101,18};
    vector<int> nums ={0,1,0,3,2,1};
    int res = s.lengthOfLIS(nums);
    cout<< "result is: "<<res<<endl;
    return 0;
}