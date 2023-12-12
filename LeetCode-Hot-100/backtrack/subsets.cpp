
// 78. 子集

// 在什么地方收获结果？ 节点中
// 视频：
// https://www.bilibili.com/video/BV1U84y1q7Ci/?vd_source=f48666313e287bbf423762465f29de45

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> path;   // 路径，也就是遍历中的一种结果
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtacking(nums,0);
        return res;
    }

    // startindex 解决组合问题
    void backtacking(vector<int>& nums, int startindex){
        res.push_back(path);    // 进入节点是就将放入结果中
        if(startindex>=nums.size())return;  // 可以省略
        for(int i=startindex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtacking(nums, i+1);
            path.pop_back();
        }
    }
};