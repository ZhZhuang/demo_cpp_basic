//
// Created by Administrator on 2023/12/26.
//

//136. 只出现一次的数字
// 认真审题！！！！！

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // 本题有个前提，重复的数字出现两次
    int singleNumber(vector<int>& nums) {
        int result =0;
        for(auto &i :nums){
            result ^= i;
        }
        return result;
    }

    int findSingleNumber(vector<int>& nums) {
        unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }
        for (const auto& pair : countMap) {
            if (pair.second == 1) {
                return pair.first;
            }
        }
        return -1; // 如果没有找到只出现一次的数字
    }
};