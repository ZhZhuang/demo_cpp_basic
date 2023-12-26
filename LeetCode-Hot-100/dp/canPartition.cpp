
//416. 分割等和子集

//输入：nums = [1,5,11,5]
//输出：true
//解释：数组可以分割成 [1, 5, 5] 和 [11] 。

//输入：nums = [1,2,3,5]
//输出：false
//解释：数组不能分割成两个元素和相等的子集。

/**方法
 * 方法一：练习回溯法，回溯法！！！ 先做一遍！！！！！！
 * 方法二：DP，二维数组
 * 方法三：DP，一维数组
 *
 * 本题的核心思路：
 * 转化为01背包问题
 * 背包是否能装满，背包的价值=重量
 * target= sum/2
 */

#include <vector>
//#include <algorithm>
using namespace std;


// 回溯法,变成了二叉树
class Solution_1 {
public:
    int target = 0;
    int path = 0;
    bool res = false;
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        if(sum&1){
            return false;
        }
        target = sum/2;
        backtarcking(nums,0);
        return res;
    }

    void backtarcking(vector<int>& nums, int index){
        if(index >= nums.size()){
            if(path == target)
                res = true;
            return;
        }
        if(res == true)
            return;
        path += nums[index];
        backtarcking(nums,index+1);
        path -= nums[index];
        backtarcking(nums,index+1);
    }
};


// 自己解决了
// 二维dp数组
class Solution_2 {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if (sum & 1) {  //奇数
            return false;
        }
        int target = sum/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,0));
        // 初始化dp
        for(int i=nums[0];i<target+1;i++){
            dp[0][i]=nums[0];
        }

        for(int i=1;i<nums.size();i++){ //物品
            for(int j=1;j<target+1;j++){    //重量
                if(j>=nums[i]){
                    dp[i][j]= max(dp[i-1][j],
                                  dp[i-1][j-nums[i]] + nums[i]);
                } else{
                    dp[i][j]= dp[i-1][j];
                }
            }
        }
        return dp[nums.size()-1][target] == target;
    }
};

// 一维dp数组，滚动数组
class Solution_3 {
public:
    bool canPartition(vector<int>& nums) {

    }
};