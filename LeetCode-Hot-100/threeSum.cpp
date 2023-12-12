//
// Created by Administrator on 2023/11/25.
//


// 15. 三数之和 （为0）
// 技巧：排序+双指针
// 想不起来要先排序
// https://programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E6%80%9D%E8%B7%AF

#include <vector>
#include <set>
#include <algorithm>
using namespace std;

//int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
//
//}

// 暴力枚举: 超时
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    set<vector<int>> resultSet; // 使用set来进行去重
    for(int i=0;i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k= j+1;k<nums.size();k++){
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> temp = {nums[i], nums[j], nums[k]};
                    sort(temp.begin(),temp.end());
                    resultSet.insert(temp);
                }
            }
        }
    }
    for(auto it= resultSet.begin();it != resultSet.end();it++){
        res.push_back(*it);
    }
    return res;
}

// 双指针
vector<vector<int>> threeSum_2(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    // 找出a + b + c = 0
    // a = nums[i], b = nums[left], c = nums[right]
    for (int i = 0; i < nums.size(); i++) {
        // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
        if (nums[i] > 0) {
            return result;
        }
        // 错误去重a方法，将会漏掉-1,-1,2 这种情况
        /*
        if (nums[i] == nums[i + 1]) {
            continue;
        }
        */
        // 正确去重a方法
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = nums.size() - 1;
        while (right > left) {
            // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
            /*
            while (right > left && nums[right] == nums[right - 1]) right--;
            while (right > left && nums[left] == nums[left + 1]) left++;
            */
            if (nums[i] + nums[left] + nums[right] > 0) right--;
            else if (nums[i] + nums[left] + nums[right] < 0) left++;
            else {
                result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                while (right > left && nums[right] == nums[right - 1]) right--;
                while (right > left && nums[left] == nums[left + 1]) left++;

                // 找到答案时，双指针同时收缩
                right--;
                left++;
            }
        }

    }
    return result;
}